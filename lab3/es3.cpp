#include <iostream>

void print_reference(const int& intVar, const double& doubleVar) {
    // Stampa i valori passati per reference costante
    std::cout << "Stampa per reference:" << std::endl;
    std::cout << "intVar = " << intVar << std::endl;
    std::cout << "doubleVar = " << doubleVar << std::endl;
}

void print_pointer(const int* intPtr, const double* doublePtr) {
    // Stampa i valori puntati dai puntatori
    std::cout << "Stampa per puntatore:" << std::endl;
    std::cout << "intVar = " << *intPtr << std::endl;
    std::cout << "doubleVar = " << *doublePtr << std::endl;
}

int main() {
    // Definizione di una variabile int e una double
    int myInt = 10;
    double myDouble = 3.14;

    // Chiamata alla funzione print_reference passando le variabili per const reference
    print_reference(myInt, myDouble);

    // Chiamata alla funzione print_pointer passando le variabili per puntatore
    print_pointer(&myInt, &myDouble);

    return 0;
}
