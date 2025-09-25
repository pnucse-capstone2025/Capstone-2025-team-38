// #include "/home/jspark/uros_ws/firmware/zephyrproject/modules/crypto/tinycrypt/lib/include/tinycrypt/sha256.h"
#include "hash/hash.h"

int hash_firmware(uint8_t *output_hash)
{
    if (output_hash == NULL) {
        return 0; // TC_CRYPTO_FAIL
    }

    const uint8_t *firmware_ptr = (const uint8_t *)FIRMWARE_START_ADDR;

    struct tc_sha256_state_struct sha_ctx;
    if (!tc_sha256_init(&sha_ctx)) {
        return 0;
    }

    for (uint32_t offset = 0; offset < FIRMWARE_SIZE; offset += CHUNK_SIZE) {
        size_t len = (FIRMWARE_SIZE - offset > CHUNK_SIZE) ? CHUNK_SIZE : (FIRMWARE_SIZE - offset);
        if (!tc_sha256_update(&sha_ctx, firmware_ptr + offset, len)) {
            return 0;
        }
    }

    if (!tc_sha256_final(output_hash, &sha_ctx)) {
        return 0;
    }

    return 1; // TC_CRYPTO_SUCCESS
}
