#pragma once

#include <stdio.h>
#include "stdlib.h"
#include "time.h"

typedef struct {
	int* pole;
	int hranica;
}KCM;

void Inicializacia(KCM* kcm, int hranica);
void ADD(KCM* kcm, int number);
void Ziednotenia(KCM* kcm1, KCM* kcm2, KCM* result);
void Pretin(KCM* kcm1, KCM* kcm2, KCM* result);
void FreeKCM(KCM* kcm);
void print(int hranica);