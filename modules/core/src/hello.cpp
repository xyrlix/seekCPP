#include "core/hello.hpp"

namespace core {

Hello::Hello(const std::string& name) : name_(name) {}

std::string Hello::greet() const {
    return "Hello, " + name_ + "!";
}

}