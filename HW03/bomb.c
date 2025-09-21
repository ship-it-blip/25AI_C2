#include <stdio.h>
#include <math.h>
#include <Windows.h>

#define PI 3.14159226535897

void moveCursor(int x, int y)
{
    printf("\x1b[%d;%dH", y, x);
}

void printBomb(int isExploded)
{
    if (isExploded)
    {
        printf("\x1b[A^^^^^^^");
        printf("\x1b[B\x1b[7D!BO0OM!");
        printf("\x1b[B\x1b[7D^^^^^^^");
    }
    else
        printf("(  b  )");
}

int path[500][2];
int path_len = 0;

void generateAndDrawFuse() {
#define PLOT(x, y) \
        moveCursor(x, y); printf("#"); \
        path[path_len][0] = x; path[path_len][1] = y; path_len++;

    for (int x = 8; x <= 19; x++) { PLOT(x, 2); }
    for (int y = 3; y <= 14; y++) { PLOT(19, y); }
    for (int x = 18; x >= 8; x--) { PLOT(x, 14); }
    for (int y = 13; y >= 4; y--) { PLOT(8, y); }

    for (int x = 9; x <= 17; x++) { PLOT(x, 4); }
    for (int y = 5; y <= 12; y++) { PLOT(17, y); }
    for (int x = 16; x >= 10; x--) { PLOT(x, 12); }
    for (int y = 11; y >= 6; y--) { PLOT(10, y); }

    for (int x = 11; x <= 15; x++) { PLOT(x, 6); }
    for (int y = 7; y <= 10; y++) { PLOT(15, y); }
    for (int x = 14; x >= 12; x--) { PLOT(x, 10); }
    for (int y = 9; y >= 8; y--) { PLOT(12, y); }

    PLOT(13, 8);
    PLOT(14, 8);
}


int main()
{
    printf("\x1b[?25l");

    moveCursor(1, 2);
    printBomb(0);

    generateAndDrawFuse();

    int flame_x = 14, flame_y = 9;
    moveCursor(flame_x, flame_y);
    printf("*");
    fflush(stdout);

    Sleep(1000);

    for (int i = path_len - 1; i >= 0; i--) {
        moveCursor(flame_x, flame_y);
        printf(" ");

        flame_x = path[i][0];
        flame_y = path[i][1];

        moveCursor(flame_x, flame_y);
        printf("*");

        fflush(stdout);
        Sleep(50);
    }

    Sleep(200);

    moveCursor(flame_x, flame_y);
    printf(" ");

    moveCursor(1, 2);
    printBomb(1);

    printf("\x1b[?25h");

    moveCursor(10, 22);
    return 0;
}