#include <iostream>
using namespace std;

   void intercambiar(int* a, int* b) {

    int temporal = *a;
    *a = *b;
    *b = temporal;
    }

int main() {

    int numero1;
    int numero2;

        cout << "====================================" << endl;
        cout << "     INTERCAMBIO CON PUNTEROS" << endl;
        cout << "====================================" << endl;
        cout << " " << endl;

    cout << "Ingrese el primer numero: ";
    cin >> numero1;

    cout << "Ingrese el segundo numero: ";
    cin >> numero2;

        cout << " " << endl;
        cout << "====================================" << endl;
        cout << "     ANTES DEL INTERCAMBIO" << endl;
        cout << "====================================" << endl;
        cout << "Numero 1: " << numero1 << endl;
        cout << "Numero 2: " << numero2 << endl;

    intercambiar(&numero1, &numero2);

        cout << " " << endl;
        cout << "====================================" << endl;
        cout << "     DESPUES DEL INTERCAMBIO" << endl;
        cout << "====================================" << endl;
        cout << "Numero 1: " << numero1 << endl;
        cout << "Numero 2: " << numero2 << endl;

    return 0;
}
