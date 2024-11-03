














































































































#include <bits/stdc++.h>

#include <iostream>
#define ll long long
#define lld long double
#define pb push_back
#define py cout << 'Y'<<'E'<<'S'<<endl;
#define pn cout << 'N'<<'O'<<endl;
#define pii pair<ll,ll>
#define pdd pair<lld,lld>
#define all(v) v.begin(), v.end()
#define Meyank ios_base::sync_with_stdio(false);
#define Garg cin.tie(NULL);
#define huehue cout.tie(NULL);
#define max_heap(datatype) priority_queue<datatype>
#define min_heap(datatype) priority_queue<datatype, vector<idatatypent>, greater<datatype> >
using namespace std;
int modulo = 1e9 + 7;
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
bool sorta(const pii& a, const pii& b) { return (a.second < b.second); }
bool sortd(const pii& a, const pii& b) { return (a.second > b.second); }
string decToBinary(int n) {
    string s = "";
    int i = 0;
    while (n > 0) {
        s = to_string(n % 2) + s;
        n = n / 2;
        i++;
    }
    return s;
}
ll binaryToDecimal(string n) {
    string num = n;
    ll dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1') dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}
bool isPowerOfTwo(int n) {
    if (n == 0) return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool isPerfectSquare(ll x) {
    if (x >= 0) {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
long long moduloMultiplication(long long a, long long b, long long mod)
{
    long long res = 0;
    a %= mod;

    while (b)
    {

        if (b & 1)
            res = (res + a) % mod;

        a = (2 * a) % mod;

        b >>= 1; 

    }

    return res;
}
ll powermod(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}


ll bs_sqrt(ll x)
{
    ll left = 0, right = 2000000123;
    while (right > left)
    {
        ll mid = (left + right) / 2;

        if (mid * mid > x)
            right = mid;
        else
            left = mid + 1;
    }
    return left - 1;
}



ll modular_inverse(ll n, ll mod)
{
    return powermod(n, mod - 2, mod);
}

ll nCr(ll n, ll r, ll p)
{
    

    if (n < r)
        return 0;
    

    if (r == 0)
        return 1;

    

    

    

    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modular_inverse(fac[r], p) % p * modular_inverse(fac[n - r], p) % p) % p;
}

int modFact(int n, int p)
{
    if (n >= p)
        return 0;

    int result = 1;
    for (int i = 1; i <= n; i++)
        result = (result * i) % p;

    return result;
}

void ps(vector<int>& tree, vector<int>& permutation, int n) {

    int root = -1;
    for (int i = 0;i < n;i++) {
        if (tree[i] == (i + 1)) {
            root = i + 1;
            break;
        }
    }

    if (root == -1) {
        cout << -1 << endl;
        return;
    }

    vector<ll>ans(n + 3, -1);
    ans[root] = 0;
    ll max_distace = 2;

    if (permutation[0] != root) {
        cout << -1 << endl;
        return;

    }

    for (int i = 1;i < n;i++) {
        int node = permutation[i];
        int parent = tree[node - 1];

        if (ans[parent] == -1) {
            cout << -1 << endl;
            return;

        }else{
            ll reqired_dis=max_distace+2;
            max_distace++;
            ans[node]=reqired_dis;
        }
        

    }

    


    

    

    

    


   for(int i=1;i<=n;i++){
    cout<<ans[i]-ans[tree[i-1]]<<" ";
   }
   cout<<endl;



}
int main() {
    Meyank Garg huehue;
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>parents(n);
        for (int i = 0;i < n;i++) {
            cin >> parents[i];
        }

        vector<int>permutation(n);
        for (int i = 0;i < n;i++) {
            cin >> permutation[i];
        }

        ps(parents,permutation,n);





    }
    return 0;
}