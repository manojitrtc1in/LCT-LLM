#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 109

typedef struct {
    int x;
    int y;
} Po;

typedef struct {
    Po a;
    Po b;
} Line;

typedef struct {
    Line line;
} Seg;

Po createPo(int x, int y) {
    Po p;
    p.x = x;
    p.y = y;
    return p;
}

Line createLine(int x0, int y0, int x1, int y1) {
    Line l;
