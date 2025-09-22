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
    Array(Array&& other) noexcept;
    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;
    ~Array();

    int getSize() const;
    int& operator[](int index);
    const int& operator[](int index) const;

    Array operator!() const;

    friend std::ostream& operator<<(std::ostream& os, const Array& arr) {
        os << arr.size << ":";
        if (arr.size > 0) os << ' ';
        for (int i = 0; i < arr.size; ++i) {
            os << arr.data[i];
            if (i + 1 < arr.size) os << ' ';
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Array& arr) {
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
};