#pragma once

#include "stackException.h"
#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <compare>

template <typename T>
class Stack
{
  private:
    struct StackNode
    {
        T value;
        StackNode *nextNode = nullptr;
        explicit StackNode(const T &val) : value(val) {}
    };

    StackNode *topElement = nullptr; 
    size_t elementCount = 0;   
  public:
    Stack() = default;
    ~Stack();
    Stack(const Stack &other);
    Stack &operator=(const Stack &other);

    void push(const T &value);
    void pop();
    T peek() const;
    bool is_empty() const;
    size_t get_size() const;
    void print() const;
    void clear_stack();

    friend bool operator==(const Stack &left, const Stack &right)
    {
        if (left.elementCount != right.elementCount)
        {
            return false;
        }

        StackNode *node1 = left.topElement;
        StackNode *node2 = right.topElement;

        while (node1 && node2)
        {
            if (node1->value != node2->value)
            {
                return false;
            }
            node1 = node1->nextNode;
            node2 = node2->nextNode;
        }

        return true;
    }

    friend auto operator<=>(const Stack &left, const Stack &right)
    {
        StackNode *node1 = left.topElement;
        StackNode *node2 = right.topElement;

        while (node1 && node2)
        {
            if (auto cmp = node1->value <=> node2->value; cmp != 0)
            {
                return cmp;
            }
            node1 = node1->nextNode;
            node2 = node2->nextNode;
        }

        return left.elementCount <=> right.elementCount;
    }

    void swap(Stack &other) noexcept;

    class StackIterator
    {
      private:
        StackNode *currentNode;

      public:
        explicit StackIterator(StackNode *node); 

        T &operator*() const;
        StackIterator &operator++();

        friend bool operator==(const StackIterator &left, const StackIterator &right) = default;
    };

    StackIterator begin() const;
    StackIterator end() const;
};

template <typename T>
Stack<T>::~Stack()
{
    while (topElement)
    {
        StackNode *temp = topElement;
        topElement = topElement->nextNode;
        delete temp;
    }
}

template <typename T>
Stack<T>::Stack(const Stack &other)
{
    Stack<T> temporaryStack;
    StackNode *currentNode = other.topElement;
    while (currentNode)
    {
        temporaryStack.push(currentNode->value);
        currentNode = currentNode->nextNode;
    }
    while (!temporaryStack.is_empty())
    {
        push(temporaryStack.peek());
        temporaryStack.pop();
    }
}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack &other)
{
    if (this != &other)
    {
        clear_stack();
        Stack<T> temporaryStack;
        StackNode *currentNode = other.topElement;
        while (currentNode)
        {
            temporaryStack.push(currentNode->value);
            currentNode = currentNode->nextNode;
        }
        while (!temporaryStack.is_empty())
        {
            push(temporaryStack.peek());
            temporaryStack.pop();
        }
    }
    return *this;
}

template <typename T>
void Stack<T>::push(const T &value)
{
    auto *newNode = new StackNode(value);
    newNode->nextNode = topElement;
    topElement = newNode;
    elementCount++;
}

template <typename T>
void Stack<T>::pop()
{
    if (is_empty())
    {
        throw StackException(); 
    }
    StackNode *temp = topElement;
    topElement = topElement->nextNode;
    delete temp;
    elementCount--;
}

template <typename T>
T Stack<T>::peek() const
{
    if (is_empty())
    {
        throw StackException(); 
    }
    return topElement->value;
}

template <typename T>
bool Stack<T>::is_empty() const
{
    return topElement == nullptr;
}

template <typename T>
size_t Stack<T>::get_size() const
{
    return elementCount;
}

template <typename T>
void Stack<T>::print() const
{
    if (is_empty())
    {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    std::cout << "Stack elements (top to bottom): ";
    StackNode *currentNode = topElement;
    while (currentNode)
    {
        std::cout << currentNode->value << " ";
        currentNode = currentNode->nextNode;
    }
    std::cout << std::endl;
}

template <typename T>
void Stack<T>::clear_stack()
{
    while (!is_empty())
    {
        pop();
    }
}

template <typename T>
void Stack<T>::swap(Stack &other) noexcept
{
    StackNode *tempTop = topElement;
    size_t tempSize = elementCount;

    topElement = other.topElement;
    elementCount = other.elementCount;

    other.topElement = tempTop;
    other.elementCount = tempSize;
}

template <typename T>
Stack<T>::StackIterator::StackIterator(StackNode *node) : currentNode(node)
{
}

template <typename T>
T &Stack<T>::StackIterator::operator*() const
{
    return currentNode->value;
}

template <typename T>
typename Stack<T>::StackIterator &Stack<T>::StackIterator::operator++()
{
    if (currentNode)
    {
        currentNode = currentNode->nextNode;
    }
    return *this;
}

template <typename T>
typename Stack<T>::StackIterator Stack<T>::begin() const
{
    return StackIterator(topElement);
}

template <typename T>
typename Stack<T>::StackIterator Stack<T>::end() const
{
    return StackIterator(nullptr);
}