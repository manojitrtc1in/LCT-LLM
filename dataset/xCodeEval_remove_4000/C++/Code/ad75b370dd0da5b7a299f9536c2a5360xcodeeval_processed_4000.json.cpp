














 using namespace std;


 




 
























 


 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<long long> vl;
typedef vector<vector<long long> > vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef priority_queue<int, vector<int>, greater<int> > pqm;
 
 

const ll INF = 8 * 1e18;
const int big = 1e6 + 7;
 
ll gcd(ll a, ll b) {if (!b)return a; return gcd(b, a % b);}
ll powe(ll x, ll y, ll p = mod) { ll res = 1; x %= p; while (y > 0) { if (y & 1) res = (res * x) % p; y >>= 1; x = (x * x) % p;} return res; }
ll lcm(ll x, ll y) { return ((x * y) / (gcd(x, y))); }
ll modi(ll x, ll p = mod) { return powe(x, p - 2, p); }
 
ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      

  
    x = x % p;  

                

  
    while (y > 0) 
    { 
        

        if (y & 1)   
            res = (res*x) % p; 
  
        

        y = y>>1; 

        x = (x*x) % p; 
    } 
    return res; 
} 
  


ll modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p); 
} 
  




ll id1(ll n, ll r, ll p) 
{ 
   

   if (r==0) 
      return 1;  
    ll fac[n+1]; 
    fac[0] = 1; 
    for (ll i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p; 
  
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
} 
ll prime[300001]={0};
void id0(int n)
{
    

    

    

    

    

    

    

    

 
    for (int p = 2; p * p <= n; p++)
    {
        

        

        if (prime[p] == 0)
        {
            

            

            

            

            

            

            for (int i = p * p; i <= n; i += p)
                prime[i] = 1;
        }
    }
 
    
}
ll fast_pow(ll a, ll p) {
  ll res = 1;
  while (p) {
    if (p % 2 == 0) {
      a = a * 1ll * a % mod;
      p /= 2;
    } else {
      res = res * 1ll * a % mod;
      p--;
    }
  }
  return res;
}
 
ll fact(int n) {
  ll res = 1;
  for (ll i = 1; i <= n; i++) {
    res = res * 1ll * i % mod;
  }
  return res;
}
 
ll C(ll n, ll k) {
  return fact(n) * 1ll * fast_pow(fact(k), mod - 2) % mod * 1ll * fast_pow(fact(n - k), mod - 2) % mod;
}


























































 




































    




































 


 













































































































































    




















   



















































































































































































































    

    

    

    

    

    

    

    

    

    

    

    





































            
















        

















        

    


























































    

    

    

    

    

    

    

ll ans=0;
vector<ll>a;
void check(ll i,ll j){
    if(j-i+1==3){
        if((a[i+1]>a[i] && a[i+1]>a[i+2]) || (a[i+1]<a[i] && a[i+1]<a[i+2])){
            ans++;
        }
    }
    else {
        if(((a[i+1]>a[i] && a[i+1]>a[i+2]) || (a[i+1]<a[i] && a[i+1]<a[i+2])) && ((a[i+1]>a[i] && a[i+1]>a[i+3]) || (a[i+1]<a[i] && a[i+1]<a[i+3])) && ((a[i+2]>a[i] && a[i+2]>a[i+3]) || (a[i+2]<a[i] && a[i+2]<a[i+3])) && ((a[i+2]>a[i+1] && a[i+2]>a[i+3]) || (a[i+2]<a[i+1] && a[i+2]<a[i+3]))){
            ans++;
        }
    }
}
int main()
{
  ll t;
  cin >> t;
 

  while(t--){
       ll n;
       cin >> n;
       for(ll i=0;i<n;i++){
           ll x;
           cin >> x;
           a.pb(x);
       }
      
       for(ll i=0;i<n-2;i++){
          if(i!=n-3){
              check(i,i+2);
              

              check(i,i+3);
              

          }
          else {
              check(i,i+2);
              

          }
       }
     cout << ans+2*n-1 << endl;
     a.clear();
     ans=0;
  }

}
   