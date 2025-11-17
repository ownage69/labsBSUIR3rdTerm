#pragma once

#include <string>
#include <ostream>
#include <fstream>
#include <format>
#include <cstddef>

class Car {
    std::string regNumber;
    int yearOfRelease = 0;
    std::string bodyColor;
    static constexpr std::size_t MAX_STR_SIZE = 1024;

public:
    Car() = default;
    Car(const std::string& rn, int yr, const std::string& color)
        : regNumber(rn), yearOfRelease(yr), bodyColor(color) {
    }
    Car(const Car&) = default;

    std::string getRegNumber() const { return regNumber; }
    int getYearOfRelease() const { return yearOfRelease; }
    std::string getBodyColor() const { return bodyColor; }

    void input(); 

    friend std::ostream& operator<<(std::ostream& out, const Car& car) {
        out << std::format("| Reg number: {} | Production year: {} | Color: {:>12} |\n",
            car.regNumber, car.yearOfRelease, car.bodyColor);
        return out;
    }

    friend std::fstream& operator<<(std::fstream& out, const Car& car) {
        const std::size_t regSize = car.regNumber.size();
        const std::size_t colorSize = car.bodyColor.size();

        const std::byte* bRegSize = reinterpret_cast<const std::byte*>(&regSize);
        out.write(reinterpret_cast<const char*>(bRegSize), sizeof(regSize));

        if (regSize > 0) {
            const std::byte* bReg = reinterpret_cast<const std::byte*>(car.regNumber.data());
            out.write(reinterpret_cast<const char*>(bReg), static_cast<std::streamsize>(regSize));
        }

        const std::byte* bYear = reinterpret_cast<const std::byte*>(&car.yearOfRelease);
        out.write(reinterpret_cast<const char*>(bYear), sizeof(car.yearOfRelease));

        const std::byte* bColorSize = reinterpret_cast<const std::byte*>(&colorSize);
        out.write(reinterpret_cast<const char*>(bColorSize), sizeof(colorSize));

        if (colorSize > 0) {
            const std::byte* bColor = reinterpret_cast<const std::byte*>(car.bodyColor.data());
            out.write(reinterpret_cast<const char*>(bColor), static_cast<std::streamsize>(colorSize));
        }

        out.flush();
        return out;
    }

    friend std::fstream& operator>>(std::fstream& in, Car& car) {
        std::size_t regSize = 0;
        if (!in.read(reinterpret_cast<char*>(reinterpret_cast<std::byte*>(&regSize)),
            sizeof(regSize)) || regSize > MAX_STR_SIZE)
        {
            in.setstate(std::ios::failbit);
            return in;
        }

        car.regNumber.resize(regSize);
        if (regSize > 0) {
            if (!in.read(reinterpret_cast<char*>(reinterpret_cast<std::byte*>(&car.regNumber[0])),
                static_cast<std::streamsize>(regSize)))
            {
                in.setstate(std::ios::failbit);
                return in;
            }
        }

        if (!in.read(reinterpret_cast<char*>(reinterpret_cast<std::byte*>(&car.yearOfRelease)),
            sizeof(car.yearOfRelease)))
        {
            in.setstate(std::ios::failbit);
            return in;
        }

        std::size_t colorSize = 0;
        if (!in.read(reinterpret_cast<char*>(reinterpret_cast<std::byte*>(&colorSize)),
            sizeof(colorSize)) || colorSize > MAX_STR_SIZE)
        {
            in.setstate(std::ios::failbit);
            return in;
        }

        car.bodyColor.resize(colorSize);
        if (colorSize > 0) {
            if (!in.read(reinterpret_cast<char*>(reinterpret_cast<std::byte*>(&car.bodyColor[0])),
                static_cast<std::streamsize>(colorSize)))
            {
                in.setstate(std::ios::failbit);
                return in;
            }
        }

        return in;
    }
};
