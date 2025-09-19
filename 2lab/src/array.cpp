#include "array.h"
#include <stdexcept>

Array::Array() : size(0), data(nullptr) {}

Array::Array(int n) {
    if (n < 0) throw std::invalid_argument("Size cannot be negative");
    size = n;
    data = (n > 0) ? new int[size] {} : nullptr;
}

Array::Array(const Array& other) : size(other.size), data(nullptr) {
    if (size > 0) {
        data = new int[size];
        for (int i = 0; i < size; ++i) data[i] = other.data[i];
    }
}

Array& Array::operator=(const Array& other) {
    if (this == &other) return *this;
    delete[] data;
    size = other.size;
    data = nullptr;
    if (size > 0) {
        data = new int[size];
        for (int i = 0; i < size; ++i) data[i] = other.data[i];
    }
    return *this;
}

Array::~Array() {
    delete[] data;
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
        result[i] = data[i];
        result[i + size] = data[i];
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

std::istream& operator>>(std::istream& is, Array& arr) {
    delete[] arr.data;
    is >> arr.size;
    arr.data = (arr.size > 0) ? new int[arr.size] : nullptr;
    for (int i = 0; i < arr.size; ++i) {
        is >> arr.data[i];
    }
    return is;
}