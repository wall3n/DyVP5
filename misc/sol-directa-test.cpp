#include <iostream>

using namespace std;

int main() {
    string entrada;
    cout << "Introduce una secuencia de caracteres: ";
    getline(cin, entrada); // Permite leer toda la línea, incluidos espacios
    int n = entrada.length();
    
    int maxc = 0;
    int maxI = 0;

    int contVentana = 0;
    for(int i = 0; i < 5; i++){
        if(entrada[i] == 'c'){
            contVentana += 1;
        }
    }
    if(contVentana > maxc){
        maxc = contVentana;
    }
    for(int i = 5; i < n; i++){
        if(entrada[i] == 'c'){
            contVentana += 1;
        }
        if(entrada[i-5] == 'c'){
            contVentana -= 1;
        }

        if(contVentana > maxc){
            maxc = contVentana;
            maxI = i - 5 + 1;
        }
    }
    cout << "Has introducido: " << entrada << endl;
    cout << "La mayor ventana comienza en el indice " << maxI << "con un numero de apariciones " << maxc << endl;
    return 0;
}
