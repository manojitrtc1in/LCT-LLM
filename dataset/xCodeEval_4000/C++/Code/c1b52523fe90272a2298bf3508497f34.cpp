

























































#include <bits/stdc++.h>






















#define endl "\n"
#define amd and
#define vd void
#define pb push_back
#define f first
#define s second
#define ret return
#define cont continue
#define lcm(x,y) (x*y/__gcd(x,y))

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
    PrDoX(sqrt(1e9));

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








#ifdef NekoLover
    freopen("in.NekoLover","r",stdin);


#endif















    ll n;
    cin >> n;

    vector<ll> v1(n);

    for(ll i=0;i<n;i++)cin >> v1[i];

    ll m;
    cin >> m;

    vector<ll> v2(m);
    for(ll i=0;i<m;i++)cin >> v2[i];

    ll y1=0,y2=0,sum=0;
    vector<ll> ans={0};

    while(y2<m)
    {
        if(sum<v2[y2])
        {
            if(y1<n)sum+=v1[y1],y1++;
            else
            {
                cout << "NO\n";
                ret 0;
            }
        }
        else if(sum==v2[y2])ans.pb(y1),y2++,sum=0;
        else
        {
            cout << "NO\n";
            ret 0;
        }
    }

    if(ans[ans.size()-1]!=n)
    {
        cout << "NO\n";
        ret 0;
    }




    vector<pair<ll,ch> > out;
    ll k=0;

    reverse(ans.begin(),ans.end());

    for(ll i=0;i<ans.size()-1;i++)
    {
        ll r=ans[i]-1,l=ans[i+1],fl=0,mx=v1[l];

        if(r-l==0)cont;

        for(ll j=l+1;j<=r;j++)
        {
            if(v1[j]!=mx)fl=1;
            mx=max(mx,v1[j]);
        }

        if(fl==0)
        {
            cout << "NO\n";
            ret 0;
        }

        fl=0;
        for(ll j=l+1;j<=r;j++)
        {
            if(v1[j]==mx and v1[j]!=v1[j-1])
            {
                fl=-(j+1);
                break;
            }
        }

        for(ll j=l;j<r;j++)
        {
            if(v1[j]==mx and v1[j]!=v1[j+1])
            {
                fl=j+1;
                break;
            }
        }





        if(fl==0)
        {
            if(v1[l]>v1[r])out.pb({l+1,'R'});
            else if(v1[l]<v1[r])out.pb({r+1,'L'});
        }
        else
        {
            l++,r++;
            if(fl>0)
            {
                while(r!=fl)out.pb({fl,'R'}),r--;
                while(fl!=l)out.pb({fl,'L'}),fl--;
            }
            else
            {
                fl=abs(fl);
                while(fl!=l)out.pb({fl,'L'}),fl--,r--;
                while(r!=fl)out.pb({fl,'R'}),r--;
            }
        }

    }

    cout << "YES\n";
    for(ll i=0;i<out.size();i++)cout << out[i].f << " " << out[i].s << endl;





    ret 0;
}
