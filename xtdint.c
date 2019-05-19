#include "xtdint.h"
/* Input 8-bit array - v - along with a 16-bit "size-in-bytes" - s - and return a 2048-bit representation*/
u2048* U2048(u8* v, u16 s)
{
    if (s > 256)
        return NULL;
        
    u2048* w = (u2048*)malloc(256); u8 d = 32 - (s/8);
    
    for (u8 i = 0; i < d; i++)
        w->n[i] = 0;
        
    for (u16 i = 1; i <= s; i+=8)
        w->n[(i/8) + d] = ((u64)v[i - 1] << 56) | ((u64)v[i] << 48) | ((u64)v[i + 1] << 40) | ((u64)v[i + 2] << 32) | ((u64)v[i + 3] << 24) | ((u64)v[i + 4] << 16) | ((u64)v[i + 5] << 8) | (u64)v[i + 6];
        
    return w;
}

s2048* S2048(u8* v, u16 s){ return U2048(v, s);}
