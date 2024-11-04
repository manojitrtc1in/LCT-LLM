






#pragma GCC optimize("O3")








#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)


#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define bg begin()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
#define ll long long
#define sz(a) a.size()
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif
#define mp make_pair
#define mt make_tuple
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))
#ifdef LOCAL
void dmpr(ostream&os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
	os<<t<<" ";
	dmpr(os,args...);
}
#define dmp2(...) dmpr(cerr,__LINE__,##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif
const int mod=1000000007;
using uint=unsigned;
using ull=unsigned long long;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;





ll checker=0,counter=0;
ll temporary=0,loop_counter=0;



inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline int lcm(int a, int b) { return a * b / gcd(a, b); }
inline int add(int a, int b) {    return ((a % mod) + (b % mod)) % mod;}
inline int multi(int a, int b) {   return ((a % mod) * (b % mod)) % mod;}
inline int sub(int a, int b) {       a %= mod; b %= mod; a -= b; if (a < 0) a += mod; return a;}
inline void wri(const int v) { cout << v; }
inline void wrll(const long long &v) { cout << v; }
inline void wrs(const string& s) { cout << s; }
inline void wrc(const char c) { cout << c; }



template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
 
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
 
using pii=pair<int,int>;
using vi=vc<int>;
 
template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}
 
template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
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
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }
 
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;
#else
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
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
 

 
constexpr int md = (int) 1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
 
vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);
 
Mint C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() < n + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}

template<typename T>
void printList(std::initializer_list<T> text)
{
    for (const auto & value: text)
        std::cout << value << " ";
}

template<typename T, typename U>
static inline void amin(T &x, U y)
{
    if (y < x)
        x = y;
}
  


template<typename T, typename U>
static inline void amax(T &x, U y)
{
    if (x < y)
        x = y;
}

  
template<typename T> void print(T n)
{
    bool neg = 0;
  
    if (n < 0ll)
        n *= -1, neg = 1;
  
    char snum[65];
    int i = 0;
    do
    {
        snum[i++] = n % 10 + '0';
        n /= 10;
    }
  
    while (n);
    --i;
  
    if (neg)
        putchar('-');
  
    while (i >= 0)
        putchar(snum[i--]);
  
    putchar('\n');
}
template <int MOD_> struct modnum {
   static constexpr int MOD = MOD_;
   static_assert(MOD_ > 0, "MOD must be positive");
   private:
  

   int v;
   static int minv(int a, int m) {
      a %= m;
      assert(a);
      return a == 1 ? 1 : (m - (minv(m, a)) * (m) / a);
   }
   public:
   modnum() : v(0) {}
   modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
   explicit operator int() const { return v; }
   friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
   friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }
   friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
   friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
   modnum inv() const {
      modnum res;
      res.v = minv(v, MOD);
      return res;
   }
   friend modnum inv(const modnum& m) { return m.inv(); }
   modnum neg() const {
      modnum res;
      res.v = v ? MOD-v : 0;
      return res;
   }
   friend modnum neg(const modnum& m) { return m.neg(); }
   modnum operator- () const {
      return neg();
   }
   modnum operator+ () const {
      return modnum(*this);
   }
   modnum& operator ++ () {
      v ++;
      if (v == MOD) v = 0;
      return *this;
   }
   modnum& operator -- () {
      if (v == 0) v = MOD;
      v --;
      return *this;
   }
   modnum& operator += (const modnum& o) {
      v += o.v;
      if (v >= MOD) v -= MOD;
      return *this;
   }
   modnum& operator -= (const modnum& o) {
      v -= o.v;
      if (v < 0) v += MOD;
      return *this;
   }
   modnum& operator *= (const modnum& o) {
      v = int((v) * (o.v) % MOD);
      return *this;
   }
   modnum& operator /= (const modnum& o) {
      return *this *= o.inv();
   }
   friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
   friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
   friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
   friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
   friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
   friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};


struct Scanner {
    FILE* fp = nullptr;
    char line[(1 << 15) + 1];
    size_t st = 0, ed = 0;
    void reread() {
        memmove(line, line + st, ed - st);
        ed -= st;
        st = 0;
        ed += fread(line + ed, 1, (1 << 15) - ed, fp);
        line[ed] = '\0';
    }
    bool succ() {
        while (true) {
            if (st == ed) {
                reread();
                if (st == ed) return false;
            }
            while (st != ed && isspace(line[st])) st++;
            if (st != ed) break;
        }
        if (ed - st <= 50) reread();
        return true;
    }
    template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        while (true) {
            size_t sz = 0;
            while (st + sz < ed && !isspace(line[st + sz])) sz++;
            ref.append(line + st, sz);
            st += sz;
            if (!sz || st != ed) break;
            reread();            
        }
        return true;
    }
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        bool neg = false;
        if (line[st] == '-') {
            neg = true;
            st++;
        }
        ref = T(0);
        while (isdigit(line[st])) {
            ref = 10 * ref + (line[st++] - '0');
        }
        if (neg) ref = -ref;
        return true;
    }
    template <class T> bool read_single(vector<T>& ref) {
        for (auto& d : ref) {
            if (!read_single(d)) return false;
        }
        return true;
    }
    void read() {}
    template <class H, class... T> void read(H& h, T&... t) {
        bool f = read_single(h);
        assert(f);
        read(t...);
    }
    Scanner(FILE* _fp) : fp(_fp) {}
};
 
struct Printer {
  public:
    template <bool F = false> void write() {}
    template <bool F = false, class H, class... T>
    void write(const H& h, const T&... t) {
        if (F) write_single(' ');
        write_single(h);
        write<true>(t...);
    }
    template <class... T> void writeln(const T&... t) {
        write(t...);
        write_single('\n');
    }
 
    Printer(FILE* _fp) : fp(_fp) {}
    ~Printer() { flush(); }
 
  private:
    static constexpr size_t SIZE = 1 << 15;
    FILE* fp;
    char line[SIZE], small[50];
    size_t pos = 0;
    void flush() {
        fwrite(line, 1, pos, fp);
        pos = 0;
    }
    void write_single(const char& val) {
        if (pos == SIZE) flush();
        line[pos++] = val;
    }
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    void write_single(T val) {
        if (pos > (1 << 15) - 50) flush();
        if (val == 0) {
            write_single('0');
            return;
        }
        if (val < 0) {
            write_single('-');
            val = -val;  

        }
        size_t len = 0;
        while (val) {
            small[len++] = char('0' + (val % 10));
            val /= 10;
        }
        for (size_t i = 0; i < len; i++) {
            line[pos + i] = small[len - 1 - i];
        }
        pos += len;
    }
    void write_single(const string& s) {
        for (char c : s) write_single(c);
    }
    void write_single(const char* s) {
        size_t len = strlen(s);
        for (size_t i = 0; i < len; i++) write_single(s[i]);
    }
    template <class T> void write_single(const vector<T>& val) {
        auto n = val.size();
        for (size_t i = 0; i < n; i++) {
            if (i) write_single(' ');
            write_single(val[i]);
        }
    }
};
 






int fast_pow(int a, int p) {
  int res = 1;
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




vector<int>count_set(int n)
{
vector<int >ans(n+1,0);
for(int i=1; i<=n; i++)
{
ans[i]=ans[i&i-1]+1;


}
return ans;
}
bool pow2(int x)
{
    if(x==0)
    return false;
    return x&(x-1)==0?true:false;
}
int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}
int botbit(signed a){
	return a==0?32:__builtin_ctz(a);
}
int botbit(ll a){
	return a==0?64:__builtin_ctzll(a);
}
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
bool ispow2(int i){
	return i&&(i&-i)==i;
}
ll mask(int i){
	return (int(1)<<i)-1;
}
int ceil(int a,int b)
{
    return (a+b-1)/b;
    
}
int pow(int a,int b)
{int ans=1;
int x=a;
while(b!=0)
{if(b&1)
{ans=ans*x;
    
}
x=x*x;
b/=2;
    
}
return ans;
    
}
int moddedpower(int a,int b,int p)
{int ans=1;
int x=a%p;
if(x==0)
return 0;
while(b!=0)
{if(b&1)
{ans=(ans*x)%p;
    
}
x=(x*x)%p;b/=2;
    
}
return ans;
    
}
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        

        

        if (arr[mid] == x)
            return mid;
 
        

        

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        

        

        return binarySearch(arr, mid + 1, r, x);
    }
 
    

    

    return -1;
}
int getSum(int BITree[], int index)
{
    int sum = 0; 

  
    

    index = index + 1;
  
    

    while (index>0)
    {
        

        sum += BITree[index];
  
        

        index -= index & (-index);
    }
    return sum;
}
  






void updateBIT(int BITree[], int n, int index, int val)
{
    

    index = index + 1;
  
    

    while (index <= n)
    {
    

    BITree[index] += val;
  
    

    index += index & (-index);
    }
}
  




int *constructBITree(int arr[], int n)
{
    

    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;
  
    

    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);
  
    

    

    

  
    return BITree;
}





void OO_Geez_Rick()
{
    
           int a, b; 
        cin>>a>>b;
        string str; cin>>str;
 
int n=sz(str);
        int c = count(str.begin(), str.end(), '0'), d =  count(str.begin(), str.end(), '1');

        if(c > a || d > b){
            cout<<-1<<endl; 
            return;
        }
 
        a -= c; b -= d;
 
        bool ankit = true;
        rep(i,0,n/2){
            if(str[i] == '?'){
                if(str[n-i-1] == '?')continue;
                if(str[n-i-1] == '1')b--;
                else a--;
                str[i] = str[n-i-1];
            }
            else{
                if(str[n-i-1] == '?'){
                    if(str[i] == '1')b--;
                    else a--;
                    str[n-i-1] = str[i];
                }
                else if(str[i] != str[n-i-1]){ankit = false; break;}
            }
            if(a < 0 || b < 0){
                ankit  = false; break;
            }
        }

        if(!ankit){
            cout<<-1<<endl; return;
        }
 
       rep(i,0,n/2){
            if(str[i] == '?'){
                if(a > 1){
                    str[i] = '0'; str[n-i-1] = '0';
                    a -=2;
                }
                else if(b > 1){
                    str[i] = '1'; str[n-i-1] = '1';
                    b -=2;
                }
                else {
                    ankit= false; break;
                }
            }
        }

 
        if(!ankit){
            cout<<-1<<endl; return;
        }
 
        int m = (n+1)/2  - 1;
 
        if(str[m] == '?'){
            if(a > 0)str[m] = '0';
            else str[m] = '1';
        }
 
        cout<<str<<endl;
    
 
}






signed main()
{ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int t;
cin>>t;
while(t--)
{
 OO_Geez_Rick();
}
return 0;

}

