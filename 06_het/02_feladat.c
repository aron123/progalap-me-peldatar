/* Az egyetemi hallgatóknak félévente 6 vizsgájuk van. Félév végén az elért tanulmányi átlag alapján
   ki szeretnénk számolni a hallgató ösztöndíját a következő félévre: 3,5 alatt 0 Ft/hó, 3,6-4,0 között
   5eFt/hó, 4,1-4,5 között 10eFt/hó és 4,6-5,0 között 15eFt/hó.
   Írjon C programot, amely beolvassa egy hallgató vizsgajegyeit és eltárolja,
   kiszámítja a tanulmányi átlagot és kiírja az ösztöndíj havi összegét. */

#include <stdio.h>
#define VIZSGASZAM 6

int main()
{
    int jegyek[VIZSGASZAM];
    double atlag;
    int i;

    //jegyek bekerese
    for (i=0; i < VIZSGASZAM; i++) {
        do {
            printf("%d. Vizsgajegy: ", i+1);
            scanf("%d", &jegyek[i]);
            if (jegyek[i] < 1 || jegyek[i] > 5) printf("Hibas adat, adja meg ujra:\n");
        } while (jegyek[i] < 1 || jegyek[i] > 5);
    }

    //atlag kiszamitasa
    for (i=0, atlag=0; i < VIZSGASZAM; i++) {
        atlag += jegyek[i];
    }
    atlag /= VIZSGASZAM;

    printf("\nTanulmanyi atlag: %lf", atlag);

    printf("\nOsztondij: ");
    if (atlag < 3.5) printf("0 Ft/ho");
    else if (3.5 <= atlag && atlag < 4.0) printf("5 000 Ft/ho\n");
    else if (4.0 <= atlag && atlag < 4.5) printf("10 000 Ft/ho\n");
    else if (4.5 <= atlag && atlag < 5.0) printf("15 000 Ft/ho\n");

    return 0;
}
