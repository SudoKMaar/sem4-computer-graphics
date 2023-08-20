#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void main() {
    int gd, gm, x, y, r;
    int i, j, k, l, m;

    gd = DETECT;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    x = 20;
    y = 20;
    r = 20;

    do {
        for (i = 0; i <= 80; i++) {
            cleardevice();
            circle(x, y, r);
            x = x + 5;
            y = y + 5;
            delay(50);
        }

        for (j = 0; j <= 40; j++) {
            cleardevice();
            circle(x, y, r);
            x = x + 5;
            y = y - 5;
            delay(50);
        }

        for (k = 0; k <= 50; k++) {
            cleardevice();
            circle(x, y, r);
            x = x - 5;
            y = y - 5;
            delay(50);
        }

        for (l = 0; l <= 70; l++) {
            cleardevice();
            circle(x, y, r);
            x = x - 5;
            y = y + 5;
            delay(50);
        }

        for (m = 0; m <= 70; m++) {
            cleardevice();
            circle(x, y, r);
            x = x + 5;
            y = y + 5;
            delay(50);
        }
    } while (!kbhit());

    closegraph();
}
