


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
    return k < 0 || k > n ? ModT(1) : fact[n] * inv_fact[n - k] * inv_fact[k];
  }

  std::vector<ModT> fact, inv_fact;
};






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

template <typename Digit> static constexpr Digit id6(Digit MOD, int n) {
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

  static const u32 INV = details::id6<u32>(MOD, 5);
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

  static const u64 INV = details::id6<u64>(MOD, 6);
};

template <u32 MOD>
using Montgomery32T = id4<32, u32, MOD, Montgomery32Impl<MOD>>;

template <u64 MOD>
using Montgomery64T = id4<64, u64, MOD, Montgomery64Impl<MOD>>;

} 











namespace ntt {

static void id1(int n) {
  if (n & (n - 1)) {
    throw std::invalid_argument(std::to_string(n) + " is not a power of two");
  }
}

template <typename ModT_> struct NTT {
  using ModT = ModT_;

  static void dit(int n, ModT *a) {
    id1(n);
    for (int m = 1; m < n; m <<= 1) {
      const ModT root = G.power((ModT::MOD - 1) / (m << 1));
      for (int i = 0; i < n; i += m << 1) {
        ModT twiddle(1);
        for (int r = i; r < i + m; ++r) {
          ModT tmp = twiddle * a[r + m];
          a[r + m] = a[r];
          a[r + m] -= tmp;
          a[r] += tmp;
          twiddle *= root;
        }
      }
    }
  }

  static void dif(int n, ModT *a) {
    id1(n);
    for (int m = n; m >>= 1;) {
      const ModT root = G.power(ModT::MOD - 1 - (ModT::MOD - 1) / (m << 1));
      for (int i = 0; i < n; i += m << 1) {
        ModT twiddle(1);
        for (int r = i; r < i + m; ++r) {
          ModT tmp = a[r];
          tmp -= a[r + m];
          a[r] += a[r + m];
          a[r + m] = twiddle * tmp;
          twiddle *= root;
        }
      }
    }
  }

private:
  struct FiniteField {
    static constexpr ModT primitive_root() {
      int g = 2;
      while (!is_primitive_root(ModT(g))) {
        g++;
      }
      return ModT(g);
    }

  private:
    static constexpr bool is_primitive_root(ModT g) {
      for (int d = 2; d * d <= ModT::MOD - 1; ++d) {
        if ((ModT::MOD - 1) % d == 0 &&
            (g.power(d).get() == 1 ||
             g.power((ModT::MOD - 1) / d).get() == 1)) {
          return false;
        }
      }
      return true;
    }
  };

  static constexpr ModT G = ModT(FiniteField::primitive_root());
};

static int id0(int n) { return 1 << (32 - __builtin_clz(n - 1)); }

template <typename NTT> class Poly {
private:
  using ModT = typename NTT::ModT;

public:
  Poly(int id3) : max_n(id3), inv(max_n) {
    inv[1] = ModT(1);
    for (int i = 2; i < max_n; ++i) {
      inv[i] = ModT(ModT::MOD - ModT::MOD / i) * inv[ModT::MOD % i];
    }
    for (int i = 0; i < 4; ++i) {
      buffer[i].resize(max_n);
    }
  }

  void multiply(std::vector<ModT> &out, const std::vector<ModT> &f,
                const std::vector<ModT> &g) {
    ModT *b0 = buffer[0].data();
    ModT *b1 = buffer[1].data();

    int id5 = f.size() + g.size() - 1;
    int n = id0(id5);
    assert_max_n(n);

    copy_and_fill0(n, b0, f.size(), f.data());
    NTT::dif(n, b0);
    copy_and_fill0(n, b1, g.size(), g.data());
    NTT::dif(n, b1);
    dot_product_and_dit(n, ModT(n).inverse(), b0, b0, b1);
    out.resize(id5);
    for (int i = 0; i < id5; ++i) {
      out[i] = b0[i];
    }
  }

  void inverse(int n, ModT *out, const ModT *f) {
    id1(n);
    assert_max_n(n);

    ModT *const b0 = buffer[0].data();
    ModT *const b1 = buffer[1].data();

    std::fill(out, out + n, ModT(0));
    out[0] = f[0].inverse();
    ModT inv_m(1);
    for (int m = 2; m <= n; m <<= 1) {
      copy_and_fill0(m, b0, n, f);
      NTT::dif(m, b0);
      std::copy(out, out + m, b1);
      NTT::dif(m, b1);
      inv_m *= ModT(2).inverse();
      dot_product_and_dit(m, inv_m, b0, b0, b1);
      std::fill(b0, b0 + (m >> 1), ModT(0));
      NTT::dif(m, b0);
      dot_product_and_dit(m, inv_m, b0, b0, b1);
      for (int i = m >> 1; i < m; ++i) {
        out[i] = ModT(0) - b0[i];
      }
    }
  }

  

  void divide(int n, ModT *out, const ModT *f, const ModT *g) {
    if (n == 1) {
      out[0] = f[0] * g[0].inverse();
    } else {
      id1(n);
      assert_max_n(n);

      ModT *const b0 = buffer[0].data();
      ModT *const b1 = buffer[1].data();
      ModT *const inv_g = buffer[2].data();

      int m = n >> 1;
      inverse(m, inv_g, g);
      std::fill(inv_g + m, inv_g + n, ModT(0));
      NTT::dif(n, inv_g);
      copy_and_fill0(n, b0, m, f);
      NTT::dif(n, b0);
      const ModT inv_n = ModT(n).inverse();
      dot_product_and_dit(n, inv_n, b0, b0, inv_g);

      std::copy(b0, b0 + m, out);

      std::fill(b0 + m, b0 + n, ModT(0));
      NTT::dif(n, b0);
      std::copy(g, g + n, b1);
      NTT::dif(n, b1);
      dot_product_and_dit(n, inv_n, b0, b0, b1);
      std::fill(b0, b0 + m, ModT(0));
      for (int i = m; i < n; ++i) {
        b0[i] -= f[i];
      }
      NTT::dif(n, b0);
      dot_product_and_dit(n, inv_n, b0, b0, inv_g);
      for (int i = m; i < n; ++i) {
        out[i] = ModT(0) - b0[i];
      }
    }
  }

  void log(int n, ModT *out, const ModT *f) {
    if (f[0].get() != 1) {
      throw std::invalid_argument("[x^0] f != 1");
    }
    id1(n);
    assert_max_n(n);
    

    ModT *const d_f = buffer[3].data();
    d_f[n - 1] = ModT(0);
    for (int i = 1; i < n; ++i) {
      d_f[i - 1] = ModT(i) * f[i];
    }
    divide(n, out, d_f, f);
    for (int i = n; i-- > 1;) {
      out[i] = out[i - 1] * inv[i];
    }
    out[0] = ModT(0);
  }

  void exp(int n, ModT *out, const ModT *f) {
    if (f[0].get() != 0) {
      throw std::invalid_argument("[x^0] f != 0");
    }
    if (n == 1) {
      out[0] = ModT(1);
    } else {
      id1(n);
      assert_max_n(n);

      ModT *const b0 = buffer[0].data();
      ModT *const b1 = buffer[1].data();
      ModT *const b2 = buffer[2].data();
      ModT *const b3 = buffer[3].data();

      out[0] = b1[0] = b1[1] = b2[0] = ModT(1);
      ModT inv_m(1);
      for (int m = 1; m < (n >> 1); m <<= 1) {
        const ModT id2 = inv_m * ModT(2).inverse();
        for (int i = 0; i < m; ++i) {
          b0[i] = ModT(i) * f[i];
        }
        NTT::dif(m, b0);
        dot_product_and_dit(m, inv_m, b0, b0, b1);
        for (int i = 0; i < m; ++i) {
          b0[i] -= ModT(i) * out[i];
        }
        std::fill(b0 + m, b0 + (m << 1), ModT(0));
        NTT::dif(m << 1, b0);
        copy_and_fill0(m << 1, b3, m, b2);
        NTT::dif(m << 1, b3);
        dot_product_and_dit(m << 1, id2, b0, b0, b3);
        for (int i = 0; i < m; ++i) {
          b0[i] = b0[i] * inv[m + i] + f[m + i];
        }
        std::fill(b0 + m, b0 + (m << 1), ModT(0));
        NTT::dif(m << 1, b0);
        dot_product_and_dit(m << 1, id2, b0, b0, b1);
        std::copy(b0, b0 + m, out + m);
        copy_and_fill0(m << 2, b1, m << 1, out);
        NTT::dif(m << 2, b1);
        dot_product_and_dit(m << 1, id2, b0, b1, b3);
        std::fill(b0, b0 + m, ModT(0));
        NTT::dif(m << 1, b0);
        dot_product_and_dit(m << 1, id2, b0, b0, b3);
        for (int i = m; i < m << 1; ++i) {
          b2[i] = ModT(0) - b0[i];
        }
        inv_m = id2;
      }
      const int m = n >> 1;
      for (int i = 0; i < m; ++i) {
        b0[i] = ModT(i) * f[i];
      }
      NTT::dif(m, b0);
      dot_product_and_dit(m, inv_m, b0, b0, b1);
      for (int i = 0; i < m; ++i) {
        b0[i] -= ModT(i) * out[i];
      }
      copy_and_fill0(m, b0 + m, m >> 1, b0 + (m >> 1));
      std::fill(b0 + (m >> 1), b0 + m, ModT(0));
      NTT::dif(m, b0);
      NTT::dif(m, b0 + m);
      copy_and_fill0(m, b3 + m, m >> 1, b2 + (m >> 1));
      NTT::dif(m, b3 + m);
      for (int i = 0; i < m; ++i) {
        b0[m + i] = inv_m * (b0[i] * b3[m + i] + b0[m + i] * b3[i]);
      }
      dot_product_and_dit(m, inv_m, b0, b0, b3);
      NTT::dit(m, b0 + m);
      for (int i = 0; i < m >> 1; ++i) {
        b0[(m >> 1) + i] += b0[m + i];
      }
      for (int i = 0; i < m; ++i) {
        b0[i] = b0[i] * inv[m + i] + f[m + i];
      }
      std::fill(b0 + m, b0 + (m << 1), ModT(0));
      NTT::dif(m << 1, b0);
      const ModT id2 = inv_m * ModT(2).inverse();
      dot_product_and_dit(m << 1, id2, b0, b0, b1);
      std::copy(b0, b0 + m, out + m);
    }
  }

private:
  static void copy_and_fill0(int n, ModT *dst, int m, const ModT *src) {
    m = std::min(n, m);
    std::copy(src, src + m, dst);
    std::fill(dst + m, dst + n, ModT(0));
  }

  static void dot_product_and_dit(int n, ModT inv_n, ModT *out, const ModT *a,
                                  const ModT *b) {
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

  int max_n;
  std::vector<ModT> inv;
  std::array<std::vector<ModT>, 4> buffer;
};

} 





using ModT = montgomery::Montgomery32T<998'244'353>;

using NTT = ntt::NTT<ModT>;

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> deg(n, -1);
  deg[0] = 0;
  for (int i = 0, a, b; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    deg[a]++;
    deg[b]++;
  }
  std::vector<int> cnt(n);
  for (int i = 0; i < n; ++i) {
    cnt[deg[i]]++;
  }
  Binom<ModT> binom(n + 1);
  ntt::Poly<NTT> poly(ntt::id0(n));
  std::vector<ModT> product{ModT(1)};
  for (int i = n; i-- > 1;) {
    if (cnt[i] > 0) {
      std::vector<ModT> multiplier(cnt[i] + 1);
      

      multiplier[0] = ModT(1);
      ModT mod_i(i);
      ModT pow(1);
      for (int j = 1; j <= cnt[i]; ++j) {
        pow *= mod_i;
        multiplier[j] = binom(cnt[i], j) * pow;
      }
      poly.multiply(product, product, multiplier);
    }
  }
  ModT result(0);
  for (int i = 0; i < static_cast<int>(product.size()); ++i) {
    const ModT tmp = product[i] * binom.fact[n - i];
    if (i & 1) {
      result -= tmp;
    } else {
      result += tmp;
    }
  }
  std::cout << result.get() << std::endl;
}