/* Írjon C programot, ami meghatározza egy megadott szám számjegyeinek az összegét. */

#include <stdio.h>

int main() {
    int szam;
    int osszeg = 0;

    printf("Tetszoleges szam: ");
    scanf("%d", &szam);

    while (szam != 0) {
        osszeg += szam % 10;
        szam /= 10;
    }

    printf("A szamjegyek osszege %d.\n", osszeg);

    return 0;
}
