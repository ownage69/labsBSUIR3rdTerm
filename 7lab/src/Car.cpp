#include "Car.h"
#include <cstddef>     
#include <cstring>     
#include <array>

void Car::writeTo(std::ostream& os) const {
    std::array<std::byte, sizeof(int)> buffer;
    std::memcpy(buffer.data(), &number, sizeof(int));
    os.write(reinterpret_cast<const char*>(buffer.data()), sizeof(int));

    std::memcpy(buffer.data(), &year, sizeof(int));
    os.write(reinterpret_cast<const char*>(buffer.data()), sizeof(int));

    const auto len = color.size();
    std::array<std::byte, sizeof(size_t)> len_buf;
    std::memcpy(len_buf.data(), &len, sizeof(size_t));
    os.write(reinterpret_cast<const char*>(len_buf.data()), sizeof(size_t));

    if (len > 0) {
        os.write(color.data(), static_cast<std::streamsize>(len));
    }
}

void Car::readFrom(std::istream& is) {
    std::array<std::byte, sizeof(int)> buffer;

    if (!is.read(reinterpret_cast<char*>(buffer.data()), sizeof(int))) {
        is.setstate(std::ios::failbit);
        return;
    }
    std::memcpy(&number, buffer.data(), sizeof(int));

    if (!is.read(reinterpret_cast<char*>(buffer.data()), sizeof(int))) {
        is.setstate(std::ios::failbit);
        return;
    }
    std::memcpy(&year, buffer.data(), sizeof(int));

    std::array<std::byte, sizeof(size_t)> len_buf;
    if (!is.read(reinterpret_cast<char*>(len_buf.data()), sizeof(size_t))) {
        is.setstate(std::ios::failbit);
        return;
    }
    size_t len = 0;
    std::memcpy(&len, len_buf.data(), sizeof(size_t));

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