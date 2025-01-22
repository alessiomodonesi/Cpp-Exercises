#include <iostream>
#include <initializer_list>
#include <algorithm> // Necessario per std::copy

class vector
{
    int sz;       // Dimensione del vettore
    double *elem; // Puntatore ai dati del vettore (array dinamico)

public:
    // Costruttore che accetta la dimensione
    vector(int s) : sz{s}, elem{new double[s]}
    {
        // Inizializza tutti gli elementi a 0
        for (int i = 0; i < s; ++i)
            elem[i] = 0;
    }

    // Costruttore con initializer_list (C++11)
    vector(std::initializer_list<double> lst) : sz{static_cast<int>(lst.size())}, elem{new double[sz]}
    {
        // Copia i valori dall'initializer_list all'array dinamico
        std::copy(lst.begin(), lst.end(), elem);
    }

    // Costruttore di copia (necessario per una gestione corretta della memoria)
    vector(const vector &arg) : sz{arg.sz}, elem{new double[arg.sz]}
    {
        // Copia i valori dell'array dinamico dal vettore sorgente
        std::copy(arg.elem, arg.elem + sz, elem);
    }

    // Operatore di assegnazione per copia
    vector &operator=(const vector &a)
    {
        // Alloca un nuovo array per i dati
        double *p = new double[a.sz];
        // Copia i dati dal vettore sorgente al nuovo array
        std::copy(a.elem, a.elem + a.sz, p);
        // Libera la memoria precedentemente allocata
        delete[] elem;
        // Aggiorna il puntatore e la dimensione
        elem = p;
        sz = a.sz;
        return *this;
    }

    // Costruttore di move (C++11)
    vector(vector &&a) : sz{a.sz}, elem{a.elem}
    {
        // Trasferisce la proprietà della memoria dal sorgente al vettore corrente
        a.sz = 0; // Il vettore sorgente diventa vuoto
        a.elem = nullptr;
    }

    // Operatore di assegnazione per move (C++11)
    vector &operator=(vector &&a)
    {
        // Libera la memoria attuale
        delete[] elem;
        // Trasferisce la proprietà della memoria
        elem = a.elem;
        sz = a.sz;
        // Resetta il vettore sorgente
        a.elem = nullptr;
        a.sz = 0;
        return *this;
    }

    // Metodo che restituisce la dimensione del vettore
    int size() const { return this->sz; }

    // Metodo per aggiungere un elemento al vettore (da implementare)
    void push_back(double d);

    // Operatori per l'accesso agli elementi del vettore
    double &operator[](int n);      // Per accesso in lettura e scrittura
    double operator[](int n) const; // Per accesso in sola lettura

    // Distruttore (necessario per evitare memory leak)
    ~vector() { delete[] elem; } // Libera la memoria dinamica allocata
};
