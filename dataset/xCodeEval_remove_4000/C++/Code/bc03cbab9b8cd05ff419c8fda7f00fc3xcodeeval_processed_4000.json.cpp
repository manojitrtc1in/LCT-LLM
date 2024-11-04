




using namespace std;


















int id11 = 0;

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
struct Sep { Sep(T& i, string x, FN fn = write<V>): x(x), i(i), fn(fn) {}; string x; T& i; function<void(V)> fn; };
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
  T zero; function<T(T,T)> op; vector<T> data = {}; size_t size;
  SegmentTree(size_t size, T zero, function<T(T,T)> op): zero(zero), op(op) {
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
void id9(int x, const TPrimes& primes, TOut& out) {
  MEASURE_TOTAL(find_primes);
  ITER(p, primes) { BR_IF(p*p > x); while (x % p == 0) { out[p]++; x /= p; } }
  if (x > 1) { out[x]++; }
}

template<typename T1, typename T2>
void id17(T1& src, T2& dest) {
  for (auto [p, c] : src) { dest[p] = max(dest[p], src[p]); }
}

template<typename TPrimes, typename TOut>
void id8(int x, const TPrimes& primes, TOut& out) {
  TOut src; id9(x, primes, src); id17(src, out);
}

bool id10(LL d) { return true; }
void id1(LL d) { }
template<typename T, typename K = typename T::key_type, typename V = typename T::mapped_type>
void id16(LL upTo, T& original, std::function<bool(LL)> cbtest = nullptr, std::function<void(LL)> cbin = nullptr, std::function<void(LL)> cbout = nullptr) {
  MEASURE_TOTAL(id16);
  if (cbtest == nullptr) { cbtest = id10; }
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



int main() {
  INIT; MEASURE(app);
  Measure capture_app("capture_app", false, true);
  MeasureCapture _capture_app(&capture_app);

  Measure id7("id7", false, true);

  auto sieve = id4(MAXN+10);
  vector<int> primes; id6(sieve, primes);

  DEBUG(primes.size());

  int n;
  

  read(n);
  DEBUG(n);

  vector<int> a;
  

  read(PushN(a, n));

  if (LOCAL) while(a.size() < 100000) { a.push_back(a[a.size()-n]-primes[a.size()%500]); }; n = a.size();

  


  unordered_map<int, int> ap;
  vector<int> divCount(MAXN+10);

  vector<unique_ptr<vector<int>>> id0(MAXN+10);

  vector<bool> id14(MAXN+10);

  {
    MEASURE(iter_ai);
    MeasureCapture id15(&id7);

    ITER(ai, a) {
      unordered_map<int, int> aip;
      {
        MEASURE_TOTAL(find_primes_primes_lcd);
        id9(ai, primes, aip);
        id17(aip, ap);
      }

      

      


      COUNT(findPrimes_ai);

      {
        MEASURE_TOTAL(find_divisors);
        

        if (!id0[ai]) {
          

          


          

          

          id0[ai] = make_unique<vector<int>>();
          id16(MAXN, aip, [&](LL d) {
            if (id14[d]) { return false; }
            id0[ai]->push_back(d); id14[d] = true;
            if (d > 1 && id0[ai/d]) {
              ITER(dd, *id0[ai/d]) {
                if (!id14[d*dd]) { id0[ai]->push_back(d*dd); id14[d*dd] = true; }
              }
              return false;
            }
            return true;
          });
          

          

        }
      }

      

      {
        MEASURE_TOTAL(copy_divisors);
        ITER(d, *id0[ai]) { divCount[d]++; id14[d] = false; }
      }
    }
    DEBUG("over");
  }

  vector<LL> d_stack = { 0 };
  vector<LL> id5(MAXN+10, -1);
  

  

  


  {
    MEASURE(iterateDivisors_ap);
    id16(MAXN, ap, [&](LL d) {
      if (d > MAXN || divCount[d] == 0) { return false; }
      if (capture_app.elapsed() > 3.5) {
        id7.report();
        exit(0);
      }
      if (id5[d] >= 0) {
        id5[d_stack.back()] = max(id5[d_stack.back()], id5[d]+d_stack.back() * (divCount[d_stack.back()] - divCount[d]));
        return false;
      }
      return true;
    }, [&](LL d) {
      id5[d] = divCount[d] * d;
      d_stack.push_back(d);
    }, [&](LL d) {
      d_stack.pop_back();
      id5[d_stack.back()] = max(id5[d_stack.back()], id5[d]+d_stack.back() * (divCount[d_stack.back()] - divCount[d]));
    });
  }

  writeln(id5[0]);

  REPORT;
  return 0;
}