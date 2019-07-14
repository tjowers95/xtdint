#ifndef _XTDINT_H_
#define _XTDINT_H_
typedef unsigned char u8;
typedef char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef unsigned long long u64;
typedef long long s64;
typedef struct u2048{u64 n[32];} u2048;

extern u2048 *U2048(const u8 *__restrict__ v, u16 s);
extern void shift(u2048 *__restrict__ v, s32 n);
extern void add(const u2048 *__restrict__ v, u2048 *__restrict__ w);
extern void sub(const u2048 *__restrict__ v, u2048 *__restrict__ w);
extern void mul(const u2048 *__restrict__ v, u2048 *__restrict__ w);
extern void printb(const u2048 *__restrict__ v);
extern void printb(u64 v);
#endif