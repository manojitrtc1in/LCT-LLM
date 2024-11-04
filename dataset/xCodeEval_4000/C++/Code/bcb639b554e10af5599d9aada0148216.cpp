

























































#include <bits/stdc++.h>


































#define endl "\n"
#define amd and
#define pb push_back
#define f first
#define s second
#define ret return
#define cont continue
#define lcm(x,y) (x*y/__gcd(x,y))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef char ch;
typedef string str;
typedef bool bl;
typedef void vd;

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
vd PrDoX(ll x)
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
    PrDoX(sqrt(1e10));

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





int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);




    

    





    

    


    ll n,m,k;
    cin >> n >> m >> k;

    vector<ll> p(n+1);
    vector<pll> v;
    vector<vector<ll> > g(n+1);
    ll ans=0;
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin >> a >> b;

        g[a].pb(b);
        g[b].pb(a);

        p[a]++;
        p[b]++;

        v.pb({a,b});

        ans+=(p[a]==k)+(p[b]==k);
    }

    queue<ll> q;
    for(ll i=1;i<=n;i++)if(p[i]>0 and p[i]<k)q.push(i);

    vector<bl> fl(n+1);
    while(!q.empty())
    {
        ll a=q.front();
        q.pop();
        if(fl[a]==1)cont;
        fl[a]=1;

        vector<ll> v=g[a];
        ll n=v.size();
        for(ll i=0;i<n;i++)
        {
            ll b=v[i];
            if(fl[b]==1)cont;

            p[b]--;
            if(p[b]==k-1)ans--,q.push(b);
        }
    }

    vector<ll> an;
    an.pb(ans);



    for(ll i=1;i<=n;i++)sort(all(g[i]));

    for(ll i=m-1;i>0;i--)
    {



        ll a=v[i].f,b=v[i].s;









        if(fl[a] or fl[b]==1)
        {
            an.pb(ans);
            cont;
        }



        p[a]--;
        p[b]--;


        g[a].erase(lower_bound(all(g[a]),b));
        g[b].erase(lower_bound(all(g[b]),a));

        queue<ll> q;

        bl F=0;
        if(p[a]==k-1)q.push(a),ans--;
        if(p[b]==k-1)q.push(b),ans--;

















        while(!q.empty())
        {


            ll a0=q.front();
            q.pop();
            if(fl[a0]==1)cont;


            fl[a0]=1;

            vector<ll> v=g[a0];
            ll n=v.size();
            for(ll i=0;i<n;i++)
            {
                ll b0=v[i];
                if((a0==a and b0==b)or(a0==b and b0==a))cont;
                if(fl[b0]==1)cont;




                p[b0]--;
                if(p[b0]==k-1)ans--,q.push(b0);
            }
        }


















        an.pb(ans);
    }

    for(ll i=m-1;i>=0;i--)cout << an[i] << endl;










  ret 0;
}
