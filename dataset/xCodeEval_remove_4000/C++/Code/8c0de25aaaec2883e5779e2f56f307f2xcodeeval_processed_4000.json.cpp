

using namespace std;


 





ll cb(ll n)
{
    ll res=0;
    while(n)
    {
        n=(n&(n-1));
        res++;
    }
    return res;
}
ll cf(ll a[],ll k,ll n,ll m)
{
    ll c=0,t=a[m],ans=0;
    for(ll i=0;i<m;++i)
    {
        if(cb(a[i]^t)<=k)
        ans++;
    }        
    return ans;
}
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    ll a[m+1];
    for(ll i=0;i<=m;++i)
    {
        cin>>a[i];
    }
    ll p=cf(a,k,n,m);
    cout<<p;
    
}