#pragma once

#include <fstream>
#include <string>
#include <memory>
#include "Car.h"

class CarFile final {
public:
    explicit CarFile(const std::string& fn);
    ~CarFile() noexcept;

    CarFile(const CarFile& other);
    CarFile& operator=(const CarFile& other);
    CarFile(CarFile&& other) noexcept;
    CarFile& operator=(CarFile&& other) noexcept;

    CarFile& operator<<(const Car& car);
    CarFile& operator>>(Car& car);
    explicit operator bool() const;

    int countByYear(int year) const;
    void showAll() const;

private:
    std::unique_ptr<std::fstream> fileStream_;
    std::string filename_;
    std::size_t fileSize_{ 0 };

    void openFile(const std::string& filePath);
    void validateFileOpen() const;
    void ensureFileIsOpen() const;
    void closeFileSafely() noexcept;
};