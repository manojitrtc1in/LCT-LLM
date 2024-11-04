#include <bits/stdc++.h>
#ifndef _LIB_MODULAR_INTEGER
#define _LIB_MODULAR_INTEGER
#include <bits/stdc++.h>
#ifndef _LIB_NUMBER_THEORY
#define _LIB_NUMBER_THEORY
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
namespace nt {
  int64_t inverse(int64_t a, int64_t b) {
    long long b0 = b, t, q;
    long long x0 = 0, x1 = 1;
    if (b == 1) return 1;
    while (a > 1) {
      q = a / b;
      t = b, b = a % b, a = t;
      t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return x1;
  }
}
}  


#endif

#if __cplusplus < 201300
#error required(c++14)
#endif

namespace lib {
  using namespace std;
namespace {
  template<typename T, T ...Mods>
  struct ModularIntegerBase {
    typedef ModularIntegerBase<T, Mods...> type;

    T x[sizeof...(Mods)];
    friend ostream& operator<<(ostream& output, const type& var) {
      output << "(";
      for(int i = 0; i < sizeof...(Mods); i++) {
        if(i) output << ", ";
        output << var.x[i];
      }
      return output << ")";
    }
  };

  template<typename T, T Mod>
  struct ModularIntegerBase<T, Mod> {
    typedef ModularIntegerBase<T, Mod> type;

    T x[1];

    explicit operator int() const { return this->x[0]; }
    explicit operator long long() const { return this->x[0]; }
    explicit operator double() const { return this->x[0]; }
    explicit operator long double() const { return this->x[0]; }
    friend ostream& operator<<(ostream& output, const type& var) {
      return output << var.x[0];
    }
  };


  template<typename T, class Enable, T ...Mods>
  struct ModularIntegerImpl : ModularIntegerBase<T, Mods...> {
    typedef ModularIntegerImpl<T, Enable, Mods...> type;
    typedef T type_int;
    typedef int64_t large_int;
    const static size_t n_mods = sizeof...(Mods);

    struct Less {
      bool operator()(const type& lhs, const type& rhs) const {
        for(size_t i = 0; i < sizeof...(Mods); i++)
          if(lhs.x[i] != rhs.x[i])
            return lhs.x[i] < rhs.x[i];
        return false;
      };
    };
    typedef Less less;

    constexpr static T mods[sizeof...(Mods)] = {Mods...};
    using ModularIntegerBase<T, Mods...>::x;

    ModularIntegerImpl() {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] = T();
    }
    ModularIntegerImpl(large_int y) {
      for(size_t i = 0; i < sizeof...(Mods); i++) {
        x[i] = y % mods[i];
        if(x[i] < 0) x[i] += mods[i];
      }
    }
    static type with_remainders(T y[sizeof...(Mods)]) {
      type res;
      for(size_t i = 0; i < sizeof...(Mods); i++)
        res.x[i] = y[i];
      res.normalize();
      return res;
    }

    void normalize() {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        if((x[i] %= mods[i]) < 0)
          x[i] += mods[i];
    }

    inline T operator[](int i) const { return x[i]; }

    inline T multiply(T a, T b, T mod) const {
      return (large_int)a*b % mod;
    }

    inline T inv(T a, T mod) const {
      return static_cast<T>(nt::inverse(a, mod));
    }

    type inverse() const {
      T res[sizeof...(Mods)];
      for(size_t i = 0; i < sizeof...(Mods); i++)
        res[i] = inv(x[i], mods[i]);
      return type::with_remainders(res);
    }
    
    template<typename U>
    T power_(T a, U p, T mod) {
      if(mod == 1) return T();
      if(p < 0) {
        if(a == 0)
          throw domain_error("0^p with negative p is invalid");
        p = -p;
        a = inv(a, mod);
      }
      if(p == 0) return T(1);
      if(p == 1) return a;
      T res = 1;
      while(p > 0) {
        if(p&1)
          res = multiply(res, a, mod);
        p >>= 1;
        a = multiply(a, a, mod);
      }
      return res;
    }
 
    type& operator+=(const type& rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        (x[i] += rhs.x[i]) %= mods[i];
      return *this;
    }
    type& operator-=(const type& rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        if((x[i] -= rhs.x[i]) < 0)
          x[i] += mods[i];
      return *this;
    }
    type& operator*=(const type& rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] = multiply(x[i], rhs.x[i], mods[i]);
      return *this;
    }
    type& operator/=(const type& rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] = multiply(x[i], inv(rhs.x[i], mods[i]), mods[i]);
      return *this;
    }

    type& operator+=(T rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] += rhs;
      normalize();
      return *this;
    }
    
    type& operator-=(T rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] -= rhs;
      normalize();
      return *this;
    }

    type& operator*=(T rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] = multiply(x[i], rhs, mods[i]);
      return *this;
    }

    type& operator/=(T rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] = multiply(inv(rhs, mods[i]), x[i], mods[i]);
      return *this;
    }

    type& operator^=(large_int p) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        x[i] = power_(x[i], p, mods[i]);
      return *this;
    }

    type& operator++() {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        if((++x[i]) >= mods[i])
          x[i] -= mods[i];
      return *this;
    }
    type& operator--() {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        if((--x[i]) < 0)
          x[i] += mods[i];
      return *this;
    }
    type operator++(int unused) { type res = *this; ++(*this); return res; }
    type operator--(int unused) { type res = *this; --(*this); return res; }

    friend type operator+(const type& lhs, const type& rhs) {
      type res = lhs;
      return res += rhs;
    }
    friend type operator-(const type& lhs, const type& rhs) {
      type res = lhs;
      return res -= rhs;
    }
    friend type operator*(const type& lhs, const type& rhs) {
      type res = lhs;
      return res *= rhs;
    }
    friend type operator/(const type& lhs, const type& rhs) {
      type res = lhs;
      return res /= rhs;
    }

    friend type operator+(const type& lhs, T rhs) {
      type res = lhs;
      return res += rhs;
    }
    
    friend type operator-(const type& lhs, T rhs) {
      type res = lhs;
      return res -= rhs;
    }

    friend type operator*(const type& lhs, T rhs) {
      type res = lhs;
      return res *= rhs;
    }
    
    friend type operator/(const type& lhs, T rhs) {
      type res = lhs;
      return res /= rhs;
    }

    friend type operator^(const type& lhs, large_int rhs) {
      type res = lhs;
      return res ^= rhs;
    }

    friend type power(const type& lhs, large_int rhs) {
      return lhs ^ rhs;
    }

    type operator-() const {
      type res = *this;
      for(size_t i = 0; i < sizeof...(Mods); i++)
        if(res.x[i])
          res.x[i] = mods[i] - res.x[i];
      return res;
    }

    friend bool operator==(const type& lhs, const type& rhs) {
      for(size_t i = 0; i < sizeof...(Mods); i++)
        if(lhs.x[i] != rhs.x[i])
          return false;
      return true;
    }
    friend bool operator!=(const type& lhs, const type& rhs) {
      return !(lhs == rhs);
    }
 
    friend istream& operator>>(istream& input, type& var) {
      T y; cin >> y;
      var = y;
      return input;
    }
  };
}

  

  template<typename T, class Enable, T ...Mods>
  constexpr T ModularIntegerImpl<T, Enable, Mods...>::mods[];
 
  template<typename T, T ...Mods>
  using ModularInteger = 
    ModularIntegerImpl<T,
                       typename enable_if<is_integral<T>::value>::type,
                       Mods...>;
 
  template<int32_t ...Mods>
  using Mint32 = ModularInteger<int32_t, Mods...>;

  template<int64_t ...Mods>
  using Mint64 = ModularInteger<int64_t, Mods...>;
}  


#endif
#ifndef _LIB_SEGTREE_NORMAL
#define _LIB_SEGTREE_NORMAL
#include <bits/stdc++.h>
#ifndef _LIB_SEGTREE_BEATS
#define _LIB_SEGTREE_BEATS
#include <bits/stdc++.h>
#ifndef _LIB_SEGTREE
#define _LIB_SEGTREE
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
namespace seg {
  struct LeafBuilder {
    template<typename Node>
    void operator()(Node& no, int i) const {}
    inline pair<int, int> range() const { return {0, 0}; }
    bool should_build() const { return true; }
  };

  struct EmptyLeafBuilder : LeafBuilder {
    int n;
    explicit EmptyLeafBuilder(int n) : n(n) {}
    inline pair<int, int> range() const { return {0, n-1}; }
    bool should_build() const { return true; }
  };

  struct ImplicitBuilder : LeafBuilder {
    int L, R;
    explicit ImplicitBuilder(int L, int R) : L(L), R(R) {}
    inline pair<int, int> range() const { return {L, R}; }
    bool should_build() const { return false; }
  };

  

  template<typename DefaultNode>
  struct ImplicitWithDefaultBuilder : LeafBuilder {
    int L, R;
    DefaultNode default_node;
    explicit ImplicitWithDefaultBuilder(int L, int R, DefaultNode def) : L(L), R(R), default_node(def) {}

    template<typename Node>
    inline void operator()(Node& no, int i) const { no = default_node; }

    inline pair<int, int> range() const { return {L, R}; }
    bool should_build() const { return false; }
  };

  template<typename RandomIterator>
  struct RangeLeafBuilder : LeafBuilder {
    RandomIterator begin, end;
    explicit RangeLeafBuilder(RandomIterator begin, RandomIterator end)
      : begin(begin), end(end) {}

    template<typename Node>
    inline void operator()(Node& no, int i) const { no = *(begin + i); }

    inline pair<int, int> range() const { return {0, end-begin-1}; }
  };

  EmptyLeafBuilder make_builder(int n) { return EmptyLeafBuilder(n); }

  template<typename RandomIterator>
  RangeLeafBuilder<RandomIterator> make_builder(RandomIterator begin, 
                                                RandomIterator end) {
    return RangeLeafBuilder<RandomIterator>(begin, end);
  }

  template<typename T>
  RangeLeafBuilder<typename vector<T>::const_iterator>
  make_builder(const vector<T>& v) {
    return RangeLeafBuilder<typename vector<T>::const_iterator>(v.begin(), 
                                                                v.end());
  }

  template<typename T>
  struct CombineFolder {
    inline T operator()() const { return T(); }

    template<typename Node>
    inline T operator()(const Node& no) const { return T(no); }

    inline T operator()(const T& a, const T& b) const { return a + b; }
  };

  template<typename T>
  struct EmptyFolder : CombineFolder<T> {
    using CombineFolder<T>::operator();

    template<typename Node>
    inline T operator()(const Node& no) const { return T(); }
    inline T operator()(const T& a, const T& b) const { return T(); }
  };

  template<typename T>
  struct SumFolder : CombineFolder<T> {};

  template<typename T>
  struct ProductFolder : CombineFolder<T> {
    using CombineFolder<T>::operator();
    inline T operator()() const { return T(1); }
    inline T operator()(const T& a, const T& b) const { return a*b; }
  };
  
  template<typename T>
  struct MaxFolder : CombineFolder<T> {
    using CombineFolder<T>::operator();
    inline T operator()() const { return numeric_limits<T>::min(); }
    inline T operator()(const T& a, const T& b) const { return max(a, b); }
  };

  template<typename T>
  struct MinFolder : CombineFolder<T> {
    using CombineFolder<T>::operator();
    inline T operator()() const { return numeric_limits<T>::max(); }
    inline T operator()(const T& a, const T& b) const { return min(a, b); }
  };

  template<typename T>
  struct SingleValueUpdater {
    T value;
    explicit SingleValueUpdater(T val) : value(val) {}
  };

  template<typename T>
  struct SetUpdater : SingleValueUpdater<T> {
    using SingleValueUpdater<T>::SingleValueUpdater;

    template<typename Node>
    inline void operator()(Node& no) const { no = this->value; }
  };

  template<typename T>
  struct AddUpdater: SingleValueUpdater<T> {
    using SingleValueUpdater<T>::SingleValueUpdater;

    template<typename Node>
    inline void operator()(Node& no) const { no += this->value; }
  };

  template<typename T>
  struct MultUpdater: SingleValueUpdater<T> {
    using SingleValueUpdater<T>::SingleValueUpdater;

    template<typename Node>
    inline void operator()(Node& no) const { no *= this->value; }
  };

  struct EmptyPushdown {
    template<typename Node>
    inline bool dirty(const Node& no) const { return false; }

    template<typename Node>
    inline void operator()(Node& no, int l, int r, 
                    Node* ln, Node* rn) const {}
  };
}  

}  


#endif

namespace lib {
  using namespace std;
namespace seg { 
  struct DefaultBreakCond {
    template<typename Node>
    inline bool operator()(const Node& no, int l, int r, int i, int j) const {
      return i > r || j < l;
    }
  };

  struct DefaultTagCond {
    template<typename Node>
    inline bool operator()(const Node& no, int l, int r, int i, int j) const {
      return i <= l && r <= j;
    }
  };

  template<typename T>
  struct SearchResult {
    bool found;
    int pos;
    T value;

    static SearchResult<T> not_found(T acc = T()) {
      return {false, 0, acc};
    }
  };

  struct PrefixSearch;
  struct SuffixSearch;

  template<typename Direction>
  using IsSuffix = is_same<Direction, SuffixSearch>;

  template<typename Node>
  struct InMemoryNodeManager {
    typedef int vnode;
    vector<Node> t;

    template<typename Builder>
    void initialize(const Builder& builder) {
      int L, R;
      tie(L, R) = builder.range();
      t = vector<Node>(4 * (R - L + 1));
    }

    inline bool has(vnode no) { return true; }
    inline vnode root() { return 1; }
    inline vnode new_root(vnode no) { return no; }
    inline vnode left(vnode no) { return no << 1; }
    inline vnode right(vnode no) { return no << 1 | 1; }
    inline Node& ref(vnode no) { return t[no]; }
    inline Node* ptr(vnode no) { return &t[no]; }
    inline Node value(vnode no) { return t[no]; }

    inline vnode persist(vnode no) { return no; }
    inline void ensure_left(vnode no) {}
    inline void ensure_right(vnode no) {}
  };

  template<typename Node, 
           typename NodeManager,
           typename CombinerFn = EmptyFolder<int>,
           typename PushdownFn = EmptyPushdown, 
           typename BreakCond = DefaultBreakCond, 
           typename TagCond = DefaultTagCond>
  struct SegtreeImpl {
    typedef typename NodeManager::vnode vnode;
    constexpr static bool has_lazy = !is_same<PushdownFn, EmptyPushdown>::value;
    constexpr static bool is_implicit = !is_same<NodeManager, InMemoryNodeManager<Node>>::value;

    CombinerFn combiner_fn;
    PushdownFn pushdown_fn;
    BreakCond break_cond;
    TagCond tag_cond;
    NodeManager manager;

    int L, R;

    template<typename Builder>
    explicit SegtreeImpl(const Builder& builder) {
      tie(L, R) = builder.range();
      assert(L <= R);
      manager.initialize(builder);
      if(builder.should_build())
        build(builder);
    }

    inline vnode root() { return manager.root(); }
    inline int split(int l, int r) { return l + (r-l)/2; }

    template<typename Builder>
    vnode build(const Builder& builder, vnode no, int l, int r) {
      no = manager.persist(no);
      if(l == r) {
        builder(manager.ref(no), l);
      } else {
        int mid = split(l, r);
        build(builder, manager.left(no), l, mid);
        build(builder, manager.right(no), mid+1, r);
        manager.ref(no) = combiner_fn(manager.value(manager.left(no)), 
                                      manager.value(manager.right(no)));
      }
      return no;
    }

    template<typename Builder>
    vnode build(const Builder& builder) {
      return manager.new_root(build(builder, root(), L, R));
    }

    inline int size() const { return R-L+1; }

    void push(vnode no, int l, int r) {
      if(!pushdown_fn.dirty(no)) return;
      manager.ensure_left(no);
      manager.ensure_right(no);
      Node* left = l == r ? nullptr : manager.ptr(manager.left(no));
      Node* right = l == r ? nullptr : manager.ptr(manager.right(no));
      pushdown_fn(manager.ref(no), l, r, left, right);
    }

    template<typename T, typename Folder>
    T query(vnode no, int l, int r, int i, int j, const Folder& folder) {
      if(!manager.has(no))
        return folder();
      if(j < l || i > r) return folder();
      if(has_lazy)
        push(no, l, r);
      if(i <= l && r <= j) return folder(manager.ref(no));
      int mid = split(l, r);
      return folder(
          query<T>(manager.left(no), l, mid, i, j, folder),
          query<T>(manager.right(no), mid+1, r, i, j, folder)
      );
    }

    template<typename T, typename Folder>
    inline T query(vnode root, int i, int j, const Folder& folder) {
      return query<T>(root, L, R, i, j, folder);
    }

    template<typename T, typename Folder>
    inline T query(int i, int j, const Folder& folder) {
      return query<T>(root(), i, j, folder);
    }

    template<typename Updater>
    vnode update(vnode no, int l, int r, int i, int j, const Updater& updater) {
      push(no, l, r);
      if(break_cond(manager.ref(no), l, r, i, j)) {
        return no;
      }
      no = manager.persist(no);
      if(tag_cond(manager.ref(no), l, r, i, j)) {
        updater(manager.ref(no));
        push(no, l, r);
        return no;
      }
      int mid = split(l, r);
      update(manager.left(no), l, mid, i, j, updater);
      update(manager.right(no), mid+1, r, i, j, updater);
      manager.ref(no) = combiner_fn(manager.value(manager.left(no)),
                                    manager.value(manager.right(no)));
      return no;
    }

    template<typename Updater>
    inline vnode update(vnode root, int i, int j, const Updater& updater) {
      return manager.new_root(update(root, L, R, i, j, updater));
    }

    template<typename Updater>
    inline vnode update(int i, int j, const Updater& updater) {
      return update(root(), i, j, updater);
    }

    template<typename Beater,
             typename U = NodeManager,
             typename enable_if<is_same<U, InMemoryNodeManager<Node>>::value>::type* = nullptr>
    void beat(vnode no, int l, int r, int i, int j, const Beater& beater) {
      push(no, l, r);
      if(break_cond(manager.ref(no), l, r, i, j) || beater.stop(manager.ref(no), l, r, i, j)) {
        return;
      }
      if(tag_cond(manager.ref(no), l, r, i, j) && beater.tag(manager.ref(no), l, r, i, j)) {
        beater(manager.ref(no));
        push(no, l, r);
        return;
      }
      int mid = split(l, r);
      beat(manager.left(no), l, mid, i, j, beater);
      beat(manager.right(no), mid+1, r, i, j, beater);
      manager.ref(no) = combiner_fn(manager.value(manager.left(no)),
                                    manager.value(manager.right(no)));
    }

    template<typename Beater>
    inline void beat(int i, int j, const Beater& beater) {
      beat(root(), L, R, i, j, beater);
    }

    template<typename T, typename Direction, typename Folder, typename Checker>
    SearchResult<T> bsearch_first(vnode no, int l, int r, int i, int j,
        const Folder& folder, const Checker& checker, T acc) {
      if(manager.has(no) && has_lazy)
        push(no, l, r);
      if(j < l || i > r) return SearchResult<T>::not_found(folder());
      if(!manager.has(no)) {
        auto value = folder(acc, folder());
        if(checker(value))
          return {true, IsSuffix<Direction>::value ? r : l, value};
        else
          return SearchResult<T>::not_found(folder());
      }
      int mid = split(l, r);
      if(i <= l && r <= j) {
        auto b_value = folder(acc, manager.value(no));
        if(!checker(b_value))
          return SearchResult<T>::not_found(manager.value(no));
        if(l == r)
          return {true, l, b_value};
      }
      if(!IsSuffix<Direction>::value) {
        auto res_left = bsearch_first<T, Direction>(
            manager.left(no), l, mid, i, j, folder, checker, acc);
        if(res_left.found)
          return res_left;
        return bsearch_first<T, Direction>(
            manager.right(no), mid+1, r, i, j, folder, checker,
            folder(acc, res_left.value));
      } else {
        auto res_right = bsearch_first<T, Direction>(
            manager.right(no), mid+1, r, i, j, folder, checker, acc);
        if(res_right.found)
          return res_right;
        return bsearch_first<T, Direction>(
            manager.left(no), l, mid, i, j, folder, checker,
            folder(acc, res_right.value));

      }
    }

    template<typename T, typename Direction, typename Folder, typename Checker>
    inline SearchResult<T> bsearch_first(vnode root, int i, int j,
        const Folder& folder, const Checker& checker) {
      auto res = bsearch_first<T, Direction>(
          root, L, R, i, j, folder, checker, folder());
      if(!res.found)
        res.pos = IsSuffix<Direction>::value ? i - 1 : j + 1;
      return res;
    }

    template<typename T, typename Direction, typename Folder, typename Checker>
    inline SearchResult<T> bsearch_first(int i, int j,
        const Folder& folder, const Checker& checker) {
      return bsearch_first<T, Direction>(root(), i, j, folder, checker);
    }

    template<typename T, typename Direction, typename Folder, typename Checker>
    inline SearchResult<T> bsearch_last(vnode root, int i, int j,
        const Folder& folder, const Checker& checker) {
      auto res = bsearch_first<T, Direction>(
          root, i, j, folder, [&checker](T x) { return !checker(x); });
      if(!IsSuffix<Direction>::value) {
        if(res.pos == i) res.found = false;
        res.pos--;
      } else {
        if(res.pos == j) res.found = false;
        res.pos++;
      }
      return res;
    }

    template<typename T, typename Direction, typename Folder, typename Checker>
    inline SearchResult<T> bsearch_last(int i, int j,
        const Folder& folder, const Checker& checker) {
      return bsearch_last<T, Direction>(root(), i, j, folder, checker);
    }
  };


  template<typename Node, 
           typename CombinerFn = EmptyFolder<int>,
           typename PushdownFn = EmptyPushdown, 
           typename BreakCond = DefaultBreakCond, 
           typename TagCond = DefaultTagCond>
  struct SegtreeBeats : SegtreeImpl<Node,
                                    InMemoryNodeManager<Node>,
                                    CombinerFn,
                                    PushdownFn,
                                    BreakCond,
                                    TagCond> {

    template<typename Builder>
    explicit SegtreeBeats(const Builder& builder)
     : SegtreeImpl<Node,
                  InMemoryNodeManager<Node>,
                  CombinerFn,
                  PushdownFn,
                  BreakCond,
                  TagCond>(builder) {} 
  };

  template<typename Node>
  using Explicit = InMemoryNodeManager<Node>;
}  

}  


#endif

namespace lib {
  using namespace std;
namespace seg { 
  template<typename Node,
           typename CombinerFn,
           typename NodeManager = Explicit<Node>>
  struct SegtreeNormal : SegtreeImpl<Node, NodeManager, CombinerFn> {
    typedef SegtreeImpl<Node, NodeManager, CombinerFn> Base;
    using Base::SegtreeImpl;
    using typename Base::vnode;
    using Base::combiner_fn;
    using Base::L;
    using Base::R;
    using Base::manager;
    using Base::split;

    template<typename Updater>
    vnode update_element(vnode no, int l, int r, int idx, const Updater& updater) {
      no = manager.persist(no);
      if(l == r)
        updater(manager.ref(no));
      else {
        int mid = split(l, r);
        if(idx <= mid)
          update_element(manager.left(no), l, mid, idx, updater);
        else
          update_element(manager.right(no), mid+1, r, idx, updater);
        auto left_no = manager.left(no);
        auto right_no = manager.right(no);
        auto left_value = manager.has(left_no) ? manager.value(left_no) : combiner_fn();
        auto right_value = manager.has(right_no) ? manager.value(right_no) : combiner_fn();
        manager.ref(no) = combiner_fn(left_value, right_value);
      }
      return no;
    }

    template<typename Updater>
    inline vnode update_element(vnode root, int idx, const Updater& updater) {
      return manager.new_root(update_element(root, L, R, idx, updater));
    }
    
    template<typename Updater>
    inline vnode update_element(int idx, const Updater& updater) {
      return update_element(this->root(), idx, updater);
    }
  };
}  

}  


#endif
#ifndef _LIB_SEGTREE_PERSISTENT
#define _LIB_SEGTREE_PERSISTENT
#include <bits/stdc++.h>
#ifndef _LIB_SEGTREE_IMPLICIT
#define _LIB_SEGTREE_IMPLICIT
#include <bits/stdc++.h>

namespace lib {
  using namespace std;
namespace seg {

  template<typename Node>
  struct ImplicitNodeManager {
    struct NodeWrapper {
      Node no;
      NodeWrapper* left = nullptr;
      NodeWrapper* right = nullptr;
      NodeWrapper() : no(1) {}
    };

    struct VirtualNode {
      NodeWrapper *cur = nullptr, **edge = nullptr;
    };

    typedef VirtualNode vnode;

    vnode r = {new NodeWrapper()};

    template<typename Builder>
    void initialize(const Builder& builder) {}

    inline bool has(vnode no) const { return no.cur; }
    inline vnode root() { return r; }
    inline vnode new_root(vnode no) { return r = no; }
    inline vnode left(vnode no) { return {no.cur->left, &(no.cur->left)}; }
    inline vnode right(vnode no) { return {no.cur->right, &(no.cur->right)}; }
    inline Node& ref(vnode no) { return no.cur->no; }
    inline Node* ptr(vnode no) { return &(no.cur->no); }
    inline Node value(vnode no) { return no.cur->no; }

    inline vnode persist(vnode no) {
      if(no.cur)
        return no;
      vnode res = no;
      res.cur = *res.edge = new NodeWrapper();
      return res;
    }
    inline void ensure_left(vnode no) {
      if(!no.cur->left)
        no.cur->left = new NodeWrapper();
    }
    inline void ensure_right(vnode no) {
      if(!no.cur->right)
        no.cur->right = new NodeWrapper();
    }
  };
 
  template<typename Node>
  using Implicit = ImplicitNodeManager<Node>;
}  

}  


#endif

namespace lib {
  using namespace std;
namespace seg {

  template<typename Node>
  struct PersistentNodeManager : ImplicitNodeManager<Node> {
    using typename ImplicitNodeManager<Node>::vnode;
    using typename ImplicitNodeManager<Node>::NodeWrapper;

    inline vnode persist(vnode no) {
      vnode res = no;
      res.cur = no.cur ? new NodeWrapper(*no.cur) : new NodeWrapper();
      if(res.edge) *res.edge = res.cur;
      return res;
    }
  };
 
  template<typename Node>
  using Persistent = PersistentNodeManager<Node>;
}  

}  


#endif
using namespace std;
 
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ms(v, x) memset((v), (x), sizeof(v))
#define all(v) (v).begin(), (v).end()
#define ff first
#define ss second
#define iopt ios::sync_with_stdio(false); cin.tie(0)
 
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
int power(int x, int p, int MOD) {
    if(p == 0) return 1%MOD;
    if(p == 1) return x%MOD;
    int res = power(x, p/2, MOD);
    res = (long long)res*res%MOD;
    if(p&1) res = (long long)res*x%MOD;
    return res;
}
 
typedef pair<int, int> ii;
typedef long double LD;
typedef vector<int> vi;

using namespace lib;
const int MOD = (int)1e9+7;
using Mint = Mint32<MOD>;

const int N = 2e5+10;

vector<int> primes;
bool sv[N];
vector<ii> sta[N];

int32_t main(){
    iopt;
    for(int i = 2; i < N; i++) {
        if(!sv[i]) {
            primes.pb(i);
            for(int j = i+i; j < N; j+=i)
                sv[j] = true;
        }
    }

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    seg::ImplicitBuilder builder(0, n-1);
    seg::SegtreeNormal<Mint, seg::ProductFolder<Mint>, seg::Persistent<Mint>> tree(builder);
    seg::ProductFolder<Mint> folder;

    vector<decltype(tree)::vnode> vs;

    auto relax = [&](int i, int x, int cnt) {
        Mint xx = x;
        int cnt2 = 0;

        while(!sta[x].empty() && sta[x].back().ff <= cnt) {
            ii p = sta[x].back();
            Mint xx2 = xx^(p.ff-cnt2);
            tree.update_element(p.ss, seg::MultUpdater<Mint>(xx2.inverse()));
            sta[x].pop_back();
            if(!sta[x].empty())
                sta[x].back().ff += p.ff;
            cnt2 = p.ff;
        }

        if(!sta[x].empty()) {
            tree.update_element(sta[x].back().ss, seg::MultUpdater<Mint>((xx^(cnt-cnt2)).inverse()));
            sta[x].back().ff -= cnt;
        }
        sta[x].pb({cnt, i});
    };

    for(int i = 0; i < n; i++) {
        int o = a[i];
        for(int x : primes) {
            if(x*x > a[i]) break;
            if(a[i] % x) continue;
            int cnt = 0;
            while(a[i] % x == 0) {
                cnt++;
                a[i] /= x;
            }
            relax(i, x, cnt);
        }
        if(a[i] > 1) {
            relax(i, a[i], 1);
        }
        tree.update_element(i, seg::MultUpdater<Mint>(o));
        vs.pb(tree.root());
    }

    int q;
    cin >> q;
    int last = 0;
    while(q--) {
        int x, y;
        cin >> x >> y;
        int l = (last+x)%n;
        int r = (last+y)%n;
        if(l > r) swap(l, r);
        Mint res2 = tree.query<Mint>(vs[r], l, r, folder);
        last = int(res2);
        cout << res2 << endl;
    }
}
