#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string nombreArchivo;

    cout << "Nombre del archivo que desea abrir: ";
    getline(cin, nombreArchivo);

    ifstream archivo(nombreArchivo);

    if(!archivo.is_open()) {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
        cout << "Compruebe que exista este archivo y que el nombre sea el correcto" << endl;
    }
    else {
        cout << "Archivo abierto correctamente " << endl;
        archivo.close();
    }

    cout << "El programa se ejecuto correctamente" << endl;

    return 0;
}