#ifndef MEMORY_CALCULATOR_HPP
#define MEMORY_CALCULATOR_HPP 

#include <atomic>
#include <cstdint>

namespace memory {

class RequestCounter {
private:
    std::atomic<uint32_t> total_{0};
public:
    void onRequest() noexcept {
        total_.fetch_add(1, std::memory_order_relaxed);
    }

    uint32_t getTotal() const noexcept {
        return total_.load(std::memory_order_relaxed);
    }
};

}

#endif