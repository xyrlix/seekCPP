#include "core/hello.hpp"
#include "math/calculator.hpp"
#include "io/printer.hpp"
#include "memory/relaxed.hpp"

int main() {
    core::Hello hello("C++ Modules");
    math::Calculator calc;
    io::Printer printer;
    memory::RequestCounter counter;

    printer.printLine(hello.greet());
    counter.onRequest();

    printer.printLine(hello.greet());
    counter.onRequest();

    int result = calc.add(10, 20);
    printer.printLine("10 + 20 = " + std::to_string(result));

    result = calc.multiply(5, 6);
    printer.printLine("5 * 6 = " + std::to_string(result));

    double divResult = calc.divide(100, 4);
    printer.printLine("100 / 4 = " + std::to_string(divResult));
    counter.onRequest();

    printer.printLine("Total requests: " + std::to_string(counter.getTotal()));

    return 0;
}