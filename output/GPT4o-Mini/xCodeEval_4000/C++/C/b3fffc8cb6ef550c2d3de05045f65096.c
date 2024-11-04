#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define MOD 998244353
#define INF (1 << 30)
#define UNDEF -1
#define MN (100004)
#define L 0
#define R 1

typedef long long ll;
typedef struct {
    unsigned x;
} mint;

typedef struct {
    ll nu, de;
} rational_t;

typedef struct {
    mint prod[2];
    mint sumlr;
    bool ident;
} SegNode;

typedef struct {
    SegNode t[2 * MN];
    SegNode identity;
    int segn;
} MulSegTree;

typedef struct {
    int l;
    int r;
    int forceDir;
} Group;

typedef struct {
    rational_t collideTime;
    int pos;
    int dirL;
    int dirR;
} Collision;

mint probNoCollide = {1};
int vpos[MN], v[MN];
mint probBallDir[MN][2];
MulSegTree seg;

void mint_init(mint *m) {
    m->x = 0;
}

mint mint_add(mint a, mint b) {
    mint res;
    res.x = (a.x + b.x) % MOD;
    return res;
}

mint mint_sub(mint a, mint b) {
    mint res;
    res.x = (a.x + MOD - b.x) % MOD;
    return res;
}

mint mint_mul(mint a, mint b) {
    mint res;
    res.x = ((unsigned long long)a.x * b.x) % MOD;
    return res;
}

mint mint_inverse(mint a) {
    signed a_val = a.x, b = MOD, u = 1, v = 0;
    while (b) {
        signed t = a_val / b;
        a_val -= t * b; 
        signed temp = u; 
        u -= t * v; 
        v = temp;
        signed temp_b = b; 
        b = a_val; 
        a_val = temp_b;
    }
    if (u < 0) u += MOD;
    mint res; 
    res.x = (unsigned)u;
    return res;
}

mint mint_div(mint a, mint b) {
    return mint_mul(a, mint_inverse(b));
}

void seg_init(MulSegTree *seg, int n) {
    seg->segn = n;
    seg->identity.prod[L] = (mint){1};
    seg->identity.prod[R] = (mint){1};
    seg->identity.sumlr = (mint){1};
    seg->identity.ident = true;
}

void seg_set_before_build(MulSegTree *seg, int p, SegNode value) {
    seg->t[seg->segn + p] = value;
}

void seg_build(MulSegTree *seg) {
    int n = seg->segn;
    for (int i = n - 1; i > 0; --i) {
        seg->t[i] = seg->combine(seg->t[i << 1], seg->t[i << 1 | 1]);
    }
}

SegNode seg_query(MulSegTree *seg, int l, int r) {
    if (l > r) return seg->identity;
    r++;
    int n = seg->segn;
    SegNode resl = seg->identity, resr = seg->identity;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) resl = seg->combine(resl, seg->t[l++]);
        if (r & 1) resr = seg->combine(seg->t[--r], resr);
    }
    return seg->combine(resl, resr);
}

void mergeFates(int l, int r) {
    // Implementation of mergeFates
}

mint rat2Mint(rational_t r) {
    return mint_div((mint){r.nu}, (mint){r.de});
}

int rint() {
    int x = 0;
    bool neg = false;
    char c;
    while ((c = getchar()) == ' ' || c == '\n');
    if (c == '-') {
        neg = true;
        c = getchar();
    }
    do {
        x = x * 10 + (c - '0');
    } while ((c = getchar()) >= '0' && c <= '9');
    return neg ? -x : x;
}

int main() {
    int n = rint();
    for (int i = 0; i < n; i++) {
        vpos[i] = rint();
        v[i] = rint();
        probBallDir[i][R] = mint_div((mint){rint()}, (mint){100});
        probBallDir[i][L] = mint_sub((mint){1}, probBallDir[i][R]);
    }
    seg_init(&seg, n);
    for (int pos = 0; pos < n; pos++) {
        SegNode node = {{probBallDir[pos][L], probBallDir[pos][R]}, mint_add(probBallDir[pos][L], probBallDir[pos][R]), false};
        seg_set_before_build(&seg, pos, node);
    }
    seg_build(&seg);

    // Further implementation of the main logic

    return 0;
}
