/* Írjon C programot, amely két megadott számról eldönti a feltételes operátor használatával, hogy
melyik a nagyobb. */

#include <stdio.h>

int main() {
    int a, b, nagyobb;

    printf("Ket szam, vesszovel elvalasztva: ");
    scanf("%d, %d", &a, &b);

    nagyobb = a > b ? a : b;
    printf("\n%d a nagyobb.\n", nagyobb);

    return 0;
}

