#include <iostream>
#include <string>

using namespace std;

int main() {
    while (true) {
        string nombre_estudiante;
        int edad_estudiante;
        float calificacion1, calificacion2, calificacion3;
        float promedio;

        cout << "Ingrese el nombre del estudiante: ";
        cin >> ws;
        getline(cin, nombre_estudiante);

        if (nombre_estudiante.find_first_of("0123456789") != string::npos) {
            cout << "Ingrese un nombre valido." << endl;
            return 1;
        }

        cout << "Ingrese la edad del estudiante: ";
        cin >> edad_estudiante;

        if (edad_estudiante < 0 || edad_estudiante > 120) {
            cout << "La edad debe estar entre 0 y 120." << endl;
            cout << "Ingrese los datos nuevamente." << endl;
            return 1;
        }

        cout << "Ingrese la calificacion 1: ";
        cin >> calificacion1;

        if (calificacion1 < 0 || calificacion1 > 10) {
            cout << "La calificacion debe estar entre 0 y 10." << endl;
            cout << "Ingrese los datos nuevamente." << endl;
            return 1;
        }

        cout << "Ingrese la calificacion 2: ";
        cin >> calificacion2;

        if (calificacion2 < 0 || calificacion2 > 10) {
            cout << "La calificacion debe estar entre 0 y 10." << endl;
            cout << "Ingrese los datos nuevamente." << endl;
            return 1;
        }

        cout << "Ingrese la calificacion 3: ";
        cin >> calificacion3;

        if (calificacion3 < 0 || calificacion3 > 10) {
            cout << "La calificacion debe estar entre 0 y 10." << endl;
            cout << "Ingrese los datos nuevamente." << endl;
            return 1;
        }

        promedio = (calificacion1 + calificacion2 + calificacion3) / 3;

        if (promedio >= 9) {
            cout << "El estudiante " << nombre_estudiante << " ha aprobado con un promedio excelente de: " << promedio << endl;
        } else if (promedio >= 7) {
            cout << "El estudiante " << nombre_estudiante << " ha aprobado con un promedio de: " << promedio << endl;
        } else {
            cout << "El estudiante " << nombre_estudiante << " ha reprobado con un promedio de: " << promedio << endl;
        }

       
        cout << "GRACIAS POR USAR EL SISTEMA DE CALIFICACIONES ESCOLARES" << endl;
    }
}