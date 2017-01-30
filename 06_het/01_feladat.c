/* Készítsen programot, amely nyilvántartja az euró havi árfolyamait egy éven keresztül.
   Készítsen olyan kiírást, amelyben az első adatot követően a többi listaelem a megelőzőhöz képest
   számított relatív érték (pl: 301.1, 2.3, -0.4, 0.6, -0.2, stb.).
   Monoton nőtt-e az árfolyam az év során? */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //random szam generalas miatt

#define N 12
#define TESZT 1

int main() {
#if TESZT == 1 //random generalt ertekek
    double arfolyam[N];
#else //elore feltoltott tomb
    double arfolyam[N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
#endif

    int i, monoton = 1;

#if TESZT == 1
    srand(time(0));

    for (i=0; i < N; i++) {
        arfolyam[i] = (rand() % 51 + 270); //270-tol 320-ig terjedhet
    }
#endif

    printf("%7.2lf\n", arfolyam[0]);
    for (i=1; i < N; i++) {
        printf("%7.2lf\n", arfolyam[i] - arfolyam[i-1]);
    }

    //monotonitas vizsgalat
    for (i=1; i < N; i++) {
        if (arfolyam[i] - arfolyam[i-1] < 0) {
            monoton = 0;
        }
    }

    printf(monoton ? "Monoton novekvo.\n" : "Nem monoton novekvo.\n");

    return 0;
}
