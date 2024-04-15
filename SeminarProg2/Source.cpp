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

int main() {
	return 0;
}