#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    long long x;
    long long y;
} Point;

typedef struct {
    Point p1;
    Point p2;
} Line;

typedef struct {
    int x;
    int y;
    int r;
} Circle;

typedef struct {
    long long k;
    long long b;
} LineEquation;

typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
} Rect;

long long pow(long long x, long long p, long long mod) {
    if (p <= 0) {
        return 1;
    }
    long long th = pow(x, p / 2, mod);
    th *= th;
    th %= mod;
    if (p % 2 == 1) {
        th *= x;
    }
    return th;
}

typedef struct {
    long long x;
    long long y;
} Fraction;

Fraction createFraction(long long x, long long y) {
    Fraction f;
    f.x = x;
    f.y = y;
    return f;
}

void norm(Fraction* f) {
    long long gcd = gcd(f->x, f->y);
    f->x /= gcd;
    f->y /= gcd;
}

int compareFractions(Fraction* f1, Fraction* f2) {
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

Fraction sum(Fraction* a, Fraction* b) {
    Fraction c;
    c.x = a->x * b->y + a->y * b->x;
    c.y = a->y * b->y;
    norm(&c);
    return c;
}

long long gcd(long long x, long long y) {
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

Pair clonePair(Pair* p) {
    Pair clone;
    clone.x = p->x;
    clone.y = p->y;
    return clone;
}

int comparePairs(Pair* p1, Pair* p2) {
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

long long modInv(long long x, long long mod) {
    return pow(x, mod - 2, mod);
}

typedef struct {
    int* div;
    int* primes;
    int max;
} Factorizator;

Factorizator createFactorizator(int max) {
    Factorizator factorizator;
    factorizator.div = (int*)malloc((max + 1) * sizeof(int));
    factorizator.primes = (int*)malloc((max + 1) * sizeof(int));
    factorizator.max = max;
    for (int i = 2; i <= max; i++) {
        if (factorizator.div[i] == 0) {
            factorizator.div[i] = i;
            factorizator.primes[i] = i;
            for (int j = i * i; j <= max; j += i) {
                if (factorizator.div[j] == 0) {
                    factorizator.div[j] = i;
                }
            }
        }
    }
    return factorizator;
}

void destroyFactorizator(Factorizator* factorizator) {
    free(factorizator->div);
    free(factorizator->primes);
}

int* factorization(Factorizator* factorizator, int x, int* size) {
    int* ans = (int*)malloc(factorizator->max * sizeof(int));
    int index = 0;
    while (factorizator->div[x] > 0) {
        ans[index++] = factorizator->div[x];
        x /= factorizator->div[x];
    }
    *size = index;
    return ans;
}

int* all_divisors(Factorizator* factorizator, int x, int* size) {
    int* div = factorization(factorizator, x, size);
    int len = *size;
    int* ans = (int*)malloc((1 << len) * sizeof(int));
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
    *size = iter;
    free(div);
    return ans;
}

int* divisors(Factorizator* factorizator, int x, int* size) {
    int* div = factorization(factorizator, x, size);
    int pr = 0;
    for (int i = 0; i < *size; i++) {
        if (i == 0 || div[i] != div[i - 1]) {
            pr++;
        }
    }
    int* primes = (int*)malloc(pr * sizeof(int));
    int* sz = (int*)malloc(pr * sizeof(int));
    pr = -1;
    for (int i = 0; i < *size; i++) {
        if (i == 0 || div[i] != div[i - 1]) {
            pr++;
            primes[pr] = div[i];
            sz[pr] = 1;
        } else {
            sz[pr]++;
        }
    }
    *size = pr + 1;
    int** pow = (int**)malloc((*size) * sizeof(int*));
    for (int i = 0; i < *size; i++) {
        pow[i] = (int*)malloc((sz[i] + 1) * sizeof(int));
        pow[i][0] = 1;
        for (int j = 1; j <= sz[i]; j++) {
            pow[i][j] = pow[i][j - 1] * primes[i];
        }
    }
    int* th = (int*)malloc(*size * sizeof(int));
    int* ans = (int*)malloc((1 << pr) * sizeof(int));
    int iter = 0;
    for (int i = 0; i < *size; i++) {
        th[i] = 0;
    }
    while (true) {
        int z = 1;
        for (int i = 0; i < *size; i++) {
            z *= pow[i][th[i]];
        }
        ans[iter++] = z;
        bool next = false;
        for (int i = *size - 1; i >= 0; i--) {
            if (th[i] != sz[i]) {
                th[i]++;
                for (int j = i + 1; j < *size; j++) {
                    th[j] = 0;
                }
                next = true;
                break;
            }
        }
        if (!next) {
            break;
        }
    }
    *size = iter;
    for (int i = 0; i < *size; i++) {
        free(pow[i]);
    }
    free(pow);
    free(th);
    free(div);
    free(primes);
    free(sz);
    return ans;
}

typedef struct {
    int pow;
    long long* max;
    long long* delta;
    bool* flag;
} SegmentTreeAdd;

SegmentTreeAdd createSegmentTreeAdd(int n) {
    SegmentTreeAdd segmentTreeAdd;
    segmentTreeAdd.pow = 1;
    while (segmentTreeAdd.pow < n) {
        segmentTreeAdd.pow *= 2;
    }
    segmentTreeAdd.max = (long long*)malloc((2 * segmentTreeAdd.pow) * sizeof(long long));
    segmentTreeAdd.delta = (long long*)malloc((2 * segmentTreeAdd.pow) * sizeof(long long));
    segmentTreeAdd.flag = (bool*)malloc((2 * segmentTreeAdd.pow) * sizeof(bool));
    for (int i = 0; i < 2 * segmentTreeAdd.pow; i++) {
        segmentTreeAdd.max[i] = LLONG_MIN / 2;
    }
    return segmentTreeAdd;
}

void destroySegmentTreeAdd(SegmentTreeAdd* segmentTreeAdd) {
    free(segmentTreeAdd->max);
    free(segmentTreeAdd->delta);
    free(segmentTreeAdd->flag);
}

void push(SegmentTreeAdd* segmentTreeAdd, int v, int tl, int tr) {
    if (segmentTreeAdd->flag[v]) {
        if (v < segmentTreeAdd->pow) {
            segmentTreeAdd->flag[2 * v] = true;
            segmentTreeAdd->flag[2 * v + 1] = true;
            segmentTreeAdd->delta[2 * v] += segmentTreeAdd->delta[v];
            segmentTreeAdd->delta[2 * v + 1] += segmentTreeAdd->delta[v];
        }
        segmentTreeAdd->flag[v] = false;
        segmentTreeAdd->max[v] += segmentTreeAdd->delta[v];
        segmentTreeAdd->delta[v] = 0;
    }
}

void add(SegmentTreeAdd* segmentTreeAdd, int v, int l, int r, int x, long long d) {
    push(segmentTreeAdd, v, l, r);
    if (l > r || x < l || x > r) {
        return;
    }
    if (l == r) {
        segmentTreeAdd->max[v] += d;
        return;
    }
    int m = (l + r) / 2;
    add(segmentTreeAdd, 2 * v, l, m, x, d);
    add(segmentTreeAdd, 2 * v + 1, m + 1, r, x, d);
    segmentTreeAdd->max[v] = fmax(segmentTreeAdd->max[2 * v], segmentTreeAdd->max[2 * v + 1]);
}

void set(SegmentTreeAdd* segmentTreeAdd, int v, int l, int r, int x, int y, long long d) {
    push(segmentTreeAdd, v, l, r);
    if (l > r || x > r || y < l) {
        return;
    }
    if (x <= l && r <= y) {
        segmentTreeAdd->flag[v] = true;
        segmentTreeAdd->delta[v] += d;
        push(segmentTreeAdd, v, l, r);
        return;
    }
    int m = (l + r) / 2;
    set(segmentTreeAdd, 2 * v, l, m, x, y, d);
    set(segmentTreeAdd, 2 * v + 1, m + 1, r, x, y, d);
    segmentTreeAdd->max[v] = fmax(segmentTreeAdd->max[2 * v], segmentTreeAdd->max[2 * v + 1]);
}

long long get(SegmentTreeAdd* segmentTreeAdd, int v, int l, int r, int x, int y) {
    push(segmentTreeAdd, v, l, r);
    if (l > r || x > r || y < l) {
        return LLONG_MIN / 2;
    }
    if (x <= l && r <= y) {
        return segmentTreeAdd->max[v];
    }
    int m = (l + r) / 2;
    long long ans = fmax(get(segmentTreeAdd, 2 * v, l, m, x, y), get(segmentTreeAdd, 2 * v + 1, m + 1, r, x, y));
    return ans;
}

typedef struct {
    bool branchUp;
    long long neutral;
    int pow;
    LineEquation* ch;
} LiChaoTree;

LiChaoTree createLiChaoTree(int n, bool branchUp) {
    LiChaoTree liChaoTree;
    liChaoTree.branchUp = branchUp;
    if (branchUp) {
        liChaoTree.neutral = LLONG_MIN / 2;
    } else {
        liChaoTree.neutral = LLONG_MAX / 2;
    }
    liChaoTree.pow = 1;
    while (liChaoTree.pow < n) {
        liChaoTree.pow *= 2;
    }
    liChaoTree.ch = (LineEquation*)malloc((2 * liChaoTree.pow) * sizeof(LineEquation));
    for (int i = 0; i < 2 * liChaoTree.pow; i++) {
        liChaoTree.ch[i].k = 0;
        liChaoTree.ch[i].b = liChaoTree.neutral;
    }
    return liChaoTree;
}

void destroyLiChaoTree(LiChaoTree* liChaoTree) {
    free(liChaoTree->ch);
}

bool better(LiChaoTree* liChaoTree, double a, double b) {
    return liChaoTree->branchUp ^ a < b;
}

long long function(LiChaoTree* liChaoTree, long long a, long long b) {
    return liChaoTree->branchUp ^ a < b ? a : b;
}

void add(LiChaoTree* liChaoTree, int v, int l, int r, LineEquation line) {
    if (liChaoTree->ch[v].k == 0) {
        liChaoTree->ch[v] = line;
        return;
    }
    if (v >= liChaoTree->pow) {
        if (v % 2 == 0) {
            if (better(liChaoTree, line.k * l + line.b, liChaoTree->ch[v].k * l + liChaoTree->ch[v].b)) {
                liChaoTree->ch[v] = line;
            }
        } else {
            if (better(liChaoTree, line.k * r + line.b, liChaoTree->ch[v].k * r + liChaoTree->ch[v].b)) {
                liChaoTree->ch[v] = line;
            }
        }
        return;
    }
    int m = (l + r) / 2;
    if (better(liChaoTree, line.k * m + line.b, liChaoTree->ch[v].k * m + liChaoTree->ch[v].b)) {
        LineEquation c = line;
        line = liChaoTree->ch[v];
        liChaoTree->ch[v] = c;
    }
    if (better(liChaoTree, line.k * l + line.b, liChaoTree->ch[v].k * l + liChaoTree->ch[v].b)) {
        add(liChaoTree, 2 * v, l, m, line);
    }
    if (better(liChaoTree, line.k * r + line.b, liChaoTree->ch[v].k * r + liChaoTree->ch[v].b)) {
        add(liChaoTree, 2 * v + 1, m + 1, r, line);
    }
}

long long get(LiChaoTree* liChaoTree, int v, int l, int r, int x) {
    if (liChaoTree->ch[v].k == 0) {
        return liChaoTree->neutral;
    }
    if (v >= liChaoTree->pow) {
        return liChaoTree->ch[v].k * x + liChaoTree->ch[v].b;
    }
    long long ans = liChaoTree->ch[v].k * x + liChaoTree->ch[v].b;
    int m = (l + r) / 2;
    if (x <= m) {
        ans = function(liChaoTree, ans, get(liChaoTree, 2 * v, l, m, x));
    }
    if (x >= m) {
        ans = function(liChaoTree, ans, get(liChaoTree, 2 * v + 1, m + 1, r, x));
    }
    return ans;
}

void solve() {
    char s[100001];
    scanf("%s", s);
    int l = 0;
    int r = 100001;
    while (true) {
        int sz = (l + r) / 2;
        int* a = (int*)malloc(sz * sizeof(int));
        for (int i = 0; i < sz; i++) {
            a[i] = i;
        }
        int x = 0;
        int* b = (int*)malloc(sz * sizeof(int));
        if (!mergeSort(s, a, 0, sz, &x, b)) {
            r = sz;
            continue;
        }
        if (x < strlen(s)) {
            l = sz;
            continue;
        }
        for (int i = 0; i < sz; i++) {
            b[i] = a[b[i]];
        }
        printf("%d\n", sz);
        for (int i = 0; i < sz; i++) {
            printf("%d ", b[i] + 1);
        }
        return;
    }
}

int main() {
    solve();
    return 0;
}
