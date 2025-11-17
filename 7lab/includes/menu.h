#pragma once

#include "binaryFile.h"

class Menu {
    BinaryFile file;
    void printMenu() const;
    void chooseOperation();
public:
    void start();
};