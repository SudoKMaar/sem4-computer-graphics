#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void main()
{
    int gdriver = DETECT, gm, i;
    float x, y, dx, dy, steps;
    int x0, x1, y0, y1;
    initgraph(&gdriver, &gm, "C:\\TurboC++\\Disk\\TurboC3\\BGI");
    setbkcolor(WHITE);
    x0 = 69, y0 = 96, x1 = 169, y1 = 196;
    dx = (float)(x1 - x0);
    dy = (float)(y1 - y0);
    if (dx >= dy)
    {
        steps = dx;
    }
    else
    {
        steps = dy;
    }
    dx = dx / steps;
    dy = dy / steps;
    x = x0;
    y = y0;
    i = 1;
    while (i <= steps)
    {
        putpixel(x, y, GREEN);
        x += dx;
        y += dy;
        i = i + 1;
    }
    getch();
    closegraph();
}