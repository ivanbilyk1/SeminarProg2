#include "KCM.h"

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