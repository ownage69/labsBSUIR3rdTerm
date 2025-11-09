#pragma once
#include <exception>
#include <string>

class EmptyInputException : public std::exception {
    std::string message;

public:
    explicit EmptyInputException(const std::string& input) {
        message = "Ошибка ввода: строка пустая";
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};