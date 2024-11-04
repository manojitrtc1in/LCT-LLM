#include<bits/stdc++.h>
#define MAX 55

using namespace std;

typedef long long int lli;

typedef pair<lli,lli> pii;



lli ok[2000];
vector<lli> ans,arr;
map<lli,lli> Hash;

lli _gcd(lli x,lli y){
    return y?_gcd(y,x%y):x;
}

int main(void){
    
    lli i,j,x,y,newX,newY,n;
    
    
    
    cin>>n;
        
    for(i=0;i<n*n;i++){
    
      cin>>x;
      arr.push_back(x);
      Hash[x]++;
      
    }
        
    sort(arr.begin(),arr.end());
    reverse(arr.begin(),arr.end());
    
    ans.push_back(arr[0]);
    Hash[arr[0]]--;
    
    for(i=1;i<arr.size();i++){
        
        if(Hash[arr[i]]<=0) continue;
        
        lli flag=1;
        for(j=0;j<ans.size();j++)
          if(ans[j]%arr[i]==0) flag=0;
        
        if(flag==1||arr[i]==1){
         
          flag=1;
          ans.push_back(arr[i]);
        
        }
        
        else{
            
            flag=1;
            map<lli,lli> yo;
            yo[arr[i]]++;
            for(j=0;j<ans.size();j++){
                
                lli temp=_gcd(arr[i],ans[j]);
                yo[temp]++;
                
            }
            
            map<lli,lli> :: iterator itr = yo.begin();
            while(itr!=yo.end()){
                
                lli now=itr->first;
                if(Hash[itr->first]<itr->second){
                    flag=0;
                    break;
                }
                
                itr++;
                
            }
            
            if(flag==1){
             ans.push_back(arr[i]);
            }
        }
        
        if(flag)
        for(j=0;j<ans.size();j++)
             if(j!=ans.size()-1)
            Hash[_gcd(arr[i],ans[j])]-=2;
            
            else Hash[_gcd(arr[i],ans[j])]--;       
                    
        if(ans.size()==n) break;
                
    }
    
    for(i=0;i<ans.size();i++)
      cout<<ans[i]<<" ";
    
        
    return 0;
    
}