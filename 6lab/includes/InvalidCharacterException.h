#pragma once
#include <exception>
#include <string>

class InvalidCharacterException : public std::exception {
    std::string message;

public:
    InvalidCharacterException(const std::string& input, const std::string& invalidChars) {
        message = "Ошибка ввода: недопустимые символы '" + invalidChars + "' в строке: \"" + input + "\"";
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};