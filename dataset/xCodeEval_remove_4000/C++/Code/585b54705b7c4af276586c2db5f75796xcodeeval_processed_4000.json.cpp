






using namespace std;
using namespace __gnu_pbds;
using ull = unsigned long long int;
















void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

struct yo
{
    ll x, y, w;
    bool operator <(const yo &t) const
    {
        return w < t.w;
    }
}edge[400005];

ll block_size = 0;
struct mo{
    ll l, r, idx;
    bool operator < (const mo& other) const{
        return mp(l / block_size, r) < mp(other.l / block_size, other.r);
    }
}qu[200005];

template <typename D>
void put(vector<D> aa,int st, int ed)
{
    for (int i = st; i < ed-1; i++)
    {
        cout << aa[i] << " ";
    }
    cout << aa[ed-1] << endl;
}


ll bg(ll x, ll y)
{ 

    if (y == 1)
        return x % mod;
    else if (y % 2 == 0)
    {
        ll tmp = bg(x, y / 2);
        return ((tmp % mod) * tmp) % mod;
    }
    else
        return (bg(x, y - 1) * x) % mod;
}

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Multi_Set;







template <typename T = int>
class bit
{
private:
    vector<T> a;

public:
    bit(int n) { a.resize(n + 1); }

    void add(int i, T x)
    {
        for (; i < a.size(); i += i & -i)
            a[i] += x;
    }

    T sum(int i)
    {
        T ans = 0;
        for (; i > 0; i -= i & -i)
            ans += a[i];
        return ans;
    }

    void clear() { a.assign(a.size(), 0); }
};



vl fac, inv, numinv; 


inline ll ncr(int n, int r)
{
    if (n < 0 || r < 0 || r > n)
        return 0;
    return fac[n] * inv[r] % mod * inv[n - r] % mod;
}
inline void id1(int n)
{
    fac.reserve(n + 1);
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
    numinv.reserve(n + 1);
    numinv[0] = numinv[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        numinv[i] = numinv[mod % i] * (mod - mod / i) % mod;
    }
    inv.reserve(n + 1);
    inv[0] = inv[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        inv[i] = numinv[i] * inv[i - 1] % mod;
    }
    return;
}



















int bt(ll x){
    return (((long long)(1))<<x);
}

ll t, n, m, k, ans, l, r, mi, tot, cnt, q, c, S, T, U, V;
string ss1, ss2;
vector<int> ee[500005];
vector<pair<ll, ll> > ee2[300005], ee3[300005];
int cycle = 0;

ull base = 9973; 

ull M = 1e9 + 9;

vector<ull> base_pow, pref;


void gen_hash(string& s){
    base_pow.resize(s.size() + 5);
    pref.resize(s.size() + 5);
    base_pow[0] = 1;
    pref[0] = 0;
    for (int i=0;i<s.size();i++){
        ll cur = ((pref[i] * base) % M + s[i]) % M;
        pref[i+1] = cur;
        base_pow[i+1] = (base_pow[i] * base) % M;
    }
}


ull get_hash(int start, int end){
    ull pre = (base_pow[end - start + 1] * pref[start]) % M;
    ull tmp = ((pref[end + 1] + M) - pre) % M;
    return tmp;
}

vector<ll> cc(200005), lucky;
struct id2 {
    int l, r, mid;
    ll val = 0, inc = 0, setall = 0;
    bool id3 = false;
    ll mn = kk, mncount = 0, left;
    ll id;
 
    id2 *lc, *rc;
    id2(int L, int R) {
        l = L;
        r = R;
        mid = (l + r) / 2;
        if (l != r) {
            lc = new id2(l, mid);
            rc = new id2(mid + 1, r);
            check_mn(lc, rc);
        }else{
            for (int i=0;i<lucky.size();i++){
                if (lucky[i] >= cc[L]){
                    mn = lucky[i] - cc[L];
                    id = i;
                    break;
                }
            }
            mncount = 1;
            left = L;
        }
    }

    void check_mn(id2 *lch, id2 *rch){
        if (lch->mn == rch->mn){
            mn = lch->mn;
            mncount = lch->mncount + rch->mncount;
            left = lch->left;
        }else if (lch->mn < rch->mn){
            mn = lch->mn;
            mncount = lch->mncount;
            left = lch->left;
        }else{
            mn = rch->mn;
            mncount = rch->mncount;    
            left = rch->left;            
        }
    }
 
    void inc_update(int L, int R, ll X) {
        apply();
        if (l == L && r == R) {
            

            inc += X;
            return;
        }
        else if (R <= mid) lc->inc_update(L, R, X);
        else if (L >= mid + 1) rc->inc_update(L, R, X);
        else {
            lc->inc_update(L, mid, X);
            rc->inc_update(mid + 1, R, X);
        }
        lc->apply();
        rc->apply();
        check_mn(lc, rc);
        

        

        
    }
 
    void set_update(int L, int R, ll X) {
        apply();
        if (l == L && r == R) {
            id3 = true;
            setall = mn;
            do{
                id++;
                setall += lucky[id] - lucky[id-1];
            }while (setall < 0);
            inc = 0;
            return;
        }
        else if (R <= mid) lc->set_update(L, R, X);
        else if (L >= mid + 1) rc->set_update(L, R, X);
        else {
            lc->set_update(L, mid, X);
            rc->set_update(mid + 1, R, X);
        }
        

        lc->apply();
        rc->apply();
        check_mn(lc, rc);
        

    }
 
    pair<ll, ll> query_1(int L, int R) {
        apply();
        if (l == L && r == R) return {mn, mncount};
        else if (R <= mid) return lc->query_1(L, R);
        else if (L >= mid + 1) return rc->query_1(L, R);
        else {

            pair<ll, ll> tmp1 = lc->query_1(L, mid);
            pair<ll, ll> tmp2 = rc->query_1(mid + 1, R);

            if (tmp1.x == tmp2.x) return {tmp1.x, tmp1.y + tmp2.y};
            else if (tmp1.x < tmp2.x) return tmp1;
            else return tmp2;
            

        }
    }

    pair<ll, ll> query_lt(int L, int R) {
        apply();
        if (l == L && r == R) return {mn, left};
        else if (R <= mid) return lc->query_lt(L, R);
        else if (L >= mid + 1) return rc->query_lt(L, R);
        else {

            pair<ll, ll> tmp1 = lc->query_lt(L, mid);
            pair<ll, ll> tmp2 = rc->query_lt(mid + 1, R);
            error(tmp1.x, tmp1.y, tmp2.x, tmp2.y)
            if (tmp1 <= tmp2) return tmp1;
            else return tmp2;
            

        }
    }
    
    void apply(){ 

        if (id3){
            mn = setall;
            mncount = (r-l+1);
        }
        mn += inc;
 
        if (l != r){
            compose(lc);
            compose(rc);
        }
 
        reset();
    }
 
    void compose(id2* child){
        if (id3){
            child->id3 = id3;
            child->setall = setall;
            child->inc = inc;
        }else child->inc += inc;
    }
 
    void reset(){
        inc = 0;
        setall = 0;
        id3 = false;
    }
    

} *segroot, *segrootlt, *segrootrt;


















































































vector<pair<ll, ll>> quy[200005];




vector<int> prime;
bool is_composite[200005];
int mu[200005];

void id0(int n){
    mu[1] = 1;
    for (int i=2;i<=n;i++){
        if (!is_composite[i]){
            prime.pb(i);
            mu[i] = -1;
        }
        for (auto p: prime){
            if (i * p > n) break;
            is_composite[i * p] = true;
            if (i % p == 0){
                mu[i * p] = 0; 

                break;
            }else mu[i * p] = mu[i] * mu[p]; 

        }
    }
}

pair<ll, ll> pp[200005];
ll F(ll xx){
    ll ans = 0;
    vector<vector<ll>> dp(n+5, vector<ll>(m/xx+5));
    dp[0][0] = 1;

    for (int i=0;i<n;i++){
        ll x = (pp[i].x-1) / xx + 1;
        ll y = pp[i].y / xx;
        

        if (x > y) return 0;
        for (int j=x;j<=m/xx;j++){
            ll lb = max(0LL, j-y);
            ll rb = j-x;
            dp[i+1][j] = (dp[i+1][j] + dp[i][rb]) % 998244353;
            if (lb != 0) dp[i+1][j] = (dp[i+1][j] - dp[i][lb-1] + 998244353) % 998244353;
        }
        for (int j=1;j<=m/xx;j++) dp[i+1][j] = (dp[i+1][j] + dp[i+1][j-1]) % 998244353;
    }
    
    for (int i=0;i<=m/xx;i++){
        ans = (ans + dp[n][i]) % 998244353;
    }

    

    return ans;
}

pair<ll, ll> lis[200005];
ll count1[200005], count2[200005];
int gp1[200005], gp2[200005];

ll dp[300005][2];

string ss;

void solve(){
    

    

    

    cin >> n >> m;
    
    id0(m);
    

    


    for (int i=0;i<n;i++){
        ll x, y;
        cin >> x >> y;
        pp[i] = {x, y};
    }

    ll ans = 0;
    for (int i=1;i<=m;i++){
        ans = (ans + mu[i] * F(i) + 998244353) % 998244353;
    }

    cout << ans << endl;


    

    

    
    

    



    


    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    


    

    

    

    

    



    

    

    

    


    

    return;
    

    

    

    

    
    

    

    

    

}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    t = 1;
    

    while (t--){
        solve();
    }
}
