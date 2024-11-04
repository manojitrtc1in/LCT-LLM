
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<unordered_set>
#include<set>
#include<algorithm>
#include<cmath>
#include<iomanip>
#define ll long long int
using namespace std;
const int N=100001;
const int mod=1000000007;
const int bhot_chhota=-1;
const int papa_prime=199999991;
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
void printDivisors(ll n)
{    vector<ll>div;
    for (ll i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i){
               div.push_back(i);
            }
            else{
              div.push_back(i);
              div.push_back(n/i);
            } 
        }
}
}
int main(){
         ios_base::sync_with_stdio(false);
         cin.tie(0);
         cout.tie(0);
         ll t;
         cin>>t;
         while(t--){
           ll n,m;
           cin>>n>>m;
           ll k[n];
           for(ll i=0;i<n;i++){
               cin>>k[i];
           }
           sort(k,k+n,greater<ll>());
           ll c[m];
           for(ll i=0;i<m;i++){
               cin>>c[i];
           }
           

           

           ll ans=199999999999999991,sum=0;
           for(ll i=0;i<n;i++){
               sum+=c[k[i]-1];
           }
           ans=min(ans,sum);
           sum=0;
           ll j=0;
           for(ll i=0;i<n;i++){
               if(c[j]<c[k[i]-1]){
                   sum+=c[j];
                  j++;
               }
               else{
                   sum+=c[k[i]-1];
               }
           }
           cout<<min(sum,ans)<<"\n";
         }
  return 0;
}