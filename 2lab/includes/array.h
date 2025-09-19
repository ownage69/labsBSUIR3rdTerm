#pragma once
#include <iostream>

class Array {
private:
    int size;
    int* data;

public:
    Array();
    explicit Array(int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    int getSize() const;
    int& operator[](int index);
    const int& operator[](int index) const;

    Array operator!() const;

    friend std::ostream& operator<<(std::ostream& os, const Array& arr);
    friend std::istream& operator>>(std::istream& is, Array& arr);
};