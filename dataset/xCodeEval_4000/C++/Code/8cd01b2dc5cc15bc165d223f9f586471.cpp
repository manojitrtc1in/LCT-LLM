#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ld long double
#define re register 
#define ar array
#define ke string
#define ll long long 
#define vo void 
#define in int
#define bo bool
#define ch char 
#define br() break
#define cont() continue

#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend() 
#define sz(x) (in)(x).size()

#define F_OR(i, a, b, s) for (in i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define pi(x, a) for(auto &x : a)

#define deb(x) cout << #x << "=" << x << endl; 
#define pb push_back 
#define ff first 
#define ss second 
#define setbits(x) __builtin_popcountll(x)  

#define zrobits(x) __builtin_ctzll(x) 

#define sp(x, y) fixed<<setprecision(y)<<x  

#define mk(ar,n,type) type*ar = new type[n]; 

#define tr(it, a) for(auto it = a.begin(); it!=a.end(); ++it); 
#define yes() cout << "YES" << '\n'; 
#define no() cout << "NO" << '\n'; 
#define syes() cout << "Yes" << '\n'; 
#define sno() cout << "No" << '\n'; 

#define pimath 3.14285714286
#define vpp vector<pair<in, in>>
typedef pair<in, in> pii;  
typedef pair<ll , ll> pll;
typedef vector<ll> vl; 
const in mod = 1e9+7;
const in mxN = 998244353;
class BIT {
 public:
  BIT(ll n) {
    sz = n;
    tree.resize(n + 1, 0);
  }

  ll sz;
  vector<ll> tree;

  void Update(ll x, ll y) {
    for (ll i = x; i <= sz; i += i & -i) {
      tree[i] += y;
    }
  }

  ll Query(ll x) {
    ll res = 0;
    for (ll i = x; i > 0; i -= i & - i) {
      res += tree[i];
    }
    return res;
  }
};
void pairsort(in a[], in b[], in n){
    vpp v(n);
    FOR(i, n){
        v[i] = make_pair(a[i], b[i]); 
    }
    sort(v.begin(), v.end()); 
    FOR(i, n){
        a[i] = v[i].ff; 
        b[i] = v[i].ss;  
    }
    return; 
}
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> class Cpoin
{
    public: 
    ll x, y, z; 
    Cpoin(T tmpx, T tmpy, T tmpz){
        x = tmpx; 
        y = tmpy; 
        z = tmpz; 
    }
    Cpoin operator+(Cpoin b){
        return Cpoin(this->x+b.x, this->y+b.y, this->z+b.z); 
    }
    Cpoin& operator+=(Cpoin b){
        *this = *this+b; 
        return *this; 
    }
}; 
template<typename T> T dot(Cpoin<T> a, Cpoin<T> b){
    return a.x*b.x+a.y*b.y+a.z*b.z; 
}
template<typename T> double ang(Cpoin<T> a, Cpoin<T> b) {
   return acos(dot(a,b)/sqrt(dot(a, a)*dot(b,b)));    
}
template<class T> bo umin(T& a, const T& b) {
    return b<a?a=b, 1:0;
}
template<class T> bo umax(T& a, const T& b) { 
    return a<b?a=b, 1:0;
} 

ll FIRSTTRUE(function<bo(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb)/2;
        f(mb)?rb=mb:lb=mb+1; 
    } 
    return lb;
}
ll LASTTRUE(function<bo(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb+1)/2;
        f(mb)?lb=mb:rb=mb-1; 
    } 
    return lb;
}

template<class A> void inp(vt<A>& v);
template<class A, size_t S> void inp(ar<A, S>& a);
template<class T> void inp(T& x) {
    cin >> x;
}
void inp(double& d) {
    ke t;
    inp(t);
    d=stod(t);
}
void inp(long double& d) {
    ke t;
    inp(t);
    d=stold(t);
}
template<class H, class... T> void inp(H& h, T&... t) {
    inp(h);
    inp(t...);
}
template<class A> void inp(vt<A>& x) {
    pi(a, x)
        inp(a);
}
template<class A, size_t S> void inp(array<A, S>& x) {
    pi(a, x)
        inp(a);
}

ke to_string(char c) {
    return ke(1, c);
}
ke to_string(bo b) {
    return b?"true":"false";
}
ke to_string(const char* s) {
    return ke(s);
}
ke to_string(ke s) {
    return s;
}
ke to_string(vt<bo> v) {
    ke res;
    FOR(sz(v))
        res+=char('0'+v[i]);
    return res;
}

template<size_t S> ke to_string(bitset<S> b) {
    ke res;
    FOR(S)
        res+=char('0'+b[i]);
    return res;
}
template<class T> ke to_string(T v) {
    bo f=1;
    ke res;
    pi(x, v) {
        if(!f)
            res+=' ';
        f=0;
        res+=to_string(x);
    }
    return res;
}

template<class A> void write(A x) {
    cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) { 
    write(h);
    write(t...);
}
void pr() {
    write("\n");
}
template<class H, class... T> void pr(const H& h, const T&... t) { 
    write(h);
    if(sizeof...(t))
        write(' ');
    pr(t...);
}
void DBG() {
    cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
    cerr << ro_string(h);
    if(sizeof...(t))
        cerr << ", ";
    DBG(t...);
}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

template<class T> void offset(ll o, T& x) {
    x+=o;
}
template<class T> void offset(ll o, vt<T>& x) {
    pi(a, x)
        offset(o, a);
}
template<class T, size_t S> void offset(ll o, ar<T, S>& x) {
    pi(a, x)
        offset(o, a);
}

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randin(ll a, ll b) {
    return uniform_int_distribution<ll>(a, b)(mt_rng);
}
template<class T, class U> void vti(vt<T> &v, U x, size_t n) {
    v=vt<T>(n, x);
}
template<class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {
    v=vt<T>(n);
    pi(a, v)
        vti(a, x, m);
}
const in d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const in d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
in smallestDivisor(in n)
{
    if (n % 2 == 0)
        return 2;
    for (in i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return i;
    }
 
    return n;
}
ll gcd(ll a, ll b){
    while(b){
        a%=b;swap(a,b);
    }
    return a;
}
ll lcm(in a, in b){
    ll a0 = a; 
    ll b0 = b; 
    return a*b/__gcd(a0, b0); 
}
in mpow(in base, in exp){
    base%=mod; 
    in result = 1; 
    while(exp > 0){
        if(exp & 1) result = ((ll)result*base)%mod; 
        base = ((ll)base * base)%mod; 
        exp >> 1; 
    }
    return result; 
}
in modulo(){
    in mpow_result = mpow(2, 1000); 
    return mpow_result; 
}
in divisible(in n,in a,in b){
    in c1 = n/a; 
    in c2 = n/b; 
    in c3 = n/(a*b);
    return c1+c2-c3; 
}
struct word{
    in a;
    in b;
    in c;
    in d;
    in e;
    in tot;
};
 
word ar[200005];
 
bo compa(word a , word b){
    in x = 2*a.a - a.tot;
    in y = 2*b.a - b.tot;
    
    return x < y;
}
 
bo compb(word a , word b){
    in x = 2*a.b - a.tot;
    in y = 2*b.b - b.tot;
    return x < y;
}
 
bo compc(word a , word b){
    in x = 2*a.c - a.tot;
    in y = 2*b.c - b.tot;
    return x < y;
}
 
bo compd(word a , word b){
    in x = 2*a.d - a.tot;
    in y = 2*b.d - b.tot;
    return x < y;
}
 
bo compe(word a , word b){
    in x = 2*a.e - a.tot;
    in y = 2*b.e - b.tot;
    return x < y;
}
ll in gcd_sum(ll in num){
    long long in tmp = num, digitsum = 0;

    while (tmp > 0) {
        digitsum += tmp % 10;
        tmp /= 10;
    }               

    long long in gcd = __gcd(num, digitsum);
    return gcd;
}
in sum(in a){
    in result = 0; 
    while(a>0){
        result += a%10; 
        a/= 10; 
    }
    return result; 
}  
bo isPowerOfTwo(in n)
{
   if(n==0)
   return false;
 
   return (ceil(log2(n)) == floor(log2(n)));
}
in removedecimal( in number, in digitNo )
{
    in result = number;
    in decimal = (in)pow( 10, digitNo ); 

    in div = number / decimal;                      
    if ( div > 0 )                         

    {
        in rest = number % decimal;       

        result = div / 10;                 

        result *= 10 * decimal;            

        result += rest;                    

    }
    return result;
}
in fact(in n){
    in res = 1;
    for (in i = 1; i <= n; i++) {
    res = res * 1ll * i % mod;
    }
    return res;
}
in fast_pow(in a, in p) {
  in res = 1;
  while (p) {
    if (p % 2 == 0) {
      a = a * 1ll * a % mod;
      p /= 2;
    } else {
      res = res * 1ll * a % mod;
      p--;
    }
  }
  return res;
}
in C(in n, in k) {
  return fact(n) * 1ll * fast_pow(fact(k), mod - 2) % mod * 1ll * fast_pow(fact(n - k), mod - 2) % mod;
} 
inline in GCD(re in x,re in y){
    return y?gcd(y,x%y):x;
}
inline in LCM(re in x,re in y){
    return x/GCD(x,y)*y;
}
ll binpower(ll a,ll b){
    if(b == 0){
        return 1;
    }
    ll ans = binpower(a, b/2); 
    if(b%2) return ans * ans * a; 
    else return ans * ans; 
}
bo isPrime(in n)
{
    

    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    

    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (in i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}
  
bo isPerfectSquare(in n)
{
    in sr = sqrt(n); 
    if (sr * sr == n)
        return true;
    else
        return false;
}
in largestno(ll arr[], ll n)
{
    ll i;
    ll max = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
 
    return max;
} 
vt<ch> data = {'a', 'e', 'i', 'o', 'u'};
 
template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}
 
 
const int INF = int(1e9) + 5;
 
struct state {
    int high = -INF, low = -INF;
    int previous = -1, a = 0;
 
    bool operator<(const state &other) const {
        if (high != other.high)
            return high < other.high;
 
        return low < other.low;
    }
 
    pair<state, bool> add(int from, int x) {
        if (x < low)
            return {state(), false};
 
        state sum = *this;
        sum.previous = from;
        sum.a = x;
 
        if (x > high)
            sum.high = x;
        else
            sum.low = x;
 
        return {sum, true};
    }
};
 
void solve() {
    int N;
    cin >> N;
    vt<in> P(N);
 
    for (auto &p : P)
        cin >> p;
 
    vector<vector<state>> dp(N + 1);
    dp[0] = {state()};
 
    for (int i = 0; i < N; i++) {
        vt<in> options = {-P[i], P[i]};
 
        for (int j = 0; j < int(dp[i].size()); j++) {
            state s = dp[i][j];
 
            for (int x : options) {
                pair<state, bool> result = s.add(j, x);
 
                if (result.second)
                    dp[i + 1].push_back(result.first);
            }
        }
 
        sort(dp[i + 1].begin(), dp[i + 1].end());
        vector<state> filtered;
 
        for (state s : dp[i + 1]) {
            bool bad = false;
 
            for (state f : filtered)
                if (f.low <= s.low && f.high <= s.high)
                    bad = true;
 
            if (!bad)
                filtered.push_back(s);
        }
 
        dp[i + 1] = filtered;
    }
 
    if (dp.back().empty()) {
        cout << "NO" << '\n';
        return;
    }
 
    yes(); 
    vt<in> A(N);
    int index = 0;
 
    for (int i = N - 1; i >= 0; i--) {
        state s = dp[i + 1][index];
        A[i] = s.a;
        index = s.previous;
    }
 
    output_vector(A);
}
in main(vo)
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr); 
    srand(chrono::high_resolution_clock::now().time_since_epoch().count()); 
    in t; 
    inp(t); 
    while(t--)
    solve(); 
    return 0; 
}