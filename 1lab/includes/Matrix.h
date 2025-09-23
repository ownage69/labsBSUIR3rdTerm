#pragma once

class Matrix {
private:
    int rows = 0;
    int cols = 0;
    int** data = nullptr;

    void allocateMemory();
    void freeMemory();

public:
    Matrix() = default;
    Matrix(int r, int c);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other) noexcept;
    ~Matrix();

    void create(int r, int c);
    void copyFrom(const Matrix& other);

    void input() const;
    void display() const;
    bool subtract(const Matrix& other, Matrix& result) const;

    bool isValid() const { return data != nullptr && rows > 0 && cols > 0; }
    int getRows() const { return rows; }
    int getCols() const { return cols; }
};