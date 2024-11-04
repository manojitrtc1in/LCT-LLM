#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define forn(i, n) for(int i = 0; i < n; i++)
#define fore(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define sz(x) (int)(x).size()
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
    return sqr((li)(a.x - b.x)) + sqr((li)(a.y - b.y));
}

li dot(point a, point b) {
    return (li)a.x * b.x + (li)a.y * b.y;
}

li cross(point a, point b) {
    return (li)a.x * b.y - (li)a.y * b.x;
}

int compare_points(const void* a, const void* b) {
    point* p1 = (point*)a;
    point* p2 = (point*)b;
    if (p1->x != p2->x) {
        return p1->x - p2->x;
    }
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

void print_vector(const char* name, point* v, int size) {
    printf("%s = [", name);
    forn(i, size) {
        if (i) {
            printf(", ");
        }
        print_point(v[i]);
    }
    printf("]\n");
}

point a[2007];
char s[2007];

void read() {
    int n;
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].i = i + 1;
    }
    scanf("%s", s);
}

point* build(int n) {
    if (n <= 1) {
        point* res = (point*)malloc(n * sizeof(point));
        forn(i, n) {
            res[i] = a[i];
        }
        return res;
    }
    
    point* up = (point*)malloc(n * sizeof(point));
    point* dw = (point*)malloc(n * sizeof(point));
    int up_size = 0;
    int dw_size = 0;
    
    up[up_size++] = a[0];
    dw[dw_size++] = a[0];
    
    fore(i, 1, n - 1) {
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
    
    point* res = (point*)malloc((up_size + dw_size - 2) * sizeof(point));
    int res_size = 0;
    forn(i, up_size) {
        res[res_size++] = up[i];
    }
    for (int i = dw_size - 2; i >= 1; i--) {
        res[res_size++] = dw[i];
    }
    
    free(up);
    free(dw);
    
    return res;
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
    
    point* ans = (point*)malloc(n * sizeof(point));
    int ans_size = 0;
    
    point* ch = build(n);
    ans[ans_size++] = ch[0];
    if (s[0] == 'L') {
        ans[ans_size++] = ch[sz(ch) - 1];
    } else {
        ans[ans_size++] = ch[1];
    }
    
    forn(i, sz(s)) {
        int x = -1;
        forn(j, n) {
            if (operator_equal(a[j], ans[ans_size - 2])) {
                x = j;
                break;
            }
        }
        fore(j, x + 1, n - 1) {
            a[j - 1] = a[j];
        }
        n--;
        
        free(ch);
        ch = build(n);
        
        int pos = -1;
        forn(j, sz(ch)) {
            if (operator_equal(ch[j], ans[ans_size - 1])) {
                pos = j;
                break;
            }
        }
        
        if (s[i + 1] == 'L') {
            ans[ans_size++] = ch[(pos - 1 + sz(ch)) % sz(ch)];
        } else {
            ans[ans_size++] = ch[(pos + 1) % sz(ch)];
        }
    }
    
    forn(i, ans_size) {
        printf("%d ", ans[i].i);
    }
    printf("\n");
    
    free(ans);
    free(ch);
}

int main() {
    read();
    solve();
    return 0;
}
