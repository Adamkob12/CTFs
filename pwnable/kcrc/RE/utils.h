
#include <stdint.h>
#include <stddef.h>

#define __usercall
#define __fastcall
#define __user

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef size_t    usize;
typedef ptrdiff_t isize;

void *qmemcpy(void *dst, const void *src, usize n);

// 0 if copied all
// N if didn't copy N bytes
u32 copy_from_user(void *to, const void __user *from, u32 n);

void printk(char *, int);
