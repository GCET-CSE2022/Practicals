#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void Ellipse(int x_center, int y_center, int a, int b) {
    int x = 0, y = b;
    int a2 = a * a, b2 = b * b;
    int twob2 = 2 * b2, twoda2 = 2 * a2;
    int p1 = b2 - (a2 * b) + (a2 / 4);
    
    // Plotting points for the upper and lower halves
    while (2 * b2 * x < 2 * a2 * y) {
        putpixel(x_center + x, y_center + y, WHITE);
        putpixel(x_center - x, y_center + y, WHITE);
        putpixel(x_center + x, y_center - y, WHITE);
        putpixel(x_center - x, y_center - y, WHITE);

        x++;
        if (p1 < 0) {
            p1 += twob2 * x + b2;
        } else {
            y--;
            p1 += twob2 * x - twoda2 * y + b2;
        }
    }

    // Second half of the ellipse (steeper curve)
    int p2 = b2 * (x + 1) * (x + 1) + a2 * (y - 1) * (y - 1) - a2 * b2;
    while (y >= 0) {
        putpixel(x_center + x, y_center + y, WHITE);
        putpixel(x_center - x, y_center + y, WHITE);
        putpixel(x_center + x, y_center - y, WHITE);
        putpixel(x_center - x, y_center - y, WHITE);

        y--;
        if (p2 > 0) {
            p2 -= twoda2 * y + a2;
        } else {
            x++;
            p2 += twob2 * x - twoda2 * y + a2;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x_center, y_center, a, b;
    printf("Enter the center coordinates of the ellipse (x, y): ");
    scanf("%d%d", &x_center, &y_center);
    printf("Enter the lengths of the semi-major axis (a) and semi-minor axis (b): ");
    scanf("%d%d", &a, &b);

    Ellipse(x_center, y_center, a, b);

    getch();
    closegraph();

    return 0;
}
