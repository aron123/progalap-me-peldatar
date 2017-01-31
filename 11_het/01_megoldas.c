/* Hozzon létre egy autó adatait tárolni képes struktúrát,
   majd egy 10 autó adatait tároló dinamikusan lefoglalt tömböt.

   Definiálja a struktúrán elvégezhető alábbi műveleteket:
   beolvasás, kiírás, 15%-os árleszállítás, a legdrágább/legolcsóbb autó megkeresése,
   megadott árhatárok közé eső autók kiírása (pl.: 2 000 000 ft és 3 000 000 ft). */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define AUTONEV_MERET 16

struct kocsi {
    char nev[AUTONEV_MERET];
    double ar;
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

    /* dinamikus foglalas */
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

    free(kocsi); //lefoglalt tomb felszabaditasa

    return 0;
}

void beolvas(struct kocsi* tomb, int meret) {
    char autonev[AUTONEV_MERET];
    double ar;
    int i;

    for (i=0; i < meret; i++) {
        printf("\n%d. auto neve: ", i+1);
        fflush(stdin);
        scanf("%s", autonev);

        printf("Ar: ");
        fflush(stdin);
        scanf("%lf", &ar); // elvart formatum: '1234567'

        strcpy(tomb[i].nev, autonev);
        tomb[i].ar = ar;
    }

    return;
}

void kiir(struct kocsi* tomb, int meret) {
    int i;

    printf("%-20s\t%-9s\n", "Nev", "Ar");
    for (i=0; i < meret; i++) {
        printf("%-20s\t%.2lf Ft\n", tomb[i].nev, tomb[i].ar);
    }

    return;
}

void arleszallitas(struct kocsi* tomb, int meret, double szorzo) {
    int i;

    for (i=0; i < meret; i++) {
        tomb[i].ar *= szorzo;
    }

    return;
}

void kiir_legolcsobb(struct kocsi* tomb, int meret) {
    int i;
    int minindex;
    int minertek;

    minindex = 0;
    minertek = tomb[0].ar;
    for (i=1; i < meret; i++) {
        if (tomb[i].ar < minertek) {
            minindex = i;
            minertek = tomb[i].ar;
        }
    }

    printf("%-20s\t%-9s\n", "Nev", "Ar");
    printf("%-20s\t%.2lf Ft\n", tomb[minindex].nev, tomb[minindex].ar);

    return;
}

void kiir_legdragabb(struct kocsi* tomb, int meret) {
    int i;
    int maxindex;
    int maxertek;

    maxindex = 0;
    maxertek = tomb[0].ar;
    for (i=1; i < meret; i++) {
        if (tomb[i].ar > maxertek) {
            maxindex = i;
            maxertek = tomb[i].ar;
        }
    }

    printf("%-20s\t%-9s\n", "Nev", "Ar");
    printf("%-20s\t%.2lf Ft\n", tomb[maxindex].nev, tomb[maxindex].ar);

    return;
}

void kiir_kozott(struct kocsi* tomb, int meret, double min, double max) {
    int i;

    printf("\n\nTalalatok:\n");
    printf("%-20s\t%-9s\n", "Nev", "Ar");
    for (i=0; i < meret; i++) {
        if (min <= tomb[i].ar && tomb[i].ar <= max)
            printf("%-20s\t%.2lf Ft\n", tomb[i].nev, tomb[i].ar);
    }

    return;
}
