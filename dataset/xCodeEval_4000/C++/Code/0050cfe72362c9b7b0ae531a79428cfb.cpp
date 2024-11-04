#include<bits/stdc++.h>
#define ll long long int
#define vi                  vector<ll>
#define f(i,n) for(int i=0;i<n;i++)
#define ff(j,n) for(int j=1;j<n;j++)

using namespace std;



































































































































































































































































ll fastmodexp(ll a, ll b , ll m)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b = b >> 1;
    }
    return res;
}

ll power(ll a, ll b)
{
    if (b == 0)
    {
        return 1;
    }

    ll ans = power(a, b / 2) * power(a, b / 2);
    if (b & 1)
    {
        ans *= a;
    }
    return ans;
}

vector<int>v[40];
vector<int>vv(40, 0);
vector<int>l(40, -1);

void bfs(int u)
{
    queue<int>q;
    q.push(u);
    vv[u] = 1;
    l[u] = 0;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        


        for (auto i : v[f])
        {
            if (vv[i] == 0)
            {
                l[i] = l[f] + 1;
                q.push(i);
                vv[i] = 1;

            }
        }
    }
}

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int x()
{
    return 1;
    return 2;
    return 3;
}


int equalPartition(int N, int arr[])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
    }

    if (sum % 2 != 0)
    {
        return 0;
    }

    int m = sum / 2;
    bool dp[N + 1][m + 1];

    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = true;
    }

    for (int j = 1; j <= sum / 2; j++)
    {
        dp[0][j] = false;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= m ; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
            }

            else
            {
                dp[i][j] = (dp[i - 1][j]);
            }
        }
    }

    return (dp[N][m]);



}

ll modFact(ll n, ll p)
{
    if (n >= p)
        return 0;

    ll result = 1;
    for (ll i = 1; i <= n; i++)
        result = (result * i) % p;

    return result;
}

void solve() {
    ll n, k; cin >> n >> k;
    ll ans = 1;
    for (ll i = 0; i < k; i++)
    {   ans = (ans * n) % 1000000007;
    }
    cout << ans << endl;
}

ll p(ll n, ll k, ll m = 1000000007)
{
    ll ans = 1 ;
    for (ll i = 0; i < k; i++)
    {
        ans = (ans * n) % m;
    }
    return ans;
}


vector<int>vect;
void SieveOfEratosthenes(int n)
{

    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        

        

        if (prime[p] == true)
        {

            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    

    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
        {
            vect.push_back(p);
        }
    }
}

int cmp(pair<int, int> a, pair<int, int> b)
{
    return (a.second < b.second);
}

ll fact(ll n)
{
    if (n == 1)
    {
        return 1;
    }

    return (n * fact(n - 1) % 1000000007);

}

ll mod = 1000000007;

ll dp[200001][11];
ll sol(ll m, ll x)
{
    if (m == 0) return 0;
    

    if (dp[m][x] != -1) return dp[m][x];
    dp[m][x] = 0;
    if (m >= 10 - x) dp[m][x] = (sol(m - (10 - x), 1) % mod + 1 + sol(m - (10 - x), 0) % mod) % mod;
    return dp[m][x];
}

ll c(ll a, ll b)
{
    return (a > b);
}




































































































































































const int _MAX = 10000;
vector<int>children[_MAX];
int depth[_MAX];

const int LOG = 14;

int up[_MAX][LOG];




void dfs(int a)
{
    for (int b : children[a])
    {
        up[b][0] = a;
        depth[b] = depth[a] + 1;
        for (int i = 1; i < LOG ; i++)
        {
            up[b][i] = up[up[b][i - 1]][i - 1];
        }

        dfs(b);
    }
}



int get_lca(int a, int b)
{
    if (depth[a] < depth[b])
    {
        swap(a, b);
    }

    int k = depth[a] - depth[b];

    


    for (int i = LOG - 1; i >= 0; i--)
    {
        if (k & (1 << i))
        {
            a = up[a][i];
        }
    }

    if (a == b)
    {
        return a;
    }

    for (int i = LOG - 1; i >= 0; i--)
    {
        if (up[a][i] != up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}

const ll MOD = 1e9 + 7;

ll solve(ll n)
{
    ll ans = 0;

    ll lcm = 1;
    for (ll i = 2;; i++)
    {
        if (lcm > n)
        {
            break;
        }
        ll left = n / lcm;

        lcm = (lcm / (__gcd(i , lcm))) * i;

        ll right = n / lcm;

        ans = (ans + (left - right) * i) % MOD;
    }

    return ans;

}














































ll cmp()
{
    ll a, b;
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}




ll divide(ll a, ll b)
{
    return (a + b - 1) / b;
}



ll soln(ll W, ll H, ll x1 , ll y1 , ll x2, ll y2, ll w, ll h)
{
    ll a = W;
    ll b = H - y2;

    ll c = W;
    ll d = y1;

    ll e = x1;
    ll f = H;

    ll g = W - x2;
    ll hh = H;

    if ((w <= a && h <= b ) || (w <= c && h <= d ) || (w <= e && h <= f) || (w <= g && h <= hh ))
    {
        cout << fixed << setprecision(9) << double(0) << endl;
    }
    else
    {
        ll up = INT_MAX, dn = INT_MAX, left = INT_MAX, right = INT_MAX;
        if ((H - abs(y1 - y2)) >= h)
        {
            ll xx = (H - h);
            up = min(up, abs(y2 - xx));
        }
        if ((H - abs(y1 - y2)) >= h)
        {
            dn = abs(h - y1);
        }
        if ((W - abs(x1 - x2)) >= w)
        {
            left = abs(x1 - w);
        }
        if ((W - abs(x1 - x2)) >= w)
        {
            right = abs(x2 - abs(W - w));
        }

        cout << fixed << setprecision(9) << double(min(up, min(min(dn, left), right))) << endl;
    }
    return 0;
}














bool cc(string a, string b)
{
    return (a + b  < b + a );
}


multiset<int>s;

void erase(int x) {
    s.erase(s.find(x));
}


bool C(vector<int>a, vector<int>b)
{
    return a.size() < b.size();
}


bool isPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}


void run_case() {
    int64_t A, S;
    cin >> A >> S;
    string B;

    while (S > 0) {
        int64_t D = A % 10;
        int64_t SD = S % 10;
        int64_t BD = (10 + SD - D) % 10;

        if (D + BD == SD) {
            B = to_string(BD) + B;
            A /= 10;
            S /= 10;
        } else if (D + BD == S % 100) {
            B = to_string(BD) + B;
            A /= 10;
            S /= 100;
        } else {
            cout << -1 << '\n';
            return;
        }
    }

    if (A != 0) {
        cout << -1 << '\n';
        return;
    }

    

    


    cout << B << '\n';
}


int main()
{
    

#ifndef ONLINE_JUDGE
    

    freopen("input.txt", "r", stdin);
    

    freopen("output.txt", "w", stdout);
#endif
    

    


    int t;
    cin >> t;
    while (t--)
    {
        string a , b;
        cin >> a >> b;

        sort(a.begin(), a.end());
        



        if (a.length() < b.length())
        {
            cout << a << endl;
        }
        else if (a == b)
        {
            swap(a[2], a[1]);
            cout << a << endl;
        }
        else if (b == "abc" && a.length() > b.length())
        {
            int x = -1 , y = -1, z = -1;
            for (int i = 0; i < a.length(); i++)
            {
                if (a[i] == 'b')
                {
                    x = i;
                    break;
                }
            }

            for (int i = 0; i < a.length(); i++)
            {
                if (a[i] == 'a')
                {
                    z = i;
                    break;
                }
            }

            for (int i = a.length() - 1; i >= 0; i--)
            {
                if (a[i] == 'c')
                {
                    y = i;
                    break;
                }
            }
            


            while (x < y && x != -1 && y != -1 && z != -1)
            {
                swap(a[x], a[y]);
                x++; y--;
            }

            

            cout << a << endl;
        }
        else
        {
            cout << a << endl;
        }
    }
}




































