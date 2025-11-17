#pragma once

#include "car.h"
#include "safeInput.h"
#include <fstream>
#include <string>

class BinaryFile {
    std::string fileName;
    std::fstream fileStream;
public:
    BinaryFile();
    explicit BinaryFile(const std::string& name);
    ~BinaryFile();
    bool open(bool truncate = false);
    bool isOpen();
    bool isEmpty();
    void close();
    void show();
    void writeObject(const Car& car);
    void readObject(Car& car);
    int findCarsByYear(int year);
};