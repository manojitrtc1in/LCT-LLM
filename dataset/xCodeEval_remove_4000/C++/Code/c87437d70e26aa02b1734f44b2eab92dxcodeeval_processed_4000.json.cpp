






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


int main() {
  
  std::freopen(__FILE__ "\\..\\tests\\" MIRAI_TESTNO ".in", "r", stdin);
  std::freopen(__FILE__ "\\..\\tests\\" MIRAI_TESTNO ".out", "w", stdout);
  
  
  mirai::flush_input();
  
  int ret = mirai::main();
  
  std::fclose(stdin);
  std::fclose(stdout);
  
  return ret;
}


	   	 	   	  		  	 	 	  		  			