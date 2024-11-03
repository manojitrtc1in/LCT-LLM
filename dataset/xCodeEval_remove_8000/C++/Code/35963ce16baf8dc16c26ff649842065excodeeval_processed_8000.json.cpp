
using namespace std;
const int id1 = 0;
const int id0 = 1e9+5;
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;






namespace {
  using namespace std;
namespace seg {
  struct LeafBuilder {
    template<typename Node>
    void operator()(Node&, int) const {}
    inline pair<int, int> range() const { return {0, 0}; }
    bool should_build() const { return true; }
  };

  struct id20 : LeafBuilder {
    int n;
    explicit id20(int n) : n(n) {}
    inline pair<int, int> range() const { return {0, n-1}; }
    bool should_build() const { return true; }
  };

  struct ImplicitBuilder : LeafBuilder {
    int L, R;
    explicit ImplicitBuilder(int L, int R) : L(L), R(R) {}
    inline pair<int, int> range() const { return {L, R}; }
    bool should_build() const { return false; }
  };

  template<typename RandomIterator>
  struct id6 : LeafBuilder {
    RandomIterator begin, end;
    explicit id6(RandomIterator begin, RandomIterator end)
      : begin(begin), end(end) {}

    template<typename Node>
    inline void operator()(Node& no, int i) const { no = *(begin + i); }

    inline pair<int, int> range() const { return {0, end-begin-1}; }
  };

  id20 make_builder(int n) { return id20(n); }

  template<typename RandomIterator>
  id6<RandomIterator> make_builder(RandomIterator begin, 
                                                RandomIterator end) {
    return id6<RandomIterator>(begin, end);
  }

  template<typename T>
  id6<typename vector<T>::const_iterator>
  make_builder(const vector<T>& v) {
    return id6<typename vector<T>::const_iterator>(v.begin(), 
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
  struct DisabledCombiner {
    inline T operator()() const { throw std::runtime_error("Disabled combiner."); }

    template<typename Node>
    inline T operator()(const Node&) const { throw std::runtime_error("Disabled combiner."); }

    inline T operator()(const T&, const T&) const { throw std::runtime_error("Disabled combiner."); }
  };

  template<typename T>
  struct id15 {
    T value;
    explicit id15(T val) : value(val) {}
  };

  template<typename T>
  struct SetUpdater : id15<T> {
    using id15<T>::id15;

    template<typename Node>
    inline void operator()(Node& no) const { no = this->value; }
  };

  template<typename T>
  struct AddUpdater: id15<T> {
    using id15<T>::id15;

    template<typename Node>
    inline void operator()(Node& no) const { no += this->value; }
  };

  template<typename T>
  struct MinUpdater: id15<T> {
    using id15<T>::id15;

    template<typename Node>
    inline void operator()(Node& no) const { no = std::min(no, this->value); }
  };

  template<typename T>
  struct MaxUpdater: id15<T> {
    using id15<T>::id15;

    template<typename Node>
    inline void operator()(Node& no) const { no = std::max(no, this->value); }
  };

  struct EmptyPushdown {
    template<typename Node>
    inline void operator()(Node&, int, int, 
                    Node*, Node*) const {}
  };
}  

}  




namespace {
  using namespace std;
namespace seg { 
  struct DefaultBreakCond {
    template<typename Node>
    inline bool operator()(const Node&, int l, int r, int i, int j) const {
      return i > r || j < l;
    }
  };

  struct DefaultTagCond {
    template<typename Node>
    inline bool operator()(const Node&, int l, int r, int i, int j) const {
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

    

    const Node identity = Node();

    template<typename Builder>
    void initialize(const Builder& builder) {
      int L, R;
      tie(L, R) = builder.range();
      t = vector<Node>(4 * (R - L + 1));
    }

    inline bool has(vnode) { return true; }
    inline vnode root() { return 1; }
    inline vnode new_root(vnode no) { return no; }
    inline vnode left(vnode no) { return no << 1; }
    inline vnode right(vnode no) { return no << 1 | 1; }
    inline Node& ref(vnode no) { return t[no]; }
    inline Node* ptr(vnode no) { return &t[no]; }
    inline Node value(vnode no) { return t[no]; }

    inline vnode persist(vnode no) { return no; }
    inline void ensure_left(vnode) {}
    inline void ensure_right(vnode) {}
  };

  template<typename Node, 
           typename NodeManager,
           typename CombinerFn = EmptyFolder<int>,
           typename PushdownFn = EmptyPushdown, 
           typename BreakCond = DefaultBreakCond, 
           typename TagCond = DefaultTagCond>
  struct id10 {
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
    explicit id10(const Builder& builder) {
      tie(L, R) = builder.range();
      assert(L <= R);
      manager.initialize(builder);
      if(builder.should_build())
        build(builder);
    }

    template<typename Builder>
    explicit id10(const Builder& builder, const Node& identity)
        : manager(identity)
    {
      tie(L, R) = builder.range();
      assert(L <= R);
      manager.initialize(builder);
      if(builder.should_build())
        build(builder);
    }

    inline vnode root() { return manager.root(); }
    inline int split(int l, int r) { return l + (r-l)/2; }

    template<typename Builder>
    vnode build_raw(const Builder& builder, vnode no, int l, int r) {
      no = manager.persist(no);
      if(l == r) {
        builder(manager.ref(no), l);
      } else {
        int mid = split(l, r);
        build_raw(builder, manager.left(no), l, mid);
        build_raw(builder, manager.right(no), mid+1, r);
        manager.ref(no) = combiner_fn(manager.value(manager.left(no)), 
                                      manager.value(manager.right(no)));
      }
      return no;
    }

    template<typename Builder>
    vnode build(const Builder& builder) {
      return manager.new_root(build_raw(builder, root(), L, R));
    }

    inline int size() const { return R-L+1; }

    void push(vnode no, int l, int r) {
      manager.ensure_left(no);
      manager.ensure_right(no);
      Node* left = l == r ? nullptr : manager.ptr(manager.left(no));
      Node* right = l == r ? nullptr : manager.ptr(manager.right(no));
      pushdown_fn(manager.ref(no), l, r, left, right);
    }

    template<typename Folder>
    auto query_raw(vnode no, int l, int r, int i, int j, const Folder& folder) -> decltype(folder()) {
      if(j < l || i > r) return folder();
      if(!manager.has(no))
        return manager.identity;
      if(has_lazy)
        push(no, l, r);
      if(i <= l && r <= j) return folder(manager.ref(no));
      int mid = split(l, r);
      return folder(
          query_raw(manager.left(no), l, mid, i, j, folder),
          query_raw(manager.right(no), mid+1, r, i, j, folder)
      );
    }

    template<typename Folder>
    inline auto query(vnode root, int i, int j, const Folder& folder) -> decltype(folder()) {
      return query_raw(root, L, R, i, j, folder);
    }

    template<typename Folder>
    inline auto query(int i, int j, const Folder& folder) -> decltype(folder()) {
      return query(root(), i, j, folder);
    }

    inline auto query_combiner(vnode root, int i, int j) -> decltype(combiner_fn()) {
      return query(root, i, j, combiner_fn);
    }

    inline auto query_combiner(int i, int j) -> decltype(combiner_fn()) {
      return query(i, j, combiner_fn);
    }

    template<typename Updater>
    vnode update_raw(vnode no, int l, int r, int i, int j, const Updater& updater) {
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
      update_raw(manager.left(no), l, mid, i, j, updater);
      update_raw(manager.right(no), mid+1, r, i, j, updater);
      manager.ref(no) = combiner_fn(manager.value(manager.left(no)),
                                    manager.value(manager.right(no)));
      return no;
    }

    template<typename Updater>
    inline vnode update(vnode root, int i, int j, const Updater& updater) {
      return manager.new_root(update_raw(root, L, R, i, j, updater));
    }

    template<typename Updater>
    inline vnode update(int i, int j, const Updater& updater) {
      return update(root(), i, j, updater);
    }

    

    

    

    template<typename Updater>
    vnode id18(vnode no, int l, int r, int i, int j, const Updater& updater) {
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
      id18(manager.left(no), l, mid, i, j, updater);
      id18(manager.right(no), mid+1, r, i, j, updater);
      updater(manager.ref(no));
      return no;
    }

    template<typename Updater>
    inline vnode id19(vnode root, int i, int j, const Updater& updater) {
      return manager.new_root(id18(root, L, R, i, j, updater));
    }

    template<typename Updater>
    inline vnode id19(int i, int j, const Updater& updater) {
      return id19(root(), i, j, updater);
    }

    template<typename Beater,
             typename U = NodeManager,
             typename enable_if<is_same<U, InMemoryNodeManager<Node>>::value>::type* = nullptr>
    void beat_raw(vnode no, int l, int r, int i, int j, const Beater& beater) {
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
      beat_raw(manager.left(no), l, mid, i, j, beater);
      beat_raw(manager.right(no), mid+1, r, i, j, beater);
      manager.ref(no) = combiner_fn(manager.value(manager.left(no)),
                                    manager.value(manager.right(no)));
    }

    template<typename Beater>
    inline void beat(int i, int j, const Beater& beater) {
      beat_raw(root(), L, R, i, j, beater);
    }

    template<typename T, typename Direction, typename Folder, typename Checker>
    SearchResult<T> id16(vnode no, int l, int r, int i, int j,
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
        auto res_left = id16<T, Direction>(
            manager.left(no), l, mid, i, j, folder, checker, acc);
        if(res_left.found)
          return res_left;
        return id16<T, Direction>(
            manager.right(no), mid+1, r, i, j, folder, checker,
            folder(acc, res_left.value));
      } else {
        auto res_right = id16<T, Direction>(
            manager.right(no), mid+1, r, i, j, folder, checker, acc);
        if(res_right.found)
          return res_right;
        return id16<T, Direction>(
            manager.left(no), l, mid, i, j, folder, checker,
            folder(acc, res_right.value));

      }
    }

    template<typename T, typename Direction, typename Folder, typename Checker>
    inline SearchResult<T> id14(vnode root, int i, int j,
        const Folder& folder, const Checker& checker) {
      auto res = id16<T, Direction>(
          root, L, R, i, j, folder, checker, folder());
      if(!res.found)
        res.pos = IsSuffix<Direction>::value ? i - 1 : j + 1;
      return res;
    }

    template<typename T, typename Direction, typename Folder, typename Checker>
    inline SearchResult<T> id14(int i, int j,
        const Folder& folder, const Checker& checker) {
      return id16<T, Direction>(root(), i, j, folder, checker);
    }

    template<typename T, typename Direction, typename Folder, typename Checker>
    inline SearchResult<T> id4(vnode root, int i, int j,
        const Folder& folder, const Checker& checker) {
      auto res = id16<T, Direction>(
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
    inline SearchResult<T> id4(int i, int j,
        const Folder& folder, const Checker& checker) {
      return id4<T, Direction>(root(), i, j, folder, checker);
    }
  };


  template<typename Node, 
           typename CombinerFn = EmptyFolder<int>,
           typename PushdownFn = EmptyPushdown, 
           typename BreakCond = DefaultBreakCond, 
           typename TagCond = DefaultTagCond>
  struct id7 : id10<Node,
                                    InMemoryNodeManager<Node>,
                                    CombinerFn,
                                    PushdownFn,
                                    BreakCond,
                                    TagCond> {

    template<typename Builder>
    explicit id7(const Builder& builder)
     : id10<Node,
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




namespace {
  using namespace std;
namespace seg {
  template<typename Node, typename CombinerFn>
  struct id12 {
    const static int MULTIPLIER = 2;

    CombinerFn combiner_fn;

    vector<Node> t;
    int L, n;

    template<typename Builder>
    explicit id12(const Builder& builder) {
      pair<int, int> range = builder.range();
      L = range.first;
      n = range.second - range.first + 1;
      assert(n > 0);
      t = vector<Node>(n * MULTIPLIER);
      build(builder);
    }

    template<typename Builder>
    void build(const Builder& builder) {
      for(int i = n; i < 2*n; i++)
        builder(t[i], L + i - n);
      for(int i = n-1; i > 0; i--)
        t[i] = combiner_fn(t[i<<1], t[i<<1|1]);
    }

    template<typename Rebuilder>
    void rebuild(const Rebuilder& rebuilder) {
      for(int i = n; i < 2*n; i++)
        rebuilder(t[i]);
      for(int i = n-1; i > 0; i--)
        rebuilder(t[i], t[i<<1], t[i<<1|1]);
    }
  };

  template<typename Node, typename CombinerFn>
  struct SegtreeFast : id12<Node, CombinerFn> {
    typedef id12<Node, CombinerFn> Base;
    using Base::id12;
    using Base::combiner_fn;
    using Base::n;
    using Base::t;
    using Base::L;

    template<typename Updater>
    void update_element(int i, const Updater& updater)  {
      i -= L;
      assert(i >= 0);
      for(updater(t[i += n]); i /= 2; )
        t[i] = combiner_fn(t[i<<1], t[i<<1|1]);
    }

    inline void update_element_combiner(int idx, const Node& rhs) {
      auto updater = [&](Node& lhs) {
        lhs = combiner_fn(lhs, rhs);
      };
      update_element(idx, updater);
    }

    template<typename T, typename Folder>
    T query(int i, int j, const Folder& folder) {
      

      i -= L, j -= L;
      assert(i >= 0 && j >= 0);
      i += n, j += n;
      if(i == j) return folder(t[i]);
      T resl = folder(t[i]), resr = folder(t[j]);

      

      i++;
      while(i < j) {
        if(i&1)
          resl = folder(resl, folder(t[i++]));
        if(j&1)
          resr = folder(folder(t[--j]), resr);
        i /= 2, j /= 2;
      }

      return folder(resl, resr);
    }
  };

  template<typename Node>
  struct SegtreeFastSplash : id12<Node, EmptyFolder<Node>> {
    typedef id12<Node, EmptyFolder<Node>> Base;
    using Base::id12;
    using Base::n;
    using Base::t;
    using Base::L;

    template<typename T, typename Folder>
    T query_element(int i, const Folder& folder)  {
      i -= L;
      assert(i >= 0);
      T res = folder(t[i += n]);
      while(i /= 2) {
        res = folder(folder(t[i]), res);
      }
      return res;
    }

    template<typename Updater>
    void splash(int i, int j, const Updater& updater) {
      

      i -= L, j -= L;
      assert(i >= 0 && j >= 0);
      

      i += n, j += n+1;

      while(i < j) {
        if(i&1)
          updater(t[i++]);
        if(j&1)
          updater(t[--j]);
        i /= 2, j /= 2;
      }
    }
  };

}  

}  




namespace {
  using namespace std;
namespace seg { 
  template<typename Node,
           typename CombinerFn,
           typename PushdownFn,
           typename NodeManager = Explicit<Node>>
  struct SegtreeLazy : id10<Node, NodeManager, CombinerFn, PushdownFn> {
    typedef id10<Node, NodeManager, CombinerFn, PushdownFn> Base;
    using Base::id10;
    using typename Base::vnode;
  };
}  

}  




namespace {
  using namespace std;
namespace seg { 
  template<typename Node,
           typename CombinerFn,
           typename NodeManager = Explicit<Node>>
  struct SegtreeNormal : id10<Node, NodeManager, CombinerFn> {
    typedef id10<Node, NodeManager, CombinerFn> Base;
    using Base::id10;
    using typename Base::vnode;
    using Base::combiner_fn;
    using Base::L;
    using Base::R;
    using Base::manager;

    template<typename Updater>
    vnode id11(vnode no, int l, int r, int idx, const Updater& updater) {
      no = manager.persist(no);
      if(l == r)
        updater(manager.ref(no));
      else {
        int mid = (l+r)/2;
        if(idx <= mid)
          id11(manager.left(no), l, mid, idx, updater);
        else
          id11(manager.right(no), mid+1, r, idx, updater);
        auto left_no = manager.left(no);
        auto right_no = manager.right(no);
        auto left_value = manager.has(left_no) ? manager.value(left_no) : manager.identity;
        auto right_value = manager.has(right_no) ? manager.value(right_no) : manager.identity;
        manager.ref(no) = combiner_fn(left_value, right_value);
      }
      return no;
    }

    template<typename Updater>
    inline vnode update_element(vnode root, int idx, const Updater& updater) {
      return manager.new_root(id11(root, L, R, idx, updater));
    }

    template<typename Updater>
    inline vnode update_element(int idx, const Updater& updater) {
      return update_element(this->root(), idx, updater);
    }

    inline vnode update_element_combiner(vnode root, int idx, const Node& rhs) {
      auto updater = [&](Node& lhs) {
        lhs = combiner_fn(lhs, rhs);
      };
      return update_element(root, idx, updater);
    }

    inline vnode update_element_combiner(int idx, const Node& rhs) {
      return update_element_combiner(this->root(), idx, rhs);
    }

    template<typename Updater>
    inline vnode id17(vnode root, int idx, const Updater& updater) {
      return this->id19(root, idx, idx, updater);
    }

    template<typename Updater>
    inline vnode id17(int idx, const Updater& updater) {
      return this->id19(idx, idx, updater);
    }
  };
}  

}  




namespace {
  using namespace std;
namespace seg {

  template<typename Node>
  struct id13 {
    const Node identity;

    explicit id13(const Node identity = Node())
        : identity(identity)
    {
    }

    struct NodeWrapper {
      Node no;
      NodeWrapper* left = nullptr;
      NodeWrapper* right = nullptr;
    };

    struct VirtualNode {
      NodeWrapper *cur = nullptr, **edge = nullptr;
    };

    typedef VirtualNode vnode;

    vnode r = {new NodeWrapper{identity}};

    template<typename Builder>
    void initialize(const Builder&) {}

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
      res.cur = *res.edge = new NodeWrapper{identity};
      return res;
    }
    inline void ensure_left(vnode no) {
      if(!no.cur->left)
        no.cur->left = new NodeWrapper{identity};
    }
    inline void ensure_right(vnode no) {
      if(!no.cur->right)
        no.cur->right = new NodeWrapper{identity};
    }
  };
 
  template<typename Node>
  using Implicit = id13<Node>;

  template<typename Node,
           typename CombinerFn>
  using SegtreeImplicit = SegtreeNormal<Node, CombinerFn, Implicit<Node>>;
}  

}  




namespace {
  using namespace std;
namespace seg {

  template<typename Node>
  struct PersistentNodeManager : id13<Node> {
    using typename id13<Node>::vnode;
    using typename id13<Node>::NodeWrapper;
    using typename id13<Node>::id13;

    inline vnode persist(vnode no) {
      vnode res = no;
      res.cur = no.cur ? new NodeWrapper(*no.cur) : new NodeWrapper{this->identity};
      if(res.edge) *res.edge = res.cur;
      return res;
    }
  };
 
  template<typename Node>
  using Persistent = PersistentNodeManager<Node>;

  template<typename Node,
           typename CombinerFn>
  using SegtreePersistent = SegtreeNormal<Node, CombinerFn, Persistent<Node>>;
}  

}  




namespace {
  using namespace std;
namespace seg { 
  template<typename Node,
           typename NodeManager = Explicit<Node>>
  struct SegtreeSplash : id7<Node, NodeManager, EmptyFolder<void>> {
    typedef id7<Node, NodeManager, EmptyFolder<void>> Base;
    using Base::id7;
    using Base::L;
    using Base::R;
    using typename Base::vnode;
    using Base::manager;

    template<typename T, typename Folder>
    T query_element(vnode no, int l, int r, int idx, const Folder& folder) {
      if(!manager.has(no))
        return folder();
      T res = folder(manager.ref(no));
      if(l != r) {
        int mid = (l+r)/2;
        if(idx <= mid)
          res = folder(res, query_element<T>(manager.left(no), l, mid, idx, folder));
        else
          res = folder(res, query_element<T>(manager.right(no), mid+1, r, idx, folder));
      }
      return res;
    }

    template<typename T, typename Folder>
    inline T query_element(vnode root, int idx, const Folder& folder) {
      return query_element<T>(root, L, R, idx, folder);
    }

    template<typename T, typename Folder>
    inline T query_element(int idx, const Folder& folder) {
      return query_element<T>(this->root(), idx, folder);
    }

    template<typename Updater>
    vnode splash(vnode no, int l, int r, int i, int j, const Updater& updater) {
      no = manager.persist(no);
      if(tag_cond(manager.ref(no), l, r, i, j)) {
        updater(manager.ref(no));
        return no;
      }
      int mid = (l+r)/2;
      if(j <= mid) {
        manager.ensure_left(no);
        splash(manager.left(no), l, mid, i, j, updater);
      } else if(i > mid) {
        manager.ensure_right(no);
        splash(manager.right(no), mid+1, r, i, j, updater);
      } else {
        manager.ensure_left(no), manager.ensure_right(no);
        splash(manager.left(no), l, mid, i, j, updater);
        splash(manager.right(no), mid+1, r, i, j, updater);
      }
      return no;
    }

    template<typename Updater>
    inline vnode splash(vnode root, int i, int j, const Updater& updater) {
      return manager.new_root(splash(root, L, R, i, j, updater));
    }

    template<typename Updater>
    inline vnode splash(int i, int j, const Updater& updater) {
      return splash(this->root(), i, j, updater);
    }

  };
}  

}  



std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());


template<typename T, typename O>
vector<int> sorted_indices(const vector<T>& v, O op) {
    auto cmp = [&](const int i, const int j) {
        return op(v[i], v[j]);
    };
    const int n = v.size();
    vector<int> vidx(n);
    for (int i = 0; i < n; ++i)
        vidx[i] = i;
    sort(vidx.begin(), vidx.end(), cmp);
    return vidx;
}
template<typename T>
vector<int> sorted_indices(const vector<T>& v) {
    return sorted_indices(v, less<T>());
}
template<typename T>
void id2(map<T, int>& m, const int x) {
    ++m[x];
}
template<typename T>
void id22(map<T, int>& m, const int x) {
    auto it = m.find(x);
    

    if (--it->second == 0) {
        m.erase(it);
    }
}
template<typename Cont>
typename Cont::iterator id9(Cont& s, const typename Cont::key_type x) {
    return s.upper_bound(x);
}
template<typename Cont>
typename Cont::iterator id21(Cont& s, const typename Cont::key_type x) {
    return s.lower_bound(x);
}
template<typename Cont>
typename Cont::iterator id5(Cont& s, const typename Cont::key_type x) {
    const auto beg = s.begin();
    const auto end = s.end();
    if (beg == end) {
        return end;
    }
    auto it = s.lower_bound(x);
    if (it->first == x) {
        return it;
    }
    if (it == beg) {
        return end;
    }
    return --it;
}
template<typename Cont>
typename Cont::iterator id3(Cont& s, const typename Cont::key_type x) {
    const auto beg = s.begin();
    const auto end = s.end();
    if (beg == end) {
        return end;
    }
    auto it = s.lower_bound(x);
    if (it == beg) {
        return end;
    } else {
        return --it;
    }
}


template<typename Cont>
typename Cont::iterator id23(Cont& s, const typename Cont::key_type x) {
    const auto beg = s.begin();
    const auto end = s.end();
    if (beg == end)
        return end;
    auto it1 = s.lower_bound(x);
    if (it1 == beg)
        return it1;
    if (it1 == end)
        return --it1;
    auto it2 = it1;
    --it2;
    return abs(*it2 - x) <= abs(*it1 - x) ? it2 : it1;
}




const int INF = 1e9+5;
using Seg = seg::SegtreePersistent<int, seg::MaxFolder<int>>;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin>>n>>m>>k;
    map<int, vector<ii>, greater<int>> by_l;
    for (int i = 0; i < k; ++i) {
        int l, r, p;
        cin>>l>>r>>p;
        by_l[l].push_back({r, p});
    }

    Seg seg(seg::ImplicitBuilder(1, n), INF);
    map<int, Seg::vnode> id8;
    for (auto& p : by_l) {
        const int l = p.first;
        const auto& v = p.second;
        for (auto pa : v) {
            const int p = pa.second;
            const int r = pa.first;
            seg.update_element(p, seg::MinUpdater<int>(r));
        }
        id8[l] = seg.root();
    }

    for (int i = 0; i < m; ++i) {
        int a, b, x, y;
        cin>>a>>b>>x>>y;

        auto it = id21(id8, x);
        if (it != id8.end()) {
            Seg::vnode root = it->second;
            int val = seg.query(root, a, b, seg::MaxFolder<int>());
            cout<<((val<=y)?"yes":"no")<<endl;
        } else {
            cout<<"no"<<endl;
        }
    }
}
