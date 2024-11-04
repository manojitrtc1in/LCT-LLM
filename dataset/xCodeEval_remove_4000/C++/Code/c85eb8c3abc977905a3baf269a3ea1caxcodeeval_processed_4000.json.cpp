






























using namespace std;



const ll MOD = 998244353;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;




int n, m, T,  lr, rr, kl[100001], sz, nw;
pii TT;
vector<pii> vv;
bool tt[1000001];
vector<pair<pii,int> > c[100001];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h;
        h *= h;
        

        r /= 2;
    }
    return l;
}

ll gcd(ll x, ll y)
{
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}


struct segment_tree
{
    pii d[500001];
    int sz;

    void build(int h,int l,int r)
    {
        if (l==r)
        {
            d[h]=mp(-1e9,-1);
            return;
        }
        int w=(l+r)/2;
        build(h*2,l,w);
        build(h*2+1,w+1,r);
        if (d[h*2].fi>d[h*2+1].fi) d[h]=d[h*2]; else d[h]=d[h*2+1];
    }

    void update(int h,int l,int r,int x,pii k)
    {
        

        if (l==r)
        {
            if (k.fi>d[h].fi) d[h]=k;
            return;
        }
        int w=(l+r)/2;
        if (x<=w) update(h*2,l,w,x,k); else update(h*2+1,w+1,r,x,k);
        if (d[h*2].fi>d[h*2+1].fi) d[h]=d[h*2]; else d[h]=d[h*2+1];
    }

    pii get(int h,int l,int r,int x,int y)
    {
        if (x>y) return mp(-1e9,-1);
        if (l==x && y==r) return d[h];
        int w=(l+r)/2;
        pii o1=get(h*2,l,w,x,min(y,w)), o2=get(h*2+1,w+1,r,max(x,w+1),y);
        if (o1.fi>o2.fi) return o1; else return o2;
    }
};

segment_tree g;

void dfs(int h,int p=-1)
{
    

    kl[h]=1;
    sz++;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i].fi.fi!=p && !tt[c[h][i].fi.fi])
        {
            dfs(c[h][i].fi.fi, h);
            kl[h]+=kl[c[h][i].fi.fi];
        }
}

int get(int h)
{
    if (T>h)  return -1; else return 1;
}

void dfs2(int h,int k,int sm,int p)
{
    

    if (k>rr) return;
    pll y=g.get(1,0,g.sz,max(0,lr-k),min(rr-k,g.sz));
    if (y.fi+sm>=0) {TT=mp(y.se, h);return;}
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i].fi.fi] && c[h][i].fi.fi!=p)
        {
            dfs2(c[h][i].fi.fi,k+1,sm+get(c[h][i].fi.se),h);
        }
}

void dfs3(int h,int k,int sm,int p)
{
    

    if (k>rr) return;
    g.update(1,0,g.sz,k,mp(sm,h));
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i].fi.fi] && c[h][i].fi.fi!=p)
        {
            dfs3(c[h][i].fi.fi,k+1,sm+get(c[h][i].fi.se),h);
        }
}

ll id0(int h,int k,int p=-1)
{
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i].fi.fi!=p && kl[c[h][i].fi.fi]*2>=k && !tt[c[h][i].fi.fi]) return id0(c[h][i].fi.fi,k,h);
    return h;
}

void rec(int h)
{
    sz=0;
    dfs(h);
    if (sz<=lr) return;
    h=id0(h,sz);
    vv.pb(mp(h,sz));
    tt[h]=1;
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i].fi.fi]) rec(c[h][i].fi.fi);
}


int main()
{
    

    

    

    

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> lr >> rr;
    vector<ll> qq, q;
    for (int i = 1; i < n; i++)
    {
        ll x, y, h;
        cin >> x >> y >> h;
        qq.pb(h);
        c[x].pb(mp(mp(y,h),i));
        c[y].pb(mp(mp(x,h),i));
        

    }
    ld nox=clock();
    sort(all(qq));
    for (int i = 0; i < qq.size(); i++)
        if (i==0 || qq[i]!=qq[i-1]) q.pb(qq[i]);
    

    rec(1);
    

    

    

    ll l=0, r=q.size()-1;
    ll nm=0;
    

    while (l<r)
    {
        

        int w=(l+r+1)/2;
        T=q[w];
        TT=mp(-1,-1);
        

        for (int i = 1; i <= n; i++) tt[i]=0;
        for (int i = 0; i < vv.size(); i++)
        {
            tt[vv[i].fi]=1;
            g.sz=min(rr, vv[i].se);
            g.build(1,0,g.sz);
            g.update(1,0,g.sz,0,mp(0,vv[i].fi));
            for (int j = 0; j < c[vv[i].fi].size(); j++)
                if (!tt[c[vv[i].fi][j].fi.fi])
                {
                    dfs2(c[vv[i].fi][j].fi.fi,1,get(c[vv[i].fi][j].fi.se),vv[i].fi);
                    dfs3(c[vv[i].fi][j].fi.fi,1,get(c[vv[i].fi][j].fi.se),vv[i].fi);
                    if (TT.fi!=-1) break;
                }
            if (TT.fi!=-1) break;
        }
        if (TT.fi!=-1) l=w; else r=w-1;
    }
    T=q[l];
    TT=mp(-1,-1);
    for (int i = 1; i <= n; i++) tt[i]=0;
    for (int i = 0; i < vv.size(); i++)
    {
        tt[vv[i].fi]=1;
        g.sz=min(rr, vv[i].se);
        g.build(1,0,g.sz);
        g.update(1,0,g.sz,0,mp(0,vv[i].fi));
        

        for (int j = 0; j < c[vv[i].fi].size(); j++)
            if (!tt[c[vv[i].fi][j].fi.fi])
            {
                

                dfs2(c[vv[i].fi][j].fi.fi,1,get(c[vv[i].fi][j].fi.se),vv[i].fi);
                

                dfs3(c[vv[i].fi][j].fi.fi,1,get(c[vv[i].fi][j].fi.se),vv[i].fi);
                

                if (TT.fi!=-1) break;
            }
        if (TT.fi!=-1) break;
    }
    cout << TT.fi << " " << TT.se << "\n";
    

    

    return 0;
}


