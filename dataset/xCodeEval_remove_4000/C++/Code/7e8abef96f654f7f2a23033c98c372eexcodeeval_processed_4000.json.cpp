

















inline char gc() {
  static const int L = 233333;
  static char sxd[L], *sss = sxd, *ttt = sxd;
  if (sss == ttt) {
    ttt = (sss = sxd) + fread(sxd, 1, L, stdin);
    if (sss == ttt) {
      return EOF;
    }
  }
  return *sss++;
}






template <class T>
inline bool read(T& x) {
  x = 0;
  char dd;
  bool flg = false;
  for (; !isdigit(c); dd) {
    if (c == '-') {
      flg = true;
    } else if (c == EOF) {
      return false;
    }
  }
  for (; isdigit(c); dd) {
    x = (x * 10) + (c ^ 48);
  }
  if (flg) {
    x = -x;
  }
  return true;
}


template <class T>
inline void write(T x) {
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (x > 9) {
    write(x / 10);
    x %= 10;
  }
  putchar(x | 48);
}

template <class T>
inline void writeln(T x) {
  write(x);
  puts("");
}

template <class T>
inline void id0(T x) {
  write(x);
  putchar(' ');
}


typedef long long LL;

int n;

LL ask(int x, int y) {
  assert(1 <= x && x <= n && 1 <= y && y <= n);
  std::cout << "? " << x << ' ' << y << std::endl;
  std::cout.flush();
  LL ans;
  std::cin >> ans;
  return ans;
}

namespace solve_small {
  const int maxn = 105;

  LL lcm[maxn][maxn];

  void solve() {
    memset(lcm, 0, sizeof(lcm));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        lcm[i][j] = lcm[j][i] = ask(i, j);
      }
    }
    std::pair<int, int> idans(0, 0);
    if (n == 3) {
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
          if (lcm[i][j] > lcm[idans.first][idans.second]) {
            idans = std::make_pair(i, j);
          }
        }
      }
      std::vector<int> ANS(4);
      ANS[idans.first] = sqrt(lcm[idans.first][idans.second]);
      ANS[idans.second] = ANS[idans.first] + 1;
      ANS[6 - idans.first - idans.second] = ANS[idans.first] - 1;
      if ((LL) ANS[idans.first] * ANS[6 - idans.first - idans.second]
               / std::__gcd(ANS[idans.first], ANS[6 - idans.first - idans.second])
          != lcm[idans.first][6 - idans.first - idans.second]) {
        std::swap(ANS[idans.first], ANS[idans.second]);
      }
      std::cout << "! ";
      for (int i = 1; i <= 3; ++i) {
        std::cout << ANS[i] << ' ';
      }
      std::cout << std::endl;
      std::cout.flush();
    } else {
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          lcm[i][i] = std::__gcd(lcm[i][i], lcm[i][j]);
        }
      }
      std::cout << "! ";
      for (int i = 1; i <= n; ++i) {
        std::cout << lcm[i][i] << ' ';
      }
      std::cout << std::endl;
      std::cout.flush();
    }
  }
}

namespace solve_large {
  struct debug {
    int n;
    std::vector<int> alb;

    LL ask(int x, int y) {
      return (LL) alb[x - 1] * alb[y - 1] / std::__gcd(alb[x - 1], alb[y - 1]);
    }

    debug() {
      std::ifstream fin("a.in");
      fin >> n;
      for (int i = 1; i <= n; ++i) {
        int xx;
        fin >> xx;
        alb.push_back(xx);
      }
    }
  } deb;

  
  
  

  const int maxn = 200005;
  
  LL ans[maxn];
  int np[maxn];

  std::mt19937 rnd(20030211u);

  void Euler(const int n = 200000) {
    std::vector<int> prime;
    prime.clear();
    for (int i = 2; i <= n; ++i) {
      if (!np[i]) {
        prime.push_back(i);
      }
      for (unsigned j = 0; j < prime.size() && (LL) i * prime[j] <= n; ++j) {
        np[i * prime[j]] = true;
        if (!(i % prime[j])) {
          break;
        }
      }
    }
    

    

    

    

  }

  void solve() {
    std::vector<int> id;
    id.clear();
    for (int i = 1; i <= n; ++i) {
      ans[i] = 0;
      id.push_back(i);
    }
    std::shuffle(id.begin(), id.end(), rnd);
    int qd = 0;
    

    

    

    

    

    

    for (int i = 1; i <= 249 && i <= n; ++i) {
      

      qd = id[i - 1];
      for (int j = 1; j <= 20; ++j) {
        

        

        int wz = rnd() % n + 1;
        while (wz == qd) {
          wz = rnd() % n + 1;
        }
        ans[qd] = std::__gcd(ask(qd, wz), ans[qd]);
        

        if (ans[qd] <= 200000 && ans[qd] && !np[ans[qd]]) {
          break;
        }
      }
      

      

      

      

      if (ans[qd] && !np[ans[qd]] && ((ans[qd] << 1) > n)) {
        break;
      }
    }
    

    

    

    

    

    

    

    

    

    

    assert(ans[qd] <= 200000 && ans[qd] && !np[ans[qd]] && ((ans[qd] << 1) > n));
    for (int i = 1; i <= n; ++i) {
      if (!ans[i]) {
        ans[i] = ask(i, qd) / ans[qd];
      }
    }
    LL mx = 0;
    int idd = 0;
    for (int i = 1; i <= n; ++i) {
      if (!np[ans[i]] && ans[i] >= mx) {
        mx = ans[i];
        idd = i;
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (ans[i] == 2) {
        

        ans[i] = ask(i, idd) / mx;
      }
    }
    

      

      

    

    

    

    

    

    

    

    

    

    

    

    

    

    
    std::cout << "! ";
    
    for (int i = 1; i <= n; ++i) {
      std::cout << ans[i] << ' ';
    }
    std::cout << std::endl;
    std::cout.flush();
  }

  
  
  
}

void solve() {
  
  std::cin >> n;
  
  n = solve_large::deb.n;
  freopen("a.out", "w", stdout);
  std::cout << n << std::endl;
  
  if (n <= 100) {
    solve_small::solve();
  } else {
    solve_large::solve();
  }
}

int main() {
  

  

  

  solve_large::Euler();
  int T;
  
  std::cin >> T;
  
  T = 1;
  
  while (T--) {
    solve();
  }
  return 0;
}

