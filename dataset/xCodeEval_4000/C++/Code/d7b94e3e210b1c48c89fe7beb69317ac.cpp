

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<  pair<ll,ll>   , null_type,less< pair<ll,ll> >, rb_tree_tag,tree_order_statistics_node_update>


using ld = long double;
 

using ii = pair<int, int>;

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back
#define nline "\n"
#define sz(x) (int)x.size()
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define debug(x) cerr << '>' << #x << ':' << x << endl;
#define all(x) (x).begin(), (x).end()
#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define product(v) accumulate(all(v), double(1), multiplies < double > ())
#define innerproduct(a,b) inner_product(all(a), (b).begin(), 0)
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define ps(x, y) fixed << setprecision(y) << x
#define google cout << "Case #" << i << ": "
bool revsort(ll a, ll b) {return a > b;}

#define maxfast(x, y) (y-x >> 31 & (x^y) ^ y)
#define minfast(x, y) (y-x >> 31 & (x^y) ^ x)
bool isPalindrome(const string& s) {
    return std::equal(s.begin(), s.end(), s.rbegin());
}

auto cmp = [](const pair<int, int>& A, const pair<int, int>& B) { 
    if(A.second == B.second) return A.first < B.first;
    return A.second < B.second; 
};

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}











template<typename... Args>int summation(int a, Args... args) { return a + summation(args...); }
template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}
template <class T> T gcd(T a , T b){ while(a != 0){T temp = a; a = b % a; b = temp;}return b;}
template <class T> T egcd(T a , T b , T &x , T &y){T gcd , xt , yt;if(a == 0){gcd = b;x = 0 , y = 1;}else {gcd = egcd(b % a , a , xt , yt);x = yt - (b/a)*xt; y = xt;}return gcd;}
template <class T> T expo(T base , T exp , T mod){T res = 1;base = base % mod;while (exp > 0){if (exp & 1)res = (res*base) % mod;exp = exp>>1;base = (base*base) % mod;}return res;}
template <class T> T modinv(T a , T mod){T x , y; egcd<T>(a , mod , x , y);while(x < 0) x += mod; while(x >= mod) x -= mod; return x;}
template <class T> T modinvfermat(T a , T mod){return expo<T>(a , mod - 2 , mod);}
template <class T> bool rev(T a , T b){return a > b;}
template <class T> ll maxpower(T a , T b){ll ans = 0;while(a >   0 && a % b == 0){ans++;a /= b;}return ans;}
template <class T> T mceil(T a, T b){if(a % b == 0) return a/b; else return a/b + 1;}
template <class T> T lcm(T a, T b){return (a*b)/gcd<T>(a, b);}

#define mod 1e9+7
#define INF 1e18

template<const int &MOD>
struct _m_int {
    int val;
 
    _m_int(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = int(v);
    }
 
    _m_int(uint64_t v) {
        if (v >= MOD) v %= MOD;
        val = int(v);
    }
 
    _m_int(int v) : _m_int(int64_t(v)) {}
    _m_int(unsigned v) : _m_int(uint64_t(v)) {}
 
    static int inv_mod(int a, int m = MOD) {
        

        int g = m, r = a, x = 0, y = 1;
 
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
 
        return x < 0 ? x + m : x;
    }
 
    explicit operator int() const { return val; }
    explicit operator unsigned() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }
 
    _m_int& operator+=(const _m_int &other) {
        val -= MOD - other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    _m_int& operator-=(const _m_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif
        

        

        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }
 
    _m_int& operator*=(const _m_int &other) {
        val = fast_mod(uint64_t(val) * other.val);
        return *this;
    }
 
    _m_int& operator/=(const _m_int &other) {
        return *this *= other.inv();
    }
 
    friend _m_int operator+(const _m_int &a, const _m_int &b) { return _m_int(a) += b; }
    friend _m_int operator-(const _m_int &a, const _m_int &b) { return _m_int(a) -= b; }
    friend _m_int operator*(const _m_int &a, const _m_int &b) { return _m_int(a) *= b; }
    friend _m_int operator/(const _m_int &a, const _m_int &b) { return _m_int(a) /= b; }
 
    _m_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    _m_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    _m_int operator++(int) { _m_int before = *this; ++*this; return before; }
    _m_int operator--(int) { _m_int before = *this; --*this; return before; }
 
    _m_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    friend bool operator==(const _m_int &a, const _m_int &b) { return a.val == b.val; }
    friend bool operator!=(const _m_int &a, const _m_int &b) { return a.val != b.val; }
    friend bool operator<(const _m_int &a, const _m_int &b) { return a.val < b.val; }
    friend bool operator>(const _m_int &a, const _m_int &b) { return a.val > b.val; }
    friend bool operator<=(const _m_int &a, const _m_int &b) { return a.val <= b.val; }
    friend bool operator>=(const _m_int &a, const _m_int &b) { return a.val >= b.val; }
 
    _m_int inv() const {
        return inv_mod(val);
    }
 
    _m_int pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);
 
        _m_int a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            p >>= 1;
 
            if (p > 0)
                a *= a;
        }
 
        return result;
    }
 
    friend ostream& operator<<(ostream &os, const _m_int &m) {
        return os << m.val;
    }
};
 
extern const int MOD = 1e9 + 7;
using mod_int = _m_int<MOD>;
 
vector<mod_int> inv, factorial, inv_factorial;
int prepared_maximum = -1;
 
void prepare_factorials(int64_t maximum) {
    static int prepare_calls = 0;
 
    if (prepare_calls++ == 0) {
        

        for (int p = 2; p * p <= MOD; p += p % 2 + 1)
            assert(MOD % p != 0);
 
        inv = {0, 1};
        factorial = inv_factorial = {1, 1};
        prepared_maximum = 1;
    }
 
    if (maximum > prepared_maximum) {
        inv.resize(maximum + 1);
        factorial.resize(maximum + 1);
        inv_factorial.resize(maximum + 1);
 
        for (int i = prepared_maximum + 1; i <= maximum; i++) {
            inv[i] = inv[MOD % i] * (MOD - MOD / i);
            factorial[i] = i * factorial[i - 1];
            inv_factorial[i] = inv[i] * inv_factorial[i - 1];
        }
 
        prepared_maximum = int(maximum);
    }
}
 
mod_int choose(int64_t n, int64_t r) {
    if (r < 0 || r > n) return 0;
    return factorial[n] * inv_factorial[r] * inv_factorial[n - r];
}
 
mod_int inv_choose(int64_t n, int64_t r) {
    assert(0 <= r && r <= n);
    return inv_factorial[n] * factorial[r] * factorial[n - r];
}
 
mod_int permute(int64_t n, int64_t r) {
    if (r < 0 || r > n) return 0;
    return factorial[n] * inv_factorial[n - r];
}
 
mod_int inv_permute(int64_t n, int64_t r) {
    assert(0 <= r && r <= n);
    return inv_factorial[n] * factorial[n - r];
}
int fact(int n)
{
    if (n <= 1)
        return 1;
    return n * fact(n - 1);
}
 
int nPr(int n, int r)
{
    return fact(n) / fact(n - r);
}


ll getC(ll n, int k)
{
    if (k > n) return 0;
    ll res = 1;
    for (int i = 0; i < k; i++)
    {
        res *= n - i;
        res /= i + 1;
    }
    return res;
}



vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);

            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}

vector<pair<int64_t, int>> prime_factorize(int64_t n) {
    int64_t sieve_max = int64_t(smallest_factor.size()) - 1;
    assert(1 <= n && n <= sieve_max * sieve_max);
    vector<pair<int64_t, int>> result;

    if (n <= sieve_max) {
        while (n != 1) {
            int64_t p = smallest_factor[n];
            int exponent = 0;

            do {
                n /= p;
                exponent++;
            } while (n % p == 0);

            result.emplace_back(p, exponent);
        }

        return result;
    }

    for (int64_t p : primes) {
        if (p * p > n)
            break;

        if (n % p == 0) {
            result.emplace_back(p, 0);

            do {
                n /= p;
                result.back().second++;
            } while (n % p == 0);
        }
    }

    if (n > 1)
        result.emplace_back(n, 1);

    return result;
}
bool check(ll n , ll a , ll b){
    while(n>0){
        if(n%10 !=a && n%10 != b){
            return false;
        }
        n/=10;
    }
    return true;
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





















void findPrefix(string pattern, int m, int prefArray[]) {
   int length = 0;
   prefArray[0] = 0;     


   for(int i = 1; i<m; i++) {
      if(pattern[i] == pattern[length]) {
         length++;
         prefArray[i] = length;    
      }else {
         if(length != 0) {
            length = prefArray[length - 1];
            i--;     

         }else
            prefArray[i] = 0;
      }
   }
}

void kmpPattSearch(string mainString, string pattern, int *locArray, int &loc) {
   int n, m, i = 0, j = 0;
   n = mainString.size();
   m = pattern.size();
   int prefixArray[m];    

   findPrefix(pattern, m, prefixArray);
   loc = 0;

   while(i < n) {
      if(mainString[i] == pattern[j]) {
         i++; j++;
      }

      if(j == m) {
         locArray[loc] = i-j;      

         loc++;
         j = prefixArray[j-1];    

      }else if(i < n && pattern[j] != mainString[i]) {
         if(j != 0)
            j = prefixArray[j-1];
         else
            i++;
      }
   }
}

int go(string pat,string c){
    int locationArray[c.size()];
    int index;
    kmpPattSearch(c, pat, locationArray, index);
    ll ans=0;
    for(int i = 0; i<index; i++) {
        cout << "Pattern visited at location: " <<locationArray[i] << endl;
    }
    return index;
}
vector<ll> pref;
void init(int n){
    pref.resize(n);
    for(int i=2;i<n;i++){
        for(int j=i+i;j<n;j+=i){
            pref[j]=1;
        }
    }
}
bool isPrime(int n)
{
    static int i = 2;
 
    

    if (n == 0 || n == 1) {
        return false;
    }
 
    

    if (n == i)
        return true;
 
    

    if (n % i == 0) {
        return false;
    }
    i++;
    return isPrime(n);
}
bool isComposite(ll n){
    bool flag=false;
    for(int i = 2; i*i <= n; i++){
        if((n % i)==0){
            flag=true;
            break;
        }
    }
    return flag;
}
int64_t mm=1e9+7 ;
ll poww(int64_t x,int64_t y,  int64_t  mm){
    if(y==0){
        return 1LL;

    }
    return (poww(( (x*x)%mm),y/2,mm)*(y&1?x:1LL)%mm);
}

void tc() {
    ll s,n,k;
    cin >> s >> n >> k;
    if(s==k){
        cout <<"YES" << nline;

    }
    else if(k>s){
        cout << "NO" << nline;
    }
    else{
        ll l=k;
        ll r=s;
        ll size= s-k;
        ll nn=(s/(k*2LL))*k;
        ll mm=s%(k*2LL);
        nn+=min(mm+1LL,k);
        if(n>=nn){
            cout << "YES" << nline;
        }
        else{
            cout << "NO" << nline;
        }
        
    }


}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    auto start = chrono::high_resolution_clock::now();
    int t=1;
    

    

    

    

    cin>>t;
    
    

    while(t--){
        

        

        tc();
    }
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-6;
    cerr << ps(time_taken, 6) << " ms" << endl;
    


 
    return 0;
}



