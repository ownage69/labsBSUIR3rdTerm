#pragma once
#include <exception>
#include <string>

class InvalidCharacterException : public std::exception {
    std::string message_;
public:
    InvalidCharacterException(const std::string& input, const std::string& invalidChars) {
        message_ = "Ошибка ввода: найдены недопустимые символы: '" + invalidChars + "' в строке: \"" + input + "\"";
    }
    const char* what() const noexcept override {
        return message_.c_str();
    }
};