

















using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef pair <int, int> PII;
const int MOD = 1000000007;
template <class T> typename T::value_type arr_sum(const T& v, int n) { typename T::value_type sum = 0; FOR(i, 0, n) sum += v[i]; return sum; }
struct Sync_stdio { Sync_stdio() { cin.tie(NULL); ios_base::sync_with_stdio(false); } } _sync_stdio;

int MAXN = 3000000;

template <class T>
class BaseUpdater
{
  public:
    virtual T current_update(T current, T value) const { return std::numeric_limits<T>::min();}
};

template <class T>
class AddUpdater: public BaseUpdater<T>
{
  public:
    T current_update(T current, T value) const override {
        return current + value;
    }
};

template <class T>
class AssignUpdater: public BaseUpdater<T>
{
  public:
    T current_update(T current, T value) const override {
        return value;
    }
};

template <class T>
class BaseCombiner
{
  public:
    virtual T combine(T left, T right) const { return std::numeric_limits<T>::min();}
    virtual T default_value() const { return std::numeric_limits<T>::min();}
};

template <class T>
class SumCombiner: public BaseCombiner<T>
{
  public:
    T combine(T left, T right) const override {
        return left + right;
    }
    T default_value() const override {
        return 0;
    }
};

template <class T>
class MaxCombiner: public BaseCombiner<T>
{
  public:
    T combine(T left, T right) const override {
        return max(left, right);
    }
    T default_value() const override {
        return std::numeric_limits<T>::min();
    }
};

template <class T>
class MinCombiner: public BaseCombiner<T>
{
  public:
    T combine(T left, T right) const override {
        return min(left, right);
    }
    T default_value() const override {
        return std::numeric_limits<T>::max();
    }
};

LL mul(LL x, LL y)
{
    if ((LD)x * (LD)y > 4e18) {
        return 2e18;
    }
    LL ans = (LL)x * y;
    return ans;
}

template <class T>
class MulCombiner: public BaseCombiner<T>
{
  public:
    T combine(T left, T right) const override {
        return mul(left, right);
    }
    T default_value() const override {
        return 1;
    }
};

LL id1(LL x)
{
    if (x == 0) {
        return -1;
    }
    return 63 - __builtin_clzll(x);
}

template <class T, class Combiner, class Updater> class id0
{
    Combiner combiner;
    Updater updater;
    int n;
    int maxn = 1000000;
    int start_pos;
    vector<T> t;
    void build(const vector<T> &a) {
        copy(a.begin(), a.end(), t.begin() + start_pos);
        for (int i = maxn - 1; i > 0; --i) {
            t[i] = combiner.combine(t[i << 1], t[i << 1 | 1]);
        }
    }

    T query_impl(int l, int r) {
         T res = combiner.default_value();
         if (l > r) {
            return res;
         }
         ++r;
         for (l += start_pos, r += start_pos; l < r; l >>= 1, r >>= 1) {
             if (l & 1) {
                 res = combiner.combine(res, t[l++]);
             }
             if (r & 1) {
                 res = combiner.combine(res, t[--r]);
             }
         }
         return res;
    }

    void update_impl(int pos, T value) {
        pos += start_pos;
        t[pos] = updater.current_update(t[pos], value);
        for (; pos > 1; pos >>= 1) {
            t[pos >> 1] = combiner.combine(t[pos], t[pos ^ 1]);
        }
    }
public:
    id0(){}
    id0(int n)
       : n(n),
         maxn((1 << (id1(n - 1) + 1))),
         start_pos(maxn),
         t(2 * maxn, combiner.default_value())
    {
    }
    id0(const vector<T> &a): n(a.size()), maxn((1 << (id1(n - 1) + 1))), start_pos(maxn)
    { 

        t.resize(2 * maxn, combiner.default_value());
        build(a);
    }
    void update(int pos, T value)
    {
        update_impl(pos, value);
    }
    T query(int l, int r)
    {
        return query_impl(l, r);
    }
    int size() const
    {
        return n;
    }
};

template <class T, class Combiner, class Updater> class SegmentTree
{
    Combiner combiner;
    Updater updater;
    int maxn = 1000000;
    vector <T> t;
    int n;
    void build(const vector <T> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2 + 1, tl, tm);
            build(a, v * 2 + 2, tm + 1, tr);
            t[v] = combiner.combine(t[v * 2 + 1], t[v * 2 + 2]);
        }
    }
    T query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return combiner.default_value();
        }
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return combiner.combine(query(v * 2 + 1, tl, tm, l, min(r, tm)),
                                query(v * 2 + 2, tm + 1, tr, max(l, tm + 1), r));
    }
    void update(int v, int tl, int tr, int pos, T new_val) {
        if (tl == tr) {
            t[v] = updater.current_update(t[v], new_val);
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(v * 2 + 1, tl, tm, pos, new_val);
            } else {
                update(v * 2 + 2, tm + 1, tr, pos, new_val);
            }
            t[v] = combiner.combine(t[v * 2 + 1], t[v * 2 + 2]);
        }
    }
public:
    SegmentTree(){}
    SegmentTree(int n): n(n)
    {
        maxn = n;
        t.resize(4 * maxn);
    }
    SegmentTree (const vector <T> &a): n(a.size()) {
        maxn = a.size();
        t.resize(4 * maxn);
        build(a, 0, 0, maxn - 1);
    }
    void update(int pos, T add)
    {
        update(0, 0, maxn - 1, pos, add);
    }
    T query(int l, int r)
    {
        return query(0, 0, maxn - 1, l, r);
    }
    int size() const
    {
        return n;
    }
};

class Lca
{
  public:
    Lca(const vector<vector<int>> &g)
    {
        timer = 0;
        par.resize(g.size());
        d.assign(g.size(), -1);
        tin.resize(g.size());
        tout.resize(g.size());
        up.resize(g.size());
        s.resize(g.size());
        int l = 1;
        while ((1 << l) <= int(g.size())) {
            ++l;
        }
        for (auto &i: up) {
           i.resize(l + 1);
        }
        dfs(g, 0);
    }

    int lca(int a, int b)
    {
        if (upper(a, b)) {
            return a;
        }
        if (upper(b, a)) {
            return b;
        }
        FORR (i, up[a].size() - 1, -1) {
            if (!upper(up[a][i], b)) {
                a = up[a][i];
            }
        }
        return up[a][0];
    }

    int dist(int a, int b)
    {
        int p = lca(a, b);
        return d[a] + d[b] - 2 * d[p];
    }

    int upper(int a, int b) 

    {
        return tin[a] <= tin[b] && tout[a] >= tout[b];
    }

    inline int light(int i, int j)
    {
        return 2 * s[j] < s[i];
    }

    inline int heavy(int i, int j)
    {
        return 2 * s[j] >= s[i];
    }

  private:
    vector<int> d;
    vector<int> tin;
    vector<int> tout;
    vector<int> par;
    vector<int> s;
    vector<vector<int>> up;
    int timer = 0;

    void dfs(const vector<vector<int>> &g, int t, int p = 0, int depth = 0)
    {
        s[t] = 1;
        d[t] = depth;
        par[t] = p;
        tin[t] = ++timer;
        up[t][0] = p;
        FOR (i, 1, int(up[t].size())) {
            up[t][i] = up[up[t][i - 1]][i - 1];
        }
        for (auto i: g[t]) {
            if (d[i] != -1) {
                continue;
            }
            dfs(g, i, t, depth + 1);
            s[t] += s[i];
        }
        tout[t] = ++timer;
    }
};


template<template<typename, typename, typename> class SegmentTree, class Combiner, class Updater, class Label>
class id2
{
  public:

    id2(const vector<vector<int>> &tree, const vector<Label> &labels): g(tree) 

    {
        id3 = false;
        init(labels);
    }

    id2(const vector<vector<int>> &tree, bool id3): id3(id3), g(tree), lca(g) 

    {
        init_hld();
    }

    id2(const vector<vector<pair<int, Label>>> &tree): g(remove_labels(tree)), lca(g) 

    {
        const Label id5 = 0;
        id3 = true;
        vector<Label> labels(tree.size());
        vector<int> used(tree.size());
        fill_labels(0, id5, tree, labels, used);
        init(labels);
    }

    void update_vertex(int vertex, Label val)
    {
        assert(!id3);
        update(vertex, val);
    }

    void update_edge(PII edge, Label val)
    {
        assert(id3);
        if (lca.upper(edge.first, edge.second)) {
            update(edge.second, val);
        } else {
            update(edge.first, val);
        }
    }
    Label query(int x, int y)
    {
        int p = lca.lca(x, y);
        Label ans = combiner.default_value();
        if (pos[x].first == pos[p].first) {
            ans = combiner.combine(ans, tr[pos[x].first].query(pos[x].second, pos[p].second - (id3 ? 1 : 0)));
        } else {
            int t = x;
            while (pos[t].first != pos[p].first) {
                ans = combiner.combine(ans, tr[pos[t].first].query(pos[t].second, int(tr[pos[t].first].size()) - 1));
                t = next[pos[t].first];
            }
            ans = combiner.combine(ans, tr[pos[t].first].query(pos[t].second, pos[p].second - (id3 ? 1 : 0)));
        }
        if (pos[y].first == pos[p].first) { 

            ans = combiner.combine(ans, tr[pos[y].first].query(pos[y].second, pos[p].second - 1));
        } else {
            int t = y;
            while (pos[t].first != pos[p].first) {
                ans = combiner.combine(ans, tr[pos[t].first].query(pos[t].second, int(tr[pos[t].first].size()) - 1));
                t = next[pos[t].first];
            }
            ans = combiner.combine(ans, tr[pos[t].first].query(pos[t].second, pos[p].second - 1));
        }
        return ans;
    }

    PII get_pos(int v)
    {
        return pos[v];
    }
  private:
    Combiner combiner;
    Updater updater;
    bool id3 = false;
    vector<SegmentTree<Label, Combiner, Updater>> tr;
    vector<int> next;
    vector<vector<int>> g; 

    Lca lca;
    int tr_size = 0;
    vector<PII> pos;

    void init_hld()
    {
        tr.assign(g.size(), {});
        next.assign(g.size(), {});
        for (int i = 0; i < g.size(); ++i) {
            int flag = 1;
            for (auto j: g[i]) {
                if (lca.upper(j, i)) {
                    continue;
                }
                if (lca.heavy(i, j)) {
                    flag = 0;
                    break;
                }
            }
            if (!flag) {
                continue;
            }
            next[i] = -1;
            go_up(i, 0, i + 1);
        }
    }


    void go_up(int x, int p, int tr_size)
    {
        pos[x] = {tr_size - 1, p};
        int flag = 0;
        for (auto i: g[x]) {
            if (lca.upper(x, i)) {
                continue;
            }
            if (lca.heavy(i, x)) {
                flag = 1;
                go_up(i, p + 1, tr_size);
            } else {
                next[tr_size - 1] = i;
            }
        }
        if (!flag) {
            tr[tr_size - 1] = SegmentTree<Label, Combiner, Updater>(p + 1);
        }
    }

    void init(const vector<Label> &labels)
    {
        pos.resize(g.size());
        init_hld();
        for (int i = 0; i < labels.size(); ++i) { 

            update(i, labels[i]);
        }
    }

    void update(int vertex, Label val)
    {
        tr[pos[vertex].first].update(pos[vertex].second, val);
    }

    void fill_labels(int x, Label label, const vector<vector<pair<int, Label>>> &g, vector<Label> &labels, vector<int> &used)
    {
        labels[x] = label;
        used[x] = 1;
        for (auto v: g[x]) {
            if (used[v.first]) {
                continue;
            }
            fill_labels(v.first, v.second, g, labels, used);
        }
    }

    vector<vector<int>> remove_labels(const vector<vector<pair<int, Label>>> &id4) {
        vector<vector<int>> tree(id4.size());
        for (int i = 0; i < tree.size(); ++i) {
            tree[i].reserve(id4[i].size());
            for (const auto &vertex: id4[i]) {
                tree[i].push_back(vertex.first);
            }
        }
        return tree;
    }
};




int main()
{
    int n, m;
    cin >> n >> m;
    vector<PII> edges;
    vector<vector<pair<int, LL>>> g(n);
    FOR (i, 0, n - 1) {
        LL a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
        edges.push_back({a, b});
    }
    id2<id0, MulCombiner<LL>, AssignUpdater<LL>, LL> h(g);
    FOR (i, 0, m) {
        LL t;
        cin >> t;
        if (t == 1) {
            LL a, b, y;
            cin >> a >> b >> y;
            --a;
            --b;
            LL ans = h.query(a, b);
            cout << y / ans << endl;
        } else {
            LL p, c;
            cin >> p >> c;
            --p;
            int x = edges[p].first;
            int y = edges[p].second;
            h.update_edge({x, y}, c);
        }
    }
}
