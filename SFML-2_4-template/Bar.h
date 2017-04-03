#pragma once
class Bar {
private:
    int bar_height;
public:

    Bar();

    int getBarHeight();
    void setBarHeight(int h);
    const int BAR_WIDTH = 25;
};