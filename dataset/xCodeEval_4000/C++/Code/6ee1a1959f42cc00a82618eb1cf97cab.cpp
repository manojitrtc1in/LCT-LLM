   



#include <bits/stdc++.h>
#include<stdio.h>
#define pb(x) push_back(x)
#define XX first
#define YY second
#define cst 1000000007
#define nor_rad(x) ( ( PI*x )/180)
#define rad_nor(x)  ( (x/IP)*180 )
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
 
const ll mod = 1e9+7;
const ld error = 2e-6;
const ld PI = acosl(-1); 

 
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))
 










 
inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}
 
const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;


 
 
 
 
int main()
{
    

    int t; cin>>t;
    for(int kk=1;kk<=t;kk++){
        int n; cin>>n; int i; std::vector<int> v1(n);  std::vector<int> alada;
        for(i=0;i<n;i++) {
            int xx; cin>>xx; v1[i]=xx; 
            if(i==0){ alada.pb(xx); }
            else{ 
                if(v1[i-1]!=xx) alada.pb(xx);
                

             }
        }


        if( n==1 or n==2 or alada.size()==1 ){ cout<<0<<endl; continue; }
        if( kk!=kk ){

           

             

            

            cout<<v1[0]; cout<<v1[1]; cout<<v1[2]; cout<<v1[3]; cout<<v1[4];
            cout<<v1[5]; cout<<v1[6]; cout<<v1[7]; cout<<v1[8]; cout<<v1[9];
            cout<<endl; continue;


        }
        int cn=2;
        int bort_alada=1;
        for(i=n-2;i>0;i--){
            

            if( v1[i]==v1[i-1] && v1[i]==v1[i+1] ){ cn++;  continue; }
            

           else if( v1[i]==v1[i+1] && v1[i]!=v1[i-1] ){ 
              

                

            int suck= alada.size() - (bort_alada-1-1)-1;
                if( suck<0 or suck>=alada.size()){ cn++; }
                else{
                    if( v1[i]>alada[suck] or v1[i]>v1[i-1] ){ cn++; }
                    else{ break; }
                }
                
                continue;
             }
             

           else if( v1[i]!=v1[i+1] && v1[i]==v1[i-1] ){ bort_alada++; cn++; continue; }
           

            

           else if( v1[i]!=v1[i-1] && v1[i]!=v1[i+1] ){
            bort_alada++;
                
                    if( v1[i]>v1[i-1] or v1[i]>v1[i+1] ){ cn++; }
                    else{ break; }          
                continue;
           }


          

           

        }
 
        cout<<n-cn<<endl;
 
 
 
    }
 
 
 
    return 0;
}
 
 
 
 
 




























































