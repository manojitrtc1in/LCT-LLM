



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
private:
    const vector<ll> &v2e0;
    const vector<ll> &e2f;
    const vector<ll> &e2t;
    const vector<ll> &e2c;
    const vector<ll> &e2n;
    ll s,t;

    ll find_aug_path(const vector<ll> &v2e0,
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

public:
    FordFulk(const vector<ll> &_v2e0,
        const vector<ll> &_e2f,
        const vector<ll> &_e2t,
        const vector<ll> &_e2c,
        const vector<ll> &_e2n,
        ll _s, ll _t)
        :  s(_s),t(_t),v2e0(_v2e0),e2f(_e2f),e2t(_e2t),e2c(_e2c),e2n(_e2n)
    {
    }

    ll eval()
    {
        

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
            ll res = find_aug_path(rv2e0, re2f, re2t, re2c, re2n, s, t, epath);
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

struct LazySegTree {
    ll l;
    ll r;
    int val;
    int to_push;
    LazySegTree* lchd;
    LazySegTree* rchd;
    LazySegTree(ll _l, ll _r, int _v):l(_l),r(_r),val(_v),to_push(_v),lchd(NULL),rchd(NULL){}
    void set(ll l1, ll r1, int v1){

        assert(l1>=l&&r1<=r);
        val=min(val,v1);
        if (l==l1&&r==r1){
            to_push=min(to_push,v1);
            return;
        }
        ll m=(l+r)/2;
        if (lchd==NULL){
            lchd=new LazySegTree(l,m,to_push);
            rchd=new LazySegTree(m+1,r,to_push);
        }
        lchd->set(l,m,to_push);
        rchd->set(m+1,r,to_push);
        if (l1<=m) lchd->set(l1,min(r1,m),v1);
        if (r1>m) rchd->set(max(l1,m+1),r1,v1);
    }
    int get(ll l1, ll r1){
        assert(l1>=l&&r1<=r);
        if (l==l1&&r==r1){
            return val;
        }
        if (lchd==NULL) return val;
        ll m=(l+r)/2;
        lchd->set(l,m,to_push);
        rchd->set(m+1,r,to_push);
        bool lgood=(l1<=m);
        ll lv=(lgood)?lchd->get(l1,min(r1,m)):0;
        bool rgood=(m+1<=r1);
        ll rv=(rgood)?rchd->get(max(m+1,l1),r1):0;
        return (!lgood)?rv:(!rgood)?lv:min(lv,rv);
    }
};

void readll(ll &x){int r;scanf("%d",&r);x=r;}

int main()
{
    ll n,m;readll(n);readll(m);
    vector<ll> x(n);
    vector<ll> t(n);
    vector<ll> kil(n);
    vector<pair<ll,ll>> xi(n);

    ll maxreach=0;
    ll fmax=0;
    ll mmax=0;
    for (ll i=0;i<n;i++){
        readll(x[i]);
        readll(t[i]);
        xi[i]=make_pair(x[i],i);
        fmax=max(fmax,x[i]+t[i]);
    }
    sort(xi.begin(),xi.end());

    vector<ll> p(m);
    vector<ll> b(m);
    for (ll i=0;i<m;i++){
        readll(p[i]);
        readll(b[i]);
        mmax=max(mmax,p[i]);
        fmax+=b[i];
    }

    LazySegTree tree(0,max(fmax,mmax),n);
    for (ll i=0;i<n;i++){
        ll fgi=xi[i].second;
        ll x0=x[fgi];
        ll x1=x[fgi]+t[fgi];
        tree.set(x0,x1,i);
    }
    map<ll,ll> p2t;

    map<ll,ll> p2c;

    for (ll i=0;i<m;i++){
        p2t[p[i]]+=b[i];
        p2c[p[i]]++;
        auto itt=p2t.find(p[i]);
        auto itc=p2c.find(p[i]);
        while (true){
            if (itt==p2t.end()) {assert(itc==p2c.end());break;}
            ll pos=itt->first;
            ll j=tree.get(pos,pos);
            if (j==n) break;
            ll fgi=xi[j].second;

            kil[fgi]+=itc->second;
            t[fgi]+=itt->second;
            tree.set(x[fgi],x[fgi]+t[fgi],j);
            itt=p2t.erase(itt);
            itc=p2c.erase(itc);
        }
    }
    for (ll i=0;i<n;i++){
        int ti=t[i];
        int ki=kil[i];
        printf("%d %d\n",ki,ti);
    }
    return 0;
}
