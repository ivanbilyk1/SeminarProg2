#include <stdio.h>
#include "stdlib.h"
#include "time.h"

typedef struct {
	int pole[101];
}KCM;

void Inicializacia(KCM* kcm) {
    for (int i = 0; i <= 100; i++) {
        kcm->pole[i] = 0;
    }
}

void ADD(KCM* kcm, int number) {
    if (number > 0 && number <= 100) {
        kcm->pole[number] = 1;
    }
}

KCM Ziednotenia(KCM kcm1, KCM kcm2) {
    KCM result;
    Inicializacia(&result);

    for (int i = 1; i <= 100; i++) {
        if (kcm1.pole[i] || kcm2.pole[i]) {
            result.pole[i] = 1;
        }
    }

    return result;
}

KCM Pretin(KCM kcm1, KCM kcm2) {
    KCM result;
    Inicializacia(&result);

    for (int i = 1; i <= 100; i++) {
        if (kcm1.pole[i] && kcm2.pole[i]) {
            result.pole[i] = 1;
        }
    }

    return result;
}


int main() {
    srand((unsigned int)time(NULL));
    int n1 = rand() % (10 + 1);
    int n2 = rand() % (10 + 1);
    int n3 = rand() % (10 + 1);
    int n4 = rand() % (10 + 1);
    int n5 = rand() % (10 + 1);
    int n6 = rand() % (10 + 1);
    printf("%d %d %d %d %d %d\n", n1, n2, n3, n4, n5, n6);
    KCM kcm1, kcm2, ziednotenia, pretin;
    Inicializacia(&kcm1);
    Inicializacia(&kcm2);

    ADD(&kcm1, n1);
    ADD(&kcm1, n2);
    ADD(&kcm1, n3);

    ADD(&kcm2, n4);
    ADD(&kcm2, n5);
    ADD(&kcm2, n6);

    ziednotenia = Ziednotenia(kcm1, kcm2);
    pretin = Pretin(kcm1, kcm2);

    printf("Ziednotiena KCM: {");
    for (int i = 1; i <= 100; i++) {
        if (ziednotenia.pole[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("}\n");

    printf("Pretin KCM: {");
    for (int i = 1; i <= 100; i++) {
        if (pretin.pole[i] == 1) {
            printf("%d ", i);
        }
    } 
    printf("}\n");

	return 0;
}