#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;





#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define fillchar(a, x) memset(a, x, sizeof(a))
#define rep(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define irep(i, a, b) for (int i = int(a); i >= int(b); --i)
#define replr(i, a, b) rep(i, a, (b)-1)
#define reprl(i, a, b) irep(i, (b)-1, a)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define popcount __builtin_popcount
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<PII> VPI;
typedef vector<PLL> VPL;
template <class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os << "(" << v.first << ", " << v.second << ")"; }
template <class T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; repn(i, sz(v)) { if(i) os << ", "; os << v[i]; } return os << "]"; }
template <class T> bool setmax(T& _a, T _b) { if(_a < _b) { _a = _b; return true; } return false; }
template <class T> bool setmin(T& _a, T _b) { if(_b < _a) { _a = _b; return true; } return false; }
template <class T> T gcd(T _a, T _b) { return _b == 0 ? _a : gcd(_b, _a % _b); }





const int N = 20000;
const int Q = 20000;
const int LOG = 16;

struct Edge {
    int ch;
    bool valid;
};

vector<pair<int, Edge*>> es[N];
map<PII, int> e2c;
Edge all_edges[N];
VPI qs[N];
int ans[Q];
int n, qn;

void input() {
    scanf("%d%d", &n, &qn);
    repn(i, n - 1) {
        int a, b;
        char c;
        scanf("%d%d %c", &a, &b, &c);
        --a, --b;
        all_edges[i].ch = int(c - 'a');
        e2c[mp(a, b)] = e2c[mp(b, a)] = int(c - 'a');
        es[a].pb(mp(b, &all_edges[i])), es[b].pb(mp(a, &all_edges[i]));
    }
    repn(i, qn) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x, --y;
        qs[x].pb(mp(y, i));
    }
}

struct Hash {
    static constexpr LL M1 = LL(1e9) + 7;
    static constexpr LL M2 = LL(1e9) + 9;
    static constexpr LL P1 = 911;
    static constexpr LL P2 = 127;

    LL h1, h2;
    Hash(int ch = 0) : h1(ch), h2(ch) {}
    Hash(LL h1, LL h2) : h1(h1), h2(h2) {}
    Hash operator+(const Hash& b) const {
        return Hash((h1 + b.h1) % M1, (h2 + b.h2) % M2);
    }
    Hash operator-(const Hash& b) const {
        return Hash((h1 - b.h1 + M1) % M1, (h2 - b.h2 + M2) % M2);
    }
    Hash operator*(const Hash& b) const {
        return Hash((h1 * b.h1) % M1, (h2 * b.h2) % M2);
    }
    static Hash P() { return Hash(P1, P2); }

    bool operator==(const Hash& b) const { return h1 == b.h1 && h2 == b.h2; }
};

namespace std {
template <> struct hash<Hash> {
    size_t operator()(const Hash& s) const { return s.h1 ^ s.h2; }
};
}

Hash hash_pow[N + 10], hash_ipow[N + 10];

Hash hash_add(Hash h, int ch) { return h * Hash::P() + ch; }

Hash hash_merge(Hash h1, Hash h2, int l2) { return h1 * hash_pow[l2] + h2; }

void hash_prepare() {
    const auto pow = [](LL a, LL b, LL mod) {
        LL r = 1;
        for(; b > 0; b >>= 1, a = a * a % mod) {
            if(b & 1) r = r * a % mod;
        }
        return r;
    };
    hash_pow[0] = Hash(1);
    rep(i, 1, N) { hash_pow[i] = hash_add(hash_pow[i - 1], 0); }
    hash_ipow[N].h1 = pow(hash_pow[N].h1, Hash::M1 - 2, Hash::M1);
    hash_ipow[N].h2 = pow(hash_pow[N].h2, Hash::M2 - 2, Hash::M2);
    irep(i, N, 1) { hash_ipow[i - 1] = hash_add(hash_ipow[i], 0); }
}

int dep[N], up[N][LOG];
Hash hu[N], hd[N];

void init() {
    hash_prepare();

    const function<void(int, int, int)> dfs = [&](int x, int fa, int d) {
        dep[x] = d;
        fillchar(up[x], -1);
        up[x][0] = fa;
        for(int i = 0; up[x][i] >= 0; ++i) up[x][i + 1] = up[up[x][i]][i];
        for(const auto& e : es[x]) {
            const int y = e.fi;
            if(y != fa) {
                hu[y] = hash_merge(e.se->ch + 1, hu[x], d);
                hd[y] = hash_add(hd[x], e.se->ch + 1);
                dfs(y, x, d + 1);
            }
        }
    };
    hu[0] = hd[0] = 0;
    dfs(0, -1, 0);
}

int go_up(int x, int d) {
    repn(i, LOG) if(d & (1 << i)) x = up[x][i];
    return x;
}

int lca(int x, int y) {
    int d = dep[x] - dep[y];
    if(d > 0) {
        x = go_up(x, d);
    } else {
        y = go_up(y, -d);
    }
    irepn(i, LOG) if(up[x][i] != up[y][i]) {
        x = up[x][i];
        y = up[y][i];
    }
    if(x != y) x = up[x][0];
    return x;
}

int dis(int x, int y) { return dep[x] + dep[y] - 2 * dep[lca(x, y)]; }

string extract(int x, int y) {
    string r;
    const function<void(int, int, string)> dfs = [&](int cur, int fa,
                                                     string s) {
        if(cur == y) {
            r = s;
            return;
        }
        for(const auto& e : es[cur]) {
            if(e.fi != fa) dfs(e.fi, cur, s + char('a' + e.se->ch));
        }
    };
    dfs(x, -1, "");
    return r;
}

Hash get_hash(int x, int y) {
    

    int z = lca(x, y);
    Hash l = (hu[x] - hu[z]) * hash_ipow[dep[z]];
    Hash r = hd[y] - hd[z] * hash_pow[dep[y] - dep[z]];
    return hash_merge(l, r, dep[y] - dep[z]);
}

int go(int x, int y, int d) {
    int z = lca(x, y);
    int dx = dep[x] - dep[z];
    if(d <= dx) {
        return go_up(x, d);
    } else {
        return go_up(y, dep[y] - dep[z] - (d - dx));
    }
}

int next(int x, int y) { return go(x, y, 1); }

int next_ch(int x, int y) {
    y = next(x, y);
    assert(e2c.count(mp(x, y)));
    return e2c[mp(x, y)];
}

int compare(int x1, int y1, int x2, int y2) {
    int d = min(dis(x1, y1), dis(x2, y2));
    int le = 0, ri = d;
    while(le < ri) {
        int mid = (le + ri + 1) / 2;
        if(get_hash(x1, go(x1, y1, mid)) == get_hash(x2, go(x2, y2, mid))) {
            le = mid;
        } else {
            ri = mid - 1;
        }
    }
    if(le == d) return 0;
    return next_ch(go(x1, y1, le), y1) < next_ch(go(x2, y2, le), y2) ? -1 : 1;
}

class Trie {
    struct Node {
        int count = 0, lt = 0, tot = 0;
        Hash hash;
        Node* child[26] = {nullptr};

        Node() { assert(child[20] == nullptr); }
    };
    Node* root;
    unordered_map<Hash, Node*> h2n;

    Node* add(Node* cur, int x, int fa) {
        if(!cur) cur = new Node();
        ++cur->count;
        for(const auto& e : es[x]) {
            if(e.fi != fa && e.se->valid) {
                cur->child[e.se->ch] = add(cur->child[e.se->ch], e.fi, x);
            }
        }
        return cur;
    }

    multiset<string> strings;
    void vio_add(int x, int fa, string s) {
        strings.insert(s);
        for(const auto& e : es[x]) {
            if(e.fi != fa && e.se->valid) {
                vio_add(e.fi, x, s + char('a' + e.se->ch));
            }
        }
    }

    int vio_count_lt(int x, int y) const {
        string s = extract(x, y);
        int r = 0;
        for(const auto u : strings) {
            if(u < s) ++r;
        }
        return r;
    }

public:
    Trie() : root(new Node()) {}

    void add(int x, int fa, int ch) {
        

        root->child[ch] = add(root->child[ch], x, fa);
    }

    void prepare() {
        const function<void(Node*, Hash, int)> dfs = [&](Node* cur, Hash h,
                                                         int tot) {
            h2n[h] = cur;
            cur->lt = tot;
            cur->tot = cur->count;
            cur->hash = h;
            tot += cur->count;
            repn(ch, 26) if(cur->child[ch]) {
                dfs(cur->child[ch], hash_add(h, ch + 1), tot);
                cur->tot += cur->child[ch]->tot;
                tot += cur->child[ch]->tot;
            }
        };
        dfs(root, Hash(), 0);
    }

    int count_lt(int x, int y) const {
        

        const int d = dis(x, y);
        int le = 0, ri = d;
        while(le < ri) {
            int mid = (le + ri + 1) / 2;
            if(h2n.count(get_hash(x, go(x, y, mid)))) {
                le = mid;
            } else {
                ri = mid - 1;
            }
        }
        const int z = go(x, y, le);
        Node* cur = h2n.find(get_hash(x, z))->se;
        

        

        

        

        int r = cur->lt;
        if(le < d) {
            r += cur->count;
            int ch = next_ch(z, y);
            

            repn(i, ch) if(cur->child[i]) r += cur->child[i]->tot;
        }
        
        return r;
    }

    int count() const { return root->tot; }
};

pair<int, VI> find_center(int start) {
    VI xs;
    VPI ss;
    const function<int(int, int)> dfs = [&](int x, int fa) {
        int s = 1, m = 0;
        for(const auto& e : es[x]) {
            if(e.fi != fa && e.se->valid) {
                int tmp = dfs(e.fi, x);
                s += tmp;
                setmax(m, tmp);
            }
        }
        xs.pb(x), ss.pb(mp(s, m));
        return s;
    };
    dfs(start, -1);
    for(auto& s : ss) {
        setmax(s.se, sz(xs) - s.fi - 1);
    }
    int center_i = 0;
    repn(i, sz(xs)) {
        if(ss[i].se < ss[center_i].se) center_i = i;
    }
    return mp(xs[center_i], xs);
}

void solve(int start) {
    int center;
    VI xs;
    tie(center, xs) = find_center(start);

    Trie tr;
    static Trie sub_tr[N];
    for(const auto& e : es[center]) {
        if(e.se->valid) {
            sub_tr[e.fi] = Trie();
            sub_tr[e.fi].add(e.fi, center, e.se->ch);
            sub_tr[e.fi].prepare();
            tr.add(e.fi, center, e.se->ch);
        }
    }
    tr.prepare();

    

    

    


    for(int x : xs) {
        for(const auto& q : qs[x]) {
            const int y = q.fi, qi = q.se;
            

            if(dis(x, y) < dis(x, center)) {
                int z = go(x, center, dis(x, y));
                int cmp = compare(x, z, x, y);
                if(cmp < 0) {
                    assert(center != x);
                    const int sub_x = next(center, x);
                    

                    ans[qi] += sz(xs) - sub_tr[sub_x].count();
                }
            } else {
                int z = go(x, y, dis(x, center));
                int cmp = compare(x, center, x, z);
                if(cmp < 0) {
                    assert(center != x);
                    const int sub_x = next(center, x);
                    ans[qi] += sz(xs) - sub_tr[sub_x].count();
                    

                } else if(cmp == 0) {
                    if(z != y && x != center) {
                        

                        ++ans[qi];
                    }
                    ans[qi] += tr.count_lt(z, y);
                    

                    if(x != center) {
                        const int sub_x = next(center, x);
                        ans[qi] -= sub_tr[sub_x].count_lt(z, y);
                        

                    }
                }
            }
        }
    }
    xs.clear();

    for(const auto& e : es[center]) {
        if(e.se->valid) {
            e.se->valid = false;
            solve(e.fi);
        }
    }
}

int main() {
    input();
    init();

    repn(i, n - 1) all_edges[i].valid = true;
    solve(0);
    repn(i, qn) printf("%d\n", ans[i]);
    return 0;
}
