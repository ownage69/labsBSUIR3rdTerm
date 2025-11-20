#pragma once

#include "stack.h"
#include <algorithm>

template <typename T>
class StackAlgorithms
{
  public:
    static bool findElement(const Stack<T> &stack, const T &value);
    static void sortStack(Stack<T> &stack);
    static void reverseStack(Stack<T> &stack);
};

template <typename T>
bool StackAlgorithms<T>::findElement(const Stack<T> &stack, const T &value)
{
    return std::find(stack.begin(), stack.end(), value) != stack.end();
}

template <typename T>
void StackAlgorithms<T>::sortStack(Stack<T> &stack)
{
    if (stack.is_empty() || stack.get_size() == 1)
    {
        return;
    }

    bool hasSwapped;
    size_t remainingElements = stack.get_size();

    do
    {
        hasSwapped = false;
        Stack<T> auxiliaryStack;
        T currentValue = stack.peek();
        stack.pop();

        for (size_t i = 1; i < remainingElements; i++)
        {
            T nextValue = stack.peek();
            stack.pop();

            if (currentValue > nextValue)
            {
                auxiliaryStack.push(nextValue);
                hasSwapped = true;
            }
            else
            {
                auxiliaryStack.push(currentValue);
                currentValue = nextValue;
            }
        }
        auxiliaryStack.push(currentValue);

        while (!auxiliaryStack.is_empty())
        {
            stack.push(auxiliaryStack.peek());
            auxiliaryStack.pop();
        }
        remainingElements--;
    } while (hasSwapped);
}

template <typename T>
void StackAlgorithms<T>::reverseStack(Stack<T> &stack)
{
    if (stack.is_empty() || stack.get_size() == 1)
    {
        return;
    }

    Stack<T> temporaryStack;

    while (!stack.is_empty())
    {
        temporaryStack.push(stack.peek());
        stack.pop();
    }

    stack = temporaryStack;
}
