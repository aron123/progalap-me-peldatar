/* Írjon C programot a másodfokú egyismeretlenes egyenletek megoldásához! */

// A program alapja: https://www.programiz.com/c-programming/examples/quadratic-roots

#include <stdio.h>
#include <math.h>

struct komplex {
    double valos;
    double kepzetes;
};

struct megoldas {
    struct komplex gyok1;
    struct komplex gyok2;
};

struct megoldas megoldas(double a, double b, double c);

int main() {
    double a, b, c;
    struct megoldas Megoldas;

    printf("Egyutthatok [a, b, c formaban]: ");
    scanf("%lf, %lf, %lf", &a, &b, &c);

    Megoldas = megoldas(a, b, c);

    printf("\nMegoldasok:\n");
    printf("x1 = %.2lf + (%.2lf)i\n", Megoldas.gyok1.valos, Megoldas.gyok1.kepzetes);
    printf("x2 = %.2lf + (%.2lf)i\n", Megoldas.gyok2.valos, Megoldas.gyok2.kepzetes);

    return 0;
}

struct megoldas megoldas(double a, double b, double c) {
    double determinans;
    struct megoldas Megoldas;

    determinans = pow(b, 2) - 4 * a * c;

    // 1. eset: a gyokok valosak, es kulonbozoek:
    if (determinans > 0) {
        Megoldas.gyok1.valos = (-b + sqrt(determinans)) / (2 * a);
        Megoldas.gyok1.kepzetes = 0;

        Megoldas.gyok2.valos = (-b - sqrt(determinans)) / (2 * a);
        Megoldas.gyok2.kepzetes = 0;

        return Megoldas;
    }

    // 2. eset: a gyokok valosak, es azonosak:
    else if (determinans == 0) {
        Megoldas.gyok1.valos = -b / (2 * a);
        Megoldas.gyok1.kepzetes = 0;

        Megoldas.gyok2.valos = Megoldas.gyok1.valos;
        Megoldas.gyok2.kepzetes = Megoldas.gyok1.kepzetes;

        return Megoldas;
    }

    // 3. eset: a gyok komplex:
    else {
        Megoldas.gyok1.valos = -b / (2 * a);
        Megoldas.gyok1.kepzetes = sqrt(-determinans) / (2 * a);

        Megoldas.gyok2.valos = Megoldas.gyok1.valos;
        Megoldas.gyok2.kepzetes = -Megoldas.gyok1.kepzetes;

        return Megoldas;
    }
}
