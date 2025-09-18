#pragma once

#include <cstddef>
#include <iostream>

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

    friend Array operator+(const Array& lhs, const Array& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Array& arr);
    friend std::istream& operator>>(std::istream& is, Array& arr);
};