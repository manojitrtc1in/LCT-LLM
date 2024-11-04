
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<unordered_set>
#include<set>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<stack>
#include<queue>
#include<unordered_map>
#define ll long long int
using namespace std;
const int NN=100001;
const int mod=1000000007;
const int bhot_chhota=-1;
const int papa_prime=199999991;
vector<int> graph[1000000];
int height[1000000];
int visited[1000000];
int order[1000000];
int val[1000000];
int N;
int X,k=0;
int main(){
         ios_base::sync_with_stdio(false);
         cin.tie(0);
         cout.tie(0);
         ll t;
         cin>>t;
         while(t--){
             ll n,l,r;
             cin>>n>>l>>r;
             vector<ll>a(n);
             for(ll i=0;i<n;i++){
                 cin>>a[i];
             }
             ll ans=0;
            sort(a.begin(),a.end());
            vector<ll>::iterator x,y;
            for(ll i=0;i<n;i++){
                 x=lower_bound(a.begin(),a.begin()+i,l-a[i]);
                 y=upper_bound(a.begin(),a.begin()+i,r-a[i]);
                ans+=x-y;
            }
             cout<<abs(ans)<<"\n";
         }
  return 0;
}