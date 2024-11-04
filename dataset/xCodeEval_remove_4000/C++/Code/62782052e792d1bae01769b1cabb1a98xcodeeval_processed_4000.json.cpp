
NDEBUG
























using namespace std;

template<class T>
using vec = std::vector<T>;

















































































































































































































































































































































































































































































































































































































bool __hack = std::ios::sync_with_stdio(false);


auto id0 = cin.tie(nullptr);


















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


template<class T>
void outVec(ostream& out, const vector<T>& v) {
  out << v[0];
  for (size_t i = 1; i < v.size(); ++i) {
    out << ' ' << v[i];
  }
  out << "\n";
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

  MR &operator=(C value) { this->value = reduce(value % Modulus, tag_minus()); return *this; }

  constexpr MR operator +(MR b) const { return MR(value + b.value, tag_plus()); }
  
  constexpr MR operator *(MR b) const { return MR(C(value) * C(b.value) % Modulus, tag_good()); }
  

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
vector<T> id1(int n) {
  vector<T> res(n);
  res[0] = T(1);
  for (int i = 1; i < n; ++i) {
    res[i] = res[i-1] * i;
  }
  return res;
}














































typedef MR<int, int64_t, 1000000007> md;




void solve(istream& in, ostream& out) {



  auto n = next<int>(in);
  auto k = next<int>(in);
  auto a = next_vec<int>(in, n);
  if (k == 0) {
    outVec(out, a);
    return;
  }


  


  vec<md> f = id1<md>(n + 1);










  vec<md> ki(n + 1);
  --k;
  ki[1] = md(k + 1);
  for (int i = 2; i <= n; ++i) {
    ki[i] = ki[i-1] * md(k + i);
  }
  auto C2 = [&] (int i) -> md {
    return ki[i] / f[i];
  };

  vec<md> cRow(n);
  cRow[0] = 1;
  for (int i = 1; i < n; ++i) {
    cRow[i] = C2(i);
  }
  reverse(all(cRow));
  dbg(cRow);
  vec<md> res;
  FOR(i, n) {
    md cur = 0;
    FOR(j, n) {
      cur = cur + md(a[j]) * cRow[j];
    }
    res.push_back(cur);
    cRow.push_back(0);
    cRow.erase(cRow.begin());


  }
  reverse(all(res));
  for (auto i : res) {
    out << i << ' ';
  }
  out << "\n";
}







int main() {




    solve(cin, cout);


    return 0;
}

