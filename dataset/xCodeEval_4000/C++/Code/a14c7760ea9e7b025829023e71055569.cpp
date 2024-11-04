


#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <vector>
#include <cstring>

namespace mirai {
#define FILE_IO
#define MIRAI_INPUT_BUFFER
#define MIRAI_DEBUG
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

#if defined(MIRAI_LOCAL) && defined(MIRAI_DEBUG)
#define assume(statement) (statement || (std::printf("Assumption failed on line #%d: " #statement " == false", __LINE__), std::exit(1), 0))
#define dprintf(...) (std::printf(__VA_ARGS__))
#else
#define assume(statement) (0)
#define dprintf(statement) (0)
#endif
}  


#define MIRAI_TESTNO "1540B-3"

namespace mirai {

using ll = long long;
constexpr ll mod = 1e9L + 7;
constexpr int MAXN = 220;
std::vector<int> graph[MAXN];
ll f[MAXN][MAXN];
ll pow(ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b & 1) {
      ret = ret * a % mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}
inline ll inv(ll a) {
  return pow(a, mod - 2);
}
int dep[MAXN], top[MAXN], sze[MAXN], fa[MAXN], hson[MAXN];

void dfs1(int u, int f) {
  sze[u] = 1;
  fa[u] = f;
  dep[u] = dep[f] + 1;
  for (auto v : graph[u]) {
    if (v == f) { continue; }
    dfs1(v, u);
    sze[u] += sze[v];
    if (sze[hson[u]] < sze[v]) {
      hson[u] = v;
    }
  }
  return;
}
void dfs2(int u, int tp) {
  top[u] = tp;
  if (hson[u]) {
    dfs2(hson[u], tp);
  }
  for (auto v : graph[u]) {
    if (v == fa[u] || v == hson[u]) { continue; }
    dfs2(v, v);
  }
  return;
}
int lca(int u, int v) {
  while (top[u] != top[v]) {
    if (dep[top[u]] > dep[top[v]]) {
      u = fa[top[u]];
    } else {
      v = fa[top[v]];
    }
  }
  return dep[u] < dep[v] ? u : v;
}

int main(void) {
  int n = scan();
  for (int i = 1; i < n; ++i) {
    int u, v;
    u = scan();
    v = scan();
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  ll tot = 0;
  ll inv2 = inv(2);
  for (int i = 1; i <= n; ++i) {
    f[0][i] = 0;
    f[i][0] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      f[i][j] = (f[i][j - 1] + f[i - 1][j]) * inv2 % mod;
    }
  }
  for (int u = 1; u <= n; ++u) {
    std::memset(hson, 0x00, sizeof(hson));
    fa[u] = 0;
    dfs1(u, 0);
    dfs2(u, u);
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        int l = lca(i, j);
        int u = dep[i] - dep[l], v = dep[j] - dep[l];
        tot += f[u][v];
        if (tot >= mod) { tot -= mod; }
      }
    }
  }
  std::printf("%lld\n", tot * inv(n) % mod);
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


int main(void) {
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
  #if defined(MIRAI_PAUSE) && defined(MIRAI_LOCAL)
  std::system("pause");
  #endif
  return ret;
}
