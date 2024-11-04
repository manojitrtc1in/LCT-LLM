
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






































































template <class T>
struct Point {
    T x, y;
    
    Point(const T& x, const T& y) : x(x), y(y) {}
    

    void swap(Point& other) {
        ::swap(x, other.x);
        ::swap(y, other.y);
    }

    
};


template <class T> void swap(Point<T>& p1, Point<T>& p2) {
    p1.swap(p2);
}





















































































































































typedef Point<i64> Pnt;

const i64 MOD = (i64) 1e9 + 7;
const i64 INF = numeric_limits<i64>::max() / 4;

int getChange(const Pnt& v1, const Pnt& v2) {
  i64 x = (v2.y - v1.y) / (v1.x - v2.x);
  if (x < 0) return 0;
  if (x >= 1000000001) return 1000000001;
  return (int)x;
}

i64 getSum(const Pnt& v, int from, int to) {
  i64 d = to - from + 1;
  i64 res = (v.y * d) % MOD;
  if (res < 0) res += MOD;

  i64 cur = (from + to) * d / 2;
  cur %= MOD;
  cur *= v.x;
  cur %= MOD;
  res += cur;
  if (res >= MOD) res -= MOD;
  return res;
}

bool id2(const Pnt& v1, const Pnt& v2, const Pnt& v3) {
  i64 X = (v2.y - v1.y) / (v1.x - v2.x) + 1;
  if (v2.x * X + v2.y <= v3.x * X + v3.y) {
    return true;
  }
  return false;
}

void solve(istream& in, ostream& out) {
  

  

  

  

  


  auto n = next<int>(in);
  auto m = next<int>(in);
  auto q = next<int>(in);

  vec2d<pair<int, i64>> g(n);
  vec<i64> weightMax(n, 0);
  FOR(i, m) {
    auto a = next<int>(in) - 1;
    auto b = next<int>(in) - 1;
    auto w = next<i64>(in);
    g[a].push_back({b, w});
    g[b].push_back({a, w});
    weightMax[a] = max(weightMax[a], w);
    weightMax[b] = max(weightMax[b], w);
  }

  vec2d<i64> dst = id0<i64>(n, m + 1, -INF);
  dst[0][0] = 0;
  FORA(i, 1, m + 1) {
    FOR(v, n) {
      if (dst[v][i-1] < 0) continue;
      for (auto top : g[v]) {
        auto to = top.first;
        auto w = top.second;
        dst[to][i] = max(dst[to][i], dst[v][i-1] + w);
      }
    }
  }
  i64 res = 0;
  FOR(d, m + 1) {
    i64 best = 0;
    FOR(i, n) {
      if (dst[i][d] < 0) continue;
      best = max(best, dst[i][d]);
    }
    res += best;
    while (res >= MOD) res -= MOD;
  }
  vec<Pnt> points;
  FOR(i, n) {
    if (dst[i][m] >= 0) {
      points.push_back(Pnt(weightMax[i], dst[i][m] - m * weightMax[i]));
    }
  }
  sort(all(points), [](const Pnt& a, const Pnt& b) -> bool {
    return a.x < b.x || (a.x == b.x && a.y < b.y);

  });
  dbg(points);
  vec<Pnt> convex;
  FOR(i, points.size()) {
    Pnt v = points[i];
    if (convex.empty()) {
      convex.push_back(v);
      continue;
    }
    if (convex.back().x == v.x) {
      if (convex.back().y < v.y) {
        convex.back() = v;
      }
      continue;
    }
    while (convex.size() >= 2) {
      Pnt v1 = convex.end()[-2];
      Pnt v2 = convex.end()[-1];
      if (id2(v1, v2, v)) {
        convex.pop_back();
      } else {
        break;
      }
    }
    convex.push_back(v);
  }
  dbg(convex);
  points = convex;
  int from = m + 1;
  int ptr = 0;



































  while (from <= q) {

    int upTo = q;



    if (ptr + 1 < points.size()) {
      if (points[ptr].x == points[ptr + 1].x) {
        ++ptr;
        continue;
      }
    }

    FORA(i, ptr + 1, points.size()) {
      int ch = getChange(points[ptr], points[i]);
      if (upTo > ch) {
        upTo = ch;


      }
      upTo = min(upTo, ch);
    }















    if (upTo < from) {
      ++ptr;
      continue;
    }

    res += getSum(points[ptr], from, upTo);
    if (res >= MOD) res -= MOD;
    from = upTo + 1;
    ++ptr;
  }

  out << res << "\n";
}





int main() {




    solve(cin, cout);


    return 0;
}

