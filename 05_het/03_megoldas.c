/* Rajzoljon ki egy megadott magasságú, egyenlőszárú háromszöget!
   Módosítsa az előző algoritmust: csak a szárakat, illetve csak a
   háromszög keretét rajzolja ki. */

#include <stdio.h>

int main() {
    int sor;
    int oszlop;
    int magassag;

    printf("Magassag: ");
    scanf("%d", &magassag);

    //egyenlőszárú telt háromszög
    for (sor = 0; sor < magassag; sor++) {
        for(oszlop = 0; oszlop < magassag * 2 - 1; oszlop++) {
            if (oszlop >= magassag - sor - 1 && oszlop <= magassag + sor - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    //csak szárak
    for (sor = 0; sor < magassag; sor++) {
        for(oszlop = 0; oszlop < magassag * 2 - 1; oszlop++) {
            if (oszlop == magassag - sor - 1 || oszlop == magassag + sor - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    //háromszög körvonala
    for (sor = 0; sor < magassag; sor++) {
        for(oszlop = 0; oszlop < magassag * 2 - 1; oszlop++) {
            if (oszlop == magassag - sor - 1 || oszlop == magassag + sor - 1 ||
                    sor == magassag - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
