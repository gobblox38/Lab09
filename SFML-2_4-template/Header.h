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
    bool is_max;
    char letter;
public:
    const int BAR_WIDTH = 24;

    Bar() {};

    void setName(char c) { letter = c; }
    char getName() { return letter; }
    bool isMax() { return is_max; }
    void setIsMax(bool b) { is_max = b; }
    int getBarValue() { return bar_value; }
    void setBarValue(int h);
    
};

int getMaxOf(Bar bars[]);
int main();