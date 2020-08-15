#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <ctime>

#include "List.h"

using namespace std;

int main() {
    srand(time(0));
    List<int,100> myList;
    setlocale(LC_ALL,"spanish");

    cout << "MI LISTA - INGRESADO DATOS\n" << endl;
    for(int i = 0; i < 10; i++) {
        int myData = 1 + rand() % 100;
        cout << "Insertando los datos: " << myData << " - Inidice: " << i << endl;
        myList.insertData(myList.getLastPos(), myData);
    }

    cout << "\nMI LISTA - IMPRIMIR LOS DATOS\n" << endl;
    myList.printData();

    cout << "\n\nEXCEPTION\n" << endl;
    try {
        myList.insertData(9, 385);
        myList.printData();
    } catch (ListException ex) {
        cout << "- Ooooooops!!!" << endl;
        cout << "- Parece que algo no esta bien..." << endl;
        cout << "- El sistema dice que: " << endl;
        cout << "- " << ex.what() << endl;
        cout << "- Vamos a continuar, esperemos no haya m�s errores..." << endl;
    }
    return 0;
}
