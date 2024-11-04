


#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
#include <cctype>
 
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
#define int long long

typedef pair<int, int> node;
typedef tree<node, null_type, less<node>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
double eps = 1e-12;
ll MOD = 998244353;
ll mod = 1000000007;
#define fr(i, a, b) for(int i = a;i < b;i++)
#define fr_inv(i, a, b) for(int i = a;i >= b;i--)
#define nl "\n"
#define INF 2e18
#define pi  2*acos(0.0)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define sz(x) ((ll)(x).size())
#define square(x) x * x
#define cube(x) x * x * x
#define PYES cout<<"YES"
#define PNO cout<<"NO"
#define PYes cout<<"Yes"
#define PNo cout<<"No"

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifndef ONLINE_JUDGE
#define debug(x) cerr << (#x) << " is "; _print(x); cerr << nl;
#else
#define debug(x);
#endif




void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}






int power(long long x, unsigned int y, int p)
{
    int res = 1;

    x = x % p;

    if (x == 0) return 0;

    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;

       y = y>>1; 

        x = (x*x) % p;
    }
    return res;
}


unsigned long long modInverse(unsigned long long n,  
int p)
{
return power(n, p - 2, p);
}

int add(int x, int y, int m){int val = ((x % m) + (y % m)) % m;return val;}
int subtract(int x, int y, int m){int val = ((x % m) - (y % m) + m) % m;return val;}
int multiply(int x, int y, int m){int val = ((x % m) * (y % m)) % m;return val;}
int divide(int x, int y, int m){x = x % m;y = modInverse(y, m);return (x * y);}




template <typename T> ostream& operator <<(ostream& output, const vector<T>& data)
{
      for (const T& x : data)
            output << x <<" ";
      return output;
}
 
 
template <typename T> istream& operator>>(istream& input,vector<T>& data)
{
      for (auto& item : data)
      {
           input >> item;
      }
      return input;
}




map<int, int>map_for_prime;
void sieve_of_eratosthenes(int n)
{
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    map_for_prime[2] = 1;
    for(int i = 3;i < n;i += 2)
    {
      map_for_prime[i] = 1;
    }
}




void primeFactors(int n)
{
    while (n % 2 == 0)
    {
        

        n = n/2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            

            n = n/i;
        }
    }
    if (n > 2)
    {
        

    }
}




int NODiv(int n)
{
    int cnt = 0;
    for(int i = 1;i * i <= n;i++)
    {
        if(i * i == n)
        {
            cnt++;
            continue;
        }
        cnt += 2;
    }
    return cnt;
}




int nCr(int n, int k) 
{
    if(n < k)
    {
        return 0;
    }
    if(k == 0)
    {
        return 1;
    }
    int res = 1;
    for (int i = n - k + 1; i <= n; ++i)
        res *= i;
    for (int i = 2; i <= k; ++i)
        res /= i;
    return res;
}





unsigned long long nCrModPFermat(unsigned long long n,int r, int p)
{


if (n < r)
    return 0;


if (r == 0)
    return 1;

unsigned long long fac[n + 1];
fac[0] = 1;
for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

   return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}





bool isPrime(int x) {
  for (int d = 2; d * d <= x; d++) {
      if (x % d == 0)
          return false;
  }
  return true;
}
























void lets_solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    cin>>v;
    int i=0;
    while(v[i]==1){
        i++;
    }
    i -= 1;
    int p = n - 1;
    while(v[p] == 1)
    {
        p--;
    }
    p+=1;
    if(p>i){
        cout<<p-i<<nl;
        return;
    }
    cout<<0<<nl;
    

}
signed main()
{
    fast_cin();
    auto start1 = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ll test_cases = 1;
    cin >> test_cases;
    int test_case_no = 1;
    while(test_cases--) {
    

    test_case_no++;
        lets_solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifndef ONLINE_JUDGE
    cerr << "Time: " << duration . count() / 1000 << endl;
    #endif
    return 0;
}


















































 






 


























































































 































































































 
 



















































































































































































































































































































































































 






 


























































































 































































































 
 

























































































































































































































































































































































































 






 


























































































 































































































 
 


































































































































































































































































































































































































































































