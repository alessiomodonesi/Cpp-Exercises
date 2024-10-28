#include <iostream>

class Complex
{
public:
    Complex(int real, int imag);
    Complex(int real);
    Complex(void);
    int real(void) const;
    int imag(void) const;
    Complex &operator=(const Complex &a);

private:
    int r{0};
    int i{0};
};

std::ostream &operator<<(std::ostream &out, const Complex &a);
Complex operator+(const Complex &a, const Complex &b);
Complex operator+(const Complex &a, int b);