

















using namespace std;
using i64 = int_fast64_t;
using ui64 = uint_fast64_t;
using db = long double;
using pii = pair<int, int>;
using pli = pair<int_fast64_t, int>;
using pll = pair<int_fast64_t, int_fast64_t>;
using pdi = pair<double, int>;
template <class T> using vct = vector<T>;
template <class T> using heap = priority_queue<T>;
template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template <class T> constexpr T inf = numeric_limits<T>::max() / (T)1024;
constexpr int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr long double Pi = 3.1415926535897932384626433832795028841971;
constexpr long double Golden = 1.61803398874989484820;
constexpr long double eps = 1e-15;




























struct setupper {
    setupper() {
        if(iostream_untie) {
            ios::sync_with_stdio(false);
            std::cin.tie(nullptr);
            std::cout.tie(nullptr);
            std::cerr.tie(nullptr);
        }
        std::cout << fixed << setprecision(stdout_precision);
        std::cerr << fixed << setprecision(stderr_precision);

        if(!freopen("input.txt","rt",stdin)) {
            cerr << "Failed to open the input file.\n"; exit(EXIT_FAILURE);
        }
        

        

        

        

        

        

        

        

        

        


    }
} id4;

namespace std {
    template <class RAitr> void rsort(RAitr __first, RAitr __last) {
        sort(__first, __last, greater<>());
    }
    template <class T> void id3(size_t &seed, T const &key) {
        seed ^= hash<T>()(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    template <class T, class U> struct hash<pair<T,U>> {
        size_t operator()(pair<T,U> const &pr) const
        {
            size_t seed = 0;
            id3(seed,pr.first);
            id3(seed,pr.second);
            return seed;
        }
    };
    template <class Tup, size_t index = tuple_size<Tup>::value - 1> struct hashval_calc {
        static void apply(size_t& seed, Tup const& tup) {
            hashval_calc<Tup, index - 1>::apply(seed, tup);
            id3(seed,get<index>(tup));
        }
    };
    template <class Tup> struct hashval_calc<Tup,0> {
        static void apply(size_t& seed, Tup const& tup) {
            id3(seed,get<0>(tup));
        }
    };
    template <class ...T> struct hash<tuple<T...>> {
        size_t operator()(tuple<T...> const& tup) const
        {
            size_t seed = 0;
            hashval_calc<tuple<T...>>::apply(seed,tup);
            return seed;
        }
    };
}

template <class T, class U> istream &operator>> (istream &s, pair<T,U> &p) { return s >> p.first >> p.second; }
template <class T, class U> ostream &operator<< (ostream &s, const pair<T,U> p) { return s << p.first << " " << p.second; }
template <class T> ostream &operator<< (ostream &s, const vector<T> &v) {
    for(size_t i = 0; i < v.size(); ++i) s << (i ? " " : "") << v[i]; return s;
}

dump_func(__VA_ARGS__)
template <class T> void dump_func(T x) { cerr << x << '\n'; }
template <class T,class ...Rest> void dump_func(T x, Rest ... rest) { cerr << x << ","; dump_func(rest...); }
template <class T = i64> T read() { T x; return cin >> x, x; }
template <class T> void write(T x) { cout << x << '\n'; }
template <class T, class ...Rest> void write(T x, Rest ... rest) { cout << x << ' '; write(rest...); }
void writeln() {}
template <class T, class ...Rest> void writeln(T x, Rest ... rest) { cout << x << '\n'; writeln(rest...); }


namespace updater {
    template <class T> static void add(T &x, const T &y) { x += y; }
    template <class T> static void ext_add(T &x, const T &y, size_t w) { x += y * w; }
    template <class T> static void mul(T &x, const T &y) { x *= y; }
    template <class T> static void ext_mul(T &x, const T &y, size_t w) { x *= (T)pow(y,w); }
    template <class T, class U> static bool chmax(T &x, const U &y) { return x < y ? x = y,true : false; }
    template <class T, class U> static bool chmin(T &x, const U &y) { return x > y ? x = y,true : false; }
};
using updater::add;
using updater::chmax;
using updater::chmin;

template <class T> T minf(const T &x, const T &y) { return min(x,y); }
template <class T> T maxf(const T &x, const T &y) { return max(x,y); }
bool bit(i64 n, int e) { return e >= 0 ? (n >> e) & 1 : 0; }
i64 mask(i64 n, int e) { return e >= 0 ? n & ((1 << e) - 1) : 0; }
int ilog(uint64_t x, uint64_t b = 2) { return x ? 1 + ilog(x / b,b) : -1; }
template <class F> i64 binry(i64 ok, i64 ng, const F &fn) {
    while (abs(ok - ng) > 1) {
        i64 mid = (ok + ng) / 2;
        (fn(mid) ? ok : ng) = mid;
    }
    return ok;
}
template <class A, size_t N, class T> void init(A (&array)[N], const T &val) { fill((T*)array,(T*)(array + N),val); }
template <class A> void cmprs(A ary[], size_t n) {
    vector<A> tmp(ary,ary + n);
    tmp.erase(unique(begin(tmp),end(tmp)), end(tmp));
    for(A *i = ary; i != ary + n; ++i) *i = l_bnd(all(tmp),*i) - begin(tmp);
}
template <class T> void cmprs(vector<T> &v) {
    vector<T> tmp = v; sort(begin(tmp),end(tmp));
    tmp.erase(unique(begin(tmp),end(tmp)), end(tmp));
    for(auto i = begin(v); i != end(v); ++i) *i = l_bnd(all(tmp),*i) - begin(tmp);
}
template <class F> void for_subset(uint_fast64_t s, const F &fn) {
    uint_fast64_t tmp = s;
    do { fn(tmp); } while((--tmp &= s) != s);
}





namespace Calcfn {
    
        
    
    struct modint {
        int x;
        constexpr modint() : x(0) {}
        constexpr modint(int_fast64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

        constexpr modint &operator+=(const modint &p) {
            if((x += p.x) >= mod) x -= mod;
            return *this;
        }

        constexpr modint &operator ++() { return ++x,*this; }

        constexpr modint operator ++(int) {
            modint t = *this; 
            return ++x,t;
        }

        constexpr modint &operator-=(const modint &p) {
            if((x += mod - p.x) >= mod) x -= mod;
            return *this;
        }

        constexpr modint &operator --() { return --x,*this; }

        constexpr modint operator --(int) {
            modint t = *this;
            return --x,t;
        }

        constexpr modint &operator*=(const modint &p) {
            x = (int) (1LL * x * p.x % mod);
            return *this;
        }

        constexpr modint &operator/=(const modint &p) {
            *this *= inverse(p);
            return *this;
        }

        constexpr modint operator-() { return modint(-x); }

        constexpr modint operator+(const modint &p) { return modint(*this) += p; }

        constexpr modint operator-(const modint &p) { return modint(*this) -= p; }

        constexpr modint operator*(const modint &p) { return modint(*this) *= p; }

        constexpr modint operator/(const modint &p) { return modint(*this) /= p; }

        constexpr bool operator==(const modint &p) { return x == p.x; }

        constexpr bool operator!=(const modint &p) { return x != p.x; }

        constexpr bool operator!() { return !x; }

        constexpr bool operator>(const modint &p) { return x > p.x; }

        constexpr bool operator<(const modint &p) { return x <  p.x; }

        constexpr bool operator>=(const modint &p) { return x >= p.x; }

        constexpr bool operator<=(const modint &p) { return x <= p.x; }

        constexpr static modint inverse(const modint &p) {
            int a = p.x, b = mod, u = 1, v = 0;
            while(b > 0) {
                int t = a / b;
                a -= t * b;
                a ^= b ^= a ^= b;
                u -= t * v;
                u ^= v ^= u ^= v;
            }
            return modint(u);
        }

        constexpr static modint pow(modint p, uint_fast64_t e) {
            if(!e) return 1;
            if(!p) return 0;
            return pow(p * p, e >> 1) * (e & 1 ? p : 1);
        }

        friend ostream &operator<<(ostream &s, const modint &p) { return s << p.x; }

        friend istream &operator>>(istream &s, modint &p) {
            uint_fast64_t x;
            p = modint((s >> x,x));
            return s;
        }
    };

    constexpr static int N = 2e5 + 2e4, N_max = 2e6 + 2e5;

    struct impl {
        int_fast64_t fact_[N + 1],invfact_[N + 1],inv_[N + 1];

        constexpr impl() : fact_(),invfact_(),inv_() {
            fact_[0] = 1;
            for(int i = 1; i <= N; ++i) fact_[i] = fact_[i - 1] * i % mod;
            inv_[1] = 1;
            for(int i = 2; i <= N; ++i) inv_[i] = mod - inv_[mod % i] * (mod / i) % mod;
            invfact_[0] = 1;
            for(int i = 1; i <= N; ++i) invfact_[i] = invfact_[i - 1] * inv_[i] % mod;
        }
    };
    constexpr static impl id1;

    int_fast64_t _dyn_fact[N_max + 1];
    int_fast64_t _dyn_inv[N_max + 1];
    int_fast64_t _dyn_invfact[N_max + 1];

    static int_fast64_t dyn_fact(int x) {
        assert(x <= N_max);
        if(x < 0) return 0;
        static size_t _size = 1;
        for(size_t &i = _size; i <= x; ++i) {
            if(i <= N) _dyn_fact[i] = id1.fact_[i];
            else _dyn_fact[i] = _dyn_fact[i - 1] * i % mod;
        }   
        return _dyn_fact[x];
    }

    static int_fast64_t id2(int x) {
        assert(x <= N_max);
        if(x < 0)  return 0;
        static size_t _size = 1;
        for(size_t &i = _size; i <= x; ++i) {
            if(i <= N) {
                _dyn_inv[i] = id1.inv_[i];
                _dyn_invfact[i] = id1.invfact_[i];
            } else {
                _dyn_inv[i] = mod - _dyn_inv[mod % i] * (mod / i) % mod;
                _dyn_invfact[i] = _dyn_invfact[i - 1] * _dyn_inv[i] % mod;
            }
        }
        return _dyn_invfact[x];
    }

    static modint fact(int x) {
        if(x > N) return dyn_fact(x);
        return x >= 0 ? id1.fact_[x] : 0;
    }

    static modint invfact(int x) {
        if(x > N) return id2(x);
        return x >= 0 ? id1.invfact_[x] : 0;
    }

    static modint comb(int x, int y) {
        return fact(x) * invfact(y) * invfact(x - y);
    }

    static modint perm(int x, int y) {
        return comb(x,y) * fact(y);
    }

    constexpr static int_fast64_t gcd(int_fast64_t a, int_fast64_t b) {
        if(!b) return a > 0 ? a : -a; return gcd(b, a % b);
    }

    constexpr static int_fast64_t lcm(int_fast64_t a, int_fast64_t b) {
        if(a | b) return a / gcd(a, b) * b; return 0;
    }

    constexpr static int_fast64_t id0(int_fast64_t a, int_fast64_t b, int_fast64_t &x, int_fast64_t &y) {
        int_fast64_t d = a;
        if (b) d = id0(b, a % b, y, x), y -= (a / b) * x;
        else x = 1, y = 0;
        return d;
    }
}
using Calcfn::modint;
using Calcfn::fact;
using Calcfn::perm;
using Calcfn::comb;


int n,k,m;
modint dp[1<<17][17][15];

signed main() {
    cin>>n>>k>>m;
    dp[n][0][0]=1;
    for(int i=n;i;--i) {
        for(int j=0;j<1<<m;++j) {
            for(int h=0;h<=k;++h) {
                if(!dp[i][j][h]) continue;
                dp[i-1][mask(j<<1,m)][h]+=dp[i][j][h];
                dp[i-1][mask(1|(j<<1),m)][h+1]+=dp[i][j][h]*(popcnt(j)+1);
            }
        }
    }
    modint ans;
    for(int j=0;j<1<<m;++j) ans+=dp[0][j][k];
    esc(ans);
}