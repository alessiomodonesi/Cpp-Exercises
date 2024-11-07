#include <iostream>
#include <stdexcept> // Per std::out_of_range
#include <algorithm> // Per std::copy

class MyVector
{
    int size;     // Numero di elementi effettivamente salvati
    int capacity; // Numero massimo di elementi gestibile con il buffer corrente
    double *elem; // Puntatore al buffer dinamico

    // Metodo privato per ridimensionare il buffer
    void resize(int new_capacity)
    {
        if (new_capacity <= capacity)
            return; // Non ridimensionare se il nuovo buffer non è più grande
        double *new_elem = new double[new_capacity];
        std::copy(elem, elem + size, new_elem); // Copia degli elementi esistenti
        delete[] elem;                          // Deallocazione del vecchio buffer
        elem = new_elem;
        capacity = new_capacity;
    }

public:
    // Costruttore con capacità iniziale
    MyVector(int initial_capacity = 10)
        : size{0}, capacity{initial_capacity}, elem{new double[initial_capacity]} {}

    // Distruttore
    ~MyVector()
    {
        delete[] elem;
    }

    // Metodo per aggiungere un elemento al vettore
    void push_back(double value)
    {
        if (size == capacity)
        {
            // Raddoppia la capacità per gestire la crescita esponenziale
            int new_capacity = capacity > 0 ? capacity * 2 : 1;
            resize(new_capacity);
        }
        elem[size++] = value; // Aggiungi l'elemento e incrementa la dimensione
    }

    // Overloading dell'operatore [] in versione non const
    double &operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Indice fuori dai limiti");
        }
        return elem[index];
    }

    // Overloading dell'operatore [] in versione const
    const double &operator[](int index) const
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Indice fuori dai limiti");
        }
        return elem[index];
    }

    // Funzione per ottenere la dimensione del vettore
    int get_size() const
    {
        return size;
    }

    // Funzione per ottenere la capacità del buffer
    int get_capacity() const
    {
        return capacity;
    }

    // Funzione per rimuovere l'ultimo elemento (simile a pop_back)
    void pop_back()
    {
        if (size > 0)
        {
            --size;
        }
        else
        {
            throw std::underflow_error("Il vettore è già vuoto");
        }
    }
};

// Funzione di test
int main()
{
    try
    {
        MyVector vec;

        // Aggiunta di elementi al vettore
        for (int i = 0; i < 15; ++i)
        {
            vec.push_back(i * 1.5);
            std::cout << "Aggiunto: " << i * 1.5 << ", Dimensione: " << vec.get_size()
                      << ", Capacità: " << vec.get_capacity() << std::endl;
        }

        // Accesso agli elementi tramite l'operatore []
        for (int i = 0; i < vec.get_size(); ++i)
        {
            std::cout << "vec[" << i << "] = " << vec[i] << std::endl;
        }

        // Rimozione di elementi con pop_back
        vec.pop_back();
        std::cout << "Dopo pop_back, Dimensione: " << vec.get_size() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Errore: " << e.what() << std::endl;
    }

    return 0;
}
