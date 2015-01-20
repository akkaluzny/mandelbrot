#include <stdio.h>
#include <curses.h>
#include "mandel.h"

extern int vres, hres;

void printman(int mandel[vres][hres/2]){
    int ii, jj;
    int extraSpace = hres%2;
    move(0,0);  // move to upper left before printing
    for (ii = 0; ii < vres; ii++){
        for (jj = 0; jj < hres/2; jj++){
            if (mandel[ii][jj] < 0){
                addch('*');
                addch('*');
            } else {
                addch(' ');
                addch(' ');
            }
        }
        if (extraSpace){addch(' ');}
    }
}

void computeman(double rcenter, double icenter, double inc, int depth, int mandel[vres][hres/2]){
    int ii, jj;
    double rc, ic;
    for (ii = 0; ii < vres; ii++){
        for (jj = 0; jj < hres/2; jj++){
            ic = icenter + inc * (vres / 2 - ii);
            rc = rcenter - inc * ((hres/2) / 2 - jj);
            mandel[ii][jj] = iterate(rc, ic, depth);
        }
    }

}

int iterate(double rc, double ic, int depth){
    double rz = rc;
    double iz = ic;
    double tmp;
    int result = -1;
    int ii = 0;
    while ((ii < depth) && ((rz * rz + iz * iz) < 4)){
        tmp = rz * rz - iz * iz + rc;
        iz = 2 * rz * iz + ic;
        rz = tmp;
        ii ++;
    }
    if (ii < depth){
        result = ii;
    }
    return result;
}
