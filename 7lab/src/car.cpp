#include "car.h"
#include "safeinput.h"
#include <iomanip>
#include <limits>
#include <cstring>
#include <cstddef>

constexpr size_t MAX_STR_SIZE = 1024;

Car::Car() : regNumber("1111 AA-1"), yearOfRelease(1900), bodyColor("black") {}

Car::Car(const std::string& regNumber, int yearOfRelease, const std::string& bodyColor)
    : regNumber(regNumber), yearOfRelease(yearOfRelease), bodyColor(bodyColor) {
}

std::string Car::getRegNumber() const {
    return regNumber;
}
int Car::getYearOfRelease() const {
    return yearOfRelease;
}
std::string Car::getBodyColor() const {
    return bodyColor;
}
void Car::input() {
    std::cout << "Creating a new vehicle:\n";
    while (true) {
        regNumber = safeInputString("Enter vehicle registration number (e.g., 5678 BC-2):\n");
        if (checkCorrectRegNum(regNumber)) {
            break;
        }
        std::cout << "Invalid registration number format. Please try again.\n";
    }
    while (true) {
        yearOfRelease = safeInputInt("Enter the vehicle's production year (between 1990 and 2025):\n");
        if (yearOfRelease >= 1990 && yearOfRelease <= 2025) {
            break;
        }
        std::cout << "Year must be between 1990 and 2025. Please try again.\n";
    }
    bodyColor = safeInputString("Enter the body color (e.g., silver, blue, green):\n");
    std::cout << "New vehicle added successfully.\n";
}

bool Car::readFromStream(std::fstream& in) {
    size_t regNumberSize;
    auto regNumberSizeBytes = reinterpret_cast<std::byte*>(&regNumberSize);
    if (!in.read(static_cast<char*>(static_cast<void*>(regNumberSizeBytes)), sizeof(regNumberSize)) || regNumberSize > MAX_STR_SIZE) {
        return false;
    }
    regNumber.resize(regNumberSize);
    auto regNumberBytes = reinterpret_cast<std::byte*>(&regNumber[0]);
    if (!in.read(static_cast<char*>(static_cast<void*>(regNumberBytes)), static_cast<std::streamsize>(regNumberSize))) {
        return false;
    }
    auto yearBytes = reinterpret_cast<std::byte*>(&yearOfRelease);
    if (!in.read(static_cast<char*>(static_cast<void*>(yearBytes)), sizeof(yearOfRelease))) {
        return false;
    }
    size_t colorSize;
    auto colorSizeBytes = reinterpret_cast<std::byte*>(&colorSize);
    if (!in.read(static_cast<char*>(static_cast<void*>(colorSizeBytes)), sizeof(colorSize)) || colorSize > MAX_STR_SIZE) {
        return false;
    }
    bodyColor.resize(colorSize);
    auto colorBytes = reinterpret_cast<std::byte*>(&bodyColor[0]);
    if (!in.read(static_cast<char*>(static_cast<void*>(colorBytes)), static_cast<std::streamsize>(colorSize))) {
        return false;
    }
    return true;
}

bool Car::writeToStream(std::fstream& out) const {
    size_t regNumberSize = regNumber.size();
    auto regNumberSizeBytes = reinterpret_cast<const std::byte*>(&regNumberSize);
    if (!out.write(static_cast<const char*>(static_cast<const void*>(regNumberSizeBytes)), sizeof(regNumberSize))) return false;
    auto regNumberBytes = reinterpret_cast<const std::byte*>(regNumber.c_str());
    if (!out.write(static_cast<const char*>(static_cast<const void*>(regNumberBytes)), static_cast<std::streamsize>(regNumberSize))) return false;
    auto yearBytes = reinterpret_cast<const std::byte*>(&yearOfRelease);
    if (!out.write(static_cast<const char*>(static_cast<const void*>(yearBytes)), sizeof(yearOfRelease))) return false;
    size_t colorSize = bodyColor.size();
    auto colorSizeBytes = reinterpret_cast<const std::byte*>(&colorSize);
    if (!out.write(static_cast<const char*>(static_cast<const void*>(colorSizeBytes)), sizeof(colorSize))) return false;
    auto colorBytes = reinterpret_cast<const std::byte*>(bodyColor.c_str());
    if (!out.write(static_cast<const char*>(static_cast<const void*>(colorBytes)), static_cast<std::streamsize>(colorSize))) return false;
    out.flush();
    return true;
}

bool checkCorrectRegNum(const std::string& regNum) {
    if (regNum.length() != 9 || regNum[4] != ' ' || regNum[7] != '-' ||
        !(regNum[5] >= 'A' && regNum[5] <= 'Z') || !(regNum[6] >= 'A' && regNum[6] <= 'Z') ||
        !(regNum[8] >= '0' && regNum[8] <= '9')) {
        return false;
    }
    for (int i = 0; i < 4; ++i) {
        if (!(regNum[i] >= '0' && regNum[i] <= '9')) {
            return false;
        }
    }
    return true;
}
