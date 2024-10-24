#include <iostream>
#include "Rational.h"
int main(void)
{
    Rational c1(2, 1); // Costruttore
    Rational c2;       // Costruttore di default
    Rational c3;       // Costruttore di default
    Rational c4(1, 1); // Costruttore
    Rational c5, c6;   // Costruttore di default
    c3 = c1;           // assegnamento
    c4 = c1 + c4;      // somma due Rational
    c5 = c1 + 3;       // somma Rational e intero
    c6 = 3 + c1;       // somma intero e Rational
    std::cout << "Rational number c1: " << c1 << std::endl;
    std::cout << "Rational number c2: " << c2 << std::endl;
    std::cout << "Rational number c3: " << c3 << std::endl;
    std::cout << "Rational number c4: " << c4 << std::endl;
    std::cout << "Rational number c5: " << c5 << std::endl;
    std::cout << "Rational number c6: " << c6 << std::endl;
    return 0;
}