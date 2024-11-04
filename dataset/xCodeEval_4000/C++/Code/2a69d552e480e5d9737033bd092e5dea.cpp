#include<bits/stdc++.h>
#include <iostream>
#include <cctype>
using namespace std;
using ll = long long;
const int N = 100005;
const int inf = 1e9+10;
const int mod = 32768;
using vi = vector<int>; 
using vb = vector<bool>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvb = vector<vb>;
#define pb push_back


































































    




 vector<int>par1,par2;
int find_par(int node,vector<int>&parent){
    if(parent[node] == node)return parent[node];
        

        

    return parent[node] = find_par(parent[node],parent);
}
void Union(int u,int v,vector<int>&parent){
    int pu = find_par(u,parent);
    int pv = find_par(v,parent);
        
    

    

    

    

    

    if(pu!=pv)parent[v] = u;
    

    

} 






    
























    


  








        
























        






















 


























































































































































 

























































































    




































































































































































     




     






         






             




         













































































































































    
















 






















 




ll squ(ll num)
{
    if (num < 0) num = -num;
    ll result = 0, times = num;
 
    while (times > 0)
    {
        ll po = 0, currTimes = 1;
 
        while ((currTimes << 1) <= times)
        {
            currTimes = currTimes << 1;
            ++po;
        }
 
        result = result + (1LL *num << po);
        times = times - currTimes;
    }
    return 1LL*result;
}


























        























   












































void solve(){
    ll n,k;
    cin>>n>>k;
  string s;
  cin>>s;
    vector<string>ans,ans1;
    for(int i=0;i<n;i++){
      string x = s.substr(0,i+1);
      ans1.push_back(x);
    }
  for(int i=0;i<ans1.size();i++){
    string x = ans1[i];
    while(x.size()<k){
      x+=x;
    }
    x=x.substr(0,k);
    ans.push_back(x);
  }
  sort(ans.begin(),ans.end());
  cout<<ans[0]<<endl;
}
struct cmp{
bool operator()(pair<int,int>&p1,pair<int,int>&p2){
    if(p1.second == p2.second)
      return p1.first > p2.first;
    else
      return p1.first < p2.first;
  }
};
int ceil(int a, int b) {
   return (a+b-1)/b;
}
bool comp(pair<ll,ll>&p1,pair<ll,ll>&p2){
  return p1.second < p2.second;
}
ll pre[N];
int a,b;
int main()
{
  ll t = 1;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;
    ll a[n];
    for(int i =0;i<n;i++)cin>>a[i];
    int i = 0;
    int j = n-1;
    ll sum1=0;
    ll ans = 0;
    ll sum2=0;
    int count1 = 0,count2=0;
    while(i<=j){
      if(sum1<=sum2){
        sum1+=a[i];
        i++;
        count1++;
      }
      else{
        sum2+=a[j];
        j--;
        count2++;
      }
      if(sum1==sum2)ans=count1+count2;
    }
    count1+=count2;
    cout<<ans<<endl;
  }
}

  