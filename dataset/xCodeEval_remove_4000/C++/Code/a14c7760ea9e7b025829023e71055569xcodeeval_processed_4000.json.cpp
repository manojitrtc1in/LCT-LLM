









namespace mirai {








void flush_input(); ll sscan(); void sread(bool&); void sread(int&); void sread(u&); void sread(short&); 
void sread(long&); void sread(ll&); void sread(u short&); void sread(u long&); void sread(u ll&); void sread(char&); 
void sread(char*); void sread(float&); void sread(double&); void sread(long double&); template <typename type> 
void sread(type&); u ll scan(); void read(bool&); void read(int&); void read(short&); void read(long&); void read(ll&); 
void read(u int&); void read(u short&); void read(u long&); void read(u ll&); void read(char&); void read(char*); 
void read(float&); void read(double&); void read(long double&); template <typename type> void read(type&); char readch(); 
char readc(); void readstr(char*); float readf(); double id0(); long double readlf();

template <typename type, typename... Args> void sread(type&, Args&...); 
template <typename type, typename... Args> void read(type&, Args&...); 











}  




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


  __cplusplus < 201103L

use MIRAI_FORCE_USE_ARG_LIST if really need.






  __cplusplus < 202002L

use MIRAI_FORCE_ATTR_EXPECT if really need.

































char input_buffer[MIRAI_INPUT_BUFFER_SIZE + 1];
char *id1 = input_buffer;
char *input_buffer_end = input_buffer + MIRAI_INPUT_BUFFER_SIZE;

void flush_input(void) {
  
  std::size_t ret = ::read(0, input_buffer, MIRAI_INPUT_BUFFER_SIZE);
  
  std::size_t ret = std::fread(input_buffer, sizeof(input_buffer[0]), 
    MIRAI_INPUT_BUFFER_SIZE, stdin);
  
  iff(ret < MIRAI_INPUT_BUFFER_SIZE) {
    input_buffer[ret] = '\0';
  }
  id1 = input_buffer;
  return;
}

void flush_input(void) {}





char readchar(void) {
  iff(id1 == input_buffer_end) {
    flush_input();
  }
  return *(id1++);
}








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
void sread(double& u) { u = id0(); }
void sread(long double& u) { u = readlf(); }




template <typename type, typename... Args>
void sread(type &u, Args&... args) {
  sread(u);
  sread(args...);
  return;
}




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
void read(double& u) { u = id0(); }
void read(long double& u) { u = readlf(); }




template <typename type, typename... Args>
void read(type &u, Args&... args) {
  read(u);
  read(args...);
  return;
}


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
double id0(void) {
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








}  


int main(void) {
  
  std::freopen(__FILE__ "\\..\\tests\\" MIRAI_TESTNO ".in", "r", stdin);
  std::freopen(__FILE__ "\\..\\tests\\" MIRAI_TESTNO ".out", "w", stdout);
  
  
  mirai::flush_input();
  
  int ret = mirai::main();
  
  std::fclose(stdin);
  std::fclose(stdout);
  
  
  std::system("pause");
  
  return ret;
}
