#include <iostream>
#include <stdexcept> // Per std::out_of_range

class MyVector
{
    int size;     // Lunghezza del vettore
    double *elem; // Puntatore al buffer dinamico

public:
    // Costruttore
    MyVector(int s) : size{s}, elem{new double[s]}
    {
        for (int i = 0; i < s; ++i)
        {
            elem[i] = 0; // Inizializzazione a 0
        }
    }

    // Distruttore
    ~MyVector()
    {
        delete[] elem;
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

    // Funzione safe_set
    void safe_set(int index, double value)
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Indice fuori dai limiti in safe_set");
        }
        elem[index] = value;
    }

    // Funzione safe_get
    double safe_get(int index) const
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Indice fuori dai limiti in safe_get");
        }
        return elem[index];
    }

    // Metodo per ottenere la lunghezza del vettore
    int get_size() const
    {
        return size;
    }
};

// Funzione di test
int main()
{
    try
    {
        MyVector vec(5);

        // Impostazione dei valori tramite safe_set
        for (int i = 0; i < vec.get_size(); ++i)
        {
            vec.safe_set(i, i * 2.0);
        }

        // Visualizzazione dei valori tramite safe_get
        for (int i = 0; i < vec.get_size(); ++i)
        {
            std::cout << "vec[" << i << "] = " << vec.safe_get(i) << std::endl;
        }

        // Accesso tramite operatore []
        vec[2] = 10.5;
        std::cout << "Dopo la modifica, vec[2] = " << vec[2] << std::endl;

        // Accesso fuori dai limiti per testare l'eccezione
        // std::cout << vec[10] << std::endl; // Decommenta per testare l'eccezione
    }
    catch (const std::exception &e)
    {
        std::cerr << "Errore: " << e.what() << std::endl;
    }

    return 0;
}
