// g++ finanza.cpp -o finanza.exe; ./finanza.exe

#include <iostream>
#include <iomanip>
#include <ios>

using namespace std;

class ValidacionDatos {
public:
    int validarMayorIgualCero(int numero) {
        while (numero < 0) {
            cout << "ERROR: El numero debe ser mayor o igual a cero" << endl;
            cout << "Intente nuevamente:  ";
            cin >> numero;
        }
         return numero; };

    int validarNumeroAlumnos(int numeroAlumnosEscuela, int numeroAlumnosViaje) {
    while (numeroAlumnosEscuela < numeroAlumnosViaje || numeroAlumnosViaje < 0) {
        cout << "ERROR: El numero de alumnos de viaje debe ser mayor a cero y no puede ser superior al que hay en la escuela" << endl;
        cout << "Intente nuevamente:  ";
        cin >> numeroAlumnosViaje;
    }
    return numeroAlumnosViaje; };
};

class Calculo {
    public:
    double calcularPorcentaje(int valor, double porcentaje, bool sumarPorcentaje) {
        double calculoPorcentaje{0};

        ValidacionDatos validacion;
        valor = validacion.validarMayorIgualCero(valor);

        sumarPorcentaje ? 
        calculoPorcentaje = valor + (valor * porcentaje) :
        calculoPorcentaje = valor - (valor * porcentaje);

        return calculoPorcentaje; };
};

class Finanza {
public:
    int porcentajeAlumnos(){
        int numeroAlumnosEscuela{0};
        int numeroAlumnosViaje{0};
        double porcentajeAlumnosViaje{0};

        ValidacionDatos validacion;

        cout << right << setfill('.') << setw(50) << " " << endl;
        cout << "# Ingrese el numero de alumnos de la escuela: ";
        cin >> numeroAlumnosEscuela;
        numeroAlumnosEscuela = validacion.validarMayorIgualCero(numeroAlumnosEscuela);
        cout << "# Ingrese el numero de alumnos que fueron de viaje: ";
        cin >> numeroAlumnosViaje;
        numeroAlumnosViaje = validacion.validarNumeroAlumnos(numeroAlumnosEscuela, numeroAlumnosViaje);

        porcentajeAlumnosViaje = (double)numeroAlumnosViaje/numeroAlumnosEscuela * 100;
        cout << "# El porcentaje de alumnos que fueron de viaje es: " << porcentajeAlumnosViaje << "%" << endl;
        return 0;
    }

    int descuentoVehiculo(){
        int precioVehiculo{0};
        double porcentajeDescuento{0.075};
        double precioFinal{0};

        Calculo calculo;
        cout << right << setfill('.') << setw(50) << " " << endl;
        cout << "# Ingrese el precio del vehiculo: ";
        cin >> precioVehiculo;
        precioFinal = calculo.calcularPorcentaje(precioVehiculo, porcentajeDescuento, false);

        cout << "# El valor que hay que pagar por el vehiculo menos el descuento es: " 
        <<  precioFinal
        << "$" << endl;

        return 0;
    }

    int ordenadorIVA(){
        int precioOrdenador{0};
        double valorIVA{0.19};
        double precioFinal{0};

        Calculo calculo;
        cout << right << setfill('.') << setw(50) << " " << endl;
        cout << "# Ingrese el precio del Ordenador: ";
        cin >> precioOrdenador;
        precioFinal = calculo.calcularPorcentaje(precioOrdenador, valorIVA, true);

        cout << "# El valor que hay que pagar por el Ordenador con IVA es: " 
        <<  precioFinal
        << "$" << endl;

        return 0;
    }

    int descuentoMonitor(){
        int precioMonitor{0};
        double porcentajeDescuento{0.08};
        double precioFinal{0};

        Calculo calculo;
        cout << right << setfill('.') << setw(50) << " " << endl;
        cout << "# Ingrese el precio del Monitor: ";
        cin >> precioMonitor;
        precioFinal = calculo.calcularPorcentaje(precioMonitor, porcentajeDescuento, false);

        cout << "# El valor que hay que pagar por el Monitor es: " 
        <<  precioFinal
        << "$" << endl;

        return 0;
    }

    int precioVentaArticulo(){
        int precioArticulo{0};
        double porcentajeDescuento{0.08};
        double precioFinal{0};

        Calculo calculo;
        cout << right << setfill('.') << setw(50) << " " << endl;
        cout << "# Ingrese el precio del Articulo: ";
        cin >> precioArticulo;
        precioFinal = calculo.calcularPorcentaje(precioArticulo, porcentajeDescuento, true);

        cout << "# El valor al que hay que vender el Articulo para ganar el 8% es: " 
        <<  precioFinal
        << "$" << endl;

        return 0;
    }

    int precioGananciaVenta(){
        int precioArticulo{0};
        double porcentajeDescuento{0.1};
        double precioFinal{0};

        Calculo calculo;
        cout << right << setfill('.') << setw(50) << " " << endl;
        cout << "# Ingrese el precio del Articulo: ";
        cin >> precioArticulo;
        precioFinal = calculo.calcularPorcentaje(precioArticulo, porcentajeDescuento, true);

        cout << "# El valor al que hay que vender el articulo para ganar el 10% es: " 
        <<  precioFinal
        << "$" << endl;

        return 0;
    };

    int precioVentaZapatos(){
        int precioArticulo{0};
        double porcentajeDescuento{0.12};
        double precioFinal{0};

        Calculo calculo;
        cout << right << setfill('.') << setw(50) << " " << endl;
        cout << "# Ingrese el precio de los zapataos: ";
        cin >> precioArticulo;
        precioFinal = calculo.calcularPorcentaje(precioArticulo, porcentajeDescuento, false);

        cout << "# El valor al que hay que vender los zapatos descontando el 12% es: " 
        <<  precioFinal
        << "$" << endl;

        return 0;
    };

    int precioPerdidaVenta(){
        int precioArticulo{0};
        double porcentajeDescuento{0.2};
        double precioFinal{0};

        Calculo calculo;
        cout << right << setfill('.') << setw(50) << " " << endl;
        cout << "# Ingrese el precio del objeto: ";
        cin >> precioArticulo;
        precioFinal = calculo.calcularPorcentaje(precioArticulo, porcentajeDescuento, false);

        cout << "# El valor al que hay que vender el objeto descontando el 20% es: " 
        <<  precioFinal
        << "$" << endl;

        return 0;
    };
};

class MenuPrincipal {
public:
    void mostrarMenu() {
        cout << "# Bienvenido al programa de finanzas" << endl;
        cout << right << setfill('.') << setw(50) << " " << endl;
        cout << "# Escoja una opcion: " << endl;
        cout << right << setfill('.') << setw(50) << " " << endl;
        cout << "# 1. Calcular el porcentaje de alumnos que fueron de viaje" << endl;
        cout << "# 2. Calcular descuento de vehiculo (7.5%)" << endl;
        cout << "# 3. Calcular IVA de un ordenador (19%)" << endl;
        cout << "# 4. Calcular descuento de un monitor (8%)" << endl;
        cout << "# 5. Calcular precio de venta de un articulo (8%)" << endl;
        cout << "# 6. Calcular precio de venta de ganancia de un articulo (10%)" << endl;
        cout << "# 7. Calcular precio de venta de zapatos (12%)" << endl;
        cout << "# 8. Calcular precio de venta de perdida de un articulo (20%)" << endl;
        cout << "# 9. Salir" << endl;
        cout << right << setfill('.') << setw(50) << " " << endl;
    }

    int iniciarPrograma() {

        char foo;

        Finanza objFinanza;
        int opcion{0};
        while (opcion != 9) {
            mostrarMenu();
            cin >> opcion;
            switch (opcion) {
                case 1:
                    objFinanza.porcentajeAlumnos();
                    break;
                case 2:
                    objFinanza.descuentoVehiculo();
                    break;
                case 3:
                    objFinanza.ordenadorIVA();
                    break;
                case 4:
                    objFinanza.descuentoMonitor();
                    break;
                case 5:
                    objFinanza.precioVentaArticulo();
                    break;
                case 6:
                    objFinanza.precioGananciaVenta();
                    break;
                case 7:
                    objFinanza.precioVentaZapatos();
                    break;
                case 8:
                    objFinanza.precioPerdidaVenta();
                    break;
                case 9:
                    cout << "# Gracias por usar el programa" << endl;
                    break;
                default:
                    cout << "# Opcion no valida" << endl;
                    break;
            }
        cout << "# Presione cualquier tecla para continuar..." << endl;
        cin >> foo;
        system("clear");

        cout << right << setfill('.') << setw(50) << " " << endl;
        }
         return 0; };

};

int main()
{

    MenuPrincipal menu;
    menu.iniciarPrograma();

    cout << "\n"
         << "# Fin del programa"
         << "\n";

    return 0;
}
