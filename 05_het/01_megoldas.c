/* Az E betű tükrözésével rajzoljon ki 3-ast a képernyőre. */

#include <stdio.h>

int main() {
    int sor;
    int oszlop;
    int magassag;

    printf("3-as magassaga (paratlan): ");
    scanf("%d", &magassag);

    for (sor = 0; sor < magassag; sor++) {
        for (oszlop = 0; oszlop < magassag; oszlop++) {
            if (sor == 0 || sor == magassag-1 || oszlop == magassag-1 || sor == magassag / 2) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
