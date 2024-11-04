










using namespace std;
const int N=100001;
const int mod=1000000007;
const int id1=-1;
const int id0=199999991;
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
ll factorial(ll n)
{
     if(n == 0)
          return 1;
    ll i = n, fact = 1;
    while (n / i != n) {
        fact = fact * i;
        i--;
    }
    return fact;
}

ll dp[50];
void fun(){
dp[0]=1;
for(ll i=1;i<50;i++){
    dp[i]=dp[i-1]*2;
}
}
int main(){
         ios_base::sync_with_stdio(false);
         cin.tie(0);
         cout.tie(0);
         ll t;
         cin>>t;
         fun();
         while(t--){
            ll n;
            cin>>n;
            bool ok=false;
            for(ll i=0;i<50;i++){
                if(dp[i]==n){
                    ok=true;
                    break;
                }
            }
           if(ok) cout<<"NO\n";
           else cout<<"YES\n";
         }
  return 0;
}