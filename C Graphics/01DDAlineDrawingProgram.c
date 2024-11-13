#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void DDA_Line(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1, dy = y2 - y1;
    int steps;
    float x = x1, y = y1;

    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    } else {
        steps = abs(dy);
    }

    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;

    for (int i = 0; i <= steps; i++) {
        putpixel((int)(x), (int)(y), WHITE);
        x += Xinc;
        y += Yinc;
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

    DDA_Line(x1, y1, x2, y2);

    getch();
    closegraph();

    return 0;
}
