



using namespace std;

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

  Modular inverse() const {
    Type a = value, b = mod(), u = 0, v = 1;
    while (a != 0) {
      Type t = b / a;
      b -= t * a; swap(a, b);
      u -= t * v; swap(u, v);
    }
    assert(b == 1);
    return Modular(u);
  }
  Modular& operator/=(const Modular& other) { return *this *= other.inverse(); }

  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

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



constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

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
    while (power(root, (md - 1) >> 1) == 1) {
      root++;
    }
    assert(power(root, md - 1) == 1);
    root = power(root, (md - 1) >> max_base);
    base = 1;
    rev = {0, 1};
    roots = {0, 1};
  }

  static void ensure_base(int nbase) {
    if (md != T::value) {
      clear();
    }
    if (roots.empty()) {
      init();
    }
    if (nbase <= base) {
      return;
    }
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
    int eq = (a.size() == b.size() && a == b);
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
vector<Modular<T>> inverse_old(vector<Modular<T>> a) {
  assert(!a.empty());
  int n = (int) a.size();
  if (n == 1) {
    return {1 / a[0]};
  }
  int m = (n + 1) >> 1;
  vector<Modular<T>> b = inverse_old(vector<Modular<T>>(a.begin(), a.begin() + m));
  int need = n << 1;
  int nbase = 0;
  while ((1 << nbase) < need) {
    ++nbase;
  }
  NTT<T>::ensure_base(nbase);
  int size = 1 << nbase;
  a.resize(size);
  b.resize(size);
  NTT<T>::fft(a);
  NTT<T>::fft(b);
  Modular<T> inv = 1 / static_cast<Modular<T>>(size);
  for (int i = 0; i < size; ++i) {
    a[i] = (2 - a[i] * b[i]) * b[i] * inv;
  }
  reverse(a.begin() + 1, a.end());
  NTT<T>::fft(a);
  a.resize(n);
  return a;
}

template <typename T>
vector<Modular<T>> operator*(const vector<Modular<T>>& a, const vector<Modular<T>>& b) {
  if (a.empty() || b.empty()) {
    return {};
  }
  if (min(a.size(), b.size()) < 100) {
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

template <typename T>
vector<T>& operator+=(vector<T>& a, const vector<T>& b) {
  if (a.size() < b.size()) {
    a.resize(b.size());
  }
  for (int i = 0; i < (int) b.size(); i++) {
    a[i] += b[i];
  }
  return a;
}

template <typename T>
vector<T> operator+(const vector<T>& a, const vector<T>& b) {
  vector<T> c = a;
  return c += b;
}

template <typename T>
vector<T>& operator-=(vector<T>& a, const vector<T>& b) {
  if (a.size() < b.size()) {
    a.resize(b.size());
  }
  for (int i = 0; i < (int) b.size(); i++) {
    a[i] -= b[i];
  }
  return a;
}

template <typename T>
vector<T> operator-(const vector<T>& a, const vector<T>& b) {
  vector<T> c = a;
  return c -= b;
}

template <typename T>
vector<T> operator-(const vector<T>& a) {
  vector<T> c = a;
  for (int i = 0; i < (int) c.size(); i++) {
    c[i] = -c[i];
  }
  return c;
}


int n, k, q;



const int MXN = 3e5+2, MXK = 6, MAX = 6e5;
int a[MAX], b[MXK], c1[MAX], c2[MAX];




Mint modPow(Mint a, lli p){
        Mint o = 1, aa = a;
        while(p > 0){
                 if(p&1)o*=aa;
                 aa*=aa;
                 p>>=1;
        }
        return o;
}




vector<Mint> raise1(int x){
    

    if(x <= 0){
        vector<Mint> y(1);
        y[0] = 1;
        return y;
    }
    if(x == 1){
        vector<Mint> y(2);
        y[0] = 1;
        y[1] = 2;
        return y;
    }
    vector<Mint> a = raise1(x/2);
    a = a*a;
    if(x%2 == 1)a = a*raise1(1);
    return a;
}

vector<Mint> raise2(int x){
    

    if(x <= 0){
        vector<Mint> y(1);
        y[0] = 1;
        return y;
    }
    if(x == 1){
        vector<Mint> y(3);
        y[0] = 1;
        y[1] = 2;
        y[2] = 1;
        return y;
    }
    vector<Mint> a = raise2(x/2);
    a = a*a;
    if(x%2 == 1)a = a*raise2(1);
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;
    for(int i = 0; i< MAX; i++){
        c1[i] = 0;
        c2[i] = 0;
    }
    for(int i = 0; i< n; i++)cin>>a[i];
    sort(a, a+n);
    int p = 0;
    c1[0] = 0;c2[0] = 0;
    for(int i = 1; i< MAX; i++){
        c1[i] = c1[i-1];
        c2[i] = c2[i-1];
        while(p < n && a[p] < i)p++;
        if(p < n && a[p] == i){
            c1[i]++;
            p++;
            if(p < n && a[p] == i){
                c1[i]--;
                c2[i]++;
            }
        }
    }
    
    for(int i = 0; i< k; i++)cin>>b[i];
    sort(b, b+k);
    vector<Mint> poly[k];
    int p1 = 0, p2 = 0;
    for(int i = 0; i< k; i++){
        int t1 = c1[b[i]-1]-p1, t2 = c2[b[i]-1]-p2;
        poly[i] = (raise1(t1)*raise2(t2));
        if(i > 0)poly[i] *= poly[i-1];
        p1 = c1[b[i]-1];
        p2 = c2[b[i]-1];
    }
    cin>>q;
    while(q-->0){
        int tmp;
        cin>>tmp;
        tmp /= 2;
        Mint ans = 0;
        for(int i = 0; i< k; i++)
            if(tmp-b[i]-1 < poly[i].size() && tmp-b[i]-1 >= 0)
                ans += poly[i][tmp-b[i]-1];
        cout<<ans<<"\n";
    }
    return 0;
}