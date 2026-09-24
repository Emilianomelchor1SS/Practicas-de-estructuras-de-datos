#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include <limits>// Limpiar el estado de error y descartar la entrada inválida
  struct Estudiante {
        string nombre_estudiante;
        int edad_estudiante;
        vector<float> calificaciones;
    };
int main() {
    int opcion;
    
vector<Estudiante> listaEstudiantes;
    int cantidad_calificaciones;
    bool estudianteRegistrado = false;
    int repeticiones = 0; // Contador de repeticiones

    while (true) {
        do{
        cout << "\n===== Sistema de Calificaciones =====" << endl;
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Ver información del programa" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
         cin >> opcion;
        }while( opcion < 1 || opcion > 3); 
       

        switch (opcion) {
            case 1: {

                cin.ignore();
               Estudiante nuevoEstudiante;
                do {
                    cout << "Ingrese el nombre del estudiante: ";
                  
                    getline(cin,nuevoEstudiante.nombre_estudiante);

                    if (nuevoEstudiante.nombre_estudiante.find_first_of("0123456789") != string::npos) {
                        cout << "-----------------------------Ingrese un nombre válido ----------------------------" << endl;
                        repeticiones++;
                        if (repeticiones >= 3) {
                            cout << "-----------------------------Se ha excedido el número de intentos.-----------------------------" << endl;
                            break;
                           
                        } 
                    }
                }while (nuevoEstudiante.nombre_estudiante.find_first_of("0123456789") != string::npos && repeticiones < 3);
                    if (repeticiones >= 3) {
                        repeticiones = 0; 
                        break;           
                        }
                    
                
                repeticiones = 0; 
              
                do{    cout << "Ingrese la edad del estudiante: ";
                    cin >> nuevoEstudiante.edad_estudiante;
                    if (nuevoEstudiante.edad_estudiante < 0 || nuevoEstudiante.edad_estudiante > 120|| cin.fail() ) {
                        cout << "-----------------------------La edad debe estar entre 0 y 120.-----------------------------" << endl;
                        cin.clear();
                      cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        repeticiones++;
                        nuevoEstudiante.edad_estudiante = -1; // Reiniciar la edad para que el ciclo continúe
                        if (repeticiones >= 3) {
                            cout << "-----------------------------Se ha excedido el número de intentos.-----------------------------" << endl;
                            break;
                        }


                    }
                }while (nuevoEstudiante.edad_estudiante < 0 || nuevoEstudiante.edad_estudiante > 120|| cin.fail());
                if (repeticiones >= 3) {
                    repeticiones = 0; 
                    break;           
                }

                cout << "Cuantas calificaciones desea ingresar?: ";
                cin >> cantidad_calificaciones;

                if (cantidad_calificaciones <= 0) {
                    cout << "-----------------------------Debe ingresar al menos una calificación.-----------------------------" << endl;
                    break;
                }

                nuevoEstudiante.calificaciones.clear();

                for (int i = 0; i < cantidad_calificaciones; i++) {
                    float calificacion;
                    cout << "Ingrese la calificacion " << i + 1 << ": ";
                    cin >> calificacion;

                    if (calificacion < 0 || calificacion > 10) {
                        cout << "-----------------------------La calificacion debe estar entre 0 y 10.-----------------------------" << endl;
                        i--;
                        continue;
                       
                    }

                    nuevoEstudiante.calificaciones.push_back(calificacion);
                }

                listaEstudiantes.push_back(nuevoEstudiante);
                cout << "Estudiante registrado correctamente." << endl;
                break;
              
                
            }

            case 2: {
                if (listaEstudiantes.empty()) {
                    cout << "-----------------------------No se han registrado estudiantes.-----------------------------" << endl;
                    break;
                }

                cout << "\n===== LISTA DE ESTUDIANTES REGISTRADOS =====" << endl;

                // Recorremos el vector con un ciclo for para mostrar a TODOS los estudiantes
                for (size_t i = 0; i < listaEstudiantes.size(); i++) {
                    float suma = 0;

                    for (float calificacion : listaEstudiantes[i].calificaciones) {
                        suma += calificacion;
                    }

                    float promedio = suma / listaEstudiantes[i].calificaciones.size();

                    cout << i + 1 << ". Nombre: " << listaEstudiantes[i].nombre_estudiante 
                         << " | Edad: " << listaEstudiantes[i].edad_estudiante 
                         << " | Promedio: " << promedio << endl;
                }
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