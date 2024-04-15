#include <stdio.h>

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
    KCM kcm1, kcm2, ziednotenia, pretin;
    Inicializacia(&kcm1);
    Inicializacia(&kcm2);

    ADD(&kcm1, 1);
    ADD(&kcm1, 2);
    ADD(&kcm1, 3);

    ADD(&kcm2, 3);
    ADD(&kcm2, 4);
    ADD(&kcm2, 5);

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