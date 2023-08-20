#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

int main()
{
    int gd = DETECT, gm, i = 0, x, xx, y, yy;
    
    // Initializes the graphics system
    initgraph(&gd, &gm, "c:\\tc\\bgi");
    
    x = getmaxx();
    y = getmaxy();
    
    while (!kbhit())
    {
        i++;
        circle(xx = random(x), yy = random(y), random(30));
        setfillstyle(random(i), random(30));
        floodfill(xx, yy, getmaxcolor());
        delay(200);
    }
    
    getch();
    closegraph();
    
    return 0;
}
