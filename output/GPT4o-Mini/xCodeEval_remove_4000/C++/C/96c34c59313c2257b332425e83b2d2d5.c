#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <string.h>

typedef long long ll;

typedef struct {
    double real;
    double imag;
} Point;

typedef struct {
    Point first;
    Point second;
} Line;

typedef struct {
    Point center;
    double r;
} Circle;

double dot(Point a, Point b) {
    return (a.real * b.real + a.imag * b.imag);
}

double cross(Point a, Point b) {
    return (a.real * b.imag - a.imag * b.real);
}

double id3(Line a, Point b) {
    double eps = 1e-9;
    if (dot((Point){a.second.real - a.first.real, a.second.imag - a.first.imag}, (Point){b.real - a.first.real, b.imag - a.first.imag}) < eps) 
        return sqrt(pow(b.real - a.first.real, 2) + pow(b.imag - a.first.imag, 2));
    if (dot((Point){a.first.real - a.second.real, a.first.imag - a.second.imag}, (Point){b.real - a.second.real, b.imag - a.second.imag}) < eps) 
        return sqrt(pow(b.real - a.second.real, 2) + pow(b.imag - a.second.imag, 2));
    return fabs(cross((Point){a.second.real - a.first.real, a.second.imag - a.first.imag}, (Point){b.real - a.first.real, b.imag - a.first.imag})) / 
           sqrt(pow(a.second.real - a.first.real, 2) + pow(a.second.imag - a.first.imag, 2));
}

int id0(Line a, Line b) {
    double eps = 1e-9;
    return (cross((Point){a.second.real - a.first.real, a.second.imag - a.first.imag}, (Point){b.first.real - a.first.real, b.first.imag - a.first.imag}) * 
            cross((Point){a.second.real - a.first.real, a.second.imag - a.first.imag}, (Point){b.second.real - a.first.real, b.second.imag - a.first.imag}) < eps) &&
           (cross((Point){b.second.real - b.first.real, b.second.imag - b.first.imag}, (Point){a.first.real - b.first.real, a.first.imag - b.first.imag}) * 
            cross((Point){b.second.real - b.first.real, b.second.imag - b.first.imag}, (Point){a.second.real - b.first.real, a.second.imag - b.first.imag}) < eps);
}

Point intersection_l(Line a, Line b) {
    Point da = {a.second.real - a.first.real, a.second.imag - a.first.imag};
    Point db = {b.second.real - b.first.real, b.second.imag - b.first.imag};
    double t = cross(db, (Point){b.first.real - a.first.real, b.first.imag - a.first.imag}) / cross(db, da);
    return (Point){a.first.real + da.real * t, a.first.imag + da.imag * t};
}

double id8(Line a, Line b) {
    if (id0(a, b) == 1) {
        return 0;
    }
    return fmin(fmin(id3(a, b.first), id3(a, b.second)), fmin(id3(b, a.first), id3(b, a.second)));
}

void id9(Circle a, Circle b, Point* l, Point* r) {
    double dist = sqrt(pow(a.center.real - b.center.real, 2) + pow(a.center.imag - b.center.imag, 2));
    assert(dist <= 1e-9 + a.r + b.r);
    assert(dist + 1e-9 >= fabs(a.r - b.r));
    Point target = {b.center.real - a.center.real, b.center.imag - a.center.imag};
    double pointer = target.real * target.real + target.imag * target.imag;
    double aa = (pointer + a.r * a.r - b.r * b.r) / 2.0;
    double sqrt_term = sqrt(pointer * a.r * a.r - aa * aa) / pointer;
    *l = (Point){(aa * target.real + target.imag * sqrt_term), (aa * target.imag - target.real * sqrt_term)};
    *r = (Point){(aa * target.real - target.imag * sqrt_term), (aa * target.imag + target.real * sqrt_term)};
    l->real += a.center.real;
    l->imag += a.center.imag;
    r->real += a.center.real;
    r->imag += a.center.imag;
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
    ll zipper[100000]; // Adjust size as needed
    ll unzipper[100000]; // Adjust size as needed
    int fetcher[100000]; // Adjust size as needed
    int fetcher_size;
} Compressor;

void Compressor_init(Compressor* c) {
    c->id6 = false;
    memset(c->zipper, 0, sizeof(c->zipper));
    memset(c->unzipper, 0, sizeof(c->unzipper));
    c->fetcher_size = 0;
}

void Compressor_add(Compressor* c, ll now) {
    assert(c->id6 == false);
    c->zipper[now] = 1;
    c->fetcher[c->fetcher_size++] = now;
}

void Compressor_exec(Compressor* c) {
    assert(c->id6 == false);
    int cnt = 0;
    for (int i = 0; i < 100000; ++i) { // Adjust size as needed
        if (c->zipper[i]) {
            c->zipper[i] = cnt;
            c->unzipper[cnt] = i;
            cnt++;
        }
    }
    c->id6 = true;
}

ll Compressor_fetch(Compressor* c) {
    assert(c->id6 == true);
    ll hoge = c->fetcher[0];
    memmove(c->fetcher, c->fetcher + 1, (c->fetcher_size - 1) * sizeof(int));
    c->fetcher_size--;
    return c->zipper[hoge];
}

ll Compressor_zip(Compressor* c, ll now) {
    assert(c->id6 == true);
    assert(c->zipper[now] != 0);
    return c->zipper[now];
}

ll Compressor_unzip(Compressor* c, ll a) {
    assert(c->id6 == true);
    assert(a < 100000); // Adjust size as needed
    return c->unzipper[a];
}

ll Compressor_next(Compressor* c, ll now) {
    for (int i = 0; i < 100000; ++i) { // Adjust size as needed
        if (c->zipper[i] > now) return c->zipper[i];
    }
    return 100000; // Adjust size as needed
}

ll Compressor_back(Compressor* c, ll now) {
    for (int i = 0; i < 100000; ++i) { // Adjust size as needed
        if (c->zipper[i] < now) return c->zipper[i];
    }
    return -1;
}

typedef struct {
    int rows;
    int cols;
    int data[100][100]; // Adjust size as needed
} Matrix;

Matrix Matrix_add(Matrix a, Matrix b) {
    Matrix result;
    result.rows = a.rows;
    result.cols = a.cols;
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return result;
}

Matrix Matrix_sub(Matrix a, Matrix b) {
    Matrix result;
    result.rows = a.rows;
    result.cols = a.cols;
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[i][j] = a.data[i][j] - b.data[i][j];
        }
    }
    return result;
}

Matrix Matrix_mul(Matrix a, Matrix b) {
    Matrix result;
    result.rows = a.rows;
    result.cols = b.cols;
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < a.cols; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return result;
}

typedef struct {
    unsigned long value;
} modint;

modint modint_init(ll a, unsigned long mod) {
    modint m;
    m.value = ((a % mod) + 2 * mod) % mod;
    return m;
}

modint modint_add(modint a, modint b, unsigned long mod) {
    return modint_init(a.value + b.value, mod);
}

modint modint_sub(modint a, modint b, unsigned long mod) {
    return modint_init(a.value - b.value, mod);
}

modint modint_mul(modint a, modint b, unsigned long mod) {
    return modint_init((a.value * b.value) % mod, mod);
}

modint modint_div(modint a, modint b, unsigned long mod) {
    ll rem = mod - 2;
    while (rem) {
        if (rem % 2) {
            a = modint_mul(a, b, mod);
        }
        b = modint_mul(b, b, mod);
        rem /= 2LL;
    }
    return a;
}

typedef struct {
    ll vertexs[6];
} Dice;

void Dice_init(Dice* d, ll init[6]) {
    memcpy(d->vertexs, init, sizeof(d->vertexs));
}

void Dice_RtoL(Dice* d) {
    for (int q = 1; q < 4; ++q) {
        ll temp = d->vertexs[q];
        d->vertexs[q] = d->vertexs[q + 1];
        d->vertexs[q + 1] = temp;
    }
}

void Dice_LtoR(Dice* d) {
    for (int q = 3; q >= 1; --q) {
        ll temp = d->vertexs[q];
        d->vertexs[q] = d->vertexs[q + 1];
        d->vertexs[q + 1] = temp;
    }
}

void Dice_UtoD(Dice* d) {
    ll temp = d->vertexs[5];
    d->vertexs[5] = d->vertexs[4];
    d->vertexs[4] = d->vertexs[2];
    d->vertexs[2] = d->vertexs[0];
    d->vertexs[0] = temp;
}

void Dice_DtoU(Dice* d) {
    ll temp = d->vertexs[0];
    d->vertexs[0] = d->vertexs[2];
    d->vertexs[2] = d->vertexs[5];
    d->vertexs[5] = d->vertexs[4];
}

bool Dice_ReachAble(Dice* d1, Dice* d2) {
    // Implement BFS or DFS to check reachability
    return false; // Placeholder
}

bool Dice_equal(Dice* d1, Dice* d2) {
    for (int q = 0; q < 6; ++q) {
        if (d1->vertexs[q] != d2->vertexs[q]) {
            return false;
        }
    }
    return true;
}

typedef struct {
    int vertexs[100][100]; // Adjust size as needed
    int depth[100]; // Adjust size as needed
    int backs[100]; // Adjust size as needed
    int connections[100]; // Adjust size as needed
    int zip[100]; // Adjust size as needed
    int unzip[100]; // Adjust size as needed
} id7;

void id7_init(id7* tree, int n) {
    memset(tree->vertexs, 0, sizeof(tree->vertexs));
    memset(tree->depth, 0, sizeof(tree->depth));
    memset(tree->zip, 0, sizeof(tree->zip));
    memset(tree->unzip, 0, sizeof(tree->unzip));
}

void id7_add_edge(id7* tree, int a, int b) {
    tree->vertexs[a][b] = 1;
    tree->vertexs[b][a] = 1;
}

int id7_depth_dfs(id7* tree, int now, int back) {
    tree->depth[now] = 0;
    for (int x = 0; x < 100; ++x) { // Adjust size as needed
        if (tree->vertexs[now][x] && x != back) {
            tree->depth[now] = fmax(tree->depth[now], 1 + id7_depth_dfs(tree, x, now));
        }
    }
    return tree->depth[now];
}

void id7_dfs(id7* tree, int now, int backing) {
    tree->zip[now] = tree->backs[now]; // Placeholder for actual logic
    // Implement DFS logic
}

void id7_build(id7* tree) {
    id7_depth_dfs(tree, 0, -1);
    // Implement build logic
}

void solve() {
    int n, w;
    scanf("%d %d", &n, &w);
    // Implement the rest of the solve function logic
}

int main() {
    solve();
    return 0;
}
