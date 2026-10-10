#include <iostream>
using namespace std;

void mostrarNumero() {

    int numeros[5] = { 10, 20, 30, 40, 50 };

    cout << "Numero: " << numeros[4] << endl;
    }

int main() {

    cout << "====================================" << endl;
    cout << "       ERROR DE MEMORIA" << endl;
    cout << "====================================" << endl;

    mostrarNumero();

    return 0;
    }
