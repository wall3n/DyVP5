#include <iostream>

using namespace std;

struct Solucion {
    int maxi;
    int maxc;
};

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

int main(){
    int opcion;

    cout << "========================" << endl;
    cout << "         MENU" << endl;
    cout << "========================" << endl;
    cout << "1. Probar DyV" << endl;
    cout << "2. Probar SolucionDirecta" << endl;
    cout << "3. Comprobación DyV vs SolucionDirecta" << endl;
    cout << "4. Generador de casos" << endl;
    cout << "5. Ayuda" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opción: ";

    do {
        cin >> opcion;

        if(opcion == 1){
            char c;
            int m;
            string entrada;
            cin >> c;
            cin >> m;
            cin.ignore();
            getline(cin, entrada);
            Solucion sol = DyV(0, entrada.length()-1, m, c, entrada);
            cout << "La solucion de la cadena ( " << entrada << " ) m=" << m << " c=" << c << " maxI: " << sol.maxi << " maxc: " << sol.maxc << endl;
        
        }

        if(opcion==2){
            char c;
            int m;
            string entrada;
            cout << "Introduce el caracter a analizar: ";
            cin >> c;
            cout << "Introduce el tamaño de la ventana: ";
            cin >> m;
            cin.ignore();
            cout << "Introduce la entrada: ";
            getline(cin, entrada);
            cout << entrada.length();
            Solucion sol = SolucionDirecta(0, entrada.length()-1, m, c, entrada);
            cout << "La solucion es maxI: " << sol.maxi << " maxc: " << sol.maxc << endl;
        
        }

        if(opcion==3){
            char c;
            int m;
            string entrada;
            cin >> c;
            cin >> m;
            cin.ignore();
            getline(cin, entrada);
            Solucion solDyV = DyV(0, entrada.length()-1, m, c, entrada);
            cout << "La solucion de la cadena ( " << entrada << " ) m=" << m << " c=" << c << " maxI: " << solDyV.maxi << " maxc: " << solDyV.maxc << endl;
            
            Solucion solDir = SolucionDirecta(0, entrada.length() - 1, m, c , entrada);
            cout << "La solucion de la cadena ( " << entrada << " ) m=" << m << " c=" << c << " maxI: " << solDir.maxi << " maxc: " << solDir.maxc << endl;

            cout << (solDyV.maxi == solDir.maxi && solDyV.maxc == solDir.maxc ? "LAS SOLUCIONES COINCIDEN" : "NO COINCIDEN") << endl;

        }


        if(opcion == 5){
            cout << "=================================================" << endl;
            cout << "              MENU DE AYUDA" << endl;
            cout << "=================================================" << endl;
            cout << "El formato de entrada del programa es el siguiente:" << endl;
            cout << endl;
            cout << "1) La primera línea es el nº de opcion." << endl;
            cout << "2) La segunda línea es un carácter, que es el objetivo a analizar." << endl;
            cout << "3) La tercera línea es un entero positivo, que representa el tamaño de la ventana." << endl;
            cout << "4) La cuarta línea es la cadena de entrada." << endl;
            cout << endl;
            cout << "Ejemplo de entrada:" << endl;
            cout << "1" << endl;
            cout << "c" << endl;
            cout << "5" << endl;
            cout << "aaaacccccaaacc" << endl;
            cout << "=================================================" << endl;
        }

        if(opcion == 6){
            cout << "Saliendo...";
        }
        cout << endl;
        
    } while (opcion != 6);


    return 0;
}
