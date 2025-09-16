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

int& Array::operator[](size_t index) {
    return data[index];
}

const int& Array::operator[](size_t index) const {
    return data[index];
}