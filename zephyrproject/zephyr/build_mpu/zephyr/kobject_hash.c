/* ANSI-C code produced by gperf version 3.1 */
/* Command-line: /usr/bin/gperf --output-file kobject_hash_preprocessed.c --multiple-iterations 10 kobject_hash.gperf  */
/* Computed positions: -k'1-2' */

#line 6 "kobject_hash.gperf"

#include <zephyr/kernel.h>
#include <zephyr/toolchain.h>
#include <zephyr/internal/syscall_handler.h>
#include <string.h>
#line 12 "kobject_hash.gperf"
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
#define MAX_HASH_VALUE 111
/* maximum key range = 112, duplicates = 0 */

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
        6, 112, 112, 112, 112, 112, 112, 112,  83, 104,
      112, 112,  66,  46,  61,  64,  22,  45,  47,  49,
       19, 112, 112, 112, 112, 112, 112, 112, 103, 112,
      112, 112,  98, 112, 112, 112, 103,   6,  13,   2,
       66,  30,   1, 112,  88, 112, 112, 112,  91, 112,
      112, 112, 100, 112, 112, 112,  62, 112, 112, 112,
       13, 112, 112, 112,  61, 112, 112, 112, 112,   3,
        5, 112,  99, 112, 112, 112,  61, 112, 112, 112,
       11,   3,  32,   0, 112, 112, 112,   2,   4,   4,
      112, 112,  36, 112, 112, 112,  28, 112, 112, 112,
        9, 112, 112, 112, 112, 112, 112, 112,  21, 112,
      112, 112,  85, 112, 112, 112,  97, 112, 112, 112,
       92, 112, 112, 112,   3, 112, 112, 112,  86, 112,
      112, 112,  91, 112, 112, 112,  44, 112, 112,  50,
       76, 112, 112, 112,  56, 112, 112, 112,  87, 112,
      112, 112,  57, 112, 112, 112,  53, 112, 112, 112,
       42, 112, 112, 112,  55, 112, 112, 112,  40, 112,
      112, 112,   0, 112, 112, 112,  48, 112, 112, 112,
       82, 112, 112, 112,  51, 112, 112, 112,  35, 112,
      112, 112,  40, 112, 112, 112,  25, 112, 112, 112,
       48, 112, 112,  39,  72, 112, 112, 112,  64, 112,
      112, 112,  76, 112, 112, 112,  72, 112, 112, 112,
       50, 112, 112, 112,  39, 112, 112, 112, 112, 112,
      112, 112,  33, 112, 112, 112,  30, 112, 112, 112,
       30, 112, 112, 112, 112, 112, 112, 112,  49, 112,
      112, 112,  67, 112, 112, 112
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
     4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4
  };

static struct k_object wordlist[] =
  {
#line 67 "kobject_hash.gperf"
    {(char *)0x00000000200053ac, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 129 "kobject_hash.gperf"
    {(char *)0x0000000020012aac, {0}, K_OBJ_SEM, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 116 "kobject_hash.gperf"
    {(char *)0x00000000200127ac, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 64 "kobject_hash.gperf"
    {(char *)0x000000002000537c, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 127 "kobject_hash.gperf"
    {(char *)0x0000000020012a7c, {0}, K_OBJ_SEM, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 114 "kobject_hash.gperf"
    {(char *)0x000000002001277c, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 55 "kobject_hash.gperf"
    {(char *)0x0000000020005300, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 121 "kobject_hash.gperf"
    {(char *)0x0000000020012a00, {0}, K_OBJ_MUTEX, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 109 "kobject_hash.gperf"
    {(char *)0x0000000020012700, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 61 "kobject_hash.gperf"
    {(char *)0x0000000020005364, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 126 "kobject_hash.gperf"
    {(char *)0x0000000020012a64, {0}, K_OBJ_SEM, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 27 "kobject_hash.gperf"
    {(char *)0x0000000008034600, {0}, K_OBJ_DRIVER_GPIO, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 125 "kobject_hash.gperf"
    {(char *)0x0000000020012a50, {0}, K_OBJ_MUTEX, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 76 "kobject_hash.gperf"
    {(char *)0x0000000020005864, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 124 "kobject_hash.gperf"
    {(char *)0x0000000020012a3c, {0}, K_OBJ_MUTEX, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 45 "kobject_hash.gperf"
    {(char *)0x0000000020005058, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 31 "kobject_hash.gperf"
    {(char *)0x0000000008034650, {0}, K_OBJ_DRIVER_UART, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 91 "kobject_hash.gperf"
    {(char *)0x0000000020012550, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 30 "kobject_hash.gperf"
    {(char *)0x000000000803463c, {0}, K_OBJ_DRIVER_UART, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 90 "kobject_hash.gperf"
    {(char *)0x000000002001253c, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 122 "kobject_hash.gperf"
    {(char *)0x0000000020012a14, {0}, K_OBJ_MUTEX, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 62 "kobject_hash.gperf"
    {(char *)0x000000002000536c, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 56 "kobject_hash.gperf"
    {(char *)0x0000000020005310, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 80 "kobject_hash.gperf"
    {(char *)0x0000000020005914, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 28 "kobject_hash.gperf"
    {(char *)0x0000000008034614, {0}, K_OBJ_DRIVER_GPIO, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 82 "kobject_hash.gperf"
    {(char *)0x000000002000596c, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 130 "kobject_hash.gperf"
    {(char *)0x0000000020012ac4, {0}, K_OBJ_SEM, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 92 "kobject_hash.gperf"
    {(char *)0x000000002001256c, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 24 "kobject_hash.gperf"
    {(char *)0x00000000080345c4, {0}, K_OBJ_DRIVER_GPIO, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 84 "kobject_hash.gperf"
    {(char *)0x00000000200059c4, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 113 "kobject_hash.gperf"
    {(char *)0x0000000020012760, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 20 "kobject_hash.gperf"
    {(char *)0x0000000008034560, {0}, K_OBJ_DRIVER_RESET, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 119 "kobject_hash.gperf"
    {(char *)0x00000000200127f0, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 26 "kobject_hash.gperf"
    {(char *)0x00000000080345ec, {0}, K_OBJ_DRIVER_GPIO, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 85 "kobject_hash.gperf"
    {(char *)0x00000000200059f0, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 99 "kobject_hash.gperf"
    {(char *)0x0000000020012610, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 60 "kobject_hash.gperf"
    {(char *)0x000000002000535c, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 79 "kobject_hash.gperf"
    {(char *)0x00000000200058e8, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 70 "kobject_hash.gperf"
    {(char *)0x000000002000575c, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 78 "kobject_hash.gperf"
    {(char *)0x00000000200058bc, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 68 "kobject_hash.gperf"
    {(char *)0x00000000200053c0, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 73 "kobject_hash.gperf"
    {(char *)0x00000000200057e0, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 117 "kobject_hash.gperf"
    {(char *)0x00000000200127c0, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 108 "kobject_hash.gperf"
    {(char *)0x00000000200126ec, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 47 "kobject_hash.gperf"
    {(char *)0x00000000200050e8, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 97 "kobject_hash.gperf"
    {(char *)0x00000000200125e0, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 71 "kobject_hash.gperf"
    {(char *)0x0000000020005788, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 21 "kobject_hash.gperf"
    {(char *)0x0000000008034588, {0}, K_OBJ_DRIVER_GPIO, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 106 "kobject_hash.gperf"
    {(char *)0x00000000200126bc, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 102 "kobject_hash.gperf"
    {(char *)0x000000002001265c, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 38 "kobject_hash.gperf"
    {(char *)0x0000000020001060, {0}, K_OBJ_THREAD, 0, { .thread_id = 5 }},
#line 23 "kobject_hash.gperf"
    {(char *)0x00000000080345b0, {0}, K_OBJ_DRIVER_GPIO, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 118 "kobject_hash.gperf"
    {(char *)0x00000000200127dc, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 46 "kobject_hash.gperf"
    {(char *)0x00000000200050a0, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 95 "kobject_hash.gperf"
    {(char *)0x00000000200125b0, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 105 "kobject_hash.gperf"
    {(char *)0x00000000200126a0, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 22 "kobject_hash.gperf"
    {(char *)0x000000000803459c, {0}, K_OBJ_DRIVER_GPIO, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 66 "kobject_hash.gperf"
    {(char *)0x0000000020005398, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 115 "kobject_hash.gperf"
    {(char *)0x0000000020012790, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 94 "kobject_hash.gperf"
    {(char *)0x000000002001259c, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 77 "kobject_hash.gperf"
    {(char *)0x0000000020005890, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 83 "kobject_hash.gperf"
    {(char *)0x0000000020005998, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 54 "kobject_hash.gperf"
    {(char *)0x00000000200052ec, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 112 "kobject_hash.gperf"
    {(char *)0x000000002001274c, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 19 "kobject_hash.gperf"
    {(char *)0x000000000803454c, {0}, K_OBJ_DRIVER_CLOCK_CONTROL, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 81 "kobject_hash.gperf"
    {(char *)0x0000000020005940, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 75 "kobject_hash.gperf"
    {(char *)0x0000000020005838, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 123 "kobject_hash.gperf"
    {(char *)0x0000000020012a28, {0}, K_OBJ_MUTEX, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 44 "kobject_hash.gperf"
    {(char *)0x00000000200014f8, {0}, K_OBJ_THREAD, 0, { .thread_id = 11 }},
#line 40 "kobject_hash.gperf"
    {(char *)0x0000000020001210, {0}, K_OBJ_THREAD, 0, { .thread_id = 7 }},
#line 74 "kobject_hash.gperf"
    {(char *)0x000000002000580c, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 29 "kobject_hash.gperf"
    {(char *)0x0000000008034628, {0}, K_OBJ_DRIVER_UART, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 88 "kobject_hash.gperf"
    {(char *)0x000000002001250c, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 98 "kobject_hash.gperf"
    {(char *)0x00000000200125fc, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 101 "kobject_hash.gperf"
    {(char *)0x0000000020012640, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 25 "kobject_hash.gperf"
    {(char *)0x00000000080345d8, {0}, K_OBJ_DRIVER_GPIO, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 69 "kobject_hash.gperf"
    {(char *)0x00000000200053d4, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 107 "kobject_hash.gperf"
    {(char *)0x00000000200126d0, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 96 "kobject_hash.gperf"
    {(char *)0x00000000200125cc, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 87 "kobject_hash.gperf"
    {(char *)0x000000002000cbc0, {0}, K_OBJ_THREAD_STACK_ELEMENT, 0, { .stack_data = &stack_data[1] }},
#line 52 "kobject_hash.gperf"
    {(char *)0x00000000200052c8, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 43 "kobject_hash.gperf"
    {(char *)0x0000000020001438, {0}, K_OBJ_THREAD, 0, { .thread_id = 10 }},
#line 53 "kobject_hash.gperf"
    {(char *)0x00000000200052dc, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 51 "kobject_hash.gperf"
    {(char *)0x00000000200052b8, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 72 "kobject_hash.gperf"
    {(char *)0x00000000200057b4, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 35 "kobject_hash.gperf"
    {(char *)0x0000000020000de0, {0}, K_OBJ_THREAD, 0, { .thread_id = 2 }},
#line 34 "kobject_hash.gperf"
    {(char *)0x0000000020000da8, {0}, K_OBJ_TIMER, 0, { .unused = 0 }},
#line 50 "kobject_hash.gperf"
    {(char *)0x00000000200052a4, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 128 "kobject_hash.gperf"
    {(char *)0x0000000020012a94, {0}, K_OBJ_SEM, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 104 "kobject_hash.gperf"
    {(char *)0x000000002001268c, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 86 "kobject_hash.gperf"
    {(char *)0x0000000020008bc0, {0}, K_OBJ_THREAD_STACK_ELEMENT, 0, { .stack_data = &stack_data[0] }},
#line 65 "kobject_hash.gperf"
    {(char *)0x0000000020005384, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 93 "kobject_hash.gperf"
    {(char *)0x0000000020012580, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 111 "kobject_hash.gperf"
    {(char *)0x0000000020012730, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 48 "kobject_hash.gperf"
    {(char *)0x0000000020005130, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 49 "kobject_hash.gperf"
    {(char *)0x0000000020005178, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 41 "kobject_hash.gperf"
    {(char *)0x00000000200012f8, {0}, K_OBJ_THREAD, 0, { .thread_id = 9 }},
#line 63 "kobject_hash.gperf"
    {(char *)0x0000000020005374, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 103 "kobject_hash.gperf"
    {(char *)0x0000000020012670, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 59 "kobject_hash.gperf"
    {(char *)0x0000000020005348, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 58 "kobject_hash.gperf"
    {(char *)0x0000000020005334, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 100 "kobject_hash.gperf"
    {(char *)0x000000002001262c, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 120 "kobject_hash.gperf"
    {(char *)0x00000000200129cc, {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 57 "kobject_hash.gperf"
    {(char *)0x0000000020005324, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 89 "kobject_hash.gperf"
    {(char *)0x0000000020012520, {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 110 "kobject_hash.gperf"
    {(char *)0x000000002001271c, {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 42 "kobject_hash.gperf"
    {(char *)0x0000000020001398, {0}, K_OBJ_THREAD, 0, { .thread_id = 8 }},
#line 39 "kobject_hash.gperf"
    {(char *)0x0000000020001138, {0}, K_OBJ_THREAD, 0, { .thread_id = 6 }},
#line 37 "kobject_hash.gperf"
    {(char *)0x0000000020000f88, {0}, K_OBJ_THREAD, 0, { .thread_id = 4 }},
#line 36 "kobject_hash.gperf"
    {(char *)0x0000000020000eb0, {0}, K_OBJ_THREAD, 0, { .thread_id = 3 }},
#line 33 "kobject_hash.gperf"
    {(char *)0x0000000020000900, {0}, K_OBJ_THREAD, 0, { .thread_id = 1 }},
#line 32 "kobject_hash.gperf"
    {(char *)0x0000000020000860, {0}, K_OBJ_THREAD, 0, { .thread_id = 0 }}
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
#line 131 "kobject_hash.gperf"

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
