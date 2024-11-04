



using namespace std;
using ll = long long;


using namespace __gnu_pbds;



using ld = long double;
 

using ii = pair<int, int>;






















bool revsort(ll a, ll b) {return a > b;}



bool isPalindrome(const string& s) {
    return std::equal(s.begin(), s.end(), s.rbegin());
}

auto cmp = [](const pair<int, int>& A, const pair<int, int>& B) { 
    if(A.second == B.second) return A.first < B.first;
    return A.second < B.second; 
};



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
template <class T> T id6(T a , T mod){return expo<T>(a , mod - 2 , mod);}
template <class T> bool rev(T a , T b){return a > b;}
template <class T> ll maxpower(T a , T b){ll ans = 0;while(a >   0 && a % b == 0){ans++;a /= b;}return ans;}
template <class T> T mceil(T a, T b){if(a % b == 0) return a/b; else return a/b + 1;}
template <class T> T lcm(T a, T b){return (a*b)/gcd<T>(a, b);}




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
 
vector<mod_int> inv, factorial, id1;
int id8 = -1;
 
void id3(int64_t maximum) {
    static int prepare_calls = 0;
 
    if (prepare_calls++ == 0) {
        

        for (int p = 2; p * p <= MOD; p += p % 2 + 1)
            assert(MOD % p != 0);
 
        inv = {0, 1};
        factorial = id1 = {1, 1};
        id8 = 1;
    }
 
    if (maximum > id8) {
        inv.resize(maximum + 1);
        factorial.resize(maximum + 1);
        id1.resize(maximum + 1);
 
        for (int i = id8 + 1; i <= maximum; i++) {
            inv[i] = inv[MOD % i] * (MOD - MOD / i);
            factorial[i] = i * factorial[i - 1];
            id1[i] = inv[i] * id1[i - 1];
        }
 
        id8 = int(maximum);
    }
}
 
mod_int choose(int64_t n, int64_t r) {
    if (r < 0 || r > n) return 0;
    return factorial[n] * id1[r] * id1[n - r];
}
 
mod_int inv_choose(int64_t n, int64_t r) {
    assert(0 <= r && r <= n);
    return id1[n] * factorial[r] * factorial[n - r];
}
 
mod_int permute(int64_t n, int64_t r) {
    if (r < 0 || r > n) return 0;
    return factorial[n] * id1[n - r];
}
 
mod_int id7(int64_t n, int64_t r) {
    assert(0 <= r && r <= n);
    return id1[n] * factorial[n - r];
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



vector<int> id0;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
    maximum = max(maximum, 1);
    id0.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            id0[p] = p;
            primes.push_back(p);

            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    id0[i] = p;
                }
        }
}

vector<pair<int64_t, int>> id2(int64_t n) {
    int64_t id4 = int64_t(id0.size()) - 1;
    assert(1 <= n && n <= id4 * id4);
    vector<pair<int64_t, int>> result;

    if (n <= id4) {
        while (n != 1) {
            int64_t p = id0[n];
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

void id5(string mainString, string pattern, int *locArray, int &loc) {
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
    id5(c, pat, locationArray, index);
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
        if (s < k || s >= n+(n/k)*k)
            cout << "NO" << nline;
        else cout << "YES" << nline;
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



