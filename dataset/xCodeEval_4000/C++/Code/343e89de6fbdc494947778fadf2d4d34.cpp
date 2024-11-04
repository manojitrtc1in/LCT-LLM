#line 1 "f.cpp"


#include <bits/stdc++.h>
#include <x86intrin.h>


#line 12 "/mnt/c/Users/tkmma/competitive_programming/CPBF/library/include/string/ac_machine.hpp"

struct _AcMachineNode {
  using id_type = int;
  using index_type = int;
  using char_type = char;
  using edge_type = std::unordered_map<char_type, index_type>;
  id_type id = -1;
  edge_type e;
  index_type fail = -1;
  void set_fail(index_type u, index_type f, _AcMachineNode &r) { fail = f; }
};
template <class Node> struct _AcMachine {
public:
  using value_type = std::string;
  using id_type = _AcMachineNode::id_type;
  using index_type = _AcMachineNode::index_type;
  using char_type = _AcMachineNode::char_type;
  std::vector<std::string> keys_;
  std::vector<Node> nodes_;

  index_type _go(index_type u, char_type c) const {
    auto &node = nodes_[u];
    auto it = node.e.find(c);
    if (it != node.e.end())
      return it->second;
    else
      return u == 0 ? 0 : -1;
  }
  template <typename It> void _build_trie(It begin, It end) {
    for (auto it = begin; it != end; ++it) {
      insert_key(*it);
    }
  }
  template <typename It> void _build(It begin, It end) {
    using traits = std::iterator_traits<It>;
    static_assert(
        std::is_convertible<typename traits::value_type, std::string>::value,
        "");
    static_assert(std::is_base_of<std::forward_iterator_tag,
                                  typename traits::iterator_category>::value,
                  "");

    build_trie(begin, end);
    build_fail();
  }

private:
  std::vector<id_type> _output_id(index_type u) const {
    std::vector<id_type> ret;
    while (u != 0) {
      if (nodes_[u].id != -1)
        ret.push_back(nodes_[u].id);
      u = nodes_[u].fail;
    }
    return ret;
  }

  std::vector<std::string> _output(index_type u) const {
    std::vector<std::string> ret;
    while (u != 0) {
      auto id = nodes_[u].id;
      if (id != -1)
        ret.push_back(keys_[id]);
      u = nodes_[u].fail;
    }
    return ret;
  }

public:
  _AcMachine() : nodes_(1) {}
  template <typename It> explicit _AcMachine(It begin, It end) {
    _build(begin, end);
  }
  _AcMachine(std::initializer_list<value_type> list)
      : _AcMachine(list.begin(), list.end()) {}

  index_type insert_key(const std::string &key) {
    index_type u = 0;
    size_t i;
    for (i = 0; i < key.size(); i++) {
      auto it = nodes_[u].e.find(key[i]);
      if (it == nodes_[u].e.end())
        break;
      u = it->second;
    }
    if (i == key.size())
      return u;
    for (; i < key.size(); i++) {
      auto next = nodes_.size();
      nodes_.emplace_back();
      nodes_[u].e[key[i]] = next;
      u = next;
    }
    nodes_[u].id = (id_type)keys_.size();
    keys_.push_back(key);
    return u;
  }
  index_type trans(index_type u, char_type c) const {
    index_type v;
    while ((v = _go(u, c)) == -1)
      u = nodes_[u].fail;
    return v;
  }
  index_type fail(index_type u) const { return nodes_[u].fail; }
  void build_fail() {
    std::queue<index_type> idx;
    for (auto s : nodes_[0].e) {
      index_type next = s.second;
      idx.push(next);
      nodes_[next].set_fail(next, 0, nodes_[0]);
    }
    while (!idx.empty()) {
      auto id = idx.front();
      idx.pop();
      for (auto s : nodes_[id].e) {
        char_type c = s.first;
        index_type next = s.second;
        idx.push(next);
        auto state = nodes_[id].fail;
        index_type target;
        while ((target = _go(state, c)) == -1)
          state = nodes_[state].fail;
        nodes_[next].set_fail(next, target, nodes_[target]);
      }
    }
  }
  std::vector<std::vector<std::string>> all_output() const {
    std::vector<std::vector<std::string>> res(nodes_.size());
    std::queue<index_type> idx;
    idx.push(0);
    while (!idx.empty()) {
      auto u = idx.front();
      idx.pop();
      res[u] = _output(u);
      for (auto s : nodes_[u].e) {
        idx.push(s.second);
      }
    }
    return res;
  }

  class key_iterator {
  public:
    using value_type = std::string;
    using reference = const value_type &;
    using pointer = const value_type *;
    using iterator_category = std::forward_iterator_tag;
    using difference_type = long long;

  private:
    const _AcMachine *ac_;
    index_type u_;
    void _forward_until_data() {
      while (u_ != 0 and ac_->nodes_[u_].id == -1) {
        u_ = ac_->nodes_[u_].fail;
      }
    }

  public:
    key_iterator() = default;
    explicit key_iterator(const _AcMachine *ac, index_type u) : ac_(ac), u_(u) {
      _forward_until_data();
    }
    index_type node() const { return u_; }
    reference operator*() const { return ac_->keys_[ac_->nodes_[u_].id]; }
    pointer operator->() const { return &ac_->keys_[ac_->nodes_[u_].id]; }
    bool operator==(const key_iterator &r) const { return u_ == r.u_; }
    bool operator!=(const key_iterator &r) const { return !(*this == r); }
    key_iterator &operator++() {
      u_ = ac_->nodes_[u_].fail;
      _forward_until_data();
      return *this;
    }
    key_iterator operator++(int) {
      key_iterator ret = *this;
      ++*this;
      return ret;
    }
  };
  key_iterator get_iterator(index_type u) const {
    return key_iterator(this, u);
  }
  key_iterator key_end() const { return get_iterator(0); }
  std::vector<std::pair<size_t, key_iterator>>
  find(const std::string &text) const {
    std::vector<std::pair<size_t, key_iterator>> ret;
    auto u = 0;
    for (size_t i = 0; i < text.size(); i++) {
      char_type c = text[i];
      index_type target;
      while ((target = _go(u, c)) == -1)
        u = nodes_[u].fail;
      u = target;
      if (u != 0) {
        auto out = key_iterator(this, u, 0);
        if (out != key_end())
          ret.emplace_back(i, out);
      }
    }
    return ret;
  }
  std::pair<std::pair<size_t, key_iterator>, bool>
  find_first(const std::string &text) const {
    auto u = 0;
    for (size_t i = 0; i < text.size(); i++) {
      char_type c = text[i];
      index_type target;
      while ((target = _go(u, c)) == -1)
        u = nodes_[u].fail;
      u = target;
      auto out = key_iterator(this, u);
      if (out != key_end())
        return {{i + 1, out}, true};
    }
    return {{}, false};
  }
  size_t root() const { return 0; }
  size_t node_size() const { return nodes_.size(); }
};
using AcMachine = _AcMachine<_AcMachineNode>;
#line 4 "/mnt/c/Users/tkmma/competitive_programming/CPBF/library/include/bit_manip.hpp"

namespace bm {

constexpr uint64_t popcnt_e8(uint64_t x) {
  x = (x & 0x5555555555555555) + ((x >> 1) & 0x5555555555555555);
  x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333);
  x = (x & 0x0F0F0F0F0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F0F0F0F0F);
  return x;
}


constexpr unsigned popcnt(uint64_t x) {
  return (popcnt_e8(x) * 0x0101010101010101) >> 56;
}


constexpr unsigned ctz(uint64_t x) { return popcnt((x & (-x)) - 1); }
constexpr unsigned ctz8(uint8_t x) {
  return x == 0 ? 8 : popcnt_e8((x & (-x)) - 1);
}


constexpr uint8_t summary(uint64_t x) {
  constexpr uint64_t hmask = 0x8080808080808080ull;
  constexpr uint64_t lmask = 0x7F7F7F7F7F7F7F7Full;
  auto a = x & hmask;
  auto b = x & lmask;
  b = hmask - b;
  b = ~b;
  auto c = (a | b) & hmask;
  c *= 0x0002040810204081ull;
  return uint8_t(c >> 56);
}


constexpr uint64_t bextr(uint64_t x, unsigned start, unsigned len) {
  uint64_t mask = len < 64 ? (1ull << len) - 1 : 0xFFFFFFFFFFFFFFFFull;
  return (x >> start) & mask;
}


constexpr unsigned log2p1(uint8_t x) {
  if (x & 0x80)
    return 8;
  uint64_t p = uint64_t(x) * 0x0101010101010101ull;
  p -= 0x8040201008040201ull;
  p = ~p & 0x8080808080808080ull;
  p = (p >> 7) * 0x0101010101010101ull;
  p >>= 56;
  return p;
}


constexpr unsigned mssb8(uint8_t x) {
  assert(x != 0);
  return log2p1(x) - 1;
}


constexpr unsigned lssb8(uint8_t x) {
  assert(x != 0);
  return popcnt_e8((x & -x) - 1);
}


constexpr unsigned clz(uint64_t x) {
  if (x == 0)
    return 64;
  auto i = mssb8(summary(x));
  auto j = mssb8(bextr(x, 8 * i, 8));
  return 63 - (8 * i + j);
}
constexpr unsigned clz8(uint8_t x) { return x == 0 ? 8 : 7 - mssb8(x); }
constexpr uint64_t bit_reverse(uint64_t x) {
  x = ((x & 0x00000000FFFFFFFF) << 32) | ((x & 0xFFFFFFFF00000000) >> 32);
  x = ((x & 0x0000FFFF0000FFFF) << 16) | ((x & 0xFFFF0000FFFF0000) >> 16);
  x = ((x & 0x00FF00FF00FF00FF) << 8) | ((x & 0xFF00FF00FF00FF00) >> 8);
  x = ((x & 0x0F0F0F0F0F0F0F0F) << 4) | ((x & 0xF0F0F0F0F0F0F0F0) >> 4);
  x = ((x & 0x3333333333333333) << 2) | ((x & 0xCCCCCCCCCCCCCCCC) >> 2);
  x = ((x & 0x5555555555555555) << 1) | ((x & 0xAAAAAAAAAAAAAAAA) >> 1);
  return x;
}

} 

#line 11 "f.cpp"
#define _overload3(_1, _2, _3, target, ...) target
#define _REP(i, l, r) for (int i = (l), i##_less = (r); i < i##_less; i++)
#define _rep(i, n) _REP(i, 0, n)
#define rep(args...) _overload3(args, _REP, _rep)(args)
#define _RREP(i, l, r) for (int i = (r)-1, i##_least = (l); i >= i##_least; i--)
#define _rrep(i, n) _RREP(i, 0, n)
#define rrep(args...) _overload3(args, _RREP, _rrep)(args)
#define chmax(dst, x) dst = max(dst, (x))
#define chmin(dst, x) dst = min(dst, (x))
using namespace std;
using lint = long long int;
using ulint = unsigned long long int;
template <typename T> using vvec = vector<vector<T>>;
template <typename T> vvec<T> make_vvec(int n, int m, T v) {
  return vvec<T>(n, vector<T>(m, v));
}
#if __cplusplus >= 201703L
template <typename... T> auto make_vvec(int n, T... args) {
  return vector(n, make_vvec(args...));
}
#endif
template <typename T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;

class Solver {
public:
  Solver();
  void solve();
};

Solver::Solver() {}

void Solver::solve() {
  int n;
  cin >> n;
  const int k = 12;
  unordered_map<int, int> C;
  AcMachine ac;
  rep(i, n) {
    int c;
    cin >> c;
    string s;
    cin >> s;
    vector<int> G(k);
    rep(u, s.size() - 1) {
      auto a = s[u] - 'a';
      auto b = s[u + 1] - 'a';
      G[a] |= 1 << b;
      G[b] |= 1 << a;
    }
    vector<int> D(k);
    rep(u, k) D[u] = bm::popcnt(G[u]);
    if (count(D.begin(), D.end(), 1) != 2 or
        *max_element(D.begin(), D.end()) > 2)
      continue;
    int u = find(D.begin(), D.end(), 1) - D.begin();
    int p = -1;
    string l;
    while (true) {
      l.push_back(char(u + 'a'));
      int v = bm::ctz(G[u]);
      if (v == p) {
        if (D[u] > 1)
          v = bm::ctz(G[u] ^ (1 << v));
        else
          break;
      }
      p = u;
      u = v;
    }
    

    C[ac.insert_key(l)] += c;
    reverse(l.begin(), l.end());
    C[ac.insert_key(l)] += c;
  }
  ac.build_fail();
  {
    queue<int> qs;
    qs.push(0);
    while (!qs.empty()) {
      int u = qs.front();
      qs.pop();
      for (auto [c, v] : ac.nodes_[u].e) {
        qs.push(v);
      }
      C[u] += C[ac.fail(u)];
    }
  }

  constexpr int MINF = -1e9;
  auto dp = make_vvec(1 << k, (int)ac.node_size(), MINF);
  dp[0][ac.root()] = 0;
  auto prev = make_vvec(1 << k, (int)ac.node_size(), make_pair(-1, -1));
  rep(i, 1 << k) {
    rep(u, ac.node_size()) if (dp[i][u] != MINF) {
      rep(c, 12) if ((i & (1 << c)) == 0) {
        int t = i | (1 << c);
        auto v = ac.trans(u, c + 'a');
        if (dp[t][v] < dp[i][u] + C[v]) {
          chmax(dp[t][v], dp[i][u] + C[v]);
          prev[t][v] = {i, u};
        }
      }
    }
  }
  int u = max_element(dp.back().begin(), dp.back().end()) - dp.back().begin();
  int m = (1 << k) - 1;
  string ans;
  while (m) {
    auto [nm, p] = prev[m][u];
    ans.push_back(bm::ctz(nm ^ m) + 'a');
    m = nm;
    u = p;
  }
  cout << ans << endl;
  

}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  Solver solver;
  int t = 1;
  

  while (t--) {
    solver.solve();
  }
  return 0;
}
