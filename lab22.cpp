#include <iostream>
#include <cmath>
using namespace std;

class ComplexNumber {
public:
    double real, imag;
    
    ComplexNumber(double = 0, double = 0);

    // Operator Overloads
    ComplexNumber operator+(const ComplexNumber &) const;
    ComplexNumber operator-(const ComplexNumber &) const;
    ComplexNumber operator*(const ComplexNumber &) const;
    ComplexNumber operator/(const ComplexNumber &) const;
    bool operator==(const ComplexNumber &) const;

    // Absolute Value & Angle
    double abs() const;
    double angle() const;

    // Friend Functions for double Operations & Output Stream
    friend ComplexNumber operator+(double, const ComplexNumber &);
    friend ComplexNumber operator-(double, const ComplexNumber &);
    friend ComplexNumber operator*(double, const ComplexNumber &);
    friend ComplexNumber operator/(double, const ComplexNumber &);
    friend bool operator==(double, const ComplexNumber &);
    friend ostream &operator<<(ostream &, const ComplexNumber &);
};

// Constructor
ComplexNumber::ComplexNumber(double x, double y) {
    real = x;
    imag = y;
}

// Operator Overloading for ComplexNumber
ComplexNumber ComplexNumber::operator+(const ComplexNumber &c) const {
    return ComplexNumber(real + c.real, imag + c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c) const {
    return ComplexNumber(real - c.real, imag - c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c) const {
    return ComplexNumber(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c) const {
    double denominator = c.real * c.real + c.imag * c.imag;
    return ComplexNumber((real * c.real + imag * c.imag) / denominator, 
                         (imag * c.real - real * c.imag) / denominator);
}

bool ComplexNumber::operator==(const ComplexNumber &c) const {
    return (real == c.real && imag == c.imag);
}

// Friend functions for double operations
ComplexNumber operator+(double d, const ComplexNumber &c) {
    return ComplexNumber(d + c.real, c.imag);
}

ComplexNumber operator-(double d, const ComplexNumber &c) {
    return ComplexNumber(d - c.real, -c.imag);
}

ComplexNumber operator*(double d, const ComplexNumber &c) {
    return ComplexNumber(d * c.real, d * c.imag);
}

ComplexNumber operator/(double d, const ComplexNumber &c) {
    double denominator = c.real * c.real + c.imag * c.imag;
    return ComplexNumber(d * c.real / denominator, -d * c.imag / denominator);
}

bool operator==(double d, const ComplexNumber &c) {
    return (d == c.real && c.imag == 0);
}

// Absolute Value (Magnitude)
double ComplexNumber::abs() const {
    return sqrt(real * real + imag * imag);
}

// Angle in Degrees
double ComplexNumber::angle() const {
    return atan2(imag, real) * 180 / M_PI;
}

// Output Stream Overloading
ostream &operator<<(ostream &out, const ComplexNumber &c) {
    if (c.real == 0 && c.imag == 0) {
        out << "0";
    } else if (c.real == 0) {
        out << c.imag << "i";
    } else if (c.imag == 0) {
        out << c.real;
    } else {
        out << c.real;
        if (c.imag > 0) {
            out << "+" << c.imag << "i";
        } else {
            out << c.imag << "i";
        }
    }
    return out;
}




int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}





