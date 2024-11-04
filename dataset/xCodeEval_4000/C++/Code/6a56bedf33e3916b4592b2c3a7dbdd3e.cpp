






































    
    
    
    
    
    
  




  

















 


   















   

#include <set>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define str string
#define br endl
#define ll long long
int main(){





ll t;
cin>>t;
while(t--){
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
            cin>>a[i];
    }
    if(a[0]!=a[1] && a[1]==a[2]){
            cout<<1<<br;
    }else{
        int x=a[0];
        for(int i=1;i<n;i++){
            if(a[i]!=x){
            cout<<i+1<<br;
            break;
            }
        }
    }
}
    return 0;
}
