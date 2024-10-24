#include <iostream>

class Rational
{
public:
    // constructor
    Rational(void);             // punto A
    Rational(int interger);     // punto B
    Rational(int num, int den); // punto C

    // member function
    int num(void) const;
    int den(void) const;
    Rational &operator=(const Rational &a); // punto D

private:
    // variables
    int n{0};
    int d{1};
};

// helper function
Rational operator+(const Rational &a, int b); // punti E
Rational operator+(const Rational &a, const Rational &b);

Rational operator-(const Rational &a, int b); // punto F
Rational operator-(const Rational &a, const Rational &b);

Rational operator*(const Rational &a, int b); // punto G
Rational operator*(const Rational &a, const Rational &b);

Rational operator/(const Rational &a, int b); // punto H
Rational operator/(const Rational &a, const Rational &b);

// punto I
Rational operator==(const Rational &a, int b);
Rational operator==(const Rational &a, const Rational &b);

Rational operator>(const Rational &a, int b);
Rational operator>(const Rational &a, const Rational &b);

Rational operator<(const Rational &a, int b);
Rational operator<(const Rational &a, const Rational &b);

std::ostream &operator<<(std::ostream &out, const Rational &a);
double ::to_double(const Rational &a);