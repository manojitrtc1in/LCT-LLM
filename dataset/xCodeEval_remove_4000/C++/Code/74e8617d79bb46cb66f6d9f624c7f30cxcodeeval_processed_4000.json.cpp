
NDEBUG
























using namespace std;

template<class T>
using vec = std::vector<T>;

template<class T>
using vec2d = std::vector<std::vector<T>>;


template<class T>
vec2d<T> id1(const int n1) {
  return vec2d<T>(n1);
}


template<class T>
vec2d<T> id1(const int n1, const int n2, const T initValue) {
  return vec2d<T>(n1, vec<T>(n2, initValue));
}

















































































































































































































































































































































































































































































































































































































bool __hack = std::ios::sync_with_stdio(false);


auto id2 = cin.tie(nullptr);


















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
struct MinQueue {
  vec<T> a;
  vec<int> inds;
  int s, t;

  MinQueue(int n) {
    a = vec<T>(n);
    inds = vec<int>(n);
    s = t = 0;
  }

  T min() {
    if (s == t) {
      throw 42;
    }
    return a[s];
  }

  void push(int i, T val) {
    while (s < t && a[t - 1] >= val) {
      --t;
    }
    a[t] = val;
    inds[t] = i;
    ++t;
  }

  void pop(int i) {
    if (inds[s] == i) {
      ++s;
    }
  }
};


int64_t getSum(const vec2d<int64_t>& s, int x1, int y1, int x2, int y2) {
  ++x2;
  ++y2;
  return s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1];
}

vec2d<int> id0(const vec2d<int>& f, int a, int b) {
  int n = f.size(), m = f[0].size();
  auto res = id1<int>(n - a + 1,  m, 0);

  for (int j = 0; j < m; ++j) {
    MinQueue<int> q(n);
    FOR(i, a - 1) {
      q.push(i, f[i][j]);
    }
    for (int i = a - 1; i < n; ++i) {
      q.push(i, f[i][j]);
      res[i - a + 1][j] = q.min();
      q.pop(i - a + 1);
    }
  }

  for (int i = 0; i < n - a + 1; ++i) {
    vec<int> tmp(m - b + 1, 0);
    MinQueue<int> q(m);
    FOR(j, b - 1) {
      q.push(j, res[i][j]);
    }
    for (int j = b - 1; j < f[0].size(); ++j) {
      q.push(j, res[i][j]);
      tmp[j - b + 1] = q.min();
      q.pop(j - b + 1);
    }
    res[i] = tmp;
  }



























































  return res;
}

void solve(istream& in, ostream& out) {
  auto nRows = next<int>(in);
  auto nCols = next<int>(in);
  auto recRows = next<int>(in);
  auto recCols = next<int>(in);
  vec2d<int> f = id1<int>(nRows);
  FOR(i, nRows) {
    f[i] = next_vec<int>(in, nCols);
  }
  auto sum = id1<int64_t>(nRows + 1, nCols + 1, 0);
  FOR(i, nRows) {
    FOR(j, nCols) {
      sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + f[i][j];
    }
  }
  auto mins = id0(f, recRows, recCols);
  vec2d<int> used = id1<int>(nRows, nCols, 0);
  vec<pair<int64_t, pair<int, int>>> allVals;
  for (int i = 0, i2 = recRows - 1; i2 < nRows; ++i, ++i2) {
    for (int j = 0, j2 = recCols - 1; j2 < nCols; ++j, ++j2) {
      auto s = getSum(sum, i, j, i2, j2);
      int64_t mi = mins[i][j];
      s = s - mi * 1LL * (i2 - i + 1) * 1LL * (j2 - j + 1);
      allVals.push_back({s, {i, j}});
    }
  }
  sort(all(allVals));
  vec<tuple<int, int, int64_t>> result;
  for (auto& p : allVals) {
    int i = p.second.first, j = p.second.second;
    int i2 = p.second.first + recRows - 1;
    int j2 = p.second.second + recCols - 1;
    if (!used[i][j] && !used[i][j2] && !used[i2][j] && !used[i2][j2]) {
      result.push_back({i + 1, j + 1, p.first});
      for (int ti = i; ti <= i2; ++ti) {
        for (int tj = j; tj <= j2; ++tj) {
          used[ti][tj] = 1;
        }
      }
    }
  }
  out << result.size() << "\n";
  for (auto& t : result) {
    int x, y;
    int64_t r;
    tie(x, y, r) = t;
    out << x << " " << y << " " << r << "\n";
  }
}





int main() {




    solve(cin, cout);


    return 0;
}

