




















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
double id31(const PT& u, const PT& v) { return dot(u, v) / sqrt(dot(u,u)*dot(v,v)); }
double id8(const PT& u, const PT& v) { return cross(u, v) / sqrt(dot(u, u)*dot(v, v)); }
ostream &operator<<(ostream &os, const PT &p) {
    os << "(" << p.x << "," << p.y << ")";
}
double id26(const PT &v) {return atan2(v.y, v.x);}




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
ll id18(ll a, ll b, ll &x, ll &y) {
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
    ll d = id18(a, n, x, y);
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



void id13(ll n,
    const vector<ll> &froms, const vector<ll> &tos,
    vector<ll> &id25, vector<ll> &id6)
{
    id25.resize(n);
    id25.assign(n, -1);
    ll en = froms.size();
    id6.resize(en);
    for (int i = 0;i < en;i++) {
        ll f = froms[i];
        ll t = tos[i];
        id6[i] = id25[f];
        id25[f] = i;
    }
}



struct id27 {
    const vector<ll> &id25;
    const vector<ll> &id22;
    const vector<ll> &id11;
    const vector<ll> &id15;
    const vector<ll> &id6;
    ll s,t;
    id27(const vector<ll> &id32,
        const vector<ll> &id4,
        const vector<ll> &id35,
        const vector<ll> &id23,
        const vector<ll> &id7,
        ll _s, ll _t)
        :  s(_s),t(_t),id25(id32),id22(id4),id11(id35),id15(id23),id6(id7)
    {}
    ll _find_aug_path(const vector<ll> &id25,
        const vector<ll> &id22,
        const vector<ll> &id11,
        const vector<ll> &id15,
        const vector<ll> &id6,
        ll s, ll t, vector<ll> &epath)
    {
        vector<ll> id33;
        vector<ll> id0;
        vector<ll> id30;
        vector<ll> id37;
        vector<bool> inq(id25.size(), false);
        

        id33.push_back(s);
        id0.push_back(-1);
        id30.push_back(-1);
        id37.push_back(INT_MAX);
        inq[s] = true;
        for (ll i = 0;i<id33.size();i++) {
            ll crt = id33[i];
            ll f = id37[i];
            for (ll j = id25[crt];j != -1;j = id6[j]) {
                ll to = id11[j];
                ll rem = id15[j];
                if (inq[to]) continue;
                if (rem <= 0) continue;
                id33.push_back(to);
                id0.push_back(i);
                id30.push_back(j);
                id37.push_back(min(f, rem));
                inq[to] = true;
            }
        }
        

        for (ll i = 0;i<id33.size();i++) {
            if (id33[i] != t) continue;
            stack<ll> stk;
            for (ll j = i;j>0;j = id0[j]) {
                stk.push(id30[j]);
            }
            while (!stk.empty()) {
                epath.push_back(stk.top());
                stk.pop();
            }
            return id37[i];
        }
        return 0;
    }

    ll eval(){
        

        ll en = id22.size();
        map<pair<ll, ll>, ll> rsd;
        for (ll i = 0;i<en;i++) {
            ll f = id22[i];
            ll t = id11[i];
            rsd[make_pair(f, t)] += id15[i];
            rsd[make_pair(t, f)] += 0;
        }
        map<pair<ll, ll>, ll> nei;
        ll ren = 0;
        for (auto er : rsd) {
            nei[er.first] = ren++;
        }
        ll rvn = id25.size();
        vector<ll> id19(rvn, -1);
        vector<ll> id29(ren);

        vector<ll> id2(ren);

        vector<ll> id17(ren);

        vector<ll> id24(ren);

        vector<ll> id34(ren);

        ll rei = 0;
        for (auto er : rsd) {
            ll f = er.first.first;
            ll t = er.first.second;
            ll c = er.second;
            id29[rei] = f;
            id2[rei] = t;
            id17[rei] = c;
            id34[rei] = nei[make_pair(t, f)];
            id24[rei] = id19[f];
            id19[f] = rei;
            ++rei;
        }

        

        ll sol = 0;
        vector<ll> epath;
        while (true) {
            epath.clear();
            ll res = _find_aug_path(id19, id29, id2, id17, id24, s, t, epath);
            if (res == 0) break;
            for (auto ei : epath) {
                id17[ei] -= res;
                id17[id34[ei]] += res;
            }
            sol += res;
        }
        return sol;
    }
};



template <typename T>
struct id28 {
    vector<T> v;
    vector<ll> opr;

    vector<T> opd;
    vector<ll> nxt;
    ll LEFT;
    ll RGHT;
    T (*fnx)(ll,T);
    T (*fab)(T,T);
    id28(ll _l, ll _r, T _v, T (*_fnx)(ll,T), T (*_fab)(T,T))
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







ll getmove(ll n, ll from, ll to){
    ll c=dis0(n,from,to);
    ll cc=dis1(n,from,to);
    if (c<cc) return c;
    return -cc;
}
vector<ll> id1(ll n, vector<ll> &eles, ll from, ll to){
    vector<ll> ret;
    ll en=eles.size();
    while(from!=to){
        ll nxt=(from+1)%en;
        ret.push_back(dis0(n,eles[from],eles[nxt]));
        from=nxt;
    }
    return ret;
}
vector<ll> id9(ll n, vector<ll> &eles, ll from, ll to){
    vector<ll> ret;
    ll en=eles.size();
    while(from!=to){
        ll nxt=(from+en-1)%en;
        ret.push_back(-dis1(n,eles[from],eles[nxt]));
        from=nxt;
    }
    return ret;
}
vector<ll> convec(const vector<ll> &va, const vector<ll> &vb){
    vector<ll> ret(va);
    ret.insert(ret.end(),vb.begin(),vb.end());
    return ret;
}
ll id21(ll n, vector<ll> &eles, ll from, ll to){
    ll en=eles.size();
    ll topre=(to+en-1)%en;
    ll tonxt=(to+1)%en;
    ll c0=dis0(n,eles[from],eles[topre])+dis1(n,eles[topre],eles[to]);
    ll c1=dis1(n,eles[from],eles[tonxt])+dis0(n,eles[tonxt],eles[to]);
    return min(c0,c1);
}
vector<ll> id10(ll n, vector<ll> &eles, ll from, ll to){
    

    

    ll en=eles.size();
    if (en==1) return vector<ll>(0);
    ll topre=(to+en-1)%en;
    ll tonxt=(to+1)%en;
    ll c0=dis0(n,eles[from],eles[topre])+dis1(n,eles[topre],eles[to]);
    ll c1=dis1(n,eles[from],eles[tonxt])+dis0(n,eles[tonxt],eles[to]);
    vector<ll> seq;
    vector<ll> dir;
    if (c0<=c1){
        for (ll i=from;;i=(i+1)%en){
            seq.push_back(eles[i]);
            if (i==topre) break;
            dir.push_back(0);
        }
        for (ll i=(from+en-1)%en;;i=(i+en-1)%en){
            dir.push_back(1);
            seq.push_back(eles[i]);
            if (i==to) break;
        }
    }else{
        for (ll i=from;;i=(i+en-1)%en){
            seq.push_back(eles[i]);
            if (i==tonxt) break;
            dir.push_back(1);
        }
        for (ll i=(from+1)%en;;i=(i+1)%en){
            dir.push_back(0);
            seq.push_back(eles[i]);
            if (i==to) break;
        }
    }
    vector<ll> ret;
    for (ll i=1;i<seq.size();i++)
        ret.push_back((dir[i-1]==0)?dis0(n,seq[i-1],seq[i]):-dis1(n,seq[i-1],seq[i]));
    return ret;
}
void dijkstra(vector<ll>& id25, vector<ll>& id11, vector<ll>& id15, vector<ll>& id6, ll src, vector<ll>& dist, vector<ll>& prec){
    ll n=id25.size();
    dist.assign(n,INT_MAX);
    prec.assign(n,-1);

    vector<bool> arr(n);
    ll sel=src;
    dist[sel]=0;
    while (sel>=0){
        arr[sel]=true;
        for (ll i=id25[sel];i>=0;i=id6[i]){
            ll to=id11[i];
            ll cost=id15[i];
            if (!arr[to]&&dist[to]>dist[sel]+cost){
                dist[to]=dist[sel]+cost;
                prec[to]=sel;
            }
        }
        sel=-1;
        for (ll i=0;i<n;i++)
            if (!arr[i]&&(sel==-1||dist[i]<dist[sel])) sel=i;
    }
}

bool inseg(ll l, ll r, ll m){
    if (l==r) return true;
    if (l<r) return l<=m&&m<r;
    if (l>r) return m>=l||m<r;
}

ll id16(vector<ll> &x){
    set<ll> avset(x.begin(),x.end());
    map<ll,ll> vmap;ll dn=0;
    for (auto it=avset.begin();it!=avset.end();it++) vmap[*it]=dn++;
    for (ll i=0,n=x.size();i<n;i++) x[i]=vmap[x[i]];
    return dn;
}

int main()
{
    ll n,p0;cin>>n>>p0;
    ll gvn=n*2+2;
    p0--;
    vector<ll> a(n);for (ll i=0;i<n;i++) cin>>a[i];
    ll bn=id16(a);

    vector<vector<ll>> id20(bn);
    for (ll i=0;i<n;i++) id20[a[i]].push_back(i);
    for (auto ps:id20) sort(ps.begin(),ps.end());

    ll vn=0;
    vector<ll> id22;vector<ll> id11;vector<ll> id6;vector<ll> id15;
    vector<ll> id25(gvn,-1);
    vector<ll> id12(gvn,-1);
    vector<ll> id14(gvn,-1);
    for (ll i=0;i<bn;i++){
        auto poss=id20[i];
        ll pn=poss.size();
        

        for (ll j=0;j<pn;j++) id12[vn+j]=id12[vn+pn+j]=poss[j];
        for (ll j=0;j<pn;j++) id14[vn+j]=id14[vn+pn+j]=j;
        

        if (pn==1){
            addedge(vn,vn+1,0);
        }else{
            for (ll j=0;j<pn;j++)
                for (ll k=0;k<pn;k++){
                    if (k==j) continue;
                    ll cost=id21(n,poss,j,k);
                    addedge(vn+j,vn+pn+k,cost);
                }
        }

        

        if (i<bn-1){
            auto id3=id20[i+1];
            ll id36=id3.size();
            if (id36==1){
                for (ll j=0,k=0;j<pn;j++) addedge(vn+pn+j,vn+pn*2,min(dis0(n,poss[j],id3[0]),dis1(n,poss[j],id3[0])));
            }else{
                for (ll j=0,k=0;j<pn;j++){
                    for(;!inseg(id3[k],id3[(k+1)%id36],poss[j]);k=(k+1)%id36);
                    ll k1=(k+1)%id36;
                    addedge(vn+pn+j,vn+pn*2+k,dis1(n,poss[j],id3[k]));
                    addedge(vn+pn+j,vn+pn*2+k1,dis0(n,poss[j],id3[k1]));
                }
            }
        }
        vn+=pn*2;
    }
    id12[gvn-2]=p0;
    

    ll k=0,kn=id20[0].size();
    for(;!inseg(id20[0][k],id20[0][(k+1)%kn],p0);k=(k+1)%kn);
    if (p0==id20[0][k]){
        addedge(gvn-2,k,0);
    }else{
        addedge(gvn-2,k,dis1(n,p0,id20[0][k]));
        addedge(gvn-2,(k+1)%kn,dis0(n,p0,id20[0][(k+1)%kn]));
    }

    

    auto lastposs=id20.back();
    ll lastkn=lastposs.size();
    for (ll i=gvn-2-lastkn;i<gvn-2;i++) addedge(i,gvn-1,0);

    

    id13(gvn,id22,id11,id25,id6);

    vector<ll> prec(gvn,-1);
    vector<ll> dist(gvn,INT_MAX);
    dijkstra(id25,id11,id15,id6,gvn-2,dist,prec);

    stack<ll> solstk;
    for (ll i=prec[gvn-1];i!=gvn-2;i=prec[prec[i]]){
        ll lo=i;
        ll li=prec[lo];
        auto zu=id20[a[id12[li]]];
        auto lp=id10(n,zu,id14[li],id14[lo]);
        for (auto it=lp.rbegin();it!=lp.rend();++it) solstk.push(*it);
        ll gp=getmove(n,id12[prec[li]],id12[li]);
        solstk.push(gp);
    }

    cout<<dist.back()<<endl;
    for (;!solstk.empty();){
        ll mv=solstk.top();solstk.pop();
        if (mv>=0)cout<<"+";
        cout<<mv<<endl;
    }
    return 0;
}
