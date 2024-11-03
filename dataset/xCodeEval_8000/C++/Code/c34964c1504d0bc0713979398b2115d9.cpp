










































































































#include <bits/stdc++.h>

#include <iostream>
#define ll long long
#define lld long double
#define pb push_back
#define py cout << 'Y' << 'E' << 'S' << endl;
#define pn cout << 'N' << 'O' << endl;
#define pii pair<ll, ll>
#define pdd pair<lld, lld>
#define all(v) v.begin(), v.end()
#define Meyank ios_base::sync_with_stdio(false);
#define Garg cin.tie(NULL);
#define huehue cout.tie(NULL);
#define max_heap(datatype) priority_queue<datatype>
#define min_heap(datatype) priority_queue<datatype, vector<idatatypent>, greater<datatype>>
using namespace std;
int modulo = 1e9 + 7;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
bool sorta(const pii& a, const pii& b) { return (a.second < b.second); }
bool sortd(const pii& a, const pii& b) { return (a.second > b.second); }
string decToBinary(int n)
{
    string s = "";
    int i = 0;
    while (n > 0)
    {
        s = to_string(n % 2) + s;
        n = n / 2;
        i++;
    }
    return s;
}
ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
bool isPrime(int n)
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
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool isPerfectSquare(ll x)
{
    if (x >= 0)
    {
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
ll powermod(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
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

ll ps(vector<int>& v)
{
    ll n = v.size();
    vector<pii>cum_sum(n);

    int min_ele = v[0];
    cum_sum[0] = { v[0],min_ele };

    for (int i = 2;i < n;i += 2) {
        min_ele = min(min_ele, v[i]);
        cum_sum[i] = { cum_sum[i - 2].first + v[i],min_ele };
    }

    cum_sum[1] = { v[1],v[1] };
    min_ele = v[1];

    for (int i = 3;i < n;i += 2) {
        min_ele = min(min_ele, v[i]);
        cum_sum[i] = { cum_sum[i - 2].first + v[i],min_ele };
    }

    

    

    

    


    queue<pii>q;

    int i = n / 2;
    if (n % 2) {
        i++;
    }
    q.push({ n - 1,i });
    q.push({ n - 2,n / 2 });

    ll ans=LLONG_MAX;

    while (q.size() > 1) {
        pii p = q.front();
        q.pop();
        pii p2 = q.front();

        ll temp=cum_sum[p.first].first -cum_sum[p.first].second + (n-(p.first/2))*cum_sum[p.first].second + cum_sum[p2.first].first-cum_sum[p2.first].second + (n-(p2.first/2))*cum_sum[p2.first].second;

        


        ans=min(ans,temp);
        if(p.first -2 >=0){
            q.push({p.first-2,p.second-1});
        }



       
    }

    return ans;










}

int main()
{
    Meyank Garg huehue;
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        cout << ps(nums) << endl;
    }
    return 0;
}