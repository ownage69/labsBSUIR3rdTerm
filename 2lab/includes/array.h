#pragma once

#include <iostream>
#include <cstddef>
#include <algorithm>

class Array {
private:
    int* data;
    size_t size;

public:
    Array(size_t s = 0);
    ~Array();
    Array(const Array& other);
    Array& operator=(const Array& other);
    Array operator+(const Array& other) const;
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    size_t getSize() const { return size; }

    friend std::ostream& operator<<(std::ostream& os, const Array& arr);
    friend std::istream& operator>>(std::istream& is, Array& arr);
};