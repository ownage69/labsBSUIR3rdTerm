#pragma once

#include <stdexcept>
#include <string>

class StackException : public std::runtime_error
{
public:
    StackException() : std::runtime_error("Stack is empty") {}
    using std::runtime_error::runtime_error;
};