




















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
double id24(const PT& u, const PT& v) { return dot(u, v) / sqrt(dot(u,u)*dot(v,v)); }
double id7(const PT& u, const PT& v) { return cross(u, v) / sqrt(dot(u, u)*dot(v, v)); }
ostream &operator<<(ostream &os, const PT &p) {
    os << "(" << p.x << "," << p.y << ")";
}
double id19(const PT &v) {return atan2(v.y, v.x);}




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
ll id13(ll a, ll b, ll &x, ll &y) {
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
    ll d = id13(a, n, x, y);
    if (d > 1) return -1;
    return mod(x, n);
}



struct id4 {
    int m, n;
    VI B, N;
    VVD D;
    id4(const VVD &A, const VD &b, const VD &c) :
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



void id9(ll n,
    const vector<ll> &froms, const vector<ll> &tos,
    vector<ll> &id18, vector<ll> &id5)
{
    id18.resize(n);
    id18.assign(n, -1);
    ll en = froms.size();
    id5.resize(en);
    for (int i = 0;i < en;i++) {
        ll f = froms[i];
        ll t = tos[i];
        id5[i] = id18[f];
        id18[f] = i;
    }
}



struct id20 {
private:
    const vector<ll> &id18;
    const vector<ll> &id15;
    const vector<ll> &id8;
    const vector<ll> &id10;
    const vector<ll> &id5;
    ll s,t;

    ll find_aug_path(const vector<ll> &id18,
        const vector<ll> &id15,
        const vector<ll> &id8,
        const vector<ll> &id10,
        const vector<ll> &id5,
        ll s, ll t, vector<ll> &epath)
    {
        vector<ll> id26;
        vector<ll> id0;
        vector<ll> id23;
        vector<ll> id29;
        vector<bool> inq(id18.size(), false);
        

        id26.push_back(s);
        id0.push_back(-1);
        id23.push_back(-1);
        id29.push_back(INT_MAX);
        inq[s] = true;
        for (ll i = 0;i<id26.size();i++) {
            ll crt = id26[i];
            ll f = id29[i];
            for (ll j = id18[crt];j != -1;j = id5[j]) {
                ll to = id8[j];
                ll rem = id10[j];
                if (inq[to]) continue;
                if (rem <= 0) continue;
                id26.push_back(to);
                id0.push_back(i);
                id23.push_back(j);
                id29.push_back(min(f, rem));
                inq[to] = true;
            }
        }
        

        for (ll i = 0;i<id26.size();i++) {
            if (id26[i] != t) continue;
            stack<ll> stk;
            for (ll j = i;j>0;j = id0[j]) {
                stk.push(id23[j]);
            }
            while (!stk.empty()) {
                epath.push_back(stk.top());
                stk.pop();
            }
            return id29[i];
        }
        return 0;
    }

public:
    id20(const vector<ll> &id25,
        const vector<ll> &id3,
        const vector<ll> &id28,
        const vector<ll> &id16,
        const vector<ll> &id6,
        ll _s, ll _t)
        :  s(_s),t(_t),id18(id25),id15(id3),id8(id28),id10(id16),id5(id6)
    {
    }

    ll eval()
    {
        

        ll en = id15.size();
        map<pair<ll, ll>, ll> rsd;
        for (ll i = 0;i<en;i++) {
            ll f = id15[i];
            ll t = id8[i];
            rsd[make_pair(f, t)] += id10[i];
            rsd[make_pair(t, f)] += 0;
        }
        map<pair<ll, ll>, ll> nei;
        ll ren = 0;
        for (auto er : rsd) {
            nei[er.first] = ren++;
        }
        ll rvn = id18.size();
        vector<ll> id14(rvn, -1);
        vector<ll> id22(ren);

        vector<ll> id2(ren);

        vector<ll> id12(ren);

        vector<ll> id17(ren);

        vector<ll> id27(ren);

        ll rei = 0;
        for (auto er : rsd) {
            ll f = er.first.first;
            ll t = er.first.second;
            ll c = er.second;
            id22[rei] = f;
            id2[rei] = t;
            id12[rei] = c;
            id27[rei] = nei[make_pair(t, f)];
            id17[rei] = id14[f];
            id14[f] = rei;
            ++rei;
        }

        

        ll sol = 0;
        vector<ll> epath;
        while (true) {
            epath.clear();
            ll res = find_aug_path(id14, id22, id2, id12, id17, s, t, epath);
            if (res == 0) break;
            for (auto ei : epath) {
                id12[ei] -= res;
                id12[id27[ei]] += res;
            }
            sol += res;
        }
        return sol;
    }
};

struct id21 {
    vector<ll> v;
    vector<ll> p;
    vector<ll> l;
    ll LEFT;
    ll RGHT;
    id21(ll _l, ll _r, ll _v):v(1),p(1),l(1),LEFT(_l),RGHT(_r) {
        v[0]=_v;
        p[0]=_v;
        l[0]=-1;
    }
    void _split(ll i){
        assert(l[i]==-1);
        ll n=v.size();
        v.push_back(p[i]);v.push_back(p[i]);
        p.push_back(p[i]);p.push_back(p[i]);
        l.push_back(-1);l.push_back(-1);
        l[i]=n;
    }
    void _set(ll i, ll l0, ll r0, ll l1, ll r1, ll v1){
        assert(l1>=l0&&r1<=r0);
        v[i]=min(v[i],v1);
        if (l0==l1&&r0==r1){
            p[i]=min(p[i],v1);
            return;
        }
        ll m0=(l0+r0)/2;
        if (l[i]==-1)
            _split(i);
        else{
            _set(l[i],l0,m0,l0,m0,p[i]);
            _set(l[i]+1,m0+1,r0,m0+1,r0,p[i]);
        }
        if (l1<=m0) _set(l[i],l0,m0,l1,min(r1,m0),v1);
        if (r1>m0) _set(l[i]+1,m0+1,r0,max(l1,m0+1),r1,v1);
    }
    ll _get(ll i, ll l0, ll r0, ll l1, ll r1){
        assert(l0<=l1&&r1<=r0);
        if (l0==l1&&r1==r0) return v[i];
        if (l[i]==-1) return v[i];
        ll m0=(l0+r0)/2;
        _set(l[i],l0,m0,l0,m0,p[i]);
        _set(l[i]+1,m0+1,r0,m0+1,r0,p[i]);
        bool lgood=(l1<=m0);
        ll lv=(lgood)?_get(l[i],l0,m0,l1,min(r1,m0)):0;
        bool rgood=(m0+1<=r1);
        ll rv=(rgood)?_get(l[i]+1,m0+1,r0,max(m0+1,l1),r1):0;
        return (!lgood)?rv:(!rgood)?lv:min(lv,rv);
    }
    void set(ll l1, ll r1, ll v1){_set(0,LEFT,RGHT,l1,r1,v1);}
    ll get(ll l1, ll r1){return _get(0,LEFT,RGHT,l1,r1);}
};

void asd(){
    id21 tree(0,44444,2222);
    cout<<tree.v.size()<<endl;
}

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

    id21 tree(0,max(fmax,mmax),n);
    for (ll i=0;i<n;i++){
        ll fgi=xi[i].second;
        ll x0=x[fgi];
        ll x1=x[fgi]+t[fgi];
        tree.set(x0,x1,i);
    }
    map<ll,ll> id11;

    map<ll,ll> id1;

    for (ll i=0;i<m;i++){
        id11[p[i]]+=b[i];
        id1[p[i]]++;
        auto itt=id11.find(p[i]);
        auto itc=id1.find(p[i]);
        while (true){
            if (itt==id11.end()) {assert(itc==id1.end());break;}
            ll pos=itt->first;
            ll j=tree.get(pos,pos);
            if (j==n) break;
            ll fgi=xi[j].second;

            kil[fgi]+=itc->second;
            t[fgi]+=itt->second;
            tree.set(x[fgi],x[fgi]+t[fgi],j);
            itt=id11.erase(itt);
            itc=id1.erase(itc);
        }
    }
    for (ll i=0;i<n;i++){
        int ti=t[i];
        int ki=kil[i];
        printf("%d %d\n",ki,ti);
    }
    return 0;
}
