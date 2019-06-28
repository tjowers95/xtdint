#include <stdio.h>
#include "xtdint.h"
u2048*
U2048(u8* v, u16 s)
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

void
printx (u2048 * v)
{
  u8 *w = v->n;
  for (int i = 1; i <= 256; i++)
  {
      if (w[i - 1] & 0xf0)
        printf ("%x ", w[i - 1]);
	  else
	    printf ("0%x ", w[i - 1]);

	  if (!(i % 8))
	    printf ("\n");
    }
  printf ("\n");
}

void
printb(u2048 * v)
{
    for (int i = 0; i < 32; i++)
    {
        for (int j = 63; j > -1; j--)
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
    printf("\n");
}
void
shift (u2048 * v, s32 n)
{
    /* Solve for u64 */
    s32 u = n / 64;      // this will be the number of array positions that will be shifted
    /* Copy "n"'s state*/
    s32 n0 = n;          // we are going to need the number of bits as a counter after shifting the array positions
    s32 chk_sign = n & 0x80000000;
    
    if (!chk_sign) // positive
    {
        u64 ps0 = 0, ps1 = 0; // previous state
        s32 u0 = u; // save u state
        for (u8 i = 0; i < u; i++)
        {
            for (u8 j = 0; j < 32; j++)
            {
                ps1 = v->n[j];
                v->n[j] = ps0;
                ps0 = ps1;
            }
        }
        while (--u0) v->n[u0] = 0;
    }
    else // negative
    {
        u64 ps0 = 0, ps1 = 0;
        s32 u0 = u;
        for (u8 i = 0; i < -u; i++)
        {
            for (int j = 31; j > -1; j--)
            {
                ps1 = v->n[j];
                v->n[j] = ps0;
                ps0 = ps1;
            }
        }
    }
    
    
}

void
endian_mod(void* v, int n)
{
    
}
s2048* S2048(u8* v, u16 s){return U2048(v, s);}
