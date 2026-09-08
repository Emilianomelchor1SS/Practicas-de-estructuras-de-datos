#include <iostream>

using namespace std;

int main() {

  string nombre_estudiante;
 int edad_estudiante;
 float calificacion1, calificacion2, calificacion3;
 float promedio;
 cout << "Ingrese el nombre del estudiante: ";
    cin >> nombre_estudiante;
cout << "Ingrese la edad del estudiante: ";
    cin >> edad_estudiante;
    cout << "Ingrese la calificación 1: ";
    cin >> calificacion1;
    cout << "Ingrese la calificación 2: ";
    cin >> calificacion2;
    cout << "Ingrese la calificación 3: ";
    cin >> calificacion3;

    promedio = (calificacion1 + calificacion2 + calificacion3) / 3;

    cout << "El promedio de " << nombre_estudiante << " es: " << promedio << endl;
    cout << "GRACIAS POR USAR EL SISTEMA DE CALIFICACIONES ESCOLARES" << endl;
  return 0;
}