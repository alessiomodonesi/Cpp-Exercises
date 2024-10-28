#include <iostream>
#include "Rational.h"

int main()
{
    // Create rational numbers
    Rational r1(3, 4); // 3/4
    Rational r2(2, 5); // 2/5
    Rational r3;       // default 0/1
    Rational r4(5);    // 5/1

    // Display the rational numbers
    std::cout << "Rational numbers:" << std::endl;
    std::cout << "r1 = " << r1 << std::endl;
    std::cout << "r2 = " << r2 << std::endl;
    std::cout << "r3 (default) = " << r3 << std::endl;
    std::cout << "r4 (integer constructor) = " << r4 << std::endl;

    // Test addition
    Rational add1 = r1 + r2;
    Rational add2 = r1 + 3;
    std::cout << "\nAddition:" << std::endl;
    std::cout << "r1 + r2 = " << add1 << std::endl;
    std::cout << "r1 + 3 = " << add2 << std::endl;

    // Test subtraction
    Rational sub1 = r1 - r2;
    Rational sub2 = r1 - 2;
    std::cout << "\nSubtraction:" << std::endl;
    std::cout << "r1 - r2 = " << sub1 << std::endl;
    std::cout << "r1 - 2 = " << sub2 << std::endl;

    // Test multiplication
    Rational mul1 = r1 * r2;
    Rational mul2 = r1 * 4;
    std::cout << "\nMultiplication:" << std::endl;
    std::cout << "r1 * r2 = " << mul1 << std::endl;
    std::cout << "r1 * 4 = " << mul2 << std::endl;

    // Test division
    Rational div1 = r1 / r2;
    Rational div2 = r1 / 2;
    std::cout << "\nDivision:" << std::endl;
    std::cout << "r1 / r2 = " << div1 << std::endl;
    std::cout << "r1 / 2 = " << div2 << std::endl;

    // Test comparisons
    std::cout << "\nComparisons:" << std::endl;
    std::cout << "r1 == r2: " << (r1 == r2 ? "true" : "false") << std::endl;
    std::cout << "r1 == 3: " << (r1 == 3 ? "true" : "false") << std::endl;
    std::cout << "r1 > r2: " << (r1 > r2 ? "true" : "false") << std::endl;
    std::cout << "r1 < r2: " << (r1 < r2 ? "true" : "false") << std::endl;

    // Test conversion to double
    std::cout << "\nConversion to double:" << std::endl;
    std::cout << "r1 as double: " << to_double(r1) << std::endl;
    std::cout << "r2 as double: " << to_double(r2) << std::endl;

    return 0;
}
