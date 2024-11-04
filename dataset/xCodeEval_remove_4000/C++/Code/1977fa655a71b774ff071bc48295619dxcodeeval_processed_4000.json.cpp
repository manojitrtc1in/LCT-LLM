

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;






TTi T SQR(T x) { return x * x; }





















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


    
    
    
    

    inline void id9(int line) { cerr << "
    inline void id4(vector<string>::iterator it) {cerr << endl;}

    TTi void id11(vector<T> val) {
        cerr << arrStr(val, val.size());
    }
    TTi void id11(T* val) {
        cerr << arrStr(val, 10);
    }
    TTi void id11(T val) {
        cerr << val;
    }
    template<typename T, typename... Args>
    inline void id4(vector<string>::iterator it, T a, Args... args) {
        cerr << it->substr((*it)[0] == ' ', it->length()) << "=";
        id11(a);
        cerr << "; ";
        id4(++it, args...);
    }

    
    
    
    


template<class T> inline string TOSTR(const T & x) { stringstream ss; ss << x; return ss.str(); }




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
V id14(const std::map <K,V> & m, const K & key, const V & defval ) {
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

vector<LL> id6(LL a, LL b) {
    

    

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
vector<map<int, int>> id2;
vector<map<int, int>> id0;

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



pair<LL, LL> id7(LL a, LL b, LL c, LL d, bool indexes1) {
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

    vector<LL> xg = id6(-b, d);
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

void id5(int gi) {
    set<int> primes;
    FOREACH(pe, id2[0]) primes.insert(pe.first);
    FOREACH(pe, id0[0]) primes.insert(pe.first);
    FOREACH(pe, id2[gi]) primes.insert(pe.first);
    FOREACH(pe, id0[gi]) primes.insert(pe.first);

    pair<LL, LL> inds0 = {0, 1};
    pair<LL, LL> inds1 = {0, 1};
    int iter = 0;
    FOREACH(p, primes) {
        LL a = id14(id2[0], p, 0);
        LL b = id14(id0[0], p, 0);
        LL c = id14(id2[gi], p, 0);
        LL d = id14(id0[gi], p, 0);

        EPR("\nPrime %d (%lld %lld, %lld %lld)\n", p, a, b, c, d);
        auto id12 = id7(a, b, c, d, RESULT_INDEXES);
        auto id3 = id7(c, d, a, b, RESULT_INDEXES);
        EPR("inds0: %lld %lld, inds1: %lld %lld\n", inds0.first, inds0.second, inds1.first, inds1.second);
        EPR("id12: %lld %lld, id3: %lld %lld\n", id12.first, id12.second, id3.first, id3.second);
        if (id12.first == EMPTY || id3.first == EMPTY) DIE("-1\n");
        if (iter++ == 0) {
            inds0 = id12;
            inds1 = id3;
            continue;
        }

        

        
        

        LL da1 = inds1.first - inds0.first;
        LL db1 = inds1.second - inds0.second;

        LL dc1 = id3.first - id12.first;
        LL dd1 = id3.second - id12.second;

        

        auto id13 = id7(da1, db1, dc1, dd1, RESULT_INDEXES);
             

        pair<LL,LL> id8 = {inds0.first + id13.first * inds0.second, id13.second * inds0.second};
        EPR("deltas: %lld %lld, new %lld %lld. Intersect (indexes): %lld %lld (values): %lld %lld\n",
            da1, db1, dc1, dd1,
            id13.first, id13.second,
            id8.first, id8.second
        );

        

        auto id1 = id7(id8.first, id8.second, inds0.first, inds0.second, RESULT_PROGRESSION);
             id1 = id7(id1.first, id1.second, id12.first, id12.second, RESULT_PROGRESSION);

        inds0 = id1;
        if (inds0.first == EMPTY) DIE("-1\n");

        pair<LL,LL> id10 = {da1 + inds0.first * db1, inds0.second * db1};

        inds1 = {
            inds0.first + id10.first,
            inds0.first + inds0.second + id10.first + id10.second,
        };
        

        

        EPR("inds0: %lld %lld, inds1: %lld %lld\n", inds0.first, inds0.second, inds1.first, inds1.second);
        if (inds0.first == EMPTY || inds1.first == EMPTY) DIE("-1\n");
        
    }

    EVARS(cur_s, cur_t, inds0.first, inds0.second);
    auto res = id7(cur_s, cur_t, inds0.first, inds0.second, RESULT_PROGRESSION);
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
        id2.push_back(P.factorize2map(a));
        id0.push_back(P.factorize2map(b));
    }

    if (N == 1) DIE("%d\n", geoms[0].first % MOD);

    cur_s = 0;
    cur_t = 1;
    FOR(i, 1, N) {
        EPR("---\n\nIntersect with %d: %d %d\n", i, geoms[i].first, geoms[i].second);
        id5(i);
        assert(cur_s < 2e18);
        assert(cur_t < 2e18);
    }

    EVARS(geoms[0].first, cur_s, cur_t);
    LL res = (geoms[0].first % MOD) * powmod((geoms[0].second % MOD), cur_s, MOD);
    res %= MOD;
    cout << res << endl;

    return 0;
}
