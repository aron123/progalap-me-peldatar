/* Egy egyetemi oktató 5 csoportba oszt szét 150 db ZH dolgozatot (max. 50 pont):
   0-25 pont elégtelen,
   26-32 pont elégséges,
   33-39 pont közepes,
   40-45 pont jó,
   46-50 pont jeles.
   Készítsen C programot, amely elvégzi ezt a feladatot. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void feltolt(int* tomb, int meret);
void eredmeny_kiiras(int* tomb, int meret);

int main()
{
    int dolgozatok[150];

    feltolt(dolgozatok, 150);
    eredmeny_kiiras(dolgozatok, 150);

    return 0;
}

void feltolt(int* tomb, int meret) {
    int i;
    srand(time(0));

    for (i=0; i < meret; i++) {
        //random feltoltes teszteleshez:
        //tomb[i] = rand() % (50 + 1);

        //manualis felvitelhez:
        int jo = 1;
        do {
            if (!jo) //if (jo == 0)
                printf("Hibas pontszam, adja meg ujra:\n");
            printf("%d azonositoju tanulo jegye: ", i);
            scanf("%d", &tomb[i]);
            jo = 0;
        } while (tomb[i] < 0 || tomb[i] > 50);
    }

    return;
}

void eredmeny_kiiras(int* tomb, int meret) {
    int i;

    for (i=0; i < meret; i++) {
        switch (tomb[i]) {
        case 0 ... 25 :
            printf("Tanulo%d : %d pont : elegtelen\n", i, tomb[i]);
            break;
        case 26 ... 32 :
            printf("Tanulo%d : %d pont : elegseges\n", i, tomb[i]);
            break;
        case 33 ... 39 :
            printf("Tanulo%d : %d pont : kozepes\n", i, tomb[i]);
            break;
        case 40 ... 45 :
            printf("Tanulo%d : %d pont : jo\n", i, tomb[i]);
            break;
        case 46 ... 50 :
            printf("Tanulo%d : %d pont : jeles\n", i, tomb[i]);
        }
    }

    return;
}
