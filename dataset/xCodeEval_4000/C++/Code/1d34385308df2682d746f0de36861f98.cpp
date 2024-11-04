

























































#include <bits/stdc++.h>






















#define endl "\n"
#define amd and
#define vd void
#define pb push_back
#define f first
#define s second
#define ret return
#define cont continue

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
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
vd PrDoX()
{
    if(pr.size()>0)ret;

    ll x=1000000;

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
    PrDoX();

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

ll lcm(vector<ll> an)
{
    ll n=1e6;

    vector<ll> de(n+1);
    for(ll i=0;i<an.size();i++)
    {
        ll k=2,ans=0,a=an[i];
        while(a>1)
        {
            if(a%k==0)ans++,a/=k;
            else de[k]=max(de[k],ans),ans=0,k++;
        }
        de[k]=max(de[k],ans);

    }

    ll ans=1;
    for(ll i=2;i<=n;i++)
    {
        ans*=binpow(i,de[i]);
    }
    ret ans;
}



int main()
{





















    ll n,m,k;
    cin >> n >> m >> k;

    vector<pll> v(n);

    for(ll i=0;i<n;i++)
    {
        cin >> v[i].f;
        v[i].s=i+1;
    }


    map<ll,ll> mp;
    ll c;

    cin >> c;

    for(ll i=0;i<c;i++)
    {
        ll a;
        cin >> a;
        mp[a]=1;
    }

    cin >> c;
    for(ll i=0;i<c;i++)
    {
        ll a;
        cin >> a;

        if(mp[a]==1)mp[a]=3;
        else mp[a]=2;
    }

    sort(v.begin(),v.end());

    multiset<ll> st,st1;
    vector<ll> v1,v2,v3;

    for(ll i=0;i<n;i++)
    {
        ll a=v[i].f,b=v[i].s;

        if(mp[b]==1)v1.pb(a);
        else if(mp[b]==2)v2.pb(a);
        else if(mp[b]==3)v3.pb(a),st1.insert(a);
        else st1.insert(a);
    }

    for(ll i=k;i<v1.size();i++)st1.insert(v1[i]);
    for(ll i=k;i<v2.size();i++)st1.insert(v2[i]);

    while(v1.size()>k)v1.pop_back();
    while(v2.size()>k)v2.pop_back();

    ll ans=0,mn=1e18;

    for(ll i=0;i<v1.size();i++)ans+=v1[i];
    for(ll i=0;i<v2.size();i++)ans+=v2[i];

    for(ll i=0;i<=min(m,ll(v3.size()));i++)
    {
        ll nv=max(k-i,0ll);

        if(nv<=min(v1.size(),v2.size()))
        {
            while(v1.size()>nv)ans-=v1.back(),st1.insert(v1.back()),v1.pop_back();
            while(v2.size()>nv)ans-=v2.back(),st1.insert(v2.back()),v2.pop_back();

            ll len=m-nv*2-i;

            if(len>=0)
            {
                while(st.size()>len)
                {
                    auto it=--st.end();
                    ans-=*it;
                    st1.insert(*it);
                    st.erase(it);
                }

                while(st.size()<len)
                {
                    if(st1.size()==0)break;

                    auto it=st1.begin();
                    ans+=*it;
                    st.insert(*it);
                    st1.erase(it);
                }

                if(st.size()==len)mn=min(mn,ans);
            }
        }

        if(i==v3.size())break;

        ans+=v3[i];

        if(st1.find(v3[i])!=st1.end())st1.erase(st1.find(v3[i]));
        else st.erase(st.find(v3[i])),ans-=v3[i];

    }

    if(mn==1e18)cout << "-1\n";
    else cout << mn << endl;

    ret 0;
}
