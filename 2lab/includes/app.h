#pragma once
#include "array.h"

class App {
private:
    Array arr;
    bool hasArray = false;

    void printMenu() const;
    void inputArray();
    void showArray() const;
    void duplicateArray();

public:
    void run();
};