#include <bits/stdc++.h>



#include <array>
#include <cstring>
#include <iostream>
#include <tuple>
struct IOPre {
  static constexpr int TEN = 10, SZ = TEN * TEN * TEN * TEN;
  std::array<char, 4 * SZ> num;
  constexpr IOPre() : num{} {
    for (int i = 0; i < SZ; i++) {
      int n = i;
      for (int j = 3; j >= 0; j--) {
        num[i * 4 + j] = static_cast<char>(n % TEN + '0');
        n /= TEN;
      }
    }
  }
};
struct IO {
#if !HAVE_DECL_FREAD_UNLOCKED
#define fread_unlocked fread
#endif
#if !HAVE_DECL_FWRITE_UNLOCKED
#define fwrite_unlocked fwrite
#endif
  static constexpr int SZ = 1 << 17, LEN = 32, TEN = 10, HUNDRED = TEN * TEN,
                       THOUSAND = HUNDRED * TEN, TENTHOUSAND = THOUSAND * TEN,
                       MAGIC_MULTIPLY = 205, MAGIC_SHIFT = 11, MASK = 15,
                       TWELVE = 12, SIXTEEN = 16;
  static constexpr IOPre io_pre = {};
  std::array<char, SZ> input_buffer, output_buffer;
  int input_ptr_left, input_ptr_right, output_ptr_right;
  IO()
      : input_buffer{},
        output_buffer{},
        input_ptr_left{},
        input_ptr_right{},
        output_ptr_right{} {}
  IO(const IO&) = delete;
  IO(IO&&) = delete;
  IO& operator=(const IO&) = delete;
  IO& operator=(IO&&) = delete;
  ~IO() { flush(); }
  template <class T>
  struct is_char {
    static constexpr bool value = std::is_same_v<T, char>;
  };
  template <class T>
  struct is_bool {
    static constexpr bool value = std::is_same_v<T, bool>;
  };
  template <class T>
  struct is_string {
    static constexpr bool value =
        std::is_same_v<T, std::string> || std::is_same_v<T, const char*> ||
        std::is_same_v<T, char*> || std::is_same_v<std::decay_t<T>, char*>;
    ;
  };
  template <class T, class D = void>
  struct is_custom {
    static constexpr bool value = false;
  };
  template <class T>
  struct is_custom<T, std::void_t<typename T::internal_value_type>> {
    static constexpr bool value = true;
  };
  template <class T>
  struct is_default {
    static constexpr bool value = is_char<T>::value || is_bool<T>::value ||
                                  is_string<T>::value || std::is_integral_v<T>;
  };
  template <class T, class D = void>
  struct is_iterable {
    static constexpr bool value = false;
  };
  template <class T>
  struct is_iterable<
      T, typename std::void_t<decltype(std::begin(std::declval<T>()))>> {
    static constexpr bool value = true;
  };
  template <class T, class D = void, class E = void>
  struct is_applyable {
    static constexpr bool value = false;
  };
  template <class T>
  struct is_applyable<T, std::void_t<typename std::tuple_size<T>::type>,
                      std::void_t<decltype(std::get<0>(std::declval<T>()))>> {
    static constexpr bool value = true;
  };
  template <class T>
  static constexpr bool needs_newline = (is_iterable<T>::value ||
                                         is_applyable<T>::value) &&
                                        (!is_default<T>::value);
  template <typename T, typename U>
  struct any_needs_newline {
    static constexpr bool value = false;
  };
  template <typename T>
  struct any_needs_newline<T, std::index_sequence<>> {
    static constexpr bool value = false;
  };
  template <typename T, std::size_t I, std::size_t... Is>
  struct any_needs_newline<T, std::index_sequence<I, Is...>> {
    static constexpr bool value =
        needs_newline<decltype(std::get<I>(std::declval<T>()))> ||
        any_needs_newline<T, std::index_sequence<Is...>>::value;
  };
  inline void load() {
    memcpy(std::begin(input_buffer), std::begin(input_buffer) + input_ptr_left,
            input_ptr_right - input_ptr_left);
    input_ptr_right =
        input_ptr_right - input_ptr_left +
        static_cast<int>(fread_unlocked(
            std::begin(input_buffer) + input_ptr_right - input_ptr_left, 1,
            SZ - input_ptr_right + input_ptr_left, stdin));
    input_ptr_left = 0;
  }
  inline void read_char(char& c) {
    if (input_ptr_left + LEN > input_ptr_right) load();
    c = input_buffer[input_ptr_left++];
  }
  inline void read_string(std::string& x) {
    char c;
    while (read_char(c), c < '!') continue;
    x = c;
    while (read_char(c), c >= '!') x += c;
  }
  template <class T>
  inline std::enable_if_t<std::is_integral_v<T>, void> read_int(T& x) {
    if (input_ptr_left + LEN > input_ptr_right) load();
    char c = 0;
    do c = input_buffer[input_ptr_left++];
    while (c < '-');
    [[maybe_unused]] bool minus = false;
    if constexpr (std::is_signed<T>::value == true)
      if (c == '-') minus = true, c = input_buffer[input_ptr_left++];
    x = 0;
    while (c >= '0')
      x = x * TEN + (c & MASK), c = input_buffer[input_ptr_left++];
    if constexpr (std::is_signed<T>::value == true)
      if (minus) x = -x;
  }
  inline void skip_space() {
    if (input_ptr_left + LEN > input_ptr_right) load();
    while (input_buffer[input_ptr_left] <= ' ') input_ptr_left++;
  }
  inline void flush() {
    fwrite_unlocked(std::begin(output_buffer), 1, output_ptr_right, stdout);
    output_ptr_right = 0;
  }
  inline void write_char(char c) {
    if (output_ptr_right > SZ - LEN) flush();
    output_buffer[output_ptr_right++] = c;
  }
  inline void write_bool(bool b) {
    if (output_ptr_right > SZ - LEN) flush();
    output_buffer[output_ptr_right++] = b ? '1' : '0';
  }
  inline void write_string(const std::string& s) {
    for (auto x : s) write_char(x);
  }
  inline void write_string(const char* s) {
    while (*s) write_char(*s++);
  }
  inline void write_string(char* s) {
    while (*s) write_char(*s++);
  }
  template <typename T>
  inline std::enable_if_t<std::is_integral_v<T>, void> write_int(T x) {
    if (output_ptr_right > SZ - LEN) flush();
    if (!x) {
      output_buffer[output_ptr_right++] = '0';
      return;
    }
    if constexpr (std::is_signed<T>::value == true)
      if (x < 0) output_buffer[output_ptr_right++] = '-', x = -x;
    int i = TWELVE;
    std::array<char, SIXTEEN> buf{};
    while (x >= TENTHOUSAND) {
      memcpy(std::begin(buf) + i,
             std::begin(io_pre.num) + (x % TENTHOUSAND) * 4, 4);
      x /= TENTHOUSAND;
      i -= 4;
    }
    if (x < HUNDRED) {
      if (x < TEN) {
        output_buffer[output_ptr_right++] = static_cast<char>('0' + x);
      } else {
        std::uint32_t q =
            (static_cast<std::uint32_t>(x) * MAGIC_MULTIPLY) >> MAGIC_SHIFT;
        std::uint32_t r = static_cast<std::uint32_t>(x) - q * TEN;
        output_buffer[output_ptr_right] = static_cast<char>('0' + q);
        output_buffer[output_ptr_right + 1] = static_cast<char>('0' + r);
        output_ptr_right += 2;
      }
    } else {
      if (x < THOUSAND) {
        memcpy(std::begin(output_buffer) + output_ptr_right,
               std::begin(io_pre.num) + (x << 2) + 1, 3),
            output_ptr_right += 3;
      } else {
        memcpy(std::begin(output_buffer) + output_ptr_right,
               std::begin(io_pre.num) + (x << 2), 4),
            output_ptr_right += 4;
      }
    }
    memcpy(std::begin(output_buffer) + output_ptr_right,
           std::begin(buf) + i + 4, TWELVE - i);
    output_ptr_right += TWELVE - i;
  }
  template <typename T_>
  IO& operator<<(T_&& x) {
    using T =
        typename std::remove_cv<typename std::remove_reference<T_>::type>::type;
    static_assert(is_custom<T>::value or is_default<T>::value or
                  is_iterable<T>::value or is_applyable<T>::value);
    if constexpr (is_custom<T>::value) {
      write_int(x.get());
    } else if constexpr (is_default<T>::value) {
      if constexpr (is_bool<T>::value) {
        write_bool(x);
      } else if constexpr (is_string<T>::value) {
        write_string(x);
      } else if constexpr (is_char<T>::value) {
        write_char(x);
      } else if constexpr (std::is_integral_v<T>) {
        write_int(x);
      }
    } else if constexpr (is_iterable<T>::value) {
      using E = decltype(*std::begin(x));
      constexpr char sep = needs_newline<E> ? '\n' : ' ';
      int i = 0;
      for (const auto& y : x) {
        if (i++) write_char(sep);
        operator<<(y);
      }
    } else if constexpr (is_applyable<T>::value) {
      constexpr char sep =
          (any_needs_newline<
              T, std::make_index_sequence<std::tuple_size_v<T>>>::value)
              ? '\n'
              : ' ';
      int i = 0;
      std::apply(
          [this, &sep, &i](auto const&... y) {
            (((i++ ? write_char(sep) : void()), this->operator<<(y)), ...);
          },
          x);
    }
    return *this;
  }
  template <typename T>
  IO& operator>>(T& x) {
    static_assert(is_custom<T>::value or is_default<T>::value or
                  is_iterable<T>::value or is_applyable<T>::value);
    static_assert(!is_bool<T>::value);
    if constexpr (is_custom<T>::value) {
      typename T::internal_value_type y;
      read_int(y);
      x = y;
    } else if constexpr (is_default<T>::value) {
      if constexpr (is_string<T>::value) {
        read_string(x);
      } else if constexpr (is_char<T>::value) {
        read_char(x);
      } else if constexpr (std::is_integral_v<T>) {
        read_int(x);
      }
    } else if constexpr (is_iterable<T>::value) {
      for (auto& y : x) operator>>(y);
    } else if constexpr (is_applyable<T>::value) {
      std::apply([this](auto&... y) { ((this->operator>>(y)), ...); }, x);
    }
    return *this;
  }
  IO* tie(std::nullptr_t) { return this; }
  void sync_with_stdio(bool) {}
};
namespace std {
IO io;
}  

#define cin io
#define cout io




#include <algorithm>
#include <array>


#include <map>
#include <tuple>
#include <utility>
template<class T>
class AnyMap {
  static int instance_count;
  const int instance_id_;
  T default_value_;
 public:
  AnyMap(T default_value = T())
      : instance_id_(instance_count++), default_value_(std::move(default_value)) {}
  template <class... Args>
  auto &operator()(Args &&...args) {
    using Tuple =
        decltype(std::make_tuple(instance_id_, std::forward<Args>(args)...));
    static std::map<Tuple, T> map;
    auto [it, placed] = map.emplace(
        Tuple{instance_id_, std::forward<Args>(args)...}, default_value_);
    return it->second;
  }
};
template<class T>
int AnyMap<T>::instance_count = 0;

#include <limits>


#include <iostream>
#ifdef ENABLE_DEBUG
#define LOCAL_ASSERT(condition, message)            \
  if (!(condition)) {                               \
    std::cerr << "Assertion (" << #condition        \
              << ") failed\non line " << __LINE__   \
              << " in " << __FILE__                 \
              << '#' << __FUNCTION__ << "()\n";     \
    std::cerr << message << '\n';                   \
    abort();                                        \
  }
#else
#define LOCAL_ASSERT(...) do {} while (0);
#endif
#define LOCAL_ASSERT_IN_RANGE(variable, low, high)  \
  LOCAL_ASSERT(low <= variable && variable <= high, \
               #variable << '=' << variable         \
               << " is out of the range "           \
               << '[' << low << ", " << high << ']')


#include <numeric>
#include <string>
#include <tuple>




#include <cstdint>
using i8 = int8_t;
using u8 = uint8_t;
using i16 = int16_t;
using u16 = uint16_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using i128 = __int128_t;
using u128 = __uint128_t;


#include <random>
#include <chrono>
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
struct r_hash {
  static u64 splitmix64(u64 x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  template<class T>
  u64 operator()(const T &x) const;
  u64 operator()(u64 x) const {
    static const u64 FIXED_RANDOM = rng();
    return splitmix64(x + FIXED_RANDOM);
  }
};
template<class...Ts>
struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;
template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
struct {
  template<class T>
  operator T() {
    T x;
    std::cin >> x;
    return x;
  }
} in;


#include <vector>


struct LayeredNodeNameTranslator {
  const std::vector<int> layer_sizes;
  const std::vector<int> layer_sizes_prefix_sum;
  template <class... Args>
  LayeredNodeNameTranslator(Args &&...args)
      : layer_sizes{std::forward<Args>(args)...},
        layer_sizes_prefix_sum(get_prefix_sum(layer_sizes)) {}
  static std::vector<int> get_prefix_sum(const std::vector<int> &a) {
    std::vector<int> res(a.size() + 1);
    for (int i = 0; i < (int)a.size(); ++i) res[i + 1] = res[i] + a[i];
    return res;
  }
  
  int to_id(int layer_number, int index_in_layer) {
    LOCAL_ASSERT_IN_RANGE(layer_number, 0, (int)layer_sizes.size() - 1);
    LOCAL_ASSERT_IN_RANGE(index_in_layer, 0, layer_sizes[layer_number] - 1);
    return layer_sizes_prefix_sum[layer_number] + index_in_layer;
  }
  
  int to_id(int index_in_layer) { return to_id(0, index_in_layer); }
  std::array<int, 2> from_id(int id) {
    LOCAL_ASSERT_IN_RANGE(id, 0, layer_sizes_prefix_sum.back() - 1);
    auto it = std::upper_bound(layer_sizes_prefix_sum.begin(),
                               layer_sizes_prefix_sum.end(), id);
    LOCAL_ASSERT(it != layer_sizes_prefix_sum.begin(),
                 "oops, something is wrong with the internal binary search.");
    int layer_number = int(it - layer_sizes_prefix_sum.begin()) - 1;
    int index_in_layer = id - layer_sizes_prefix_sum[layer_number];
    return {layer_number, index_in_layer};
  }
  auto get_edge_group_descriptor(int from_layer, int to_layer) {
    std::vector<int> from_list(layer_sizes[from_layer]);
    std::iota(from_list.begin(), from_list.end(),
              layer_sizes_prefix_sum[from_layer]);
    auto is_in_to_layer =
        [begin = layer_sizes_prefix_sum[to_layer],
         end = layer_sizes_prefix_sum[to_layer + 1]](int index) {
          return begin <= index && index < end;
        };
    return std::make_pair(from_list, is_in_to_layer);
  }
};
struct AnyNodeNameTranslator {
  AnyMap<int> mp;
  int next_node_id;
  AnyNodeNameTranslator() : mp(-1), next_node_id(0) {}
  template <class... Args>
  int to_id(Args &&...args) {
    int &v = mp(std::forward<Args>(args)...);
    if (v == -1) v = next_node_id++;
    return v;
  }
};
template <class FlowType = long long, class CapType = FlowType,
          bool shuffle = false,
          class NodeNameTranslator = LayeredNodeNameTranslator>
class Flow {
  struct EdgeReference {
    Flow &flow;
    int i, j;
    void operator=(CapType w) { flow.make_edge(i, j, w); }
    FlowType max_flow() { return flow.max_flow(i, j); }
  };
  struct NodeReference {
    Flow &flow;
    int i;
    template <class... Args>
    EdgeReference operator()(Args &&...args) {
      return {flow, i,
              flow.node_name_translator.to_id(std::forward<Args>(args)...)};
    }
  };
 public:
  NodeNameTranslator node_name_translator;
  template <class... Args>
  Flow(Args &&...args) : node_name_translator(std::forward<Args>(args)...) {}
  std::vector<int> to;
  std::vector<CapType> cap;
  std::vector<std::basic_string<int>> graph;
  std::vector<int> bfs_graph, bfs_graph_outdegree, bfs_graph_start, queue,
      used_edge;
  std::vector<int> vis, dist;
  template <class... Args>
  NodeReference operator()(Args &&...args) {
    return NodeReference{
        *this, node_name_translator.to_id(std::forward<Args>(args)...)};
  }
  template <class... Args>
  std::vector<std::tuple<int, int, CapType, CapType>> get_edge_group(int x,
                                                                       int y) {
    auto [from, is_to] = node_name_translator.get_edge_group_descriptor(x, y);
    std::vector<std::tuple<int, int, CapType, CapType>> res;
    for (int i : from) {
      for (int eid : graph[i]) {
        int j = to[eid];
        if (!is_to(j)) continue;
        CapType current_flow = cap[eid ^ 1];
        CapType capacity = cap[eid] + current_flow;
        res.emplace_back(i, j, current_flow, capacity);
      }
    }
    return res;
  }
  
  void make_edge(int from_id, int to_id, CapType weight) {
    LOCAL_ASSERT(from_id != to_id, "Self-loops are not supported.")
    expand_graph(std::max(from_id, to_id) + 1);
    graph[from_id].push_back(cap.size());
    to.emplace_back(to_id);
    cap.push_back(weight);
    graph[to_id].push_back(cap.size());
    to.push_back(from_id);
    cap.push_back(0);
  }
  
  FlowType max_flow(int source_id, int sink_id) {
    expand_graph(std::max(source_id, sink_id) + 1);
    source_id_ = source_id;
    sink_id_ = sink_id;
    if constexpr (shuffle)
      for (auto &adj_list : graph)
        std::shuffle(adj_list.begin(), adj_list.end(), rng);
    FlowType ans = 0;
    FlowType to_add;
    while ((to_add = blocking_flow())) ans += to_add;
    return ans;
  }
 private:
  int source_id_, sink_id_;
  void expand_graph(int new_size) {
    while ((int)graph.size() < new_size) {
      graph.emplace_back();
      bfs_graph_outdegree.emplace_back();
      bfs_graph_start.emplace_back();
      vis.emplace_back();
      dist.emplace_back();
    }
  }
  
  FlowType blocking_flow() {
    init_bfs_graph();
    FlowType ans = 0;
    FlowType to_add;
    while ((to_add = dfs(source_id_, std::numeric_limits<CapType>::max())))
      ans += to_add;
    return ans;
  }
  void init_bfs_graph() {
    reset_bfs_graph();
    forward_bfs();
    backward_bfs();
    load_edges();
  }
  void reset_bfs_graph() {
    for (int i : queue) {
      vis[i] = 0;
      dist[i] = 0;
      bfs_graph_outdegree[i] = 0;
    }
    queue.clear();
  }
  void forward_bfs() {
    queue.push_back(source_id_);
    vis[source_id_] = 1;
    for (int qq = 0; qq < (int)queue.size(); ++qq) {
      int i = queue[qq];
      if (i == sink_id_) break;
      for (int eid : graph[i]) {
        if (!cap[eid]) continue;
        int j = to[eid];
        if (vis[j]) continue;
        vis[j] = 1;
        dist[j] = dist[i] + 1;
        queue.push_back(j);
      }
    }
  }
  void backward_bfs() {
    vis[sink_id_] = 0;
    bfs_graph_start[queue.back()] = 0;
    for (int qq = (int)queue.size() - 1; qq >= 0; --qq) {
      int j = queue[qq];
      if (qq + 1 < (int)queue.size()) {
        int nxt = queue[qq + 1];
        bfs_graph_start[j] = bfs_graph_start[nxt] + bfs_graph_outdegree[nxt];
        bfs_graph_outdegree[nxt] = 0;
      }
      if (vis[j]) continue;
      for (int eid : graph[j]) {
        if (!cap[eid ^ 1]) continue;
        int i = to[eid];
        if (dist[i] + 1 != dist[j]) continue;
        vis[i] = 0;
        ++bfs_graph_outdegree[i];
        used_edge.push_back(eid);
      }
    }
  }
  void load_edges() {
    bfs_graph.resize(bfs_graph_start[queue.front()] +
                     bfs_graph_outdegree[queue.front()]);
    bfs_graph_outdegree[queue.front()] = 0;
    while (used_edge.size()) {
      int rev_eid = used_edge.back();
      used_edge.pop_back();
      int i = to[rev_eid];
      bfs_graph[bfs_graph_start[i] + bfs_graph_outdegree[i]++] = rev_eid ^ 1;
    }
  }
  FlowType dfs(int current, CapType prefix_cap) {
    if (current == sink_id_) return prefix_cap;
    while (bfs_graph_outdegree[current]) {
      int eid = bfs_graph[bfs_graph_start[current] +
                          bfs_graph_outdegree[current] - 1];
      int next = to[eid];
      if (vis[next]) {
        --bfs_graph_outdegree[current];
        continue;
      }
      if (!cap[eid]) {
        --bfs_graph_outdegree[current];
        continue;
      }
      CapType here = dfs(next, std::min(prefix_cap, cap[eid]));
      if (!here) {
        --bfs_graph_outdegree[current];
        continue;
      }
      cap[eid] -= here;
      cap[eid ^ 1] += here;
      if (!cap[eid]) {
        if (!--bfs_graph_outdegree[current]) vis[current] = 1;
      }
      return here;
    }
    vis[current] = 1;
    return 0;
  }
};



using namespace std;
using std::cout;  

using u32 = uint32_t;
using u64 = uint64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vector<int> s(n), a(n);
  for (int &x : s) cin >> x;
  for (int &x : a) cin >> x;
  vector<array<int, 2>> es(m);
  for (auto &[i, j] : es) cin >> i >> j, --i, --j;

  for (auto [i, j] : es) {
    if (s[i] == 1) ++a[i];
    if (s[j] == 1) ++a[j];
  }

  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 || a[i] < 0) {
      cout << "NO\n";
      return 0;
    }
    a[i] /= 2;
  }

  enum { S, T, SPRIME, TPRIME };
  enum { _, EDGE, VERTEX };
  Flow<u64, u64> f(4, m, n);
  f(T)(S) = ~u32(0);

  auto demand = [&](auto &&...args) {
    return [&](auto &&...brgs) {
      return [&](auto &&cap) {
        f(args...)(TPRIME) = cap;
        f(SPRIME)(brgs...) = cap;
      };
    };
  };

  for (int e = 0; e < m; ++e) demand(S)(EDGE, e)(1);

  for (int e = 0; e < m; ++e) {
    auto [i, j] = es[e];
    f(EDGE, e)(VERTEX, i) = 1;
    f(EDGE, e)(VERTEX, j) = 1;
  }

  for (int i = 0; i < n; ++i) {
    if (s[i] == 0) {
      f(VERTEX, i)(T) = ~u32(0);
    } else if (s[i] == 1) {
      demand(VERTEX, i)(T)(a[i]);
    } else {
      assert(0 && "invalid s[i]");
    }
  }

  u64 saturation = m + accumulate(a.begin(), a.end(), u64(0));

  if (saturation != f(SPRIME)(TPRIME).max_flow()) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";

  for (auto [e, i, fwd, bak] : f.get_edge_group(EDGE, VERTEX)) {
    if (fwd != 0) {
      e = f.node_name_translator.from_id(e)[1];
      i = f.node_name_translator.from_id(i)[1];
      cout << es[e][i == es[e][0]] + 1 << ' ' << i + 1 << '\n';
    }
  }
}
