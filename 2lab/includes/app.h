#pragma once
#include "array.h"

class App {
private:
    Array arr;
    bool hasArray;

    void printMenu();
    void inputArray();
    void showArray();
    void duplicateArray();

public:
    App();
    void run();
};