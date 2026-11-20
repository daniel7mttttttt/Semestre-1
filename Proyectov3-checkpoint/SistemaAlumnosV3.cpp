#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Alumno {
    string nombre;
    string matricula;
    float calificaciones[3] = {};
    int grupo = -1;
};

struct Maestro {
    string nombre;
    string materia;
};

struct Grupo {
    string nombre;
    string carrera;
};

float promedio(const Alumno& alumno) {
    return (alumno.calificaciones[0] +
            alumno.calificaciones[1] +
            alumno.calificaciones[2]) / 3;
}

void guardarDatos(const vector<Alumno>& alumnos,
                  const vector<Grupo>& grupos,
                  const vector<Maestro>& maestros) {
    ofstream archivo("sistema_alumnos.txt");

    if (!archivo.is_open()) {
        cout << "\nNo se pudo crear el archivo.\n";
        return;
    }

    archivo << grupos.size() << '\n';
    for (int i = 0; i < grupos.size(); i++) {
        archivo << grupos[i].nombre << '\n';
        archivo << grupos[i].carrera << '\n';
    }

    archivo << maestros.size() << '\n';
    for (int i = 0; i < maestros.size(); i++) {
        archivo << maestros[i].nombre << '\n';
        archivo << maestros[i].materia << '\n';
    }

    archivo << alumnos.size() << '\n';
    for (int i = 0; i < alumnos.size(); i++) {
        archivo << alumnos[i].nombre << '\n';
        archivo << alumnos[i].matricula << '\n';
        archivo << alumnos[i].calificaciones[0] << ' '
                << alumnos[i].calificaciones[1] << ' '
                << alumnos[i].calificaciones[2] << ' '
                << alumnos[i].grupo << '\n';
    }

    archivo.close();

    if (!archivo) {
        cout << "\nOcurrio un error al guardar los datos.\n";
    } else {
        cout << "\nDatos guardados correctamente.\n";
    }
}

void cargarDatos(vector<Alumno>& alumnos,
                 vector<Grupo>& grupos,
                 vector<Maestro>& maestros) {
    ifstream archivo("sistema_alumnos.txt");

    if (!archivo.is_open()) {
        cout << "\nNo hay archivo previo. El sistema inicia vacio.\n";
        return;
    }

    vector<Grupo> gruposLeidos;
    vector<Maestro> maestrosLeidos;
    vector<Alumno> alumnosLeidos;
    int cantidad;

    if (!(archivo >> cantidad) || cantidad < 0) {
        cout << "\nEl archivo no tiene un formato valido.\n";
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        Grupo grupo;

        if (!getline(archivo >> ws, grupo.nombre) ||
            !getline(archivo, grupo.carrera)) {
            cout << "\nEl archivo no tiene un formato valido.\n";
            return;
        }

        gruposLeidos.push_back(grupo);
    }

    if (!(archivo >> cantidad) || cantidad < 0) {
        cout << "\nEl archivo no tiene un formato valido.\n";
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        Maestro maestro;

        if (!getline(archivo >> ws, maestro.nombre) ||
            !getline(archivo, maestro.materia)) {
            cout << "\nEl archivo no tiene un formato valido.\n";
            return;
        }

        maestrosLeidos.push_back(maestro);
    }

    if (!(archivo >> cantidad) || cantidad < 0) {
        cout << "\nEl archivo no tiene un formato valido.\n";
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        Alumno alumno;

        if (!getline(archivo >> ws, alumno.nombre) ||
            !getline(archivo, alumno.matricula) ||
            !(archivo >> alumno.calificaciones[0]
                      >> alumno.calificaciones[1]
                      >> alumno.calificaciones[2]
                      >> alumno.grupo)) {
            cout << "\nEl archivo no tiene un formato valido.\n";
            return;
        }

        if (alumno.grupo < 0 ||
            alumno.grupo >= gruposLeidos.size()) {
            cout << "\nEl archivo contiene un grupo invalido.\n";
            return;
        }

        alumnosLeidos.push_back(alumno);
    }

    grupos = gruposLeidos;
    maestros = maestrosLeidos;
    alumnos = alumnosLeidos;

    cout << "\nDatos cargados correctamente: "
         << grupos.size() << " grupo(s), "
         << maestros.size() << " maestro(s) y "
         << alumnos.size() << " alumno(s).\n";
}

void generarReporte(vector<Alumno> alumnos,
                    const vector<Grupo>& grupos) {
    if (alumnos.empty()) {
        cout << "\nNo hay alumnos para generar el reporte.\n";
        return;
    }

    for (int i = 0; i < alumnos.size(); i++) {
        for (int j = i + 1; j < alumnos.size(); j++) {
            if (promedio(alumnos[j]) > promedio(alumnos[i])) {
                Alumno temporal = alumnos[i];
                alumnos[i] = alumnos[j];
                alumnos[j] = temporal;
            }
        }
    }

    ofstream reporte("reporte_alumnos.txt");

    if (!reporte.is_open()) {
        cout << "\nNo se pudo crear el reporte.\n";
        return;
    }

    reporte << "ALUMNOS ORDENADOS POR PROMEDIO\n\n";

    for (int i = 0; i < alumnos.size(); i++) {
        reporte << alumnos[i].nombre
                << " | Matricula: " << alumnos[i].matricula
                << " | Grupo: " << grupos[alumnos[i].grupo].nombre
                << " | Promedio: " << promedio(alumnos[i]) << '\n';
    }

    reporte.close();

    if (!reporte) {
        cout << "\nOcurrio un error al escribir el reporte.\n";
    } else {
        cout << "\nReporte creado en reporte_alumnos.txt.\n";
    }
}

int main() {
    int opcion = 0;
    vector<Alumno> alumnos;
    vector<Maestro> maestros;
    vector<Grupo> grupos;

    cargarDatos(alumnos, grupos, maestros);

    do {
        cout << "\n========== SISTEMA DE ALUMNOS ==========\n\n";
        cout << "1. Capturar alumnos\n";
        cout << "2. Capturar grupos\n";
        cout << "3. Capturar maestros\n";
        cout << "4. Mostrar reportes\n";
        cout << "5. Guardar datos\n";
        cout << "6. Generar reporte de texto\n";
        cout << "7. Salir\n";
        cout << "\nElige una opcion: ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nOpcion invalida.\n";
            continue;
        }

        switch (opcion) {
            case 1: {
                cout << "\n==Capturar alumnos==\n";

                if (grupos.empty()) {
                    cout << "\nPrimero registra un grupo con la opcion 2.\n";
                    break;
                }

                int cantidad;
                cout << "\nCuantos alumnos deseas registrar: ";

                if (!(cin >> cantidad) || cantidad < 1) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "\nLa cantidad debe ser mayor que cero.\n";
                    break;
                }

                for (int numero = 0; numero < cantidad; numero++) {
                    Alumno nuevoAlumno;

                    cout << "\nAlumno " << numero + 1
                         << " de " << cantidad << "\n\n";

                    cout << "Nombre del alumno: ";
                    getline(cin >> ws, nuevoAlumno.nombre);

                    cout << "Matricula del alumno: ";
                    getline(cin, nuevoAlumno.matricula);

                    cout << "\nGrupos disponibles:\n";
                    for (int i = 0; i < grupos.size(); i++) {
                        cout << i + 1 << ". " << grupos[i].nombre
                             << " | " << grupos[i].carrera << '\n';
                    }

                    int numeroGrupo;
                    do {
                        cout << "\nElige el numero del grupo: ";

                        if (!(cin >> numeroGrupo)) {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            numeroGrupo = 0;
                        }

                        if (numeroGrupo < 1 ||
                            numeroGrupo > grupos.size()) {
                            cout << "Este grupo no existe. Intenta de nuevo.\n";
                        }
                    } while (numeroGrupo < 1 ||
                             numeroGrupo > grupos.size());

                    nuevoAlumno.grupo = numeroGrupo - 1;

                    for (int i = 0; i < 3; i++) {
                        do {
                            cout << "Calificacion " << i + 1 << ": ";

                            if (!(cin >> nuevoAlumno.calificaciones[i])) {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                nuevoAlumno.calificaciones[i] = -1;
                            }

                            if (nuevoAlumno.calificaciones[i] < 0 ||
                                nuevoAlumno.calificaciones[i] > 10) {
                                cout << "Ingresa una calificacion de 0 a 10.\n";
                            }
                        } while (nuevoAlumno.calificaciones[i] < 0 ||
                                 nuevoAlumno.calificaciones[i] > 10);
                    }

                    alumnos.push_back(nuevoAlumno);
                    cout << "\nAlumno registrado correctamente.\n";
                }

                break;
            }

            case 2: {
                cout << "\n==Capturar grupos==\n\n";

                Grupo nuevoGrupo;

                cout << "Nombre del grupo: ";
                getline(cin >> ws, nuevoGrupo.nombre);

                cout << "Nombre de la carrera: ";
                getline(cin, nuevoGrupo.carrera);

                grupos.push_back(nuevoGrupo);
                cout << "\nGrupo registrado correctamente.\n";
                break;
            }

            case 3: {
                cout << "\n==Capturar maestros==\n\n";

                Maestro nuevoMaestro;

                cout << "Nombre del maestro: ";
                getline(cin >> ws, nuevoMaestro.nombre);

                cout << "Materia que imparte: ";
                getline(cin, nuevoMaestro.materia);

                maestros.push_back(nuevoMaestro);
                cout << "\nMaestro registrado correctamente.\n";
                break;
            }

            case 4: {
                cout << "\n========== REPORTES ==========\n";

                cout << "\nPromedio de cada alumno:\n\n";

                if (alumnos.empty()) {
                    cout << "No hay alumnos registrados.\n";
                }

                for (int i = 0; i < alumnos.size(); i++) {
                    cout << alumnos[i].nombre
                         << " | Grupo: "
                         << grupos[alumnos[i].grupo].nombre
                         << " | Promedio: "
                         << promedio(alumnos[i]) << '\n';
                }

                cout << "\nMejor alumno por grupo:\n\n";

                for (int g = 0; g < grupos.size(); g++) {
                    int mejor = -1;

                    for (int i = 0; i < alumnos.size(); i++) {
                        if (alumnos[i].grupo == g &&
                            (mejor == -1 ||
                             promedio(alumnos[i]) >
                             promedio(alumnos[mejor]))) {
                            mejor = i;
                        }
                    }

                    cout << grupos[g].nombre << ": ";

                    if (mejor == -1) {
                        cout << "Sin alumnos\n";
                    } else {
                        cout << alumnos[mejor].nombre
                             << " | Promedio: "
                             << promedio(alumnos[mejor]) << '\n';
                    }
                }

                cout << "\nAlumnos por carrera:\n\n";

                for (int g = 0; g < grupos.size(); g++) {
                    bool repetida = false;

                    for (int anterior = 0; anterior < g; anterior++) {
                        if (grupos[anterior].carrera ==
                            grupos[g].carrera) {
                            repetida = true;
                        }
                    }

                    if (repetida) {
                        continue;
                    }

                    int total = 0;

                    for (int i = 0; i < alumnos.size(); i++) {
                        if (grupos[alumnos[i].grupo].carrera ==
                            grupos[g].carrera) {
                            total++;
                        }
                    }

                    cout << grupos[g].carrera << ": "
                         << total << " alumno(s)\n";
                }

                cout << "\nMaestros registrados:\n\n";

                if (maestros.empty()) {
                    cout << "No hay maestros registrados.\n";
                }

                for (int i = 0; i < maestros.size(); i++) {
                    cout << maestros[i].nombre << " | "
                         << maestros[i].materia << '\n';
                }

                break;
            }

            case 5: {
                guardarDatos(alumnos, grupos, maestros);
                break;
            }

            case 6: {
                generarReporte(alumnos, grupos);
                break;
            }

            case 7: {
                cout << "\nSaliendo del sistema...\n";
                break;
            }

            default: {
                cout << "\nOpcion invalida.\n";
                break;
            }
        }

    } while (opcion != 7);

    return 0;
}