#include "App.h"
#include <clocale>

int main() {
    setlocale(LC_ALL, "");
    App app;
    app.run();
    return 0;
}
