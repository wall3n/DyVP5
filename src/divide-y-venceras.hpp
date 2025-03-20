#ifndef __DIVIDE_Y_VENCERAS__
#define __DIVIDE_Y_VENCERAS__

#include <iostream>

using namespace std;

struct Solucion {
    int maxi;
    int maxc;
};

bool esPequeno(int p, int q, int m);

int Dividir(int p, int q);

Solucion SolucionDirecta(int p, int q, int m, char c, string A);

Solucion Combinar(Solucion s1, Solucion s2, int h, int m, char c, string A);

Solucion DyV(int p, int q, int m, char c, string A);

#endif
