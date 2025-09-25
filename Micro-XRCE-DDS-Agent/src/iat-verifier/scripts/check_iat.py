#!/usr/bin/env python3
# -----------------------------------------------------------------------------
# Copyright (c) 2019-2025, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
# -----------------------------------------------------------------------------

"""CLI script for verifying an IAT."""

import argparse
import json
import logging
import sys

from pycose.algorithms import Es256, Es384, HMAC256

from iatverifier.util import recursive_bytes_to_strings, read_keyfile, get_cose_alg_from_key
from iatverifier.psa_iot_profile1_token_verifier import PSAIoTProfile1TokenVerifier
from iatverifier.psa_2_0_0_token_verifier import PSA_2_0_0_TokenVerifier
from iatverifier.attest_token_verifier import VerifierConfiguration, AttestationTokenVerifier
from iatverifier.cca_token_verifier import CCATokenVerifier, CCAPlatformTokenVerifier

logger = logging.getLogger('iat-verify')

def main():
    """Main function for verifying an IAT"""

    token_verifiers = {
        "PSA-IoT-Profile1-token": PSAIoTProfile1TokenVerifier,
        "CCA-token": CCATokenVerifier,
        "CCA-plat-token": CCAPlatformTokenVerifier,
        "PSA-2.0.0-token": PSA_2_0_0_TokenVerifier,
    }

    parser = argparse.ArgumentParser(
        description='''
        Validates a signed Initial Attestation Token (IAT), checking
        that the signature is valid, the token contian the required
        fields, and those fields are in a valid format.
        ''')
    parser.add_argument('-k', '--key',
                        help='''Path to the key in PEM format that should be used to
                        verify the token. If this is not specified, the token signature
                        will not be checked.''')
    parser.add_argument('tokenfile',
                        help='''
                        path to a file containing a signed IAT.
                        ''')
    parser.add_argument('-K', '--keep-going', action='store_true',
                        help='''
                        Do not stop upon encountering a validation error.
                        ''')
    parser.add_argument('-p', '--print-iat', action='store_true',
                        help='''
                        Print the decoded token in JSON format.
                        ''')
    parser.add_argument('-s', '--strict', action='store_true',
                        help='''
                        Report failure if unknown claim is encountered.
                        ''')
    parser.add_argument('-m', '--method', choices=['sign', 'mac', 'raw'], default='sign',
                        help='''
                        Specify how this token is wrapped -- whether Sign1Message or
                        Mac0Message COSE structure is used. In case of 'raw' no COSE envelope is
                        expected.
                        ''')
    parser.add_argument('-t', '--token-type',
                        help='''The type of the Token.''',
                        choices=token_verifiers.keys(),
                        required=True)
    parser.add_argument('--expect-token-indicator',
                        help='''Expect token indicator in the cbor.''',
                        action='store_true')

    args = parser.parse_args()

    logging.basicConfig(level=logging.INFO)

    config = VerifierConfiguration(keep_going=args.keep_going, strict=args.strict)
    if args.method == 'mac':
        method = AttestationTokenVerifier.SIGN_METHOD_MAC0
    elif args.method == 'raw':
        if args.key:
            raise ValueError('A keyfile cannot be specified with --raw.')
        method = AttestationTokenVerifier.SIGN_METHOD_RAW
    elif args.method == 'sign':
        method = AttestationTokenVerifier.SIGN_METHOD_SIGN1
    else:
        assert False

    key_checked = False

    verifier_class = token_verifiers[args.token_type]
    if verifier_class == PSAIoTProfile1TokenVerifier:
        key_checked = args.key
        key = read_keyfile(keyfile=args.key, method=method)
        if method == AttestationTokenVerifier.SIGN_METHOD_SIGN1:
            cose_alg = get_cose_alg_from_key(key, Es256)
        else:
            cose_alg = HMAC256
        verifier = PSAIoTProfile1TokenVerifier(
            method=method,
            cose_alg=cose_alg,
            signing_key=key,
            configuration=config)
    elif verifier_class == CCATokenVerifier:
        if method != AttestationTokenVerifier.SIGN_METHOD_SIGN1:
            logger.error('Only sign1 method is supported by this token type.\n\t'.format(verifier_class))
            sys.exit(1)
        key_checked = args.key
        platform_token_key = read_keyfile(args.key, method)
        realm_token_method = AttestationTokenVerifier.SIGN_METHOD_SIGN1
        platform_token_method = AttestationTokenVerifier.SIGN_METHOD_SIGN1
        realm_token_cose_alg = get_cose_alg_from_key(None, Es384)
        platform_token_cose_alg = get_cose_alg_from_key(platform_token_key, Es384)
        verifier = CCATokenVerifier(
            realm_token_method=realm_token_method,
            realm_token_cose_alg=realm_token_cose_alg,
            platform_token_method=platform_token_method,
            platform_token_cose_alg=platform_token_cose_alg,
            platform_token_key=platform_token_key,
            configuration=config)
    elif verifier_class == CCAPlatformTokenVerifier:
        key_checked = args.key
        key = read_keyfile(args.key, method)
        cose_alg = get_cose_alg_from_key(key, Es384)
        verifier = CCAPlatformTokenVerifier(
            method=AttestationTokenVerifier.SIGN_METHOD_SIGN1,
            cose_alg=cose_alg,
            signing_key=key,
            configuration=config,
            necessity=None,
            has_type_indicator=args.expect_token_indicator)
    elif verifier_class == PSA_2_0_0_TokenVerifier:
        key_checked = args.key
        key = read_keyfile(keyfile=args.key, method=method)
        if method == AttestationTokenVerifier.SIGN_METHOD_SIGN1:
            cose_alg = get_cose_alg_from_key(key, Es256)
        else:
            cose_alg = HMAC256
        verifier = PSA_2_0_0_TokenVerifier(method=method, cose_alg=cose_alg, signing_key=key, configuration=config)
    else:
        logger.error(f'Invalid token type:{verifier_class}\n\t')
        sys.exit(1)

    try:
        with open(args.tokenfile, 'rb') as token_file:
            token = verifier.parse_token(
                token=token_file.read(),
                lower_case_key=False)
            token.verify()
        # if key_checked:
            # print('Signature OK')
        # print('Token format OK')
    except ValueError as exc:
        logger.error(f'Token verification failed:\n\t{exc}')
        return 1

    if args.print_iat:
        print('Token:')
        token_map = token.get_token_map()
        json.dump(recursive_bytes_to_strings(token_map, in_place=True),
                  sys.stdout, indent=4)
        print('')

    return 0

if __name__ == '__main__':
    main()
