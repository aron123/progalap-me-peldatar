/* Írja meg azt a C programot, amely megállapítja egy megadott dátumról,
   hogy hányadik napja az évnek. Vegye figyelembe, hogy szökõévrõl van-e szó!
   b) Készítse el az algoritmus fordítottját is:
      ha adott, hogy hányadik napja az évnek, mondja meg, hogy melyik napról van szó.
      Pl. 2016-ban (szökõév) az év 60. napja február 29.
   c) Készítse el azt a függvényt, amely megállapítja egy megadott dátumról, hogy helyes-e.
      Pl. 2016.01.32. hibás dátum. */

#include <stdio.h>

int szokoev(int evszam);
int hanyadik_nap(int ev, int ho, int nap);
int ervenyes(int ev, int ho, int nap);
struct datum datum(int ev, int nap);

struct datum {
    int ho;
    int nap;
};

int main() {
    int ev, ho, nap;
    struct datum Datum;

    printf("Datum [YYYY-MM-DD]: ");
    scanf("%d-%d-%d", &ev, &ho, &nap);
    printf("A megadott datum az ev %d. napja.\n", hanyadik_nap(ev, ho, nap));

    printf("Melyik ev melyik napjat formazzam datumma? [YYYY, DDD] ");
    scanf("%d, %d", &ev, &nap);
    Datum = datum(ev, nap);
    printf("A megadott nap datum formaban: %d-%d-%d\n", ev, Datum.ho, Datum.nap);

    printf("Datum ervenyesites [YYYY-MM-DD]: ");
    scanf("%d-%d-%d", &ev, &ho, &nap);
    if (ervenyes(ev,ho,nap))
        printf("A megadott datum letezik.\n");
    else
        printf("A megadott datum nem letezik.\n");

    return 0;
}

//visszaadja, hogy az atadott ev szokoev-e (1: igen, 0: nem)
int szokoev(int evszam) {
    if ((evszam % 400 == 0) || (evszam % 100 != 0 && evszam % 4 == 0))
        return 1;
    else
        return 0;
}

//visszaadja, hogy az atadott datum az ev hanyadik napja.
int hanyadik_nap(int ev, int ho, int nap) {
    int napok[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //nem szokoev
    int osszeg = 0;
    int i;

    if (szokoev(ev) && ho > 2)
        napok[1] = 29;

    for (i=0; i < ho-1; i++) //a megadott honap napjainak szamat nem adjuk az osszeghez
        osszeg += napok[i];

    osszeg += nap; // csak a ciklusbol kilepve, annyi napot, amennyi mar eltelt a honapban

    return osszeg;
}

//visszaadja, hogy az atadott ev atadott napja milyen datumra esik.
struct datum datum(int ev, int nap) {
    int napok[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //nem szokoev
    struct datum Datum;
    int i;

    if (szokoev(ev) && nap > napok[0]+napok[1])
        napok[1] = 29;

    for (i=0; napok[i] < nap; i++)
        nap -= napok[i];

    //i = honapok szama-1
    Datum.ho = i + 1;

    //megmarad a honap adott napjanak a szama.
    Datum.nap = nap;

    return Datum;
}

//visszaadja, hogy az atadott datum letezik-e (1: igen, 0: nem)
int ervenyes(int ev, int ho, int nap) {
    int napok[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (szokoev(ev))
        napok[1] = 29;

    if (ev > 0 && 1 <= ho && ho <= 12 && 1 <= nap && nap < napok[ho-1])
        return 1;
    else
        return 0;
}
