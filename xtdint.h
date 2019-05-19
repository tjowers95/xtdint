#ifndef _XTDINT_H_
#define _XTDINT_H_
typedef unsigned char u8; typedef char s8;typedef unsigned short u16; typedef short s16;
typedef unsigned int u32; typedef int s32;typedef unsigned long long u64; typedef long long s64;
typedef struct u2048 {u64 n[32];} u2048; typedef u2048 s2048;
u2048* U2048(u8* v, u16 s); s2048* S2048(u8* v, u16 s);
void shift(u2048* v, s16 n);
void add(u2048* v, u2048* w); void add_s(s2048* v, s2048* w);
void sub(u2048* v, u2048* w); void sub_s(s2048* v, s2048* w);
void mul(u2048* v, u2048* w); void mul_s(s2048* v, s2048* w);
#define to_u64(a,b,c,d,e,f,g,h) ((((u64)a) << 56) | (((u64)b) << 48) | (((u64)c) << 40) | (((u64)d) << 32) | (((u64)e) << 24) | (((u64)f) << 16) | (((u64)g) << 8) | (((u64)g) << 8) | ((u64)h))
#endif
