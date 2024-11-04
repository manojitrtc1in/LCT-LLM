
 

 
#pragma region
 
#include <bits/stdc++.h>
 
#define CodeForces
 
#ifndef CodeForces
#include <bits/extc++.h>
#endif
 
#define cin fio
#define cout fio
#define endl '\n'
 
#ifdef Atcoder
#include <atcoder/all>
#endif
 
#ifdef UVA
#warning UVA请注意格式
#warning UVA请注意是否正常运转
#endif
 
#define int long long
 
using namespace std;
 
template <class T>
inline double rand(T L, T R)
{
  return (T)rand() / (T)32767 * (R - L) + L;
}
 
struct bigint
{
  static const int MAXN = 1005;
  int d[MAXN], len;
  void clean()
  {
    while (len > 1 && !d[len - 1])
      len--;
  }
  bigint()
  {
    memset(d, 0, sizeof(d));
    len = 1;
  }
  bigint(int num) { *this = num; }
  bigint(char *num) { *this = num; }
  bigint operator=(const char *num)
  {
    memset(d, 0, sizeof(d));
    len = strlen(num);
    for (int i = 0; i < len; i++)
      d[i] = num[len - 1 - i] - '0';
    clean();
    return *this;
  }
  bigint operator=(int num)
  {
    char s[20];
    sprintf(s, "%d", num);
    *this = s;
    return *this;
  }
 
  bigint operator+(const bigint &b)
  {
    bigint c = *this;
    int i;
    for (i = 0; i < b.len; i++)
    {
      c.d[i] += b.d[i];
      if (c.d[i] > 9)
        c.d[i] %= 10, c.d[i + 1]++;
    }
    while (c.d[i] > 9)
      c.d[i++] %= 10, c.d[i]++;
    c.len = max(len, b.len);
    if (c.d[i] && c.len <= i)
      c.len = i + 1;
    return c;
  }
  bigint operator-(const bigint &b)
  {
    bigint c = *this;
    int i;
    for (i = 0; i < b.len; i++)
    {
      c.d[i] -= b.d[i];
      if (c.d[i] < 0)
        c.d[i] += 10, c.d[i + 1]--;
    }
    while (c.d[i] < 0)
      c.d[i++] += 10, c.d[i]--;
    c.clean();
    return c;
  }
  bigint operator*(const bigint &b) const
  {
    int i, j;
    bigint c;
    c.len = len + b.len;
    for (j = 0; j < b.len; j++)
      for (i = 0; i < len; i++)
        c.d[i + j] += d[i] * b.d[j];
    for (i = 0; i < c.len - 1; i++)
      c.d[i + 1] += c.d[i] / 10, c.d[i] %= 10;
    c.clean();
    return c;
  }
  bigint operator/(const bigint &b) const
  {
    int i, j;
    bigint c = *this, a = 0LL;
    for (i = len - 1; i >= 0; i--)
    {
      a = a * 10 + d[i];
      for (j = 0; j < 10; j++)
        if (a < b * (j + 1))
          break;
      c.d[i] = j;
      a = a - b * j;
    }
    c.clean();
    return c;
  }
  bigint operator%(const bigint &b) const
  {
    int i, j;
    bigint a = 0LL;
    for (i = len - 1; i >= 0; i--)
    {
      a = a * 10 + d[i];
      for (j = 0; j < 10; j++)
        if (a < b * (j + 1))
          break;
      a = a - b * j;
    }
    return a;
  }
  bool operator<(const bigint &b) const
  {
    if (len != b.len)
      return len < b.len;
    for (int i = len - 1; i >= 0; i--)
      if (d[i] != b.d[i])
        return d[i] < b.d[i];
    return false;
  }
  bigint operator/=(const bigint &b)
  {
    *this = *this / b;
    return *this;
  }
  bigint operator*=(const bigint &b)
  {
    *this = *this * b;
    return *this;
  }
  bigint operator+=(const bigint &b)
  {
    *this = *this + b;
    return *this;
  }
  bigint operator-=(const bigint &b)
  {
    *this = *this - b;
    return *this;
  }
  bool operator>(const bigint &b) const
  {
    return b < *this;
  }
  bool operator<=(const bigint &b) const
  {
    return !(b < *this);
  }
  bool operator>=(const bigint &b) const
  {
    return !(*this < b);
  }
  bool operator!=(const bigint &b) const
  {
    return b < *this || *this < b;
  }
  bool operator==(const bigint &b) const
  {
    return !(b < *this) && !(b > *this);
  }
  string str() const
  {
    char s[MAXN] = {};
    for (int i = 0; i < len; i++)
      s[len - 1 - i] = d[i] + '0';
    return s;
  }
};
istream &operator>>(istream &in, bigint &x)
{
  string s;
  in >> s;
  x = s.c_str();
  return in;
}
ostream &operator<<(ostream &out, const bigint &x)
{
  out << x.str();
  return out;
}
 
const int mod = 2017;
 
class matrix
{
public:
  int z[103][103];
  int r, c;
  matrix()
  {
    memset(z, 0, sizeof z);
    r = c = 0;
  }
  matrix(int x, int y, int w)
  {
    r = x, c = y;
    for (int i = 1; i <= x; i++)
      for (int j = 1; j <= y; j++)
        z[i][j] = w;
  }
};
 
int gsc(int a, int b, int c)
{
  if (!b)
    return 0;
  int ans = gsc(a, b >> 1, c);
  ans = (ans + ans) % c;
  if (b & 1)
    ans = (ans + a) % c;
  return ans;
}
 
matrix operator*(const matrix &a, const matrix &b)
{
  if (a.c != b.r)
  {
    puts("Oops!");
    throw;
  }
  matrix c;
  c.r = a.r;
  c.c = b.c;
  for (int i = 0; i <= c.r; i++)
    for (int j = 0; j <= c.c; j++)
      for (int k = 0; k <= a.c; k++)
        (c.z[i][j] += gsc(a.z[i][k], b.z[k][j], mod)) %= mod;
  return c;
}
 
matrix operator*=(matrix &a, const matrix &b)
{
  a = a * b;
  return a;
}
 
matrix I, ans;
 
void ksm(matrix a, int b)
{
  if (b == 1)
  {
    ans = a;
    return;
  }
  ksm(a, b >> 1);
  ans = ans * ans;
  if (b & 1)
    ans = ans * a;
}
 
class fastIO
{
private:
  char ibuf[1000007], *p1 = ibuf, *p2 = ibuf, obuf[1000007], *p3 = obuf, sta[50];
  bool file_end = false;
  char get()
  {
    return p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1000007, stdin), p1 == p2) ? (file_end = true), EOF : *p1++;
  }
  void put(char x)
  {
    p3 - obuf < 1000007 ? *p3++ = x : (fwrite(obuf, p3 - obuf, 1, stdout), p3 = obuf, *p3++ = x);
  }
 
public:
  explicit operator bool()
  {
    return !file_end;
  }
  size_t flush()
  {
    size_t f = fwrite(obuf, p3 - obuf, 1, stdout);
    p3 = obuf;
    *p3 = 0;
    return f;
  }
  fastIO &operator>>(char &t)
  {
    for (t = get(); !isgraph(t); t = get())
      ;
    return *this;
  }
  template <typename any>
  typename std::enable_if<std::is_same<any, char>::value, any>::type tpval()
  {
    char t;
    for (t = get(); !isgraph(t); t = get())
      ;
    return t;
  }
  fastIO &operator>>(char *t)
  {
    char c;
    for (c = get(); !isgraph(c); c = get())
      ;
    for (; isgraph(c); c = get())
      *t = c, t++;
    *t = 0;
    return *this;
  }
  fastIO &operator>>(std::string &t)
  {
    t.clear();
    char c;
    for (c = get(); !isgraph(c); c = get())
      ;
    for (; isgraph(c); c = get())
      t += c;
    return *this;
  }
  template <typename any>
  typename std::enable_if<std::is_same<any, std::string>::value, any>::type tpval()
  {
    std::string t;
    char c;
    for (c = get(); !isgraph(c); c = get())
      ;
    for (; isgraph(c); c = get())
      t += c;
    return t;
  }
  template <typename any>
  typename std::enable_if<(std::is_signed<any>::value && std::is_integral<any>::value && !std::is_same<any, char>::value) || std::is_same<any, __int128_t>::value, fastIO>::type &operator>>(any &t)
  {
    t = 0;
    bool y = 0;
    char c = get();
    for (; !isdigit(c); c = get())
      if (c == 45)
        y = true;
    for (; isdigit(c); c = get())
      t = (t << 3) + (t << 1) + (c ^ 48);
    if (y == 1)
      t = -t;
    return *this;
  }
  template <typename any>
  typename std::enable_if<(std::is_signed<any>::value && std::is_integral<any>::value && !std::is_same<any, char>::value) || std::is_same<any, __int128_t>::value, any>::type tpval()
  {
    any t = 0;
    bool y = 0;
    char c = get();
    for (; !isdigit(c); c = get())
      if (c == 45)
        y = true;
    for (; isdigit(c); c = get())
      t = (t << 3) + (t << 1) + (c ^ 48);
    if (y == 1)
      t = -t;
    return t;
  }
  template <typename any>
  typename std::enable_if<(std::is_unsigned<any>::value && std::is_integral<any>::value && !std::is_same<any, char>::value || std::is_same<any, __uint128_t>::value), fastIO>::type &operator>>(any &t)
  {
    t = 0;
    char c = get();
    for (; !isdigit(c); c = get())
      ;
    for (; isdigit(c); c = get())
      t = (t << 3) + (t << 1) + (c ^ 48);
    return *this;
  }
  template <typename any>
  typename std::enable_if<(std::is_unsigned<any>::value && std::is_integral<any>::value && !std::is_same<any, char>::value) || std::is_same<any, __uint128_t>::value, any>::type tpval()
  {
    any t = 0;
    char c = get();
    for (; !isdigit(c); c = get())
      ;
    for (; isdigit(c); c = get())
      t = (t << 3) + (t << 1) + (c ^ 48);
    return t;
  }
  template <typename any1, typename any2>
  fastIO &operator>>(std::pair<any1, any2> &t)
  {
    return *this >> t.first >> t.second;
  }
  fastIO &operator<<(const char t)
  {
    put(t);
    return *this;
  }
  fastIO &operator<<(const char *t)
  {
    for (; *t; t++)
      put(*t);
    return *this;
  }
  fastIO &operator<<(const std::string &t)
  {
    for (const char it : t)
      put(it);
    return *this;
  }
  template <typename any>
  typename std::enable_if<(std::is_signed<any>::value && std::is_integral<any>::value && !std::is_same<any, char>::value) || std::is_same<any, __int128_t>::value, fastIO>::type &operator<<(any t)
  {
    if (!t)
    {
      put(48);
      return *this;
    }
    int len = 0;
    if (t < 0)
      t = -t, put(45);
    while (t)
      sta[len++] = t % 10 + 48, t /= 10;
    while (len--)
      put(sta[len]);
    return *this;
  }
  template <typename any>
  typename std::enable_if<(std::is_unsigned<any>::value && std::is_integral<any>::value && !std::is_same<any, char>::value || std::is_same<any, __uint128_t>::value), fastIO>::type &operator<<(any t)
  {
    if (!t)
    {
      put(48);
      return *this;
    }
    int len = 0;
    while (t)
      sta[len++] = t % 10 + 48, t /= 10;
    while (len--)
      put(sta[len]);
    return *this;
  }
  template <typename any1, typename any2>
  fastIO &operator<<(const std::pair<any1, any2> &t)
  {
    return *this << t.first << ' ' << t.second;
  }
  ~fastIO()
  {
    fwrite(obuf, p3 - obuf, 1, stdout);
  }
} fio;
 
int H(int n)
{
  int m = sqrt(n);
  int ans = 0;
  for (int i = 1; i <= m; i++)
    ans += n / i;
  ans <<= 1;
  ans -= m * m;
  return ans;
}
 
#if 0
double a[233][233], x[233];
#endif
 
inline int gcd(int a, int b)
{
  return b ? a : gcd(b, a % b);
}
 
inline int lcm(int a, int b)
{
  return a / gcd(a, b) * b;
}
 
#if 0
int n;
 
void gauss() {
    for (int i = 1; i <= n; i ++) {
        int id = i;
        for (int j = i; j <= n; j ++)
            if (fabs(a[j][i]) > fabs(a[i][i]))
                id = j;
        for (int k = 1; k <= n + 1; k ++)
            swap (a[i][k], a[id][k]);
        if (fabs(a[i][i]) < 1e-8)
            continue ; 

        for (int j = i + 1; j <= n; j ++) {
            double ratio = a[j][i] / a[i][i];
            for (int k = 1; k <= n + 1; k ++)
                a[j][k] -= a[i][k] * ratio;
        }
    }
    bool _1 = false, _2 = false;
    for (int i = 1; i <= n; i ++) {
        int j = 1;
        while (fabs(a[i][j]) < 1e-8 && j <= n + 1)
            j ++;
        if (j == n + 1)
            _1 = true;
        if (j > n + 1)
            _2 = true;
    }
    if (_1)
        puts("-1");
    else if (_2)
        puts("0");
    else {
        x[n] = a[n][n + 1] / a[n][n];
        for (int i = n; i; i --) {
            for (int j = i + 1; j <= n; j ++)
                a[i][n + 1] -= a[i][j] * x[j];
            x[i] = a[i][n + 1] / a[i][i];
        }
        for (int i = 1; i <= n; i ++)
            if (fabs(x[i]) < 1e-8)
                x[i] = fabs(x[i]);
        for (int i = 1; i <= n; i ++)
            printf ("x%d=%.2lf\n", i, x[i]);
    }
}
#endif
 
void solve()
{
  int a, b, c;
  cin >> a >> b >> c;
  int _1 = a - 1;
  int _2;
  if (b >= c)
    _2 = b - 1;
  else
    _2 = c - b + c - 1;
  if (_1 > _2)
    cout << "2\n";
  else if (_1 < _2)
    cout << "1\n";
  else
    cout << "3\n";
}
 
signed main()
{
  int T;
  cin >> T;
  while (T --)
    solve();
  return 0;
}
 
#pragma endregion
 


 




























































