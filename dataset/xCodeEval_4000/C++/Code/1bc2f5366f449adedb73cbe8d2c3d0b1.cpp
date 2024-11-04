
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
 
#define G G
#define O O
#define K K
#define U U
int main()
{
    ll t=1;
    

    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        a[0]=0;
        ll k,s=0;
        for(ll i=1;i<n;++i)
        {
            cin>>k;
            a[i]=k+a[i-1];
            s+=a[i];            
        }
        

        k=((n*(n+1))/2)-s;
        if(k>=0&&k%n==0)
        {
            ll f=0;
            unordered_set<ll>s;            
            ll x=k/n;
            
            for(ll i=0;i<n;++i)
            {
                if(!s.count(x+a[i])&&x<=n&&x>=1)
                {
                    s.insert(x+a[i]);
                }   
                else
                {
                    f=1;
                    break;
                }             
            }
            if(!f)
            {
                for(ll i=0;i<n;++i)
                {
                    cout<<x+a[i]<<" ";
                }
            }
            else
            {
                cout<<-1;
            }
        }
        else
        cout<<-1;
        return 0;
 
    }
}