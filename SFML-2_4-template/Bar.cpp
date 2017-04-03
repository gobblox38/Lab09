
#include "Header.h"


Bar::Bar() {
    bar_value = 0;
}

int Bar::getBarValue() {
    return bar_value;
}

void Bar::setBarValue(int h) {
    bar_value = h;
    setSize(Vector2f(BAR_WIDTH, bar_value));
}