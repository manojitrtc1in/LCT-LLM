
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define call(x)#x
#define fo(i,n)        for(int i=0;i<n;i++)
#define Fo(i,k,n)    for(int i=k;i<n;i++)
#define vi            vector<int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pi 3.1415926535
#define set_bits __builtin_popcountll

typedef long long ll;
typedef unsigned long long ull;
ll mod = (ll) 1e9 + 7;

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" "; _print(x) ;  cerr<< "\n";
#else
#define debug(x)
#endif
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

ll setBitNumber(ll n)
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

ll  nextPowerOf2(ll  n)
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
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
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
void divisors(ll num)
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


int cntConneceted(int n, vector<int> adj[] )
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


int ceil_log2( long long x)
{
    static const unsigned long long t[6] = {
        0xFFFFFFFF00000000ull,
        0x00000000FFFF0000ull,
        0x000000000000FF00ull,
        0x00000000000000F0ull,
        0x000000000000000Cull,
        0x0000000000000002ull
    };

    int y = (((x & (x - 1)) == 0) ? 0 : 1);
    int j = 32;
    int i;

    for (i = 0; i < 6; i++) {
        int k = (((x & t[i]) == 0) ? 0 : j);
        y += k;
        x >>= k;
        j >>= 1;
    }

    return y;
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

bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}





bool dfsCycle(int i, vector<bool> &vis, vector<vector<int>> &prerequisites)
{
    if (vis[i] == 1)
        return true;

    vis[i] = 1;
    for (int j = 0; j < (int)prerequisites[i].size(); j++)
    {
        if (vis[prerequisites[i][j]] == 0)
            dfsCycle(i, vis, prerequisites);
        else
            return true;
    }

    return false;
}


struct node {
    int data;
    struct node * left, * right;
};





void get_children(node * n1, vector<int>& res,  node * parent) {

    if (n1 == NULL)
        return;

    if (n1->data > parent->data)
    {
        res.push_back(n1->data);
    }

    get_children(n1->left, res, parent);

    get_children(n1->right, res, parent);


}

void inOrderTrav(node * curr, vector < int > & inOrder) {
    if (curr == NULL)
        return;

    vector<int>temp;



    get_children(curr->left, temp, curr);


    get_children(curr->right, temp, curr);
    


    inOrderTrav(curr -> left, inOrder);

    inOrder.push_back(curr -> data);

    inOrderTrav(curr -> right, inOrder);
}




ll maxSubArraySum(vector<ll>a, ll size)
{
    ll max_so_far = INT_MIN, max_ending_here = 0;

    for (ll i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

ll maxSumK(vector<ll>v , ll n, ll k)
{

    ll res = 0;

    for (ll i = 0; i < k; i++)
        res += v[i];

    ll curr_sum = res;

    for (ll i = k; i < n; i++)
    {
        curr_sum += v[i] - v[i - k];

        res = max(res, curr_sum);
    }
    return res;

}



bool isPalindrome(string &s)
{

    int n = (int)s.size();

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] == s[n - i - 1])
        {

        }
        else
        {
            return false;
        }
    }
    return 1;
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

int g = 0;
void dfs(int n , int n1, vector< pair<int, int>> adj[] , vector<int> &vis , vector<pair<int, int>> &storeDfs )
{
    if (vis[n] == 1)
        return;
    vis[n] = 1;

    storeDfs.push_back({n, n1});
    for (auto it : adj[n])
    {
        if (!vis[it.first])
        {
            dfs(it.first, adj[it.first][0].second, adj , vis, storeDfs);
        }
    }


}



ll binaryToDecimal(string n)
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



void dfsg(int n, vector<int> adj[], vector<int> &ket, vector<int> &vis)
{
    if (vis[n] == 1)
        return;

    vis[n] = 1;
    ket.push_back(n);
    for (int it : adj[n])
    {
        if (vis[it] == 0)
            dfsg(it, adj, ket, vis);
        

    }

}

int b_s(vector<pair<int, int>> temp, int e )
{
    int r = (int)temp.size() - 1;
    int l = 0;
    int index = 0;
    while (l <= r)
    {
        int mid = (l) + (r - l) / 2;
        if (temp[mid].first == e)
        {
            index = mid;
            break;
        }

        if (temp[mid].first < e)
        {
            index = mid;
            l = mid + 1;
        }
        else
        {
            index = mid;
            r = mid - 1;

        }

    }
    debug(index)
    return index;

}


void  solve()
{


    int n, k;
    cin >> n >> k;

    vector<int>v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    ll ans = 0;

    for (int i = 0; i < n; i++)
        ans += (v[i] / k);
    debug(ans)

    vector<int>ket(n);
    for (int i = 0; i < n; i++)
        ket[i] = v[i] % k;




    sort(all(ket));
    debug(ket)

    multiset<int>mp(all(ket));

    for (int i = 0; i < n; i++)
    {
        int ele = k - ket[i];

        auto it = mp.find(ket[i]);
        if (it != mp.end())
        {
            mp.erase(it);
            auto ik = mp.lower_bound(ele);
            if (ik != mp.end())
            {
                mp.erase(ik);
                ans++;
            }
        }
        debug(ket[i])
        debug(ele)
        debug(ans)
        

        

        

        

    }
    cout << ans << "\n";




}




int  main()
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