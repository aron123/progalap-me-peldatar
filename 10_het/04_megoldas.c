/* Geometriai programban egy pont és egy kör egymáshoz viszonyított helyzetét
   vizsgáljuk. Állapítsa meg, hogy a megadott pont rajta van-e a megadott körvonalon,
   vagy azon belül, vagy azon kívül helyezkedik-e el. A pontot a koordinátáival adja meg,
   a kört pedig a középpont koordinátáival és a sugarával. */

#include <stdio.h>
#include <math.h>

struct descartes {
    double x;
    double y;
};

struct kor {
    struct descartes Kozeppont;
    int r;
};

int main() {
    struct descartes Pont;
    struct kor Korvonal;

    printf("A vizsgalando pont koordinatai [x, y]: ");
    scanf("%lf, %lf", &Pont.x, &Pont.y);
    printf("A kor kozeppontja [x, y]: ");
    scanf("%lf, %lf", &Korvonal.Kozeppont.x, &Korvonal.Kozeppont.y);
    printf("A kor sugara: ");
    scanf("%d", &Korvonal.r);

    /* adott (u, v) kozeppontu, r sugaru kor korvonalanak egyenlete:
       (x-u)^2 + (y-v)^2 = r^2

       koron kivuli pont:
       (x-u)^2 + (y-v)^2 > r^2

       koron beluli pont:
       (x-u)^2 + (y-v)^2 < r^2

       (Jelen esetben x es y helyere a megadott pont koordinatait kell helyettesitenunk.)
    */

    //hatvanyfuggveny: pow(double alap, double kitevo);
    if (pow(Pont.x - Korvonal.Kozeppont.x, 2) + pow(Pont.y - Korvonal.Kozeppont.y, 2) == pow(Korvonal.r, 2))
        printf("A pont rajta van a korvonalon.\n");
    else if (pow(Pont.x - Korvonal.Kozeppont.x, 2) + pow(Pont.y - Korvonal.Kozeppont.y, 2) > pow(Korvonal.r, 2))
        printf("A pont a korvonalon kivul van.\n");
    else
        printf("A pont a korvonalon belul van.\n");

    return 0;
}
