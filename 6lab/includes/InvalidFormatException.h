#pragma once
#include <exception>
#include <string>

class InvalidFormatException : public std::exception {
    std::string message;

public:
    explicit InvalidFormatException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};