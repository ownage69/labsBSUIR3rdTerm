#include "car.h"
#include "safeinput.h"
#include <iomanip>
#include <limits>
#include <cstring>

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
        yearOfRelease = safeInputInt("Enter the vehicle's production year (between 1888 and 2025):\n");
        if (yearOfRelease >= 1888 && yearOfRelease <= 2025) {
            break;
        }
        std::cout << "Year must be between 1888 and 2025. Please try again.\n";
    }
    bodyColor = safeInputString("Enter the body color (e.g., silver, blue, green):\n");
    std::cout << "New vehicle added successfully.\n";
}

bool Car::readFromStream(std::fstream& in) {
    size_t regNumberSize;
    if (!in.read(reinterpret_cast<char*>(&regNumberSize), sizeof(regNumberSize)) || regNumberSize > MAX_STR_SIZE) {
        return false;
    }
    regNumber.resize(regNumberSize);
    if (!in.read(&regNumber[0], static_cast<std::streamsize>(regNumberSize))) {
        return false;
    }
    if (!in.read(reinterpret_cast<char*>(&yearOfRelease), sizeof(yearOfRelease))) {
        return false;
    }
    size_t colorSize;
    if (!in.read(reinterpret_cast<char*>(&colorSize), sizeof(colorSize)) || colorSize > MAX_STR_SIZE) {
        return false;
    }
    bodyColor.resize(colorSize);
    if (!in.read(&bodyColor[0], static_cast<std::streamsize>(colorSize))) {
        return false;
    }
    return true;
}

bool Car::writeToStream(std::fstream& out) const {
    size_t regNumberSize = regNumber.size();
    if (!out.write(reinterpret_cast<const char*>(&regNumberSize), sizeof(regNumberSize))) return false;
    if (!out.write(regNumber.c_str(), static_cast<std::streamsize>(regNumberSize))) return false;
    if (!out.write(reinterpret_cast<const char*>(&yearOfRelease), sizeof(yearOfRelease))) return false;
    size_t colorSize = bodyColor.size();
    if (!out.write(reinterpret_cast<const char*>(&colorSize), sizeof(colorSize))) return false;
    if (!out.write(bodyColor.c_str(), static_cast<std::streamsize>(colorSize))) return false;
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
