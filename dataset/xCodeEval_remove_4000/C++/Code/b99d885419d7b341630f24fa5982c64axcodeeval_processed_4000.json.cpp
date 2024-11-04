







namespace mirai {









void flush_input(); ll sscan(); void sread(bool&); void sread(int&); void sread(u&); 
void sread(short&); void sread(long&); void sread(ll&); void sread(u short&); void sread(u long&); void sread(u ll&); 
void sread(char&); void sread(char*); void sread(float&); void sread(double&); void sread(long double&); 
template <typename type> void sread(type&); template <typename type, typename... Args> void sread(type&, Args&...); 
u ll scan(); void read(bool&); void read(int&); void read(short&); void read(long&); void read(ll&); void read(u int&); 
void read(u short&); void read(u long&); void read(u ll&); void read(char&); void read(char*); void read(float&);
void read(double&); void read(long double&); template <typename type> void read(type&);
template <typename type, typename... Args> void read(type&, Args&...); char readch(); char readc(); void readstr(char*);
float readf(); double id1(); long double readlf();


} 




namespace mirai {

constexpr int MAXN = 2.5e5;
constexpr int INF = 0x3f3f3f3f;

int l[MAXN], r[MAXN], p[MAXN], dist[MAXN];
int t[MAXN * 4];
void pushup(int u) {
  t[u] = std::min(t[u * 2], t[u * 2 + 1]);
  return;
}
void build(int u, int l, int r, int* const& a) {
  if (l == r) {
    t[u] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(u * 2, l, mid, a);
  build(u * 2 + 1, mid + 1, r, a);
  pushup(u);
  return;
}
void modify(int u, int l, int r, int const& pos, int const& val) {
  if (pos < l || r < pos) { return; }
  if (l == r) {
    t[u] = val;
    return;
  }
  int mid = (l + r) / 2;
  modify(u * 2, l, mid, pos, val);
  modify(u * 2 + 1, mid + 1, r, pos, val);
  pushup(u);
  return;
}
void modify2(int, int, int, int const&, int const&);
void find(int u, int l, int r, int const& ql, int const& qr, int const& val, std::queue<int>& que, int const& d, int const& n) {
  if (qr < ql || qr < l || r < ql || val < t[u]) { return; }
  if (l == r) {
    t[u] = INF;
    dist[l] = d + 1;
    modify2(1, 1, n, l, -INF);
    que.push(l);
    return;
  }
  int mid = (l + r) / 2;
  find(u * 2, l, mid, ql, qr, val, que, d, n);
  find(u * 2 + 1, mid + 1, r, ql, qr, val, que, d, n);
  pushup(u);
  return;
}

int t2[MAXN * 4];
void id0(int u) {
  t2[u] = std::max(t2[u * 2], t2[u * 2 + 1]);
  return;
}
void build2(int u, int l, int r, int* const& a) {
  if (l == r) {
    t2[u] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build2(u * 2, l, mid, a);
  build2(u * 2 + 1, mid + 1, r, a);
  id0(u);
  return;
}
void modify2(int u, int l, int r, int const& pos, int const& val) {
  if (pos < l || r < pos) { return; }
  if (l == r) {
    t2[u] = val;
    return;
  }
  int mid = (l + r) / 2;
  modify2(u * 2, l, mid, pos, val);
  modify2(u * 2 + 1, mid + 1, r, pos, val);
  id0(u);
  return;
}
void find2(int u, int l, int r, int const& ql, int const& qr, int const& val, std::queue<int> &que, int const& d, int const& n) {
  if (qr < ql || qr < l || r < ql || val > t2[u]) { return; }
  if (l == r) {
    t2[u] = -INF;
    dist[l] = d + 1;
    modify(1, 1, n, l, INF);
    que.push(l);
    return;
  }
  int mid = (l + r) / 2;
  find2(u * 2, l, mid, ql, qr, val, que, d, n);
  find2(u * 2 + 1, mid + 1, r, ql, qr, val, que, d, n);
  id0(u);
  return;
}

int main(int argc, char** argv) {
  int t = scan();
  while (t--) {
    int n, a, b;
    n = scan();
    a = scan();
    b = scan();
    for (int i = 1; i <= n; ++i) {
      p[i] = scan();
      l[i] = std::max(1, i - p[i]);
      r[i] = std::min(n, i + p[i]);
    }
    build(1, 1, n, l);
    build2(1, 1, n, r);
    modify(1, 1, n, a, INF);
    modify2(1, 1, n, a, -INF);
    std::queue<int> que;
    dist[a] = 0;
    que.push(a);
    while (!que.empty()) {
      auto front = que.front();
      que.pop();
      find(1, 1, n, front + 1, r[front], front, que, dist[front], n);
      find2(1, 1, n, l[front], front - 1, front, que, dist[front], n);
    }
    std::printf("%d\n", dist[b]);
  }
  return 0;
}

} 


namespace mirai {


  __cplusplus < 201103L

use MIRAI_FORCE_USE_ARG_LIST if really need.






  __cplusplus < 202002L

use MIRAI_FORCE_ATTR_EXPECT if really need.

































char input_buffer[MIRAI_INPUT_BUFFER_SIZE + 1];
char *id2 = input_buffer;
char *input_buffer_end = input_buffer + MIRAI_INPUT_BUFFER_SIZE;

void flush_input(void) {
  
  std::size_t ret = ::read(0, input_buffer, MIRAI_INPUT_BUFFER_SIZE);
  
  std::size_t ret = std::fread(input_buffer, sizeof(input_buffer[0]), 
    MIRAI_INPUT_BUFFER_SIZE, stdin);
  
  iff(ret < MIRAI_INPUT_BUFFER_SIZE) {
    input_buffer[ret] = '\0';
  }
  id2 = input_buffer;
  return;
}

void flush_input(void) {}





char readchar(void) {
  iff(id2 == input_buffer_end) {
    flush_input();
  }
  return *(id2++);
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
void sread(double& u) { u = id1(); }
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
void read(double& u) { u = id1(); }
void read(long double& u) { u = readlf(); }




template <typename type, typename... Args>
void read(type &u, Args&... args) {
  read(u);
  read(args...);
  return;
}


char readch(void) {
  char ch;
  ch = readchar();
  return ch;
}
char readc(void) {
  char ch;
  ch = readchar();
  whilet(std::isblank(ch)) {
    ch = readchar();
  }
  return ch;
}

void readstr(char* str) {
  *str = readchar();
  whilef(std::isblank(*str)) {
    *str = readchar();
    str++;
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
double id1(void) {
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
      x = x * std::pow(10.F, -1.F * y);
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


int main(int argc, char** argv) {
  
  std::freopen(__FILE__ R"(\..\tests\)" MIRAI_TESTNO ".in", "r", stdin);
  std::freopen(__FILE__ R"(\..\tests\)" MIRAI_TESTNO ".out", "w", stdout);
  
  
  mirai::flush_input();
  
  int ret = mirai::main(argc, argv);
  
  std::fclose(stdin);
  std::fclose(stdout);
  
  return ret;
}