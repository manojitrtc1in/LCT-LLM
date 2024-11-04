#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

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
    return distance(c.center, p) <= sqrt(c.sqRadius);
}

Point intersections(Circle c1, Circle c2) {
    Point P0 = c1.center;
    Point P1 = c2.center;
    double d = distance(P0, P1);
    double a = (c1.sqRadius - c2.sqRadius + d * d) / (2 * d);
    double h = sqrt(c1.sqRadius - a * a);
    Point P2 = { (P1.x - P0.x) * (a / d) + P0.x, (P1.y - P0.y) * (a / d) + P0.y };
    Point intersection1 = { P2.x + h * (P1.y - P0.y) / d, P2.y - h * (P1.x - P0.x) / d };
    Point intersection2 = { P2.x - h * (P1.y - P0.y) / d, P2.y + h * (P1.x - P0.x) / d };
    return intersection1; // Just returning one intersection for simplicity
}

double solve(double XP, double YP, double VP, double X, double Y, double V, double R) {
    Point Orig = {X, Y};
    Point Zero = {0, 0};
    Circle Forbidden = {Zero, R * R};

    double RR = sqrt(XP * XP + YP * YP);
    double init = atan2(YP, XP);
    
    // Placeholder for binary search logic
    double t = 0.0; // This would be the result of the binary search
    // Implement the binary search logic here...

    return t; // Return the result
}

int main() {
    double XP, YP, VP;
    scanf("%lf %lf %lf", &XP, &YP, &VP);

    double X, Y, V, R;
    scanf("%lf %lf %lf %lf", &X, &Y, &V, &R);

    double result = solve(XP, YP, VP, X, Y, V, R);
    printf("%.10f\n", result);

    return 0;
}
