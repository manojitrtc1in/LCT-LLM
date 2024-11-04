
using namespace std;

int io_=[](){ ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

using LL = long long;
using ULL = unsigned long long;
using LD = long double;
using PII = pair<int, int>;
using VI = vector<int>;
using MII = map<int, int>;

template<typename T> void cmin(T &x,const T &y) { if(y<x) x=y; }
template<typename T> void cmax(T &x,const T &y) { if(x<y) x=y; }
template<typename T> bool ckmin(T &x,const T &y) { 
    return y<x ? (x=y, true) : false; }
template<typename T> bool ckmax(T &x,const T &y) { 
    return x<y ? (x=y, true) : false; }
template<typename T> void cmin(T &x,T &y,const T &z) {

    if(z<x) { y=x; x=z; } else if(z<y) y=z; }
template<typename T> void cmax(T &x,T &y,const T &z) {

    if(x<z) { y=x; x=z; } else if(y<z) y=z; }





template<long long Mo=998244353> struct ModInt {
  static long long MO;
  static void setMo(long long mo) { MO = mo; }
  long long x;
  ModInt(long long x=0) : x(x){ norm(); }
  friend istream &operator>>(istream& in, ModInt &B) { in>>B.x; return in; }
  friend ostream &operator<<(ostream& out, const ModInt &B) { 
    out<<B.x; return out; }
  

  void norm() { x = (x%MO + MO) % MO; }
  long long get() { return x; }

  ModInt operator-() const { return ModInt(MO - x); }
  ModInt operator+=(const ModInt &B) { x+=B.x; if(x>=MO) x-=MO; return *this; }
  ModInt operator-=(const ModInt &B) { x-=B.x; if(x<0) x+=MO; return *this; }
  ModInt operator*=(const ModInt &B) { x=x*B.x%MO; return *this; }
  ModInt operator+(const ModInt &B) const { ModInt ans=*this; return ans+=B; }
  ModInt operator-(const ModInt &B) const { ModInt ans=*this; return ans-=B; }
  ModInt operator*(const ModInt &B) const { ModInt ans=*this; return ans*=B; }
  ModInt operator^(long long n) const  {
    ModInt a=*this; ModInt ans(1);
    while(n) { if(n&1) ans*=a; a*=a; n>>=1; }
    return ans;
  }
  ModInt inv() const { return (*this)^(MO-2); } 

  ModInt operator/=(const ModInt &B) { (*this)*=B.inv(); return *this; }
  ModInt operator/(const ModInt &B) const { ModInt ans=*this; return ans/=B; }

  bool operator<(const ModInt &B) const { return x<B.x; }
  bool operator==(const ModInt &B) const { return x==B.x; }
  bool operator!=(const ModInt &B) const { return x!=B.x; }
};
template<long long Mo> long long ModInt<Mo>::MO = Mo;
typedef ModInt<998244353> Mint;

template<typename T> struct PullMax {
  T operator()(const T& l, const T& r) const { return max(l, r); } };
template<typename T> struct PullMin {
  T operator()(const T& l, const T& r) const { return min(l, r); } };
template<typename T> struct EmptyPush { 
  void operator()(T&, T&, T&) const {} };
template<typename TN=int, 
    typename Pull=PullMax<TN>, typename Push=EmptyPush<TN>>
struct SegT {
  static constexpr Pull pull{};
  static constexpr Push push{};
  int aL, aR;
  vector<TN> tn;
  int L, R;

  SegT(int n = 0) : aL(0), aR(n - 1), tn(n << 2) {}
  SegT(int l, int r) : aL(l), aR(r), tn((r - l + 1) << 2) {}
  template<typename T> SegT(const vector<T>& vec) 
      : aL(0), aR(vec.size() - 1), tn(vec.size() << 2) {
    build(1, aL, aR, vec);
  }
  template<typename T> SegT(const vector<T>& vec, int l, int r) 
      : aL(l), aR(r), tn((r - l + 1) << 2) {
    build(1, aL, aR, vec);
  }
  SegT(const function<TN(int)>& gen, int n) 
      : aL(0), aR(n - 1), tn(n << 2) {
    build(1, aL, aR, gen);
  }
  SegT(const function<TN(int)>& gen, int l, int r) 
      : aL(l), aR(r), tn((r - l + 1) << 2) {
    build(1, aL, aR, gen);
  }

  TN query(int l, int r) {
    L = l; R = r;
    return query_(1, aL, aR);
  }
  void update(int l, int r, const function<void(TN&)>& mark) {
    L = l; R = r;
    update_(1, aL, aR, mark);
  }
  pair<TN, bool> query_last_before(
      int r, const function<bool(const TN&)>& pred) {
    R = r;
    return query_last_before(1, aL, aR, pred);
  }
  pair<TN, bool> query_first_after(
      int l, const function<bool(const TN&)>& pred) {
    L = l;
    return query_first_after(1, aL, aR, pred);
  }
  pair<int, bool> query_pos_last_before(
      int r, const function<bool(const TN&)>& pred) {
    R = r;
    return query_pos_last_before(1, aL, aR, pred);
  }
  pair<int, bool> query_pos_first_after(
      int l, const function<bool(const TN&)>& pred) {
    L = l;
    return query_pos_first_after(1, aL, aR, pred);
  }
  void show() { cerr << "SegT\n"; show(1, aL, aR); cerr << endl; }


  template<typename T>
  void build(int o, int l, int r, const vector<T>& vec) {
    if (l == r) { tn[o] = TN(vec[l - aL]); return; }
    int m = (l + r) >> 1;
    build(o << 1, l, m, vec);
    build(o << 1 | 1, m + 1, r, vec);
    tn[o] = pull(tn[o << 1], tn[o << 1 | 1]);
  }
  void build(int o, int l, int r, const function<TN(int)>& gen) {
    if (l == r) { tn[o] = gen(l); return; }
    int m = (l + r) >> 1;
    build(o << 1, l, m, gen);
    build(o << 1 | 1, m + 1, r, gen);
    tn[o] = pull(tn[o << 1], tn[o << 1 | 1]);
  }
  TN query_(int o, int l, int r) {
    if (L <= l && r <= R) { return tn[o]; }
    int m = (l + r) >> 1;
    push(tn[o], tn[o << 1], tn[o << 1 | 1]);
    if (R <= m) { return query_(o << 1, l, m); }
    if (m < L) { return query_(o << 1 | 1, m + 1, r); }
    return pull(query_(o << 1, l, m), query_(o << 1 | 1, m + 1, r));
  }
  void update_(int o, int l, int r, const function<void(TN&)>& mark) {
    if (L <= l && r <= R) {
      mark(tn[o]);
      return;
    }
    int m = (l + r) >> 1;
    push(tn[o], tn[o << 1], tn[o << 1 | 1]);
    if (L <= m) { update_(o << 1, l, m, mark); }
    if (m < R) { update_(o << 1 | 1, m + 1, r, mark); }
    tn[o] = pull(tn[o << 1], tn[o << 1 | 1]);
  }
  pair<TN, bool> query_first_after(
      int o, int l, int r, const function<bool(const TN&)>& pred) {
    if (r < L || !pred(tn[o])) {
      return {tn[o], false};
    }
    if (l == r) {
      return {tn[o], true};
    }
    int mid = (l + r) >> 1;
    push(tn[o], tn[o << 1], tn[o << 1 | 1]);
    pair<TN, bool> ans = query_first_after(o << 1, l, mid, pred);
    if (ans.second) {
      return ans;
    }
    return query_first_after(o << 1 | 1, mid + 1, r, pred);
  }
  pair<TN, bool> query_last_before(
      int o, int l, int r, const function<bool(const TN&)>& pred) {
    if (R < l || !pred(tn[o])) {
      return {tn[o], false};
    }
    if (l == r) {
      return {tn[o], true};
    }
    int mid = (l + r) >> 1;
    push(tn[o], tn[o << 1], tn[o << 1 | 1]);
    pair<TN, bool> ans = query_last_before(o << 1 | 1, mid + 1, r, pred);
    if (ans.second) {
      return ans;
    }
    return query_last_before(o << 1, l, mid, pred);
  }
  pair<int, bool> query_pos_first_after(
      int o, int l, int r, const function<bool(const TN&)>& pred) {
    if (r < L || !pred(tn[o])) {
      return {0, false};
    }
    if (l == r) {
      return {l, true};
    }
    int mid = (l + r) >> 1;
    push(tn[o], tn[o << 1], tn[o << 1 | 1]);
    pair<int, bool> ans = query_pos_first_after(o << 1, l, mid, pred);
    if (ans.second) {
      return ans;
    }
    return query_pos_first_after(o << 1 | 1, mid + 1, r, pred);
  }
  pair<int, bool> query_pos_last_before(
      int o, int l, int r, const function<bool(const TN&)>& pred) {
    if (R < l || !pred(tn[o])) {
      return {0, false};
    }
    if (l == r) {
      return {l, true};
    }
    int mid = (l + r) >> 1;
    push(tn[o], tn[o << 1], tn[o << 1 | 1]);
    pair<int, bool> ans = query_pos_last_before(o << 1 | 1, mid + 1, r, pred);
    if (ans.second) {
      return ans;
    }
    return query_pos_last_before(o << 1, l, mid, pred);
  }
  void show(int o, int l, int r) {
    cerr << o << ' ' << l << ' ' << r << " :\n" << tn[o] << endl;
    if (l == r) return;
    int mid = (l + r) >> 1;
    show(o << 1, l, mid);
    show(o << 1 | 1, mid + 1, r);
  }
};

template<typename Func> struct id0 {
	Func func;
	template<typename T>
	explicit id0(T &&func) : func(std::forward<T>(func)) {}
	template<class ...Args> decltype(auto) operator()(Args &&...args) {
		return func(std::ref(*this), std::forward<Args>(args)...);
	}
};
template<typename Func> decltype(auto) y_comb(Func &&fun) {
	return id0<std::decay_t<Func>>(std::forward<Func>(fun));
}





template<typename T, int M = 2>
struct Mat {
  T a[M][M];
  Mat() { 
    memset(a, 0, sizeof(a));
    for (int i = 0; i < M; i++) { a[i][i] = 1; }
  }
  Mat(int v) { 
    memset(a, 0, sizeof(a));
    for (int i = 0; i < M; i++) { a[i][i] = v; }
  }
  Mat(initializer_list<T> vec) {
    auto it = vec.begin();
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < M; j++) {
        a[i][j] = ((it == vec.end()) ? T(0) : *it++);
      }
    }
  }

  T* operator[](int x) { return a[x]; }
  const T* operator[](int x) const { return a[x]; }

  Mat operator*(const Mat& B) const {
    Mat ans(0);
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < M; j++) {
        for (int k = 0; k < M; k++) {
          ans[i][j] += a[i][k] * B[k][j];
        }
      }
    }
    return ans;
  }
  Mat operator*=(const Mat& B) { return (*this) = (*this) * B; }
  Mat operator+(const Mat& B) const {
    Mat ans;
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < M; j++) {
        ans[i][j] = a[i][j] + B[i][j];
      }
    }
    return ans;
  }
  Mat operator-(const Mat& B) const {
    Mat ans;
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < M; j++) {
        ans[i][j] = a[i][j] + B[i][j];
      }
    }
    return ans;
  }

  friend ostream& operator<<(ostream& os, const Mat& a) {
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < M; j++) {
        os << a[i][j] << (j == M - 1 ? '\n' : '\t');
      }
    }
    return os;
  }
};

const int M = 3e5;

typedef Mat<Mint> TN;
struct Pull {
  TN operator()(const TN&, const TN&) const { 
    return {};
   } };
struct Push { 
  void operator()(TN& o, TN& l, TN& r) const {
    l *= o; 
    r *= o;
    o = TN();
  } };

void solve() {
  int n; cin >> n;
  int l, r;
  int L = -1, R = M + 1;
  SegT<TN, Pull, Push> segt(L, R);
  Mat cover{Mint(1), Mint(2), Mint(1), Mint(2)};
  Mat uncov{Mint(3), Mint(0), Mint(1), Mint(2)};

  

  


  int sl, sr; cin >> sl >> sr;

  

  for (int i = 1; i < n; i++) {
    cin >> l >> r;
    segt.update(L, l - 1, [&](TN& o){
      o *= uncov;
    });
    segt.update(l, r, [&](TN& o){
      o *= cover;
    });
    segt.update(r + 1, R, [&](TN& o){
      o *= uncov;
    });
  }

  Mint ans = 0;
  y_comb([&](auto dfs, int o, int l, int r) -> void {
    if (l == r) {
      ans += segt.tn[o][(sl <= l && l <= sr)][1];
      return;
    }
    int m = (l + r) >> 1;
    segt.push(segt.tn[o], segt.tn[o << 1], segt.tn[o << 1 | 1]);
    dfs(o << 1, l, m);
    dfs(o << 1 | 1, m + 1, r);
  })(1, L, R);
  cout << ans << '\n';
}

int main() {
  int t = 1; 
  

  while (t--) {
    solve();
  }
  return 0;
}
