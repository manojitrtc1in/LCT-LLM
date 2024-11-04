#include <stdio.h>
#include <math.h>

#define EPS 1e-8

typedef struct {
    double x, y;
} point;

typedef struct {
    point p;
    double r;
} circle;

int cmp(double x, double y, double tol) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

double dist2(point p, point q) {
    return ((p.x - q.x) * (p.x - q.x)) + ((p.y - q.y) * (p.y - q.y));
}

int ccw(point p, point q, point r) {
    return cmp((p.x - r.x) * (q.y - r.y), (p.y - r.y) * (q.x - r.x), EPS);
}

double angle(point p, point q, point r) {
    double ux = p.x - q.x;
    double uy = p.y - q.y;
    double vx = r.x - q.x;
    double vy = r.y - q.y;
    return atan2(ux * vy - uy * vx, ux * vx + uy * vy);
}

point rotateCCW90(point p) {
    return (point) {-p.y, p.x};
}

point rotateCW90(point p) {
    return (point) {p.y, -p.x};
}

point rotateCCW(point p, double t) {
    double cos_t = cos(t);
    double sin_t = sin(t);
    return (point) {p.x * cos_t - p.y * sin_t, p.x * sin_t + p.y * cos_t};
}

point projectPointLine(point a, point b, point c) {
    double r = ((c.x - a.x) * (b.x - a.x) + (c.y - a.y) * (b.y - a.y)) / ((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
    return (point) {a.x + r * (b.x - a.x), a.y + r * (b.y - a.y)};
}

point projectPointSegment(point a, point b, point c) {
    double r = ((c.x - a.x) * (b.x - a.x) + (c.y - a.y) * (b.y - a.y)) / ((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
    if (r < 0) {
        return a;
    } else if (r > 1) {
        return b;
    } else {
        return (point) {a.x + r * (b.x - a.x), a.y + r * (b.y - a.y)};
    }
}

int between(point p, point q, point r) {
    return ccw(p, q, r) == 0 && cmp((p.x - q.x) * (r.x - q.x) + (p.y - q.y) * (r.y - q.y), 0, EPS) <= 0;
}

double distancePointSegment(point a, point b, point c) {
    return sqrt(dist2(c, projectPointSegment(a, b, c)));
}

int linesParallel(point a, point b, point c, point d) {
    return cmp((b.x - a.x) * (d.y - c.y), (b.y - a.y) * (d.x - c.x), EPS) == 0;
}

int linesCollinear(point a, point b, point c, point d) {
    return linesParallel(a, b, c, d) && cmp((a.x - b.x) * (a.x - c.x) + (a.y - b.y) * (a.y - c.y), 0, EPS) == 0 && cmp((c.x - d.x) * (c.x - a.x) + (c.y - d.y) * (c.y - a.y), 0, EPS) == 0;
}

int seg_intersect(point p, point q, point r, point s) {
    point A = (point) {q.x - p.x, q.y - p.y};
    point B = (point) {s.x - r.x, s.y - r.y};
    point C = (point) {r.x - p.x, r.y - p.y};
    point D = (point) {s.x - q.x, s.y - q.y};
    int a = cmp(A.x * C.y - A.y * C.x, 0, EPS) + 2 * cmp(A.x * D.y - A.y * D.x, 0, EPS);
    int b = cmp(B.x * C.y - B.y * C.x, 0, EPS) + 2 * cmp(B.x * D.y - B.y * D.x, 0, EPS);
    if (a == 3 || a == -3 || b == 3 || b == -3) {
        return 0;
    }
    if (a || b || p.x == r.x && p.y == r.y || p.x == s.x && p.y == s.y || q.x == r.x && q.y == r.y || q.x == s.x && q.y == s.y) {
        return 1;
    }
    int t = (p.x < r.x) + (p.x < s.x) + (q.x < r.x) + (q.x < s.x);
    return t != 0 && t != 4;
}

point line_intersect(point p, point q, point r, point s) {
    point a = (point) {q.x - p.x, q.y - p.y};
    point b = (point) {s.x - r.x, s.y - r.y};
    point c = (point) {p.x * q.y - p.y * q.x, r.x * s.y - r.y * s.x};
    return (point) {(a.x * b.x * c.y - a.y * b.x * c.x - a.x * b.y * c.x + a.y * b.y * c.x) / (a.x * b.y - a.y * b.x), (a.x * b.y * c.y - a.y * b.y * c.x - a.x * b.x * c.y + a.y * b.x * c.y) / (a.y * b.x - a.x * b.y)};
}

int circle2PtsRad(point p1, point p2, double r, point *c) {
    double d2 = dist2(p1, p2);
    double det = ((r * r) / d2) - 0.25;
    if (det < 0.0) {
        return 0;
    }
    double h = sqrt(det);
    c->x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c->y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return 1;
}

point computeCircleCenter(point a, point b, point c) {
    b.x = (a.x + b.x) * 0.5;
    b.y = (a.y + b.y) * 0.5;
    c.x = (a.x + c.x) * 0.5;
    c.y = (a.y + c.y) * 0.5;
    return line_intersect(b, (point) {b.x + rotateCW90(a.x - b.x), b.y + rotateCW90(a.y - b.y)}, c, (point) {c.x + rotateCW90(a.x - c.x), c.y + rotateCW90(a.y - c.y)});
}

point computeCircleIncenter(point a, point b, point c) {
    point d = (point) {b.x + rotateCCW(c.x - b.x, angle(c, b, a) * 0.5), b.y + rotateCCW(c.y - b.y, angle(c, b, a) * 0.5)};
    point e = (point) {c.x + rotateCCW(a.x - c.x, angle(a, c, b) * 0.5), c.y + rotateCCW(a.y - c.y, angle(a, c, b) * 0.5)};
    return line_intersect(b, d, c, e);
}

int circleLineIntersection(point a, point b, point c, double r, point *p1, point *p2) {
    b.x -= a.x;
    b.y -= a.y;
    a.x -= c.x;
    a.y -= c.y;
    double A = b.x * b.x + b.y * b.y;
    double B = a.x * b.x + a.y * b.y;
    double C = a.x * a.x + a.y * a.y - r * r;
    double D = B * B - A * C;
    if (D < -EPS) {
        return 0;
    }
    p1->x = c.x + a.x + b.x * (-B + sqrt(D + EPS)) / A;
    p1->y = c.y + a.y + b.y * (-B + sqrt(D + EPS)) / A;
    if (D > EPS) {
        p2->x = c.x + a.x + b.x * (-B - sqrt(D)) / A;
        p2->y = c.y + a.y + b.y * (-B - sqrt(D)) / A;
        return 2;
    }
    return 1;
}

int circleCircleIntersection(point a, point b, double r, double R, point *p1, point *p2) {
    double d = sqrt(dist2(a, b));
    if (d > r + R || d + fmin(r, R) < fmax(r, R)) {
        return 0;
    }
    double x = (d * d - R * R + r * r) / (2 * d);
    double y = sqrt(r * r - x * x);
    double vx = (b.x - a.x) / d;
    double vy = (b.y - a.y) / d;
    p1->x = a.x + x * vx - y * vy;
    p1->y = a.y + x * vy + y * vx;
    if (y > 0) {
        p2->x = a.x + x * vx + y * vy;
        p2->y = a.y + x * vy - y * vx;
        return 2;
    }
    return 1;
}

int tangentSegments(point c, double r, point p, point *p1, point *p2) {
    point toCenter = (point) {c.x - p.x, c.y - p.y};
    if (cmp(r - sqrt(dist2(toCenter, (point) {0, 0})), 0, EPS) >= 0) {
        *p1 = p;
        *p2 = p;
        return 1;
    }
    double angle = asin(r / sqrt(dist2(toCenter, (point) {0, 0})));
    point uni = (point) {toCenter.x / sqrt(dist2(toCenter, (point) {0, 0})), toCenter.y / sqrt(dist2(toCenter, (point) {0, 0}})};
    double tam = sqrt(dist2(toCenter, (point) {0, 0}) - r * r);
    point origi = (point) {uni.x * tam, uni.y * tam};
    *p1 = (point) {p.x + origi.x * cos(angle) - origi.y * sin(angle), p.y + origi.x * sin(angle) + origi.y * cos(angle)};
    *p2 = (point) {p.x + origi.x * cos(-angle) - origi.y * sin(-angle), p.y + origi.x * sin(-angle) + origi.y * cos(-angle)};
    return 2;
}

int in_poly(point p, point T[], int N) {
    double a = 0;
    for (int i = 0; i < N; i++) {
        if (between(T[i], p, T[(i + 1) % N])) {
            return -1;
        }
        a += angle(T[i], p, T[(i + 1) % N]);
    }
    return cmp(a, 0, EPS) != 0;
}

double poly_area(point T[], int N) {
    double s = 0;
    for (int i = 0; i < N; i++) {
        s += T[i].x * T[(i + 1) % N].y - T[(i + 1) % N].x * T[i].y;
    }
    return s / 2;
}

point computeCentroid(point p[], int n) {
    point c = {0, 0};
    double scale = 6.0 * poly_area(p, n);
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        c.x += (p[i].x + p[j].x) * (p[i].x * p[j].y - p[j].x * p[i].y);
        c.y += (p[i].y + p[j].y) * (p[i].x * p[j].y - p[j].x * p[i].y);
    }
    c.x /= scale;
    c.y /= scale;
    return c;
}

int radial_lt(point p, point q) {
    point P = (point) {p.x - point::pivot.x, p.y - point::pivot.y};
    point Q = (point) {q.x - point::pivot.x, q.y - point::pivot.y};
    double R = P.x * Q.y - P.y * Q.x;
    if (cmp(R, 0, EPS)) {
        return R > 0;
    }
    return cmp(P.x * P.x + P.y * P.y, Q.x * Q.x + Q.y * Q.y, 0) < 0;
}

void swap(point *a, point *b) {
    point temp = *a;
    *a = *b;
    *b = temp;
}

void sort_points(point p[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (p[j].y < p[min_idx].y || (p[j].y == p[min_idx].y && p[j].x < p[min_idx].x)) {
                min_idx = j;
            }
        }
        swap(&p[min_idx], &p[i]);
    }
    point::pivot = p[0];
    for (i = 1; i < n; i++) {
        p[i].x -= p[0].x;
        p[i].y -= p[0].y;
    }
    p[0].x = 0;
    p[0].y = 0;
    for (i = 1; i < n; i++) {
        p[i].x -= p[0].x;
        p[i].y -= p[0].y;
    }
    p[0].x = 0;
    p[0].y = 0;
    qsort(p + 1, n - 1, sizeof(point), radial_lt);
}

void convex_hull(point T[], int n, point U[], int *m) {
    int j, k;
    *m = 0;
    point::pivot = T[0];
    sort_points(T, n);
    for (k = n - 2; k >= 0 && ccw(T[0], T[n - 1], T[k]) == 0; k--);
    for (j = 0; j < n; j++) {
        while (*m > 1 && ccw(U[*m - 2], U[*m - 1], T[j]) >= 0) {
            (*m)--;
        }
        U[(*m)++] = T[j];
    }
}

void poly_intersect(point P[], int n, point Q[], int m, point R[], int *r) {
    int a = 0, b = 0, aa = 0, ba = 0, inflag = 0;
    *r = 0;
    while ((aa < n || ba < m) && aa < 2 * n && ba < 2 * m) {
        point p1 = P[a], p2 = P[(a + 1) % n], q1 = Q[b], q2 = Q[(b + 1) % m];
        point A = (point) {p2.x - p1.x, p2.y - p1.y};
        point B = (point) {q2.x - q1.x, q2.y - q1.y};
        int cross = cmp(A.x * B.y - A.y * B.x, 0, EPS);
        int ha = ccw(p2, q2, p1);
        int hb = ccw(q2, p2, q1);
        if (cross == 0 && ccw(p1, q1, p2) == 0 && cmp(A.x * B.x + A.y * B.y, 0, EPS) < 0) {
            if (between(p1, q1, p2)) {
                R[(*r)++] = q1;
            }
            if (between(p1, q2, p2)) {
                R[(*r)++] = q2;
            }
            if (between(q1, p1, q2)) {
                R[(*r)++] = p1;
            }
            if (between(q1, p2, q2)) {
                R[(*r)++] = p2;
            }
            if (*r < 2) {
                return;
            }
            inflag = 1;
            break;
        } else if (cross != 0 && seg_intersect(p1, p2, q1, q2)) {
            if (inflag == 0) {
                aa = ba = 0;
            }
            R[(*r)++] = line_intersect(p1, p2, q1, q2);
            inflag = (hb > 0) ? 1 : -1;
        }
        if (cross == 0 && hb < 0 && ha < 0) {
            return;
        }
        int t = (p1.x < q1.x) + (p1.x < q2.x) + (p2.x < q1.x) + (p2.x < q2.x);
        if (t != 0 && t != 4) {
            if (inflag == 1) {
                R[(*r)++] = p2;
            }
            aa++;
            a++;
            a %= n;
        } else {
            if (inflag == -1) {
                R[(*r)++] = q2;
            }
            ba++;
            b++;
            b %= m;
        }
    }
    if (inflag == 0) {
        if (in_poly(P[0], Q, m)) {
            for (int i = 0; i < n; i++) {
                R[i] = P[i];
            }
            *r = n;
            return;
        }
        if (in_poly(Q[0], P, n)) {
            for (int i = 0; i < m; i++) {
                R[i] = Q[i];
            }
            *r = m;
            return;
        }
    }
}

double distancePointPlane(double x, double y, double z, double a, double b, double c, double d) {
    return fabs(a * x + b * y + c * z - d) / sqrt(a * a + b * b + c * c);
}

int main() {
    int xp, yp, vp, x, y, v, r;
    scanf("%d %d %d %d %d %d %d", &xp, &yp, &vp, &x, &y, &v, &r);
    int cont = 1000000;
    double R = hypot(yp, xp);
    double initial = atan2(yp, xp);
    double bot = 0;
    double timeTot = 1000000.0;
    double t1 = (2 * M_PI * R) / vp;
    double top = timeTot;
    while (top - bot > EPS) {
        double mid = (top + bot) / 2;
        double angle = ((2 * M_PI * mid) / t1) + initial;
        point loc = (point) {cos(angle) * R, sin(angle) * R};
        if (pode(loc, mid)) {
            top = mid - EPS;
        } else {
            bot = mid + EPS;
        }
    }
    printf("%.7f\n", bot);
    return 0;
}
