/* Írjon C programot egy beolvasott N érték faktoriálisának kiszámítására.
   Figyelem! 8! = 40320, ami már nem fér el egy int típusú változóban.
   Korlátozza N értékét 0 és 10 közé, és válasszon megfelelő adattípust a faktoriális tárolásához!
*/

#include <stdio.h>

int main() {
    int szam;
    long int eredmeny;

    printf("Szam: ");
    scanf("%d", &szam);

    eredmeny = 1;

    if (szam <= 10 && szam >= 0){
        printf("%d", szam);
        while (szam >= 1){
            eredmeny *= szam; //eredmeny = eredmeny * szam
            szam--;  //szam = szam - 1
        }
        printf("! = %ld", eredmeny);
    }
    else
        printf("Hibas ertek!");

    return 0;
}

