#pragma once

#include <stdexcept>
#include <string>

class StackException : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;
    StackException() : std::runtime_error("Stack is empty") {}
};