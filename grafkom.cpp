#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <curses.h>

using namespace std;

bool getInput(char *c){
    if (kbhit()){
        *c = getch();
        return true;
    }
    return false;
}

int main() {
    char key = ' ';
    while (key != 'q'){
        while(!getInput(&key)){

        }
        cout << "You pressed: '" << key << "' "<< endl;
    }
    cout << "You Quit! Bye World." << endl;
    return 0;
}

