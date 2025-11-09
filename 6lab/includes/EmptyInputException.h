#pragma once

#include <exception>
#include <string>
#include <string_view>

class EmptyInputException : public std::exception {
    std::string message;

public:
    explicit EmptyInputException(std::string_view) : message("Ошибка ввода: строка пустая") {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};