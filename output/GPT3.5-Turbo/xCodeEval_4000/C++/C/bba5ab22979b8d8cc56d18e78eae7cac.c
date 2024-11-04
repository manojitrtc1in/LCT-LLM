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

typedef struct {
  point p1, p2;
} segment;

int cmp(double x, double y, double tol) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int ccw(point p, point q, point r) {
  return cmp((p.x-r.x) * (q.y-r.y) - (p.y-r.y) * (q.x-r.x), 0, EPS);
}

double dist2(point p, point q) {
  return (p.x-q.x) * (p.x-q.x) + (p.y-q.y) * (p.y-q.y);
}

point rotateCCW90(point p) {
  return (point) {-p.y, p.x};
}

point rotateCW90(point p) {
  return (point) {p.y, -p.x};
}

point rotateCCW(point p, double t) {
  return (point) {p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t)};
}

point projectPointLine(point a, point b, point c) {
  double r = ((c.x-a.x) * (b.x-a.x) + (c.y-a.y) * (b.y-a.y)) / ((b.x-a.x) * (b.x-a.x) + (b.y-a.y) * (b.y-a.y));
  return (point) {a.x + r * (b.x-a.x), a.y + r * (b.y-a.y)};
}

point projectPointSegment(point a, point b, point c) {
  double r = ((c.x-a.x) * (b.x-a.x) + (c.y-a.y) * (b.y-a.y)) / ((b.x-a.x) * (b.x-a.x) + (b.y-a.y) * (b.y-a.y));
  if (r < 0) return a;
  if (r > 1) return b;
  return (point) {a.x + r * (b.x-a.x), a.y + r * (b.y-a.y)};
}

int between(point p, point q, point r) {
  return ccw(p, q, r) == 0 && cmp((p.x-q.x) * (r.x-q.x) + (p.y-q.y) * (r.y-q.y), 0, EPS) <= 0;
}

double distancePointSegment(point a, point b, point c) {
  return sqrt(dist2(c, projectPointSegment(a, b, c)));
}

int linesParallel(point a, point b, point c, point d) {
  return cmp((b.x-a.x) * (d.y-c.y) - (b.y-a.y) * (d.x-c.x), 0, EPS) == 0;
}

int linesCollinear(point a, point b, point c, point d) {
  return linesParallel(a, b, c, d) && cmp((a.x-b.x) * (a.x-c.x) + (a.y-b.y) * (a.y-c.y), 0, EPS) == 0 && cmp((c.x-d.x) * (c.x-a.x) + (c.y-d.y) * (c.y-a.y), 0, EPS) == 0;
}

int seg_intersect(point p, point q, point r, point s) {
  point A = (point) {q.x-p.x, q.y-p.y};
  point B = (point) {s.x-r.x, s.y-r.y};
  double cross = A.x * B.y - A.y * B.x;
  if (cmp(cross, 0, EPS) != 0) return 1;
  double dot = A.x * B.x + A.y * B.y;
  if (cmp(dot, 0, EPS) < 0 || cmp(dot, dot, EPS) > 0) return 0;
  double lenA = A.x * A.x + A.y * A.y;
  double lenB = B.x * B.x + B.y * B.y;
  if (cmp(dot, lenA, EPS) > 0 || cmp(dot, lenB, EPS) > 0) return 0;
  return 1;
}

point line_intersect(point p, point q, point r, point s) {
  point a = (point) {q.x-p.x, q.y-p.y};
  point b = (point) {s.x-r.x, s.y-r.y};
  double c = a.x * p.x + a.y * p.y;
  double d = b.x * r.x + b.y * r.y;
  double det = a.x * b.y - a.y * b.x;
  return (point) {(b.y * c - a.y * d) / det, (a.x * d - b.x * c) / det};
}

int circle2PtsRad(point p1, point p2, double r, point *c) {
  double d2 = dist2(p1, p2);
  double det = (r * r) / d2 - 0.25;
  if (det < 0.0) return 0;
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
  return line_intersect(b, b+rotateCW90(a-b), c, c+rotateCW90(a-c));
}

point computeCircleIncenter(point a, point b, point c) {
  point d = b + rotateCCW(c-b, atan2(c.y-b.y, c.x-b.x) / 2);
  point e = c + rotateCCW(a-c, atan2(a.y-c.y, a.x-c.x) / 2);
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
  if (D < -EPS) return 0;
  p1->x = c.x + (a.x * A - b.x * B) / A;
  p1->y = c.y + (a.y * A - b.y * B) / A;
  if (D > EPS) {
    p2->x = c.x + (a.x * A + b.x * B) / A;
    p2->y = c.y + (a.y * A + b.y * B) / A;
    return 2;
  }
  return 1;
}

int circleCircleIntersection(point a, point b, double r, double R, point *p1, point *p2) {
  double d = sqrt(dist2(a, b));
  if (d > r+R || d+fabs(r-R) < fabs(r-R)) return 0;
  double x = (d*d-R*R+r*r) / (2*d);
  double y = sqrt(r*r-x*x);
  point v = (point) {(b.x-a.x) / d, (b.y-a.y) / d};
  p1->x = a.x + x * v.x + y * v.y;
  p1->y = a.y + x * v.y - y * v.x;
  if (y > 0) {
    p2->x = a.x + x * v.x - y * v.y;
    p2->y = a.y + x * v.y + y * v.x;
    return 2;
  }
  return 1;
}

int tangentSegments(point c, double r, point p, segment *s1, segment *s2) {
  point toCenter = (point) {c.x-p.x, c.y-p.y};
  if (cmp(r - sqrt(dist2(toCenter, (point) {0, 0}))), 0, EPS) >= 0) {
    *s1 = (segment) {p, p};
    *s2 = (segment) {p, p};
    return 1;
  }
  double angle = asin(r / sqrt(dist2(toCenter, (point) {0, 0})));
  point uni = (point) {toCenter.x / sqrt(dist2(toCenter, (point) {0, 0})), toCenter.y / sqrt(dist2(toCenter, (point) {0, 0}})};
  double tam = sqrt(dist2(toCenter, (point) {0, 0}}) - r * r);
  point origi = (point) {uni.x * tam, uni.y * tam};
  s1->p1 = (point) {p.x + origi.x * cos(angle) - origi.y * sin(angle), p.y + origi.x * sin(angle) + origi.y * cos(angle)};
  s1->p2 = (point) {p.x + origi.x * cos(-angle) - origi.y * sin(-angle), p.y + origi.x * sin(-angle) + origi.y * cos(-angle)};
  s2->p1 = (point) {p.x - origi.x * cos(angle) + origi.y * sin(angle), p.y - origi.x * sin(angle) - origi.y * cos(angle)};
  s2->p2 = (point) {p.x - origi.x * cos(-angle) + origi.y * sin(-angle), p.y - origi.x * sin(-angle) - origi.y * cos(-angle)};
  return 2;
}

int in_poly(point p, point *T, int n) {
  double a = 0;
  for (int i = 0; i < n; i++) {
    if (between(T[i], p, T[(i+1) % n])) return -1;
    a += atan2(T[(i+1) % n].y-p.y, T[(i+1) % n].x-p.x) - atan2(T[i].y-p.y, T[i].x-p.x);
  }
  return cmp(a) != 0;
}

double poly_area(point *T, int n) {
  double s = 0;
  for (int i = 0; i < n; i++) {
    s += T[i].x * T[(i+1) % n].y - T[(i+1) % n].x * T[i].y;
  }
  return s / 2;
}

point computeCentroid(point *p, int n) {
  point c = {0, 0};
  double scale = 6.0 * poly_area(p, n);
  for (int i = 0; i < n; i++) {
    int j = (i+1) % n;
    c.x += (p[i].x + p[j].x) * (p[i].x * p[j].y - p[j].x * p[i].y);
    c.y += (p[i].y + p[j].y) * (p[i].x * p[j].y - p[j].x * p[i].y);
  }
  c.x /= scale;
  c.y /= scale;
  return c;
}

int radial_lt(point p, point q) {
  return cmp(p.x * q.y, q.x * p.y, EPS) > 0;
}

void swap(point *a, point *b) {
  point temp = *a;
  *a = *b;
  *b = temp;
}

void sort_points(point *p, int n) {
  int i, j, min_idx;
  for (i = 0; i < n-1; i++) {
    min_idx = i;
    for (j = i+1; j < n; j++) {
      if (radial_lt(p[j], p[min_idx])) {
        min_idx = j;
      }
    }
    swap(&p[min_idx], &p[i]);
  }
}

void convex_hull(point *T, int n, point *U, int *m) {
  int j = 0, k;
  sort_points(T, n);
  for (k = n-2; k >= 0 && ccw(T[0], T[n-1], T[k]) == 0; k--);
  for (int i = 0; i < n; i++) {
    while (j > 1 && ccw(U[j-1], U[j-2], T[i]) >= 0) j--;
    U[j++] = T[i];
  }
  *m = j;
}

void poly_intersect(point *P, int n, point *Q, int m, point *R, int *k) {
  int a = 0, b = 0, aa = 0, ba = 0, inflag = 0;
  while ((aa < n || ba < m) && aa < 2*n && ba < 2*m) {
    point p1 = P[a], p2 = P[(a+1) % n], q1 = Q[b], q2 = Q[(b+1) % m];
    int cross = cmp((p2.x-p1.x) * (q2.y-q1.y) - (p2.y-p1.y) * (q2.x-q1.x), 0, EPS);
    int ha = ccw(p2, q2, p1), hb = ccw(q2, p2, q1);
    if (cross == 0 && ccw(p1, q1, p2) == 0 && cmp((p1.x-q1.x) * (p2.x-q1.x) + (p1.y-q1.y) * (p2.y-q1.y), 0, EPS) <= 0) {
      if (between(p1, q1, p2)) R[(*k)++] = q1;
      if (between(p1, q2, p2)) R[(*k)++] = q2;
      if (between(q1, p1, q2)) R[(*k)++] = p1;
      if (between(q1, p2, q2)) R[(*k)++] = p2;
      if (*k < 2) return;
      inflag = 1;
      break;
    } else if (cross != 0 && seg_intersect(p1, p2, q1, q2)) {
      if (inflag == 0) aa = ba = 0;
      R[(*k)++] = line_intersect(p1, p2, q1, q2);
      inflag = hb > 0 ? 1 : -1;
    }
    if (cross == 0 && hb < 0 && ha < 0) return;
    int t = cross == 0 && hb == 0 && ha == 0;
    if (t ? (inflag == 1) : (cross >= 0) ? (ha <= 0) : (hb > 0)) {
      if (inflag == -1) R[(*k)++] = q2;
      ba++; b++; b %= m;
    } else {
      if (inflag == 1) R[(*k)++] = p2;
      aa++; a++; a %= n;
    }
  }
  if (inflag == 0) {
    if (in_poly(P[0], Q, m)) {
      for (int i = 0; i < n; i++) R[i] = P[i];
      *k = n;
    }
    if (in_poly(Q[0], P, n)) {
      for (int i = 0; i < m; i++) R[i] = Q[i];
      *k = m;
    }
  }
}

double distancePointPlane(double x, double y, double z, double a, double b, double c, double d) {
  return fabs(a*x + b*y + c*z - d) / sqrt(a*a + b*b + c*c);
}

int main() {
  int xp, yp, vp, x, y, v, r;
  scanf("%d %d %d %d %d %d %d", &xp, &yp, &vp, &x, &y, &v, &r);
  double R = hypot(yp, xp);
  double initial = atan2(yp, xp);
  double bot = 0;
  double timeTot = (2 * M_PI * R) / vp;
  double top = 100000000000000.0;
  while (cmp(top, bot, EPS) == 1) {
    double mid = (top + bot) / 2;
    double angle = ((2 * M_PI * mid) / timeTot) + initial;
    point loc = (point) {cos(angle) * R, sin(angle) * R};
    if (pode(loc, mid)) {
      top = mid;
    } else {
      bot = mid;
    }
  }
  printf("%.7f\n", bot);
  return 0;
}
