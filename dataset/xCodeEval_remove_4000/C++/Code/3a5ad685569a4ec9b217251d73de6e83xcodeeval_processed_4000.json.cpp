





using namespace std;











const ll mod=1e9+7;

void yes()
{
    cout<<"YES"<<"\n";
}
void no()
{
    cout<<"NO"<<"\n";
}

bool com(ll a,ll b)
{
    return a>b;
}

void solve()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    if(n==2)
    {
        for(ll i=0; i<n; i++)
        {
            cout<<a[i]<<" ";
        }
        return;
    }
    else
    {
        ll x=1;
        for(ll i=2;i<n;i++)
        {
            if(a[i]-a[i-1]<a[x]-a[x-1])
                x=i;
        }
        for(ll i=x;i<n;i++)
            cout<<a[i]<<" ";
        for(ll i=0;i<x;i++)
            cout<<a[i]<<" ";
    }
    cout<<en;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
