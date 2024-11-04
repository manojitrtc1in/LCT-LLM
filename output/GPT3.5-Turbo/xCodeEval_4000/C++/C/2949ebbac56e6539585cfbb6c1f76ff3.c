#include <stdio.h>
#include <math.h>

#define INF 1e10
#define EPS 1e-8

typedef double DB;

typedef struct PT {
    DB x, y;
} PT;

PT PT_create(DB x, DB y) {
    PT p;
    p.x = x;
    p.y = y;
    return p;
}

PT PT_add(PT p1, PT p2) {
    PT p;
    p.x = p1.x + p2.x;
    p.y = p1.y + p2.y;
    return p;
}

PT PT_sub(PT p1, PT p2) {
    PT p;
    p.x = p1.x - p2.x;
    p.y = p1.y - p2.y;
    return p;
}

PT PT_mul(PT p, DB c) {
    PT res;
    res.x = p.x * c;
    res.y = p.y * c;
    return res;
}

PT PT_div(PT p, DB c) {
    PT res;
    res.x = p.x / c;
    res.y = p.y / c;
    return res;
}

DB PT_dis(PT p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

DB PT_dis2(PT p) {
    return p.x * p.x + p.y * p.y;
}

DB PT_vect(PT v1, PT v2) {
    return v1.x * v2.y - v2.x * v1.y;
}

DB PT_scal(PT v1, PT v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

int sgn(DB v) {
    return v < -EPS ? -1 : v > EPS;
}

int sect(PT p) {
    if (sgn(p.x) == 0 && sgn(p.y) == 0) return 0;
    if (sgn(p.x) == 0) return sgn(p.y) > 0 ? 2 : 4;
    if (sgn(p.y) == 0) return sgn(p.x) > 0 ? 1 : 3;
    if (sgn(p.x) == 1) return sgn(p.y) == 1 ? 1 : 4;
    return sgn(p.y) == 1 ? 2 : 3;
}

DB dis(const PT v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

DB dis2(const PT v) {
    return v.x * v.x + v.y * v.y;
}

DB dis(const PT p1, const PT p2) {
    return dis(PT_sub(p1, p2));
}

DB dis2(const PT p1, const PT p2) {
    return dis2(PT_sub(p1, p2));
}

PT proj(const PT p, const PT p1, const PT p2) {
    return PT_add(p1, PT_mul(PT_sub(p, p1), PT_scal(PT_sub(p1, p), PT_sub(p2, p1)) / dis2(p1, p2)));
}

PT normalLine(const PT p1, const PT p2) {
    return PT_create(-(p2.y - p1.y), p2.x - p1.x);
}

int main() {
    int n;
    scanf("%d", &n);
    PT p[n];
    for (int i = 0; i < n; ++i) {
        scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    PT g = PT_create(0, 0);
    for (int i = 0; i < n; ++i) {
        g = PT_add(g, p[i]);
    }
    g = PT_div(g, n);
    for (int i = 0; i < n; ++i) {
        p[i] = PT_sub(p[i], g);
    }
    PT q;
    for (int i = 0; i < n; ++i) {
        int fp = -1;
        for (int j = 0; j < n; ++j) {
            if (p[j].x == -p[i].x && p[j].y == -p[i].y) {
                fp = j;
                break;
            }
        }
        if (fp == -1) {
            q = p[i];
            break;
        }
        if (i == n - 1) {
            printf("-1\n");
            return 0;
        }
    }
    PT v[n];
    int v_size = 0;
    for (int i = 0; i < n; ++i) {
        PT m = PT_div(PT_add(p[i], q), 2);
        PT nv = normalLine(PT_create(0, 0), m);
        if (sect(nv) >= 3) {
            nv = PT_mul(nv, -1);
        }
        int found = 0;
        for (int j = 0; j < v_size; ++j) {
            if (sect(v[j]) == sect(nv) && PT_vect(v[j], nv) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            v[v_size++] = nv;
        }
    }
    int ans = 0;
    for (int i = 0; i < v_size; ++i) {
        DB d[n];
        for (int j = 0; j < n; ++j) {
            d[j] = PT_scal(v[i], proj(p[j], PT_create(0, 0), v[i])) / dis(v[i]);
        }
        for (int j = 0; j < n / 2; ++j) {
            if (sgn(d[j] + d[n - 1 - j])) {
                ans = 0;
                break;
            }
        }
        ans += 1;
    }
    printf("%d\n", ans);
    return 0;
}
