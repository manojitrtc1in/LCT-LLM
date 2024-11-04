



































typedef long long ll;
using namespace std;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vll;
ll exp(ll n, ll m, ll md){
        ll a = 1;
        while (m > 0){
                if (m&1) a = (a * n%md) % md;
                m /= 2;
                n = (n*n) % md;
        }
        return a % md;
}
void disp(vector<int> v){
        for(auto u:v)
                cout<<u<<" ";
        cout<<"\n";
}

bool id0(ll n, ll a, ll d, int s){
        ll x = exp(a, d, n);
        if (x == 1 || x == n-1) return false;
        for(int r = 1;r < s;++r){
                x = x * x%n;
                x %= n;
                if(x == n-1) return false;
        }
        return true;
}
bool prime(ll n){
        if(n < 4) return n == 2 || n == 3;
        if (!(n&1)) return false;
        int s = 0;
        ll d = n-1;
        while(!(d&1)){
                d >>= 1;
                s++;
        }
        for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
                if(n == a) return true;
                if(id0(n, a, d, s)) return false;
        }
        return true;
}

const int NPR = 10000000;
int lp[NPR + 1];
vector<int> pr;
void prfac(int n = NPR){
        if (n > NPR) return;
        int i, j;
        forn(i, n) lp[i] = 0;
        for (  i =2;i <= n;++i) {
                if (lp[i] == 0) {
                        lp[i] = i;
                        pr.push_back(i);
                }
                for ( j = 0; j < (int)pr.size() && pr[j] <= lp[i]; ++j) {
                        long long a = i * pr[j];
                        if(a <= n) lp[a] = pr[j];
                }
        }
}



vi loga;
vector<vi> pmin;
vector<vi> pmax;

void id6(int n){
        int i, j, k;
        pmin.clear();pmax.clear();
        pmin.resize(n, vi(25, 0));
        pmax.resize(n, vi(25, 0));

        for(i = 0;i < n;i++)  {
                

                

        }
        j = 1;
        while(n >= (1LL << (ll)j)){
                for(i = 0;i < n;i++)  {
                        if(i + (1LL << (ll)(j-1)) >= n){
                                pmin[i][j] = pmin[i][j-1];
                                pmax[i][j] = pmax[i][j-1];
                                continue;
                        }
                        pmin[i][j] = min(pmin[i][j-1], pmin[i + (1LL << (long long)(j-1))][j-1]);
                        pmax[i][j] = max(pmax[i][j-1], pmax[i + (1LL << (long long)(j-1))][j-1]);
                }
                j++;
        }

        i = 0;
        while(n >= (1LL << (long long)i)){
                loga.PB((1LL << (long long)i));
                i++;
        }
        loga.PB((1LL << (long long)i));
}
ll id3(int l, int r){
        if(l > r) return 0;

        int j = upper_bound(loga.begin(), loga.end(), r - l + 1) - loga.begin() - 1;
        return min(pmin[l][j], pmin[r - (1LL << (long long)j) + 1][j]);
}
ll id5(int l, int r){
        if(l > r) return 0;
        int j = upper_bound(loga.begin(), loga.end(), r - l + 1) - loga.begin() - 1;
        return max(pmax[l][j], pmax[r - (1LL << (long long)j) + 1][j]);
}


const int MAXN = 1000000;
int seg_t[4*MAXN];
void seg_build(int array[], int v, int tl, int tr){
        if (tl == tr) {
                seg_t[v] = array[tl];
        } else {
                int tm = (tl + tr) / 2;
                seg_build(array, v*2, tl, tm);
                seg_build(array, v*2+1, tm+1, tr);
                seg_t[v] = seg_t[v*2] + seg_t[v*2+1];
        }
}
int seg_sum(int v, int tl, int tr, int l, int r) {
        if (l > r)
                return 0;
        if (l == tl && r == tr) {
                return seg_t[v];
        }
        int tm = (tl + tr) / 2;
        return seg_sum(v*2, tl, tm, l, min(r, tm))
               + seg_sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}
int seg_max(int v, int tl, int tr, int l, int r) {
        if (l > r)
                return 0;
        if (l == tl && r == tr) {
                return seg_t[v];
        }
        int tm = (tl + tr) / 2;
        return max(seg_max(v*2, tl, tm, l, min(r, tm))
               ,seg_max(v*2+1, tm+1, tr, max(l, tm+1), r));
}
void seg_update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
                seg_t[v] = new_val;
        } else {
                int tm = (tl + tr) / 2;
                if (pos <= tm)
                        seg_update(v*2, tl, tm, pos, new_val);
                else
                        seg_update(v*2+1, tm+1, tr, pos, new_val);
                seg_t[v] = seg_t[v*2] + seg_t[v*2+1];
        }
}




using namespace std;
int pos[100005];
vector<int> v[100005],col[100005],s;
vector<int> cyc;
bool dfs(int node)
{
        pos[node]=s.size();
        col[pos[node]%2].push_back(node);
        s.push_back(node);
        int low=-1;
        for (int u:v[node])
        {
                if (pos[u]!=-1 && pos[node]-pos[u]>1)
                        low=max(low,pos[u]);
        }
        if (low!=-1)
        {
                for (int i=low;i<=pos[node];i++)
                        cyc.push_back(s[i]);
                return 1;
        }
        for (int u:v[node])
        {
                if (pos[u]==-1)
                {
                        if (dfs(u))
                                return 1;
                }
        }
        s.pop_back();
        return 0;
}



struct pt {
    ll x, y;
}aa;

bool cmp(pll a, pll b) {
        return a.F < b.F || (a.F == b.F && a.S < b.S);
}

pll add(pll a, pll b) {
        return {a.F + b.F, a.S + b.S};
}

pll sub(pll a, pll b) {
        return {a.F - b.F, a.S - b.S};
}

bool cw(pll a, pll b, pll c) {
        return a.F*(b.S-c.S)+b.F*(c.S-a.S)+c.F*(a.S-b.S) <= 0;
}
bool cw1(pll a, pll b, pll c) {
        return a.F*(b.S-c.S)+b.F*(c.S-a.S)+c.F*(a.S-b.S) < 0;
}

bool ccw(pll a, pll b, pll c) {
        return a.F*(b.S-c.S)+b.F*(c.S-a.S)+c.F*(a.S-b.S) > 0;
}
bool id4(pll a, pll b, pll c) {
        return a.F*(b.S-c.S)+b.F*(c.S-a.S)+c.F*(a.S-b.S) >= 0;
}
ll dot(pll a, pll b) {
       return a.F * b.F + a.S * b.S;
}

ll cross(pll a, pll b) {
        return a.F * b.S - a.S * b.F;
}

ll area(pll a, pll b, pll c) {
        return abs(a.F*(b.S-c.S)+b.F*(c.S-a.S)+c.F*(a.S-b.S));
}

ll areaSign(pll a, pll b, pll c){
        return (a.F*(b.S-c.S)+b.F*(c.S-a.S)+c.F*(a.S-b.S));
}

ll areaPoly(vector<pll> &a) {
        pll o = {0, 0};
        int n = a.size();
        if(n <= 2) return 0;
        int i;
        ll area = 0;
        forsn(i,1, n) {
                area += areaSign(o, a[i-1], a[i]);
        }
        return abs(area);
}

bool id1(pll a, pll b, pll c, pll d) {
        return area(a, b, c) == area(a, b, d) + area(a, c, d) + area(b, c, d);
}

bool id7(pll a, pll b, pll c) {
        

        if(a.F == b.F && b.F == c.F) return true;
        if(a.S == b.S && b.S == c.S) return true;
        return ((c.S - a.S) * (b.F - a.F) == (c.F - a.F) * (b.S - a.S)) ;
}

ll id8(vector<pll> &a, pll p, ll l, ll r) {
        if(l == r) {
                return l;
        }
        ll mid = (l + r) /2;
        if(id4(a[0], p, a[mid])) {
                if(cw1(a[0], p, a[mid + 1])){
                        return mid;
                }
                else {
                        return id8(a, p, mid + 1, r);
                }
        }
        else {
                return id8(a, p, l, mid - 1);
        }
}
bool inPoly(vector<pll>& a, pll p) {

        ll n = a.size();
        if(n <= 2) return false;
        ll one = cross(sub(a[1], a[0]), sub(p, a[0]));
        ll three = cross(sub(a[n-1], a[0]), sub(a[1], a[0]));
        ll two = cross(sub(a[n-1], a[0]), sub(p , a[0]));
        ll four = cross(sub(a[1], a[0]), sub(a[n-1] , a[0]));
        if(!(one == 0 || !((one > 0) ^ (four > 0))) || !(three == 0  || !((three > 0) ^ (two > 0))) ) {
                return false;
        }
        if(id7(a[0], a[1], p) || id7(a[0], a[n-1], p)){
                return false;
        }
        ll i = id8(a, p, 1, n-1);
        if(id1(a[0], a[i], a[i+1], p)) {
                if(id7(a[i], a[i+1], p)) {
                        return false;
                }
                if(i == 1) {
                        if(id7(a[0], a[1], p)) {
                                return false;
                        }
                }
                if(i == n-2) {
                        if(id7(a[n-2], a[n-1], p)) {
                                return false;
                        }
                }
                return true;
        }
        else {
                return false;
        }

}

vector<set<pll>> layers;
vector<vector<pll>> layers_v;
map<pll, int> m;
void id9(vector<pll>& a) {
        if (a.size() <= 2) {
                layers_v.PB(a);
                set<pll> b;
                b.insert(a.back());
                b.insert(a[0]);
                a.clear();
                layers.PB(b);
                return;
        }

        sort(a.begin(), a.end());
        pll p1 = a[0], p2 = a.back();
        vector<pll> up, down;
        up.push_back(p1);
        down.push_back(p1);
        for (ll i = 1; i < (ll)a.size(); i++) {
                if (i == a.size() - 1 || cw(p1, a[i], p2)) {
                        while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                                up.pop_back();
                        up.push_back(a[i]);
                }
                if (i == a.size() - 1 || id4(p1, a[i], p2)) {
                        while(down.size() >= 2 && !id4(down[down.size()-2], down[down.size()-1], a[i]))
                                down.pop_back();
                        down.push_back(a[i]);
                }
        }

        set<pll> b;
        vector<pll> c = a;
        a.clear();
        for (ll i = 0; i < (ll)up.size(); i++) {
                if(b.count(up[i]) == 0) {
                        b.insert(up[i]);
                        a.push_back(up[i]);
                }
                m[{up[i].F, up[i].S}] = layers.size();
        }
        for (ll i = down.size() - 2; i > 0; i--) {
                if(b.count(down[i]) == 0) {
                        a.push_back(down[i]);
                        b.insert(down[i]);
                }
                m[{down[i].F, down[i].S}] = layers.size();
        }
        layers.PB(b);
        layers_v.PB(a);
        a.clear();
        for(auto u : c){
                if(b.count(u)) continue;
                a.PB(u);
        }

}









const int N = 500043;
const int MOD = 998244353;

int fact[N];

int add(int x, int y)
{
        x += y;
        while(x >= MOD) x -= MOD;
        while(x < 0) x += MOD;
        return x;
}

int mul(int x, int y)
{
        return (x * 1ll * y) % MOD;
}

int binpow(int x, int y)
{
        int z = 1;
        while(y > 0)
        {
                if(y % 2 == 1)
                        z = mul(z, x);
                x = mul(x, x);
                y /= 2;
        }
        return z;
}

int inv(int x)
{
        return binpow(x, MOD - 2);
}

int divide(int x, int y)
{
        return mul(x, inv(y));
}

void precalc()
{
        fact[0] = 1;
        for(int i = 1; i < N; i++)
                fact[i] = mul(i, fact[i - 1]);
}

int C(int n, int k)
{
        if(n <= 0) return 0;
        if(k > n) return 0;
        return divide(fact[n], mul(fact[n - k], fact[k]));
}




struct LCA {
    vector<int > height, euler, first, segtree;
    vector<char> vis;
    int n;

    LCA(vector<vector<int>> &ad, int root = 0) {
            n = ad.size();
            height.resize(n);
            first.resize(n);
            euler.reserve(2*n);
            vis.assign(n, false);
            dfs(ad, root);
            int m = euler.size();
            segtree.resize(4*m);
            build(1, 0, m-1);
    }

    void dfs(vector<vector<int> > &ad, int node, int h = 0) {
            vis[node] = true;
            height[node] = h;
            first[node] = euler.size();
            euler.push_back(node);
            for(auto u: ad[node]) {
                    if(vis[node]) continue;
                    dfs(ad, node, h+1);
                    euler.push_back(node);
            }
    }

    void build(int node, int b, int e) {
            if(b == e) {
                    segtree[node] = euler[b];
            }
            else {
                    int mid = (b + e) / 2;
                    build(node << 1, b, mid);
                    build(node << 1 | 1, mid+1, e);
                    int l = segtree[node << 1], r = segtree[node << 1 | 1];
                    segtree[node] = (height[l] < height[r]) ? l : r;
            }
    }

    int que(int node, int b, int e, int L, int R) {
            if(b > R || e < L)
                    return -1;
            if(b >= L && e <= R)
                    return segtree[node];
            int mid = (b + e) >> 1;

            int left = que(node << 1, b, mid, L, R);
            int right = que(node<<1 | 1, mid+1, e, L, R);
            if(left == -1) return right;
            if(right == -1) return left;
            return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
            int left = first[u], right =  first[v];
            if(left > right)
                    swap(left, right);
            return que(1, 0, euler.size() - 1, left, right);
    }

    int dist(int u, int v) {
            return height[u] + height[v] - height[lca(u,v)];
    }
};









ll dp[2000001] = {0};

void go1() {
        int n;cin >> n;
        cout << dp[n] << ln;

}

int main(){
        fio;
        

        chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

        ll tt = 1;
        cin >> tt;
        cout<<fixed<<setprecision(10);
        dp[1] = 0;dp[2] = 0;
        int i;
        for(i = 3;i < 2000001;i++) dp[i] = (dp[i-1] + 2*dp[i-2] + 4*(i%3 == 0)) % (ll)(1e9 + 7);
        while(tt--){

                go1();
        }

        chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
        long double id2 = (chrono::duration_cast<chrono::duration<long double> >(end-start)).count();
        

        cerr<<id2<<'\n';
        return 0;
}
