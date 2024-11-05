#include <iostream>
using namespace std;

void f() {
    // a. Definisci un array di 10 interi
    int arr[10] = {0};  // Inizializziamo l'array con zeri per chiarezza

    // b. Crea un puntatore che punta a un elemento dell'array (non il primo)
    int* ptr = &arr[3]; // Puntiamo al quarto elemento

    // Usa il puntatore per scrivere sull'intero array usando l'operatore []
    for (int i = 0; i < 10; ++i) {
        ptr[i - 3] = i + 1; // Modifica i valori partendo da 1
    }

    // Stampa il contenuto dell'array per verificare il risultato
    cout << "Array in funzione f(): ";
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Funzione che scrive oltre i limiti dell'array
void f_illegal() {
    int arr[10] = {0};  // Array di 10 interi

    // Prova a scrivere oltre i limiti dell'array
    cout << "Scrittura oltre i limiti dell'array:" << endl;
    for (int i = 0; i < 15; ++i) { // Va oltre i limiti (fino a 14)
        arr[i] = i + 1;
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

int main() {
    // Chiamata alla funzione f()
    cout << "Esecuzione della funzione f():" << endl;
    f();

    // Chiamata alla funzione f_illegal()
    cout << "\nEsecuzione della funzione f_illegal():" << endl;
    f_illegal();

    return 0;
}
