#include "Rational.h"
// #include <algorithm>

Rational::Rational(int num, int den) : n{num}, d(den) {}
int Rational::num(void) const
{
    return n;
}
int Rational::den(void) const
{
    return d;
}

Rational &Rational::operator=(const Rational &a) // punto D
{
    n = a.num();
    d = a.den();
    return *this;
}

Rational operator+(const Rational &a, const Rational &b) // punto E
{
    int nump, denp;
    nump = (a.num() * b.den()) + (b.num() * a.den());
    denp = a.den() * b.den();
    return Rational(nump, denp);
    // return Rational(__gcd(nump, denp));
}

Rational operator+(const Rational &a, int b)
{
    int nump = a.num() + (a.den() * b);
    return Rational(nump, a.den());
    // return Rational(__gcd(nump, denp));
}

Rational operator-(const Rational &a, const Rational &b) // punto F
{
    int nump, denp;
    nump = (a.num() * b.den()) - (b.num() * a.den());
    denp = a.den() * b.den();
    return Rational(nump, denp);
    // return Rational(__gcd(nump, denp));
}

Rational operator-(const Rational &a, int b)
{
    int nump = a.num() - (a.den() * b);
    return Rational(nump, a.den());
    // return Rational(__gcd(nump, denp));
}

Rational operator*(const Rational &a, const Rational &b) // punto G
{
    int nump, denp;
    nump = a.num() * b.num();
    denp = a.den() * b.den();
    return Rational(nump, denp);
    // return Rational(__gcd(nump, denp));
}

Rational operator*(const Rational &a, int b)
{
    return Rational(a.num() * b, a.den());
    // return Rational(__gcd(nump, denp));
}

Rational operator/(const Rational &a, const Rational &b) // punto H
{
    int nump, denp;
    nump = a.num() * b.den();
    denp = a.den() * b.num();
    return Rational(nump, denp);
    // return Rational(__gcd(nump, denp));
}

Rational operator/(const Rational &a, int b)
{
    return Rational(a.num(), a.den() * b);
    // return Rational(__gcd(nump, denp));
}

Rational operator==(const Rational &a, const Rational &b) // punto I
{
    return to_double(Rational(a)) == to_double(Rational(b));
}

Rational operator==(const Rational &a, int b)
{
    return to_double(Rational(a)) == b;
}

Rational operator>(const Rational &a, const Rational &b)
{
    return to_double(Rational(a)) > to_double(Rational(b));
}

Rational operator>(const Rational &a, int b)
{
    return to_double(Rational(a)) > b;
}

Rational operator<(const Rational &a, const Rational &b)
{
    return to_double(Rational(a)) < to_double(Rational(b));
}

Rational operator<(const Rational &a, int b)
{
    return to_double(Rational(a)) < b;
}

std::ostream &operator<<(std::ostream &out, const Rational &a)
{
    return out << a.num() << "/" << a.den();
}

double ::to_double(const Rational &a)
{
    return (double)(a.num() / a.den());
}
