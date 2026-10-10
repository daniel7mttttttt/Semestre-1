#include <iostream>

using namespace std;

double grupoA[5];
double grupoB[5];
double grupoC[5];


int main() {
    cout << " " << endl;
    cout << " Ingrese los 5 promedios del grupo A: " << endl;
    cout << "======================================" << endl;

    for (int i = 0; i < 5; i++) {
        cin >> grupoA[i];
    }

    cout << " " << endl;
    cout << " Ingrese los 5 promedios del grupo B: " << endl;
    cout << "======================================" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> grupoB[i];
    }

    system("cls");

    for (int i = 0; i < 5; i++) {
        if (grupoA[i] >= grupoB[i])
            grupoC[i] = grupoA[i];

        else {
            grupoC[i] = grupoB[i];
        }
    }

    cout << "Grupo A\tGrupo B\tPromedio Mayor" << endl;
     for (int i = 0; i < 5; i++) {
         cout << grupoA[i] << "   \t   " << grupoB[i] << "\t   " << grupoC[i] << endl;
     }

    return 0;
}









