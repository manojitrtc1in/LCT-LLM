#include <bits/stdc++.h>
#ifdef ALGO
#include "el_psy_congroo.hpp"
#else
#define DUMP(...) 1145141919810
#define CHECK(...) (__VA_ARGS__)
#endif

using LL = long long;
const LL inf = 4e18;
const int INF = 0x3f3f3f3f;

template<typename T> inline void enlarge(T& a, T b) { if (a < b) a = b; }
template<typename T> inline void minify(T& a, T b) { if (a > b) a = b; }

struct Point {
  int x, y;
};

std::string to_string (const Point& p) { return std::string("(") + std::to_string(p.x) + ", " + std::to_string(p.y) + ")"; }

LL det(const Point& lhs, const Point& rhs) {
  return lhs.x * 1LL * rhs.y - rhs.x * 1LL * lhs.y;
}

LL dot(const Point& lhs, const Point& rhs) {
  return lhs.x * 1LL * rhs.x + lhs.y * 1LL * rhs.y;
}

Point operator - (Point lhs, const Point& rhs) {
  lhs.x -= rhs.x;
  lhs.y -= rhs.y;
  return lhs;
}

struct BoundingBox {
  int xmin = INF;
  int xmax = -INF;
  int ymin = INF;
  int ymax = -INF;

  int H() const { return ymax - ymin; }
  int W() const { return xmax - xmin; }
  LL area() const { return H() * 1LL * W(); }

  void aggregate(const Point& p) {
    minify(xmin, p.x);
    enlarge(xmax, p.x);
    minify(ymin, p.y);
    enlarge(ymax, p.y);
  }
};

LL solve_case1(std::vector<Point> points) {
  std::sort(points.begin(), points.end(),
            [](const Point& lhs, const Point& rhs) {
              return lhs.x < rhs.x;
            });
  int n = points.size();
  std::vector<BoundingBox> prefix_boxes(n + 1);
  for (int i = 0; i < n; ++i) {
    prefix_boxes[i + 1] = prefix_boxes[i];
    prefix_boxes[i + 1].aggregate(points[i]);
  }

  LL ret = prefix_boxes.back().area();
  BoundingBox suffix_box;
  for (int i = n - 1; i >= 0; --i) {
    suffix_box.aggregate(points[i]);
    if (i > 0) {
      minify(ret, suffix_box.area() + prefix_boxes[i].area());
    }
  }

  DUMP("solve_case1", ret);
  return ret;
}

struct SegmentTree {
  int n = 0;
  std::vector<LL> a;
  explicit SegmentTree(int n) : n(n), a(n + n - 1, -inf) {}

  int get_id(int l, int r) const { return l + r | (l != r); }

  void up(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    a[get_id(l, r)] = std::max(a[get_id(l, mid)], a[get_id(mid + 1, r)]);
  }

  void update(int p, LL v) {
    if (p < 0 || p >= n) return;
    return update(p, v, 0, n - 1);
  }
  void update(int p, LL v, int l, int r) {
    if (l == r) {
      enlarge(a[get_id(l, r)], v);
      return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) update(p, v, l, mid);
    else update(p, v, mid + 1, r);
    up(l, r);
  }

  LL query(int L, int R) const {
    if (L > R || L < 0 || R >= n) return -inf;
    return query(L, R, 0, n - 1);
  }
  LL query(int L, int R, int l, int r) const {
    if (r < L || R < l) return -inf;
    if (L <= l && r <= R) {
      return a[get_id(l, r)];
    }
    int mid = (l + r) >> 1;
    return std::max(query(L, R, l, mid), query(L, R, mid + 1, r));
  }
};

void divide2(int vmin, int vmax, int L, int R, int l, int r, const std::vector<Point>& P, const std::vector<Point>& Q,
             const std::vector<int>& left, std::vector<int>& right, std::vector<LL>& output) {
  if (vmin > vmax || L > R || l > r) return;
  int vmid = vmin + (vmax - vmin) / 2;
  int MID = L - 1;
  int mid = l - 1;
  while (MID < R && P[left[MID + 1]].x <= vmid) ++MID;
  while (mid < r && Q[right[mid + 1]].y <= vmid) ++mid;

  auto cmp_by_slope = [&Q](int lhs, int rhs) {
    return det(Q[lhs], Q[rhs]) < 0;
  };

  if (vmid != vmax && vmin <= vmid && L <= MID && l <= mid) {
    divide2(vmin, vmid, L, MID, l, mid, P, Q, left, right, output);
  } else if (l <= mid) {
    std::sort(right.begin() + l, right.begin() + mid + 1, cmp_by_slope);
  }
  if (vmid + 1 <= vmax && MID + 1 <= R && mid + 1 <= r) {
    divide2(vmid + 1, vmax, MID + 1, R, mid + 1, r, P, Q, left, right, output);
  } else if (mid < r) {
    std::sort(right.begin() + mid + 1, right.begin() + r + 1, cmp_by_slope);
  }
  std::inplace_merge(right.begin() + l, right.begin() + mid + 1, right.begin() + r + 1, cmp_by_slope);
  if (L <= MID) {
    std::vector<Point> convex;
    for (int i = L; i <= MID; ++i) {
      Point p = P[left[i]];
      while (!convex.empty()) {
        if (convex.back().y <= p.y) {
          convex.pop_back();
        } else if (convex.size() >= 2 && det(convex[convex.size() - 2] - p, convex.back() - p) >= 0) {
          convex.pop_back();
        } else {
          break;
        }
      }
      convex.emplace_back(std::move(p));
    }
    for (int i = l, j = 0; i <= r; ++i) if (Q[right[i]].y >= vmid) {
      int id = right[i];
      while (j + 1 < convex.size() && dot(convex[j], Q[id]) <= dot(convex[j + 1], Q[id])) ++j;
      enlarge(output[id], dot(convex[j], Q[id]));
    }
  }
}

void divide(int vmin, int vmax, int L, int R, int l, int r, const std::vector<Point>& P, const std::vector<Point>& Q,
            std::vector<LL>& output) {
  if (vmin > vmax || L > R || l > r) return;
  int vmid = vmin + (vmax - vmin) / 2;
  int MID = L - 1;
  int mid = l - 1;
  while (MID < R && P[MID + 1].y <= vmid) ++MID;
  while (mid < r && Q[mid + 1].x <= vmid) ++mid;

  if (vmid != vmax && vmin <= vmid && L <= MID && l <= mid) {
    divide(vmin, vmid, L, MID, l, mid, P, Q, output);
  }
  if (vmid + 1 <= vmax && MID + 1 <= R && mid + 1 <= r) {
    divide(vmid + 1, vmax, MID + 1, R, mid + 1, r, P, Q, output);
  }

  int mid2 = l - 1;
  while (mid2 < r && Q[mid2 + 1].x < vmid) ++mid2;
  int VMIN = INF;
  int VMAX = -INF;
  for (int i = L; i <= MID; ++i) {
    minify(VMIN, P[i].x);
    enlarge(VMAX, P[i].x);
  }
  for (int i = mid2 + 1; i <= r; ++i) {
    minify(VMIN, Q[i].y);
    enlarge(VMAX, Q[i].y);
  }
  std::vector<int> left, right;
  for (int i = L; i <= MID; ++i) left.emplace_back(i);
  for (int i = mid2 + 1; i <= r; ++i) right.emplace_back(i);
  std::sort(left.begin(), left.end(), [&](int lhs, int rhs) { return P[lhs].x < P[rhs].x; });
  std::sort(right.begin(), right.end(), [&](int lhs, int rhs) { return Q[lhs].y < Q[rhs].y; });
  divide2(VMIN, VMAX, 0, (int)left.size() - 1, 0, (int)right.size() - 1, P, Q, left, right, output);
}

void align_to_axises(std::vector<Point>& points) {
  BoundingBox box;
  for (const auto& p : points) box.aggregate(p);
  for (auto& p : points) {
    p.x -= box.xmin;
    p.y -= box.ymin;
  }
}

LL solve_case2and3(std::vector<Point> points) {
  align_to_axises(points);
  std::sort(points.begin(), points.end(),
            [](const Point& lhs, const Point& rhs) {
              if (lhs.x != rhs.x) return lhs.x < rhs.x;
              return lhs.y < rhs.y;
            });
  int n = points.size();
  std::vector<BoundingBox> suffix_box(n + 1);
  for (int i = n - 1; i >= 0; --i) {
    suffix_box[i] = suffix_box[i + 1];
    suffix_box[i].aggregate(points[i]);
  }
  int H = suffix_box[0].H();
  int W = suffix_box[0].W();
  std::vector<Point> P(n);
  std::vector<Point> Q(n);
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      Q[i].x = points[i - 1].x;
      Q[i].y = suffix_box[i].ymax;
    } else {
      Q[i].x = 0;
      Q[i].y = 0;
    }
  }
  std::vector<int> ys;
  for (const Point& p : points) ys.emplace_back(p.y);
  std::sort(ys.begin(), ys.end());
  ys.erase(std::unique(ys.begin(), ys.end()), ys.end());
  auto get_index = [&ys](int y) -> int {
    return std::lower_bound(ys.begin(), ys.end(), y) - ys.begin();
  };
  int bottom = ys.size();
  std::vector<int> L(ys.size(), INF);
  DUMP(points);
  for (int i = 0; i < n; ++i) {
    int y_index = get_index(points[i].y);
    while (bottom > y_index + 1) {
      --bottom;
      L[bottom] = points[i].x;
    }
    if (bottom == y_index + 1) {
      

    }
  }
  for (int i = 0; i < n; ++i) {
    int y_index = get_index(points[i].y);
    if (L[y_index] == INF) {
      P[i].x = P[i].y = INF;
    } else {
      P[i].y = L[y_index];
      P[i].x = points[i].y;
    }
  }
  LL ret2 = inf;
  std::vector<LL> output(n, -inf);
  std::sort(P.begin(), P.end(), [](const Point& lhs, const Point& rhs) {
    return lhs.y < rhs.y;
  });
  int vmin = INF;
  int vmax = -INF;
  for (int i = 0; i < n; ++i) {
    minify(vmin, P[i].x);
    enlarge(vmax, P[i].x);
  }
  for (int i = 0; i < n; ++i) {
    minify(vmin, Q[i].y);
    enlarge(vmax, Q[i].y);
  }
  divide(vmin, vmax, 0, n - 1, 0, n - 1, P, Q, output);
  std::vector<LL> val(n, inf);
  for (int i = 1; i < n; ++i) {
    minify(val[i], -(output[i] - Q[i].x * 1LL * H - Q[i].y * 1LL * W));
    minify(ret2, val[i]);
  }
  DUMP("solve_case3", ret2);
  

  

  

  

  

  if (false) {
    std::vector<LL> output2(n, -inf);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) if (P[j].x < Q[i].y) {
        enlarge(output2[i], dot(P[j], Q[i]));
      }
    }
    for (int i = 0; i < n; ++i) {
      CHECK(output[i] == output2[i]);
    }
  }

  LL ret = inf;
  bottom = ys.size();
  SegmentTree sgt_upper(ys.size() + 1), sgt_lower(ys.size() + 1);
  std::set<std::pair<int, int>> set;
  int L_Lu = INF;  

  int Lu_index = -1;
  for (int i = 0; i < n; ++i) {
    while (!set.empty() && set.rbegin()->first > suffix_box[i].ymax) {
      auto it = std::prev(set.end());
      minify(L_Lu, it->second);
      set.erase(it);
    }
    while (Lu_index + 1 < (int)ys.size() && L[Lu_index + 1] > L_Lu) ++Lu_index;
    if (i > 0 && L_Lu != INF) {
      int R = points[i - 1].x;
      int Ru = suffix_box[i].ymax;
      int Rd = suffix_box[i].ymin;
      LL constant = Ru * 1LL * W + R * 1LL * H;
      int Ru_index = get_index(Ru);
      int Rd_index = get_index(Rd);
      if (Lu_index < Rd_index) {
        minify(ret, constant - sgt_lower.query(Lu_index + 1, Rd_index));
        if (Lu_index >= 0) {
          minify(ret, constant - ys[Lu_index] * 1LL * W - L_Lu * 1LL * H);
        }
      } else {
        minify(ret, constant - Rd * 1LL * W - L_Lu * 1LL * H);
      }
      if (Lu_index < Rd_index) {
        minify(ret, constant - sgt_upper.query(Rd_index, Ru_index) - Rd * 1LL * W);
        if (Lu_index >= 0) {
          minify(ret, constant - ys[Lu_index] * 1LL * W - L_Lu * 1LL * H);
        }
      } else if (Lu_index < Ru_index) {
        minify(ret, constant - sgt_upper.query(Lu_index + 1, Ru_index) - Rd * 1LL * W);
        minify(ret, constant - Rd * 1LL * W - L_Lu * 1LL * H);
      } else {
        minify(ret, constant - Rd * 1LL * W - L_Lu * 1LL * H);
      }
      

      

    }
    set.emplace(points[i].y, points[i].x);
    int y_index = get_index(points[i].y);
    while (bottom > y_index + 1) {
      --bottom;
      sgt_lower.update(bottom, ys[bottom] * 1LL * W + points[i].x * 1LL * H);
      sgt_upper.update(bottom, points[i].x * 1LL * H);
    }
    if (bottom == y_index + 1) {
      

      

    }
  }
  DUMP("solve_case2", ret);
  return std::min(ret, ret2);
}

LL solve(std::vector<Point> points) {
  LL ret = inf;
  minify(ret, solve_case1(points));
  for (auto& point : points) std::swap(point.x, point.y);
  minify(ret, solve_case1(points));

  minify(ret, solve_case2and3(points));
  for (auto& point : points) point.x *= -1;
  minify(ret, solve_case2and3(points));

  return ret;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::istream& reader = std::cin;

  int cas;
  reader >> cas;
  while (cas--) {
    int n;
    reader >> n;
    std::vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
      reader >> points[i].x >> points[i].y;
    }
    std::cout << solve(std::move(points)) << std::endl;
  }
}



