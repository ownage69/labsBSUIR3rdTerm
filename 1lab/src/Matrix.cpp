#include "Matrix.h"
#include "SafeInput.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <format>
using namespace std;

Matrix::Matrix(int r, int c) {
    if (r > 0 && c > 0) {
        create(r, c);
    }
}

Matrix::Matrix(const Matrix& other) {
    copyFrom(other);
}

Matrix::Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols), data(other.data) {
    other.rows = 0;
    other.cols = 0;
    other.data = nullptr;
}

Matrix::~Matrix() {
    freeMemory();
}

void Matrix::allocateMemory() {
    data = new int* [rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols]();
    }
}

void Matrix::freeMemory() {
    if (data) {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
    data = nullptr;
    rows = 0;
    cols = 0;
}

void Matrix::create(int r, int c) {
    if (r <= 0 || c <= 0) {
        freeMemory();
        return;
    }
    if (rows != r || cols != c) {
        freeMemory();
        rows = r;
        cols = c;
        allocateMemory();
    }
}

void Matrix::copyFrom(const Matrix& other) {
    if (this == &other) return;
    create(other.rows, other.cols);
    if (other.isValid()) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }
}

void Matrix::input() {
    if (!isValid()) {
        cout << "Матрица не создана.\n";
        return;
    }
    cout << "Введите элементы матрицы (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = safeInputInt(std::format("Элемент [{}][{}]: ", i + 1, j + 1));
        }
    }
}

void Matrix::display() const {
    if (!isValid()) {
        cout << "Матрица не создана.\n";
        return;
    }
    for (int i = 0; i < rows; i++) {
        string line;
        for (int j = 0; j < cols; j++) {
            string num_str = to_string(data[i][j]);
            int len = num_str.length();
            string padded = string(5 - len, ' ') + num_str;
            line += padded;
        }
        cout << line << "\n";
    }
}

bool Matrix::subtract(const Matrix& other, Matrix& result) const {
    if (!isValid() || !other.isValid()) {
        return false;
    }
    if (rows != other.rows || cols != other.cols) {
        return false;
    }
    result.create(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return true;
}