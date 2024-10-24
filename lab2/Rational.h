#include <iostream>

class Rational
{
public:
    Rational(int num, int den);
    Rational(int interger);
    Rational(void);

    int num(void) const;
    int den(void) const;
    Rational &operator=(const Rational &a);

private:
    int n{0};
    int d{0};
};

std::ostream &operator<<(std::ostream &out, const Rational &a);
Rational operator+(const Rational &a, const Rational &b);
Rational operator+(const Rational &a, int b);