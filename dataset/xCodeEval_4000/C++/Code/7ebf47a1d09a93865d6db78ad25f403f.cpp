





#include <bits/stdc++.h>
#include<cstring>
#include <time.h>
using namespace std;

#define ll long long













































#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);


#define READ freopen("input.txt","r",stdin);
#define WRITE freopen("output.txt","w",stdout);




















int main()
{
    FAST;
#ifndef ONLINE_JUDGE
    

    READ;
    

    WRITE;
#endif
   int t;
   cin>>t;
   while(t--)
    {
        string s;
        cin>>s;     
        if(s.length()%2!=0){
            cout<<"NO"<<endl;
        }else{
            int nB=0;
            for (int i = 0; i < s.length(); ++i)
            {
                if(s[i]=='B'){
                    nB++;
                }
            }
            if(nB==s.length()/2){
                cout<<"YES"<<endl;
            }else
            {
                cout<<"NO"<<endl;
            }
        }
    } 
   
}






 

 

 

 

 

 

 

 

 

 

 


 






 

 


 
