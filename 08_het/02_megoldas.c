/* Az 5. gyakorlat rajzoló algoritmusait valósítsa meg függvényként.

   5. gyakorlat 3. feladat megvalósítása. Feladat szövege:
   Egyenlőszárú, N magasságú háromszög kirajzolása.
*/

#include <stdio.h>

void haromszograjzolo(int magassag);

int main() {
    int n;

    printf("Haromszog magassaga: ");
    scanf("%d", &n);
    haromszograjzolo(n);

    return 0;
}

void haromszograjzolo(int magassag) {
    int sor, i;

    for (sor=1; sor<=magassag; sor++) {
        for (i=0; i < magassag-sor; i++)
            printf("%c", ' '); // space kiírása
        for (i=0; i < sor+(sor-1); i++)
            printf("%c", '*'); // *-ok kiírása

        printf("\n"); // sortörés
    }

    return;
}
