#include "Rational.h"
Rational::Rational(int num, int den) : n{num}, d(den) {}
int Rational::num(void) const
{
    return n;
}
int Rational::den(void) const
{
    return d;
}

std::ostream &operator<<(std::ostream &out, const Rational &a)
{
    return out << a.num() << "/" << a.den() << "i";
}

Rational operator+(const Rational &a, const Rational &b)
{
    int nump, denp;
    nump = a.num() + b.num();
    denp = a.den() + b.den();
    return Rational(nump, denp);
}

Rational operator+(const Rational &a, int b)
{
    return a + Rational(b);
}

Rational &Rational::operator=(const Rational &a)
{
    n = a.num();
    d = a.den();
    return *this;
}