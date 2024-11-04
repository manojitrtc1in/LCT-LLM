



using namespace std;






using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


struct custHash {
    static uint64_t splitmix64(uint64_t x) {  
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t id0 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id0);
    }
};

vector<string> id1(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}






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

      uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
      uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
      asm(
          "divl %4; \n\t"
          : "=a" (d), "=d" (m)
          : "d" (xh), "a" (xl), "r" (mod())
      );
      value = m;

      value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));

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

template <typename T>
class NTT {
 public:
    using Type = typename decay<decltype(T::value)>::type;
    static Type md;
    static Modular<T> root;
    static int base;
    static int max_base;
    static vector<Modular<T>> roots;
    static vector<int> rev;
    static void clear() {
      root = 0;
      base = 0;
      max_base = 0;
      roots.clear();
      rev.clear();
    }
    static void init() {
      md = T::value;
      assert(md >= 3 && md % 2 == 1);
      auto tmp = md - 1;
      max_base = 0;
      while (tmp % 2 == 0) {
        tmp /= 2;
        max_base++;
      }
      root = 2;
      while (power(root, (md - 1) >> 1) == 1) {  root++; }
      assert(power(root, md - 1) == 1);
      root = power(root, (md - 1) >> max_base);
      base = 1;
      rev = {0, 1};
      roots = {0, 1};
    }
    static void ensure_base(int nbase) {
      if (md != T::value) { clear(); }
      if (roots.empty()) { init(); }
      if (nbase <= base) { return; }
      assert(nbase <= max_base);
      rev.resize(1 << nbase);
      for (int i = 0; i < (1 << nbase); i++) {
        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
      }
      roots.resize(1 << nbase);
      while (base < nbase) {
        Modular<T> z = power(root, 1 << (max_base - 1 - base));
        for (int i = 1 << (base - 1); i < (1 << base); i++) {
          roots[i << 1] = roots[i];
          roots[(i << 1) + 1] = roots[i] * z;
        }
        base++;
      }
    }
    static void fft(vector<Modular<T>> &a) {
      int n = (int) a.size();
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
            Modular<T> x = a[i + j];
            Modular<T> y = a[i + j + k] * roots[j + k];
            a[i + j] = x + y;
            a[i + j + k] = x - y;
          }
        }
      }
    }
    static vector<Modular<T>> multiply(vector<Modular<T>> a, vector<Modular<T>> b) {
      if (a.empty() || b.empty()) {
        return {};
      }
      int eq = (a == b);
      int need = (int) a.size() + (int) b.size() - 1;
      int nbase = 0;
      while ((1 << nbase) < need) nbase++;
      ensure_base(nbase);
      int sz = 1 << nbase;
      a.resize(sz);
      b.resize(sz);
      fft(a);
      if (eq) b = a; else fft(b);
      Modular<T> inv_sz = 1 / static_cast<Modular<T>>(sz);
      for (int i = 0; i < sz; i++) {
        a[i] *= b[i] * inv_sz;
      }
      reverse(a.begin() + 1, a.end());
      fft(a);
      a.resize(need);
      return a;
    }
};
template <typename T> typename NTT<T>::Type NTT<T>::md;
template <typename T> Modular<T> NTT<T>::root;
template <typename T> int NTT<T>::base;
template <typename T> int NTT<T>::max_base;
template <typename T> vector<Modular<T>> NTT<T>::roots;
template <typename T> vector<int> NTT<T>::rev;
template <typename T>
vector<Modular<T>> inverse(const vector<Modular<T>>& a) {
    assert(!a.empty());
    int n = (int) a.size();
    vector<Modular<T>> b = {1 / a[0]};
    while ((int) b.size() < n) {
      vector<Modular<T>> x(a.begin(), a.begin() + min(a.size(), b.size() << 1));
      x.resize(b.size() << 1);
      b.resize(b.size() << 1);
      vector<Modular<T>> c = b;
      NTT<T>::fft(c);
      NTT<T>::fft(x);
      Modular<T> inv = 1 / static_cast<Modular<T>>((int) x.size());
      for (int i = 0; i < (int) x.size(); i++) {
        x[i] *= c[i] * inv;
      }
      reverse(x.begin() + 1, x.end());
      NTT<T>::fft(x);
      rotate(x.begin(), x.begin() + (x.size() >> 1), x.end());
      fill(x.begin() + (x.size() >> 1), x.end(), 0);
      NTT<T>::fft(x);
      for (int i = 0; i < (int) x.size(); i++) {
        x[i] *= c[i] * inv;
      }
      reverse(x.begin() + 1, x.end());
      NTT<T>::fft(x);
      for (int i = 0; i < ((int) x.size() >> 1); i++) {
        b[i + ((int) x.size() >> 1)] = -x[i];
      }
    }
    b.resize(n);
    return b;
}
template <typename T>
vector<Modular<T>> operator*(const vector<Modular<T>>& a, const vector<Modular<T>>& b) {
    if (a.empty() || b.empty()) {
      return {};
    }
    if (min(a.size(), b.size()) < 150) {
      vector<Modular<T>> c(a.size() + b.size() - 1, 0);
      for (int i = 0; i < (int) a.size(); i++) {
        for (int j = 0; j < (int) b.size(); j++) {
          c[i + j] += a[i] * b[j];
        }
      }
      return c;
    }
    return NTT<T>::multiply(a, b);
}
template <typename T>
vector<Modular<T>>& operator*=(vector<Modular<T>>& a, const vector<Modular<T>>& b) {
  return a = a * b;
}








typedef long long LL;

constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

int n;
int u,v;
int deg[250001];
Mint fact[250001];

void solve(){
	cin >> n;
	
	REP(i,n-1){
		cin >> u >> v; u--,v--;
		deg[u]++; deg[v]++;
	}
	fact[0] = 1;
	FOR(i,1,n+1) fact[i] = fact[i-1]*i;
	FOR(i,1,n) deg[i]--;
	
	auto compute = [&](auto self, int l, int r){
    	if( l == r-1 )  return vector<Mint>{1,deg[l]};
		int m = l + (r-l)/2;
		return self(self,l,m)*self(self,m,r);
	};
	auto pol = compute(compute,0,n);

	Mint res = 0;
	REP(i,n) {
		if(i&1) res -= fact[n-i]*pol[i];
		else res += fact[n-i]*pol[i];
	}
	cout << res << endl;
}



int main(){
	ios::sync_with_stdio(false);		
    cin.tie(NULL);
    solve();
	return 0;
}