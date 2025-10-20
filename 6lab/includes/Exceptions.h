#pragma once
#include <exception>
#include <string>

class InvalidCharacterException : public std::exception {
    std::string message_;
public:
    InvalidCharacterException(const std::string& input, const std::string& invalidChars) {
        message_ = "������ �����: ������� ������������ �������: '" + invalidChars + "' � ������: \"" + input + "\"";
    }
    const char* what() const noexcept override {
        return message_.c_str();
    }
};