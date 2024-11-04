

#include <bits/stdc++.h>


using namespace std;
using namespace chrono;


#define nline "\n"
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
#define mod (ll)1000000007
#define MAXN (int)2e5 + 5
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ppb pop_back
#define setbits(x) __builtin_popcountll(x)
#define inf 1e18
#define sz(v) (int)(v.size())
#define all(v) (v).begin(), (v).end()
#define PI 3.14159265358979323846264
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
    

    

    


    using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
using vi = vector<int>;
using vpii = vector<pii>;
using vb = vector<bool>;


bool search(ll *a, int n, ll k) {int lo = 0, hi = n - 1; while (lo <= hi) {int mid = (lo + hi) / 2; if (a[mid] == k) {return true;} else if (a[mid] < k) {lo = mid + 1;} else {hi = mid - 1;}} return false;}



template <typename T>
void print(T t)
{
    for (const auto &e : t)
    {
        cout << e << " ";
    }
    cout << nline;
}
template <typename T>
void printPairs(T t)
{
    for (const auto &e : t)
    {
        cout << e.ff << " " << e.ss << "\n";
    }
}
template <typename T>
void printBits(T t){
    cout << bitset<31> (t) << nline;
}
template <typename T>
void input(T &t)
{
    for (auto &e : t)
    {
        cin >> e;
    }
}





ll hash_value(const string s) {const ll p = 31; const ll m = 1e9 + 9; ll num = 0; ll p_pow = 1; for (auto e : s) {num = (num + (e - 'a' + 1) * p_pow) % m; p_pow = (p_pow * p) % m;} return num;}
vector<vector<int>> groupIdenticalstrings(vector<string> s) {int n = sz(s); vector<pair<ll, ll>> hashes(n); for (int i = 0; i < n; i++) {hashes[i] = {hash_value(s[i]), i};} sort(all(hashes)); vector<vector<int>> groups; for (int i = 0; i < n; i++) {if (i == 0 || hashes[i].first != hashes[i - 1].first) {hashes.emplace_back();} groups.back().push_back(hashes[i].second);} return groups;}
vector<int> rabin_karp(string s, string t) {const ll p = 31; const ll m = 1e9 + 9; vector<ll> p_pow(max(sz(s), sz(t))); p_pow[0] = 1; for (int i = 1; i < sz(p_pow); i++) {p_pow[i] = (p_pow[i - 1] * p) % m;} vector<ll> h(sz(t) + 1, 0); for (int i = 0; i < sz(t); i++) {h[i + 1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;} ll h_s = 0; for (int i = 0; i < sz(s); i++) {h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;} vector<int> pos; for (int i = 0; i + sz(s) - 1 < sz(t); i++) {ll curr_h = (h[i + sz(s)] + m - h[i]) % m; if (curr_h == h_s * p_pow[i] % m) {pos.push_back(i);}} return pos;}
vector<int> prefix_function(string s) {int n = sz(s); vector<int> pi = vector<int>(n, 0); for (int i = 1; i < n; i++) {int j = pi[i - 1]; while (j > 0 && s[i] != s[j]) {j = pi[j - 1];} if (s[i] == s[j]) {j++;} pi[i] = j;} return pi;}
vector<int> kmp(string s, string t) {string res = s + '#' + t; vector<int> pos; vector<int> pi = prefix_function(res); for (int i = 0; i < sz(res); i++) {if (pi[i] == sz(s)) {pos.pb(i - 2 * sz(s));}} return pos;}
void AllPalindromesInAString(string s, vector<int> &d1, vector<int> &d2) {int n = s.length(); for (int i = 0, l = 0, r = -1; i < n; i++) {int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1); while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {k++;} d1[i] = k--; if (i + k > r) {l = i - k; r = i + k;}} for (int i = 0, l = 0, r = -1; i < n; i++) {int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1); while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {k++;} d2[i] = k--; if (i + k > r) {l = i - k - 1; r = i + k;}}}
bool isPalindrome(string s) {int st = 0, end = sz(s) - 1; while (st <= end) {if (s[st] != s[end]) {return false;} st++; end--;} return true;}
bool checkSubsequence(string S, string target) {stack<char> s; for (int i = 0; i < sz(target); i++) {s.push(target[i]);} for (int i = sz(S) - 1; i >= 0; i--) {if (s.empty()) {return true;} if (S[i] == s.top()) {s.pop();}} return s.empty() ? true : false;}







bool isPrime(ll n) {if (n == 1) {return false;} if (n == 2 || n == 3 || n == 5 || n == 7) {return true;} if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0) {return false;} for (ll i = 3; i * i <= n; i += 6) {if (n % (i + 2) == 0 || n % (i + 4) == 0) {return false;}} return true;}
bool distinctPowersOfNumber(ll n, ll number) {while (n > 0) {if (n % number >= 2) {return false;} n /= number;} return true;}
string precisionCompute(ll x, ll y, ll n) {string s = ""; ll d = x / y; for (int i = 0; i <= n; i++) {s += to_string(d); x = x - (y * d); if (x == 0)break; x = x * 10; d = x / y; if (i == 0)s += '.';} return s;}
pair<ll, ll> getCommon(pair<ll, ll> a, pair<ll, ll> b) {vector<pair<ll, ll>> v = {a, b}; sort(all(v)); a = v[0]; b = v[1]; if (a.second < b.first) {return {1e18, 1e18};} else {return {b.first, min(a.second, b.ss)};}}
ll nC2(ll n) {return (n * (n - 1)) / 2;}
ll msb(ll n) {return (int)(log2l(n));}
bool CheckSubArraySum(vector<ll> arr, ll sum) {ll n = sz(arr); ll curr_sum = arr[0], start = 0, i; for (i = 1; i <= n; i++) {while (curr_sum > sum && start < i - 1) {curr_sum = curr_sum - arr[start]; start++;} if (curr_sum == sum) {return true;} if (i < n)curr_sum = curr_sum + arr[i];} return false;}
ll lcm(ll a, ll b) {return (a * b) / (__gcd(a, b));}
bool isPowerOf2(ll n) {return n && !(n & (n - 1));}
bool isPerfectSquare(ll n) {ll y = sqrtl(n); return (y * y == n);}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll p) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % p; a = (a * a) % p; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} 

ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} 

ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
vector<bool> p;
vector<ll> primes;
void sieve(ll n){p = vector<bool>(n + 1, true);p[0] = p[1] = false;for (int i = 2; i * i <= n; i++){if (p[i]){primes.push_back(i);for (int j = i * i; j <= n; j += i){p[j] = false;}}}}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  

ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} 

ll maxSubArraySum(vll a){ll max_so_far = a[0];ll curr_max = a[0];int n = sz(a);for (int i = 1; i < n; i++){curr_max = max(a[i], curr_max + a[i]);max_so_far = max(max_so_far, curr_max);}return max_so_far;}
bool isSet(ll n, ll pos){return ((1ll << pos) & (n));}






struct cmp1 {

    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
        int lena = a.second - a.first + 1;
        int lenb = b.second - b.first + 1;
        if (lena == lenb) return a.first < b.first;
        return lena > lenb;
    }
};
struct cmp2 { 

    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
        if(a.ss == b.ss){
            return a.ff <= b.ff;
        }
        return a.ss > b.ss;
    }
};


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

void _print(int t) {cerr << t;}
void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}






set<ll> s;

bool helper(ll n, ll val){

    if(n != val){
        if(s.find(n) != s.end()){
            return true;
        }
    }
    if(n <= 0){
        return false;
    }
    if(n % 2 == 0){
        if(n % 4 == 0){
            return helper(n / 4, val);
        }
        else{
            return false;
        }
    }
    else{
        ll x = (n - 1) / 2;
        if(x <= 0){
            return false;
        }
        else{
            return helper(x, val);
        }
    }
}

void solve(){
    ll n, p;
    cin >> n >> p;
    
    vector<ll> dp(2e5 + 5);
    ll val = 0;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        val = max(val, x);
        s.insert(x);
    }
    
    set<ll> res = s;
    for(auto e : res){
        if(helper(e, e)){
            s.erase(e);
        }
    }
    for(auto e : s){
        ll x = msb(e);
        dp[x]++;
    }
    ll ans = 0;
    ans += (dp[0]) % mod;
    for(ll i = 1; i < p; i++){
        if(i == 1){
            dp[i] = (dp[i] + dp[i - 1]) % mod;
        }
        else{
            dp[i] = ((dp[i] + dp[i - 1]) % mod + dp[i - 2]) % mod;
        }
        ans += dp[i];
        ans %= mod;
    }
    cout << ans << nline;
}   

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    fastio();
    auto start1 = high_resolution_clock::now();
    
    ll t = 1;   
    

    
    while (t--) {
        solve();
    }
    
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);

#ifndef ONLINE_JUDGE
    cerr << "Time: " << duration . count() / 1000 << nline;
#endif

    return 0;
}