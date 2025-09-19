#include "array.h"
#include <algorithm>

Array::Array() : size(0), data(nullptr) {}

Array::Array(int n) {
    if (n <= 0) {
        size = 0;
        data = nullptr;
    }
    else {
        size = n;
        data = new int[size];
        std::fill(data, data + size, 0);
    }
}

Array::Array(const Array& other) : size(other.size), data(nullptr) {
    if (size > 0) {
        data = new int[size]();
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
    data = nullptr;
    if (size > 0) {
        data = new int[size]();
        for (int i = 0; i < size; ++i) data[i] = other.data[i];
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
    return data[index];
}

const int& Array::operator[](int index) const {
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
    if (arr.size <= 0) {
        arr.size = 0;
        arr.data = nullptr;
    }
    else {
        arr.data = new int[arr.size];
        for (int i = 0; i < arr.size; ++i) {
            is >> arr.data[i];
        }
    }
    return is;
}