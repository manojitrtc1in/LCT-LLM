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
   vector<int>a(n),b(n);
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   for(int i=0;i<n;i++){
    cin>>b[i];
   }
   map<int,int>mp;
   for(int i=0;i<=29;i++){
    int b1=0,b2=0;
    for(int j=0;j<n;j++){
        if(((a[j]>>i)&1)==1){
            b1++;
        }
    }
    for(int j=0;j<n;j++){
        if(((b[j]>>i)&1)==0){
            b2++;
        }
    }
    if(b1==b2){
        mp[i]=1;
    }
   }
   vector<pair<int,int>>lr;
   lr.push_back({0,n-1});
   int ans=0;
    for(int i=29;i>=0;i--){
    if(mp[i]==0)continue;
        vector<pair<int,int>>tlr;
        int c1g=0;
        int c2g=0;
        int c3=0;
        int f=1;
    for(int k=0;k<lr.size();k++){
        int c1=0;
        int c2=0;
        for(int j=lr[k].first;j<=lr[k].second;j++){
            if(((a[j]>>i)&1)==1){
                c1++;
                c1g++;
            }
            if(((b[j]>>i)&1)==0){
                c2++;
                c2g++;
            }
        }
        if(c1==c2){
            c3++;
            int l=lr[k].first,r=lr[k].second,c=l;
            while(c<r){
                if(((a[c]>>i)&1)==0){
                    swap(a[c],a[r]);
                    r--;
                }else{
                     swap(a[c],a[l]);
                     l++;
                     c++;
                }
            }
            l=lr[k].first,r=lr[k].second,c=l;
            while(c<r){
                if(((b[c]>>i)&1)==1){
                    swap(b[c],b[r]);
                    r--;
                }else{
                     swap(b[c],b[l]);
                     l++;
                     c++;
                }
            }
            if(c1==lr[k].second-lr[k].first+1){
                    tlr.push_back({lr[k].first,lr[k].second});
            }else{
                tlr.push_back({lr[k].first,lr[k].first+c1-1});
            tlr.push_back({lr[k].first+c1,lr[k].second});

            }
            
        }else{
            f=0;
            break;
        }
    }
    
    if(f==1){
    lr.clear();
    for(int j=0;j<tlr.size();j++){
        lr.push_back(tlr[j]);
    }
    }
}

    
   
   ans=1073741823;
   
    for(int j=0;j<a.size();j++){
        int x=(a[j]^b[j]);
        ans=(ans&x);
    }
    cout<<ans<<endl;
}
    


int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    

    while(t--){
        solve();
    }
    

}










