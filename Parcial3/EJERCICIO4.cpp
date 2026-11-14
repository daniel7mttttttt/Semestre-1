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

void guardarTexto(ofstream& archivo, const string& texto) {
    size_t longitud = texto.size();

    archivo.write(reinterpret_cast<const char*>(&longitud),
                  sizeof(longitud));
    archivo.write(texto.data(), longitud);
}

int main() {
    vector<Alumno> alumnos = {
    {"Carlos Ramirez", "A003", {10, 9, 8}, 0},
    {"Maria Torres", "A004", {7, 8, 9}, 1},
    {"Pedro Garcia", "A005", {6, 7, 8}, 0}
    };

    ofstream texto("comparacion.txt");
    ofstream binario("alumnos.bin", ios::binary);

    if (!texto.is_open() || !binario.is_open()) {
        cout << "No se pudieron crear los archivos." << endl;
        return 1;
    }

    for (size_t i = 0; i < alumnos.size(); i++) {
        texto << alumnos[i].nombre << '|'
              << alumnos[i].matricula << '|';

        for (int j = 0; j < 3; j++) {
            texto << alumnos[i].calificaciones[j] << '|';
        }

        texto << alumnos[i].grupo << '\n';

        guardarTexto(binario, alumnos[i].nombre);
        guardarTexto(binario, alumnos[i].matricula);

        for (int j = 0; j < 3; j++) {
            binario.write(
                reinterpret_cast<const char*>(&alumnos[i].calificaciones[j]),
                sizeof(float)
            );
        }

        binario.write(
            reinterpret_cast<const char*>(&alumnos[i].grupo),
            sizeof(int)
        );
    }

    texto.close();
    binario.close();

    if (!texto || !binario) {
        cout << "Ocurrio un error al guardar los datos." << endl;
        return 1;
    }

    cout << "Alumnos guardados: " << alumnos.size() << endl;
    cout << "Archivos creados correctamente." << endl;

    return 0;
}