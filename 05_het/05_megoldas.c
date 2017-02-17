/* Keresse meg és irassa ki az első N db prímszámot.
   N értékének beolvasása ellenőrzéssel történjen. */

#include <stdio.h>

int prim_e(int szam);

int main() {
    int N;
    int szam;
    int primdb;
    int s;

    do {
        printf("Mennyi primszamot irjak ki? ");
        s = scanf("%d", &N);
        fflush(stdin);
    } while (s != 1 || N < 0);

    for (szam = 2, primdb = 0; primdb < N; szam++) {
        if (prim_e(szam)) {
            primdb++;
            printf("%d\n", szam);
        }
    }

    return 0;
}

//visszaadja, hogy az adott szam primszam-e (1: igen, 0: nem)
int prim_e (int szam) {
    int oszto;

    //van-e osztoja 2 es (szam - 1) kozott?
    for (oszto = 2; oszto < szam; oszto++)
        if (szam % oszto == 0)
            return 0; //ha van, 'hamis' ertekkel terunk vissza

    return 1; //egyebkent a szam prim
}
