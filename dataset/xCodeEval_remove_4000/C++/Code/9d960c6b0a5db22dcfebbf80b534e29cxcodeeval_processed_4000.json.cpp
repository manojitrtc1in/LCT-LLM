

































using namespace std;


void swap(int &x, int &y) {int temp = x; x = y; y = temp;}

int XOR(int n)
{
  if (n % 4 == 0)
    return n;
  if (n % 4 == 1)
    return 1;
  if (n % 4 == 2)
    return n + 1;
  return 0;
}




int isPrime(int N){
 if(N<2 || (!(N&1) && N!=2))
      return 0;
  for(int i=3; i*i<=N; i+=2){
     if(!(N%i))
         return 0;
 }
  return 1;
}




void id1(vector<int>& prime, int high)
{
    bool ck[high + 1];
    memset(ck, true, sizeof(ck));
    ck[1] = false;
    ck[0] = false;
    for (int i = 2; (i * i) <= high; i++) {
        if (ck[i] == true) {
            for (int j = i * i; j <= high; j = j + i) {
                ck[j] = false;
            }
        }
   }
    for (int i = 2; i * i <= high; i++) {
        if (ck[i] == true) {
            prime.push_back(i);
        }
    }
}

vector<bool> id0(int low, int high)
{
    vector<bool>prime(high-low+1,true);
    vector<int> chprime;
    id1(chprime, high);
    for (int i : chprime) {
        int lower = (low / i);     
        if (lower <= 1) {
            lower = i + i;
        }
        else if (low % i) {
            lower = (lower * i) + i;
        }
        else {
            lower = (lower * i);
        }
        for (int j = lower; j <= high; j = j + i) {
            prime[j - low] = false;
        }
    }
    return prime;
}




const double eps = 1e-7;
const ll N = 5e5 + 7, mod = 1e9 + 7;
ll POW(ll a, ll b, ll mod)
{
    a %= mod;
    ll r = 1;
    for(ll i = b; i > 0; i >>= 1)
    {
        if(i & 1)
            r = (r * a) % mod;
        a = (a * a) % mod;
    }
    return r;
}




ll f[N];
void init(){
  f[0] = 1;
  for(ll  i = 1; i < N; i++)
  {
      f[i] = (f[i - 1] * i) % mod;
  }
}
ll nCr(ll n, ll r)
{
    if(n < r)
        return 0;
    return f[n] * POW(f[n - r] * f[r], mod - 2, mod) % mod;
}
ll nPr(ll n, ll r)
{
    return nCr(n, r) * f[r] % mod;
}




vector<ll> getFactors(ll n)
{
    vector<ll>v;
    for (ll i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i) v.push_back(i);
            else {v.push_back(i); v.push_back(n/i);}    
        }
    }
    return v;
}




ll p=1e9+7;
ll modadd(ll a, ll b) {a = a % p; b = b % p; return (((a + b) % p) + p) % p;}
ll modmul(ll a, ll b) {a = a % p; b = b % p; return (((a * b) % p) + p) % p;}
ll modsub(ll a, ll b) {a = a % p; b = b % p; return (((a - b) % p) + p) % p;}






















void solve() {


    ll n;
    cin>>n;
    ll arr[n];
    F(i,n) cin>>arr[i];
    F(i,n){
        if(((ll)sqrt(arr[i])*(ll)sqrt(arr[i]))!=arr[i]) {cout<<"YES"<<endl; return;}
    }
    cout<<"NO"<<endl;


    return;


}




signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}