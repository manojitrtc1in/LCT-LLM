




















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
double id25(const PT& u, const PT& v) { return dot(u, v) / sqrt(dot(u,u)*dot(v,v)); }
double id8(const PT& u, const PT& v) { return cross(u, v) / sqrt(dot(u, u)*dot(v, v)); }
ostream &operator<<(ostream &os, const PT &p) {
    os << "(" << p.x << "," << p.y << ")";
}
double id20(const PT &v) {return atan2(v.y, v.x);}




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
ll id14(ll a, ll b, ll &x, ll &y) {
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
    ll d = id14(a, n, x, y);
    if (d > 1) return -1;
    return mod(x, n);
}



struct id5 {
    int m, n;
    VI B, N;
    VVD D;
    id5(const VVD &A, const VD &b, const VD &c) :
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



void id10(ll n,
    const vector<ll> &froms, const vector<ll> &tos,
    vector<ll> &id19, vector<ll> &id6)
{
    id19.resize(n);
    id19.assign(n, -1);
    ll en = froms.size();
    id6.resize(en);
    for (int i = 0;i < en;i++) {
        ll f = froms[i];
        ll t = tos[i];
        id6[i] = id19[f];
        id19[f] = i;
    }
}



struct id21 {
private:
    const vector<ll> &id19;
    const vector<ll> &id16;
    const vector<ll> &id9;
    const vector<ll> &id11;
    const vector<ll> &id6;
    ll s,t;

    ll find_aug_path(const vector<ll> &id19,
        const vector<ll> &id16,
        const vector<ll> &id9,
        const vector<ll> &id11,
        const vector<ll> &id6,
        ll s, ll t, vector<ll> &epath)
    {
        vector<ll> id27;
        vector<ll> id1;
        vector<ll> id24;
        vector<ll> id30;
        vector<bool> inq(id19.size(), false);
        

        id27.push_back(s);
        id1.push_back(-1);
        id24.push_back(-1);
        id30.push_back(INT_MAX);
        inq[s] = true;
        for (ll i = 0;i<id27.size();i++) {
            ll crt = id27[i];
            ll f = id30[i];
            for (ll j = id19[crt];j != -1;j = id6[j]) {
                ll to = id9[j];
                ll rem = id11[j];
                if (inq[to]) continue;
                if (rem <= 0) continue;
                id27.push_back(to);
                id1.push_back(i);
                id24.push_back(j);
                id30.push_back(min(f, rem));
                inq[to] = true;
            }
        }
        

        for (ll i = 0;i<id27.size();i++) {
            if (id27[i] != t) continue;
            stack<ll> stk;
            for (ll j = i;j>0;j = id1[j]) {
                stk.push(id24[j]);
            }
            while (!stk.empty()) {
                epath.push_back(stk.top());
                stk.pop();
            }
            return id30[i];
        }
        return 0;
    }

public:
    id21(const vector<ll> &id26,
        const vector<ll> &id4,
        const vector<ll> &id29,
        const vector<ll> &id17,
        const vector<ll> &id7,
        ll _s, ll _t)
        :  s(_s),t(_t),id19(id26),id16(id4),id9(id29),id11(id17),id6(id7)
    {
    }

    ll eval()
    {
        

        ll en = id16.size();
        map<pair<ll, ll>, ll> rsd;
        for (ll i = 0;i<en;i++) {
            ll f = id16[i];
            ll t = id9[i];
            rsd[make_pair(f, t)] += id11[i];
            rsd[make_pair(t, f)] += 0;
        }
        map<pair<ll, ll>, ll> nei;
        ll ren = 0;
        for (auto er : rsd) {
            nei[er.first] = ren++;
        }
        ll rvn = id19.size();
        vector<ll> id15(rvn, -1);
        vector<ll> id23(ren);

        vector<ll> id3(ren);

        vector<ll> id13(ren);

        vector<ll> id18(ren);

        vector<ll> id28(ren);

        ll rei = 0;
        for (auto er : rsd) {
            ll f = er.first.first;
            ll t = er.first.second;
            ll c = er.second;
            id23[rei] = f;
            id3[rei] = t;
            id13[rei] = c;
            id28[rei] = nei[make_pair(t, f)];
            id18[rei] = id15[f];
            id15[f] = rei;
            ++rei;
        }

        

        ll sol = 0;
        vector<ll> epath;
        while (true) {
            epath.clear();
            ll res = find_aug_path(id15, id23, id3, id13, id18, s, t, epath);
            if (res == 0) break;
            for (auto ei : epath) {
                id13[ei] -= res;
                id13[id28[ei]] += res;
            }
            sol += res;
        }
        return sol;
    }
};



template <typename T>
struct id22 {
    vector<T> v;
    vector<ll> opr;

    vector<T> opd;
    vector<ll> nxt;
    ll LEFT;
    ll RGHT;
    T (*fnx)(ll,T);
    T (*fab)(T,T);
    id22(ll _l, ll _r, T _v, T (*_fnx)(ll,T), T (*_fab)(T,T))
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

void readll(ll &x){int r;scanf("%d",&r);x=r;}

int min_ab(int a, int b){return min(a,b);}
int id0(ll n, int x){return x;}

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

    id22<int> tree(0,max(fmax,mmax),n,id0,min_ab);
    for (ll i=0;i<n;i++){
        ll fgi=xi[i].second;
        ll x0=x[fgi];
        ll x1=x[fgi]+t[fgi];
        tree.updres(x0,x1,i);
    }
    map<ll,ll> id12;

    map<ll,ll> id2;

    for (ll i=0;i<m;i++){
        id12[p[i]]+=b[i];
        id2[p[i]]++;
        auto itt=id12.find(p[i]);
        auto itc=id2.find(p[i]);
        while (true){
            if (itt==id12.end()) {assert(itc==id2.end());break;}
            ll pos=itt->first;
            int j=tree.get(pos,pos);
            if (j==n) break;
            ll fgi=xi[j].second;

            kil[fgi]+=itc->second;
            t[fgi]+=itt->second;
            tree.updres(x[fgi],x[fgi]+t[fgi],j);
            itt=id12.erase(itt);
            itc=id2.erase(itc);
        }
    }
    for (ll i=0;i<n;i++){
        int ti=t[i];
        int ki=kil[i];
        printf("%d %d\n",ki,ti);
    }
    return 0;
}
