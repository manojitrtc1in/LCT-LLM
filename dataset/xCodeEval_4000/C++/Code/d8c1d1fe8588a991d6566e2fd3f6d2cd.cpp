








#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <random>
#include <assert.h>
#include <memory.h>
#include <time.h>

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)

using namespace std;

inline void setmin(int &x, int y) { if (y < x) x = y; }
inline void setmax(int &x, int y) { if (y > x) x = y; }
inline void setmin(ll &x, ll y) { if (y < x) x = y; }
inline void setmax(ll &x, ll y) { if (y > x) x = y; }

const int N = 100000;
const int inf = (int)1e9 + 1;
const ll big = (ll)1e18 + 1;
const int P = 239;
const int P1 = 31;
const int P2 = 57;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const int MOD2 = 998244353;
const double eps = 1e-9;
const double pi = atan2(0, -1);
const int ABC = 26;

class Math
{
public:
    bool is_square(ll n)
    {
        ll x = round(sqrt(n));
        return x * x == n;
    }

    ll gcd(ll a, ll b)
    {
        while (a > 0)
        {
            ll c = a;
            a = b % a;
            b = c;
        }
        return b;
    }

    ll gcd_ex(ll a, ll b, ll &x, ll &y) 

    {
        if (a == 0)
        {
            x = 0; y = 1;
            return b;
        }
        ll x1, y1;
        ll d = gcd_ex(b % a, a, x1, y1);
        x = y1 - (b / a) * x1;
        y = x1;
        return d;
    }

    ll rev_mod(ll a, ll mod)
    {
        ll x, y;
        gcd_ex(a, mod, x, y);
        return (x % mod + mod) % mod;
    }

    vector<ll> get_rev_mod(ll mod)
    {
        vector<ll> r(mod);
        r[0] = 0; r[1] = 1;
        for (ll i = 2; i < mod; i++)
            r[i] = (mod - (mod / i) * r[mod % i] % mod) % mod;
        return r;
    }

    vector<ll> get_rev_mod(ll n, ll mod)
    {
        vector<ll> r(n + 1);
        r[0] = 0; r[1] = 1;
        for (ll i = 2; i < n + 1; i++)
            r[i] = (mod - (mod / i) * r[mod % i] % mod) % mod;
        return r;
    }

    ll fact(ll n, ll mod) 

    {
        ll res = 1;
        for (ll i = 1; i <= n; i++)
            res = (res * i) % mod;
        return res;
    }

    ll fact_mod(ll n, ll mod) 

    {
        ll res = 1;
        while (n > 1) {
            res = (res * ((n / mod) % 2 ? mod - 1 : 1)) % mod;
            for (int i = 2; i <= n % mod; i++)
                res = (res * i) % mod;
            n /= mod;
        }
        return res % mod;
    }

    vector<ll> get_fact(ll n, ll mod)
    {
        vector<ll> fact(n + 1, 1);
        rep(i, 1, n + 1)
            fact[i] = (fact[i - 1] * i) % mod;
        return fact;
    }

    ll A(ll n, ll k, ll mod)
    {
        ll res = fact(n, mod);
        res = (res * rev_mod(fact(n - k, mod), mod)) % mod;
        return res;
    }

    ll A(ll n, ll k, ll mod, vector<ll> &fact)
    {
        ll res = fact[n];
        res = (res * rev_mod(fact[n - k], mod)) % mod;
        return res;
    }

    ll A(ll n, ll k, ll mod, vector<ll> &fact, vector<ll> &rev_mod)
    {
        ll res = fact[n];
        res = (res * rev_mod[fact[n - k]]) % mod;
        return res;
    }

    ll C(ll n, ll k, ll mod)
    {
        ll res = fact(n, mod);
        res = (res * rev_mod(fact(k, mod), mod)) % mod;
        res = (res * rev_mod(fact(n - k, mod), mod)) % mod;
        return res;
    }

    ll C(ll n, ll k, ll mod, vector<ll> &fact)
    {
        ll res = fact[n];
        res = (res * rev_mod(fact[k], mod)) % mod;
        res = (res * rev_mod(fact[n - k], mod)) % mod;
        return res;
    }

    ll C(ll n, ll k, ll mod, vector<ll> &fact, vector<ll> &rev_mod)
    {
        ll res = fact[n];
        res = (res * rev_mod[fact[k]]) % mod;
        res = (res * rev_mod[fact[n - k]]) % mod;
        return res;
    }

    ll C_(ll n, ll k, ll mod) 

    {
        return C(n + k - 1, k - 1, mod);
    }

    ll C_(ll n, ll k, ll mod, vector<ll> &fact) 

    {
        return C(n + k - 1, k - 1, mod, fact);
    }

    ll C_(ll n, ll k, ll mod, vector<ll> &fact, vector<ll> &rev_mod) 

    {
        return C(n + k - 1, k - 1, mod, fact, rev_mod);
    }

    ll Catalan(ll n, ll mod)
    {
        return C(n * 2, n, mod) * rev_mod(n + 1, mod) % mod;
    }

    ll Catalan(ll n, ll mod, vector<ll> &fact)
    {
        return C(n * 2, n, mod, fact) * rev_mod(n + 1, mod) % mod;
    }

    ll Catalan(ll n, ll mod, vector<ll> &fact, vector<ll> &rev_mod)
    {
        return C(n * 2, n, mod, fact, rev_mod) * rev_mod[n + 1] % mod;
    }

    ll get_t(ll n)
    {
        while (n % 2 == 0)
            n /= 2;
        return n;
    }

    ll get_s(ll n)
    {
        ll s = 0;
        while (n % 2 == 0)
        {
            n /= 2;
            s++;
        }
        return s;
    }

    ll log_2(ll n)
    {
        ll cnt = 1, curr = 0;
        while (cnt < n)
        {
            cnt <<= 1;
            curr++;
        }
        return curr;
    }

    ll min_pow_2(ll n)
    {
        ll cnt = 1, curr = 0;
        while (cnt < n)
        {
            cnt <<= 1;
            curr++;
        }
        return cnt;
    }

    ll bin_mult(ll a, ll n, ll mod)
    {
        ll res = 0;
        while (n) {
            if (n & 1)
                res = (res + a) % mod;
            a = (a + a) % mod;
            n >>= 1;
        }
        return res;
    }

    ll bin_pow(ll a, ll n, ll mod)
    {
        ll res = 1;
        while (n) {
            if (n & 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            n >>= 1;
        }
        return res;
    }

    ll bin_pow_ll(ll a, ll n, ll mod)
    {
        ll res = 1;
        while (n) {
            if (n & 1)
                res = bin_mult(res, a, mod) % mod;
            a = bin_mult(a, a, mod) % mod;
            n >>= 1;
        }
        return res;
    }

    bool miller_rabin(ll n)
    {
        srand(time(0));
        if (n == 2 || n == 3)
            return true;
        if (n == 1 || n % 2 == 0)
            return false;
        ll k = log_2(n);
        ll t = get_t(n - 1);
        ll s = get_s(n - 1);
        for (ll i = 0; i < k; i++)
        {
            ll a = rand() % (n - 3) + 2;
            ll x = bin_pow_ll(a, t, n);
            if (x == 1 || x == n - 1)
                continue;
            bool b = false;
            for (ll j = 0; j < s - 1; j++)
            {
                x = bin_mult(x, x, n);
                if (x == 1)
                    return false;
                if (x == n - 1)
                {
                    b = true;
                    break;
                }
            }
            if (!b)
                return false;
        }
        return true;
    }

    bool isprime(ll n)
    {
        if (n == 1)
            return false;
        for (ll i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }

    vector<ll> getprimes(ll n)
    {
        vector<bool> e(n + 1, true);
        vector<ll> primes;
        e[0] = false;
        e[1] = false;
        for (ll i = 2; i <= n; i++)
            if (e[i])
            {
                primes.push_back(i);
                for (ll j = i + i; j <= n; j += i)
                    e[j] = false;
            }
        return primes;
    }

    vector<bool> Eratosthenes(ll n)
    {
        vector<bool> e(n + 1, true);
        e[0] = false;
        e[1] = false;
        for (ll i = 2; i <= n; i++)
            if (e[i])
                for (ll j = i + i; j <= n; j += i)
                    e[j] = false;
        return e;
    }

    vector<ll> Eratosthenes_n(ll n)
    {
        vector<ll> lp(n + 1, 0);
        vector<ll> pr;
        for (ll i = 2; i <= n; i++)
        {
            if (lp[i] == 0)
            {
                lp[i] = i;
                pr.push_back(i);
            }
            for (ll j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= n; j++)
                lp[i * pr[j]] = pr[j];
        }
        return lp;
    }

    vector<pair<ll, ll> > Factorization(ll n)
    {
        vector<pair<ll, ll> > f;
        for (ll i = 2; i * i <= n; i++)
            if (n % i == 0)
            {
                f.push_back({i, 0});
                while (n % i == 0)
                {
                    f[sz(f) - 1].se++;
                    n /= i;
                }
            }
        if (n > 1)
            f.push_back({n, 1});
        return f;
    }

    vector<pair<ll, ll> > Factorization(ll n, vector<ll> &lp)
    {
        vector<pair<ll, ll> > f;
        while (n > 1)
        {
            if (sz(f) > 0 && f[sz(f) - 1].fi == lp[n])
                f[sz(f) - 1].se++;
            else
                f.push_back({lp[n], 1});
            n /= lp[n];
        }
        return f;
    }

    ll cntdivisors2(ll n)
    {
        ll cnt = 0;
        for (ll i = 1; i * i <= n; i++)
            if (n % i == 0)
            {
                if (i * i != n)
                    cnt += 2;
                else
                    cnt++;
            }
        return cnt;
    }

    ll cntdivisors3(ll n)
    {
        ll p = 1;
        while (p * p * p < n)
            p++;
        vector<ll> primes = getprimes(p);
        ll cnt = 1;
        for (ll i = 0; i < primes.size(); i++)
        {
            ll curr = 0;
            while (n % primes[i] == 0)
            {
                n /= primes[i];
                curr++;
            }
            cnt *= (curr + 1);
        }
        if (n == 1)
            cnt *= 1;
        else if (miller_rabin(n))
            cnt *= 2;
        else if (is_square(n))
            cnt *= 3;
        else
            cnt *= 4;
        return cnt;
    }

    ll ETF(ll n) 

    {
        ll res = n;
        vector<pair<ll, ll> > f = Factorization(n);
        for (auto p : f)
            res -= res / p.fi;
        return res;
    }

    ll ETF(ll n, vector<ll> &lp) 

    {
        ll res = n;
        vector<pair<ll, ll> > f = Factorization(n, lp);
        for (auto p : f)
            res -= res / p.fi;
        return res;
    }
};

class Matrix
{
public: ll n;
public: ll mod;
public: vector<vector<ll> > matrix;

public: Matrix(ll n, ll mod)
    {
        this->n = n;
        this->mod = mod;
        matrix.resize(n);
        for (ll i = 0; i < n; i++)
            matrix[i].resize(n, 0);
    }

public: void mult(Matrix m)
    {
        vector<vector<ll> > ans(n);
        for (ll i = 0; i < n; i++)
            ans[i].resize(n, 0);
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j < n; j++)
                for (ll k = 0; k < n; k++)
                    ans[i][j] = (ans[i][j] + matrix[k][j] * m.matrix[i][k]) % mod;
        swap(matrix, ans);
    }

public: void mult()
    {
        vector<vector<ll> > ans(n);
        for (ll i = 0; i < n; i++)
            ans[i].resize(n, 0);
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j < n; j++)
                for (ll k = 0; k < n; k++)
                    ans[i][j] = (ans[i][j] + matrix[k][j] * matrix[i][k]) % mod;
        swap(matrix, ans);
    }

public: void binpow(ll p)
    {
        Matrix tmp = Matrix(n, mod);
        tmp.matrix = matrix;
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j < n; j++)
                matrix[i][j] = (i == j ? 1 : 0);
        while (p)
        {
            if (p & 1)
                mult(tmp);
            tmp.mult();
            p >>= 1;
        }
    }

public: void print()
    {
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }

};

class Vector
{
public: ll n;
public: ll mod;
public: vector<ll> vect;

public: Vector(ll n, ll mod)
    {
        this->n = n;
        this->mod = mod;
        vect.resize(n, 0);
    }

public: void mult(Matrix m)
    {
        vector<ll> ans(n, 0);
        for (ll i = 0; i < n; i++)
            for (ll k = 0; k < n; k++)
                ans[i] = (ans[i] + vect[k] * m.matrix[i][k]) % mod;
        swap(vect, ans);
    }

public: void print()
    {
        for (ll i = 0; i < n; i++)
            cout << vect[i] << " ";
        cout << "\n";
    }

};

ll bin_pow(ll a, ll p, ll mod) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        p >>= 1;
    }
    return res;
}

ll rev_mod(ll a, ll mod) {
    return bin_pow(a, mod - 2, mod);
}






ll get_log(ll x, ll a, ll mod) {
    

    ll aa = rev_mod(a, mod);
    const int B = 30000;
    map<ll, ll> mapa;
    rep(i, 0, B) {
        mapa[x * bin_pow(aa, i, mod) % mod] = i;
    }
    ll aB = bin_pow(a, B, mod);
    ll res = 1;
    for (ll cur = 0; cur * B < mod; cur++) {
        auto it = mapa.find(res);
        if (it != mapa.end()) {
            return cur * B + it->se;
        }
        res = res * aB % mod;
    }
    return -1;
}

Math math;

void solve(ll a, ll b, ll mod, ll &u0, ll &g) {
    

    g = math.gcd(a, mod);
    if (b % g != 0) {
        u0 = -1;
        return;
    }
    a /= g;
    b /= g;
    mod /= g;
    u0 = b * math.rev_mod(a, mod) % mod;
    return;
}

int main()
{
    

    

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(100);
    cout << fixed;
    

    


    
    

    

    int k;
    cin >> k;
    int b[k];
    rep(i, 0, k) {
        cin >> b[i];
    }
    int n, m;
    cin >> n >> m;

    

    Matrix matr = Matrix(k, MOD2 - 1);
    rep(i, 0, k - 1) {
        matr.matrix[i][i + 1] = 1;
    }
    rep(i, 0, k) {
        matr.matrix[k - 1][i] = b[k - 1 - i];
    }
    matr.binpow(n - k);
    Vector dp = Vector(k, MOD2 - 1);
    dp.vect[k - 1] = 1;
    
    dp.mult(matr);
    ll pw = dp.vect[k - 1];
    


    if (pw == 0) {
        if (m == 1) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
        return 0;
    }

    ll g = 3;
    

    ll c = get_log(m, g, MOD2);
    

    if (c == -1) {
        assert(false);
        cout << -1 << "\n";
        return 0;
    }
    

    ll u0, d;
    solve(pw, c, MOD2 - 1, u0, d);
    if (u0 == -1) {
        cout << -1 << "\n";
        return 0;
    }
    


    


    ll t = get_log(m * rev_mod(bin_pow(3, u0 * pw, MOD2), MOD2) % MOD2, bin_pow(3, (MOD2 - 1) / d * pw, MOD2), MOD2);
    

    

    

    if (t != -1) {
        ll ST = bin_pow(3, u0 + (MOD2 - 1) / d * t, MOD2);
        

        assert(bin_pow(ST, pw, MOD2) == m);
        cout << ST << "\n";
    } else {
        cout << -1 << "\n";
    }

    

    
    return 0;
}
