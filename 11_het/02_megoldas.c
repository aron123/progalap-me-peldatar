/* Az előző feladatot módosítsa úgy, hogy az autó struktúrán belül az árat összeg és 
   devizanem formájában tudjuk megadni (beágyazott struktúra) (pl.: 20000 USD, 2000000 HUF).
   
   Előző feladat szövege:
   Hozzon létre egy autó adatait tárolni képes struktúrát,
   majd egy 10 autó adatait tároló dinamikusan lefoglalt tömböt.

   Definiálja a struktúrán elvégezhető alábbi műveleteket:
   beolvasás, kiírás, 15%-os árleszállítás, a legdrágább/legolcsóbb autó megkeresése,
   megadott árhatárok közé eső autók kiírása (pl.: 2 000 000 ft és 3 000 000 ft). */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define AUTONEV_MERET 16
#define DEVIZANEV_MERET 4

struct ar {
    double osszeg;
    char deviza[DEVIZANEV_MERET];
};

struct kocsi {
    char nev[AUTONEV_MERET];
    struct ar Ar;
};

void beolvas(struct kocsi* tomb, int meret);
void kiir(struct kocsi* tomb, int meret);
void arleszallitas(struct kocsi* tomb, int meret, double szorzo);
void kiir_legolcsobb(struct kocsi* tomb, int meret);
void kiir_legdragabb(struct kocsi* tomb, int meret);
void kiir_kozott(struct kocsi* tomb, int meret, double min, double max);

int main() {
    int adatok_szama = 10;
    double alsohatar, felsohatar;

    struct kocsi* kocsi = malloc(adatok_szama * sizeof(struct kocsi));

    beolvas(kocsi, adatok_szama);
    kiir(kocsi, adatok_szama);

    printf("\n\nArleszallitas utan:\n");
    arleszallitas(kocsi, adatok_szama, 0.85); //15%-os arleszallitas
    kiir(kocsi, adatok_szama);

    printf("\n\nLegolcsobb auto:\n");
    kiir_legolcsobb(kocsi, adatok_szama);

    printf("\n\nLegdragabb auto:\n");
    kiir_legdragabb(kocsi, adatok_szama);

    printf("\n\nAuto keresese arhatarok kozott:\n");
    printf("Alsohatar: ");
    scanf("%lf", &alsohatar);
    printf("Felsohatar: ");
    scanf("%lf", &felsohatar);
    kiir_kozott(kocsi, adatok_szama, alsohatar, felsohatar);

    free(kocsi);

    return 0;
}

void beolvas(struct kocsi* tomb, int meret) {
    char autonev[AUTONEV_MERET];
    double osszeg;
    char deviza[DEVIZANEV_MERET];
    int i;

    for (i=0; i < meret; i++) {
        printf("\n%d. auto neve: ", i+1);
        fflush(stdin);
        scanf("%s", autonev);

        printf("Ar, deviza: ");
        fflush(stdin);
        scanf("%lf %s", &osszeg, deviza); // elvart formatum: '1234567 HUF'

        strcpy(tomb[i].nev, autonev);
        tomb[i].Ar.osszeg = osszeg;
        strcpy(tomb[i].Ar.deviza, deviza);
    }

    return;
}

void kiir(struct kocsi* tomb, int meret) {
    int i;

    printf("%-20s\t%-9s\n", "Nev", "Ar");
    for (i=0; i < meret; i++) {
        printf("%-20s\t%.2lf %-3s\n", tomb[i].nev, tomb[i].Ar.osszeg, tomb[i].Ar.deviza);
    }

    return;
}

void arleszallitas(struct kocsi* tomb, int meret, double szorzo) {
    int i;

    for (i=0; i < meret; i++) {
        tomb[i].Ar.osszeg *= szorzo;
    }

    return;
}

void kiir_legolcsobb(struct kocsi* tomb, int meret) {
    int i;
    int minindex;
    int minertek;

    minindex = 0;
    minertek = tomb[0].Ar.osszeg;
    for (i=1; i < meret; i++) {
        if (tomb[i].Ar.osszeg < minertek) {
            minindex = i;
            minertek = tomb[i].Ar.osszeg;
        }
    }

    printf("%-20s\t%-9s\n", "Nev", "Ar");
    printf("%-20s\t%.2lf %-3s\n", tomb[minindex].nev, tomb[minindex].Ar.osszeg,
           tomb[minindex].Ar.deviza);

    return;
}

void kiir_legdragabb(struct kocsi* tomb, int meret) {
    int i;
    int maxindex;
    int maxertek;

    maxindex = 0;
    maxertek = tomb[0].Ar.osszeg;
    for (i=1; i < meret; i++) {
        if (tomb[i].Ar.osszeg > maxertek) {
            maxindex = i;
            maxertek = tomb[i].Ar.osszeg;
        }
    }

    printf("%-20s\t%-9s\n", "Nev", "Ar");
    printf("%-20s\t%.2lf %-3s\n", tomb[maxindex].nev, tomb[maxindex].Ar.osszeg,
           tomb[maxindex].Ar.deviza);

    return;
}

void kiir_kozott(struct kocsi* tomb, int meret, double min, double max) {
    int i;

    printf("\n\nTalalatok:\n");
    printf("%-20s\t%-9s\n", "Nev", "Ar");
    for (i=0; i < meret; i++) {
        if (min <= tomb[i].Ar.osszeg && tomb[i].Ar.osszeg <= max)
            printf("%-20s\t%.2lf %-3s\n", tomb[i].nev, tomb[i].Ar.osszeg,
                   tomb[i].Ar.deviza);
    }

    return;
}
