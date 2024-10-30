#include "rational.h"
#include <iostream>
#include <cassert>

// g++ -o main main.cpp rational.cpp

void test_constructors() {
    Rational r1;
    assert(r1.num() == 0 && r1.den() == 1);
    
    Rational r2(5);
    assert(r2.num() == 5 && r2.den() == 1);
    
    Rational r3(3, 4);
    assert(r3.num() == 3 && r3.den() == 4);
    
    Rational r4(-6, -8);
    assert(r4.num() == 3 && r4.den() == 4); // Should reduce to 3/4
}

void test_addition() {
    Rational r1(1, 2);
    Rational r2(1, 3);
    Rational r3 = r1 + r2;
    assert(r3.num() == 5 && r3.den() == 6);
    
    Rational r4 = r1 + 1;
    assert(r4.num() == 3 && r4.den() == 2);
}

void test_subtraction() {
    Rational r1(3, 4);
    Rational r2(1, 2);
    Rational r3 = r1 - r2;
    assert(r3.num() == 1 && r3.den() == 4);
    
    Rational r4 = r1 - 1;
    assert(r4.num() == -1 && r4.den() == 4);
}

void test_multiplication() {
    Rational r1(2, 3);
    Rational r2(3, 4);
    Rational r3 = r1 * r2;
    assert(r3.num() == 1 && r3.den() == 2);
    
    Rational r4 = r1 * 3;
    assert(r4.num() == 2 && r4.den() == 1);
}

void test_division() {
    Rational r1(3, 4);
    Rational r2(2, 3);
    Rational r3 = r1 / r2;
    assert(r3.num() == 9 && r3.den() == 8);
    
    Rational r4 = r1 / 2;
    assert(r4.num() == 3 && r4.den() == 8);
}

void test_comparison() {
    Rational r1(1, 2);
    Rational r2(1, 2);
    assert(r1 == r2);
    
    Rational r3(3, 4);
    assert(r3 > r1);
    assert(r1 < r3);
    
    Rational r4(1, 2);
    assert(r1 == 1);
    assert(r1 < 2);
}

void test_to_double() {
    Rational r1(1, 2);
    assert(to_double(r1) == 0.5);
    
    Rational r2(3, 4);
    assert(to_double(r2) == 0.75);
}

void test_output() {
    Rational r1(3, 4);
    std::cout << "Expected output: 3/4, Actual output: " << r1 << std::endl;
    
    Rational r2(5);
    std::cout << "Expected output: 5, Actual output: " << r2 << std::endl;
}

int main() {
    test_constructors();
    test_addition();
    test_subtraction();
    test_multiplication();
    test_division();
    test_comparison();
    test_to_double();
    test_output();
    
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
