#pragma once

#include <iostream>
#include <cstddef>
#include <algorithm>
#include <format>

class Array {
private:
    size_t size;
    int* data;

public:
    explicit Array(size_t s = 0);
    ~Array();
    Array(const Array& other);
    Array& operator=(const Array& other);

    int& operator[](size_t index) {
        return data[index];
    }

    const int& operator[](size_t index) const {
        return data[index];
    }

    size_t getSize() const { return size; }

    friend Array operator+(const Array& lhs, const Array& rhs) {
        Array result(lhs.size + rhs.size);
        std::copy(lhs.data, lhs.data + lhs.size, result.data);
        std::copy(rhs.data, rhs.data + rhs.size, result.data + lhs.size);
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Array& arr) {
        os << arr.size << ": ";
        for (size_t i = 0; i < arr.size; ++i) {
            os << arr.data[i];
            if (i < arr.size - 1) os << " ";
        }
        os << std::endl;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Array& arr) {
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
};