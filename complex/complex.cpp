#include "complex.h"

Complex::Complex(int real, int imag) : r{real}, i(imag) {}
Complex::Complex(int real) : r{real} {}
Complex::Complex(void) {}
int Complex::real(void) const
{
    return r;
}
int Complex::imag(void) const
{
    return i;
}

std::ostream &operator<<(std::ostream &out, const Complex &a)
{
    return out << a.real() << "+" << a.imag() << "i";
}

Complex operator+(const Complex &a, const Complex &b)
{
    int realp, imagp;
    realp = a.real() + b.real();
    imagp = a.imag() + b.imag();
    return Complex(realp, imagp);
}

Complex operator+(const Complex &a, int b)
{
    return a + Complex(b);
}

Complex &Complex::operator=(const Complex &a)
{
    r = a.real();
    i = a.imag();
    return *this;
}