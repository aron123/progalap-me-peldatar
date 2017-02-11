/* Geometriai programban egy négyzetet az oldalhosszúságával és a bal felső
   csúcsának koordinátáival adunk meg. Határozza meg a négyzet középpontjának
   (az átló felezőpontjának) koordinátáit. */

#include <stdio.h>

struct descartes {
    double x;
    double y;
};

int main() {
    struct descartes Pont;
    double oldal;

    printf("Negyzet oldalainak hossza: ");
    scanf("%lf", &oldal);
    printf("Bal felso csucs koordinatai [x, y]: ");
    scanf("%lf, %lf", &Pont.x, &Pont.y);

    printf("A kozeppont koordinatai: x = %.2lf, y = %.2lf\n", Pont.x + (oldal / 2),
           Pont.y - (oldal / 2));

    return 0;
}
