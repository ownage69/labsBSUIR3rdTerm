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
    T* data;
    int size;

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
Array<T>::Array(int n) : size(n), data(n > 0 ? new T[n] : nullptr) {
}

template <typename T>
Array<T>::Array(const Array& other) : size(other.size), data(size > 0 ? new T[size] : nullptr) {
    std::copy(other.data, other.data + size, data);
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
        data = (size > 0) ? new T[size] : nullptr;
        std::copy(other.data, other.data + size, data);
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](int index) {
    if (index < 0 || index >= size)
        throw std::out_of_range("������ ��� ���������!");
    return data[index];
}

template <typename T>
int Array<T>::getSize() const {
    return size;
}

template <typename T>
void Array<T>::fillArray() {
    if (size <= 0) {
        std::cout << "������ ����.\n";
        return;
    }
    std::cout << "������� " << size << " ���������:\n";
    for (int i = 0; i < size; i++) {
        data[i] = safeInputInt(std::format("[{}] = ", i));
    }
}

template <typename T>
void Array<T>::printArray() const {
    if (size <= 0) {
        std::cout << "������ ����.\n";
        return;
    }
    std::cout << "�������� �������:\n";
    for (int i = 0; i < size; i++)
        std::cout << data[i] << " ";
    std::cout << "\n";
}