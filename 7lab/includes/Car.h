#pragma once

#include <fstream>
#include <iostream>
#include <string>

class Car {
    std::string regNumber;
    int yearOfRelease;
    std::string bodyColor;
public:
    Car();
    Car(const std::string& regNumber, int yearOfRelease, const std::string& bodyColor);
    Car(const Car& car) = default;
    std::string getRegNumber() const;
    int getYearOfRelease() const;
    std::string getBodyColor() const;
    void input();
    friend std::fstream& operator>>(std::fstream& in, Car& car);
    friend std::fstream& operator<<(std::fstream& out, const Car& car);
    friend std::ostream& operator<<(std::ostream& out, const Car& car);
};

bool checkCorrectRegNum(const std::string& regNum);