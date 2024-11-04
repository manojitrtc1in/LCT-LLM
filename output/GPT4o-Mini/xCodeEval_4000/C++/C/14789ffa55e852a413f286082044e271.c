#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 2007
#define INF 1000000000
#define EPS 1e-9

typedef long long li;

typedef struct {
    int x, y, i;
} point;

point a[MAX_N];
char s[MAX_N];
int n;

int cmp(const void *p1, const void *p2) {
    point *a = (point *)p1;
    point *b = (point *)p2;
    if (a->x != b->x)
        return a->x - b->x;
    return a->y - b->y;
}

li sqr(li a) {
    return a * a;
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

li dot(point a, point b) {
    return a.x * (li)b.x + a.y * (li)b.y;
}

li cross(point a, point b) {
    return a.x * (li)b.y - a.y * (li)b.x;
}

point *build(int *size) {
    if (n <= 1) {
        *size = n;
        return a;
    }

    point up[MAX_N], dw[MAX_N];
    int up_size = 0, dw_size = 0;

    up[up_size++] = a[0];
    dw[dw_size++] = a[0];

    for (int i = 1; i < n; i++) {
        if (i == n - 1 || cross(operator_minus(a[n - 1], a[0]), operator_minus(a[i], a[0])) >= 0) {
            while (up_size > 1 && cross(operator_minus(a[i], up[up_size - 2]), operator_minus(up[up_size - 1], up[up_size - 2])) < 0)
                up_size--;
            up[up_size++] = a[i];
        }
        if (i == n - 1 || cross(operator_minus(a[n - 1], a[0]), operator_minus(a[i], a[0])) < 0) {
            while (dw_size > 1 && cross(operator_minus(a[i], dw[dw_size - 2]), operator_minus(dw[dw_size - 1], dw[dw_size - 2])) > 0)
                dw_size--;
            dw[dw_size++] = a[i];
        }
    }

    static point res[MAX_N];
    int res_size = 0;
    for (int i = 0; i < up_size; i++)
        res[res_size++] = up[i];
    for (int i = dw_size - 2; i >= 1; i--)
        res[res_size++] = dw[i];

    *size = res_size;
    return res;
}

void solve() {
    qsort(a, n, sizeof(point), cmp);
    point cur[MAX_N];
    int cur_size = n;
    memcpy(cur, a, sizeof(point) * n);
    point ans[MAX_N];
    int ans_size = 0;

    int ch_size;
    point *ch = build(&ch_size);
    ans[ans_size++] = ch[0];
    if (s[0] == 'L')
        ans[ans_size++] = ch[ch_size - 1];
    else
        ans[ans_size++] = ch[1];
    
    for (int i = 0; i < cur_size; i++) {
        if (operator_equal(cur[i], ans[0])) {
            cur[i] = cur[cur_size - 1];
            cur_size--;
            break;
        }
    }

    for (int i = 0; i < strlen(s); i++) {
        n = 0;
        for (int j = 0; j < cur_size; j++)
            a[n++] = cur[j];
        int ch_size;
        point *ch = build(&ch_size);
        int pos = 0;
        for (int j = 0; j < ch_size; j++) {
            if (operator_equal(ch[j], ans[ans_size - 1])) {
                pos = j;
                break;
            }
        }
        if (s[i + 1] == 'L')
            ans[ans_size++] = ch[(pos - 1 + ch_size) % ch_size];
        else
            ans[ans_size++] = ch[(pos + 1) % ch_size];
        
        for (int j = 0; j < cur_size; j++) {
            if (operator_equal(cur[j], ans[ans_size - 2])) {
                cur[j] = cur[cur_size - 1];
                cur_size--;
                break;
            }
        }
    }

    for (int i = 0; i < ans_size; i++)
        printf("%d ", ans[i].i);
    puts("");
}

int read() {
    if (scanf("%d", &n) != 1)
        return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].i = i + 1;
    }
    scanf("%s", s);
    return 1;
}

int main() {
    while (read()) {
        solve();
    }
    return 0;
}
