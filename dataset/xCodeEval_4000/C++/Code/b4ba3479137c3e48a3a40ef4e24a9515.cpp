#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <cassert>
#include <optional>
#include <iomanip>
#include <array>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string binaryRepr(int j);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

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

#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

struct state {
    int value;
    pair<int, int> mn, mx;
    pair<int, int> minAll, maxAll;
    int turnOn;
};

const int INF = (int) 1e9;

struct SegmentTree {
    public:
        vector<state> a;
        vector<int> values;
        int n;

        state unitState() {
            state s;
            s.value = INF;
            s.minAll = {INF, n};
            s.maxAll = {-INF, -1};
            s.turnOn = 2;
            s.mn = {INF, n};
            s.mx = {-INF, -1};
            return s;
        }

        SegmentTree(int _n) {
            n = _n;
            int sz = 0;
            while ((1 << sz) < n) sz++;
            sz++;
            a.resize(1 << sz);

            auto s = unitState();
            fill(a.begin(), a.end(), s);
        }

        void init(vector<int> _values) {
            values = _values;
            assert(values.size() == n);
            debug(a.size());

            build(1, 0, n - 1);
        }

        state combine(state a, state b) {
            state s;
            s.turnOn = 2;
            s.minAll = min(a.minAll, b.minAll);
            s.maxAll = max(a.maxAll, b.maxAll);
            s.mn = min(a.mn, b.mn);
            s.mx = max(a.mx, b.mx);
            return s;
        }

        void build(int k, int lo, int hi) {
            assert(lo <= hi);


            if (lo == hi) {
                state s;
                assert(lo < values.size());
                s.value = values[lo];
                s.minAll = {INF, n};
                s.maxAll = {-INF, -1};
                s.turnOn = 2;
                s.mn = {values[lo], lo};
                s.mx = {values[lo], lo};


                a[k] = s;
            } else {
                int mid = (lo + hi) / 2;
                build(2 * k, lo, mid);
                build(2 * k + 1, mid + 1, hi);


                a[k] = combine(a[2 * k], a[2 * k + 1]);


            }
        }

        void pushDown(int k, int lo, int hi) {
            if (a[k].turnOn == 2) {
                return;
            }

            if (lo != hi) {
                a[2 * k].turnOn = a[k].turnOn;
                a[2 * k + 1].turnOn = a[k].turnOn;
            }

            if (a[k].turnOn == 1) {
                a[k].minAll = a[k].mn;
                a[k].maxAll = a[k].mx;
            } else if (a[k].turnOn == 0) {
                a[k].minAll = {INF, n};
                a[k].maxAll = {-INF, -1};
            }

            a[k].turnOn = 2;
        }

        state get(int k, int lo, int hi, int L, int R) {
            pushDown(k, lo, hi);
            if (lo == L && hi == R) {
                return a[k];
            } else {
                int mid = (lo + hi)  / 2;
                if (R <= mid) {
                    return get(2 * k, lo, mid, L, R);
                } else if (L > mid) {
                    return get(2 * k + 1, mid + 1, hi, L, R);
                } else {
                    state a = get(2 * k, lo, mid, L, mid);
                    state b = get(2 * k + 1, mid + 1, hi, mid + 1, R);
                    

                    return combine(a, b);
                }
            }
        }

        void update(int k, int lo, int hi, int L, int R, int turnOn) {
            pushDown(k, lo, hi);
            if (lo == L && hi == R) {
                a[k].turnOn = turnOn;
                pushDown(k, lo, hi);
            } else {
                int mid = (lo + hi)  / 2;
                if (R <= mid) {
                    update(2 * k, lo, mid, L, R, turnOn);
                    pushDown(2 * k + 1, mid + 1, hi);
                } else if (L > mid) {
                    update(2 * k + 1, mid + 1, hi, L, R, turnOn);
                    pushDown(2 * k, lo, mid);
                } else {
                    update(2 * k, lo, mid, L, mid, turnOn);
                    update(2 * k + 1, mid + 1, hi, mid + 1, R, turnOn);
                }




                a[k] = combine(a[2 * k], a[2 * k + 1]);
            }
        }















































































};



namespace atcoder {









    struct dsu {
    public:
        dsu() : _n(0) {}
        explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

        int merge(int a, int b) {
            assert(0 <= a && a < _n);
            assert(0 <= b && b < _n);
            int x = leader(a), y = leader(b);
            if (x == y) return x;
            if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
            parent_or_size[x] += parent_or_size[y];
            parent_or_size[y] = x;
            return x;
        }

        bool same(int a, int b) {
            assert(0 <= a && a < _n);
            assert(0 <= b && b < _n);
            return leader(a) == leader(b);
        }

        int leader(int a) {
            assert(0 <= a && a < _n);
            if (parent_or_size[a] < 0) return a;
            return parent_or_size[a] = leader(parent_or_size[a]);
        }

        int size(int a) {
            assert(0 <= a && a < _n);
            return -parent_or_size[leader(a)];
        }

        std::vector<std::vector<int>> groups() {
            std::vector<int> leader_buf(_n), group_size(_n);
            for (int i = 0; i < _n; i++) {
                leader_buf[i] = leader(i);
                group_size[leader_buf[i]]++;
            }
            std::vector<std::vector<int>> result(_n);
            for (int i = 0; i < _n; i++) {
                result[i].reserve(group_size[i]);
            }
            for (int i = 0; i < _n; i++) {
                result[leader_buf[i]].push_back(i);
            }
            result.erase(
                    std::remove_if(result.begin(), result.end(),
                                   [&](const std::vector<int>& v) { return v.empty(); }),
                    result.end());
            return result;
        }

    private:
        int _n;
        

        

        std::vector<int> parent_or_size;
    };

}  



void testSegmentTree() {




























































    auto test = [&] (int n) {
        vector<int> dfn(n);
        for (int &x: dfn) {
            x = rand() % 100;
        }

        SegmentTree seg(n);
        seg.init(dfn);

        vector<int> opened(n);

        int Q = 1000;
        while (Q--) {
            int type = rand() % 2;
            int l = rand() % n, r = rand() % n;
            if (l > r) swap(l, r);
            debug(type, l, r);
            if (type == 0) {
                int turnOn = rand() % 2;


                seg.update(1, 0, n - 1, l, r, turnOn);
                for (int i = l; i <= r; i++) {
                    opened[i] = turnOn;
                }
            } else if (type == 1) {
                auto s = seg.get(1, 0, n - 1, l, r);

                pair<int, int> minAll = {INF, n};
                pair<int, int> maxAll = {-INF, -1};
                for (int i = l; i <= r; i++) {
                    if (opened[i]) {
                        minAll = min(minAll, {dfn[i], i});
                        maxAll = max(maxAll, {dfn[i], i});
                    }
                }
                debug(dfn);
                debug(opened);

                debug(s.minAll, minAll);
                debug(s.maxAll, maxAll);

                assert(s.minAll == minAll);
                assert(s.maxAll == maxAll);
            }
        }
    };



for (int n = 1; n <= 32; n++) {
    test(n);
}








































}


struct Tree {
    vector<vector<int> > pr;
    int n;
    int LOG;
    vector<int> depth;

    Tree(int _n) {
        n = _n;
        int log = 0;
        while ((1 << log) < n) log++;
        LOG = log;
        pr = vector<vector<int> > (LOG + 1, vector<int> (n, -1));
    }

    void init(vector<int> parent, vector<int> _depth) {
        assert(parent.size() == n);
        assert(_depth.size() == n);
        depth = _depth;
        for (int i = 0; i < n; i++) {
            pr[0][i] = parent[i];
        }
        compute();
    }

    void compute() {
        for (int lg = 1; lg <= LOG; lg++) {
            for (int i = 0; i < n; i++) {
                if (pr[lg - 1][i] != -1) {
                    pr[lg][i] = pr[lg - 1][pr[lg - 1][i]];
                }
            }
        }
    }

    int getLCA(int x, int y) {
        if (x == y) return x;
        if (depth[x] > depth[y]) {
            swap(x, y);
        }

        int d = depth[y] - depth[x];




        for (int lg = LOG; lg >= 0; lg--) {
            if (d >= (1 << lg)) {
                d -= (1 << lg);
                y = pr[lg][y];
            }
        }








        assert(depth[x] == depth[y]);

        if (x == y) {
            return x;
        }

        for (int lg = LOG; lg >= 0; lg--) {
            if (pr[lg][x] != pr[lg][y]) {
                x = pr[lg][x];
                y = pr[lg][y];
            }
        }




        return pr[0][x];
    }
};


void testLCA() {
    int n = 5;
    Tree tree(n);
    vector<int> parent(n, -1);
    vector<int> depth(n);
    parent[1] = parent[2] = 0;
    parent[3] = parent[4] = 2;
    depth[1] = depth[2] = 1;
    depth[3] = depth[4] = 2;
    tree.init(parent, depth);

    debug(tree.getLCA(2, 3));


}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);












    int T = 1;
    while (T--) {
        int n, Q;
        cin >> n >> Q;
        vector<tuple<int, int, int> > edges;
        for (int i = 0; i + 1 < n; i++) {
            int from, to, wt;
            cin >> from >> to >> wt;
            from--;
            to--;
            edges.emplace_back(make_tuple(wt, from, to));
        }

        sort(edges.begin(), edges.end());

        int N = n + n - 1;
        vector<vector<int> > g(N);

        atcoder::dsu dsu(n);
        vector<int> vertexNum(n);
        for (int i = 0; i < n; i++) {
            vertexNum[i] = i;
        }

        int s = n;
        for (auto &[wt, u, v]: edges) {
            int pu = vertexNum[dsu.leader(u)];
            int pv = vertexNum[dsu.leader(v)];
            g[pu].emplace_back(s);
            g[s].emplace_back(pu);
            g[pv].emplace_back(s);
            g[s].emplace_back(pv);

            vertexNum[dsu.merge(u, v)] = s;
            s++;
        }
















        vector<int> dfn(N);
        int counter = 0;
        function<void(int,int)> dfs;

        dfs = [&] (int from, int par) -> void {
            vector<int> children;
            for (int to: g[from]) {
                if (to != par) {
                    children.push_back(to);
                }
            }
            int sz = children.size();
            if (sz == 0) {
                dfn[from] = counter++;
                return;
            }
            dfs(children[0], from);
            dfn[from] = counter++;
            if (sz == 2) {
                dfs(children[1], from);
            }
        };

        dfs(N - 1, -1);
        debug(dfn);

        vector<int> start(N), end(N);
        vector<int> depth(N), parent(N, -1);
        function<void(int,int)> dfs2;
        counter = 0;
        dfs2 = [&] (int from, int par) -> void {
            parent[from] = par;
            start[from] = ++counter;
            for (int to: g[from]) if (to != par) {
                depth[to] = depth[from] + 1;
                dfs2(to, from);
            }
            end[from] = ++counter;
        };

        dfs2(N - 1, -1);

        Tree tree(N);
        tree.init(parent, depth);

        SegmentTree seg(n);
        vector<int> values(n);
        for (int i = 0; i < n; i++) {
            values[i] = dfn[i];
        }
        seg.init(values);

        vector<int> open(n, false);
        while (Q--) {
            int type;
            cin >> type;
            if (type == 1 || type == 2) {
                int l, r;
                cin >> l >> r;
                l--;
                r--;














                seg.update(1, 0, n - 1, l, r, type == 1 ? 1: 0);
            } else {
                int x;
                cin >> x;
                x--;
















































































                int bans = -1;
                auto st = seg.get(1, 0, n - 1, 0, n - 1);
                int mnWhich = st.minAll.second;
                int mxWhich = st.maxAll.second;



                for (auto cur: vector<int>{mnWhich, mxWhich}) {
                    if (cur < 0 || cur >= n) continue;
                    if (x != cur) {
                        int ancestor = tree.getLCA(x, cur);
                        debug(x, ancestor);
                        bans = max(bans, get<0>(edges[ancestor - n]));
                    }
                }
                cout << bans << "\n";





            }
        }
    }

    return 0;
}