














































































































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



bool ps(string& s, string& t, map<char, vector<int>>& odd_pos, map<char, vector<int>>& even_pos, int s_i, int t_i) {
    


    if (s_i >= s.length()) {

        return (t.length() - t_i) % 2 == 1;
    }




    

    char ch = s[s_i];
    


    if (t_i & 1) {
        

        

        vector<int>& v = even_pos[ch];
        int index = lower_bound(all(v), t_i) - v.begin();
        bool ans = false;

        if (index < v.size()) {


            ans = ps(s, t, odd_pos, even_pos, s_i + 1, v[index]);

        }

        


        return ans;


    }
    else {
        

       vector<int>& v = odd_pos[ch];
        int index = lower_bound(all(v), t_i) - v.begin();
        bool ans = false;

        if (index < v.size()) {


            ans = ps(s, t, odd_pos, even_pos, s_i + 1, v[index]);

        }

        


        return ans;
    }
















}

int main() {
    Meyank Garg huehue;
    ll t;
    cin >> t;
    while (t--) {
        

        

        string s, t;
        cin >> t >> s;
        bool ans = false;

        map<char, vector<int>>odd_pos, even_pos;
        for (int i = 0;i < t.size();i++) {
            if (i % 2) {
                odd_pos[t[i]].push_back(i);
            }
            else {
                even_pos[t[i]].push_back(i);
            }
        }

        ans = ((odd_pos[s[0]].size() > 0) ? ps(s, t, odd_pos, even_pos, 1, odd_pos[s[0]][0]) : false) || ((even_pos[s[0]].size() > 0) ? ps(s, t, odd_pos, even_pos, 1, even_pos[s[0]][0]) : false);
        


        if (ans) {
            py;
        }
        else {
            pn;
        }



    }
    return 0;
}