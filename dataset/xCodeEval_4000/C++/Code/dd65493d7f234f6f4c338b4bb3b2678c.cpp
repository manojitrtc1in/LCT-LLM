#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>
#include <chrono>
using namespace __gnu_pbds; 
using namespace std;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace chrono;
#define ll long long int
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define MOD1 998244353
#define inf 1e17
#define neginf -1e17
#define sp(y, x) fixed << setprecision(x) << y
#define all(x) x.begin(), x.end()
#define power(a, b) (double)pow((double)a, (double)b)
#define gcd(a, b) __gcd(a, b)
#define PI 3.1415926535
#define ss second
#define ff first
#define umap unordered_map
#define ummap unordered_multimap
#define uset unordered_set
#define umset unordered_multiset


ll powerm(ll a,unsigned long long int b,ll mod)  
{  
    ll ans = 1;   
    a = a % mod; 
    if (a == 0) return 0; 
    while (b > 0)  
    {  
        if (b & 1)  
        ans = (ans*a) % mod;  
        b = b>>1;  
        a = (a*a)%mod;  
    }  
    return ans;  
}
ll lcm(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}


void buildseg(ll arr[],ll le,ll ri,ll idx,ll arr1[])
{
    if(le==ri)
    {
        arr[idx]=arr1[le];
        return;
    }
    else
    {
        ll mid=le+(ri-le)/2;
        buildseg(arr,le,mid,2*idx+1,arr1);
        buildseg(arr,mid+1,ri,2*idx+2,arr1);
        arr[idx]=arr[2*idx+1]+arr[2*idx+2];
        return;
    }
}
ll rangesum(ll arr[],ll l1,ll r1,ll l2,ll r2,ll idx)
{
    

    if(l1<=l2&&r1>=r2)
    return arr[idx];
    

    if(l1>r2||r1<l2)
    return 0;
    ll mid=(l2+r2)/2;
    return (rangesum(arr,l1,r1,l2,mid,2*idx+1)+rangesum(arr,l1,r1,mid+1,r2,2*idx+2));
}
void update(ll arr[],ll le,ll re,ll idx,ll idx1,ll arr1[],ll val)
{
    if(idx1<le||idx1>re)
    return;
    if(le==re)
    {
        arr1[le]=val;
        arr[idx]=val;
        return;
    }
    else
    {
        ll mid=(le+re)/2;
        if(idx1<=mid)
        {
            update(arr,le,mid,2*idx+1,idx1,arr1,val);
        }
        else
        {
            update(arr,mid+1,re,2*idx+2,idx1,arr1,val);
        }
        arr[idx]=arr[2*idx+1]+arr[2*idx+2];
        return;
        
    }
    
}




ll ask(ll a,ll b,ll c)
{
    cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
    ll n;
    cin>>n;
    return n;
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t;
    t=1;
    cin>>t;
    

    

    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>imp,crew;
        for(ll i=1;i<=n;i+=3)
        {
            ll ans=ask(i,i+1,i+2);
            if(ans==0)
            {
                imp.pb(i);
            }
            else
            crew.pb(i);
        }
        

        vector<ll>final;
        vector<ll>crew1;
        ll ind1=imp[0];

        ll ind2=crew[0];

        ll hash[n+1];

        ll hash1[n+1];

        for(ll i=0;i<=n;i++)
        {
            hash[i]=0;
            hash1[i]=0;
        }
        for(ll i=ind1;i<ind1+2;i++)
        {
            ll ans=ask(i,ind2,ind2+1);
            ll ans1=ask(i,ind2,ind2+2);
            ll ans2=ask(i,ind2+1,ind2+2);
            if(ans==0&&ans1==0)
            {
                hash1[i]++;
                hash1[ind2]++;
                hash[ind2+1]++;
                hash[ind2+2]++;
                final.pb(i);
                final.pb(ind2);
                crew1.pb(ind2+1);
                crew1.pb(ind2+2);
                break;
            }
            else if(ans==0&&ans2==0)
            {
                hash1[i]++;
                hash1[ind2+1]++;
                hash[ind2]++;
                hash[ind2+2]++;
                final.pb(i);
                final.pb(ind2+1);
                crew1.pb(ind2);
                crew1.pb(ind2+2);
                break;
            }
            else if(ans1==0&&ans2==0)
            {
                hash1[i]++;
                hash1[ind2+2]++;
                hash[ind2+1]++;
                hash[ind2]++;
                final.pb(i);
                final.pb(ind2+2);
                crew1.pb(ind2+1);
                crew1.pb(ind2);
                break;
            }
        }
        if((ll)(final.size())==0)
        {
            

            if(n==6)
            {
                cout<<"! "<<3<<" "<<imp[0]<<" "<<imp[0]+1<<" "<<imp[0]+2<<endl;
                continue;
            }
            else if(n==9)
            {
                

                

                

                

                

                

                if((ll)(crew.size())==1)
                {
                    

                    ll crew2=crew[0];
                for(ll i=0;i<imp.size();i++)
                {
                    ll ans1=ask(imp[i],imp[i]+1,crew2);
                    ll ans2=ask(imp[i],imp[i]+2,crew2);
                    ll ans3=ask(imp[i]+1,imp[i]+2,crew2);
                    if(ans1==0)
                    {
                        hash1[imp[i]]++;
                        hash1[imp[i]+1]++;
                        final.pb(imp[i]);
                        final.pb(imp[i]+1);
                    }
                    if(ans2==0)
                    {
                        hash1[imp[i]]++;
                        hash1[imp[i]+2]++;
                        final.pb(imp[i]);
                        final.pb(imp[i]+2);
                    }
                    if(ans3==0)
                    {
                        hash1[imp[i]+2]++;
                        hash1[imp[i]+1]++;
                        final.pb(imp[i]+2);
                        final.pb(imp[i]+1);
                    }
                }
                cout<<"!";
                ll cnt=0;
                for(ll i=1;i<=n;i++)
                if(hash1[i]>0)
                cnt++;
                cout<<" "<<cnt;
                for(ll i=1;i<=n;i++)
                if(hash1[i]>0)
                cout<<" "<<i;
                cout<<endl;
                continue;
                
                }
                else
                {
                    

                    hash1[imp[0]]++;
                    hash1[imp[0]+1]++;
                    hash1[imp[0]+2]++;
                    final.pb(imp[0]);
                    final.pb(imp[0]+1);
                    final.pb(imp[0]+2);
                    ll crew2=crew[0];
                    ll ans1=ask(final[0],crew2,crew[1]);
                    if(ans1==0)
                    {
                        cout<<"! "<<4<<" "<<final[0]<<" "<<final[1]<<" "<<final[2]<<" "<<crew[1]<<endl;
                        continue;
                    }
                    ll ans2=ask(final[0],crew2,crew[1]+1);
                    if(ans2==0)
                    {
                        cout<<"! "<<4<<" "<<final[0]<<" "<<final[1]<<" "<<final[2]<<" "<<crew[1]+1<<endl;
                        continue;
                    }
                    ll ans3=ask(final[0],crew2,crew[1]+2);
                    if(ans3==0)
                    {
                        cout<<"! "<<4<<" "<<final[0]<<" "<<final[1]<<" "<<final[2]<<" "<<crew[1]+2<<endl;
                        continue;
                    }
                }
            }
            else
            {
            crew1.pb(crew[0]);
            crew1.pb(crew[0]+1);
            crew1.pb(crew[0]+2);
            hash[crew[0]]++;
            hash[crew[0]+1]++;
            hash[crew[0]+2]++;
                ll crew2=crew[0];
                
                for(ll i=0;i<imp.size();i++)
                {
                    ll ans1=ask(crew2,imp[i],imp[i]+1);
                    ll ans2=ask(crew2,imp[i]+1,imp[i]+2);
                    if(ans1==0&&ans2==0)
                    {
                        final.pb(imp[i]);
                        final.pb(imp[i]+1);
                        final.pb(imp[i]+2);
                        hash1[imp[i]]++;
                        hash1[imp[i]+1]++;
                        hash1[imp[i]+2]++;
                    }
                    else if(ans1==0)
                    {
                        final.pb(imp[i]);
                        final.pb(imp[i]+1);
                        

                        hash1[imp[i]]++;
                        hash1[imp[i]+1]++;
                        

                    }
                    else if(ans2==0)
                    {
                        

                        final.pb(imp[i]+1);
                        final.pb(imp[i]+2);
                       

                        hash1[imp[i]+1]++;
                        hash1[imp[i]+2]++;
                    }
                    else
                    {
                        final.pb(imp[i]);
                        

                        final.pb(imp[i]+2);
                        hash1[imp[i]]++;
                        

                        hash1[imp[i]+2]++;
                    }
                }
                ll impo=final[0];
                for(ll i=1;i<crew.size();i++)
                {
                    ll ans1=ask(impo,crew[i],crew[i]+1);
                    ll ans2=ask(impo,crew[i]+1,crew[i]+2);
                    if(ans1==1&&ans2==1)
                    {
                        crew1.pb(crew[i]);
                    }
                    else if(ans1==1)
                    {
                        final.pb(crew[i]+2);
                        hash1[crew[i]+2]++;
                    }
                    else if(ans2==1)
                    {
                        final.pb(crew[i]);
                        hash1[crew[i]]++;
                    }
                    else
                    {
                        final.pb(crew[i]+1);
                        hash1[crew[i]+1]++;
                    }
                }
                cout<<"!";
                ll cnt=0;
                for(ll i=1;i<=n;i++)
                if(hash1[i]>0)
                cnt++;
                cout<<" "<<cnt;
                for(ll i=1;i<=n;i++)
                if(hash1[i]>0)
                cout<<" "<<i;
                cout<<endl;
                continue;
            }
        }
        else
        {
            ll crew2=crew1[0];
            if(n==6)
            {
                if(hash1[imp[0]]==0)
                {
                    if(ask(imp[0],crew1[0],final[0])==0)
                    {
                        cout<<"! "<<3<<" "<<imp[0]<<" "<<final[0]<<" "<<final[1]<<endl;
                        continue;
                    }
                }
                if(hash1[imp[0]+1]==0)
                {
                    if(ask(imp[0]+1,crew1[0],final[0])==0)
                    {
                        cout<<"! "<<3<<" "<<imp[0]+1<<" "<<final[0]<<" "<<final[1]<<endl;
                        continue;
                    }
                }
                cout<<"! "<<3<<" "<<imp[0]+2<<" "<<final[0]<<" "<<final[1]<<endl;
                continue;
            }
            else if(n==9)
            {
                ll impo=final[0];
                ll crew2=crew1[0];
                for(ll i=0;i<imp.size();i++)
                {
                    if(hash1[imp[i]]==0&&ask(imp[i],impo,crew2)==0)
                    {
                        hash1[imp[i]]++;
                    }
                    if(hash1[imp[i]+1]==0&&ask(imp[i]+1,impo,crew2)==0)
                    hash1[imp[i]+1]++;
                    if(hash1[imp[i]+2]==0&&ask(imp[i]+2,impo,crew2)==0)
                    hash1[imp[i]+2]++;
                }
                for(ll i=1;i<crew.size();i++)
                {
                    if(hash1[crew[i]]==0&&ask(crew[i],impo,crew2)==0)
                    {
                        hash1[crew[i]]++;
                    }
                    if(hash1[crew[i]+1]==0&&ask(crew[i]+1,impo,crew2)==0)
                    hash1[crew[i]+1]++;
                    if(hash1[crew[i]+2]==0&&ask(crew[i]+2,impo,crew2)==0)
                    hash1[crew[i]+2]++;
                }
                cout<<"!";
                ll cnt=0;
                for(ll i=1;i<=n;i++)
                if(hash1[i]>0)
                cnt++;
                cout<<" "<<cnt;
                for(ll i=1;i<=n;i++)
                if(hash1[i]>0)
                cout<<" "<<i;
                cout<<endl;
                continue;
            }
            else
            {
            
                for(ll i=0;i<imp.size();i++)
                {
                    ll ans1=ask(crew2,imp[i],imp[i]+1);
                    ll ans2=ask(crew2,imp[i]+1,imp[i]+2);
                    if(ans1==0&&ans2==0)
                    {
                        final.pb(imp[i]);
                        final.pb(imp[i]+1);
                        final.pb(imp[i]+2);
                        hash1[imp[i]]++;
                        hash1[imp[i]+1]++;
                        hash1[imp[i]+2]++;
                    }
                    else if(ans1==0)
                    {
                        final.pb(imp[i]);
                        final.pb(imp[i]+1);
                        

                        hash1[imp[i]]++;
                        hash1[imp[i]+1]++;
                        

                    }
                    else if(ans2==0)
                    {
                        

                        final.pb(imp[i]+1);
                        final.pb(imp[i]+2);
                       

                        hash1[imp[i]+1]++;
                        hash1[imp[i]+2]++;
                    }
                    else
                    {
                        final.pb(imp[i]);
                        

                        final.pb(imp[i]+2);
                        hash1[imp[i]]++;
                        

                        hash1[imp[i]+2]++;
                    }
                }
                ll impo=final[0];
                for(ll i=0;i<crew.size();i++)
                {
                    ll ans1=ask(impo,crew[i],crew[i]+1);
                    ll ans2=ask(impo,crew[i]+1,crew[i]+2);
                    if(ans1==1&&ans2==1)
                    {
                        crew1.pb(crew[i]);
                    }
                    else if(ans1==1)
                    {
                        final.pb(crew[i]+2);
                        hash1[crew[i]+2]++;
                    }
                    else if(ans2==1)
                    {
                        final.pb(crew[i]);
                        hash1[crew[i]]++;
                    }
                    else
                    {
                        final.pb(crew[i]+1);
                        hash1[crew[i]+1]++;
                    }
                }
                cout<<"!";
                ll cnt=0;
                for(ll i=1;i<=n;i++)
                if(hash1[i]>0)
                cnt++;
                cout<<" "<<cnt;
                for(ll i=1;i<=n;i++)
                if(hash1[i]>0)
                cout<<" "<<i;
                cout<<endl;
                continue;
            }
        }
    }
    return 0;
}