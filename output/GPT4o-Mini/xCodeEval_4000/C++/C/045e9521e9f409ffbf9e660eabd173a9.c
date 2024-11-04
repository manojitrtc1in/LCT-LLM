#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point center;
    double sqRadius;
} Circle;

typedef struct {
    Point a, b;
} Segment;

double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool contains(Circle c, Point p) {
    return distance(c.center, p) * distance(c.center, p) <= c.sqRadius;
}

Point intersections(Circle c1, Circle c2) {
    double d = distance(c1.center, c2.center);
    double a = (c1.sqRadius - c2.sqRadius + d * d) / (2 * d);
    double h = sqrt(c1.sqRadius - a * a);
    Point p2 = {c2.center.x + a * (c1.center.x - c2.center.x) / d, 
                 c2.center.y + a * (c1.center.y - c2.center.y) / d};
    return (Point){p2.x + h * (c2.center.y - c1.center.y) / d, 
                   p2.y - h * (c2.center.x - c1.center.x) / d};
}

double solve(double XP, double YP, double VP, double X, double Y, double V, double R) {
    Point Orig = {X, Y};
    Point Zero = {0, 0};
    Circle Forbidden = {Zero, R * R};

    double RR = sqrt(XP * XP + YP * YP);
    double init = atan2(YP, XP);
    double t = 0.0, step = 1e-9;

    while (t <= 1e5) {
        double angle = (t * VP) / RR;
        Point New = {RR * cos(angle + init), RR * sin(angle + init)};
        Segment straight = {New, Orig};

        double dist = distance(Zero, straight.a);
        if (dist >= R) {
            if (distance(straight.a, straight.b) <= t * V) {
                return t;
            }
        } else {
            // Solve for intersections and distances
            Circle Thales1 = {Orig, 0};
            Circle Thales2 = {New, 0};

            Point Inter1 = intersections(Thales1, Forbidden);
            Point Inter2 = intersections(Thales2, Forbidden);

            double dist1 = distance(Inter1, Inter2);
            if (dist1 <= t * V) {
                return t;
            }
        }
        t += step;
    }
    return -1; // If no solution found
}

int main() {
    double XP, YP, VP;
    scanf("%lf %lf %lf", &XP, &YP, &VP);

    double X, Y, V, R;
    scanf("%lf %lf %lf %lf", &X, &Y, &V, &R);

    double result = solve(XP, YP, VP, X, Y, V, R);
    printf("%.10lf\n", result);

    return 0;
}
