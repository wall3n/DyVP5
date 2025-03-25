#include "divide-y-venceras.hpp"

using namespace std;

/*
 * Determina si el problema es lo suficientemente pequeño para resolverlo directamente.
 * @param p Índice de inicio. 
 * @param q Índice de fin.
 * @param m Tamaño de la ventana. 
 * @return True si el tamaño de la cadena es menor o igual al tamaño requerido de la ventana, False en caso contrario. 
 */
bool esPequeno(int p, int q, int m){
    return ((q - p + 1) <= m );
}

/*
* Divide el problema en dos subproblemas.
* @param p Índice de inicio. 
* @param q Índice de fin.
* @return Índice del punto medio de la cadena. 
*/
int Dividir(int p, int q){
    return (p+q) / 2;
}

/*
 * Encuentra la posición de inicio y el número máximo de apariciones del carácter C en una ventana de tamaño m dentro de la cadena [p, q].
 * @param p Índice de inicio.
 * @param q Índice de fin.
 * @param m Tamaño de la ventana.
 * @param c Carácter a buscar.
 * @param A Cadena en la que se busca el carácter.
 * @return Una estructura Solucion con el índice de inicio y el máximo numero de apariciones del carácter c en la ventana m.
 */
Solucion SolucionDirecta(int p, int q, int m, char c, const string &A){
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

/*
 * Combina las soluciones de los subproblemas y encuentra la mejor solución.
 * @param s1 Solución del subproblema izquierdo.
 * @param s2 Solución del subproblema derecho.
 * @param h Índice del punto medio.
 * @param m Tamaño de la ventana.
 * @param c Carácter a buscar.
 * @param A Cadena en la que se busca el carácter.
 * @return La mejor solución entre los subproblemas y la solución en la frontera entre ellos.
 */
Solucion Combinar(Solucion s1, Solucion s2, int h, int m, char c, const string &A){
    if(s1.maxc == m){
        return s1;
    }
    if(s2.maxc == m){
        return s2;
    }

    Solucion solucionFrontera = SolucionDirecta(h - m + 1, h + m - 1, m ,c , A);
    if(s1.maxc >= s2.maxc && s1.maxc >= solucionFrontera.maxc){
        return s1;
    } else if (s2.maxc >= s1.maxc && s2.maxc >= solucionFrontera.maxc){
        return s2;
    } else {
        return solucionFrontera;
    }
};
/*
 * Algoritmo recursivo de Divide y Vencerás.
 * @param p Índice de inicio.
 * @param q Índice de fin.
 * @param m Tamaño de la ventana.
 * @param c Carácter a buscar.
 * @param A Cadena en la que se busca el carácter.
 * @return La mejor solución encontrada.
 */
Solucion DyV(int p, int q, int m, char c, const string &A){
    int h;
    Solucion resultado;

    if(esPequeno(p, q, m)){
        resultado = SolucionDirecta(p, q, m, c, A);
    } else {
        h = Dividir(p, q);
        resultado = Combinar(DyV(p,h,m,c,A), DyV(h+1,q,m,c,A), h, m, c, A);
    }
    return resultado;
}

