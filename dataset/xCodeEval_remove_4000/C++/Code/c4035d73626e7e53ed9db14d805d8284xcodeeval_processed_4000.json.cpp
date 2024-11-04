

















  












  


 






  


















using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9 + 7;
const ld error = 2e-6;
const ld PI = acosl(-1); 

















inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;





int main()
{
   

   ll n,p; cin>>n>>p;
   if(p==0){ cout<<__builtin_popcount(n)<<endl; exit(0);    }
   if(p>0){
    ll i;
    for(i=1;i<=35;i++){
        n-=p; if(n<0){ cout<<-1<<endl; exit(0); }
        if( __builtin_popcount(n)<=i && __builtin_popcount(n)!=0 ){
                if( __builtin_popcount(n) ==1 && i> log(n)/log(2)+1 ){ cout<<-1<<endl; exit(0); }
                cout<<i<<endl; exit(0); }
    }
    cout<<-1<<endl;
    exit(0);
   }


   if(p<0){
    ll i;
    for(i=1;i<=35;i++){
        n+=-p; if(n<0){ continue; }
        if( __builtin_popcount(n)<=i && __builtin_popcount(n)!=0  ){
                if(  __builtin_popcount(n) ==1 && i> log(n)/log(2)+1 ){ cout<<-1<<endl; exit(0); }
                cout<<i<<endl; exit(0); }
    }
    cout<<-1<<endl;
    exit(0);
   }



    return 0;
}


































































