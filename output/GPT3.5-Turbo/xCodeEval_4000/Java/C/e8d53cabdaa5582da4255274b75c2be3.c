#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    long x;
    long y;
} Point;

typedef struct {
    long x1;
    long y1;
    long x2;
    long y2;
} Rect;

typedef struct {
    long x;
    long y;
    long r;
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
} LiChaoTree;

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

int gcd(long x, long y) {
    if (y == 0) {
        return x;
    }
    if (x == 0) {
        return y;
    }
    return gcd(y, x % y);
}

int compareFraction(Fraction a, Fraction b) {
    if (a.x > b.x) {
        return 1;
    }
    if (a.x < b.x) {
        return -1;
    }
    if (a.y > b.y) {
        return 1;
    }
    if (a.y < b.y) {
        return -1;
    }
    return 0;
}

Fraction createFraction(long x, long y) {
    Fraction fraction;
    fraction.x = x;
    fraction.y = y;
    return fraction;
}

void normalizeFraction(Fraction* fraction) {
    long gcdValue = gcd(fraction->x, fraction->y);
    fraction->x /= gcdValue;
    fraction->y /= gcdValue;
}

Fraction sumFraction(Fraction a, Fraction b) {
    Fraction c;
    c.x = a.x * b.y + a.y * b.x;
    c.y = a.y * b.y;
    normalizeFraction(&c);
    return c;
}

typedef struct {
    int x;
    int y;
} Pair;

int comparePair(Pair a, Pair b) {
    if (a.x > b.x) {
        return 1;
    }
    if (a.x < b.x) {
        return -1;
    }
    if (a.y > b.y) {
        return 1;
    }
    if (a.y < b.y) {
        return -1;
    }
    return 0;
}

Pair createPair(int x, int y) {
    Pair pair;
    pair.x = x;
    pair.y = y;
    return pair;
}

typedef struct {
    int* arr;
    int size;
} ArrayList;

ArrayList* createArrayList() {
    ArrayList* list = malloc(sizeof(ArrayList));
    list->arr = malloc(sizeof(int));
    list->size = 0;
    return list;
}

void addArrayList(ArrayList* list, int value) {
    list->arr = realloc(list->arr, (list->size + 1) * sizeof(int));
    list->arr[list->size] = value;
    list->size++;
}

void freeArrayList(ArrayList* list) {
    free(list->arr);
    free(list);
}

typedef struct {
    int* arr;
    int size;
} TreeSet;

TreeSet* createTreeSet() {
    TreeSet* set = malloc(sizeof(TreeSet));
    set->arr = malloc(sizeof(int));
    set->size = 0;
    return set;
}

void addTreeSet(TreeSet* set, int value) {
    set->arr = realloc(set->arr, (set->size + 1) * sizeof(int));
    set->arr[set->size] = value;
    set->size++;
}

void freeTreeSet(TreeSet* set) {
    free(set->arr);
    free(set);
}

typedef struct {
    int* arr;
    int size;
} Divisors;

Divisors* createDivisors() {
    Divisors* divisors = malloc(sizeof(Divisors));
    divisors->arr = malloc(sizeof(int));
    divisors->size = 0;
    return divisors;
}

void addDivisor(Divisors* divisors, int value) {
    divisors->arr = realloc(divisors->arr, (divisors->size + 1) * sizeof(int));
    divisors->arr[divisors->size] = value;
    divisors->size++;
}

void freeDivisors(Divisors* divisors) {
    free(divisors->arr);
    free(divisors);
}

Divisors* factorization(int x) {
    Divisors* divisors = createDivisors();
    while (x > 1) {
        int prime = div[x];
        addDivisor(divisors, prime);
        x /= prime;
    }
    return divisors;
}

Divisors* allDivisors(int x) {
    Divisors* divisors = factorization(x);
    TreeSet* set = createTreeSet();
    int len = divisors->size;
    for (int mask = 0; mask < (1 << len); mask++) {
        int th = 1;
        for (int i = 0; i < len; i++) {
            if ((mask & (1 << i)) > 0) {
                th *= divisors->arr[i];
            }
        }
        addTreeSet(set, th);
    }
    freeDivisors(divisors);
    return set;
}

Divisors* divisors(int x) {
    Divisors* divisors = factorization(x);
    int pr = 0;
    for (int i = 0; i < divisors->size; i++) {
        if (i == 0 || divisors->arr[i] != divisors->arr[i - 1]) {
            pr++;
        }
    }
    int* primes = malloc(pr * sizeof(int));
    int* sz = malloc(pr * sizeof(int));
    pr = -1;
    for (int i = 0; i < divisors->size; i++) {
        if (i == 0 || divisors->arr[i] != divisors->arr[i - 1]) {
            pr++;
            primes[pr] = divisors->arr[i];
            sz[pr] = 1;
        } else {
            sz[pr]++;
        }
    }
    pr++;
    int** pow = malloc(pr * sizeof(int*));
    for (int i = 0; i < pr; i++) {
        pow[i] = malloc((sz[i] + 1) * sizeof(int));
        pow[i][0] = 1;
        for (int j = 1; j <= sz[i]; j++) {
            pow[i][j] = pow[i][j - 1] * primes[i];
        }
    }
    TreeSet* set = createTreeSet();
    int* th = malloc(pr * sizeof(int));
    do {
        int z = 1;
        for (int i = 0; i < pr; i++) {
            z *= pow[i][th[i]];
        }
        addTreeSet(set, z);
    } while (next(th, sz, pr));
    free(th);
    for (int i = 0; i < pr; i++) {
        free(pow[i]);
    }
    free(pow);
    free(primes);
    free(sz);
    freeDivisors(divisors);
    return set;
}

bool next(int* th, int* max, int size) {
    for (int i = size - 1; i >= 0; i--) {
        if (th[i] != max[i]) {
            th[i]++;
            for (int j = i + 1; j < size; j++) {
                th[j] = 0;
            }
            return true;
        }
    }
    return false;
}

typedef struct {
    int x;
    int y;
} Point;

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

typedef struct {
    long* sum;
    int size;
} Fenvik;

Fenvik* createFenvik(int n) {
    Fenvik* fenvik = malloc(sizeof(Fenvik));
    fenvik->sum = malloc(n * sizeof(long));
    fenvik->size = n;
    return fenvik;
}

void addFenvik(Fenvik* fenvik, int x, long d) {
    for (int i = x; i < fenvik->size; i = (i | (i + 1))) {
        fenvik->sum[i] += d;
    }
}

long sumFenvik(Fenvik* fenvik, int r) {
    long ans = 0;
    for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
        ans += fenvik->sum[i];
    }
    return ans;
}

long rangeSumFenvik(Fenvik* fenvik, int l, int r) {
    if (l > r) {
        return 0;
    }
    return sumFenvik(fenvik, r) - sumFenvik(fenvik, l - 1);
}

typedef struct {
    long* max;
    long* delta;
    bool* flag;
    int pow;
} SegmentTreeAdd;

SegmentTreeAdd* createSegmentTreeAdd(int n) {
    SegmentTreeAdd* segmentTree = malloc(sizeof(SegmentTreeAdd));
    segmentTree->pow = 1;
    while (segmentTree->pow < n) {
        segmentTree->pow *= 2;
    }
    segmentTree->max = malloc(2 * segmentTree->pow * sizeof(long));
    segmentTree->delta = malloc(2 * segmentTree->pow * sizeof(long));
    segmentTree->flag = malloc(2 * segmentTree->pow * sizeof(bool));
    for (int i = 0; i < 2 * segmentTree->pow; i++) {
        segmentTree->max[i] = LONG_MIN / 2;
    }
    return segmentTree;
}

void setSegmentTreeAdd(SegmentTreeAdd* segmentTree, int v, int tl, int tr, int l, int r, long x) {
    if (l > tr || r < tl) {
        return;
    }
    if (l <= tl && r >= tr) {
        segmentTree->delta[v] += x;
        segmentTree->flag[v] = true;
        return;
    }
    int tm = (tl + tr) / 2;
    setSegmentTreeAdd(segmentTree, 2 * v, tl, tm, l, r, x);
    setSegmentTreeAdd(segmentTree, 2 * v + 1, tm + 1, tr, l, r, x);
    segmentTree->max[v] = fmax(segmentTree->max[2 * v], segmentTree->max[2 * v + 1]);
}

void pushSegmentTreeAdd(SegmentTreeAdd* segmentTree, int v, int tl, int tr) {
    if (segmentTree->flag[v]) {
        if (v < segmentTree->pow) {
            segmentTree->flag[2 * v] = true;
            segmentTree->flag[2 * v + 1] = true;
            segmentTree->delta[2 * v] += segmentTree->delta[v];
            segmentTree->delta[2 * v + 1] += segmentTree->delta[v];
        }
        segmentTree->flag[v] = false;
        segmentTree->max[v] += segmentTree->delta[v];
        segmentTree->delta[v] = 0;
    }
}

long getSegmentTreeAdd(SegmentTreeAdd* segmentTree, int v, int tl, int tr, int x) {
    if (segmentTree->max[v] == LONG_MIN / 2) {
        return segmentTree->max[v];
    }
    if (v >= segmentTree->pow) {
        return segmentTree->max[v];
    }
    long ans = segmentTree->max[v];
    int m = (tl + tr) / 2;
    if (x <= m) {
        ans = fmax(ans, getSegmentTreeAdd(segmentTree, 2 * v, tl, m, x));
    }
    if (x >= m) {
        ans = fmax(ans, getSegmentTreeAdd(segmentTree, 2 * v + 1, m + 1, tr, x));
    }
    return ans;
}

long rangeMaxSegmentTreeAdd(SegmentTreeAdd* segmentTree, int l, int r) {
    if (l > r) {
        return segmentTree->neutral;
    }
    return getSegmentTreeAdd(segmentTree, 1, 0, segmentTree->pow, r);
}

typedef struct {
    int x;
    int y;
    int r;
} Circle;

bool inside(Circle small, Circle big) {
    return (small.x - big.x) * (small.x - big.x) + (small.y - big.y) * (small.y - big.y) <= (big.r - small.r) * (big.r - small.r);
}

double* tangent(Circle c1, Circle c2) {
    Circle a = c1;
    Circle b = c2;
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

double* normalize(double* ans) {
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

bool mergeSort(char* s, int* a, int l, int r, int x) {
    if (r - l <= 1) {
        return true;
    }
    int m = (l + r) >> 1;
    if (!mergeSort(s, a, l, m, x)) {
        return false;
    }
    if (!mergeSort(s, a, m, r, x)) {
        return false;
    }
    int i = l;
    int j = m;
    int k = l;
    while (i < m && j < r) {
        if (x == strlen(s)) {
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

int* rev(int* a, int size) {
    int* res = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        res[a[i]] = i;
    }
    return res;
}

void solve() {
    char* s = malloc(100 * sizeof(char));
    scanf("%s", s);
    for (int sz = 1; ; sz++) {
        int* a = malloc(sz * sizeof(int));
        for (int i = 0; i < sz; i++) {
            a[i] = i;
        }
        x = 0;
        b = malloc(sz * sizeof(int));
        if (!mergeSort(s, a, 0, sz, x)) {
            continue;
        }
        if (x < strlen(s)) {
            continue;
        }
        a = rev(a, sz);
        printf("%d\n", sz);
        for (int i = 0; i < sz; i++) {
            printf("%d ", a[i] + 1);
        }
        return;
    }
}

int main() {
    solve();
    return 0;
}
