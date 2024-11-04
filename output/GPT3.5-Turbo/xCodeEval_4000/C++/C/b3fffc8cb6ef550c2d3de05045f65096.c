#include <stdio.h>
#include <stdlib.h>

#define MAXN 100004
#define MOD 998244353

typedef struct {
    unsigned int x;
} mint;

typedef struct {
    long long nu, de;
} rational_t;

typedef struct {
    mint prod[2];
    mint sumlr;
    int ident;
} SegNode;

typedef struct {
    int l, r, forceDir;
} Group;

typedef struct {
    Group s[MAXN];
} GroupSet;

typedef struct {
    rational_t collideTime;
    int pos, dirL, dirR;
} Collision;

int vpos[MAXN], v[MAXN];
mint probBallDir[MAXN][2];
GroupSet gs;
SegNode t[2 * MAXN];
mint probNoCollide = {1};

mint mint_norm(int x) {
    if (x < 0) x += MOD;
    return (mint) {x};
}

mint mint_add(mint a, mint b) {
    a.x += b.x;
    if (a.x >= MOD) a.x -= MOD;
    return a;
}

mint mint_sub(mint a, mint b) {
    a.x += MOD - b.x;
    if (a.x >= MOD) a.x -= MOD;
    return a;
}

mint mint_mul(mint a, mint b) {
    a.x = ((unsigned long long) a.x * b.x) % MOD;
    return a;
}

mint mint_div(mint a, mint b) {
    return mint_mul(a, mint_inverse(b));
}

mint mint_add_int(mint a, int b) {
    b = mint_norm(b);
    a.x += b;
    if (a.x >= MOD) a.x -= MOD;
    return a;
}

mint mint_sub_int(mint a, int b) {
    b = mint_norm(b);
    a.x += MOD - b;
    if (a.x >= MOD) a.x -= MOD;
    return a;
}

mint mint_mul_int(mint a, int b) {
    b = mint_norm(b);
    a.x = ((unsigned long long) a.x * b) % MOD;
    return a;
}

mint mint_div_int(mint a, int b) {
    b = mint_norm(b);
    return mint_mul(a, (mint) {b});
}

mint mint_inverse(mint a) {
    signed int x = a.x, b = MOD, u = 1, v = 0;
    while (b) {
        signed int t = x / b;
        x -= t * b;
        signed int temp = x;
        x = b;
        b = temp;
        u -= t * v;
        signed int temp2 = u;
        u = v;
        v = temp2;
    }
    if (u < 0) u += MOD;
    return (mint) {(unsigned) u};
}

int mint_get(mint a) {
    return (int) a.x;
}

mint mint_neg(mint a) {
    mint t;
    t.x = a.x == 0 ? 0 : MOD - a.x;
    return t;
}

mint mint_pow(mint a, unsigned long long k) {
    mint r = {1};
    while (k) {
        if (k & 1) r = mint_mul(r, a);
        a = mint_mul(a, a);
        k >>= 1;
    }
    return r;
}

SegNode seg_combine(SegNode x, SegNode y) {
    if (x.ident) return y;
    if (y.ident) return x;
    SegNode ans;
    for (int d = 0; d < 2; d++) {
        ans.prod[d] = mint_mul(x.prod[d], y.prod[d]);
    }
    ans.sumlr = mint_add(mint_mul(x.sumlr, y.prod[1]), mint_sub(mint_mul(x.prod[0], y.sumlr), mint_mul(x.prod[0], y.prod[1])));
    ans.ident = 0;
    return ans;
}

void seg_init(int n) {
    for (int i = 0; i < n; i++) {
        t[n + i].prod[0] = probBallDir[i][0];
        t[n + i].prod[1] = probBallDir[i][1];
        t[n + i].sumlr = mint_add(probBallDir[i][0], probBallDir[i][1]);
        t[n + i].ident = 0;
    }
}

void seg_build(int n) {
    for (int i = n - 1; i > 0; --i) {
        t[i] = seg_combine(t[i << 1], t[i << 1 | 1]);
    }
}

void seg_set(int p, SegNode value) {
    int n = MAXN;
    t[p += n] = value;
    while (p >>= 1) t[p] = seg_combine(t[p << 1], t[p << 1 | 1]);
}

SegNode seg_query(int l, int r) {
    if (l > r) {
        SegNode ans;
        ans.ident = 1;
        return ans;
    }
    r++;
    int n = MAXN;
    SegNode resl = t[0], resr = t[0];
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) resl = seg_combine(resl, t[l++]);
        if (r & 1) resr = seg_combine(t[--r], resr);
    }
    return seg_combine(resl, resr);
}

mint getProdOfRange(int l, int r) {
    int lo = 1 << 30, hi = -1 << 30;
    mint ans = {1};
    for (int pos = l; pos <= r;) {
        Group dat = gs.s[pos];
        if (dat.forceDir == -1) {
            ans = mint_mul(ans, seg_query(dat.l, dat.r).sumlr);
        } else {
            ans = mint_mul(ans, seg_query(dat.l, dat.r).prod[dat.forceDir]);
        }
        pos = dat.r + 1;
    }
    return ans;
}

void mergeFates(int l, int r) {
    Group dl = gs.s[l];
    Group dr = gs.s[r];
    if ((dl.forceDir == 1 && dr.forceDir == -1) ||
        (dl.forceDir == -1 && dr.forceDir == 0) ||
        (dl.forceDir == -1 && dr.forceDir == -1)) {
        mint den = getProdOfRange(dl.l, dr.r);
        gs.s[l].r = dr.r;
        mint num = getProdOfRange(dl.l, dr.r);
        probNoCollide = mint_mul(probNoCollide, mint_div(num, den));
    } else if (dl.forceDir == 0 && dr.forceDir == -1) {
        gs.s[l].r = r;
    } else if (dl.forceDir == -1 && dr.forceDir == 1) {
        gs.s[r].l = l;
    } else if (dl.forceDir >= 0 && dr.forceDir >= 0) {
        if (dl.forceDir == dr.forceDir) {
            gs.s[l].r = dr.r;
        } else {
            probNoCollide = (mint) {0};
        }
    } else {
        exit(1);
    }
}

mint rat2Mint(rational_t r) {
    return mint_div_int((mint) {r.nu}, r.de);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &vpos[i], &v[i]);
        int probR;
        scanf("%d", &probR);
        probBallDir[i][0] = mint_div_int((mint) {probR}, 100);
        probBallDir[i][1] = mint_sub_int((mint) {1}, probBallDir[i][0]);
    }
    gs.s[0].l = 0;
    gs.s[0].r = n - 1;
    gs.s[0].forceDir = -1;
    gs.s[1].l = 1;
    gs.s[1].r = n - 1;
    gs.s[1].forceDir = -1;
    seg_init(n);
    seg_build(n);
    Collision collisions[n - 1];
    int numCollisions = 0;
    for (int i = 0; i < n - 1; i++) {
        int dist = vpos[i + 1] - vpos[i];
        rational_t rlCollideTime = {(long long) dist, v[i + 1] + v[i]};
        collisions[numCollisions++] = (Collision) {rlCollideTime, i, 1, 0};
        if (v[i] > v[i + 1]) {
            rational_t rrCollideTime = {(long long) dist, v[i] - v[i + 1]};
            collisions[numCollisions++] = (Collision) {rrCollideTime, i, 1, 1};
        }
        if (v[i] < v[i + 1]) {
            rational_t llCollideTime = {(long long) dist, v[i + 1] - v[i]};
            collisions[numCollisions++] = (Collision) {llCollideTime, i, 0, 0};
        }
    }
    for (int i = 0; i < numCollisions; i++) {
        Collision c = collisions[i];
        int pos = c.pos;
        mint prevProbNoCollide = probNoCollide;
        int dl = gs.s[c.pos].forceDir;
        int dr = gs.s[c.pos + 1].forceDir;
        if (dl != -1 && dl != c.dirL) continue;
        if (dr != -1 && dr != c.dirR) continue;
        if (c.dirL == 1 && c.dirR == 0) {
            mergeFates(pos, pos + 1);
        } else if (c.dirL == 1 && c.dirR == 1) {
            if (dl == 1) {
                probNoCollide = (mint) {0};
            } else {
                mint den = getProdOfRange(pos, pos + 1);
                gs.s[pos].r = pos;
                mint num = getProdOfRange(pos, pos + 1);
                probNoCollide = mint_mul(probNoCollide, mint_div(num, den));
            }
        } else if (c.dirL == 0 && c.dirR == 0) {
            if (dr == 0) {
                probNoCollide = (mint) {0};
            } else {
                mint den = getProdOfRange(pos, pos + 1);
                gs.s[pos + 1].l = pos + 1;
                mint num = getProdOfRange(pos, pos + 1);
                probNoCollide = mint_mul(probNoCollide, mint_div(num, den));
            }
        } else {
            exit(1);
        }
        mint collideTime = rat2Mint(c.collideTime);
        finalSum = mint_add(finalSum, mint_mul(collideTime, mint_sub(prevProbNoCollide, probNoCollide)));
        if (probNoCollide.x == 0) break;
    }
    printf("%d\n", mint_get(finalSum));
    return 0;
}
