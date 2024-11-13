#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void Bresenham_Line(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1, dy = y2 - y1;
    int dx2 = 2 * dx, dy2 = 2 * dy;
    int err = dy - dx;
    int x = x1, y = y1;

    putpixel(x, y, WHITE);

    while (x < x2) {
        if (err >= 0) {
            y++;
            err -= dx2;
        }
        x++;
        err += dy2;
        putpixel(x, y, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;
    printf("Enter the coordinates of the first point (x1, y1): ");
    scanf("%d%d", &x1, &y1);
    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%d%d", &x2, &y2);

    Bresenham_Line(x1, y1, x2, y2);

    getch();
    closegraph();

    return 0;
}
