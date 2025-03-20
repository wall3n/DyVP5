#include "divide-y-venceras.hpp"

using namespace std;


bool esPequeno(int p, int q, int m){
    return ((q - p + 1) <= m );
}

int Dividir(int p, int q){
    return (p+q) / 2;
}

Solucion SolucionDirecta(int p, int q, int m, char c, string A){
    Solucion sol = {.maxi = 0, .maxc = 0};
    if(( q - p + 1) < m){
        return sol;
    } else {
        int maxI = p, maxC = 0, contVentana = 0;
        for(int i = p; i < p+m; i++){
            if(A[i] == c){
                contVentana++;
            }
        }
        if(contVentana > maxC){
            maxC = contVentana;
        }
        for(int i = p+m; i < q + 1; i++){
            if(A[i] == c){
                contVentana++;
            }
            if(A[i - m] == c){
                contVentana--;
            }
            if(contVentana > maxC){
                maxC = contVentana;
                maxI = i - m + 1;
            }
        }
        sol.maxi = maxI;
        sol.maxc = maxC;
        return sol;
    }
}

Solucion Combinar(Solucion s1, Solucion s2, int h, int m, char c, string A){
    if(s1.maxc == m){
        return s1;
    }
    if(s2.maxc == m){
        return s2;
    }

    Solucion solucionFrontera = SolucionDirecta(h - m + 1, h + m - 1, m ,c , A);
    /*
    cout << "S1 = maxi: " << s1.maxi << " maxc: " << s1.maxc << endl;
    cout << "S2 = maxi: " << s2.maxi << " maxc: " << s2.maxc << endl;
    cout << "SF = maxi: " << solucionFrontera.maxi << " maxc: " << solucionFrontera.maxc << endl;
    */
    if(s1.maxc >= s2.maxc && s1.maxc >= solucionFrontera.maxc){
        return s1;
    } else if (s2.maxc >= s1.maxc && s2.maxc >= solucionFrontera.maxc){
        return s2;
    } else {
        return solucionFrontera;
    }
};

Solucion DyV(int p, int q, int m, char c, string A){
    int h;
    Solucion resultado;

    if(esPequeno(p, q, m)){
        resultado = SolucionDirecta(p, q, m, c, A);
    } else {
        h = Dividir(p, q);
        /*
        cout << "h es " << h << endl;
        */
        resultado = Combinar(DyV(p,h,m,c,A), DyV(h+1,q,m,c,A), h, m, c, A);
    }
    return resultado;
}

