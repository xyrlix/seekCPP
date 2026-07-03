#include "core/hello.hpp"
#include "math/calculator.hpp"
#include "memory/relaxed.hpp"
#include <gtest/gtest.h>

TEST(CoreTest, Greet) {
    core::Hello h("World");
    EXPECT_EQ(h.greet(), "Hello, World!");
}

TEST(MathTest, Add) {
    math::Calculator calc;
    EXPECT_EQ(calc.add(2, 3), 5);
    EXPECT_EQ(calc.add(-1, 1), 0);
    EXPECT_EQ(calc.add(0, 0), 0);
}

TEST(MathTest, Multiply) {
    math::Calculator calc;
    EXPECT_EQ(calc.multiply(4, 5), 20);
    EXPECT_EQ(calc.multiply(-2, 3), -6);
}

TEST(MemoryTest, RequestCounter) {
    memory::RequestCounter counter;
    EXPECT_EQ(counter.getTotal(), 0);
    counter.onRequest();
    EXPECT_EQ(counter.getTotal(), 1);
    counter.onRequest();
    EXPECT_EQ(counter.getTotal(), 2);
}