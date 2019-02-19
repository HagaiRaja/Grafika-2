/*
http://ubuntuforums.org/archive/index.php/t-225713.html
*/

#include <stdio.h>
#include <unistd.h>
#include <termios.h>

int getch(void);

int main()
{
    int x = ' ';
    int y = ' ';
    int z = ' ';

    while (1) {
        x = getch();

        if (x == 27) {
            y = getch();
            z = getch();

            if (x == 27 && y == 91) {
                switch (z) {
                case 65:
                printf("up arrow key pressed\n");
                break;

                case 66:
                printf("down arrow key pressed\n");
                break;

                case 67:
                printf("right arrow key pressed\n");
                break;

                case 68:
                printf("left arrow key pressed\n");
                break;
                }
            }   
        }
        else {
            printf("'%c' key pressed\n", x);
        } 
    }


    return 0;
}

int getch(void)
{
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