#ifndef HASH_H_
#define HASH_H_

#include <stdint.h>
#include <stddef.h>
#include <tinycrypt/sha256.h>

#ifdef __cplusplus
extern "C" {
#endif

// start_addr: 해시할 메모리 시작 주소
// size: 해시할 메모리 크기 (바이트 단위)
#define FIRMWARE_START_ADDR 0x08000000
#define FIRMWARE_SIZE       0x00035c88  
#define CHUNK_SIZE          1024        

// output_hash: 결과 SHA256 digest 출력 버퍼 (32바이트)
int hash_firmware(uint8_t *output_hash);

#ifdef __cplusplus
}
#endif

#endif  