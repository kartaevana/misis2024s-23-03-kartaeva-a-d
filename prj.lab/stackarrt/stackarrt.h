#ifndef STACKARR
#define STACKARR

#include "complex/complex.hpp"
#include <cstddef>

template<class T>
class StackArrT final{
public:
    StackArrT() = default;
    StackArrT(const StackArrT& rhs);

    StackArrT& operator=(const StackArrT& rhs);
    ~StackArrT() = default;

    void Push(const T& rhs);
    void Pop() noexcept;
    T& Top() &;

    const T& Top() const &;

    void Clear() noexcept;

    bool IsEmpty() const noexcept;


private:
//    текущий индекс - индекс последнего внесённого элемента (НЕ следующего)
    int current_index = -1;
    std::ptrdiff_t capacity = 0;
    T* data_ = nullptr;
};

#endif //STACKARR
