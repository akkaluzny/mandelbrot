#include <stdio.h>
#include <curses.h>
#include "mandel.h"

#define DEPTH 1000
#define ZOOM (3.0)
#define I_INIT (0.0)
#define R_INIT (-0.75)


int vres, hres;

void printctrls(){
    mvaddstr(0,0,"\t\t\t\t\t");
    mvaddstr(1,0,"\tControls:\t\t\t");
    mvaddstr(2,0,"\th -- move left\tl -- move right\t");
    mvaddstr(3,0,"\tj -- move down\tk -- move up\t");
    mvaddstr(4,0,"\tz -- zoom in\tx -- zoom out\t");
    mvaddstr(5,0,"\tr -- focus in\tt -- focus out\t");
    mvaddstr(6,0,"\tc -- reset\ti -- help\t");
    mvaddstr(7,0,"\tq -- quit\t\t\t");
    mvaddstr(8,0,"\t\t\t\t\t");
}

int main(int argc, char **argv){
    initscr();
    cbreak();
    noecho();
    getmaxyx(stdscr, vres, hres);

    int mandel[vres][hres/2];
    int depth = DEPTH;
    int hlp = 0;
    double inc = ZOOM/(hres/2);
    double icenter = I_INIT;
    double rcenter = R_INIT;
    char command;

    computeman(rcenter, icenter, inc, DEPTH, mandel);
    printman(mandel);
    printctrls();
    refresh();
    while ((command = getch()) != 'q'){
        switch (command){
            case 'h':
                rcenter -= inc;
                break;
            case 'j':
                icenter -= inc;
                break;
            case 'k':
                icenter += inc;
                break;
            case 'l':
                rcenter += inc;
                break;
            case 'z':
                inc /= 1.5;
                break;
            case 'x':
                inc *= 1.5;
                break;
            case 'r':
                depth *= 1.1;
                break;
            case 't':
                depth /= 1.1;
                break;
            case 'c':
                depth = DEPTH;
                rcenter = R_INIT;
                icenter = I_INIT;
                inc = ZOOM/(hres/2);
                break;
            case 'i':
                hlp = 1;
            default:
                break;
        }
        computeman(rcenter, icenter, inc, depth, mandel);
        printman(mandel);
        if (hlp){
            printctrls();
            hlp = 0;
        }
        refresh();
    }
    endwin();
    return 0;
}

