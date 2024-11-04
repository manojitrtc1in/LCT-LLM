
NDEBUG
























using namespace std;

template<class T>
using vec = std::vector<T>;

















































































































































































































































































































































































































































































































































































































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





struct Node {
  Node* left = NULL;
  Node* right = NULL;
  int64_t min = 0;
  int64_t add = 0;
  int rangeLeft, rangeRight;

  Node() {}
};


int memoPtr = 0;

Node* newNode() {
  return new Node();


}

struct id0 {
  Node* root;
  int n;

  id0(int sz) : n(sz) {
    root = newNode();
    root->rangeLeft = 0;
    root->rangeRight = n;
  }

  void push(Node* t) {
    if (t->rangeLeft + 1 == t->rangeRight) {
      return;
    }
    if (t->add != 0) {
      int middle = (t->rangeLeft + t->rangeRight) / 2;
      if (!t->left) {
        t->left = newNode();
        t->left->rangeLeft = t->rangeLeft;
        t->left->rangeRight = middle;
      }
      if (!t->right) {
        t->right = newNode();
        t->right->rangeLeft = middle;
        t->right->rangeRight = t->rangeRight;
      }
      t->left->add += t->add;
      t->left->min += t->add;

      t->right->add += t->add;
      t->right->min += t->add;

      t->add = 0;
    }
  }

  void internalAdd(Node* t, int left, int right, int64_t val) {
    if (left >= t->rangeRight || right <= t->rangeLeft) {
      return;
    }
    push(t);
    if (t->rangeLeft >= left && t->rangeRight <= right) {
      t->min += val;
      t->add += val;
      return;
    }
    int middle = (t->rangeLeft + t->rangeRight) / 2;
    if (!t->left) {
      t->left = newNode();
      t->left->rangeLeft = t->rangeLeft;
      t->left->rangeRight = middle;
    }
    internalAdd(t->left, left, right, val);
    if (!t->right) {
      t->right = newNode();
      t->right->rangeLeft = middle;
      t->right->rangeRight = t->rangeRight;
    }
    internalAdd(t->right, left, right, val);
    t->min = min(t->left->min, t->right->min);
  }

  void add(int from, int to, int val) {
    internalAdd(root, from, to + 1, val);
  }

  int getFirst0() {
    Node* t = root;
    if (t->min > 0) {
      return n;
    }
    while (t->rangeLeft + 1 != t->rangeRight) {
      push(t);
      int middle = (t->rangeLeft + t->rangeRight) / 2;
      if (!t->left) {
        return t->rangeLeft;
      }
      if (t->left->min == 0) {
        t = t->left;
      } else {
        if (!t->right) {
          return middle;
        }
        t = t->right;
      }
    }
    return t->rangeLeft;
  }

  int getLast0() {
    Node* t = root;
    if (t->min > 0) {
      return -1;
    }
    while (t->rangeLeft + 1 != t->rangeRight) {
      push(t);
      int middle = (t->rangeLeft + t->rangeRight) / 2;
      if (!t->right) {
        return t->rangeRight - 1;
      }
      if (t->right->min == 0) {
        t = t->right;
      } else {
        if (!t->left) {
          return middle - 1;
        }
        t = t->left;
      }
    }
    return t->rangeLeft;
  }
};



















































































































































































struct Event {
  int x, from, to, type;

  
  Event(int x, int from, int to, int type) : x(x), from(from), to(to), type(type) {}

  bool operator < (const Event& e) const {
    if (x != e.x) {
      return x < e.x;
    }
    if (type != e.type) {
      return type < e.type;
    }
    return make_pair(from, to) < make_pair(from, to);
  }
};

pair<int, int> id1(const vec<Event>& events, int n, int m) {
  if (events.empty()) {
    return {0, m-1};
  }
  if (events[0].x > 0 || events.back().x < n-1) {
    return {0, m-1};
  }

  int mi = m, ma = -1;
  id0 st(m);
  FOR(i, events.size()) {
    if (events[i].type == 1) {
      dbg("x", events[i].x, "add", events[i].from, events[i].to);
      st.add(events[i].from, events[i].to, 1);
    } else if (events[i].type == 0) {
      dbg("x", events[i].x, "remove", events[i].from, events[i].to);
      st.add(events[i].from, events[i].to, -1);
    } else {
      dbg("looking at x", events[i].x, "first", st.getFirst0(), "last", st.getLast0());
      mi = min(st.getFirst0(), mi);
      ma = max(st.getLast0(), ma);
    }
  }

  return {mi, ma};
}

bool canCover(int n, int m, const vec<pair<int, int>>& loc, int t) {
  dbg("process", t);
  vec<Event> eventX, eventY;
  FOR(i, loc.size()) {
    int x1 = max(0, loc[i].first - t), x2 = min(loc[i].first + t, n-1);
    int y1 = max(0, loc[i].second - t), y2 = min(loc[i].second + t, m-1);

    eventX.push_back(Event(x1, y1, y2, 1));
    eventX.push_back(Event(x2 + 1, y1, y2, 0));
    for (int delta = -1; delta <= 1; ++delta) {
      eventX.push_back(Event(min(n-1, max(0, x1+delta)), -1, -1, 2));
      eventX.push_back(Event(min(n-1, max(0, x2+delta)), -1, -1, 2));
    }

    eventY.push_back(Event(y1, x1, x2, 1));
    eventY.push_back(Event(y2 + 1, x1, x2, 0));
    for (int delta = -1; delta <= 1; ++delta) {
      eventY.push_back(Event(min(m-1, max(0, y1+delta)), -1, -1, 2));
      eventY.push_back(Event(min(m-1, max(0, y2+delta)), -1, -1, 2));
    }
  }
  sort(all(eventX));
  sort(all(eventY));
  auto mmX = id1(eventX, n, m);
  auto mmY = id1(eventY, m, n);
  int delta = max(mmX.second - mmX.first + 1, mmY.second - mmY.first + 1);
  if (delta <= 0) {
    delta = 0;
  }
  if (delta % 2 == 0) {
    ++delta;
  }
  delta /= 2;
  return delta <= t;
}

void solve(istream& in, ostream& out) {
  memoPtr = 0;
  auto n = next<int>(in);
  auto m = next<int>(in);
  auto k = next<int>(in);
  vec<pair<int, int>> loc(k);
  FOR(i, k) {
    auto x = next<int>(in) - 1;
    auto y = next<int>(in) - 1;
    loc[i] = {x, y};
  }
  canCover(n, m, loc, 3);


  int le = 0, ri = max(n, m) * 2, res = -1;
  while (le <= ri) {
    auto e = static_cast<int>((le + ri) / 2);
    if (canCover(n, m, loc, e)) {
      res = e;
      ri = e - 1;
    } else {
      le = e + 1;
    }
  }
  out << res << "\n";
}





int main() {




    solve(cin, cout);


    return 0;
}

