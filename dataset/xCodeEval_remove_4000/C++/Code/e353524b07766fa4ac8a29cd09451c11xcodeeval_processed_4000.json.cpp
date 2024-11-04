




using namespace std;

















































const ll N=200005;
ll BITree[N];
ll n;
ll getSum(ll index)
{
    ll sum = 0; 

    
    

    while (index > 0)
    {
        
        

        sum += BITree[index];

        

        index -= (index & (-index));
    }
    return sum;
}

void updateBIT(ll index, ll val)
{
    

    
    while (index <= n)
    {
        
    

    BITree[index] += val;

    

    index += (index & (-index));
    }
}
void solve()
{
    
    ll t,k;
    cin>>n>>t;
   
    map<ll,ll>mp;
    while(t--)
    {  
         
        ll ans=-1;
        ll l=1,r=n;
    
        cin>>k;
        while(l<=r)
        {
            ll cnt0;
            ll mid=(l+r)/2;
            if(mp.find(mid)!=mp.end())
            {
                ll y=mp[mid]+getSum(mid);
                cnt0=mid-y;
            }
            else
            {
                cout<<"? "<<1<<" "<<mid<<endl;
                cout.flush();
                ll x;
                cin>>x;
                mp[mid]=x-getSum(mid);
                cnt0=mid-x;
                
            }
            
            if(cnt0>=k)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        cout<<"! "<<ans<<endl;
        cout.flush();
        updateBIT(ans,1);
        
    }
    return ;
}
  
int main() 
{ 
   

   

   

   ll t;
   t=1;
   

   while(t--)
   solve();
   return 0;
}
