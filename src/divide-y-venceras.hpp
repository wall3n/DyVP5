#ifndef __DIVIDE_Y_VENCERAS__
#define __DIVIDE_Y_VENCERAS__

#include <iostream>
#include <string>

struct Solucion {
    int maxi;
    int maxc;
};

Solucion SolucionDirecta(int p, int q, int m, char c, const std::string &A);

Solucion DyV(int p, int q, int m, char c, const std::string &A);

#endif
