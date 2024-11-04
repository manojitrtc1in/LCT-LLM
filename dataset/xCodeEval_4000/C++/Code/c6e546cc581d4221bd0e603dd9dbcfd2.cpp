








#include <bits/stdc++.h>
using namespace std;

string to_string(char c) {
	return string(1, c);
}
string to_string(string s) {
	return s;
}
string to_string(const char* s) {
	return string(s);
}
string to_string(bool b) {
  return (b ? "true" : "false");
}
string to_string(vector<bool> v) {
	string res;
	for(int i = 0; i < (int)v.size(); i++)
		res+=char('0'+v[i]);
	return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #VA_ARGS << "]:", debug_out(VA_ARGS)
#else
#define debug(...) 42
#endif

#define FOR(i,a,b)      for (int i = (a); i < (b); ++i)
#define F0R(i,a)        FOR(i,0,a)
#define ROF(i,a,b)      for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a)        ROF(i,0,a)
#define rep(a)          F0R(_,a)
#define IOS             ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define dbg(x)          cout << #x << "=" << x << endl
#define dbg2(x, y)      cout << #x << "=" << x << "," << #y << "=" << y << endl
#define dbg3(x, y,z)    cout << #x << "=" << x << "," << #y << "=" << y <<"," << #z << "=" << z << endl
#define ff              first
#define ss              second
#define all(x)          (x).begin(), (x).end()
#define pb              push_back
#define mp              make_pair
#define sz(x)           (int)(x).size()
#define lb              lower_bound
#define ub              upper_bound 
#define endl            "\n"
#define mem0(a)         memset(a,0,sizeof(a))
#define mem1(a)         memset(a,-1,sizeof(a))
#define memf(a)         memset(a,false,sizeof(a))
#define memt(a)         memset(a,true,sizeof(a))
#define meminf(a)       memset(a,0x7f,sizeof(a))
#define nO              {cout<<"NO\n"; return;}
#define yES             {cout<<"YES\n"; return;}
#define neg             {cout<<"-1\n"; return;}
#define each(a,x)       for (auto& a: x)
#define ar              array
mt19937_64 				      rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define int             long long

template<typename T> using V = vector<T>;
template<typename T> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } 

template<typename T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

 
using ll = long long;
using db = long double;
using vd = vector<db>; 
using vs = vector<string>;
using pi = pair<int,int>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vpi = vector<pi>;

template<class A> void read(V<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
	cin >> x;
}
void read(double& d) {
	string t;
	read(t);
	d=stod(t);
}
void read(long double& d) {
	string t;
	read(t);
	d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
template<class A> void read(V<A>& x) {
	each(a, x)
		read(a);
}
template<class A, size_t S> void read(ar<A, S>& x) {
	each(a, x)
		read(a);
}

const int mod = 998244353;
const ll INF = 1e18;
const db PI = acos((db)-1);



constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr int bits(int x) { 

	return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }

namespace fft {
  struct cmpl {
    double x, y;
    cmpl() {
      x = y = 0;
    }
    cmpl(double x, double y) : x(x), y(y) {}
    inline cmpl conjugated() const {
      return cmpl(x, -y);
    }
  };
  inline cmpl operator+(cmpl a, cmpl b) {
    return cmpl(a.x + b.x, a.y + b.y);
  }
  inline cmpl operator-(cmpl a, cmpl b) {
    return cmpl(a.x - b.x, a.y - b.y);
  }
  inline cmpl operator*(cmpl a, cmpl b) {
    return cmpl(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
  }

  int base = 1; 

  vector<cmpl> roots = {{0, 0}, {1, 0}}; 

  vector<int> rev = {0, 1}; 

  const double PI = static_cast<double>(acosl(-1.0));

  void ensure_base(int nbase) { 

    if (nbase <= base) {
      return;
    }
    rev.resize(1 << nbase);
    for (int i = 1; i < (1 << nbase); i++) {
      rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    roots.resize(1 << nbase);
    while (base < nbase) {
      double angle = 2 * PI / (1 << (base + 1));
      for (int i = 1 << (base - 1); i < (1 << base); i++) {
        roots[i << 1] = roots[i];
        double angle_i = angle * (2 * i + 1 - (1 << base));
        roots[(i << 1) + 1] = cmpl(cos(angle_i), sin(angle_i));
      }
      base++;
    }
  }

  void fft(vector<cmpl>& a, int n = -1) {
    if (n == -1) {
      n = (int) a.size();
    }
    assert((n & (n - 1)) == 0); 

    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for (int i = 0; i < n; i++) {
      if (i < (rev[i] >> shift)) {
        swap(a[i], a[rev[i] >> shift]);
      }
    }
    for (int k = 1; k < n; k <<= 1) {
      for (int i = 0; i < n; i += 2 * k) {
        for (int j = 0; j < k; j++) {
          cmpl z = a[i + j + k] * roots[j + k];
          a[i + j + k] = a[i + j] - z;
          a[i + j] = a[i + j] + z;
        }
      }
    }
  }

  vector<cmpl> fa, fb;

  vector<long long> square(const vector<int>& a) {
    if (a.empty()) {
      return {};
    }
    int need = (int) a.size() + (int) a.size() - 1;
    int nbase = 1;
    while ((1 << nbase) < need) {
      nbase++;
    }
    ensure_base(nbase);
    int sz = 1 << nbase;
    if ((sz >> 1) > (int) fa.size()) {
      fa.resize(sz >> 1);
    }
    for (int i = 0; i < (sz >> 1); i++) {
      int x = (2 * i < (int) a.size() ? a[2 * i] : 0);
      int y = (2 * i + 1 < (int) a.size() ? a[2 * i + 1] : 0);
      fa[i] = cmpl(x, y);
    }
    fft(fa, sz >> 1);
    cmpl r(1.0 / (sz >> 1), 0.0);
    for (int i = 0; i <= (sz >> 2); i++) {
      int j = ((sz >> 1) - i) & ((sz >> 1) - 1);
      cmpl fe = (fa[i] + fa[j].conjugated()) * cmpl(0.5, 0);
      cmpl fo = (fa[i] - fa[j].conjugated()) * cmpl(0, -0.5);
      cmpl aux = fe * fe + fo * fo * roots[(sz >> 1) + i] * roots[(sz >> 1) + i];
      cmpl tmp = fe * fo;
      fa[i] = r * (aux.conjugated() + cmpl(0, 2) * tmp.conjugated());
      fa[j] = r * (aux + cmpl(0, 2) * tmp);
    }
    fft(fa, sz >> 1);
    vector<long long> res(need);
    for (int i = 0; i < need; i++) {
      res[i] = llround(i % 2 == 0 ? fa[i >> 1].x : fa[i >> 1].y);
    }
    return res;
  }
  
  


  vector<long long> multiply(const vector<int>& a, const vector<int>& b) {
    if (a.empty() || b.empty()) {
      return {};
    }
    if (a == b) {
      return square(a);
    }
    int need = (int) a.size() + (int) b.size() - 1;
    int nbase = 1;
    while ((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    int sz = 1 << nbase;
    if (sz > (int) fa.size()) {
      fa.resize(sz);
    }
    for (int i = 0; i < sz; i++) {
      int x = (i < (int) a.size() ? a[i] : 0);
      int y = (i < (int) b.size() ? b[i] : 0);
      fa[i] = cmpl(x, y);
    }
    fft(fa, sz);
    cmpl r(0, -0.25 / (sz >> 1));
    for (int i = 0; i <= (sz >> 1); i++) {
      int j = (sz - i) & (sz - 1);
      cmpl z = (fa[j] * fa[j] - (fa[i] * fa[i]).conjugated()) * r;
      fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conjugated()) * r;
      fa[i] = z;
    }
    for (int i = 0; i < (sz >> 1); i++) {
      cmpl A0 = (fa[i] + fa[i + (sz >> 1)]) * cmpl(0.5, 0);
      cmpl A1 = (fa[i] - fa[i + (sz >> 1)]) * cmpl(0.5, 0) * roots[(sz >> 1) + i];
      fa[i] = A0 + A1 * cmpl(0, 1);
    }
    fft(fa, sz >> 1);
    vector<long long> res(need);
    for (int i = 0; i < need; i++) {
    res[i] = llround(i % 2 == 0 ? fa[i >> 1].x : fa[i >> 1].y);
    }
    return res;
  }

  vector<int> multiply_mod(const vector<int>& a, const vector<int>& b, int m) {
    if (a.empty() || b.empty()) {
      return {};
    }
    int need = (int) a.size() + (int) b.size() - 1;
    int nbase = 0;
    while ((1 << nbase) < need) {
      nbase++;
    }
    ensure_base(nbase);
    int sz = 1 << nbase;
    if (sz > (int) fa.size()) {
      fa.resize(sz);
    }
    for (int i = 0; i < (int) a.size(); i++) {
      int x = (a[i] % m + m) % m;
      fa[i] = cmpl(x & ((1 << 15) - 1), x >> 15);
    }
    fill(fa.begin() + a.size(), fa.begin() + sz, cmpl{0, 0});
    fft(fa, sz);
    if (sz > (int) fb.size()) {
      fb.resize(sz);
    }
    if (a == b) {
      copy(fa.begin(), fa.begin() + sz, fb.begin());
    } else {
      for (int i = 0; i < (int) b.size(); i++) {
        int x = (b[i] % m + m) % m;
        fb[i] = cmpl(x & ((1 << 15) - 1), x >> 15);
      }
      fill(fb.begin() + b.size(), fb.begin() + sz, cmpl{0, 0});
      fft(fb, sz);
    }
    double ratio = 0.25 / sz;
    cmpl r2(0, -1);
    cmpl r3(ratio, 0);
    cmpl r4(0, -ratio);
    cmpl r5(0, 1);
    for (int i = 0; i <= (sz >> 1); i++) {
      int j = (sz - i) & (sz - 1);
      cmpl a1 = (fa[i] + fa[j].conjugated());
      cmpl a2 = (fa[i] - fa[j].conjugated()) * r2;
      cmpl b1 = (fb[i] + fb[j].conjugated()) * r3;
      cmpl b2 = (fb[i] - fb[j].conjugated()) * r4;
      if (i != j) {
        cmpl c1 = (fa[j] + fa[i].conjugated());
        cmpl c2 = (fa[j] - fa[i].conjugated()) * r2;
        cmpl d1 = (fb[j] + fb[i].conjugated()) * r3;
        cmpl d2 = (fb[j] - fb[i].conjugated()) * r4;
        fa[i] = c1 * d1 + c2 * d2 * r5;
        fb[i] = c1 * d2 + c2 * d1;
      }
      fa[j] = a1 * b1 + a2 * b2 * r5;
      fb[j] = a1 * b2 + a2 * b1;
    }
    fft(fa, sz);
    fft(fb, sz);
    vector<int> res(need);
    for (int i = 0; i < need; i++) {
      long long aa = llround(fa[i].x);
      long long bb = llround(fb[i].x);
      long long cc = llround(fa[i].y);
      res[i] = static_cast<int>((aa + ((bb % m) << 15) + ((cc % m) << 30)) % m);
    }
    return res;
  }
}  



const int mx = 250000 + 100;
int c[mx];

vi recur(int i, int j){
  if(i == j) return {1, c[i]};
  int mid = (i + j) / 2;
  vi l = recur(i, mid);
  vi r = recur(mid + 1, j);
  vi res = fft::multiply_mod(l, r, mod);
  return res;
}

void solve(){
  int n; cin >> n;
  F0R(i,n-1){
    int x,y;
    cin >> x >> y;
    x--; y--;
    c[x]++;
    c[y]++;
  }
  FOR(i,1,n) c[i]--;
  vi res = recur(0, n-1);
  int ans = 0;
  int val = 1;
  for(int i = n-1; i >= 0; i--){
    val = val * (n - i) % mod;
    int x = val * res[i] % mod;
    if(i&1) x *= -1;
    ans = (ans + x + mod) % mod;
  }
  cout << ans << endl;
}

signed main(){
  IOS;
  int tt = 1;
  

  for(int ii = 1; ii <= tt; ii++)
    solve();
}
