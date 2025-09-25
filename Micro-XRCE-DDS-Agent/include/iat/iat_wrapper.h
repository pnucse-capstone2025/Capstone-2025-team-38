#ifndef IAT_VERIFIER_WRAPPER_H
#define IAT_VERIFIER_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

int run_check_iat(int argc, char *argv[]);

#define IAT_DATA_SIZE 64
#define IAT_NONCE_SIZE 64


#ifdef __cplusplus
}
#endif

#endif // IAT_VERIFIER_WRAPPER_H
