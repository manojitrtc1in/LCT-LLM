#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define en '\n'
#define sp ' '
#define tb '\t'
#define ri(n) int n; cin >> n
#define rl(n) ll n; cin >> n
#define rs(s) string s; cin >> s
#define rc(c) char c; cin >> c
#define rv(v) for (auto &x : v) cin >> x
#define pven(v) for (auto x : v) cout << x << en
#define pv(v) for (auto x : v) cout << x << sp; cout << en
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define yes cout << "YES" << en
#define no cout << "NO" << en
#define smin(a, b) a = min(a, b)
#define smax(a, b) a = max(a, b)
#define ssort(a, b) if (a < b) swap(a, b)
#define bitcnt(a) (__builtin_popcountll(a))
#define bithigh(a) (63-__builtin_clzll(a))
#define lg bithigh
#define highpow(a) (1LL << (ll)lg(a))

using namespace std;

namespace NumberTheory{
    vector<int> sito, primes;
    bool _precomputed_sito_ = 0;
    ll gcd(ll a, ll b, ll* x = nullptr, ll* y = nullptr){
        if (!b){
            if (x){ *x = 1; *y = 0; }
            return a;
        }
        ll x1, y1;
        ll g = gcd(b, a%b, &x1, &y1);
        if (x){ *x = y1; *y = x1 - (a/b) * y1; }
        return g;
    }
    ll lcm(ll a, ll b){ return a*b/gcd(a, b); }
    bool Diof(ll a, ll b, ll c, ll* x0, ll* y0, ll* u, ll* v){
        ll g = gcd(a, b, x0, y0);
        if (c%g != 0) return 0;
        *u = a/g; *v = b/g;
        *x0 *= c/g; *y0 *= c/g;
        return 1;
    }
    array<ll, 2> Crt(const vector<array<ll, 2> >& v){
        queue<array<ll, 2> > q;
        ll nzd = 0;
        for (auto x : v){
            x[0] %= x[1]; if (x[0]<0) x[0] += x[1];
            nzd = gcd(nzd, x[1]);
            q.push(x);
        }
        if (nzd^1) return {-1, -1};
        while (1){
            auto s1 = q.front(); q.pop();
            auto s2 = q.front(); q.pop();
            if (s2[0]-s1[0] < 0) swap(s1, s2);
            ll x, y;
            gcd(s1[1], s2[1], &x, &y);
            ll m = s1[1]*s2[1];
            x %= s2[1]; if (x<0) x += s2[1];
            ll c = (x * (s2[0] - s1[0])) % m;
            array<ll, 2> s3 = {(c * s1[1] + s1[0]) % m, m};
            if (q.empty()) return s3;
            q.push(s3);
        }
    }
    void PrecomputeSito(const int mx){
        _precomputed_sito_ = 1;
        sito = vector<int>(mx+10);
        for (int i = 2; i < mx; i++)
            sito[i] = i;
        for (ll i = 2; i < mx; i++)
            if (sito[i] == i)
                for (ll j = i*i; j < mx; j += i)
                    if (sito[j] == j)
                        sito[j] = i;
    }
    bool IsPrime(int x){
        if (_precomputed_sito_) return sito[x] == x;
        if (x <= 1) return 0;
        for (int i = 2; i*i <= x; i++)
            if (x % i == 0)
                return 0;
        return 1;
    }
    void GetPrimes(){
        if (!_precomputed_sito_){
            cerr << "Precompute sito u idiot." << endl;
            exit(1);
        }
        for (int i = 2; i < sito.size(); i++)
            if (sito[i]==i)
                primes.pb(i);
    }
    vector<int> Factor(int x){
        if (!_precomputed_sito_){
            cerr << "Precompute sito u idiot." << endl;
            exit(1);
        }
        vector<int> f;
        while (x^1){
            f.pb(sito[x]);
            x /= sito[x];
        }
        return f;
    }
    vector<int> GetDivs(ll x){
        vector<int> divs;
        for (int i = 2; i*i <= x; i++){
            if (x % i == 0){
                divs.pb(i);
                if (i*i < x) divs.pb(x / i);
            }
        }
        return divs;
    }
};
using namespace NumberTheory;

template <ll mod>
class mll{

    ll v;
    void norm(){ v %= mod; if(v<0) v += mod; }
    mll<mod> inv() const { return  *this ^ (mod-2); }
    mll<mod> pow(const ll& exp) const {
        if (!exp) return 1;
        mll<mod> t = pow(exp/2);
        if (exp%2) return t*t*v;
        return t*t;
    }
    static vector<mll<mod> > fact, ifact;

public:
    mll<mod>(ll val = 0){ v = val; norm(); }
    bool operator==(const mll<mod>& a) const { return v == a.v; }
    bool operator!=(const mll<mod>& a) const { return v != a.v; }
    bool operator<(const mll<mod>& a) const { return v < a.v; }
    bool operator<=(const mll<mod>& a) const { return v <= a.v; }
    bool operator>(const mll<mod>& a) const { return v > a.v; }
    bool operator>=(const mll<mod>& a) const { return v >= a.v; }

    mll<mod> operator+(const mll<mod>& a) const { return mll<mod>(v+a.v); }
    mll<mod> operator-(const mll<mod>& a) const { return mll<mod>(v-a.v); }
    mll<mod> operator*(const mll<mod>& a) const { return mll<mod>(v*a.v); }
    mll<mod> operator/(const mll<mod>& a) const { return *this * a.inv(); }
    mll<mod> operator=(const mll<mod>& a) { v = a.v; norm(); return *this; }
    mll<mod> operator+=(const mll<mod>& a) { v += a.v; norm(); return *this; }
    mll<mod> operator-=(const mll<mod>& a) { v -= a.v; norm(); return *this; }
    mll<mod> operator*=(const mll<mod>& a) { v *= a.v; norm(); return *this; }
    mll<mod> operator/=(const mll<mod>& a) { v /= a.v; norm(); return *this; }
    mll<mod> operator^(const ll& a) const { return pow(a); }
    mll<mod> operator^=(const ll& a) { v = pow(a).v; return *this; }
    mll<mod> operator++() { v++; return *this; }
    mll<mod> operator++(int) { mll<mod> temp = *this; v++; return temp; }
    mll<mod> operator--() { v--; return *this; }
    mll<mod> operator--(int) { mll<mod> temp = *this; v--; return temp; }

    friend istream& operator>>(istream& is, mll<mod>& a){ is >> a.v; return is; }
    friend ostream& operator<<(ostream& os, const mll<mod>& a){ os << a.v; return os; }

    static void init_fact(int mx){
        mll<mod>::fact.resize(mx+1);
        mll<mod>::ifact.resize(mx+1);
        mll<mod>::fact[0] = mll<mod>::fact[1] = 1;
        mll<mod>::ifact[0] = mll<mod>::ifact[1] = 1;
        for (int i = 2; i <= mx; i++) mll<mod>::fact[i] = mll<mod>::fact[i-1] * i;
        mll<mod>::ifact[mx] = mll<mod>::fact[mx].inv();
        for (int i = mx-1; i > 1; i--) mll<mod>::ifact[i] = mll<mod>::ifact[i+1] * (i+1);
    }
    static mll<mod> nck(const mll<mod>& n, const mll<mod>& k){ if (k>n) return 0; return mll<mod>::fact[n.v] * mll<mod>::ifact[k.v] * mll<mod>::ifact[(n-k).v]; }
    static mll<mod> Fact(const mll<mod>& f){ if (f < 0) return LONG_MIN; return mll<mod>::fact[f.v]; }
};
#define mod mll<998244353>
template<> vector<mod> mod::fact = vector<mod>();
template<> vector<mod> mod::ifact = vector<mod>();

class Tree{

private:
    int n, root;
    vector<int> depth, in, out;
    vector<vector<int> > g, par;
    int _edges_ = 0;
    bool _initialized_ = 0;

    bool Valid(int s) const { return s >= 0 && s < n; }

    int InitDfs(int s, int p = -1, int d = 0, int t = 0){
        par[s][0] = p;
        depth[s] = d;
        in[s] = t;
        for (int u : g[s])
            if (u^p)
                t = InitDfs(u, s, d+1, t+1);
        return out[s] = ++t;
    }

    void Dfs(int s, int p, void bf(int, int), void af(int, int)) const {
        bf(s, p);
        for (int u : g[s])
            if (u^p)
                Dfs(u, s, bf, af);
        af(s, p);
    }

public:
    Tree(int s = 0){
        n = s;
        depth.assign(s, 0);
        in.assign(s, 0);
        out.assign(s, 0);
        g.assign(s, vector<int>());
        par.assign(s, vector<int>(lg(s)+1, -1));
    }

    void Edge(int u, int v){
        if (!Valid(u) || !Valid(v)){
            cerr << "Node index out of range" << endl;
            exit(1);
        }
        g[u].pb(v);
        g[v].pb(u);
        _edges_++;
    }

    void Read(){
        for (int i = 0; i < n-1; i++){
            ri(u); ri(v);
            u--; v--;
            Edge(u, v);
        }
    }

    void Initialize(int s = 0){
        if (!Valid(s)){
            cerr << "Node index out of range" << endl;
            exit(1);
        }
        if (_edges_ < n-1){
            cerr << "Tree is not connected" << endl;
            exit(1);
        }
        if (_edges_ > n-1){
            cerr << "Tree has cycle(s)" << endl;
            exit(1);
        }
        root = s;
        InitDfs(s);
        for (int d = 1; d <= lg(n); d++)
            for (int i = 0; i < n; i++)
                if (depth[i] >= (1<<d))
                    par[i][d] = par[par[i][d-1]][d-1];
        _initialized_ = 1;
    }

    int Depth(int s) const {
        if (!Valid(s)){
            cerr << "Node index out of range" << endl;
            exit(1);
        }
        return depth[s];
    }

    int InTime(int s) const {
        if (!Valid(s)){
            cerr << "Node index out of range" << endl;
            exit(1);
        }
        return in[s];
    }

    int OutTime(int s) const {
        if (!Valid(s)){
            cerr << "Node index out of range" << endl;
            exit(1);
        }
        return out[s];
    }

    vector<int> GetAdjecent(int s) const {
        if (!Valid(s)){
            cerr << "Node index out of range" << endl;
            exit(1);
        }
        return g[s];
    }

    vector<int> GetChilds(int s) const {
        if (!Valid(s)){
            cerr << "Node index out of range" << endl;
            exit(1);
        }
        vector<int> ch;
        for (int u : g[s])
            if (u^par[s][0])
                ch.pb(u);
        return ch;
    }

    int Par(int s, int d = 1) const {
        if (!_initialized_){
            cerr << "Tree has not been initialized yet" << endl;
            exit(1);
        }
        if (d < 0 || d > depth[s]) return -1;
        if (!d) return s;
        return Par(par[s][lg(d)], d - highpow(d));
    }

    bool Ancestor(int s, int p) const {
        if (!_initialized_){
            cerr << "Tree has not been initialized yet" << endl;
            exit(1);
        }
        return in[s] > in[p] && out[s] < out[p];
    }

    int Lca(int u, int v) const {
        if (!Valid(u) || !Valid(v)){
            cerr << "Node index out of range" << endl;
            exit(1);
        }
        if (!_initialized_){
            cerr << "Tree has not been initialized yet" << endl;
            exit(1);
        }
        if (depth[u] > depth[v]) swap(u, v);
        if (Ancestor(v, u)) return u;
        v = Par(v, depth[v] - depth[u]);
        for (int d = lg(n); ~d; d--){
            if (par[u][d] != par[v][d]){
                u = par[u][d];
                v = par[v][d];
            }
        }
        return par[u][0];
    }

    int Dist(int u, int v) const {
        if (!Valid(u) || !Valid(v)){
            cerr << "Node index out of range" << endl;
            exit(1);
        }
        if (!_initialized_){
            cerr << "Tree has not been initialized yet" << endl;
            exit(1);
        }
        int lca = Lca(u, v);
        return 2*depth[lca] - depth[u] - depth[v];
    }

    void Dfs(void bf(int, int), void af(int, int)) const { Dfs(root, -1, bf, af); }
};
#define Empty [](int, int){}

const ll LINF = 4e18;
const int mxN = 1e6+10, INF = 2e9;
ll n, m, a[mxN], sz[mxN];
vector<int> p[mxN], g[mxN];
Tree* tree;
mod ans;

void dfs(int s, int p, int tot, int q){

    sz[s] = (a[s] % q == 0);
    for (int u : g[s]){
        dfs(u, s, tot, q);
        sz[s] += sz[u];
    }
    if (~p) ans += (mod::nck(tot, 3) - mod::nck(sz[s], 3) - mod::nck(tot-sz[s], 3)) * (tree->Depth(s) - tree->Depth(p));
}

void Solve(){

    PrecomputeSito(mxN);
    GetPrimes();
    mod::init_fact(mxN);
    cin >> n;
    tree = new Tree(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        auto f = Factor(a[i]);
        f.erase(unique(all(f)), f.end());
        for (int q : f) p[q].pb(i);
    }
    tree->Read();
    tree->Initialize();
    for (int q : primes){
        if (p[q].size() < 3) continue;
        auto a = p[q];
        sort(all(a), [&](int u, int v){ return tree->InTime(u) < tree->InTime(v); });
        int tot = a.size();
        for (int i = a.size()-2; ~i; i--)
            a.pb(tree->Lca(a[i], a[i+1]));
        sort(all(a), [&](int u, int v){ return tree->InTime(u) < tree->InTime(v); });
        a.erase(unique(all(a)), a.end());
        stack<int> stk; stk.push(a[0]);
        for (int i = 1; i < a.size(); i++){
            while (!tree->Ancestor(a[i], stk.top())) stk.pop();
            g[stk.top()].pb(a[i]);
            stk.push(a[i]);
        }
        dfs(a[0], -1, tot, q);
        for (auto s : a) g[s].clear();
    }
    cout << ans << en;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); cerr.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;
    cerr << "Started!" << endl;

    int t = 1;
    

    while (t--)
        Solve();

    return 0;
}
