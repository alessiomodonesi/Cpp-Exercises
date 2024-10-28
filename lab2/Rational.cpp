#include "rational.h"
#include <stdexcept>
#include <numeric>

Rational::Rational(void) : n(0), d(1) {}

Rational::Rational(int integer) : n(integer), d(1) {}

Rational::Rational(int num, int den) : n(num), d(den)
{
    if (den == 0)
        throw std::invalid_argument("Denominator cannot be zero.");
    reduce();
}

int Rational::num(void) const
{
    return n;
}

int Rational::den(void) const
{
    return d;
}

Rational &Rational::operator=(const Rational &a)
{
    if (this != &a) // controllo auto-assegnazione
    {
        n = a.num();
        d = a.den();
    }
    return *this;
}

Rational operator+(const Rational &a, const Rational &b)
{
    int nump, denp;
    nump = (a.num() * b.den()) + (b.num() * a.den());
    denp = a.den() * b.den();
    return Rational(nump, denp);
}

Rational operator+(const Rational &a, int b)
{
    int nump = a.num() + (a.den() * b);
    return Rational(nump, a.den());
}

Rational operator-(const Rational &a, const Rational &b)
{
    int nump, denp;
    nump = (a.num() * b.den()) - (b.num() * a.den());
    denp = a.den() * b.den();
    return Rational(nump, denp);
}

Rational operator-(const Rational &a, int b)
{
    int nump = a.num() - (a.den() * b);
    return Rational(nump, a.den());
}

Rational operator*(const Rational &a, const Rational &b)
{
    int nump, denp;
    nump = a.num() * b.num();
    denp = a.den() * b.den();
    return Rational(nump, denp);
}

Rational operator*(const Rational &a, int b)
{
    return Rational(a.num() * b, a.den());
}

Rational operator/(const Rational &a, const Rational &b)
{
    int nump, denp;
    nump = a.num() * b.den();
    denp = a.den() * b.num();
    return Rational(nump, denp);
}

Rational operator/(const Rational &a, int b)
{
    return Rational(a.num(), a.den() * b);
}

bool operator==(const Rational &a, const Rational &b)
{
    return (a.num() * b.den() == b.num() * a.den());
}

bool operator==(const Rational &a, int b)
{
    return (a.num() == (b * a.den()));
}

bool operator>(const Rational &a, const Rational &b)
{
    return (a.num() * b.den() > b.num() * a.den());
}

bool operator>(const Rational &a, int b)
{
    return (a.num() > (b * a.den()));
}

bool operator<(const Rational &a, const Rational &b)
{
    return (a.num() * b.den() < b.num() * a.den());
}

bool operator<(const Rational &a, int b)
{
    return (a.num() < (b * a.den()));
}

std::ostream &operator<<(std::ostream &out, const Rational &a)
{
    if (a.den() == 1)
        return out << a.num(); // Solo numeratore se denominatore è 1
    return out << a.num() << '/' << a.den();
}

double to_double(const Rational &a)
{
    return ((double)a.num() / (double)a.den());
}

// Metodo privato per ridurre la frazione al termine minimo
void Rational::reduce()
{
    int gcd = std::gcd(n, d);
    n /= gcd;
    d /= gcd;

    // Assicura che il denominatore sia sempre positivo
    if (d < 0)
    {
        n = -n;
        d = -d;
    }
}