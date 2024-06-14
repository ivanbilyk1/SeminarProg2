#include <stdio.h>
#include "stdlib.h"
#include "time.h"

typedef struct {
	int* pole;
    int hranica;
}KCM;

void Inicializacia(KCM* kcm, int hranica) {
    kcm->pole = (int*)malloc(hranica * sizeof(int));
    kcm->hranica = hranica;
    for (int i = 0; i < hranica; i++) {
        kcm->pole[i] = 0;
    }
}

void ADD(KCM* kcm, int number) {
    if (number > 0 && number < kcm->hranica) {
        kcm->pole[number] = 1;
    }
}

void Ziednotenia(KCM* kcm1, KCM *kcm2, KCM *result) {
    Inicializacia(result, kcm1->hranica);

    for (int i = 1; i < kcm1->hranica; i++) {
        if (kcm1->pole[i] || kcm2->pole[i]) {
            result->pole[i] = 1;
        }
    }
}

void Pretin(KCM* kcm1, KCM* kcm2, KCM* result) {
    Inicializacia(result, kcm1->hranica);

    for (int i = 1; i < kcm1->hranica; i++) {
        if (kcm1->pole[i] && kcm2->pole[i]) {
            result->pole[i] = 1;
        }
    }
}

void FreeKCM(KCM* kcm) {
    free(kcm->pole);
    kcm->pole = NULL;
    kcm->hranica = 0;
}

void print(int hranica) {
    int n1 = rand() % ((hranica - 1) + 1);
    int n2 = rand() % ((hranica - 1) + 1);
    int n3 = rand() % ((hranica - 1) + 1);
    int n4 = rand() % ((hranica - 1) + 1);
    int n5 = rand() % ((hranica - 1) + 1);
    int n6 = rand() % ((hranica - 1) + 1);
    printf("%d %d %d    %d %d %d\n", n1, n2, n3, n4, n5, n6);
    KCM kcm1, kcm2, ziednotenia, pretin;
    Inicializacia(&kcm1, hranica);
    Inicializacia(&kcm2, hranica);
    Inicializacia(&ziednotenia, hranica);
    Inicializacia(&pretin, hranica);

    ADD(&kcm1, n1);
    ADD(&kcm1, n2);
    ADD(&kcm1, n3);

    ADD(&kcm2, n4);
    ADD(&kcm2, n5);
    ADD(&kcm2, n6);

    Ziednotenia(&kcm1, &kcm2, &ziednotenia);
    Pretin(&kcm1, &kcm2, &pretin);

    printf("Ziednotiena KCM: {");
    for (int i = 1; i < hranica; i++) {
        if (ziednotenia.pole[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("}\n");

    printf("Pretin KCM: {");
    for (int i = 1; i < hranica; i++) {
        if (pretin.pole[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("}\n");

    FreeKCM(&kcm1);
    FreeKCM(&kcm2);
    FreeKCM(&pretin);
    FreeKCM(&ziednotenia);
}

int main() {
    srand((unsigned int)time(NULL));
    int hranica;
    printf("zadajte hranicu: ");
    scanf("%d", &hranica);

    if (hranica <= 0) {
        printf("Hranica musi byt vacsia ako nula.\n");
        return 1;
    }

    print(hranica);
	return 0;
}