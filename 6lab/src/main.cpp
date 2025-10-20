#include "C.h"
#include "menu.h"
#include <clocale>

int main() {
    setlocale(LC_ALL, "");
    C equation;
    runMenu(equation);
    return 0;
}