#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Alumno {
    string nombre;
    string matricula;
    float calificaciones[3] = {};
    int grupo = -1;
};

int main() {

    vector<Alumno> alumnos = {
    {"Benito Bodoque", "A002", {7, 7, 7}, 0},
    {"Yumei Mamei", "A001", {9, 9, 9}, 1}
    };

    ofstream archivo("alumnos.txt");

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }
    for (size_t i = 0; i < alumnos.size(); i++) {
        archivo << alumnos[i].nombre << '|'
            << alumnos[i].matricula << '|'
            << alumnos[i].calificaciones[0] << '|'
            << alumnos[i].calificaciones[1] << '|'
            << alumnos[i].calificaciones[2] << '|'
            << alumnos[i].grupo << '\n';

    }
    archivo.close();
    cout << "Alumnos guardados en alumnos.txt." << endl;
    return 0;
}