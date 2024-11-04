#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <limits.h>
#include <queue>
#include <complex>
#include <map>
#include <set>
#include <vector>

#define MAX_MOD 1000000007
#define MOD 1000000007
#define eps 1e-9

typedef long long ll;
typedef struct {
    long double real;
    long double imag;
} Point;

typedef struct {
    Point first;
    Point second;
} Line;

typedef struct {
    Point center;
    long double r;
} Circle;

long double dot(Point a, Point b) {
    return (a.real * b.real + a.imag * b.imag);
}

long double cross(Point a, Point b) {
    return (a.real * b.imag - a.imag * b.real);
}

long double id3(Line a, Point b) {
    if (dot((Point){a.second.real - a.first.real, a.second.imag - a.first.imag}, (Point){b.real - a.first.real, b.imag - a.first.imag}) < eps) 
        return sqrt(pow(b.real - a.first.real, 2) + pow(b.imag - a.first.imag, 2));
    if (dot((Point){a.first.real - a.second.real, a.first.imag - a.second.imag}, (Point){b.real - a.second.real, b.imag - a.second.imag}) < eps) 
        return sqrt(pow(b.real - a.second.real, 2) + pow(b.imag - a.second.imag, 2));
    return fabs(cross((Point){a.second.real - a.first.real, a.second.imag - a.first.imag}, (Point){b.real - a.first.real, b.imag - a.first.imag})) / 
           sqrt(pow(a.second.real - a.first.real, 2) + pow(a.second.imag - a.first.imag, 2));
}

int id0(Line a, Line b) {
    return (cross((Point){a.second.real - a.first.real, a.second.imag - a.first.imag}, (Point){b.first.real - a.first.real, b.first.imag - a.first.imag}) * 
            cross((Point){a.second.real - a.first.real, a.second.imag - a.first.imag}, (Point){b.second.real - a.first.real, b.second.imag - a.first.imag}) < eps) &&
           (cross((Point){b.second.real - b.first.real, b.second.imag - b.first.imag}, (Point){a.first.real - b.first.real, a.first.imag - b.first.imag}) * 
            cross((Point){b.second.real - b.first.real, b.second.imag - b.first.imag}, (Point){a.second.real - b.first.real, a.second.imag - b.first.imag}) < eps);
}

Point intersection_l(Line a, Line b) {
    Point da = {a.second.real - a.first.real, a.second.imag - a.first.imag};
    Point db = {b.second.real - b.first.real, b.second.imag - b.first.imag};
    return (Point){a.first.real + da.real * cross(db, (Point){b.first.real - a.first.real, b.first.imag - a.first.imag}) / 
                   cross(db, da), 
                   a.first.imag + da.imag * cross(db, (Point){b.first.real - a.first.real, b.first.imag - a.first.imag}) / 
                   cross(db, da)};
}

long double id8(Line a, Line b) {
    if (id0(a, b) == 1) {
        return 0;
    }
    return fmin(fmin(id3(a, b.first), id3(a, b.second)), fmin(id3(b, a.first), id3(b, a.second)));
}

void id9(Circle a, Circle b, Point* l, Point* r) {
    long double dist = sqrt(pow(a.center.real - b.center.real, 2) + pow(a.center.imag - b.center.imag, 2));
    assert(dist <= eps + a.r + b.r);
    assert(dist + eps >= fabs(a.r - b.r));
    Point target = {b.center.real - a.center.real, b.center.imag - a.center.imag};
    long double pointer = target.real * target.real + target.imag * target.imag;
    long double aa = pointer + a.r * a.r - b.r * b.r;
    aa /= 2.0L;
    *l = (Point){(aa * target.real + target.imag * sqrt(pointer * a.r * a.r - aa * aa)) / pointer,
                  (aa * target.imag - target.real * sqrt(pointer * a.r * a.r - aa * aa)) / pointer};
    *r = (Point){(aa * target.real - target.imag * sqrt(pointer * a.r * a.r - aa * aa)) / pointer,
                  (aa * target.imag + target.real * sqrt(pointer * a.r * a.r - aa * aa)) / pointer};
    *l = (Point){l->real + a.center.real, l->imag + a.center.imag};
    *r = (Point){r->real + a.center.real, r->imag + a.center.imag};
}

ll gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll pows(ll val, ll b) {
    assert(b >= 1);
    ll ans = val;
    b--;
    while (b) {
        if (b % 2) {
            ans *= val;
        }
        val *= val;
        b /= 2LL;
    }
    return ans;
}

typedef struct {
    bool id6;
    std::map<ll, ll> zipper;
    std::map<ll, ll> unzipper;
    std::queue<ll> fetcher;
} Compressor;

void add(Compressor* comp, ll now) {
    assert(comp->id6 == false);
    comp->zipper[now] = 1;
    comp->fetcher.push(now);
}

void exec(Compressor* comp) {
    assert(comp->id6 == false);
    int cnt = 0;
    for (auto i = comp->zipper.begin(); i != comp->zipper.end(); ++i) {
        i->second = cnt;
        comp->unzipper[cnt] = i->first;
        cnt++;
    }
    comp->id6 = true;
}

ll fetch(Compressor* comp) {
    assert(comp->id6 == true);
    ll hoge = comp->fetcher.front();
    comp->fetcher.pop();
    return comp->zipper[hoge];
}

ll zip(Compressor* comp, ll now) {
    assert(comp->id6 == true);
    assert(comp->zipper.find(now) != comp->zipper.end());
    return comp->zipper[now];
}

ll unzip(Compressor* comp, ll a) {
    assert(comp->id6 == true);
    assert(a < comp->unzipper.size());
    return comp->unzipper[a];
}

ll next(Compressor* comp, ll now) {
    auto x = comp->zipper.upper_bound(now);
    if (x == comp->zipper.end()) return comp->zipper.size();
    return (ll)((*x).second);
}

ll back(Compressor* comp, ll now) {
    auto x = comp->zipper.lower_bound(now);
    if (x == comp->zipper.begin()) return -1;
    x--;
    return (ll)((*x).second);
}

typedef struct {
    std::vector<std::vector<ll>> data;
} Matrix;

Matrix create_matrix(std::vector<std::vector<ll>> a) {
    Matrix m;
    m.data = a;
    return m;
}

Matrix add_matrix(Matrix obj1, Matrix obj2) {
    std::vector<std::vector<ll>> ans;
    assert(obj2.data.size() == obj1.data.size());
    assert(obj2.data[0].size() == obj1.data[0].size());
    for (size_t i = 0; i < obj2.data.size(); i++) {
        std::vector<ll> row;
        for (size_t q = 0; q < obj2.data[i].size(); q++) {
            ll hoge = obj2.data[i][q] + (obj1.data[i][q]);
            row.push_back(hoge);
        }
        ans.push_back(row);
    }
    return create_matrix(ans);
}

Matrix subtract_matrix(Matrix obj1, Matrix obj2) {
    std::vector<std::vector<ll>> ans;
    assert(obj2.data.size() == obj1.data.size());
    assert(obj2.data[0].size() == obj1.data[0].size());
    for (size_t i = 0; i < obj2.data.size(); i++) {
        std::vector<ll> row;
        for (size_t q = 0; q < obj2.data[i].size(); q++) {
            ll hoge = obj1.data[i][q] - obj2.data[i][q];
            row.push_back(hoge);
        }
        ans.push_back(row);
    }
    return create_matrix(ans);
}

Matrix multiply_matrix(Matrix obj1, Matrix obj2) {
    std::vector<std::vector<ll>> ans;
    assert(obj2.data.size() == obj1.data[0].size());
    for (size_t i = 0; i < obj1.data.size(); i++) {
        std::vector<ll> row;
        for (size_t q = 0; q < obj2.data[0].size(); q++) {
            ll hoge = (obj1.data[i][0]) * (obj2.data[0][q]);
            for (int t = 1; t < obj2.data[i].size(); ++t) {
                hoge += obj1.data[i][t] * obj2.data[t][q];
            }
            row.push_back(hoge);
        }
        ans.push_back(row);
    }
    return create_matrix(ans);
}

typedef struct {
    ll a;
    ll b;
} Fraction;

Fraction create_fraction(ll c, ll d) {
    Fraction frac;
    int hoge = gcd(llabs(c), llabs(d));
    c /= hoge;
    d /= hoge;
    if (d < 0) {
        d *= -1;
        c *= -1;
    }
    frac.a = c;
    frac.b = d;
    return frac;
}

bool less_than_fraction(Fraction lhs, Fraction rhs) {
    return lhs.a * rhs.b < rhs.a * lhs.b;
}

typedef struct {
    uint64_t value;
} modint;

modint create_modint(ll a) {
    modint m;
    m.value = ((a % MAX_MOD) + 2 * MAX_MOD) % MAX_MOD;
    return m;
}

modint add_modint(modint lhs, modint rhs) {
    modint result = lhs;
    result.value += rhs.value;
    if (result.value >= MAX_MOD) {
        result.value -= MAX_MOD;
    }
    return result;
}

modint subtract_modint(modint lhs, modint rhs) {
    if (lhs.value < rhs.value) {
        lhs.value += MAX_MOD;
    }
    lhs.value -= rhs.value;
    return lhs;
}

modint multiply_modint(modint lhs, modint rhs) {
    modint result;
    result.value = (lhs.value * rhs.value) % MAX_MOD;
    return result;
}

modint divide_modint(modint lhs, modint rhs) {
    ll rem = MAX_MOD - 2;
    while (rem) {
        if (rem % 2) {
            lhs = multiply_modint(lhs, rhs);
        }
        rhs = multiply_modint(rhs, rhs);
        rem /= 2LL;
    }
    return lhs;
}

bool less_than_modint(modint lhs, modint rhs) {
    return lhs.value < rhs.value;
}

void print_modint(modint p) {
    printf("%llu\n", p.value);
}

typedef struct {
    std::vector<ll> vertexs;
} Dice;

Dice create_dice(std::vector<ll> init) {
    Dice d;
    d.vertexs = init;
    return d;
}

void RtoL(Dice* d) {
    for (int q = 1; q < 4; ++q) {
        ll temp = d->vertexs[q];
        d->vertexs[q] = d->vertexs[q + 1];
        d->vertexs[q + 1] = temp;
    }
}

void LtoR(Dice* d) {
    for (int q = 3; q >= 1; --q) {
        ll temp = d->vertexs[q];
        d->vertexs[q] = d->vertexs[q + 1];
        d->vertexs[q + 1] = temp;
    }
}

void UtoD(Dice* d) {
    ll temp = d->vertexs[5];
    d->vertexs[5] = d->vertexs[4];
    d->vertexs[4] = d->vertexs[2];
    d->vertexs[2] = d->vertexs[0];
    d->vertexs[0] = temp;
}

void DtoU(Dice* d) {
    ll temp = d->vertexs[0];
    d->vertexs[0] = d->vertexs[2];
    d->vertexs[2] = d->vertexs[5];
    d->vertexs[5] = d->vertexs[4];
}

bool ReachAble(Dice now, Dice target) {
    std::set<Dice> hoge;
    std::queue<Dice> next;
    next.push(now);
    hoge.insert(now);
    while (!next.empty()) {
        Dice seeing = next.front();
        next.pop();
        if (seeing == target) return true;
        RtoL(&seeing);
        if (hoge.count(seeing) == 0) {
            hoge.insert(seeing);
            next.push(seeing);
        }
        LtoR(&seeing);
        LtoR(&seeing);
        if (hoge.count(seeing) == 0) {
            hoge.insert(seeing);
            next.push(seeing);
        }
        RtoL(&seeing);
        UtoD(&seeing);
        if (hoge.count(seeing) == 0) {
            hoge.insert(seeing);
            next.push(seeing);
        }
        DtoU(&seeing);
        DtoU(&seeing);
        if (hoge.count(seeing) == 0) {
            hoge.insert(seeing);
            next.push(seeing);
        }
    }
    return false;
}

bool equal_dice(Dice a, Dice b) {
    for (int q = 0; q < 6; ++q) {
        if (a.vertexs[q] != b.vertexs[q]) {
            return false;
        }
    }
    return true;
}

bool less_than_dice(Dice a, Dice b) {
    return a.vertexs < b.vertexs;
}

std::pair<Dice, Dice> id1(int center, int up) {
    int target = 1;
    while (true) {
        if (center != target && 7 - center != target && up != target && 7 - up != target) {
            break;
        }
        target++;
    }
    return std::make_pair(create_dice((std::vector<ll>){up, target, center, 7 - target, 7 - center, 7 - up}),
                           create_dice((std::vector<ll>){up, 7 - target, center, target, 7 - center, 7 - up}));
}

std::tuple<Dice, Dice, Dice, Dice> id2(int center) {
    int bo = fmin(center, 7 - center);
    std::pair<int, int> goa;
    if (bo == 1) {
        goa = std::make_pair(2, 3);
    } else if (bo == 2) {
        goa = std::make_pair(1, 3);
    } else if (bo == 3) {
        goa = std::make_pair(1, 2);
    }
    return std::make_tuple(create_dice((std::vector<ll>){goa.first, goa.second, center, 7 - goa.second, 7 - center, 7 - goa.first}),
                           create_dice((std::vector<ll>){goa.first, 7 - goa.second, center, goa.second, 7 - center, 7 - goa.first}),
                           create_dice((std::vector<ll>){7 - goa.first, goa.second, center, 7 - goa.second, 7 - center, goa.first}),
                           create_dice((std::vector<ll>){7 - goa.first, 7 - goa.second, center, goa.second, 7 - center, goa.first}));
}

typedef struct {
    std::vector<std::vector<std::pair<int, ll>>> vertexs;
    ll (*Cost_Function)(ll);
} Dijkstra;

Dijkstra create_dijkstra(int n, ll (*cost)(ll)) {
    Dijkstra d;
    d.vertexs = std::vector<std::vector<std::pair<int, ll>>>(n, std::vector<std::pair<int, ll>>{});
    d.Cost_Function = cost;
    return d;
}

void add_edge(Dijkstra* d, int a, int b, ll c) {
    d->vertexs[a].push_back(std::make_pair(b, c));
}

std::vector<ll> build_result(Dijkstra* d, int StartPoint) {
    std::vector<ll> dist(d->vertexs.size(), 2e18);
    dist[StartPoint] = 0;
    std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>, std::greater<std::pair<ll, int>>> next;
    next.push(std::make_pair(0, StartPoint));
    while (!next.empty()) {
        std::pair<ll, int> now = next.top();
        next.pop();
        if (dist[now.second] != now.first) continue;
        for (auto x : d->vertexs[now.second]) {
            ll now_cost = now.first + d->Cost_Function(x.second);
            if (dist[x.first] > now_cost) {
                dist[x.first] = now_cost;
                next.push(std::make_pair(now_cost, x.first));
            }
        }
    }
    return dist;
}

typedef struct {
    struct edge {
        int to;
        int cap;
        int rev;
    };
    std::vector<std::vector<edge>> Graph;
    std::vector<int> level;
    std::vector<int> itr;
} Dinic;

Dinic create_dinic(int n) {
    Dinic d;
    d.Graph = std::vector<std::vector<edge>>(n, std::vector<edge>());
    return d;
}

void add_edge_dinic(Dinic* d, int a, int b, int cap) {
    d->Graph[a].push_back((edge){b, cap, (int)d->Graph[b].size()});
    d->Graph[b].push_back((edge){a, 0, (int)d->Graph[a].size() - 1});
}

void bfs(Dinic* d, int s) {
    d->level = std::vector<int>(d->Graph.size(), -1);
    d->level[s] = 0;
    std::queue<int> next;
    next.push(s);
    while (!next.empty()) {
        int now = next.front();
        next.pop();
        for (auto x : d->Graph[now]) {
            if (x.cap == 0) continue;
            if (d->level[x.to] == -1) {
                d->level[x.to] = d->level[now] + 1;
                next.push(x.to);
            }
        }
    }
}

int dfs(Dinic* d, int now, int goal, int val) {
    if (goal == now) return val;
    for (int& i = d->itr[now]; i < (int)d->Graph[now].size(); ++i) {
        edge* target = &d->Graph[now][i];
        if (target->cap > 0 && d->level[now] < d->level[target->to]) {
            int d = dfs(d, target->to, goal, fmin(val, target->cap));
            if (d > 0) {
                target->cap -= d;
                d->Graph[target->to][target->rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int run(Dinic* d, int s, int t) {
    int ans = 0;
    int f = 0;
    while (bfs(d, s), d->level[t] >= 0) {
        d->itr = std::vector<int>(d->Graph.size(), 0);
        while ((f = dfs(d, s, t, 1e9)) > 0) {
            ans += f;
        }
    }
    return ans;
}

typedef struct {
    std::vector<std::vector<int>> vertexs;
    std::vector<int> depth;
    std::vector<int> backs;
    std::vector<int> connections;
    std::vector<int> zip, unzip;
} id7;

id7 create_id7(int n) {
    id7 id;
    id.vertexs = std::vector<std::vector<int>>(n, std::vector<int>());
    id.depth = std::vector<int>(n);
    id.zip = std::vector<int>(n);
    id.unzip = id.zip;
    return id;
}

void add_edge_id7(id7* id, int a, int b) {
    id->vertexs[a].push_back(b);
    id->vertexs[b].push_back(a);
}

int depth_dfs(id7* id, int now, int back) {
    id->depth[now] = 0;
    for (auto x : id->vertexs[now]) {
        if (x == back) continue;
        id->depth[now] = fmax(id->depth[now], 1 + depth_dfs(id, x, now));
    }
    return id->depth[now];
}

void dfs_id7(id7* id, int now, int backing) {
    id->zip[now] = id->backs.size();
    id->unzip[id->backs.size()] = now;
    id->backs.push_back(backing);
    int now_max = -1;
    int itr = -1;
    for (auto x : id->vertexs[now]) {
        if (id->depth[x] > id->depth[now]) continue;
        if (now_max < id->depth[x]) {
            now_max = id->depth[x];
            itr = x;
        }
    }
    if (itr == -1) return;
    id->connections.push_back(id->connections.back());
    dfs_id7(id, itr, backing);
    for (auto x : id->vertexs[now]) {
        if (id->depth[x] > id->depth[now]) continue;
        if (x == itr) continue;
        id->connections.push_back(id->zip[now]);
        dfs_id7(id, x, id->backs.size());
    }
    return;
}

void build_id7(id7* id) {
    depth_dfs(id, 0, -1);
    id->connections.push_back(-1);
    dfs_id7(id, 0, -1);
}

std::vector<std::pair<int, int>> query_id7(id7* id, int a, int b) {
    a = id->zip[a];
    b = id->zip[b];
    std::vector<std::pair<int, int>> ans;
    while (id->backs[a] != id->backs[b]) {
        if (a < b) swap(a, b);
        ans.push_back(std::make_pair(id->backs[a], a + 1));
        a = id->connections[a];
    }
    if (a > b) swap(a, b);
    ans.push_back(std::make_pair(a, b + 1));
    return ans;
}

int lca_id7(id7* id, int a, int b) {
    a = id->zip[a];
    b = id->zip[b];
    while (id->backs[a] != id->backs[b]) {
        if (a < b) swap(a, b);
        a = id->connections[a];
    }
    return id->unzip[fmin(a, b)];
}

typedef struct {
    std::function<ll(ll, ll)> f;
    std::function<ll(ll, ll, int)> g;
    std::function<ll(ll, ll)> h;
    int sz;
    std::vector<ll> data;
    std::vector<ll> lazy;
    ll M1;
    ll OM0;
} SegmentTree;

SegmentTree create_segment_tree(int n, std::function<ll(ll, ll)> f, std::function<ll(ll, ll, int)> g, std::function<ll(ll, ll)> h, ll M1, ll OM0) {
    SegmentTree st;
    st.f = f;
    st.g = g;
    st.h = h;
    st.sz = 1;
    while (st.sz < n) st.sz <<= 1;
    st.data.assign(2 * st.sz, M1);
    st.lazy.assign(2 * st.sz, OM0);
    return st;
}

void set_segment_tree(SegmentTree* st, int k, ll x) {
    st->data[k + st->sz] = x;
}

void build_segment_tree(SegmentTree* st) {
    for (int k = st->sz - 1; k > 0; k--) {
        st->data[k] = st->f(st->data[2 * k + 0], st->data[2 * k + 1]);
    }
}

void update_segment_tree(SegmentTree* st, int k, ll x) {
    k += st->sz;
    st->data[k] = x;
    while (k >>= 1) {
        st->data[k] = st->f(st->data[2 * k + 0], st->data[2 * k + 1]);
    }
}

ll query_segment_tree(SegmentTree* st, int a, int b) {
    ll L = st->M1, R = st->M1;
    for (a += st->sz, b += st->sz; a < b; a >>= 1, b >>= 1) {
        if (a & 1) L = st->f(L, st->data[a++]);
        if (b & 1) R = st->f(st->data[--b], R);
    }
    return st->f(L, R);
}

ll operator_segment_tree(SegmentTree* st, const int* k) {
    return st->data[k + st->sz];
}

typedef struct {
    std::function<ll(ll, ll)> f;
    std::function<ll(ll, ll, int)> g;
    std::function<ll(ll, ll)> h;
    int sz;
    std::vector<ll> data;
    std::vector<ll> lazy;
    ll M1;
    ll OM0;
} id5;

id5 create_id5(int n, std::function<ll(ll, ll)> f, std::function<ll(ll, ll, int)> g, std::function<ll(ll, ll)> h, ll M1, ll OM0) {
    id5 id;
    id.f = f;
    id.g = g;
    id.h = h;
    id.sz = 1;
    while (id.sz < n) id.sz <<= 1;
    id.data.assign(2 * id.sz, M1);
    id.lazy.assign(2 * id.sz, OM0);
    return id;
}

void set_id5(id5* id, int k, ll x) {
    id->data[k + id->sz] = x;
}

void build_id5(id5* id) {
    for (int k = id->sz - 1; k > 0; k--) {
        id->data[k] = id->f(id->data[2 * k + 0], id->data[2 * k + 1]);
    }
}

void propagate_id5(id5* id, int k) {
    if (id->lazy[k] != id->OM0) {
        id->lazy[2 * k + 0] = id->h(id->lazy[2 * k + 0], id->lazy[k]);
        id->lazy[2 * k + 1] = id->h(id->lazy[2 * k + 1], id->lazy[k]);
        id->data[k] = reflect_id5(id, k);
        id->lazy[k] = id->OM0;
    }
}

ll reflect_id5(id5* id, int k) {
    if (id->lazy[k] == id->OM0) return id->data[k];
    for (int q = id->sz; q >= 0; q /= 2) {
        if (q & k) {
            return id->g(id->data[k], id->lazy[k], id->sz / q);
        }
    }
}

void recalc_id5(id5* id, int k) {
    while (k >>= 1) id->data[k] = id->f(reflect_id5(id, 2 * k + 0), reflect_id5(id, 2 * k + 1));
}

void thrust_id5(id5* id, int k) {
    for (int i = id->height; i > 0; i--) propagate_id5(id, k >> i);
}

void update_id5(id5* id, int a, int b, ll x) {
    thrust_id5(id, a += id->sz);
    thrust_id5(id, b += id->sz - 1);
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) id->lazy[l] = id->h(id->lazy[l], x), ++l;
        if (r & 1) --r, id->lazy[r] = id->h(id->lazy[r], x);
    }
    recalc_id5(id, a);
    recalc_id5(id, b);
}

ll query_id5(id5* id, int a, int b) {
    thrust_id5(id, a += id->sz);
    thrust_id5(id, b += id->sz - 1);
    ll L = id->M1, R = id->M1;
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) L = id->f(L, reflect_id5(id, l++));
        if (r & 1) R = id->f(reflect_id5(id, --r), R);
    }
    return id->f(L, R);
}

ll operator_id5(id5* id, const int* k) {
    return query_id5(id, k, k + 1);
}

typedef struct {
    std::vector<int> table;
    std::vector<int> Pattern;
} KMP;

KMP create_kmp(std::vector<int> a) {
    KMP k;
    build_kmp(&k, a);
    return k;
}

void build_kmp(KMP* k, std::vector<int> a) {
    k->Pattern = a;
    k->table = std::vector<int>(a.size() + 1, -1);
    int j = -1;
    for (int i = 0; i < a.size(); ++i) {
        while (j >= 0 && k->Pattern[i] != k->Pattern[j]) {
            j = k->table[j];
        }
        k->table[i + 1] = ++j;
    }
}

std::vector<int> search_kmp(KMP* k, std::vector<int> a) {
    std::vector<int> ans;
    for (int i = 0, k_index = 0; i < a.size(); ++i) {
        while (k_index >= 0 && a[i] != k->Pattern[k_index]) k_index = k->table[k_index];
        ++k_index;
        if (k_index >= k->Pattern.size()) {
            ans.push_back(i - k->Pattern.size() + 1);
            k_index = k->table[k_index];
        }
    }
    return ans;
}

unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

void init() {
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(200);
}

std::vector<int> cnter;
std::pair<modint, modint> hoge[300000] = {};
std::pair<modint, modint> rev[300000] = {};

void solve() {
    int n;
    scanf("%d", &n);
    char t[300000];
    scanf("%s", t);
    for (int i = 0; i < strlen(t); i++) {
        if (t[i] == '0') {
            cnter.push_back(i * 2 + i % 2);
        }
    }
    std::pair<modint, modint> nexts;
    nexts.first = create_modint(1);
    nexts.second = create_modint(1);
    for (int i = 0; i < cnter.size(); i++) {
        hoge[i + 1] = hoge[i];
        hoge[i + 1].first = add_modint(hoge[i + 1].first, multiply_modint(nexts.first, create_modint(cnter[i] % 2)));
        hoge[i + 1].second = add_modint(hoge[i + 1].second, multiply_modint(nexts.second, create_modint(cnter[i] % 2)));
        rev[i + 1] = rev[i];
        rev[i + 1].first = add_modint(rev[i + 1].first, multiply_modint(nexts.first, create_modint((cnter[i] + 1) % 2)));
        rev[i + 1].second = add_modint(rev[i + 1].second, multiply_modint(nexts.second, create_modint((cnter[i] + 1) % 2)));
        nexts.first = multiply_modint(nexts.first, create_modint(2));
        nexts.second = multiply_modint(nexts.second, create_modint(2));
    }
    int query;
    scanf("%d", &query);
    for (int i = 0; i < query; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--; b--;
        std::pair<int, int> Left = std::make_pair(lower_bound(cnter.begin(), cnter.end(), a * 2) - cnter.begin(), 
                                                    lower_bound(cnter.begin(), cnter.end(), (a + c) * 2) - cnter.begin());
        std::pair<int, int> Right = std::make_pair(lower_bound(cnter.begin(), cnter.end(), b * 2) - cnter.begin(), 
                                                     lower_bound(cnter.begin(), cnter.end(), (b + c) * 2) - cnter.begin());
        if (Left.second - Left.first != Right.second - Right.first) {
            printf("No\n");
            continue;
        }
        int ok = 1;
        std::pair<modint, modint> aa, bb;
        aa = hoge[Left.second];
        aa.first = subtract_modint(hoge[Left.second].first, hoge[Left.first].first);
        aa.second = subtract_modint(hoge[Left.second].second, hoge[Left.first].second);
        if (a % 2 == b % 2) {
            bb = hoge[Right.second];
            bb.first = subtract_modint(hoge[Right.second].first, hoge[Right.first].first);
            bb.second = subtract_modint(hoge[Right.second].second, hoge[Right.first].second);
        } else {
            bb = rev[Right.second];
            bb.first = subtract_modint(rev[Right.second].first, rev[Right.first].first);
            bb.second = subtract_modint(rev[Right.second].second, rev[Right.first].second);
        }
        if (Left.first != 0) {
            aa.first = divide_modint(aa.first, pows(create_modint(2), Left.first));
            aa.second = divide_modint(aa.second, pows(create_modint(2), Left.first));
        }
        if (Right.first != 0) {
            bb.first = divide_modint(bb.first, pows(create_modint(2), Right.first));
            bb.second = divide_modint(bb.second, pows(create_modint(2), Right.first));
        }
        if (aa.first.value != bb.first.value || aa.second.value != bb.second.value) {
            ok = 0;
        }
        if (ok == 1) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}

int main() {
    init();
    solve();
    return 0;
}
