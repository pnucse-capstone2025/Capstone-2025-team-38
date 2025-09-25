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
hash (register const char *str, register size_t len)
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

static unsigned char lengthtable[] =
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
    {"L!\001 ", {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 124 "kobject_prebuilt_hash.gperf"
    {"\274!\001 ", {0}, K_OBJ_MUTEX, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 90 "kobject_prebuilt_hash.gperf"
    {"\274\034\001 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 96 "kobject_prebuilt_hash.gperf"
    {"L\035\001 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 94 "kobject_prebuilt_hash.gperf"
    {"\034\035\001 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 19 "kobject_prebuilt_hash.gperf"
    {"LE\003\010", {0}, K_OBJ_DRIVER_CLOCK_CONTROL, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 97 "kobject_prebuilt_hash.gperf"
    {"`\035\001 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 78 "kobject_prebuilt_hash.gperf"
    {"\274X\000 ", {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 20 "kobject_prebuilt_hash.gperf"
    {"`E\003\010", {0}, K_OBJ_DRIVER_RESET, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 45 "kobject_prebuilt_hash.gperf"
    {"XP\000 ", {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 31 "kobject_prebuilt_hash.gperf"
    {"PF\003\010", {0}, K_OBJ_DRIVER_UART, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 93 "kobject_prebuilt_hash.gperf"
    {"\000\035\001 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 107 "kobject_prebuilt_hash.gperf"
    {"P\036\001 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 55 "kobject_prebuilt_hash.gperf"
    {"\000S\000 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 62 "kobject_prebuilt_hash.gperf"
    {"lS\000 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 27 "kobject_prebuilt_hash.gperf"
    {"\000F\003\010", {0}, K_OBJ_DRIVER_GPIO, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 127 "kobject_prebuilt_hash.gperf"
    {"\374!\001 ", {0}, K_OBJ_SEM, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 82 "kobject_prebuilt_hash.gperf"
    {"lY\000 ", {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 108 "kobject_prebuilt_hash.gperf"
    {"l\036\001 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 28 "kobject_prebuilt_hash.gperf"
    {"\024F\003\010", {0}, K_OBJ_DRIVER_GPIO, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 80 "kobject_prebuilt_hash.gperf"
    {"\024Y\000 ", {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 103 "kobject_prebuilt_hash.gperf"
    {"\360\035\001 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 38 "kobject_prebuilt_hash.gperf"
    {"`\020\000 ", {0}, K_OBJ_THREAD, 0, { .thread_id = 5 }},
#line 92 "kobject_prebuilt_hash.gperf"
    {"\354\034\001 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 56 "kobject_prebuilt_hash.gperf"
    {"\020S\000 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 114 "kobject_prebuilt_hash.gperf"
    {"\374\036\001 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 85 "kobject_prebuilt_hash.gperf"
    {"\360Y\000 ", {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 26 "kobject_prebuilt_hash.gperf"
    {"\354E\003\010", {0}, K_OBJ_DRIVER_GPIO, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 47 "kobject_prebuilt_hash.gperf"
    {"\350P\000 ", {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 115 "kobject_prebuilt_hash.gperf"
    {"\020\037\001 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 60 "kobject_prebuilt_hash.gperf"
    {"\\S\000 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 79 "kobject_prebuilt_hash.gperf"
    {"\350X\000 ", {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 70 "kobject_prebuilt_hash.gperf"
    {"\\W\000 ", {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 102 "kobject_prebuilt_hash.gperf"
    {"\334\035\001 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 73 "kobject_prebuilt_hash.gperf"
    {"\340W\000 ", {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 118 "kobject_prebuilt_hash.gperf"
    {"\\\037\001 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 113 "kobject_prebuilt_hash.gperf"
    {"\340\036\001 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 125 "kobject_prebuilt_hash.gperf"
    {"\320!\001 ", {0}, K_OBJ_MUTEX, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 91 "kobject_prebuilt_hash.gperf"
    {"\320\034\001 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 24 "kobject_prebuilt_hash.gperf"
    {"\304E\003\010", {0}, K_OBJ_DRIVER_GPIO, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 23 "kobject_prebuilt_hash.gperf"
    {"\260E\003\010", {0}, K_OBJ_DRIVER_GPIO, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 101 "kobject_prebuilt_hash.gperf"
    {"\300\035\001 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 84 "kobject_prebuilt_hash.gperf"
    {"\304Y\000 ", {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 68 "kobject_prebuilt_hash.gperf"
    {"\300S\000 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 111 "kobject_prebuilt_hash.gperf"
    {"\260\036\001 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 100 "kobject_prebuilt_hash.gperf"
    {"\254\035\001 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 89 "kobject_prebuilt_hash.gperf"
    {"\240\034\001 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 67 "kobject_prebuilt_hash.gperf"
    {"\254S\000 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 46 "kobject_prebuilt_hash.gperf"
    {"\240P\000 ", {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 22 "kobject_prebuilt_hash.gperf"
    {"\234E\003\010", {0}, K_OBJ_DRIVER_GPIO, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 121 "kobject_prebuilt_hash.gperf"
    {"\200!\001 ", {0}, K_OBJ_MUTEX, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 66 "kobject_prebuilt_hash.gperf"
    {"\230S\000 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 99 "kobject_prebuilt_hash.gperf"
    {"\220\035\001 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 110 "kobject_prebuilt_hash.gperf"
    {"\234\036\001 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 83 "kobject_prebuilt_hash.gperf"
    {"\230Y\000 ", {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 77 "kobject_prebuilt_hash.gperf"
    {"\220X\000 ", {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 21 "kobject_prebuilt_hash.gperf"
    {"\210E\003\010", {0}, K_OBJ_DRIVER_GPIO, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 54 "kobject_prebuilt_hash.gperf"
    {"\354R\000 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 71 "kobject_prebuilt_hash.gperf"
    {"\210W\000 ", {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 109 "kobject_prebuilt_hash.gperf"
    {"\200\036\001 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 98 "kobject_prebuilt_hash.gperf"
    {"|\035\001 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 116 "kobject_prebuilt_hash.gperf"
    {",\037\001 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 64 "kobject_prebuilt_hash.gperf"
    {"|S\000 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 61 "kobject_prebuilt_hash.gperf"
    {"dS\000 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 76 "kobject_prebuilt_hash.gperf"
    {"dX\000 ", {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 53 "kobject_prebuilt_hash.gperf"
    {"\334R\000 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 81 "kobject_prebuilt_hash.gperf"
    {"@Y\000 ", {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 30 "kobject_prebuilt_hash.gperf"
    {"<F\003\010", {0}, K_OBJ_DRIVER_UART, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 117 "kobject_prebuilt_hash.gperf"
    {"@\037\001 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 106 "kobject_prebuilt_hash.gperf"
    {"<\036\001 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 75 "kobject_prebuilt_hash.gperf"
    {"8X\000 ", {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 128 "kobject_prebuilt_hash.gperf"
    {"\024\"\001 ", {0}, K_OBJ_SEM, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 44 "kobject_prebuilt_hash.gperf"
    {"\370\024\000 ", {0}, K_OBJ_THREAD, 0, { .thread_id = 11 }},
#line 40 "kobject_prebuilt_hash.gperf"
    {"\020\022\000 ", {0}, K_OBJ_THREAD, 0, { .thread_id = 7 }},
#line 123 "kobject_prebuilt_hash.gperf"
    {"\250!\001 ", {0}, K_OBJ_MUTEX, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 35 "kobject_prebuilt_hash.gperf"
    {"\340\015\000 ", {0}, K_OBJ_THREAD, 0, { .thread_id = 2 }},
#line 43 "kobject_prebuilt_hash.gperf"
    {"8\024\000 ", {0}, K_OBJ_THREAD, 0, { .thread_id = 10 }},
#line 74 "kobject_prebuilt_hash.gperf"
    {"\014X\000 ", {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 126 "kobject_prebuilt_hash.gperf"
    {"\344!\001 ", {0}, K_OBJ_SEM, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 25 "kobject_prebuilt_hash.gperf"
    {"\330E\003\010", {0}, K_OBJ_DRIVER_GPIO, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 104 "kobject_prebuilt_hash.gperf"
    {"\014\036\001 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 69 "kobject_prebuilt_hash.gperf"
    {"\324S\000 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 112 "kobject_prebuilt_hash.gperf"
    {"\314\036\001 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 87 "kobject_prebuilt_hash.gperf"
    {"\300\313\000 ", {0}, K_OBJ_THREAD_STACK_ELEMENT, 0, { .stack_data = &stack_data[1] }},
#line 52 "kobject_prebuilt_hash.gperf"
    {"\310R\000 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 51 "kobject_prebuilt_hash.gperf"
    {"\270R\000 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 72 "kobject_prebuilt_hash.gperf"
    {"\264W\000 ", {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 50 "kobject_prebuilt_hash.gperf"
    {"\244R\000 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 122 "kobject_prebuilt_hash.gperf"
    {"\224!\001 ", {0}, K_OBJ_MUTEX, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 88 "kobject_prebuilt_hash.gperf"
    {"\214\034\001 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 86 "kobject_prebuilt_hash.gperf"
    {"\300\213\000 ", {0}, K_OBJ_THREAD_STACK_ELEMENT, 0, { .stack_data = &stack_data[0] }},
#line 65 "kobject_prebuilt_hash.gperf"
    {"\204S\000 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 95 "kobject_prebuilt_hash.gperf"
    {"0\035\001 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 48 "kobject_prebuilt_hash.gperf"
    {"0Q\000 ", {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 49 "kobject_prebuilt_hash.gperf"
    {"xQ\000 ", {0}, K_OBJ_SEM, 0, { .unused = 0 }},
#line 63 "kobject_prebuilt_hash.gperf"
    {"tS\000 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 119 "kobject_prebuilt_hash.gperf"
    {"p\037\001 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 59 "kobject_prebuilt_hash.gperf"
    {"HS\000 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 130 "kobject_prebuilt_hash.gperf"
    {"D\"\001 ", {0}, K_OBJ_SEM, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 58 "kobject_prebuilt_hash.gperf"
    {"4S\000 ", {0}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 29 "kobject_prebuilt_hash.gperf"
    {"(F\003\010", {0}, K_OBJ_DRIVER_UART, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 57 "kobject_prebuilt_hash.gperf"
    {"$S\000 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 105 "kobject_prebuilt_hash.gperf"
    {" \036\001 ", {0}, K_OBJ_CONDVAR, 0, { .unused = 0 }},
#line 42 "kobject_prebuilt_hash.gperf"
    {"\230\023\000 ", {0}, K_OBJ_THREAD, 0, { .thread_id = 8 }},
#line 39 "kobject_prebuilt_hash.gperf"
    {"8\021\000 ", {0}, K_OBJ_THREAD, 0, { .thread_id = 6 }},
#line 37 "kobject_prebuilt_hash.gperf"
    {"\210\017\000 ", {0}, K_OBJ_THREAD, 0, { .thread_id = 4 }},
#line 36 "kobject_prebuilt_hash.gperf"
    {"\260\016\000 ", {0}, K_OBJ_THREAD, 0, { .thread_id = 3 }},
#line 33 "kobject_prebuilt_hash.gperf"
    {"\000\011\000 ", {0}, K_OBJ_THREAD, 0, { .thread_id = 1 }},
#line 32 "kobject_prebuilt_hash.gperf"
    {"`\010\000 ", {0}, K_OBJ_THREAD, 0, { .thread_id = 0 }},
    {""},
#line 129 "kobject_prebuilt_hash.gperf"
    {",\"\001 ", {0}, K_OBJ_SEM, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
    {""}, {""}, {""},
#line 41 "kobject_prebuilt_hash.gperf"
    {"\370\022\000 ", {0}, K_OBJ_THREAD, 0, { .thread_id = 9 }},
    {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 34 "kobject_prebuilt_hash.gperf"
    {"\250\015\000 ", {0}, K_OBJ_TIMER, 0, { .unused = 0 }}
  };

struct k_object *
z_object_lookup (register const char *str, register size_t len)
{
  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        if (len == lengthtable[key])
          {
            register const char *s = wordlist[key].name;

            if (*str == *s && !memcmp (str + 1, s + 1, len - 1))
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
