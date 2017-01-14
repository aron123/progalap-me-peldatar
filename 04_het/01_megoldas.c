/* Írjon C programot, amely két megadott számról eldönti, hogy melyik a nagyobb
   (szelekciós utasítás). Vizsgálja az egyenlőségüket is! */

#include <stdio.h>

int main() {
    int a, b;

    printf("2 szam, vesszovel elvalasztva: ");
    scanf("%d, %d", &a, &b);

    if (a == b)
        printf("A ket szam egyenlo.\n");
    else if (a > b)
        printf("%d szam a nagyobb.\n", a);
    else
        printf("%d szam a nagyobb.\n", b);

    return 0;
}
