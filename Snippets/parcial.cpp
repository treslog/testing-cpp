#include <iostream>
#include <iomanip>
#include <ios>
#include <algorithm>
using namespace std;

// Clase main abajo del todo
int main() {
    //MenuPrincipal menu;
    //menu.iniciarPrograma();
    cout << "\n"
         << "# Fin del programa"
         << "\n";
    return 0;
}

//--------------------

// Clase menu principal, menú genérico
class MenuPrincipal {
    public:
        void mostrarMenu() {
            cout << "# Programa" << endl;
            cout << right << setfill('.') << setw(50) << " " << endl;
            cout << "# Escoja una opcion: " << endl;
            cout << right << setfill('.') << setw(50) << " " << endl;
            cout << "# 1. Registrar un estudiante" << endl;
            // [...]
            cout << "# 6. Salir" << endl;
            cout << right << setfill('.') << setw(50) << " " << endl;
        }
        int iniciarPrograma() {

            system("clear");

            //Estudiante estudiante;
            //Resultado resultado;

            int opcion{0};
            while (opcion != 6) {
                    mostrarMenu();
                    cin >> opcion;
                    switch (opcion) {
                        case 1:
                            //estudiante.leerDatos();
                            break;
                        case 2:
                            //estudiante.mostrarPromedios();
                            break;
                        case 3:
                            //estudiante.mostrarMejorEstudiante();
                            break;
                        case 4:
                            //estudiante.mostrarPeorEstudiante();
                            break;
                        case 5:
                            //estudiante.mostrarPromedioCurso();
                            break;
                        case 6:
                            cout << "# Gracias por usar el programa" << endl;
                            break;
                        default:
                            cout << "# Opcion no valida" << endl;
                            break;
                    }
                system("pause");
                system("clear");
                cout << right << setfill('.') << setw(50) << " " << endl;
            }
         return 0; 
        };
};

//--------------------

//Clase de validación de datos
class Validacion {
    public:
        double validarNota(double nota) {
            while (nota < 0 || nota > 5) {
                cout << "La nota debe estar entre 0 y 5" << endl;
                cout << "Ingrese la nota nuevamente: ";
                cin >> nota;
            }
            return nota;
        };

        int validarID(int id) {
            while (id < 0) {
                cout << "El ID debe ser mayor a 0" << endl;
                cout << "Ingrese el ID nuevamente: ";
                cin >> id;
            }
            return id;
        };
};

// Para invocar la validación de datos
// cin >> nota;
// nota = validacion.validarNota(nota);

//--------------------


// Clase con matriz y métodos para trabajar
class Matriz {
    double baseDeDatos[5][5];
    int a;
    int b;

    public:
        // Ejemplo de constructor, se ejecuta al crear el objeto "Matriz matriz(a, b)";
        Matriz(int a_, int b_) {
            a = a_;
            b = b_;
        }
        // llenar la matriz con ceros
        void llenarMatriz() {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    baseDeDatos[i][j] = 0;
                }
            }
        }

        // comprobar y llenar la primera fila vacia con los datos
        void llenarFila(int id, double nota1, double nota2, double nota3, double nota4) {
            for (int i = 0; i < 5; i++) {
                if (baseDeDatos[i][0] == 0) {
                    baseDeDatos[i][0] = id;
                    baseDeDatos[i][1] = nota1;
                    baseDeDatos[i][2] = nota2;
                    baseDeDatos[i][3] = nota3;
                    baseDeDatos[i][4] = nota4;
                    break;
                }
            }
        }

        // mostrar la fila con el id más alto (o nota)
        void mostrarIDMasAlto() {
            int id = 0;
            int fila = 0;
            for (int i = 0; i < 5; i++) {
                if (baseDeDatos[i][0] > id) {
                    id = baseDeDatos[i][0];
                    fila = i;
                }
            }
            cout << "El mejor estudiante es: " << endl;
            cout << "ID: " << baseDeDatos[fila][0] << endl;
            cout << "Nota 1: " << baseDeDatos[fila][1] << endl;
            cout << "Nota 2: " << baseDeDatos[fila][2] << endl;
            cout << "Nota 3: " << baseDeDatos[fila][3] << endl;
            cout << "Nota 4: " << baseDeDatos[fila][4] << endl;
        }

        // mostrar la fila con el id más bajo (o nota)
        void mostrarIDMasBajo() {
            int id = 999999999;
            int fila = 0;
            for (int i = 0; i < 5; i++) {
                if (baseDeDatos[i][0] < id) {
                    id = baseDeDatos[i][0];
                    fila = i;
                }
            }
            cout << "El peor estudiante es: " << endl;
            cout << "ID: " << baseDeDatos[fila][0] << endl;
            cout << "Nota 1: " << baseDeDatos[fila][1] << endl;
            cout << "Nota 2: " << baseDeDatos[fila][2] << endl;
            cout << "Nota 3: " << baseDeDatos[fila][3] << endl;
            cout << "Nota 4: " << baseDeDatos[fila][4] << endl;
        }

        // mostrar promedio de todas las notas
        void mostrarPromedioCurso() {
            double promedio = 0;
            int contador = 0;
            for (int i = 0; i < 5; i++) {
                for (int j = 1; j < 5; j++) {
                    promedio += baseDeDatos[i][j];
                    contador++;
                }
            }
            promedio = promedio / contador;
            cout << "El promedio del curso es: " << promedio << endl;
        }

        // mostrar promedio de una fila
        void mostrarPromedioFila(int fila) {
            double promedio = 0;
            for (int i = 1; i < 5; i++) {
                promedio += baseDeDatos[fila][i];
            }
            promedio = promedio / 4;
            cout << "El promedio del estudiante es: " << promedio << endl;
        }

        // ordenar la matriz por id con sort
        void ordenarMatriz() {
            sort(baseDeDatos, baseDeDatos + 5);
        }
};