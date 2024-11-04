#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;
typedef long double ld;

const int MOD = 998244353;
const int UNDEF = -1;
const int INF = 1 << 30;

typedef struct {
    unsigned x;
} mint;

typedef struct {
    ll nu, de;
} id5;

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
    rat id7;
    int pos;
    int dirL;
    int dirR;
} Collision;

const int mn = (1e5) + 4;
const int L = 0;
const int R = 1;

typedef struct {
    SegNode t[2 * mn];
    SegNode identity;
    int segn;
} MulSegTree;

typedef struct {
    set<UFTYPE> s;
} GroupSet;

int vpos[mn], v[mn];
mint probBallDir[mn][2];
GroupSet<mn> gs;
MulSegTree<mn> seg;

mint id10 = 1;

mint mint_norm(mint m) {
    if (m.x < 0) {
        m.x += MOD;
    }
    return m;
}

mint mint_init() {
    mint m;
    m.x = 0;
    return m;
}

mint mint_init_signed(int sig) {
    mint m;
    sig = mint_norm(sig);
    m.x = sig;
    return m;
}

mint mint_init_signed_long_long(int sig) {
    mint m;
    sig = mint_norm(sig % MOD);
    m.x = sig;
    return m;
}

int mint_get(mint m) {
    return (int)m.x;
}

mint mint_add(mint a, mint that) {
    if ((a.x += that.x) >= MOD) {
        a.x -= MOD;
    }
    return a;
}

mint mint_sub(mint a, mint that) {
    if ((a.x += MOD - that.x) >= MOD) {
        a.x -= MOD;
    }
    return a;
}

mint mint_mul(mint a, mint that) {
    a.x = ((unsigned long long)a.x * that.x) % MOD;
    return a;
}

mint mint_div(mint a, mint that) {
    return mint_mul(a, mint_inverse(that));
}

mint mint_add_int(mint a, int that) {
    that = mint_norm(that);
    if ((a.x += that) >= MOD) {
        a.x -= MOD;
    }
    return a;
}

mint mint_sub_int(mint a, int that) {
    that = mint_norm(that);
    if ((a.x += MOD - that) >= MOD) {
        a.x -= MOD;
    }
    return a;
}

mint mint_mul_int(mint a, int that) {
    that = mint_norm(that);
    a.x = ((unsigned long long)a.x * that) % MOD;
    return a;
}

mint mint_div_int(mint a, int that) {
    that = mint_norm(that);
    return mint_mul(a, mint_inverse_int(that));
}

mint mint_add_mint(mint a, mint that) {
    return mint_add(a, that);
}

mint mint_sub_mint(mint a, mint that) {
    return mint_sub(a, that);
}

mint mint_mul_mint(mint a, mint that) {
    return mint_mul(a, that);
}

mint mint_div_mint(mint a, mint that) {
    return mint_div(a, that);
}

mint mint_inverse(mint m) {
    signed a = m.x, b = MOD, u = 1, v = 0;
    while (b) {
        signed t = a / b;
        a -= t * b;
        signed temp = a;
        a = b;
        b = temp;
        u -= t * v;
        signed temp2 = u;
        u = v;
        v = temp2;
    }
    if (u < 0) {
        u += MOD;
    }
    mint res;
    res.x = (unsigned)u;
    return res;
}

bool mint_equal(mint a, mint that) {
    return a.x == that.x;
}

bool mint_not_equal(mint a, mint that) {
    return a.x != that.x;
}

mint mint_negate(mint m) {
    mint t;
    t.x = m.x == 0 ? 0 : MOD - m.x;
    return t;
}

mint mint_pow(mint a, unsigned long long k) {
    mint r = mint_init(1);
    while (k) {
        if (k & 1) {
            r = mint_mul(r, a);
        }
        a = mint_mul(a, a);
        k >>= 1;
    }
    return r;
}

id5 id5_init(const ll n, const ll d) {
    id5 i5;
    i5.nu = n;
    i5.de = d;
    if (i5.de < 0) {
        i5.nu = -i5.nu;
        i5.de = -i5.de;
    }
    return i5;
}

id5 id5_add(id5 a, id5 b) {
    return id5_init(a.nu * b.de + a.de * b.nu, a.de * b.de);
}

id5 id5_sub(id5 a, id5 b) {
    return id5_init(a.nu * b.de - a.de * b.nu, a.de * b.de);
}

id5 id5_negate(id5 a) {
    return id5_init(-a.nu, a.de);
}

id5 id5_mul(id5 a, id5 b) {
    return id5_init(a.nu * b.nu, a.de * b.de);
}

id5 id5_div(id5 a, id5 b) {
    return id5_init(a.nu * b.de, a.de * b.nu);
}

bool id5_equal(id5 a, id5 b) {
    return a.nu * b.de == b.nu * a.de;
}

bool id5_equal_int(id5 a, ll k) {
    return a.nu == k * a.de;
}

bool id5_less_than(id5 a, id5 b) {
    return a.nu * b.de < b.nu * a.de;
}

bool id5_less_than_equal(id5 a, id5 b) {
    return a.nu * b.de <= b.nu * a.de;
}

bool id5_greater_than(id5 a, id5 b) {
    return a.nu * b.de > b.nu * a.de;
}

bool id5_greater_than_equal(id5 a, id5 b) {
    return a.nu * b.de >= b.nu * a.de;
}

typedef struct {
    int l;
    int r;
    int forceDir;
} UFTYPE;

void groupset_init(GroupSet *gs, int n) {
    for (int x = 0; x < n; x++) {
        groupset_ufreset(gs, x);
    }
}

UFTYPE groupset_combine(UFTYPE x, UFTYPE y) {
    if (min(x.forceDir, y.forceDir) >= 0) {
        assert(x.forceDir == y.forceDir);
    }
    UFTYPE combined;
    combined.l = min(x.l, y.l);
    combined.r = max(x.r, y.r);
    combined.forceDir = max(x.forceDir, y.forceDir);
    return combined;
}

UFTYPE groupset_get_initial_value(int x) {
    UFTYPE initial;
    initial.l = x;
    initial.r = x;
    initial.forceDir = -1;
    return initial;
}

void groupset_ufreset(GroupSet *gs, int x) {
    UFTYPE initial = groupset_get_initial_value(x);
    gs->s.insert(initial);
}

UFTYPE groupset_lb(GroupSet *gs, int x) {
    set<UFTYPE>::iterator it = gs->s.upper_bound({-2, x, -2});
    return *it;
}

void groupset_funion(GroupSet *gs, int x, int y) {
    set<UFTYPE>::iterator it1 = groupset_lb(gs, x);
    set<UFTYPE>::iterator it2 = groupset_lb(gs, y);
    if (it1 != it2) {
        UFTYPE combined = groupset_combine(*it1, *it2);
        gs->s.erase(it1);
        it2 = groupset_lb(gs, y);
        gs->s.erase(it2);
        gs->s.insert(combined);
    }
}

UFTYPE groupset_get_data(GroupSet *gs, int x) {
    set<UFTYPE>::iterator it = groupset_lb(gs, x);
    return *it;
}

void groupset_set_data(GroupSet *gs, int x, UFTYPE dat) {
    set<UFTYPE>::iterator it = groupset_lb(gs, x);
    gs->s.erase(it);
    gs->s.insert(dat);
}

void groupset_split(GroupSet *gs, int pl, int pr, int dl, int dr) {
    assert(UNDEF <= dl && dl < 2);
    assert(UNDEF <= dr && dr < 2);
    assert(pl + 1 == pr);
    set<UFTYPE>::iterator itl = groupset_lb(gs, pl);
    set<UFTYPE>::iterator itr = groupset_lb(gs, pr);
    assert(itl->forceDir == -1);
    assert(itr->forceDir == -1);
    if (itl == itr) {
        Group g = *itl;
        gs->s.erase(itl);
        gs->s.insert({g.l, pl, dl});
        gs->s.insert({pr, g.r, dr});
    } else {
        assert(0);
    }
}

void groupset_check(GroupSet *gs) {
}

int groupset_get_dir(GroupSet *gs, int x) {
    return groupset_get_data(gs, x).forceDir;
}

mint id3(rat r) {
    return mint_div_int(mint_init(r.nu), mint_init(r.de));
}

int main() {
    int n = rint();
    int alln = n;
    for (int i = 0; i < n; i++) {
        vpos[i] = rint();
        v[i] = rint();
        probBallDir[i][R] = mint_div_int(mint_init(rint()), mint_init(100));
        probBallDir[i][L] = mint_sub_int(mint_init(1), probBallDir[i][R]);
    }
    groupset_init(&gs, n);
    {
        seg.segn = n;
        for (int pos = 0; pos < n; pos++) {
            seg.t[seg.segn + pos].prod[L] = probBallDir[pos][L];
            seg.t[seg.segn + pos].prod[R] = probBallDir[pos][R];
            seg.t[seg.segn + pos].sumlr = mint_add(probBallDir[pos][L], probBallDir[pos][R]);
            seg.t[seg.segn + pos].ident = false;
        }
        seg_build(&seg);
    }

    Collision collisions[n - 1];
    for (int i = 0; i < (n - 1); i++) {
        int dist = vpos[i + 1] - vpos[i];

        rat id8 = id5_init(dist, v[i + 1] + v[i]);
        collisions[i].id7 = id8;
        collisions[i].pos = i;
        collisions[i].dirL = R;
        collisions[i].dirR = L;

        if (v[i] > v[i + 1]) {
            rat id6 = id5_init(dist, v[i] - v[i + 1]);
            collisions[i + n - 1].id7 = id6;
            collisions[i + n - 1].pos = i;
            collisions[i + n - 1].dirL = R;
            collisions[i + n - 1].dirR = R;
        }

        if (v[i] < v[i + 1]) {
            rat id11 = id5_init(dist, v[i + 1] - v[i]);
            collisions[i + 2 * (n - 1)].id7 = id11;
            collisions[i + 2 * (n - 1)].pos = i;
            collisions[i + 2 * (n - 1)].dirL = L;
            collisions[i + 2 * (n - 1)].dirR = L;
        }
    }
    qsort(collisions, n - 1, sizeof(Collision), cmpfunc);
    mint finalSum = mint_init(0);
    for (int i = 0; i < (n - 1); i++) {
        Collision c = collisions[i];
        int pos = c.pos;
        mint id9 = id10;

        int dl = groupset_get_dir(&gs, c.pos);
        int dr = groupset_get_dir(&gs, c.pos + 1);

        if (dl != UNDEF && dl != c.dirL) continue;
        if (dr != UNDEF && dr != c.dirR) continue;
        if (c.dirL == R && c.dirR == L) {
            id12(pos, pos + 1);
        } else if (c.dirL == R && c.dirR == R) {
            if (dl == R) {
                id10 = mint_init(0);
            } else {
                mint den = id2(pos, pos + 1);
                groupset_split(&gs, c.pos, c.pos + 1, L, UNDEF);
                mint num = id2(pos, pos + 1);
                id10 = mint_mul(mint_div(num, den), id10);
            }
        } else if (c.dirL == L && c.dirR == L) {
            if (dr == L) {
                id10 = mint_init(0);
            } else {
                mint den = id2(pos, pos + 1);
                groupset_split(&gs, c.pos, c.pos + 1, UNDEF, R);
                mint num = id2(pos, pos + 1);
                id10 = mint_mul(mint_div(num, den), id10);
            }
        } else {
            assert(0);
        }
        groupset_check(&gs);
        mint id7 = id3(c.id7);
        finalSum = mint_add(finalSum, mint_mul(id7, mint_sub(id9, id10)));
        if (mint_equal(id10, mint_init(0))) break;
    }
    printf("%d\n", mint_get(finalSum));

    return 0;
}

static char stdinBuffer[1024];
static char* id4 = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = id4;

void readAhead(size_t amount) {
    size_t remaining = id4 - stdinPos;
    if (remaining < amount) {
        memmove(stdinBuffer, stdinPos, remaining);
        size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
        stdinPos = stdinBuffer;
        id4 = stdinBuffer + remaining + sz;
        if (id4 != stdinBuffer + sizeof (stdinBuffer))
            *id4 = 0;
    }
}

int rint() {
    readAhead(16);

    int x = 0;
    bool neg = false;
    while (*stdinPos == ' ' || *stdinPos == '\n') ++stdinPos;
    if (*stdinPos == '-') {
        ++stdinPos;
        neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
        x *= 10;
        x += *stdinPos - '0';
        ++stdinPos;
    }

    return neg ? -x : x;
}

char rch() {
    readAhead(16);
    while (*stdinPos == ' ' || *stdinPos == '\n') ++stdinPos;
    char ans = *stdinPos;
    ++stdinPos;
    return ans;
}

long long rlong() {
    readAhead(32);

    long long x = 0;
    bool neg = false;
    while (*stdinPos == ' ' || *stdinPos == '\n') ++stdinPos;
    if (*stdinPos == '-') {
        ++stdinPos;
        neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
        x *= 10;
        x += *stdinPos - '0';
        ++stdinPos;
    }

    return neg ? -x : x;
}
