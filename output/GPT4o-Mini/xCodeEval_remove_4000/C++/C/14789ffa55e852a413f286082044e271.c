#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef long long li;
typedef long double ld;

#define MAX_N 2007
#define INF (int)(1e9)
#define INF64 (li)(1e18)
#define MOD (INF + 7)
#define EPS 1e-9
#define PI acos(-1.0)

typedef struct {
    int x, y, i;
} point;

point a[MAX_N];
char s[MAX_N];
int n;

li sqr(li x) {
    return x * x;
}

li dot(point a, point b) {
    return a.x * (li)b.x + a.y * (li)b.y;
}

li cross(point a, point b) {
    return a.x * (li)b.y - a.y * (li)b.x;
}

point operator_minus(point a, point b) {
    return (point){a.x - b.x, a.y - b.y, -1};
}

point operator_plus(point a, point b) {
    return (point){a.x + b.x, a.y + b.y, -1};
}

int operator_equal(point a, point b) {
    return (a.x == b.x && a.y == b.y);
}

li sdist(point a, point b) {
    return sqr((li)(a.x - b.x)) + sqr((li)(a.y - b.y));
}

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].i = i + 1;
    }
    scanf("%s", s);
}

void build(point* res, int* res_size) {
    if (n <= 1) {
        for (int i = 0; i < n; i++) {
            res[i] = a[i];
        }
        *res_size = n;
        return;
    }

    point up[MAX_N], dw[MAX_N];
    int up_size = 0, dw_size = 0;

    up[up_size++] = a[0];
    dw[dw_size++] = a[0];

    for (int i = 1; i < n; i++) {
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

    for (int i = 0; i < up_size; i++) {
        res[i] = up[i];
    }
    for (int i = dw_size - 2; i >= 1; i--) {
        res[up_size++] = dw[i];
    }
    *res_size = up_size;
}

void solve() {
    point cur[MAX_N];
    int cur_size = n;
    for (int i = 0; i < n; i++) {
        cur[i] = a[i];
    }

    point ans[MAX_N];
    int ans_size = 0;

    point ch[MAX_N];
    int ch_size;
    build(ch, &ch_size);
    ans[ans_size++] = ch[0];
    if (s[0] == 'L') {
        ans[ans_size++] = ch[ch_size - 1];
    } else {
        ans[ans_size++] = ch[1];
    }

    cur_size--;
    for (int i = 0; i < cur_size; i++) {
        if (operator_equal(cur[i], ans[0])) {
            for (int j = i; j < cur_size - 1; j++) {
                cur[j] = cur[j + 1];
            }
            cur_size--;
            break;
        }
    }

    for (int i = 0; i < strlen(s) - 1; i++) {
        n = 0;
        for (int j = 0; j < cur_size; j++) {
            a[n++] = cur[j];
        }
        build(ch, &ch_size);
        int pos = -1;
        for (int j = 0; j < ch_size; j++) {
            if (operator_equal(ch[j], ans[ans_size - 1])) {
                pos = j;
                break;
            }
        }
        if (s[i + 1] == 'L') {
            ans[ans_size++] = ch[(pos - 1 + ch_size) % ch_size];
        } else {
            ans[ans_size++] = ch[(pos + 1) % ch_size];
        }

        for (int j = 0; j < cur_size; j++) {
            if (operator_equal(cur[j], ans[ans_size - 2])) {
                for (int k = j; k < cur_size - 1; k++) {
                    cur[k] = cur[k + 1];
                }
                cur_size--;
                break;
            }
        }
    }

    for (int i = 0; i < ans_size; i++) {
        printf("%d ", ans[i].i);
    }
    puts("");
}

int main() {
    freopen("input.txt", "r", stdin);
    clock_t tt = clock();

    while (1) {
        read();
        if (n == 0) break;
        solve();
        fprintf(stderr, "TIME = %ld\n", clock() - tt);
        tt = clock();
    }
    return 0;
}
