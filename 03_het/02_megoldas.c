/* Írjon C programot, amely segédváltozó használatával felcserél két beolvasott értéket. */

#include <stdio.h>

int main() {
    int a;
    int b;
    int seged;

    printf("Adjon meg ket szamot, vesszovel elvalasztva: ");
    scanf("%d, %d", &a, &b);

    seged = a;
    a = b;
    b = seged;

    printf("\n%d, %d\n", a, b);

    return 0;
}

