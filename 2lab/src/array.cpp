#include "array.h"
#include <stdexcept>

Array::Array() {
    size = 0;
    data = nullptr;
}

Array::Array(int n) {
    if (n < 0) throw std::invalid_argument("Size cannot be negative");
    if (n == 0) {
        size = 0;
        data = nullptr;
        return;
    }
    size = n;
    data = new int[size];
    for (int i = 0; i < size; ++i) data[i] = 0;
}

Array::Array(const Array& other) {
    if (other.size > 0) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i) data[i] = other.data[i];
    }
    else {
        size = 0;
        data = nullptr;
    }
}

Array& Array::operator=(const Array& other) {
    if (this == &other) return *this;
    int* new_data = nullptr;
    if (other.size > 0) {
        new_data = new int[other.size];
        for (int i = 0; i < other.size; ++i) new_data[i] = other.data[i];
    }
    delete[] data;
    data = new_data;
    size = other.size;
    return *this;
}

Array::~Array() {
    delete[] data;
    data = nullptr;
    size = 0;
}

int Array::getSize() const {
    return size;
}

int& Array::operator[](int index) {
    if (index < 0 || index >= size) throw std::out_of_range("Index out of range");
    return data[index];
}

const int& Array::operator[](int index) const {
    if (index < 0 || index >= size) throw std::out_of_range("Index out of range");
    return data[index];
}

Array Array::operator!() const {
    if (size == 0) return Array();
    Array result(size * 2);
    for (int i = 0; i < size; ++i) {
        result.data[i] = data[i];
        result.data[i + size] = data[i];
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const Array& arr) {
    os << arr.size << ":";
    if (arr.size > 0) os << ' ';
    for (int i = 0; i < arr.size; ++i) {
        os << arr.data[i];
        if (i + 1 < arr.size) os << ' ';
    }
    return os;
}
