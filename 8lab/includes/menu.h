#pragma once

#include "readUserInput.h"
#include "safeInput.h"
#include "stack.h"
#include "stackAlgorithms.h"
#include <iostream>
#include <limits>
#include <string>
#include <iomanip>

class Menu
{
  private:
    void displayTypeSelectionMenu() const;
    void displayOperationsMenu() const;
    int getMenuChoice(const std::string &prompt) const;
    void clearInputBuffer() const;
    void printSeparator() const;
    void printHeader(const std::string &title) const;

    template <typename T>
    void runOperationsMenu();
    template <typename T>
    void handlePushOperation(Stack<T> &stack) const;
    template <typename T>
    void handlePopOperation(Stack<T> &stack) const;
    template <typename T>
    void handlePeekOperation(Stack<T> &stack) const;
    template <typename T>
    void handleFindOperation(Stack<T> &stack) const;
    template <typename T>
    void handleSortOperation(Stack<T> &stack) const;
    template <typename T>
    void handleReverseOperation(Stack<T> &stack) const;

  public:
    void run();
};

template <typename T>
void Menu::runOperationsMenu()
{
    Stack<T> stack;
    int operationChoice;

    do
    {
        displayOperationsMenu();
        operationChoice = getMenuChoice("Choose operation: ");

        switch (operationChoice)
        {
        case 1:
            handlePushOperation(stack);
            break;
        case 2:
            handlePopOperation(stack);
            break;
        case 3:
            handlePeekOperation(stack);
            break;
        case 4:
            if (stack.is_empty())
            {
                std::cout << "Stack is empty!" << std::endl;
            }
            else
            {
                stack.print();
            }
            break;
        case 5:
            if (stack.is_empty())
            {
                std::cout << "Stack is already empty!" << std::endl;
            }
            else
            {
                stack.clear_stack();
                std::cout << "Stack cleared." << std::endl;
            }
            break;
        case 6:
            handleFindOperation(stack);
            break;
        case 7:
            handleSortOperation(stack);
            break;
        case 8:
            handleReverseOperation(stack);
            break;
        case 0:
            std::cout << "Returning to type selection." << std::endl;
            break;
        default:
            std::cout << "Invalid choice! Please try again." << std::endl;
            break;
        }

        if (operationChoice != 0)
        {
            std::cout << std::endl;
        }
    } while (operationChoice != 0);
}

template <typename T>
void Menu::handlePushOperation(Stack<T> &stack) const
{
    T value = readUserInput<T>("Enter element to add: ");
    stack.push(value);
    std::cout << "Element successfully added to stack." << std::endl;
}

template <typename T>
void Menu::handlePopOperation(Stack<T> &stack) const
{
    if (stack.is_empty())
    {
        std::cout << "Error: stack is empty!" << std::endl;
    }
    else
    {
        T topValue = stack.peek();
        stack.pop();
        std::cout << "Element " << topValue << " removed from stack." << std::endl;
    }
}

template <typename T>
void Menu::handlePeekOperation(Stack<T> &stack) const
{
    if (stack.is_empty())
    {
        std::cout << "Error: stack is empty!" << std::endl;
    }
    else
    {
        std::cout << "Top element of stack: " << stack.peek() << std::endl;
    }
}

template <typename T>
void Menu::handleFindOperation(Stack<T> &stack) const
{
    if (stack.is_empty())
    {
        std::cout << "Error: stack is empty!" << std::endl;
    }
    else
    {
        T searchValue = readUserInput<T>("Enter element to search: ");
        bool found = StackAlgorithms<T>::findElement(stack, searchValue);
        std::cout << "Element " << searchValue << " " << (found ? "found" : "not found") << " in stack." << std::endl;
    }
}

template <typename T>
void Menu::handleSortOperation(Stack<T> &stack) const
{
    if (stack.is_empty())
    {
        std::cout << "Error: stack is empty!" << std::endl;
    }
    else if (stack.get_size() == 1)
    {
        std::cout << "Stack has only one element - sorting not required." << std::endl;
    }
    else
    {
        StackAlgorithms<T>::sortStack(stack);
        std::cout << "Stack sorted." << std::endl;
        stack.print();
    }
}

template <typename T>
void Menu::handleReverseOperation(Stack<T> &stack) const
{
    if (stack.is_empty())
    {
        std::cout << "Error: stack is empty!" << std::endl;
    }
    else
    {
        StackAlgorithms<T>::reverseStack(stack);
        std::cout << "Stack reversed." << std::endl;
        stack.print();
    }
}

