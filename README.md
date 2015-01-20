# mandelbrot

Some old code a wrote sometime around 2013 when first learning C.

Creates an interactive text viewer for the mandelbrot set, 
you can scroll around and zoom in and such. Note that "focus"
refers to the number of iterations used to determine which points
are in the set, so one will need to "focus in" to see fine details 
at higher zoom levels.

Since it isn't really optimized or anything, eventually things slow
down once you focus in enough, so to get a nice experience it sometimes
helps to zoom really far in somewhere, with only minimal focusing in on
the details, then focus in a bit more so everything is reasonably clear,
and zoom out gradually--it can give a nice sense of the depth.

To compile just run make; it should be noted that the ncurses
library is needed. The executable is then called "mandel".
