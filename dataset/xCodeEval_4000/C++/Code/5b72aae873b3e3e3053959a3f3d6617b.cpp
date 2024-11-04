#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<long long, null_type, less<long long>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;

#define range(i, m, n) for(int i = m; i < n; i++)
#define husk(i, m, n) for(int i = m; i > n; i--)

const long long inf = 1e11;

template <typename T>
void debug_out(T t) {
  cerr << t;
}

template <typename A, typename B>
void debug_out(pair<A, B> u) {
  cerr << "(" << u.first << " " << u.second << ")";
}

template <typename T>
void debug_out(vector<T> t) {
  int sz = t.size();
  for(int i = 0; i < sz; i++) {
    debug_out(t[i]);
    if(i != sz - 1) cerr << ", ";
  }
}

template <typename T>
void debug_out(vector<vector<T>> t) {
  int sz = t.size();
  for(int i = 0; i < sz; i++) {
    debug_out(t[i]);
    if(i != sz - 1) cerr << endl;
  }
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  debug_out(H);
  cerr << " ";
  debug_out(T...);
}

template <typename T>
void debug_out(set<T> a) {
  vector<T> _a;
  for(T t : a) _a.push_back(t);
  debug_out(_a);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:" << endl, debug_out(__VA_ARGS__), cerr << endl;

class segtree1 {
  public:

  struct node {
    long long val = inf;
    long long second_val = LLONG_MAX;
    int sval = 0;
    long long p = LLONG_MIN;
    long long sum = 0;
    long long add = 0;
    int total = 0;
    void apply(int l, int r, long long v) {
      if(v >= 0) {
        assert(v < second_val);
        if(v <= val) return;
        sum += 1LL * sval * (v - val);
        val = v;
        p = max(p, v);
      }
      if(v == -inf) {
        val = 0;
        sval = 1;
        total = 1;
      }
      if(v < 0 && v > -inf) {
        if(!sval) return;
        v = ~v;
        val += v;
        if(second_val < inf) second_val += v;
        if(p > LLONG_MIN) p += v;
        add += v;
        sum += v * total;
      }
    }
  };

  node unite(const node &a, const node &b) const {
    node res;
    res.val = min(a.val, b.val);
    if(a.val == b.val) res.second_val = min(a.second_val, b.second_val);
    else res.second_val = min((res.val == a.val ? b.val : a.val), min(a.second_val, b.second_val));
    if(a.val == res.val) res.sval += a.sval;
    if(b.val == res.val) res.sval += b.sval;
    res.sum = a.sum + b.sum;
    res.total = a.total + b.total;
    return res;
  }

  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if(tree[x].add != 0) {
      tree[x + 1].apply(l, y, ~tree[x].add);
      tree[z].apply(y + 1, r, ~tree[x].add);
      tree[x].add = 0;
    }
    if(tree[x].p > LLONG_MIN) {
      tree[x + 1].apply(l, y, tree[x].p);
      tree[z].apply(y + 1, r, tree[x].p);
      tree[x].p = LLONG_MIN;
    }
  }

  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  int n;
  vector<node> tree;

  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }

  template <typename M, typename... T>
  void build(int x, int l, int r, const vector<M> &v, const T&... t) {
    if (l == r) {
      tree[x].apply(l, r, v[l], t...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v, t...);
    build(z, y + 1, r, v, t...);
    pull(x, z);
  }

  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    node a = tree[x], b = tree[x + 1], c = tree[z];
    push(x, l, r);
    node res{};
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
      }
    }
    pull(x, z);
    return res;
  }

  void modify(int x, int l, int r, int ll, int rr, long long v) {
    if (ll <= l && r <= rr && (v < 0 || (v >= 0 && tree[x].second_val > v))) {
      tree[x].apply(l, r, v);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v);
    }
    pull(x, z);
  }

  int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[x + 1])) {
      res = find_first_knowingly(x + 1, l, y, f);
    } else {
      res = find_first_knowingly(z, y + 1, r, f);
    }
    pull(x, z);
    return res;
  }

  int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_first_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (ll <= y) {
      res = find_first(x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
      res = find_first(z, y + 1, r, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[z])) {
      res = find_last_knowingly(z, y + 1, r, f);
    } else {
      res = find_last_knowingly(x + 1, l, y, f);
    }
    pull(x, z);
    return res;
  }

  int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_last_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (rr > y) {
      res = find_last(z, y + 1, r, ll, rr, f);
    }
    if (ll <= y && res == -1) {
      res = find_last(x + 1, l, y, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  segtree1(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }

  template <typename M, typename... T>
  segtree1(const vector<M> &v, const T&... t) {
    n = v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v, t...);
  }

  node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return get(0, 0, n - 1, ll, rr);
  }

  node get(int p) {
    assert(0 <= p && p <= n - 1);
    return get(0, 0, n - 1, p, p);
  }

  void modify(int ll, int rr, long long v) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    modify(0, 0, n - 1, ll, rr, v);
  }


  int find_first(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_first(0, 0, n - 1, ll, rr, f);
  }

  int find_last(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_last(0, 0, n - 1, ll, rr, f);
  }

};

class segtree2 {
  public:

  struct node {

    long long val = -inf;
    long long second_val = LLONG_MIN;
    int sval = 0;
    long long p = LLONG_MAX;
    long long sum = 0;
    long long add = 0;
    int total = 0;
    void apply(int l, int r, long long v) {
      if(v >= 0) {
        if(v < second_val) {
          cerr << l << " " << r << " " << val << " " << second_val << endl;
        }
        assert(v > second_val);
        if(v >= val) return;
        sum += 1LL * sval * (v - val);
        sum = ((sum % inf) + inf) % inf;
        val = v;
        p = min(p, v);
      }
      if(v == -inf) {
        val = inf;
        sval = 1;
        total = 1;
      }
      if(v < 0 && v > -inf) {
        if(!sval) return;
        v = ~v;
        val += v;
        if(second_val > -inf) second_val += v;
        if(p < LLONG_MAX) p += v;
        add += v;
        sum += v * total;
        sum %= inf;
      }
    }
  };

  node unite(const node &a, const node &b) const {
    node res;
    res.val = max(a.val, b.val);
    if(a.val == b.val) res.second_val = max(a.second_val, b.second_val);
    else res.second_val = max((res.val == a.val ? b.val : a.val), max(a.second_val, b.second_val));
    if(a.val == res.val) res.sval += a.sval;
    if(b.val == res.val) res.sval += b.sval;
    res.sum = a.sum + b.sum;
    res.total = a.total + b.total;
    return res;
  }

  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if(tree[x].add != 0) {
      tree[x + 1].apply(l, y, ~tree[x].add);
      tree[z].apply(y + 1, r, ~tree[x].add);
      tree[x].add = 0;
    }
    if(tree[x].p < LLONG_MAX) {
      tree[x + 1].apply(l, y, tree[x].p);
      tree[z].apply(y + 1, r, tree[x].p);
      tree[x].p = LLONG_MAX;
    }
  }

  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  int n;
  vector<node> tree;

  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }

  template <typename M, typename... T>
  void build(int x, int l, int r, const vector<M> &v, const T&... t) {
    if (l == r) {
      tree[x].apply(l, r, v[l], t...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v, t...);
    build(z, y + 1, r, v, t...);
    pull(x, z);
  }

  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    node res{};
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
      }
    }
    pull(x, z);
    return res;
  }

  void modify(int x, int l, int r, int ll, int rr, long long v) {
    if (ll <= l && r <= rr && (v < 0 || (v >= 0 && tree[x].second_val < v))) {
      tree[x].apply(l, r, v);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v);
    }
    pull(x, z);
  }

  int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[x + 1])) {
      res = find_first_knowingly(x + 1, l, y, f);
    } else {
      res = find_first_knowingly(z, y + 1, r, f);
    }
    pull(x, z);
    return res;
  }

  int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_first_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (ll <= y) {
      res = find_first(x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
      res = find_first(z, y + 1, r, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[z])) {
      res = find_last_knowingly(z, y + 1, r, f);
    } else {
      res = find_last_knowingly(x + 1, l, y, f);
    }
    pull(x, z);
    return res;
  }

  int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_last_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (rr > y) {
      res = find_last(z, y + 1, r, ll, rr, f);
    }
    if (ll <= y && res == -1) {
      res = find_last(x + 1, l, y, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  segtree2(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }

  template <typename M, typename... T>
  segtree2(const vector<M> &v, const T&... t) {
    n = v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v, t...);
  }

  node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return get(0, 0, n - 1, ll, rr);
  }

  node get(int p) {
    assert(0 <= p && p <= n - 1);
    return get(0, 0, n - 1, p, p);
  }

  void modify(int ll, int rr, long long v) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    modify(0, 0, n - 1, ll, rr, v);
  }


  int find_first(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_first(0, 0, n - 1, ll, rr, f);
  }

  int find_last(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_last(0, 0, n - 1, ll, rr, f);
  }

};

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  segtree1 st(n);
  segtree2 gr(n);
  vector<int> a(n);
  range(i, 0, n) {
    int pos;
    cin >> pos;
    pos--;
    a[pos] = i;
  }
  long long cnt = 0;
  ordered_set cur;
  vector<int> que;
  for(int i : a) {
    cnt++;
    st.modify(i, i, -inf);
    gr.modify(i, i, -inf);
    gr.modify(i, i, cnt);
    int id = cur.order_of_key(i);
    if(i < n - 1) {
      st.modify(i + 1, n - 1, ~1);
      gr.modify(i + 1, n - 1, ~1);
      st.modify(i + 1, n - 1, id + 1);
    }
    if(i > 0) {
      gr.modify(0, i - 1, id);
    }
    cur.insert(i);
    cout << gr.get(0, n - 1).sum - st.get(0, n - 1).sum << endl;
  }
  return 0;
}
