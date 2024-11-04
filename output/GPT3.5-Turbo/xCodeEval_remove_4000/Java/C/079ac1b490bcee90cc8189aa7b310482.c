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
    bool branchUp;
    long neutral;
    int pow;
    Line* ch;
} id4;

typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
} Rect;

typedef struct {
    double angle;
    int type;
} Point;

typedef struct {
    long x;
    long y;
} Pair;

typedef struct {
    long x;
    long y;
} Fraction;

typedef struct {
    int x;
    int y;
} Pair;

typedef struct {
    int* div;
    int* primes;
} id5;

typedef struct {
    long* sum;
} id6;

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

Fraction createFraction(long x, long y) {
    Fraction fraction;
    fraction.x = x;
    fraction.y = y;
    return fraction;
}

void norm(Fraction* fraction) {
    long gcd = gcd(fraction->x, fraction->y);
    fraction->x /= gcd;
    fraction->y /= gcd;
}

int compareFractions(Fraction* a, Fraction* b) {
    if (a->x > b->x) {
        return 1;
    }
    if (a->x < b->x) {
        return -1;
    }
    if (a->y > b->y) {
        return 1;
    }
    if (a->y < b->y) {
        return -1;
    }
    return 0;
}

Fraction sum(Fraction* a, Fraction* b) {
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

Pair createPair(int x, int y) {
    Pair pair;
    pair.x = x;
    pair.y = y;
    return pair;
}

Pair clonePair(Pair* p) {
    Pair pair;
    pair.x = p->x;
    pair.y = p->y;
    return pair;
}

int comparePairs(Pair* a, Pair* b) {
    if (a->x > b->x) {
        return 1;
    }
    if (a->x < b->x) {
        return -1;
    }
    if (a->y > b->y) {
        return 1;
    }
    if (a->y < b->y) {
        return -1;
    }
    return 0;
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

int modInv(long x) {
    return pow(x, mod - 2);
}

int compareCircles(Circle* c1, Circle* c2) {
    if (c1->r != c2->r) {
        return c1->r - c2->r;
    }
    if (c1->x != c2->x) {
        return c1->x - c2->x;
    }
    return c1->y - c2->y;
}

bool inside(Circle* small, Circle* big) {
    return (small->x - big->x) * (small->x - big->x) + (small->y - big->y) * (small->y - big->y) <= (big->r - small->r) * (big->r - small->r);
}

double* tangent(Circle* c1, Circle* c2) {
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
    double* ans = malloc(2 * sizeof(double));
    ans[0] = a0 - da;
    ans[1] = a0 + da;
    return ans;
}

double* normAngles(double* ans) {
    for (int i = 0; i < 2; i++) {
        while (ans[i] < 0) {
            ans[i] += 2 * M_PI;
        }
        while (ans[i] > 2 * M_PI) {
            ans[i] -= 2 * M_PI;
        }
    }
    if (ans[0] > ans[1]) {
        double* answer = malloc(4 * sizeof(double));
        answer[0] = 0;
        answer[1] = ans[1];
        answer[2] = ans[0];
        answer[3] = 2 * M_PI;
        return answer;
    }
    return ans;
}

int comparePoints(Point* a, Point* b) {
    if (a->angle > b->angle) {
        return 1;
    }
    if (a->angle < b->angle) {
        return -1;
    }
    return a->type - b->type;
}

int compareRects(Rect* r1, Rect* r2) {
    if (r1->x1 != r2->x1) {
        return r1->x1 - r2->x1;
    }
    if (r1->y1 != r2->y1) {
        return r1->y1 - r2->y1;
    }
    if (r1->x2 != r2->x2) {
        return r1->x2 - r2->x2;
    }
    return r1->y2 - r2->y2;
}

int compareLines(Line* a, Line* b) {
    if (a->k != b->k) {
        return a->k - b->k;
    }
    return a->b - b->b;
}

id6 createId6(int n) {
    id6 id;
    id.sum = malloc(n * sizeof(long));
    return id;
}

void add(id6* id, int x, long d) {
    for (int i = x; i < id->sum.length; i = (i | (i + 1))) {
        id->sum[i] += d;
    }
}

long sum(id6* id, int r) {
    long ans = 0;
    for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
        ans += id->sum[i];
    }
    return ans;
}

long sum(id6* id, int l, int r) {
    if (l > r) {
        return 0;
    }
    return sum(id, r) - sum(id, l - 1);
}

id3 createId3(int n) {
    id3 id;
    id.pow = 1;
    while (id.pow < n) {
        id.pow *= 2;
    }
    id.flag = malloc(2 * id.pow * sizeof(bool));
    id.max = malloc(2 * id.pow * sizeof(long));
    id.delta = malloc(2 * id.pow * sizeof(long));
    for (int i = 0; i < 2 * id.pow; i++) {
        id.max[i] = LONG_MIN / 2;
    }
    return id;
}

id3 createId3(long* a) {
    id3 id = createId3(sizeof(a) / sizeof(a[0]));
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        id.max[id.pow + i] = a[i];
    }
    for (int i = id.pow - 1; i > 0; i--) {
        id.max[i] = f(id.max[2 * i], id.max[2 * i + 1]);
    }
    return id;
}

void set(id3* id, int v, int tl, int tr, int l, int r, long x) {
    push(id, v, tl, tr);
    if (l > tr || r < tl) {
        return;
    }
    if (l <= tl && r >= tr) {
        id->delta[v] += x;
        id->flag[v] = true;
        push(id, v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    set(id, 2 * v, tl, tm, l, r, x);
    set(id, 2 * v + 1, tm + 1, tr, l, r, x);
    id->max[v] = f(id->max[2 * v], id->max[2 * v + 1]);
}

void push(id3* id, int v, int tl, int tr) {
    if (id->flag[v]) {
        if (v < id->pow) {
            id->flag[2 * v] = true;
            id->flag[2 * v + 1] = true;
            id->delta[2 * v] += id->delta[v];
            id->delta[2 * v + 1] += id->delta[v];
        }
        id->flag[v] = false;
        id->max[v] += id->delta[v];
        id->delta[v] = 0;
    }
}

long get(id3* id, int v, int tl, int tr, int x) {
    if (id->max[v] == NULL) {
        return id->neutral;
    }
    if (v >= id->pow) {
        return id->max[v];
    }
    long ans = id->max[v];
    int m = (tl + tr) / 2;
    if (x <= m) {
        ans = f(ans, get(id, 2 * v, tl, m, x));
    }
    if (x >= m) {
        ans = f(ans, get(id, 2 * v + 1, m, tr, x));
    }
    return ans;
}

long get(id3* id, int x) {
    return get(id, 1, 0, id->pow, x);
}

id4 createId4(int n, bool branchUp) {
    id4 id;
    id.branchUp = branchUp;
    if (branchUp) {
        id.neutral = LONG_MIN / 2;
    } else {
        id.neutral = LONG_MAX / 2;
    }
    id.pow = 1;
    while (id.pow < n) {
        id.pow *= 2;
    }
    id.ch = malloc(2 * id.pow * sizeof(Line));
    return id;
}

bool better(id4* id, double a, double b) {
    return id->branchUp ^ a < b;
}

long function(id4* id, long a, long b) {
    return id->branchUp ^ a < b ? a : b;
}

void add(id4* id, Line* line) {
    add(id, 1, 0, id->pow, line);
}

void add(id4* id, int v, int l, int r, Line* line) {
    if (id->ch[v] == NULL) {
        id->ch[v] = *line;
        return;
    }
    if (v >= id->pow) {
        if (v % 2 == 0) {
            if (better(id, line->value(l), id->ch[v].value(l))) {
                id->ch[v] = *line;
            }
        } else {
            if (better(id, line->value(r), id->ch[v].value(r))) {
                id->ch[v] = *line;
            }
        }
        return;
    }
    int m = (l + r) / 2;
    if (better(id, line->value(m), id->ch[v].value(m))) {
        Line c = *line;
        *line = id->ch[v];
        id->ch[v] = c;
    }
    if (better(id, line->value(l), id->ch[v].value(l))) {
        add(id, 2 * v, l, m, line);
    }
    if (better(id, line->value(r), id->ch[v].value(r))) {
        add(id, 2 * v + 1, m, r, line);
    }
}

long get(id4* id, int v, int l, int r, int x) {
    if (id->ch[v] == NULL) {
        return id->neutral;
    }
    if (v >= id->pow) {
        return id->ch[v].value(x);
    }
    long ans = id->ch[v].value(x);
    int m = (l + r) / 2;
    if (x <= m) {
        ans = function(id, ans, get(id, 2 * v, l, m, x));
    }
    if (x >= m) {
        ans = function(id, ans, get(id, 2 * v + 1, m, r, x));
    }
    return ans;
}

long get(id4* id, int x) {
    return get(id, 1, 0, id->pow, x);
}

id5 createId5(int max) {
    id5 id;
    id.div = malloc((max + 1) * sizeof(int));
    id.primes = malloc((max + 1) * sizeof(int));
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

int* factorization(id5* id, int x) {
    int* ans = malloc(sizeof(int));
    int ansSize = 0;
    while (id->div[x] > 0) {
        ans[ansSize++] = id->div[x];
        x /= id->div[x];
    }
    return ans;
}

int* id1(id5* id, int x) {
    int* div = factorization(id, x);
    int len = sizeof(div) / sizeof(div[0]);
    int* ans = malloc(sizeof(int));
    int ansSize = 0;
    for (int mask = 0; mask < (1 << len); mask++) {
        int th = 1;
        for (int i = 0; i < len; i++) {
            if ((mask & (1 << i)) > 0) {
                th *= div[i];
            }
        }
        ans[ansSize++] = th;
    }
    return ans;
}

int* id0(id5* id, int x) {
    int* div = factorization(id, x);
    int pr = 0;
    for (int i = 0; i < sizeof(div) / sizeof(div[0]); i++) {
        if (i == 0 || div[i] != div[i - 1]) {
            pr++;
        }
    }
    int* primes = malloc(pr * sizeof(int));
    int* sz = malloc(pr * sizeof(int));
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
    int** pow = malloc(pr * sizeof(int*));
    for (int i = 0; i < sizeof(pow) / sizeof(pow[0]); i++) {
        pow[i] = malloc((sz[i] + 1) * sizeof(int));
        pow[i][0] = 1;
        for (int j = 1; j < sizeof(pow[i]) / sizeof(pow[i][0]); j++) {
            pow[i][j] = pow[i][j - 1] * primes[i];
        }
    }
    int* th = malloc(pr * sizeof(int));
    int* ans = malloc(sizeof(int));
    int ansSize = 0;
    do {
        int z = 1;
        for (int i = 0; i < sizeof(th) / sizeof(th[0]); i++) {
            z *= pow[i][th[i]];
        }
        ans[ansSize++] = z;
    } while (next(th, sz));
    return ans;
}

bool next(int* th, int* max) {
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

char* id2(int x) {
    if (x == 1) {
        return "1 = 1";
    }
    int* list = factorization(x);
    char* ans = malloc(sizeof(char));
    int ansSize = 0;
    sprintf(ans, "%d = ", x);
    for (int i = 0; i < sizeof(list) / sizeof(list[0]); i++) {
        sprintf(ans, "%d", list[i]);
        if (i < sizeof(list) / sizeof(list[0]) - 1) {
            sprintf(ans, " * ");
        }
    }
    return ans;
}

void solve() {
    char* s = malloc(100000 * sizeof(char));
    scanf("%s", s);
    int l = 0;
    int r = 100001;
    while (1) {
        int sz = (l + r) >> 1;
        int* a = malloc(sz * sizeof(int));
        for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
            a[i] = i;
        }
        int x = 0;
        int* b = malloc(sz * sizeof(int));
        if (!mergeSort(s, a, 0, sz)) {
            r = sz;
            continue;
        }
        if (x < sizeof(s) / sizeof(s[0])) {
            l = sz;
            continue;
        }
        a = rev(a);
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
