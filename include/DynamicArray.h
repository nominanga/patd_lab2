#pragma once
#include<algorithm>

template <typename T>
class DynamicArray
{
private:
    T*data;
    int size;

public:
    explicit DynamicArray(const int size) : size(size) {
        if (size < 0)
            throw std::invalid_argument("size must be positive");
        data = new T[size];
    }

    explicit DynamicArray(T* input, const int count) : size(count) {
        if (count < 0)
            throw std::invalid_argument("size must be positive");
        data = new T[count];
        std::copy(input, input + count, data);
    }

    DynamicArray(const DynamicArray& other) : size(other.size) {
        data = new T[size];
        std::copy(other.data, other.data + size, data);
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new T[size];
            std::copy(other.data, other.data + size, data);
        }
        return *this;
    }

    ~DynamicArray() {
        delete[] data;
    }
};
