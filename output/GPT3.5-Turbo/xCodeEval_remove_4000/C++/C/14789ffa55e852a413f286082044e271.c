#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define forn(i, n) for(int i=0; i<(n); i++)
#define fore(i, a, b) for(int i=(a); i<=(b); i++)
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long li;
typedef long double ld;

typedef struct {
    int x, y, i;
} point;

point make_point(int x, int y, int i) {
    point p;
    p.x = x;
    p.y = y;
    p.i = i;
    return p;
}

li sqr(li x) {
    return x * x;
}

li sdist(point a, point b) {
    return sqr(li(a.x - b.x)) + sqr(li(a.y - b.y));
}

li dot(point a, point b) {
    return a.x * li(b.x) + a.y * li(b.y);
}

li cross(point a, point b) {
    return a.x * li(b.y) - a.y * li(b.x);
}

int compare_points(const void* a, const void* b) {
    point* p1 = (point*)a;
    point* p2 = (point*)b;
    if (p1->x != p2->x)
        return p1->x - p2->x;
    return p1->y - p2->y;
}

point operator_minus(point a, point b) {
    return make_point(a.x - b.x, a.y - b.y, -1);
}

point operator_plus(point a, point b) {
    return make_point(a.x + b.x, a.y + b.y, -1);
}

int operator_equal(point a, point b) {
    return (a.x == b.x && a.y == b.y);
}

void print_point(point p) {
    printf("(%d, %d)", p.x, p.y);
}

void print_vector(point* v, int n) {
    printf("[");
    forn(i, n) {
        if (i) printf(", ");
        print_point(v[i]);
    }
    printf("]");
}

point a[2007];
char s[2007];

point build[2007];

void build_convex_hull(int n, point* a, int* m, point* ch) {
    if (n <= 1) {
        *m = n;
        forn(i, n) {
            ch[i] = a[i];
        }
        return;
    }

    point* up = ch;
    point* dw = ch + n;

    int up_size = 0;
    int dw_size = 0;

    up[up_size++] = a[0];
    dw[dw_size++] = a[0];

    fore(i, 1, n-1) {
        if (i == n - 1 || cross(operator_minus(a[n - 1], a[0]), operator_minus(a[i], a[0])) >= 0) {
            while (up_size > 1 && cross(operator_minus(a[i], up[up_size - 2]), operator_minus(up[up_size - 1], up[up_size - 2])) < 0) {
                up_size--;
            }
            up[up_size++] = a[i];
        }
        if (i == n - 1 || cross(operator_minus(a[n - 1], a[0]), operator_minus(a[i], a[0])) < 0) {
            while (dw_size > 1 && cross(operator_minus(a[i], dw[dw_size - 2]), operator_minus(dw[dw_size - 1], dw[dw_size - 2])) > 0) {
                dw_size--;
            }
            dw[dw_size++] = a[i];
        }
    }

    *m = up_size + dw_size - 2;
    int k = 0;
    for (int i = up_size - 1; i >= 1; i--) {
        ch[k++] = up[i];
    }
    forn(i, dw_size) {
        ch[k++] = dw[i];
    }
}

void solve() {
    int n;
    scanf("%d", &n);

    forn(i, n) {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].i = i + 1;
    }

    scanf("%s", s);

    qsort(a, n, sizeof(point), compare_points);

    point* cur = a;
    int cur_size = n;

    point* ans = build;
    int ans_size = 0;

    point* ch = build + n;

    build_convex_hull(cur_size, cur, &ans_size, ans);

    printf("%d ", ans[0].i);

    if (s[0] == 'L') {
        printf("%d ", ans[ans_size - 1].i);
    } else {
        printf("%d ", ans[1].i);
    }

    cur_size--;
    cur = ans + ans_size - 2;

    forn(i, n-1) {
        build_convex_hull(cur_size, cur, &ans_size, ans);

        int pos = -1;
        forn(j, ans_size) {
            if (operator_equal(ans[j], ans[ans_size - 1])) {
                pos = j;
                break;
            }
        }

        if (s[i + 1] == 'L') {
            cur = ans + (pos - 1 + ans_size) % ans_size;
        } else {
            cur = ans + (pos + 1) % ans_size;
        }

        printf("%d ", cur->i);

        cur_size--;
    }

    printf("\n");
}

int main() {
    freopen("input.txt", "r", stdin);

    int tt = clock();

    while (1) {
        if (!read()) {
            break;
        }

        solve();
    }

    return 0;
}
