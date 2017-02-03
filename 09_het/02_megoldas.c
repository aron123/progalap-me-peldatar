/* Implementálja az alapvető standard sztringkezelő függvényeket.
   Minden esetben próbálja ki a megfelelő standard függvényhívást is:
   sztring hosszának meghatározása, sztring másolás, sztring hozzáfűzés,
   karakter keresése sztringben, rész-sztring keresés. */

/*  +-----------------------+---------------+----------+
    | feladat               | sajat         | standard |
    +-----------------------+---------------+----------+
    | sztring hossz:        | sztr_hossz    | strlen   |
    | sztring masolas:      | sztr_masol    | strcpy   |
    | sztring hozzafuzes:   | sztr_hozzafuz | strcat   |
    | karakter kereses:     | kar_keres     | strchr   |
    | resz-sztring kereses: | rsztr_keres   | strstr   |
    +-----------------------+---------------+----------+
*/

#include <stdio.h>
#include <string.h>

int sztr_hossz(char* sztring); //strlen
void sztr_masol(char* cel, char* forras); //strcpy
void sztr_hozzafuz(char* mihez, char* mit); //strcat
char* kar_keres(char* sztring, char karakter); //strchr
char* rsztr_keres(char* forras_sztring, char* resz_sztring); //strstr
char eleje_egyezik(char* sztring, char* szubsztring);

int main() {
    /* sztring hossz */
    char* sztring = { "Ez egy karaktertomb" };
    int hossz = sztr_hossz(sztring);

    printf("Vizsgalt sztring: %s\n", sztring);
    printf("%d karaktert tartalmaz.\n", hossz);
    printf("Standard fuggveny eredmenye: %d\n\n", strlen(sztring));


    /* sztring masolas */
    char* forras = { "123456" };
    char cel[7];

    printf("Masolando sztring: %s\n", forras);
    sztr_masol(cel, forras);
    printf("Masolt sztring: %s\n", cel);

    char* forras2 = { "123456" };
    char cel2[7];
    strcpy(cel2, forras2);
    printf("Standard fuggvennyel: %s\n\n", cel2);


    /* sztring hozzafuzes */
    char* eleje = { "Ez itt egy " };
    char* vege = { "karaktertomb." };
    char mondat[30];

    //sajat fuggvennyel:
    sztr_masol(mondat, eleje); //a mondat elejet a "mondat" tombbe masoljuk.
    sztr_hozzafuz(mondat, vege); //a mondat elejehez hozzafuzzuk a veget.
    printf("Kulonallo sztringek: \"%s\", \"%s\"\n", eleje, vege);
    printf("Hozzafuzes utan: %s\n", mondat);

    //standard eljarassal:
    char std_mondat[30];
    strcpy(std_mondat, eleje);
    strcat(std_mondat, vege);
    printf("Standard hozzafuzessel: %s\n\n", std_mondat);


    /* karakter kereses */
    sztring = "www.github.com";
    char karakter = '.';
    printf("Szoveg: \"%s\"\n", sztring);

    char* valasz = kar_keres(sztring, karakter);
    printf("Szoveg a legelso \"%c\" karakter utan: %s\n", karakter, valasz);

    valasz = strchr(sztring, karakter);
    printf("Standard uton: %s\n\n", valasz);


    /* resz-sztring kereses */
    sztring = "www.github.com";
    char* resz_sztring = "git";

    printf("Teljes sztring: %s\n", sztring);
    printf("Resz sztring: %s\n", resz_sztring);
    valasz = rsztr_keres(sztring, resz_sztring);
    printf("Kereses eredmenye: %s\n", valasz);

    valasz = strstr(sztring, resz_sztring);
    printf("Standard uton: %s\n", valasz);

    return 0;
}

int sztr_hossz(char* sztring) {
    int i;

    for (i=0; sztring[i] != '\0'; i++);

    return i;
}

void sztr_masol(char* cel, char* forras) {
    int i;

    for (i=0; forras[i] != '\0'; i++)
        cel[i] = forras[i];
    cel[i] = '\0';

    return;
}

void sztr_hozzafuz(char* mihez, char* mit) {
    //elofeltetel: '\0' karakterrel lezart "mihez" sztring
    int i;

    /* megnezzuk, honnan tudunk hozzafuzni a "mihez" tombhoz */
    for (i=0; mihez[i] != '\0'; i++);

    /* hozzafuzzuk a "mit" tomb karaktereit a "mihez" tomb karaktereihez */
    int j=0;
    while (mit[j] != '\0') {
        mihez[i] = mit[j];
        i++;
        j++;
    }
    mihez[i] = '\0';

    return;
}

/* Pointert ad vissza, ami a sztringben szereplo karakter elso elofordulasara mutat.
   Ha a karakter nem talalhato, NULL pointerrel ter vissza. */
char* kar_keres(char* sztring, char karakter) {
    int i;

    for (i=0; sztring[i] != '\0'; i++) {
        if (sztring[i] == karakter)
            return sztring+i;
    }

    return NULL;
}

/* Azt vizsgalja, hogy a "resz" szerepel-e a "forras"-ban.
   Ha igen, az elso elofordulasra mutato pointert ad vissza,
   ha nem, akkor NULL pointert. */

char* rsztr_keres(char* forras, char* resz) {
    int i; //forras indexe
    int j; //forras indexe szubsztring vizsgalatakor
    int k; //szubsztring indexe
    int szubindex;
    int egyezik;

    for (i=0; forras[i] != '\0'; i++) {
        for (j=i, k=0, szubindex=i; resz[k] != '\0' && forras[j] != '\0'; j++, k++) {
            if (resz[k] == forras[j]) {
                egyezik = 1;
                continue;
            }
            else {
                egyezik = 0;
                break;
            }
        }

        if (egyezik) // if (egyezik != 0)
            return forras+szubindex;
    }

    return NULL;
}

/* 2 fuggvenyes megoldas szubsztring keresesre:

char* rsztr_keres(char* forras, char* resz) {
    int i;

    for (i=0; forras[i] != '\0'; i++) {
        if (eleje_egyezik(forras+i, resz) == 0)
            return forras+i;
    }

    return NULL;
}

//Megadja, hogy az atadott sztring eleje egyezik-e a szubsztringgel:
//Ha igen, 0-t ad vissza, ha nem, -1-et.
char eleje_egyezik(char* sztring, char* szubsztring) {
    int i;

    for (i=0; szubsztring[i] != '\0' && sztring[i] != '\0'; i++) {
        if (szubsztring[i] == sztring[i])
            continue;
        else
            return -1;
    }

    return 0;
}

*/
