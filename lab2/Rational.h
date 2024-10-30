#include <stdexcept>

class Rational
{
public:
    // Constructors
    Rational(void);
    Rational(int integer);
    Rational(int num, int den);

    // Accessor methods
    int num(void) const;
    int den(void) const;

    // Assignment operator
    Rational &operator=(const Rational &a);

private:
    int n{0};      
    int d{1};     
    void reduce();
};

// helper function
Rational operator+(const Rational &a, int b);
Rational operator+(const Rational &a, const Rational &b);

Rational operator-(const Rational &a, int b);
Rational operator-(const Rational &a, const Rational &b);

Rational operator*(const Rational &a, int b);
Rational operator*(const Rational &a, const Rational &b);

Rational operator/(const Rational &a, int b);
Rational operator/(const Rational &a, const Rational &b);

bool operator==(const Rational &a, int b);
bool operator==(const Rational &a, const Rational &b);

bool operator>(const Rational &a, int b);
bool operator>(const Rational &a, const Rational &b);

bool operator<(const Rational &a, int b);
bool operator<(const Rational &a, const Rational &b);

double to_double(const Rational &a);
std::ostream &operator<<(std::ostream &out, const Rational &a);