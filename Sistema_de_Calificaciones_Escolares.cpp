#include <iostream>
#include <string>
using namespace std;

int main() {
    int opcion;
    string nombre_estudiante;
    int edad_estudiante;
    float calificacion1, calificacion2, calificacion3;
    bool estudianteRegistrado = false;

    while (true) {
        cout << "\n===== Sistema de Calificaciones =====" << endl;
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Mostrar estudiantes" << endl;
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
                }// esta parte es prevencion de que el nombre no tenga algun numero

                cout << "Ingrese la edad del estudiante: ";
                cin >> edad_estudiante;
                if (edad_estudiante < 0 || edad_estudiante > 120) {
                    cout << "La edad debe estar entre 0 y 120." << endl;
                    break;
                }

                cout << "Ingrese la calificacion 1: ";
                cin >> calificacion1;
                if (calificacion1 < 0 || calificacion1 > 10) {
                    cout << "La calificacion debe estar entre 0 y 10." << endl;
                    break;
                }

                cout << "Ingrese la calificacion 2: ";
                cin >> calificacion2;
                if (calificacion2 < 0 || calificacion2 > 10) {
                    cout << "La calificacion debe estar entre 0 y 10." << endl;
                    break;
                }

                cout << "Ingrese la calificacion 3: ";
                cin >> calificacion3;
                if (calificacion3 < 0 || calificacion3 > 10) {
                    cout << "La calificacion debe estar entre 0 y 10." << endl;
                    break;
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

                float promedio = (calificacion1 + calificacion2 + calificacion3) / 3;
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