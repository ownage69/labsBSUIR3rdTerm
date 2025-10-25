#pragma once
#include <exception>
#include <string>

class InvalidCharacterException : public std::exception {
    std::string errormessage;
public:
    InvalidCharacterException(const std::string& input, const std::string& invalidChars) {
        errormessage = "Ошибка ввода: найдены недопустимые символы: '" + invalidChars + "' в строке: \"" + input + "\"";
    }

    const char* what() const noexcept override {
        return errormessage.c_str();
    }
};