

using namespace std;






















typedef vector<l> vl;
typedef vector<ul> vul;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vector<l>> vvl;
typedef vector<vector<ll>> vvll;
typedef vector<vector<bool>> vvb;
typedef pair<l, l> pl;
typedef pair<ul,ul> pul;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef vector<pl> vpl;
typedef vector<pll> vpll;
typedef vector<vector<pl>> vvpl;
typedef vector<vector<pll>> vvpll;
struct trio {
  ll fst, snd, trd;
  friend ostream& operator<<(ostream &o, trio &a){ o<<"("<<a.fst<<","<<a.snd<<","<<a.trd<<")"; return o; }
};
typedef vector<trio> vt;











template<typename T> il T max() { return numeric_limits<T>::max(); }

template<typename T> il T gcd(T a, T b) { return b == 0 ? a : gcd(b, a%b); }

template<typename T> il void prtv(T v) { cout << v << '\n'; }

template<typename T, typename... Args> il void prtv(T v, Args... args) { cout << v << ' '; prtv(args...); }

template<typename T> il void prtc(T a, const str s = " ") {
  for (auto v : a) cout << v << s;
  cout << '\n';
}

ostream& operator<<(ostream &out, pl &a) { out << "(" << a.fst << "," << a.snd << ")"; return out; }
ostream& operator<<(ostream &out, pll &a) { out << "(" << a.fst << "," << a.snd << ")"; return out; }








vl primes;
il void id0() {
  vb s(10e4, 0);
  s[0] = 1;
  s[1] = 1;
  for (l i = 3; i < 10e4; i += 2) {
    conif (s[i]);
    primes.pub(i);
    for (l j = i + (i << 1); j < 10e4; j += (i << 1))
      s[j] = 1;
  }
}

il vpl factorize(l n) {
  vpl a;
  l cnt = ctz(n);
  a.pub({2, cnt});
  n >>= cnt;
  for (auto &d : primes) {
    cnt = 0;
    while (n % d == 0) {
      n /= d;
      cnt++;
    }
    a.pub({d, cnt});
    brkif (n == 1);
  }
  if (n != 1) a.pub({n, 1});
  return a;
}


int main() {
  fast_io();



  id0();

  l n;
  cin >> n;
  vl a(n);
  map<l,l> m;
  for (l i = 0; i < n; i++) {
    l v;
    cin >> v;
    if (v) {
      vpl d = factorize(abs(v));
      v = (v > 0 ? 1 : -1);
      for (auto &x : d)  if (x.snd & 1) v *= x.fst;
      v = m.insert({v, m.size() + 1}).fst->snd;
    }
    a[i] = v;
  }

  vl b(n);
  for (l i = 0; i < n; i++) {
    l r = 0;
    vl c(n+1);
    for (l j = i; j < n; j++) {
      if (!c[a[j]]++) r++;
      if (c[0] > 0 && r > 1) b[r - 2]++;
      else b[r - 1]++;
    }
  }
  prtc(b);

  return 0;
}

