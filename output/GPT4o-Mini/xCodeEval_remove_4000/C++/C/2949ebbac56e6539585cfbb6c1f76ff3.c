#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef double DB;
const DB PI = acos(-1);
const DB INF = 1e10;
const DB EPS = 1e-8;

inline DB sqr(const DB v) { return v * v; }
inline int sgn(const DB v) { return v < -EPS ? -1 : v > EPS; }

typedef struct {
    DB x, y;
} PT;

PT create_PT(DB x, DB y) {
    PT p;
    p.x = x;
    p.y = y;
    return p;
}

PT add_PT(const PT a, const PT b) { return create_PT(a.x + b.x, a.y + b.y); }
PT sub_PT(const PT a, const PT b) { return create_PT(a.x - b.x, a.y - b.y); }
PT neg_PT(const PT p) { return create_PT(-p.x, -p.y); }
PT mul_PT(const PT p, const DB c) { return create_PT(p.x * c, p.y * c); }
PT div_PT(const PT p, const DB c) { return create_PT(p.x / c, p.y / c); }

int less_PT(const PT a, const PT b) {
    int cmp = sgn(a.x - b.x);
    return cmp ? cmp < 0 : sgn(a.y - b.y) < 0;
}

int eq_PT(const PT a, const PT b) { return !sgn(a.x - b.x) && !sgn(a.y - b.y); }
int neq_PT(const PT a, const PT b) { return sgn(a.x - b.x) || sgn(a.y - b.y); }

DB dis(const PT v) { return sqrt(sqr(v.x) + sqr(v.y)); }
DB dis2(const PT v) { return sqr(v.x) + sqr(v.y); }
DB dis_pts(const PT p1, const PT p2) { return dis(sub_PT(p1, p2)); }
DB dis2_pts(const PT p1, const PT p2) { return dis2(sub_PT(p1, p2)); }

DB vect(const PT v1, const PT v2) { return v1.x * v2.y - v2.x * v1.y; }
DB scal(const PT v1, const PT v2) { return v1.x * v2.x + v1.y * v2.y; }

int sect(const PT p) {
    if (sgn(p.x) == 0 && sgn(p.y) == 0) return 0;
    if (sgn(p.x) == 0) return sgn(p.y) > 0 ? 2 : 4;
    if (sgn(p.y) == 0) return sgn(p.x) > 0 ? 1 : 3;
    if (sgn(p.x) == 1) return sgn(p.y) == 1 ? 1 : 4;
    return sgn(p.y) == 1 ? 2 : 3;
}

DB ang(const PT v) { return atan2(v.y, v.x); }
DB ang_pts(const PT p1, const PT p2) { return ang(sub_PT(p2, p1)); }

PT proj(const PT p, const PT p1, const PT p2) {
    return add_PT(p1, mul_PT(sub_PT(p2, p1), scal(p1, p, p2) / dis2_pts(p1, p2)));
}

PT normalLine(const PT p1, const PT p2) { return create_PT(-(p2.y - p1.y), p2.x - p1.x); }

DB id2(const PT p, const PT p1, const PT p2) { return fabs(vect(p, p1, p2)) / dis(p1, p2); }

int id0(const PT p1, const PT p2, const PT p3, const PT p4, PT *p) {
    DB s1 = vect(p1, p2, p3), s2 = vect(p1, p2, p4);
    if (!sgn(s1 - s2)) return sgn(s1) ? 0 : 2;
    *p = sub_PT(p3, mul_PT(sub_PT(p4, p3), s1 / (s2 - s1)));
    return 1;
}

int inPolygon(const PT p, PT q[], int n) {
    int c = 0;
    PT r = create_PT(INF, INF * sqrt(3)), t;
    for (int i = 0; i < n; ++i) {
        if (onLine(p, q[i], q[(i + 1) % n])) return 2;
        if (id0(p, r, q[i], q[(i + 1) % n], &t) == 1) ++c;
    }
    return c % 2;
}

int main() {
    int n;
    scanf("%d", &n);
    PT p[n];
    for (int i = 0; i < n; ++i) scanf("%lf%lf", &p[i].x, &p[i].y);
    
    PT g = gravityCenter(p, n);
    for (int i = 0; i < n; ++i) p[i] = sub_PT(p[i], g);
    
    PT q;
    for (int i = 0; i < n; ++i) {
        int fp = lower_bound(p, p + n, neg_PT(p[i])) - p;
        if (p[fp] != neg_PT(p[i])) {
            q = p[i];
            break;
        }
        if (i == n - 1) {
            printf("-1\n");
            return 0;
        }
    }
    
    // Additional logic for handling the rest of the algorithm...
    
    return 0;
}
