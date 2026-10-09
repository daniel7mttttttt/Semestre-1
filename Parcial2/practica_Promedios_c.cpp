#include <iostream>

using namespace std;
double calificaciones[6];
double suma = 0;


int main() {
   
	cout << "Ingrese 5 calificaciones: " << endl;

    for (int i = 0; i < 5; i++) {
		cin >> calificaciones[i];

        suma += calificaciones[i];


    } 

    calificaciones[5] = suma / 5;

    cout << " Calificaciones: " << endl;
    cout << "=================" << endl;

    for (int i = 0; i < 5; i++) {
        cout<< calificaciones[i] << " " << endl;
    }

    cout << "=================" << endl;
    cout << "Promedio: " << calificaciones[5] << endl;

    return 0;
}
