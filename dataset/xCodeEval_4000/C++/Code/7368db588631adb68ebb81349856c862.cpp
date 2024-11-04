







#include <bits/stdc++.h>
#include <complex>
using namespace std;
const long double PI = 3.1415926535897932384626;
typedef long long ll;
typedef vector<ll> vli;
typedef pair<ll, ll> pii;
#define f first


#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (long long int i = a; i < b; i++)


#define mod 1000000007

#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
























bool collinear(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return (y1 - y2) * (x1 - x3) != (y1 - y3) * (x1 - x2);
}
bool isInt(double num)
{
    return (num == (int)num);
}

























































































































































































































































































































































































































































































































double euclid_dist(ll x1, ll y1, ll x2, ll y2)
{
    return sqrt(abs(x1 - x2) * abs(x1 - x2) * 1.000 + abs(y1 - y2) * abs(y1 - y2) * 1.000);
}

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll binpow_mod(ll a, ll b, ll MOD)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = ((res % MOD) * (a % MOD)) % MOD;
        }
        b = b >> 1;
        a = ((a % MOD) * (a % MOD)) % MOD;
    }
    return res;
}











































































































































































































































































































































string convert_binary(ll n)
{
    string str = "";
    while (n)
    {
        if (n & 1)
        {
            str.push_back('1');
        }
        else
        {
            str.push_back('0');
        }
        n = n / 2;
    }
    reverse(str.begin(), str.end());
    return str;
}



























































































































































































































































































































































































































































































































































































































































































































































ll check(string str1, string str2)
{
    if (str2.find(str1) != string::npos)
    {
        return 1;
    }
    return 0;
}
ll findMex(vli arr, ll n)
{
    sort(arr.begin(), arr.end());
    if (arr[0] != 0)
        return 0;
    rep(i, 1, n - 1)
    {
        if (arr[i] - arr[i - 1] <= 1)
            continue;
        return arr[i - 1] + 1;
    }
    return arr[n - 1] + 1;
}
const int maxn = 2e5 + 5;

vector<int> convert_string(ll a)
{
    vector<int> ans;
    ll b = a;
    while (b)
    {
        ans.push_back(b % 10);
        b /= 10;
    }
    return ans;
}

















































































































vector<bool> prime;
void seive(int n)
{
    prime[0] = false;
    prime[1] = false;
    prime[2] = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
}














































































































ll n, m, k;
vector<vector<vector<ll>>> dp;
vector<vector<ll>> r, d;
ll recur(int i, int j, int k)
{
    if (k == 0)
    {
        return 0;
    }

    if (dp[i][j][k] != -1)
    {
        return dp[i][j][k];
    }
    ll ans = LLONG_MAX;

    if (i - 1 >= 0)
    {
        ans = min(ans, d[i - 1][j] + recur(i - 1, j, k - 1));
    }
    if (i + 1 < n)
    {
        ans = min(ans, d[i][j] + recur(i + 1, j, k - 1));
    }
    if (j - 1 >= 0)
    {
        ans = min(ans, r[i][j - 1] + recur(i, j - 1, k - 1));
    }
    if (j + 1 < m)
    {
        ans = min(ans, r[i][j] + recur(i, j + 1, k - 1));
    }

    return dp[i][j][k] = ans;
}

void update(vector<ll> &fenwick, ll i, ll val)
{
    while (i < (int)fenwick.size())
    {
        fenwick[i] += val;
        i += (i & (-i));
    }
}
ll sum(vector<ll> &fenwick, ll i)
{
    ll sm = 0;
    while (i > 0)
    {
        sm += (fenwick[i]);
        i -= (i & (-i));
    }
    return sm;
}
string removeLeadingZeros(string &num)
{
    int i = 0;
    while (num[i] == '0')
        i++;

    return num.substr(i);
}

int compareTwoLargeNumbers(string &str1, string &str2)
{
    

    


    int str1_length = str1.size();
    int str2_length = str2.size();

    if (str1_length != str2_length)
        return str1_length < str2_length ? 1 : 2;
    else
    {
        for (int i = 0; i < str1_length; i++)
        {
            if (str1[i] > str2[i])
                return 2;
            else if (str2[i] > str1[i])
                return 1;
        }
    }

    return 3;
}
void solve()
{
    string str;
    cin>>str;

    if(str=="EN"||str=="NE")
    {
        cout<<"NO\n";
        return;
    }
    int n=str.size();
    int i=0;
    int cnt=0;
    for(int i=0;i<n;i+=1)
    {
        if(str[i]=='N')
        {
            cnt+=1;
        }
    }
    if(cnt==1)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    

    

    

    

    

    

    ll t;
    scanf("%lld", &t);
    

    

    

    

    


    for (int i = 1; i <= t; i++)
    {

        

        solve();
    }

    return 0;
}









