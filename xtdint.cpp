#include "xtdint.h"
#include <OpenCL/opencl.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
u2048 *
U2048(const u8 *__restrict v, u16 s)
{
    if (s > 256)
        return NULL;

    u2048 *w = (u2048 *)malloc(256);
    u8 d = 32 - (s / 8);

    for (u8 i = 0; i < d; i++)
        w->n[i] = 0;

    for (u16 i = 1; i <= s; i += 8)
        w->n[(i / 8) + d] = ((u64)v[i - 1] << 56) | ((u64)v[i] << 48) | ((u64)v[i + 1] << 40) | ((u64)v[i + 2] << 32) | ((u64)v[i + 3] << 24) | ((u64)v[i + 4] << 16) | ((u64)v[i + 5] << 8) | (u64)v[i + 6];

    return w;
}

void printx(const u2048 *__restrict v)
{
    u8 *w = (u8 *)v->n;
    for (int i = 1; i <= 256; i++)
    {
        if (w[i - 1] & 0xf0)
            printf("%x ", w[i - 1]);
        else
            printf("0%x ", w[i - 1]);

        if (!(i % 8))
            printf("\n");
    }
    printf("\n");
}


void printb(const u2048 *__restrict v)
{
    for (s8 i = 0; i < 32; i++)
    {
        for (s8 j = 63; j > -1; j--)
        {
            if (v->n[i] & ((u64)1 << j))
                printf("1");
            else
                printf("0");
            if (!(j % 8))
                printf(" ");
        }
        printf("\n");
    }
}
void printb(u64 v)
{
    for (s8 j = 63; j > -1; j--)
    {
        if (v & ((u64)1 << j))
            printf("1");
        else
            printf("0");
        if (!(j % 8))
            printf(" ");
    }
    printf("\n");
}
void shift(u2048 *__restrict v, s32 n)
{
    s32 u = n / 64;
    s32 n0 = n;
    s32 chk_sign = n & 0x80000000;
    u64 ps0 = 0, ps1 = 0, ps2 = 0, ps3 = 0;
    s32 u0 = u;
    u64 s = 1;
    n0 -= u*64;
    s32 n1 = n0;

    if (!chk_sign) // positive
    {
        while (--n0) s |= (u64)1 << n0;
        for (u8 i = 0; i < u; i++)
        {
            for (u8 j = 0; j < 32; j++)
            {
                    ps1 = v->n[j];
                    v->n[j] = ps0;
                    ps0 = ps1;
            }
        }
        if (u0 != 0)
            while (--u0)
                v->n[u0 - 1] = 0;

        ps0 = 0; ps1 = 0; ps2 = 0;
        for (u8 i = u; i < 32; i++)
        {
            ps0 = v->n[i] >> n1;
            ps3 = v->n[i];
            v->n[i] = ps0 | ps1;
            ps1 = (ps3 & s) << (64 - n1);
        }
    }
    else // negative
    {
        while(++n0) s |= (u64)1 << (-n0);
        for (u8 i = 0; i < -u; i++)
        {
            for (s8 j = 31; j > -1; j--)
            {
                ps1 = v->n[j];
                v->n[j] = ps0;
                ps0 = ps1;
            }
        }
        if (u0 != 0)
            while (++u0)
                v->n[32 + u0] = 0;
        
        ps0 = 0; ps1 = 0; ps2 = 0;
        for (s8 i = 31 + u; i >= 0; i--)
        {
            ps0 = v->n[i] << (64 - n1);
            ps3 = v->n[i];
            v->n[i] = ps0 | ps1;
            ps1 = (ps3 & s) >> (n1);
        }
    }
}

void add(const u2048*__restrict v, u2048*__restrict w)
{
    for (int i = 0; i < 32; i++){
        v->n[i] += w->n[i];
    }
}