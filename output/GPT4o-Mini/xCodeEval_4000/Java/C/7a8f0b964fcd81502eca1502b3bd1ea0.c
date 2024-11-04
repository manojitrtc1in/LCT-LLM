#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define EPS 1e-7
#define MAX_ITER 10000
#define INF 3e6

typedef struct {
    double x;
    double y;
} Point2D;

typedef struct {
    Point2D c;
    double r;
} Circle2D;

typedef struct {
    Point2D p1;
    Point2D p2;
    double A;
    double B;
    double C;
} Line2D;

double dist(Point2D p1, Point2D p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double distSqr(Point2D p1, Point2D p2) {
    return pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2);
}

double cross(Point2D p0, Point2D p1, Point2D p2) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

bool hasCSC(Point2D p1, Point2D p2, Circle2D c) {
    double A = p2.y - p1.y;
    double B = p1.x - p2.x;
    double d = A * A + B * B;
    double dist = 0.0;

    if (fabs(d) < EPS) {
        dist = dist(p1, c.c);
    } else {
        double t = (B * (p1.x - c.c.x) - A * (p1.y - c.c.y)) / d;
        if (0.0 <= t && t <= 1.0) {
            dist = sqrt(pow(p1.x - B * t - c.c.x, 2) + pow(p1.y + A * t - c.c.y, 2));
        } else {
            dist = fmin(dist(p1, c.c), dist(p2, c.c));
        }
    }

    return dist <= c.r + EPS;
}

bool can(double t, Point2D ps, Point2D pp, double vP, double vs, Circle2D star) {
    Point2D rotated;
    rotated.x = pp.x * cos(t * vP / sqrt(pp.x * pp.x + pp.y * pp.y)) - pp.y * sin(t * vP / sqrt(pp.x * pp.x + pp.y * pp.y));
    rotated.y = pp.x * sin(t * vP / sqrt(pp.x * pp.x + pp.y * pp.y)) + pp.y * cos(t * vP / sqrt(pp.x * pp.x + pp.y * pp.y));
    return dist(ps, rotated) < t * vs;
}

double solve(Point2D pp, double vP, Point2D ps, double vs, Circle2D star) {
    double ans = INF;
    double left = 0;
    double right = ans;

    for (int it = 0; it < MAX_ITER; it++) {
        double mid = 0.5 * (left + right);
        if (can(mid, ps, pp, vP, vs, star)) {
            right = mid;
            ans = fmin(ans, mid);
        } else {
            left = mid;
        }
    }

    return ans;
}

int main() {
    double xp, yp, vP, vs, radius;
    Point2D pp, ps;
    
    FILE *input = fopen("input.txt", "r");
    if (input) {
        fscanf(input, "%lf %lf %lf %lf %lf", &xp, &yp, &vP, &ps.x, &ps.y, &vs);
        fscanf(input, "%lf", &radius);
        fclose(input);
    }

    pp.x = xp;
    pp.y = yp;

    Circle2D star = {{0.0, 0.0}, radius};
    double ans = solve(pp, vP, ps, vs, star);
    
    printf("%.10f\n", ans);
    return 0;
}
