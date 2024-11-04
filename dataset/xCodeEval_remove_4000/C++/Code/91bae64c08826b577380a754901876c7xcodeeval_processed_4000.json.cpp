

















  












  


 






  


















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



ll id0(ll x)
{
    ll l = 0, r = 1000005;
    while (l != r) {
        ll m = (l + r + 1) / 2;
        if (m * m * m > x)
            r = m - 1;
        else
            l = m;
    }
    return l;
}


int main()
{
   

   int t; scanf("%d",&t);
   while(t--){
    ll a,b; scanf("%lld%lld",&a,&b);  ll gun=a*b; 

    double t1= gun*1.00;
    ll cb=   id0(gun);            

    

    if( cb*cb*cb==a*b && a%cb==0 && b%cb==0 ) printf("Yes\n");
    else printf("No\n");

   }





    return 0;
}


































































