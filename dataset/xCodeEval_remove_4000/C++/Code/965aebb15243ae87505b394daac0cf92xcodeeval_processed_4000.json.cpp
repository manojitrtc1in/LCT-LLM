





using namespace std;



















int id10 = 0;

int id12 = 0;

unordered_map<const char*,LL> __counts;




bool JUDGE = true; bool LOCAL = false;

bool JUDGE = false; bool LOCAL = true;


template<typename T> void read(T& v) { cin >> v; };
template<typename T, typename V = typename T::value_type, typename FN = decltype(read<V>)>
struct PushN { PushN(T& i, int n, FN fn = read<V>): n(n), i(i), fn(fn) {}; int n; T& i; function<void(V&)> fn; };
template<typename T, typename V, typename FN> void read(PushN<T, V, FN> r) {
  REP(i, 0, r.n) { V value = V(); r.fn(value); r.i.push_back(value); }
};

template<typename T1, typename T2, typename... Rest>
void read(T1& v1, T2& v2, Rest&... rest) { read(v1); read(v2, rest...); }

template<typename T> void write(T v) { cout << v; };
template<typename T1, typename T2> void write(pair<T1, T2> v) { cout << v.first << " " << v.second; };
template<typename T, typename V = typename T::value_type, typename FN = decltype(write<V>)>
struct Sep { Sep(const T& i, string x, FN fn = write<V>): x(x), i(i), fn(fn) {}; string x; const T& i; function<void(V)> fn; };
template<typename T, typename V = typename T::value_type, typename FN> void write(Sep<T, V, FN> s) {
  bool first = true;
  for (const auto & v : s.i) { if (first) { first = false; } else { write(s.x); } s.fn(v); }
};
template<typename T1, typename T2, typename... Rest>
void write(T1 v1, T2 v2, Rest... rest) { write(v1); write(v2, rest...); }
template<typename... Rest> void writeln(Rest... rest) { write(rest...); write('\n'); }

template<typename T>
void debug1(T v) { write(v); }
template<typename T1, typename T2, typename... Rest>
void debug1(T1 v1, T2 v2, Rest... rest) { debug1(v1); write(", "); debug1(v2, rest...); }
template<typename... Rest> void debug(string args, Rest... rest) {
  if (LOCAL) { write(" >>> ["); write(args); write("] = ["); debug1(rest...); write("]\n"); flush(cout); }
}



struct Measure {
  Measure(const char * label, bool autoreport = true, bool always_capture = false) : label(label), autoreport(autoreport), always_capture(always_capture) { if (autoreport) start(); }
  ~Measure() { if (autoreport) { stop(); report(); } }
  void start() { if (LOCAL || always_capture) { start_time = chrono::high_resolution_clock::now(); } }
  double elapsed() { if (LOCAL || always_capture) { chrono::duration<double> local_diff = chrono::high_resolution_clock::now() - start_time; return local_diff.count(); } return 0; }
  void stop() { if (LOCAL || always_capture) { diff += elapsed(); count++; } }
  void report() { if (LOCAL || always_capture) { writeln(" @@@ [", label, "] time = (",  diff*1000/count, " ms)  x  (", count, ") = (", diff*1000, " ms)"); } }
  const char * label;
  double diff = 0;
  bool autoreport;
  int count = 0;
  bool always_capture;
  chrono::time_point<chrono::high_resolution_clock> start_time;
};

unordered_map<const char*,shared_ptr<Measure>> id3;
struct MeasureTotal {
  MeasureTotal(const char *label) : label(label) {
    if (DO_COUNT) {
      if (!id3[label]) { id3[label] = make_shared<Measure>(label, false); }
      id3[label]->start();
    }
  }
  ~MeasureTotal() { if (DO_COUNT) id3[label]->stop(); };
  const char *label;
};
struct MeasureCapture {
  MeasureCapture(Measure* measure) : measure(measure) { measure->start(); }
  ~MeasureCapture() { measure->stop(); };
  Measure* measure;
};


  for (auto [label, measure] : set(ALL(id3))) measure->report(); \
  for (auto [label, count] : set(ALL(__counts))) writeln(" 


template<typename T, typename V = typename T::value_type>
bool Contains(const T& container, V value) {
  return container.find(value) != container.end();
}

template<typename T>
struct SegmentTree {
  T zero; function<T(T,T)> op; vector<T> data = {}; size_t size; size_t requested_size;
  SegmentTree(size_t size, T zero, function<T(T,T)> op): zero(zero), op(op), requested_size(size) {
    this->size = 1; while (this->size < size) { this->size *= 2; }
    data.resize(this->size * 2); fill(ALL(data), zero);
  };
};

template<typename T>
struct SegmentUpdate : SegmentTree<T> {
  using SegmentTree<T>::SegmentTree;
  void update(size_t from, size_t to, T value) {
    from += this->size; to += this->size; auto& data = this->data; auto& op = this->op;
    while (from < to) {
      if (from % 2 == 0) { from /= 2; } else { data[from] = op(data[from], value); from = from / 2 + 1; }
      if (to % 2 == 1) { to /= 2; } else { data[to] = op(data[to], value); to = to / 2 - 1; }
    }
    if (from == to) { data[from] = op(data[from], value); }
  }

  T query(size_t index) {
    index += this->size; T result = this->zero;
    while (index > 0) { result = this->op(result, this->data[index]); index /= 2; }
    return result;
  }

  vector<T> debug() {
    vector<T> result;
    REP(i, 0, this->requested_size) { result.push_back(query(i)); }
    return result;
  }
};

template<typename T>
struct SegmentQuery : SegmentTree<T> {
  using SegmentTree<T>::SegmentTree;
  void update(size_t index, T value) {
    index += this->size;
    auto& data = this->data;
    data[index] = value;
    while (index > 1) { index /= 2; data[index] = this->op(data[index*2], data[index*2+1]); }
  }

  T query(size_t from, size_t to) {
    from += this->size; to += this->size; T result = this->zero; auto& data = this->data; auto& op = this->op;
    while (from < to) {
      if (from % 2 == 0) { from /= 2; } else { result = op(result, data[from]); from = from / 2 + 1; }
      if (to % 2 == 1) { to /= 2; } else { result = op(result, data[to]); to = to / 2 - 1; }
    }
    if (from == to) { result = op(result, data[from]); }
    return result;
  }
};

vector<bool> id4(int upTo) {
  vector<bool> r(upTo + 1, true); r[0] = r[1] = false;
  for(LL i = 2; i * i <= upTo; i++) {
    if (r[i]) { for(LL j = i*i; j <= upTo; j+=i) { r[j] = false; } }
  }
  return r;
}

template<typename T>
void id6(const vector<bool>& b, T& r) {
  REP(i, 2, b.size()) { if (b[i]) { r.push_back(i); } }
}
template<typename T>
void id6(int upTo, T& r) { return id6(id4(upTo), r); }

template<typename TPrimes, typename TOut>
void id8(int x, const TPrimes& primes, TOut& out) {
  MEASURE_TOTAL(find_primes);
  ITER(p, primes) { BR_IF(p*p > x); while (x % p == 0) { out[p]++; x /= p; } }
  if (x > 1) { out[x]++; }
}

template<typename T1, typename T2>
void id15(T1& src, T2& dest) {
  for (auto [p, c] : src) { dest[p] = max(dest[p], src[p]); }
}

template<typename TPrimes, typename TOut>
void id7(int x, const TPrimes& primes, TOut& out) {
  TOut src; id8(x, primes, src); id15(src, out);
}

bool id9(LL d) { return true; }
void id1(LL d) { }
template<typename T, typename K = typename T::key_type, typename V = typename T::mapped_type>
void id14(LL upTo, T& original, std::function<bool(LL)> cbtest = nullptr, std::function<void(LL)> cbin = nullptr, std::function<void(LL)> cbout = nullptr) {
  MEASURE_TOTAL(id14);
  if (cbtest == nullptr) { cbtest = id9; }
  if (cbin == nullptr) { cbin = id1; }
  if (cbout == nullptr) { cbout = id1; }
  vector<pair<K,V>> src(ALL(original));
  sort(ALL(src));
  vector<vector<LL>> id13 = { {} };
  vector<LL> div_stack = { -1 };
  LL current = 1;
  auto fill_candidates = [&]() {
    MEASURE_TOTAL(iterateDivisors_fill_candidates);
    auto& top_stack = id13[div_stack.size()-1];
    REP(i, 0, src.size()) {
      auto [p, c] = src[i];
      BR_IF(p * current > upTo);
      if (c > 0 && cbtest(p * current)) { top_stack.push_back(i); }
    }
    COUNTS(fill_candidates_total, top_stack.size());
  };

  fill_candidates();
  if (!cbtest(current)) {
    return;
  }
  cbin(current);

  while (!div_stack.empty()) {
    COUNT(iterateDivisors_while);
    auto id2 = div_stack.back();
    auto& top_stack = id13[div_stack.size()-1];

    if (top_stack.empty()) {
      MEASURE_TOTAL(iterateDivisors_pop);
      cbout(current);
      if (id2 > -1) {
        src[id2].second++;
        current /= src[id2].first;
      };
      div_stack.pop_back();
    } else {
      MEASURE_TOTAL(iterateDivisors_push);
      auto next_idx = top_stack.back();
      auto next = src[next_idx].first;
      top_stack.pop_back();
      current *= next;
      cbin(current);
      div_stack.push_back(next_idx);
      if (id13.size() < div_stack.size()) {
        id13.push_back({});
      }
      id13[div_stack.size()-1].clear();
      src[next_idx].second--;
      fill_candidates();
    }
  };
}

template<typename T>
pair<T, T> id5(T o_from, T o_to, function<T(T)> fn) {
  T from = o_from; T to = o_to-1;
  T u_from = o_from; T u_to = o_to-1;
  bool id0 = false;
  bool id11 = false;
  while (from < to) {
    auto mid = (from + to + 1) / 2;
    auto mid_fn = fn(mid);
    if (mid_fn < 0) {
      from = mid;
      id0 = true;

      u_from = mid;
    } else {
      to = mid - 1;
    }
    if (mid_fn > 0) { u_to = mid; id11 = true; }
  }
  T lower = from;
  from = u_from; to = u_to;
  while (from < to) {
    auto mid = (from + to) / 2;
    auto mid_fn = fn(mid);
    if (mid_fn > 0) { to = mid; id11 = true; } else { from = mid + 1; }
  }
  T upper = to;
  return make_pair(
    (id0 || fn(lower) < 0) ? lower+1 : lower,
    (id11 || fn(upper) > 0) ? upper : upper+1);
}





































struct Tree {
  


  unique_ptr<Tree> left = nullptr;
  unique_ptr<Tree> right = nullptr;
  int value = 0;

  int path = 0;
  int bit = 1<<30;

  int query(int x, bool show_debug = false) {
    Tree* node = left.get();
    if (x & (bit>>1)) { node = right.get(); }
    if (show_debug) {
      auto [range_from, range_to] = range();
      DEBUG(range_from, range_to, value);
    }
    if (!node) { return value; }
    return value + node->query(x, show_debug);
  }

  void update(int from, int to, int increment) {
    auto [node_from, node_to] = range();
    if (from <= node_from && node_to <= to) {
      

      value += increment;
      return;
    }
    if (to < node_from || node_to < from) {
      return;
    }
    if (!left) {
      

      


      left = make_unique<Tree>();
      left->bit = bit >> 1;
      left->path = path;
    }
    left->update(from, to, increment);
    if (right == nullptr) {
      

      


      right = make_unique<Tree>();
      right->bit = bit >> 1;
      right->path = path | right->bit;
    }
    right->update(from, to, increment);
  }

  pair<int, int> range() {
    return make_pair(path & ~(bit-1), path | bit-1);
  }
};

struct Day { int T; int k; vector<int> x; };

int RMIN = 0;
int RMAX = (1<<30)-1;

int main() {
  INIT;
  MEASURE(app);

  int last_ans = 0;
  DEBUG(RMAX);

  int n; read(n);
  vector<Day> days; read(PushN(days, n, FNR1(day) {
    read(day.T);
    read(day.k);
    read(PushN(day.x, day.k));
  }));

  

  Tree shifts;
  


  ITER(day, days) {
    DEBUG(day.T);

    auto [from, to] = id5<LL>(
      RMIN,
      RMAX+1,
      LAMBDA1(x, x+shifts.query(x) - day.T));

    


    if (from > RMIN) {
      shifts.update(0, from-1, +1);
    }
    if (to <= RMAX) {
      shifts.update(to, RMAX, -1);
    }

    

    


    ITER(encoded_x, day.x) {
      int actual_x = MOD(encoded_x + last_ans);

      


      last_ans = actual_x + shifts.query(actual_x);
      writeln(last_ans);
    }
  }

  REPORT;
  return 0;
}