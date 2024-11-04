



using namespace std;
using namespace __gnu_pbds;




















































typedef pair<in, in> pii;  
typedef pair<ll , ll> pll;
typedef vector<ll> vl;
const ll mod = 1e9+7;
const in suffixN = 998244353;

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

template<class T> bo ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
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
template<in n> 
struct matrix{
    using TYPE = ll; 
    TYPE v[n][n]; 
    matrix(){ 
        memset(v, 0, sizeof(v)); 
    }matrix<n> mul(matrix &b){
        matrix<n> res;  static const ll msq = mod * mod; FOR(n){ FOR(k, n){FOR(j, n){
            res.v[i][j] += v[i][k] * b.v[k][j]; res.v[i][j] = 
            (res.v[i][j] >= msq ? res.v[i][j] - msq : res.v[i][j]); } } } 
            FOR(n){ FOR(j, n){res.v[i][j] %= mod;  } }return res; }
     matrix<n> pw(matrix<n> &a, ll x){
         matrix<n> res; 
         FOR(i, n)
             res.v[i][i] = 1; 
             while(x){
                 if(x & 1){
                     res = res.mul(a); 
                 }
                 x /= 2; 
                 a = a.mul(a); 
             }
             return res; 
     }
     void prin_matrix(){
         pr("-----------"); 
         FOR(n){
             FOR(j, n){
                 write(v[i][j], ' '); 
             }pr(); 
         }
         pr("-----------"); 
     }
}; 
struct sum_t{
     ll val; 
     static const ll null_v = 0; 
     sum_t() : val(0) {} 
     sum_t(ll v) : val(v) {}
     
     sum_t op(sum_t& other){
         return sum_t(val + other.val);
     }
     sum_t extt(sum_t&v, in size){
         return sum_t(val + v.val * size); 
     }
}; 
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

void DBG() {
    cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
    cerr << ro_string(h);
    if(sizeof...(t))
        cerr << ", ";
    DBG(t...);
}






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
in id4(in n)
{
    if (n % 2 == 0)
        return 2;
    for (in i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return i;
    }
 
    return n;
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
template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;
 
  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }
 
  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }
 
  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }
 
  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(in) { Modular result(*this); *this += 1; return result; }
  Modular operator--(in) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }
 
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, in>::value, Modular>::type& operator*=(const Modular& rhs) {

    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;

    value = normalize(static_cast<in64_t>(value) * static_cast<in64_t>(rhs.value));

    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type& operator*=(const Modular& rhs) {
    long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }
 
  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }
 
  friend const Type& abs(const Modular& x) { return x.value; }
 
  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
 
  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
 
  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);
 
 private:
  Type value;
};
 
template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }
 
template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
 
template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }
 
template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
 
template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
 
template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}
 
template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}
 
template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}
template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  return stream << number();
}
template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, long long>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}
 
constexpr in md = (in) 1e9+7; 
using Min = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
ll in id0(ll in num){
    long long in tmp = num, digitsum = 0;

    while (tmp > 0) {
        digitsum += tmp % 10;
        tmp /= 10;
    }               

    long long in gcd = __gcd(num, digitsum);
    return gcd;
}
bo id1(in n)
{
   if(n==0)
   return false;
 
   return (ceil(log2(n)) == floor(log2(n)));
}
in id3( in number, in digitNo )
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
  
    for (in i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}
  
bo id2(in n)
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
vt<ch> dt = {'a', 'e', 'i', 'o', 'u'}; 




vo solve(in test_case = 0){
    in n;
    inp(n); 
    ke s; 
    inp(s); 
    if (is_sorted(all(s))) {
      pr(0); 
      return; 
    }
    while (1) {
      in k0 = 0;
      in k1 = 0;
      FOR(n) {
        k0 += (s[i] == '0');
        k1 += (s[i] == '1');
      }
      if (k0 < k1) {
        reverse(all(s)); 
        pi(c, s){
          c ^= '0' ^ '1';
        }
        continue;
      }
      vt<in> suffix(n + 1, -1);
      in bal = 0;
      FOR(n) {
        bal += (s[i] == '0' ? 1 : -1);
        if (bal >= 0) {
          suffix[bal] = max(suffix[bal], i);
        }
      }
      in ans = 1;
      in cut = 0;
      in to = suffix[0];
      while (1) {
        while (s[cut] == '0' && cut < k0 - k1) {
          cut += 1;
          to = max(to, suffix[cut]);
        }
        if (cut == k0 - k1) {
          br(); 
        }
        for (in i = cut, j = to; i < j; i++, j--) {
          s[i] = '0';
          s[j] = '1';
        }
        ans += 1;
      }
      pr(ans); 
      br(); 
    }
}     
main(vo)
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr); 
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    in t; 
    inp(t); 
    while(t-->0)
    solve();
    return 0; 
}