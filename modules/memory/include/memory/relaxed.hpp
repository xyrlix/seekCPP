#ifndef MEMORY_CALCULATOR_HPP
#define MEMORY_CALCULATOR_HPP 

#include <atomic>
#include <cstdint>

namespace memory {

// 纯计数器，不使用锁，不使用原子操作
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

class IdGenerator {
private:
    std::atomic<uint32_t> id_{0};
public:
    uint32_t next() {
        return id_.fetch_add(1, std::memory_order_relaxed) + 1;
    }
}

}

#endif