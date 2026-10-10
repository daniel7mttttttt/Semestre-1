#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Alumno {
    string nombre;
    string matricula;
    float calificaciones[3];
};

int main() {

    Alumno alumnos[5];

    for (int i = 0; i < 5; i++) {

        cout << "Alumno " << i + 1 << endl;

        cout << "Nombre: ";
        getline(cin, alumnos[i].nombre);

        cout << "Matricula: ";
        getline(cin, alumnos[i].matricula);

     
        for (int x = 0; x < 3; x++) {
            cout << "Calificacion " << x + 1 << ": ";
            cin >> alumnos[i].calificaciones[x];
        }
        cin.ignore();

        float suma = 0;

        for (int j = 0; j < 3; j++) {
            suma += alumnos[i].calificaciones[j];
        }
        float promedio = suma / 3;

        cout << " " << endl;
        cout << "========================" << endl;
        cout << "Nombre: " << alumnos[i].nombre << endl;
        cout << "Matricula: " << alumnos[i].matricula << endl;
        cout << "Promedio: " << promedio << endl;
        cout << "========================" << endl;
        cout << " " << endl;
    }

    return 0;
}
