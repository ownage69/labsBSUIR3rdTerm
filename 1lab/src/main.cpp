#include "App.h"
#include <locale>

int main() {
    setlocale(LC_ALL, "");
    App app;
    app.run();
    return 0;
}
