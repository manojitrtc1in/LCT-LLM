















































































































































































































































































































































































































































































































































































































































































#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
ll mod = ll(1e9+7);
 
#define MAXN   500001
#define ll_MAX 500000000011
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;








 
vector<ll> prllNGE(ll arr[], ll n)
{
    stack<ll> s;
    vector<ll> pos(n,n);
    s.push(0);
    for (ll i = 1; i < n; i++) 
    {
        if (s.empty()) {
            s.push(i);
            continue;
        }
        while (s.empty() == false 
               && arr[s.top()] < arr[i]) 
        {
            pos[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    return pos;
}
 
vector<ll> prllNLE(ll arr[], ll n)
{
    stack<ll> s;
    vector<ll> pos(n,n);
    s.push(0);
    for (ll i = 1; i < n; i++) 
    {
        if (s.empty()) {
            s.push(i);
            continue;
        }
        while (s.empty() == false 
               && arr[s.top()] > arr[i]) 
        {
            pos[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    return pos;
}
 
vector<ll> getVectorFromString(string& s){
    ll n = s.length();
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        v[i]=s[i]-'a';
    }
    return v;
}
 
void solve(){
    ll n;
    cin>>n;
    indexed_set os;
    string x;
    cin>>x;
    vector<ll> s = getVectorFromString(x);
    cin>>x;
    vector<ll> t = getVectorFromString(x);
    vector<queue<ll>> places(26);
    for(ll i=0;i<n;i++){
        places[s[i]].push(i);
    }
    vector<bool> taken(n,false);
    ll ans = ll_MAX;
    ll cnt = 0;
    ll i1=0;
    for(ll i=0;i<n;i++){
        if(s[i1]==t[i]){
            taken[i1]=true;
            places[s[i1]].pop();
            ll i3 = ll_MAX;
            for(ll j=t[i]-1;j>=0;j--){
                if(!places[j].empty()){
                    ll p = places[j].front();
                    ll q = os.order_of_key(n+1)-os.order_of_key(p);
                    i3= min(i3,q+p);
                }
            }
            ans = min(ans,(i3!=ll_MAX ? i3-i+cnt:i3));
            i1++;
        }else if(s[i1]<t[i]){
            cout<<min(cnt,ans)<<endl;
            return ;
        }else{
            

            ll i3 = ll_MAX;
            for(ll j=t[i]-1;j>=0;j--){
                if(!places[j].empty()){
                    ll p = places[j].front();
                    ll q = os.order_of_key(n+1)-os.order_of_key(p);
                    i3= min(i3,q+p);
                }
            }
            ans = min(ans,(i3!=ll_MAX ? i3-i+cnt:i3));
            

            if(places[t[i]].empty()){
                if(ans==ll_MAX){
                    cout<<-1<<endl;
                    return;
                }else{
                    cout<<ans<<endl;
                    return;
                }
            }
            

            ll i11 = places[t[i]].front();
            ll ac = i11+os.order_of_key(n+1)-os.order_of_key(i11);
            cnt+= ac-i;
            taken[i11]=true;
            os.insert(i11);
            places[s[i11]].pop();
        }
        while(i1<n && taken[i1]){
            i1++;
        }
    }
    if(ans==ll_MAX){
        cout<<-1<<endl;
        return;
    }
    cout<<ans<<endl;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    

    cin>>t;
    for(int i=0;i<t;i++){
        solve();
    }
}