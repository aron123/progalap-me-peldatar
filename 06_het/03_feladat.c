/* Írjon C programot az ötöslottó számainak véletlenszerű előállítására.
   Ügyeljen, hogy ne ismétlődjenek a számok!

   Megoldas:
   Legeneralunk a "szamok" tombbe egy szamsort 1-90-ig (lehetseges nyeroszamok),
   Ezekbol kihuzunk egy szamot, amit beirunk a "nyeroszamok" tombbe,
   A kihuzott szamot a "szamok" tombben kicsereljuk az utolso elemmel,
   Legkozelebb a "szamok" tomb elsotol utolso elotti elemeig valasztunk nyeroszamot,
   A kihuzott szamot a "szamok" tombben kicsereljuk az utolso elotti elemmel,
   Legkozelebb a "szamok" tomb elsotol utolso elotti elotti elemeig valasztunk nyeroszamot...
   ...es igy tovabb, pontosan otszor. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //random szam generalashoz

int main()
{
    int huzasok=5;
    int szamok[90], nyeroszamok[huzasok];
    int index, i;

    srand(time(NULL));

    //kihuzhato szamok tombje (1-90)
    for (i=0; i < 90; i++) {
        szamok[i] = i+1;
    }

    //nem lehet ismetlodes
    for (i=0; i < huzasok; i++) {
        index = rand() % (90-i);      //random index valasztasa egyre kisebb halmazbol
        nyeroszamok[i] = szamok[index];

        //a kihuzott szam helyere a tomb vizsgalt reszenek utolso elemet tesszuk
        szamok[index] = szamok[89-i];
    }

    printf("Otoslotto nyeroszamok:\n");
    for (i=0; i < huzasok; i++) {
        printf("%d\t", nyeroszamok[i]);
    }
    printf("\n");

    return 0;
}
