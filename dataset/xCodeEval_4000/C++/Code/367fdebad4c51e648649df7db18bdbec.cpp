
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>

namespace mirai {
#define FILE_IO
#ifdef FILE_IO
#define MIRAI_INPUT_BUFFER
#endif
#define MIRAI_INPUT_BUFFER_SIZE (1L << 16)
#define MIRAI_USE_ARG_LIST

#define ll long long
#define u unsigned
void flush_input(); ll sscan(); void sread(bool&); void sread(int&); void sread(u&); void sread(short&); 
void sread(long&); void sread(ll&); void sread(u short&); void sread(u long&); void sread(u ll&); void sread(char&); 
void sread(char*); void sread(float&); void sread(double&); void sread(long double&); template <typename type> 
void sread(type&); u ll scan(); void read(bool&); void read(int&); void read(short&); void read(long&); void read(ll&); 
void read(u int&); void read(u short&); void read(u long&); void read(u ll&); void read(char&); void read(char*); 
void read(float&); void read(double&); void read(long double&); template <typename type> void read(type&); char readch(); 
char readc(); void readstr(char*); float readf(); double readdf(); long double readlf();
#if (defined(MIRAI_USE_ARG_LIST) && __cplusplus >= 201103L) || defined(MIRAI_FORCE_USE_ARG_LIST)
template <typename type, typename... Args> void sread(type&, Args&...); 
template <typename type, typename... Args> void read(type&, Args&...); 
#endif
#undef u
#undef ll
}  


#define MIRAI_TESTNO "1527E-1"

namespace mirai {

using ll = long long;
constexpr int MAXN = 4e4;
int a[MAXN];
int prev[MAXN], nxt[MAXN];
int first[MAXN], last[MAXN];
int tmp[MAXN];
ll sum = 0;
int L, R;

ll calc(int l, int r) {
  while (L > l) {
    L--;
    int u = a[L];
    if (first[u] == 0) {
      first[u] = last[u] = L;
    } else {
      sum += first[u] - L;
      first[u] = L;
    }
  }
  while (R < r) {
    R++;
    int u = a[R];
    if (first[u] == 0) {
      first[u] = last[u] = R;
    } else {
      sum += R - last[u];
      last[u] = R;
    }
  }
  while (L < l) {
    int u = a[L];
    if (last[u] == L) {
      first[u] = last[u] = 0;
    } else {
      sum -= nxt[L] - L;
      first[u] = nxt[L];
    }
    L++;
  }
  while (R > r) {
    int u = a[R];
    if (first[u] == R) {
      first[u] = last[u] = 0;
    } else {
      sum -= R - prev[R];
      last[u] = prev[R];
    }
    R--;
  }
  return sum;
}

ll dp[2][MAXN];
ll& f(int u, int v) {
  return dp[u & 1][v];
}

void solve(int l, int r, int ml, int mr, int c) {
  if (l > r || ml > mr) { return; }
  int mid = (l + r) / 2, m = 0;
  ll tmp = 0;
  f(c, mid) = 0x3f3f3f3f3f3f3f3fll;
  for (int i = ml; i <= mr && i < mid; ++i) {
    tmp = f(c - 1, i) + calc(i + 1, mid);
    if (f(c, mid) > tmp) {
      f(c, mid) = tmp;
      m = i;
    }
  }
  solve(l, mid - 1, ml, m, c);
  solve(mid + 1, r, m, mr, c);
  return;
}

int main() {
  int n, k;
  read(n, k);
  for (int i = 1; i <= n; ++i) {
    read(a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    prev[i] = tmp[a[i]];
    tmp[a[i]] = i;
  }
  std::memset(tmp, 0x00, sizeof(tmp));
  for (int i = n; i >= 1; --i) {
    nxt[i] = tmp[a[i]];
    tmp[a[i]] = i;
  }
  L = 1;
  

  

  

  

  

  

  for (int i = 1; i <= n; ++i) {
    f(0, i) = calc(1, i);
  }
  for (int i = 1; i < k; ++i) {
    solve(1, n, 0, n - 1, i);
  }
  std::printf("%lld\n", f(k - 1, n));
  return 0;
}

}  


namespace mirai {

#if !defined(MIRAI_FORCE_USE_ARG_LIST) && defined(MIRAI_USE_ARG_LIST) && \
  __cplusplus < 201103L
#error MIRAI_USE_ARG_LIST needs C++11 to enable. \
use MIRAI_FORCE_USE_ARG_LIST if really need.
#endif
#ifdef MIRAI_FORCE_USE_ARG_LIST
#define MIRAI_USE_ARG_LIST
#endif

#if !defined(MIRAI_FORCE_ATTR_EXPECT) && defined(MIRAI_ATTR_EXPECT) && \
  __cplusplus < 202002L
#error MIRAI_ATTR_EXPECT needs C++20 to enable. \
use MIRAI_FORCE_ATTR_EXPECT if really need.
#undef MIRAI_ATTR_EXPECT
#endif
#ifdef MIRAI_FORCE_ATTR_EXPECT
#define MIRAI_ATTR_EXPECT
#endif

#ifdef MIRAI_ATTR_EXPECT
#define ift(x) [[likely]] if (x)
#define iff(x) [[unlikely]] if (x)
#define whilet(x) [[unlikely]] while (x)
#define whilef(x) [[likely]] while (x)
#elif defined(MIRAI_BUILTIN_EXPECT)
#define ift(x) if (__builtin_expect(!!(x), 1))
#define iff(x) if (__builtin_expect(!!(x), 0))
#define whilet(x) while (__builtin_expect(!!(x), 1))
#define whilef(x) while (__builtin_expect(!!(x), 0))
#else 
#define ift(x) if (x)
#define iff(x) if (x)
#define whilet(x) while (x)
#define whilef(x) while (x)
#endif

#ifndef MIRAI_INPUT_BUFFER_SIZE
#define MIRAI_INPUT_BUFFER_SIZE (1UL << 16)
#endif
#ifndef MIRAI_OUTPUT_BUFFER_SIZE
#define MIRAI_OUTPUT_BUFFER_SIZE (1UL << 16)
#endif

#ifdef MIRAI_INPUT_BUFFER


char input_buffer[MIRAI_INPUT_BUFFER_SIZE + 1];
char *input_buffer_now = input_buffer;
char *input_buffer_end = input_buffer + MIRAI_INPUT_BUFFER_SIZE;

void flush_input(void) {
  #ifdef MIRAI_USE_READ_FUNC
  std::size_t ret = ::read(0, input_buffer, MIRAI_INPUT_BUFFER_SIZE);
  #else
  std::size_t ret = std::fread(input_buffer, sizeof(input_buffer[0]), 
    MIRAI_INPUT_BUFFER_SIZE, stdin);
  #endif
  iff(ret < MIRAI_INPUT_BUFFER_SIZE) {
    input_buffer[ret] = '\0';
  }
  input_buffer_now = input_buffer;
  return;
}
#else
void flush_input(void) {}
#endif

#ifndef MIRAI_INPUT_BUFFER
#define readchar() (std::getchar())
#else
char readchar(void) {
  iff(input_buffer_now == input_buffer_end) {
    flush_input();
  }
  return *(input_buffer_now++);
}
#endif

#ifdef MIRAI_USE_ISDIGIT
#define digit(x) (std::isdigit(x))
#else
#define digit(x) ((x) >= '0' && (x) <= '9')
#endif

void readstr(char*);

long long sscan(void) {
  char ch = readchar();
  whilet(!digit(ch) && ch != '-') {
    ch = readchar();
  }
  unsigned long long ret = 0;
  bool flag = false;
  iff(ch != '-') {
    ret = ch - '0';
  } else {
    flag = true;
  }
  ch = readchar();
  whilet(digit(ch)) {
    ret = ret * 10 + ch - '0';
    ch = readchar();
  }
  iff(flag) {
    return -ret;
  } else {
    return ret;
  }
}

void sread(bool& u) { u = sscan(); }
void sread(int& u) { u = sscan(); }
void sread(short& u) { u = sscan(); }
void sread(long& u) { u = sscan(); }
void sread(long long& u) { u = sscan(); }
void sread(unsigned int& u) { u = sscan(); }
void sread(unsigned short& u) { u = sscan(); }
void sread(unsigned long& u) { u = sscan(); }
void sread(unsigned long long& u) { u = sscan(); }

void sread(char& u) {
  u = readchar();
  return;
}
void sread(char* str) {
  readstr(str);
  return;
}

void sread(float& u) { u = readf(); }
void sread(double& u) { u = readdf(); }
void sread(long double& u) { u = readlf(); }

#ifdef MIRAI_USE_ARG_LIST


template <typename type, typename... Args>
void sread(type &u, Args&... args) {
  sread(u);
  sread(args...);
  return;
}
#endif



unsigned long long scan(void) {
  char ch = readchar();
  whilet(!digit(ch)) {
    ch = readchar();
  }
  unsigned long long ret = ch - '0';
  ch = readchar();
  whilet(digit(ch)) {
    ret = ret * 10 + ch - '0';
    ch = readchar();
  }
  return ret;
}

void read(bool& u) { u = scan(); }
void read(int& u) { u = scan(); }
void read(short& u) { u = scan(); }
void read(long& u) { u = scan(); }
void read(long long& u) { u = scan(); }
void read(unsigned int& u) { u = scan(); }
void read(unsigned short& u) { u = scan(); }
void read(unsigned long& u) { u = scan(); }
void read(unsigned long long& u) { u = scan(); }

void read(char& u) {
  u = readchar();
}
void read(char* str) {
  readstr(str);
  return;
}

void read(float& u) { u = readf(); }
void read(double& u) { u = readdf(); }
void read(long double& u) { u = readlf(); }

#ifdef MIRAI_USE_ARG_LIST


template <typename type, typename... Args>
void read(type &u, Args&... args) {
  read(u);
  read(args...);
  return;
}
#endif

bool isvisible(char ch) {
  return ch > '\x20' && ch < '\x7F';
}

char readch(void) {
  char ch;
  ch = readchar();
  return ch;
}
char readc(void) {
  char ch;
  ch = readchar();
  whilet(!isvisible(ch)) {
    ch = readchar();
  }
  return ch;
}

void readstr(char* str) {
  *str = ' ';
  whilef(!isvisible(*str)) {
    *str = readchar();
  }
  whilet(isvisible(*str)) {
    str++;
    *str = readchar();
  }
  *str = '\0';
  return;
}

float readf(void) {
  float x = 0;
  char ch = readchar();
  whilet(!digit(ch) && ch != '-') {
    ch = readchar();
  }
  bool flag = false;
  iff(ch == '-') {
    flag = true;
  } else iff(ch != '+' && ch != '.') {
    x = ch - '0';
  }
  ch = readchar();
  whilet(digit(ch)) {
    x = x * 10 + ch - '0';
    ch = readchar();
  }
  ift(ch == '.') {
    float tmp = 0;
    tmp = 0.1;
    ch = readchar();
    whilet(digit(ch)) {
      x += tmp * (ch - '0');
      tmp = tmp * 0.1;
      ch = readchar();
    }
  }
  ift(ch == 'e' || ch == 'E') {
    unsigned int y = 0, cnt = 6;
    ch = readchar();
    bool flag2 = false;
    iff(ch == '-') {
      flag2 = true;
    } else ift(digit(ch)) {
      y = ch - '0';
      cnt--;
    }
    ch = readchar();
    whilet(digit(ch) && cnt) {
      y = y * 10 + (ch - '0');
      cnt--;
      ch = readchar();
    }
    if (digit(ch) && cnt == 0) {
      while (digit(ch)) {
        ch = readchar();
      }
    }
    if (flag2) {
      x = x * std::pow(10.F, -1.F * y);
    } else {
      x = x * std::pow<float, float>(10, y);
    }
  }
  iff(flag) {
    return -x;
  } else {
    return x;
  }
}
double readdf(void) {
  double x = 0;
  char ch = readchar();
  whilet(!digit(ch) && ch != '-') {
    ch = readchar();
  }
  bool flag = false;
  iff(ch == '-') {
    flag = true;
  } else iff(ch != '+' && ch != '.') {
    x = ch - '0';
  }
  ch = readchar();
  whilet(digit(ch)) {
    x = x * 10 + ch - '0';
    ch = readchar();
  }
  ift(ch == '.') {
    double tmp = 0;
    tmp = 0.1;
    ch = readchar();
    whilet(digit(ch)) {
      x += tmp * (ch - '0');
      tmp = tmp * 0.1;
      ch = readchar();
    }
  }
  ift(ch == 'e' || ch == 'E') {
    unsigned int y = 0, cnt = 6;
    ch = readchar();
    bool flag2 = false;
    iff(ch == '-') {
      flag2 = true;
    } else ift(digit(ch)) {
      y = ch - '0';
      cnt--;
    }
    ch = readchar();
    whilet(digit(ch) && cnt) {
      y = y * 10 + (ch - '0');
      cnt--;
      ch = readchar();
    }
    if (digit(ch) && cnt == 0) {
      while (digit(ch)) {
        ch = readchar();
      }
    }
    if (flag2) {
      x = x * std::pow(10., -1. * y);
    } else {
      x = x * std::pow<double, double>(10, y);
    }
  }
  iff(flag) {
    return -x;
  } else {
    return x;
  }
}
long double readlf(void) {
  long double x = 0;
  char ch = readchar();
  whilet(!digit(ch) && ch != '-') {
    ch = readchar();
  }
  bool flag = false;
  iff(ch == '-') {
    flag = true;
  } else iff(ch != '+' && ch != '.') {
    x = ch - '0';
  }
  ch = readchar();
  whilet(digit(ch)) {
    x = x * 10 + ch - '0';
    ch = readchar();
  }
  ift(ch == '.') {
    long double tmp = 0;
    tmp = 0.1;
    ch = readchar();
    whilet(digit(ch)) {
      x += tmp * (ch - '0');
      tmp = tmp * 0.1;
      ch = readchar();
    }
  }
  ift(ch == 'e' || ch == 'E') {
    unsigned int y = 0, cnt = 6;
    ch = readchar();
    bool flag2 = false;
    iff(ch == '-') {
      flag2 = true;
    } else ift(digit(ch)) {
      y = ch - '0';
      cnt--;
    }
    ch = readchar();
    whilet(digit(ch) && cnt) {
      y = y * 10 + (ch - '0');
      cnt--;
      ch = readchar();
    }
    if (digit(ch) && cnt == 0) {
      while (digit(ch)) {
        ch = readchar();
      }
    }
    if (flag2) {
      x = x * std::pow(10.L, -1.L * y);
    } else {
      x = x * std::pow<long double, long double>(10, y);
    }
  }
  iff(flag) {
    return -x;
  } else {
    return x;
  }
}

#undef ift
#undef iff
#undef whilet
#undef whilef
#undef digit
#undef readchar

}  


int main() {
  #if defined(MIRAI_LOCAL) && defined(FILE_IO)
  std::freopen(__FILE__ "\\..\\tests\\" MIRAI_TESTNO ".in", "r", stdin);
  std::freopen(__FILE__ "\\..\\tests\\" MIRAI_TESTNO ".out", "w", stdout);
  #endif
  #ifdef MIRAI_INPUT_BUFFER
  mirai::flush_input();
  #endif
  int ret = mirai::main();
  #if defined(MIRAI_LOCAL) && defined(FILE_IO)
  std::fclose(stdin);
  std::fclose(stdout);
  #endif
  return ret;
}
