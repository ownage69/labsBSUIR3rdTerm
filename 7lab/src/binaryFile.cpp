#include "binaryFile.h"
#include <iostream>
#include <iomanip>

BinaryFile::BinaryFile() : fileName("cars.bin") {}
BinaryFile::BinaryFile(const std::string& name) : fileName(name) {}

BinaryFile::~BinaryFile() {
    close();
}

bool BinaryFile::open(bool clearFile) {
    if (fileStream.is_open()) {
        close();
    }
    std::ios_base::openmode mode = std::ios::binary | std::ios::in | std::ios::out;
    if (clearFile) {
        mode |= std::ios::trunc;
    }
    fileStream.open(fileName, mode);
    return fileStream.is_open();
}

void BinaryFile::close() {
    if (fileStream.is_open()) {
        fileStream.close();
    }
}

bool BinaryFile::isOpen() const {
    return fileStream.is_open();
}

bool BinaryFile::isEmpty() {
    if (!isOpen()) {
        return true;
    }
    fileStream.seekg(0, std::ios::end);
    size_t length = fileStream.tellg();
    fileStream.seekg(0, std::ios::beg);
    return length == 0;
}

void BinaryFile::show() {
    if (!isOpen()) {
        std::cout << "Error: File is not open.\n";
        return;
    }
    if (isEmpty()) {
        std::cout << "File is empty.\n";
        return;
    }
    fileStream.seekg(0, std::ios::beg);
    Car car;
    std::cout << "File contents:\n";
    while (fileStream >> car) {
        std::cout << car;
    }
    if (!fileStream.eof()) {
        std::cout << "Error: File may be corrupted or incomplete.\n";
    }
    fileStream.clear();
    fileStream.seekg(0, std::ios::beg);
}

void BinaryFile::writeObject(const Car& car) {
    if (!isOpen()) {
        std::cout << "Error: File is not open.\n";
        return;
    }
    fileStream.seekp(0, std::ios::end);
    fileStream << car;
}

void BinaryFile::readObject(Car& car) {
    if (!isOpen()) {
        std::cout << "Error: File is not open.\n";
        return;
    }
    fileStream >> car;
}

int BinaryFile::findCarsByYear(int year) {
    if (!isOpen()) {
        std::cout << "Error: File is not open.\n";
        return 0;
    }
    if (isEmpty()) {
        std::cout << "File is empty.\n";
        return 0;
    }
    fileStream.seekg(0, std::ios::beg);
    Car car;
    int count = 0;
    while (fileStream >> car) {
        if (car.getYearOfRelease() == year) {
            count++;
        }
    }
    if (!fileStream.eof()) {
        std::cout << "Error: File may be corrupted or incomplete.\n";
    }
    fileStream.clear();
    fileStream.seekg(0, std::ios::beg);
    return count;
}