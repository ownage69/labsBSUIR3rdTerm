#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <format>
#include "safeInput.h"

template <typename T>
class Array {
private:
    int size = 0;
    T* data = nullptr;

public:
    explicit Array(int n = 0);
    Array(const Array& other);
    ~Array();

    Array& operator=(const Array& other);
    T& operator[](int index);
    int getSize() const;
    void fillArray();
    void printArray() const;
};

template <typename T>
Array<T>::Array(int n) : size(n), data(nullptr) {
    if (size > 0) {
        data = new T[size];
    }
}

template <typename T>
Array<T>::Array(const Array& other) : size(other.size), data(nullptr) {
    if (size > 0) {
        data = new T[size];
        std::copy(other.data, other.data + size, data);
    }
}

template <typename T>
Array<T>::~Array() {
    delete[] data;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = nullptr;
        if (size > 0) {
            data = new T[size];
            std::copy(other.data, other.data + size, data);
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](int index) {
    if (index < 0 || index >= size)
        throw std::out_of_range("Индекс вне диапазона!");
    return data[index];
}

template <typename T>
int Array<T>::getSize() const {
    return size;
}

template <typename T>
void Array<T>::fillArray() {
    if (size <= 0) {
        std::cout << "Массив пуст.\n";
        return;
    }
    std::cout << "Введите " << size << " элементов:\n";
    for (int i = 0; i < size; i++) {
        data[i] = safeInputInt(std::format("[{}] = ", i + 1));
    }
}

template <typename T>
void Array<T>::printArray() const {
    if (size <= 0) {
        std::cout << "Массив пуст.\n";
        return;
    }
    std::cout << "Элементы массива:\n";
    for (int i = 0; i < size; i++)
        std::cout << data[i] << " ";
    std::cout << "\n";
}