#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<queue>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include<iostream>
#include <sstream>  

#include <string>  

#include <stack> 
#include <cmath>
 
#pragma comment(linker, "/STACK:2000000")
#pragma comment(linker, "/HEAP:2000000")
 
#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define f(n) for(ll i=0;i<n;i++)
#define fn(a,n) for(ll a=0; a<n; a++)
#define flr(a,l,r) for(ll a=l; a<=r;a++)
#define mp make_pair
#define sorta(a) sort(a.begin(), a.end());
#define sortd(a) sort(a.begin(), a.end(), greater<ll>());
#define sortdp(a) sort(a.begin(), a.end(), greater<pair<ll, ll>>());
#define vec std::vector<ll>
#define vp std::vector<pair<ll, ll>>
#define all(a) a.begin(), a.end()
#define inf (long long)1e18
#define infi (int)1e9
#define endl '\n'
#define ff(a, b) for (ll i = 0; i < a; i++) for (ll j = 0; j < b; j++)
#define pp1(a) cout << a << endl;
#define pp2(a, b) cout << a << " " << b << endl;
#define pp3(a, b, c) cout << a << " " << b << " " << c << endl;
#define pp4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl;
#define vvl vector<vector<ll>>
#define vvc std::vector<std::vector<char>>
#define vvi std::vector<std::vector<int>>
#define blb(a, b) lower_bound(all(a), b) - a.begin();
#define bub(a, b) upper_bound(all(a), b) - a.begin();
#define graph(n) vvl g(n + 1, vector<ll>(0));
#define in(a, n) vec a(n); f (n) cin >> a[i];
 


#define MOD 1000000007
#define mod 998244353
#define MODLL 1000000000000000007
 
using namespace std;
 
 
void print_width(ll x) {
 
    std::cout << std::fixed;
    std::cout << std::setprecision(x);
}
 
ll power(ll x, ll y, ll p = MOD)
{ 
    ll res = 1;      

 
    x = x % p;  

                

 
    while (y > 0) 
    { 
        

        if (y & 1) 
            res = (res * x) % p; 
 
        

        y = y >> 1; 

        x = (x * x) % p;   
    } 
    return res; 
} 
 
void printArr(ll a[], ll n) {
    f(n)
        cout << a[i] << " ";
    cout << endl;
}
 
void printVector(std::vector<ll> v) {
    f(v.size())
        cout << v[i] << " ";
    cout << endl;
}
 
void printVectorPair(std::vector<pair<ll, ll>> v) {
    f(v.size())
        pp2(v[i].first, v[i].second);
    cout << endl;
}
 
ll Min(ll a, ll b, ll c) {
    if (a < b and a < c)
        return a;
    if (b < c)
        return b;
    return c;
}
 
void initialize(ll arr[], ll n) {
    for (ll i = 0; i <= n; i++)
        arr[i] = i;
}
 
ll root(ll arr[], ll i) {
 
    while (arr[i] != i) {
        arr[ i ] = arr[ arr[ i ] ] ; 
        i = arr[i];
    }
    return i;
 
}
 
void Union(ll arr[], ll a, ll b) {
    ll root_a = root(arr, a);
    ll root_b = root(arr, b);
 
    arr[root_a] = root_b;
}
 
 
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else return gcd(b, a % b);
}
 
ll power_wm(ll x, ll y)
{ 
    ll res = 1;      

 
 
    while (y > 0) 
    { 
        

        if (y & 1) 
            res = (res * x); 
 
        

        y = y >> 1; 

        x = (x * x);   
    } 
    return res; 
} 
 
long double dpower(long double x, ll y) { 
    long double res = 1;      

 
 
    while (y > 0) 
    { 
        

        if (y & 1) 
            res = (res * x); 
 
        

        y = y >> 1; 

        x = (x * x);   
    } 
    return res; 
}
 
std::vector<ll> vsum(std::vector<ll> a) {
 
    std::vector<ll> s(a.size());
    s[0] = a[0];
    flr (i, 1, a.size() - 1) {
        s[i] = s[i - 1] + a[i];
    }
    return s;
}

std::vector<ld> vsumld(std::vector<ld> a) {
 
    std::vector<ld> s(a.size());
    s[0] = a[0];
    flr (i, 1, a.size() - 1) {
        s[i] = s[i - 1] + a[i];
    }
    return s;
}
 
bool comp( pair<ll, ll> a, pair<ll, ll> b) {
    ll x = a.second * b.first;
    ll y = a.first * b.second;
 
    if (x <= y)
        return false;
    else
        return true;
}
 
bool is_cap(char a) {
 
    if (a <= 'Z' and a >= 'A')
        return true;
    else
        return false;
}
 
bool is_small(char a) {
 
    if (a <= 'z' and a >= 'a')
        return true;
    else
        return false;
}
 
string addition(string str1, string str2) 
{ 
    string str = ""; 
    if (str1.size() > str2.size())  {
        swap(str1, str2); 
    }
 
    int n1 = str1.size(), n2 = str2.size(); 
  
    reverse(all(str1)); 
    reverse(all(str2)); 
  
    int carry;
    carry = 0;
    for (int i = 0; i<n1; i++) { 
        int sum;
        sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.pb(sum%10 + '0'); 
  
        carry = sum / 10; 
    } 
  
    for (int i=n1; i<n2; i++)  { 
        int sum;
        sum = ((str2[i]-'0')+carry); 
        str.pb(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    if (carry) 
        str.pb(carry+'0'); 
  
    reverse(all(str)); 
  
    return str; 
} 
 
bool mcomp(ll a, ll b, ll c, ll d) {
 
    if (a == b and b == c and c == d)
        return true;
    else
        return false;
 
}
 

 






 










 






            

















ll modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p); 
} 
  




ll nCr(ll n, ll r, ll p) 
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
 
ll c2(ll n) {
    return (n * (n - 1)) / 2;
}


void time() {
    #ifndef ONLINE_JUDGE
    cout << "\nTime: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
    #endif
}



string multiply(string num1, string num2) 
{ 
    int n1 = num1.size(); 
    int n2 = num2.size(); 
    if (n1 == 0 || n2 == 0) 
    return "0"; 
   
    

    

    vector<int> result(n1 + n2, 0); 
   
    

    

    int i_n1 = 0;  
    int i_n2 = 0;  
       
    

    for (int i=n1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
   
        

        

        i_n2 = 0;  
           
        

        for (int j=n2-1; j>=0; j--) 
        { 
            

            int n2 = num2[j] - '0'; 
   
            

            

            

            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
   
            

            carry = sum/10; 
   
            

            result[i_n1 + i_n2] = sum % 10; 
   
            i_n2++; 
        } 
   
        

        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
   
        

        

        i_n1++; 
    } 
   
    

    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 
   
    

    

    if (i == -1) 
    return "0"; 
   
    

    string s = ""; 
       
    while (i >= 0) 
        s += std::to_string(result[i--]); 
   
    return s; 
} 









  






  





ll sti(string s) {

    ll ans = 0;
    ll p = 1;

    for (ll i = s.size() - 1; i >= 0; i--) {
        ans = (ans + ((ll)(s[i] - '0') * p) % mod) % mod;
        p = (p * 10) % mod;
    }
    return ans;

}



















































int lps(char *seq, int i, int j) 
{ 


if (i == j) 
    return 1; 
  




if (seq[i] == seq[j] && i + 1 == j) 
    return 2; 
  


if (seq[i] == seq[j]) 
    return lps (seq, i+1, j-1) + 2; 
  


return max( lps(seq, i, j-1), lps(seq, i+1, j) ); 
} 

























































bitset<64> left_child(bitset<64> node) {

    f (64) {

        if (node[i] == 1) {

            if (i == 0)
                break;

            node[i] = 0;
            node[i - 1] = 1;
            break;

        }

    }
    return node;

}

bitset<64> right_child(bitset<64> node) {

    f (64) {

        if (node[i] == 1) {

            if (i == 0)
                break;

            node[i - 1] = 1;
            break;

        }

    }
    return node;

}

bitset<64> parent(bitset<64> node, bitset<64> root) {

    if (node == root)
        return node;

    f (64) {

        if (node[i] == 1) {

            


            if (node[i + 1] == 0) {
                node[i + 1] = 1;
                node[i] = 0;
                break;
            }
        
            else if (node.count() > 1) {

                node[i] = 0;
                break;

            }
            break;
        }

    }
    return node;
}

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);

int myrand(int mo) {
    return mt()%mo;
}

int main() {
 
    

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
 
    

    print_width(15);


    ll n, k;
    cin >> n >> k;

    ll mat[n][n];

    ll p = 1;

    flr (i, 0, n - 1) {
        flr (j, 0, k - 2) {
            mat[i][j] = p;
            p++;
        }
    }

    ll sum = 0;
    flr (i, 0, n - 1) {
        flr (j, k - 1, n - 1) {

            if (j == k - 1)
                sum += p;

            mat[i][j] = p;
            p++;
        }
    }

    pp1(sum);
    flr (i, 0, n - 1) {
        flr (j, 0, n - 1) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    

    return 0;
}