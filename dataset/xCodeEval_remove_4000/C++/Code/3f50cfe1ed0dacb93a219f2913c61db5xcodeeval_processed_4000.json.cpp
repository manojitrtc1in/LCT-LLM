














using namespace std;






using ll = long long;
using ld = long double;



template<typename T>
using vec = std::vector<T>;

template<typename T>
using uset = std::unordered_set<T>;

template<typename T1, typename T2>
using umap = std::unordered_map<T1, T2>;

constexpr ll INFL = 1'000'000'000'000'000'228;
constexpr int INFI = 1'000'000'228;
const ld PI = acos(-1);
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

vec<pair<int, int>> DD = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

constexpr long double EPS = 1e-5;

using FET = double;

struct id0 {
  FET val;
  explicit id0(FET val) : val(val) {}
  id0() : val(0) {}
  operator FET() const {
    return val;
  }
  inline id0& operator+=(id0 oth) {
    val += oth.val;
    return *this;
  }
  inline id0& operator-=(id0 oth) {
    val -= oth.val;
    return *this;
  }
  inline id0& operator*=(id0 oth) {
    val *= oth.val;
    return *this;
  }
  inline id0 &operator/=(id0 oth) {
    val /= oth.val;
    return *this;
  }
};

inline id0 operator+(id0 a, id0 b) {
  return a += b;
}


inline id0 operator-(id0 a, id0 b) {
  return a -= b;
}


inline id0 operator*(id0 a, id0 b) {
  return a *= b;
}


inline id0 operator/(id0 a, id0 b) {
  return a /= b;
}

inline id0 operator-(id0 a) {
  return id0(-a.val);
}

inline bool operator==(id0 a, id0 b) {
  return fabs(a.val - b.val) <= EPS;
}


inline bool operator!=(id0 a, id0 b) {
  return fabs(a.val - b.val) > EPS;
}


inline bool operator<(id0 a, id0 b) {
  return b.val - a.val > EPS;
}


inline bool operator>(id0 a, id0 b) {
  return a.val - b.val > EPS;
}


inline bool operator<=(id0 a, id0 b) {
  return a < b || a == b;
}


inline bool operator>=(id0 a, id0 b) {
  return a > b || a == b;
}

using ldp = id0;





struct Pt {
  ldp x, y;
  Pt(ldp xx, ldp yy)
  : x(xx), y(yy)
  {}
  Pt() : Pt(ldp(0), ldp(0)) {}
};

Pt operator+(Pt a, Pt b) {
  return Pt(a.x + b.x, a.y - b.y);
}

Pt operator-(Pt a, Pt b) {
  return Pt(a.x - b.x, a.y - b.y);
}

ldp operator*(Pt a, Pt b) {
  return a.x * b.y - a.y * b.x;
}

ldp operator%(Pt a, Pt b) {
  return a.x * b.x + a.y * b.y;
}

struct Seg {
  Pt p, q;
  Seg(Pt p, Pt q) : p(p), q(q) {}
  Seg() : Seg(Pt(), Pt()) {}
};

struct Line {
  ldp A, B, C;
  Line(ldp a, ldp b, ldp c)
  : A(a), B(b), C(c) {}
  Line() : Line(ldp(0), ldp(0), ldp(0)) {}
  explicit Line(Seg s) {
    A = s.p.y - s.q.y;
    B = s.q.x - s.p.x;
    C = -(A * s.p.x) - B * s.p.y;
  }
  pair<ldp, ldp> norm() {
    if (B == ldp(0)) {
      return {ldp(0), ldp(0)};
    }
    return {-(A/B), -(C/B)};
  }
};

Pt inter(Line ln1, Line ln2) {
  ldp x = -(ln1.C * ln2.B - ln2.C * ln1.B) / (ln1.A * ln2.B - ln2.A * ln1.B);
  ldp y = -(ln1.A * ln2.C - ln2.A * ln1.C) / (ln1.A * ln2.B - ln2.A * ln1.B);
  return Pt(x, y);
}

bool id2(Seg s, Pt p) {
  return (s.p % (s.q - p)) >= ldp(0);
}

bool pon(Seg s, Pt p) {
  return id2(s, p) && id2(Seg(s.q, s.p), p);
}

bool is_inter(Line ln, Seg s) {
  Pt p = inter(ln, Line(s));
  return pon(s, p);
}

struct Event {
  // Vertical line
  bool vert;
  int x;
  int id;
  // Segment
  ldp x1, x2;
  ldp xs, xf;
  ldp k;
  ldp b;
  ldp coef;
  bool end;
  ldp integral(ldp xx) {
    return k * xx * xx / ldp(2) + b * xx;
  }
  ldp calc_area() {
    ldp xx1 = integral(x1);
    ldp xx2 = integral(x2);
    xx1 -= xx2;
    return xx1 * coef;
  }
  Event(bool vert) : vert(vert), end(false) {}
};

const int MAXN = 1e5 + 10;

void run() {
  int n, q;
  cin >> n >> q;
  vec<Pt> poly(n);
  vector<int> ys;
  int mny = INFI, mxy = -INFI;
  int mnx = INFI;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    mny = min(y, mny);
    mxy = max(y, mxy);
    mnx = min(x, mnx);
    ys.push_back(y);
    poly[i] = Pt(ldp(x), ldp(y));
  }
  for (int i = 0; i < n; i++) {
    poly[i].x.val -= mnx;
    poly[i].y.val -= mny;
    ys[i] -= mny;
  }
  sort(ALL(ys));
  ys.resize(unique(ALL(ys)) - ys.begin());
  vec<Pt> left, right;
  // Making left and right hulls
  {
    bool found = false;
    vec<Pt> *cur = &right;
    int i = 0;
    while (left.size() + right.size() <= n) {
      if (int(poly[i].y.val) == 0) {
        found = true;
      }
      if (found) {
        cur->push_back(poly[i]);
      }
      if (found && int(poly[i].y.val) == mxy - mny) {
        cur = &left;
        cur->push_back(poly[i]);
      }
      i++;
      i %= n;
    }
    left.push_back(right.front());
    if ((right[right.size() - 2] - right[right.size() - 1]) * (left[0] - left[1]) < ldp(0)) {
      swap(left, right);
      reverse(ALL(left));
      reverse(ALL(right));
    }
    reverse(ALL(left));
  }
  // Dividing segments
  auto divide = [&](vec<Pt> &p) {
    vec<Pt> new_p;
    new_p.push_back(p[0]);
    for (int i = 0; i < p.size() - 1; i++) {
      int beg_y = p[i].y.val;
      int nd_y = p[i + 1].y.val;
      for (auto it = upper_bound(ALL(ys), beg_y); it != ys.end() && *it < nd_y; it++) {
        Line ln(Seg(Pt(ldp(0), ldp(*it)), Pt(ldp(1), ldp(*it))));
        new_p.push_back(inter(ln, Line(Seg(p[i], p[i + 1]))));
      }
      new_p.push_back(p[i + 1]);
    }
    return new_p;
  };
  left = divide(left);
  right = divide(right);
  // Making midline
  assert(left.size() == right.size());
  vec<Pt> midline;
  for (int i = 0; i < left.size(); i++) {
    midline.emplace_back((left[i].x + right[i].x) / ldp(2), left[i].y);
  }
  // Making 2 polygons
  vec<Pt> minus = midline, plus = right;
  for (int i = midline.size() - 2; i >= 1; i--) {
    minus.push_back(left[i]);
    plus.push_back(midline[i]);
  }
  // Making sweep line
  vec<Event> id1;
  auto add_vert = [&](int x, int id) {
    id1.push_back(Event(true));
    id1.back().x = x;
    id1.back().id = id;
  };
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    x -= mnx;
    add_vert(x, i);
  }
  auto add_seg = [&](Seg s, ldp coef) {
    auto [k, b] = Line(s).norm();
    id1.push_back(Event(false));
    id1.back().x1 = s.p.x;
    id1.back().x2 = s.q.x;
    id1.back().xs = min(s.p.x, s.q.x);
    id1.back().xf = max(s.p.x, s.q.x);
    id1.back().k = k;
    id1.back().b = b;
    id1.back().coef = coef;
    id1.back().end = false;
    id1.push_back(Event(false));
    id1.back().x1 = s.p.x;
    id1.back().x2 = s.q.x;
    id1.back().xs = min(s.p.x, s.q.x);
    id1.back().xf = max(s.p.x, s.q.x);
    id1.back().k = k;
    id1.back().b = b;
    id1.back().coef = coef;
    id1.back().end = true;
  };
  ldp total_area = ldp(0);
  for (int i = 0; i < minus.size() - 1; i++) {
    add_seg(Seg(minus[i], minus[i + 1]), ldp(-1));
    total_area += minus[i] * minus[i + 1];
  }
  total_area += minus.back() * minus.front();
  add_seg(Seg(minus.back(), minus.front()), ldp(-1));
  for (int i = 0; i < plus.size() - 1; i++) {
    add_seg(Seg(plus[i], plus[i + 1]), ldp(1));
    total_area += plus[i] * plus[i + 1];
  }
  total_area += plus.back() * plus.front();
  add_seg(Seg(plus.back(), plus.front()), ldp(1));
  total_area /= ldp(2);
  vec<ldp> ans(q);
  ldp area = total_area;
  ldp sum_k, sum_b;
  ldp left_rm;
  sort(ALL(id1), [](const auto &ev1, const auto &ev2) {
    ldp x1 = (ev1.vert ? ldp(ev1.x) : (!ev1.end ? ev1.xs : ev1.xf));
    ldp x2 = (ev2.vert ? ldp(ev2.x) : (!ev2.end ? ev2.xs : ev2.xf));
    if (ev1.vert && ev2.vert) {
      return ev1.x < ev2.x;
    }
    if (ev1.vert && x1 == x2) {
      return false;
    }
    if (ev2.vert && x1 == x2) {
      return true;
    }
    return x1 < x2;
  });
  for (auto ev : id1) {
    if (ev.vert) {
      ans[ev.id] = area;
      ans[ev.id] += (sum_k * ldp(ev.x * ev.x)) / ldp(2) + sum_b * ldp(ev.x);
      ans[ev.id] -= left_rm;
    } else {
      if (!ev.end) {
        if (ev.x1 > ev.x2) {
          sum_k += ev.k * ev.coef;
          sum_b += ev.b * ev.coef;
          left_rm += ((ev.k * ldp(ev.xs * ev.xs)) / ldp(2) + ev.b * ldp(ev.xs)) * ev.coef;
        } else {
          sum_k -= ev.k * ev.coef;
          sum_b -= ev.b * ev.coef;
          left_rm -= ((ev.k * ldp(ev.xs * ev.xs)) / ldp(2) + ev.b * ldp(ev.xs)) * ev.coef;
        }
      } else {
        area += ev.calc_area();
        if (ev.x1 > ev.x2) {
          sum_k -= ev.k * ev.coef;
          sum_b -= ev.b * ev.coef;
          left_rm -= ((ev.k * ldp(ev.xs * ev.xs)) / ldp(2) + ev.b * ldp(ev.xs)) * ev.coef;
        } else {
          sum_k += ev.k * ev.coef;
          sum_b += ev.b * ev.coef;
          left_rm += ((ev.k * ldp(ev.xs * ev.xs)) / ldp(2) + ev.b * ldp(ev.xs)) * ev.coef;
        }
      }
    }
  }
  for (auto el : ans) {
    cout << el.val << '\n';
  }
}

signed main() {

  std::freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t = 1;
  

  cout << fixed << setprecision(20);
  while (t--) {
    run();
  }
  return 0;
}


