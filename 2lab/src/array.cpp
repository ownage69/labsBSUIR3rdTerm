#include "Array.h"
#include <limits>

MyArray::MyArray(int s) : data(nullptr), size(0) {
    if (s > 0) {
        size = s;
        data = new int[size];
        for (int i = 0; i < size; ++i) data[i] = 0;
    }
}

MyArray::MyArray(const MyArray& other) : data(nullptr), size(0) {
    if (other.size > 0) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i) data[i] = other.data[i];
    }
}

MyArray::~MyArray() {
    delete[] data;
}

MyArray& MyArray::operator=(const MyArray& other) {
    if (this == &other) return *this; 

    delete[] data;
    data = nullptr;
    size = 0;

    if (other.size > 0) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i) data[i] = other.data[i];
    }

    return *this; 
}

MyArray MyArray::operator+(const MyArray& other) const {
    if (size + other.size == 0) {
        return MyArray();
    }

    MyArray res(size + other.size);

    if (size > 0) {
        for (int i = 0; i < size; ++i) {
            res.data[i] = data[i];
        }
    }

    if (other.size > 0) {
        for (int j = 0; j < other.size; ++j) {
            res.data[size + j] = other.data[j];
        }
    }

    return res;
}

istream& operator>>(istream& in, MyArray& arr) {
    int s;
    cout << "Введите количество элементов массива (целое >= 0): ";
    while (!(in >> s) || s < 0) {
        cout << "Неверный ввод. Введите неотрицательное целое: ";
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    delete[] arr.data;
    arr.size = s;
    arr.data = (arr.size > 0) ? new int[arr.size] : nullptr;

    for (int i = 0; i < arr.size; ++i) {
        cout << "Элемент [" << i << "]: ";
        while (!(in >> arr.data[i])) {
            cout << "Неверный ввод. Введите целое для элемента [" << i << "]: ";
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return in;
}


ostream& operator<<(ostream& out, const MyArray& arr) {
    out << "[";
    for (int i = 0; i < arr.size; ++i) {
        if (i) out << ", ";
        out << arr.data[i];
    }
    out << "]";
    return out;
}
