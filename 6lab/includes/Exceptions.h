#pragma once
#include <exception>
#include <string>

using namespace std;

class InvalidCharacterException : public exception {
    string message_;
public:
    InvalidCharacterException(const string& input, const string& invalidChars) {
        message_ = "Ошибка ввода: найдены недопустимые символы: '" + invalidChars + "' в строке: \"" + input + "\"";
    }
    const char* what() const noexcept override {
        return message_.c_str();
    }
};