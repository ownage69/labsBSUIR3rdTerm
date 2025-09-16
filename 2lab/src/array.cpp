#include "array.h"

Array::Array(size_t s) : size(s), data(s ? new int[s] : nullptr) {
}

Array::~Array() {
    delete[] data;
}

Array::Array(const Array& other) : size(other.size), data(other.size ? new int[other.size] : nullptr) {
    if (data) {
        std::copy(other.data, other.data + size, data);
    }
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = other.size ? new int[other.size] : nullptr;
        if (data) {
            std::copy(other.data, other.data + size, data);
        }
    }
    return *this;
}

Array Array::operator+(const Array& other) const {
    Array result(size + other.size);
    std::copy(data, data + size, result.data);
    std::copy(other.data, other.data + other.size, result.data + size);
    return result;
}

int& Array::operator[](size_t index) {
    return data[index];
}

const int& Array::operator[](size_t index) const {
    return data[index];
}

std::ostream& operator<<(std::ostream& os, const Array& arr) {
    os << arr.size << ": ";
    for (size_t i = 0; i < arr.size; ++i) {
        os << arr.data[i];
        if (i < arr.size - 1) os << " ";
    }
    os << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Array& arr) {
    size_t newSize;
    is >> newSize;
    if (is.fail()) return is;

    delete[] arr.data;
    arr.size = newSize;
    arr.data = newSize ? new int[newSize] : nullptr;

    for (size_t i = 0; i < newSize; ++i) {
        is >> arr.data[i];
    }
    return is;
}