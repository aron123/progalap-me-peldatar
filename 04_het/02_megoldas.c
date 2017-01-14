/* Készítsen C programot, amely kiszámítja két pozitív szám számtani és mértani közepét.
   Egész és lebegőpontos számokkal is teszteljék a kódot. */

#include <stdio.h>
#include <math.h>

int main() {
    //egész
    int a1, b1;
    int szamtani1, mertani1;

    printf("2 egesz szam, vesszovel elvalasztva: ");
    scanf("%d, %d", &a1, &b1);

    szamtani1 = (a1 + b1) / 2;
    mertani1 = pow((a1 * b1), (1 / 2));
    printf("Szamtani kozep: %d\nMertani kozep: %d\n", szamtani1, mertani1);

    //lebegőpontos
    double a2, b2;
    double szamtani2, mertani2;

    printf("\n\n2 lebegopontos szam, vesszovel elvalasztva: ");
    scanf("%lf, %lf", &a2, &b2);

    szamtani2 = (a2 + b2) / 2;
    mertani2 = pow((a2 * b2), 0.5);
    printf("Szamtani kozep: %lf\nMertani kozep: %lf", szamtani2, mertani2);

    return 0;
}

