#pragma once
#include "Matrix.h"

class App {
private:
    Matrix A;
    Matrix B;
    Matrix C;
    bool matricesCreated = false;

    void showMenu() const;
    void createMatrices();
    void inputMatrices();
    void displayMatrices() const;
    void subtractMatrices();

public:
    App() = default;
    void run();
};