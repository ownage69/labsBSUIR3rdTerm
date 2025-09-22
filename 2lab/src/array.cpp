#include "array.h"
#include <algorithm>
#include <stdexcept>

Array::Array() : size(0), data(nullptr) {}

Array::Array(int n) {
    if (n <= 0) {
        throw std::invalid_argument("Array size must be positive");
    }
    size = n;
    data = new int[size];
    std::fill(data, data + size, 0);
}

Array::Array(const Array& other) : size(other.size), data(nullptr) {
    if (size > 0) {
        data = new int[size];
        for (int i = 0; i < size; ++i) data[i] = other.data[i];
    }
}

Array::Array(Array&& other) noexcept : size(other.size), data(other.data) {
    other.size = 0;
    other.data = nullptr;
}

Array& Array::operator=(const Array& other) {
    if (this == &other) return *this;
    delete[] data;
    size = other.size;
    if (size > 0) {
        data = new int[size];
        for (int i = 0; i < size; ++i) data[i] = other.data[i];
    }
    else {
        data = nullptr;
    }
    return *this;
}

Array& Array::operator=(Array&& other) noexcept {
    if (this == &other) return *this;
    delete[] data;
    size = other.size;
    data = other.data;
    other.size = 0;
    other.data = nullptr;
    return *this;
}

Array::~Array() {
    delete[] data;
}

int Array::getSize() const {
    return size;
}

int& Array::operator[](int index) {
    if (size == 0 || data == nullptr) {
        throw std::out_of_range("Access to empty array");
    }
    if (index < 0 || index >= size) throw std::out_of_range("Index out of range");
    return data[index];
}

const int& Array::operator[](int index) const {
    if (size == 0 || data == nullptr) {
        throw std::out_of_range("Access to empty array");
    }
    if (index < 0 || index >= size) throw std::out_of_range("Index out of range");
    return data[index];
}

Array Array::operator!() const {
    if (size == 0) return Array();
    Array result(size * 2);
    for (int i = 0; i < size; ++i) {
        result[i] = data[i];
        result[i + size] = data[i];
    }
    return result;
}
