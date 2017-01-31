/* A 6. gyakorlaton kiadott házi feladatok implementációját írja át strukturált programra, azaz a
   logikailag elkülönülő funkciókat külön függvényben valósítsa meg.

   6. gyakorlat 4. feladat átírása. Eredeti feladat szövege:

   Töltsön fel 1 és 100 közé eső véletlenszámokkal egy 10 elemű tömböt.
   a) Rendezze a tömb elemeit növekvő sorrendbe a következő eljárás szerint:
   n elemből kiválasztja a legkisebbet, ez lesz a rendezett sorozat első eleme.
   Utána n-1 elemből választja ki a legkisebbet, ez lesz a rendezett sorozat második eleme, és így tovább.
   b) A rendezett sorozaton implementálja a logaritmikus (intervallum felező) keresés algoritmusát.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void feltolt(int *tomb, int meret);
void kiir(int *tomb, int meret);
void rendez_novekvo(int *tomb, int meret);
int log_keres(int *tomb, int meret, int keresett);

int main() {
    int tomb[N];
    int keresett, kereses_eredmeny;

    feltolt(tomb, N);
    printf("Legeneralt tomb:\n");
    kiir(tomb, N);
    rendez_novekvo(tomb, N);
    printf("Rendezett tomb:\n");
    kiir(tomb, N);

    //logaritmikus kereses
    printf("\n\nKereses rendezett tombben:\nKeresett ertek: ");
    scanf("%d", &keresett);
    kereses_eredmeny = log_keres(tomb, N, keresett);
    if (kereses_eredmeny == -1) printf("A keresett ertek nem talalhato");
    else printf("A keresett ertek a %d. a tombben (indexe %d).",
                kereses_eredmeny+1, kereses_eredmeny);

    return 0;
}

void feltolt(int *tomb, int meret) {
    int i;
    srand(time(NULL));

    for (i=0; i < meret; i++) {
        tomb[i] = rand() % 100 + 1;
    }
}

void kiir(int *tomb, int meret) {
    int i;

    for (i=0; i < meret; i++) {
        printf("%d\t", tomb[i]);
    }
    printf("\n");
}

void rendez_novekvo(int *tomb, int meret) {
    int i, j;
    int min, min_index, seged;

    for (i=0; i < meret; i++) {
        for (j=i, min = tomb[j]; j < meret; j++) {
            if (tomb[j] <= min) {
                    min = tomb[j];
                    min_index = j;
            }
        }

        seged = tomb[min_index];   //
        tomb[min_index] = tomb[i]; // ket ertek felcserelese segedvaltozoval
        tomb[i] = seged;           //
    }

}

int log_keres(int *tomb, int meret, int keresett) {
    int talalt = 0;
    int also = 0;
    int felso = 9;
    int kozepso = N/2;

    while (also <= felso && talalt == 0) {
        kozepso = (also+felso)/2;
        if (tomb[kozepso] == keresett) talalt = 1;
        if (tomb[kozepso] < keresett) also = kozepso+1;
        if (tomb[kozepso] > keresett) felso = kozepso-1;
    }

    if (talalt) return kozepso; // if (talalt != 0) return kozepso;
    else return -1;
}
