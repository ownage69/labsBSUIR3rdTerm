#pragma once

#include "binaryFile.h"

class Menu {
    BinaryFile file;
    void printMenu() const;
    void chooseOperation();

    void insertCar();
    void displayCars();
    void countByYear();
    void clearFile();

public:
    void start();
};
