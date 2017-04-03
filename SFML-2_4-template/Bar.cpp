
#include "Header.h"


Bar::Bar() {
    bar_value = 0;
}

int Bar::getBarValue() {
    return bar_value;
}

void Bar::setBarValue(int h) {
    bar_value = h;
    int scaled_value = bar_value / 24;
    setSize(Vector2f(BAR_WIDTH, scaled_value));
    setPosition(Vector2f(getPosition().x, 640 - scaled_value));
}