#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 100000

typedef struct {
    int *sz;
    int *p;
} DSU;

DSU* createDSU(int n) {
    DSU *dsu = (DSU*)malloc(sizeof(DSU));
    dsu->sz = (int*)malloc(n * sizeof(int));
    dsu->p = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        dsu->p[i] = i;
        dsu->sz[i] = 1;
    }
    return dsu;
}

int get(DSU *dsu, int x) {
    if (x == dsu->p[x]) {
        return x;
    }
    int par = get(dsu, dsu->p[x]);
    dsu->p[x] = par;
    return par;
}

bool unite(DSU *dsu, int a, int b) {
    int pa = get(dsu, a);
    int pb = get(dsu, b);
    if (pa == pb) {
        return false;
    }
    if (dsu->sz[pa] < dsu->sz[pb]) {
        dsu->p[pa] = pb;
        dsu->sz[pb] += dsu->sz[pa];
    } else {
        dsu->p[pb] = pa;
        dsu->sz[pa] += dsu->sz[pb];
    }
    return true;
}

typedef struct {
    int pow;
    long *max;
    long *delta;
    bool *flag;
} id2;

id2* createid2(long *a, int n) {
    id2 *id = (id2*)malloc(sizeof(id2));
    id->pow = 1;
    while (id->pow < n) {
        id->pow *= 2;
    }
    id->flag = (bool*)malloc(2 * id->pow * sizeof(bool));
    id->max = (long*)malloc(2 * id->pow * sizeof(long));
    id->delta = (long*)malloc(2 * id->pow * sizeof(long));
    for (int i = 0; i < 2 * id->pow; i++) {
        id->max[i] = LONG_MIN / 2;
    }
    for (int i = 0; i < n; i++) {
        id->max[id->pow + i] = a[i];
    }
    for (int i = id->pow - 1; i > 0; i--) {
        id->max[i] = f(id->max[2 * i], id->max[2 * i + 1]);
    }
    return id;
}

long get(id2 *id, int v, int tl, int tr, int l, int r) {
    push(id, v, tl, tr);
    if (l > r) {
        return LONG_MIN / 2;
    }
    if (l == tl && r == tr) {
        return id->max[v];
    }
    int tm = (tl + tr) / 2;
    return f(get(id, 2 * v, tl, tm, l, min(r, tm)), get(id, 2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void set(id2 *id, int v, int tl, int tr, int l, int r, long x) {
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

void push(id2 *id, int v, int tl, int tr) {
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

long f(long a, long b) {
    return max(a, b);
}

typedef struct {
    int pow;
    int *sum;
    int *delta;
    bool *flag;
} id5;

id5* createid5(int *a, int n) {
    id5 *id = (id5*)malloc(sizeof(id5));
    id->pow = 1;
    while (id->pow < n) {
        id->pow *= 2;
    }
    id->flag = (bool*)malloc(2 * id->pow * sizeof(bool));
    id->sum = (int*)malloc(2 * id->pow * sizeof(int));
    id->delta = (int*)malloc(2 * id->pow * sizeof(int));
    for (int i = 0; i < n; i++) {
        id->sum[id->pow + i] = a[i];
    }
    return id;
}

int get(id5 *id, int v, int tl, int tr, int l, int r) {
    push(id, v, tl, tr);
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return id->sum[v];
    }
    int tm = (tl + tr) / 2;
    return f(get(id, 2 * v, tl, tm, l, min(r, tm)), get(id, 2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void set(id5 *id, int v, int tl, int tr, int l, int r, int x) {
    push(id, v, tl, tr);
    if (l > tr || r < tl) {
        return;
    }
    if (l <= tl && r >= tr) {
        id->delta[v] = x;
        id->flag[v] = true;
        push(id, v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    set(id, 2 * v, tl, tm, l, r, x);
    set(id, 2 * v + 1, tm + 1, tr, l, r, x);
    id->sum[v] = f(id->sum[2 * v], id->sum[2 * v + 1]);
}

void push(id5 *id, int v, int tl, int tr) {
    if (id->flag[v]) {
        if (v < id->pow) {
            id->flag[2 * v] = true;
            id->flag[2 * v + 1] = true;
            id->delta[2 * v] = id->delta[v];
            id->delta[2 * v + 1] = id->delta[v];
        }
        id->flag[v] = false;
        id->sum[v] = id->delta[v] * (tr - tl + 1);
    }
}

int f(int a, int b) {
    return a + b;
}

typedef struct {
    int x;
    int y;
} Pair;

int comparePair(const void *a, const void *b) {
    Pair *p1 = (Pair*)a;
    Pair *p2 = (Pair*)b;
    if (p1->y > p2->y) {
        return 1;
    }
    if (p1->y < p2->y) {
        return -1;
    }
    if (p1->x > p2->x) {
        return 1;
    }
    if (p1->x < p2->x) {
        return -1;
    }
    return 0;
}

typedef struct {
    long mod;
    int small;
    double eps;
    long max;
    double sq2;
} E;

E* createE() {
    E *e = (E*)malloc(sizeof(E));
    e->mod = 1000000007;
    e->small = 20;
    e->eps = 1e-10;
    e->max = LONG_MAX / 2;
    e->sq2 = sqrt(2);
    return e;
}

int signum(E *e, double x) {
    if (x > e->eps) {
        return 1;
    }
    if (x < -e->eps) {
        return -1;
    }
    return 0;
}

long abs(E *e, long x) {
    return x < 0 ? -x : x;
}

long min(E *e, long x, long y) {
    return x < y ? x : y;
}

long max(E *e, long x, long y) {
    return x > y ? x : y;
}

long gcd(E *e, long x, long y) {
    while (y > 0) {
        long c = y;
        y = x % y;
        x = c;
    }
    return x;
}

typedef struct {
    double x;
    double y;
} Point;

Point* createPoint() {
    Point *p = (Point*)malloc(sizeof(Point));
    p->x = 0;
    p->y = 0;
    return p;
}

Point* createPointWithValues(double x, double y) {
    Point *p = (Point*)malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    return p;
}

int comparePoint(const void *a, const void *b) {
    Point *p1 = (Point*)a;
    Point *p2 = (Point*)b;
    int z = signum(p1->x + p1->y - p2->x - p2->y);
    if (z != 0) {
        return z;
    }
    return signum(p1->x - p2->x) != 0 ? signum(p1->x - p2->x) : signum(p1->y - p2->y);
}

typedef struct {
    Point *p;
    int r;
} Circle;

Circle* createCircle(Point *p, int r) {
    Circle *c = (Circle*)malloc(sizeof(Circle));
    c->p = p;
    c->r = r;
    return c;
}

Point* angle(Circle *c, E *e) {
    double z = c->r / e->sq2;
    z -= fmod(z, 1e-5);
    return createPointWithValues(c->p->x - z, c->p->y - z);
}

bool inside(Circle *c, Point *p, E *e) {
    return id0(p->x - c->p->x, p->y - c->p->y) <= sq(c->r);
}

typedef struct {
    long x;
    long y;
} Fraction;

Fraction* createFraction(long x, long y, bool needNorm) {
    Fraction *f = (Fraction*)malloc(sizeof(Fraction));
    f->x = x;
    f->y = y;
    if (y < 0) {
        f->x *= -1;
        f->y *= -1;
    }
    if (needNorm) {
        long gcd = gcd(f->x, f->y);
        f->x /= gcd;
        f->y /= gcd;
    }
    return f;
}

int compareFraction(const void *a, const void *b) {
    Fraction *f1 = (Fraction*)a;
    Fraction *f2 = (Fraction*)b;
    long res = f1->x * f2->y - f1->y * f2->x;
    if (res > 0) {
        return 1;
    }
    if (res < 0) {
        return -1;
    }
    return 0;
}

typedef struct {
    int x1;
    int x2;
    int y1;
    int y2;
    int number;
} Rect;

typedef struct {
    int *t;
} id6;

id6* createid6(int n) {
    id6 *id = (id6*)malloc(sizeof(id6));
    id->t = (int*)malloc(n * sizeof(int));
    return id;
}

void add(id6 *id, int x, int delta) {
    for (int i = x; i < n; i = (i | (i + 1))) {
        id->t[i] += delta;
    }
}

int sum(id6 *id, int r) {
    int ans = 0;
    int x = r;
    while (x >= 0) {
        ans += id->t[x];
        x = (x & (x + 1)) - 1;
    }
    return ans;
}

int sumRange(id6 *id, int l, int r) {
    return sum(id, r) - sum(id, l - 1);
}

typedef struct {
    int pow;
    int *sum;
    int *id3;
    int *id7;
    int *maxSum;
} id4;

id4* createid4(int *a, int n) {
    id4 *id = (id4*)malloc(sizeof(id4));
    id->pow = 1;
    while (id->pow < n) {
        id->pow *= 2;
    }
    id->sum = (int*)malloc(2 * id->pow * sizeof(int));
    id->id3 = (int*)malloc(2 * id->pow * sizeof(int));
    id->id7 = (int*)malloc(2 * id->pow * sizeof(int));
    id->maxSum = (int*)malloc(2 * id->pow * sizeof(int));
    for (int i = 0; i < n; i++) {
        id->sum[id->pow + i] = a[i];
        id->maxSum[id->pow + i] = max(a[i], 0);
        id->id3[id->pow + i] = id->maxSum[id->pow + i];
        id->id7[id->pow + i] = id->maxSum[id->pow + i];
    }
    for (int i = id->pow - 1; i > 0; i--) {
        update(id, i);
    }
    return id;
}

int* get(id4 *id, int v, int tl, int tr, int l, int r) {
    if (r <= tl || l >= tr) {
        int *ans = (int*)malloc(4 * sizeof(int));
        for (int i = 0; i < 4; i++) {
            ans[i] = 0;
        }
        return ans;
    }
    if (l <= tl && r >= tr) {
        int *ans = (int*)malloc(4 * sizeof(int));
        ans[0] = id->id3[v];
        ans[1] = id->maxSum[v];
        ans[2] = id->id7[v];
        ans[3] = id->sum[v];
        return ans;
    }
    int tm = (tl + tr) / 2;
    int *left = get(id, 2 * v, tl, tm, l, r);
    int *right = get(id, 2 * v + 1, tm + 1, tr, l, r);
    int *ans = (int*)malloc(4 * sizeof(int));
    ans[0] = max(left[0], right[0] + left[3]);
    ans[1] = max(left[1], max(right[1], left[2] + right[0]));
    ans[2] = max(right[2], left[2] + right[3]);
    ans[3] = left[3] + right[3];
    return ans;
}

void set(id4 *id, int v, int tl, int tr, int x, int value) {
    if (v >= id->pow) {
        id->sum[v] = value;
        id->maxSum[v] = max(value, 0);
        id->id3[v] = id->maxSum[v];
        id->id7[v] = id->maxSum[v];
        return;
    }
    int tm = (tl + tr) / 2;
    if (x < tm) {
        set(id, 2 * v, tl, tm, x, value);
    } else {
        set(id, 2 * v + 1, tm + 1, tr, x, value);
    }
    update(id, v);
}

void update(id4 *id, int i) {
    id->sum[i] = f(id->sum[2 * i], id->sum[2 * i + 1]);
    id->maxSum[i] = max(id->maxSum[2 * i], max(id->maxSum[2 * i + 1], id->id7[2 * i] + id->id3[2 * i + 1]));
    id->id3[i] = max(id->id3[2 * i], id->id3[2 * i + 1] + id->sum[2 * i]);
    id->id7[i] = max(id->id7[2 * i + 1], id->id7[2 * i] + id->sum[2 * i + 1]);
}

typedef struct {
    int x;
    int y;
} Event;

int compareEvent(const void *a, const void *b) {
    Event *e1 = (Event*)a;
    Event *e2 = (Event*)b;
    int c = compareFraction(&(e1->f), &(e2->f));
    if (c != 0) {
        return c;
    }
    return e1->type - e2->type;
}

typedef struct {
    int *t;
    int sz;
} Stack;

Stack* createStack(int n) {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->t = (int*)malloc(n * sizeof(int));
    s->sz = 0;
    return s;
}

bool isEmpty(Stack *s) {
    return s->sz == 0;
}

int peek(Stack *s) {
    return s->t[s->sz - 1];
}

int pop(Stack *s) {
    s->sz--;
    return s->t[s->sz];
}

void clear(Stack *s) {
    s->sz = 0;
}

void add(Stack *s, int x) {
    s->t[s->sz++] = x;
}

int get(Stack *s, int x) {
    return s->t[x];
}

typedef struct {
    int x1;
    int x2;
    int y1;
    int y2;
    int number;
} Rect;

typedef struct {
    int *p;
    int *sz;
    Stack *less;
    Stack *more;
    Stack **q;
    bool *used;
} id1;

id1* createid1(int *v, int m) {
    id1 *id = (id1*)malloc(sizeof(id1));
    int n = sizeof(v) / sizeof(v[0]);
    id->p = (int*)malloc(n * sizeof(int));
    id->sz = (int*)malloc(n * sizeof(int));
    id->q = (Stack**)malloc(n * sizeof(Stack*));
    id->less = createStack(m);
    id->more = createStack(m);
    id->used = (bool*)malloc((n + 1) * sizeof(bool));
    for (int i = 0; i < n; i++) {
        id->p[i] = i;
        id->sz[i] = 1;
        id->q[i] = createStack(m);
        add(id->q[i], -v[i]);
    }
    return id;
}

int get(id1 *id, int x) {
    while (x != id->p[x]) {
        x = id->p[x];
    }
    return x;
}

bool unite(id1 *id, int a, int b) {
    int pa = get(id, a);
    int pb = get(id, b);
    if (pa == pb) {
        add(id->less, -1);
        add(id->more, -1);
        return false;
    }
    if (id->sz[pa] < id->sz[pb]) {
        id->p[pa] = pb;
        id->sz[pb] += id->sz[pa];
        add(id->less, pa);
        add(id->more, pb);
        for (int i = 0; i < id->q[pa]->sz; i++) {
            add(id->q[pb], get(id->q[pa], i));
        }
    } else {
        id->p[pb] = pa;
        id->sz[pa] += id->sz[pb];
        add(id->less, pb);
        add(id->more, pa);
        for (int i = 0; i < id->q[pb]->sz; i++) {
            add(id->q[pa], get(id->q[pb], i));
        }
    }
    return true;
}

void popEdge(id1 *id) {
    int pa = pop(id->less);
    int pb = pop(id->more);
    if (pa < 0) {
        return;
    }
    id->p[pa] = pa;
    id->sz[pb] -= id->sz[pa];
}

int poll(id1 *id, int x) {
    int px = get(id, x);
    while (!isEmpty(id->q[px])) {
        int v = -pop(id->q[px]);
        if (!id->used[v] && get(inv[v - 1]) == px) {
            id->used[v] = true;
            return v;
        }
    }
    return 0;
}

void solve() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    int *v = (int*)malloc(n * sizeof(int));
    int *inv = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        inv[v[i] - 1] = i;
    }
    int *a = (int*)malloc(m * sizeof(int));
    int *b = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }
    bool *type = (bool*)malloc(q * sizeof(bool));
    int *x = (int*)malloc(q * sizeof(int));
    bool *removed = (bool*)malloc(m * sizeof(bool));
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d", &x[i]);
            type[i] = true;
        } else {
            scanf("%d", &x[i]);
            removed[x[i]] = true;
        }
    }
    id1 *dsu = createid1(v, m);
    for (int i = 0; i < m; i++) {
        if (!removed[i]) {
            unite(dsu, a[i], b[i]);
        }
    }
    for (int i = q - 1; i >= 0; i--) {
        if (!type[i]) {
            popEdge(dsu);
        }
    }
    for (int i = 0; i < q; i++) {
        if (type[i]) {
            printf("%d\n", poll(dsu, x[i]));
        } else {
            popEdge(dsu);
        }
    }
}

int main() {
    solve();
    return 0;
}
