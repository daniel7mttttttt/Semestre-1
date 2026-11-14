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
    vector<Alumno> alumnos;
    ifstream archivo("alumnos.txt");

        if (!archivo.is_open()) {
            cout << "No se puede abrir alumnos.txt " << endl;
            return 1;
        }
    
    string linea;
    while (getline(archivo, linea)) {
        Alumno alumno;
        istringstream datos(linea);
        char separador1, separador2, separador3;

        if (getline(datos, alumno.nombre, '|') &&
            getline(datos, alumno.matricula, '|') &&
            datos >> alumno.calificaciones[0] >> separador1
                  >> alumno.calificaciones[1] >> separador2
                  >> alumno.calificaciones[2] >> separador3
                  >> alumno.grupo &&
            separador1 == '|' && separador2 == '|' && separador3 == '|') {
            alumnos.push_back(alumno);
            } else {
              cout << "Hay una linea en formato incorrecto " << endl;
            }

    }
    archivo.close();

    cout << "Alumnos recuperados: " << alumnos.size() << endl;

    for (int i = 0; i < alumnos.size(); i++) {
        cout << "\nNombre: " << alumnos[i].nombre << endl;
        cout << "Matricula: " << alumnos[i].matricula << endl;

        for (int j = 0; j < 3; j++){
            cout << "Calificacion " << j + 1 << ": "
            << alumnos[i].calificaciones[j] << endl;
        }
    cout << "Indice de grupo: " << alumnos[i].grupo << endl;
}
}