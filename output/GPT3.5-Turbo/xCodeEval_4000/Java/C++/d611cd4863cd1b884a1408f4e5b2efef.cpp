#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <set>
#include <random>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <bitset>
#include <list>
#include <functional>
#include <sstream>
#include <numeric>
#include <complex>
#include <fstream>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <bitset>
#include <list>
#include <functional>
#include <sstream>
#include <numeric>
#include <complex>
#include <fstream>
#include <array>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
typedef vector<string> vs;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)
#define CLR(a) memset((a), 0, sizeof(a))
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define F first
#define S second

const int INF = 1e9 + 7;
const ll LLINF = 1e18 + 7;

template<typename T>
inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T>
inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T>
inline T read() {
    T x = 0, f = 1; char ch = getchar();
    while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

template<typename T>
inline void write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    if (x >= 10)write(x / 10);
    putchar(x % 10 + '0');
}

template<typename T>
inline void writeln(T x) { write(x); putchar('\n'); }
template<typename T>
inline void writesp(T x) { write(x); putchar(' '); }

template<typename T>
inline void chkmin(T &a, T b) { a = a < b ? a : b; }
template<typename T>
inline void chkmax(T &a, T b) { a = a > b ? a : b; }

template<typename T>
inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T>
inline T lcm(T a, T b) { return a / gcd(a, b) * b; }

template<typename T>
inline T sqr(T x) { return x * x; }

template<typename T>
inline int sign(T x) { return x < 0 ? -1 : x > 0; }

template<typename T>
inline T abs(T x) { return x < 0 ? -x : x; }

template<typename T>
inline T pow(T x, int y) {
    T res = 1;
    while (y) {
        if (y & 1)res = res * x;
        x = x * x;
        y >>= 1;
    }
    return res;
}

template<typename T>
inline T pow(T x, T y, T p) {
    T res = 1;
    while (y) {
        if (y & 1)res = res * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return res;
}

template<typename T>
inline T mod(T x, T p) {
    x %= p;
    if (x < 0)x += p;
    return x;
}

template<typename T>
inline T inverse(T x, T p) {
    x = mod(x, p);
    if (x == 1)return 1;
    return mod((1 - p * inverse(p % x, x)) / x, p);
}

template<typename T>
inline bool isprime(T x) {
    if (x <= 1)return 0;
    for (T i = 2; i * i <= x; i++)if (x % i == 0)return 0;
    return 1;
}

template<typename T>
inline void exgcd(T a, T b, T &x, T &y) {
    if (!b) {
        x = 1;
        y = 0;
    } else {
        exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
}

template<typename T>
inline T inv(T a, T p) {
    T x, y;
    exgcd(a, p, x, y);
    return (x % p + p) % p;
}

template<typename T>
inline T sum(T n, T m, T p) {
    T res = 0;
    n %= p;
    m %= p;
    if (n > m)swap(n, m);
    for (T i = n; i <= m; i++)res = (res + i) % p;
    return res;
}

template<typename T>
inline T mulmod(T a, T b, T p) {
    T res = 0;
    while (b) {
        if (b & 1)res = (res + a) % p;
        a = (a + a) % p;
        b >>= 1;
    }
    return res;
}

template<typename T>
inline T powmod(T a, T b, T p) {
    T res = 1;
    while (b) {
        if (b & 1)res = mulmod(res, a, p);
        a = mulmod(a, a, p);
        b >>= 1;
    }
    return res;
}

template<typename T>
inline T fact(T n, T p, T &e) {
    T res = 1;
    e = 0;
    while (n) {
        res = mulmod(res, powmod((T) 1, (n / p) % p, p), p);
        for (T i = 2; i <= n % p; i++)res = mulmod(res, i, p);
        n /= p;
    }
    return res;
}

template<typename T>
inline T Comb(T a, T b, T p) {
    if (a < b)return 0;
    T ea, eb, ec;
    T A = fact(a, p, ea), B = fact(b, p, eb), C = fact(a - b, p, ec);
    if (ea > eb + ec)return 0;
    return mulmod(mulmod(A, inv(B, p), p), inv(C, p), p);
}

template<typename T>
inline T Comb(T a, T b, T c, T p) {
    return Comb(a, b, p) * Comb(a, c, p) % p * Comb(b, c, p) % p;
}

template<typename T>
inline T sqr(T a) { return a * a; }

template<typename T>
inline T cub(T a) { return a * a * a; }

template<typename T>
inline T ceil(T x, T y) { return (x - 1) / y + 1; }

template<typename T>
inline bool bet(T x, T l, T r) { return l <= x && x <= r; }

template<typename T>
inline void chkmin(T &a, T b) { a = a < b ? a : b; }

template<typename T>
inline void chkmax(T &a, T b) { a = a > b ? a : b; }

template<typename T>
inline void read(T &x) {
    x = 0; int f = 1; char ch = getchar();
    while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    x *= f;
}

template<typename T>
inline void write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    if (x >= 10)write(x / 10);
    putchar(x % 10 + '0');
}

template<typename T>
inline void writeln(T x) { write(x); putchar('\n'); }
template<typename T>
inline void writesp(T x) { write(x); putchar(' '); }

template<typename T>
inline void chkmin(T &a, T b) { a = a < b ? a : b; }
template<typename T>
inline void chkmax(T &a, T b) { a = a > b ? a : b; }

template<typename T>
inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T>
inline T lcm(T a, T b) { return a / gcd(a, b) * b; }

template<typename T>
inline T sqr(T x) { return x * x; }

template<typename T>
inline int sign(T x) { return x < 0 ? -1 : x > 0; }

template<typename T>
inline T abs(T x) { return x < 0 ? -x : x; }

template<typename T>
inline T pow(T x, int y) {
    T res = 1;
    while (y) {
        if (y & 1)res = res * x;
        x = x * x;
        y >>= 1;
    }
    return res;
}

template<typename T>
inline T pow(T x, T y, T p) {
    T res = 1;
    while (y) {
        if (y & 1)res = res * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return res;
}

template<typename T>
inline T mod(T x, T p) {
    x %= p;
    if (x < 0)x += p;
    return x;
}

template<typename T>
inline T inverse(T x, T p) {
    x = mod(x, p);
    if (x == 1)return 1;
    return mod((1 - p * inverse(p % x, x)) / x, p);
}

template<typename T>
inline bool isprime(T x) {
    if (x <= 1)return 0;
    for (T i = 2; i * i <= x; i++)if (x % i == 0)return 0;
    return 1;
}

template<typename T>
inline void exgcd(T a, T b, T &x, T &y) {
    if (!b) {
        x = 1;
        y = 0;
    } else {
        exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
}

template<typename T>
inline T inv(T a, T p) {
    T x, y;
    exgcd(a, p, x, y);
    return (x % p + p) % p;
}

template<typename T>
inline T sum(T n, T m, T p) {
    T res = 0;
    n %= p;
    m %= p;
    if (n > m)swap(n, m);
    for (T i = n; i <= m; i++)res = (res + i) % p;
    return res;
}

template<typename T>
inline T mulmod(T a, T b, T p) {
    T res = 0;
    while (b) {
        if (b & 1)res = (res + a) % p;
        a = (a + a) % p;
        b >>= 1;
    }
    return res;
}

template<typename T>
inline T powmod(T a, T b, T p) {
    T res = 1;
    while (b) {
        if (b & 1)res = mulmod(res, a, p);
        a = mulmod(a, a, p);
        b >>= 1;
    }
    return res;
}

template<typename T>
inline T fact(T n, T p, T &e) {
    T res = 1;
    e = 0;
    while (n) {
        res = mulmod(res, powmod((T) 1, (n / p) % p, p), p);
        for (T i = 2; i <= n % p; i++)res = mulmod(res, i, p);
        n /= p;
    }
    return res;
}

template<typename T>
inline T Comb(T a, T b, T p) {
    if (a < b)return 0;
    T ea, eb, ec;
    T A = fact(a, p, ea), B = fact(b, p, eb), C = fact(a - b, p, ec);
    if (ea > eb + ec)return 0;
    return mulmod(mulmod(A, inv(B, p), p), inv(C, p), p);
}

template<typename T>
inline T Comb(T a, T b, T c, T p) {
    return Comb(a, b, p) * Comb(a, c, p) % p * Comb(b, c, p) % p;
}

template<typename T>
inline T sqr(T a) { return a * a; }

template<typename T>
inline T cub(T a) { return a * a * a; }

template<typename T>
inline T ceil(T x, T y) { return (x - 1) / y + 1; }

template<typename T>
inline bool bet(T x, T l, T r) { return l <= x && x <= r; }

template<typename T>
inline void chkmin(T &a, T b) { a = a < b ? a : b; }
template<typename T>
inline void chkmax(T &a, T b) { a = a > b ? a : b; }

template<typename T>
inline void read(T &x) {
    x = 0; int f = 1; char ch = getchar();
    while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    x *= f;
}

template<typename T>
inline void write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    if (x >= 10)write(x / 10);
    putchar(x % 10 + '0');
}

template<typename T>
inline void writeln(T x) { write(x); putchar('\n'); }
template<typename T>
inline void writesp(T x) { write(x); putchar(' '); }

template<typename T>
inline void chkmin(T &a, T b) { a = a < b ? a : b; }
template<typename T>
inline void chkmax(T &a, T b) { a = a > b ? a : b; }

template<typename T>
inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T>
inline T lcm(T a, T b) { return a / gcd(a, b) * b; }

template<typename T>
inline T sqr(T x) { return x * x; }

template<typename T>
inline int sign(T x) { return x < 0 ? -1 : x > 0; }

template<typename T>
inline T abs(T x) { return x < 0 ? -x : x; }

template<typename T>
inline T pow(T x, int y) {
    T res = 1;
    while (y) {
        if (y & 1)res = res * x;
        x = x * x;
        y >>= 1;
    }
    return res;
}

template<typename T>
inline T pow(T x, T y, T p) {
    T res = 1;
    while (y) {
        if (y & 1)res = res * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return res;
}

template<typename T>
inline T mod(T x, T p) {
    x %= p;
    if (x < 0)x += p;
    return x;
}

template<typename T>
inline T inverse(T x, T p) {
    x = mod(x, p);
    if (x == 1)return 1;
    return mod((1 - p * inverse(p % x, x)) / x, p);
}

template<typename T>
inline bool isprime(T x) {
    if (x <= 1)return 0;
    for (T i = 2; i * i <= x; i++)if (x % i == 0)return 0;
    return 1;
}

template<typename T>
inline void exgcd(T a, T b, T &x, T &y) {
    if (!b) {
        x = 1;
        y = 0;
    } else {
        exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
}

template<typename T>
inline T inv(T a, T p) {
    T x, y;
