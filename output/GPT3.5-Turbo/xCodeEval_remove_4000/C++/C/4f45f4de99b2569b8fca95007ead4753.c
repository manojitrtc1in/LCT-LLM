#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 1000000007
#define MODL 1000000000000000003LL
#define eps 1e-8

typedef long long lld;
typedef unsigned long long u64;

typedef struct {
    int x;
    int y;
} pii;

int MIN(const int x, const int y) { return (x < y) ? x : y; }
int MAX(const int x, const int y) { return (x > y) ? x : y; }

void id1(int *x, const int y) { if (*x > y) *x = y; }
void id0(int *x, const int y) { if (*x < y) *x = y; }

int SIZE(const char *x) { int count = 0; while (x[count] != '\0') count++; return count; }
int LENGTH(const char *x) { int count = 0; while (x[count] != '\0') count++; return count; }

typedef struct {
    int first;
    int second;
} pair;

pair MP(const int x, const int y) {
    pair p;
    p.first = x;
    p.second = y;
    return p;
}

int BINT(const int x) { return 1 << x; }
lld BLLD(const int x) { return 1LL << x; }
int id9(const int s, const int x) { return (s & BINT(x)) != 0; }
int id5(const lld s, const int x) { return (s & BLLD(x)) != 0LL; }

int LOWBIT(const int x) { return (x ^ (x - 1)) & x; }
int BITCOUNT(const int x) { return (!x) ? x : (1 + BITCOUNT(x & (x - 1))); }

const double PI = acos(-1.0);
const double EPS = 1e-5;

int SQR(const int x) { return x * x; }

int POW(const int x, const int y) {
    if (!y) return 1;
    else if ((y & 1) == 0) {
        return SQR(POW(x, y >> 1));
    } else return POW(x, y ^ 1) * x;
}

int GCD(const int x, const int y) {
    if (x < 0) return GCD(-x, y);
    if (y < 0) return GCD(x, -y);
    return (!y) ? x : GCD(y, x % y);
}

int LCM(const int x, const int y) {
    if (x < 0) return LCM(-x, y);
    if (y < 0) return LCM(x, -y);
    return x * (y / GCD(x, y));
}

int EEA(const int a, const int b, int *x, int *y) {
    if (a < 0) { int d = EEA(-a, b, x, y); *x = -*x; return d; }
    if (b < 0) { int d = EEA(a, -b, x, y); *y = -*y; return d; }
    if (!b) {
        *x = 1;
        *y = 0;
        return a;
    } else {
        int d = EEA(b, a % b, x, y);
        int t = *x; *x = *y; *y = t - (a / b) * *y;
        return d;
    }
}

int id16(const int x) {
    if (x <= 1) return 0;
    for (int i = 2; SQR(i) <= x; i++) if (x % i == 0) return 0;
    return 1;
}

int id6(int x) {
    int f[50];
    int len = 0;
    memset(f, 0, sizeof(f));
    if (x < 0) x = -x;
    for (int i = 2; x > 1;) {
        if (x % i == 0) {
            int count = 0;
            for (; x % i == 0; x /= i) count++;
            f[len++] = i;
        }
        i++; if (i > x / i) i = x;
    }
    for (int i = 0; i < len; i++) {
        x = x / f[i] * (f[i] - 1);
    }
    return x;
}

int id14(const int a, const int b) {
    int x, y;
    EEA(a, b, &x, &y);
    return x ? x : 1;
}

int *id15(const int til, int *length) {
    int *foo = (int*)malloc(sizeof(int) * (til + 1));
    int len = 0;
    memset(foo, 0, sizeof(int) * (til + 1));
    for (int i = 2; i <= til; i++) {
        if (!foo[i]) foo[len++] = i;
        for (int j = 0; j < len && foo[j] <= til / i; j++) {
            foo[foo[j] * i] = 1;
            if (i % foo[j] == 0) break;
        }
    }
    if (length != NULL) {
        *length = len;
    }
    foo[len++] = 0;
    foo = (int*)realloc(foo, sizeof(int) * len);
    return foo;
}

int MOD_STD(const int x, const int m) { return (x % m + m) % m; }
void MOD_STD(int *x, const int m) { *x = (*x % m + m) % m; }
int MOD_ADD(const int x, const int y, const int m) { return (x + y) % m; }
void MOD_ADD(int *x, const int y, const int m) { *x = (*x + y) % m; }
int id4(const int x, const int y, const int m) { return (int)((1LL * x * y) % m); }
void id4(int *x, const int y, const int m) { *x = (int)((1LL * (*x) * y) % m); }
int id10(const int x, const int y, const int m) {
    if (y == 0) return 1 % m;
    else if ((y & 1) == 0) {
        int z = id10(x, y >> 1, m); return id4(z, z, m);
    } else return id4(id10(x, y ^ 1, m), x, m);
}

lld id12(lld x, lld y, const lld m) {
    if (x < y) swap(&x, &y);
    lld z = 0LL;
    while (y > 0) {
        if (y & 1) {
            MOD_ADD(&z, x, m);
        }
        MOD_ADD(&x, x, m);
        y >>= 1;
    }
    return z;
}

lld id3(const lld x, const lld y, const lld m) {
    if (y == 0LL) return 1LL % m;
    else if ((y & 1) == 0LL) {
        lld z = id3(x, y >> 1, m); return id12(z, z, m);
    } else return id12(id3(x, y ^ 1, m), x, m);
}

typedef struct {
    unsigned long hig;
    unsigned long wid;
    int *data;
} MATX;

MATX MATX_new() {
    MATX matx;
    matx.hig = 1;
    matx.wid = 1;
    matx.data = (int*)malloc(sizeof(int));
    matx.data[0] = 0;
    return matx;
}

MATX MATX_new_with_len(const unsigned long len) {
    MATX matx;
    matx.hig = len;
    matx.wid = len;
    matx.data = (int*)malloc(sizeof(int) * len * len);
    memset(matx.data, 0, sizeof(int) * len * len);
    return matx;
}

MATX MATX_new_with_hig_wid(const unsigned long hig, const unsigned long wid) {
    MATX matx;
    matx.hig = hig;
    matx.wid = wid;
    matx.data = (int*)malloc(sizeof(int) * hig * wid);
    memset(matx.data, 0, sizeof(int) * hig * wid);
    return matx;
}

MATX MATX_copy(const MATX *rhs) {
    MATX matx;
    matx.hig = rhs->hig;
    matx.wid = rhs->wid;
    matx.data = (int*)malloc(sizeof(int) * matx.hig * matx.wid);
    for (unsigned long x = 0; x < matx.hig; x++) {
        for (unsigned long y = 0; y < matx.wid; y++) {
            matx.data[x * matx.wid + y] = rhs->data[x * matx.wid + y];
        }
    }
    return matx;
}

void MATX_free(MATX *matx) {
    free(matx->data);
}

int MATX_at(const MATX *matx, const unsigned long x, const unsigned long y) {
    if (x >= matx->hig || y >= matx->wid) return 0;
    return matx->data[x * matx->wid + y];
}

void MATX_set(MATX *matx, const unsigned long x, const unsigned long y, const int val) {
    if (x >= matx->hig || y >= matx->wid) return;
    matx->data[x * matx->wid + y] = val;
}

MATX MATX_add(const MATX *opn1, const MATX *opn2) {
    MATX ret = MATX_new_with_hig_wid(opn1->hig, opn1->wid);
    for (unsigned long x = 0; x < ret.hig; x++) {
        for (unsigned long y = 0; y < ret.wid; y++) {
            ret.data[x * ret.wid + y] = opn1->data[x * ret.wid + y] + opn2->data[x * ret.wid + y];
        }
    }
    return ret;
}

MATX MATX_sub(const MATX *opn1, const MATX *opn2) {
    MATX ret = MATX_new_with_hig_wid(opn1->hig, opn1->wid);
    for (unsigned long x = 0; x < ret.hig; x++) {
        for (unsigned long y = 0; y < ret.wid; y++) {
            ret.data[x * ret.wid + y] = opn1->data[x * ret.wid + y] - opn2->data[x * ret.wid + y];
        }
    }
    return ret;
}

MATX MATX_mul(const MATX *opn1, const MATX *opn2) {
    MATX ret = MATX_new_with_hig_wid(opn1->hig, opn2->wid);
    const unsigned long len = MIN(opn1->wid, opn2->hig);
    for (unsigned long x = 0; x < ret.hig; x++) {
        for (unsigned long y = 0; y < ret.wid; y++) {
            for (unsigned long z = 0; z < len; z++) {
                ret.data[x * ret.wid + y] += opn1->data[x * opn1->wid + z] * opn2->data[z * opn2->wid + y];
            }
        }
    }
    return ret;
}

MATX MATX_mul_with_mod(const MATX *opn1, const MATX *opn2, const int m) {
    MATX ret = MATX_new_with_hig_wid(opn1->hig, opn2->wid);
    const unsigned long len = MIN(opn1->wid, opn2->wid);
    for (unsigned long x = 0; x < ret.hig; x++) {
        for (unsigned long y = 0; y < ret.wid; y++) {
            for (unsigned long z = 0; z < len; z++) {
                ret.data[x * ret.wid + y] = MOD_ADD(ret.data[x * ret.wid + y], id4(opn1->data[x * opn1->wid + z], opn2->data[z * opn2->wid + y], m), m);
            }
        }
    }
    return ret;
}

MATX MATX_pow(const MATX *matx, const unsigned long p) {
    MATX buff = MATX_copy(matx);
    MATX ret = MATX_new_with_hig_wid(matx->hig, matx->wid);
    for (unsigned long i = 0; i < ret.hig; i++) {
        for (unsigned long j = 0; j < ret.wid; j++) {
            if (i == j) ret.data[i * ret.wid + j] = 1;
            else ret.data[i * ret.wid + j] = 0;
        }
    }
    if (p > 0) {
        for (unsigned long i = 1;; i <<= 1) {
            if (p & i) ret = MATX_mul(&ret, &buff);
            buff = MATX_mul(&buff, &buff);
            if (i > (p >> 1)) break;
        }
    }
    return ret;
}

typedef struct {
    int r;
    int i;
} complex_t;

complex_t complex_t_new(const int x, const int y) {
    complex_t c;
    c.r = x;
    c.i = y;
    return c;
}

complex_t complex_t_add(const complex_t *opn1, const complex_t *opn2) {
    complex_t c;
    c.r = opn1->r + opn2->r;
    c.i = opn1->i + opn2->i;
    return c;
}

complex_t complex_t_sub(const complex_t *opn1, const complex_t *opn2) {
    complex_t c;
    c.r = opn1->r - opn2->r;
    c.i = opn1->i - opn2->i;
    return c;
}

complex_t complex_t_mul(const complex_t *opn1, const complex_t *opn2) {
    complex_t c;
    c.r = opn1->r * opn2->r - opn1->i * opn2->i;
    c.i = opn1->r * opn2->i + opn1->i * opn2->r;
    return c;
}

int fsign(const double x) {
    if (x > -eps && x < eps) return 0;
    return (x < 0.0) ? -1 : 1;
}

typedef struct {
    int x;
    int y;
} point_t;

point_t point_t_new() {
    point_t p;
    p.x = 0.0;
    p.y = 0.0;
    return p;
}

point_t point_t_new_with_xy(const int x, const int y) {
    point_t p;
    p.x = x;
    p.y = y;
    return p;
}

point_t point_t_sub(const point_t *opn1, const point_t *opn2) {
    point_t p;
    p.x = opn1->x - opn2->x;
    p.y = opn1->y - opn2->y;
    return p;
}

int point_t_cross(const point_t *p, const point_t *q) {
    return p->x * q->y - p->y * q->x;
}

int point_t_dot(const point_t *p, const point_t *q) {
    return p->x * q->x + p->y * q->y;
}

int point_t_less(const point_t *lhs, const point_t *rhs) {
    if (fsign(lhs->y - rhs->y) != 0) return fsign(lhs->y - rhs->y) < 0;
    return fsign(lhs->x - rhs->x) < 0;
}

int point_t_cross_3(const point_t *p, const point_t *q, const point_t *r) {
    return point_t_cross(&point_t_sub(p, r), &point_t_sub(q, r));
}

void point_t_rotate(point_t *p, const double radian) {
    int x0 = p->x, y0 = p->y;
    double sinr = sin(radian);
    double cosr = cos(radian);
    p->x = x0 * cosr - y0 * sinr;
    p->y = x0 * sinr + y0 * cosr;
}

void point_t_rotate_with_p(point_t *p, const point_t *q, const double radian) {
    int x0 = p->x - q->x, y0 = p->y - q->y;
    double sinr = sin(radian);
    double cosr = cos(radian);
    p->x = x0 * cosr - y0 * sinr + q->x;
    p->y = x0 * sinr + y0 * cosr + q->y;
}

int point_t_dist2(const point_t *lhs, const point_t *rhs) {
    return point_t_dot(&point_t_sub(lhs, rhs), &point_t_sub(lhs, rhs));
}

double point_t_dist(const point_t *lhs, const point_t *rhs) {
    return sqrt(point_t_dist2(lhs, rhs));
}

typedef struct {
    point_t p;
    point_t q;
} segment_t;

segment_t segment_t_new() {
    segment_t seg;
    seg.p = point_t_new();
    seg.q = point_t_new();
    return seg;
}

segment_t segment_t_new_with_pq(const point_t *p, const point_t *q) {
    segment_t seg;
    seg.p = *p;
    seg.q = *q;
    return seg;
}

segment_t segment_t_new_with_pq_xy(const int px, const int py, const int qx, const int qy) {
    segment_t seg;
    seg.p = point_t_new_with_xy(px, py);
    seg.q = point_t_new_with_xy(qx, qy);
    return seg;
}

int segment_t_length(const segment_t *seg) {
    return point_t_dist(&seg->p, &seg->q);
}

int segment_t_length2(const segment_t *seg) {
    return point_t_dist2(&seg->p, &seg->q);
}

int segment_t_contain(const segment_t *seg, const point_t *pnt, const int ignore_endpoint) {
    if (ignore_endpoint) {
        return fsign(point_t_cross_3(&seg->p, &seg->q, pnt)) == 0
            && fsign((pnt->x - seg->p.x) * (pnt->x - seg->q.x)) < 0
            && fsign((pnt->y - seg->p.y) * (pnt->y - seg->q.y)) < 0;
    } else {
        return fsign(point_t_cross_3(&seg->p, &seg->q, pnt)) == 0
            && fsign((pnt->x - seg->p.x) * (pnt->x - seg->q.x)) <= 0
            && fsign((pnt->y - seg->p.y) * (pnt->y - seg->q.y)) <= 0;
    }
}

int segment_t_intersection(const segment_t *sa, const segment_t *sb, const int ignore_endpoint) {
    if (!ignore_endpoint) {
        if (segment_t_contain(sa, &sb->p, 0) || segment_t_contain(sa, &sb->q, 0) || segment_t_contain(sb, &sa->p, 0) || segment_t_contain(sb, &sa->q, 0))
            return 1;
    }
    return fsign(point_t_cross_3(&sa->p, &sa->q, &sb->p)) * fsign(point_t_cross_3(&sa->p, &sa->q, &sb->q)) < 0
        && fsign(point_t_cross_3(&sb->p, &sb->q, &sa->p)) * fsign(point_t_cross_3(&sb->p, &sb->q, &sa->q)) < 0;
}

int segment_t_intersection_with_seg(const segment_t *seg1, const segment_t *seg2, const int ignore_endpoint) {
    return segment_t_intersection(seg1, seg2, ignore_endpoint);
}

typedef struct {
    int foo[50];
    int sup[50];
} id13;

void id13_clear(id13 *obj) {
    memset(obj->foo, 0, sizeof(obj->foo));
    memset(obj->sup, 0, sizeof(obj->sup));
}

void id13_put(id13 *obj, const int key, const int val) {
    if (val == 0) return;
    if (obj->foo[key]) {
        obj->foo[key] += val;
    } else {
        obj->foo[key] = val;
    }
}

int id13_pop(id13 *obj, const int key, const int val) {
    int res = 0;
    if (obj->foo[key]) {
        if (obj->foo[key] > val) {
            res = val;
            obj->foo[key] -= val;
        } else {
            res = obj->foo[key];
            obj->foo[key] = 0;
        }
    }
    return res;
}

int n;
lld a[110000];
int _seq[50], _sup[50];
int seq[50], sup[50];

int process(const int from) {
    for (int i = 0; i < 50; i++) seq[i] = _seq[i];
    for (int i = 0; i < 50; i++) sup[i] = _sup[i];
    if (from + from < seq[0]) return 1;
    id13_clear(&open);
    id13_clear(&close);
    id13_put(&open, 0, from - (seq[0] - from));
    id13_put(&close, 0, seq[0] - from);
    for (int i = 1; i < 45; i++) {
        int ext = id13_pop(&open, i - 1, seq[i]);
        seq[i] -= ext;
        id13_put(&open, i, ext);
        ext = id13_pop(&close, i - 1, seq[i]);
        sup[i] += seq[i] - ext;
        id13_put(&close, i, ext);
        int cls = id13_pop(&open, i, sup[i]);
        sup[i + 1] += sup[i] - cls;
        id13_put(&close, i, cls);
    }
    if (sup[45] != 0) return 1;
    return 0;
}

int find(int lef, int rig) {
    while (lef <= rig) {
        int mid = (lef + rig) >> 1;
        if (!process(mid)) {
            if (mid == lef || process(mid - 1)) {
                return mid;
            }
            rig = mid - 1;
        } else lef = mid + 1;
    }
    return -1;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        for (int i = 0; i < 50; i++) {
            _seq[i] = 0;
            _sup[i] = 0;
        }
        int cur = 0;
        for (int i = 0; i < n; i++) {
            while (a[i] >= (1LL << (cur + 1))) cur++;
            if (a[i] == (1LL << cur)) {
                _seq[cur]++;
            } else {
                _sup[cur]++;
            }
        }
        if (process(_seq[0])) {
            printf("-1\n");
        } else {
            int hig = _seq[0];
            int low = find(1, hig);
            for (int i = low; i <= hig; i++) {
                if (i != low) printf(" ");
                printf("%d", i);
            }
            printf("\n");
        }
    }
    return 0;
}
