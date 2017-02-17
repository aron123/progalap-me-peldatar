/* Keresse meg 1 és 100 között az összes ikerprím számpárt (olyan prímek, melyek különbsége 2). */

#include <stdio.h>

#define MINIMUM_SZAM 1
#define MAXIMUM_SZAM 100

//visszaadja, hogy az adott szam primszam-e (1: igen, 0: nem)
int prim_e (int szam) {
    int oszto;

    for (oszto = 2; oszto < szam; oszto++)
        if (szam % oszto == 0)
            return 0;

    return 1;
}

int main() {
    int szam;

    for (szam = MINIMUM_SZAM; szam <= MAXIMUM_SZAM; szam++)
        if (prim_e(szam) && prim_e(szam + 2))
            printf("%d es %d ikerprimek.\n", szam, szam + 2);

    return 0;
}
