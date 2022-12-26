#include <iostream>
#include <iomanip>
#include <ios>
#include <algorithm>
using namespace std;

void menu() {
    system("clear");
    cout << "1. Option 1" << endl;
    cout << "2. Option 2" << endl;
    cout << "3. Option 3" << endl;
    cout << "4. Exit" << endl;
    cout << "Select an option: ";

    int option;
    cin >> option;

    switch (option) {
        case 1:
            cout << "Option 1 selected" << endl;
            system("pause");
            menu();
            break;
        case 2:
            cout << "Option 2 selected" << endl;
            system("pause");
            menu();
            break;
        case 3:
            cout << "Option 3 selected" << endl;
            system("pause");
            menu();
            break;
        case 4:
            cout << right << setfill('.') << setw(50) << " " << endl
            << "# Fin del programa" << endl
            << right << setfill('.') << setw(50) << " " << endl;
            break;
        default:
            cout << "Invalid option" << endl;
            system("pause");
            menu();
            break;
    }
}



int main() {

    menu();

    return 0;
}
