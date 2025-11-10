#include "Car.h"
#include <cstddef>  

void Car::writeTo(std::ostream& os) const {
    const std::byte* p = reinterpret_cast<const std::byte*>(&number);
    os.write(reinterpret_cast<const char*>(p), sizeof(int));

    p = reinterpret_cast<const std::byte*>(&year);
    os.write(reinterpret_cast<const char*>(p), sizeof(int));

    size_t len = color.size();
    p = reinterpret_cast<const std::byte*>(&len);
    os.write(reinterpret_cast<const char*>(p), sizeof(size_t));

    if (len > 0) {
        os.write(reinterpret_cast<const char*>(color.data()), static_cast<std::streamsize>(len));
    }
}

void Car::readFrom(std::istream& is) {
    std::byte buf[sizeof(int)];
    if (!is.read(reinterpret_cast<char*>(buf), sizeof(int))) {
        is.setstate(std::ios::failbit);
        return;
    }
    number = *reinterpret_cast<int*>(buf);

    if (!is.read(reinterpret_cast<char*>(buf), sizeof(int))) {
        is.setstate(std::ios::failbit);
        return;
    }
    year = *reinterpret_cast<int*>(buf);

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