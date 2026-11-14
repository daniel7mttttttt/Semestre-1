#include <sstream>
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

    Alumno nuevoAlumno = {"Diego Hernandez", "A010", {8, 9, 10}, 0};

    ofstream archivo("alumnos.txt", ios::app);

    if (!archivo.is_open()) {
            cout << "No se puede abrir alumnos.txt " << endl;
            return 1;
    }

    archivo << nuevoAlumno.nombre << '|'
            << nuevoAlumno.matricula << '|'
            << nuevoAlumno.calificaciones[0] << '|'
            << nuevoAlumno.calificaciones[1] << '|'
            << nuevoAlumno.calificaciones[2] << '|'
            << nuevoAlumno.grupo << '\n';
    
    archivo.close();

    if (!archivo) {
        cout << "Ocurrio un error " << endl;
        return 1;
    }

    cout << "Alumnos agregados correctamente" << endl;
    return 0;
}