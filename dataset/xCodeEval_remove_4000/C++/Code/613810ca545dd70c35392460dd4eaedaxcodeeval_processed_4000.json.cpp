
















































































using namespace std;

typedef int ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef char ch;
typedef string str;
typedef bool bl;

ll binpow(ll a,ll n,ll mod)
{
    ll ans=1;
    while(n)
    {
        if(n&1)ans=(ans*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    ret ans;
}

ll binpow(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n&1)ans*=a;
        a*=a;
        n>>=1;
    }
    ret ans;
}

vector<ll> pr;
vd id0(ll x)
{
    if(pr.size()>0)ret;

    vector<ll> p(x+1);

    for(ll i=2;i<=x;i++)
    {
        if(p[i]==0)
        {
            pr.pb(i);
            for(ll j=i+i;j<=x;j+=i)p[j]=1;
        }
    }
}

vector<ll> fact(ll x)
{
    id0(sqrt(1e9));

    vector<ll> ans;

    ll i=0,c=sqrt(x),n=pr.size();
    while(x>1 and pr[i]<=c and i<n)
    {
        if(x%pr[i]==0)
        {
            x/=pr[i];
            ans.pb(pr[i]);
            c=sqrt(x);
        }
        else i++;
    }

    if(x!=1)ans.pb(x);

    ret ans;
}























    























































queue<pll> q;
ll n,m,k,col,F;
vector<vector<ll> > g,ans;
vector<ll> v,fl;

vd add(ll a,ll b)
{
    
}

int32_t main()
{

   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);






    

    

    

    


    cin >> n >> m >> k >> col;

    v.resize(n);
    g.resize(n+1);
    ans.resize(n+1);
    fl.resize(n+1);

    for(ll i=0;i<n;i++)cin >> v[i];

    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin >> a >> b;
    
        g[a].pb(b);
        g[b].pb(a);
    }

    for(ll i=1;i<=k;i++)
    {
        F=i;
        for(ll j=0;j<n;j++)if(v[j]==i)q.push({j+1,0}),ans[j+1].pb(0),fl[j+1]=i;

        while(!q.empty())
        {
            ll a=q.front().f,b=q.front().s;
            

            q.pop();

            vector<ll> kol=g[a];
            ll n=kol.size();
            for(ll l=0;l<n;l++)if(fl[kol[l]]!=F)
            {
                ll a=kol[l];

                q.push({a,b+1});
                ans[a].pb(b+1);
                fl[a]=F;
            
            }

        }
    }

    for(ll i=1;i<=n;i++)
    {
        ll an=0;

        vector<ll> v=ans[i];
        sort(v.begin(),v.end());
        

        for(ll j=0;j<col;j++)an+=v[j];
        


        cout << an << " ";
    }
    cout << endl;

    ret 0;
}