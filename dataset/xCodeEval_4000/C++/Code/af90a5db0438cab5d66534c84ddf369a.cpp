#define _USE_MATH_DEFINES
#pragma GCC optimize("O3")







#include <bits/stdc++.h>
using namespace std;

#define LSB(i) ((i) & -(i)) 


#define OPEN(a) freopen(a, "r", stdin)
#define F first
#define S second
#define PB push_back
#define BOOST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ALL(i) begin((i)), end((i))
#define SZ(i) ((int)i.size())
#define SORT(a) sort(ALL(a))

using LL = long long;
using LD = long double;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using PLD = pair<LD, LD>;
using VI = vector<int>;
using VLL = vector<LL>;
using VLD = vector<LD>;
using VPII = vector<PII>;
using VPLL = vector<PLL>;
using VPLD = vector<PLD>;
using VVI = vector<VI>;

#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define __FOR3(i, a, n, inc) for(int i = (a); (inc) > 0 ? i < (n) : i >= (n); i += (inc))
#define __FOR2(i, a, n) __FOR3(i, a, n, 1)
#define __FOR1(i, n) __FOR2(i, 0, n)
#define FOR(...) GET_MACRO(__VA_ARGS__, __FOR3, __FOR2, __FOR1)(__VA_ARGS__)

#define REV(a,b) for(int a= b; a >= 0; --a)
#define FRU(a,b) for(const auto& a: b)
#define FRUM(a,b) for(auto& a : b)

const int inf = 1e9 + 7;
const int MOD = 998244353;
const LL INF = 1e18 + 7;
const long double PI = acos(-1);
const LD EPS = 1e-9;



namespace input {
    template< class T> istream& operator>>(istream& st, vector<T> & container) { for (auto& u : container) st >> u; return st; }
    template< class T, size_t N> istream& operator>>(istream& st, array<T, N> & container) { for (auto& u : container) st >> u; return st; }
    template <class T, class U> istream& operator>>(istream& st, pair<T, U> & p) { st >> p.first >> p.second; return st; }

    void re() {}
    template<typename T, typename... TArgs> void re(T& x, TArgs&... rest) { cin >> x; re(rest...); };
}
using namespace input;



#define RE(...)   int __VA_ARGS__; re(__VA_ARGS__);
#define RELL(...) LL __VA_ARGS__; re(__VA_ARGS__);
#define RELD(...) LD __VA_ARGS__; re(__VA_ARGS__);


namespace output
{
    template< class T> ostream& operator<<(ostream& st, const vector<T> & container) { for (auto& u : container) st << u << ' '; return st; }
    template< class T, size_t N> ostream& operator<<(ostream& st, const array<T, N> & container) { for (auto& u : container) st << u << ' '; return st; }
    template <class T, class U> ostream& operator<<(ostream& st, pair<T, U> p) { st << p.first << ' ' << p.second; return st; }

    void pr() {}
    template <typename T> void pr(const T& x) { cout << x; }
    template <typename T, typename... TArgs> void pr(const T& x, const TArgs&... rest) { cout << x << ' '; pr(rest...); }
    template <typename... TArgs> void prln(const TArgs&... args) { pr(args...); cout << '\n'; }
}
using namespace output;

namespace pairs
{
    template<class T, class U, class V> pair<T, U> operator* (pair<T, U>p, V val) { return{ p.first * val, p.second * val }; }
    template<class T, class U, class V> pair<T, U> operator/ (pair<T, U>p, V val) { return{ p.first / val, p.second / val }; }
    template<class T, class U>  pair<T, U> operator- (pair<T, U> a, pair<T, U> b) { return{ a.first - b.first, a.second - b.second }; }
    template<class T, class U>  pair<T, U> operator+ (pair<T, U> a, pair<T, U> b) { return{ a.first + b.first, a.second + b.second }; }
}
using namespace pairs;

namespace triples
{
#define TT1T2T3 template<class T1, class T2, class T3>
#define TT1T2T3T4 template<class T1, class T2, class T3, class T4>
#define TRT1T2T3  triple<T1, T2, T3>
    TT1T2T3 struct triple { T1 x; T2 y; T3 z; triple() : x(T1()), y(T2()), z(T3()) {}; triple(T1 _x, T2 _y, T3 _z) :x(_x), y(_y), z(_z) {} };
    TT1T2T3 bool operator<(const TRT1T2T3&t1, const TRT1T2T3&t2) { if (t1.x != t2.x)return t1.x < t2.x; if (t1.y != t2.y) return t1.y < t2.y; else return t1.z < t2.z; }
    TT1T2T3 bool operator>(const TRT1T2T3&t1, const TRT1T2T3&t2) { if (t1.x != t2.x)return t1.x > t2.x; if (t1.y != t2.y) return t1.y > t2.y; else return t1.z > t2.z; }
    TT1T2T3 bool operator==(const TRT1T2T3&t1, const TRT1T2T3&t2) { return (t1.x == t2.x && t1.y == t2.y && t1.z == t2.z); }
    TT1T2T3 inline istream& operator >> (istream& os, triple<T1, T2, T3>& t) { return os >> t.x >> t.y >> t.y; }
    TT1T2T3 ostream& operator << (ostream& os, const triple<T1, T2, T3>& t) { return os << t.x << " " << t.y << " " << t.z; }

    TT1T2T3 TRT1T2T3 operator+(TRT1T2T3 a, TRT1T2T3 b) { return { a.x + b.x, a.y + b.y, a.z + b.z }; }
    TT1T2T3 TRT1T2T3 operator-(TRT1T2T3 a, TRT1T2T3 b) { return { a.x - b.x, a.y - b.y, a.z - b.z }; }
    TT1T2T3T4 TRT1T2T3 operator*(TRT1T2T3 a, T4 val) { return { a.x * val, a.y * val, a.z * val }; }
    TT1T2T3T4 TRT1T2T3 operator/(TRT1T2T3 a, T4 val) { return { a.x / val, a.y / val, a.z / val }; }

#undef TT1T2T3T4
#undef TRT1T2T3
#undef TT1T2T3
    using TRII = triple<int, int, int>;
    using TRLL = triple<LL, LL, LL>;
    using TRLD = triple<LD, LD, LD>;
    using VTRII = vector<TRII>;
    using VTRLL = vector<TRLL>;
    using VTRLD = vector<TRLD>;
}
using namespace triples;

namespace geo
{
    template<class T> T dotProduct(pair<T, T> a, pair<T, T> b) { return a.first*b.first + a.second* b.second; }
    template<class T> T crossProduct(pair<T, T>a, pair<T, T> b) { return a.first * b.second - a.second * b.first; }
    template<class T> T lengthPow(pair<T, T> a) { return a.first*1ll*a.first + a.second*1ll*a.second; }
    template<class T> LD length(pair<T, T> a) { return sqrt(lengthPow(a)); }


    template<class T> T dotProduct(triple<T, T, T> a, triple<T, T, T> b) { return a.x*b.x + a.y* b.y + a.z*b.z; }
    template<class T> T crossProduct(triple<T, T, T> a, triple<T, T, T> b) { return { a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x }; }
    template<class T> T lengthPow(triple<T, T, T> a) { return a.x*1ll*a.x + a.y*1ll*a.y + a.z*1ll*a.z; }
    template<class T> LD length(triple<T, T, T> a) { return sqrt(lengthPow(a)); }
}
using namespace geo;

template <class T> T invGeneral(T a, T b) { 

    a %= b;
    if (a == 0) return b == 1 ? 0 : -1;
    T x = invGeneral(b, a);
    return x == -1 ? -1 : ((1 - (LL)b * x) / a + b) % b;
}

template<class T> struct modular {
    T val;
    explicit operator T() const { return val; }
    modular() { val = 0; }
    modular(const LL& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }

    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend void pr(const modular& a) { pr(a.val); }
    friend void re(modular& a) { LL x; re(x); a = modular(x); }

    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
    friend bool operator<(const modular& a, const modular& b) { return a.val < b.val; }

    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (LL)val*m.val%MOD; return *this; }
    friend modular pow(modular a, LL p) {
        modular ans = 1; for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
        return ans;
    }
    friend modular inv(const modular& a) {
        auto i = invGeneral(a.val, MOD); assert(i != -1);
        return i;
    } 

    modular& operator/=(const modular& m) { return (*this) *= inv(m); }

    friend modular operator+(modular a, const modular& b) { return a += b; }
    friend modular operator-(modular a, const modular& b) { return a -= b; }
    friend modular operator*(modular a, const modular& b) { return a *= b; }
    friend modular operator/(modular a, const modular& b) { return a /= b; }
};

using MI = modular<int>;
using PMI = pair<MI, MI>;
using VMI = vector<MI>;
using VPMI = vector<PMI>;


namespace debug {
    template < typename _T > inline void _debug(const char *s, _T x) { cerr << s << " = " << x << "\n"; }
    template < typename _T, typename... args > void _debug(const char *s, _T x, args... a) { while (*s != ',') cerr << *s++; cerr << " = " << x << ','; _debug(s + 1, a...); }

#if 0 && defined(LOCAL)
#define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 1999
#define cerr if(0) cout
#endif
}
using namespace debug;

template <class T> bool setMax(T& v, T newV) { if (v < newV) { v = newV; return true; } return false; }
template <class T> bool setMin(T& v, T newV) { if (v > newV) { v = newV;    return true; } return false; }
LL sq(LL a) {return a*a;}

namespace fft
{
    using namespace std;
    typedef complex<double> comp;
    const int MAXN = 1 << 19;
    const double PI = 3.14159265358979323846;

    void fft(vector<comp> & a, bool invert) {
        int n = a.size();

        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; j & bit; bit >>= 1)
                j ^= bit;
            j ^= bit;

            if (i < j)
                swap(a[i], a[j]);
        }

        for (int len = 2; len <= n; len <<= 1) {
            double ang = 2 * PI / len * (invert ? -1 : 1);
            comp wlen(cos(ang), sin(ang));
            for (int i = 0; i < n; i += len) {
                comp w(1);
                for (int j = 0; j < len / 2; j++) {
                    comp u = a[i+j], v = a[i+j+len/2] * w;
                    a[i+j] = u + v;
                    a[i+j+len/2] = u - v;
                    w *= wlen;
                }
            }
        }

        if (invert) {
            for (auto & x : a)
                x /= n;
        }
    }

    vector<int> mult(const vector<int>& a, const vector<int>& b)
    {
        vector<comp> fa(a.begin(), a.end()), fb(b.begin(), b.end());
        int n = 1;
        while (n < a.size() + b.size()) 
            n <<= 1;
        fa.resize(n);
        fb.resize(n);

        fft(fa, false);
        fft(fb, false);
        for (int i = 0; i < n; i++)
            fa[i] *= fb[i];
        fft(fa, true);

        int newSize = a.size() + b.size() - 1;
        vector<int> result(newSize);
        for (int i = 0; i < newSize; i++)
            result[i] = ((long long)round(fa[i].real()) );
        return result;
    }
}

struct cmp
{
    bool operator() (const pair<vector<int>, int> & a, const pair<vector<int>, int> & b)
    {
        if(a.first.size() == b.first.size())
            return a.second < b.second;
        return a.first.size() < b.first.size();
    }
};

const int N = 5e5 + 6;
bitset<N> wa;

auto solve()
{
	int n;
    cin >> n;

    string s;
    cin >> s;

    wa.reset();

    vector<int> a(n), b(n);

    for(int i = 0; i < n; ++i)
    {
        if(s[i] == 'V')
            a[i] = 1;
        if(s[i] == 'K')
            b[n-i-1] = 1;
    }

    auto res = fft::mult(a,b);
    debug(a);
    debug(b);
    debug(res);

    for(int i = 0; i <n; ++i)
    {
        if(res[i])
        {
            wa[n - i - 1] = 1;
            debug(i, n - i);
        }
    }

    for(int i = n; i < 2 *n - 1; ++i)
    {
        if(res[i])
        {
            wa[i-n+1] = 1;
            debug(i, i-n + 1);
        }
    }

    for(int i = 1; i <=n; ++i)
    {
        for(int j = 2*i; j <= n; j += i)
        {
            if(wa[j])
            {
                debug("change", i, j);
                wa[i] = 1;
            }
        }
    }

    vector<int> odp;

    for(int i = 1; i <= n; ++i)
    {
        if(!wa[i])
        {
            odp.push_back(i);
        }
    }

    prln(odp.size());
    prln(odp);



	

}

int main()
{   
    

        

        

    



    BOOST;
    cout << fixed << setprecision(10);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
} 