#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef long long li;
typedef struct {
    int x, y, i;
} point;

int n;
point a[2007];
char s[2007];

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
    return (li)(a.x - b.x) * (a.x - b.x) + (li)(a.y - b.y) * (a.y - b.y);
}

li dot(point a, point b) {
    return a.x * (li)b.x + a.y * (li)b.y;
}

li cross(point a, point b) {
    return a.x * (li)b.y - a.y * (li)b.x;
}

point* build(int* size) {
    if (n <= 1) {
        *size = n;
        return a;
    }

    point up[2007], dw[2007];
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

    point ans[2007];
    int ans_size = 0;

    int size;
    point* ch = build(&size);
    ans[ans_size++] = ch[0];
    if (s[0] == 'L')
        ans[ans_size++] = ch[size - 1];
    else
        ans[ans_size++] = ch[1];

    for (int i = 0; i < strlen(s); i++) {
        int x = -1;
        for (int j = 0; j < n; j++) {
            if (operator_equal(a[j], ans[ans_size - 2])) {
                x = j;
                break;
            }
        }
        for (int j = x + 1; j < n; j++)
            a[j - 1] = a[j];
        n--;

        ch = build(&size);
        int pos = -1;
        for (int j = 0; j < size; j++) {
            if (operator_equal(ch[j], ans[ans_size - 1])) {
                pos = j;
                break;
            }
        }
        if (s[i + 1] == 'L')
            ans[ans_size++] = ch[(pos - 1 + size) % size];
        else
            ans[ans_size++] = ch[(pos + 1) % size];
    }

    for (int i = 0; i < ans_size; i++)
        printf("%d ", ans[i].i);
    puts("");
}

int main() {
    freopen("input.txt", "r", stdin);

    while (read()) {
        solve();
    }

    return 0;
}
