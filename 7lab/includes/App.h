#pragma once

#include <string>
#include <memory>
#include "CarFile.h"

class App final {
public:
    App() = default;
    void run();

private:
    std::unique_ptr<CarFile> carFile_;
    std::string filename_ = "cars.bin";

    void showMenu() const;
    void handleChoice(int choice);
    void addCar();
    void showAllCars() const;
    void countCarsByYear() const;
};