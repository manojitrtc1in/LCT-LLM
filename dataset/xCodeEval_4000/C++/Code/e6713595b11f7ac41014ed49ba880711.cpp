









#include <bits/stdc++.h>
using namespace std;


















typedef long double LD;
typedef unsigned long long ull;
typedef long long ll;
#define int ll

#define pb push_back
#define mp make_pair

#define rep(i,n) for (int i = 0; i < n; i++)
#define ford(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)

#define all(v) v.begin(),v.end()

typedef map<int, int> mii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

#define F first
#define S second

#define PQ(type) priority_queue<type>
#define PQD(type) priority_queue<type,vector<type>,greater<type> >

#define WL(t) while(t --)
#define SZ(x) ((int)(x).size())

#define runtime() ((LD)clock() / CLOCKS_PER_SEC)
#define inrange(i,a,b) ((i>=min(a,b)) && (i<=max(a,b)))

#define PRECISION(x) cout << fixed << setprecision(x);
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);






const int MAXN = 3e5 + 5;
const int SQRTN = 1003;
const int LOGN = 22;
const double PI = acos(-1);

#ifdef int
const int INF = 1e18;
#else
const int INF = 1e9;
#endif

const int MOD =  1e9 + 7;
const int FMOD = 998244353;
const double eps = 1e-9;





void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif






mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define SHUF(v) shuffle(all(v), RNG);








template<typename T> T gcd(T a, T b) {if (b == 0) return a; a %= b; return gcd(b, a);}
template<typename T> T lcm(T a, T b) {return (a * (b / gcd(a, b)));}
int add(int a, int b, int c = MOD) {int res = a + b; return (res >= c ? res % c : res);}
int sub(int a, int b, int c = MOD) {int res; if (abs(a - b) < c)res = a - b; else res = (a - b) % c; return (res < 0 ? res + c : res);}
int mul(int a, int b, int c = MOD) {ll res = (ll)a * b; return (res >= c ? res % c : res);}
int muln(int a, int b, int c = MOD) {ll res = (ll)a * b; return ((res % c) + c) % c;}
ll mulmod(ll a, ll b, ll m = MOD) {ll q = (ll)(((LD)a * (LD)b) / (LD)m); ll r = a * b - q * m; if (r > m)r %= m; if (r < 0)r += m; return r;}
template<typename T>T binpow(T e, T n) {T x = 1, p = e; while (n) {if (n & 1)x = x * p; p = p * p; n >>= 1;} return x;}
template<typename T>T binpow2(T e, T n, T m = MOD) {T x = 1, p = e; while (n) {if (n & 1)x = mul(x, p, m); p = mul(p, p, m); n >>= 1;} return x;}
template<typename T>T extended_euclid(T a, T b, T &x, T &y) {
    T xx = 0, yy = 1; y = 0; x = 1; while (b) {
        T q = a / b, t = b; b = a % b; a = t; \
        t = xx; xx = x - q * xx; x = t; t = yy; yy = y - q * yy; y = t;
    } return a;
}
template<typename T>T mod_inverse(T a, T n = MOD) {T x, y, z = 0; T d = extended_euclid(a, n, x, y); return (d > 1 ? -1 : sub(x, z, n));}

const int FACSZ = 1e4; 


int fact[FACSZ], ifact[FACSZ];





void precom(int c = MOD) {
    fact[0] = 1;
    ford(i, 1, FACSZ) fact[i] = mul(fact[i - 1], i, c);
    ifact[FACSZ - 1] = mod_inverse(fact[FACSZ - 1], c);
    REPD(i, FACSZ - 1) {
        ifact[i] = mul(i + 1, ifact[i + 1], c);
    }
}
vi primes;
void prime_precom() {
    primes.push_back(2);
    for (int x = 3; primes.size() <= MAXN; x += 2) {bool isPrime = true; for (auto p : primes) {if (x % p == 0) {isPrime = false; break;} if (p * p > x) {break;}} if (isPrime) {primes.push_back(x);}}
    

    

    


}
int ncr(int n, int k) {if (n < k) return 0; if (k == 0) return 1; int res = 1; if (k > n - k) k = n - k; for (int i = 0; i < k; ++i) {res *= (n - i); res /= (i + 1);} return res;}
int ncr_modp(int n, int k, int c = MOD) {if (n < k) return 0; if (k == 0) return 1; int res = 1; if (k > n - k) k = n - k; for (int i = 0; i < k; ++i) {res = mul(res, n - i, c); res = mul(res, binpow2(i + 1, c - 2, c), c);} return res;}


vi factors;
void factorize(int a) {factors.clear(); for (int i = 1; i * i <= a; i++) {if (a % i == 0) {factors.pb(i); factors.pb(a / i);}} sort(factors.begin(), factors.end());}

int ncr_precom(int n, int r, int c = MOD) {
    

    return mul(mul(ifact[r], ifact[n - r], c), fact[n], c);
}
int ceil(int a, int b) {return (a + b - 1) / b;}
bool is_prime( int n ) {for (int i = 2; i * i <= n; i++) {if ( n % i == 0 ) {return 0;}} return 1;}
bool diophantine_checker(int a, int b, int n) {for (int i = 0; i * a <= n; i++) {if ((n - (i * a)) % b == 0) {return true;}} return false;}
int count_divisors(int n) {int c; int ans = 1; for (int i = 2; i * i <= n; i++) {c = 0; while (n % i == 0) {c++; n /= i;} ans *= (c + 1);} if (n > 2) {return ans * 2;} return ans;}
string to_binary(int n) {string r; while (n != 0) {r = (n % 2 == 0 ? "0" : "1") + r; n /= 2;} return r;}
bool ispower2(int x) {return x && (!(x & (x - 1)));}



vi spf;
void sieve() {spf.resize(MAXN); spf[1] = 1; ford(i, 2, MAXN) {spf[i] = i;} for (int i = 4; i < MAXN; i += 2) {spf[i] = 2;} for (int i = 3; i * i <= MAXN; i++) {if (spf[i] == i) {for (int j = i * i; j < MAXN; j += i) {if (spf[j] == j) {spf[j] = i;}}}}}
void pfactor(int x, vi &ret) {while (x != 1) {ret.push_back(spf[x]); x = x / spf[x];}}






struct dsu {
public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    


    

    

    int merge(int a, int b) {
        

        

        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);

        int x = leader(a), y = leader(b);

        if (x == y) {
            return x;
        }

        if (-parent_or_size[x] < -parent_or_size[y]) {
            swap(x, y);
        }

        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        

        

        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        

        

        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        

        

        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    vvi groups() {
        

        

        vi leader_buf(_n), group_size(_n);
        rep(i, _n) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        vvi result(_n);
        rep(i, _n) {
            result[i].reserve(group_size[i]);
        }
        rep(i, _n) {
            result[leader_buf[i]].pb(i);
        }
        result.erase(
            remove_if(all(result),
        [&](const vi & v) { return v.empty(); }),
        result.end());
        return result;
    }

private:
    int _n;
    

    

    vi parent_or_size;
};
vi g[MAXN];
int dp[MAXN][LOGN];
vi depth(MAXN);
void dfs(int node, int par = 0) {
    depth[node] = depth[par] + 1;
    dp[node][0] = par;

    

    for (int i = 1; i < LOGN; i++) {
        dp[node][i] = dp[dp[node][i - 1]][i - 1];
    }

    for (auto child : g[node]) {
        if (child == par)continue;

        dfs(child, node);
    }
}


int ancestor(int node, int k) {
    


    for (int i = 0; i < LOGN && node; i++) {
        if (k & (1ll << i)) {
            node = dp[node][i];
        }
    }
    return (node == 0 ? -1 : node);
}


int lca(int node1, int node2) {
    if (depth[node1] < depth[node2]) {
        swap(node2, node1);
    }

    node1 = ancestor(node1, depth[node1] - depth[node2]);

    if (node1 == node2)return node1;


    for (int i = LOGN - 1; i >= 0; i--) {
        if (dp[node1][i] != dp[node2][i]) {
            node1 = dp[node1][i];
            node2 = dp[node2][i];
        }
    }

    return dp[node1][0];
}


void solvethetestcase() {
    int n, m;
    cin >> n >> m;
    vpii e;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        e.pb({a, b});
    }
    int q; cin >> q;
    vector<bool> cnt(n, 0);
    vpii quer;
    WL(q) {
        int a, b;
        cin >> a >> b;
        quer.pb({a, b});
        a--, b--;
        cnt[a] = cnt[a] ^ 1;
        cnt[b] = cnt[b] ^ 1;
    }
    int ans = 0;
    rep(i, n) {
        if (cnt[i]) {
            ans++;
        }
    }

    if (ans) {
        cout << "NO\n" << ans / 2 << "\n"; return;
    }

    dsu ds(n);

    for (auto x : e) {
        if (!ds.same(x.F, x.S)) {
            ds.merge(x.F, x.S);
            x.F++, x.S++;
            g[x.F].pb(x.S);
            g[x.S].pb(x.F);
        }
    }

    dfs(1);
    cout << "YES\n";
    for (auto x : quer) {
        int l = lca(x.F, x.S);
        int cur = x.F;
        vi pathL, pathR;
        while (cur != dp[l][0]) {
            pathL.pb(cur);
            cur = dp[cur][0];
        }
        cur = x.S;
        while (cur != l) {
            pathR.pb(cur);
            cur = dp[cur][0];
        }
        reverse(all(pathR));

        cout << pathL.size() + pathR.size() << "\n";
        for (auto z : pathL) {
            cout << z << " ";
        }

        for (auto z : pathR) {
            cout << z << " ";
        }
        cout << "\n";
    }

}




signed main() {


#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif

    PRECISION(12);
    FAST_IO
    int t = 1;

    

    




    ford(testcase, 1, t + 1) {
        

        

        solvethetestcase();


    }

    


}





