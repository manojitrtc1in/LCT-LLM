#define _USE_MATH_DEFINES





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
    template<typename T, typename... TArgs> void re(T& x, TArgs&... rest) { cin >> x; re(rest...); }
}
using namespace input;


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
    TT1T2T3 struct triple { T1 x; T2 y; T3 z; triple() : x(T1()), y(T2()), z(T3()) {};
     triple(T1 _x, T2 _y, T3 _z) :x(_x), y(_y), z(_z) {} };
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

#if 1 && defined(LOCAL)
#define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 1999
#define cerr if(0) cout
#endif
}
using namespace debug;

template <class T> bool setMax(T& v, T newV) { if (v < newV) { v = newV; return true; } return false; }
template <class T> bool setMin(T& v, T newV) { if (v > newV) { v = newV; return true; } return false; }



bool wavy(LL val)
{
    VI vec;
    while (val)
    {
        vec.push_back(val % 10);
        val /= 10;
    }
    for(int i = 1; i < SZ(vec) - 1; ++i){
        if(vec[i - 1] <= vec[i] && vec[i] <= vec[i + 1])
            return false;
        if(vec[i - 1] >= vec[i] && vec[i] >= vec[i + 1])
            return false;

    }
    return true;
}

LL n;
LL val = 0;
vector<int> vals;

void gen(int dl, int mini, int maxi, int typ, int s)
{
    if(dl == 0)
    {
        vals.push_back(val);
        return;
    }
    if(typ)
    {
        val *= 10;
        for(int i = max(0, s); i < maxi; ++i)
        {
            val += i;
            gen(dl - 1, i, maxi, 0, 0);
            val -= i;
        }
        val /= 10;
    }
    else
    {
        val *= 10;
        for(int i = max(s, mini + 1); i <= 9; ++i)
        {
            val += i;
            gen(dl - 1, mini, i, 1, 0);
            val -= i;
        }
        val /= 10;
    }
}

int len(LL val)
{
    int ile = 0;
    while(val)
    {
        val /= 10;
        ++ile;
    }
    return ile;
}

bool cmp(int a, int b)
{
    int r1 = a % n;
    int r2 = b % n;
    if(r1 == r2)
        return a < b;
    return r1 < r2;
}
bool cmp2(int a, int b)
{
    int r1 = a % n;
    int r2 = b % n;
    return r1 < r2;
}

unordered_map<int,int> incCnt[10];
unordered_map<int,int> decCnt[10];
VPII incVec[10];
VPII decVec[10];

void solve()
{
    LL k;
    re(n , k);

    const LL MNO = 1e7;
    const LL HELP = MNO / 10;

    gen(7, -1, 10, 1, 1);
    gen(6, -1, 10, 0, 1);
    for(auto u : vals)
    {
        int fir = u / HELP;
        for(int i = fir; i < 10; ++i)
        {
            

            incVec[i].push_back({u%n, u});
        }
    }
    vals.clear();

    gen(7, -1, 10, 0, 1);
    for(auto u : vals)
    {
        int fir = u / HELP;        
        for(int i = fir; i >= 0; --i)
        {
            

            decVec[i].push_back({u%n, u});
        }
    }
    vals.clear();


    FOR(i, 10)
    {
        sort(ALL(decVec[i]));
        sort(ALL(incVec[i]));
    }

    VI valsWithType;

    for(int i = 1; i <= 7; ++i)
    {
        int typ1 = 0;
        int typ2 = 1;
        if(i % 2 == 0)
            swap(typ1, typ2);

        gen(i, -1, 10, 0, 1);
        for(auto val : vals)
            valsWithType.push_back(val * 2 + typ1);
        vals.clear();
        
        
        gen(i, -1, 10, 1, 1);
        for(auto val : vals)
            valsWithType.push_back(val * 2 + typ2);
        vals.clear();
    }
    vals.shrink_to_fit();

    sort(ALL(valsWithType));

    for(auto pa : valsWithType)
    {
        auto type = pa % 2;
        auto val = pa / 2;
        if(val % n == 0  && (val >= 10 || type))
        {
            --k;
        }
        if(k == 0)
        {
            prln(val);
            return;
        }
    }

    for(auto pa : valsWithType)
    {
        auto type = pa % 2;
        auto val = pa / 2;
        LL tmp = (-MNO * val) % n;
        tmp = (tmp + n) % n;
        int mod = tmp;

        int fir = val % 10;

        if(tmp > MNO)
            continue;

        if(type)
        {
            if(fir == 9)
                continue;
            fir++;
            int ile = upper_bound(ALL(decVec[fir]), pair{mod, inf})
                     -lower_bound(ALL(decVec[fir]), pair{mod, 0});
            

            if(k > ile)
            {
                k -= ile;
                continue;
            }
            

            

                for(auto secVal : decVec[fir])
                {
                    LL fullVal = val * MNO + secVal.second;
                    if(fullVal % n == 0)
                    {
                        --k;
                        if(k == 0)
                        {
                            prln(fullVal);
                            return;
                        }
                    }
                }
            

        }
        else
        {
            if(fir == 0)
                continue;
            fir--;

            int ile = upper_bound(ALL(incVec[fir]), pair{mod, inf})
                     -lower_bound(ALL(incVec[fir]), pair{mod, 0});
            

            if(k > ile)
            {
                k -= ile;
                continue;
            }
            

            

                for(auto secVal : incVec[fir])
                {
                    LL fullVal = val * MNO + secVal.second;
                    if(fullVal % n == 0)
                    {
                        --k;
                        if(k == 0)
                        {
                            prln(fullVal);
                            return;
                        }
                    }
                }
            

            
        }
        
    }
    prln(-1);
}

int main()
{   
    

        

        

    


    BOOST;
    cout << fixed << setprecision(13);
    int t = 1;
    

    for(int i = 1; i <= t; ++i)
    

    

    {
        solve();
    }
    return 0;
}   