#ifndef MANDEL
#define MANDEL

    #define VRES 30
    #define HRES 40

    void printman(int[VRES][HRES]);
    void computeman(double, double, double, int, int[VRES][HRES]);
    int iterate(double, double, int);

#endif
