#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;

#define MAX_INT (int)0x7fffffff
#define MIN_INT (int)0x80000000
#define MAX_UINT (uint)0xffffffff

#define TTi template<typename T> inline
TTi T SQR(T x) { return x * x; }

#define CONCAT3_NX(x, y, z) x ## y ## z
#define CONCAT3(x, y, z) CONCAT3_NX(x, y, z)
#define VAR(name) CONCAT3(__tmpvar__, name, __LINE__)
#define TYPE(x) __typeof(x)

#define FOR(i, s, n)  for (TYPE(n) i=(s),   VAR(end)=(n);  i <  VAR(end);  i++)
#define RFOR(i, s, n) for (TYPE(n) i=(n)-1, VAR(end)=(s);  i >= VAR(end);  i--)
#define FORN(i, n)    FOR(i, 0, n)
#define RFORN(i, n)   RFOR(i, 0, n)
#define FOREACH(i, v) for (auto& i: v)

#define MP(a, b) make_pair(a, b)
#define WHOLE(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define POPST(stack) (stack).top();(stack).pop();
#define POPQ(queue) (queue).front();(queue).pop();
#define CONTAINS(v, x) (find(WHOLE(v), (x)) != v.end())
#define SORT(v) (sort(WHOLE(v)))

#define LIMIT(x, lim) {if (x > lim) x = lim;}
TTi T MIN(T x, T y) { return (x < y) ? x : y; }
TTi T MAX(T x, T y) { return (x > y) ? x : y; }
TTi T ABS(T x) { return (x > 0) ? x : -x; }
TTi void UPDATE_MIN(T &x, T y) {if (y < x) {x = y;}}
TTi void UPDATE_MAX(T &x, T y) {if (x < y) {x = y;}}
TTi int ARGMAX(T cont) { return max_element(cont.begin(), cont.end()) - cont.begin(); }
TTi int ARGMIN(T cont) { return min_element(cont.begin(), cont.end()) - cont.begin(); }

vector<string> split(const string& s, char c) {
    vector<string> v; stringstream ss(s); string x;
    while (getline(ss, x, c)) v.emplace_back(x); return move(v);
}
template<typename T, typename... Args>
inline string arrStr(T arr, int n) {
    stringstream s;
    s << "[";
    FORN(i, n - 1) s << arr[i] << ",";
    s << arr[n - 1] << "]";
    return s.str();
}

#ifndef ONLINE_JUDGE
    #define EPR(args...)   if (DEBUG) {fprintf(stderr, args);}
    #define EARR(arr, n)   if (DEBUG) {FORN(i, n) fprintf(stderr, "%d, ", arr[i]);}
    #define EVEC(arr)      if (DEBUG) {FORN(i, arr.size()) fprintf(stderr, "%d, ", arr[i]);}
    #define EVARS(args...) if (DEBUG) { __evars_begin(__LINE__); __evars(split(#args, ',').begin(), args);}

    inline void __evars_begin(int line) { cerr << "#" << line << ": "; }
    inline void __evars(vector<string>::iterator it) {cerr << endl;}

    TTi void __evars_out_var(vector<T> val) {
        cerr << arrStr(val, val.size());
    }
    TTi void __evars_out_var(T* val) {
        cerr << arrStr(val, 10);
    }
    TTi void __evars_out_var(T val) {
        cerr << val;
    }
    template<typename T, typename... Args>
    inline void __evars(vector<string>::iterator it, T a, Args... args) {
        cerr << it->substr((*it)[0] == ' ', it->length()) << "=";
        __evars_out_var(a);
        cerr << "; ";
        __evars(++it, args...);
    }
#else
    #define EPR(args...) 1
    #define EARR(args...) 1
    #define EVEC(args...) 1
    #define EVARS(args...) 1
#endif

template<class T> inline string TOSTR(const T & x) { stringstream ss; ss << x; return ss.str(); }
#define DIE(args...) {EVARS(1);printf(args);exit(0);}
#define PR(x) cout << (x) << endl
#define PRF(x) cout << fixed << setprecision(10) << x << endl

inline int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
inline LL gcd(LL a, LL b) { return a ? gcd(b % a, a) : b; }
inline LL powmod(LL a, LL p, LL m) { LL r = 1; while (p) { if (p & 1) r = r*a%m; p>>=1; a=a*a%m; } return r; }

struct pairhash {
    template <typename T, typename U>
    std::size_t operator() (const std::pair<T, U> &x) const {
        return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
    }
};

template <typename K, typename V>
V GetWithDef(const std::map <K,V> & m, const K & key, const V & defval ) {
    auto it = m.find(key);
    return (it == m.end()) ? defval : it->second;
}

template <typename K, typename V>
void SetDef(std::map <K,V> & m, const K & key, const V & defval ) {
    auto it = m.find(key);
    if (it == m.end()) m[key] = defval;
}

const int MOD = 1000 * 1000 * 1000 + 7;
const double PI = 3.1415926535897932384626433832795l;










#define DEBUG 1

struct Primes {
    vector<bool> is_prime;
    vector<int> primes;

    void sieve(int upto) {
        is_prime.assign(upto + 1, true);
        is_prime[1] = false;
        for(int p = 2; p < upto; p++)
            if (is_prime[p])
                for(int kp = 2*p; kp <= upto; kp += p)
                    is_prime[kp] = false;

        primes.clear();
        primes.push_back(2);
        for(int p = 3; p <= upto; p += 2)
            if (is_prime[p])
                primes.push_back(p);
    }

    vector<pair<int, int>> factorize2pairs(int n) {
        vector<pair<int, int>> f;
        assert(n > 0);
        if (n == 1) return f;
        assert(primes.size() > 0);
        assert(primes.back() * primes.back() >= n);
        for(auto p: primes) {
            int e = 0;
            while (n % p == 0) {
                e++;
                n /= p;
            }
            if (e) f.push_back(make_pair(p, e));
            if (p * p > n) break;
        }
        if (n > 1) f.push_back(make_pair(n, 1));
        return f;
    }

    map<int, int> factorize2map(int n) {
        map<int, int> f;
        assert(n > 0);
        if (n == 1) return f;
        assert(primes.size() > 0);
        assert(primes.back() * primes.back() >= n);
        for(auto p: primes) {
            int e = 0;
            while (n % p == 0) {
                e++;
                n /= p;
            }
            if (e) f[p] = e;
            if (p * p > n) break;
        }
        if (n > 1) f[n] = 1;
        return f;
    }
};

vector<LL> xgcd(LL a, LL b) {
    

    

    if (a == 0) return {0, 1, b};
    if (b == 0) return {1, 0, a};
    int siga = (a < 0) ? -1 : 1;
    int sigb = (b < 0) ? -1 : 1;
    if (siga == -1) a = -a;
    if (sigb == -1) b = -b;

    LL px = 0, ppx = 1;
    LL py = 1, ppy = 0;

    while (b > 0) {
        LL q = a / b;

        

        LL tmp = b;
        b = a % b;
        a = tmp;

        LL x = ppx - q * px;
        LL y = ppy - q * py;
        ppx = px;
        ppy = py;
        px = x;
        py = y;
    }
    return {ppx * siga, ppy * sigb, a};
}

Primes P;
int N;
vector<pair<int, int>> geoms;
vector<map<int, int>> a_facts;
vector<map<int, int>> b_facts;

LL EMPTY = -313333337LL;
LL cur_s = EMPTY;
LL cur_t = EMPTY;

LL coolmod(LL a, LL mod) {
    assert(mod > 0);
    if (a < 0)
        a += ((-a) / mod) * mod + mod;
    a %= mod;
    return a;
}

LL mulix(LL a, LL b, LL d) {
    LL sig = 1;
    if (a < 0) {a = -a; sig *= -1;}
    if (b < 0) {b = -b; sig *= -1;}
    if (d < 0) {d = -d; sig *= -1;}
    

    LL g = gcd(a, d);
    a /= g;
    d /= g;

    g = gcd(b, d);
    b /= g;
    d /= g;
    return sig * a * b / d;
}

#define RESULT_PROGRESSION 0
#define RESULT_INDEXES 1
pair<LL, LL> intersect_arith(LL a, LL b, LL c, LL d, bool indexes1) {
    assert(a < 2e18);
    assert(b < 2e18);
    assert(c < 2e18);
    assert(d < 2e18);

    

    EVARS(a, b, c, d);

    

    if (a == EMPTY)
        return {EMPTY, 0};

    

    if (b == 0 && d == 0) {
        if (a != c)
            return {EMPTY, 0};
        return (indexes1) ? MP(0LL, 1LL) : MP((LL)a, 0LL);
    }

    vector<LL> xg = xgcd(-b, d);
    LL x = xg[0], y = xg[1], g = xg[2];
    EVARS(x, y, g);
    assert(d * y - b * x == g);
    if ((a - c) % g)
        return {EMPTY, 0};

    LL k = (a - c) / g;
    d /= g;
    b /= g;

    assert(d * y - b * x == 1);

    LL mindx = ABS(d);
    LL mindy = ABS(b);
    if (y < 0 && mindy == 0) return {EMPTY, 0};
    if (x < 0 && mindx == 0) return {EMPTY, 0};

    

    

    

    EVARS(x, y, k);

    

    if (mindx != 0) {
        LL new_x = coolmod(x, mindx);;
        LL dx = new_x - x;
        if (mindy != 0)
            y += mulix(b, dx, d);
        x = new_x;
    }
    assert(d * y - b * x == 1);

    if (y < 0) {
        LL new_y = coolmod(y, mindy);
        LL dy = new_y - y;
        if (mindx != 0)
            x += mulix(d, dy, b);
        y = new_y;
    }
    assert(d * y - b * x == 1);

    if (x < 0 || y < 0) return {EMPTY, 0}; 


    x *= k;
    y *= k;
    if (y < 0 && mindy == 0) return {EMPTY, 0};
    if (x < 0 && mindx == 0) return {EMPTY, 0};

    EVARS(d, y, b, x, k);
    assert(d * y - b * x == k);

    if (mindx != 0) {
        LL new_x = coolmod(x, mindx);
        LL dx = new_x - x;
        if (mindy != 0)
            y += mulix(b, dx, d);
        x = new_x;
    }
    EVARS(d, y, b, x, k);
    assert(d * y - b * x == k);

    if (y < 0) {
        LL new_y = coolmod(y, mindy);
        LL dy = new_y - y;
        if (mindx != 0)
            x += mulix(d, dy, b);
        y = new_y;
    }
    EVARS(d, y, b, x, k);
    assert(d * y - b * x == k);

    if (x < 0 || y < 0) return {EMPTY, 0}; 


    if (indexes1) {
        EVARS(RESULT_INDEXES, x, mindx);
        return {x, mindx};
    }
    else {
        x = a + g * b * x;
        mindx = g * b * mindx;
        EVARS(RESULT_PROGRESSION, x, mindx);
        return {x, mindx};
    }
}

void intersect_geom(int gi) {
    set<int> primes;
    FOREACH(pe, a_facts[0]) primes.insert(pe.first);
    FOREACH(pe, b_facts[0]) primes.insert(pe.first);
    FOREACH(pe, a_facts[gi]) primes.insert(pe.first);
    FOREACH(pe, b_facts[gi]) primes.insert(pe.first);

    pair<LL, LL> inds0 = {0, 1};
    pair<LL, LL> inds1 = {0, 1};
    int iter = 0;
    FOREACH(p, primes) {
        LL a = GetWithDef(a_facts[0], p, 0);
        LL b = GetWithDef(b_facts[0], p, 0);
        LL c = GetWithDef(a_facts[gi], p, 0);
        LL d = GetWithDef(b_facts[gi], p, 0);

        EPR("\nPrime %d (%lld %lld, %lld %lld)\n", p, a, b, c, d);
        auto new_inds0 = intersect_arith(a, b, c, d, RESULT_INDEXES);
        auto new_inds1 = intersect_arith(c, d, a, b, RESULT_INDEXES);
        EPR("inds0: %lld %lld, inds1: %lld %lld\n", inds0.first, inds0.second, inds1.first, inds1.second);
        EPR("new_inds0: %lld %lld, new_inds1: %lld %lld\n", new_inds0.first, new_inds0.second, new_inds1.first, new_inds1.second);
        if (new_inds0.first == EMPTY || new_inds1.first == EMPTY) DIE("-1\n");
        if (iter++ == 0) {
            inds0 = new_inds0;
            inds1 = new_inds1;
            continue;
        }

        

        #if 1
        

        LL da1 = inds1.first - inds0.first;
        LL db1 = inds1.second - inds0.second;

        LL dc1 = new_inds1.first - new_inds0.first;
        LL dd1 = new_inds1.second - new_inds0.second;

        

        auto dlt_indexes = intersect_arith(da1, db1, dc1, dd1, RESULT_INDEXES);
             

        pair<LL,LL> int_dlt = {inds0.first + dlt_indexes.first * inds0.second, dlt_indexes.second * inds0.second};
        EPR("deltas: %lld %lld, new %lld %lld. Intersect (indexes): %lld %lld (values): %lld %lld\n",
            da1, db1, dc1, dd1,
            dlt_indexes.first, dlt_indexes.second,
            int_dlt.first, int_dlt.second
        );

        

        auto tmp_inds0 = intersect_arith(int_dlt.first, int_dlt.second, inds0.first, inds0.second, RESULT_PROGRESSION);
             tmp_inds0 = intersect_arith(tmp_inds0.first, tmp_inds0.second, new_inds0.first, new_inds0.second, RESULT_PROGRESSION);

        inds0 = tmp_inds0;
        if (inds0.first == EMPTY) DIE("-1\n");

        pair<LL,LL> new_deltas = {da1 + inds0.first * db1, inds0.second * db1};

        inds1 = {
            inds0.first + new_deltas.first,
            inds0.first + inds0.second + new_deltas.first + new_deltas.second,
        };
        

        

        EPR("inds0: %lld %lld, inds1: %lld %lld\n", inds0.first, inds0.second, inds1.first, inds1.second);
        if (inds0.first == EMPTY || inds1.first == EMPTY) DIE("-1\n");
        #endif
    }

    EVARS(cur_s, cur_t, inds0.first, inds0.second);
    auto res = intersect_arith(cur_s, cur_t, inds0.first, inds0.second, RESULT_PROGRESSION);
    cur_s = res.first;
    cur_t = res.second;
    EVARS(cur_s, cur_t);
    if (cur_s == EMPTY)
        DIE("-1\n");
}

int main() {
    ios_base::sync_with_stdio(0);

    P.sieve(100123);

    

    

    

    

    

    


    cin >> N;
    FORN(i, N) {
        int a, b;
        cin >> a >> b;
        geoms.push_back(MP(a, b));
        a_facts.push_back(P.factorize2map(a));
        b_facts.push_back(P.factorize2map(b));
    }

    if (N == 1) DIE("%d\n", geoms[0].first % MOD);

    cur_s = 0;
    cur_t = 1;
    FOR(i, 1, N) {
        EPR("---\n\nIntersect with %d: %d %d\n", i, geoms[i].first, geoms[i].second);
        intersect_geom(i);
        assert(cur_s < 2e18);
        assert(cur_t < 2e18);
    }

    EVARS(geoms[0].first, cur_s, cur_t);
    LL res = (geoms[0].first % MOD) * powmod((geoms[0].second % MOD), cur_s, MOD);
    res %= MOD;
    cout << res << endl;

    return 0;
}
