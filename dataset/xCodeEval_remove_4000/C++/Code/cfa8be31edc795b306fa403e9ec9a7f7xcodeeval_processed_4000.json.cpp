













namespace algo {
template <typename _Tp, typename = void> struct is_multipliable {
  static constexpr bool value = false;
};
template <typename _Tp>
struct is_multipliable<_Tp,
                       std::void_t<decltype(std::declval<_Tp &>() *=
                                            std::declval<const _Tp &>())>> {
  static constexpr bool value = true;
};
template <typename _Tp>
constexpr bool id12 = is_multipliable<_Tp>::value;

template <typename _Tp> constexpr bool id15 = std::id15<_Tp>;
template <typename T>
struct function_traits : public function_traits<decltype(&T::operator())> {};





template <typename _Fn, typename _Ret, typename... _Args>
struct function_traits<_Ret (_Fn::*)(_Args...) const>


{
  enum { arity = sizeof...(_Args) };
  


  typedef _Ret result_type;

  template <size_t i> struct arg {
    typedef typename std::tuple_element<i, std::tuple<_Args...>>::type type;
    

    

  };
};
template <typename _Tp, typename = void> struct less_than_comparable {
  enum { value = 0 };
};
template <typename _Tp>
struct less_than_comparable<
    _Tp, std::void_t<decltype(std::declval<const _Tp &>() <
                              std::declval<const _Tp &>())>> {
  enum { value = 1 };
};
} 


namespace algo {
constexpr int id11(int n) { return __builtin_clz(n); };
constexpr int id2(int n) { return __builtin_ctz(n); };


constexpr int id7(int n) { return 32 - __builtin_clz(n); };
constexpr int id8(int n) {
  return n ? id7(n - 1) + 1 : 0;
};
constexpr int id6(int n) { return 1u << (31 - id11(n)); };
constexpr int id10(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  return id6(n - 1) << 1;
};
constexpr int id4(int n) { return 31 - id11(n); };
constexpr int id14(int n) {
  if (n == 0 || n == 1) {
    return 0;
  }
  return id4(n - 1) + 1;
}
constexpr int id5(int n) { return __builtin_popcount(n); };
constexpr int id13(int n) { return __builtin_parity(n); };
} 

namespace algo {
template <typename _Monoid, typename _F, typename _E> class id3 {
public:
  id3() = delete;
  

  

  id3(int n, _F &&f, _E &&e)
      : _n(n), id0(id14(n)), _size(1 << id0), _tree(_size << 1, e()),
        _f(f), _ef(e) {}
  id3(const std::vector<_Monoid> &vec, _F &&f, _E &&e)
      : id3(vec.size(), std::forward<_F>(f), std::forward<_E>(e)) {
    static_assert(
        std::is_same_v<std::invoke_result_t<_E>, _Monoid>,
        "return type of _E must be compatible to value type of the array!");
    std::copy(vec.begin(), vec.end(), _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) {
      _update(i);
    }
  }
  id3(std::vector<_Monoid> &&vec, _F &&f, _E &&e) noexcept
      : id3(int(vec.size()), std::forward<_F>(f), std::forward<_E>(e)) {
    static_assert(
        std::is_same_v<std::invoke_result_t<_E>, _Monoid>,
        "return type of _E must be compatible to value type of the array!");
    std::move(vec.begin(), vec.end(), _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) {
      _update(i);
    }
  }
  template <typename _InputIterator>
  id3(_InputIterator first, _InputIterator last, _F &&f, _E &&e)
      : id3((int)std::distance(first, last), std::forward<_F>(f),
                std::forward<_E>(e)) {
    static_assert(
        std::is_same_v<
            std::invoke_result_t<_E>,
            typename std::iterator_traits<_InputIterator>::value_type>,
        "return type of _E must be compatible to value type of the array!");
    std::copy(first, last, _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) {
      _update(i);
    }
  }
  template <typename _InputIterator, typename _Gen>
  id3(_InputIterator first, _InputIterator last, _F &&f, _E &&e, _Gen &&gen)
      : id3((int)std::distance(first, last), std::forward<_F>(f),
                std::forward<_E>(e)) {
    static_assert(std::is_same_v<std::invoke_result_t<_E>, _Monoid>);
    std::transform(first, last, _tree.begin() + _size, std::forward<_Gen>(gen));
    for (int i = _size - 1; i > 0; --i) {
      _update(i);
    }
  }
  ~id3() = default;
  void set_val(int pos, const _Monoid &val) {

    assert(0 <= pos && pos < _n);

    _tree[pos += _size] = val;
    for (int i = 1; i <= id0; ++i) {
      _update(pos >> i);
    }
  }
  _Monoid get_val(int pos) const {

    assert(0 <= pos && pos < _n);

    return _tree[pos + _size];
  }
  _Monoid query(int l, int r) const {

    assert(0 <= l && l <= r && r <= _n);

    _Monoid resl = _ef(), resr = _ef();
    for (l += _size, r += _size; l < r; l >>= 1, r >>= 1) {
      if (l & 0x01) {
        resl = _f(resl, _tree[l++]);
      }
      if (r & 0x01) {
        resr = _f(_tree[--r], resr);
      }
    }
    return _f(resl, resr);
  }
  

  _Monoid query() const { return _tree[1]; }
  template <typename _Pred> int max_right(int l, _Pred &&pred) const {

    assert(0 <= l && l <= _n);
    assert(pred(_ef()));

    if (l < _n) {
      l += _size;
      _Monoid cur = _ef();
      do {
        while (!(l & 0x01))
          l >>= 1;
        if (!pred(_f(cur, _tree[l]))) {
          while (l < _size) {
            l <<= 1;
            if (pred(_f(cur, _tree[l]))) {
              cur = _f(cur, _tree[l++]);
            }
          }
          return l - _size;
        }
        cur = _f(cur, _tree[l++]);
      } while ((l & -l) - l);
    }
    return _n;
  }
  template <typename Pred> int min_left(int r, Pred &&pred) const {

    assert(0 <= r && r <= _n);

    if (r > 0) {
      r += _size;
      _Monoid cur = _ef();
      do {
        --r;
        while (r > 1 && (r & 0x01))
          r >>= 1;
        if (!pred(_f(_tree[r], cur))) {
          while (r < _size) {
            r <<= 1;
            r |= 1;
            if (pred(_f(_tree[r], cur))) {
              cur = _f(_tree[r--], cur);
            }
          }
          return r + 1 - _size;
        }
        cur = _f(_tree[r], cur);
      } while ((r & -r) - r);
    }
    return 0;
  }

private:
  void _update(int v) { _tree[v] = _f(_tree[v << 1], _tree[v << 1 | 1]); }
  int _n, id0, _size;
  std::vector<_Monoid> _tree;
  _F _f;
  _E _ef;
};
template <typename _F, typename _E>
id3(int, _F &&, _E &&) -> id3<std::invoke_result_t<_E>, _F, _E>;
template <typename _Monoid, typename _F, typename _E>
id3(const std::vector<_Monoid> &, _F &&, _E &&) -> id3<_Monoid, _F, _E>;
template <typename _Monoid, typename _F, typename _E>
id3(std::vector<_Monoid> &&, _F &&, _E &&) -> id3<_Monoid, _F, _E>;
template <typename _InputIterator, typename _F, typename _E>
id3(_InputIterator, _InputIterator, _F &&, _E &&)
    -> id3<typename std::iterator_traits<_InputIterator>::value_type, _F,
               _E>;
template <typename _InputIterator, typename _Gen, typename _F, typename _E>
id3(_InputIterator, _InputIterator, _F &&, _E &&, _Gen &&)
    -> id3<std::invoke_result_t<_Gen, typename std::iterator_traits<
                                              _InputIterator>::value_type>,
               _F, _E>;
















template <typename _Monoid, typename _X, typename _F, typename _Map,
          typename _G, typename _EF>
class id9 {
public:
  id9(int n, _F &&f, _Map &&mapping, _G &&g, _EF &&ef)
      : _n(n), id0(id14(_n)), _size(1 << id0), _tree(_size << 1, ef()),
        _lazy(_size), _marked(_size, false), _f(f), _map(mapping), _g(g),
        _ef(ef) {}
  id9(const std::vector<_Monoid> &vec, _F &&f, _Map &&mapping, _G &&g,
               _EF &&ef)
      : id9((int)vec.size(), std::forward<_F>(f),
                     std::forward<_Map>(mapping), std::forward<_G>(g),
                     std::forward<_EF>(ef)) {
    std::copy(vec.begin(), vec.end(), _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) {
      _update(i);
    }
  }
  id9(std::vector<_Monoid> &&vec, _F &&f, _Map &&mapping, _G &&g,
               _EF &&ef) noexcept
      : id9((int)vec.size(), std::forward<_F>(f),
                     std::forward<_Map>(mapping), std::forward<_G>(g),
                     std::forward<_EF>(ef)) {
    std::move(vec.begin(), vec.end(), _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) {
      _update(i);
    }
  }
  template <typename _InputIterator>
  id9(_InputIterator first, _InputIterator last, _F &&f,
               _Map &&mapping, _G &&g, _EF &&ef)
      : id9((int)std::distance(first, last), std::forward<_F>(f),
                     std::forward<_Map>(mapping), std::forward<_G>(g),
                     std::forward<_EF>(ef)) {
    std::copy(first, last, _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) {
      _update(i);
    }
  }
  template <typename _InputIterator, typename _Gen>
  id9(_InputIterator first, _InputIterator last, _F &&f,
               _Map &&mapping, _G &&g, _EF &&ef, _Gen &&gen)
      : id9((int)std::distance(first, last), std::forward<_F>(f),
                     std::forward<_Map>(mapping), std::forward<_G>(g),
                     std::forward<_EF>(ef)) {
    std::transform(first, last, _tree.begin() + _size, std::forward<_Gen>(gen));
    for (int i = _size - 1; i > 0; --i) {
      _update(i);
    }
  }
  ~id9() = default;
  void set_val(int pos, const _Monoid &val) {

    assert(0 <= pos && pos < _n);

    pos += _size;
    for (int i = id0; i >= 1; --i) {
      _push(pos >> i);
    }
    _tree[pos] = val;
    for (int i = 1; i <= id0; ++i) {
      _update(pos >> i);
    }
  }
  _Monoid get_val(int pos) {

    assert(0 <= pos && pos < _n);

    pos += _size;
    for (int i = id0; i >= 1; --i) {
      _push(pos >> i);
    }
    return _tree[pos];
  }
  void apply(int pos, const _X &arg) {

    assert(0 <= pos && pos < _n);

    pos += _size;
    for (int i = id0; i >= 1; --i) {
      _push(pos >> i);
    }
    _tree[pos] = _map(_tree[pos], arg);
    for (int i = 1; i <= id0; ++i) {
      _update(pos >> i);
    }
  }
  void apply(int l, int r, const _X &arg) {

    assert(0 <= l && l <= r && r <= _n);

    if (l < r) {
      l += _size;
      r += _size;
      for (int i = id0; i >= 1; --i) {
        if (((l >> i) << i) != l) {
          _push(l >> i);
        }
        if (((r >> i) << i) != r) {
          _push((r - 1) >> i);
        }
      }
      for (int _l = l, _r = r; _l < _r; _l >>= 1, _r >>= 1) {
        if (_l & 0x01) {
          _apply_subtree(_l++, arg);
        }
        if (_r & 0x01) {
          _apply_subtree(--_r, arg);
        }
      }
      for (int i = 1; i <= id0; ++i) {
        if (((l >> i) << i) != l) {
          _update(l >> i);
        }
        if (((r >> i) << i) != r) {
          _update((r - 1) >> i);
        }
      }
    }
  }
  _Monoid query(int l, int r) {

    assert(0 <= l && l <= r && r <= _n);

    _Monoid resl = _ef(), resr = _ef();
    if (l < r) {
      l += _size, r += _size;
      for (int i = id0; i >= 1; --i) {
        if (((l >> i) << i) != l) {
          _push(l >> i);
        }
        if (((r >> i) << i) != r) {
          _push((r - 1) >> i);
        }
      }
      while (l < r) {
        if (l & 0x01) {
          resl = _f(resl, _tree[l++]);
        }
        if (r & 0x01) {
          resr = _f(_tree[--r], resr);
        }
        l >>= 1;
        r >>= 1;
      }
    }
    return _f(resl, resr);
  }
  _Monoid query() const { return _tree[1]; }
  template <typename _Pred> int max_right(int l, _Pred &&pred) {

    assert(0 <= l && l <= _n);
    assert(pred(_ef()));

    if (l < _n) {
      l += _size;
      for (int i = id0; i >= 1; --i) {
        _push(l >> i);
      }
      _Monoid cur = _ef();
      do {
        while (!(l & 0x01))
          l >>= 1;
        if (!pred(_f(cur, _tree[l]))) {
          while (l < _size) {
            _push(l);
            l <<= 1;
            if (pred(_f(cur, _tree[l]))) {
              cur = _f(cur, _tree[l++]);
            }
          }
          return l - _size;
        }
        cur = _f(cur, _tree[l++]);
      } while ((l & -l) != l);
    }
    return _n;
  }
  template <typename _Pred> int min_left(int r, _Pred &&pred) {

    assert(0 <= r && r <= _n);
    assert(pred(_ef()));

    if (r > 0) {
      r += _size;
      for (int i = id0; i >= 1; --i) {
        _push(r - 1 >> i);
      }
      _Monoid cur = _ef();
      do {
        --r;
        while (r > 1 && (r & 0x01))
          r >>= 1;
        if (!pred(_f(_tree[r], cur))) {
          while (r < _size) {
            _push(r);
            r <<= 1;
            r |= 1;
            if (pred(_f(_tree[r], cur))) {
              cur = _f(_tree[r--], cur);
            }
          }
          return r + 1 - _size;
        }
        cur = _f(_tree[r], cur);
      } while ((r & -r) != r);
    }
    return 0;
  }

private:
  void _update(int v) { _tree[v] = _f(_tree[v << 1], _tree[v << 1 | 1]); }
  void _apply_subtree(int v, const _X &arg) {
    _tree[v] = _map(_tree[v], arg);
    if (v < _size && _marked[v]) {
      _lazy[v] = _g(_lazy[v], arg);
    }
    if (v < _size && !_marked[v]) {
      _lazy[v] = arg;
      _marked[v] = true;
    }
  }
  void _push(int v) {
    if (_marked[v]) {
      _apply_subtree(v << 1, _lazy[v]);
      _apply_subtree(v << 1 | 1, _lazy[v]);
      _marked[v] = false;
    }
  }
  int _n, id0, _size;
  std::vector<_Monoid> _tree;
  std::vector<_X> _lazy;
  std::vector<bool> _marked;
  _F _f;
  _Map _map;
  _G _g;
  _EF _ef;
};

template <typename _F, typename _Map, typename _G, typename _EF>
id9(int, _F &&, _Map &&, _G &&, _EF &&) -> id9<
    std::invoke_result_t<_EF>,
    typename function_traits<std::remove_reference_t<_G>>::result_type, _F,
    _Map, _G, _EF>;
template <typename _Monoid, typename _F, typename _Map, typename _G,
          typename _EF>
id9(const std::vector<_Monoid> &, _F &&, _Map &&, _G &&, _EF &&)
    -> id9<
        std::invoke_result_t<_EF>,
        typename function_traits<std::remove_reference_t<_G>>::result_type, _F,
        _Map, _G, _EF>;
template <typename _Monoid, typename _F, typename _Map, typename _G,
          typename _EF>
id9(std::vector<_Monoid> &&, _F &&, _Map &&, _G &&, _EF &&)
    -> id9<
        _Monoid,
        typename function_traits<std::remove_reference_t<_G>>::result_type, _F,
        _Map, _G, _EF>;
template <typename _InputIterator, typename _F, typename _Map, typename _G,
          typename _EF>
id9(_InputIterator, _InputIterator, _F &&, _Map &&, _G &&, _EF &&)
    -> id9<
        typename std::iterator_traits<_InputIterator>::value_type,
        typename function_traits<std::remove_reference_t<_G>>::result_type, _F,
        _Map, _G, _EF>;
template <typename _InputIterator, typename _Gen, typename _F, typename _Map,
          typename _G, typename _EF>
id9(_InputIterator, _InputIterator, _F &&, _Map &&, _G &&, _EF &&,
             _Gen &&)
    -> id9<
        std::invoke_result_t<
            _Gen, typename std::iterator_traits<_InputIterator>::value_type>,
        typename function_traits<std::remove_reference_t<_G>>::result_type, _F,
        _Map, _G, _EF>;


template <typename _T> class bitree {
public:
  bitree() = delete;
  explicit bitree(int n) : _size(n), _bit(_size + 1) {}
  void add(int pos, const _T &val) {

    assert(0 <= pos && pos < _size);

    for (++pos; pos <= _size; pos += pos & -pos) {
      _bit[pos] += val;
    }
  }
  

  _T sum(int r) const {
    _T res{};
    for (++r; r > 0; r -= r & -r) {
      res += _bit[r];
    }
    return res;
  }
  

  _T sum(int l, int r) const { return sum(r) - sum(l - 1); }
  int lower_bound(const _T &val) const {
    _T sum = 0;
    int pos = 0;
    for (int i = id4(_size); i >= 0; --i) {
      if (pos + (1 << i) <= _size && sum + _bit[pos + (1 << i)] < val) {
        pos |= 1 << i;
        sum += _bit[pos];
      }
    }
    return pos;
  }
  int upper_bound(const _T &val) const {
    _T sum = 0;
    int pos = 0;
    for (int i = id4(_size); i >= 0; --i) {
      if (pos + (1 << i) <= _size && sum + _bit[pos + (1 << i)] <= val) {
        pos |= 1 << i;
        sum += _bit[pos];
      }
    }
    return pos;
  }

private:
  int _size;
  std::vector<_T> _bit;
};








template <typename _T, typename _Fn> class id1 {
public:
  id1(const std::vector<_T> &vec, _Fn &&f)
      : _size((int)vec.size()), _lg_size(id4(_size)),
        _spt(_lg_size + 1, std::vector<_T>(_size)), id0(_size), _f(f) {
    std::copy(vec.begin(), vec.end(), _spt.front().begin());
    for (int i = 1; i < _size; ++i) {
      id0[i] = id0[i - 1 >> 1] + 1;
    }
    for (int j = 1; j <= _lg_size; ++j) {
      for (int i = 0; i + (1 << j) <= _size; ++i) {
        _spt[j][i] = _f(_spt[j - 1][i], _spt[j - 1][i + (1 << j - 1)]);
      }
    }
  }
  id1(std::vector<_T> &&vec, _Fn &&f) noexcept
      : _size((int)vec.size()), _lg_size(id4(_size)),
        _spt(_lg_size + 1, std::vector<_T>(_size)), id0(_size), _f(f) {
    std::move(vec.begin(), vec.end(), _spt.front().begin());
    for (int i = 1; i < _size; ++i) {
      id0[i] = id0[i - 1 >> 1] + 1;
    }
    for (int j = 1; j <= _lg_size; ++j) {
      for (int i = 0; i + (1 << j) <= _size; ++i) {
        _spt[j][i] = _f(_spt[j - 1][i], _spt[j - 1][i + (1 << j - 1)]);
      }
    }
  }
  template <typename _InputIterator>
  id1(_InputIterator first, _InputIterator last, _Fn &&f)
      : _size((int)std::distance(first, last)), _lg_size(id4(_size)),
        _spt(_lg_size + 1, std::vector<_T>(_size)), id0(_size), _f(f) {
    std::copy(first, last, _spt.front().begin());
    for (int i = 1; i < _size; ++i) {
      id0[i] = id0[i - 1 >> 1] + 1;
    }
    for (int j = 1; j <= _lg_size; ++j) {
      for (int i = 0; i + (1 << j) <= _size; ++i) {
        _spt[j][i] = _f(_spt[j - 1][i], _spt[j - 1][i + (1 << j - 1)]);
      }
    }
  }
  _T query(int l, int r) const {

    assert(l <= r);

    const int lgl = id0[r - l];
    return _f(_spt[lgl][l], _spt[lgl][r - (1 << lgl) + 1]);
  }

private:
  int _size, _lg_size;
  std::vector<std::vector<_T>> _spt;
  std::vector<int> id0;
  _Fn _f;
};
template <typename _T, typename _Fn>
id1(const std::vector<_T> &, _Fn &&) -> id1<_T, _Fn>;
template <typename _T, typename _Fn>
id1(std::vector<_T> &&, _Fn &&) -> id1<_T, _Fn>;
template <typename _InputIterator, typename _Fn>
id1(_InputIterator, _InputIterator, _Fn &&)
    -> id1<typename std::iterator_traits<_InputIterator>::value_type,
                    _Fn>;
} 


using namespace std;
using namespace __gnu_pbds;
template <typename _Tp, typename _Fn>
using ordered_set =
    tree<_Tp, null_type, _Fn, rb_tree_tag, tree_order_statistics_node_update>;
using uint = unsigned int;
template <typename _Key, typename _Value>
using umap = unordered_map<_Key, _Value>;
template <typename _Tp, typename _Fn = less<_Tp>>
using max_heap = priority_queue<_Tp, vector<_Tp>, _Fn>;
template <typename _Tp, typename _Fn = greater<_Tp>>
using min_heap = priority_queue<_Tp, vector<_Tp>, _Fn>;
template <typename _Value> using uset = unordered_set<_Value>;
using wint = long long int;

  cerr << "\033[1;32m" << 
       << "\033[1;34m" << x << "\033[0m\n";









namespace {} 


struct query{
  int l,r,i;
};



void solve() {
  int n,q;cin>>n>>q;
  auto f=[](int x,int y)->int{return x+y;};
  auto g=[](int x,int y)->int{return 0;};
  auto ef=[](){return 0;};
  algo::id9 lsg(n,f,g,g,ef);
  for(int i=0;i<n;++i){
    lsg.set_val(i,1);
  }
  vector<bool>ans(n);
  algo::id3 sg(n,[](int x,int y){return min(x,y);},[&](){return n;});
  for(int i=0;i<q;++i){
    int t;cin>>t;
    if(t==0){
      int l,r,x;cin>>l>>r>>x;
      if(x==0){
        lsg.apply(l-1,r,0);
      }else{
        int v=sg.get_val(l-1);
        sg.set_val(l-1,min(v,r-1));
      }
    }else{
      int p;cin>>p;
      if(ans[p-1]){cout<<"YES\n";}
      else if(lsg.get_val(p-1)==0){
        cout<<"NO\n";
      }else{
        int lb=lsg.min_left(p-1,[](int x){return x<1;});
        int rb=lsg.max_right(p,[](int x){return x<1;});
        if(sg.query(lb,p)<rb){
          ans[p-1]=true;
          cout<<"YES\n";
        }else{
          cout<<"N/A\n";
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if constexpr (MULTI) {
    int tc = 1;
    cin >> tc;
    while (tc--) {
      solve();
    }
  } else {
    solve();
  }
  return 0;
}
