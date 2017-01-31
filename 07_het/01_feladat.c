/* Adott egy program, amely beolvassa, majd kiírja az euro havi árfolyamait 1 éven keresztül.
   Készítsen hozzá lineáris keresést megvalósító függvényt! */

//--------------------------------------------- ettol a ponttol adott a forras.
//eloforditonak szolo direktivak (#)
#include <stdio.h>
#define N 12

//sajat fuggvenyek prototipusa
void beolvas(double *tomb, int meret);
void kiir(double *tomb, int meret);
void keres(double *tomb, int meret);

//main fuggveny definicioja
int main() {
    double tomb[N];
    beolvas(tomb, N);
    kiir(tomb, N);
    keres(tomb, N);
    return 0;

}

//sajat fuggvenyek definicioja
void beolvas(double *tomb, int meret) {
    int i;
    int karakter;
    int jo;
    int beolvasott_adatok_szama;


    printf("HUF/EUR folyamok:\n");

    for (i = 0; i < meret; i++) {

        /* Tombelemek ellenorzott beolvasasa */
        jo = 0;
        do {
            printf("%d. ertek: ", i + 1);
            /* a scanf a sikeresen beolvasott adatok szamaval ter vissza */
            beolvasott_adatok_szama = scanf("%lf", &tomb[i]);

            if (beolvasott_adatok_szama == 1)
                jo = 1;
            else {
                printf("Hibas adat. Kerem adja meg ujra!\n");
                while ((karakter = getchar()) != '\n'); //stdin uritese
            }
        } while (!jo);

    }

    return;
}

void kiir(double *tomb, int meret) {
    int i;

    printf("\nAz eltarolt arfolyamok kiiratasa:\n");

    for(i = 0; i < meret; i++) {
        printf("%d. ertek: %.2lf\n", i + 1, tomb[i]);
    }
    printf("\n");
    return;
}

void keres(double *tomb, int meret) {
    
// --------------------------------------------- eddig a pontig adott a forras.

    double keresett, talalt;
    int index;

    printf("Keresett adat: ");
    scanf("%lf", &keresett);

    for (index=0; index < N; index++) {
        if (tomb[index] == keresett) {
            talalt=1;
            break;
        }
    }

    if (talalt) printf("A keresett elem a(z) %d. a listaban.", index+1);
    else printf("Nincs ilyen elem a listaban.");
}
