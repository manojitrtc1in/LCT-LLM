




















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
double id7(const PT& u, const PT& v) { return cross(u, v) / sqrt(dot(u, u)*dot(v, v)); }
ostream &operator<<(ostream &os, const PT &p) {
    os << "(" << p.x << "," << p.y << ")";
}
double id21(const PT &v) {return atan2(v.y, v.x);}




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
    vector<ll> &id20, vector<ll> &id5)
{
    id20.resize(n);
    id20.assign(n, -1);
    ll en = froms.size();
    id5.resize(en);
    for (int i = 0;i < en;i++) {
        ll f = froms[i];
        ll t = tos[i];
        id5[i] = id20[f];
        id20[f] = i;
    }
}



struct id22 {
private:
    const vector<ll> &id20;
    const vector<ll> &id16;
    const vector<ll> &id8;
    const vector<ll> &id10;
    const vector<ll> &id5;
    ll s,t;

    ll find_aug_path(const vector<ll> &id20,
        const vector<ll> &id16,
        const vector<ll> &id8,
        const vector<ll> &id10,
        const vector<ll> &id5,
        ll s, ll t, vector<ll> &epath)
    {
        vector<ll> id27;
        vector<ll> id0;
        vector<ll> id24;
        vector<ll> id30;
        vector<bool> inq(id20.size(), false);
        

        id27.push_back(s);
        id0.push_back(-1);
        id24.push_back(-1);
        id30.push_back(INT_MAX);
        inq[s] = true;
        for (ll i = 0;i<id27.size();i++) {
            ll crt = id27[i];
            ll f = id30[i];
            for (ll j = id20[crt];j != -1;j = id5[j]) {
                ll to = id8[j];
                ll rem = id10[j];
                if (inq[to]) continue;
                if (rem <= 0) continue;
                id27.push_back(to);
                id0.push_back(i);
                id24.push_back(j);
                id30.push_back(min(f, rem));
                inq[to] = true;
            }
        }
        

        for (ll i = 0;i<id27.size();i++) {
            if (id27[i] != t) continue;
            stack<ll> stk;
            for (ll j = i;j>0;j = id0[j]) {
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
    id22(const vector<ll> &id26,
        const vector<ll> &id3,
        const vector<ll> &id29,
        const vector<ll> &id17,
        const vector<ll> &id6,
        ll _s, ll _t)
        :  s(_s),t(_t),id20(id26),id16(id3),id8(id29),id10(id17),id5(id6)
    {
    }

    ll eval()
    {
        

        ll en = id16.size();
        map<pair<ll, ll>, ll> rsd;
        for (ll i = 0;i<en;i++) {
            ll f = id16[i];
            ll t = id8[i];
            rsd[make_pair(f, t)] += id10[i];
            rsd[make_pair(t, f)] += 0;
        }
        map<pair<ll, ll>, ll> nei;
        ll ren = 0;
        for (auto er : rsd) {
            nei[er.first] = ren++;
        }
        ll rvn = id20.size();
        vector<ll> id14(rvn, -1);
        vector<ll> id23(ren);

        vector<ll> id2(ren);

        vector<ll> id12(ren);

        vector<ll> id18(ren);

        vector<ll> id28(ren);

        ll rei = 0;
        for (auto er : rsd) {
            ll f = er.first.first;
            ll t = er.first.second;
            ll c = er.second;
            id23[rei] = f;
            id2[rei] = t;
            id12[rei] = c;
            id28[rei] = nei[make_pair(t, f)];
            id18[rei] = id14[f];
            id14[f] = rei;
            ++rei;
        }

        

        ll sol = 0;
        vector<ll> epath;
        while (true) {
            epath.clear();
            ll res = find_aug_path(id14, id23, id2, id12, id18, s, t, epath);
            if (res == 0) break;
            for (auto ei : epath) {
                id12[ei] -= res;
                id12[id28[ei]] += res;
            }
            sol += res;
        }
        return sol;
    }
};

struct id19 {
    ll l;
    ll r;
    int val;
    int to_push;
    id19* id15;
    id19* rchd;
    id19(ll _l, ll _r, int _v):l(_l),r(_r),val(_v),to_push(_v),id15(NULL),rchd(NULL){}
    void set(ll l1, ll r1, int v1){

        assert(l1>=l&&r1<=r);
        val=min(val,v1);
        if (l==l1&&r==r1){
            to_push=min(to_push,v1);
            return;
        }
        ll m=(l+r)/2;
        if (id15==NULL){
            id15=new id19(l,m,to_push);
            rchd=new id19(m+1,r,to_push);
        }
        id15->set(l,m,to_push);
        rchd->set(m+1,r,to_push);
        if (l1<=m) id15->set(l1,min(r1,m),v1);
        if (r1>m) rchd->set(max(l1,m+1),r1,v1);
    }
    int get(ll l1, ll r1){
        assert(l1>=l&&r1<=r);
        if (l==l1&&r==r1){
            return val;
        }
        if (id15==NULL) return val;
        ll m=(l+r)/2;
        id15->set(l,m,to_push);
        rchd->set(m+1,r,to_push);
        bool lgood=(l1<=m);
        ll lv=(lgood)?id15->get(l1,min(r1,m)):0;
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

    id19 tree(0,max(fmax,mmax),n);
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
