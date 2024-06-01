#include <stdio.h>
#include "stdlib.h"
#include "time.h"

typedef struct {
	int* pole;
    int size;
}KCM;

void Inicializacia(KCM* kcm, int size) {
    kcm->pole = (int*)malloc(size * sizeof(int));
    kcm->size = size;
    for (int i = 0; i < size; i++) {
        kcm->pole[i] = 0;
    }
}

void ADD(KCM* kcm, int number) {
    if (number > 0 && number < kcm->size) {
        kcm->pole[number] = 1;
    }
}

void Ziednotenia(KCM* kcm1, KCM *kcm2, KCM *result) {
    Inicializacia(result, kcm1->size);

    for (int i = 1; i < kcm1->size; i++) {
        if (kcm1->pole[i] || kcm2->pole[i]) {
            result->pole[i] = 1;
        }
    }
}

void Pretin(KCM* kcm1, KCM* kcm2, KCM* result) {
    Inicializacia(result, kcm1->size);

    for (int i = 1; i < kcm1->size; i++) {
        if (kcm1->pole[i] && kcm2->pole[i]) {
            result->pole[i] = 1;
        }
    }
}

void FreeKCM(KCM* kcm) {
    free(kcm->pole);
    kcm->pole = NULL;
    kcm->size = 0;
}

void print(int size) {
    int n1 = rand() % ((size - 1) + 1);
    int n2 = rand() % ((size - 1) + 1);
    int n3 = rand() % ((size - 1) + 1);
    int n4 = rand() % ((size - 1) + 1);
    int n5 = rand() % ((size - 1) + 1);
    int n6 = rand() % ((size - 1) + 1);
    printf("%d %d %d    %d %d %d\n", n1, n2, n3, n4, n5, n6);
    KCM kcm1, kcm2, ziednotenia, pretin;
    Inicializacia(&kcm1, size);
    Inicializacia(&kcm2, size);
    Inicializacia(&ziednotenia, size);
    Inicializacia(&pretin, size);

    ADD(&kcm1, n1);
    ADD(&kcm1, n2);
    ADD(&kcm1, n3);

    ADD(&kcm2, n4);
    ADD(&kcm2, n5);
    ADD(&kcm2, n6);

    Ziednotenia(&kcm1, &kcm2, &ziednotenia);
    Pretin(&kcm1, &kcm2, &pretin);

    printf("Ziednotiena KCM: {");
    for (int i = 1; i < size; i++) {
        if (ziednotenia.pole[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("}\n");

    printf("Pretin KCM: {");
    for (int i = 1; i < size; i++) {
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
    int size;
    printf("zadajte hranicu: ");
    scanf_s("%d", &size);

    print(size);
	return 0;
}