#include "Car.h"
#include <cstddef>

void Car::writeTo(std::ostream& os) const {
    os.write(reinterpret_cast<const char*>(&number), sizeof(int));
    os.write(reinterpret_cast<const char*>(&year), sizeof(int));
    size_t len = color.size();
    os.write(reinterpret_cast<const char*>(&len), sizeof(size_t));
    if (len > 0) {
        os.write(color.data(), static_cast<std::streamsize>(len));
    }
}

void Car::readFrom(std::istream& is) {
    if (!is.read(reinterpret_cast<char*>(&number), sizeof(int))) {
        is.setstate(std::ios::failbit);
        return;
    }
    if (!is.read(reinterpret_cast<char*>(&year), sizeof(int))) {
        is.setstate(std::ios::failbit);
        return;
    }
    size_t len = 0;
    if (!is.read(reinterpret_cast<char*>(&len), sizeof(size_t))) {
        is.setstate(std::ios::failbit);
        return;
    }
    if (len > 1024) {
        is.setstate(std::ios::failbit);
        return;
    }
    color.resize(len);
    if (len > 0 && !is.read(&color[0], static_cast<std::streamsize>(len))) {
        is.setstate(std::ios::failbit);
        return;
    }
}