#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string nombrecompleto;
string nombre;
string apellido;


int main()
{
	cout << "Ingrese su nombre completo: ";
	getline(cin, nombrecompleto);

	

		size_t espacio = nombrecompleto.find(' ');
	nombre = nombrecompleto.substr(0, espacio);
	apellido = nombrecompleto.substr(espacio + 1);
	
	bool tienenumeros = false;

	for (size_t i = 0; i < nombre.length(); i++) {

		if (isdigit(nombre[i])) {
			tienenumeros = true;
			break;
		}
	}
	for (size_t i = 0; i < apellido.length(); i++) {

		if (isdigit(apellido[i])) {
			tienenumeros = true;
			break;
		}
	}

	if (tienenumeros) {
		cout << " " << endl;
		cout << "Error: El nombre y el apellido no pueden contener numeros." << endl;
		cout << " " << endl;
	}
	else {
		cout << " " << endl;
		cout << "Nombre: " << nombre << endl;
		cout << " " << endl;
		cout << "Apellido: " << apellido << endl;
	}

	


			
			
return 0;
}
