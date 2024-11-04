

using namespace std;











typedef long long ll;
typedef unsigned long long ull;
ll mod = (ll) 1e9 + 7;






void _print(int a) {cerr << a;}
void _print(bool a) {cerr << a;}
void _print(ull a) {cerr << a;}
void _print(ll a) {cerr << a;}
void _print(double a) {cerr << a;}
void _print(string s) {cerr << s;}



template <class T> void _print(std::vector<T> v) {cerr << "[ "; for (T i  : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(std::set<T>s) {cerr << "[ "; for (T i  : s) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(std::multiset<T>s) {cerr << "[ "; for (T i  : s) {_print(i); cerr << " ";} cerr << "]";}


ll mod_add(ll a, ll b, ll M) {a = a % M; b = b % M; return (((a + b) % M) + M) % M;}
ll mod_mul(ll a, ll b, ll mod) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
ll mod_sub(ll a, ll b, ll M) {a = a % M; b = b % M; return (((a - b) % M) + M) % M;}

























ll ceil2(ll a, ll b) {
    ll c = a / b;
    if (c * b < a) c++;
    return c;
}

ll id7(ll n)
{

    

    

    

    ll k = (ll)(log2(n));

    

    

    

    return  k;
}
bool pow2(ll n)
{
    if (n == 0)
        return false;

    return (ceil(log2(n)) == floor(log2(n)));
}

ll  id6(ll  n)
{
    ll  p = 1;
    if (n && !(n & (n - 1)))
        return n;

    while (p < n)
        p <<= 1;

    return p;
}



ll binpow(ll a, ll b, ll m) {
    if (b == 0)
        return 1;
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;  

    }
    return res;
}

ll fact(ll n);

ll nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
}



ll fact(ll n)
{

    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = (res * i) % mod;
    return res;
}

struct neal {
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t id3 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id3);
    }
};


long long gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}



long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}


bool isPrime(ll n)
{
    

    if (n <= 1)
        return false;

    

    for (ll i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}






























vector<ll>primef;
void primeFactors(ll n)
{
    while (n % 2 == 0)
    {
        

        primef.push_back(2);
        n = n / 2;
    }

    for (ll i = 3; i <= (ll)sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            

            primef.push_back(i);
            n = n / i;
        }
    }

    if (n > 2) {
        primef.push_back(n);
    }
}


vector<ll>proper_d;
void id0(ll num)
{
    ll result = 0;
    if (num == 1) {
        proper_d.push_back(result);
        return ;
    }
    for (ll i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            if (i == (num / i))
                proper_d.push_back(i);
            else {
                proper_d.push_back(i);
                proper_d.push_back(num / i);
            }
        }
    }

    proper_d.push_back(1);
    return;
}




ll id8(string n)
{
    string num = n;
    ll dec_value = 0;

    

    ll base = 1;

    ll len = num.length();
    for (ll i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}

ll findMean(vector<ll>a, ll n)
{
    ll sum = 0;
    for (ll i = 0; i < n; i++)
        sum += a[i];

    return (ll)sum / (ll)n;
}

vector<ll>med;


void findMedian( vector<ll>a, ll n)
{
    

    sort(all(a));

    

    if (n % 2 != 0) {
        med.push_back(a[n / 2]);
        return ;
    }
    med.push_back(a[(n - 1) / 2]);
    med.push_back((a[n / 2]));

    return ;
}


ll powerTow(ll a) {
    ll x = 1;
    fo(i, a) {
        x *= 2;
    }
    return x;
}


bool isComposite(ll  i)
{
    for ( ll  j = 2; j < i; j++)
    {
        if (i % j == 0)
        {   return true;    }
    }
    return false;
}

bool sorn(const pair<int, int> &a,
          const pair<int, int> &b)
{
    return (a.first > b.first);

    if (a.first == b.first)
        return (a.second < b.second);
}









ll evenSum(ll n)
{
    

    return (n * (n + 1)) ;
}

bool isPalindrome(string S)
{
    

    

    string P = S;

    

    reverse(P.begin(), P.end());

    

    if (S == P) {
        

        return 1;
    }
    

    else {
        

        return 0;
    }
}





bool sort1(const pair<int, int> &a,
           const pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return b.second < a.second;
    }

    return a.first < b.first;
}

const ll limit = 2e5 + 10;





void dfs(int v, vector<int> adj[], vector<bool> &vis)
{
    vis[v] = true;

    for (auto it : adj[v])
    {
        if (vis[it] == false)
            dfs(it, adj, vis);

    }
}


int id4(int n, vector<int> adj[] )
{
    int cnt = 0;

    vector<bool>vis(n + 1, 0);

    for (int i = 0; i <= n; i++)
        vis[i] = false;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] )
        {
            dfs(i, adj, vis);
            cnt++;
        }
    }

    return cnt;
}
ll p(ll n, ll ket)
{
    ll ans = 1;

    for (int i = 1; i <= ket; i++)
        ans = (ans * n) % mod;

    return ans;

}

bool solveR(vector<int> &v, vector<vector<ll>> &dp , ll sum, int n)
{
    if (sum == 0)
        return true;
    if (sum < 0)
        return false;
    if (n < 0)
        return false;

    if (dp[n][sum] != -1)
        return dp[n][sum];

    


    bool op1 = solveR(v, dp,  sum - v[n], n - 1);
    bool op2 = solveR(v, dp,  sum, n - 1);

    bool ans;

    ans = op1 or op2;

    return dp[n][sum] = ans;


}


ll rut = 0;
ll maxSum(vector<ll>arr , ll n, ll k)
{
    



    

    ll res = 0;
    for (ll i = 0; i < k; i++)
        res += arr[i];

    

    

    

    

    ll curr_sum = res;
    for (ll i = k; i < n; i++)
    {
        curr_sum += arr[i] - arr[i - k];
        res = max(res, curr_sum);
    }

    return res;
}


ll id1(vector<ll>a, ll size)
{
    ll id5 = INT_MIN, id2 = 0;
    ll cnt = 0;
    for (ll i = 0; i < size; i++)
    {
        id2 = id2 + a[i];
        cnt++;
        if (id5 < id2) {
            id5 = id2;
            rut = max(rut, cnt);
        }

        if (id2 < 0) {
            id2 = 0;
            cnt = 0;
        }
    }
    return id5;
}









ll  factorial(ll  n)
{
    if (n == 0)
        return 1;
    ll ans = 1;
    for (ll i = 1; i <= n; i++)
        ans = ans * i;
    return ans;

}



int id9( int W, vector<ll> a, int n, int cnt )
{

    if (n == 0 || W == 0)
        return cnt;

    if (a[n - 1] > W) {
        return id9(W, a, n - 1, cnt);
    }


    else
        return min(id9(W - a[n - 1], a, n - 1, cnt + 1),
                   id9(W, a, n - 1, cnt));

}


void dfs(int i, vector<int> adj[] , int &cnt, int parent, vector<int> &v)
{

    if (adj[i].size() == 0)
        return;
    debug(v[i])
    debug(parent)
    if (v[i] > parent)
        cnt++;


    for (int it : adj[i])
    {
        dfs(it, adj, cnt, parent, v);
    }


}







void  solve()
{



    int n;
    cin >> n;


    vector<ll> ket;










    ll turika = n % 3;
    ll res = n / 3;
    ll rem = n % 3;


    

    

    

    

    

    

    

    

    


    

    

    


    

    

    

    

    

    

    


    


    if (n % 3 == 0)
    {
        turika = 2;

        turika = 2;
        turika = 2;
        turika = 2;

    }






                                                                while (n)
                                                                {

                                                                    n -= turika;
                                                                    

                                                                    



                                                                    

                                                                    

                                                                    

                                                                    

                                                                    

                                                                    

                                                                    

                                                                    

                                                                    


                                                                    

                                                                    

                                                                    


                                                                    

                                                                    

                                                                    

                                                                    

                                                                    

                                                                    

                                                                    


                                                                    

                                                                    ket.push_back(turika);


                                                                    turika = 3 - turika;


                                                                }





    



    

    

    

    

    

    

    

    

    


    

    

    


    

    

    

    

    

    

    


    




for (int i = 0; i < ket.size(); i++)
    {





cout << ket[i];
}



    cout << "\n";






}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed;
    cout << setprecision(10);

    

    

    

    

    







    ll t = 1;

    cin >> t;

    while (t-- > 0)
    {


        

        solve();
        


    }

}