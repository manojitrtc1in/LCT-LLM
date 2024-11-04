#include <stdio.h>
#include <math.h>

#define EPS 1e-8

typedef struct {
  double x, y;
} point;

double dist2(point p, point q) {
  return ((p.x - q.x) * (p.x - q.x)) + ((p.y - q.y) * (p.y - q.y));
}

int cmp(double x, double y, double tol) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int pode(point loc, double time, int xp, int yp, int vp, int x, int y, int v, int r) {
  point nave = {x, y};
  double distN = sqrt(dist2(nave, loc) - r * r);
  double distL = sqrt(dist2(loc, (point){0, 0}) - r * r);
  double id12 = fabs(atan(distN / r)) + fabs(atan(distL / r));
  double menor = distN + distL + fabs(r * id12);
  if (cmp(dist2(loc, (point){0, 0}), r * r) >= 0) {
    return cmp(time, sqrt(dist2(nave, loc)) / v) >= 0;
  } else {
    return cmp(time, menor / v) >= 0;
  }
}

int main() {
  int xp, yp, vp, x, y, v, r;
  scanf("%d %d %d %d %d %d %d", &xp, &yp, &vp, &x, &y, &v, &r);
  double R = hypot(yp, xp);
  double initial = atan2(yp, xp);
  double bot = 0;
  double timeTot = 1000000.0;
  double t1 = (2 * M_PI * R) / vp;
  double top = timeTot;
  while (top - bot > EPS) {
    double mid = (top + bot) / 2;
    double angle = ((2 * M_PI * mid) / t1) + initial;
    point loc = {cos(angle) * R, sin(angle) * R};
    if (pode(loc, mid, xp, yp, vp, x, y, v, r)) {
      top = mid - EPS;
    } else {
      bot = mid + EPS;
    }
  }
  printf("%.7f\n", bot);
  return 0;
}
