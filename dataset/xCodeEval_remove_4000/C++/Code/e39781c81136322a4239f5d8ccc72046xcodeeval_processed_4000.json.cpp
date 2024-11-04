
NDEBUG
























using namespace std;

template<class T>
using vec = std::vector<T>;

















































































































































































































































































































































































































































































































































































































bool __hack = std::ios::sync_with_stdio(false);


auto id1 = cin.tie(nullptr);


















namespace template_util {
    

    constexpr int bytecount(uint64_t x) {
        return x ? 1 + bytecount(x >> 8) : 0;
    }

    template<int N>
    struct bytetype {
        
    };

    
    

    template<uint64_t N>
    struct minimal_uint : bytetype<bytecount(N)> {
    };
}


template<class T>
T next(istream& in) {
    T ret;
    in >> ret;
    return ret;
}

template<class T>
vector<T> next_vec(istream& in, size_t n) {
  vector<T> ret(n);
  for (size_t i = 0; i < n; ++i) {
    ret[i] = next<T>(in);
  }
  return ret;
}


template<typename T> static constexpr T wrap_pos(T a, T m) { return a < 0 ? a + m : a; }



template<typename T> static constexpr T mod(T a, T m) { return wrap_pos(a % m, m); }

template<typename T>
static constexpr T inverse2(T a, T m) { return a <= 1 ? a : mod((1 - inverse2(m % a, a) * m) / a, m); }

template<typename T>
static constexpr T inverse(T a, T m) { return inverse2(mod(a, m), m); }

template<typename T, typename C, T Modulus>
class MR
{
 private:
  struct tag_plus {}; 

  struct tag_minus {}; 

  struct tag_good {}; 





  static_assert(std::numeric_limits<C>::max() / Modulus / Modulus > 0, "compute type is too small");
  static_assert(Modulus < std::numeric_limits<T>::max() / 2, "storage type is too small");

  static constexpr T reduce(T value, tag_plus)
  {
    return value >= Modulus ? value - Modulus : value;
  }

  static constexpr T reduce(T value, tag_minus)
  {
    return value < 0 ? value + Modulus : value;
  }

  static constexpr T reduce(T value, tag_good) { return value; }

 public:
  T value;
  
  
  constexpr MR() : value(0) {}
  constexpr MR(C value) : value(reduce(value % Modulus, tag_minus())) {}
  template<typename tag_t>
  constexpr MR(T value, tag_t tag) : value(reduce(value, tag)) {}

  
  constexpr MR operator +(MR b) const { return MR(value + b.value, tag_plus()); }
  
  constexpr MR operator *(MR b) const { return MR(C(value) * C(b.value) % Modulus, tag_good()); }
  

  MR &operator *=(MR b) { value = C(value) * C(b.value) % Modulus; return *this; }

  
  constexpr T get() const { return value; }

  

  constexpr MR inverse() const
  {
    return MR(::inverse(C(value), C(Modulus)), tag_good());
  }
  constexpr MR operator /(MR b) const { return *this * b.inverse(); }
  
};

template<typename T, typename C, T Modulus>
static inline std::ostream &operator<<(std::ostream &o, MR<T, C, Modulus> mr)
{
  return o << mr.get();
}


















template<class T>
vector<T> id2(int n) {
  vector<T> res(n);
  res[0] = T(1);
  for (int i = 1; i < n; ++i) {
    res[i] = res[i-1] * i;
  }
  return res;
}






template<class T, class P>
T pow(T x, P p) {
    T res = 1;
    for (P i = p; i > 0; i >>= 1) {
        if (i & 1) {
            res *= x;
        }
        x *= x;
    }
    return res;
}










































typedef MR<int, int64_t, 1000000007> md;
const int MAXN = 5000004;

vec<md> fs = id2<md>(MAXN);


md C(int n, int k) {
  return fs[n] / fs[k] / fs[n - k];
}


































md process(int left, int right, const vec<pair<int, int>>& ps, int t, int n) {


  md res = 1;
  FOR(i, ps.size()) {
    int curTime = ps[i].first - t - 1;
    t = ps[i].first;
    int pos = ps[i].second;
    if (pos < left) {
      int id3 = left - pos - 1;
      if (id3 > curTime) {
        return 0;
      }
      res *= C(curTime, id3);


      left = pos;
      right += curTime - id3;
    } else if (pos > right) {
      int id0 = pos - right - 1;
      if (id0 > curTime) {
        return 0;
      }
      res *= C(curTime, id0);


      right = pos;
      left -= (curTime - id0);
    } else {
      return 0;
    }
    if (left < 0 || right >= n) {
      return 0;
    }
  }

  int restLeft = left;
  int restTotal = restLeft + (n - 1 - right);
  res = res * C(restTotal, restLeft);


  return res;
}

void solve(istream& in, ostream& out) {
  auto n = next<int>(in);
  auto a = next_vec<int>(in, n);

  bool all0 = all_of(all(a), [] (int x) { return x == 0; });
  if (all0) {
    

    out << pow(md(2), n - 1) << "\n";
    return;
  }

  vec<pair<int, int>> ps;
  FOR(i, n) {
    if (a[i]) {
      ps.push_back({a[i], i});
    }
  }
  

  sort(all(ps));
  md res = 0;
  auto f = ps[0];

  ps.erase(ps.begin());
  md add = 1;
  if (f.first - 1 >= 1) {
    add = pow(md(2), f.first - 2);


  }
  if (f.second - (f.first - 1) >= 0) {
    res = res + (process(f.second - (f.first - 1), f.second, ps, f.first, n) * add);
  }
  if (f.first > 1 && f.second + (f.first - 1) < n) {
    res = res + (process(f.second, f.second + (f.first - 1), ps, f.first, n) * add);
  }


  out << res << "\n";
}





int main() {




    solve(cin, cout);


    return 0;
}

