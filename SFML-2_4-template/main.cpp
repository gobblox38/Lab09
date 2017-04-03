/*CSCI 261: Assignment 09: Graph Alice
*
*Author: Dustin Huntsman
*
*02 Apr 2017
*
*/

#include "Header.h"

int getMaxOf(Bar bars[]) {
    double maxOccur = 0;
    double maxOccurAt = 0;

    for (int i = 0; i < NUM_LETTERS; ++i) {
        if (maxOccur < bars[i].getBarValue()) {
            maxOccur = bars[i].getBarValue();
            maxOccurAt = i;
        }
    }
    return maxOccurAt;
}

int main() {

    /***** PLACE YOUR FILE PROCESSING CODE HERE *****/
    //begin A08 copy
    ifstream numOccur;

    Bar bars[NUM_LETTERS];

    numOccur.open("numOccur.txt");
    if (!numOccur.is_open()) {
        cout << "Could not open file myfile.txt." << endl;
        return 1;
    }
    //end A08 copy

    for (int i = 0; i < NUM_LETTERS; i++)
    {
        
        string line, temp;
        getline(numOccur, line);
        temp = line.substr(1, line.length());

        std::string::size_type sz;   // alias of size_t
        bars[i].setPosition(Vector2f((i * 26), 0));

        bars[i].setBarValue(stoi(temp, &sz));
        bars[i].setName(line.at(0));
    }
     //end array set

    Font font;
    if (!font.loadFromFile("arial.ttf")) {
        //error
    }


    /***** END OF FILE PROCESSING *****/

    // creates the window object with an 640x640 resolution window
    RenderWindow window(VideoMode(672, 640), "SFML Template");

    int maxBar = getMaxOf(bars);
    bars[maxBar].setFillColor(Color::Blue);

    // Draw loop: Each iteration of this loop draws a single frame
    while (window.isOpen()) {

        // Erase the screen with black (because space)
        window.clear();

        /***** PLACE YOUR DRAWING CODE HERE *****/

        for (int i = 0; i < NUM_LETTERS; i++) {
            Bar bar = bars[i];
            int value = bar.getBarValue();

            // change color here
            window.draw((RectangleShape)bar);
            // draw out the value with bars[i].getBarValue() or numArray[i]
            char letter = bar.getName();
            Vector2f pos = bar.getPosition();

        }
        /***** END OF DRAWING	*****/

        // Apply all the draws to the screen
        window.display();

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
    }
    numOccur.close();
    return EXIT_SUCCESS;
}
