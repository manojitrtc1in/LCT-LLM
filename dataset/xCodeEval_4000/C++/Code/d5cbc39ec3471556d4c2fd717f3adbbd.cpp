#include <bits/stdc++.h>

const int N = 100010;
const int M = 200010;
const long long mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int m;

int ReadInt() {
  int x = 0, f = 1; 
  char ch = getchar();
  while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
  while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
  return x * f;
}

class SegmentTree {

public:
  SegmentTree() {}

  

  void Init(int n) {
    n_ = n;
  }

  

  void Build(int l, int r, int rt, int v[90][N]) {
    if (l == r) {
      for (int i = 1; i <= m; ++i) { 
        mx_[rt][i] = v[i][l];
      }
      

      return;
    }
    int m = (l + r) >> 1;
    Build(l, m, rt << 1, v);
    Build(m + 1, r, rt << 1 | 1, v);
    Up(rt);
  }

  

  void ChangeSingle(int l, int r, int rt, int id, int num, int x) {
    

    if (l == r) {
      mx_[rt][num] = x;   

      return;
    }
    int m = (l + r) >> 1;
    if (id <= m) {
      ChangeSingle(l, m, rt << 1, id, num, x);
    } else {
      ChangeSingle(m + 1, r, rt << 1 | 1, id, num, x);
    }
    Up(rt);
  }

  

  void MaxInterval(int l, int r, int rt, int L, int R, int* ans) {
    if (L <= l && r <= R) {
      for (int i = 1; i <= m; ++i) {
        ans[i] = std::max(ans[i], mx_[rt][i]);
      }
      return;
    }
    int m = (l + r) >> 1;
    if (L <= m) {
      MaxInterval(l, m, rt << 1, L, R, ans);
    }
    if (R > m) {
      MaxInterval(m + 1, r, rt << 1 | 1, L, R, ans);
    }
    return;
  }

private:
  void Up(int rt) {
    

    for (int i = 1; i <= m; ++i) {
      mx_[rt][i] = std::max(mx_[rt << 1][i], mx_[rt << 1 | 1][i]);
    }
  }

  int n_;
  int mx_[N<<2|1][90];        

}seg; 


class PersistentSegmentTree {

public:
  PersistentSegmentTree() {
    cnt = 0; 
    memset(root, 0, sizeof(root));
  }

  void Init(int n) {
    n_ = n;
    root[0] = ++cnt;
    Build(1, n, root[0]);
  }

  void Copy(int cur, int last) {
    assert(root[last] != 0);
    root[cur] = root[last];
  }

  

  

  void CreateSingle(int cur, int last, int id, long long x) {
    

    assert(root[last] != 0);
    int root_cur = ++cnt;
    CreateSingleImp(1, n_, root_cur, root[last], id, x);
    root[cur] = root_cur;
    

  }

  

  long long QueryProInterval(int L, int R) {
    return ProInterval(1, n_, root[R], L, R);
  }

private:

  

  void Build(int l, int r, int rt) {
    pro[rt] = 1ll;
    if (l == r) {
      return;
    }
    ls[rt] = ++cnt;
    rs[rt] = ++cnt;
    int m = (l + r) >> 1;
    Build(l, m, ls[rt]);
    Build(m + 1, r, rs[rt]);
  }

  

  void CreateSingleImp(int l, int r, int rt, int rt_old, int id, long long x) {
    if (l == r) {
      pro[rt] = x;
      return;
    }
    int m = (l + r) >> 1;
    ls[rt] = ls[rt_old];
    rs[rt] = rs[rt_old];
    if (id <= m) {
      ls[rt] = ++cnt;
      CreateSingleImp(l, m, ls[rt], ls[rt_old], id, x);
    } else {
      rs[rt] = ++cnt;
      CreateSingleImp(m + 1, r, rs[rt], rs[rt_old], id, x);
    }
    pro[rt] = (pro[ls[rt]] * pro[rs[rt]]) % mod;
  }

  

  long long ProInterval(int l, int r, int rt, int L, int R) {
    if (L <= l && r <= R) {
      return pro[rt];
    }
    int m = (l + r) >> 1;
    long long ans = 1ll;
    if (L <= m) {
      ans = (ans * ProInterval(l, m, ls[rt], L, R)) % mod;
    }
    if (R > m) {
      ans = (ans * ProInterval(m + 1, r, rs[rt], L, R)) % mod;
    }
    return ans;
  }

  int n_;
  int cnt;                

  int ls[N * 100];        

  int rs[N * 100];        

  long long pro[N * 100]; 

  int root[N]; 

}pers; 


class Discretization {

public:
  Discretization() {
    vec_.clear();
  }

  void Init() {
    vec_.clear();
  }

  

  void Add(int x) {
    vec_.push_back(x);
  }

  

  void Build() {
    std::sort(vec_.begin(), vec_.end());
    vec_.erase(std::unique(vec_.begin(), vec_.end()), vec_.end());
  }

  

  int Id(int x) {
    auto y = std::lower_bound(vec_.begin(), vec_.end(), x);
    if (y == vec_.end() || *y != x) {
      return -1;
    } else {
      return y - vec_.begin() + 1;
    }
  }

  

  int Val(int id) {
    return vec_[id - 1];
  }

  int Size() {
    return vec_.size();
  }

private:
  std::vector<int> vec_;
}disc;

typedef std::pair<long long, int> PrimeFactor;
#define prime first
#define num second

class Number {

public:
  Number() {
    memset(vis, false, sizeof(vis));
    cnt = 0;
  }

  

  void PrePrime(long long n, std::vector<int>& _prime) {
    _prime.clear();
    for (long long i = 2ll; i <= n; ++i) {
      if (!vis[i]) {
        prime[cnt++] = i;
        _prime.push_back(i);
        for (long long j = i + i; j <= n; j += i) {
          vis[j] = true;
        }
      }
    }
    
  }

  

  void FactorPrime(long long n, std::vector<PrimeFactor>& vec) {
    long long sn = sqrt(n);
    vec.clear();
    for (int i = 0; i < cnt && prime[i] <= sn; ++i) {
      if (n % prime[i] == 0) {
        PrimeFactor p(prime[i], 0);
        disc.Add(prime[i]);
        while (n % prime[i] == 0) {
          ++p.num;
          n /= prime[i];
        }
        vec.emplace_back(p);
        


        if (n == 1ll) {
          break;
        }
      }
    }

    if (n != 1) {
      vec.emplace_back(PrimeFactor(n, 1));
      

    }
    

  }

private:
  bool vis[M];        

  long long prime[M]; 

  int cnt;            


}number; 


long long Pow(long long a, long long b) {
  long long ans = 1ll;
  for (long long tmp = a; b;) {
    if (b & 1) {
      ans = (ans * tmp) % mod;
    }
    tmp = (tmp * tmp) % mod;
    b >>= 1ll;
  }
  return ans;
}

struct FunTime {
  std::string topic;
  double run_time;
  
  FunTime() {}
  FunTime(std::string a, double b) : topic(a), run_time(b) {}
};

class Timer {
 public:
  Timer () {
    each_.clear();
    sum_ = 0.0;
  }
  ~Timer() { }
  void Init() {
    each_.clear();
    sum_ = 0.0;
  }
  void Begin() {
    beg_ = std::chrono::system_clock::now();
    

  }
  void End(const std::string& s) {
    end_ = std::chrono::system_clock::now();
    std::chrono::duration<double> tim = end_ - beg_;
    each_[s] += tim.count() * 1000;
    sum_ += tim.count() * 1000;

    

    

    

    

    

  }
  void PrintStatistics(const std::string& s) {
    std::cout << s << " Time Statistics ======================\n";
    std::cout << "Sum Run Time: " << sum_ <<  "ms\n";
    fun_times_.clear();
    for (auto x : each_) {
      fun_times_.push_back(FunTime(x.first, x.second));
    }
    sort(fun_times_.begin(), fun_times_.end(), [](FunTime x, FunTime y){return x.run_time > y.run_time;});
    for (size_t i = 0; i < fun_times_.size(); ++i) {
      double percentage = fun_times_[i].run_time / sum_;
      std::cout << fun_times_[i].topic << ": " << fun_times_[i].run_time << "ms " << percentage * 100.0 << "\%" << std::endl;
    }
  }
  double SumTime() {
    return sum_;
  }
 private:
  std::chrono::time_point<std::chrono::system_clock> beg_;
  std::chrono::time_point<std::chrono::system_clock> end_;
  

  

  std::map<std::string, double> each_;
  std::vector<FunTime> fun_times_;
  double sum_; 
}timer; 


int n, q;
long long a[N];
int b[90][N];
std::vector<PrimeFactor> fac_pri[N]; 

std::vector<int> pri; 

int last_id[M];






int main() {































  

  timer.Begin();
  scanf("%d", &n);

  

  disc.Init();
  number.PrePrime(448ll, pri); 

  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    number.FactorPrime(a[i], fac_pri[i]);
  }
  disc.Build();
  m = disc.Size();
  assert(m < 90);
  for (int i = 1; i <= n; ++i) {
    for (size_t j = 0; j < fac_pri[i].size(); ++j) {
      long long pri = fac_pri[i][j].prime;
      int num = fac_pri[i][j].num;
      int id = disc.Id(pri);
      

      if (id != -1) {
        b[id][i] = num;
        

        

      }
    }
  }
  seg.Init(n);
  seg.Build(1, n, 1, b);
  timer.End("Segment Preparation");

  timer.Begin();
  

  pers.Init(n);
  memset(last_id, 0, sizeof(last_id));
  for (int i = 1; i <= n; ++i) {
    if (!fac_pri[i].size()) {
      pers.Copy(i, i - 1);
    } else {
      long long pri = fac_pri[i].back().prime;
      int id = disc.Id(pri);
      if (id == -1) {
        if (!last_id[pri]) {
          pers.CreateSingle(i, i - 1, i, pri);
        } else {
          

          pers.CreateSingle(i, i - 1, last_id[pri], 1ll);
          pers.CreateSingle(i, i, i, pri);
        }
        last_id[pri] = i;
      } else {
        pers.Copy(i, i - 1);
      }
    }
  }
  timer.End("Persistent Segment Tree Preparation");

  timer.Begin();
  scanf("%d", &q);
  int last = 0;
  for (int i = 1; i <= q; ++i) {
    int x = ReadInt();
    int y = ReadInt();
    x = (last + x) % n + 1;
    y = (last + y) % n + 1;
    if (x > y) {
      std::swap(x, y);
    }
    long long ans = 1ll;
    

    int num[90];
    for (int j = 1; j <= m; ++j) {
      num[j] = 0;
    }
    seg.MaxInterval(1, n, 1, x, y, num);
    for (int j = 1; j <= m; ++j) {
      ans = (ans * Pow(disc.Val(j), num[j])) % mod;
    }
    


    

    ans = (ans * pers.QueryProInterval(x, y)) % mod;
    printf("%lld\n", ans);
    last = ans % n;
  }
  timer.End("Query");

  



  return 0;
}