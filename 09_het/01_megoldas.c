/* Egy beolvasott karaktert lineáris kereső eljárással keressen meg az angol ábécében
   (az ábécé betűit tárolja inicializált karakter tömbben). */

#include <stdio.h>

int lin_keres(char* tomb, int meret, char keresett);

int main() {
    char angolabc[] = { "abcdefghijklmnopqrstuvxyz" };
    char keresett;
    int hanyadik;

    printf("Keresett betu: ");
    keresett = getchar();

    hanyadik = lin_keres(angolabc, sizeof(angolabc)/sizeof(angolabc[0]), keresett);

    if (hanyadik == -1)
        printf("Hiba, a keresett karakter nem talalhato.\n");
    else
        printf("\nA %c betu %d. az angol abeceben.\n", keresett, hanyadik+1);

    return 0;
}

/* Visszaadja a keresett betu indexet az adott tombben.
   Ha nem talalhato, -1 ertekkel ter vissza. */
int lin_keres(char* tomb, int meret, char keresett) {
    int i;

    for (i=0; i < meret; i++) {
        if (tomb[i] == keresett)
            return i;
    }

    return -1;
}