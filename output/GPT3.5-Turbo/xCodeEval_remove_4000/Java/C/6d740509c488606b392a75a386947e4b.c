#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

typedef struct {
    int m;
} Modular;

Modular new_Modular(int m) {
    Modular mod;
    mod.m = m;
    return mod;
}

int valueOf(Modular mod, int x) {
    x %= mod.m;
    if (x < 0) {
        x += mod.m;
    }
    return x;
}

int mul(Modular mod, int x, int y) {
    return valueOf(mod, (long long)x * y);
}

int plus(Modular mod, int x, int y) {
    return valueOf(mod, x + y);
}

typedef struct {
    int size;
    int cap;
    int *data;
} IntList;

IntList new_IntList(int cap) {
    IntList list;
    list.size = 0;
    list.cap = cap;
    if (cap == 0) {
        list.data = NULL;
    } else {
        list.data = (int *)malloc(cap * sizeof(int));
    }
    return list;
}

IntList clone(IntList list) {
    IntList ans;
    ans.size = list.size;
    ans.cap = list.cap;
    ans.data = (int *)malloc(ans.cap * sizeof(int));
    for (int i = 0; i < ans.size; i++) {
        ans.data[i] = list.data[i];
    }
    return ans;
}

void ensureSpace(IntList *list, int req) {
    if (req > list->cap) {
        while (list->cap < req) {
            list->cap = list->cap + 10 > 2 * list->cap ? list->cap + 10 : 2 * list->cap;
        }
        list->data = (int *)realloc(list->data, list->cap * sizeof(int));
    }
}

void checkRange(IntList *list, int i) {
    if (i < 0 || i >= list->size) {
        printf("ArrayIndexOutOfBoundsException\n");
        exit(1);
    }
}

int get(IntList *list, int i) {
    checkRange(list, i);
    return list->data[i];
}

void addAll(IntList *list, int *x, int offset, int len) {
    ensureSpace(list, list->size + len);
    for (int i = 0; i < len; i++) {
        list->data[list->size + i] = x[offset + i];
    }
    list->size += len;
}

void addAll_IntList(IntList *list, IntList *another) {
    addAll(list, another->data, 0, another->size);
}

void expandWith(IntList *list, int x, int len) {
    ensureSpace(list, list->size + len);
    for (int i = 0; i < len; i++) {
        list->data[list->size + i] = x;
    }
    list->size += len;
}

void retain(IntList *list, int n) {
    if (n < 0) {
        printf("IllegalArgumentException\n");
        exit(1);
    }
    if (n >= list->size) {
        return;
    }
    list->size = n;
}

int size(IntList *list) {
    return list->size;
}

int *toArray(IntList *list) {
    int *arr = (int *)malloc(list->size * sizeof(int));
    for (int i = 0; i < list->size; i++) {
        arr[i] = list->data[i];
    }
    return arr;
}

void clear(IntList *list) {
    list->size = 0;
}

int rankOf(IntList *p) {
    int r = p->size - 1;
    while (r >= 0 && p->data[r] == 0) {
        r--;
    }
    return r >= 0 ? r : 0;
}

void normalize(IntList *list) {
    retain(list, rankOf(list) + 1);
}

typedef struct {
    int m;
    int *wCache;
    int *invCache;
} id9;

id9 new_id9(Modular mod, int g) {
    id9 ntt;
    ntt.m = mod.m;
    ntt.wCache = (int *)malloc(30 * sizeof(int));
    ntt.invCache = (int *)malloc(30 * sizeof(int));
    for (int i = 0; i < 30; i++) {
        int s = 1 << i;
        ntt.wCache[i] = pow(g, (mod.m - 1) / 2 / s, mod.m);
        ntt.invCache[i] = pow(s, mod.m - 2, mod.m);
    }
    return ntt;
}

void dotMul(id9 *ntt, int *a, int *b, int *c, int m) {
    int n = 1 << m;
    for (int i = 0; i < n; i++) {
        c[i] = mul(ntt->m, a[i], b[i]);
    }
}

void prepareReverse(int *r, int b) {
    int n = 1 << b;
    r[0] = 0;
    for (int i = 1; i < n; i++) {
        r[i] = (r[i >> 1] >> 1) | ((1 & i) << (b - 1));
    }
}

void dft(id9 *ntt, int *p, int m) {
    int n = 1 << m;

    int *rev = (int *)malloc(n * sizeof(int));
    prepareReverse(rev, m);

    for (int i = 0; i < n; i++) {
        if (rev[i] > i) {
            int tmp = p[i];
            p[i] = p[rev[i]];
            p[rev[i]] = tmp;
        }
    }

    int w = 0;
    int t = 0;
    for (int d = 0; d < m; d++) {
        int w1 = ntt->wCache[d];
        int s = 1 << d;
        int s2 = s << 1;
        for (int i = 0; i < n; i += s2) {
            w = 1;
            for (int j = 0; j < s; j++) {
                int a = i + j;
                int b = a + s;
                t = mul(ntt->m, w, p[b]);
                p[b] = plus(ntt->m, p[a], -t);
                p[a] = plus(ntt->m, p[a], t);
                w = mul(ntt->m, w, w1);
            }
        }
    }

    free(rev);
}

void idft(id9 *ntt, int *p, int m) {
    dft(ntt, p, m);

    int n = 1 << m;
    int invN = ntt->invCache[m];

    p[0] = mul(ntt->m, p[0], invN);
    p[n / 2] = mul(ntt->m, p[n / 2], invN);
    for (int i = 1, until = n / 2; i < until; i++) {
        int a = p[n - i];
        p[n - i] = mul(ntt->m, p[i], invN);
        p[i] = mul(ntt->m, a, invN);
    }
}

void id1(id9 *ntt, IntList *lists, IntList *ans) {
    int n = lists->size;

    IntList *pqs = (IntList *)malloc(n * sizeof(IntList));
    for (int i = 0; i < n; i++) {
        pqs[i] = clone(lists[i]);
    }

    while (n > 1) {
        IntList *a = &pqs[0];
        IntList *b = &pqs[1];
        dotMul(ntt, a->data, b->data, a->data, rankOf(a) + rankOf(b) + 1);
        normalize(a);
        free(b->data);
        free(b);
        for (int i = 1; i < n - 1; i++) {
            pqs[i] = pqs[i + 1];
        }
        n--;
    }

    IntList *last = &pqs[0];
    ans->size = 0;
    addAll_IntList(ans, last);
    free(last->data);
    free(last);
    free(pqs);
}

int pow(int x, int n, int mod) {
    int res = 1;
    for (long long p = x; n > 0; n >>= 1, p = (p * p) % mod) {
        if ((n & 1) != 0) {
            res = (int)((long long)res * p % mod);
        }
    }
    return res;
}

void ntt(int *a, int n, int invert, int mod, int root) {
    int shift = 32 - __builtin_clz(n - 1);
    for (int i = 1; i < n; i++) {
        int j = __builtin_bswap32(i << shift);
        if (i < j) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }

    int root_inv = pow(root, mod - 2, mod);

    for (int len = 1; len < n; len <<= 1) {
        int wlen = pow(invert ? root_inv : root, (mod - 1) / (2 * len), mod);
        for (int i = 0; i < n; i += 2 * len) {
            int w = 1;
            for (int j = 0; j < len; ++j) {
                int a = i + j;
                int b = a + len;
                int u = a[a];
                int v = (int)((long long)a[b] * w % mod);
                a[b] = plus(mod, u, -v);
                a[a] = plus(mod, u, v);
                w = mul(mod, w, wlen);
            }
        }
    }

    if (invert) {
        int nrev = pow(n, mod - 2, mod);
        for (int i = 0; i < n; ++i) {
            a[i] = mul(mod, a[i], nrev);
        }
    }
}

int gcd(int a, int b) {
    return a >= b ? id7(a, b) : id7(b, a);
}

int id7(int a, int b) {
    return b == 0 ? a : id7(b, a % b);
}

int id0(int x, int c, int n) {
    int xi = x;
    int xj = x;
    int j = 2;
    int i = 1;
    while (i < n) {
        i++;
        xi = (long long)xi * xi + c;
        if (xi >= n) {
            xi -= n;
        }
        int g = gcd(n, abs(xi - xj));
        if (g != 1 && g != n) {
            return g;
        }
        if (i == j) {
            j = j << 1;
            xj = xi;
        }
    }
    return -1;
}

typedef struct {
    int m;
    int *factors;
    Modular mod;
    Power pow;
    int phi;
} PrimitiveRoot;

PrimitiveRoot new_PrimitiveRoot(Modular x) {
    PrimitiveRoot root;
    root.mod = x;
    root.pow = new_Power(x);
    root.phi = x.m - 1;
    root.factors = (int *)malloc(root.phi * sizeof(int));
    int cnt = 0;
    for (int i = 2; i <= root.phi; i++) {
        if (root.phi % i == 0) {
            root.factors[cnt++] = i;
        }
    }
    return root;
}

PrimitiveRoot new_PrimitiveRoot_int(int x) {
    return new_PrimitiveRoot(new_Modular(x));
}

int id3(PrimitiveRoot *root) {
    return id3_since(root, 2);
}

int id3_since(PrimitiveRoot *root, int since) {
    for (int i = since; i < root->mod.m; i++) {
        int flag = 1;
        for (int j = 0; j < root->phi; j++) {
            if (pow(root->pow, i, root->phi / root->factors[j]) == 1) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            return i;
        }
    }
    return -1;
}

typedef struct {
    int m;
    Power power;
    Modular modular;
    int *data;
} id6;

id6 new_id6() {
    id6 rho;
    rho.m = 0;
    rho.power = new_Power(new_Modular(0));
    rho.modular = new_Modular(0);
    rho.data = NULL;
    return rho;
}

int findFactor(id6 *rho, int n) {
    if (mr(rho->m, n, 10)) {
        return n;
    }
    while (1) {
        int f = id0(rho->power.pow(0, n), rho->power.pow(0, n), n);
        if (f != -1) {
            return f;
        }
    }
}

int id2(id6 *rho, int n, int *map) {
    if (n == 1) {
        return;
    }
    int f = findFactor(rho, n);
    if (f == n) {
        int value = map[f];
        if (value == 0) {
            value = 1;
        }
        map[f] = value * f;
        return;
    }
    id2(rho, f, map);
    id2(rho, n / f, map);
}

void id2_map(id6 *rho, int n, int *map) {
    id2(rho, n, map);
}

typedef struct {
    int m;
    Power power;
    Modular modular;
    Random random;
} id8;

id8 new_id8(Modular modular) {
    id8 mr;
    mr.modular = modular;
    mr.power = new_Power(modular);
    mr.random = new_Random();
    return mr;
}

int mr(id8 *mr, int n, int s) {
    if (n == 2) {
        return 1;
    }
    if (n % 2 == 0) {
        return 0;
    }
    for (int i = 0; i < s; i++) {
        int x = nextInt(&mr->random, n - 2) + 2;
        if (!mr0(mr, x, n)) {
            return 0;
        }
    }
    return 1;
}

int mr0(id8 *mr, int x, int n) {
    int exp = n - 1;
    while (1) {
        int y = pow(mr->power, x, exp);
        if (y != 1 && y != n - 1) {
            return 0;
        }
        if (y != 1 || exp % 2 == 1) {
            break;
        }
        exp = exp / 2;
    }
    return 1;
}

typedef struct {
    int m;
    Power power;
    Modular modular;
} Power;

Power new_Power(Modular modular) {
    Power power;
    power.modular = modular;
    return power;
}

int pow(Power power, int x, int n) {
    if (n == 0) {
        return valueOf(power.modular, 1);
    }
    long long r = pow(power, x, n >> 1);
    r = valueOf(power.modular, r * r);
    if ((n & 1) == 1) {
        r = valueOf(power.modular, r * x);
    }
    return (int)r;
}

int inverse(Power power, int x) {
    return pow(power, x, power.modular.m - 2);
}

typedef struct {
    int m;
    int *data;
} FastInput;

FastInput new_FastInput() {
    FastInput in;
    in.m = 0;
    in.data = NULL;
    return in;
}

int read(FastInput *in) {
    return in->data[in->m++];
}

void skipBlank(FastInput *in) {
    while (in->m >= 0 && in->m <= 32) {
        in->m = read(in);
    }
}

int readInt(FastInput *in) {
    int sign = 1;

    skipBlank(in);
    if (in->m == '+' || in->m == '-') {
        sign = in->m == '+' ? 1 : -1;
        in->m = read(in);
    }

    int val = 0;
    if (sign == 1) {
        while (in->m >= '0' && in->m <= '9') {
            val = val * 10 + in->m - '0';
            in->m = read(in);
        }
    } else {
        while (in->m >= '0' && in->m <= '9') {
            val = val * 10 - in->m + '0';
            in->m = read(in);
        }
    }

    return val;
}

typedef struct {
    int m;
    int *data;
} FastOutput;

FastOutput new_FastOutput() {
    FastOutput out;
    out.m = 0;
    out.data = (int *)malloc(10 * 1024 * 1024);
    return out;
}

FastOutput println(FastOutput out, int c) {
    out.data[out.m++] = c;
    out.data[out.m++] = '\n';
    return out;
}

void flush(FastOutput *out) {
    for (int i = 0; i < out->m; i++) {
        putchar(out->data[i]);
    }
    out->m = 0;
}

void close(FastOutput *out) {
    flush(out);
}

typedef struct {
    int m;
    int *data;
} Buffer;

Buffer new_Buffer(int cap) {
    Buffer buf;
    buf.m = 0;
    buf.data = (int *)malloc(cap * sizeof(int));
    return buf;
}

void release(Buffer *buf) {
    buf->m = 0;
}

typedef struct {
    int m;
    Power power;
    Modular modular;
    Buffer listBuffer;
    Log2 log2;
} id9;

id9 new_id9(Modular mod, int g) {
    id9 ntt;
    ntt.modular = mod;
    ntt.power = new_Power(mod);
    ntt.log2 = new_Log2();
    ntt.listBuffer = new_Buffer(0);
    ntt.m = g;
    return ntt;
}

void dotMul(id9 *ntt, int *a, int *b, int *c, int m) {
    int n = 1 << m;
    for (int i = 0; i < n; i++) {
        c[i] = mul(ntt->modular, a[i], b[i]);
    }
}

void prepareReverse(int *r, int b) {
    int n = 1 << b;
    r[0] = 0;
    for (int i = 1; i < n; i++) {
        r[i] = (r[i >> 1] >> 1) | ((1 & i) << (b - 1));
    }
}

void dft(id9 *ntt, int *p, int m) {
    int n = 1 << m;

    int *rev = (int *)malloc(n * sizeof(int));
    prepareReverse(rev, m);

    for (int i = 0; i < n; i++) {
        if (rev[i] > i) {
            int tmp = p[i];
            p[i] = p[rev[i]];
            p[rev[i]] = tmp;
        }
    }

    int w = 0;
    int t = 0;
    for (int d = 0; d < m; d++) {
        int w1 = ntt->power.pow(ntt->power, ntt->m, (ntt->modular.m - 1) / 2 / (1 << d));
        int s = 1 << d;
        int s2 = s << 1;
        for (int i = 0; i < n; i += s2) {
            w = 1;
            for (int j = 0; j < s; j++) {
                int a = i + j;
                int b = a + s;
                t = mul(ntt->modular, w, p[b]);
                p[b] = plus(ntt->modular, p[a], -t);
                p[a] = plus(ntt->modular, p[a], t);
                w = mul(ntt->modular, w, w1);
            }
        }
    }

    free(rev);
}

void idft(id9 *ntt, int *p, int m) {
    dft(ntt, p, m);

    int n = 1 << m;
    int invN = ntt->power.inverse(ntt->power, n);

    p[0] = mul(ntt->modular, p[0], invN);
    p[n / 2] = mul(ntt->modular, p[n / 2], invN);
    for (int i = 1, until = n / 2; i < until; i++) {
        int a = p[n - i];
        p[n - i] = mul(ntt->modular, p[i], invN);
        p[i] = mul(ntt->modular, a, invN);
    }
}

void id1(id9 *ntt, IntList *lists, IntList *ans) {
    int n = lists->size;

    IntList *pqs = (IntList *)malloc(n * sizeof(IntList));
    for (int i = 0; i < n; i++) {
        pqs[i] = clone(lists[i]);
    }

    while (n > 1) {
        IntList *a = &pqs[0];
        IntList *b = &pqs[1];
        dotMul(ntt, a->data, b->data, a->data, rankOf(a) + rankOf(b) + 1);
        normalize(a);
        free(b->data);
        free(b);
        for (int i = 1; i < n - 1; i++) {
            pqs[i] = pqs[i + 1];
        }
        n--;
    }

    IntList *last = &pqs[0];
    ans->size = 0;
    addAll_IntList(ans, last);
    free(last->data);
    free(last);
    free(pqs);
}

int pow(int x, int n, int mod) {
    int res = 1;
    for (long long p = x; n > 0; n >>= 1, p = (p * p) % mod) {
        if ((n & 1) != 0) {
            res = (int)((long long)res * p % mod);
        }
    }
    return res;
}

void ntt(int *a, int n, int invert, int mod, int root) {
    int shift = 32 - __builtin_clz(n - 1);
    for (int i = 1; i < n; i++) {
        int j = __builtin_bswap32(i << shift);
        if (i < j) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }

    int root_inv = pow(root, mod - 2, mod);

    for (int len = 1; len < n; len <<= 1) {
        int wlen = pow(invert ? root_inv : root, (mod - 1) / (2 * len), mod);
        for (int i = 0; i < n; i += 2 * len) {
            int w = 1;
            for (int j = 0; j < len; ++j) {
                int a = i + j;
                int b = a + len;
                int u = a[a];
                int v = (int)((long long)a[b] * w % mod);
                a[b] = plus(mod, u, -v);
                a[a] = plus(mod, u, v);
                w = mul(mod, w, wlen);
            }
        }
    }

    if (invert) {
        int nrev = pow(n, mod - 2, mod);
        for (int i = 0; i < n; ++i) {
            a[i] = mul(mod, a[i], nrev);
        }
    }
}

int gcd(int a, int b) {
    return a >= b ? id7(a, b) : id7(b, a);
}

int id7(int a, int b) {
    return b == 0 ? a : id7(b, a % b);
}

int id0(int x, int c, int n) {
    int xi = x;
    int xj = x;
    int j = 2;
    int i = 1;
    while (i < n) {
        i++;
        xi = (long long)xi * xi + c;
        if (xi >= n) {
            xi -= n;
        }
        int g = gcd(n, abs(xi - xj));
        if (g != 1 && g != n) {
            return g;
        }
        if (i == j) {
            j = j << 1;
            xj = xi;
        }
    }
    return -1;
}

typedef struct {
    int m;
    int *factors;
    Modular mod;
    Power pow;
    int phi;
} PrimitiveRoot;

PrimitiveRoot new_PrimitiveRoot(Modular x) {
    PrimitiveRoot root;
    root.mod = x;
    root.pow = new_Power(x);
    root.phi = x.m - 1;
    root.factors = (int *)malloc(root.phi * sizeof(int));
    int cnt = 0;
    for (int i = 2; i <= root.phi; i++) {
        if (root.phi % i == 0) {
            root.factors[cnt++] = i;
        }
    }
    return root;
}

PrimitiveRoot new_PrimitiveRoot_int(int x) {
    return new_PrimitiveRoot(new_Modular(x));
}

int id3(PrimitiveRoot *root) {
    return id3_since(root, 2);
}

int id3_since(PrimitiveRoot *root, int since) {
    for (int i = since; i < root->mod.m; i++) {
        int flag = 1;
        for (int j = 0; j < root->phi; j++) {
            if (pow(root->power, i, root->phi / root->factors[j]) == 1) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            return i;
        }
    }
    return -1;
}

typedef struct {
    int m;
    Power power;
    Modular modular;
    int *data;
} id6;

id6 new_id6() {
    id6 rho;
    rho.m = 0;
    rho.power = new_Power(new_Modular(0));
    rho.modular = new_Modular(0);
    rho.data = NULL;
    return rho;
}

int findFactor(id6 *rho, int n) {
    if (mr(rho->m, n, 10)) {
        return n;
    }
    while (1) {
        int f = id0(rho->power.pow(0, n), rho->power.pow(0, n), n);
        if (f != -1) {
            return f;
        }
    }
}

int id2(id6 *rho, int n, int *map) {
    if (n == 1) {
        return;
    }
    int f = findFactor(rho, n);
    if (f == n) {
        int value = map[f];
        if (value == 0) {
            value = 1;
        }
        map[f] = value * f;
        return;
    }
    id2(rho, f, map);
    id2(rho, n / f, map);
}

void id2_map(id6 *rho, int n, int *map) {
    id2(rho, n, map);
}

typedef struct {
    int m;
    Power power;
    Modular modular;
    Random random;
} id8;

id8 new_id8(Modular modular) {
    id8 mr;
    mr.modular = modular;
    mr.power = new_Power(modular);
    mr.random = new_Random();
    return mr;
}

int mr(id8 *mr, int n, int s) {
    if (n == 2) {
        return 1;
    }
    if (n % 2 == 0) {
        return 0;
    }
    for (int i = 0; i < s; i++) {
        int x = nextInt(&mr->random, n - 2) + 2;
        if (!mr0(mr, x, n)) {
            return 0;
        }
    }
    return 1;
}

int mr0(id8 *mr, int x, int n) {
    int exp = n - 1;
    while (1) {
        int y = pow(mr->power, x, exp);
        if (y != 1 && y != n - 1) {
            return 0;
        }
        if (y != 1 || exp % 2 == 1) {
            break;
        }
        exp = exp / 2;
    }
    return 1;
}

typedef struct {
    int m;
    Power power;
    Modular modular;
} Power;

Power new_Power(Modular modular) {
    Power power;
    power.modular = modular;
    return power;
}

int pow(Power power, int x, int n) {
    if (n == 0) {
        return valueOf(power.modular, 1);
    }
    long long r = pow(power, x, n >> 1);
    r = valueOf(power.modular, r * r);
    if ((n & 1) == 1) {
        r = valueOf(power.modular, r * x);
    }
    return (int)r;
}

int inverse(Power power, int x) {
    return pow(power, x, power.modular.m - 2);
}

typedef struct {
    int m;
    int *data;
} FastInput;

FastInput new_FastInput() {
    FastInput in;
    in.m = 0;
    in.data = NULL;
    return in;
}

int read(FastInput *in) {
    return in->data[in->m++];
}

void skipBlank(FastInput *in) {
    while (in->m >= 0 && in->m <= 32) {
        in->m = read(in);
    }
}

int readInt(FastInput *in) {
    int sign = 1;

    skipBlank(in);
    if (in->m == '+' || in->m == '-') {
        sign = in->m == '+' ? 1 : -1;
        in->m = read(in);
    }

    int val = 0;
    if (sign == 1) {
        while (in->m >= '0' && in->m <= '9') {
            val = val * 10 + in->m - '0';
            in->m = read(in);
        }
    } else {
        while (in->m >= '0' && in->m <= '9') {
            val = val * 10 - in->m + '0';
            in->m = read(in);
        }
    }

    return val;
}

typedef struct {
    int m;
    int *data;
} FastOutput;

FastOutput new_FastOutput() {
    FastOutput out;
    out.m = 0;
    out.data = (int *)malloc(10 * 1024 * 1024);
    return out;
}

FastOutput println(FastOutput out, int c) {
    out.data[out.m++] = c;
    out.data[out.m++] = '\n';
    return out;
}

void flush(FastOutput *out) {
    for (int i = 0; i < out->m; i++) {
        putchar(out->data[i]);
    }
    out->m = 0;
}

void close(FastOutput *out) {
    flush(out);
}

int main() {
    FastInput in = new_FastInput();
    FastOutput out = new_FastOutput();

    int n = readInt(&in);
    int k = readInt(&in);
    int *allow = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < k; i++) {
        allow[readInt(&in)] = 1;
    }
    IntList p = new_IntList();
    addAll(&p, allow, 0, 10);

    int m = n / 2;
    IntList last = clone(p);
    id9 ntt = new_id9(new_Modular(998244353), 3);

    IntList *lists = (IntList *)malloc(m * sizeof(IntList));
    int cnt = 0;
    while (m > 1) {
        if (m % 2 == 1) {
            lists[cnt++] = clone(last);
        }
        int proper = ceilLog(2 * last.size);
        expandWith(&last, 0, 1 << proper);
        dft(&ntt, last.data, proper);
        dotMul(&ntt, last.data, last.data, last.data, proper);
        idft(&ntt, last.data, proper);
        normalize(&last);
        m /= 2;
    }
    lists[cnt++] = last;

    IntList prod = new_IntList();
    id1(&ntt, lists, &prod);

    int ans = 0;
    for (int i = 0; i < prod.size; i++) {
        int plus = prod.data[i];
        ans = plus(ntt.modular, ans, mul(ntt.modular, plus, plus));
    }

    out = println(out, ans);
    flush(&out);
    close(&out);
    return 0;
}
