#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100000
#define MAX_M 100000
#define MAX_Q 100000

typedef struct {
    int x;
    int y;
} Pair;

typedef struct {
    long long x1;
    long long x2;
    long long y1;
    long long y2;
    int number;
} Rect;

typedef struct {
    long long x;
    long long y;
} Point;

typedef struct {
    long long x;
    long long y;
    bool needNorm;
} Fraction;

typedef struct {
    int* st;
    int sz;
} Stack;

typedef struct {
    int* p;
    int* sz;
    Stack less;
    Stack more;
    PriorityQueue** q;
    bool* used;
} DSU1;

typedef struct {
    int* t;
} Fenvik;

typedef struct {
    int pow;
    int* sum;
    int* maxPrefSum;
    int* maxSufSum;
    int* maxSum;
} SegmentTreeMaxSum;

typedef struct {
    int pow;
    long long* max;
    long long* delta;
    bool* flag;
} SegmentTreeAdd;

typedef struct {
    int pow;
    int* sum;
    int* delta;
    bool* flag;
} SegmentTreeSet;

typedef struct {
    int* sz;
    int* p;
} DSU;

typedef struct {
    double* coeff;
} Pol;

typedef struct {
    double x;
    double y;
} Vector;

typedef struct {
    Fraction f;
    int type;
} Event;

typedef struct {
    Point p;
    int r;
} Circle;

void shuffle(Pair* a, int n);
void sort(int** a, int n);
void add(HashMap* map, long long l);
void remove(TreeMap* map, int s);
int signum(double x);
long long abs(long long x);
long long min(long long x, long long y);
long long max(long long x, long long y);
long long gcd(long long x, long long y);
int compareTo(Pair* a, Pair* b);
int compareTo(Event* a, Event* b);
int compareTo(Fraction* a, Fraction* b);
int compareTo(Point* a, Point* b);
int compareTo(Circle* a, Circle* b);
int f(int a, int b);
double sq(double x);
long long sq(long long x);
double hypot2(double x, double y);
long long hypot2(long long x, long long y);
bool kuhn(int v, int** edge, bool* used, int* mt, int n);
int matching(int** edge, int n, int m);
int** readGraph(int n, int m);
void solve();
void add(HashMap* map, int x);
void run();
void initFact();
void initInv(int* inv, int* v, int n);
void dsuInit(DSU* dsu, int* v, int n);
int dsuGet(DSU* dsu, int x);
bool dsuUnite(DSU* dsu, int a, int b);
void dsuPopEdge(DSU* dsu);
int dsuPoll(DSU* dsu, int x);
void segmentTreeAddInit(SegmentTreeAdd* st, long long* a, int n);
long long segmentTreeAddGet(SegmentTreeAdd* st, int v, int tl, int tr, int l, int r);
void segmentTreeAddSet(SegmentTreeAdd* st, int v, int tl, int tr, int l, int r, long long x);
void segmentTreeAddPush(SegmentTreeAdd* st, int v, int tl, int tr);
long long segmentTreeAddF(long long a, long long b);
void segmentTreeSetInit(SegmentTreeSet* st, int* a, int n);
int segmentTreeSetGet(SegmentTreeSet* st, int v, int tl, int tr, int l, int r);
void segmentTreeSetSet(SegmentTreeSet* st, int v, int tl, int tr, int l, int r, int x);
void segmentTreeSetPush(SegmentTreeSet* st, int v, int tl, int tr);
int segmentTreeSetF(int a, int b);
void segmentTreeMaxSumInit(SegmentTreeMaxSum* st, int* a, int n);
int* segmentTreeMaxSumGet(SegmentTreeMaxSum* st, int v, int tl, int tr, int l, int r);
void segmentTreeMaxSumSet(SegmentTreeMaxSum* st, int v, int tl, int tr, int x, int value);
void segmentTreeMaxSumUpdate(SegmentTreeMaxSum* st, int i);
int segmentTreeMaxSumF(int a, int b);
void fenvikInit(Fenvik* f, int n);
void fenvikAdd(Fenvik* f, int x, int delta);
int fenvikSum(Fenvik* f, int r);
int fenvikSumRange(Fenvik* f, int l, int r);
void polInit(Pol* p, double* coeff, int n);
Pol polMult(Pol* p, Pol* q);
double polValue(Pol* p, double x);
double polIntegrate(Pol* p, double r);
double polIntegrateRange(Pol* p, double l, double r);
void stackInit(Stack* s, int n);
bool stackIsEmpty(Stack* s);
int stackPeek(Stack* s);
int stackPop(Stack* s);
void stackClear(Stack* s);
void stackAdd(Stack* s, int x);
int stackGet(Stack* s, int x);
void dsu1Init(DSU1* dsu, int* v, int m, int n);
int dsu1Get(DSU1* dsu, int x);
bool dsu1Unite(DSU1* dsu, int a, int b);
void dsu1PopEdge(DSU1* dsu);
int dsu1Poll(DSU1* dsu, int x);
void pointInit(Point* p, double x, double y);
Point pointAdd(Point* p, Point* v);
int main();

int main() {
    run();
    return 0;
}

void shuffle(Pair* a, int n) {
    for (int i = 0; i < n; i++) {
        int x = rand() % (i + 1);
        Pair t = a[x];
        a[x] = a[i];
        a[i] = t;
    }
}

void sort(int** a, int n) {
    for (int i = 0; i < n; i++) {
        qsort(a[i], n, sizeof(int), compareTo);
    }
}

void add(HashMap* map, long long l) {
    if (hashMapContainsKey(map, l)) {
        hashMapPut(map, l, hashMapGet(map, l) + 1);
    } else {
        hashMapPut(map, l, 1);
    }
}

void remove(TreeMap* map, int s) {
    if (treeMapGet(map, s) > 1) {
        treeMapPut(map, s, treeMapGet(map, s) - 1);
    } else {
        treeMapRemove(map, s);
    }
}

int signum(double x) {
    if (x > 1e-10) {
        return 1;
    }
    if (x < -1e-10) {
        return -1;
    }
    return 0;
}

long long abs(long long x) {
    return x < 0 ? -x : x;
}

long long min(long long x, long long y) {
    return x < y ? x : y;
}

long long max(long long x, long long y) {
    return x > y ? x : y;
}

long long gcd(long long x, long long y) {
    while (y > 0) {
        long long c = y;
        y = x % y;
        x = c;
    }
    return x;
}

int compareTo(Pair* a, Pair* b) {
    if (a->y > b->y) {
        return 1;
    }
    if (a->y < b->y) {
        return -1;
    }
    if (a->x > b->x) {
        return 1;
    }
    if (a->x < b->x) {
        return -1;
    }
    return 0;
}

int compareTo(Event* a, Event* b) {
    int c = compareTo(&a->f, &b->f);
    if (c != 0) {
        return c;
    }
    return a->type - b->type;
}

int compareTo(Fraction* a, Fraction* b) {
    long long res = a->x * b->y - a->y * b->x;
    if (res > 0) {
        return 1;
    }
    if (res < 0) {
        return -1;
    }
    return 0;
}

int compareTo(Point* a, Point* b) {
    int z = signum(a->x + a->y - b->x - b->y);
    if (z != 0) {
        return z;
    }
    return signum(a->x - b->x) != 0 ? signum(a->x - b->x) : signum(a->y - b->y);
}

int compareTo(Circle* a, Circle* b) {
    Point pa = angle(a);
    Point pb = angle(b);
    int z = signum(pa.x + pa.y - pb.x - pb.y);
    if (z != 0) {
        return z;
    }
    return signum(pa.y - pb.y);
}

int f(int a, int b) {
    return a + b;
}

double sq(double x) {
    return x * x;
}

long long sq(long long x) {
    return x * x;
}

double hypot2(double x, double y) {
    return sq(x) + sq(y);
}

long long hypot2(long long x, long long y) {
    return sq(x) + sq(y);
}

bool kuhn(int v, int** edge, bool* used, int* mt, int n) {
    used[v] = true;
    for (int u = 0; u < n; u++) {
        if (edge[v][u] && (mt[u] < 0 || (!used[mt[u]] && kuhn(mt[u], edge, used, mt, n)))) {
            mt[u] = v;
            return true;
        }
    }
    return false;
}

int matching(int** edge, int n, int m) {
    int* mt = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        mt[i] = -1;
    }
    bool* used = malloc(n * sizeof(bool));
    for (int i = 0; i < n; i++) {
        used[i] = false;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i] && kuhn(i, edge, used, mt, n)) {
            for (int i = 0; i < n; i++) {
                used[i] = false;
            }
            ans++;
        }
    }
    free(mt);
    free(used);
    return ans;
}

int** readGraph(int n, int m) {
    int** to = malloc(n * sizeof(int*));
    int* sz = malloc(n * sizeof(int));
    int* x = malloc(m * sizeof(int));
    int* y = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        x[i] = in.nextInt() - 1;
        y[i] = in.nextInt() - 1;
        sz[x[i]]++;
        sz[y[i]]++;
    }
    for (int i = 0; i < n; i++) {
        to[i] = malloc(sz[i] * sizeof(int));
        sz[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        to[x[i]][sz[x[i]]++] = y[i];
        to[y[i]][sz[y[i]]++] = x[i];
    }
    free(sz);
    free(x);
    free(y);
    return to;
}

void solve() {
    int n = in.nextInt();
    int m = in.nextInt();
    int q = in.nextInt();
    int* v = malloc(n * sizeof(int));
    int* inv = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        v[i] = in.nextInt();
        inv[v[i] - 1] = i;
    }
    int* a = malloc(m * sizeof(int));
    int* b = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        a[i] = in.nextInt() - 1;
        b[i] = in.nextInt() - 1;
    }
    bool* type = malloc(q * sizeof(bool));
    int* x = malloc(q * sizeof(int));
    bool* removed = malloc(m * sizeof(bool));
    for (int i = 0; i < q; i++) {
        if (in.nextInt() == 1) {
            x[i] = in.nextInt() - 1;
            type[i] = true;
        } else {
            x[i] = in.nextInt() - 1;
            removed[x[i]] = true;
        }
    }
    DSU1 dsu;
    dsuInit(&dsu, v, m);
    for (int i = 0; i < m; i++) {
        if (!removed[i]) {
            dsuUnite(&dsu, a[i], b[i]);
        }
    }
    for (int i = q - 1; i >= 0; i--) {
        if (!type[i]) {
            dsuPopEdge(&dsu);
        }
    }
    for (int i = 0; i < q; i++) {
        if (type[i]) {
            out.println(dsuPoll(&dsu, x[i]));
        } else {
            dsuPopEdge(&dsu);
        }
    }
    free(v);
    free(inv);
    free(a);
    free(b);
    free(type);
    free(x);
    free(removed);
}

void add(HashMap* map, int x) {
    if (hashMapContainsKey(map, x)) {
        hashMapPut(map, x, hashMapGet(map, x) + 1);
    } else {
        hashMapPut(map, x, 1);
    }
}

void run() {
    solve();
    out.close();
}

void initFact() {
    fact[0] = 1;
    for (int i = 1; i < 100; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

void initInv(int* inv, int* v, int n) {
    for (int i = 0; i < n; i++) {
        inv[v[i] - 1] = i;
    }
}

void dsuInit(DSU* dsu, int* v, int n) {
    dsu->p = malloc(n * sizeof(int));
    dsu->sz = malloc(n * sizeof(int));
    dsu->less = malloc(sizeof(Stack));
    dsu->more = malloc(sizeof(Stack));
    dsu->q = malloc(n * sizeof(PriorityQueue*));
    dsu->used = malloc((n + 1) * sizeof(bool));
    for (int i = 0; i < n; i++) {
        dsu->p[i] = i;
        dsu->sz[i] = 1;
        dsu->q[i] = malloc(sizeof(PriorityQueue));
        priorityQueueInit(dsu->q[i]);
        priorityQueueAdd(dsu->q[i], -v[i]);
    }
    stackInit(dsu->less, m);
    stackInit(dsu->more, m);
    for (int i = 0; i <= n; i++) {
        dsu->used[i] = false;
    }
}

int dsuGet(DSU* dsu, int x) {
    while (x != dsu->p[x]) {
        x = dsu->p[x];
    }
    return x;
}

bool dsuUnite(DSU* dsu, int a, int b) {
    int pa = dsuGet(dsu, a);
    int pb = dsuGet(dsu, b);
    if (pa == pb) {
        stackAdd(dsu->less, -1);
        stackAdd(dsu->more, -1);
        return false;
    }
    if (dsu->sz[pa] < dsu->sz[pb]) {
        dsu->p[pa] = pb;
        dsu->sz[pb] += dsu->sz[pa];
        stackAdd(dsu->less, pa);
        stackAdd(dsu->more, pb);
        for (int i = 0; i < dsu->q[pa]->sz; i++) {
            priorityQueueAdd(dsu->q[pb], dsu->q[pa]->arr[i]);
        }
    } else {
        dsu->p[pb] = pa;
        dsu->sz[pa] += dsu->sz[pb];
        stackAdd(dsu->less, pb);
        stackAdd(dsu->more, pa);
        for (int i = 0; i < dsu->q[pb]->sz; i++) {
            priorityQueueAdd(dsu->q[pa], dsu->q[pb]->arr[i]);
        }
    }
    return true;
}

void dsuPopEdge(DSU* dsu) {
    int pa = stackPop(dsu->less);
    int pb = stackPop(dsu->more);
    if (pa < 0) {
        return;
    }
    dsu->p[pa] = pa;
    dsu->sz[pb] -= dsu->sz[pa];
}

int dsuPoll(DSU* dsu, int x) {
    int px = dsuGet(dsu, x);
    while (!priorityQueueIsEmpty(dsu->q[px])) {
        int v = -priorityQueuePoll(dsu->q[px]);
        if (!dsu->used[v] && dsuGet(dsu, inv[v - 1]) == px) {
            dsu->used[v] = true;
            return v;
        }
    }
    return 0;
}

void segmentTreeAddInit(SegmentTreeAdd* st, long long* a, int n) {
    st->pow = 1;
    while (st->pow < n) {
        st->pow *= 2;
    }
    st->flag = malloc(2 * st->pow * sizeof(bool));
    st->max = malloc(2 * st->pow * sizeof(long long));
    st->delta = malloc(2 * st->pow * sizeof(long long));
    for (int i = 0; i < 2 * st->pow; i++) {
        st->max[i] = LLONG_MIN / 2;
    }
    for (int i = 0; i < n; i++) {
        st->max[st->pow + i] = a[i];
    }
    for (int i = st->pow - 1; i > 0; i--) {
        st->max[i] = f(st->max[2 * i], st->max[2 * i + 1]);
    }
}

long long segmentTreeAddGet(SegmentTreeAdd* st, int v, int tl, int tr, int l, int r) {
    segmentTreeAddPush(st, v, tl, tr);
    if (l > r) {
        return LLONG_MIN / 2;
    }
    if (l == tl && r == tr) {
        return st->max[v];
    }
    int tm = (tl + tr) / 2;
    return f(segmentTreeAddGet(st, 2 * v, tl, tm, l, min(r, tm)), segmentTreeAddGet(st, 2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void segmentTreeAddSet(SegmentTreeAdd* st, int v, int tl, int tr, int l, int r, long long x) {
    segmentTreeAddPush(st, v, tl, tr);
    if (l > tr || r < tl) {
        return;
    }
    if (l <= tl && r >= tr) {
        st->delta[v] += x;
        st->flag[v] = true;
        segmentTreeAddPush(st, v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    segmentTreeAddSet(st, 2 * v, tl, tm, l, r, x);
    segmentTreeAddSet(st, 2 * v + 1, tm + 1, tr, l, r, x);
    st->max[v] = f(st->max[2 * v], st->max[2 * v + 1]);
}

void segmentTreeAddPush(SegmentTreeAdd* st, int v, int tl, int tr) {
    if (st->flag[v]) {
        if (v < st->pow) {
            st->flag[2 * v] = true;
            st->flag[2 * v + 1] = true;
            st->delta[2 * v] += st->delta[v];
            st->delta[2 * v + 1] += st->delta[v];
        }
        st->flag[v] = false;
        st->max[v] += st->delta[v];
        st->delta[v] = 0;
    }
}

long long segmentTreeAddF(long long a, long long b) {
    return max(a, b);
}

void segmentTreeSetInit(SegmentTreeSet* st, int* a, int n) {
    st->pow = 1;
    while (st->pow < n) {
        st->pow *= 2;
    }
    st->flag = malloc(2 * st->pow * sizeof(bool));
    st->sum = malloc(2 * st->pow * sizeof(int));
    st->delta = malloc(2 * st->pow * sizeof(int));
    for (int i = 0; i < n; i++) {
        st->sum[st->pow + i] = a[i];
    }
}

int segmentTreeSetGet(SegmentTreeSet* st, int v, int tl, int tr, int l, int r) {
    segmentTreeSetPush(st, v, tl, tr);
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return st->sum[v];
    }
    int tm = (tl + tr) / 2;
    return f(segmentTreeSetGet(st, 2 * v, tl, tm, l, min(r, tm)), segmentTreeSetGet(st, 2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void segmentTreeSetSet(SegmentTreeSet* st, int v, int tl, int tr, int l, int r, int x) {
    segmentTreeSetPush(st, v, tl, tr);
    if (l > tr || r < tl) {
        return;
    }
    if (l <= tl && r >= tr) {
        st->delta[v] = x;
        st->flag[v] = true;
        segmentTreeSetPush(st, v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    segmentTreeSetSet(st, 2 * v, tl, tm, l, r, x);
    segmentTreeSetSet(st, 2 * v + 1, tm + 1, tr, l, r, x);
    st->sum[v] = f(st->sum[2 * v], st->sum[2 * v + 1]);
}

void segmentTreeSetPush(SegmentTreeSet* st, int v, int tl, int tr) {
    if (st->flag[v]) {
        if (v < st->pow) {
            st->flag[2 * v] = true;
            st->flag[2 * v + 1] = true;
            st->delta[2 * v] = st->delta[v];
            st->delta[2 * v + 1] = st->delta[v];
        }
        st->flag[v] = false;
        st->sum[v] = st->delta[v] * (tr - tl + 1);
    }
}

int segmentTreeSetF(int a, int b) {
    return a + b;
}

void segmentTreeMaxSumInit(SegmentTreeMaxSum* st, int* a, int n) {
    st->pow = 1;
    while (st->pow < n) {
        st->pow *= 2;
    }
    st->sum = malloc(2 * st->pow * sizeof(int));
    st->maxPrefSum = malloc(2 * st->pow * sizeof(int));
    st->maxSufSum = malloc(2 * st->pow * sizeof(int));
    st->maxSum = malloc(2 * st->pow * sizeof(int));
    for (int i = 0; i < n; i++) {
        st->sum[st->pow + i] = a[i];
        st->maxSum[st->pow + i] = max(a[i], 0);
        st->maxPrefSum[st->pow + i] = st->maxSum[st->pow + i];
        st->maxSufSum[st->pow + i] = st->maxSum[st->pow + i];
    }
    for (int i = st->pow - 1; i > 0; i--) {
        segmentTreeMaxSumUpdate(st, i);
    }
}

int* segmentTreeMaxSumGet(SegmentTreeMaxSum* st, int v, int tl, int tr, int l, int r) {
    if (r <= tl || l >= tr) {
        int* ans = malloc(4 * sizeof(int));
        ans[0] = 0;
        ans[1] = 0;
        ans[2] = 0;
        ans[3] = 0;
        return ans;
    }
    if (l <= tl && r >= tr) {
        int* ans = malloc(4 * sizeof(int));
        ans[0] = st->maxPrefSum[v];
        ans[1] = st->maxSum[v];
        ans[2] = st->maxSufSum[v];
        ans[3] = st->sum[v];
        return ans;
    }
    int tm = (tl + tr) / 2;
    int* left = segmentTreeMaxSumGet(st, 2 * v, tl, tm, l, min(r, tm));
    int* right = segmentTreeMaxSumGet(st, 2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    int* ans = malloc(4 * sizeof(int));
    ans[0] = max(left[0], right[0] + left[3]);
    ans[1] = max(left[1], max(right[1], left[2] + right[0]));
    ans[2] = max(right[2], left[2] + right[3]);
    ans[3] = left[3] + right[3];
    free(left);
    free(right);
    return ans;
}

void segmentTreeMaxSumSet(SegmentTreeMaxSum* st, int v, int tl, int tr, int x, int value) {
    if (v >= st->pow) {
        st->sum[v] = value;
        st->maxSum[v] = max(value, 0);
        st->maxPrefSum[v] = st->maxSum[v];
        st->maxSufSum[v] = st->maxSum[v];
        return;
    }
    int tm = (tl + tr) / 2;
    if (x < tm) {
        segmentTreeMaxSumSet(st, 2 * v, tl, tm, x, value);
    } else {
        segmentTreeMaxSumSet(st, 2 * v + 1, tm + 1, tr, x, value);
    }
    segmentTreeMaxSumUpdate(st, v);
}

void segmentTreeMaxSumUpdate(SegmentTreeMaxSum* st, int i) {
    st->sum[i] = f(st->sum[2 * i], st->sum[2 * i + 1]);
    st->maxSum[i] = max(st->maxSum[2 * i], max(st->maxSum[2 * i + 1], st->maxSufSum[2 * i] + st->maxPrefSum[2 * i + 1]));
    st->maxPrefSum[i] = max(st->maxPrefSum[2 * i], st->maxPrefSum[2 * i + 1] + st->sum[2 * i]);
    st->maxSufSum[i] = max(st->maxSufSum[2 * i + 1], st->maxSufSum[2 * i] + st->sum[2 * i + 1]);
}

int segmentTreeMaxSumF(int a, int b) {
    return max(a, b);
}

void fenvikInit(Fenvik* f, int n) {
    f->t = malloc(n * sizeof(int));
}

void fenvikAdd(Fenvik* f, int x, int delta) {
    for (int i = x; i < sizeof(f->t) / sizeof(int); i = (i | (i + 1))) {
        f->t[i] += delta;
    }
}

int fenvikSum(Fenvik* f, int r) {
    int ans = 0;
    int x = r;
    while (x >= 0) {
        ans += f->t[x];
        x = (x & (x + 1)) - 1;
    }
    return ans;
}

int fenvikSumRange(Fenvik* f, int l, int r) {
    return fenvikSum(f, r) - fenvikSum(f, l - 1);
}

void polInit(Pol* p, double* coeff, int n) {
    p->coeff = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        p->coeff[i] = coeff[i];
    }
}

Pol polMult(Pol* p, Pol* q) {
    int n = sizeof(p->coeff) / sizeof(double);
    int m = sizeof(q->coeff) / sizeof(double);
    double* ans = malloc((n + m - 1) * sizeof(double));
    for (int i = 0; i < n + m - 1; i++) {
        ans[i] = 0;
        for (int j = max(0, i - m + 1); j < n && j <= i; j++) {
            ans[i] += p->coeff[j] * q->coeff[i - j];
        }
    }
    Pol result;
    polInit(&result, ans, n + m - 1);
    return result;
}

double polValue(Pol* p, double x) {
    double ans = 0;
    double pow = 1;
    int n = sizeof(p->coeff) / sizeof(double);
    for (int i = 0; i < n; i++) {
        ans += p->coeff[i] * pow;
        pow *= x;
    }
    return ans;
}

double polIntegrate(Pol* p, double r) {
    Pol result;
    polInit(&result, malloc((sizeof(p->coeff) / sizeof(double) + 1) * sizeof(double)), sizeof(p->coeff) / sizeof(double) + 1);
    for (int i = 0; i < sizeof(p->coeff) / sizeof(double); i++) {
        result.coeff[i + 1] = p->coeff[i] / fact[i + 1];
    }
    return polValue(&result, r);
}

double polIntegrateRange(Pol* p, double l, double r) {
    return polIntegrate(p, r) - polIntegrate(p, l);
}

void stackInit(Stack* s, int n) {
    s->st = malloc(n * sizeof(int));
    s->sz = 0;
}

bool stackIsEmpty(Stack* s) {
    return s->sz == 0;
}

int stackPeek(Stack* s) {
    return s->st[s->sz - 1];
}

int stackPop(Stack* s) {
    s->sz--;
    return s->st[s->sz];
}

void stackClear(Stack* s) {
    s->sz = 0;
}

void stackAdd(Stack* s, int x) {
    s->st[s->sz++] = x;
}

int stackGet(Stack* s, int x) {
    return s->st[x];
}

void dsu1Init(DSU1* dsu, int* v, int m, int n) {
    dsu->p = malloc(n * sizeof(int));
    dsu->sz = malloc(n * sizeof(int));
    dsu->less = malloc(sizeof(Stack));
    dsu->more = malloc(sizeof(Stack));
    dsu->q = malloc(n * sizeof(PriorityQueue*));
    dsu->used = malloc((n + 1) * sizeof(bool));
    for (int i = 0; i < n; i++) {
        dsu->p[i] = i;
        dsu->sz[i] = 1;
        dsu->q[i] = malloc(sizeof(PriorityQueue));
        priorityQueueInit(dsu->q[i]);
        priorityQueueAdd(dsu->q[i], -v[i]);
    }
    stackInit(dsu->less, m);
    stackInit(dsu->more, m);
    for (int i = 0; i <= n; i++) {
        dsu->used[i] = false;
    }
}

int dsu1Get(DSU1* dsu, int x) {
    while (x != dsu->p[x]) {
        x = dsu->p[x];
    }
    return x;
}

bool dsu1Unite(DSU1* dsu, int a, int b) {
    int pa = dsu1Get(dsu, a);
    int pb = dsu1Get(dsu, b);
    if (pa == pb) {
        stackAdd(dsu->less, -1);
        stackAdd(dsu->more, -1);
        return false;
    }
    if (dsu->sz[pa] < dsu->sz[pb]) {
        dsu->p[pa] = pb;
        dsu->sz[pb] += dsu->sz[pa];
        stackAdd(dsu->less, pa);
        stackAdd(dsu->more, pb);
        for (int i = 0; i < dsu->q[pa]->sz; i++) {
            priorityQueueAdd(dsu->q[pb], dsu->q[pa]->arr[i]);
        }
    } else {
        dsu->p[pb] = pa;
        dsu->sz[pa] += dsu->sz[pb];
        stackAdd(dsu->less, pb);
        stackAdd(dsu->more, pa);
        for (int i = 0; i < dsu->q[pb]->sz; i++) {
            priorityQueueAdd(dsu->q[pa], dsu->q[pb]->arr[i]);
        }
    }
    return true;
}

void dsu1PopEdge(DSU1* dsu) {
    int pa = stackPop(dsu->less);
    int pb = stackPop(dsu->more);
    if (pa < 0) {
        return;
    }
    dsu->p[pa] = pa;
    dsu->sz[pb] -= dsu->sz[pa];
}

int dsu1Poll(DSU1* dsu, int x) {
    int px = dsu1Get(dsu, x);
    while (!priorityQueueIsEmpty(dsu->q[px])) {
        int v = -priorityQueuePoll(dsu->q[px]);
        if (!dsu->used[v] && dsu1Get(dsu, inv[v - 1]) == px) {
            dsu->used[v] = true;
            return v;
        }
    }
    return 0;
}

void pointInit(Point* p, double x, double y) {
    p->x = x;
    p->y = y;
}

Point pointAdd(Point* p, Point* v) {
    Point result;
    pointInit(&result, p->x + v->x, p->y + v->y);
    return result;
}
