#include "menu.h"

void Menu::printSeparator() const
{
    std::cout << "============================================================" << std::endl;
}

void Menu::printHeader(const std::string &title) const
{
    std::cout << std::endl;
    printSeparator();
    std::cout << "  " << title << std::endl;
    printSeparator();
}

void Menu::displayTypeSelectionMenu() const
{
    printHeader("STACK DATA TYPE SELECTION");
    std::cout << "  1. Integer (int)" << std::endl;
    std::cout << "  2. Double precision (double)" << std::endl;
    std::cout << "  3. Floating point (float)" << std::endl;
    std::cout << "  4. Character (char)" << std::endl;
    std::cout << "  5. String (string)" << std::endl;
    std::cout << "  0. Exit program" << std::endl;
    printSeparator();
}

void Menu::displayOperationsMenu() const
{
    printHeader("STACK OPERATIONS");
    std::cout << "  1. Add element (Push)" << std::endl;
    std::cout << "  2. Remove element (Pop)" << std::endl;
    std::cout << "  3. View top element (Peek)" << std::endl;
    std::cout << "  4. Print all stack elements" << std::endl;
    std::cout << "  5. Clear stack" << std::endl;
    std::cout << "  6. Find element" << std::endl;
    std::cout << "  7. Sort stack" << std::endl;
    std::cout << "  8. Reverse stack" << std::endl;
    std::cout << "  0. Back to type selection" << std::endl;
    printSeparator();
}

int Menu::getMenuChoice(const std::string &prompt) const
{
    return safeInputInt(prompt);
}

void Menu::clearInputBuffer() const
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Menu::run()
{
    int userChoice;

    do
    {
        displayTypeSelectionMenu();
        userChoice = getMenuChoice("Choose data type: ");

        switch (userChoice)
        {
        case 1:
            runOperationsMenu<int>();
            break;
        case 2:
            runOperationsMenu<double>();
            break;
        case 3:
            runOperationsMenu<float>();
            break;
        case 4:
            runOperationsMenu<char>();
            break;
        case 5:
            runOperationsMenu<std::string>();
            break;
        case 0:
            printHeader("EXIT PROGRAM");
            std::cout << "  Thank you for using the program!" << std::endl;
            printSeparator();
            break;
        default:
            std::cout << "Invalid choice! Please try again." << std::endl;
            break;
        }

        if (userChoice != 0)
        {
            std::cout << std::endl;
        }
    } while (userChoice != 0);
}



