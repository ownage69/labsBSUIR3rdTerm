#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <format>

class Car {
    std::string regNumber;
    int yearOfRelease;
    std::string bodyColor;

    bool readFromStream(std::fstream& in);
    bool writeToStream(std::fstream& out) const;

public:
    Car();
    Car(const std::string& regNumber, int yearOfRelease, const std::string& bodyColor);
    Car(const Car& car) = default;

    std::string getRegNumber() const;
    int getYearOfRelease() const;
    std::string getBodyColor() const;

    void input();

    friend std::ostream& operator<<(std::ostream& out, const Car& car) {
        out << std::format("| Reg number: {} | Production year: {} | Color: {:>12} |\n",
            car.regNumber,
            car.yearOfRelease,
            car.bodyColor);
        return out;
    }

    friend std::fstream& operator>>(std::fstream& in, Car& car) {
        if (!car.readFromStream(in)) {
            in.setstate(std::ios::failbit);
        }
        return in;
    }
    friend std::fstream& operator<<(std::fstream& out, const Car& car) {
        if (!car.writeToStream(out)) {
            out.setstate(std::ios::failbit);
        }
        return out;
    }
};

bool checkCorrectRegNum(const std::string& regNum);
