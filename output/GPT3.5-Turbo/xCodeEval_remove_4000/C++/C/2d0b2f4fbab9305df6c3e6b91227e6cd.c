#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} xyPoint;

typedef struct {
    xyPoint center;
    double radius;
} xyCircle;

void print_xyPoint(xyPoint p) {
    printf("(%d, %d)\n", p.x, p.y);
}

void print_xyCircle(xyCircle o) {
    printf("{{%d, %d}, %f}\n", o.center.x, o.center.y, o.radius);
}

double id14(xyPoint a, xyPoint b) {
    double d = a.x - b.x;
    double e = a.y - b.y;
    return sqrt(d * d + e * e);
}

typedef struct {
    double id4;
    double id10;
    double id27;
    bool m_vertical;
    double id8;
} xyLine;

xyLine create_xyLine(xyPoint a, xyPoint b) {
    xyLine line;
    if (a.x == b.x) {
        line.m_vertical = true;
        line.id8 = a.x;
        line.id10 = 0;
        line.id4 = INFINITY;
        line.id27 = 0;
    } else {
        line.m_vertical = false;
        line.id8 = 0;
        line.id4 = (b.y - a.y) / (b.x - a.x);
        line.id10 = a.y - line.id4 * a.x;
        line.id27 = sqrt(line.id4 * line.id4 + 1.0);
    }
    return line;
}

double orth_dist(xyLine line, xyPoint o) {
    if (line.m_vertical) {
        return o.x - line.id8;
    } else {
        return (line.id4 * o.x - o.y + line.id10) / line.id27;
    }
}

double triangle_area(xyPoint a, xyPoint b, xyPoint c) {
    xyLine l = create_xyLine(a, b);
    double h = fabs(orth_dist(l, c));
    double e = id14(a, b);
    return h * e;
}

int main() {
    xyPoint a = {0, 0};
    xyPoint b = {3, 4};
    xyPoint c = {6, 0};

    double area = triangle_area(a, b, c);
    printf("Triangle Area: %f\n", area);

    return 0;
}
