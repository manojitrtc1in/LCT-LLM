

#include <iostream>
#include <fstream>

#define C11

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
#include <iomanip>
#include <queue>
#include <stack>
#include <functional>
#include <sstream>
#include <deque>
#include <climits>
#include <cfloat>
#include <bitset>

#ifdef C11

#include <array>
#include <type_traits>
#include <random>
#include <unordered_set>
#include <unordered_map>
#include <memory>

#endif

#define LOG(l, x) if (l <= LOGLEVEL) cout << x << endl

#define int64 long long
#define repeat(x) for (auto repeat_var = 0; repeat_var < x; ++repeat_var)

#define for_inc(i, x) for (auto i = 0; i < x; ++i)
#define for_dec(i, x) for (auto i = x - 1; i >= 0; --i)
#define for_inc_range(i, x, y) for (auto i = x; i <= y; ++i)
#define for_dec_range(i, x, y) for (auto i = x; i >= y; --i)

#define countBit __builtin_popcount
#define countBit64 __builtin_popcountl

#define fill0(x) memset(x, 0, sizeof(x))
#define INT_INF ((int)2E9L)
#define INT64_INF ((int64)1E18L)
#define MOD 1000000007

using namespace std;

#ifndef GLOBAL_H
#define GLOBAL_H

#ifndef NDEBUG
#   define ASSERT(condition, message) \
    do { \
        if (! (condition)) { \
            std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
                      << " line " << __LINE__ << ": " << message << std::endl; \
            assert(false); \
        } \
    } while (false)
#else
#   define ASSERT(condition, message) do { } while (false)
#endif

string toYesNo(bool b) {
    return b ? "YES" : "NO";
}

#endif


#ifndef H_WEIGHTED_TREE
#define H_WEIGHTED_TREE



template<class T>
class WeightedTree {
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

    WeightedTree() { }

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

#endif


template<class T>
class SubtreeSize {
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
    SubtreeSize(const WeightedTree<T> &tree) : tree(tree) {
        subtreeSize.resize(tree.getSize() + 1);
        visit.resize(tree.getSize() + 1);
        dfs(tree.getRoot());
    }

    const int operator[](int u) const {
        assert(1 <= u && u <= tree.getSize());
        return subtreeSize[u];
    }
};


template<class T>
class HeavyLightDecomposition {
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
    HeavyLightDecomposition(const WeightedTree<T> &tree) : tree(tree) {
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

    const WeightedTree<T> &getTree() const {
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


#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H

template<class T, class Q>
using TreeInitFunction = function<Q(const T &, int, int)>;

template<class T, class Q>
class SegmentTree {
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
    TreeInitFunction<T, Q> init;
    const T defaultValue;

    int addNode(int l, int r) {
        TreeNode newNode;
        newNode.value = defaultValue;
        node.push_back(newNode);
        return (int) node.size() - 1;
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
        split(node[p].query, node[lc].query, node[rc].query, node[p].value, l, m,
              r);
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
        node[p].query =
                merge(node[node[p].leftChild].query, node[node[p].rightChild].query);
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
            ret = merge(query(node[p].leftChild, l, m, i, j),
                        query(node[p].rightChild, m + 1, r, i, j));
        }
        node[p].query =
                merge(node[node[p].leftChild].query, node[node[p].rightChild].query);
        return ret;
    }

    int minIndex, maxIndex;
    int root;

public:
    

    virtual Q merge(const Q &leftSide, const Q &rightSide) = 0;

    

    virtual Q updateLeaf(const Q &current, const T &oldValue, const T &currentValue, int leftIndex, int rightIndex) = 0;

    

    virtual Q split(Q &current, Q &leftChild, Q &rightChild, const T &currentValue, int leftIndex, int midIndex,
                    int rightIndex) = 0;

    explicit SegmentTree(int minIndex, int maxIndex, T defaultValue)
            : defaultValue(defaultValue), minIndex(minIndex), maxIndex(maxIndex) {
        root = addNode(minIndex, maxIndex);
    }

    

    

    void update(int i, int j, T v) { update(root, minIndex, maxIndex, i, j, v); }

    

    Q query(int i, int j) { return query(root, minIndex, maxIndex, i, j); }

    

    Q query() { return query(root, minIndex, maxIndex, minIndex, maxIndex); }
};


template<class T, class Q>
class SimpleSegmentTree : SegmentTree<T, Q> {

public:
    virtual Q initLeaf(const T &value, int leftIndex, int rightIndex) = 0;


private:
    virtual Q updateLeaf(const Q &current, const T &oldValue, const T &currentValue, int leftIndex,
                         int rightIndex) override {
        return initLeaf(currentValue, leftIndex, rightIndex);
    }

    virtual Q split(Q &current, Q &leftChild, Q &rightChild, const T &currentValue, int leftIndex, int midIndex,
                    int rightIndex) override {
        leftChild = initLeaf(currentValue, leftIndex, midIndex);
        rightChild = initLeaf(currentValue, midIndex + 1, rightIndex);
    }

    SimpleSegmentTree(int minIndex, int maxIndex, T defaultValue) : SegmentTree<T, Q>(minIndex, maxIndex,
                                                                                      defaultValue) { }
};


#endif

template<class T, class Q, class W>
class HLDSegmentTree : SegmentTree<T, Q> {
private:
    const HeavyLightDecomposition<W> &hld;
public:
    virtual Q merge(const Q &leftSide, const Q &rightSide) = 0;

    HLDSegmentTree(int minIndex, int maxIndex, T defaultValue,
                   const HeavyLightDecomposition<W> &hld)
            : SegmentTree<T, Q>(minIndex, maxIndex, defaultValue), hld(hld) { }

    void updateNode(int u, T v) {
        int s = hld.getStartTime(u);
        SegmentTree<T, Q>::update(s, s, v);
    }

    void updateSubtree(int u, T v) {
        SegmentTree<T, Q>::update(hld.getStartTime(u), hld.getFinishTime(u), v);
    }

    

    Q queryHeavyPath(int u) {
        return SegmentTree<T, Q>::query(hld.getHeadTime(u), hld.getStartTime(u));
    }

    

    

    Q queryHeavyPath(int ancestor, int u) {
        assert(hld.inSameHeavyPath(u, ancestor));
        assert(hld.getStartTime(ancestor) <= hld.getStartTime(u));
        return SegmentTree<T, Q>::query(hld.getStartTime(ancestor), hld.getStartTime(u));
    }

    Q queryNode(int u) {
        return SegmentTree<T, Q>::query(hld.getStartTime(u), hld.getStartTime(u));
    }

    

    

    Q queryPath(int ancestor, int u, const function<Q(int)> &queryNodeFunc) {
        assert(hld.getStartTime(ancestor) <= hld.getStartTime(u));
        Q res = queryNodeFunc(u);
        while (1) {
            res = merge(res, queryNodeFunc(u));
            if (u == ancestor) {
                break;
            }
            if (hld.isLight(u)) {
                u = hld.getTree().getParent(u);
            } else {
                if (hld.inSameHeavyPath(u, ancestor)) {
                    Q q = queryHeavyPath(ancestor, u);
                    res = merge(res, q);
                    break;
                } else {
                    Q q = queryHeavyPath(u);
                    res = merge(res, q);
                    u = hld.getHead(u);
                }
            }
        }
        return res;
    }

    Q queryPath(int ancestor, int u) {
        return queryPath(ancestor, u, [&](int u) { return queryNode(u); });
    }
};

template<class T, class Q, class W>
class SimpleHLDSegmentTree : public HLDSegmentTree<T, Q, W> {

public:
    virtual Q initLeaf(const T &value, int leftIndex, int rightIndex) = 0;

    explicit SimpleHLDSegmentTree(int minIndex, int maxIndex, T defaultValue, const HeavyLightDecomposition<W> &hld)
            : HLDSegmentTree<T, Q, W>(minIndex, maxIndex, defaultValue, hld) { }

private:
    Q updateLeaf(const Q &current, const T &oldValue, const T &currentValue, int leftIndex,
                 int rightIndex) override {
        return initLeaf(currentValue, leftIndex, rightIndex);
    }

    Q split(Q &current, Q &leftChild, Q &rightChild, const T &currentValue, int leftIndex, int midIndex,
            int rightIndex) override {
        leftChild = initLeaf(currentValue, leftIndex, midIndex);
        rightChild = initLeaf(currentValue, midIndex + 1, rightIndex);
        return current;
    }


};




template<class T, class Q>
class LowestCommonAncestor {
    

    

    

    vector<vector<pair<int, Q>>> anc;
    WeightedTree<T> &t;
    function<Q(Q, Q)> combine;

public:
    LowestCommonAncestor(WeightedTree<T> &tree)
            : LowestCommonAncestor(
            tree, [](WeightedTree<T> &t, int u) { return t.getWeight(u); },
            [](Q a, Q b) { return min(a, b); }) { }

    LowestCommonAncestor(WeightedTree<T> &tree,
                         const function<Q(WeightedTree<T> &, int)> &getInitial,
                         const function<Q(Q, Q)> &combine)
            : t(tree), combine(combine) {
        anc.resize(t.getSize() + 1);
        for_inc_range(i, 1, t.getSize()) {
            if (i != t.getRoot()) {
                anc[i].push_back(make_pair(t.getParent(i), getInitial(t, i)));
            }
        }
        for (int k = 1; ; ++k) {
            bool ok = false;
            for_inc_range(i, 1, t.getSize()) {
                if (anc[i].size() >= k) {
                    int j = anc[i][k - 1].first;
                    if (anc[j].size() >= k) {
                        int x = anc[j][k - 1].first;
                        anc[i].push_back(make_pair(
                                x, combine(anc[i][k - 1].second, anc[j][k - 1].second)));
                        ok = true;
                    }
                }
            }
            if (!ok)
                break;
        }
    }

    

    int getAncestor(int u, int k) {
        assert(0 <= k && k <= t.getDepth(u));
        if (k == 0) {
            return u;
        }
        int b = 0;
        while ((1 << b) <= k) ++b;
        --b;
        return getAncestor(anc[u][b].first, k - (1 << b));
    }

    Q queryAncestor(int u, int k) {
        assert(0 <= k && k <= t.getDepth(u));
        if (k == 0) {
            return u;
        }
        int b = 0;
        while ((1 << b) <= k) ++b;
        --b;
        return combine(anc[u][b].second, queryAncestor(anc[u][b].first, k - (1 << b)));
    }

    pair<int, T> getLCA(int u, int v) {
        if (t.getDepth(u) > t.getDepth(v)) {
            swap(u, v);
        }
        if (t.getDepth(v) > t.getDepth(u)) {
            for_dec(i, anc[v].size()) {
                int w = anc[v][i].first;
                if (t.getDepth(w) >= t.getDepth(u)) {
                    pair<int, T> p = getLCA(u, w);
                    p.second = min(anc[v][i].second, p.second);
                    return p;
                }
            }
        } else { 

            if (u == v) {
                return make_pair(u, INT_INF);
            }
            for_dec(i, anc[u].size()) {
                int x = anc[u][i].first;
                int y = anc[v][i].first;
                if (x != y || i == 0) {
                    pair<int, T> p = getLCA(x, y);
                    p.second = combine(anc[u][i].second, p.second);
                    p.second = combine(anc[v][i].second, p.second);
                    return p;
                }
            }
        }
        return make_pair(-1, -1);
    }
};


#ifndef COLLECTIONS_H
#define COLLECTIONS_H

namespace cl {
    template<class K, class V>
    class Map {
        std::map<K, V> map;

        typedef typename std::map<K, V>::iterator iterator;
        typedef typename std::map<K, V>::reverse_iterator reverse_iterator;
    public:
        bool empty() {
            return map.empty();
        }

        iterator begin() {
            return map.begin();
        }

        iterator end() {
            return map.end();
        }

        reverse_iterator rbegin() {
            return map.rbegin();
        }

        reverse_iterator rend() {
            return map.rend();
        }

        K firstKey() {
            assert(!empty());
            return begin()->first;
        }

        V firstValue() {
            assert(!empty());
            return begin()->second;
        }

        K lastKey() {
            assert(!empty());
            return map.rbegin()->first;
        }

        V lastValue() {
            assert(!empty());
            return map.rbegin()->second;
        }

        void removeLast() {
            map.erase(lastKey());
        }

        void removeFirst() {
            map.erase(firstKey());
        }

        V &operator[](const K &k) {
            return map[k];
        }
    };

    template<class V>
    class Array {
        std::vector<V> vec;

        typedef typename std::vector<V>::iterator iterator;
        typedef typename std::vector<V>::const_iterator const_iterator;

    public:
        Array() { }

        Array(int sz) : vec(vector<V>(sz)) { }

        void resize(int sz) {
            vec.resize(sz);
        }

        void assertIndex(int index) const {
            ASSERT(index >= 0 && index < vec.size(), "Index of out bounds, size = " << size() << ", index = " << index);
        }

        V &operator[](int index) {
            assertIndex(index);
            return vec[index];
        }

        const V &operator[](int index) const {
            assertIndex(index);
            return vec[index];
        }

        
        int add(const V &v) {
            vec.push_back(v);
            return vec.size() - 1;
        }

        iterator begin() {
            return vec.begin();
        }

        const_iterator begin() const {
            return vec.begin();
        }

        iterator end() {
            return vec.end();
        }

        const_iterator end() const {
            return vec.end();
        }

        int size() const {
            return vec.size();
        }

        V &last() {
            return this[size() - 1];
        }

        V &first() {
            return this[0];
        }

        bool empty() {
            return size() == 0;
        }

        friend std::ostream &operator<<(std::ostream &stream, const Array<V> &array) {
            bool first = true;
            stream << "Array of " << array.size() << ": [";
            for (auto &v : array) {
                if (!first) {
                    stream << ", ";
                }
                first = false;
                stream << v;
            }
            stream << "]";
            return stream;
        }
    };

    
    template<class V>
    class Array1 : public Array<V> {
    public:
        Array1() { }

        Array1(int sz) : Array<V>(sz) { }

        V &operator[](int index) {
            return Array<V>::operator[](index - 1);
        }

        const V &operator[](int index) const {
            return Array<V>::operator[](index - 1);
        }
    };

    
    template<class V>
    class ArrayR : public Array<V> {
        int minIndex, maxIndex;
    public:
        ArrayR() { }

        ArrayR(int minIndex, int maxIndex) : Array<V>(maxIndex - minIndex + 1), minIndex(minIndex), maxIndex(maxIndex) {
            assert(minIndex <= maxIndex);
            assert(Array<V>::size() == (maxIndex - minIndex + 1));
        }

        V &operator[](int index) {
            return Array<V>::operator[](index - minIndex);
        }

        const V &operator[](int index) const {
            return Array<V>::operator[](index - minIndex);
        }
    };
}

#endif


#define CAP 10

struct NodeStruct {
    int sz = 0;
    int a[CAP];

    void add(int x) {
        for_inc(i, sz) {
            if (a[i] == x) {
                return;
            }
        }
        if (sz < CAP) {
            a[sz] = x;
            sz++;
        } else {
            a[sz - 1] = min(a[sz - 1], x);
        }
        sort(a, a + sz);
    }
};

NodeStruct mergeNode(const NodeStruct &s1, const NodeStruct &s2) {
    NodeStruct s;
    int i1 = 0, i2 = 0;
    while (i1 < s1.sz || i2 < s2.sz) {
        bool use1;
        if (i2 == s2.sz) {
            use1 = true;
        } else if (i1 == s1.sz) {
            use1 = false;
        } else {
            use1 = s1.a[i1] < s2.a[i2];
        }
        if (use1) {
            if (s.sz == 0 || s.a[s.sz - 1] < s1.a[i1]) {
                s.a[s.sz] = s1.a[i1];
                s.sz++;
            }
            i1++;
        } else {
            if (s.sz == 0 || s.a[s.sz - 1] < s2.a[i2]) {
                s.a[s.sz] = s2.a[i2];
                s.sz++;
            }
            i2++;
        }
        if (s.sz == CAP) {
            break;
        }
    }
    return s;
}

class HSeg : public SimpleHLDSegmentTree<NodeStruct, NodeStruct, int> {


public:

    HSeg(int minIndex, int maxIndex, const NodeStruct &defaultValue, const HeavyLightDecomposition<int> &hld)
            : SimpleHLDSegmentTree(minIndex, maxIndex, defaultValue, hld) { }


    virtual NodeStruct initLeaf(const NodeStruct &value, int leftIndex, int rightIndex) override {
        return value;
    }

    virtual NodeStruct merge(const NodeStruct &leftSide, const NodeStruct &rightSide) override {
        return mergeNode(leftSide, rightSide);
    }
};


int main() {
    int n, nPeople, q;
    scanf("%d%d%d", &n, &nPeople, &q);

    WeightedTree<int> tree;
    tree.reset(n);
    vector<pair<int, int>> edge;

    repeat(n - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        tree.addEdge(u, v, 1);
        edge.push_back(make_pair(u, v));
    }

    tree.setRoot(1);


    HeavyLightDecomposition<int> hld(tree);

    cl::Array1<NodeStruct> who(n);

    for_inc_range(i, 1, nPeople) {
        int city;
        scanf("%d", &city);
        who[city].add(i);
    }

    HSeg hseg(1, n, NodeStruct(), hld);


    for_inc_range(i, 1, n) {
        hseg.updateNode(i, who[i]);
    }

    LowestCommonAncestor<int, int> lca(tree);

    repeat(q) {
        int u, v, a;
        scanf("%d%d%d", &u, &v, &a);
        int ancestor = lca.getLCA(u, v).first;

        


        NodeStruct q1 = hseg.queryPath(ancestor, u);
        NodeStruct q2 = hseg.queryPath(ancestor, v);

        NodeStruct q3 = mergeNode(q1, q2);

        int sz = min(a, q3.sz);
        printf("%d", sz);
        for_inc(i, sz) {
            printf(" %d", q3.a[i]);
        }
        printf("\n");
    }
    return 0;
}
