#include <iostream>
#include "Complex.h"
int main(void)
{
    Complex c1(2, 1); // Costruttore
    Complex c2;       // Costruttore di default
    Complex c3;       // Costruttore di default
    Complex c4(1, 1); // Costruttore
    Complex c5, c6;   // Costruttore di default
    c3 = c1;          // assegnamento
    c4 = c1 + c4;     // somma due Complex
    c5 = c1 + 3;      // somma Complex e intero
    c6 = 3 + c1;      // somma intero e Complex
    std::cout << "Complex number c1: " << c1 << std::endl;
    std::cout << "Complex number c2: " << c2 << std::endl;
    std::cout << "Complex number c3: " << c3 << std::endl;
    std::cout << "Complex number c4: " << c4 << std::endl;
    std::cout << "Complex number c5: " << c5 << std::endl;
    std::cout << "Complex number c6: " << c6 << std::endl;
    return 0;
}