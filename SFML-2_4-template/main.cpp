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

    Bar *bars = (Bar*) malloc(sizeof(Bar)*Z);

    char c = 'c';
    int i = 0;
    
    int numArray[Z];
    string letters[Z];

    for (i = 0; i < Z; ++i) {
        numArray[i] = 0;
    }

    numOccur.open("numOccur.txt");
    if (!numOccur.is_open()) {
        cout << "Could not open file myfile.txt." << endl;
        return 1;
    }
    //end A08 copy

    for (int i = 0; i < Z; i++)
    {
        
        string line, temp;
        getline(numOccur, line);

        letters[i] = line.at(0);
        temp = line.substr(1, line.length());

        std::string::size_type sz;   // alias of size_t
        numArray[i] = stoi(temp, &sz);
    }


    //end array set

    const int X = 26; //this is used to set bar hight
    const int BAR_WIDTH = 24;
    int bar_height = 100;


    RectangleShape bar(Vector2f(BAR_WIDTH, bar_height);
   
    bar.setPosition(Vector2f((float)0, (float)540));
    /***** END OF FILE PROCESSING *****/

    // creates the window object with an 640x640 resolution window
    RenderWindow window(VideoMode(640, 640), "SFML Template");

    // Draw loop: Each iteration of this loop draws a single frame
    while (window.isOpen()) {

        // Erase the screen with black (because space)
        window.clear();

        /***** PLACE YOUR DRAWING CODE HERE *****/
        window.draw(bar);
        
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
