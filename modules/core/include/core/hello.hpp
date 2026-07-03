#ifndef CORE_HELLO_HPP
#define CORE_HELLO_HPP

#include <string>

namespace core {

class Hello {
public:
    Hello(const std::string& name);
    std::string greet() const;

private:
    std::string name_;
};

}

#endif