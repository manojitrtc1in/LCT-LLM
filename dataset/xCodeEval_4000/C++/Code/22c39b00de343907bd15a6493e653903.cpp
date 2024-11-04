





#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
#define endl "\n"
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define all(v) (v).begin(),(v).end()
#define im_Fast_af_Boii ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long int
#define vi vector<long long int>
#define vpi vector<pair<int,int>>
#define vvi vector<vector<int>>
#define mii map<int,int>


#ifdef ONPC
    #include "debug.h"
#else
    #define deb(...)
#endif

ll query(ll l,ll r){
    cout<<"? "<<l<<" "<<r<<endl;
    ll v;
    cin>>v;
    return v;
}

int countDigit(long long n) {
  return floor(log10(n) + 1);
}

int findSubarraySum(int arr[], int n, int sum)
{
    unordered_map<int, int> prevSum;
 
    int res = 0;
    int currSum = 0;
    for (int i = 0; i < n; i++) {
        currSum += arr[i];
        if (currSum == sum)
            res++;
        if (prevSum.find(currSum - sum) != prevSum.end())
            res += (prevSum[currSum - sum]);
        prevSum[currSum]++;
    }
 
    return res;
}

vector<ll> prefixSum(vector<ll> a,ll n){
    vector<ll> pre(n+1,0);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i-1];
    }
    return pre;
}

long long ncr(int n, int r) {
    if(r>n){
        return 0;
    }
    if(r > n - r) r = n - r; 

    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}
set<ll> cubes;

void solve(){
    ll n;
    cin>>n;
    

    

    

    for(ll it:cubes){
        

        if(it<=n){
            if(cubes.find(n-it)!=cubes.end()){
                yes;
                return;
            }
        }
        

            
        

    }no;

}


int main(){
    im_Fast_af_Boii;
    for(ll i=1;i<=10000;i++){
        cubes.insert(i*i*i);
    }
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}




