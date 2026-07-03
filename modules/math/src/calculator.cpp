#include "math/calculator.hpp"

namespace math {

int Calculator::add(int a, int b) const {
    return a + b;
}

int Calculator::subtract(int a, int b) const {
    return a - b;
}

int Calculator::multiply(int a, int b) const {
    return a * b;
}

double Calculator::divide(double a, double b) const {
    return a / b;
}

}