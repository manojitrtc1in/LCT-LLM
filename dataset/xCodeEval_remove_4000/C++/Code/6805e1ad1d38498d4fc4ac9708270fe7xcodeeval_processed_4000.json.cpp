

















































typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace __gnu_pbds; 

using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef vector<ll> VLL;
typedef vector<int> VI;
const ll mod = 998244353;


string to_string (string s) { return '"' + s + '"'; }

string to_string (const char *s) { return to_string ((string) s); }

string to_string (bool b) { return (b ? "true" : "false"); }

template<typename A, typename B>
string to_string (pair<A, B> p) { return "(" + to_string (p.first) + ", " + to_string (p.second) + ")"; }

template<typename A>
string to_string (A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) { res += ", "; }
        first = false;
        res += to_string (x);
    }
    res += "}";
    return res;
}

void debug_out () { cerr<<endl; }

template<typename Head, typename... Tail>
void debug_out (Head H, Tail... T) {
    cerr<<" "<<to_string (H);
    debug_out (T...);
}







template<typename T, typename S>
inline bool upmin (T &a, const S &b) { return a > b ? a = b, 1 : 0; }

template<typename T, typename S>
inline bool upmax (T &a, const S &b) { return a < b ? a = b, 1 : 0; }


ull twop (ll x) { return 1ULL<<x; }

ll MOD (ll a, ll m) {
    a %= m;
    if (a < 0)a += m;
    return a;
}

ll inverse (ll a, ll m) {
    a = MOD (a, m);
    if (a <= 1)return a;
    return MOD ((1 - inverse (m, a) * m) / a, m);
}

template<typename T>
T sqr (T x) { return x * x; }

ll gcd (ll a, ll b) {
    a = abs (a), b = abs (b);
    while (b != 0) {
        a %= b;
        swap (a, b);
    }
    return a;
}

ll fast (ll a, ll b, ll mod) {
    a %= mod;
    if (b < 0)a = inverse (a, mod), b = -b;
    ll ans = 1;
    while (b) {
        if (b & 1)ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans % mod;
}


namespace NTT {
    const int mod = 998244353, g = 3;
    

    

    

    

    
    void id5 (VI &a) {
        int n = sz (a);
        for (int i = 1, j = n>>1, k; i < n - 1; i++) {
            if (i < j) swap (a[i], a[j]);
            for (k = n>>1; j >= k; j -= k, k >>= 1);
            j += k;
        }
    }
    
    void NTT (VI &a, int type) {
        id5 (a);
        int n = sz (a);
        for (int i = 2; i <= n; i *= 2) {
            const auto wi = fast (g, type * (mod - 1) / i, mod); 

            for (int j = 0; j < n; j += i) {
                ll w = 1;
                for (int k = j, h = i / 2; k < j + h; k++) {
                    int t = w * a[k + h] % mod, u = a[k];
                    a[k] = (u + t) % mod;
                    a[k + h] = (u - t + mod) % mod;
                    w = w * wi % mod;
                }
            }
        }
        const ll inv = inverse (n, mod);
        if (type == -1) for (auto &x : a) x = x * inv % mod;
    }
    
    
    VI conv (const VI &a, const VI &b, const int n, const int m, const int mod = NTT::mod) {
        VI _a (begin (a), begin (a) + n);
        VI _b (begin (b), begin (b) + m);
        int len = 1;
        while (len <= n + m - 2) len <<= 1;
        while (len != lowbit (len)) len += lowbit (len);
        _a.resize (len), _b.resize (len);
        NTT (_a, 1), NTT (_b, 1);
        REP (i, 0, len)_a[i] = (ll) _a[i] * _b[i] % mod;
        NTT (_a, -1);
        _a.resize (n + m - 1);
        return _a;
    }
}


namespace Poly {
    using NTT::mod;
    using NTT::conv;
    VI iv ({0, 1}), fac ({1, 1}), id6 ({1, 1});
    
    void init (const int n) {
        while (sz (iv) <= n) {
            ll cur = sz (iv);
            iv.emplace_back ((mod - (ll) mod / cur * iv[mod % cur] % mod));
            fac.PB (cur * fac.back () % mod);
            id6.PB ((ll) iv.back () * id6.back () % mod);
        }
    }
    
    

    VI inv (const VI &poly) {
        int n = 1;
        VI res (1);
        res[0] = inverse (poly[0], mod);
        while (n < sz (poly)) {
            auto new_res = conv (res, res, n, n, mod);
            new_res = conv (poly, new_res, min (2 * n, sz (poly)), sz (new_res), mod);
            res.resize (2 * n, 0);
            REP (i, 0, 2 * n) {
                res[i] = (2ll * res[i] - (i < sz (new_res) ? new_res[i] : 0) + mod) % mod;
            }
            n *= 2;
        }
        res.resize (sz (poly));
        return res;
    }
    
    VI integrate (const VI &poly) {
        init (sz (poly));
        VI res (sz (poly), 0);
        REP (i, 1, sz (res)) {
            res[i] = poly[i - 1] * (ll) iv[i] % mod;
        }
        return res;
    }
    
    VI differentiate (const VI &poly) {
        VI res (sz (poly), 0);
        REP (i, 0, sz (res) - 1) {
            res[i] = poly[i + 1] * ll (i + 1) % mod;
        }
        return res;
    }
    
    VI log (const VI &poly) {
        auto res = integrate (conv (differentiate (poly), inv (poly), sz (poly), sz (poly), mod));
        res.resize (sz (poly));
        return res;
    }
    
    

    VI exp (const VI &poly) {
        int n = 1;
        VI res (1, 1);
        VI tmp;
        while (n < sz (poly)) {
            tmp = res;
            tmp.resize (2 * n, 0);
            tmp = log (tmp);
            REP (i, 0, 2 * n) {
                tmp[i] = (ll (i == 0) - tmp[i] + (i < sz (poly) ? poly[i] : 0) + mod) % mod;
            }
            res = conv (res, tmp, n, 2 * n, mod);
            res.resize (2 * n, 0);
            n *= 2;
        }
        res.resize (sz (poly));
        return res;
    }
    
    

    VI power (const VI &poly, const ll k) {
        auto low = find_if (all (poly), [] (const int x) { return x != 0; });
        if (low == end (poly))return VI (sz (poly), 0);
        ll padding = (low - begin (poly)) * k;
        if (padding >= sz (poly))return VI (sz (poly), 0);
        VI tmp (low, end (poly));
        ll inv = inverse (*low, mod);
        for (auto &x:tmp) x = x * inv % mod;
        tmp = log (tmp);
        for (auto &x:tmp) x = x * (k % mod) % mod;
        tmp = exp (tmp);
        ll pw = fast (inv, -k, mod);
        for (auto &x:tmp) x = x * pw % mod;
        if (padding) {
            VI zeros (padding, 0);
            tmp.insert (tmp.begin (), all (zeros));
        }
        tmp.resize (sz (poly), 0);
        return tmp;
    }
    
    ll id2 (ll a, ll p) {
        auto isSquare = [&] (ll a, ll p) {
            return fast (a, (p - 1) / 2, p) == 1;
        };
        if (a == 0) return 0;
        if (p == 2) return a;
        if (!isSquare (a, p)) return -1;
        ll b = 2;
        while (isSquare ((b * b - a + p) % p, p)) b++;
        ll w = (b * b - a + p) % p;
        
        auto mul = [&] (PLL u, PLL v) {
            ll a = (u.first * v.first + u.second * v.second % p * w) % p;
            ll b = (u.first * v.second + u.second * v.first) % p;
            return MP (a, b);
        };
        
        

        ll e = (p + 1) / 2;
        auto ret = MP (1, 0);
        auto v = MP (b, 1);
        while (e > 0) {
            if (e & 1) ret = mul (ret, v);
            v = mul (v, v);
            e /= 2;
        }
        return ret.first;
    }
    
    VI sqrt (VI poly) {
        const int len = sz (poly);
        init (2);
        const auto low = find_if (all (poly), [] (const int x) { return x != 0; });
        if (low == end (poly))return VI (sz (poly), 0);
        int padding = (low - begin (poly));
        if (padding & 1) return VI (1, -1);
        padding >>= 1;
        poly = VI (low, end (poly));
        VI res (1);
        res[0] = id2 (poly[0], mod);
        if (res[0] == -1)return res;
        res[0] = min (res[0], mod - res[0]);
        int n = 1;
        while (n < len) {
            n *= 2;
            res.resize (n, 0);
            auto other = conv (poly, inv (res), min (2 * n, sz (poly)), n, mod);
            REP (i, 0, n) {
                res[i] = (res[i] + other[i]) * ll (iv[2]) % mod;
            }
        }
        if (padding) {
            VI zeros (padding, 0);
            res.insert (res.begin (), all (zeros));
        }
        res.resize (len, 0);
        return res;
    }
    
    pair<VI, VI> divmod (VI f, VI g) {
        auto id1 = [] (VI &poly) {
            while (sz (poly) and poly.back () == 0)poly.pop_back ();
        };
        id1 (f);
        id1 (g);
        assert (sz (g) > 0);
        const int n = sz (f) - 1, m = sz (g) - 1;
        if (n < m)return MP (VI (), f);
        auto rev = [] (VI poly) {
            reverse (all (poly));
            return poly;
        };
        auto rg = rev (g);
        rg.resize (n, 0);
        auto q = (conv (rev (f), inv (rg), sz (f), sz (rg)));
        q.resize (n - m + 1, 0);
        q = rev (q);
        auto prod = conv (g, q, sz (g), sz (q));
        auto r = f;
        REP (i, 0, sz (r))r[i] = (r[i] - prod[i] + mod) % mod;
        r.resize (m, 0);
        id1 (r);
        return MP (q, r);
    }
    
    VI shift (const VI &poly, const int n) {
        init (sz (poly));
        VI a (sz (poly)), b (sz (poly));
        REP (i, 0, sz (a))a[i] = (ll) fac[i] * poly[i] % mod;
        for (int i = 0, prod = 1; i < sz (poly); i++, prod = (ll) prod * n % mod) {
            b[i] = (ll) id6[i] * prod % mod;
        }
        VI res (sz (poly));
        reverse (all (b));
        a = conv (a, b, sz (a), sz (b));
        REP (i, 0, sz (res)) {
            res[i] = (ll) a[i + sz (poly) - 1] * id6[i] % mod;
        }
        return res;
    }
    
    
    

    VI id3 (const int n) {
        if (n == 0) return VI ({1});
        else {
            VI a = id3 (n / 2);
            VI b = shift (a, mod - n / 2);
            a = conv (a, b, sz (a), sz (b));
            if (n & 1) {
                a.PB (0);
                RREP (i, n, 0) {
                    a[i] = (ll (a[i]) * (mod - (n - 1)) + (i > 0 ? a[i - 1] : 0)) % mod;
                }
            }
            return a;
        }
    }
    
    
    VI id4 (const int n) {
        init (n);
        VI a (begin (id6), begin (id6) + n + 1), b (begin (id6), begin (id6) + n + 1);
        ll cur = 1;
        REP(i, 0, n + 1) {
            if (i & 1)b[i] = mod - b[i];
            a[i] = MOD (a[i] * fast (i, n, mod), mod);
        }
        auto res = conv (a, b, n + 1, n + 1);
        res.resize (n + 1);
        return res;
    }
    
    

    

    

    VI id0 (const int n) {
        init (n + 2);
        VI v (begin (id6) + 1, begin (id6) + n + 2);
        v = inv (v);
        REP(i, 0, sz (v))v[i] = v[i] * ll (fac[i]) % mod;
        return v;
    }
    
    

}


namespace SOLVE {
    const ll mod = 998244353;
    
    void main () {
        int n, a, b;
        cin>>n>>a>>b;
        if (!a or !b) {
            cout<<0;
            return;
        }
        a--;
        b--;
        VI v (n + 10);
        Poly::init (n + 10);
        
        REP(i, 1, sz (v))v[i] = Poly::iv[i];
        auto va = Poly::power (v, a+b);
        ll ans = 1ll * va[n-1] * Poly::id6[a]%mod * Poly::id6[b] % mod;
        cout<<1ll * ans * Poly::fac[n - 1] % mod<<endl;
    }
}


signed main () {

    fr("/Users/zhangqingchuan/Desktop/cp/cp/input.txt");
    fw("/Users/zhangqingchuan/Desktop/cp/cp/output.txt");

    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);
    
    
    int t = 1;


    for (int i = 1; i <= t; i++) {


        SOLVE::main ();
        
    }
















    
    
    
    
    
    
    return 0;
}