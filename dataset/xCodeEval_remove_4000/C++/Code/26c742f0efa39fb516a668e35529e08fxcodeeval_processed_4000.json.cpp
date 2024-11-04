

using namespace std;


 





 
ll bs(ll a[],ll n,ll x)
{
    ll l=0,r=n-1;
    while(l<=r)
    {
        ll m=(l+r)/2;
        if(a[m]==x)
        return m;
        else if(a[m]>x)
        r=m-1;
        else
        l=m+1;
    }
    return -1;
}
ll bsre(ll a[],ll n,ll l,ll r,ll x)
{
    if(l>r) return -1;
    ll m=(l+r)/2;
    if(a[m]==x) return m;
    else if(a[m]>x) return bsre(a,n,l,m-1,x);
    else return bsre(a,n,m+1,r,x);
}
bool ip(ll n)
{
    if(n==0||n==1) return false;
    if(n==2||n==3) return true;
    if(n%2==0||n%3==0) return false;
    for(ll i=5;i*i<=n;i+=6)
    {
        if(n%i==0||n%(i+2)==0)
        return false;
    }
    return true;
}
void sieve(ll n)
{
    bool p[n+1];
    for(ll i=0;i<n;++i)
    {
        if(i%2==0||i%3==0)
        p[i]=false;
        else
        p[i]=true;
    }
    p[1]=false;
    p[2]=true;
    p[3]=p[2];
    for(ll i=5;i*i<=n;i+=6)
    {
        if(p[i])
        {
            for(ll j=i*i;j<=n;j+=2*i)
            {
                p[j]=false;
            }
        }
    }
    ll c=0;
    for(ll i=0;i<=n;++i)
    {
        if(p[i])
        {
            cout<<i<<" ";
            c++;
        }
    }
    cout<<endl;
    

 
}
ll maxkad(ll a[],ll n)
{
    ll s=a[0],b=a[0];
    for(ll i=1;i<n;++i)
    {
        s=max(s+a[i],a[i]);
        b=max(s,b);
    }
    return b;
}
int main()
{
    ll t=1;
    cin>>t;
    

    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;++i)
        a[i]=i+1;
        ll i=n-1,j=n-3;
        cout<<2<<endl;
        if(n==2)
        {
            cout<<1<<" "<<2<<endl;
        }
        else
        {
            while(i>0)
            {
                if(i==j) j--;
                cout<<a[j]<<" "<<a[i]<<endl;
                a[j]=(a[j]+a[i])/2;
                
                i--;
            }
        }
    }
    return 0;
}