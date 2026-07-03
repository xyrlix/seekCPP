#ifndef IO_PRINTER_HPP
#define IO_PRINTER_HPP

#include <string>

namespace io {

class Printer {
public:
    void print(const std::string& message) const;
    void printLine(const std::string& message) const;
};

}

#endif