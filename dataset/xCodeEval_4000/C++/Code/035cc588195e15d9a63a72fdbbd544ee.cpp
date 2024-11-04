#include <iomanip>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <cstring>
#include <unordered_map>
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define ll long long
#define INF ((1<<30)-1)
#define NEG (-1)
#define MOD 1000000007
#define MAXN 100100
#define EPS 1e-9
#define INFLL 1e18
using namespace std;
FILE *in,*out;

namespace fft {
  typedef double dbl;

  struct num {
    dbl x, y;
    num() { x = y = 0; }
    num(dbl x, dbl y) : x(x), y(y) { }
  };

  inline num operator+(num a, num b) { return num(a.x + b.x, a.y + b.y); }
  inline num operator-(num a, num b) { return num(a.x - b.x, a.y - b.y); }
  inline num operator*(num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
  inline num conj(num a) { return num(a.x, -a.y); }

  int base = 1;
  vector<num> roots = {{0, 0}, {1, 0}};
  vector<int> rev = {0, 1};

  const dbl PI = acosl(-1.0);

  void ensure_base(int nbase) {
    if (nbase <= base) {
      return;
    }
    rev.resize(1 << nbase);
    for (int i = 0; i < (1 << nbase); i++) {
      rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    roots.resize(1 << nbase);
    while (base < nbase) {
      dbl angle = 2 * PI / (1 << (base + 1));


      for (int i = 1 << (base - 1); i < (1 << base); i++) {
        roots[i << 1] = roots[i];


        dbl angle_i = angle * (2 * i + 1 - (1 << base));
        roots[(i << 1) + 1] = num(cos(angle_i), sin(angle_i));
      }
      base++;
    }
  }

  void fft(vector<num> &a, int n = -1) {
    if (n == -1) {
      n = a.size();
    }
    

    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for (int i = 0; i < n; i++) {
      if (i < (rev[i] >> shift)) {
        swap(a[i], a[rev[i] >> shift]);
      }
    }
    for (int k = 1; k < n; k <<= 1) {
      for (int i = 0; i < n; i += 2 * k) {
        for (int j = 0; j < k; j++) {
          num z = a[i + j + k] * roots[j + k];
          a[i + j + k] = a[i + j] - z;
          a[i + j] = a[i + j] + z;
        }
      }
    }

  }

  vector<num> fa, fb;

  vector<int> multiply(vector<int> &a, vector<int> &b) {
    int need = a.size() + b.size() - 1;
    int nbase = 0;
    while ((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    int sz = 1 << nbase;
    if (sz > (int) fa.size()) {
      fa.resize(sz);
    }
    for (int i = 0; i < sz; i++) {
      int x = (i < (int) a.size() ? a[i] : 0);
      int y = (i < (int) b.size() ? b[i] : 0);
      fa[i] = num(x, y);
    }
    fft(fa, sz);
    num r(0, -0.25 / sz);
    for (int i = 0; i <= (sz >> 1); i++) {
      int j = (sz - i) & (sz - 1);
      num z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
      if (i != j) {
        fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;
      }
      fa[i] = z;
    }
    fft(fa, sz);
    vector<int> res(need);
    for (int i = 0; i < need; i++) {
      res[i] = fa[i].x + 0.5;
    }
    return res;
  }

  vector<int> multiply_mod(vector<int> &a, vector<int> &b, int m, int eq = 0) {
    int need = a.size() + b.size() - 1;
    int nbase = 0;
    while ((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    int sz = 1 << nbase;
    if (sz > (int) fa.size()) {
      fa.resize(sz);
    }
    for (int i = 0; i < (int) a.size(); i++) {
      int x = (a[i] % m + m) % m;
      fa[i] = num(x & ((1 << 15) - 1), x >> 15);
    }
    fill(fa.begin() + a.size(), fa.begin() + sz, num {0, 0});
    fft(fa, sz);
    if (sz > (int) fb.size()) {
      fb.resize(sz);
    }
    if (eq) {
      copy(fa.begin(), fa.begin() + sz, fb.begin());
    } else {
      for (int i = 0; i < (int) b.size(); i++) {
        int x = (b[i] % m + m) % m;
        fb[i] = num(x & ((1 << 15) - 1), x >> 15);
      }
      fill(fb.begin() + b.size(), fb.begin() + sz, num {0, 0});
      fft(fb, sz);
    }
    dbl ratio = 0.25 / sz;
    num r2(0, -1);
    num r3(ratio, 0);
    num r4(0, -ratio);
    num r5(0, 1);
    for (int i = 0; i <= (sz >> 1); i++) {
      int j = (sz - i) & (sz - 1);
      num a1 = (fa[i] + conj(fa[j]));
      num a2 = (fa[i] - conj(fa[j])) * r2;
      num b1 = (fb[i] + conj(fb[j])) * r3;
      num b2 = (fb[i] - conj(fb[j])) * r4;
      if (i != j) {
        num c1 = (fa[j] + conj(fa[i]));
        num c2 = (fa[j] - conj(fa[i])) * r2;
        num d1 = (fb[j] + conj(fb[i])) * r3;
        num d2 = (fb[j] - conj(fb[i])) * r4;
        fa[i] = c1 * d1 + c2 * d2 * r5;
        fb[i] = c1 * d2 + c2 * d1;
      }
      fa[j] = a1 * b1 + a2 * b2 * r5;
      fb[j] = a1 * b2 + a2 * b1;
    }
    fft(fa, sz);
    fft(fb, sz);
    vector<int> res(need);
    for (int i = 0; i < need; i++) {
      long long aa = fa[i].x + 0.5;
      long long bb = fb[i].x + 0.5;
      long long cc = fa[i].y + 0.5;
      res[i] = (aa + ((bb % m) << 15) + ((cc % m) << 30)) % m;
    }
    return res;
  }

  vector<int> square_mod(vector<int> &a, int m) {
    return multiply_mod(a, a, m, 1);
  }
};








const int base = 10;
const int base_digits = 1; 
struct bigint {
    vector<int> a;
    int sign;
    
    int size(){
    if(a.empty())return 0;
    int ans=(a.size()-1)*base_digits;
    int ca=a.back();
    while(ca)
        ans++,ca/=10;
    return ans;
    }
    bigint operator ^(const bigint &v){
    bigint ans=1,a=*this,b=v;
    while(!b.isZero()){
        if(b%2)
        ans*=a;
        a*=a,b/=2;
    }
    return ans;
    }
    string to_string(){
    stringstream ss;
    ss << *this;
    string s;
    ss >> s;
    return s;
    }
    int sumof(){
    string s = to_string();
    int ans = 0;
    for(auto c : s)  ans += c - '0';
    return ans;
    }
    
    bigint() :
    sign(1) {
    }
 
    bigint(long long v) {
    *this = v;
    }
 
    bigint(const string &s) {
    read(s);
    }
 
    void operator=(const bigint &v) {
    sign = v.sign;
    a = v.a;
    }
 
    void operator=(long long v) {
    sign = 1;
    a.clear();
    if (v < 0)
        sign = -1, v = -v;
    for (; v > 0; v = v / base)
        a.push_back(v % base);
    }
 
    bigint operator+(const bigint &v) const {
    if (sign == v.sign) {
        bigint res = v;
 
        for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
        if (i == (int) res.a.size())
            res.a.push_back(0);
        res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
        carry = res.a[i] >= base;
        if (carry)
            res.a[i] -= base;
        }
        return res;
    }
    return *this - (-v);
    }
 
    bigint operator-(const bigint &v) const {
    if (sign == v.sign) {
        if (abs() >= v.abs()) {
        bigint res = *this;
        for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
            res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
            carry = res.a[i] < 0;
            if (carry)
            res.a[i] += base;
        }
        res.trim();
        return res;
        }
        return -(v - *this);
    }
    return *this + (-v);
    }
 
    void operator*=(int v) {
    if (v < 0)
        sign = -sign, v = -v;
    for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
        if (i == (int) a.size())
        a.push_back(0);
        long long cur = a[i] * (long long) v + carry;
        carry = (int) (cur / base);
        a[i] = (int) (cur % base);
        

    }
    trim();
    }
 
    bigint operator*(int v) const {
    bigint res = *this;
    res *= v;
    return res;
    }
 
    void operator*=(long long v) {
    if (v < 0)
        sign = -sign, v = -v;
    for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
        if (i == (int) a.size())
        a.push_back(0);
        long long cur = a[i] * (long long) v + carry;
        carry = (int) (cur / base);
        a[i] = (int) (cur % base);
        

    }
    trim();
    }
 
    bigint operator*(long long v) const {
    bigint res = *this;
    res *= v;
    return res;
    }
 
    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
    int norm = base / (b1.a.back() + 1);
    bigint a = a1.abs() * norm;
    bigint b = b1.abs() * norm;
    bigint q, r;
    q.a.resize(a.a.size());
 
    for (int i = a.a.size() - 1; i >= 0; i--) {
        r *= base;
        r += a.a[i];
        int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
        int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
        int d = ((long long) base * s1 + s2) / b.a.back();
        r -= b * d;
        while (r < 0)
        r += b, --d;
        q.a[i] = d;
    }
 
    q.sign = a1.sign * b1.sign;
    r.sign = a1.sign;
    q.trim();
    r.trim();
    return make_pair(q, r / norm);
    }
 
    bigint operator/(const bigint &v) const {
    return divmod(*this, v).first;
    }
 
    bigint operator%(const bigint &v) const {
    return divmod(*this, v).second;
    }
 
    void operator/=(int v) {
    if (v < 0)
        sign = -sign, v = -v;
    for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
        long long cur = a[i] + rem * (long long) base;
        a[i] = (int) (cur / v);
        rem = (int) (cur % v);
    }
    trim();
    }
 
    bigint operator/(int v) const {
    bigint res = *this;
    res /= v;
    return res;
    }
 
    int operator%(int v) const {
    if (v < 0)
        v = -v;
    int m = 0;
    for (int i = a.size() - 1; i >= 0; --i)
        m = (a[i] + m * (long long) base) % v;
    return m * sign;
    }
 
    void operator+=(const bigint &v) {
    *this = *this + v;
    }
    void operator-=(const bigint &v) {
    *this = *this - v;
    }
    void operator*=(const bigint &v) {
    *this = *this * v;
    }
    void operator/=(const bigint &v) {
    *this = *this / v;
    }
 
    bool operator<(const bigint &v) const {
    if (sign != v.sign)
        return sign < v.sign;
    if (a.size() != v.a.size())
        return a.size() * sign < v.a.size() * v.sign;
    for (int i = a.size() - 1; i >= 0; i--)
        if (a[i] != v.a[i])
        return a[i] * sign < v.a[i] * sign;
    return false;
    }
 
    bool operator>(const bigint &v) const {
    return v < *this;
    }
    bool operator<=(const bigint &v) const {
    return !(v < *this);
    }
    bool operator>=(const bigint &v) const {
    return !(*this < v);
    }
    bool operator==(const bigint &v) const {
    return !(*this < v) && !(v < *this);
    }
    bool operator!=(const bigint &v) const {
    return *this < v || v < *this;
    }
 
    void trim() {
    while (!a.empty() && !a.back())
        a.pop_back();
    if (a.empty())
        sign = 1;
    }
 
    bool isZero() const {
    return a.empty() || (a.size() == 1 && !a[0]);
    }
 
    bigint operator-() const {
    bigint res = *this;
    res.sign = -sign;
    return res;
    }
 
    bigint abs() const {
    bigint res = *this;
    res.sign *= res.sign;
    return res;
    }
 
    long long longValue() const {
    long long res = 0;
    for (int i = a.size() - 1; i >= 0; i--)
        res = res * base + a[i];
    return res * sign;
    }
 
    friend bigint gcd(const bigint &a, const bigint &b) {
    return b.isZero() ? a : gcd(b, a % b);
    }
    friend bigint lcm(const bigint &a, const bigint &b) {
    return a / gcd(a, b) * b;
    }
 
    void read(const string &s) {
    sign = 1;
    a.clear();
    int pos = 0;
    while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
        if (s[pos] == '-')
        sign = -sign;
        ++pos;
    }
    for (int i = s.size() - 1; i >= pos; i -= base_digits) {
        int x = 0;
        for (int j = max(pos, i - base_digits + 1); j <= i; j++)
        x = x * 10 + s[j] - '0';
        a.push_back(x);
    }
    trim();
    }
 
    friend istream& operator>>(istream &stream, bigint &v) {
    string s;
    stream >> s;
    v.read(s);
    return stream;
    }
 
    friend ostream& operator<<(ostream &stream, const bigint &v) {
    if (v.sign == -1)
        stream << '-';
    stream << (v.a.empty() ? 0 : v.a.back());
    for (int i = (int) v.a.size() - 2; i >= 0; --i)
        stream << setw(base_digits) << setfill('0') << v.a[i];
    return stream;
    }
 
    bigint operator*(const bigint &v) const {
    vector<int> ax(this->a.begin(), this->a.end());
    vector<int> bx(v.a.begin(), v.a.end());
    vector<int> c = fft::multiply(ax,bx);
    bigint res;
    res.sign = sign * v.sign;
    int i, carry;
    for (i = 0, carry = 0; i < (int) c.size(); i++) {
        if(c[i]<0)
        {
            printf("Error! FFT out of range!\n");
            exit(0);
        }
        long long cur = c[i] + carry;
        res.a.push_back((int) (cur % base));
        carry = (int) (cur / base);
    }
    if(carry)
        res.a.push_back(carry);
    res.trim();
    return res;
    }
};
































int N,M,K;

int read()
{
    int i,j,k;
    bigint a;
    cin >> a;
    if(a == 1)
    {
        cout << 1 <<endl;
        return 0;
    }
    int x = max(0,(int)ceil((a.size()-1) * logl(10) / logl(3))-3);
    int ans = -1;
    bigint st = (bigint(3)^x);
    for(i=0,j=1;i<3;i++,j*=2)
    {
        bigint cur = st;
        k = x*3 + i*2;
        cur *= j;
        while(cur < a)
        {
            cur *= 3;
            k += 3;
        }
        

        

        

        

        if(ans == -1 || ans > k)
            ans = k;
    }
    cout << ans << endl;
    return 0;
}

int main()
{
    

    

    in = stdin;
    out = stdout;
    read();
    return 0;
}

















