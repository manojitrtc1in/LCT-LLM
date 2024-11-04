#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INF (int)(1e9)
#define INF64 (long long)(1e18)
#define MOD (INF + 7)
#define EPS 1e-9
#define PI acos(-1.0)
#define N (2000 + 7)

typedef long long li;

typedef struct {
    int x, y, i;
} point;

int n;
point a[N];
char s[N];

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

point subtract(point a, point b) {
    return (point){a.x - b.x, a.y - b.y, -1};
}

point add(point a, point b) {
    return (point){a.x + b.x, a.y + b.y, -1};
}

int equal(point a, point b) {
    return (a.x == b.x && a.y == b.y);
}

li sdist(point a, point b) {
    return (li)(a.x - b.x) * (a.x - b.x) + (li)(a.y - b.y) * (a.y - b.y);
}

li dot(point a, point b) {
    return a.x * (li)b.x + a.y * (li)b.y;
}

li cross(point a, point b) {
    return a.x * (li)b.y - a.y * (li)b.x;
}

point* build(int* size) {
    static point up[N], dw[N];
    int up_size = 0, dw_size = 0;

    if (n <= 1) {
        *size = n;
        return a;
    }

    up[up_size++] = a[0];
    dw[dw_size++] = a[0];

    for (int i = 1; i < n; i++) {
        if (i == n - 1 || cross(subtract(a[n - 1], a[0]), subtract(a[i], a[0])) >= 0) {
            while (up_size > 1 && cross(subtract(a[i], up[up_size - 2]), subtract(up[up_size - 1], up[up_size - 2])) < 0)
                up_size--;
            up[up_size++] = a[i];
        }
        if (i == n - 1 || cross(subtract(a[n - 1], a[0]), subtract(a[i], a[0])) < 0) {
            while (dw_size > 1 && cross(subtract(a[i], dw[dw_size - 2]), subtract(dw[dw_size - 1], dw[dw_size - 2])) > 0)
                dw_size--;
            dw[dw_size++] = a[i];
        }
    }

    point* res = malloc((up_size + dw_size - 2) * sizeof(point));
    memcpy(res, up, up_size * sizeof(point));
    for (int i = dw_size - 2; i >= 1; --i)
        res[up_size++] = dw[i];

    *size = up_size;
    return res;
}

void solve() {
    qsort(a, n, sizeof(point), [](const void* a, const void* b) {
        point* p1 = (point*)a;
        point* p2 = (point*)b;
        if (p1->x != p2->x)
            return p1->x - p2->x;
        return p1->y - p2->y;
    });

    point ans[N];
    int ans_size = 0;

    int ch_size;
    point* ch = build(&ch_size);
    ans[ans_size++] = ch[0];
    if (s[0] == 'L')
        ans[ans_size++] = ch[ch_size - 1];
    else
        ans[ans_size++] = ch[1];

    for (int i = 0; i < strlen(s); i++) {
        int x = (int)(find(a, a + n, ans[ans_size - 2]) - a);
        for (int j = x + 1; j < n; j++)
            a[j - 1] = a[j];
        n--;
        ch = build(&ch_size);
        int pos = (int)(find(ch, ch + ch_size, ans[ans_size - 1]) - ch);
        if (s[i + 1] == 'L')
            ans[ans_size++] = ch[(pos - 1 + ch_size) % ch_size];
        else
            ans[ans_size++] = ch[(pos + 1) % ch_size];
    }

    for (int i = 0; i < ans_size; i++)
        printf("%d ", ans[i].i);
    puts("");
}

int main() {
    while (read()) {
        solve();
    }
}
