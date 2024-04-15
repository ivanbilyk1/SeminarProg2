#include <stdio.h>

typedef struct {
	int pole[1001];
}KCM;

void Inicializacia(KCM* kcm) {
    for (int i = 0; i <= 1000; i++) {
        kcm->pole[i] = 0;
    }
}

void ADD(KCM* kcm, int number) {
    if (number > 0 && number <= 1000) {
        kcm->pole[number] = 1;
    }
}

KCM Ziednotenia(KCM kcm1, KCM kcm2) {
    KCM result;
    Inicializacia(&result);

    for (int i = 1; i <= 1000; i++) {
        if (kcm1.pole[i] || kcm2.pole[i]) {
            result.pole[i] = 1;
        }
    }

    return result;
}

KCM Pretin(KCM kcm1, KCM kcm2) {
    KCM result;
    Inicializacia(&result);

    for (int i = 1; i <= 1000; i++) {
        if (kcm1.pole[i] && kcm2.pole[i]) {
            result.pole[i] = 1;
        }
    }

    return result;
}


int main() {
	return 0;
}