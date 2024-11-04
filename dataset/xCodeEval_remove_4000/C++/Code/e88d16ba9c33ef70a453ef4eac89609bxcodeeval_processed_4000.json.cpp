






































using namespace std;





using namespace tr1;









using namespace __gnu_pbds;


typedef __gnu_pbds::priority_queue<int, greater<int>, pairing_heap_tag> pq_type;


typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    tree_type;



typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef map<string, int> mpsi;
typedef map<double, int> mpdi;
typedef map<int, int> mpii;

const double pi = acos(0.0) * 2.0;
const long double eps = 1e-10;
const int step[8][2] = {{-1, 0}, {0, 1}, {1, 0},  {0, -1},
                        {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};

template <class T>
inline T abs1(T a) {
  return a < 0 ? -a : a;
}


template <class T>
inline T max1(T a, T b) {
  return b < a ? a : b;
}
template <class T>
inline T max1(T a, T b, T c) {
  return max1(max1(a, b), c);
}
template <class T>
inline T max1(T a, T b, T c, T d) {
  return max1(max1(a, b, c), d);
}
template <class T>
inline T max1(T a, T b, T c, T d, T e) {
  return max1(max1(a, b, c, d), e);
}
template <class T>
inline T min1(T a, T b) {
  return a < b ? a : b;
}
template <class T>
inline T min1(T a, T b, T c) {
  return min1(min1(a, b), c);
}
template <class T>
inline T min1(T a, T b, T c, T d) {
  return min1(min1(a, b, c), d);
}
template <class T>
inline T min1(T a, T b, T c, T d, T e) {
  return min1(min1(a, b, c, d), e);
}

template <typename t, typename t1>
t min1(t a, t1 b) {
  return a < b ? a : b;
}
template <typename t, typename... arg>
t min1(t a, arg... arr) {
  return min1(a, min1(arr...));
}
template <typename t, typename t1>
t max1(t a, t1 b) {
  return a > b ? a : b;
}
template <typename t, typename... arg>
t max1(t a, arg... arr) {
  return max1(a, max1(arr...));
}


inline int jud(double a, double b) {
  if (abs(a) < eps && abs(b) < eps)
    return 0;
  else if (abs1(a - b) / max(abs1(a), abs1(b)) < eps)
    return 0;
  if (a < b) return -1;
  return 1;
}
template <typename t>
inline int jud(t a, t b) {
  if (a < b) return -1;
  if (a == b) return 0;
  return 1;
}

template <typename it, typename t1>
inline int find(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1) {
  if (na == 0) return 0;
  int be = 0, en = na - 1;
  if (*a <= *(a + na - 1)) {
    if (f_lb == 0)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != 1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != -1)
          en = mid;
        else
          be = mid + 1;
      }
    if (f_small && jud(*(a + be), val) == 1) be--;
    if (!f_small && jud(*(a + be), val) == -1) be++;
  } else {
    if (f_lb)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != -1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != 1)
          en = mid;
        else
          be = mid + 1;
      }
    if (!f_small && jud(*(a + be), val) == -1) be--;
    if (f_small && jud(*(a + be), val) == 1) be++;
  }
  return be;
}

template <class T>
inline T lowb(T num) {
  return num & (-num);
}

inline int bitnum(ui nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(ull nValue) {
  return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32);
}
inline int bitnum(ll nValue) {
  return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32);
}
inline int id0(ui a) {
  if (a == 0) return 0;
  return 32 - __builtin_clz(a);
}
inline int id0(int a) {
  if (a == 0) return 0;
  return 32 - __builtin_clz(a);
}
inline int id0(ull a) {
  int temp = a >> 32;
  if (temp) return 32 - __builtin_clz(temp) + 32;
  return id0(int(a));
}
inline int id0(ll a) {
  int temp = a >> 32;
  if (temp) return 32 - __builtin_clz(temp) + 32;
  return id0(int(a));
}



long long pow(long long n, long long m, long long mod = 0) {
  if (m < 0) return 0;
  long long ans = 1;
  long long k = n;
  while (m) {
    if (m & 1) {
      ans *= k;
      if (mod) ans %= mod;
    }
    k *= k;
    if (mod) k %= mod;
    m >>= 1;
  }
  return ans;
}


template <class t1, class t2>
inline void add(t1 &a, t2 b, int mod = -1) {
  if (mod == -1) mod = MOD;
  a += b;
  while (a >= mod) a -= mod;
  while (a < 0) a += mod;
}
template <class t>
void output1(t arr) {
  for (int i = 0; i < (int)arr.size(); i++) cerr << arr[i] << ' ';
  cerr << endl;
}
template <class t>
void output2(t arr) {
  for (int i = 0; i < (int)arr.size(); i++) output1(arr[i]);
}




const int maxn = 22;
int ncase;
int n, m;
char mp[maxn][maxn];

class Matroid {
 public:
  using UI = unordered_set<int>;
  Matroid(int n) : n_(n) {}
  virtual unordered_map<int, vi> GetAllCanExchange(
      UI* current_set, bool rev_edge) {
    unordered_map<int, vi> ans;
    for (int i = 0; i < n_; i++) {
      if (current_set->find(i) == current_set->end()) {
        current_set->insert(i);
        for (const auto it : *current_set) if (it != i) {
          current_set->erase(i);
          if (Oracle(current_set)) {
            if (rev_edge) ans[i].push_back(it);
            else ans[it].push_back(i);
          }
          current_set->insert(i);
        }
      }
    }
    return ans;
  }
  virtual UI GetAllCanExtend(UI* current_set) {
    UI ans;
    for (int i = 0; i < n_; i++) {
      if (current_set->find(i) == current_set->end()) {
        current_set->insert(i);
        if (Oracle(current_set)) {
          ans.insert(i);
        }
        current_set->erase(i);
      }
    }
    return ans;
  }
  virtual bool Oracle(UI* ui) = 0;

 protected:
  int n_;
};

class id5 {
 public:
  using UI = unordered_set<int>;
  id5(int n, Matroid* a, Matroid* b) :
      n_(n), weight_(vi{}), a_(a), b_(b),
      Augment(&id5::AugmentNormal) {}
  id5(const vi& weight, Matroid* a, Matroid* b) :
      n_(weight.size()), weight_(weight), a_(a), b_(b),
      Augment(&id5::AugmentWeighted) {}

  UI GetMaxIntersection() {
    UI ans;
    while ((this->*Augment)(&ans));
    return ans;
  }

 private:
  bool AugmentNormal(UI* current_set) {
    UI y1 = a_->GetAllCanExtend(current_set);
    UI y2 = b_->GetAllCanExtend(current_set);
    for (int i = 0; i < n_; i++) {
      if (current_set->find(i) == current_set->end() &&
          y1.find(i) != y1.end() && y2.find(i) != y2.end()) {
        current_set->insert(i);
        return true;
      }
    }
    auto e1 = a_->GetAllCanExchange(current_set, false);
    auto e2 = b_->GetAllCanExchange(current_set, true);
    vi q;
    q.reserve(n_);
    vi dis(n_, n_ + 1), fa(n_, -1);
    for (const auto it : y1) {
      dis[it] = 0;
      q.push_back(it);
    }
    for (int i = 0; i < (int)q.size(); i++) {
      int no = q[i];
      if (y2.find(no) != y2.end()) {
        for (int i = 0; no != -1; i = i ^ 1) {
          if (i) {
            current_set->erase(no);
          } else {
            current_set->insert(no);
          }
          no = fa[no];
        }
        return true;
      }
      const auto& re = dis[no] % 2 ? e1 : e2;
      auto it = re.find(no);
      if (it == re.end()) continue;
      for (const auto to : it->second) {
        if (dis[to] > dis[no] + 1) {
          dis[to] = dis[no] + 1;
          fa[to] = no;
          q.push_back(to);
        }
      }
    }

    return false;
  }
  bool AugmentWeighted(UI* current_set) {
    

    

    return false;
  }
  int n_;
  vi weight_;
  Matroid* a_;
  Matroid* b_;
  bool (id5::*Augment)(UI*);
};

class id4 : public Matroid {
 public:
  id4(int n, const vector<pii>& e) :
      Matroid(e.size()), e_(e), np_(n) {
    graph_ = vector<vi>(np_, vi{});
    for (const auto& it : e) {
      graph_[it.first].push_back(it.second);
      graph_[it.second].push_back(it.first);
    }
    for (int i = 0; i < (int)e_.size(); i++) {
      e_no_[HashE(e_[i].first, e_[i].second)] = i;
      e_no_[HashE(e_[i].second, e_[i].first)] = i;
    }
  }
  

  

  

  

  

  

  

  

  

  

  

  

  

  

  UI GetAllCanExtend(UI* current_set) override {
    vi fa = BuildDsu(current_set);
    assert(!fa.empty());
    UI ans;
    for (int i = 0; i < n_; i++) {
      if (current_set->find(i) == current_set->end()) {
        int a = e_[i].first, b = e_[i].second;
        if (GetFa(a, fa) != GetFa(b, fa)) {
          ans.insert(i);
        }
      }
    }
    return ans;
  }
  unordered_map<int, vi> GetAllCanExchange(
      UI* current_set, bool rev_edge) override {
  	vi fa(np_, -1), rfa(np_, -2), comp(np_, -1);
  	vi lca(n_, -1);
  	int current_comp = 0;
  	function<void(int)> dfs = [&](int no) {
  		comp[no] = current_comp;
  		for (const auto it : graph_[no]) if (it != fa[no]) {
  			int eno = GetEno(no, it);
  			if (current_set->find(eno) != current_set->end()) {
  				assert(fa[it] == -1);
  				lca[eno] = -2;
  				fa[it] = no;
  				rfa[it] = -1;
  				dfs(it);
  				rfa[it] = no;
  			} else {
  				if (rfa[it] != -2 && comp[it] == current_comp) {
  					lca[eno] = GetFa(it, rfa);
  				}
  			}
  		}
  	};
  	for (int i = 0; i < np_; i++) if (comp[i] == -1) {
  		rfa[i] = -1;
  		dfs(i);
  		current_comp++;
  	}

  	unordered_map<int, vi> ans;
		for (int i = 0; i < n_; i++) if (lca[i] != -2) {
			if (lca[i] == -1) {
				if (rev_edge) {
					auto& exchange = ans[i];
					for (const auto it : *current_set) {
						exchange.push_back(it);
					}
				} else {
					for (const auto it : *current_set) {
						ans[it].push_back(i);
					}
				}
			} else {
				vi rcur;
				for (int j = e_[i].first; j != lca[i]; j = fa[j]) {
					rcur.push_back(GetEno(fa[j], j));
				}
				for (int j = e_[i].second; j != lca[i]; j = fa[j]) {
					rcur.push_back(GetEno(fa[j], j));
				}
				if (rev_edge) {
					auto& exchange = ans[i];
					for (const auto it : rcur) {
						exchange.push_back(it);
					}
				} else {
					for (const auto it : rcur) {
						ans[it].push_back(i);
					}
				}
			}
		}



		return ans;
  }






























































































































  bool Oracle(UI* ui) override {
    return !BuildDsu(ui).empty();
  }

 private:
  void Debug(const unordered_set<int>* current_set) {
    puts("");
    char ans[maxn * 2][maxn * 2];
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n * 2 - 1; i++) for (int j = 0; j < m * 2 - 1; j++) {
      ans[i][j] = ' ';
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      ans[i * 2][j * 2] = mp[i][j];
    }
    for (const auto it : *current_set) {
      int p1 = e_[it].first, p2 = e_[it].second;
      int x1 = p1 / m, y1 = p1 % m, x2 = p2 / m, y2 = p2 % m;
      ans[(x1 * 2 + x2 * 2) / 2][(y1 * 2 + y2 * 2) / 2] = 'O';
    }
    for (int i = 0; i < n * 2 - 1; i++) {
      puts(ans[i]);
    }
    fflush(stdout);
  }

  vi BuildDsu(UI* current_set) {
    vi fa(np_, -1);

    function<bool(int, int)> uni = [&](int a, int b) {
      a = GetFa(a, fa);
      b = GetFa(b, fa);
      if (a == b) return false;
      fa[a] = b;
      return true;
    };

    for (const auto no : *current_set) {
      int a = e_[no].first, b = e_[no].second;
      if (!uni(a, b)) {
        return {};
      }
    }

    return fa;
  }
  int GetFa(int no, vi& fa) {
    if (fa[no] == -1) return no;
    return fa[no] = GetFa(fa[no], fa);
  }
  inline int GetEno(int a, int b) {
    return e_no_[HashE(a, b)];
  }
  inline ll HashE(int a, int b) {
    return 1ll * a * np_ + b;
  }

  const vector<pii>& e_;
  int np_;
  vector<vi> graph_;
  unordered_map<ll, int> e_no_;
};

class id2 : public Matroid {
 public:
  id2(int n, const vector<pii>& e, const UI& need_check) :
      Matroid(e.size()), e_(e), need_check_(need_check), np_(n) {}

  UI GetAllCanExtend(UI* current_set) override {
    vi deg = BuildDeg(current_set);
    UI ans;
    for (int i = 0; i < n_; i++) {
      if (current_set->find(i) == current_set->end() &&
          OK(e_[i].first, deg) && OK(e_[i].second, deg)) {
        ans.insert(i);
      }
    }

    return ans;
  }

  unordered_map<int, vi> GetAllCanExchange(
      UI* current_set, bool rev_edge) override {
    vi deg = BuildDeg(current_set);
    unordered_map<int, vi> ans;
    for (const auto it : *current_set) {
      deg[e_[it].first]--;
      deg[e_[it].second]--;
      for (int i = 0; i < n_; i++) {
        if (current_set->find(i) == current_set->end() &&
            OK(e_[i].first, deg) && OK(e_[i].second, deg)) {
          if (rev_edge) ans[i].push_back(it);
          else ans[it].push_back(i);
        }
      }
      deg[e_[it].first]++;
      deg[e_[it].second]++;
    }
    return ans;
  }

  bool Oracle(UI* current_set) override {
    return false;
  }

 private:
  vi BuildDeg(UI* current_set) {
    vi deg(np_, 0);
    for (const auto& it : *current_set) {
      deg[e_[it].first]++;
      deg[e_[it].second]++;
    }

    return deg;
  }
  bool OK(int no, const vi& deg) {
    if (need_check_.find(no) == need_check_.end() ||
        deg[no] < 2) {
      return true;
    }
    return false;
  }
  const vector<pii>& e_;
  const UI& need_check_;
  int np_;
};




bool In(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m && mp[x][y] != 'X';
}
int Pno(int a, int b) {
  return a * m + b;
}

int main() {
  ios_base::sync_with_stdio(0);


  freopen("input.txt", "r", stdin);



  scanf("%d", &ncase);
  for (int i1 = 0; i1 < ncase; i1++) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%s", mp[i]);
    }
    vector<pii> e;
    unordered_set<int> id3;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (In(i, j) && (i + j)) {
      if ((i + j) % 2 == 0) id3.insert(Pno(i, j));
      if (In(i + 1, j)) {
        e.push_back(mpr(Pno(i, j), Pno(i + 1, j)));
      }
      if (In(i, j + 1)) {
        e.push_back(mpr(Pno(i, j), Pno(i, j + 1)));
      }
    }
    id2 mm(n * m, e, id3);
    id4 am(n * m, e);
    id5 mi(e.size(), &mm, &am);
    unordered_set<int> s = mi.GetMaxIntersection();
    int deg[maxn][maxn];
    char ans[maxn * 2][maxn * 2];
    memset(deg, 0, sizeof(deg));
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n * 2 - 1; i++) for (int j = 0; j < m * 2 - 1; j++) {
      ans[i][j] = ' ';
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      ans[i * 2][j * 2] = mp[i][j];
    }
    vi fa(n * m, -1);
    function<int(int, vi&)> id1 = [&](int no, vi& fa) {
      if (fa[no] == -1) return no;
      return fa[no] = id1(fa[no], fa);
    };
    function<bool(int, int)> uni = [&](int a, int b) {
      a = id1(a, fa);
      b = id1(b, fa);
      if (a == b) return false;
      fa[a] = b;
      return true;
    };
    for (const auto it : s) {
      int p1 = e[it].first, p2 = e[it].second;
      int x1 = p1 / m, y1 = p1 % m, x2 = p2 / m, y2 = p2 % m;
      uni(p1, p2);
      ans[(x1 * 2 + x2 * 2) / 2][(y1 * 2 + y2 * 2) / 2] = 'O';
      deg[x1][y1]++;
      deg[x2][y2]++;
    }
    bool flag = 1;
    for (int i = 0; i < n && flag; i++) for (int j = 0; j < m && flag; j++) {
      if (In(i, j)) {
        if ((i + j) % 2 == 0 && (i != 0 || j != 0) && deg[i][j] < 2) {
          flag = 0;
          puts("NO");
          break;
        }
        if (In(i, j + 1) && uni(Pno(i, j), Pno(i, j + 1))) {
          ans[i * 2][j * 2 + 1] = 'O';
        }
        if (In(i + 1, j) && uni(Pno(i, j), Pno(i + 1, j))) {
          ans[i * 2 + 1][j * 2] = 'O';
        }
      }
    }
    if (flag) {
      puts("YES");
      for (int i = 0; i < n * 2 - 1; i++) {
        puts(ans[i]);
      }
    }
  }

  return 0;
}
