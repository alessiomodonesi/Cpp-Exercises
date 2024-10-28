#include <stdexcept> // per std::invalid_argument

class Rational
{
public:
    // Constructors
    Rational() = default; // Costruttore di default
    Rational(int integer);
    Rational(int num, int den);

    // Accessor methods
    int num() const { return n; }
    int den() const { return d; }

    // Assignment operator
    Rational &operator=(const Rational &a);

private:
    int n{0};      // Numeratore
    int d{1};      // Denominatore
    void reduce(); // Metodo privato per ridurre la frazione
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