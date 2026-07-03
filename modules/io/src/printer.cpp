#include "io/printer.hpp"
#include <iostream>

namespace io {

void Printer::print(const std::string& message) const {
    std::cout << message;
}

void Printer::printLine(const std::string& message) const {
    std::cout << message << std::endl;
}

}