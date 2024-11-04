










using namespace std;


















typedef long double LD;
typedef unsigned long long ull;
typedef long long ll;












typedef map<int, int> mii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;





















const int MAXN = 2e5 + 5;
const int id10 = 1003;
const int LOGN = 22;
const double PI = acos(-1);


const int INF = 1e18;

const int INF = 1e9;


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











mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());









template<typename T> T gcd(T a, T b) {if (b == 0) return a; a %= b; return gcd(b, a);}
template<typename T> T lcm(T a, T b) {return (a * (b / gcd(a, b)));}
int add(int a, int b, int c = MOD) {int res = a + b; return (res >= c ? res % c : res);}
int sub(int a, int b, int c = MOD) {int res; if (abs(a - b) < c)res = a - b; else res = (a - b) % c; return (res < 0 ? res + c : res);}
int mul(int a, int b, int c = MOD) {ll res = (ll)a * b; return (res >= c ? res % c : res);}
int muln(int a, int b, int c = MOD) {ll res = (ll)a * b; return ((res % c) + c) % c;}
ll mulmod(ll a, ll b, ll m = MOD) {ll q = (ll)(((LD)a * (LD)b) / (LD)m); ll r = a * b - q * m; if (r > m)r %= m; if (r < 0)r += m; return r;}
template<typename T>T binpow(T e, T n) {T x = 1, p = e; while (n) {if (n & 1)x = x * p; p = p * p; n >>= 1;} return x;}
template<typename T>T id6(T e, T n, T m = MOD) {T x = 1, p = e; while (n) {if (n & 1)x = mul(x, p, m); p = mul(p, p, m); n >>= 1;} return x;}
template<typename T>T id7(T a, T b, T &x, T &y) {
    T xx = 0, yy = 1; y = 0; x = 1; while (b) {
        T q = a / b, t = b; b = a % b; a = t; \
        t = xx; xx = x - q * xx; x = t; t = yy; yy = y - q * yy; y = t;
    } return a;
}
template<typename T>T mod_inverse(T a, T n = MOD) {T x, y, z = 0; T d = id7(a, n, x, y); return (d > 1 ? -1 : sub(x, z, n));}

const int id4 = 1e4; 


int fact[id4], ifact[id4];





void precom(int c = MOD) {
    fact[0] = 1;
    ford(i, 1, id4) fact[i] = mul(fact[i - 1], i, c);
    ifact[id4 - 1] = mod_inverse(fact[id4 - 1], c);
    REPD(i, id4 - 1) {
        ifact[i] = mul(i + 1, ifact[i + 1], c);
    }
}
vi primes;
void id5() {
    primes.push_back(2);
    for (int x = 3; primes.size() <= MAXN; x += 2) {bool isPrime = true; for (auto p : primes) {if (x % p == 0) {isPrime = false; break;} if (p * p > x) {break;}} if (isPrime) {primes.push_back(x);}}
    

    

    


}
int ncr(int n, int k) {if (n < k) return 0; if (k == 0) return 1; int res = 1; if (k > n - k) k = n - k; for (int i = 0; i < k; ++i) {res *= (n - i); res /= (i + 1);} return res;}
int id2(int n, int k, int c = MOD) {if (n < k) return 0; if (k == 0) return 1; int res = 1; if (k > n - k) k = n - k; for (int i = 0; i < k; ++i) {res = mul(res, n - i, c); res = mul(res, id6(i + 1, c - 2, c), c);} return res;}


vi factors;
void factorize(int a) {factors.clear(); for (int i = 1; i * i <= a; i++) {if (a % i == 0) {factors.pb(i); factors.pb(a / i);}} sort(factors.begin(), factors.end());}

int id0(int n, int r, int c = MOD) {
    

    return mul(mul(ifact[r], ifact[n - r], c), fact[n], c);
}
int ceil(int a, int b) {return (a + b - 1) / b;}
bool is_prime( int n ) {for (int i = 2; i * i <= n; i++) {if ( n % i == 0 ) {return 0;}} return 1;}
bool id3(int a, int b, int n) {for (int i = 0; i * a <= n; i++) {if ((n - (i * a)) % b == 0) {return true;}} return false;}
int id1(int n) {int c; int ans = 1; for (int i = 2; i * i <= n; i++) {c = 0; while (n % i == 0) {c++; n /= i;} ans *= (c + 1);} if (n > 2) {return ans * 2;} return ans;}
string to_binary(int n) {string r; while (n != 0) {r = (n % 2 == 0 ? "0" : "1") + r; n /= 2;} return r;}
bool id11(int x) {return x && (!(x & (x - 1)));}



vi spf;
void sieve() {spf.resize(MAXN); spf[1] = 1; ford(i, 2, MAXN) {spf[i] = i;} for (int i = 4; i < MAXN; i += 2) {spf[i] = 2;} for (int i = 3; i * i <= MAXN; i++) {if (spf[i] == i) {for (int j = i * i; j < MAXN; j += i) {if (spf[j] == j) {spf[j] = i;}}}}}
void pfactor(int x, vi &ret) {while (x != 1) {ret.push_back(spf[x]); x = x / spf[x];}}






vi v[MAXN];
vi par(MAXN);
int start;
vi a(MAXN);
vi flat_tree(MAXN);
vi in(MAXN), out(MAXN);
void dfs1(int node, int p = 0) {
    par[node] = p;
    in[node] = ++start;
    flat_tree[start] = abs(a[node]);

    for (auto child : v[node]) {
        if (child ^ p) {
            dfs1(child, node);
        }
    }
    out[node] = ++start;
    flat_tree[start] = -abs(a[node]);
}

int dp[MAXN][LOGN];
vi depth(MAXN);
void dfs(int node, int p = 0) {
    depth[node] = depth[p] + 1;
    dp[node][0] = p;

    

    for (int i = 1; i < LOGN; i++) {
        dp[node][i] = dp[dp[node][i - 1]][i - 1];
    }

    for (auto child : v[node]) {
        if (child == p)continue;

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

template <class T> struct id9 {
public:
    id9() : _n(0) {}

    id9(int n) : _n(n), data(n) {}
    


    void add(int i, T delta) {
        

        

        assert(0 <= i && i < _n);
        i++;
        while (i <= _n) {
            data[i - 1] += (delta);
            i += i & -i;
        }
    }

    T sum(int l, int r) {
        

        

        assert(0 <= l && l <= r && r <= _n);

        return sum(r) - sum(l);
    }

private:
    int _n;
    vector<T> data;

    T sum(int r) {
        T s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

void id8() {
    int n, q;
    cin >> n >> q;
    rep(i, n) {
        cin >> a[i + 1];
    }
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs1(1); dfs(1);

    id9<int> ft(2 * n + 2);
    rep(i, 2 * n + 1) {
        ft.add(i, flat_tree[i]);
    }

    WL(q) {
        int op; cin >> op;
        if (op == 1) {
            int u, x;
            cin >> u >> x;
            


            int i1 = in[u];
            int i2 = out[u];

            int v1 = ft.sum(i1, i1 + 1);
            int v2 = ft.sum(i2, i2 + 1);
            ft.add(i1, -v1); ft.add(i2, -v2);

            ft.add(i1, abs(x)); ft.add(i2, -abs(x));
        } else {
            int e1, e2;
            cin >> e1 >> e2;

            int l = lca(e1, e2);
            if (l == e1 || l == e2) {
                if (l == e2) {
                    swap(e1, e2);
                }
                if (e1 == e2) {
                    cout << 0 << "\n"; continue;
                }
                cout << ft.sum(in[e1], in[e2] + 1ll) + ((in[e1] + 1 < in[e2]) ? ft.sum(in[e1] + 1, in[e2]) : 0ll) << "\n";
            } else {
                cout << ft.sum(in[l], in[e1] + 1ll) + ft.sum(in[l], in[e2] + 1ll) + ((in[l] + 1ll < in[e1]) ? ft.sum(in[l] + 1ll, in[e1]) : 0ll) + ((in[l] + 1ll < in[e2]) ? ft.sum(in[l] + 1ll, in[e2]) : 0ll) << "\n";
            }
        }
    }

}



signed main() {



    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);



    PRECISION(12);
    FAST_IO
    int t = 1;

    

    




    ford(testcase, 1, t + 1) {
        

        

        id8();


    }

    


}





