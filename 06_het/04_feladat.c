/* Töltsön fel 1 és 100 közé eső véletlenszámokkal egy 10 elemű tömböt.
   a) Rendezze a tömb elemeit növekvő sorrendbe a következő eljárás szerint:
   n elemből kiválasztja a legkisebbet, ez lesz a rendezett sorozat első eleme.
   Utána n-1 elemből választja ki a legkisebbet, ez lesz a rendezett sorozat második eleme, és így tovább.
   b) A rendezett sorozaton implementálja a logaritmikus (intervallum felező) keresés algoritmusát.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int main()
{
    int tomb[N];
    int i, j, min, min_index, seged;
    //kereseshez
    int keresett, talalt, also, felso, kozepso;

    srand(time(NULL));

    //tomb feltoltese random ertekekkel
    for (i=0; i < N; i++) {
        tomb[i] = rand() % 100 + 1;
    }

    //tomb kiirasa
    printf("Eredeti tomb:\n");
    for (i=0; i < N; i++) {
        printf("%d\t", tomb[i]);
    }
    printf("\n");

    //tomb rendezese novekvo sorrendbe
    for (i=0; i < N; i++) {
        for (j=i, min = tomb[j]; j < N; j++) {
            if (tomb[j] <= min) {
                    min = tomb[j];
                    min_index = j;
            }
        }
        seged = tomb[min_index];   //
        tomb[min_index] = tomb[i]; // tomb[min_index] es tomb[i] felcserelese segedvaltozoval
        tomb[i] = seged;           //
    }

    //rendezett tomb kiiratasa
    printf("Rendezett tomb:\n");
    for (i=0; i < N; i++) {
        printf("%d\t", tomb[i]);
    }
    printf("\n");

    //logaritmikus kereses
    printf("Keresett ertek: ");
    scanf("%d", &keresett);

    talalt = 0;
    also = 0;
    felso = N-1;
    kozepso = N/2;

    while (also <= felso && talalt == 0) {
        kozepso = (also+felso)/2;
        if (tomb[kozepso] == keresett) talalt = 1;
        if (tomb[kozepso] < keresett) also = kozepso+1;
        if (tomb[kozepso] > keresett) felso = kozepso-1;
    }
    if (talalt == 1)
        printf("A keresett ertek a tomb %d. eleme (indexe %d).\n", kozepso+1, kozepso);
    else
        printf("A keresett ertek nem talalhato meg a tombben.\n");

    return 0;
}
