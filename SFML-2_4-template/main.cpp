/*CSCI 261: Assignment 09: Graph Alice
*
*Author: Dustin Huntsman
*
*02 Apr 2017
*
*/

#include "Header.h"



int main() {

    /***** PLACE YOUR FILE PROCESSING CODE HERE *****/
    //begin A08 copy
    ifstream numOccur;

    Bar bars[NUM_LETTERS];

    char c = 'c';
    int i = 0;
    
    int numArray[NUM_LETTERS];
    string letters[NUM_LETTERS];

    for (i = 0; i < NUM_LETTERS; ++i) {
        numArray[i] = 0;
    }

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

        letters[i] = line.at(0);
        temp = line.substr(1, line.length());

        std::string::size_type sz;   // alias of siNUM_LETTERSe_t
        numArray[i] = stoi(temp, &sz);
    }


    //end array set
    /***** END OF FILE PROCESSING *****/

    for (int i = 0; i < NUM_LETTERS; i++) {
        bars[i].setPosition(Vector2f((i * 24), 0));
    }

    // creates the window object with an 640x640 resolution window
    RenderWindow window(VideoMode(640, 640), "SFML Template");

    // Draw loop: Each iteration of this loop draws a single frame
    while (window.isOpen()) {

        // Erase the screen with black (because space)
        window.clear();

        /***** PLACE YOUR DRAWING CODE HERE *****/

        for (int i = 0; i < NUM_LETTERS; i++) {
            bars[i].setBarValue(numArray[i]);
            window.draw((RectangleShape) bars[i]);
            // draw out the value with bars[i].getBarValue() or numArray[i]
            int value = bars[i].getBarValue();// or int value = numArray[i];
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
