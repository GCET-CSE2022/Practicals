#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void Bresenham_Circle(int x_center, int y_center, int radius) {
    int x = 0, y = radius;
    int p = 3 - 2 * radius;

    while (x <= y) {
        putpixel(x_center + x, y_center + y, WHITE);
        putpixel(x_center - x, y_center + y, WHITE);
        putpixel(x_center + x, y_center - y, WHITE);
        putpixel(x_center - x, y_center - y, WHITE);
        putpixel(x_center + y, y_center + x, WHITE);
        putpixel(x_center - y, y_center + x, WHITE);
        putpixel(x_center + y, y_center - x, WHITE);
        putpixel(x_center - y, y_center - x, WHITE);

        x++;
        if (p < 0) {
            p = p + 4 * x + 6;
        } else {
            y--;
            p = p + 4 * (x - y) + 10;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x_center, y_center, radius;
    printf("Enter the center coordinates of the circle (x, y): ");
    scanf("%d%d", &x_center, &y_center);
    printf("Enter the radius of the circle: ");
    scanf("%d", &radius);

    Bresenham_Circle(x_center, y_center, radius);

    getch();
    closegraph();

    return 0;
}
