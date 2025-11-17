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

std::fstream& operator>>(std::fstream& in, Car& car) {
    size_t regNumberSize;
    if (!in.read(reinterpret_cast<char*>(&regNumberSize), sizeof(regNumberSize)) || regNumberSize > MAX_STR_SIZE) {
        in.setstate(std::ios::failbit);
        return in;
    }
    car.regNumber.resize(regNumberSize);
    if (!in.read(&car.regNumber[0], static_cast<std::streamsize>(regNumberSize))) {
        in.setstate(std::ios::failbit);
        return in;
    }
    if (!in.read(reinterpret_cast<char*>(&car.yearOfRelease), sizeof(car.yearOfRelease))) {
        in.setstate(std::ios::failbit);
        return in;
    }
    size_t colorSize;
    if (!in.read(reinterpret_cast<char*>(&colorSize), sizeof(colorSize)) || colorSize > MAX_STR_SIZE) {
        in.setstate(std::ios::failbit);
        return in;
    }
    car.bodyColor.resize(colorSize);
    if (!in.read(&car.bodyColor[0], static_cast<std::streamsize>(colorSize))) {
        in.setstate(std::ios::failbit);
        return in;
    }
    return in;
}

std::fstream& operator<<(std::fstream& out, const Car& car) {
    size_t regNumberSize = car.regNumber.size();
    out.write(reinterpret_cast<const char*>(&regNumberSize), sizeof(regNumberSize));
    out.write(car.regNumber.c_str(), static_cast<std::streamsize>(regNumberSize));
    out.write(reinterpret_cast<const char*>(&car.yearOfRelease), sizeof(car.yearOfRelease));
    size_t colorSize = car.bodyColor.size();
    out.write(reinterpret_cast<const char*>(&colorSize), sizeof(colorSize));
    out.write(car.bodyColor.c_str(), static_cast<std::streamsize>(colorSize));
    out.flush();
    return out;
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
