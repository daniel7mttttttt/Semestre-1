#include <iostream>
using namespace std;

double alumnos[10][3];

int main() {
    cout << " " << endl;
    cout << "  Ingrese los 10 promedios del grupo A: " << endl;
    cout << " ======================================= " << endl;
    cout << " " << endl;

    for (int i = 0; i < 10; i++) {
        cin >> alumnos[i][0];
    }

    cout << " " << endl;
    cout << "  Ingrese los 10 promedios del grupo B: " << endl;
    cout << " ======================================= " << endl;
    cout << " " << endl;
    for (int i = 0; i < 10; i++) {
        cin >> alumnos[i][1];
    }

                system("cls");

    for (int i = 0; i < 10; i++) {
        if (alumnos[i][0] >= alumnos[i][1])
            alumnos[i][2] = alumnos[i][0];

        else {
            alumnos[i][2] = alumnos[i][1];
        }
    }

    cout << "Grupo A\tGrupo B\tPromedio Mayor" << endl;
    for (int i = 0; i < 10; i++) {
        cout << alumnos[i][0] << "   \t   " << alumnos[i][1] << "\t   " << alumnos[i][2] << endl;
    }

    return 0;
}