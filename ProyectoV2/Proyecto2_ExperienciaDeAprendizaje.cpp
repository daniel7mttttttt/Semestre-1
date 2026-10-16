#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Estructuras para almacenar los datos de alumnos, maestros y grupos.
struct Alumno {
    string nombre;
    string matricula;
    float calificaciones[3] = {};
    int grupo = 0;
};

struct Maestro {
	string nombre;
	string materia;
};

struct Grupo {
    string nombre;
    string carrera;
};


int main() {
    // Punteros para manejar arreglos dinamicos sin un limite fijo de registros.
				int opcion = 0;
				Alumno* alumnos = nullptr;
                Maestro* maestros = nullptr;
                Grupo* grupos = nullptr;

				int totalAlumnos = 0;
				int totalMaestros = 0;
				int totalGrupos = 0;
				
    do { // Menu principal que se repite hasta que el usuario decide salir.
        cout << " " << endl;    
		cout << "====================================" << endl;
        cout << "  PROYECTO ALUMNOS/MAESTROS/GRUPOS  " << endl;
        cout << "====================================" << endl;
        cout << " " << endl;
		cout << "1. Capturar alumnos" << endl;
        cout << " " << endl;
		cout << "2. Capturar grupos y carreras" << endl;
        cout << " " << endl;
		cout << "3. Capturar maestros" << endl; 
        cout << " " << endl;
		cout << "4. Mostrar reportes" << endl;
        cout << " " << endl;
		cout << "5. Salir" << endl;
        cout << " " << endl;
		cin >> opcion;

        switch (opcion) 
        {

            case 1: 
            {
              Alumno nuevoAlumno;

			  if (totalGrupos == 0) { // Comprueba que existan grupos antes de registrar alumnos.
				  cout << " " << endl;
				  cout << "No hay grupos registrados. Por favor, registre un grupo primero." << endl;
				  break;
			  }

              cout << " " << endl;
              cout << "==================================" << endl;
              cout << "        CAPTURA DE ALUMNOS        " << endl;
              cout << "==================================" << endl;

              cin.ignore(numeric_limits<streamsize>::max(), '\n');

              cout << "Nombre del alumno: " << endl;
              getline(cin, nuevoAlumno.nombre);

              cout << "Matrícula del alumno: " << endl;
              getline(cin, nuevoAlumno.matricula);

              for (int i = 0; i < 3; i++) { // Captura las tres calificaciones y verifica que sean validas.
                  cout << "Calificacion " << i + 1 << ": ";
                  cin >> nuevoAlumno.calificaciones[i];

                  // Verifica que el grupo seleccionado exista.
				  while (cin.fail() || nuevoAlumno.calificaciones[i] < 0 || nuevoAlumno.calificaciones[i] > 10) {
					  cin.clear();
					  cin.ignore(numeric_limits<streamsize>::max(), '\n');
					  cout << "Calificación inválida. Ingrese una calificación entre 0 y 10: ";
					  cin >> nuevoAlumno.calificaciones[i];
				  }
              }
              cout << " " << endl;

              // Muestra los grupos disponibles para asignar uno al alumno.
			  cout << "Grupos disponibles: " << endl;
              for (int i = 0; i < totalGrupos; i++) {
                  cout << i + 1 << ". " << grupos[i].nombre 
                      << " - " << grupos[i].carrera << endl;
              }
              int seleccion;

			  cout << "Seleccione el grupo del alumno: ";
			  cin >> seleccion;

			  while (cin.fail() || seleccion < 1 || seleccion > totalGrupos) {
				  cin.clear();
				  cin.ignore(numeric_limits<streamsize>::max(), '\n');

				  cout << "Selección inválida. Intente de nuevo: ";
				  cin >> seleccion;
			  }
              
              nuevoAlumno.grupo = seleccion - 1;
              Alumno* arregloNuevo = new Alumno[totalAlumnos + 1];// Crea un arreglo mas grande para guardar al nuevo alumno.

              for (int i = 0; i < totalAlumnos; i++) {
                  arregloNuevo[i] = alumnos[i];
              }

              arregloNuevo[totalAlumnos] = nuevoAlumno;

			  delete[] alumnos;// Libera el arreglo anterior y conserva el nuevo con todos los alumnos.
			  alumnos = arregloNuevo;
              
			  totalAlumnos++;


			  cout << " " << endl;
			  cout << "Alumno registrado correctamente." << endl;
              cout << "==================================" << endl;
              cout << "Nombre: " << nuevoAlumno.nombre << endl;
              cout << "Matricula: " << nuevoAlumno.matricula << endl;
              cout << "Grupo: " << grupos[nuevoAlumno.grupo].nombre << endl;
              cout << "Total de alumnos: " << totalAlumnos << endl;
              cout << "==================================" << endl;

              break;
             }
            case 2: 
            {
                Grupo nuevoGrupo;

                cout << " " << endl;
                cout << "==================================" << endl;
                cout << "   CAPTURA DE GRUPOS Y CARRERAS   " << endl;
                cout << "==================================" << endl;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Nombre del grupo: ";
                getline(cin, nuevoGrupo.nombre);

                cout << "Carrera: ";
                getline(cin, nuevoGrupo.carrera);

                Grupo* arregloNuevo = new Grupo[totalGrupos + 1];

                for (int i = 0; i < totalGrupos; i++) {
                    arregloNuevo[i] = grupos[i];
                }

                arregloNuevo[totalGrupos] = nuevoGrupo;

                delete[] grupos;
                grupos = arregloNuevo;

                totalGrupos++;// Actualiza la cantidad de grupos registrados.

                cout << " " << endl;
                cout << "Grupo registrado correctamente." << endl;
                cout << "Total de grupos: " << totalGrupos << endl;
                cout << "====================================" << endl;

                break;
            }


            case 3: 
            {

                Maestro nuevoMaestro;

                cout << " " << endl;
                cout << "==================================" << endl;
                cout << "       CAPTURA DE MAESTROS        " << endl;
                cout << "==================================" << endl;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');


                cout << "Nombre del maestro: ";
                getline(cin, nuevoMaestro.nombre);

                cout << "Materia: ";
                getline(cin, nuevoMaestro.materia);

                Maestro* arregloNuevo = new Maestro[totalMaestros + 1];

                for (int i = 0; i < totalMaestros; i++) {
                    arregloNuevo[i] = maestros[i];
                }
                arregloNuevo[totalMaestros] = nuevoMaestro;

                delete[] maestros;
                maestros = arregloNuevo;

                totalMaestros++;

                cout << " " << endl;
                cout << "Maestro registrado correctamente." << endl;
                cout << "Total de maestros: " << totalMaestros << endl;
                cout << "====================================" << endl;

                break;
            }

            case 4:
            {
                system("cls");

                cout << " " << endl;
                cout << "==================================" << endl;
                cout << "             REPORTES             " << endl;
                cout << "==================================" << endl;

                if (totalAlumnos == 0) {
                    cout << "No hay alumnos registrados todavia." << endl;
                    break;
                }

                

                cout << " " << endl;
                cout << "PROMEDIO DE CADA ALUMNO" << endl;
                cout << "==================================" << endl;

                for (int i = 0; i < totalAlumnos; i++) {// Calcula y muestra el promedio individual de cada alumno.
                    float suma = 0;

                    for (int p = 0; p < 3; p++) {
                        suma += alumnos[i].calificaciones[p];
                    }

                    float promedio = suma / 3;

                    cout << " " << endl;
                    cout << "Alumno: " << alumnos[i].nombre << endl;
                    cout << "Matricula: " << alumnos[i].matricula << endl;
                    cout << "Carrera: " << grupos[alumnos[i].grupo].carrera << endl;
                    cout << "Grupo: " << grupos[alumnos[i].grupo].nombre << endl;
                    cout << "Promedio: " << promedio << endl;
                    cout << "----------------------------------" << endl;
                }

                

                cout << " " << endl;
                cout << "MEJOR ALUMNO POR GRUPO" << endl;// Busca al alumno con el promedio mas alto de cada grupo.
                cout << "==================================" << endl;

                for (int g = 0; g < totalGrupos; g++) {

                    float mejorPromedio = -1;
                    int mejorAlumno = -1;

                    for (int i = 0; i < totalAlumnos; i++) {

                        if (alumnos[i].grupo == g) {

                            float suma = 0;

                            for (int p = 0; p < 3; p++) {
                                suma += alumnos[i].calificaciones[p];
                            }

                            float promedio = suma / 3;

                            if (promedio > mejorPromedio) {// Actualiza el mejor promedio cuando encuentra uno mayor.
                                mejorPromedio = promedio;
                                mejorAlumno = i;
                            }
                        }
                    }

                    cout << " " << endl;
                    cout << "Grupo: " << grupos[g].nombre << endl;

                    if (mejorAlumno != -1) {
                        cout << "Mejor alumno: " << alumnos[mejorAlumno].nombre << endl;
                        cout << "Promedio: " << mejorPromedio << endl;
                    }
                    else {
                        cout << "No hay alumnos registrados en este grupo." << endl;
                    }

                    cout << "----------------------------------" << endl;
                }

                // Cuenta los alumnos de cada carrera sin repetir carreras.

                cout << " " << endl;
                cout << "ALUMNOS POR CARRERA" << endl;
                cout << "==================================" << endl;

                for (int g = 0; g < totalGrupos; g++) {

                    bool carreraMostrada = false;

                    for (int j = 0; j < g; j++) {
                        if (grupos[g].carrera == grupos[j].carrera) {
                            carreraMostrada = true;
                            break;
                        }
                    }

                    if (carreraMostrada) {// Evita mostrar una carrera que ya fue contabilizada.
                        continue;
                    }

                    int contador = 0;

                    for (int i = 0; i < totalAlumnos; i++) {

                        int grupoAlumno = alumnos[i].grupo;

                        if (grupos[grupoAlumno].carrera == grupos[g].carrera) {
                            contador++;
                        }
                    }

                    cout << "Carrera: " << grupos[g].carrera << endl;
                    cout << "Total de alumnos: " << contador << endl;
                    cout << "----------------------------------" << endl;
                }

                break;
            }

			case 5:
				cout << "Saliendo del programa..." << endl;
				break;
            default:
				cout << "Opción no valida. Intente de nuevo." << endl;
				break;
        }

    } while (opcion != 5);
    
    // Libera la memoria de los arreglos dinamicos antes de terminar.
	delete[] alumnos;
    delete[] grupos;
	delete[] maestros;

    return 0;
}







                                  
                                       