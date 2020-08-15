#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <exception>
#include <iostream>
#include <string>

class ListException : std::exception {
private:
    std::string msg;

public:
    explicit ListException(const char* message): msg(message) {}
    explicit ListException(const std:: string& message): msg(message) {}
    virtual ~ListException()throw() {}
    virtual const char* what() const throw() {
        return msg.c_str();
    }
};

template <class T, int arraySize = 100>
class List {
private:
    int last;                       // ultimo
    T data[arraySize];              // Data
    bool isValidPos(int);           // Validar posición

public:
    List();                         // Inicializa
    bool isEmpty();                 // Vacia
    bool isFull();                  // Llena
    void insertData(int, const T&); // Insertar *
    void deleteData(int);           // Eliminar
    int getFirstPos();              // Primero
    int getLastPos();               // Ultimo
    int getPrevPos(int);            // Antes
    int getNextPos(int);            // Despues *
    int findData(const T&);         // Localizar
    T retrieve(int);                // Recupera
    void sortData();                // Ordenar
    void printData();               // Imprimir
    void deleteAll();               // Eliminar todo (anula).
};

template <class T, int arraySize>
List<T,arraySize>::List() {
    last = -1;
}

template <class T, int arraySize>
bool List<T,arraySize>::isValidPos(int p) {
    return p >= 0 && p <= last;
}

template <class T, int arraySize>
bool List<T,arraySize>::isEmpty() {
    return last == -1;
}

template <class T, int arraySize>
bool List<T,arraySize>::isFull() {
    return  last == arraySize - 1;
}

template <class T, int arraySize>
void List<T,arraySize>::insertData(int p, const T& e) {
    if(isFull()) {
        throw ListException("Desbordamineto de datos - La lista esta llena, tratando de insertar");
    }

    if(p != -1 && !isValidPos(p)) { // p < 0 && p > last
        throw ListException("La posición es invalida, tratando de insertar");
    }

    //! SE TIENE QUE REVISAR BIEN. 0 al 8 o -2, 10 va bien, pero -1 o 9 no.
    // getLastPos() Evita ejecutar este for, pero si se desea agregar un element
    // en un index de forma manual se ejectara.
    for(int i = last; i >= p; i--) {
        data[i + 1] = data[i];
    }

    if(p < last) {
        data[p] = e;
    } else { // p == last
        data[p + 1] = e;
    }

    last++;
}

template <class T, int arraySize>
void List<T, arraySize>::deleteData(int p) {
    if(isEmpty()) {
        throw ListException("Insuficiencia de datos - La lista esta vacia, tratando de eliminar");
    }

    if(!isValidPos(p)) {
        throw ListException("La posición es invalida, tratando de eliminar");
    }

    for(int i = p; i < last; i++) {
        data[i] = data[i + 1]; // Recorre la lista.
    }
    last--;
}

template <class T, int arraySize>
int List<T, arraySize>::getFirstPos() {
    if(isEmpty()) {
        return -1;
    }
    return 0;
}

template <class T, int arraySize>
int List<T, arraySize>::getLastPos() {
    return last;
}

template <class T, int arraySize>
int List<T,arraySize>::getPrevPos(int p) {
    if(isEmpty() || !isValidPos(p) || p == 0) { // p < 0 && p > last
        return -1;
    }
    return p - 1;
}

template <class T, int arraySize>
int List<T, arraySize>::getNextPos(int p) {
    if(isEmpty() || !isValidPos(p) || p == last - 1) { // 99 == 100 - 1
        return -1;
    }
    return p + 1;
}

template <class T, int arraySize>
int List<T, arraySize>::findData(const T& e) {
    for(int i = 0; i <= last; i++) {
        if(data[i] == e) {
            return i;
        }
    }
    return -1;
}

template <class T, int arraySize>
T List<T, arraySize>::retrieve(int p) {
    if(isEmpty()) {
        throw ListException("Insuficiencia de datos - Lista esta vacia, tratando de recuperar");
    }
    if(!isValidPos(p)) {
        throw ListException("La posición es invalida, tratando de recuperar");
    }
    return data[p];
}

template <class T, int arraySize>
void List<T, arraySize>::sortData() {
    // Crear varios ordenamientos.
}

template <class T, int arraySize>
void List<T, arraySize>::printData() {
    std::cout << "[";
    for(int i = 0; i <= last; i++) {
        if(i < last) {
            std::cout << data[i] << ", ";
        } else {
            std::cout << data[i];
        }
    }
    std::cout << "]" << std::endl;
}

template <class T, int arraySize>
void List<T, arraySize>::deleteAll() {
    last = -1;
}

#endif // LIST_H_INCLUDED
