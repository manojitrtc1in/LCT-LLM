#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int x;
    int y;
} xyPoint;

typedef struct {
    xyPoint center;
    double radius;
} xyCircle;

void cartesian_dist(xyPoint a, xyPoint b, double *dist) {
    double d = a.x - b.x;
    double e = a.y - b.y;
    *dist = sqrt(d * d + e * e);
}

typedef struct {
    double slope;
    double intercept;
    double normfac;
    bool vertical;
    double xcross;
} xyLine;

void xyLine_init(xyLine *line, xyPoint a, xyPoint b) {
    if (a.x == b.x) {
        line->vertical = true;
        line->xcross = a.x;
        line->intercept = 0;
        line->slope = INFINITY;
        line->normfac = 0;
    } else {
        line->vertical = false;
        line->xcross = 0;
        line->slope = (b.y - a.y) / (b.x - a.x);
        line->intercept = a.y - line->slope * a.x;
        line->normfac = sqrt(line->slope * line->slope + 1.0);
    }
}

double orth_dist(xyLine *line, xyPoint o) {
    if (line->vertical) {
        return o.x - line->xcross;
    } else {
        return (line->slope * o.x - o.y + line->intercept) / line->normfac;
    }
}

double triangle_area(xyPoint a, xyPoint b, xyPoint c) {
    xyLine l;
    double h;
    double e;
    xyLine_init(&l, a, b);
    h = fabs(orth_dist(&l, c));
    e =  cartesian_dist(a, b);
    return h * e;
}

int main() {
    xyPoint a, b, c;
    double area;
    printf("Enter the coordinates of point A: ");
    scanf("%d %d", &a.x, &a.y);
    printf("Enter the coordinates of point B: ");
    scanf("%d %d", &b.x, &b.y);
    printf("Enter the coordinates of point C: ");
    scanf("%d %d", &c.x, &c.y);
    area = triangle_area(a, b, c);
    printf("The area of the triangle is: %.2f\n", area);
    return 0;
}
