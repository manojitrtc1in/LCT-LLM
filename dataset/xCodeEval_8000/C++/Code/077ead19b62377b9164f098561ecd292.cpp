

















  












  


 






  




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
    

    int n,k; cin>>n>>k; vector<int>vc,sv; vc.pb(0); sv.pb(0); int i;
    string fk; cin>>fk;
   string dk= fk;
   for(i=k;i<n;i++){
    dk[i]=dk[i-k];
   }

   if(dk>=fk){ cout<<n<<endl<<dk<<endl; exit(0); }

   for(i=k-1;i>=0;i--){
    if(dk[i]!='9'){
        dk[i]+=1;
        for(int ii=i+1;ii<k;ii++){
                if(dk[ii]=='9')
            dk[ii]='0';
        }

    break;
    }
   }

for(i=0;i<n;i++){
    if(i+k<n){
        dk[i+k]=dk[i];
    }
   }

cout<<n<<endl<<dk<<endl;
    return 0;
}



































































