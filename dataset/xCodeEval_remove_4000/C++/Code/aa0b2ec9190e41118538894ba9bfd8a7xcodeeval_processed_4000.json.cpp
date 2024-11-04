

using namespace std;


 




int main()
{
    ll t=1;
    

    while(t--)
    {
        ll n,m=0,sum=0;
        cin>>n;
        vector<ll>q(n-1);
        for(ll i=0;i<n-1;++i)
        {
            cin>>q[i];
            sum+=q[i];
            m=min(m,sum);
        }
        vector<ll>p(n);
        p[0]=1-m;
        bool ok=true;
        unordered_set<ll>s;
        s.insert(p[0]);
        if(p[0]<1||p[0]>n) ok=false;
        if (ok)
        {
            for(ll i=1;i<n;++i)
            {
                p[i]=p[i-1]+q[i-1];
                if(!s.count(p[i])&&p[i]>=1&&p[i]<=n)
                {
                    s.insert(p[i]);
                }
                else
                {
                    ok=false;
                    break;
                }
            }        
        }
        if(ok)
        {
            for(ll i=0;i<n;++i)
            cout<<p[i]<<" ";
        }
        else
        cout<<-1;



    }
}
