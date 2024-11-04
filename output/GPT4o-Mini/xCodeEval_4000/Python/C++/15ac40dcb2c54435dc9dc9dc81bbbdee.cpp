#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

vector<int> divisors(int M) {
    vector<int> d;
    int i = 1;
    while (M >= i * i) {
        if (M % i == 0) {
            d.push_back(i);
            if (i * i != M) {
                d.push_back(M / i);
            }
        }
        i++;
    }
    return d;
}

int popcount(int x) {
    x = x - ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x + (x >> 4)) & 0x0f0f0f0f;
    x = x + (x >> 8);
    x = x + (x >> 16);
    return x & 0x0000007f;
}

set<int> eratosthenes(int n) {
    vector<int> res(n + 1, 0);
    set<int> prime;
    for (int i = 2; i <= n; i++) {
        if (!res[i]) {
            prime.insert(i);
            for (int j = 1; j <= n / i; j++) {
                res[i * j] = 1;
            }
        }
    }
    return prime;
}

vector<int> factorization(int n, const set<int>& prime) {
    vector<int> res;
    for (int p : prime) {
        if (n % p == 0) {
            while (n % p == 0) {
                n /= p;
            }
            res.push_back(p);
        }
    }
    if (n != 1) {
        res.push_back(n);
    }
    return res;
}

int euler_phi(int n) {
    int res = n;
    for (int x = 2; x <= n; x++) {
        if (x * x > n) {
            break;
        }
        if (n % x == 0) {
            res = res / x * (x - 1);
            while (n % x == 0) {
                n /= x;
            }
        }
    }
    if (n != 1) {
        res = res / n * (n - 1);
    }
    return res;
}

int ind(int b, int n) {
    int res = 0;
    while (n % b == 0) {
        res++;
        n /= b;
    }
    return res;
}

bool isPrimeMR(int n) {
    int d = n - 1;
    d = d / (d & -d);
    vector<int> L = {2, 3, 5, 7, 11, 13, 17};
    for (int a : L) {
        int t = d;
        int y = pow(a, t);
        if (y == 1) continue;
        while (y != n - 1) {
            y = (y * y) % n;
            if (y == 1 || t == n - 1) return false;
            t <<= 1;
        }
    }
    return true;
}

int findFactorRho(int n) {
    int m = 1 << (int)(log2(n) / 8);
    for (int c = 1; c < 99; c++) {
        auto f = [c, n](int x) { return (x * x + c) % n; };
        int y = 2, r = 1, q = 1, g = 1;
        while (g == 1) {
            int x = y;
            for (int i = 0; i < r; i++) {
                y = f(y);
            }
            int k = 0;
            while (k < r && g == 1) {
                int ys = y;
                for (int i = 0; i < min(m, r - k); i++) {
                    y = f(y);
                    q = q * abs(x - y) % n;
                }
                g = gcd(q, n);
                k += m;
            }
            r <<= 1;
        }
        if (g == n) {
            g = 1;
            while (g == 1) {
                ys = f(ys);
                g = gcd(abs(x - ys), n);
            }
        }
        if (g < n) {
            if (isPrimeMR(g)) return g;
            else if (isPrimeMR(n / g)) return n / g;
            return findFactorRho(g);
        }
    }
    return -1; // If no factor found
}

map<int, int> primeFactor(int n) {
    int i = 2;
    map<int, int> ret;
    bool rhoFlg = false;
    while (i * i <= n) {
        int k = 0;
        while (n % i == 0) {
            n /= i;
            k++;
        }
        if (k) ret[i] = k;
        i += 1 + i % 2;
        if (i == 101 && n >= (1 << 20)) {
            while (n > 1) {
                if (isPrimeMR(n)) {
                    ret[n] = 1;
                    n = 1;
                } else {
                    rhoFlg = true;
                    int j = findFactorRho(n);
                    k = 0;
                    while (n % j == 0) {
                        n /= j;
                        k++;
                    }
                    ret[j] = k;
                }
            }
        }
    }
    if (n > 1) ret[n] = 1;
    if (rhoFlg) {
        map<int, int> sortedRet;
        for (auto x : ret) {
            sortedRet[x.first] = x.second;
        }
        return sortedRet;
    }
    return ret;
}

vector<int> divisors(int n) {
    vector<int> res = {1};
    auto prime = primeFactor(n);
    for (auto p : prime) {
        vector<int> newres;
        for (int d : res) {
            for (int j = 0; j <= prime[p]; j++) {
                newres.push_back(d * pow(p, j));
            }
        }
        res = newres;
    }
    sort(res.begin(), res.end());
    return res;
}

int xorfactorial(int num) {
    if (num == 0) return 0;
    else if (num == 1) return 1;
    else if (num == 2) return 3;
    else if (num == 3) return 0;
    else {
        int x = baseorder(num);
        return (1 << x) * ((num - (1 << x) + 1) % 2) + function(num - (1 << x));
    }
}

vector<int> xorconv(int n, const vector<int>& X, const vector<int>& Y, int mod) {
    if (n == 0) {
        return {(X[0] * Y[0]) % mod};
    }
    vector<int> x(1 << (n - 1)), y(1 << (n - 1)), z(1 << (n - 1)), w(1 << (n - 1));
    for (int i = 0; i < (1 << (n - 1)); i++) {
        x[i] = X[i] + X[i + (1 << (n - 1))];
        y[i] = Y[i] + Y[i + (1 << (n - 1))];
        z[i] = X[i] - X[i + (1 << (n - 1))];
        w[i] = Y[i] - Y[i + (1 << (n - 1))];
    }
    auto res1 = xorconv(n - 1, x, y, mod);
    auto res2 = xorconv(n - 1, z, w, mod);
    vector<int> former(1 << (n - 1)), latter(1 << (n - 1));
    for (int i = 0; i < (1 << (n - 1)); i++) {
        former[i] = (res1[i] + res2[i]) * inv % mod;
        latter[i] = (res1[i] - res2[i]) * inv % mod;
    }
    return former + latter;
}

vector<int> merge_sort(const vector<int>& A, const vector<int>& B) {
    int pos_A = 0, pos_B = 0;
    int n = A.size(), m = B.size();
    vector<int> res;
    while (pos_A < n && pos_B < m) {
        if (A[pos_A] < B[pos_B]) {
            res.push_back(A[pos_A]);
            pos_A++;
        } else {
            res.push_back(B[pos_B]);
            pos_B++;
        }
    }
    res.insert(res.end(), A.begin() + pos_A, A.end());
    res.insert(res.end(), B.begin() + pos_B, B.end());
    return res;
}

class UnionFindVerSize {
public:
    vector<int> _parent, _size;
    int group;

    UnionFindVerSize(int N) {
        _parent.resize(N);
        _size.resize(N, 1);
        group = N;
        iota(_parent.begin(), _parent.end(), 0);
    }

    int find_root(int x) {
        if (_parent[x] == x) return x;
        _parent[x] = find_root(_parent[x]);
        vector<int> stack = {x};
        while (_parent[stack.back()] != stack.back()) {
            stack.push_back(_parent[stack.back()]);
        }
        for (int v : stack) {
            _parent[v] = stack.back();
        }
        return _parent[x];
    }

    void unite(int x, int y) {
        int gx = find_root(x);
        int gy = find_root(y);
        if (gx == gy) return;

        group--;

        if (_size[gx] < _size[gy]) {
            _parent[gx] = gy;
            _size[gy] += _size[gx];
        } else {
            _parent[gy] = gx;
            _size[gx] += _size[gy];
        }
    }

    int get_size(int x) {
        return _size[find_root(x)];
    }

    bool is_same_group(int x, int y) {
        return find_root(x) == find_root(y);
    }
};

class WeightedUnionFind {
public:
    vector<int> parent, size, val;
    bool flag;
    vector<vector<pair<int, int>>> edge;

    WeightedUnionFind(int N) {
        parent.resize(N);
        size.resize(N, 1);
        val.resize(N, 0);
        flag = true;
        edge.resize(N);
        iota(parent.begin(), parent.end(), 0);
    }

    void dfs(int v, int pv) {
        vector<pair<int, int>> stack = {{v, pv}};
        int new_parent = parent[pv];
        while (!stack.empty()) {
            auto [v, pv] = stack.back();
            stack.pop_back();
            parent[v] = new_parent;
            for (auto [nv, w] : edge[v]) {
                if (nv != pv) {
                    val[nv] = val[v] + w;
                    stack.push_back({nv, v});
                }
            }
        }
    }

    void unite(int x, int y, int w) {
        if (!flag) return;
        if (parent[x] == parent[y]) {
            flag = (val[x] - val[y] == w);
            return;
        }

        if (size[parent[x]] > size[parent[y]]) {
            edge[x].emplace_back(y, -w);
            edge[y].emplace_back(x, w);
            size[x] += size[y];
            val[y] = val[x] - w;
            dfs(y, x);
        } else {
            edge[x].emplace_back(y, -w);
            edge[y].emplace_back(x, w);
            size[y] += size[x];
            val[x] = val[y] + w;
            dfs(x, y);
        }
    }
};

class Dijkstra {
public:
    class Edge {
    public:
        int to, cost;
        Edge(int _to, int _cost) : to(_to), cost(_cost) {}
    };

    vector<vector<Edge>> G;
    int _E, _V;

    Dijkstra(int V) : _V(V), _E(0) {
        G.resize(V);
    }

    void add_edge(int _from, int _to, int _cost) {
        G[_from].emplace_back(_to, _cost);
        _E++;
    }

    vector<long long> shortest_path(int s) {
        vector<long long> d(_V, 1e15);
        d[s] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> que;
        que.push({0, s});

        while (!que.empty()) {
            auto [cost, v] = que.top();
            que.pop();
            if (d[v] < cost) continue;

            for (auto& e : G[v]) {
                if (d[e.to] > d[v] + e.cost) {
                    d[e.to] = d[v] + e.cost;
                    que.push({d[e.to], e.to});
                }
            }
        }
        return d;
    }
};

vector<int> Z_algorithm(const string& s) {
    int N = s.size();
    vector<int> Z_alg(N, 0);
    Z_alg[0] = N;
    int i = 1, j = 0;
    while (i < N) {
        while (i + j < N && s[j] == s[i + j]) {
            j++;
        }
        Z_alg[i] = j;
        if (j == 0) {
            i++;
            continue;
        }
        int k = 1;
        while (i + k < N && k + Z_alg[k] < j) {
            Z_alg[i + k] = Z_alg[k];
            k++;
        }
        i += k;
        j -= k;
    }
    return Z_alg;
}

class BIT {
public:
    vector<int> BIT;
    int num, mod;

    BIT(int n, int mod = 0) : num(n), mod(mod) {
        BIT.resize(n + 1, 0);
    }

    int query(int idx) {
        int res_sum = 0;
        while (idx > 0) {
            res_sum += BIT[idx];
            if (mod) {
                res_sum %= mod;
            }
            idx -= idx & (-idx);
        }
        return res_sum;
    }

    void update(int idx, int x) {
        while (idx <= num) {
            BIT[idx] += x;
            if (mod) {
                BIT[idx] %= mod;
            }
            idx += idx & (-idx);
        }
    }
};

class dancinglink {
public:
    int n;
    bool debug;
    vector<int> _left, _right;
    vector<bool> exist;

    dancinglink(int n, bool debug = false) : n(n), debug(debug) {
        _left.resize(n);
        _right.resize(n);
        exist.resize(n, true);
        for (int i = 0; i < n; i++) {
            _left[i] = i - 1;
            _right[i] = i + 1;
        }
        _right[n - 1] = n;
    }

    void pop(int k) {
        if (debug) {
            assert(exist[k]);
        }
        int L = _left[k];
        int R = _right[k];
        if (L != -1) {
            if (R != n) {
                _right[L] = R;
                _left[R] = L;
            } else {
                _right[L] = n;
            }
        } else if (R != n) {
            _left[R] = -1;
        }
        exist[k] = false;
    }

    int left(int idx, int k = 1) {
        if (debug) {
            assert(exist[idx]);
        }
        int res = idx;
        while (k) {
            res = _left[res];
            if (res == -1) break;
            k--;
        }
        return res;
    }

    int right(int idx, int k = 1) {
        if (debug) {
            assert(exist[idx]);
        }
        int res = idx;
        while (k) {
            res = _right[res];
            if (res == n) break;
            k--;
        }
        return res;
    }
};

class SparseTable {
public:
    vector<vector<int>> table;
    function<int(int, int)> merge_func;
    int ide_ele;

    SparseTable(const vector<int>& A, function<int(int, int)> merge_func, int ide_ele) 
        : merge_func(merge_func), ide_ele(ide_ele) {
        int N = A.size();
        int n = N.bit_length();
        table.resize(N, vector<int>(n, ide_ele));

        for (int i = 0; i < N; i++) {
            table[i][0] = A[i];
        }

        for (int j = 1; j < n; j++) {
            for (int i = 0; i <= N - (1 << j); i++) {
                int f = table[i][j - 1];
                int s = table[i + (1 << (j - 1))][j - 1];
                table[i][j] = merge_func(f, s);
            }
        }
    }

    int query(int s, int t) {
        int b = t - s + 1;
        int m = b.bit_length() - 1;
        return merge_func(table[s][m], table[t - (1 << m) + 1][m]);
    }
};

class BinaryTrie {
public:
    class node {
    public:
        node* left;
        node* right;
        int max;

        node(int val) : left(nullptr), right(nullptr), max(val) {}
    };

    node* root;

    BinaryTrie() {
        root = new node(-1e15);
    }

    void append(int key, int val) {
        node* pos = root;
        for (int i = 29; i >= 0; i--) {
            pos->max = max(pos->max, val);
            if (key >> i & 1) {
                if (pos->right == nullptr) {
                    pos->right = new node(val);
                    pos = pos->right;
                } else {
                    pos = pos->right;
                }
            } else {
                if (pos->left == nullptr) {
                    pos->left = new node(val);
                    pos = pos->left;
                } else {
                    pos = pos->left;
                }
            }
        }
        pos->max = max(pos->max, val);
    }

    int search(int M, int xor_val) {
        int res = -1e15;
        node* pos = root;
        for (int i = 29; i >= 0; i--) {
            if (pos == nullptr) break;

            if (M >> i & 1) {
                if (xor_val >> i & 1) {
                    if (pos->right) {
                        res = max(res, pos->right->max);
                    }
                    pos = pos->left;
                } else {
                    if (pos->left) {
                        res = max(res, pos->left->max);
                    }
                    pos = pos->right;
                }
            } else {
                if (xor_val >> i & 1) {
                    pos = pos->right;
                } else {
                    pos = pos->left;
                }
            }
        }

        if (pos) {
            res = max(res, pos->max);
        }
        return res;
    }
};

vector<int> solveequation(const vector<vector<int>>& edge, vector<int>& ans, int n, int m) {
    vector<int> x(m, 0);
    vector<bool> used(n, false);
    for (int v = 0; v < n; v++) {
        if (used[v]) continue;
        int y = dfs(v, edge, ans, used, x);
        if (y != 0) {
            return {};
        }
    }
    return x;
}

int dfs(int v, const vector<vector<int>>& edge, vector<int>& ans, vector<bool>& used, vector<int>& x) {
    used[v] = true;
    int r = ans[v];
    for (const auto& [to, dire, id] : edge[v]) {
        if (used[to]) continue;
        int y = dfs(to, edge, ans, used, x);
        if (dire == -1) {
            x[id] = y;
        } else {
            x[id] = -y;
        }
        r += y;
    }
    return r;
}

class SegmentTree {
public:
    vector<int> tree;
    function<int(int, int)> segfunc;
    int ide_ele, num, size;

    SegmentTree(const vector<int>& init_val, function<int(int, int)> segfunc, int ide_ele) 
        : segfunc(segfunc), ide_ele(ide_ele) {
        size = init_val.size();
        num = 1 << (size - 1).bit_length();
        tree.resize(2 * num, ide_ele);
        for (int i = 0; i < size; i++) {
            tree[num + i] = init_val[i];
        }
        for (int i = num - 1; i > 0; i--) {
            tree[i] = segfunc(tree[2 * i], tree[2 * i + 1]);
        }
    }

    void update(int k, int x) {
        k += num;
        tree[k] = x;
        while (k > 1) {
            tree[k >> 1] = segfunc(tree[k], tree[k ^ 1]);
            k >>= 1;
        }
    }

    int query(int l, int r) {
        if (r == size) {
            r = num;
        }

        int res = ide_ele;

        l += num;
        r += num;
        while (l < r) {
            if (l & 1) {
                res = segfunc(res, tree[l]);
                l++;
            }
            if (r & 1) {
                res = segfunc(res, tree[r - 1]);
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }

    int bisect_l(int l, int r, int x) {
        l += num;
        r += num;
        int Lmin = -1, Rmin = -1;
        while (l < r) {
            if (l & 1) {
                if (tree[l] <= x && Lmin == -1) {
                    Lmin = l;
                }
                l++;
            }
            if (r & 1) {
                if (tree[r - 1] <= x) {
                    Rmin = r - 1;
                }
            }
            l >>= 1;
            r >>= 1;
        }

        if (Lmin != -1) {
            int pos = Lmin;
            while (pos < num) {
                if (tree[2 * pos] <= x) {
                    pos = 2 * pos;
                } else {
                    pos = 2 * pos + 1;
                }
            }
            return pos - num;
        } else if (Rmin != -1) {
            int pos = Rmin;
            while (pos < num) {
                if (tree[2 * pos] <= x) {
                    pos = 2 * pos;
                } else {
                    pos = 2 * pos + 1;
                }
            }
            return pos - num;
        } else {
            return -1;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, mod;
    cin >> n >> mod;

    int M = static_cast<int>(sqrt(n)) + 10;

    vector<int> dp(n + 1, 0);
    vector<int> imos(n + 1, 0);
    dp[1] = 1;
    for (int i = 1; i < n; i++) {
        imos[i] = (imos[i] + imos[i - 1]) % mod;
        dp[i] += imos[i];
        dp[i] %= mod;

        imos[i + 1] += dp[i];
        imos[i + 1] %= mod;

        for (int j = 2; j <= n; j++) {
            if (i * j > n) {
                break;
            }

            imos[i * j] += dp[i];
            imos[i * j] %= mod;
            if ((i + 1) * j <= n) {
                imos[(i + 1) * j] -= dp[i];
                imos[(i + 1) * j] %= mod;
            }
        }
    }

    int res = (dp[n] + imos[n] + imos[n - 1]) % mod;
    cout << res << '\n';

    return 0;
}
