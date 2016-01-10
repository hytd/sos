#ifndef __TYPES_H__
#define __TYPES_H__

#define PUBLIC  __attribute__((weak))
#define PRIVATE static

#define NULL ((void*)0)

typedef signed   char s8;
typedef unsigned char u8;

typedef signed   char s16;
typedef unsigned char u16;

typedef signed   int s32;
typedef unsigned int u32;

typedef s32 (*func_0)();
typedef s32 (*func_1)(u32 arg1);
typedef s32 (*func_2)(u32 arg1, u32 arg2);
typedef s32 (*func_3)(u32 arg1, u32 arg2, u32 arg3);

enum {
    OK = 0,
    ERROR,
    EINVAL, /* invalid parameter */
    ENOMEM, /* out of memory */
};

#endif /* __TYPES_H__ */