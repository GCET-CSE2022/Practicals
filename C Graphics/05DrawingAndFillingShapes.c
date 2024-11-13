#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void floodFill(int x, int y, int fill_color, int boundary_color) {
    int current_color;
    current_color = getpixel(x, y);
    if (current_color != boundary_color && current_color != fill_color) {
        putpixel(x, y, fill_color);
        floodFill(x + 1, y, fill_color, boundary_color); // right
        floodFill(x - 1, y, fill_color, boundary_color); // left
        floodFill(x, y + 1, fill_color, boundary_color); // down
        floodFill(x, y - 1, fill_color, boundary_color); // up
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;
    int x_center, y_center, radius;
    int fill_color, boundary_color;

    // Drawing and filling a rectangle
    printf("Enter the top-left and bottom-right coordinates of the rectangle (x1, y1, x2, y2): ");
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    printf("Enter the fill color and boundary color: ");
    scanf("%d%d", &fill_color, &boundary_color);
    
    rectangle(x1, y1, x2, y2);
    floodFill((x1 + x2) / 2, (y1 + y2) / 2, fill_color, boundary_color); // Fill the rectangle

    // Drawing and filling a circle
    printf("Enter the center and radius of the circle (x, y, radius): ");
    scanf("%d%d%d", &x_center, &y_center, &radius);
    printf("Enter the fill color and boundary color: ");
    scanf("%d%d", &fill_color, &boundary_color);

    circle(x_center, y_center, radius);
    floodFill(x_center, y_center, fill_color, boundary_color); // Fill the circle

    getch();
    closegraph();

    return 0;
}
