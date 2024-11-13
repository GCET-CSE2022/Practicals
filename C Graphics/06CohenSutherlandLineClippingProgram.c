#include <stdio.h>
#include <conio.h>
#include <graphics.h>

#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define ABOVE 4
#define BELOW 8

int x_min = 100, y_min = 100, x_max = 400, y_max = 400;

int computeCode(int x, int y) {
    int code = INSIDE;
    if (x < x_min) code |= LEFT;
    else if (x > x_max) code |= RIGHT;
    if (y < y_min) code |= BELOW;
    else if (y > y_max) code |= ABOVE;
    return code;
}

void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1), code2 = computeCode(x2, y2);
    while (1) {
        if ((code1 == 0) && (code2 == 0)) {
            line(x1, y1, x2, y2); // Draw line if both points are inside
            break;
        } else if ((code1 & code2) != 0) {
            break; // Reject line if both points are outside
        } else {
            int code_out, x, y;
            if (code1 != 0) code_out = code1; // Use the first code if code1 is non-zero
            else code_out = code2; // Otherwise use the second code

            // Find the intersection point
            if (code_out & ABOVE) { x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1); y = y_max; }
            else if (code_out & BELOW) { x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1); y = y_min; }
            else if (code_out & RIGHT) { y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1); x = x_max; }
            else if (code_out & LEFT) { y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1); x = x_min; }

            // Update the point that is outside the window
            if (code_out == code1) { x1 = x; y1 = y; code1 = computeCode(x1, y1); }
            else { x2 = x; y2 = y; code2 = computeCode(x2, y2); }
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");  // Initialize graphics

    int x1, y1, x2, y2;
    printf("Enter the coordinates of the line (x1, y1, x2, y2): ");
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    // Draw clipping window
    rectangle(x_min, y_min, x_max, y_max);
    
    // Apply Cohen-Sutherland Line Clipping
    cohenSutherlandClip(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
