


using namespace std;

 

 


using ll=long long;
using ld=long double;
using vi=vector<int>;
using vll=vector<ll>;
using pi=pair<int,int>;
using pll=pair<ll,ll>;
































TYPES(T) void input(T&... a){ (cin>>...>>a); }








TYPE(T) istream&operator>>(istream&is,vector<T>&v){
  for(auto&a:v)cin>>a;
  return is;
}
TYPE(T) ostream&operator<<(ostream&os,vector<T>&v){
  if(&os==&cerr)os<<"[";
  REP(i,v.size()){
    os<<v[i];
    if(i+1<v.size())os<<(&os==&cerr?",":" ");
  }
  if(&os==&cerr)os<<"]";
  return os;
}
TYPE(T,S) istream&operator>>(istream&is,pair<T,S>&p){
  cin>>p.first>>p.second;
  return is;
}

TYPE(T) using pq=priority_queue<T>;
TYPE(T) using pgq=priority_queue<T,vector<T>,greater<T>>;
TYPE(T) T pick(queue<T>& que){assert(que.size()); T a=que.front();que.pop();return a;}
TYPE(T) T pick(pq<T>& que){assert(que.size()); T a=que.top();que.pop();return a;}
TYPE(T) T pick(stack<T>& sta){assert(sta.size()); T a=sta.top();sta.pop();return a;}

string YES(bool f=true){return (f?"YES":"NO");}
string Yes(bool f=true){return (f?"Yes":"No");}
string yes(bool f=true){return (f?"yes":"no");}

vi iota(int n){vi a(n);iota(ALL(a),0);return a;}

constexpr int INF=1e9+7;
constexpr ll LINF=1e18+7;

TYPE(T) void fin(T a){cout<<a<<endl;exit(0);}

struct r2{
  int y,x;
  bool operator<(const r2&a){return (y!=a.y?y<a.y:x<a.x);}
  bool operator>(const r2&a){return (y!=a.y?y>a.y:x>a.x);}
  bool operator==(const r2&a){return (y==a.y and x==a.x);}
};






namespace atcoder {

namespace internal {





constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}







struct barrett {
    unsigned int _m;
    unsigned long long im;

    

    barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

    

    unsigned int umod() const { return _m; }

    

    

    

    unsigned int mul(unsigned int a, unsigned int b) const {
        

        


        

        

        

        

        

        

        

        unsigned long long z = a;
        z *= b;

        unsigned long long x;
        _umul128(z, im, &x);

        unsigned long long x =
            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);

        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};







constexpr long long id5(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}









constexpr bool id2(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = id5(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
template <int n> constexpr bool is_prime = id2(n);





constexpr std::pair<long long, long long> id3(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};

    

    

    

    

    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  


        

        

        

        


        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    

    

    if (m0 < 0) m0 += b / s;
    return {s, m0};
}







constexpr int id4(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (long long)(i)*i <= x; i += 2) {
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        divs[cnt++] = x;
    }
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (id5(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = id4(m);

}  


}  







namespace atcoder {

namespace internal {


template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;



template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;



template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  


}  










namespace atcoder {

namespace internal {

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

}  


template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct id1 : internal::static_modint_base {
    using mint = id1;

  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    id1() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id1(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id1(T v) {
        _v = (unsigned int)(v % umod());
    }
    id1(bool v) { _v = ((unsigned int)(v) % umod()); }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        if (prime) {
            assert(_v);
            return pow(umod() - 2);
        } else {
            auto eg = internal::id3(_v, m);
            assert(eg.first == 1);
            return eg.second;
        }
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = internal::is_prime<m>;
};

template <int id> struct id6 : internal::modint_base {
    using mint = id6;

  public:
    static int mod() { return (int)(bt.umod()); }
    static void set_mod(int m) {
        assert(1 <= m);
        bt = internal::barrett(m);
    }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    id6() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id6(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id6(T v) {
        _v = (unsigned int)(v % mod());
    }
    id6(bool v) { _v = ((unsigned int)(v) % mod()); }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v += mod() - rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        _v = bt.mul(_v, rhs._v);
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        auto eg = internal::id3(_v, mod());
        assert(eg.first == 1);
        return eg.second;
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static internal::barrett bt;
    static unsigned int umod() { return bt.umod(); }
};
template <int id> internal::barrett id6<id>::bt = 998244353;

using modint998244353 = id1<998244353>;
using modint1000000007 = id1<1000000007>;
using modint = id6<-1>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<id6<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  


}  


using namespace atcoder;
using mint=modint;
ostream& operator<<(ostream &os,mint a){os<<a.val();return os;}
istream& operator>>(istream &is,mint &a){
  long long b;is>>b;a=b;
  return is;
}

vector<vector<int>> g(2000);
int n;
vector<int> q;
vector<vector<int>> son(2000);

void dfs(int idx,int pre){
  for(int p:g[idx])if(p!=pre){
    son[idx].push_back(p);
    dfs(p,idx);
  }
  q.push_back(idx);
}

const int SIZE=5000000;
mint Factorial[SIZE],Finverse[SIZE];
void Cinit(){
  Factorial[0]=mint(1);
  for(int i=1;i<SIZE;i++)Factorial[i]=Factorial[i-1]*mint(i);
  Finverse[SIZE-1]=Factorial[SIZE-1].inv();
  for(int i=SIZE-2;i>=0;i--)Finverse[i]=mint(i+1)*Finverse[i+1];
}
mint id0(int n,int k){
  if(Factorial[0]==0)Cinit();
  if(n<k)return 0;
  return Factorial[n]*Finverse[n-k]*Finverse[k];
}

template<typename T,typename ...Args>
auto make_vector(T x,int arg,Args ...args){
  if constexpr(sizeof...(args)==0)return vector<T>(arg,x);
  else return vector(arg,make_vector<T>(x,args...));
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n;
  INT(mod);
  mint::set_mod(mod);
  REP(i,n-1){
    INT(u,v);u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0,-1);

  auto dp=make_vector<mint>(0,n,n);
  auto B=make_vector<mint>(1,n,n);
  auto cnt=make_vector<int>(0,n,n);
  vector<mint> A(n,0),C(n,0);

  for(int v:q){
    for(int u:son[v]){
      mint wa=0;
      REP(i,1,n){
        wa+=dp[u][i];
        if(wa!=0)B[v][i]*=wa;
        else cnt[v][i]++;
      }
    }

    REP(i,1,n){
      mint seki=1;
      for(int u:son[v]){
        dp[v][i]+=dp[u][i]*C[u];
        A[u]+=dp[u][i];
        if(A[u]==0 and cnt[v][i]==1)C[u]+=B[v][i];
        if(A[u]!=0 and cnt[v][i]==0)C[u]+=B[v][i]/A[u];
      }
      if(v==0)dp[v][i]=0;
      if(cnt[v][i]==0)dp[v][i]+=B[v][i];
    }

    

    

  }

  REP(i,2,n)REP(j,1,i)dp[0][i]-=dp[0][j]*id0(i,j);
  REP(i,1,n)cout<<dp[0][i]<<"\n "[i+1<n];
}

