



using namespace __gnu_pbds;
using namespace std;



void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}













using ll = long long;
using db = long double; 

using str = string; 




using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;








tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T,SZ>;
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;






















tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
tcT> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }














const int MX = 2e5+5;
const ll BIG = 1e18; 

const ll INF = 1e18; 

const db PI = acos((db)-1);
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; 

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr int bits(int x) { 

  return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int id2(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } 

ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } 


tcT> bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0; } 

tcT> bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0; } 



tcTU> T fstTrue(T lo, T hi, U f) {
  ++hi; assert(lo <= hi); 

  while (lo < hi) { 

    T mid = lo+(hi-lo)/2;
    f(mid) ? hi = mid : lo = mid+1;
  }
  return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
  --lo; assert(lo <= hi); 

  while (lo < hi) { 

    T mid = lo+(hi-lo+1)/2;
    f(mid) ? lo = mid : hi = mid-1;
  }
  return lo;
}
tcT> void remDup(vector<T>& v) { 

  sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { 

  auto it = t.find(u); assert(it != end(t));
  t.erase(it); } 







ll n, m, k, q, l, r, x, y, z;
string s, t;
ll ans = 0;


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

        return unsigned(x % m);

        

        

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

    static const int SAVE_INV = int(1e6) + 5;
    static _m_int save_inv[SAVE_INV];

    static void prepare_inv() {
        

        for (int64_t p = 2; p * p <= MOD; p += p % 2 + 1)
            assert(MOD % p != 0);

        save_inv[0] = 0;
        save_inv[1] = 1;

        for (int i = 2; i < SAVE_INV; i++)
            save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
    }

    _m_int inv() const {
        if (save_inv[1] == 0)
            prepare_inv();

        if (val < SAVE_INV)
            return save_inv[val];

        _m_int product = 1;
        int v = val;

        while (v >= SAVE_INV) {
            product *= MOD - MOD / v;
            v = MOD % v;
        }

        return product * save_inv[v];
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

template<const int &MOD> _m_int<MOD> _m_int<MOD>::save_inv[_m_int<MOD>::SAVE_INV];

extern const int MOD = 998244353;
using mod_int = _m_int<MOD>;


vector<mod_int> _factorial = {1, 1}, id0 = {1, 1};

void id3(int64_t maximum) {
    static int id4 = 1;

    if (maximum <= id4)
        return;

    

    maximum += maximum / 16;
    _factorial.resize(maximum + 1);
    id0.resize(maximum + 1);

    for (int i = id4 + 1; i <= maximum; i++) {
        _factorial[i] = i * _factorial[i - 1];
        id0[i] = id0[i - 1] / i;
    }

    id4 = int(maximum);
}

mod_int factorial(int n) {
    id3(n);
    return _factorial[n];
}

mod_int id5(int n) {
    id3(n);
    return id0[n];
}

mod_int choose(int64_t n, int64_t r) {
    if (r < 0 || r > n) return 0;
    id3(n);
    return _factorial[n] * id0[r] * id0[n - r];
}

mod_int permute(int64_t n, int64_t r) {
    if (r < 0 || r > n) return 0;
    id3(n);
    return _factorial[n] * id0[n - r];
}

mod_int inv_choose(int64_t n, int64_t r) {
    assert(0 <= r && r <= n);
    id3(n);
    return id0[n] * _factorial[r] * _factorial[n - r];
}

mod_int id1(int64_t n, int64_t r) {
    assert(0 <= r && r <= n);
    id3(n);
    return id0[n] * _factorial[n - r];
}

mod_int dp[2005][2005];

int solve(){

    

    cin >> n >> m >> k;
    


    mod_int x = (m+1)/2;
    if(k>=n)
    {
        mod_int ans = 0;
        for(int64_t i=1;i<=n;i++)
        {
            mod_int a = (m+1)/2;
            mod_int b = m-a;
            mod_int c = i;
            mod_int y = choose(n,i);
            y *= b.pow(n-i);
            y *= a.pow(i);
            y *= c.pow(k);
            ans += y;
            

        }
        cout<<ans<<"\n";
        return 0;
    }
    vector<mod_int> dp1(k+1,1);
    for(int i=1;i<=k;i++)
    {
        dp1[i] = dp1[i-1]*(n-i+1);
        

    }
    

    

    mod_int ans = 0;
    for(int i=1;i<=k;i++)
    {
        mod_int y = dp[k][i]*(x.pow(i));
        

        y *= dp1[i];
        

        mod_int mm = m;
        y *= mm.pow(n-i);
        

        ans += y;
        

    }
    cout<<ans<<"\n";
    return 0;
}


int main(){

  

  

  


    ios::sync_with_stdio(false);
    cin.tie(0);

for(int i=0;i<2005;i++)
    {
        for(int j=0;j<2005;j++)
        {
            dp[i][j]=0;
        }
    }
    dp[1][1]=1;
    for(int ii=2;ii<2005;ii++)
    {
        for(mod_int i=1;i<2005;i++)
        {
            dp[ii][int(i)] = dp[ii-1][int(i)-1] + i*dp[ii-1][int(i)];
        }
    }

    int q;
    q=1;
    cin >> q;
    while(q--){
        solve();
    }

  

  

  

  

  


    return 0;
}