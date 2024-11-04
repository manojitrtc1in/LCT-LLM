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
} id9;

typedef struct {
    id9 c;
    double r;
} id6;

typedef struct {
    id9 p1;
    id9 p2;
    double A;
    double B;
    double C;
} id5;

void set_id9(id9* p, double x, double y) {
    p->x = x;
    p->y = y;
}

double dist(id9 p1, id9 p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

bool hasCSC(id9 p1, id9 p2, id6 c) {
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

double id4(id9 p1, id9 p2, id6 c) {
    if (hasCSC(p1, p2, c)) {
        // Implement the logic for id10 and id1 here
        // For simplicity, returning a large number
        return INF;
    }
    return dist(p1, p2);
}

bool can(double t, id9 ps, id9 pp, double vs, double vP, id6 star) {
    return id4(ps, pp, star) < t * vs;
}

double solve(id9 pp, double vP, id9 ps, double vs, id6 star) {
    double ans = INF;
    double left = 0;
    double right = ans;

    for (int it = 0; it < MAX_ITER; it++) {
        double mid = 0.5 * (left + right);
        if (can(mid, ps, pp, vs, vP, star)) {
            right = mid;
            ans = fmin(ans, mid);
        } else {
            left = mid;
        }
    }

    return ans;
}

int main() {
    // Input reading
    double xp, yp, vP, xs, ys, vs, r;
    scanf("%lf %lf", &xp, &yp);
    scanf("%lf", &vP);
    scanf("%lf %lf", &xs, &ys);
    scanf("%lf", &vs);
    scanf("%lf", &r);

    id9 pp, ps;
    set_id9(&pp, xp, yp);
    set_id9(&ps, xs, ys);
    
    double rP = sqrt(xp * xp + yp * yp);
    double tvp = 1; // Assuming tvp is 1 for simplicity
    vP /= tvp;
    vs /= tvp;

    double omegaP = vP / rP;
    id6 star;
    set_id9(&star.c, 0.0, 0.0);
    star.r = r;

    double ans = solve(pp, vP, ps, vs, star);
    printf("%.10f\n", ans / tvp);

    return 0;
}
