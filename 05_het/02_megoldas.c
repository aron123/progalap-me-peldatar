/* 2. Rajzoljon # karakterekből adott magasságú és szélességű paralelogrammát. */

#include <stdio.h>

int main() {
    int szelesseg, magassag;
    int sor, oszlop;
    int eltolas;

    printf("Szelesseg: ");
    scanf("%d", &szelesseg);
    printf("Magassag: ");
    scanf("%d", &magassag);

    for (sor = 0; sor < magassag; sor++) {
        for (eltolas = 0; eltolas < sor; eltolas++)
            printf(" ");

        for (oszlop = 0; oszlop < szelesseg; oszlop++)
            printf("#");

        printf("\n");
    }

    return 0;
}
