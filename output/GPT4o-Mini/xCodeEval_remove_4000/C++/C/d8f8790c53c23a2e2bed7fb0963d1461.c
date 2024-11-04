#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

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
    if (dot((Point){a.second.real - a.first.real, a.second.imag - a.first.imag}, (Point){b.real - a.first.real, b.imag - a.first.imag}) < 1e-9) return hypot(b.real - a.first.real, b.imag - a.first.imag);
    if (dot((Point){a.first.real - a.second.real, a.first.imag - a.second.imag}, (Point){b.real - a.second.real, b.imag - a.second.imag}) < 1e-9) return hypot(b.real - a.second.real, b.imag - a.second.imag);
    return fabs(cross((Point){a.second.real - a.first.real, a.second.imag - a.first.imag}, (Point){b.real - a.first.real, b.imag - a.first.imag})) / hypot(a.second.real - a.first.real, a.second.imag - a.first.imag);
}

int id0(Line a, Line b) {
    return (cross((Point){a.second.real - a.first.real, a.second.imag - a.first.imag}, (Point){b.first.real - a.first.real, b.first.imag - a.first.imag}) * cross((Point){a.second.real - a.first.real, a.second.imag - a.first.imag}, (Point){b.second.real - a.first.real, b.second.imag - a.first.imag}) < 1e-9) &&
           (cross((Point){b.second.real - b.first.real, b.second.imag - b.first.imag}, (Point){a.first.real - b.first.real, a.first.imag - b.first.imag}) * cross((Point){b.second.real - b.first.real, b.second.imag - b.first.imag}, (Point){a.second.real - b.first.real, a.second.imag - b.first.imag}) < 1e-9);
}

Point intersection_l(Line a, Line b) {
    Point da = {a.second.real - a.first.real, a.second.imag - a.first.imag};
    Point db = {b.second.real - b.first.real, b.second.imag - b.first.imag};
    return (Point){a.first.real + da.real * cross(db, (Point){b.first.real - a.first.real, b.first.imag - a.first.imag}) / cross(db, da),
                   a.first.imag + da.imag * cross(db, (Point){b.first.real - a.first.real, b.first.imag - a.first.imag}) / cross(db, da)};
}

long double id8(Line a, Line b) {
    if (id0(a, b) == 1) {
        return 0;
    }
    return fmin(fmin(id3(a, b.first), id3(a, b.second)), fmin(id3(b, a.first), id3(b, a.second)));
}

void id9(Circle a, Circle b, Point *l, Point *r) {
    long double dist = hypot(a.center.real - b.center.real, a.center.imag - b.center.imag);
    assert(dist <= 1e-9 + a.r + b.r);
    assert(dist + 1e-9 >= fabs(a.r - b.r));
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

void Compressor_init(Compressor *c) {
    c->id6 = false;
    c->zipper.clear();
    c->unzipper.clear();
}

void Compressor_add(Compressor *c, ll now) {
    assert(c->id6 == false);
    c->zipper[now] = 1;
    c->fetcher.push(now);
}

void Compressor_exec(Compressor *c) {
    assert(c->id6 == false);
    int cnt = 0;
    for (auto i = c->zipper.begin(); i != c->zipper.end(); ++i) {
        i->second = cnt;
        c->unzipper[cnt] = i->first;
        cnt++;
    }
    c->id6 = true;
}

ll Compressor_fetch(Compressor *c) {
    assert(c->id6 == true);
    ll hoge = c->fetcher.front();
    c->fetcher.pop();
    return c->zipper[hoge];
}

ll Compressor_zip(Compressor *c, ll now) {
    assert(c->id6 == true);
    assert(c->zipper.find(now) != c->zipper.end());
    return c->zipper[now];
}

ll Compressor_unzip(Compressor *c, ll a) {
    assert(c->id6 == true);
    assert(a < c->unzipper.size());
    return c->unzipper[a];
}

ll Compressor_next(Compressor *c, ll now) {
    auto x = c->zipper.upper_bound(now);
    if (x == c->zipper.end()) return c->zipper.size();
    return (ll)((*x).second);
}

ll Compressor_back(Compressor *c, ll now) {
    auto x = c->zipper.lower_bound(now);
    if (x == c->zipper.begin()) return -1;
    x--;
    return (ll)((*x).second);
}

typedef struct {
    std::vector<std::vector<ll>> data;
} Matrix;

Matrix Matrix_init(std::vector<std::vector<ll>> a) {
    Matrix m;
    m.data = a;
    return m;
}

Matrix Matrix_add(Matrix obj1, Matrix obj2) {
    std::vector<std::vector<ll>> ans;
    assert(obj2.data.size() == obj1.data.size());
    assert(obj2.data[0].size() == obj1.data[0].size());
    for (int i = 0; i < obj2.data.size(); i++) {
        ans.push_back(std::vector<ll>());
        for (int q = 0; q < obj2.data[i].size(); q++) {
            ll hoge = obj2.data[i][q] + (obj1.data[i][q]);
            ans.back().push_back(hoge);
        }
    }
    return Matrix_init(ans);
}

Matrix Matrix_sub(Matrix obj1, Matrix obj2) {
    std::vector<std::vector<ll>> ans;
    assert(obj2.data.size() == obj1.data.size());
    assert(obj2.data[0].size() == obj1.data[0].size());
    for (int i = 0; i < obj2.data.size(); i++) {
        ans.push_back(std::vector<ll>());
        for (int q = 0; q < obj2.data[i].size(); q++) {
            ll hoge = obj1.data[i][q] - obj2.data[i][q];
            ans.back().push_back(hoge);
        }
    }
    return Matrix_init(ans);
}

Matrix Matrix_mul(Matrix obj1, Matrix obj2) {
    std::vector<std::vector<ll>> ans;
    assert(obj2.data.size() == obj1.data[0].size());
    for (int i = 0; i < obj1.data.size(); i++) {
        ans.push_back(std::vector<ll>());
        for (int q = 0; q < obj2.data[0].size(); q++) {
            ll hoge = (obj1.data[i][0]) * (obj2.data[0][q]);
            for (int t = 1; t < obj2.data[i].size(); ++t) {
                hoge += obj1.data[i][t] * obj2.data[t][q];
            }
            ans.back().push_back(hoge);
        }
    }
    return Matrix_init(ans);
}

typedef struct {
    uint_fast64_t value;
} modint;

modint modint_init(ll a) {
    modint m;
    m.value = ((a % 1000000007) + 2 * 1000000007) % 1000000007;
    return m;
}

modint modint_add(modint a, modint b) {
    return modint_init(a.value + b.value);
}

modint modint_sub(modint a, modint b) {
    if (a.value < b.value) {
        a.value += 1000000007;
    }
    a.value -= b.value;
    return a;
}

modint modint_mul(modint a, modint b) {
    a.value = (a.value * b.value) % 1000000007;
    return a;
}

modint modint_div(modint a, modint b) {
    ll rem = 1000000007 - 2;
    while (rem) {
        if (rem % 2) {
            a = modint_mul(a, b);
        }
        b = modint_mul(b, b);
        rem /= 2LL;
    }
    return a;
}

bool modint_less(modint a, modint b) {
    return a.value < b.value;
}

void modint_print(modint m) {
    printf("%llu\n", m.value);
}

typedef struct {
    std::vector<ll> vertexs;
} Dice;

Dice Dice_init(std::vector<ll> init) {
    Dice d;
    d.vertexs = init;
    return d;
}

void Dice_RtoL(Dice *d) {
    for (int q = 1; q < 4; ++q) {
        ll temp = d->vertexs[q];
        d->vertexs[q] = d->vertexs[q + 1];
        d->vertexs[q + 1] = temp;
    }
}

void Dice_LtoR(Dice *d) {
    for (int q = 3; q >= 1; --q) {
        ll temp = d->vertexs[q];
        d->vertexs[q] = d->vertexs[q + 1];
        d->vertexs[q + 1] = temp;
    }
}

void Dice_UtoD(Dice *d) {
    ll temp = d->vertexs[5];
    d->vertexs[5] = d->vertexs[4];
    d->vertexs[4] = d->vertexs[2];
    d->vertexs[2] = d->vertexs[0];
    d->vertexs[0] = temp;
}

void Dice_DtoU(Dice *d) {
    ll temp = d->vertexs[0];
    d->vertexs[0] = d->vertexs[2];
    d->vertexs[2] = d->vertexs[5];
    d->vertexs[5] = d->vertexs[4];
}

bool Dice_ReachAble(Dice now, Dice target) {
    std::set<Dice> hoge;
    std::queue<Dice> next;
    next.push(now);
    hoge.insert(now);
    while (!next.empty()) {
        Dice seeing = next.front();
        next.pop();
        if (seeing == target) return true;
        Dice_RtoL(&seeing);
        if (hoge.count(seeing) == 0) {
            hoge.insert(seeing);
            next.push(seeing);
        }
        Dice_LtoR(&seeing);
        Dice_LtoR(&seeing);
        if (hoge.count(seeing) == 0) {
            hoge.insert(seeing);
            next.push(seeing);
        }
        Dice_RtoL(&seeing);
        Dice_UtoD(&seeing);
        if (hoge.count(seeing) == 0) {
            hoge.insert(seeing);
            next.push(seeing);
        }
        Dice_DtoU(&seeing);
        Dice_DtoU(&seeing);
        if (hoge.count(seeing) == 0) {
            hoge.insert(seeing);
            next.push(seeing);
        }
    }
    return false;
}

bool Dice_equal(Dice a, Dice b) {
    for (int q = 0; q < 6; ++q) {
        if (b.vertexs[q] != a.vertexs[q]) {
            return false;
        }
    }
    return true;
}

bool Dice_less(Dice a, Dice b) {
    return a.vertexs < b.vertexs;
}

void id1(int center, int up, Dice *d1, Dice *d2) {
    int target = 1;
    while (true) {
        if (center != target && 7 - center != target && up != target && 7 - up != target) {
            break;
        }
        target++;
    }
    *d1 = Dice_init((std::vector<ll>){up, target, center, 7 - target, 7 - center, 7 - up});
    *d2 = Dice_init((std::vector<ll>){up, 7 - target, center, target, 7 - center, 7 - up});
}

void id2(int center, Dice *d1, Dice *d2, Dice *d3, Dice *d4) {
    int bo = fmin(center, 7 - center);
    int goa1, goa2;
    if (bo == 1) {
        goa1 = 2; goa2 = 3;
    } else if (bo == 2) {
        goa1 = 1; goa2 = 3;
    } else if (bo == 3) {
        goa1 = 1; goa2 = 2;
    }
    *d1 = Dice_init((std::vector<ll>){goa1, goa2, center, 7 - goa2, 7 - center, 7 - goa1});
    *d2 = Dice_init((std::vector<ll>){goa1, 7 - goa2, center, goa2, 7 - center, 7 - goa1});
    *d3 = Dice_init((std::vector<ll>){7 - goa1, goa2, center, 7 - goa2, 7 - center, goa1});
    *d4 = Dice_init((std::vector<ll>){7 - goa1, 7 - goa2, center, goa2, 7 - center, goa1});
}

typedef struct {
    std::vector<std::vector<std::pair<int, ll>>> vertexs;
    ll (*Cost_Function)(ll);
} Dijkstra;

Dijkstra Dijkstra_init(int n, ll (*cost)(ll)) {
    Dijkstra d;
    d.vertexs = std::vector<std::vector<std::pair<int, ll>>>(n, std::vector<std::pair<int, ll>>{});
    d.Cost_Function = cost;
    return d;
}

void Dijkstra_add_edge(Dijkstra *d, int a, int b, ll c) {
    d->vertexs[a].push_back((std::pair<int, ll>){b, c});
}

std::vector<ll> Dijkstra_build_result(Dijkstra *d, int StartPoint) {
    std::vector<ll> dist(d->vertexs.size(), 2e18);
    dist[StartPoint] = 0;
    std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>, std::greater<std::pair<ll, int>>> next;
    next.push((std::pair<ll, int>){0, StartPoint});
    while (!next.empty()) {
        std::pair<ll, int> now = next.top();
        next.pop();
        if (dist[now.second] != now.first) continue;
        for (auto x : d->vertexs[now.second]) {
            ll now_cost = now.first + d->Cost_Function(x.second);
            if (dist[x.first] > now_cost) {
                dist[x.first] = now_cost;
                next.push((std::pair<ll, int>){now_cost, x.first});
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

Dinic Dinic_init(int n) {
    Dinic d;
    d.Graph = std::vector<std::vector<edge>>(n, std::vector<edge>());
    return d;
}

void Dinic_add_edge(Dinic *d, int a, int b, int cap) {
    d->Graph[a].push_back((edge){b, cap, (int)d->Graph[b].size()});
    d->Graph[b].push_back((edge){a, 0, (int)d->Graph[a].size() - 1});
}

void Dinic_bfs(Dinic *d, int s) {
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

int Dinic_dfs(Dinic *d, int now, int goal, int val) {
    if (goal == now) return val;
    for (int &i = d->itr[now]; i < (int)d->Graph[now].size(); ++i) {
        edge *target = &d->Graph[now][i];
        if (target->cap > 0 && d->level[now] < d->level[target->to]) {
            int d = Dinic_dfs(d, target->to, goal, fmin(val, target->cap));
            if (d > 0) {
                target->cap -= d;
                d->Graph[target->to][target->rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int Dinic_run(Dinic *d, int s, int t) {
    int ans = 0;
    int f = 0;
    while (1) {
        Dinic_bfs(d, s);
        if (d->level[t] < 0) break;
        d->itr = std::vector<int>(d->Graph.size(), 0);
        while ((f = Dinic_dfs(d, s, t, 1e9)) > 0) {
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

id7 id7_init(int n) {
    id7 d;
    d.vertexs = std::vector<std::vector<int>>(n, std::vector<int>());
    d.depth = std::vector<int>(n);
    d.zip = std::vector<int>(n);
    d.unzip = d.zip;
    return d;
}

void id7_add_edge(id7 *d, int a, int b) {
    d->vertexs[a].push_back(b);
    d->vertexs[b].push_back(a);
}

int id7_depth_dfs(id7 *d, int now, int back) {
    d->depth[now] = 0;
    for (auto x : d->vertexs[now]) {
        if (x == back) continue;
        d->depth[now] = fmax(d->depth[now], 1 + id7_depth_dfs(d, x, now));
    }
    return d->depth[now];
}

void id7_dfs(id7 *d, int now, int backing) {
    d->zip[now] = d->backs.size();
    d->unzip[d->backs.size()] = now;
    d->backs.push_back(backing);
    int now_max = -1;
    int itr = -1;
    for (auto x : d->vertexs[now]) {
        if (d->depth[x] > d->depth[now]) continue;
        if (now_max < d->depth[x]) {
            now_max = d->depth[x];
            itr = x;
        }
    }
    if (itr == -1) return;
    d->connections.push_back(d->connections.back());
    id7_dfs(d, itr, backing);
    for (auto x : d->vertexs[now]) {
        if (d->depth[x] > d->depth[now]) continue;
        if (x == itr) continue;
        d->connections.push_back(d->zip[now]);
        id7_dfs(d, x, d->backs.size());
    }
    return;
}

void id7_build(id7 *d) {
    id7_depth_dfs(d, 0, -1);
    d->connections.push_back(-1);
    id7_dfs(d, 0, -1);
}

std::vector<std::pair<int, int>> id7_query(id7 *d, int a, int b) {
    a = d->zip[a];
    b = d->zip[b];
    std::vector<std::pair<int, int>> ans;
    while (d->backs[a] != d->backs[b]) {
        if (a < b) swap(a, b);
        ans.push_back((std::pair<int, int>){d->backs[a], a + 1});
        a = d->connections[a];
    }
    if (a > b) swap(a, b);
    ans.push_back((std::pair<int, int>){a, b + 1});
    return ans;
}

int id7_lca(id7 *d, int a, int b) {
    a = d->zip[a];
    b = d->zip[b];
    while (d->backs[a] != d->backs[b]) {
        if (a < b) swap(a, b);
        a = d->connections[a];
    }
    return d->unzip[fmin(a, b)];
}

typedef struct {
    std::vector<int> table;
    std::vector<int> Pattern;
} KMP;

KMP KMP_init(std::vector<int> a) {
    KMP k;
    k.Pattern = a;
    k.table = std::vector<int>(a.size() + 1, -1);
    int j = -1;
    for (int i = 0; i < a.size(); ++i) {
        while (j >= 0 && k.Pattern[i] != k.Pattern[j]) {
            j = k.table[j];
        }
        k.table[i + 1] = ++j;
    }
    return k;
}

std::vector<int> KMP_search(KMP *k, std::vector<int> a) {
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
    // No equivalent in C
}

typedef struct {
    ll a;
    ll b;
} Fraction;

bool Fraction_less(Fraction lhs, Fraction rhs) {
    return lhs.a * rhs.b < rhs.a * lhs.b;
}

void solve() {
    int n, w;
    scanf("%d %d", &n, &w);
    std::vector<std::pair<Fraction, Fraction>> FI;
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        Fraction Left = { -a, b - w };
        Fraction Right = { -a, b + w };
        {
            int hoge = gcd(llabs(Left.a), llabs(Left.b));
            Left.a /= hoge;
            Left.b /= hoge;
        }
        {
            int hoge = gcd(llabs(Right.a), llabs(Right.b));
            Right.a /= hoge;
            Right.b /= hoge;
        }
        if (Left.b < 0) {
            Left.a *= -1;
            Left.b *= -1;
        }
        if (Right.b < 0) {
            Right.a *= -1;
            Right.b *= -1;
        }
        Right.a *= -1;
        FI.push_back((std::pair<Fraction, Fraction>){Left, Right});
    }
    std::sort(FI.begin(), FI.end(), [](std::pair<Fraction, Fraction> lhs, std::pair<Fraction, Fraction> rhs) {
        return Fraction_less(lhs.first, rhs.first);
    });
    int ans = 0;
    Compressor zip;
    Compressor_init(&zip);
    for (int i = 0; i < FI.size(); i++) {
        FI[i].second.a *= -1;
        Compressor_add(&zip, FI[i].second);
    }
    // SegmentTree not implemented in C
    // zip.exec();
    for (int i = 0; i < FI.size(); i++) {
        int hoge = Compressor_fetch(&zip);
        // ans += seg.query(hoge, 2 * n); // SegmentTree not implemented
        // int tmp = seg[hoge]; // SegmentTree not implemented
        // seg.update(hoge, tmp + 1); // SegmentTree not implemented
    }
    printf("%d\n", ans);
}

int main() {
    init();
    solve();
    return 0;
}
