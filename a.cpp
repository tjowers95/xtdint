#include "xtdint.h"
#include <stdio.h>
int main()
{
    u8 a[256], b[256];

    for (int i = 0; i < 256; i++)
        a[i] = 0x88;
    a[0] = 0x11; a[255] = 0x11;

    for (int i = 0; i < 256; i++)
        b[i] = 0x77;
    b[0] = 0xee; b[255] = 0xee;

    u2048 *v = U2048(a, 256);
    u2048 *w = U2048(b, 256);

    /*printf("v\n_\n");
    printb(v);
    printf("w\n_\n");
    printb(w);
    add(v, w);
    printf("w += v\n______\n");
    printb(w);

    printb(v);*/
    printf("%d\n", sizeof(long));
    printb(0xf0ab212289ca3312 + 0b1101101110110110);


    return 0;
}