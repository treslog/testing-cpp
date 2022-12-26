// g++ estudiantes.cpp -o estudiantes.exe; ./estudiantes.exe

#include <iostream>
#include <iomanip>
#include <ios>
using namespace std;

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

class Resultado {
    public:
        void calcularMejorEstudiante(auto baseDeDatos) {
            int promedioMasAlto = 0;
            int idEstudiante = 0;
            for (int i = 0; i < 5; i++) {
                int promedio = baseDeDatos[i][4];
                if (promedio > promedioMasAlto) {
                    promedioMasAlto = promedio;
                    idEstudiante = baseDeDatos[i][0];
                }
            }
            cout << "El estudiante con el promedio mas alto es el estudiante con ID: " << idEstudiante << endl;
            cout << "Su promedio es: " << promedioMasAlto << endl;

        };
        void calcularPeorEstudiante(auto baseDeDatos) {
            int promedioMasBajo = 0;
            int idEstudiante = 0;
            for (int i = 0; i < 5; i++) {
                int promedio = baseDeDatos[i][4];
                if (promedio < promedioMasBajo) {
                    promedioMasBajo = promedio;
                    idEstudiante = baseDeDatos[i][0];
                }
            }
            cout << "El estudiante con el promedio mas bajo es el estudiante con ID: " << idEstudiante << endl;
            cout << "Su promedio es: " << promedioMasBajo << endl;
            
        };
        void calcularPromedioCurso(auto baseDeDatos) {
            cout << "El promedio general es: " << endl;
            int promedioGeneral = 0;
            for (int i = 0; i < 5; i++) {
                promedioGeneral += baseDeDatos[i][4];
            }
            cout << promedioGeneral / 5 << endl;

        };
        void calcularPromedios(auto baseDeDatos) {
            system("clear");
            cout << "Los promedios de los estudiantes son: " << endl;
            for (int i = 0; i < 5; i++) {
                cout << " ID: " << baseDeDatos[i][0] << " PROMEDIO: " << baseDeDatos[i][4] << endl;
            }
        };
};

class Estudiante {
    int id_estudiante;
    double nota_1;
    double nota_2;
    double nota_3;
    double promedio;
    double baseDeDatos[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    public:
        double calcularPromedio(double nota1, double nota2, double nota3) {
            promedio = (nota1 + nota2 + nota3) / 3;
            return promedio;
        }
        void guardarDatos() {

            for (int i = 0; i < 5; i++) {
                if (baseDeDatos[i][0] == 0) {
                    cout << "# Guardando estudiante con id " << id_estudiante << " en la fila " << i+1 << endl;
                    baseDeDatos[i][0] = id_estudiante;
                    baseDeDatos[i][1] = nota_1;
                    baseDeDatos[i][2] = nota_2;
                    baseDeDatos[i][3] = nota_3;
                    baseDeDatos[i][4] = promedio;
                    break;
                } else {
                    cout << "La fila " << i+1 << " esta llena" << endl;
                }
            }
        }
        void leerDatos() {

            Validacion validacion;

            cout << "Ingrese el id del estudiante: ";
            cin >> id_estudiante;
            this->id_estudiante = validacion.validarID(id_estudiante);
            cout << "Ingrese la nota 1: ";
            cin >> nota_1;
            this->nota_1 = validacion.validarNota(nota_1);
            cout << "Ingrese la nota 2: ";
            cin >> nota_2;
            this->nota_2 = validacion.validarNota(nota_2);
            cout << "Ingrese la nota 3: ";
            cin >> nota_3;
            this->nota_3 = validacion.validarNota(nota_3);

            promedio = calcularPromedio(nota_1, nota_2, nota_3);

            guardarDatos();
        }
        void mostrarPromedios() {
            Resultado resultado;
            resultado.calcularPromedios(baseDeDatos);
        }
        void mostrarMejorEstudiante() {
            Resultado resultado;
            resultado.calcularMejorEstudiante(baseDeDatos);
        }
        void mostrarPeorEstudiante() {
            Resultado resultado;
            resultado.calcularPeorEstudiante(baseDeDatos);
        }
        void mostrarPromedioCurso() {
            Resultado resultado;
            resultado.calcularPromedioCurso(baseDeDatos);
        }
};

class MenuPrincipal {
    public:
        void mostrarMenu() {
            cout << right << setfill('.') << setw(50) << " " << endl;
            cout << "# Escoja una opcion: " << endl;
            cout << right << setfill('.') << setw(50) << " " << endl;
            cout << "# 1. Registrar un estudiante" << endl;
            cout << "# 2. Mostrar promedio de todos los estudiantes" << endl;
            cout << "# 3. Mostrar id y nota del estudiante que obtuvo el promedio mas alto" << endl;
            cout << "# 4. Mostrar id y nota del estudiante que obtivo el promedio mas bajo" << endl;
            cout << "# 5. Mostrar el promedio del curso" << endl;
            cout << "# 6. Salir" << endl;
            cout << right << setfill('.') << setw(50) << " " << endl;
        }
        int iniciarPrograma() {

            system("clear");

            Estudiante estudiante;
            Resultado resultado;

            int opcion{0};
            while (opcion != 6) {
                    mostrarMenu();
                    cin >> opcion;
                    switch (opcion) {
                        case 1:
                            estudiante.leerDatos();
                            break;
                        case 2:
                            estudiante.mostrarPromedios();
                            break;
                        case 3:
                            estudiante.mostrarMejorEstudiante();
                            break;
                        case 4:
                            estudiante.mostrarPeorEstudiante();
                            break;
                        case 5:
                            estudiante.mostrarPromedioCurso();
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

int main() {
    MenuPrincipal menu;
    menu.iniciarPrograma();
    cout << "\n"
         << "# Fin del programa"
         << "\n";
    return 0;
}
