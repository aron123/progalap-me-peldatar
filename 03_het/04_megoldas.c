/* Készítsen C programot, amely bekéri egy téglatest három oldalának hosszát és
   kiszámítja annak felszínét és térfogatát. A felszín számításánál ügyeljen a
   helyes zárójelezésre (a műveletek precedenciájára)! */

#include <stdio.h>

int main() {
    int a, b, c;
    double felszin;
    double terfogat;

    printf("A teglatest szelessege, magassaga, melysege: ");
    scanf("%d, %d, %d", &a, &b, &c);

    felszin = 2 * (a * b + a * c + b * c);
    terfogat = a * b * c;

    printf("\nFelszin: %.2lf", felszin);
    printf("\nTerfogat: %.2lf\n", terfogat);

    return 0;
}
