#include <iostream>
#include <cstring>
#include <vector>

class Fraction {
private:
    int numerator;
    int denominator;

    void reduce() {
        int gcd = findGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    int findGCD(int a, int b) {
        return b == 0 ? a : findGCD(b, a % b);
    }

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        reduce();
    }
    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Division by zero.");
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
        out << fraction.numerator << "/" << fraction.denominator;
        return out;
    }
};

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denom = other.real * other.real + other.imag * other.imag;
        if (denom == 0) {
            throw std::invalid_argument("Division by zero.");
        }
        return Complex((real * other.real + imag * other.imag) / denom, (imag * other.real - real * other.imag) / denom);
    }

    friend std::ostream& operator<<(std::ostream& out, const Complex& complex) {
        out << complex.real << (complex.imag >= 0 ? " + " : " - ") << fabs(complex.imag) << "i";
        return out;
    }
};

int main() {
    Fraction f1(3, 4);
    Fraction f2(2, 5);
    std::cout << "Fraction operations:" << std::endl;
    std::cout << f1 << " + " << f2 << " = " << f1 + f2 << std::endl;
    std::cout << f1 << " - " << f2 << " = " << f1 - f2 << std::endl;
    std::cout << f1 << " * " << f2 << " = " << f1 * f2 << std::endl;
    std::cout << f1 << " / " << f2 << " = " << f1 / f2 << std::endl;

    Complex c1(3, 4);
    Complex c2(1, -2);
    std::cout << "\nComplex number operations:" << std::endl;
    std::cout << c1 << " + " << c2 << " = " << c1 + c2 << std::endl;
    std::cout << c1 << " - " << c2 << " = " << c1 - c2 << std::endl;
    std::cout << c1 << " * " << c2 << " = " << c1 * c2 << std::endl;
    std::cout << c1 << " / " << c2 << " = " << c1 / c2 << std::endl;

    return 0;
}
