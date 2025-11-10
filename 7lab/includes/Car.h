#pragma once

#include <string>
#include <ostream>
#include <istream>

struct Car {
    int number = 0;          
    int year = 0;          
    std::string color;

    void writeTo(std::ostream& os) const;
    void readFrom(std::istream& is);

    friend std::ostream& operator<<(std::ostream& os, const Car& car) {
        os << "Number: " << car.number
            << ", Year: " << car.year
            << ", Color: " << car.color;
        return os;
    }
};