/* ********** Definition of function for controlling map on screen ********** */

#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include "ITB_map.h"
using namespace std;

// reading input that user pressed
int getch(void) {
	int ch;
    struct termios oldt;
    struct termios newt;
    tcgetattr(STDIN_FILENO, &oldt); /*store old settings */
    newt = oldt; /* copy old settings to new settings */
    newt.c_lflag &= ~(ICANON | ECHO); /* make one change to old settings in new settings */
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); /*apply the new settings immediatly */
    ch = getchar(); /* standard getchar call */
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); /*reapply the old settings */
    return ch; /*return received char */
}

// execute command, return true if command is not exit, vice versa
bool getCommand() {
	int x = ' ';
    int y = ' ';
    int z = ' ';

    
    x = getch();

    if (x == 27) {
        y = getch();
        z = getch();

        if (x == 27 && y == 91) {
            switch (z) {
            case 65:
            changeMapOrientation(0, -1, false);
            // printf("up arrow key pressed\n");
            break;

            case 66:
            changeMapOrientation(0, 1, false);
            // printf("down arrow key pressed\n");
            break;

            case 67:
            changeMapOrientation(1, 0, false);
            // printf("right arrow key pressed\n");
            break;

            case 68:
            changeMapOrientation(-1, 0, false);
            // printf("left arrow key pressed\n");
            break;
            }
        }   
    }
    else {
    	switch (x) {
            case 'w':
            changeMapOrientation(0, -1, true);
            // printf("up arrow key pressed\n");
            break;

            case 's':
            changeMapOrientation(0, 1, true);
            // printf("down arrow key pressed\n");
            break;

            case 'd':
            changeMapOrientation(1, 0, true);
            // printf("right arrow key pressed\n");
            break;

            case 'a':
            changeMapOrientation(-1, 0, true);
            // printf("left arrow key pressed\n");
            break;

            case '.':
            // printf("bigger is pressed\n");
            changeMapScale(true, false);
            break;

            case ',':
            // printf("less is pressed\n");
            changeMapScale(false, false);
            break;

            case '/':
            // printf("reset left is pressed\n");
            resetMap(false);
            break;

            case 'h':
            // printf("bigger is pressed\n");
            changeMapScale(true, true);
            break;

            case 'g':
            // printf("less is pressed\n");
            changeMapScale(false, true);
            break;

            case 'j':
            // printf("reset right is pressed\n");
            resetMap(true);
            break;
        }
    }  

    if (x == 'x') {
        return false;
    }
    else {
        return true;
    }
}


#endif