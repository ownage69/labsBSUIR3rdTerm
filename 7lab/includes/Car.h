#pragma once
#include <string>
#include <ostream>
#include <istream>

struct Car {
    int number;
    int year;
    std::string color;

    void writeTo(std::ostream& os) const;

    void readFrom(std::istream& is);
};

std::ostream& operator<<(std::ostream& os, const Car& car);