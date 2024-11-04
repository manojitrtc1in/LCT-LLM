#include <bits/stdc++.h>
#define ll long long
#define el '\n'
#define pi 3.1415926536
#include <sstream>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;
int prime_factor(int number)
{
    int count = 0;
    for (int i = 2; i * i <= number; i++)
    {
        while (number % i == 0)
        {
            count++;
            number /= i;
        }
    }
    if (number != 1)
        count++;
    return count;
}







ll const N=2e5+5;
ll a[N],b[N];
set<ll>v,test,test2;
vector<pair<ll,ll>>adj[N];
map<ll,ll>mp;
bool vis[N];


int main() {
    fast;
    ll n,q,s=0;cin>>n>>q;
        map<ll,bool>mp;
        map<ll,ll>mp2;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
        mp[i]=0;mp2[i]=a[i];
    }
    ll s2=s, changvalue=0;
    bool f=1;
    while(q--){
        ll t;cin>>t;
        if(t==2){
            ll x;cin>>x;
            cout<<x*n<<el;
            s2=x*n;
             changvalue=x;
             f=0;
             mp.clear();
        }
        else{
            ll pos,x;cin>>pos>>x;
                if(changvalue!=0) {

                if(mp[pos-1]==0){
                    s2+=x-changvalue;
                    mp[pos-1]=1;mp2[pos-1]=x;
                }

               else if (mp[pos - 1] == 1) {
                    s2+=x-mp2[pos-1];
                    mp2[pos-1]=x;mp[pos-1]=1;
                }
            }
                else{
                    s2+=x-mp2[pos-1];
                    mp[pos-1]=1;
                    mp2[pos-1]=x;
                }
            cout<<s2<<el;
        }
    }


}