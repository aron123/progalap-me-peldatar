/* Készítse el a ‘Gondoltam egy számot játék’ C programját. Algoritmusa:
    1. Állítson elő egy véletlenszámot 1 és 30000 között, és tárolja el. Ez lesz a gondolt szám.
    2. A felhasználótól kérjen be a program egy tippet.
    3. A megadott tippet hasonlítsa össze a gondolt számmal.
       Írja ki, hogy eltalálta, kisebb, vagy nagyobb számra gondoltunk-e.
    4. Ha nem találta el, vissza a 2. pontra. Ha eltalálta, kérdezze meg, hogy akar-e még játszani.
    5. Ha igen, vissza az 1. pontra. Ha nem, akkor vége a programnak.

   Ezt a programot dokumentálja:
   A program elején: készítő neve, email címe, készítés dátuma, utolsó módosítás dátuma, feladat rövid leírása.
*/

/* Keszito: Kiss Aron
   E-mail: ####@####.###
   Keszites datuma: 2017.01.31.
   Utolso modositas: 2017.01.31.
   Feladat: A program "gondol" egy szamra, amit a felhasznalonak ki kell talalnia.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int gondolt;
    int tipp;
    int talalt;
    char uj_jatek = 'I';

    while (uj_jatek == 'I' || uj_jatek == 'i') {
        talalt = 0;
        gondolt = rand() % 30000 + 1;
        printf("Kitalaltam a szamot!\n\n");

        while (talalt == 0) {
            printf("Tipp: ");
            scanf("%d", &tipp);

            if (tipp == gondolt) {
                printf("TALALAT!\n");
                talalt = 1;

                printf("Akar meg jatszani? [I/N] ");
                fflush(stdin);
                scanf("%c", &uj_jatek);
            }
            else if (tipp < gondolt)
                printf("Nagyobb szamra gondoltam.\n");
            else
                printf("Kisebb szamra gondoltam.\n");
        }
    }

    return 0;
}
