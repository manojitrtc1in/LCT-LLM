





NDEBUG
























using namespace std;

template<class T>
using vec = std::vector<T>;

template<class T>
using vec2d = std::vector<std::vector<T>>;


template<class T>
vec2d<T> id0(const int n1, const int n2, const T initValue) {
  return vec2d<T>(n1, vec<T>(n2, initValue));
}








typedef int64_t i64;
typedef uint64_t ui64;






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


int ni(istream& in) {
  int ret;
  in >> ret;
  return ret;
}





template<typename T> static constexpr T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }



































































template <class T>
struct Point {
    T x, y;
    Point() : x(0), y(0) {}
    Point(const T& x, const T& y) : x(x), y(y) {}
    

};


template <class T> inline Point<T> makePoint(const T& x, const T& y) {
    return Point<T>(x, y);
}





FF2(operator -, Point<T1>& p1, Point<T2>& p2, makePoint(p1.x - p2.x, p1.y - p2.y))


FF2(operator ^, Point<T1>& p1, Point<T2>& p2, p1.x * p2.y - p1.y * p2.x)


FF2(crossProduct, Point<T1>& p1, Point<T2>& p2, p1 ^ p2)
























































































































































struct Fraction {
  i64 a, b;

  
  explicit Fraction(i64 x) : a(x), b(1) {}

  explicit Fraction(i64 a, i64 b) : a(a), b(b) {
    normalizeDenom();
    reduce();
  }

  void reduce() {
    i64 g = gcd(::abs(a), b);
    a /= g;
    b /= g;
  }

  void normalizeDenom() {
    assert(b != 0);
    if (b < 0) {
      a = -a;
      b = -b;
    }
  }

  
  static int cp(const Fraction& f1, const Fraction& f2) {
    ui64 val = (ui64)f1.a * f2.b - (ui64)f2.a * f1.b;
    if (val == 0) return 0;
    return (val >> 63 ? -1 : 1);
  }

  
  friend Fraction operator-(const Fraction& f1, const Fraction& f2) {
    return Fraction(f1.a * f2.b - f2.a * f1.b, f1.b * f2.b);
  }

  
  bool operator>(const Fraction& other) const { return cp(*this, other) > 0; }
  
  
  double toDouble() const {
    return double(a) / double(b);
  }

  
};

typedef Point<i64> Pnt;

Fraction getProj(const Pnt& p, const Pnt& v) {
  return Fraction(p.x * v.y - p.y * v.x, v.y);
}

struct Event {
  int type;
  int i1, i2;
  Pnt v;

  Event(int t, int i1, int i2, const Pnt& v) : type(t), i1(i1), i2(i2), v(v) {}


  bool operator<(const Event& e) const {
    i64 cp = crossProduct(v, e.v);
    if (cp != 0) {
      return cp > 0;
    }
    if (type != e.type) {
      return type < e.type;
    }
    return make_pair(i1, i2) < make_pair(e.i1, e.i2);
  }

};

vec2d<int8_t> g;

void solve(istream& in, ostream& out) {
  auto n = ni(in);
  vec<pair<int, int>> xs(n);
  vec<int> y(n);
  vec<Pnt> pl(n), pr(n);
  vec<int> ids(n);
  FOR(i, n) {
    ids[i] = i;
    auto xl = ni(in);
    auto xr = ni(in);
    xs[i] = {xl, xr};
    y[i] = ni(in);
    pl[i] = Pnt(xl, y[i]);
    pr[i] = Pnt(xr, y[i]);

    dbg("Segment", pl[i], pr[i]);
  }
  sort(all(ids), [&] (int i1, int i2) -> bool {
    if (y[i1] == y[i2]) {
      return xs[i1] < xs[i2];
    }
    return y[i1] > y[i2];
  });
  vec<int> posIds(n);
  FOR(i, n) {
    posIds[ids[i]] = i;
  }
  vec<Event> ev;
  FOR(i, n) {
    FOR(j, n) {
      if (y[i] < y[j]) {
        Pnt v1 = pl[i] - pr[j];
        Pnt v2 = pr[i] - pl[j];
        ev.push_back(Event(1, i, j, v1));
        ev.push_back(Event(0, i, j, v2));
      }
    }
  }
  if (ev.empty()) {
    double res = xs[ids[n-1]].second - xs[ids[0]].first;
    out << fixed << setprecision(15) << res << "\n";
    return;
  }
  Fraction res(-1);
  sort(all(ev));

  FOR(i, ev.size()) {
    dbg("ev", ev[i].type, ev[i].i1, ev[i].i2, ev[i].v);
  }

  int cnt = 0;

  g = id0<int8_t>(n, n, 0);
  FOR(i, n) {
    FOR(j, n) {
      if (posIds[i] < posIds[j]) {
        g[j][i] = 1;
      }
    }
  }

  struct compare {
    bool operator() (const int& l, const int& r) const {
      if (g[r][l]) {
        return true;
      }
      return false;
    }
  };
  set<int, compare> Q;
  FOR(i, n) {
    Q.insert(i);
  }
  vec<int> toInsert;

  auto relax = [&] (const Pnt& v) {
    while (!toInsert.empty()) {
      Q.insert(toInsert.back());
      toInsert.pop_back();
    }
    int mi = *Q.begin();
    int ma = *Q.rbegin();
    Pnt leftMost = pl[mi];
    Pnt rightMost = pr[ma];
    auto le = getProj(leftMost, v);
    auto ri = getProj(rightMost, v);

    auto d = ri - le;
    if (res.a == -1) {
      res = d;
    } else if (res > d) {
      res = d;
    }
  };


  for (const auto& e : ev) {
    if (e.type == 0) {
      swap(g[e.i1][e.i2], g[e.i2][e.i1]);
      --cnt;
      if (cnt == 0) {
        relax(e.v);
      }
    } else {
      if (cnt == 0) relax(e.v);
      ++cnt;

      if (Q.count(e.i1)) {
        toInsert.push_back(e.i1);
        Q.erase(e.i1);
      }
      if (Q.count(e.i2)) {
        toInsert.push_back(e.i2);
        Q.erase(e.i2);
      }
    }
  }
  out << fixed << setprecision(15) << res.toDouble() << "\n";
}





int main() {




    solve(cin, cout);


    return 0;
}

