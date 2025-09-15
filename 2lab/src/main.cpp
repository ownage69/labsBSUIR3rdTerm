#include "App.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");

    App app;
    app.run();
    return 0;
}
