#include <cstdlib>
#include <iostream>
#include <sys/time.h>
#include <fstream>
#include <string>

#include "divide-y-venceras.hpp"

using namespace std;

double caso_prueba(int n){
    string entrada;
    int m = rand() % n + 1;
    char c = 'a' + (rand() % 28);
    for(int i = 0 ; i < n; i++){
        entrada += 'a' + (rand() % 28);
    }

    struct timeval ti, tf;
    double time;
    gettimeofday(&ti, NULL);
    Solucion sol = DyV(0, entrada.length() - 1, m, c, entrada); 
    gettimeofday(&tf, NULL);
    time = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;
    return time;
    
}

int main(int argc, char **argv){
    
    if(argc != 3){
        cerr << "El uso de este programa es: ./generador <nºde casos> <fichero de salida>." << endl;
        return 1;
    }

    int n_casos = stoi(argv[1]);
    if(n_casos < 1){
        cerr << "El numero de casos de prueba debe ser minimo 1" << endl;
        return 1;
    }

    string file = argv[2];
    size_t check_csv = file.find(".csv");
    if(check_csv == string::npos){
        cerr << "El segundo parametro debe ser un archivo con extension .csv" << endl;
        return 1;
    }
    
    ofstream outputFile;
    outputFile.open(file, ios::trunc);

    for(int i = 0; i < n_casos; i++){
        int n = rand() % 1000001 + 100;
        string line = to_string(n) + "," + to_string(caso_prueba(n)) + "\n";
        outputFile << line;
    }

    outputFile.close();
    

    return 0;
}
