







using namespace std;

template <typename T> void set_max(T& a, T b) {
  a = max(a, b);
}
template <typename T> void set_min(T& a, T b) {
  a = min(a, b);
}
template <typename T> void id1(T& a, T b) {
  a = min(a, b);
}
template <typename T> void id0(T& a, T b) {
  a = max(a, b);
}

const string nl = "\n";









  {                                                                            \
    sort(v.begin(), v.end());                                                  \
    v.erase(unique(v.begin(), v.end()), v.end());                              \
  }

mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());




void usaco(string filename) {
  

  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}

















template <typename A, typename B> string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string)s);
}

string to_string(const char ch) {
  string ret;
  ret.push_back(ch);
  return ret;
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N> string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A> string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() {
  cerr << endl;
}

template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}













template <typename T> T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a;
    swap(a, m);
    u -= t * v;
    swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <typename T> class Modular {
public:
  using Type = typename decay<decltype(T::value)>::type;

  constexpr Modular() : value() {
  }
  template <typename U> Modular(const U& x) {
    value = normalize(x);
  }

  template <typename U> static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod())
      v = static_cast<Type>(x);
    else
      v = static_cast<Type>(x % mod());
    if (v < 0)
      v += mod();
    return v;
  }

  const Type& operator()() const {
    return value;
  }
  template <typename U> explicit operator U() const {
    return static_cast<U>(value);
  }
  constexpr static Type mod() {
    return T::value;
  }

  Modular& operator+=(const Modular& other) {
    if ((value += other.value) >= mod())
      value -= mod();
    return *this;
  }
  Modular& operator-=(const Modular& other) {
    if ((value -= other.value) < 0)
      value += mod();
    return *this;
  }
  template <typename U> Modular& operator+=(const U& other) {
    return *this += Modular(other);
  }
  template <typename U> Modular& operator-=(const U& other) {
    return *this -= Modular(other);
  }
  Modular& operator++() {
    return *this += 1;
  }
  Modular& operator--() {
    return *this -= 1;
  }
  Modular operator++(int) {
    Modular result(*this);
    *this += 1;
    return result;
  }
  Modular operator--(int) {
    Modular result(*this);
    *this -= 1;
    return result;
  }
  Modular operator-() const {
    return Modular(-value);
  }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::
      type&
      operator*=(const Modular& rhs) {

    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x),
             d, m;
    asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(mod()));
    value = m;

    value = normalize(
        static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));

    return *this;
  }
  template <typename U = T>
  typename enable_if<
      is_same<typename Modular<U>::Type, long long>::value,
      Modular>::type&
  operator*=(const Modular& rhs) {
    long long q = static_cast<long long>(
        static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::
      type&
      operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }

  Modular& operator/=(const Modular& other) {
    return *this *= Modular(inverse(other.value, mod()));
  }

  friend const Type& abs(const Modular& x) {
    return x.value;
  }

  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);

private:
  Type value;
};

template <typename T>
bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) {
  return lhs.value == rhs.value;
}
template <typename T, typename U>
bool operator==(const Modular<T>& lhs, U rhs) {
  return lhs == Modular<T>(rhs);
}
template <typename T, typename U>
bool operator==(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) == rhs;
}

template <typename T>
bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) {
  return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(const Modular<T>& lhs, U rhs) {
  return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(U lhs, const Modular<T>& rhs) {
  return !(lhs == rhs);
}

template <typename T>
bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) {
  return lhs.value < rhs.value;
}

template <typename T>
Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) += rhs;
}

template <typename T>
Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) -= rhs;
}

template <typename T>
Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) *= rhs;
}

template <typename T>
Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) /= rhs;
}

template <typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  if (b == 0)
    return 1;
  if (a == 0)
    return 0;

  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1)
      res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}

template <typename T> bool IsZero(const Modular<T>& number) {
  return number() == 0;
}

template <typename T> string to_string(const Modular<T>& number) {
  return to_string(number());
}



template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  return stream << number();
}



template <typename U, typename T> U& operator>>(U& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, long long>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}



constexpr int md = 1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;







template <typename T, int NDIMS> struct tensor_view {
  static_assert(NDIMS >= 0);

protected:
  std::array<int, NDIMS> shape;
  std::array<int, NDIMS> strides;
  T* data;

  tensor_view(
      std::array<int, NDIMS> shape_, std::array<int, NDIMS> id2, T* data_)
      : shape(shape_), strides(id2), data(data_) {
  }

public:
  tensor_view() : shape{0}, strides{0}, data(nullptr) {
  }

protected:
  int flatten_index(std::array<int, NDIMS> idx) const {
    int res = 0;
    for (int i = 0; i < NDIMS; i++) {
      res += idx[i] * strides[i];
    }
    return res;
  }
  int flatten_index_checked(std::array<int, NDIMS> idx) const {
    int res = 0;
    for (int i = 0; i < NDIMS; i++) {
      assert(0 <= idx[i] && idx[i] < shape[i]);
      res += idx[i] * strides[i];
    }
    return res;
  }

public:
  T& operator[](std::array<int, NDIMS> idx) const {
    return data[flatten_index(idx)];
  }
  T& at(std::array<int, NDIMS> idx) const {
    return data[flatten_index_checked(idx)];
  }

  template <int D = NDIMS>
  std::enable_if_t<(0 < D), tensor_view<T, NDIMS - 1>>
  operator[](int idx) const {
    std::array<int, NDIMS - 1> nshape;
    std::copy(shape.begin() + 1, shape.end(), nshape.begin());
    std::array<int, NDIMS - 1> id3;
    std::copy(strides.begin() + 1, strides.end(), id3.begin());
    T* ndata = data + (strides[0] * idx);
    return tensor_view<T, NDIMS - 1>(nshape, id3, ndata);
  }
  template <int D = NDIMS>
  std::enable_if_t<(0 < D), tensor_view<T, NDIMS - 1>> at(int idx) const {
    assert(0 <= idx && idx < shape[0]);
    return operator[](idx);
  }

  template <int D = NDIMS> std::enable_if_t<(0 == D), T&> operator*() const {
    return *data;
  }

  template <typename U, int D> friend struct tensor_view;
  template <typename U, int D> friend struct tensor;
};

template <typename T, int NDIMS> struct tensor {
protected:
  std::array<int, NDIMS> shape;
  std::array<int, NDIMS> strides;
  int len;
  T* data;

public:
  tensor() : shape{0}, strides{0}, len(0), data(nullptr) {
  }

  explicit tensor(std::array<int, NDIMS> shape_, const T& t = T()) {
    shape = shape_;
    strides[NDIMS - 1] = 1;
    for (int i = NDIMS - 1; i > 0; i--) {
      strides[i - 1] = strides[i] * shape[i];
    }
    len = strides[0] * shape[0];
    data = new T[len];
    std::fill(data, data + len, t);
  }

  tensor(const tensor& o)
      : shape(o.shape), strides(o.strides), len(o.len), data(new T[len]) {
    for (int i = 0; i < len; i++) {
      data[i] = o.data[i];
    }
  }

  tensor& operator=(tensor&& o) noexcept {
    using std::swap;
    swap(shape, o.shape);
    swap(strides, o.strides);
    swap(len, o.len);
    swap(data, o.data);
  }
  tensor(tensor&& o) : tensor() {
    *this = std::move(o);
  }
  tensor& operator=(const tensor& o) {
    return *this = tensor(o);
  }
  ~tensor() {
    delete[] data;
  }

  using view_t = tensor_view<T, NDIMS>;
  view_t view() {
    return tensor_view<T, NDIMS>(shape, strides, data);
  }
  operator view_t() {
    return view();
  }

  using const_view_t = tensor_view<const T, NDIMS>;
  const_view_t view() const {
    return tensor_view<const T, NDIMS>(shape, strides, data);
  }
  operator const_view_t() const {
    return view();
  }

  T& operator[](std::array<int, NDIMS> idx) {
    return view()[idx];
  }
  T& at(std::array<int, NDIMS> idx) {
    return view().at(idx);
  }
  const T& operator[](std::array<int, NDIMS> idx) const {
    return view()[idx];
  }
  const T& at(std::array<int, NDIMS> idx) const {
    return view().at(idx);
  }

  template <int D = NDIMS>
  std::enable_if_t<(0 < D), tensor_view<T, NDIMS - 1>> operator[](int idx) {
    return view()[idx];
  }
  template <int D = NDIMS>
  std::enable_if_t<(0 < D), tensor_view<T, NDIMS - 1>> at(int idx) {
    return view().at(idx);
  }

  template <int D = NDIMS>
  std::enable_if_t<(0 < D), tensor_view<const T, NDIMS - 1>>
  operator[](int idx) const {
    return view()[idx];
  }
  template <int D = NDIMS>
  std::enable_if_t<(0 < D), tensor_view<const T, NDIMS - 1>> at(int idx) const {
    return view().at(idx);
  }

  template <int D = NDIMS> std::enable_if_t<(0 == D), T&> operator*() {
    return *view();
  }
  template <int D = NDIMS>
  std::enable_if_t<(0 == D), const T&> operator*() const {
    return *view();
  }
};



void solve() {
  int n, m, rb, cb, rd, cd, P;
  cin >> n >> m >> rb >> cb >> rd >> cd >> P;

  int sdr = 1;
  int sdc = 1;
  {
    int nr = rb + sdr;
    int nc = cb + sdc;

    if (nr <= 0 || nr > n) {
      sdr = -sdr;
      nr = rb + sdr;
    }

    if (nc <= 0 || nc > m) {
      sdc = -sdc;
      nc = cb + sdc;
    }
  }

  tensor<bool, 4> visited({n + 1, m + 1, 3, 3});
  tensor<Mint, 4> cache({n + 1, m + 1, 3, 3});
  tensor<Mint, 4> sums({n + 1, m + 1, 3, 3});

  function<pair<Mint, Mint>(int, int, int, int, Mint, Mint)> go =
      [&](int r, int c, int dr, int dc, Mint sum, Mint p)
      -> pair<Mint, Mint> {

    int nr = r + dr;
    int nc = c + dc;

    if (nr <= 0 || nr > n) {
      dr = -dr;
      nr = r + dr;
    }

    if (nc <= 0 || nc > m) {
      dc = -dc;
      nc = c + dc;
    }

    

    



    

    

                                            

                                            

                                            


    

    

    

    if (visited[{r, c, dr + 1, dc + 1}]) {
      Mint p_ = cache[{r, c, dr + 1, dc + 1}];
      Mint sub = sums[{r, c, dr + 1, dc + 1}];
      return {p / p_, sum - p / p_ * sub};
    }

    visited[{r, c, dr + 1, dc + 1}] = true;
    cache[{r, c, dr + 1, dc + 1}] = p;
    sums[{r, c, dr + 1, dc + 1}] = sum;

    


    

    

    


    

    

    

    


    


    if (r == rd || c == cd) {
      Mint mul = Mint(100 - P) / 100;
      auto [pp, ss] = go(nr, nc, dr, dc, sum + mul * p, mul * p);
      return {pp, ss};
    } else {
      auto [pp, ss] = go(nr, nc, dr, dc, sum + p, p);
      return {pp, ss};
    }
  };

  


  auto [p, sum] = go(rb, cb, sdr, sdc, Mint(0), Mint(1));

  cout << (sum / (1 - p)) << nl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int tt;
  cin >> tt;

  while (tt--) {
    solve();
  }

  return 0;
}
