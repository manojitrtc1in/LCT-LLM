#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point p1;
    Point p2;
} Segment;

typedef struct {
    Point center;
    double radius;
} Circle;

typedef enum {
    IN,
    OUT,
    BOUNDARY
} State;

double cross(Point p1, Point p2) {
    return p1.x * p2.y - p1.y * p2.x;
}

double dot(Point p1, Point p2) {
    return p1.x * p2.x + p1.y * p2.y;
}

double length(Point p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

Point vec(Point p1, Point p2) {
    Point v;
    v.x = p2.x - p1.x;
    v.y = p2.y - p1.y;
    return v;
}

Point normalize(Point p) {
    double len = length(p);
    Point v;
    v.x = p.x / len;
    v.y = p.y / len;
    return v;
}

Point rotate(Point p, double angle) {
    Point r;
    r.x = p.x * cos(angle) - p.y * sin(angle);
    r.y = p.x * sin(angle) + p.y * cos(angle);
    return r;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

double polygonArea(Point p[], int n) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        res += cross(p[i], p[j]);
    }
    return fabs(res) / 2;
}

Point centroid(Point p[], int n) {
    double a = 0;
    double x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        x += (p[i].x + p[j].x) * (p[i].x * p[j].y - p[j].x * p[i].y);
        y += (p[i].y + p[j].y) * (p[i].x * p[j].y - p[j].x * p[i].y);
        a += p[i].x * p[j].y - p[i].y * p[j].x;
    }
    a *= 0.5;
    x /= 6 * a;
    y /= 6 * a;
    Point c;
    c.x = x;
    c.y = y;
    return c;
}

int gcdLength(Point p1, Point p2) {
    return abs(gcd((int)(p1.x - p2.x), (int)(p1.y - p2.y))) + 1;
}

double triangleArea(double base, double height) {
    return base * height / 2;
}

double triangleAreaWithSides(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double cosRule(double a, double b, double c) {
    double res = (b * b + c * c - a * a) / (2 * b * c);
    if (fabs(res - 1) < 1e-9) {
        res = 1;
    }
    if (fabs(res + 1) < 1e-9) {
        res = -1;
    }
    return acos(res);
}

double sinRule(double a, double b, double angle) {
    return (a * sin(angle)) / b;
}

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

State circlePoint(Circle c, Point p) {
    double lensqr = pow(p.x - c.center.x, 2) + pow(p.y - c.center.y, 2);
    if (fabs(lensqr - c.radius * c.radius) < 1e-9) {
        return BOUNDARY;
    }
    if (lensqr < c.radius * c.radius) {
        return IN;
    }
    return OUT;
}

int circleLineIntersection(Point p1, Point p2, Circle c, Point* r1, Point* r2) {
    double a, b, c1, t1, t2;
    a = dot(vec(p1, p2), vec(p1, p2));
    b = 2 * dot(vec(p1, p2), vec(p1, c.center));
    c1 = dot(vec(p1, c.center), vec(p1, c.center)) - c.radius * c.radius;
    double det = b * b - 4 * a * c1;
    int res;
    if (fabs(det) < 1e-9) {
        det = 0;
        res = 1;
    } else if (det < 0) {
        res = 0;
    } else {
        res = 2;
    }
    det = sqrt(det);
    t1 = (-b + det) / (2 * a);
    t2 = (-b - det) / (2 * a);
    r1->x = p1.x + t1 * (p2.x - p1.x);
    r1->y = p1.y + t1 * (p2.y - p1.y);
    r2->x = p1.x + t2 * (p2.x - p1.x);
    r2->y = p1.y + t2 * (p2.y - p1.y);
    return res;
}

void polygonCut(Point p[], int n, Point a, Point b, Point res[], int* resSize) {
    *resSize = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        int in1 = cross(vec(a, b), vec(a, p[i])) > 1e-9;
        int in2 = cross(vec(a, b), vec(a, p[j])) > 1e-9;
        if (in1) {
            res[*resSize] = p[i];
            (*resSize)++;
        }
        if (in1 ^ in2) {
            Point r;
            circleLineIntersection(a, b, (Circle){p[i], 0}, &r, NULL);
            res[*resSize] = r;
            (*resSize)++;
        }
    }
}

void convexHull(Point p[], int n, Point convex[], int* convexSize) {
    int hullSize = 0;
    Point hull[n];
    int mn = 0;
    for (int i = 1; i < n; i++) {
        if (p[i].y < p[mn].y || (p[i].y == p[mn].y && p[i].x < p[mn].x)) {
            mn = i;
        }
    }
    Point temp = p[0];
    p[0] = p[mn];
    p[mn] = temp;
    for (int i = 1; i < n; i++) {
        p[i].x -= p[0].x;
        p[i].y -= p[0].y;
    }
    convex[hullSize] = p[0];
    hullSize++;
    if (n == 1) {
        *convexSize = hullSize;
        return;
    }
    convex[hullSize] = p[1];
    hullSize++;
    if (n == 2) {
        *convexSize = hullSize;
        return;
    }
    for (int i = 2; i <= n; i++) {
        Point c = p[i % n];
        while (hullSize > 1) {
            Point b = convex[hullSize - 1];
            Point a = convex[hullSize - 2];
            if (cross(vec(b, a), vec(b, c)) < -1e-9) {
                break;
            }
            hullSize--;
        }
        if (i < n) {
            convex[hullSize] = p[i];
            hullSize++;
        }
    }
    *convexSize = hullSize;
}

double calcArc(Point a, Point b, double r) {
    double theta = fabs(atan2(b.y, b.x) - atan2(a.y, a.x));
    if (theta > M_PI) {
        theta = 2 * M_PI - theta;
    }
    double res = theta * r;
    return res;
}

double calcDis(Point a, Point c, double r, Point st, Point en) {
    double arc = calcArc(a, c, r);
    double res = arc + fabs(distance(a, st)) + fabs(distance(c, en));
    return res;
}

double calc(Point st, Point en, double xp, double yp, double vp, double x, double y, double v, double r, double R) {
    Point start = st;
    Point fin = en;
    double theta = vp * R;
    fin.x = en.x * cos(theta) - en.y * sin(theta);
    fin.y = en.x * sin(theta) + en.y * cos(theta);
    Point a, b, c, d;
    int intersection = 0;
    int num = circleLineIntersection(start, fin, (Circle){{0, 0}, r}, &a, &b);
    if (num) {
        if (cross(start, fin, a) > 1e-9) {
            intersection = 1;
        }
        if (num == 2 && cross(start, fin, b) > 1e-9) {
            intersection = 1;
        }
    }
    if (num <= 1 || !intersection) {
        double dis = distance(start, fin);
        return dis < v * vp + 1e-9;
    }
    double dis = calcDis(a, c, r, st, fin);
    dis = fmin(dis, calcDis(a, d, r, st, fin));
    dis = fmin(dis, calcDis(b, c, r, st, fin));
    dis = fmin(dis, calcDis(b, d, r, st, fin));
    return dis < v * vp + 1e-9;
}

int main() {
    double xp, yp, vp, x, y, v, r, R;
    double pi = acos(-1);
    Point st, en;
    scanf("%lf %lf %lf %lf %lf %lf %lf", &xp, &yp, &vp, &x, &y, &v, &r);
    R = length((Point){xp, yp});
    double ans = 10000000, hi = 1000000, lo = 0.0;
    for (int iter = 0; iter < 100; iter++) {
        double m = lo + (hi - lo) / 2.0;
        if (calc(m)) {
            ans = m;
            hi = m;
        } else {
            lo = m;
        }
    }
    printf("%.10lf\n", ans);
    return 0;
}
