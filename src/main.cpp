#include "divide-y-venceras.hpp"

using namespace std;

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
