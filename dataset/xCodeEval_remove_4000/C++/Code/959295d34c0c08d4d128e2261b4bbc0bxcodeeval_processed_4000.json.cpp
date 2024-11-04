




using namespace std;




















































 

void solve()
{
    ll n,m;
    cin>>n>>m;
    ll a[n],b[n],c[m];
    vector<ll>req[n+1];

    fr(n)   
    cin>>a[i];
    fr(n)  
    { 
        cin>>b[i]; 
        if(b[i]!=a[i])
         req[b[i]].pb(i+1);
    }
    fr(m)  
    { 
        cin>>c[i]; 
    }

        ll last=-1;
        if(req[c[m-1]].size()>0)
        {
            last=req[c[m-1]].back();
            req[c[m-1]].pop_back();
        }
        else
        {
            for(ll i=0;i<n;i++)
            {
                if(b[i]==c[m-1])
                {
                    last=i+1;
                    break;
                }
            }
        }
        if(last==-1)
        {
            cout<<"NO"<<endl;
            return;
        }
        
            
        vi ans;
        for(ll i=0;i<m-1;i++)
        {
            if(req[c[i]].size()==0)
            {
                ans.pb(last);
            }
            else
            {
                ans.pb(req[c[i]].back());
                req[c[i]].pop_back();
            }
        }
        ans.pb(last);

        for(ll i=1;i<=n;i++)
        {
            if(req[i].size()>0)
            {
                cout<<"NO"<<endl;
                return ;
            }
        }
        cout<<"YES"<<endl;
        for(ll x:ans)
            cout<<x<<" ";
        cout<<endl;

        
    
} 

  
int main() 
{ 
   

   FAST;
   

   ll t;
   t=1;
   cin>>t;  
   while(t--)
   solve();
   return 0;
}























