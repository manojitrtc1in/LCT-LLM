


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <chrono>

    #pragma GCC optimize("O3")
    #pragma GCC optimize("Ofast")
    #pragma GCC optimize("unroll-loops")
    

using namespace std;
using namespace __gnu_pbds;



typedef int ll;
typedef long double ld;
ll MAX = 1e18;

double PI = 3.141592653589793238463;


typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


vector<string> nums;
vector<vector<ll>> h;
vector<ll> p;
ll md=1e9+7;

ll get_hash(ll i, ll x, ll len){
    if(len<=x){
        return h[i][len-1]*31;
    }
    if(x==0){
        return h[i][len]-h[i][x];
    }
    else {
        return h[i][x-1]*31+h[i][len]-h[i][x];
    }
}
char get_c(ll i, ll x, ll idx){
    if(idx<x){
        return nums[i][idx];
    }
    if(idx+1 < nums[i].size()) return nums[i][idx+1];
    return '$';
}

bool check(ll i, ll x, ll j, ll y){
    ll len1 = nums[i].size(), len2 = nums[j].size();
    if(x!=len1) len1--;
    if(y!=len2) len2--;
    ll l=1, r=min(len1, len2);
    ll common=0;
    while(l<=r){
        ll m = (l+r)/2;
        if(get_hash(i, x, m)==get_hash(j, y, m)){
            common=max(common, m);
            l=m+1;
        }
        else {
            r=m-1;
        }
    }



    

    return get_c(i, x, common) < get_c(j, y, common);
}

bool check2(ll i, ll x, ll j, ll y){
    ll len1 = nums[i].size(), len2 = nums[j].size();
    if(x!=len1) len1--;
    if(y!=len2) len2--;
    ll l=1, r=min(len1, len2);
    ll common=0;
    while(l<=r){
        ll m = (l+r)/2;
        if(get_hash(i, x, m)==get_hash(j, y, m)){
            common=max(common, m);
            l=m+1;
        }
        else {
            r=m-1;
        }
    }

    

    return get_c(i, x, common) >= get_c(j, y, common);
}


ll basis;
bool cmpIDX(ll i, ll j){
    return check(basis, i, basis, j);
}


void solve(){
    mt19937_64 gen;

    p.resize(1e6+10);
    p[0]=1;
    for(ll i=1; i<1e6+10; i++){
        p[i]=p[i-1]*31;
    }

    ll n;
    cin >> n;
    nums.resize(n); h.resize(n);
    for(ll i=0; i<n; i++){
        cin >> nums[i];
        h[i].resize(nums[i].size());
        for(ll j=0; j<nums[i].size(); j++){
            if(j!=0) h[i][j]+=h[i][j-1];
            h[i][j]+=nums[i][j]*p[j];
        }
    }
    vector<vector<ll>> dp(n);
    dp[0].resize(nums[0].size()+1, 1);

    vector<ll> next1(nums[0].size());
    next1[nums[0].size()-1]=-1;
    for(ll j=(ll)nums[0].size()-2; j>=0; j--){
        if(nums[0][j]==nums[0][j+1]){
            next1[j] = next1[j+1];
        }
        else {
            next1[j] = j+1;
        }
    }
    vector<ll> idx(nums[0].size()+1);
    ll beg=0, en=nums[0].size();
    bool last=false;
    for(ll j=0; j<nums[0].size(); j++){
        ll id = next1[j];
        if( id==-1 && !last){
            idx[beg++]=nums[0].size();
            last=true;
        }
        if(id==-1){
            idx[beg++]=j;
        }
        else if(nums[0][j]>nums[0][id]){
            

            idx[en--]=j;
        }
        else {
            

            idx[beg++]=j;
        }

    }


    

    for(ll i=1; i<n; i++){
        dp[i].resize(nums[i].size()+1, 0);

        

        
        vector<ll> sum(idx.size(), 0);
        for(ll j=(ll)idx.size()-1; j>=0; j--){
            sum[j]+=dp[i-1][idx[j]];
            if(j!=(ll)idx.size()-1) sum[j]+=sum[j+1];
            

            if(sum[j]>=md) sum[j]-=md;
        }

        vector<ll> new_idx(nums[i].size()+1);
        vector<ll> next(nums[i].size());
        next[nums[i].size()-1]=-1;
        for(ll j=(ll)nums[i].size()-2; j>=0; j--){
            if(nums[i][j]==nums[i][j+1]){
                next[j] = next[j+1];
            }
            else {
                next[j] = j+1;
            }
        }
        beg=0; en=nums[i].size();
        last=false;
        for(ll j=0; j<nums[i].size(); j++){
            ll id = next[j];
            if( id==-1 && !last){
                new_idx[beg++]=nums[i].size();
                last=true;
            }
            if(id==-1){
                new_idx[beg++]=j;
            }
            else if(nums[i][j]>nums[i][id]){
                

                new_idx[en--]=j;
            }
            else {
                

                new_idx[beg++]=j;
            }

        }

        
        


        


        ll cur=0;
        for(auto j : new_idx){
            ll toadd=0;
            while(true){
                if(cur==idx.size()) break;
                if(check2(i, j, i-1, idx[cur])){

                    


                    toadd+=sum[cur];
                    break;
                }
                else {
                    cur++;
                }
            }
            dp[i][j]+=toadd;
            

            if(dp[i][j]>=md) dp[i][j]-=md;
        }
        idx=new_idx;
    }
    ll ans=0;
    for(auto j : dp[n-1]){
        ans+=j;
        

        if(ans>=md) ans-=md;
    }
    cout << ans;




}


void gentest(){
    freopen("input.txt", "w", stdout);

    cout << 2 << "\n";
    mt19937_64 gen;
    string s1="", s2="";
    for(ll i=0; i<20000; i++){
        s1+='a';
    }
    s2+='a';
    cout << s1 << "\n" << s2;

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    

    ll t=1;
    

    while(t--){
        solve();
    }


    return 0;
}
