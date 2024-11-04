


using namespace std;




    ff (i, 0, n) {                    \
        ff (j, 0, m) {                \
            cout << v[i][j] << " ";   \
        }                             \
        cout << '\n';                 \
    }
int ask(const string &s) { int r; return cout << "? " << s <<endl, cin >> r, r; }





typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef unordered_map<int,int> UMPII;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef stack<int> STI;
typedef multiset<int> MSETI;
typedef pair<long, long> PLL;
typedef vector<long> VL;
typedef vector<string> VS;
typedef vector<PLL> VPLL;
typedef vector<VL> VVL;
typedef map<long,long> MPLL;
typedef set<long> SETL;
typedef multiset<long> MSETL;
typedef pair<long long, long long> PLLLL;
typedef vector<ll> VLL;
typedef vector<string> VS;
typedef vector<PLLLL> VPLLLL;
typedef vector<VLL> VVLL;
typedef map<long long,long long> MPLLLL;
typedef set<long long> SETLL;
typedef multiset<long long> MSETLL;






constexpr int inf = 1E9;
constexpr ll INF = 1E18;














const int N = 400005;
ll fact[N];
ll mult(ll a,ll b){
    return ((a % MOD)*(b % MOD))%MOD;
}
ll add(ll a,ll b){
    return ((a % MOD)+(b % MOD))%MOD;
}
ll subt(ll a,ll b){
    ll ans = ((a%mod) - (b%mod))%mod;
    ans%=mod;
    ans = (ans+mod)%mod;
    return ans;
}

ll exp(ll a, ll b){
    ll ans = 1;
    ll po = a;
    while(b!=0){
        if(b%2){
            ans = ((ans%mod)*(po%mod))%mod;
        }
        po = ((po%mod)*(po%mod))%mod;
        b/=2;
    }
    return ans;
}        
ll inv(ll x)
{
	return exp(x, MOD - 2); 

}
ll divide(ll x, ll y)
{
	return mult(x, inv(y));
}
void factorial()
{
	fact[0] = 1;
	for(int i = 1; i < N; i++)
		fact[i] = mult(i, fact[i - 1]);
}






ll C(ll n, ll k)
{
	if(k > n) return 0;
	return divide(fact[n], mult(fact[n - k], fact[k]));
}


ll Pow(ll a, ll n)
{
    if (n == 0) return 0;
    if (n == 1) return a;
    ll c = Pow(a, n / 2) % MOD;
    if (n % 2 == 0) return (c % MOD) * (c % MOD) % MOD;
    return (c % MOD) * (c % MOD) * (a % MOD)% MOD;
}


class id0 {
    public:
    struct node {
        int mn = -1;
        int mx = -1;
        int val = 0;
        ll sum_v = 0;
        int add = 0;
        ll sum_a = 0;
 
        void apply(int l, int r, int v) {
            mn = mx = v;
            val = v;
            sum_v = (ll)v * (r - l + 1);
            add += v;
            sum_a += (ll)v * (r - l + 1);
        }
    };
 
    node unite(const node &a, const node &b) const {
        node res;
        res.mn = min(a.mn, b.mn);
        res.mx = max(a.mx, b.mx);
        res.sum_v = a.sum_v + b.sum_v;
        res.sum_a = a.sum_a + b.sum_a;
        return res;
    }
 
    inline void push(int x, int l, int r) {
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        if (tree[x].val != 0) {
            tree[x + 1].apply(l, y, tree[x].val);
            tree[z].apply(y + 1, r, tree[x].val);
            tree[x].val = 0;
        }
        if (tree[x].add != 0) {
            tree[x + 1].apply(l, y, tree[x].add);
            tree[z].apply(y + 1, r, tree[x].add);
            tree[x].add = 0;
        }
    }
    
    inline void pull(int x, int z) {
        tree[x] = unite(tree[x + 1], tree[z]);
    }
    
    int n;
    vector<node> tree;
    
    void build(int x, int l, int r) {
        if (l == r) {
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        build(x + 1, l, y);
        build(z, y + 1, r);
        pull(x, z);
    }
    
    template <typename M>
    void build(int x, int l, int r, const vector<M> &v) {
        if (l == r) {
            tree[x].apply(l, r, v[l]);
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        build(x + 1, l, y, v);
        build(z, y + 1, r, v);
        pull(x, z);
    }
    
    node get(int x, int l, int r, int ll, int rr) {
        if (ll <= l && r <= rr) {
            return tree[x];
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        push(x, l, r);
        node res{};
        if (rr <= y) {
            res = get(x + 1, l, y, ll, rr);
        } else {
            if (ll > y) {
                res = get(z, y + 1, r, ll, rr);
            } else {
                res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
            }
        }
        pull(x, z);
        return res;
    }
    
    template <typename... M>
    void modify(int x, int l, int r, int ll, int rr, const M&... v) {
        if (ll <= l && r <= rr) {
            tree[x].apply(l, r, v...);
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        push(x, l, r);
        if (ll <= y) {
            modify(x + 1, l, y, ll, rr, v...);
        }
        if (rr > y) {
            modify(z, y + 1, r, ll, rr, v...);
        }
        pull(x, z);
    }
    
    int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
        if (l == r) {
            return l;
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res;
        if (f(tree[x + 1])) {
            res = find_first_knowingly(x + 1, l, y, f);
        } else {
            res = find_first_knowingly(z, y + 1, r, f);
        }
        pull(x, z);
        return res;
    }
    
    int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
        if (ll <= l && r <= rr) {
            if (!f(tree[x])) {
                return -1;
            }
            return find_first_knowingly(x, l, r, f);
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res = -1;
        if (ll <= y) {
            res = find_first(x + 1, l, y, ll, rr, f);
        }
        if (rr > y && res == -1) {
            res = find_first(z, y + 1, r, ll, rr, f);
        }
        pull(x, z);
        return res;
    }
    
    int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
        if (l == r) {
            return l;
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res;
        if (f(tree[z])) {
            res = find_last_knowingly(z, y + 1, r, f);
        } else {
            res = find_last_knowingly(x + 1, l, y, f);
        }
        pull(x, z);
        return res;
    }
    
    int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
        if (ll <= l && r <= rr) {
            if (!f(tree[x])) {
                return -1;
            }
            return find_last_knowingly(x, l, r, f);
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res = -1;
        if (rr > y) {
            res = find_last(z, y + 1, r, ll, rr, f);
        }
        if (ll <= y && res == -1) {
            res = find_last(x + 1, l, y, ll, rr, f);
        }
        pull(x, z);
        return res;
    }
    
    id0(int _n) : n(_n) {
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1);
    }
    
    template <typename M>
    id0(const vector<M> &v) {
        n = v.size();
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1, v);
    }
    
    node get(int ll, int rr) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return get(0, 0, n - 1, ll, rr);
    }
    
    node get(int p) {
        assert(0 <= p && p <= n - 1);
        return get(0, 0, n - 1, p, p);
    }
    
    template <typename... M>
    void modify(int ll, int rr, const M&... v) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        modify(0, 0, n - 1, ll, rr, v...);
    }
    
    

    

    
    int find_first(int ll, int rr, const function<bool(const node&)> &f) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return find_first(0, 0, n - 1, ll, rr, f);
    }
    
    int find_last(int ll, int rr, const function<bool(const node&)> &f) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return find_last(0, 0, n - 1, ll, rr, f);
    }
};

void init_code(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}

int LIS(VL v) {
    int n = v.size();
    VI dp(n);
    dp[0] = 1;
    int ans = 0;
    ff (i, 1, n) {
        int cnt = 1;
        FF (j, i - 1, 0) {
            if (v[i] > v[j]) {
                cnt = max(cnt, dp[j] + 1);
            }
        }
        dp[i] = cnt;
    }
    ff (i, 0, n) {
        ans = max(ans, dp[i]);
    }
    return ans;
}


void solved(void)
{
    int n;
    cin >> n;
    vector<vector<string>> s(n, vector<string>(n));
    ff (i, 0, n) {
        ff (j, i + 1, n) {
            cin >> s[i][j];
            s[j][i] = s[i][j];
        }
    }
    bool f = false;
    

    

    ff (i, 1, n) {
        VPII q;
        VI used(n, 0);
        q.pb(mk(0, i));
        q.pb(mk(i, 0));
        used[0] = used[i] = 1;
        ff (j, 0, sz(q)) {
            ff (k, 0, n) {
                if (used[k]) continue;
                if (s[q[j].fi][k][q[j].se] == '1') {
                    used[k] = 1;
                    q.eb(q[j].se, k);
                }
            }
        }
        if (sz(q) != n) {
            continue;
        }
        VVI g(n, VI(n, n + 5));
        ff (j, 0, sz(q)) {
            g[q[j].fi][q[j].se] = 1;
            g[q[j].se][q[j].fi] = 1;
        }
        ff (j, 0, n) {
            g[j][j] = 0;
        }
        ff (l, 0, n) {
            ff (j, 0, n) {
                ff (k, 0, n) {
                    g[j][k] = min(g[j][k], g[j][l] + g[l][k]);
                }
            }
        }
        bool fail = false;
        ff (j, 0, n) {
            ff (k, j + 1, n) {
                ff (l, 0, n) {
                    if ((s[j][k][l] == '1') != (g[j][l] == g[k][l])) {
                        fail = true;
                    }
                }
            }
        }
        if (!fail) {
            cout << "Yes" << endl;
            q.erase(q.begin());
            ff (j, 0, sz(q)) {
                cout << q[j].fi + 1 << " " << q[j].se + 1 << endl;
            }
            f = true;
            break;
        }
    }
    if (!f) {
        cout << "No" << endl;
    }
    return;
}

signed main()
{
    init_code();
	ll t = 1;
    cin >> t;
	while(t--){
        solved();
	}
}
