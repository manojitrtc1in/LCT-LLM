

using namespace std;











using ll = int64_t;
using ld = long double;
const ld EPS = 1e-10;
const ll MOD = 1e9 + 7;
const ld PI = 3.141592653589793;
const int maxn = 2e5 + 100;


template<typename ForwardIter, typename Callback>
void forn(ForwardIter arr, int n, Callback c) {
    int z = 1;
    for (auto x = arr; z <= n; ++z, ++x) {
        c(*x);
    }
}

vector<int> id1(const vector<int> &basis) {
    vector<int> linspace;
    for (int mask = 0; mask < (1 << basis.size()); ++mask) {
        int cur = 0;
        for (int i = 0; i < basis.size(); ++i) {
            if (mask & (1 << i)) {
                cur ^= basis[i];
            }
        }
        linspace.push_back(cur);
    }
    sort(linspace.begin(), linspace.end());
    return linspace;
}

int checker[32];

bool intersect(const vector<int> &basis1, const vector<int> &basis2) {
    auto lin1 = id1(basis1);
    auto lin2 = id1(basis2);
    for (int i = 0; i < 32; ++i) {
        checker[i] = 0;
    }
    for (int el:lin1) {
        checker[el] = 1;
    }
    int cnt = 0;
    for (int el:lin2) {
        if (checker[el]) {
            ++cnt;
        }
    }
    return cnt >= 2;
}

vector<vector<int>> subspaces = {{},
                                 {1},
                                 {1,  2},
                                 {1,  2,  4},
                                 {1,  2,  4,  8},
                                 {1,  2,  4,  8, 16},
                                 {1,  2,  4,  16},
                                 {1,  2,  4,  24},
                                 {1,  2,  8},
                                 {1,  2,  8,  16},
                                 {1,  2,  8,  20},
                                 {1,  2,  12},
                                 {1,  2,  12, 16},
                                 {1,  2,  12, 20},
                                 {1,  2,  16},
                                 {1,  2,  20},
                                 {1,  2,  24},
                                 {1,  2,  28},
                                 {1,  4},
                                 {1,  4,  8},
                                 {1,  4,  8,  16},
                                 {1,  4,  8,  18},
                                 {1,  4,  10},
                                 {1,  4,  10, 16},
                                 {1,  4,  10, 18},
                                 {1,  4,  16},
                                 {1,  4,  18},
                                 {1,  4,  24},
                                 {1,  4,  26},
                                 {1,  6},
                                 {1,  6,  8},
                                 {1,  6,  8,  16},
                                 {1,  6,  8,  18},
                                 {1,  6,  10},
                                 {1,  6,  10, 16},
                                 {1,  6,  10, 18},
                                 {1,  6,  16},
                                 {1,  6,  18},
                                 {1,  6,  24},
                                 {1,  6,  26},
                                 {1,  8},
                                 {1,  8,  16},
                                 {1,  8,  18},
                                 {1,  8,  20},
                                 {1,  8,  22},
                                 {1,  10},
                                 {1,  10, 16},
                                 {1,  10, 18},
                                 {1,  10, 20},
                                 {1,  10, 22},
                                 {1,  12},
                                 {1,  12, 16},
                                 {1,  12, 18},
                                 {1,  12, 20},
                                 {1,  12, 22},
                                 {1,  14},
                                 {1,  14, 16},
                                 {1,  14, 18},
                                 {1,  14, 20},
                                 {1,  14, 22},
                                 {1,  16},
                                 {1,  18},
                                 {1,  20},
                                 {1,  22},
                                 {1,  24},
                                 {1,  26},
                                 {1,  28},
                                 {1,  30},
                                 {2},
                                 {2,  4},
                                 {2,  4,  8},
                                 {2,  4,  8,  16},
                                 {2,  4,  8,  17},
                                 {2,  4,  9},
                                 {2,  4,  9,  16},
                                 {2,  4,  9,  17},
                                 {2,  4,  16},
                                 {2,  4,  17},
                                 {2,  4,  24},
                                 {2,  4,  25},
                                 {2,  5},
                                 {2,  5,  8},
                                 {2,  5,  8,  16},
                                 {2,  5,  8,  17},
                                 {2,  5,  9},
                                 {2,  5,  9,  16},
                                 {2,  5,  9,  17},
                                 {2,  5,  16},
                                 {2,  5,  17},
                                 {2,  5,  24},
                                 {2,  5,  25},
                                 {2,  8},
                                 {2,  8,  16},
                                 {2,  8,  17},
                                 {2,  8,  20},
                                 {2,  8,  21},
                                 {2,  9},
                                 {2,  9,  16},
                                 {2,  9,  17},
                                 {2,  9,  20},
                                 {2,  9,  21},
                                 {2,  12},
                                 {2,  12, 16},
                                 {2,  12, 17},
                                 {2,  12, 20},
                                 {2,  12, 21},
                                 {2,  13},
                                 {2,  13, 16},
                                 {2,  13, 17},
                                 {2,  13, 20},
                                 {2,  13, 21},
                                 {2,  16},
                                 {2,  17},
                                 {2,  20},
                                 {2,  21},
                                 {2,  24},
                                 {2,  25},
                                 {2,  28},
                                 {2,  29},
                                 {3},
                                 {3,  4},
                                 {3,  4,  8},
                                 {3,  4,  8,  16},
                                 {3,  4,  8,  17},
                                 {3,  4,  9},
                                 {3,  4,  9,  16},
                                 {3,  4,  9,  17},
                                 {3,  4,  16},
                                 {3,  4,  17},
                                 {3,  4,  24},
                                 {3,  4,  25},
                                 {3,  5},
                                 {3,  5,  8},
                                 {3,  5,  8,  16},
                                 {3,  5,  8,  17},
                                 {3,  5,  9},
                                 {3,  5,  9,  16},
                                 {3,  5,  9,  17},
                                 {3,  5,  16},
                                 {3,  5,  17},
                                 {3,  5,  24},
                                 {3,  5,  25},
                                 {3,  8},
                                 {3,  8,  16},
                                 {3,  8,  17},
                                 {3,  8,  20},
                                 {3,  8,  21},
                                 {3,  9},
                                 {3,  9,  16},
                                 {3,  9,  17},
                                 {3,  9,  20},
                                 {3,  9,  21},
                                 {3,  12},
                                 {3,  12, 16},
                                 {3,  12, 17},
                                 {3,  12, 20},
                                 {3,  12, 21},
                                 {3,  13},
                                 {3,  13, 16},
                                 {3,  13, 17},
                                 {3,  13, 20},
                                 {3,  13, 21},
                                 {3,  16},
                                 {3,  17},
                                 {3,  20},
                                 {3,  21},
                                 {3,  24},
                                 {3,  25},
                                 {3,  28},
                                 {3,  29},
                                 {4},
                                 {4,  8},
                                 {4,  8,  16},
                                 {4,  8,  17},
                                 {4,  8,  18},
                                 {4,  8,  19},
                                 {4,  9},
                                 {4,  9,  16},
                                 {4,  9,  17},
                                 {4,  9,  18},
                                 {4,  9,  19},
                                 {4,  10},
                                 {4,  10, 16},
                                 {4,  10, 17},
                                 {4,  10, 18},
                                 {4,  10, 19},
                                 {4,  11},
                                 {4,  11, 16},
                                 {4,  11, 17},
                                 {4,  11, 18},
                                 {4,  11, 19},
                                 {4,  16},
                                 {4,  17},
                                 {4,  18},
                                 {4,  19},
                                 {4,  24},
                                 {4,  25},
                                 {4,  26},
                                 {4,  27},
                                 {5},
                                 {5,  8},
                                 {5,  8,  16},
                                 {5,  8,  17},
                                 {5,  8,  18},
                                 {5,  8,  19},
                                 {5,  9},
                                 {5,  9,  16},
                                 {5,  9,  17},
                                 {5,  9,  18},
                                 {5,  9,  19},
                                 {5,  10},
                                 {5,  10, 16},
                                 {5,  10, 17},
                                 {5,  10, 18},
                                 {5,  10, 19},
                                 {5,  11},
                                 {5,  11, 16},
                                 {5,  11, 17},
                                 {5,  11, 18},
                                 {5,  11, 19},
                                 {5,  16},
                                 {5,  17},
                                 {5,  18},
                                 {5,  19},
                                 {5,  24},
                                 {5,  25},
                                 {5,  26},
                                 {5,  27},
                                 {6},
                                 {6,  8},
                                 {6,  8,  16},
                                 {6,  8,  17},
                                 {6,  8,  18},
                                 {6,  8,  19},
                                 {6,  9},
                                 {6,  9,  16},
                                 {6,  9,  17},
                                 {6,  9,  18},
                                 {6,  9,  19},
                                 {6,  10},
                                 {6,  10, 16},
                                 {6,  10, 17},
                                 {6,  10, 18},
                                 {6,  10, 19},
                                 {6,  11},
                                 {6,  11, 16},
                                 {6,  11, 17},
                                 {6,  11, 18},
                                 {6,  11, 19},
                                 {6,  16},
                                 {6,  17},
                                 {6,  18},
                                 {6,  19},
                                 {6,  24},
                                 {6,  25},
                                 {6,  26},
                                 {6,  27},
                                 {7},
                                 {7,  8},
                                 {7,  8,  16},
                                 {7,  8,  17},
                                 {7,  8,  18},
                                 {7,  8,  19},
                                 {7,  9},
                                 {7,  9,  16},
                                 {7,  9,  17},
                                 {7,  9,  18},
                                 {7,  9,  19},
                                 {7,  10},
                                 {7,  10, 16},
                                 {7,  10, 17},
                                 {7,  10, 18},
                                 {7,  10, 19},
                                 {7,  11},
                                 {7,  11, 16},
                                 {7,  11, 17},
                                 {7,  11, 18},
                                 {7,  11, 19},
                                 {7,  16},
                                 {7,  17},
                                 {7,  18},
                                 {7,  19},
                                 {7,  24},
                                 {7,  25},
                                 {7,  26},
                                 {7,  27},
                                 {8},
                                 {8,  16},
                                 {8,  17},
                                 {8,  18},
                                 {8,  19},
                                 {8,  20},
                                 {8,  21},
                                 {8,  22},
                                 {8,  23},
                                 {9},
                                 {9,  16},
                                 {9,  17},
                                 {9,  18},
                                 {9,  19},
                                 {9,  20},
                                 {9,  21},
                                 {9,  22},
                                 {9,  23},
                                 {10},
                                 {10, 16},
                                 {10, 17},
                                 {10, 18},
                                 {10, 19},
                                 {10, 20},
                                 {10, 21},
                                 {10, 22},
                                 {10, 23},
                                 {11},
                                 {11, 16},
                                 {11, 17},
                                 {11, 18},
                                 {11, 19},
                                 {11, 20},
                                 {11, 21},
                                 {11, 22},
                                 {11, 23},
                                 {12},
                                 {12, 16},
                                 {12, 17},
                                 {12, 18},
                                 {12, 19},
                                 {12, 20},
                                 {12, 21},
                                 {12, 22},
                                 {12, 23},
                                 {13},
                                 {13, 16},
                                 {13, 17},
                                 {13, 18},
                                 {13, 19},
                                 {13, 20},
                                 {13, 21},
                                 {13, 22},
                                 {13, 23},
                                 {14},
                                 {14, 16},
                                 {14, 17},
                                 {14, 18},
                                 {14, 19},
                                 {14, 20},
                                 {14, 21},
                                 {14, 22},
                                 {14, 23},
                                 {15},
                                 {15, 16},
                                 {15, 17},
                                 {15, 18},
                                 {15, 19},
                                 {15, 20},
                                 {15, 21},
                                 {15, 22},
                                 {15, 23},
                                 {16},
                                 {17},
                                 {18},
                                 {19},
                                 {20},
                                 {21},
                                 {22},
                                 {23},
                                 {24},
                                 {25},
                                 {26},
                                 {27},
                                 {28},
                                 {29},
                                 {30},
                                 {31}};
vector<tuple<int, int, int>> ed;
vector<int> g[maxn];
int xx[maxn];
int papa_xx[maxn];
int used[maxn];
int dp[maxn][374];
int inter[374][374];
bool calced[374][374];
map<vector<int>, int> rev;
map<vector<int>, int> id0;

int can_merge(int fi, int se) {
    if (calced[fi][se]) {
        return inter[fi][se];
    } else {
        calced[fi][se] = 1;
        calced[se][fi] = 1;
        if (intersect(subspaces[fi], subspaces[se])) {
            inter[fi][se] = -1;
            inter[se][fi] = -1;
            return inter[fi][se];
        }
        vector<int> merged = subspaces[fi];
        for (int el:subspaces[se]) {
            merged.push_back(el);
        }
        auto lin = id1(merged);
        int ind = id0[lin];
        inter[fi][se] = inter[se][fi] = ind;
        return ind;
    }
}

vector<int> cmp;
int h[maxn];

vector<int> basis;

vector<int> combine(vector<int> basis1, const vector<int> &basis2) {
    if (intersect(basis1, basis2)) {
        return {0};
    }
    for (int el:basis2) {
        basis1.push_back(el);
    }
    return basis1;
}

void id3(int v, bool allow_one, int p) {
    used[v] = 1;
    debug(v, xx[v]);
    cmp.push_back(v);
    for (int id:g[v]) {
        int x = get<2>(ed[id]);
        int to = get<1>(ed[id]);
        if (used[to]) {
            if (to != p && h[to] < h[v] && (allow_one || to != 1)) {
                int nval = (to == 1) ? xx[v] ^ papa_xx[v] : xx[to] ^ xx[v] ^ x;
                basis = combine(basis, {nval});
            }
        } else {
            xx[to] = xx[v] ^ x;
            h[to] = h[v] + 1;
            id3(to, allow_one, v);
        }
    }
}

void get_space(int v, bool allow_one = false, int p = 1) {
    cmp.clear();
    basis.clear();
    id3(v, allow_one, p);
}

int main() {

    freopen("../kolya_input.txt", "r", stdin);



    

    



    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
    for (int i = 0; i < subspaces.size(); ++i) {
        debug(i);
        rev[subspaces[i]] = i;
        auto lin = id1(subspaces[i]);
        id0[lin] = i;
    }
    int n;
    cin >> n;
    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back(ed.size());
        ed.emplace_back(a, b, w);
        g[b].push_back(ed.size());
        ed.emplace_back(b, a, w);
    }
    vector<int> marked(n + 1);
    for (int id:g[1]) {
        int to = get<1>(ed[id]);
        marked[to] = 1;
    }
    vector<int> only;
    vector<pair<int, int>> pairs;
    for (int id:g[1]) {
        int to = get<1>(ed[id]);
        papa_xx[to] = get<2>(ed[id]);
        bool has_pair = false;
        for (int id2:g[to]) {
            int to2 = get<1>(ed[id2]);
            if (to2 == 1) {
                continue;
            }
            if (marked[to2]) {
                has_pair = true;
                if (to2 < to) {
                    pairs.push_back({to2, to});
                }
            }
        }
        if (!has_pair) {
            only.push_back(to);
        }
    }
    int cnt = 0;
    dp[0][0] = 1;
    used[1] = 1;
    for (int to:only) {
        ++cnt;
        xx[to] = papa_xx[to];
        get_space(to);
        for (int e = 0; e < 374; ++e) {
            dp[cnt][e] = dp[cnt - 1][e];
        }
        if (!count(basis.begin(), basis.end(), 0)) {
            int ind = id0[id1(basis)];
            for (int e = 0; e < 374; ++e) {
                int res = can_merge(ind, e);
                if (res != -1) {
                    dp[cnt][res] += dp[cnt - 1][e];
                    if (dp[cnt][res] >= MOD) {
                        dp[cnt][res] -= MOD;
                    }
                }
            }
        }
    }

    for (auto[fi, se]:pairs) {
        ++cnt;
        xx[fi] = papa_xx[fi];
        get_space(fi);
        auto id4 = basis;
        for (int el:cmp) {
            used[el] = 0;
        }
        xx[se] = papa_xx[se];
        get_space(se);
        auto base_se = basis;
        for (int el:cmp) {
            used[el] = 0;
        }
        xx[fi] = papa_xx[fi];
        get_space(fi, true);
        auto id2 = basis;
        for (int e = 0; e < 374; ++e) {
            dp[cnt][e] = dp[cnt - 1][e];
        }
        for (const auto &cur_basis:{id4, base_se, id2}) {
            if (!count(cur_basis.begin(), cur_basis.end(), 0)) {
                int ind = id0[id1(cur_basis)];
                for (int e = 0; e < 374; ++e) {
                    int res = can_merge(e, ind);
                    if (res != -1) {
                        dp[cnt][res] += dp[cnt - 1][e];
                        if (dp[cnt][res] >= MOD) {
                            dp[cnt][res] -= MOD;
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 374; ++i) {
        ans += dp[cnt][i];
        if (ans >= MOD) {
            ans -= MOD;
        }
    }
    cout << ans;
}