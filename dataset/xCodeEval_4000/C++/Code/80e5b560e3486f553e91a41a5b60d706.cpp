

                        

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
#define nl "\n"
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define sz(x) ((ll)(x).size())
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






int add(int x, int y)
{
    int res = x + y;
    return(res >= mod ? res - mod : res);
}

int multiply(int x, int y)
{
    int res = x * y;
    return(res >= mod ? res % mod : res);
}

int subtract(int x, int y)
{
    int res = x - y;
    return(res < 0 ? res + mod : res);
}

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

int modInverse(int a, int m)    

{
    int m0 = m;
    int y = 0, x = 1;
 
    if (m == 1)
       return 0;
 
    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
 
    return x;
}




void inputarray(vi&a, int n)
{
    for(int i = 0; i < n;i++)
    {
        cin>>a[i];
    }
    return;
}




int fact(int n, int m)  

{
    int val = 1;
    for(int i = 1;i <= n;i++)
    {
        val = (val * i) % m;
    }
    return (val);
}




bool sieve_of_eratosthenes(int n)
{
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime[n];
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




bool isPrime(int x) {
  for (int d = 2; d * d <= x; d++) {
      if (x % d == 0)
          return false;
  }
  return true;
}



vector<vector<int>>adj;
void addEdge(int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

















































































































bool check(vector<int>&arr)
{
    int i = 0;
    while(i != sz(arr))
    {
        if(arr[i] != arr[sz(arr) - 1 - i]) 
        {
            return false;
        }
        i++;
    }
    return true;
}


void solve(){
    int n;
    cin>>n;
    

    

    vector<int>a;
    for(int i = 0;i < n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }

    int pos1 = -1;
    int pos2 = -1;
    for(int i = 0;i < n;i++)
    {
        if(a[i] != a[n - 1 - i])
        {
            pos1 = a[i];
            pos2 = a[n - 1 - i];
            break;
        }
    }
    if(pos1 == -1 or pos2 == -1)
    {
        PYES<<nl;
        return;
    }
    

    vector<int>arr;
    int itr1 = 0;
    while(itr1 != n)
    {
        if(a[itr1] == pos1)
        {
            itr1++;
            

            continue;
        }
        arr.push_back(a[itr1]);
        itr1++;
    }
    int itr2 = 0;
    vector<int>arr2;
    while(itr2 != n)
    {
        if(a[itr2] == pos2)
        {
            itr2++;
            

            continue;
        }
        arr2.push_back(a[itr2]);
        itr2++;
    }
    if(check(arr2) or check(arr))
    {
        PYES;
        cout<<nl;
        return;
    }
    PNO;
    cout<<nl;
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

            

            

            

            

            

            

            

            

            

            

            

            

            

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

}
signed main()
{
    fast_cin();
    auto start1 = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ll t = 1;
    cin >> t;
    int k = 1;
    while(t--) {
    

    k++;
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifndef ONLINE_JUDGE
    cerr << "Time: " << duration . count() / 1000 << endl;
    #endif
    return 0;
}