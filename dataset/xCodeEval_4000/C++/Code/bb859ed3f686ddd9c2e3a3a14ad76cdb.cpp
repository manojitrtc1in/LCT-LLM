
#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
using namespace chrono;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 2e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define fr(i, a, n) for (ll i = a; i < n; i++)
#define fr1(i, a, n) for (ll i = a; i <= n; i++)
#define fr2(i,n,a) for(ll i = n; i>=a; i--)
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vpl vector<pair<ll,ll>>
#define py cout<<"Yes\n";
#define pyy cout<<"YES\n";
#define pn cout<<"No\n";
#define pnn cout<<"NO\n";

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;



void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif




ll lcm(ll a, ll b)
{
    return (a / __gcd(a, b)) * b;
}

ll power(ll a, ll b, ll mod) {
    if (b == 0) {
        return 1;
    }
    ll ans = power(a, b / 2, mod);
    ans *= ans;
    ans %= mod;
    if (b % 2) {
        ans *= a;
    }
    return ans % mod;
}

ll modpow(ll x, ll n, ll m = MOD)
{
    if (x == 0 && n == 0) return 0; 

    ll res = 1;
    while (n > 0)
    {
        if (n % 2)
            res = (res * x) % m;
        x = (x * x) % m;
        n /= 2;
    }
    return res;
}

ll modinv(ll x, ll m = MOD)
{
    return modpow(x, m - 2, m);
}

ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}

ll smallestDivisor(ll n)
{
    

    if (n % 2 == 0)
        return 2;

    

    for (ll i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return i;
    }
    return n;
}

vector<ll> primeFactors(ll n)
{
    vector<ll> factors;
    while (n % 2 == 0)
    {
        factors.push_back(2);
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n = n / i;
        }
    }
    if (n > 2)
        factors.push_back(n);
    return factors;
}

bool isPrime(ll n)
{
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }

    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }

    for (ll i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}


float log_a_to_base_b(ll a, ll b)
{
    return (float)log(a) / (float)log(b);
}

class DSU {
public:
    ll n, components;
    vector<ll> parent, siz;

    DSU(ll n) {
        this->n = n;
        for (ll i = 0; i < n; ++i) {
            parent.push_back(i);
            siz.push_back(1);
        }
        components = n;
    }

    ll find_set(ll v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]); 

    }

    ll getSiz(ll node) {
        return siz[find_set(node)];
    }

    set<ll> getParents() {
        set<ll> s;
        for (ll i = 0; i < n; i++) s.insert(find_set(i));
        return s;
    }

    bool union_sets(ll a, ll b) {
        a = find_set(a);
        b = find_set(b);

        if (a == b) return false;

        if (siz[a] > siz[b]) swap(a, b);
        parent[a] = b;
        siz[b] += siz[a];

        components--;
        return true;
    }
};

vector<bool> sieve(ll n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

ll repeatedSubstringPattern(string str) {
    ll i = 1, j = 0, n = str.size();
    vector<ll> dp(n + 1, 0);
    while ( i < str.size() ) {
        if ( str[i] == str[j] ) dp[++i] = ++j;
        else if ( j == 0 ) i++;
        else j = dp[j];
    }
    if (dp[n] && dp[n] % (n - dp[n]) == 0) return n - dp[n];
    else return n;

}



#define left(i) (2*i + 1)
#define right(i) (2*i + 2)
#define parent(i) ((i-1)/2)

template<class T>
class SegmentTree
{
public:
    

    SegmentTree(std::vector<T> data, T value, T (*combine)(T obj1, T obj2));
    SegmentTree(T ar[], int n, T value, T (*combine)(T obj1, T obj2));

    

    T query(int l, int r);

    

    void update(int idx, T val);
    

private:
    

    T *tree;

    

    void buildTree(std::vector<T> data);

    

    int segTreeSize;

    

    

    T valueForExtraNodes;

    

    T (*combine)(T obj1, T obj2);

    

    int calculateSize(int n);

    

    T queryHelper(int l, int r, int st, int ed, int node);
};

template<class T> SegmentTree<T>::SegmentTree(std::vector<T> data,
        T value, T (*combine)(T obj1, T obj2))
{
    this->combine = combine;
    valueForExtraNodes = value;
    segTreeSize = calculateSize(data.size());
    buildTree(data);
}

template<class T> SegmentTree<T>::SegmentTree(T ar[], int n,
        T value, T (*combine)(T obj1, T obj2))
{
    this->combine = combine;
    valueForExtraNodes = value;
    segTreeSize = calculateSize(n);

    std::vector<T> data;
    for (int i = 0; i < n; i++)
        data.push_back(ar[i]);

    buildTree(data);
}


template<class T> int SegmentTree<T>::calculateSize(int n)
{
    int pow2 = 1;
    while ( pow2 < n)
    {
        pow2 = pow2 << 1;
    }
    return 2 * pow2 - 1;
}

template<class T> T SegmentTree<T>::query(int l, int r)
{
    int st = 0, ed = segTreeSize / 2;
    return queryHelper(l, r, st, ed, 0);
}

template<class T> T SegmentTree<T>::queryHelper(int l, int r, int st, int ed, int node)
{
    if ( (r < st) || (l > ed) || (l > r) )
        return valueForExtraNodes;
    if (st >= l && ed <= r)
        return tree[node];
    T leftVal = queryHelper(l, r, st, (st + ed) / 2, left(node));
    T rightVal = queryHelper(l, r, (st + ed) / 2 + 1, ed, right(node));
    return combine(leftVal, rightVal);
}

template<class T> void SegmentTree<T>::buildTree(std::vector<T> data)
{
    int n = data.size();
    tree = new T[segTreeSize];
    int extraNodes = (segTreeSize / 2 + 1) - n;
    for (int i = segTreeSize - 1; i >= 0; i--)
    {
        if (extraNodes > 0)
        {
            tree[i] = valueForExtraNodes;
            extraNodes--;
        }
        else if (n > 0)
        {
            tree[i] = data[n - 1];
            n--;
        }
        else
            tree[i] = combine(tree[left(i)], tree[right(i)]);
    }
}

template<class T> void SegmentTree<T>::update(int idx, T val)
{
    int segTreeIdx = (segTreeSize / 2) + idx;
    tree[segTreeIdx] = val;
    while (parent(segTreeIdx) >= 0)
    {
        segTreeIdx = parent(segTreeIdx);
        if (right(segTreeIdx) < segTreeSize)
            tree[segTreeIdx] = combine(tree[left(segTreeIdx)], tree[right(segTreeIdx)]);
        if (segTreeIdx == 0)
            break;
    }
}







ll tc = 1;

bool sortbysec(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    return (a.second < b.second);
}
const ll maxn = 1e6 + 1;





vl getfactors(ll n) {
    vl factorss;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factorss.pb(i);
            if (i * i != n) {
                factorss.pb(n / i);
            }
        }
    }
    return factorss;
}

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


string s;

ll rec(ll i , ll j , vector<vector<ll>> &dp) { 

    if (i + 1 == j) {
        if (s[i] == s[j]) {
            return dp[i][j] = 1;   

        } else {
            return dp[i][j] = 2;  

        }
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    ll res1 = rec(i + 1 , j - 1 , dp); 

    ll res2 = rec(i + 2 , j , dp); 

    ll res3 = rec(i , j - 2 , dp); 


    if (res1 == 1) { 

        if (s[i] != s[j]) { 

            res1 = 2;
        }
    }
    if (res2 == 1) { 

        if (s[i] < s[i + 1]) { 

            res2 = 2;
        } else { 

            res2 = 0;
        }
    }
    if (res3 == 1) { 

        if (s[j] < s[j - 1]) { 

            res3 = 2;
        } else { 

            res3 = 0;
        }
    }

    if (res1 == 2 and res2 == 2) { 

        return dp[i][j] = 2;     

    }
    if (res1 == 2 and res3 == 2) { 

        return dp[i][j] = 2;     

    }
    return dp[i][j] = 1; 

}                        


void solve()
{
    cin >> s;
    ll n = s.length() - 1;
    vector<vector<ll>> dp(n+1 , vl(n+1 , -1));
    rec(0 , n , dp);
    if (dp[0][n] == 1) {
        cout << "Draw" << nline;
    } else if (dp[0][n] == 2) {
        cout << "Alice" << nline;
    } else {
        cout << "Bob" << nline;
    }
    assert(dp[0][n] != 0);
}


int main()
{

#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    fastio();

    auto start1 = high_resolution_clock::now();

    cin >> tc;
    

    

    

    

    

    


    

    

    

    

    

    



    for (ll i = 1; i <= tc; i++)
    {
        

        solve();
    }

    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
#endif
    return 0;
}


