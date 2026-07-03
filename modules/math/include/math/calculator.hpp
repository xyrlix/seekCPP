#ifndef MATH_CALCULATOR_HPP
#define MATH_CALCULATOR_HPP

namespace math {

class Calculator {
public:
    int add(int a, int b) const;
    int subtract(int a, int b) const;
    int multiply(int a, int b) const;
    double divide(double a, double b) const;
};

}

#endif