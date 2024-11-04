#include<bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;


#define double long double


#define mod 998244353
# define pi 3.14159265358979323846 














































































































































 






















 










 




























































 
















































 

 
#define int long long
void solve(){
   int n;cin>>n;
   vector<int>v(n+1);
   for(int i=1;i<=n;i++){
    cin>>v[i];
   }
   vector<int>dp(n+2);
   dp[0]=0;
   if(v[1]!=0)dp[1]=1;
   else dp[1]=0;
   for(int i=2;i<=n;i++){
    int s=0;
    dp[i]=dp[i-1]+1;
    for(int j=i;j>=0;j--){
        s=s^v[j];
        if(s==0){
            dp[i]=min(dp[i],dp[j-1]+i-j);
        }
    }
   }
   cout<<dp[n]<<endl;
}
    


int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    

    while(t--){
        solve();
    }
    

}










