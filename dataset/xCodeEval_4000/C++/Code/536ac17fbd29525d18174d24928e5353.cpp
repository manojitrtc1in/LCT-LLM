#define SUBMIT

#ifdef SUBMIT
#define LOGLEVEL 0
#define NDEBUG
#else
#define LOGLEVEL 1
#endif

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <array>
#include <type_traits>
#include <queue>
#include <stack>
#include <functional>

using namespace std;

#define LOG(l, x) if (l <= LOGLEVEL) cout << x << endl

#define int64 long long
#define repeat(x) for (auto repeat_var = 0; repeat_var < x; ++repeat_var)

#define for_inc(i, x) for (auto i = 0; i < x; ++i)
#define for_dec(i, x) for (auto i = x - 1; i >= 0; --i)
#define for_inc_range(i, x, y) for (auto i = x; i <= y; ++i)
#define for_dec_range(i, x, y) for (auto i = x; i >= y; --i)

#define fill0(x) memset(x, 0, sizeof(x))
#define INT_INF ((int)2E9L)
#define INT64_INF ((int64)1E18L)
#define MOD 1000000007
int MODP(int64 x) {
  int r = x % MOD;
  if (r < 0) r += MOD;
  return r;
}

template <class T, class Q>
using TreeMergeFunction = function<Q(const Q &, const Q &)>;
template <class T, class Q>
using TreeUpdateLeafFunction = function<Q(const Q &, const T &, const T &, int, int)>;
template <class T, class Q>
using TreeSplitFunction = function<void(Q &, Q &, Q &, T, int, int, int)>;
template <class T, class Q>
using TreeInitFunction = function<Q(const T&, int, int)>;


template <class T, class Q> struct SegmentTree {
  struct TreeNode {
    bool leaf = true; 

    T value;
    Q query;
    int leftChild = -1,
    rightChild =
    -1; 

  };
  
protected:
  vector<TreeNode> node;
  TreeMergeFunction<T, Q> merge;
  TreeUpdateLeafFunction<T, Q> updateLeaf;
  TreeSplitFunction<T, Q> split;
  TreeInitFunction<T, Q> init;
  const T defaultValue;
  
  int addNode(int l, int r) {
    TreeNode newNode;
    newNode.value = defaultValue;
    node.push_back(newNode);
    return (int)node.size() - 1;
  }
  
  void splitNode(int p, int l, int r) {
    assert(node[p].leaf);
    int m = (l + r) / 2;
    node[p].leaf = false;
    if (node[p].leftChild == -1) {
      int c = addNode(l, m);
      node[p].leftChild = c;
      c = addNode(m + 1, r);
      node[p].rightChild = c;
    }
    int lc = node[p].leftChild;
    int rc = node[p].rightChild;
    node[lc].leaf = true;
    node[rc].leaf = true;
    node[lc].value = node[p].value;
    node[rc].value = node[p].value;
    split(node[p].query, node[lc].query, node[rc].query, node[p].value, l, m, r);
  }
  
  void update(int p, int l, int r, int i, int j, const T &v) {
    if (j < l || i > r)
      return;
    int m = (l + r) / 2;
    if (i <= l && r <= j) { 

      if (node[p].leaf) {
        node[p].query = updateLeaf(node[p].query, node[p].value, v, l, r);
        node[p].value = v;
        return;
      } else {
        node[p].leaf = true;
        node[p].value = v;
      }
    } else if (node[p].leaf) { 

      splitNode(p, l, r);
    }
    update(node[p].leftChild, l, m, i, j, v);
    update(node[p].rightChild, m + 1, r, i, j, v);
    node[p].query = merge(node[node[p].leftChild].query,
                          node[node[p].rightChild].query);
  }
  
  Q query(int p, int l, int r, int i, int j) {
    if (i <= l && r <= j) { 

      return node[p].query;
    }
    if (node[p].leaf) { 

      splitNode(p, l, r);
    }
    int m = (l + r) / 2;
    Q ret;
    if (j <= m) {
      ret = query(node[p].leftChild, l, m, i, j);
    } else if (i >= m + 1) {
      ret = query(node[p].rightChild, m + 1, r, i, j);
    } else {
      ret = merge(query(node[p].leftChild, l, m, i, j), query(node[p].rightChild, m + 1, r, i, j));
    }
    node[p].query = merge(node[node[p].leftChild].query,
                          node[node[p].rightChild].query);
    return ret;
  }
  
  int minIndex, maxIndex;
  int root;
  
public:
  

  

  

  

  

  

  

  explicit SegmentTree(int minIndex, int maxIndex, T defaultValue,
                       const TreeMergeFunction<T, Q> &merge,
                       const TreeUpdateLeafFunction<T, Q> &updateLeaf,
                       const TreeSplitFunction<T, Q> &split)
  : merge(merge), updateLeaf(updateLeaf), split(split),
  defaultValue(defaultValue), minIndex(minIndex), maxIndex(maxIndex) {
    root = addNode(minIndex, maxIndex);
  }
  
  

  

  

  

  SegmentTree(int minIndex, int maxIndex, T defaultValue,
              const TreeMergeFunction<T, Q> &merge,
              const function<Q(T, int, int)> &init)
  : merge(merge),
  defaultValue(defaultValue), minIndex(minIndex), maxIndex(maxIndex), init(init) {
    updateLeaf = [&] (const Q &cur, T oldV, T curV, int l, int r) {
      return this->init(curV, l, r);
    };
    split = [&](Q &cur, Q &lQ, Q &rQ, T v, int l, int m, int r) {
      lQ = this->init(v, l, m);
      rQ = this->init(v, m + 1, r);
    };
    root = addNode(minIndex, maxIndex);
  }
  
  
  

  void update(int i, int j, T v) { update(root, minIndex, maxIndex, i, j, v); }
  
  

  Q query(int i, int j) { return query(root, minIndex, maxIndex, i, j); }
  
  

  Q query() { return query(root, minIndex, maxIndex, minIndex, maxIndex); }
};



template <class T> class WeightedTree {
  vector<vector<pair<int, T>>> adj;
  
  

  vector<pair<int, T>> p;
  
  vector<int> depth;
  
  int n;
  int root;
  
public:
  const vector<pair<int, T>> &getAdjacent(int u) const { return adj[u]; }
  
  void reset(int size) {
    this->n = size;
    adj.resize(n + 1);
    for_inc_range(i, 1, n) adj[i].clear();
    p.resize(n + 1);
    depth.resize(n + 1);
    for_inc_range(i, 1, n) {
      p[i] = make_pair(-1, -1);
      depth[i] = 0;
    }
  }
  
  WeightedTree() {}
  
  WeightedTree(int n) { reset(n); }
  
  void dfs(int u) {
    stack<int> node;
    node.push(u);
    while (!node.empty()) {
      u = node.top();
      node.pop();
      for (auto &e : adj[u]) {
        int v = e.first;
        int c = e.second;
        if (p[v].first == -1) {
          p[v] = make_pair(u, c);
          depth[v] = depth[u] + 1;
          node.push(v);
        }
      }
    }
  }
  
  int getParent(int u) const { return p[u].first; }
  
  T getWeight(int u) const { return p[u].second; }
  
  void setWeight(int u, T w) { p[u].second = w; }
  
  int getDepth(int u) const { return depth[u]; }
  
  size_t getSize() const { return n; }
  
  int getRoot() const { return root; }
  
  void setRoot(int u) {
    for_inc_range(v, 1, n) {
      p[v].first = -1;
    }
    root = u;
    p[root].first = -2;
    dfs(root);
  }
  
  void addEdge(int u, int v, int c) {
    adj[u].push_back(make_pair(v, c));
    adj[v].push_back(make_pair(u, c));
  }
};

template<class T> class SubtreeSize {
  const WeightedTree<T> &tree;
  vector<int> subtreeSize;
  vector<bool> visit;
  
  void dfs(int u) {
    stack<int> node;
    node.push(u);
    while (!node.empty()) {
      u = node.top();
      if (visit[u]) {
        node.pop();
        subtreeSize[u] = 1;
      }
      for (auto &v: tree.getAdjacent(u)) {
        if (v.first != tree.getParent(u)) {
          if (!visit[u]) {
            node.push(v.first);
          } else {
            subtreeSize[u] += subtreeSize[v.first];
          }
        }
      }
      visit[u] = true;
    }
  }
  
public:
  SubtreeSize(const WeightedTree<T> &tree): tree(tree) {
    subtreeSize.resize(tree.getSize() + 1);
    visit.resize(tree.getSize() + 1);
    dfs(tree.getRoot());
  }
  
  const int operator[](int u) const {
    assert(1 <= u && u <= tree.getSize());
    return subtreeSize[u];
  }
};


template<class T> class HeavyLightDecomposition {
  const WeightedTree<T> &tree;
  int timeStamp;
  vector<int> start;
  vector<int> finish;
  vector<int> head;
  vector<int> node;
  vector<bool> visit;
  int n;
  
  void dfs(int u, const SubtreeSize<T> &subtreeSize) {
    stack<int> s;
    s.push(u);
    while (!s.empty()) {
      u = s.top();
      
      if (!visit[u]) {
        timeStamp++;
        node[timeStamp] = u;
        start[u] = timeStamp;
        
        int heavyCutoff = subtreeSize[u] / 2;
        int nextNode = -1;
        
        for (auto &v: tree.getAdjacent(u)) {
          if (v.first != tree.getParent(u)) {
            if (subtreeSize[v.first] > heavyCutoff) {
              nextNode = v.first;
              break;
            }
          }
        }
        
        for (auto &v: tree.getAdjacent(u)) {
          if (v.first != tree.getParent(u) && v.first != nextNode) {
            head[v.first] = v.first;
            s.push(v.first);
          }
        }
        
        if (nextNode != -1) {
          head[nextNode] = head[u];
          

          

          s.push(nextNode);
        }
        visit[u] = true;
      } else {
        s.pop();
        finish[u] = timeStamp;
      }
    }
  }
  
public:
  HeavyLightDecomposition(const WeightedTree<T> &tree): tree(tree) {
    n = (int) tree.getSize();
    timeStamp = 0;
    SubtreeSize<int> subtreeSize(tree);
    start.resize(n + 1);
    head.resize(n + 1);
    node.resize(n + 1);
    finish.resize(n + 1);
    visit.resize(n + 1);
    head[tree.getRoot()] = tree.getRoot();
    dfs(tree.getRoot(), subtreeSize);
  }
  
  const WeightedTree<T>& getTree() const {
    return tree;
  }
  
  

  bool isLight(int u) const {
    assert(u != tree.getRoot());
    assert(1 <= u && u <= n);
    return head[u] == u;
  }
  
  bool isHeavy(int u) const {
    return !isLight(u);
  }
  
  int getHead(int u) const {
    assert(1 <= u && u <= n);
    return head[u];
  }
  
  int getStartTime(int u) const {
    assert(1 <= u && u <= n);
    return start[u];
  }
  
  int getFinishTime(int u) const {
    assert(1 <= u && u <= n);
    return finish[u];
  }
  
  int getNodeAtTime(int timeStamp) const {
    return node[timeStamp];
  }
  
  int getHeadTime(int u) const {
    assert(1 <= u && u <= n);
    return start[head[u]];
  }
  
  bool inSameHeavyPath(int u, int v) const {
    assert(1 <= u && u <= n);
    return head[u] == head[v];
  }
};

template <class T, class Q, class W> class HLDSegmentTree: SegmentTree<T,Q> {
private:
  const HeavyLightDecomposition<W> &hld;
public:
  HLDSegmentTree(int minIndex, int maxIndex, T defaultValue,
                 const TreeMergeFunction<T, Q> &merge,
                 const TreeUpdateLeafFunction<T, Q> &updateLeaf,
                 const TreeSplitFunction<T, Q> &split,
                 const HeavyLightDecomposition<W> &hld)
  : SegmentTree<T,Q>(minIndex, maxIndex, defaultValue, merge, updateLeaf, split), hld(hld) {}
  
  HLDSegmentTree(int minIndex, int maxIndex, T defaultValue,
                 const TreeMergeFunction<T, Q> &merge,
                 const function<Q(T, int, int)> &init,
                 const HeavyLightDecomposition<W> &hld)
  : SegmentTree<T,Q>(minIndex, maxIndex, defaultValue, merge, init), hld(hld) {}
  
  void updateNode(int u, T v) {
    int s = hld.getStartTime(u);
    SegmentTree<T,Q>::update(s, s, v);
  }
  
  void updateSubtree(int u, T v) {
    SegmentTree<T,Q>::update(hld.getStartTime(u), hld.getFinishTime(u), v);
  }
  
  

  Q queryHeavyPath(int u) {
    return SegmentTree<T,Q>::query(hld.getHeadTime(u), hld.getStartTime(u));
  }
  
  

  

  Q queryHeavyPath(int ancestor, int u) {
    assert(hld.inSameHeavyPath(u, ancestor));
    assert(hld.getStartTime(ancestor) <= hld.getStartTime(u));
    return SegmentTree<T,Q>::query(hld.getStartTime(ancestor), hld.getStartTime(u));
  }
  
  Q queryNode(int u) {
    return SegmentTree<T,Q>::query(hld.getStartTime(u), hld.getStartTime(u));
  }
  
  

  

  Q queryPath(int ancestor, int u, const function<Q(int)> &queryNodeFunc) {
    assert(hld.getStartTime(ancestor) <= hld.getStartTime(u));
    Q res = queryNodeFunc(u);
    while (1) {
      res = SegmentTree<T,Q>::merge(res, queryNodeFunc(u));
      if (u == ancestor) {
        break;
      }
      if (hld.isLight(u)) {
        u = hld.getTree().getParent(u);
      } else {
        if (hld.inSameHeavyPath(u, ancestor)) {
          Q q = queryHeavyPath(ancestor, u);
          res = SegmentTree<T,Q>::merge(res, q);
          break;
        } else {
          Q q = queryHeavyPath(u);
          res = SegmentTree<T,Q>::merge(res, q);
          u = hld.getHead(u);
        }
      }
    }
    return res;
  }
  
  Q queryPath(int ancestor, int u) {
    return queryPath(ancestor, u, [&](int u){return queryNode(u);});
  }
};

void testGen() {
  freopen("biginput1.txt", "w", stdout);
  fclose(stdout);
}

struct Query {
  int sum = 0;
  int lazy = 0;
  Query() {}
  Query(int sum, int lazy): sum(sum), lazy(lazy) {}
};
  
int main() {
  ios::sync_with_stdio(false);
#ifndef SUBMIT
  freopen("input1.txt", "r", stdin);
#endif
  
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for_inc_range(i, 1, n) cin >> a[i];
  
  WeightedTree<int> tree(n);
  repeat(n - 1) {
    int u, v;
    cin >> u >> v;
    tree.addEdge(u, v, 1);
  }
  tree.setRoot(1);
  
  HeavyLightDecomposition<int> hld(tree);
  
  TreeMergeFunction<int, Query> merge = [](const Query &l, const Query &r) {return Query(l.sum + r.sum, 0);};
  TreeUpdateLeafFunction<int, Query> updateLeaf = [](const Query &cur, int oldV, int curV, int l, int r) {
    return Query(cur.sum + curV * (r - l + 1), cur.lazy + curV);
  };
  TreeSplitFunction<int, Query> split = [](Query &cur, Query &lQ, Query &rQ, int curV, int l, int m, int r) {
    lQ.sum += cur.lazy * (m - l + 1);
    lQ.lazy += cur.lazy;
    rQ.sum += cur.lazy * (r - m);
    rQ.lazy += cur.lazy;
    cur.lazy = 0;
  };

  SegmentTree<int, Query> test(1, n, 0, merge, updateLeaf, split);
  test.update(1, 3, 5);
  test.update(2, 4, 7);
  LOG(1, n);
  LOG(1, test.query(1, 3).sum);
  
  
  HLDSegmentTree<int, Query, int> odd(1, n, 0, merge, updateLeaf, split, hld);
  HLDSegmentTree<int, Query, int> even(1, n, 0, merge, updateLeaf, split, hld);
  
  for_inc_range(u, 1, n) {
    odd.updateNode(u, a[u]);
    even.updateNode(u, a[u]);
  }
  
  repeat(q) {
    int t;
    cin >> t;
    if (t == 1) {
      int u, val;
      cin >> u >> val;
      
      if (tree.getDepth(u) % 2 == 0) {
        even.updateSubtree(u, val);
        odd.updateSubtree(u, -val);
      } else {
        odd.updateSubtree(u, val);
        even.updateSubtree(u, -val);
      }
    } else {
      int u;
      cin >> u;
      
      if (tree.getDepth(u) % 2 == 0) {
        cout << even.queryNode(u).sum << endl;
      } else {
        cout << odd.queryNode(u).sum << endl;
      }
    }
  }
  
  return 0;
}
