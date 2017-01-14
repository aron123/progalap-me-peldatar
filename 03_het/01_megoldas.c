#include <stdio.h>

int main() {
    int a;
    int b;
    int kerulet;
    int terulet;

    printf("Teglalap 2 oldalanak hossza vesszovel elvalasztva: ");
    scanf("%d, %d", &a, &b);

    kerulet = 2 * (a + b);
    terulet = a * b;

    printf("\nKerulet: %d", kerulet);
    printf("\nTerulet: %d\n", terulet);

    return 0;
}
