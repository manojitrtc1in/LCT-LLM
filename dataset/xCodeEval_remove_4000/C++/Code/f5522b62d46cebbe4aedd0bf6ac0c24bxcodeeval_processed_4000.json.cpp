



























































































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
vd id0()
{
    if(pr.size()>0)ret;

    ll x=1e6;

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






















    srand(time(0));
    id0();

    ll n;
    cin >> n;

    vector<ll> v(n);
    for(ll i=0;i<n;i++)cin >> v[i];

    set<ll> st;

    sort(v.begin(),v.end());
    st.insert(2);

    ll i=n/2;
    while(i>=0 and st.size()*n<5e5)
    {
        ll a=v[i];
        vector<ll> fc=fact(a);
    

        for(ll j=0;j<fc.size();j++)st.insert(fc[j]);
    

        fc.clear();
        fc=fact(a+1);
        for(ll j=0;j<fc.size();j++)st.insert(fc[j]);
    

        fc.clear();
        fc=fact(a-1);
        for(ll j=0;j<fc.size();j++)st.insert(fc[j]);
         i--;
    }

    ll mn=1e18;
    vector<ll> ann;
    for(auto it=st.begin();it!=st.end();++it)ann.pb(*it);

    for(ll i=ann.size();i>=0;i--)
    {
        ll a=ann[i];
        if(a<=1)cont;


        ll ans=0;
        for(ll i=0;i<n;i++)
        {


            if(ans>=mn)break;

            if(v[i]>=a)ans+=min(v[i]%(a),(a-(v[i]%(a))%(a)));
            else ans+=(a-(v[i]%(a))%(a));
        }


         mn=min(ans,mn);
    }

    cout << mn << endl;

    ret 0;
}
