// g++ methods.cpp -o methods.exe; ./methods.exe
#include <iostream>
#include <iomanip>
#include <ios>
#include <algorithm>
using namespace std;

// Clase main abajo del todo
int main() {

    // create a 5x5 matrix
    int matrix[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    // print the matrix
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n" << "Siguiente operacion" << "\n";

    // order the matrix using sort
    for (int i = 0; i < 5; i++) {
        sort(matrix[i], matrix[i] + 5);
    }

    // print the matrix
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n" << "Siguiente operacion" << "\n";

    // reverse the matrix using reverse
    for (int i = 0; i < 5; i++) {
        reverse(matrix[i], matrix[i] + 5);
    }

    // print the matrix
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // set values of the matrix to 0
    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         matrix[i][j] = 0;
    //     }
    // }

    cout << "\n" << "Siguiente operacion" << "\n";

    // check if the row is empty and set new values with cin
    for (int i = 0; i < 5; i++) {
        if (matrix[i][0] == 0) {
            cout << "Ingrese los valores de la fila " << i + 1 << ": ";
            for (int j = 0; j < 5; j++) {
                cin >> matrix[i][j];
            }
        }
    }


    // print the matrix
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    // read a name with getline and print it
    string name;
    cout << "Ingrese su nombre: ";
    getline(cin, name);
    cout << "Su nombre es: " << name << endl;

    // read a array of names with getline and print it
    string names[5];
    for (int i = 0; i < 5; i++) {
        cout << "Ingrese el nombre " << i + 1 << ": ";
        getline(cin, names[i]);
    }
    cout << "Los nombres son: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << names[i] << endl;
    }

    // order the array of names alphabetically
    sort(names, names + 5);

    // print the array of names
    cout << "Los nombres ordenados son: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << names[i] << endl;
    }

    // ask for a name and search it in the array of names
    string searchName;
    cout << "Ingrese el nombre a buscar: ";
    getline(cin, searchName);
    bool found = false;
    for (int i = 0; i < 5; i++) {
        if (names[i] == searchName) {
            found = true;
            break;
        }
    }
    if (found) {
        cout << "El nombre " << searchName << " fue encontrado" << endl;
    } else {
        cout << "El nombre " << searchName << " no fue encontrado" << endl;
    }

    // map the array of names in a short way
    cout << "Los nombres son: " << endl;
    for (string name : names) {
        cout << name << endl;
    }



    cout << "\n"
         << "# Fin del programa"
         << "\n";
    return 0;
}