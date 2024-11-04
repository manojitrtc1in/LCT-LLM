#include <bits/stdc++.h>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vs = vector<string>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdd = vector<pdd>;


using range_t = ll;
constexpr char IMPOSSIBLE[] = "IMPOSSIBLE";
constexpr char POSSIBLE[] = "POSSIBLE";
namespace coding {
namespace debug {
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(const bool &b) { return (b ? "true" : "false"); }
template <class T> string to_string(const T& x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}
template <class A, class B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <class IterType>
string iter_to_string(IterType begin, IterType end, std::string sep = ", ",
                      std::string prefix = "{", std::string suffix = "}") {
  int first = true;
  string res = prefix;
  for (auto iter = begin; iter != end; ++iter) {
    if (!first)
      res += sep;
    first = false;
    res += to_string(*iter);
  }
  res += suffix;
  return res;
}
template <class A, class B, class... Args>
string to_string(const std::unordered_set<A, B> &vec, Args... args) {
  return iter_to_string(vec.cbegin(), vec.cend(), args...);
}
template <class A, size_t N, class... Args> string to_string(const std::array<A, N> &vec, Args... args) { return iter_to_string(vec.cbegin(), vec.cend(), args...); }
template <class A, class... Args> string to_string(const std::vector<A> &vec, Args... args) { return iter_to_string(vec.cbegin(), vec.cend(), args...); }
template <class A, class... Args> string to_string(const std::list<A> &vec, Args... args) { return iter_to_string(vec.cbegin(), vec.cend(), args...); }
template <class A, class... Args>
string to_string(const std::unordered_set<A> &vec, Args... args) {
  return iter_to_string(vec.cbegin(), vec.cend(), args...);
}
template <class A, class... Args>
string to_string(const std::multiset<A> &vec, Args... args) {
  return iter_to_string(vec.cbegin(), vec.cend(), args...);
}
template <class A, class B, class... Args>
string to_string(const std::unordered_map<A, B> &vec, Args... args) {
  return iter_to_string(vec.cbegin(), vec.cend(), args...);
}
template <class A, class B, class... Args>
string to_string(const std::map<A, B> &vec, Args... args) {
  return iter_to_string(vec.cbegin(), vec.cend(), args...);
}
template <class A, class... Args>
string to_string(const A vec[], Args... args) {
  return iter_to_string(vec, vec+sizeof(vec) + args...);
}
void debug_out() { puts(""); }
template <class T, class... U> void debug_out(const T &h, const U &... t) {
  cout << " " << to_string(h) << flush;
  debug_out(t...);
}
} 

} 

namespace coding {
namespace data_structure {










template <class ValueT, class DeltaT, class ResultT> class SegmentTree;
template <class ValueT, class DeltaT> class SegmentTreeNode {
public:
  SegmentTreeNode() = default;
  SegmentTreeNode(range_t lower, range_t upper, const ValueT &value,
                  const range_t index) {
    Set(lower, upper, value, index);
  }
  void Set(range_t lower, range_t upper, const ValueT &value,
           const range_t index) {
    left_ = nullptr, right_ = nullptr;
    delayed_update_ = nullopt;
    lower_ = lower, upper_ = upper;
    mid_ = (lower_ + upper_) >> 1;
    len_ = upper_ - lower_ + 1;
    splitted_ = upper_ == lower_;
    value_ = value;
    index_ = index;
  }
  string to_string() const {
    ostringstream ss;
    ss << "<SegTreeNode<" << index_ << ">"
       << ": [" << lower_ << ", " << upper_ << "], "
       << "\tvalue = " << coding::debug::to_string(value_) << ", "
       << "\tdelayed_update = ";
    if (delayed_update_.has_value()) {
      ss << delayed_update_.value();
    } else {
      ss << "(not set)";
    }
    ss << ">";
    return ss.str();
  }
  

  

public:
  unique_ptr<SegmentTreeNode<ValueT, DeltaT>> left_, right_;
  range_t lower_, upper_, mid_, len_;
  ValueT value_;
  optional<DeltaT> delayed_update_;
  bool splitted_;
  range_t index_ = -1;
  template <class ValueT_, class DeltaT_, class ResultT_>
  friend class SegmentTree;
};

template <class ValueT, class DeltaT>
ostream &operator<<(ostream &o, const SegmentTreeNode<ValueT, DeltaT> &node) {
  o << node.to_string();
  return o;
}


template <class ValueT, class DeltaT, class ResultT> class SegmentTree {
public:
  using Node = SegmentTreeNode<ValueT, DeltaT>;
  SegmentTree(range_t lower, range_t upper, const ValueT &init_value,
              const ResultT &empty_result, bool enable_delay_push)
      : init_value_(init_value), enable_delay_push_(enable_delay_push),
        empty_result_(empty_result) {
    root_ = make_unique<Node>(lower, upper, init_value_, 1);
  }
  Node* GetRoot() const { return root_.get(); }
  ResultT Query(range_t query_lower, range_t query_upper) {
    return QueryInternal(root_.get(), query_lower, query_upper);
  }
  void Update(range_t update_lower, range_t update_upper, const DeltaT &delta) {
    UpdateInternal(root_.get(), update_lower, update_upper, delta);
  }
protected:
  
  

  virtual ResultT MergeQueriesImpl(const ResultT &l_res,
                                   const ResultT &r_res) = 0;
  

  virtual void ApplyDeltaImpl(Node *node, const DeltaT &delta) = 0;
  

  

  virtual void PushupImpl(Node *node) = 0;
  

  

  virtual ResultT GetResultImpl(Node *node) = 0;
  

  

  virtual void PushdownImpl(Node *node) {
    ApplyDeltaImpl(node->left_.get(), node->delayed_update_.value());
    ApplyDeltaImpl(node->right_.get(), node->delayed_update_.value());
  }
  
private:
  void UpdateInternal(Node *node, range_t update_lower, range_t update_upper,
                      const DeltaT &delta) {
    if ((enable_delay_push_ || node->len_ == 1) &&
        update_lower <= node->lower_ && update_upper >= node->upper_) {
      

      ApplyDeltaImpl(node, delta);
      

      return;
    }
    

    Split(node);
    

    if (enable_delay_push_)
      Pushdown(node);
    

    if (update_lower <= node->mid_) {
      UpdateInternal(node->left_.get(), update_lower, update_upper, delta);
    }
    if (node->mid_ + 1 <= update_upper) {
      UpdateInternal(node->right_.get(), update_lower, update_upper, delta);
    }
    PushupImpl(node);
    

  }
  

  ResultT QueryInternal(Node *node, range_t query_lower, range_t query_upper) {
    

    

    if (query_lower <= node->lower_ && node->upper_ <= query_upper) {
      return GetResultImpl(node);
    }
    

    if (query_upper < node->lower_ || node->upper_ < query_lower) {
      return empty_result_;
    }
    

    

    Split(node);
    if (enable_delay_push_)
      Pushdown(node);
    return MergeQueriesImpl(
        query_lower <= node->mid_
            ? QueryInternal(node->left_.get(), query_lower, query_upper)
            : empty_result_,
        node->mid_ + 1 <= query_upper
            ? QueryInternal(node->right_.get(), query_lower, query_upper)
            : empty_result_);
  }
  void Pushdown(Node *node) {
    if (!node->delayed_update_.has_value())
      return;
    

    if (node->lower_ != node->upper_) {
      PushdownImpl(node);
    }
    

    node->delayed_update_ = nullopt;
  }
  

  void Split(Node *node) {
    if (node->splitted_)
      return;
    node->left_ = make_unique<Node>(node->lower_, node->mid_, init_value_,
                                    node->index_ << 1);
    node->right_ = make_unique<Node>(node->mid_ + 1, node->upper_, init_value_,
                                     node->index_ << 1 | 1);
    node->splitted_ = true;
  }
  

  unique_ptr<Node> root_;
  

  bool enable_delay_push_ = true;
  ValueT init_value_;
  ResultT empty_result_;
};



template <class ValueT>
class SegmentTreeSum : public SegmentTree<ValueT, ValueT, ValueT> {
public:
  using Node = SegmentTreeNode<ValueT, ValueT>;
  SegmentTreeSum<ValueT>(range_t lower, range_t upper)
      : SegmentTree<ValueT, ValueT, ValueT>(lower, upper, 0,
                                            0,
                                            false) {}
  ValueT MergeQueriesImpl(const ValueT &l_res, const ValueT &r_res) override {
    return l_res + r_res;
  };
  void ApplyDeltaImpl(Node *node, const ValueT &delta) override {
    node->value_ += delta * node->len_;
    node->delayed_update_ = node->delayed_update_.value_or(0) + delta;
  };
  void PushupImpl(Node *node) override {
    node->value_ = node->left_->value_ + node->right_->value_;
  }
  ValueT GetResultImpl(Node *node) override { return node->value_; }
};

template <class ValueT>
class SegmentTreeMax : public SegmentTree<ValueT, ValueT, ValueT> {
public:
  using Node = SegmentTreeNode<ValueT, ValueT>;
  SegmentTreeMax<ValueT>(range_t lower, range_t upper)
      : SegmentTree<ValueT, ValueT, ValueT>(lower, upper, 0,
                                            0,
                                            true) {}
  ValueT MergeQueriesImpl(const ValueT &l_value,
                          const ValueT &r_value) override {
    return max(l_value, r_value);
  };
  void ApplyDeltaImpl(Node *node, const ValueT &delta) override {
    node->value_ = max(node->value_, delta);
    node->delayed_update_ = max(node->delayed_update_.value_or(0), delta);
  };
  void PushupImpl(Node *node) override {
    node->value_ = max(node->left_->value_, node->right_->value_);
  }
  ValueT GetResultImpl(Node *node) override { return node->value_; }
};
} 

} 

namespace coding {
namespace io {
void SetupStdinFromFile(const std::string filepath) {
  if (freopen(filepath.c_str(), "r", stdin) == nullptr) {
    cout << "Cannot hook file: " << filepath << endl;
    exit(EXIT_FAILURE);
  }
}
void SetupStdoutToFile(const std::string filepath) {
  if (freopen(filepath.c_str(), "w", stdout) == nullptr)
    exit(EXIT_FAILURE);
}
template<class T=long long>
inline T Read() {
  T x = 0;
  ll f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-')
      f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
void SetupQuickIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(15);
}
template <class T> std::vector<T> ReadVector(size_t size, T shift = T()) {
  std::vector<T> result;
  while (size--) {
    T input = Read<T>();
    result.push_back(input+shift);
  }
  return result;
}
template <class T> std::vector<vector<T>> ReadMatrix(size_t row, size_t column) {
  std::vector<vector<T>> result;
  while (row--) {
    result.emplace_back(ReadVector<T>(column));
  }
  return result;
}
template <class T> void OutputVector(const vector<T>& v) {
  for (const auto& x: v) {
     cout << x << " ";
  }
  cout << endl;
}
} 

} 



int32_t CODEJAM_CASE_COUNTER = 0;
std::string CODEJAM() {
  return "Case #" + to_string(++CODEJAM_CASE_COUNTER) + ": ";
}
using coding::io::Read;
using coding::io::ReadVector;
int main() {
  ll T = 1; 

  while (T--) {
    ll n = Read();
    vector<ll> v = ReadVector<ll>(n);
    vector<ll> xor_from_root(n, 0);
    unordered_map<ll, unordered_set<ll>> xor_set;
    unordered_map<ll, unordered_set<ll>> g;
    for (int i = 0; i < n - 1; ++i) {
      ll u = Read()-1, v = Read()-1;
      g[u].insert(v);
      g[v].insert(u);
    }
    ;;
    function<void(int, int)> calc_xor = [&](int cur, int parent) {
      xor_from_root[cur] = v[cur] ^ (parent == -1 ? 0 : xor_from_root[parent]);
      for (auto child : g[cur])
        if (child != parent)
          calc_xor(child, cur);
    };
    calc_xor(0, -1);
    ll ans = 0;
    function<void(int, int)> calc = [&](int cur, int parent) {
      bool bad = false;
      xor_set[cur].insert(xor_from_root[cur]);
      for (auto child : g[cur])
        if (child != parent) {
          calc(child, cur);
          ;;
          if (xor_set[cur].size() < xor_set[child].size()) {
            xor_set[cur].swap(xor_set[child]); 

          }
          for (auto xor_value : xor_set[child]) {
            if (xor_set[cur].count(xor_value ^ v[cur])) {
              bad = true;
              break;
            }
          }
          ;;
          for (auto xor_value : xor_set[child]) {
            xor_set[cur].insert(xor_value);
          }
          ;;
          xor_set[child].clear(); 

        }
      if (bad) {
        ans++;
        xor_set[cur].clear();
        return;
      }
    };
    calc(0, -1);
    cout << ans << endl;
  }
  return 0;
}
