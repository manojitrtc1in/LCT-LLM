
 
using namespace std;
 




 

typedef long long ll;
typedef unsigned long long ull;
 
 





 

 







 

 








 










 



 
 









typedef vector<int> vi;
typedef vector <ll> vll;
typedef set <ll> sll;
typedef multiset <ll> msll;
typedef queue <ll> qll;
typedef map <ll, ll> mll;
typedef pair <ll, ll> pll;
typedef vector <pair <ll , ll> > vpll;
 
 





inline bool cmp(pll a,pll b){ if(a.ff == b.ff) return a.ss < b.ss; return a.ff < b.ff; }
 

 

int drx[8] = {-2,-2,-1,-1,1,1,2,2};
int dcy[8] = {-1,1,-2,2,-2,2,-1,1};
int dirx[4] = { -1, 0, 1, 0 };
int diry[4] = { 0, -1, 0, 1 };
 
 






 

ll binpow(ll a, ll b, ll m) {a %= m; ll res = 1; while (b > 0) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1;}return res;}
ll InverseMod(ll base, ll pow) { if(pow == 0) return 1; ll ans = InverseMod(base, pow / 2); ans = (ans * ans) % mod; if(pow & 1){ return (ans * base) % mod; } else{ return ans; } }
bool isprime(ll num) { if(num < 2) return false; for(ll i = 2; i * i <= num; i++){ if(num % i == 0) return false; } return true; }
ll id2(ll num) { double ans = num; for(ll i = 2; i * i <= num; i++){ if(num % i == 0){ while (num % i == 0) { num /= i; } ans *= (1.0 - (1.0 / (double)i)); } } if(num > 1) ans *= (1.0 - (1.0 / (double)num)); return (ll)ans; }
 
template <class T> inline T gcd(T a,T b){if(b == 0)return a; return gcd(b, a % b);}
template <class T> inline T lcm(T a,T b){return a * b / gcd<T>(a, b);}
template <class T> inline T power(T b,T p){ll ans = 1;while(p--) ans *= b; return ans;}
 
ll id4(ll n, ll r)
{
 
    if (r > n)
        return 0;
    ll m = 998244353;
    ll inv[r + 1];
    CLR(inv);
    inv[0] = 1;
    if(r+1>=2)
    inv[1] = 1;
 
    

    

    

    

    for (int i = 2; i <= r; i++) {
        inv[i] = m - (m / i) * inv[m % i] % m;
    }
 
    ll ans = 1;
 
    

    for (int i = 2; i <= r; i++) {
        ans = ((ans % m) * (inv[i] % m)) % m;
    }
 
    

    for (int i = n; i >= (n - r + 1); i--) {
        ans = ((ans % m) * (i % m)) % m;
    }
    return ans;
}
 
ll id5(ll a,ll b,ll& x,ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = id5(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
bool id0(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = id5(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
 
ll mul(ll a,ll b) {
    return ((a % mod) * (b % mod)) % mod;
}
 
ll add(ll a,ll b) {
    return (a % mod + b % mod) % mod;
}
 
ll powm(ll a, ll b) {
    
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}
ll divide(ll a,ll b) {
    return (a % mod) * powm(b, mod - 2) % mod;
}
 
bool id3(vector<int> v, int n)
{
    if (n == 1 || n == 0)
        return 1;
 
    if (v[n - 1 ] < v[n - 2])
        return 0;
 
    return id3(v, n - 1);
}
 
int sumDigits(int num)
    {
        return num == 0 ? 0 : num % 10 + sumDigits(num / 10);
    } 
 
void id1(ll n)
{
    for (ll i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            

                
            

                

                

           

        }
    }
}
bool eno(string s){
    string t=s;
    srt(t);
    if(t==s) return true;
    else return false;
}
int main(){
    
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt","w",stdout);
    
 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cout<<fixed<<setprecision(20);
   ll test=1;
   cin>>test;
   while(test--){
       ll n;
  cin>>n;
  string s;
  cin>>s;
 int f1(0),f2(0),f3(0),f4(0);
  for(int i=0;i<n-1; i++){
    if(s[i]=='a'&& s[i+1]=='a'){
      f1++;
      break;
    }
  }
 
  for(int i=0;i<n; i++){
    if(i<=n-3){
      string temp = s.substr(i,3);
 
      if(temp=="aba" || temp =="aca"){
        f2++;
        break;
      }
    }
  }
 
  for(int i=0;i<n; i++){
    if(i<=n-4){
      string temp = s.substr(i,4);
 
      if(temp=="abca" || temp =="acba"){
        f3++;
        break;
      }
    }
  }
 
  for(int i=0;i<n-5; i++){
    string temp = s.substr(i,7);
    
    if(temp=="abbacca" || temp =="accabba"){
      f4++;
      break;
    }
  }
 
  if(f1) cout<<2;
  else if(f2) cout<<3;
  else if(f3) cout<<4;
  else if(f4) cout<<7;
  else cout<<-1;
  en
   }

    printf("\nRun Time -> %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

   return 0;
}

