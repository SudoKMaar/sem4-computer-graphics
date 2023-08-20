#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
void EightWaySymmetricPlot(int xc, int yc, int x, int y)
{
    putpixel(x + xc, y + yc, RED);
    putpixel(x + xc, -y + yc, YELLOW);
    putpixel(-x + xc, -y + yc, GREEN);
    putpixel(-x + xc, y + yc, BLUE);
    putpixel(y + xc, x + yc, CYAN);
    putpixel(y + xc, -x + yc, WHITE);
    putpixel(-y + xc, -x + yc, MAGENTA);
    putpixel(-y + xc, x + yc, BROWN);
}
void BresenhamCircle(int xc, int yc, int r)
{
    int x = 0, y = r, d = 3 - (2 * r);
    EightWaySymmetricPlot(xc, yc, x, y);
    while (x <= y)
    {
        if (d <= 0)
        {
            d = d + (4 * x) + 6;
        }
        else
        {
            d = d + (4 * x) - (4 * y) + 10;
            y = y - 1;
        }
        x = x + 1;
        EightWaySymmetricPlot(xc, yc, x, y);
    }
}
int main(void)
{
    int xc, yc, r, gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "C:\\TurboC++\\Disk\\TurboC3\\BGI");

    errorcode = graphresult();
    if (errorcode != grOk)
    {
        printf("Graphics error: %s\n", grapherrormsg(errorcode));
        printf("Press any key to halt:");
        getch();
        exit(1); /* terminate with an error code */
    }
    printf("ENTER THE COORDINATES OF THE CIRCLE : ");
    scanf("%d%d", &xc, &yc);
    printf("ENTER THE SIZE OF THE RADIUS : ");
    scanf("%d", &r);
    BresenhamCircle(xc, yc, r);
    getch();
    closegraph();
    return 0;
}