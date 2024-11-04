#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    int x;
    int y;
    int r;
} Circle;

typedef struct {
    long k;
    long b;
} Line;

typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
} Rect;

typedef struct {
    long x;
    long y;
} Point;

long mod = 1000000007;

long pow(long x, long p, long mod) {
    if (p <= 0) {
        return 1;
    }
    long th = pow(x, p / 2, mod);
    th *= th;
    th %= mod;
    if (p % 2 == 1) {
        th *= x;
    }
    return th;
}

typedef struct {
    long x;
    long y;
} Fraction;

Fraction createFraction(long x, long y) {
    Fraction f;
    f.x = x;
    f.y = y;
    return f;
}

void norm(Fraction *f) {
    long gcd = gcd(f->x, f->y);
    f->x /= gcd;
    f->y /= gcd;
}

int compareFractions(Fraction *f1, Fraction *f2) {
    if (f1->x > f2->x) {
        return 1;
    }
    if (f1->x < f2->x) {
        return -1;
    }
    if (f1->y > f2->y) {
        return 1;
    }
    if (f1->y < f2->y) {
        return -1;
    }
    return 0;
}

Fraction sum(Fraction *a, Fraction *b) {
    Fraction c;
    c.x = a->x * b->y + a->y * b->x;
    c.y = a->y * b->y;
    norm(&c);
    return c;
}

long gcd(long x, long y) {
    if (y == 0) {
        return x;
    }
    if (x == 0) {
        return y;
    }
    return gcd(y, x % y);
}

typedef struct {
    int x;
    int y;
} Pair;

Pair createPair(int x, int y) {
    Pair p;
    p.x = x;
    p.y = y;
    return p;
}

Pair clonePair(Pair *p) {
    Pair clone;
    clone.x = p->x;
    clone.y = p->y;
    return clone;
}

int comparePairs(Pair *p1, Pair *p2) {
    if (p1->x > p2->x) {
        return 1;
    }
    if (p1->x < p2->x) {
        return -1;
    }
    if (p1->y > p2->y) {
        return 1;
    }
    if (p1->y < p2->y) {
        return -1;
    }
    return 0;
}

typedef struct {
    int pow;
    long *max;
    long *delta;
    bool *flag;
} id3;

id3 createId3(int n) {
    id3 id;
    id.pow = 1;
    while (id.pow < n) {
        id.pow *= 2;
    }
    id.flag = (bool *)malloc(sizeof(bool) * (2 * id.pow));
    id.max = (long *)malloc(sizeof(long) * (2 * id.pow));
    id.delta = (long *)malloc(sizeof(long) * (2 * id.pow));
    for (int i = 0; i < 2 * id.pow; i++) {
        id.max[i] = LONG_MIN / 2;
    }
    return id;
}

void add(id3 *id, int v, int l, int r, Line *line) {
    if (id->max[v] == NULL) {
        id->max[v] = *line;
        return;
    }
    if (v >= id->pow) {
        if (v % 2 == 0) {
            if (line->k * l + line->b > id->max[v].k * l + id->max[v].b) {
                id->max[v] = *line;
            }
        } else {
            if (line->k * r + line->b > id->max[v].k * r + id->max[v].b) {
                id->max[v] = *line;
            }
        }
        return;
    }
    int m = (l + r) / 2;
    if (line->k * m + line->b > id->max[v].k * m + id->max[v].b) {
        Line c = *line;
        *line = id->max[v];
        id->max[v] = c;
    }
    if (line->k * l + line->b > id->max[v].k * l + id->max[v].b) {
        add(id, 2 * v, l, m, line);
    }
    if (line->k * r + line->b > id->max[v].k * r + id->max[v].b) {
        add(id, 2 * v + 1, m, r, line);
    }
}

long get(id3 *id, int v, int l, int r, int x) {
    if (id->max[v] == NULL) {
        return id->neutral;
    }
    if (v >= id->pow) {
        return id->max[v].k * x + id->max[v].b;
    }
    long ans = id->max[v].k * x + id->max[v].b;
    int m = (l + r) / 2;
    if (x <= m) {
        ans = function(ans, get(id, 2 * v, l, m, x));
    }
    if (x >= m) {
        ans = function(ans, get(id, 2 * v + 1, m, r, x));
    }
    return ans;
}

long get(id3 *id, int x) {
    return get(id, 1, 0, id->pow, x);
}

typedef struct {
    long x;
    long y;
} id6;

id6 createId6(int n) {
    id6 id;
    id.sum = (long *)malloc(sizeof(long) * n);
    return id;
}

void add(id6 *id, int x, long d) {
    for (int i = x; i < sizeof(id->sum) / sizeof(id->sum[0]); i = (i | (i + 1))) {
        id->sum[i] += d;
    }
}

long sum(id6 *id, int r) {
    long ans = 0;
    for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
        ans += id->sum[i];
    }
    return ans;
}

long sum(id6 *id, int l, int r) {
    if (l > r) {
        return 0;
    }
    return sum(id, r) - sum(id, l - 1);
}

typedef struct {
    int *div;
    int *primes;
} id5;

id5 createId5(int max) {
    id5 id;
    id.div = (int *)malloc(sizeof(int) * (max + 1));
    id.primes = (int *)malloc(sizeof(int) * (max + 1));
    for (int i = 2; i < sizeof(id.div) / sizeof(id.div[0]); i++) {
        if (id.div[i] == 0) {
            id.div[i] = i;
            id.primes[i] = i;
        }
        for (int j = 0; j < sizeof(id.primes) / sizeof(id.primes[0]); j++) {
            if (i * id.primes[j] > max) {
                break;
            }
            id.div[i * id.primes[j]] = id.primes[j];
        }
    }
    return id;
}

int *factorization(id5 *id, int x) {
    int *ans = (int *)malloc(sizeof(int) * x);
    int iter = 0;
    while (id->div[x] > 0) {
        ans[iter++] = id->div[x];
        x /= id->div[x];
    }
    return ans;
}

int *id1(id5 *id, int x) {
    int *div = factorization(id, x);
    int len = sizeof(div) / sizeof(div[0]);
    int *ans = (int *)malloc(sizeof(int) * len);
    int iter = 0;
    for (int mask = 0; mask < (1 << len); mask++) {
        int th = 1;
        for (int i = 0; i < len; i++) {
            if ((mask & (1 << i)) > 0) {
                th *= div[i];
            }
        }
        ans[iter++] = th;
    }
    return ans;
}

int *id0(id5 *id, int x) {
    int *div = factorization(id, x);
    int pr = 0;
    for (int i = 0; i < sizeof(div) / sizeof(div[0]); i++) {
        if (i == 0 || div[i] != div[i - 1]) {
            pr++;
        }
    }
    int *primes = (int *)malloc(sizeof(int) * pr);
    int *sz = (int *)malloc(sizeof(int) * pr);
    pr = -1;
    for (int i = 0; i < sizeof(div) / sizeof(div[0]); i++) {
        if (i == 0 || div[i] != div[i - 1]) {
            pr++;
            primes[pr] = div[i];
            sz[pr] = 1;
        } else {
            sz[pr]++;
        }
    }
    pr++;
    int **pow = (int **)malloc(sizeof(int *) * pr);
    for (int i = 0; i < sizeof(pow) / sizeof(pow[0]); i++) {
        pow[i] = (int *)malloc(sizeof(int) * (sz[i] + 1));
        pow[i][0] = 1;
        for (int j = 1; j < sizeof(pow[i]) / sizeof(pow[i][0]); j++) {
            pow[i][j] = pow[i][j - 1] * primes[i];
        }
    }
    int *th = (int *)malloc(sizeof(int) * pr);
    int *ans = (int *)malloc(sizeof(int) * pr);
    for (int i = 0; i < sizeof(th) / sizeof(th[0]); i++) {
        th[i] = 0;
    }
    int *answer = (int *)malloc(sizeof(int) * pr);
    int iter = 0;
    do {
        int z = 1;
        for (int i = 0; i < sizeof(th) / sizeof(th[0]); i++) {
            z *= pow[i][th[i]];
        }
        answer[iter++] = z;
    } while (next(th, sz));
    return answer;
}

bool next(int *th, int *max) {
    for (int i = sizeof(th) / sizeof(th[0]) - 1; i >= 0; i--) {
        if (th[i] != max[i]) {
            th[i]++;
            for (int j = i + 1; j < sizeof(max) / sizeof(max[0]); j++) {
                th[j] = 0;
            }
            return true;
        }
    }
    return false;
}

char *id2(id5 *id, int x) {
    if (x == 1) {
        return "1 = 1";
    }
    int *list = factorization(id, x);
    char *ans = (char *)malloc(sizeof(char) * 100);
    sprintf(ans, "%d = ", x);
    for (int i = 0; i < sizeof(list) / sizeof(list[0]); i++) {
        sprintf(ans, "%s%d", ans, list[i]);
        if (i < sizeof(list) / sizeof(list[0]) - 1) {
            sprintf(ans, "%s * ", ans);
        }
    }
    return ans;
}

int in(int min, int max, int x) {
    if (x == min || x == max) {
        return 1;
    }
    if (x > min && x < max) {
        return 2;
    }
    return 0;
}

int sum(int x, int y) {
    if (x + y >= mod) {
        return x + y - mod;
    }
    return x + y;
}

long mult(long x, long y) {
    return x * y % mod;
}

long div(long x, long y) {
    return x * modInv(y) % mod;
}

bool inside(Circle *small, Circle *big) {
    return (small->x - big->x) * (small->x - big->x) + (small->y - big->y) * (small->y - big->y) <= (big->r - small->r) * (big->r - small->r);
}

double *tangent(Circle *c1, Circle *c2) {
    Circle a = *c1;
    Circle b = *c2;
    int minr = fmin(a.r, b.r);
    a.r -= minr;
    b.r -= minr;
    b.x -= a.x;
    b.y -= a.y;
    double a0 = atan2(b.y, b.x);
    double len = sqrt(b.x * b.x + b.y * b.y);
    double da = 0;
    if (a.r == 0) {
        da = asin(b.r / len) + M_PI / 2;
    } else {
        da = acos(a.r / len);
    }
    double *ans = (double *)malloc(sizeof(double) * 2);
    ans[0] = a0 - da;
    ans[1] = a0 + da;
    return ans;
}

double *norm(double *ans) {
    for (int i = 0; i < sizeof(ans) / sizeof(ans[0]); i++) {
        while (ans[i] < 0) {
            ans[i] += 2 * M_PI;
        }
        while (ans[i] > 2 * M_PI) {
            ans[i] -= 2 * M_PI;
        }
    }
    if (ans[0] > ans[1]) {
        double *answer = (double *)malloc(sizeof(double) * 4);
        answer[0] = 0;
        answer[1] = ans[1];
        answer[2] = ans[0];
        answer[3] = 2 * M_PI;
        return answer;
    }
    return ans;
}

bool mergeSort(char *s, int *a, int l, int r) {
    if (r - l <= 1) {
        return true;
    }
    int m = (l + r) >> 1;
    if (!mergeSort(s, a, l, m)) {
        return false;
    }
    if (!mergeSort(s, a, m, r)) {
        return false;
    }
    int i = l;
    int j = m;
    int k = l;
    while (i < m && j < r) {
        if (x == sizeof(s) / sizeof(s[0])) {
            return false;
        }
        if (s[x++] == '0') {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    while (i < m) {
        b[k++] = a[i++];
    }
    while (j < r) {
        b[k++] = a[j++];
    }
    for (int p = l; p < r; p++) {
        a[p] = b[p];
    }
    return true;
}

int *rev(int *a, int size) {
    int *res = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; ++i) {
        res[a[i]] = i;
    }
    return res;
}

void solve() {
    char *s = (char *)malloc(sizeof(char) * 100);
    scanf("%s", s);
    int l = 0;
    int r = 100001;
    while (1) {
        int sz = (l + r) >> 1;
        int *a = (int *)malloc(sizeof(int) * sz);
        for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
            a[i] = i;
        }
        x = 0;
        b = (int *)malloc(sizeof(int) * sz);
        if (!mergeSort(s, a, 0, sz)) {
            r = sz;
            continue;
        }
        if (x < sizeof(s) / sizeof(s[0])) {
            l = sz;
            continue;
        }
        a = rev(a, sz);
        printf("%d\n", sz);
        for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
            printf("%d ", a[i] + 1);
        }
        return;
    }
}

int main() {
    solve();
    return 0;
}
