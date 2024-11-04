



#include <climits>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <list>
#include <tuple>
#include <ctime>
#include <cassert>
using namespace std;




typedef long long ll;
typedef vector<ll> VI;
typedef long double DOUBLE;
typedef vector<DOUBLE> VD;
typedef vector<VD> VVD;




const DOUBLE EPS=1e-9;
const DOUBLE PI = atan(1) * 4;
const ll M = 1000000007;




struct PT {
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator + (const PT &p)  const { return PT(x + p.x, y + p.y); }
    PT operator - (const PT &p)  const { return PT(x - p.x, y - p.y); }
    PT operator * (double c)     const { return PT(x*c, y*c); }
    PT operator / (double c)     const { return PT(x / c, y / c); }
};
double dot(PT p, PT q) { return p.x*q.x + p.y*q.y; }
double dist2(PT p, PT q) { return dot(p - q, p - q); }
double cross(PT p, PT q) { return p.x*q.y - p.y*q.x; }
double cos_u2v(const PT& u, const PT& v) { return dot(u, v) / sqrt(dot(u,u)*dot(v,v)); }
double sin_u2v(const PT& u, const PT& v) { return cross(u, v) / sqrt(dot(u, u)*dot(v, v)); }
ostream &operator<<(ostream &os, const PT &p) {
    os << "(" << p.x << "," << p.y << ")";
}
double vector2angle(const PT &v) {return atan2(v.y, v.x);}




struct UnionFind {
    vector<ll> C;
    UnionFind(ll n) : C(n) {
        for (int i=0;i<n;i++) C[i]=i;
    }
    ll find(ll x) {
        return (C[x] == x) ? x : C[x] = find(C[x]);
    }
    void merge(ll x, ll y) {
        C[find(x)] = find(y);
    }
};




ll mod(ll x, ll m) { return ((x%m) + m) % m; }
ll gcd(ll a, ll b) { for (;b>0;swap(a, b))a %= b;return a; }
ll extended_euclid(ll a, ll b, ll &x, ll &y) {
    ll xx = y = 0;
    ll yy = x = 1;
    while (b) {
        ll q = a / b;
        ll t = b; b = a%b; a = t;
        t = xx; xx = x - q*xx; x = t;
        t = yy; yy = y - q*yy; y = t;
    }
    return a;
}
ll mod_inverse(ll a, ll n) {
    ll x, y;
    ll d = extended_euclid(a, n, x, y);
    if (d > 1) return -1;
    return mod(x, n);
}



struct LPSolver {
    int m, n;
    VI B, N;
    VVD D;
    LPSolver(const VVD &A, const VD &b, const VD &c) :
        m(b.size()), n(c.size()), N(n + 1), B(m), D(m + 2, VD(n + 2)) {
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) D[i][j] = A[i][j];
        for (int i = 0; i < m; i++) { B[i] = n + i; D[i][n] = -1; D[i][n + 1] = b[i]; }
        for (int j = 0; j < n; j++) { N[j] = j; D[m][j] = -c[j]; }
        N[n] = -1; D[m + 1][n] = 1;
    }
    void Pivot(int r, int s) {
        for (int i = 0; i < m + 2; i++) if (i != r)
            for (int j = 0; j < n + 2; j++) if (j != s)
                D[i][j] -= D[r][j] * D[i][s] / D[r][s];
        for (int j = 0; j < n + 2; j++) if (j != s) D[r][j] /= D[r][s];
        for (int i = 0; i < m + 2; i++) if (i != r) D[i][s] /= -D[r][s];
        D[r][s] = 1.0 / D[r][s];
        swap(B[r], N[s]);
    }
    bool Simplex(int phase) {
        int x = phase == 1 ? m + 1 : m;
        while (true) {
            int s = -1;
            for (int j = 0; j <= n; j++) {
                if (phase == 2 && N[j] == -1) continue;
                if (s == -1 || D[x][j] < D[x][s] || D[x][j] == D[x][s] && N[j] < N[s]) s = j;
            }
            if (D[x][s] > -EPS) return true;
            int r = -1;
            for (int i = 0; i < m; i++) {
                if (D[i][s] < EPS) continue;
                if (r == -1 || D[i][n + 1] / D[i][s] < D[r][n + 1] / D[r][s] ||
                    (D[i][n + 1] / D[i][s]) == (D[r][n + 1] / D[r][s]) && B[i] < B[r]) r = i;
            }
            if (r == -1) return false;
            Pivot(r, s);
        }
    }
    DOUBLE solve(VD &x) {
        int r = 0;
        for (int i = 1; i < m; i++) if (D[i][n + 1] < D[r][n + 1]) r = i;
        if (D[r][n + 1] < -EPS) {
            Pivot(r, n);
            if (!Simplex(1) || D[m + 1][n + 1] < -EPS) return -numeric_limits<DOUBLE>::infinity();
            for (int i = 0; i < m; i++) if (B[i] == -1) {
                int s = -1;
                for (int j = 0; j <= n; j++)
                    if (s == -1 || D[i][j] < D[i][s] || D[i][j] == D[i][s] && N[j] < N[s]) s = j;
                Pivot(i, s);
            }
        }
        if (!Simplex(2)) return numeric_limits<DOUBLE>::infinity();
        x = VD(n);
        for (int i = 0; i < m; i++) if (B[i] < n) x[B[i]] = D[i][n + 1];
        return D[m][n + 1];
    }
};



void edgelist2adjlists(ll n,
    const vector<ll> &froms, const vector<ll> &tos,
    vector<ll> &v2e0, vector<ll> &e2n)
{
    v2e0.resize(n);
    v2e0.assign(n, -1);
    ll en = froms.size();
    e2n.resize(en);
    for (int i = 0;i < en;i++) {
        ll f = froms[i];
        ll t = tos[i];
        e2n[i] = v2e0[f];
        v2e0[f] = i;
    }
}



struct FordFulk {
    const vector<ll> &v2e0;
    const vector<ll> &e2f;
    const vector<ll> &e2t;
    const vector<ll> &e2c;
    const vector<ll> &e2n;
    ll s,t;
    FordFulk(const vector<ll> &_v2e0,
        const vector<ll> &_e2f,
        const vector<ll> &_e2t,
        const vector<ll> &_e2c,
        const vector<ll> &_e2n,
        ll _s, ll _t)
        :  s(_s),t(_t),v2e0(_v2e0),e2f(_e2f),e2t(_e2t),e2c(_e2c),e2n(_e2n)
    {}
    ll _find_aug_path(const vector<ll> &v2e0,
        const vector<ll> &e2f,
        const vector<ll> &e2t,
        const vector<ll> &e2c,
        const vector<ll> &e2n,
        ll s, ll t, vector<ll> &epath)
    {
        vector<ll> q2v;
        vector<ll> q2p;
        vector<ll> q2e;
        vector<ll> q2f;
        vector<bool> inq(v2e0.size(), false);
        

        q2v.push_back(s);
        q2p.push_back(-1);
        q2e.push_back(-1);
        q2f.push_back(INT_MAX);
        inq[s] = true;
        for (ll i = 0;i<q2v.size();i++) {
            ll crt = q2v[i];
            ll f = q2f[i];
            for (ll j = v2e0[crt];j != -1;j = e2n[j]) {
                ll to = e2t[j];
                ll rem = e2c[j];
                if (inq[to]) continue;
                if (rem <= 0) continue;
                q2v.push_back(to);
                q2p.push_back(i);
                q2e.push_back(j);
                q2f.push_back(min(f, rem));
                inq[to] = true;
            }
        }
        

        for (ll i = 0;i<q2v.size();i++) {
            if (q2v[i] != t) continue;
            stack<ll> stk;
            for (ll j = i;j>0;j = q2p[j]) {
                stk.push(q2e[j]);
            }
            while (!stk.empty()) {
                epath.push_back(stk.top());
                stk.pop();
            }
            return q2f[i];
        }
        return 0;
    }

    ll eval(){
        

        ll en = e2f.size();
        map<pair<ll, ll>, ll> rsd;
        for (ll i = 0;i<en;i++) {
            ll f = e2f[i];
            ll t = e2t[i];
            rsd[make_pair(f, t)] += e2c[i];
            rsd[make_pair(t, f)] += 0;
        }
        map<pair<ll, ll>, ll> nei;
        ll ren = 0;
        for (auto er : rsd) {
            nei[er.first] = ren++;
        }
        ll rvn = v2e0.size();
        vector<ll> rv2e0(rvn, -1);
        vector<ll> re2f(ren);

        vector<ll> re2t(ren);

        vector<ll> re2c(ren);

        vector<ll> re2n(ren);

        vector<ll> re2p(ren);

        ll rei = 0;
        for (auto er : rsd) {
            ll f = er.first.first;
            ll t = er.first.second;
            ll c = er.second;
            re2f[rei] = f;
            re2t[rei] = t;
            re2c[rei] = c;
            re2p[rei] = nei[make_pair(t, f)];
            re2n[rei] = rv2e0[f];
            rv2e0[f] = rei;
            ++rei;
        }

        

        ll sol = 0;
        vector<ll> epath;
        while (true) {
            epath.clear();
            ll res = _find_aug_path(rv2e0, re2f, re2t, re2c, re2n, s, t, epath);
            if (res == 0) break;
            for (auto ei : epath) {
                re2c[ei] -= res;
                re2c[re2p[ei]] += res;
            }
            sol += res;
        }
        return sol;
    }
};



template <typename T>
struct LazySegTree1D {
    vector<T> v;
    vector<ll> opr;

    vector<T> opd;
    vector<ll> nxt;
    ll LEFT;
    ll RGHT;
    T (*fnx)(ll,T);
    T (*fab)(T,T);
    LazySegTree1D(ll _l, ll _r, T _v, T (*_fnx)(ll,T), T (*_fab)(T,T))
        :v(1),opr(1),opd(1),nxt(1),LEFT(_l),RGHT(_r),fnx(_fnx),fab(_fab)
    {
        v[0]=fnx(RGHT-LEFT+1,_v);
        opr[0]=0;
        opd[0]=_v;
        nxt[0]=-1;
    }
    void _split(ll i, ll l0, ll r0){
        assert(nxt[i]==-1);
        assert(opr[i]==0);
        assert(l0<r0);
        ll n=v.size();
        nxt[i]=n;
        ll m0=(l0+r0)/2;
        v.push_back(fnx(m0-l0+1,opd[i]));
        v.push_back(fnx(r0-m0,opd[i]));
        opr.push_back(0);
        opr.push_back(0);
        opd.push_back(opd[i]);
        opd.push_back(opd[i]);
        nxt.push_back(-1);
        nxt.push_back(-1);
    }
    void _pushdown(ll i, ll l0, ll r0){
        if (opr[i]==-1) return;
        ll m0=(l0+r0)/2;
        if (nxt[i]==-1)
            _split(i,l0,r0);
        else if (opr[i]>=0){
            _set(nxt[i],l0,m0,l0,m0,opr[i],opd[i]);
            _set(nxt[i]+1,m0+1,r0,m0+1,r0,opr[i],opd[i]);
        }
        opr[i]=-1;
    }
    void _set(ll i, ll l0, ll r0, ll l1, ll r1, ll o1, T v1){
        assert(l1>=l0&&r1<=r0);
        if (l0==l1&&r0==r1){
            if (o1==0){
                v[i]=fnx(r0-l0+1,v1);
                opr[i]=0;opd[i]=v1;
            }else if (o1==1){
                v[i]=fab(v[i],fnx(r0-l0+1,v1));
                if (opr[i]==-1){
                    opr[i]=1;opd[i]=v1;
                }else if (opr[i]==0){
                    opr[i]=0;opd[i]=fab(opd[i],v1);
                }else if (opr[i]==1){
                    opr[i]=1;opd[i]=fab(opd[i],v1);
                }
            }
            return;
        }
        ll m0=(l0+r0)/2;
        _pushdown(i,l0,r0);
        if (l1<=m0) _set(nxt[i],l0,m0,l1,min(r1,m0),o1,v1);
        if (r1>m0) _set(nxt[i]+1,m0+1,r0,max(l1,m0+1),r1,o1,v1);
        v[i]=fab(v[nxt[i]],v[nxt[i]+1]);
    }
    T _get(ll i, ll l0, ll r0, ll l1, ll r1){
        assert(l0<=l1&&r1<=r0);
        if (l0==l1&&r1==r0) return v[i];
        _pushdown(i,l0,r0);
        ll m0=(l0+r0)/2;
        if (r1<=m0) return _get(nxt[i],l0,m0,l1,r1);
        if (m0+1<=l1) return _get(nxt[i]+1,m0+1,r0,l1,r1);
        T lv=_get(nxt[i],l0,m0,l1,m0);
        T rv=_get(nxt[i]+1,m0+1,r0,m0+1,r1);
        return fab(lv,rv);
    }
    void updres(ll l1, ll r1, T v1){_set(0,LEFT,RGHT,l1,r1,1,v1);}
    void setval(ll l1, ll r1, T v1){_set(0,LEFT,RGHT,l1,r1,0,v1);}
    T get(ll l1, ll r1){return _get(0,LEFT,RGHT,l1,r1);}
};


int main()
{
    srand(time(NULL));
    ll n,m;cin>>n>>m;
    vector<ll> a(n);
    vector<ll> b(n-1);
    vector<ll> l(n-1);
    vector<ll> r(n-1);
    for (ll i=0;i<n;i++){
        cin>>a[i];
        if (i>0) {b[i-1]=abs(a[i]-a[i-1]);}
    }
    stack<ll> s1;
    stack<ll> s2;
    for (ll i=0;i<n-1;i++){
        while (!s1.empty()&&b[i]>b[s1.top()]){
            l[i]+=1+l[s1.top()];
            s1.pop();
        }
        s1.push(i);
    }
    for (ll i=n-2;i>=0;i--){
        while (!s2.empty()&&b[i]>=b[s2.top()]){
            r[i]+=1+r[s2.top()];
            s2.pop();
        }
        s2.push(i);
    }
    for (ll i=0;i<m;i++){
        ll x,y;cin>>x>>y;
        x--;y--;
        ll sol=0;
        for (ll j=x;j<y;j++){
            sol+=b[j]*(min(l[j],j-x)+1)*(min(r[j]+1,y-j));
        }
        cout<<sol<<endl;
    }
    
    return 0;
}
