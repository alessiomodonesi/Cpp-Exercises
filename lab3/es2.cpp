#include <iostream>

// Funzione per stampare la dimensione dell'array
void print_array_length(double arr[], int size) {
    // Utilizza il parametro 'size' per stampare la dimensione dell'array
    std::cout << "Dimensione dell'array (passato alla funzione): " << size << " elementi" << std::endl;

    // NOTA: `sizeof(arr)` in questa funzione darà la dimensione di un puntatore, non dell'array
}

int main() {
    constexpr int array_size = 5; // Definizione della dimensione dell'array
    double arr[array_size] = {1.0, 2.0, 3.0, 4.0, 5.0}; // Array di double

    // Stampa la dimensione dell'array nel main
    std::cout << "Dimensione dell'array (nel main): " << sizeof(arr) / sizeof(arr[0]) << " elementi" << std::endl;

    // Passaggio dell'array alla funzione
    print_array_length(arr, array_size);

    return 0;
}
