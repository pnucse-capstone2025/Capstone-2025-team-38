/* ANSI-C code produced by gperf version 3.1 */
/* Command-line: /usr/bin/gperf --output-file kobject_prebuilt_hash_preprocessed.c --multiple-iterations 10 kobject_prebuilt_hash.gperf  */
/* Computed positions: -k'1-2' */

#line 6 "kobject_prebuilt_hash.gperf"

#include <zephyr/kernel.h>
#include <zephyr/toolchain.h>
#include <zephyr/internal/syscall_handler.h>
#include <string.h>
#line 12 "kobject_prebuilt_hash.gperf"
struct k_object;
static uint8_t Z_GENERIC_SECTION(.priv_stacks.noinit)  __aligned(Z_KERNEL_STACK_OBJ_ALIGN) priv_stacks[2][K_KERNEL_STACK_LEN(CONFIG_PRIVILEGED_STACK_SIZE)];
static const struct z_stack_data stack_data[2] = {
	{ 16384, (uint8_t *)(&priv_stacks[0]) },
	{ 20480, (uint8_t *)(&priv_stacks[1]) }
};

#define TOTAL_KEYWORDS 112
#define MIN_WORD_LENGTH 4
#define MAX_WORD_LENGTH 4
#define MIN_HASH_VALUE 0
#define MAX_HASH_VALUE 122
/* maximum key range = 123, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
/*ARGSUSED*/
static unsigned int
hash ( const char *str,  size_t len)
{
  static unsigned char asso_values[] =
    {
        8, 123, 123, 123, 123, 123, 123, 123, 105,  99,
      123, 123,  71,  48,  71,  54,  19,  40,  54,  57,
       12, 123, 123, 123, 123, 123, 123, 123,   1,   3,
        9,  10,  93,   0,  59, 123,  96, 123, 123, 123,
       93, 123, 123, 123,  51, 123, 123, 123,  89, 123,
      123, 123,  94, 123, 123, 123,  64, 123, 123, 123,
       60, 123, 123, 123,  58, 123, 123, 123,  39,   5,
        7, 123,  92, 123, 123, 123,   0, 123, 123, 123,
        3,   4,  35,   5, 123, 123, 123,   7,   6,   8,
      123, 123,  25, 123, 123, 123,   3, 123, 123, 123,
       58, 123, 123, 123, 123, 123, 123, 123,   9, 123,
      123, 123,  86, 123, 123, 123,  90, 123, 123, 123,
       90, 123, 123, 123,  57, 123, 123, 123,  50, 123,
      123, 123,  86, 123, 123, 123,  51, 123, 123,  52,
       88, 123, 123, 123,  49, 123, 123, 123,  88, 123,
      123, 123,  46, 123, 123, 123,  44, 123, 123, 123,
       45, 123, 123, 123,  52, 123, 123, 123,  74, 123,
      123, 123,  42, 123, 123, 123,  35, 123, 123, 123,
       79, 123, 123, 123,  50, 123, 123, 123,   1, 123,
      123, 123,  38, 123, 123, 123,  34, 123, 123, 123,
       49, 123, 123,  45,  73, 123, 123, 123,  37, 123,
      123, 123,  76, 123, 123, 123,  74, 123, 123, 123,
       30, 123, 123, 123,  27, 123, 123, 123,  78, 123,
      123, 123,  25, 123, 123, 123,  22, 123, 123, 123,
       18, 123, 123, 123, 123, 123, 123, 123,  60, 123,
      123, 123,  16, 123, 123, 123
    };
  return asso_values[(unsigned char)str[1]] + asso_values[(unsigned char)str[0]];
}

static unsigned char __unused lengthtable[] =
  {
     4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
     4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
     4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
     4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
     4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
     4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
     4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
     4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  0,  4,  0,
     0,  0,  4,  0,  0,  0,  0,  0,  0,  0,  4
  };

static struct k_object wordlist[] =
  {
#line 120 "kobject_prebuilt_hash.gperf"
    {(char *)0x000000002001214c, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 124 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000200121bc, {0}, K_OBJ_MUTEX, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 90 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011cbc, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 96 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011d4c, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 94 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011d1c, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 19 "kobject_prebuilt_hash.gperf"
    {(char *)0x000000000803454c, {0}, K_OBJ_DRIVER_CLOCK_CONTROL, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 97 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011d60, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 78 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000200058bc, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 20 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000008034560, {0}, K_OBJ_DRIVER_RESET, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 45 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020005058, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 31 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000008034650, {0}, K_OBJ_DRIVER_UART, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 93 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011d00, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 107 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011e50, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 55 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020005300, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 62 "kobject_prebuilt_hash.gperf"
    {(char *)0x000000002000536c, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 27 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000008034600, {0}, K_OBJ_DRIVER_GPIO, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 127 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000200121fc, {0}, K_OBJ_SEM, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 82 "kobject_prebuilt_hash.gperf"
    {(char *)0x000000002000596c, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 108 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011e6c, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 28 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000008034614, {0}, K_OBJ_DRIVER_GPIO, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 80 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020005914, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 103 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011df0, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 38 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020001060, {0}, K_OBJ_THREAD, 0, { .thread_id = 5 }},
#line 92 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011cec, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 56 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020005310, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 114 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011efc, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 85 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000200059f0, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 26 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000080345ec, {0}, K_OBJ_DRIVER_GPIO, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 47 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000200050e8, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 115 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011f10, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 60 "kobject_prebuilt_hash.gperf"
    {(char *)0x000000002000535c, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 79 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000200058e8, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 70 "kobject_prebuilt_hash.gperf"
    {(char *)0x000000002000575c, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 102 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011ddc, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 73 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000200057e0, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 118 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011f5c, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 113 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011ee0, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 125 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000200121d0, {0}, K_OBJ_MUTEX, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 91 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011cd0, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 24 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000080345c4, {0}, K_OBJ_DRIVER_GPIO, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 23 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000080345b0, {0}, K_OBJ_DRIVER_GPIO, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 101 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011dc0, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 84 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000200059c4, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 68 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000200053c0, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 111 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011eb0, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 100 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011dac, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 89 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011ca0, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 67 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000200053ac, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 46 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000200050a0, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 22 "kobject_prebuilt_hash.gperf"
    {(char *)0x000000000803459c, {0}, K_OBJ_DRIVER_GPIO, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 121 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020012180, {0}, K_OBJ_MUTEX, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 66 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020005398, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 99 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011d90, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 110 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011e9c, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 83 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020005998, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 77 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020005890, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 21 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000008034588, {0}, K_OBJ_DRIVER_GPIO, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 54 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000200052ec, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 71 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020005788, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 109 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011e80, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 98 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011d7c, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 116 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011f2c, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 64 "kobject_prebuilt_hash.gperf"
    {(char *)0x000000002000537c, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 61 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020005364, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 76 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020005864, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 53 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000200052dc, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 81 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020005940, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 30 "kobject_prebuilt_hash.gperf"
    {(char *)0x000000000803463c, {0}, K_OBJ_DRIVER_UART, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 117 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011f40, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 106 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011e3c, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 75 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020005838, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 128 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020012214, {0}, K_OBJ_SEM, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 44 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000200014f8, {0}, K_OBJ_THREAD, 0, { .thread_id = 11 }},
#line 40 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020001210, {0}, K_OBJ_THREAD, 0, { .thread_id = 7 }},
#line 123 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000200121a8, {0}, K_OBJ_MUTEX, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 35 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020000de0, {0}, K_OBJ_THREAD, 0, { .thread_id = 2 }},
#line 43 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020001438, {0}, K_OBJ_THREAD, 0, { .thread_id = 10 }},
#line 74 "kobject_prebuilt_hash.gperf"
    {(char *)0x000000002000580c, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 126 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000200121e4, {0}, K_OBJ_SEM, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 25 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000080345d8, {0}, K_OBJ_DRIVER_GPIO, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 104 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011e0c, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 69 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000200053d4, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 112 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011ecc, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 87 "kobject_prebuilt_hash.gperf"
    {(char *)0x000000002000cbc0, {0}, K_OBJ_THREAD_STACK_ELEMENT, 0, { .stack_data = &stack_data[1] }},
#line 52 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000200052c8, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 51 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000200052b8, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 72 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000200057b4, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 50 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000200052a4, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 122 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020012194, {0}, K_OBJ_MUTEX, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 88 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011c8c, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 86 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020008bc0, {0}, K_OBJ_THREAD_STACK_ELEMENT, 0, { .stack_data = &stack_data[0] }},
#line 65 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020005384, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 95 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011d30, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 48 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020005130, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 49 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020005178, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 63 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020005374, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 119 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011f70, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 59 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020005348, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 130 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020012244, {0}, K_OBJ_SEM, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 58 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020005334, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 29 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000008034628, {0}, K_OBJ_DRIVER_UART, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 57 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020005324, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 105 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020011e20, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 42 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020001398, {0}, K_OBJ_THREAD, 0, { .thread_id = 8 }},
#line 39 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020001138, {0}, K_OBJ_THREAD, 0, { .thread_id = 6 }},
#line 37 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020000f88, {0}, K_OBJ_THREAD, 0, { .thread_id = 4 }},
#line 36 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020000eb0, {0}, K_OBJ_THREAD, 0, { .thread_id = 3 }},
#line 33 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020000900, {0}, K_OBJ_THREAD, 0, { .thread_id = 1 }},
#line 32 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020000860, {0}, K_OBJ_THREAD, 0, { .thread_id = 0 }},
    {},
#line 129 "kobject_prebuilt_hash.gperf"
    {(char *)0x000000002001222c, {0}, K_OBJ_SEM, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
    {}, {}, {},
#line 41 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000200012f8, {0}, K_OBJ_THREAD, 0, { .thread_id = 9 }},
    {}, {}, {}, {}, {}, {}, {},
#line 34 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000020000da8, {0}, K_OBJ_TIMER, 0, { .unused = 0 }}
  };

static inline struct k_object *
z_object_lookup ( const char *str,  size_t len)
{
  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
       unsigned int key = hash((const char *)&str, len);

      if (key <= MAX_HASH_VALUE)
        if (len == sizeof(void *))
          {
             const char *s = wordlist[key].name;

            if (str == s)
              return &wordlist[key];
          }
    }
  return 0;
}
#line 131 "kobject_prebuilt_hash.gperf"

struct k_object *z_object_gperf_find(const void *obj)
{
    return z_object_lookup((const char *)obj, sizeof(void *));
}

void z_object_gperf_wordlist_foreach(_wordlist_cb_func_t func, void *context)
{
    int i;

    for (i = MIN_HASH_VALUE; i <= MAX_HASH_VALUE; i++) {
        if (wordlist[i].name != NULL) {
            func(&wordlist[i], context);
        }
    }
}

#ifndef CONFIG_DYNAMIC_OBJECTS
struct k_object *k_object_find(const void *obj)
	ALIAS_OF(z_object_gperf_find);

void k_object_wordlist_foreach(_wordlist_cb_func_t func, void *context)
	ALIAS_OF(z_object_gperf_wordlist_foreach);
#endif

Z_GENERIC_DOT_SECTION(data)
uint8_t _thread_idx_map[2] = { 0x0,  0xf0, };
