




using namespace std;















































 
  
ll dist(ll x1,ll y1,ll x2,ll y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

void solve()
{
    ll n;
    cin>>n;
    ll x[n],y[n];
    for(ll i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }

    ll i=0;
    vi ans;
    vector<ll>vis(n);
    ll cnt=0;
    while(cnt<n)
    {
        ans.pb(i+1);
        vis[i]=1;
        ll id=-1,d=0;
        for(ll j=0;j<n;j++)
        {
            ll dd=dist(x[i],y[i],x[j],y[j]);
            if(!vis[j] and d<dd)
            {
                d=dd;
                id=j;
            }
        }
        if(id==-1)
            break;
        i=id;
        vis[id]=1;
        cnt++;
    }


    for(ll x:ans)
        cout<<x<<" ";

    return ;
}
  
int main() 
{ 
   

   FAST;
   

   ll t;
   t=1;
   

   while(t--)
   solve();
   return 0;
}
