#include "Car.h"
#include <cstddef>  

void Car::writeTo(std::ostream& os) const {
    os.write(reinterpret_cast<const char*>(&number), sizeof(int));
    os.write(reinterpret_cast<const char*>(&year), sizeof(int));
    size_t len = color.size();
    os.write(reinterpret_cast<const char*>(&len), sizeof(size_t));
    os.write(color.data(), len);
}

void Car::readFrom(std::istream& is) {
    if (!is.read(reinterpret_cast<char*>(&number), sizeof(int)) ||
        !is.read(reinterpret_cast<char*>(&year), sizeof(int))) {
        is.setstate(std::ios::failbit);
        return;
    }
    size_t len;
    if (!is.read(reinterpret_cast<char*>(&len), sizeof(size_t))) {
        is.setstate(std::ios::failbit);
        return;
    }
    if (len > 1024) {  
        is.setstate(std::ios::failbit);
        return;
    }
    color.resize(len);
    if (len > 0 && !is.read(&color[0], len)) {
        is.setstate(std::ios::failbit);
        return;
    }
}

std::ostream& operator<<(std::ostream& os, const Car& car) {
    os << "Number: " << car.number << ", Year: " << car.year << ", Color: " << car.color;
    return os;
}