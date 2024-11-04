













#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

#define IL inline
#define CT const
#define TT template <typename Ty>
#define OP operator
#define RG register
#define UI(x) (static_cast<ui>(x))
#define LL(x) (static_cast<ll>(x))
#define ULL(x) (static_cast<ull>(x))
#define mp(x, y) std::make_pair(x, y)

TT IL Ty max(CT Ty& a, CT Ty& b) { return a > b ? a : b; }
TT IL Ty min(CT Ty& a, CT Ty& b) { return a < b ? a : b; }
TT IL void cmax(Ty& a, CT Ty& b) { if (b > a) a = b; }
TT IL void cmin(Ty& a, CT Ty& b) { if (b < a) a = b; }
TT IL void swap(Ty& a, Ty& b) { Ty t = a; a = b; b = t; }
TT IL void swap(Ty*& a, Ty*& b) { Ty *t = a; a = b; b = t; }

const ui mod = 998244353, G = 3;
const int MAXN = 1 << 19;

struct modint { ui v; modint( ui x = 0 ) { v = x; } };
IL ui add( ui x ) { return x < mod ? x : x - mod; }
IL ui add2( ui x ) { return x < mod * 2 ? x : x - mod * 2; }
IL modint OP + ( CT modint a, CT modint b ) { return add( a.v + b.v ); }
IL modint OP - ( CT modint a, CT modint b ) { return add( a.v + mod - b.v); }
IL modint OP - ( CT modint a ) { return a.v ? mod - a.v : 0; }
IL modint OP * ( CT modint a, CT modint b ) { return ULL( a.v ) * b.v % mod; }
IL modint& OP += ( modint &a, CT modint b ) { return a = a + b; }
IL modint& OP -= ( modint &a, CT modint b ) { return a = a - b; }
IL modint& OP *= ( modint &a, CT modint b ) { return a = a * b; }
IL modint qpow( modint a, int b ) { modint res = 1; for ( ; b; b >>= 1, a *= a ) if ( b & 1 ) res *= a; return res; }
IL modint ll_qpow( modint a, ll b ) { modint res = 1; for ( ; b; b >>= 1, a *= a ) if ( b & 1 ) res *= a; return res; }
IL ui multmult( CT ui x, CT ui y, CT ui z ) { ui q = ULL( x ) * z >> 32; return x * y - q * mod; }
IL ui mult( CT ui x, CT ui y, CT ui z ) { return add( multmult( x, y, z ) ); }
IL ui multq( CT ui x, CT ui y, CT ui z ) { ui q = ULL( x ) * z >> 32; return q + ( x * y - q * mod >= mod ); }

namespace poly
{
int siz;
ui w[ MAXN ], inv[ MAXN ];

void init_w( CT int n )
{
    for ( siz = 1; siz < n; siz <<= 1 ) ;
    ui pr = qpow( G, ( mod - 1 ) / siz ).v;
    ui prq = ( ULL( pr ) << 32 ) / mod;
    ui prr = ( ULL( pr ) << 32 ) % mod;
    siz >>= 1;
    w[ siz ] = 1, inv[ siz ] = ( ULL( w[ siz ] ) << 32 ) / mod;
    for ( int i = 1; i < siz; ++i )
    {
        ui x = w[ siz + i - 1 ];
        ull p = ULL( x ) * prq;
        ui q = p >> 32;
        w[ siz + i ] = add(x * pr - q * mod);
        inv[ siz + i ] = UI( p ) + multq( prr, w[ siz + i - 1 ], inv[ siz + i - 1 ] );
    }
    for (int i = siz - 1; i; --i)
        w[i] = w[i * 2], inv[i] = inv[i * 2];
    siz <<= 1;
}

void DFT( modint *_A, CT int L )
{
    ui x, y;
    if (L == 1)
        return;
    ui *A = reinterpret_cast<ui*>(_A);
    if (L == 2)
    {
        x = add2(A[0] + A[1]), y = add2(A[0] + mod * 2 - A[1]); A[0] = x, A[1] = y;
        return;
    }
    if (L == 4)
    {
        x = add2(A[0] + A[2]), y = add2(A[0] + mod * 2 - A[2]); A[0] = x, A[2] = y;
        x = add2(A[1] + A[3]), y = multmult(A[1] + mod * 2 - A[3], w[3], inv[3]); A[1] = x, A[3] = y;
        x = add2(A[0] + A[1]), y = add2(A[0] + mod * 2 - A[1]); A[0] = x, A[1] = y;
        x = add2(A[2] + A[3]), y = add2(A[2] + mod * 2 - A[3]); A[2] = x, A[3] = y;
        return; 
    }
    for (int d = L >> 1; d != 4; d >>= 1)
        for (int i = 0; i != L; i += d << 1)
            for (int j = 0; j != d; j += 4)
            {
                x = add2(A[i + j + 0] + A[i + d + j + 0]), y = multmult(A[i + j + 0] + mod * 2 - A[i + d + j + 0], w[d + j + 0], inv[d + j + 0]); A[i + j + 0] = x, A[i + d + j + 0] = y;
                x = add2(A[i + j + 1] + A[i + d + j + 1]), y = multmult(A[i + j + 1] + mod * 2 - A[i + d + j + 1], w[d + j + 1], inv[d + j + 1]); A[i + j + 1] = x, A[i + d + j + 1] = y;
                x = add2(A[i + j + 2] + A[i + d + j + 2]), y = multmult(A[i + j + 2] + mod * 2 - A[i + d + j + 2], w[d + j + 2], inv[d + j + 2]); A[i + j + 2] = x, A[i + d + j + 2] = y;
                x = add2(A[i + j + 3] + A[i + d + j + 3]), y = multmult(A[i + j + 3] + mod * 2 - A[i + d + j + 3], w[d + j + 3], inv[d + j + 3]); A[i + j + 3] = x, A[i + d + j + 3] = y;
            }
    for (int i = 0; i != L; i += 8)
    {
        x = add2(A[i] + A[i + 4]), y = add2(A[i] + mod * 2 - A[i + 4]); A[i] = x, A[i + 4] = y;
        x = add2(A[i + 1] + A[i + 5]), y = multmult(A[i + 1] + mod * 2 - A[i + 5], w[5], inv[5]); A[i + 1] = x, A[i + 5] = y;
        x = add2(A[i + 2] + A[i + 6]), y = multmult(A[i + 2] + mod * 2 - A[i + 6], w[6], inv[6]); A[i + 2] = x, A[i + 6] = y;
        x = add2(A[i + 3] + A[i + 7]), y = multmult(A[i + 3] + mod * 2 - A[i + 7], w[7], inv[7]); A[i + 3] = x, A[i + 7] = y;
    }
    for (int i = 0; i != L; i += 8)
    {
        x = add2(A[i] + A[i + 2]), y = add2(A[i] + mod * 2 - A[i + 2]); A[i] = x, A[i + 2] = y;
        x = add2(A[i + 1] + A[i + 3]), y = multmult(A[i + 1] + mod * 2 - A[i + 3], w[3], inv[3]); A[i + 1] = x, A[i + 3] = y;
        x = add2(A[i + 4] + A[i + 6]), y = add2(A[i + 4] + mod * 2 - A[i + 6]); A[i + 4] = x, A[i + 6] = y;
        x = add2(A[i + 5] + A[i + 7]), y = multmult(A[i + 5] + mod * 2 - A[i + 7], w[3], inv[3]); A[i + 5] = x, A[i + 7] = y;
    }
    for (int i = 0; i != L; i += 8)
    {
        x = add2(A[i] + A[i + 1]), y = add2(A[i] + mod * 2 - A[i + 1]); A[i] = x, A[i + 1] = y;
        x = add2(A[i + 2] + A[i + 3]), y = add2(A[i + 2] + mod * 2 - A[i + 3]); A[i + 2] = x, A[i + 3] = y;
        x = add2(A[i + 4] + A[i + 5]), y = add2(A[i + 4] + mod * 2 - A[i + 5]); A[i + 4] = x, A[i + 5] = y;
        x = add2(A[i + 6] + A[i + 7]), y = add2(A[i + 6] + mod * 2 - A[i + 7]); A[i + 6] = x, A[i + 7] = y;
    }
}

void IDFT(modint *_A, const int L)
{
    ui x, t;
    if (L == 1)
        return;
    ui *A = reinterpret_cast<ui*>(_A);
    if (L == 2)
    {
        x = add2(A[0]), t = add2(A[1]); A[0] = x + t, A[1] = x + mod * 2 - t;
        A[0] = add(add2(A[0])), A[0] = A[0] & 1 ? A[0] + mod : A[0], A[0] /= 2;
        A[1] = add(add2(A[1])), A[1] = A[1] & 1 ? A[1] + mod : A[1], A[1] /= 2;
        return;
    }
    if (L == 4)
    {
        x = add2(A[0]), t = add2(A[1]); A[0] = x + t, A[1] = x + mod * 2 - t;
        x = add2(A[2]), t = add2(A[3]); A[2] = x + t, A[3] = x + mod * 2 - t;
        x = add2(A[0]), t = add2(A[2]); A[0] = x + t, A[2] = x + mod * 2 - t;
        x = add2(A[1]), t = multmult(A[3], w[3], inv[3]); A[1] = x + t, A[3] = x + mod * 2 - t;
        std::swap(A[1], A[3]);
        for (int i = 0; i != L; ++i)
        {
            ull m = -A[i] & 3;
            A[i] = add((A[i] + m * mod) >> 2);
        }
        return; 
    }
    for (int i = 0; i != L; i += 8)
    {
        x = add2(A[i + 0]), t = add2(A[i + 1]); A[i + 0] = x + t, A[i + 1] = x + mod * 2 - t;
        x = add2(A[i + 2]), t = add2(A[i + 3]); A[i + 2] = x + t, A[i + 3] = x + mod * 2 - t;
        x = add2(A[i + 4]), t = add2(A[i + 5]); A[i + 4] = x + t, A[i + 5] = x + mod * 2 - t;
        x = add2(A[i + 6]), t = add2(A[i + 7]); A[i + 6] = x + t, A[i + 7] = x + mod * 2 - t;
    }
    for (int i = 0; i != L; i += 8)
    {
        x = add2(A[i + 0]), t = add2(A[i + 2]); A[i + 0] = x + t, A[i + 2] = x + mod * 2 - t;
        x = add2(A[i + 1]), t = multmult(A[i + 3], w[3], inv[3]); A[i + 1] = x + t, A[i + 3] = x + mod * 2 - t;
        x = add2(A[i + 4]), t = add2(A[i + 6]); A[i + 4] = x + t, A[i + 6] = x + mod * 2 - t;
        x = add2(A[i + 5]), t = multmult(A[i + 7], w[3], inv[3]); A[i + 5] = x + t, A[i + 7] = x + mod * 2 - t;
    }
    for (int i = 0; i != L; i += 8)
    {
        x = add2(A[i + 0]), t = add2(A[i + 4]); A[i + 0] = x + t, A[i + 4] = x + mod * 2 - t;
        x = add2(A[i + 1]), t = multmult(A[i + 5], w[5], inv[5]); A[i + 1] = x + t, A[i + 5] = x + mod * 2 - t;
        x = add2(A[i + 2]), t = multmult(A[i + 6], w[6], inv[6]); A[i + 2] = x + t, A[i + 6] = x + mod * 2 - t;
        x = add2(A[i + 3]), t = multmult(A[i + 7], w[7], inv[7]); A[i + 3] = x + t, A[i + 7] = x + mod * 2 - t;
    }
    for (int d = 8; d != L; d <<= 1)
        for (int i = 0; i != L; i += d << 1)
            for (int j = 0; j != d; j += 4)
            {
                x = add2(A[i + j + 0]), t = multmult(A[i + d + j + 0], w[d + j + 0], inv[d + j + 0]); A[i + j + 0] = x + t, A[i + d + j + 0] = x + mod * 2 - t;
                x = add2(A[i + j + 1]), t = multmult(A[i + d + j + 1], w[d + j + 1], inv[d + j + 1]); A[i + j + 1] = x + t, A[i + d + j + 1] = x + mod * 2 - t;
                x = add2(A[i + j + 2]), t = multmult(A[i + d + j + 2], w[d + j + 2], inv[d + j + 2]); A[i + j + 2] = x + t, A[i + d + j + 2] = x + mod * 2 - t;
                x = add2(A[i + j + 3]), t = multmult(A[i + d + j + 3], w[d + j + 3], inv[d + j + 3]); A[i + j + 3] = x + t, A[i + d + j + 3] = x + mod * 2 - t;
            }
    std::reverse(A + 1, A + L);
    int k = __builtin_ctz(L);
    for (int i = 0; i != L; ++i)
    {
        ull m = -A[i] & (L - 1);
        A[i] = add((A[i] + m * mod) >> k);
    }
}
} 


struct rndom_nums
{
    unsigned x, y, z, w;

    rndom_nums() : x(123456789), y(362436069), z(521288629), w(88675123) {}

    unsigned get_rnd()
    {
        unsigned t = x ^ (x << 11);
        x = y, y = z, z = w;
        return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
    }
} R;

int p[27];
modint rnd[27], a[MAXN], b[MAXN];
char s[MAXN], t[MAXN];
int len1, len2, n2;

int main()
{
    for (int i = 0; i < 26; ++i) 
    {
        scanf("%d", &p[i]);
        --p[i];
        long long t1 = R.get_rnd() % mod;
        long long t2 = R.get_rnd() % mod;
        t1 = (t1 * t2) % mod;
        rnd[i] = t1;
        

    }
    

    

    scanf("%s%s", s, t);
    len1 = strlen(s), len2 = strlen(t);
    for (n2 = 1; n2 <= len1 + len2 - 2; n2 <<= 1) ;
    modint sum = 0;
    for (int i = 0; i < len1; ++i) 
    {
        int c = s[i] - 'a';
        sum += rnd[c] * rnd[p[c]];
        a[len1 - 1 - i] = rnd[c] + rnd[p[c]];
    }
    for (int i = 0; i < len2; ++i) b[i] = rnd[t[i] - 'a'];
    poly::init_w(n2);
    poly::DFT(a, n2);
    poly::DFT(b, n2);
    for (int i = 0; i < n2; ++i) a[i] *= b[i];
    poly::IDFT(a, n2);
    modint tot = 0;
    for (int i = 0; i < len2; ++i)
    {
        tot += rnd[t[i] - 'a'] * rnd[t[i] - 'a'];
        if (i >= len1 - 1)
        {
            if ((sum.v + tot.v) % mod == a[i].v % mod) putchar('1'); else putchar('0');
            modint tmp = rnd[t[i - len1 + 1] - 'a'] * rnd[t[i - len1 + 1] - 'a'];
            tot += mod - tmp;
        }
    }
    putchar('\n');
    return 0;
}