#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

#define DELAY_TIME 50
#define PI 3.14159

void set(int x[][2], int h, int k, double t, int a, int b) {
    x[0][0] = h+a*cos(1.75*PI+t);
    x[0][1] = k+b*sin(1.75*PI+t);
    x[1][0] = h+a*cos(0.25*PI+t);
    x[1][1] = k+b*sin(0.25*PI+t);
    x[2][0] = h+a*cos(0.75*PI+t);
    x[2][1] = k+b*sin(0.75*PI+t);
    x[3][0] = h+a*cos(1.25*PI+t);
    x[3][1] = k+b*sin(1.25*PI+t);
}

void drawLine(int x[][2]) {
    line(x[0][0],x[0][1], x[1][0],x[1][1]);
    line(x[1][0],x[1][1], x[2][0],x[2][1]);
    line(x[2][0],x[2][1], x[3][0],x[3][1]);
    line(x[3][0],x[3][1], x[0][0],x[0][1]);
}
void draw(int h, int k) {
    int j=0;
    double s=0.0;
    int x[4][2], y[4][2], z[4][2];

    for (j=0; j<5000; j++) {
        set(x, h, k, s, 100, 100);
        set(y, h, k+15, s,100,100);
        set(z, h, k+30, s,100,100);
        s=s+0.1;
        setcolor(WHITE);
        drawLine(x);
        drawLine(y);
        drawLine(z);
        delay(DELAY_TIME);
        setcolor(BLACK);
        drawLine(x);
        drawLine(y);
        drawLine(z);
    }
}
int main() {
    srand(time(NULL));
    initwindow(800,600);
    draw(400,400);
    getch();
    closegraph( );
}
