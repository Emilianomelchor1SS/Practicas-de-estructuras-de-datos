#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int opcion;
    string nombre_estudiante;
    int edad_estudiante;
    int cantidad_calificaciones;
    vector<float> calificaciones;
    bool estudianteRegistrado = false;

    while (true) {
        cout << "\n===== Sistema de Calificaciones =====" << endl;
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Ver información del programa" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "Ingrese el nombre del estudiante: ";
                cin.ignore();
                getline(cin, nombre_estudiante);

                if (nombre_estudiante.find_first_of("0123456789") != string::npos) {
                    cout << "Ingrese un nombre válido." << endl;
                    break;
                }

                cout << "Ingrese la edad del estudiante: ";
                cin >> edad_estudiante;
                if (edad_estudiante < 0 || edad_estudiante > 120) {
                    cout << "La edad debe estar entre 0 y 120." << endl;
                    break;
                }

                cout << "Cuantas calificaciones desea ingresar?: ";
                cin >> cantidad_calificaciones;

                if (cantidad_calificaciones <= 0) {
                    cout << "Debe ingresar al menos una calificación." << endl;
                    break;
                }

                calificaciones.clear();

                for (int i = 0; i < cantidad_calificaciones; i++) {
                    float calificacion;
                    cout << "Ingrese la calificacion " << i + 1 << ": ";
                    cin >> calificacion;

                    if (calificacion < 0 || calificacion > 10) {
                        cout << "La calificacion debe estar entre 0 y 10." << endl;
                        i--;
                        continue;
                    }

                    calificaciones.push_back(calificacion);
                }

                estudianteRegistrado = true;
                cout << "Estudiante registrado correctamente." << endl;
                break;
            }

            case 2: {
                if (!estudianteRegistrado) {
                    cout << "No se han registrado calificaciones." << endl;
                    break;
                }

                float suma = 0;
                for (float calificacion : calificaciones) {
                    suma += calificacion;
                }

                float promedio = suma / calificaciones.size();
                cout << "El promedio del estudiante " << nombre_estudiante << " es: " << promedio << endl;
                break;
            }

            case 3:
                cout << "Saliendo del programa." << endl;
                return 0;

            default:
                cout << "Opción no válida." << endl;
        }
    }

    return 0;
}