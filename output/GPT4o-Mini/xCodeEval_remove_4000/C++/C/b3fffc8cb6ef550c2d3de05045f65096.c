#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef long long ll;
typedef long double ld;

const int MOD = 998244353;
const int UNDEF = -1;
const int INF = 1 << 30;

typedef struct {
    ll nu, de;
} id5;

typedef struct {
    unsigned x;
} mint;

typedef struct {
    mint prod[2];
    mint sumlr;
    bool ident;
} SegNode;

typedef struct {
    int l;
    int r;
    int forceDir;
} Group;

typedef struct {
    Group *s;
    size_t size;
    size_t capacity;
} GroupSet;

typedef struct {
    id5 id7;
    int pos;
    int dirL;
    int dirR;
} Collision;

const int mn = (1e5) + 4;
const int L = 0, R = 1;

GroupSet gs;
SegNode seg[2 * mn];
mint id10 = 1;
int vpos[mn], v[mn];
mint probBallDir[mn][2];

void initGroupSet(GroupSet *gs, size_t capacity) {
    gs->s = (Group *)malloc(capacity * sizeof(Group));
    gs->size = 0;
    gs->capacity = capacity;
}

void freeGroupSet(GroupSet *gs) {
    free(gs->s);
}

void addGroup(GroupSet *gs, Group g) {
    if (gs->size == gs->capacity) {
        gs->capacity *= 2;
        gs->s = (Group *)realloc(gs->s, gs->capacity * sizeof(Group));
    }
    gs->s[gs->size++] = g;
}

Group getData(GroupSet *gs, int x) {
    for (size_t i = 0; i < gs->size; i++) {
        if (gs->s[i].l <= x && x <= gs->s[i].r) {
            return gs->s[i];
        }
    }
    return (Group){-1, -1, -1}; // Not found
}

void ufreset(GroupSet *gs, int x) {
    addGroup(gs, (Group){x, x, -1});
}

void initSegTree(int n) {
    for (int i = 0; i < n; i++) {
        seg[n + i] = (SegNode){{{1, 1}, 1, true}};
    }
    for (int i = n - 1; i > 0; --i) {
        seg[i] = combine(seg[i << 1], seg[i << 1 | 1]);
    }
}

mint combine(SegNode x, SegNode y) {
    if (x.ident) return y;
    if (y.ident) return x;
    SegNode ans;
    for (int d = 0; d < 2; d++) {
        ans.prod[d] = (mint){(x.prod[d].x * y.prod[d].x) % MOD};
    }
    ans.sumlr = (mint){(x.sumlr.x * y.prod[R].x + x.prod[L].x * y.sumlr.x - x.prod[L].x * y.prod[R].x) % MOD};
    ans.ident = false;
    return ans;
}

mint query(int l, int r, int n) {
    if (l > r) return (mint){1}; // Identity
    r++;
    mint resl = (mint){1}, resr = (mint){1};
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) resl = combine(resl, seg[l++]);
        if (r & 1) resr = combine(seg[--r], resr);
    }
    return combine(resl, resr);
}

mint inverse(mint a) {
    signed a_val = a.x, b = MOD, u = 1, v = 0;
    while (b) {
        signed t = a_val / b;
        a_val -= t * b; 
        int temp = a_val; a_val = b; b = temp;
        u -= t * v; 
        temp = u; u = v; v = temp;
    }
    if (u < 0) u += MOD;
    return (mint){(unsigned)u};
}

mint operator_mint(mint a, mint b) {
    return (mint){(a.x * b.x) % MOD};
}

mint operator_div(mint a, mint b) {
    return operator_mint(a, inverse(b));
}

mint operator_add(mint a, mint b) {
    return (mint){(a.x + b.x) % MOD};
}

mint operator_sub(mint a, mint b) {
    return (mint){(a.x + MOD - b.x) % MOD};
}

mint id2(int l, int r) {
    int lo = INF, hi = -INF;
    mint ans = (mint){1};
    for (int pos = l; pos <= r;) {
        Group dat = getData(&gs, pos);
        lo = (lo < dat.l) ? lo : dat.l;
        hi = (hi > dat.r) ? hi : dat.r;
        mint mult;
        if (dat.forceDir == UNDEF) {
            mult = query(dat.l, dat.r, mn);
        } else {
            mult = seg[dat.l].prod[dat.forceDir];
        }
        ans = operator_mint(ans, mult);
        pos = dat.r + 1;
    }
    return ans;
}

void id12(int l, int r) {
    Group dl = getData(&gs, l);
    Group dr = getData(&gs, r);
    if ((dl.forceDir == R && dr.forceDir == -1) ||
        (dl.forceDir == -1 && dr.forceDir == L) ||
        (dl.forceDir == -1 && dr.forceDir == -1)) {
        mint den = id2(dl.l, dr.r);
        // Union operation
        mint num = id2(dl.l, dr.r);
        id10 = operator_mint(id10, operator_div(num, den));
    } else if (dl.forceDir == L && dr.forceDir == -1) {
        // Handle case
    } else if (dl.forceDir == -1 && dr.forceDir == R) {
        // Handle case
    } else if (dl.forceDir >= 0 && dr.forceDir >= 0) {
        if (dl.forceDir == dr.forceDir) {
            // Handle case
        } else {
            id10 = (mint){0}; // Set to zero
        }
    } else {
        assert(0);
    }
}

mint id3(id5 r) {
    return operator_div((mint){r.nu}, (mint){r.de});
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
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return neg ? -x : x;
}

int main() {
    int n = rint();
    for (int i = 0; i < n; i++) {
        vpos[i] = rint();
        v[i] = rint();
        probBallDir[i][R] = operator_div((mint){rint()}, (mint){100});
        probBallDir[i][L] = operator_sub((mint){1}, probBallDir[i][R]);
    }
    initGroupSet(&gs, n);
    initSegTree(n);
    for (int pos = 0; pos < n; pos++) {
        seg[n + pos] = (SegNode){{probBallDir[pos][L], probBallDir[pos][R]}, operator_add(probBallDir[pos][L], probBallDir[pos][R]), false};
    }
    // Further processing...
    return 0;
}
