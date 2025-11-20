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
    std::byte* regNumberSizeBytes = reinterpret_cast<std::byte*>(&regNumberSize);
    if (!in.read(reinterpret_cast<char*>(regNumberSizeBytes), sizeof(regNumberSize)) || regNumberSize > MAX_STR_SIZE) {
        return false;
    }
    regNumber.resize(regNumberSize);
    std::byte* regNumberBytes = reinterpret_cast<std::byte*>(&regNumber[0]);
    if (!in.read(reinterpret_cast<char*>(regNumberBytes), static_cast<std::streamsize>(regNumberSize))) {
        return false;
    }
    std::byte* yearBytes = reinterpret_cast<std::byte*>(&yearOfRelease);
    if (!in.read(reinterpret_cast<char*>(yearBytes), sizeof(yearOfRelease))) {
        return false;
    }
    size_t colorSize;
    std::byte* colorSizeBytes = reinterpret_cast<std::byte*>(&colorSize);
    if (!in.read(reinterpret_cast<char*>(colorSizeBytes), sizeof(colorSize)) || colorSize > MAX_STR_SIZE) {
        return false;
    }
    bodyColor.resize(colorSize);
    std::byte* colorBytes = reinterpret_cast<std::byte*>(&bodyColor[0]);
    if (!in.read(reinterpret_cast<char*>(colorBytes), static_cast<std::streamsize>(colorSize))) {
        return false;
    }
    return true;
}

bool Car::writeToStream(std::fstream& out) const {
    size_t regNumberSize = regNumber.size();
    const std::byte* regNumberSizeBytes = reinterpret_cast<const std::byte*>(&regNumberSize);
    if (!out.write(reinterpret_cast<const char*>(regNumberSizeBytes), sizeof(regNumberSize))) return false;
    const std::byte* regNumberBytes = reinterpret_cast<const std::byte*>(regNumber.c_str());
    if (!out.write(reinterpret_cast<const char*>(regNumberBytes), static_cast<std::streamsize>(regNumberSize))) return false;
    const std::byte* yearBytes = reinterpret_cast<const std::byte*>(&yearOfRelease);
    if (!out.write(reinterpret_cast<const char*>(yearBytes), sizeof(yearOfRelease))) return false;
    size_t colorSize = bodyColor.size();
    const std::byte* colorSizeBytes = reinterpret_cast<const std::byte*>(&colorSize);
    if (!out.write(reinterpret_cast<const char*>(colorSizeBytes), sizeof(colorSize))) return false;
    const std::byte* colorBytes = reinterpret_cast<const std::byte*>(bodyColor.c_str());
    if (!out.write(reinterpret_cast<const char*>(colorBytes), static_cast<std::streamsize>(colorSize))) return false;
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
