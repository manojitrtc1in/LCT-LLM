#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

static struct FastInput {
  static constexpr int BUF_SIZE = 1 << 20;
  char buf[BUF_SIZE];
  size_t chars_read = 0;
  size_t buf_pos = 0;
  FILE *in = stdin;
  char cur = 0;
 
  inline char get_char() {
    if (buf_pos >= chars_read) {
      chars_read = fread(buf, 1, BUF_SIZE, in);
      buf_pos = 0;
      buf[0] = (chars_read == 0 ? -1 : buf[0]);
    }
    return cur = buf[buf_pos++];
  }
 
  inline void tie(int) {}
 
  inline explicit operator bool() {
    return cur != -1;
  }
 
  inline static bool is_blank(char c) {
    return c <= ' ';
  }
 
  inline bool skip_blanks() {
    while (is_blank(cur) && cur != -1) {
      get_char();
    }
    return cur != -1;
  }
 
  inline FastInput& operator>>(char& c) {
    skip_blanks();
    c = cur;
    return *this;
  }
  
  inline FastInput& operator>>(string& s) {
    if (skip_blanks()) {
      s.clear();
      do {
        s += cur;
      } while (!is_blank(get_char()));
    }
    return *this;
  }
 
  template <typename T>
  inline FastInput& read_integer(T& n) {
    

    n = 0;
    if (skip_blanks()) {
      int sign = +1;
      if (cur == '-') {
        sign = -1;
        get_char();
      }
      do {
        n += n + (n << 3) + cur - '0';
      } while (!is_blank(get_char()));
      n *= sign;
    }
    return *this;
  }
 
  template <typename T>
  inline typename enable_if<is_integral<T>::value, FastInput&>::type operator>>(T& n) {
    return read_integer(n);
  }
  
  #if !defined(_WIN32) || defined(_WIN64)
  inline FastInput& operator>>(__int128& n) {
    return read_integer(n);
  }
  #endif
 
  template <typename T>
  inline typename enable_if<is_floating_point<T>::value, FastInput&>::type operator>>(T& n) {
    

    n = 0;
    if (skip_blanks()) {
      string s;
      (*this) >> s;
      sscanf(s.c_str(), "%lf", &n);
    }
    return *this;
  }
} fast_input;
 
#define cin fast_input
 
static struct FastOutput {
  static constexpr int BUF_SIZE = 1 << 20;
  char buf[BUF_SIZE];
  size_t buf_pos = 0;
  static constexpr int TMP_SIZE = 1 << 20;
  char tmp[TMP_SIZE];
  FILE *out = stdout;
 
  inline void put_char(char c) {
    buf[buf_pos++] = c;
    if (buf_pos == BUF_SIZE) {
      fwrite(buf, 1, buf_pos, out);
      buf_pos = 0;
    }
  }
 
  ~FastOutput() {
    fwrite(buf, 1, buf_pos, out);
  }
 
  inline FastOutput& operator<<(char c) {
    put_char(c);
    return *this;
  }
 
  inline FastOutput& operator<<(const char* s) {
    while (*s) {
      put_char(*s++);
    }
    return *this;
  }
 
  inline FastOutput& operator<<(const string& s) {
    for (int i = 0; i < (int) s.size(); i++) {
      put_char(s[i]);
    }
    return *this;
  }
 
  template <typename T>
  inline char* integer_to_string(T n) {
    

    char* p = tmp + TMP_SIZE - 1;
    if (n == 0) {
      *--p = '0';
    } else {
      bool is_negative = false;
      if (n < 0) {
        is_negative = true;
        n = -n;
      }
      while (n > 0) {
        *--p = (char) ('0' + n % 10);
        n /= 10;
      }
      if (is_negative) {
        *--p = '-';
      }
    }
    return p;
  }
 
  template <typename T>
  inline typename enable_if<is_integral<T>::value, char*>::type stringify(T n) {
    return integer_to_string(n);
  }
 
  #if !defined(_WIN32) || defined(_WIN64)
  inline char* stringify(__int128 n) {
    return integer_to_string(n);
  }
  #endif
 
  template <typename T>
  inline typename enable_if<is_floating_point<T>::value, char*>::type stringify(T n) {
    sprintf(tmp, "%.17f", n);
    return tmp;
  }
 
  template <typename T>
  inline FastOutput& operator<<(const T& n) {
    auto p = stringify(n);
    for (; *p != 0; p++) {
      put_char(*p);
    }
    return *this;
  }
} fast_output;
 
#define cout fast_output

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}
 
template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;
 
  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }
 
  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }
 
  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }
 
  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }
 
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;
#else
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
    int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }
 
  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }
 
  template <typename U>
  friend const Modular<U>& abs(const Modular<U>& v) { return v; }
 
  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
 
  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
 
  template <typename U>
  friend std::istream& operator>>(std::istream& stream, Modular<U>& number);
 
 private:
  Type value;
};
 
template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }
 
template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
 
template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }
 
template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
 
template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
 
template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
 
template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
 
template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}
 
template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}
 
template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}
 
template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
  return stream << number();
}
 
template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}
 

constexpr int md = 998244353;
using Mint = Modular<integral_constant<decay<decltype(md)>::type,md>>;

vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);
 
Mint C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() < n + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}

class segtree {
 public:
  struct node {
    

    

    Mint val = 0;
    Mint put = 0;
 
    void apply(int l, int r, Mint v) {
      val += v;
      put += v;
    }
  };
 
  node unite(const node &a, const node &b) const {
    node res;
    res.val = a.val + b.val;
    return res;
  }
 
  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (tree[x].put != 0) {
      tree[x + 1].apply(l, y, tree[x].put);
      tree[z].apply(y + 1, r, tree[x].put);
      tree[x].put = 0;
    }
  }
 
  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }
 
  int n;
  vector<node> tree;
 
  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }
 
  template <typename M>
  void build(int x, int l, int r, const vector<M> &v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v);
    build(z, y + 1, r, v);
    pull(x, z);
  }
 
  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    node res{};
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
      }
    }
    pull(x, z);
    return res;
  }
 
  template <typename... M>
  void modify(int x, int l, int r, int ll, int rr, const M&... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v...);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v...);
    }
    pull(x, z);
  }
 
  int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[x + 1])) {
      res = find_first_knowingly(x + 1, l, y, f);
    } else {
      res = find_first_knowingly(z, y + 1, r, f);
    }
    pull(x, z);
    return res;
  }
 
  int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_first_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (ll <= y) {
      res = find_first(x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
      res = find_first(z, y + 1, r, ll, rr, f);
    }
    pull(x, z);
    return res;
  }
 
  int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[z])) {
      res = find_last_knowingly(z, y + 1, r, f);
    } else {
      res = find_last_knowingly(x + 1, l, y, f);
    }
    pull(x, z);
    return res;
  }
 
  int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_last_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (rr > y) {
      res = find_last(z, y + 1, r, ll, rr, f);
    }
    if (ll <= y && res == -1) {
      res = find_last(x + 1, l, y, ll, rr, f);
    }
    pull(x, z);
    return res;
  }
 
  segtree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }
 
  template <typename M>
  segtree(const vector<M> &v) {
    n = v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v);
  }
 
  node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return get(0, 0, n - 1, ll, rr);
  }
 
  node get(int p) {
    assert(0 <= p && p <= n - 1);
    return get(0, 0, n - 1, p, p);
  }
 
  template <typename... M>
  void modify(int ll, int rr, const M&... v) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    modify(0, 0, n - 1, ll, rr, v...);
  }
 
  

  

 
  int find_first(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_first(0, 0, n - 1, ll, rr, f);
  }
 
  int find_last(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_last(0, 0, n - 1, ll, rr, f);
  }
};

struct graph {
	int n;
	vector<vector<int>> edge;
	vector<int> sz;
	vector<int> pos;
	vector<int> end;
	vector<int> head;
	vector<int> nxt;
	vector<int> pr;
	graph(int n) : n(n) {
		edge.resize(n + 1);
		sz.resize(n + 1);
		pos.resize(n + 1);
		end.resize(n + 1);
		head.resize(n + 1,-1);
		nxt.resize(n + 1,-1);
		pr.resize(n + 1);
	}
	void add(int u,int v) {
		edge[u].emplace_back(v);
		edge[v].emplace_back(u);
	}
	void dfs(int v,int p = 0) {
		sz[v] = 1;
		for (auto&u : edge[v]) {
			if (u == p) continue;
			dfs(u,v);
			sz[v] += sz[u];
		}
	}
	void dfs1(int v,int p = 0) {
		static int count = -1;
		pos[v] = ++count;
		if (head[v] == -1) head[v] = v;
		pr[v] = p;
		int big = -1;
		for (auto&u : edge[v]) {
			if (u == p) continue;
			if (big == -1 || sz[big] < sz[u]) big = u;
		}
		if (big != -1) {
			head[big] = head[v];
			nxt[v] = big;
			dfs1(big,v);
		}
		for (auto&u : edge[v]) {
			if (u == p || u == big) continue;
			dfs1(u,v);
		}
		end[v] = count;
	}
};
 
int main() {
	int n,q;
	cin >> n >> q;
	graph g(n);
	for (int i = 1; i < n; i++) {
		int u,v;
		cin >> u >> v;
		g.add(u,v);
	}
	g.dfs(1);
	g.dfs1(1);
	segtree tree(n);
	vector<Mint> value(n + 1);
	vector<Mint> spe(n + 1);
	Mint all = Mint(1) / n;
	while (q--) {
		int type,v;
		cin >> type >> v;
		if (type == 1) {
			int d;
			cin >> d;
			Mint val = (Mint)g.sz[v] * d;
			if (g.pos[v] > 0) tree.modify(0,g.pos[v] - 1,val);
			if (g.end[v] + 1 < n) tree.modify(g.end[v] + 1,n - 1,val);
			if (g.nxt[v] != -1) {
				int nxt = g.nxt[v];
				val = (Mint)(n - g.sz[nxt]) * d;
				tree.modify(g.pos[nxt],g.end[nxt],val);
			}
			spe[v] += (Mint)n * d;
			value[v] += d;
		}
		else {
			auto get = [&](int v) {
				Mint ans = 0;
				while (1) {
					if (g.head[v] == 1) {
						return ans;
					}
					v = g.head[v];
					int nxt = g.pr[v];
					ans += value[nxt] * (n - g.sz[v]);
					v = nxt;
				}
			};
			cout << ((tree.get(g.pos[v]).val + get(v) + spe[v]) * all)() <<"\n";
		}
	}
}
