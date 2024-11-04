


template <typename ModT> struct Binom {
  Binom(int n) : fact(n), inv_fact(n) {
    fact[0] = inv_fact[0] = inv_fact[1] = ModT(1);
    for (int i = 2; i < n; ++i) {
      inv_fact[i] = ModT(ModT::MOD - ModT::MOD / i) * inv_fact[ModT::MOD % i];
    }
    for (int i = 1; i < n; ++i) {
      fact[i] = ModT(i) * fact[i - 1];
      inv_fact[i] *= inv_fact[i - 1];
    }
  }

  ModT operator()(int n, int k) const {
    return k < 0 || k > n ? ModT(0) : fact[n] * inv_fact[n - k] * inv_fact[k];
  }

  std::vector<ModT> fact, inv_fact;
};




namespace ntt {

static void id1(int n) {
  if (n & (n - 1)) {
    throw std::invalid_argument(std::to_string(n) + " is not a power of two");
  }
}

static int id0(int n) {
  return n == 1 ? 1 : 1 << (32 - __builtin_clz(n - 1));
}

} 







template <typename T> using LocalSharedPtr = std::shared_ptr<T>;
template <typename T>
using LocalEnableSharedFromThis = std::enable_shared_from_this<T>;

namespace ntt {


template <typename NTT>
struct id2 : LocalEnableSharedFromThis<id2<NTT>> {
private:
  using Mod = typename NTT::Mod;
  using Factory = id2<NTT>;

public:
  using Ptr = LocalSharedPtr<Factory>;

  static Ptr create(int max_deg) { return Ptr(new Factory(max_deg)); }

  struct Poly : public std::vector<Mod> {
    Poly() : std::vector<Mod>(), factory(LocalSharedPtr<Factory>(nullptr)) {}

    int deg() const { return static_cast<int>(std::vector<Mod>::size()) - 1; }

    Poly operator+(const Poly &o) const {
      if (deg() < o.deg()) {
        return o + *this;
      }
      Poly r = factory->make(*this);
      for (int i = 0; i <= o.deg(); ++i) {
        r[i] += o[i];
      }
      return r;
    }

    Poly &operator+=(Poly &o) { return *this = *this += o; }

    Poly operator-(const Poly &o) const {
      int max_deg = std::max(deg(), o.deg());
      Poly r = factory->make(max_deg + 1);
      int min_deg = std::min(deg(), o.deg());
      for (int i = 0; i <= min_deg; ++i) {
        r[i] = (*this)[i] - o[i];
      }
      for (int i = min_deg + 1; i <= deg(); ++i) {
        r[i] = (*this)[i];
      }
      for (int i = min_deg + 1; i <= o.deg(); ++i) {
        r[i] = -o[i];
      }
      return r;
    }

    Poly &operator-=(Poly &o) { return *this = *this -= o; }

    Poly operator*(const Poly &o) const {
      Mod *b0 = factory->template raw_buffer<0>();
      Mod *b1 = factory->template raw_buffer<1>();

      int id6 = deg() + o.deg() + 1;
      int n = id0(id6);
      factory->assert_max_n(n);

      copy_and_fill0(n, b0, *this);
      NTT::dif(n, b0);
      copy_and_fill0(n, b1, o);
      NTT::dif(n, b1);
      dot_product_and_dit(n, Mod(n).inverse(), b0, b0, b1);
      return factory->make(std::vector<Mod>(b0, b0 + id6));
    }

    Poly &operator*=(const Poly &o) { return *this = *this * o; }

  private:
    friend struct id2;

    template <typename... Args>
    Poly(Ptr &&factory_, Args &&...args)
        : std::vector<Mod>(std::forward<Args>(args)...),
          factory(std::move(factory_)) {}

    Ptr factory;
  };

  template <typename... Args> Poly make(Args &&...args) {
    Poly p{LocalEnableSharedFromThis<Factory>::shared_from_this(),
           std::forward<Args>(args)...};
    return p;
  }

private:
  friend struct Poly;

  id2(int max_deg)
      : max_n{id0(max_deg + 1)}, buffer{std::vector<Mod>(max_n),
                                                     std::vector<Mod>(max_n)} {}

  static void copy_and_fill0(int n, Mod *dst, int m, const Mod *src) {
    m = std::min(n, m);
    std::copy(src, src + m, dst);
    std::fill(dst + m, dst + n, Mod(0));
  }

  static void copy_and_fill0(int n, Mod *dst, const std::vector<Mod> &src) {
    copy_and_fill0(n, dst, src.size(), src.data());
  }

  static void dot_product_and_dit(int n, Mod inv_n, Mod *out, const Mod *a,
                                  const Mod *b) {
    for (int i = 0; i < n; ++i) {
      out[i] = inv_n * a[i] * b[i];
    }
    NTT::dit(n, out);
  }

  void assert_max_n(int n) const {
    if (n > max_n) {
      throw std::invalid_argument("insufficient buffer");
    }
  }

  template <int index> Mod *raw_buffer() { return buffer[index].data(); }

  int max_n;
  std::array<std::vector<Mod>, 2> buffer;
};

} 







namespace details {

template <typename ModT> static constexpr ModT power(ModT a, uint64_t n) {
  ModT result(1);
  n %= ModT::MOD - 1;
  while (n) {
    if (n & 1) {
      result *= a;
    }
    a *= a;
    n >>= 1;
  }
  return result;
}

template <typename ModT> static constexpr ModT inverse(ModT a) {
  return power<ModT>(a, ModT::MOD - 2);
}

template <typename Digit> static constexpr Digit id8(Digit MOD, int n) {
  Digit result = 1;
  for (int i = 0; i < n; ++i) {
    result *= 2 - MOD * result;
  }
  return -result;
}

} 









namespace montgomery {

using u64 = uint64_t;
using u32 = uint32_t;

struct u128 {
  static u128 multiply(u64 x, u64 y) {

    u64 high, low;
    __asm__("mulq %3\n\t" : "=d"(high), "=a"(low) : "%a"(x), "rm"(y) : "cc");
    return {high, low};

    uint64_t a = x & UINT32_MAX, b = x >> 32u, c = y & UINT32_MAX, d = y >> 32u,
             ac = a * c, bc = b * c, ad = a * d,
             z = (bc & UINT32_MAX) + (ad & UINT32_MAX) + (ac >> 32u);
    return {b * d + (bc >> 32u) + (ad >> 32u) + (z >> 32u),
            (z & UINT32_MAX) << 32u | (ac & UINT32_MAX)};

  }

  u64 high, low;
};

template <int RBIT, typename Digit, Digit M, typename Derived>
struct id4 {
  static const Digit MOD = M;

  static_assert(MOD <= std::numeric_limits<Digit>::max() >> 2,
                "4 * MOD <= MAX");

  explicit constexpr id4(Digit x = 0)
      : x(Derived::mont_multiply(x, R2)) {}

  constexpr Digit get() const {
    Digit y = Derived::reduce(x);
    if (y >= MOD) {
      y -= MOD;
    }
    return y;
  }

  constexpr id4 &operator+=(const id4 &other) {
    x += other.x;
    if (x >= MOD2) {
      x -= MOD2;
    }
    return *this;
  }

  constexpr id4 operator+(const id4 &other) const {
    id4 copy = *this;
    return copy += other;
  }

  constexpr id4 &operator-=(const id4 &other) {
    x += MOD2 - other.x;
    if (x >= MOD2) {
      x -= MOD2;
    }
    return *this;
  }

  constexpr id4 operator-() const {
    id4 copy{0};
    return copy -= *this;
  }

  constexpr id4 operator-(const id4 &other) const {
    id4 copy = *this;
    return copy -= other;
  }

  constexpr id4 operator*=(const id4 &other) {
    x = Derived::mont_multiply(x, other.x);
    return *this;
  }

  constexpr id4 operator*(const id4 &other) const {
    id4 copy = *this;
    return copy *= other;
  }

  constexpr id4 power(u64 n) const {
    return details::power<id4>(*this, n);
  }

  constexpr id4 inverse() const {
    return details::inverse<id4>(*this);
  }

private:
  static constexpr Digit rpower(int n) {
    Digit result = 1;
    for (int i = 0; i < n; ++i) {
      result += result;
      if (result >= MOD) {
        result -= MOD;
      }
    }
    return result;
  }

  static const Digit MOD2 = MOD << 1;
  static const Digit R = rpower(RBIT);
  static const Digit R2 = rpower(RBIT << 1);

  Digit x;
};

template <u32 MOD> struct Montgomery32Impl {
  static constexpr u32 mont_multiply(u32 x, u32 y) {
    return reduce(static_cast<u64>(x) * y);
  }

  static constexpr u32 reduce(u32 x) { return reduce(static_cast<u64>(x)); }

  static constexpr u64 reduce(u64 x) {
    u64 y = (((x & UINT32_MAX) * INV) & UINT32_MAX) * MOD;
    return (x + y) >> 32U;
  }

  static const u32 INV = details::id8<u32>(MOD, 5);
};

template <u64 MOD> struct Montgomery64Impl {
  static constexpr u64 mont_multiply(u64 x, u64 y) {
    return reduce(u128::multiply(x, y));
  }

  static constexpr u64 reduce(u64 x) { return reduce(u128{0, x}); }

  static constexpr u64 reduce(u128 x) {
    u128 y = u128::multiply(u128::multiply(x.low, INV).low, MOD);
    return x.high + y.high + (x.low > ~y.low);
  }

  static const u64 INV = details::id8<u64>(MOD, 6);
};

template <u32 MOD>
using Montgomery32T = id4<32, u32, MOD, Montgomery32Impl<MOD>>;

template <u64 MOD>
using Montgomery64T = id4<64, u64, MOD, Montgomery64Impl<MOD>>;

} 


template <int RBIT, typename Digit, Digit M, typename Derived>
std::ostream &
operator<<(std::ostream &out,
           const montgomery::id4<RBIT, Digit, M, Derived> &mod) {
  return out << mod.get();
}











namespace ntt {

template <typename ModT_> struct NTT {
  using Mod = ModT_;

  static void dit(int n, Mod *a) {
    id1(n);
    for (int m = 1; m < n; m <<= 1) {
      const Mod root = G.power((Mod::MOD - 1) / (m << 1));
      for (int i = 0; i < n; i += m << 1) {
        Mod twiddle(1);
        for (int r = i; r < i + m; ++r) {
          Mod tmp = twiddle * a[r + m];
          a[r + m] = a[r];
          a[r + m] -= tmp;
          a[r] += tmp;
          twiddle *= root;
        }
      }
    }
  }

  static void dif(int n, Mod *a) {
    id1(n);
    for (int m = n; m >>= 1;) {
      const Mod root = G.power(Mod::MOD - 1 - (Mod::MOD - 1) / (m << 1));
      for (int i = 0; i < n; i += m << 1) {
        Mod twiddle(1);
        for (int r = i; r < i + m; ++r) {
          Mod tmp = a[r];
          tmp -= a[r + m];
          a[r] += a[r + m];
          a[r + m] = twiddle * tmp;
          twiddle *= root;
        }
      }
    }
  }

  static Mod get_primitive_root() { return G; }

private:
  struct FiniteField {
    static constexpr Mod primitive_root() {
      int g = 2;
      while (!is_primitive_root(Mod(g))) {
        g++;
      }
      return Mod(g);
    }

  private:
    static constexpr bool is_primitive_root(Mod g) {
      for (int d = 2; d * d <= Mod::MOD - 1; ++d) {
        if ((Mod::MOD - 1) % d == 0 &&
            (g.power(d).get() == 1 || g.power((Mod::MOD - 1) / d).get() == 1)) {
          return false;
        }
      }
      return true;
    }
  };

  static constexpr Mod G = FiniteField::primitive_root();
};

} 








using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() { std::ios::sync_with_stdio(false); }

  template <typename T = int> T read() const {
    T v;
    std::cin >> v;
    return v;
  }

  template <typename T = int> std::vector<T> read_vector(size_t n) const {
    std::vector<T> v(n);
    for (size_t i = 0; i < n; ++i) {
      v[i] = read<T>();
    }
    return v;
  }
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;


using Mod = montgomery::Montgomery32T<998'244'353>;
using PolyFactory = ntt::id2<ntt::NTT<Mod>>;
using Poly = PolyFactory::Poly;

struct Node {
  Poly product, sum_Q, sum_C, result;
};

struct Solver {
  Solver(int id3, int s)
      : max_n(id3), factory(PolyFactory::create(max_n + max_n)),
        binom(max_n + std::max(s, 1)),
        tree(max_n + max_n + 1, Node{make(0), make(0), make(0), make(0)}) {
    prepare(0, max_n);
  }

  Node &prepare(int l, int id5) {
    Node &n = get_node(l, id5);
    int r = id5 + 1;
    if (l == id5) {
      

      Poly q_l = l ? make(std::vector<Mod>{Mod(l).inverse() - Mod(1),
                                           -Mod(l).inverse()})
                   : make(std::vector<Mod>{Mod{1}});
      n.product = q_l;
      n.sum_Q = shift(q_l, 1);
    } else {
      int id7 = (l + id5) >> 1;
      const Node &ln = prepare(l, id7);
      const Node &rn = prepare(id7 + 1, id5);
      int m = id7 + 1;
      n.product = ln.product * rn.product;
      n.sum_Q = shift(ln.sum_Q, r - m) + ln.product * rn.sum_Q;
    }
    return n;
  }

  Node &recur(const std::vector<Mod> &c, int l, int id5) {
    Node &n = get_node(l, id5);
    int r = id5 + 1;
    if (l == id5) {
      n.sum_C = make(std::vector<Mod>{c[l]});
      n.result = n.product * n.sum_C;
    } else {
      int id7 = (l + id5) >> 1;
      const Node &ln = recur(c, l, id7);
      const Node &rn = recur(c, id7 + 1, id5);
      int m = id7 + 1;
      n.sum_C = ln.sum_C + shift(rn.sum_C, m - l);
      n.result = ln.result + ln.sum_Q * rn.sum_C + ln.product * rn.result;
    }
    return n;
  }

  

  Poly taylor(int n, const Poly &f) {
    std::vector<Mod> g(n + 1), h(n + 1);
    for (int i = 0; i <= n; ++i) {
      g[i] = binom.fact[n - i] * f[i];
      h[i] = minus_one(i) * binom.inv_fact[i];
    }
    auto gh = make(g) * make(h);
    gh.resize(n + 1);
    for (int k = 0; k <= n; ++k) {
      gh[k] *= binom.inv_fact[n - k];
    }
    return gh;
  }

  

  Poly solve(int n) {
    std::vector<Mod> c = stirling(n);
    for (int i = 0; i <= n; ++i) {
      c[i] *= binom.fact[i];
    }
    c.resize(max_n + 1);
    Poly result = recur(c, 0, max_n).result;
    return taylor(n, result);
  }

  Poly solve() { return solve(max_n) + solve(max_n - 1); }

  

  std::vector<Mod> stirling(int n) const {
    std::vector<Mod> g(n + 1), h(n + 1);
    for (int i = 0; i <= n; ++i) {
      g[i] = minus_one(i) * binom.inv_fact[i];
      h[i] = Mod(i).power(n) * binom.inv_fact[i];
    }
    auto gh = make(g) * make(h);
    gh.resize(n + 1);
    return gh;
  }

  Node &get_node(int l, int r) { return tree[(l + r) | (l != r)]; }

  template <typename... Args> Poly make(Args &&...args) const {
    return factory->make(std::forward<Args...>(args...));
  }

  static Mod minus_one(int n) { return Mod((n & 1) ? Mod::MOD - 1 : 1); }

  

  Poly shift(const Poly &p, int k) {
    Poly np = make(p.deg() + k + 1);
    for (int i = 0; i <= p.deg(); ++i) {
      np[i + k] = p[i];
    }
    return np;
  }

  int max_n;
  PolyFactory::Ptr factory;
  Binom<Mod> binom;
  std::vector<Node> tree;
};

int main() {
  IO io;
  int n = io.read();
  int s = io.read();
  n -= s;
  Solver solver{n, s};
  Poly result_prime = solver.solve();
  Mod b = solver.binom(n + s - 1, s);
  for (int k = 0; k < n + s; ++k) {
    auto result = k < s ? Mod{0} : b * result_prime[n - 1 - (k - s)];
    std::cout << result << " \n"[k + 1 == n + s];
  }
}
