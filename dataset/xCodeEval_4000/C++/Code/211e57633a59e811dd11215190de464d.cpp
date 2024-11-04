 


 
#include<bits/stdc++.h>
using namespace std;
 









#define lli long long int






 


#define f(i,x,n) for(i = x; i < n; i++)
#define rf(i,x,n) for(i = x; i >= n; i--)
#define fr(i,m) for(auto i:m)
 


#define vl vector<lli>
#define vs vector<string>
#define vpl vector<pair<lli,lli>>
#define pb push_back
 
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))


#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))


#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
 
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())


#define sumv(x) accumulate(v.begin(), v.end(), x)
 


#define all(v) (v).begin(),(v).end()
#define rall(a) (a).rbegin(), (a).rend()
 










 


#define sl set<lli>
#define ss set<string>
 






 


#define mll map<lli,lli>
#define mss map<string,string>
#define msl map<string,lli>
#define mls map<lli,string>
 


#define pi pair<int,int>
#define pl pair<long long,long long>
 
#define fi first
#define se second
 






 


 
#define pie (3.141592653589)
 


 
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
 


 
#define maxar *max_element
#define minar *min_element
#define sumar(x) accumulate(a, a+n, x)












 


 
#define gl(s) getline(cin,s)
#define le(s) s.length()
#define str(p,q) s.erase(p,q)




 


 
#define gcd2(a,b) __gcd(a,b)
#define lcm2(a,b) ((a*b)/(__gcd(a,b)))
 



 











 


 
















 

 
 
 
 
 
 
void solve()
{
    lli n,a,i,mi=100000000000000,ct,j,ct1=0,maxi=0,mini0,mini1=000000000000000000000,mini2=10000000000000000;
    cin>>n;
    vl v,vt;
    f(i,0,n){cin>>a;v.pb(a);vt.pb(a);if(a==1){ct1=1;}}


    


    


    

    

    

    

    sort(vt.begin(),vt.end());
    ct=(vt[0]+1)/2;
    ct+=(vt[1]+1)/2;
    mini0=ct;
    

    

    

    

    

    

    

    

    

    f(i,0,n-1){
        if(v[i]==v[i+1]){
            ct=(v[i]+v[i+1]+2)/3;
            mi=min(mi,ct);
        }else{
            maxi=max(v[i],v[i+1]);
            mini1=min(v[i],v[i+1]);
            if(2*mini1<=maxi){
                maxi=(maxi+1)/2;
                mi=min(mi,maxi);
            }else{
                ct=(v[i]+v[i+1]+2)/3;
                mi=min(mi,ct);
            }
        }
    }
    

    

    

    

    

    

    

    

    

    

    f(i,1,n-1){
        if((v[i-1]==v[i+1]) && 2*v[i-1]<=v[i]){
            mini2=min(mini2,v[i-1]);
        }else{
            mini1=min(v[i-1],v[i+1]);
            maxi=max(v[i-1],v[i+1]);
         
                ct=(maxi-mini1+1)/2;
                ct+=mini1;
            mini2=min(mini2,ct);
        }
    }
    

    

    

    

    

    

    

    

    

    

    

    

                    
    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

        
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

        mi=min3(mi,mini0,mini2);
    

    cout<<mi<<endl;
    
}
 
int main()
{
    

    

    

    

    

    lli t;
    t=1;
    

    while(t--)
    solve();
    
    return 0;
}
