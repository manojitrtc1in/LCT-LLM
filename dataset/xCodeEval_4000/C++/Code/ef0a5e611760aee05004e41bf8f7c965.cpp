
#include <bits/stdc++.h>
using namespace std;


#define REP(i, n)       for (int i = 0; i < (n); ++i)
#define FORW(i, l, r)   for (int i = (l); i < (r); ++i)
#define FORALL(i, l, r) for (int i = (l); i <= (r); ++i)
#define REV(i, n)       for (int i = (n)-1; i >= 0; --i)
#define BACKW(i, l, r)  for (int i = (r)-1; i >= (l); --i)
#define REVALL(i, l, r) for (int i = (r); i >= (l); --i)
#define ALL(x)          (x).begin(), (x).end()
#define LLA(x)          (x).rbegin(), (x).rend()
#define FST             begin()
#define LST             end()
#define FF(x)           (x).begin(), (x).begin()
#define SZ(x)           (int)((x).size())
#define CONTAINS(x, i)  ((x).find(i) != (x).end())
#define FIC(i, c)       for (auto &i : (c))
#define FPIC(a, b, c)   for (auto &[a, b] : (c))
#define ITER(it, x)     for (auto it = (x).begin(); it != (x).end(); ++it)
#define MP              make_pair
#define MT              make_tuple
#define EB              emplace_back
#define self            (*this)
#define _0              first
#define _1              second
#define TOS             to_string
#define PCT             __builtin_popcount
#define CTZ             __builtin_ctz
#define CLZ             __builtin_clz
#define SOMET           template <typename T>
#define TARGS           template <typename T, typename... Args>
#define TAP             T, Args...
#define ARGS            template <typename... Args>
#define EXP             Args...
#define KV              template <typename K, typename V>
#define KVT             template <typename K, typename V, typename T>
#define TGET(tup, i)    get<i>(tup)
#define MUN(x)          (*(x).begin())
#define CHI(x)          (*((x).end() - 1))
#define BINREP(n)       bitset<32>((uint)n)
#define SQ(x)           ((x)*(x))

SOMET using COUPLE  =    array<T, 2>;
SOMET using TRIPLE  =    array<T, 3>;
SOMET using QUAD    =    array<T, 4>;
using Byte  =           unsigned char;
using LLD   =           long long;
using ULLD  =           unsigned long long;
using UINT  =           unsigned int;
using PII   =           pair<int, int>;
using VI    =           vector<int>;
using VVI   =           vector<VI>;
using VPII  =           vector<PII>;
using MII   =           map<int, int>;
using SI    =           set<int>;
using VVP   =           vector<VPII>;
using PLLD  =           pair<LLD, LLD>;
using VLLD  =           vector<LLD>;
using VVLLD =           vector<VLLD>;
using VPLLD =           vector<PLLD>;
using VB    =           vector<bool>;
using VVB   =           vector<VB>;
using VCh   =           vector<char>;
using VVCh  =           vector<VCh>;
using CI    =           COUPLE<int>;
using TI    =           TRIPLE<int>;
using QI    =           QUAD<int>;
using VCI   =           vector<CI>;
using VTI   =           vector<TI>;
using VQI   =           vector<QI>;

template <size_t n> using INTARR = array<int, n>;
const int INF           = 2147483647 / 2;
const LLD LLDINF        = INT64_MAX / 2;
const string alphabet   = "abcdefghijklmnopqrstuvwxyz";
const int MOD           = 1e9 + 7;















int operator~(const string& s) { return (int)(s.size()); }
char& operator^(string& s, int v) { return s[~s - 1 - v]; }
char& operator-(string &s) { return s[~s - 1]; }


TARGS void operator+=(vector<TAP> &s, T v) { s.push_back(v); }
TARGS T& operator-(vector<TAP> &s) { return s[~s - 1]; }
TARGS T& operator^(vector<TAP> &s, int v) { return s[~s - 1 - v]; }
TARGS T operator--(vector<TAP>& s) { auto k = -s; s.pop_back(); return k; }
TARGS int operator~(const vector<TAP>& s) { return (int)s.size(); }




TARGS void dedup(vector<TAP>& s) { sort(ALL(s)); s.erase(unique(ALL(s)), s.end()); }
TARGS typename vector<TAP>::iterator find(vector<TAP>& s, const T& x) {
    auto it = lower_bound(ALL(s), x); return (it != s.end() && *it == x) ? it : s.end();
}
TARGS int index(vector<TAP>& s, const T& x) {
    auto it = find(s, x); check(it != s.end() && *it == x); return it - s.begin();
}

template<typename T, size_t n> int operator~(const array<T, n>& s) { return (int)s.size(); }

TARGS void operator+=(stack<TAP>& s, T v) { s.push(v); }
TARGS T operator-(stack<TAP>& s) { return s.top(); }
TARGS T operator--(stack<TAP>& s) { auto k = -s; s.pop(); return k; }
TARGS int operator~(const stack<TAP>& s) { return (int)s.size(); }

TARGS void operator+=(queue<TAP>& s, T v) { s.push(v); }
TARGS T operator-(queue<TAP>& s) { return s.front(); }
TARGS T operator--(queue<TAP>& s) { auto k = -s; s.pop(); return k; }
TARGS int operator~(const queue<TAP>& s) { return (int)s.size(); }


TARGS void operator+=(priority_queue<TAP>& s, T v) { s.push(v); }
TARGS T operator-(priority_queue<TAP>& s) { return s.top(); }
TARGS T operator--(priority_queue<TAP>& s) { auto k = -s; s.pop(); return k; }
TARGS int operator~(const priority_queue<TAP>& s) { return (int)s.size(); }

TARGS void operator+=(set<TAP>& s, T v) { s.insert(v); }
TARGS void operator-=(set<TAP>& s, T v) { s.erase(v); }
TARGS bool operator<(T v, set<TAP>& s) { return s.find(v) != s.end(); }
TARGS bool operator>(T v, set<TAP>& s) { return s.find(v) == s.end(); }
TARGS int operator~(const set<TAP>& s) { return (int)s.size(); }

KV void operator+=(map<K, V>& s, pair<K, V> v) { s.insert(v); }
KV void operator-=(map<K, V>& s, K v) { s.erase(v); }
TARGS bool operator<(T v, const map<TAP>& s) { return s.find(v) != s.end(); }
TARGS bool operator>(T v, const map<TAP>& s) { return s.find(v) == s.end(); }
TARGS int operator~(const map<TAP>& s) { return (int)s.size(); }

#ifdef JJ
SOMET void __pvec(const vector<T>& v) {
    stringstream i_tos, v_tos;
    i_tos << "i    "; v_tos << "a[i] ";
    REP(i, ~v) {
        int w = max({~TOS(v[i]), ~TOS(i), 3});
        i_tos << setw(w) << TOS(i) << " ";
        v_tos << setw(w) << TOS(v[i]) << " ";
    }
    cout << i_tos.str() << "\n" << v_tos.str() << "\n";
}

void __pvec(const string& v) {
    stringstream i_tos, v_tos;
    i_tos << "i    "; v_tos << "a[i] ";
    REP(i, ~v) {
        int w = max({~TOS(i), 3});
        i_tos << setw(w) << TOS(i) << " ";
        v_tos << setw(w) << v[i] << " ";
    }
    cout << i_tos.str() << "\n" << v_tos.str() << "\n";
}

SOMET void __p2vec(vector<vector<T>>& v)
{ REP(i, ~v) { cout << "Row: " << i << "\n"; __pvec(v[i]); } }
SOMET void __pmat(vector<vector<T>>& v) {
    int h = ~v, w = ~v[0], z = 3;
    cout << "\n" << setw(z) << "+" << " ";
    REP(j, w) cout << setw(z) << j << " \n"[j == (w - 1)];
    REP(i, h) {
        cout << setw(z) << i << " ";
        REP(j, w) cout << setw(z) << v[i][j] << " \n"[j == (w - 1)];
    }
    cout << "\n";
}
#else
SOMET void __pvec(T& v) {}
SOMET void __p2vec(T& v) {}
SOMET void __pmat(T& v) {}
#endif

KV void read(pair<K, V>& p);
SOMET void read(vector<T>& v);
KV void read(pair<K, V>& p) { read(p._0, p._1); }
SOMET void read(vector<T>& v) { REP(i, ~v) cin >> v[i]; }
SOMET void read(T& x) { cin >> x; }
TARGS void read(T& head, Args&... rest) { read(head); read(rest...); }

#define REINT(n)                int n; read(n);
#define RELLD(n)                LLD n; read(n);
#define RECHAR(c)               char c; read(c);
#define RESTRING(s)             string s; read(s);
#define RE2STRING(s, t)         string s, t; read(s, t);
#define RE2INT(a, b)            int a, b; read(a, b);
#define RE3INT(a, b, c)         int a, b, c; read(a, b, c);
#define RE4INT(a, b, c, d)      int a, b, c, d; read(a, b, c, d);
#define REN_VEC(n, x)           int n; read(n); VI x(n); read(x);
#define REVEC(n, x)             VI x(n); read(x);
#define RE2LLD(a, b)            LLD a, b; read(a, b);
#define REN_VECLLD(n, x)        int n; read(n); VLLD x(n); read(x);
#define REVECLLD(n, x)          VLLD x(n); read(x);

const char* __sep__[2] = {", ", " "};
ARGS ostream& operator<<(ostream& os, const vector<EXP>& v) {
    os << "[ ";
    REP(i, ~v) {os << v[i] << __sep__[i + 1 == ~v];}
    return os << "]";
}
template<typename T, size_t n>
ostream& operator<<(ostream& os, const array<T, n>& v) {
    os << "[ ";
    REP(i, ~v) {os << v[i] << __sep__[i + 1 == ~v];}
    return os << "]";
}
ARGS ostream& operator<<(ostream& os, const set<EXP>& v) {
    os << "{ ";
    ITER(it, v) os << *it << __sep__[next(it) == v.end()];
    return os << "}";
}
KV ostream& operator<<(ostream& os, const map<K, V>& v) {
    os << "{ ";
    ITER(it, v) os << it->first << ": " << it->second
                   << __sep__[next(it) == v.end()];
    return os <<  "}";
}
KV ostream &operator<<(ostream &os, const pair<K, V> &v) {
    return os << "(" << v.first << __sep__[0] << v.second << ")";
}
KV ostream &operator<<(ostream &os, const tuple<K, V> &v) {
    return os << "(" << tget(v, 0) << __sep__[0] << tget(v, 1) << ")";
}
KVT ostream &operator<<(ostream &os, const tuple<K, V, T> &v) {
    return os << "(" << tget(v, 0) << __sep__[0] << tget(v, 1)
           << __sep__[0] << tget(v, 2) << ")";
}

SOMET void __swrite(const char* sep, const T& x) { cout << x << sep; }
TARGS void __swrite(const char* sep, const T& x, const Args&... a) { cout << x << sep; __swrite(sep, a...); }

ARGS void writeln(const Args&... a) { __swrite("\n", a...); }
void writeln() { cout << "\n"; }

ARGS void writes(const Args&... a) { __swrite(" ", a...); }
ARGS void writesln(const Args&... a) { __swrite(" ", a...); writeln();}
ARGS void write(const Args&... a) { __swrite("", a...); }

TARGS void mkmax(T& a, Args&&... z) { a = max({a, z...}); }
TARGS void mkmin(T& a, Args&&... z) { a = min({a, z...}); }
TARGS bool ckmax(T& a, Args&&... z) { auto t = a; mkmax(a, z...); return (a != t);  }
TARGS bool ckmin(T& a, Args&&... z) { auto t = a; mkmin(a, z...); return (a != t);  }

int log2_floor(unsigned int n) { return 31 - CLZ(n); }
int log2_ceil(unsigned int n) { return log2_floor(n) + !!(n & (n - 1)); }



class Rng {
    mt19937 mtgen;
    uniform_int_distribution<int> dist_;

  public:
    Rng(int min, int max, size_t seed = random_device()())
        : mtgen(seed), dist_(min, max) {}
    int operator()() { return dist_(mtgen); }
};

VI randomvec(int sz) {
    Rng rg(0, 10);
    VI s;
    REP(i, sz) s += rg();
    return s;
}

string randomstring(int sz) {
    Rng rg((int)'a', (int)'z');
    string s;
    REP(i, sz) s += (char)rg();
    return s;
}

#ifdef JJ
#define deb(...)                                                               \
    {                                                                          \
        cout << '#' << (__LINE__) << ": " << #__VA_ARGS__ << " = ";            \
        writes(__VA_ARGS__);                                                   \
        cout << "\n" << flush;                                                 \
    }
#define putas(...)                                                             \
    { write(__VA_ARGS__); }
#define putsln(...)                                                            \
    { writesln(__VA_ARGS__), cout << flush; }
#define pvec(v)                                                                \
    {                                                                          \
        cout << '#' << (__LINE__) << ": " << #v << " = \n", __pvec(v);         \
        cout << flush;                                                         \
    }
#define p2vec(v)                                                               \
    {                                                                          \
        cout << '#' << (__LINE__) << ": " << #v << " = \n", __p2vec(v);        \
        cout << flush;                                                         \
    }
#define pmat(v)                                                                \
    {                                                                          \
        cout << '#' << (__LINE__) << ": " << #v << " = \n", __pmat(v);         \
        cout << flush;                                                         \
    }
#define linen                                                                  \
    { cout << '#' << (__LINE__) << ":\n"; }
#define check(x)   assert(x)
#define dessert(x) assert(!(x))
#else
#define linen    
#define deb(...) 
#define putas(...)
#define putsln(...)
#define pvec(v)
#define p2vec(v)
#define pmat(v)    ;
#define check(x)   
#define dessert(x) 
#endif

void measure(const string &name, function<void()> func) {
    auto start_time = chrono::high_resolution_clock::now();
    func();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(
        chrono::high_resolution_clock::now() - start_time);
    putsln(name, static_cast<double>(duration.count()) * 0.000001, "ms");
}

#define OTC





void soln(int __ntc, int __tc) {
    RE3INT(n, x, k);
    REVEC(n, A);
    sort(ALL(A));

    auto cnt_between = [&x](int ai, int aj) { return aj / x - (ai - 1) / x; };
    LLD i = 0, l = 0, r = 0, ans = 0;
    for (i = 0; i < n; ++i) {
        while (l < n && (cnt_between(A[i], A[l]) < k || A[l] < A[i])) { ++l; }
        while (r < n && cnt_between(A[i], A[r]) <= k) { ++r; }
        ans += r - l;
    }

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    writeln(ans);
}

int main() {
#ifndef JJ
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
#ifdef OTC
    soln(1, 1);
#else
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        putsln("Test case = ", i + 1);
        soln(tc, i + 1);
    }
#endif
}
