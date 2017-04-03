#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <stdlib.h>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

const int NUM_LETTERS = 26;

class Bar : public RectangleShape {
private:
    int bar_value;
public:

    Bar();

    int getBarValue();
    void setBarValue(int h);
    const int BAR_WIDTH = 25;
};