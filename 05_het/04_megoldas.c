/* Csúcsára állított egyenlőszárú, megadott magasságú háromszög kirajzolása. */

#include <stdio.h>

int main() {
    int sor;
    int magassag;
    int i;

    printf("Magassag: ");
    scanf("%d", &magassag);

    for (sor = 0; sor < magassag; sor++) {
        for (i = 0; i < sor; i++) {
            printf(" ");
        }
        for (i = 1; i < 2 * (magassag - sor); i++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
