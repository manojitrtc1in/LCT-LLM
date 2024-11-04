





using namespace __gnu_pbds;
using namespace std;
























void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



int n,  m, y, e, t, k, q, u1, u2,  w, c, d, x, ans;
const int mx = 400005, mod = 998244353, mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;
vector<int> prime;
vector<int> spf(10000005, INF);
map<int, int> prime_factor;
vector<int> adj[mx2];
vector<int> vis(mx2, 0);

int setBit(int n) {
    int count = 0;
    while (n) {n = n & (n - 1); count += 1;}
    return count;
}

int fme(int a, int b) {
    int rest = 1;
    while (b) {
        if (b & 1) rest = ((int)1 * rest * a + mod) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return rest;
}

int modinv(int a) {return fme(a, mod - 2);}

int btod(string s) {
    int len = s.length(), cur = 0, ind = 0;
    for (int i = (len - 1); i >= 0; i--) {
        if (s[i] == '1') cur += pow(2, ind);
        ind++;
    }
    return cur;
}

int id0(int a, int b) {
    if (b > a) swap(a, b);
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int gcd = id0(b, a % b);
    int lastx = x, lasty = y;
    x = lasty;
    y = lastx - (a / b) * lasty;
    return gcd;
}

void sieve(int mx) { 

    vector<int> v(mx, 1);
    v[0] = 0, v[1] = 0;
    for (int i = 2; i < mx; i++) {
        if (v[i]) {
            for (int j = i * i; j < mx; j += i) v[j] = 0;
        }
    }
    for (int i = 2; i < mx; i++) {
        if (v[i]) prime.pb(i);
    }
    return;
}

void SPF(int mx) { 

    spf[1] = 1;
    for (int i = 2; i < mx; i ++) {
        if (spf[i] == INF) {
            spf[i] = i;
            for (int j = i * i; j < mx; j += i) spf[j] = min(spf[j], i);
        }
    }
}

void id1(int num) { 

    while (num > 1) {
        prime_factor[spf[num]]++;
        num /= spf[num];
    }
    return;
}

vector<int> dfs(int v, int p) {
    vis[v] = 1;
    

    for (auto it : adj[v]) {
        if (!vis[it]) {
            auto ret = dfs(it, v);
            ret.pb(v);
            return ret;
        }
        else {
            return {v};
        }
    }
    return {};
}

void solve() {
    cin >> n; string s; cin >> s;
    fo(i, n + 1) {
        adj[i].clear();
        vis[i] = 0;
    }
    vector<int> p(n + 1, 0); fo1(i, n + 1) cin >> p[i];
    fo1(i, n + 1) {
        adj[i].pb(p[i]);
        

    }
    vector<int> lcm;
    fo1(i, n + 1) {
        if (!vis[i]) {
            debug(i)
            auto ret = dfs(i, -1);
            debug(ret)
            

            

            

            

            

            reverse(all(ret));
            vector<int> cpy(ret);
            int m = sz(ret);
            int cnt = 0;
            while (true) {
                cnt++;
                int val = cpy[m - 1];
                cpy.erase(cpy.begin() + m - 1);
                cpy.insert(cpy.begin(), val);
                int dif = 0;
                fo(j, m) {
                    if (s[cpy[j] - 1] != s[ret[j] - 1]) {
                        dif = 1;
                        break;
                    }
                }
                if (!dif) break;
            }
            lcm.pb(cnt);
        }
    }
    debug(lcm)
    if (sz(lcm)) {
        int gcd = lcm[0], prod = lcm[0], ans = lcm[0];
        fo1(i, sz(lcm)) {
            gcd = __gcd(ans, lcm[i]);
            ans = (ans * lcm[i]) / gcd;
        }
        

        cout << ans << nl;
    }
    else cout << 1 << nl;
    return;
}

signed main()
{   tezi

    

    freopen("input.txt", "r", stdin);
    

    freopen("output.txt", "w", stdout);
    

    freopen("Errors.txt", "w", stderr);

    cin >> t;
    

    fo(i, t) solve();
    return 0;
}


