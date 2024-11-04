







#include <bits/stdc++.h>
#include <complex>
using namespace std;
const long double PI = 3.1415926535897932384626;
typedef long long ll;
typedef vector<ll> vli;
typedef pair<ll, ll> pii;
#define f first
#define s second
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

ll modularexponentiation(ll a, ll b, ll MOD)
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
vector<int> adj[200005];
vector<int> level(200005, 0);
ll parent[200005][22];
ll n, q;
void dfs(int curr, int par, int h)
{
    level[curr] = h;
    if (par != -1)
    {
        parent[curr][0] = par;
    }
    for (auto it : adj[curr])
    {
        if (it != par)
        {
            dfs(it, curr, h + 1);
        }
    }
}
void preprocess_lca()
{
    dfs(1, -1, 1);

    for (int j = 1; j <= 21; j++)
    {
        

        for (int i = 1; i <= n; i++)
        {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
            

        }
        

    }
}

void query(ll x, ll k)
{
    int cnt = 0;
    while (k)
    {
        if (k & 1)
        {
            x = parent[x][cnt];
        }
        cnt += 1;
        k = k >> 1;
    }
    if (x != 0)
    {
        cout << x << "\n";
    }
    else
    {
        cout << "-1\n";
    }
    return;
}
vector<bool> prime;
void seive(int n)
{
    prime[0] = false;
    prime[1] = false;
    prime[2] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (!prime[i])
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                prime[j] = true;
            }
        }
    }
}
vector<vector<bool>> visited(1005, vector<bool>(1005, false));
ll m;


void solve()
{
    string str;
    cin>>str;

    int cnt1=0,cnt2=0;
    for(int i=0;i<(int)str.size();i++)
    {
        if(str[i]=='E')
        {
            cnt1++;
        }
        else
        {
            cnt2++;
        }
    }
    if(cnt2==1)
    {
        cout<<"NO\n";
    }
    else
    {
        cout<<"YES\n";
    }
}

int main()
{

    

    

    

    

    

    

    ll t;
    scanf("%lld", &t);
    

    

    for (int i = 1; i <= t; i++)
    {
        

        solve();
    }
}









