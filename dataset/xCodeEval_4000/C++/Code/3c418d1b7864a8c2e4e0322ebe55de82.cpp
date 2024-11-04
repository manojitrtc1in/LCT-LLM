#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize('-finline-functions', '-fipa-vrp', '-fexcess-precision=style', '-falign-loops=1', '-falign-labels=n:m', '-fuse-linker-plugin', '-fno-peephole2', '-fgnu-tm', '-fexpensive-optimizations', '-fsched-spec-insn-heuristic', '-std=c99', '-Q', '-b', '-Ofast', '-ftree-scev-cprop', '-fno-defer-pop', '-ftree-pre', '-freg-struct-return', '-fno-semantic-interposition', '-fauto-profile=path', '-o', '-fexcess-precision=fast', '-ftree-coalesce-vars', '-floop-block', '-findirect-inlining', '-freorder-blocks', '-fno-fp-int-builtin-inexact', '-fomit-frame-pointer', '-fsched-stalled-insns', '-m', '-fno-keep-inline-dllexport', '-falign-jumps=n:m:n2', '-falign-functions', '-fipa-pta', '-ftree-ch', '-fpeel-loops', '-fsched-stalled-insns-dep', '-fwrapv', '-fauto-profile', '-fcode-hoisting', '-fno-fat-lto-objects', '-fno-align-jumps', '-c', '-funsafe-math-optimizations', '-freorder-blocks-algorithm=algorithm', '-falign-functions=n:m:n2', '-fvariable-expansion-in-unroller', '-O0', '-fno-sched-spec', '-fgcse', '-flto', '-ftree-partial-pre', '--gcov=profile.afdo', '-fmodulo-sched-allow-regmoves', '-O2', '-O', '-freschedule-modulo-scheduled-loops', '-fflag', '-fipa-icf', '-falign-loops=n:m:n2', '-fstack-protection', '-fipa-profile', '-fdeclone-ctor-dtor', '-fsemantic-interposition', '-fshrink-wrap', '-ftree-builtin-call-dce', '-fisolate-erroneous-paths-attribute', '-finline-limit', '-lgfortran', '-fstore-merging', '-fexcess-precision=standard', '-fpredictive-commoning', '-flive-patching=inline-only-static', '-fvect-cost-model', '-flive-patching=inline-clone', '-fvect-cost-model=model', '-fno-trapv', '-ftree-tail-merge', '-fmerge-all-constants', '-fno-zero-initialized-in-bss', '-fbranch-count-reg', '-fselective-scheduling2', '-ftree-fre', '--binary=your_program.unstripped', '-Xassembler', '-fauto-inc-dec', '-fsplit-wide-types', '-flimit-function-alignment', '-flto-partition=alg', '--help=optimizers', '-funconstrained-commons', '-foptimize-strlen', '-fguess-branch-probability', '-ftree-ter', '-fpeephole', '-0.0', '-ftree-sink', '-fprefetch-loop-arrays', '-finline-functions-called-once', '-fno-align-labels', '-fipa-bit-cp', '-fdata-sections', '-fsignaling-nans', '-ftoplevel-reorder', '-fpeephole2', '-ftree-loop-distribution', '-flive-patching', '-fsched-group-heuristic', '-fsched-stalled-insns-dep=n', '-freorder-blocks-and-partition', '-fsanitize=address', '-freorder-functions', '--param', '-fdelete-null-pointer-checks', '-fsched-rank-heuristic', '-fno-signed-zeros', '-fsel-sched-pipelining-outer-loops', '-fno-keep-static-consts', '-ftree-dse', '-e', '-fno-sched-interblock', '-fcombine-stack-adjustments', '-fsched-stalled-insns=0', '-funroll-loops', '--profile=perf.data', '-ftree-forwprop', '-fgcse-las', '-falign-labels=1', '-ffast-math', '-ftree-dominator-opts', '-fdefer-pop', '-ftree-reassoc', '-fno-allocation-dce', '-ftree-loop-distribute-patterns', '-fsched-critical-path-heuristic', '-std=c++11', '-fcse-follow-jumps', '-fif-conversion', '-fcse-skip-blocks', '-fassociative-math', '-fsplit-ivs-in-unroller', '-Wformat-overflow', '-foptimize-sibling-calls', '-flive-range-shrinkage', '-flra-remat', '-falign-labels=n', '--gc-sections', '-fmove-loop-invariants', '-ffat-lto-objects', '-ffp-contract=on', '-funit-at-a-time', '--help=param', '-falign-functions=n:m:n2:m2', '-funroll-all-loops', '-floop-parallelize-all', '-ftree-loop-im', '-1', '-fforward-propagate', '-ftree-pta', '-fipa-icf-variables', '-falign-labels=n:m:n2', '-fsched-interblock', '-fno-strict-aliasing', '-falign-jumps=n:m:n2:m2', '-falign-jumps=n', '-ffunction-cse', '-ffp-contract=off', '-fipa-sra', '-fsched-spec-load-dangerous', '-fno-align-loops', '-fno-lto', '-fdse', '-freciprocal-math', '-flto=jobserver', '-ftree-ccp', '-fisolate-erroneous-paths-dereference', '-fno-ira-share-spill-slots', '-fssa-phiopt', '-ftree-phiprop', '-fno-function-cse', '-fconserve-stack', '-fcx-fortran-rules', '-fira-hoist-pressure', '-fdevirtualize-speculatively', '-fgraphite-identity', '-flto-compression-level=n', '-fkeep-static-consts', '-fssa-backprop', '-fsplit-loops', '-fdevirtualize-at-ltrans', '-', '-fno-align-functions', '-fno-inline', '-fipa-cp', '-fshrink-wrap-separate', '-fsplit-paths', '-ftree-loop-vectorize', '-fipa-reference-addressable', '-Wformat-truncation', '-fallow-store-data-races', '-fprofile-use', '-falign-jumps=1', '-fmax-stack-var-size', '-fschedule-insns', '-fno-unit-at-a-time', '-falign-functions=n', '-fif-conversion2', '-fno-gcse', '-fno-toplevel-reorder', '-fno-trapping-math', '-Os', '-flto=auto', '-fno-omit-frame-pointer', '-fipa-reference', '-fivopts', '-O1', '-ftree-switch-conversion', '-fno-merge-constants', '-falign-loops', '-falign-labels', '-falign-functions=32:7', '-fsingle-precision-constant', '-floop-strip-mine', '-fno-ira-share-save-slots', '-fdelayed-branch', '-falign-labels=n:m:n2:m2', '-fgcse-after-reload', '-ffunction-sections', '-fwhole-program', '-ftree-loop-linear', '-fcaller-saves', '-fno-sched-stalled-insns-dep', '-fno-branch-count-reg', '-fearly-inlining', '-ftree-copy-prop', '-finline-limit=n', '-fipa-stack-alignment', '-ftree-loop-if-convert', '-falign-functions=32', '-funswitch-loops', '-fmerge-constants', '-fira-region=region', '-fcrossjumping', '-g', '-frounding-math', '-ftree-slp-vectorize', '-fsection-anchors', '-fsplit-wide-types-early', '-fno-delete-null-pointer-checks', '-fipa-ra', '-flifetime-dse=0', '-fpartial-inlining', '-mfpmath=sse+387', '-fprofile-partial-training', '-ffoo', '-fweb', '-free', '-ftracer', '-fstdarg-opt', '-ffinite-loops', '-fira-loop-pressure', '-freorder-blocks-algorithm=stc', '-fbranch-probabilities', '-fdce', '-lfoo', '-fgcse-lm', '-fno-printf-return-value', '-falign-functions=n:m', '-ftree-dce', '-fdevirtualize', '-fprofile-arcs', '-fsched-stalled-insns=n', '-fno-peephole', '-fprintf-return-value', '-falign-functions=64:7:32:3', '-ftree-bit-ccp', '-fira-algorithm=algorithm', '-ftree-vrp', '-ffp-contract=fast', '-floop-nest-optimize', '-mfpmath=sse', '-fkeep-static-functions', '-fno-sched-stalled-insns', '-ftree-parallelize-loops=n', '-fsched-dep-count-heuristic', '-floop-unroll-and-jam', '-fcx-limited-range', '-ftree-slsr', '-fno-lifetime-dse', '-fprofile-reorder-functions', '-falign-jumps=n:m', '-frename-registers', '-fprofile-generate', '-falign-loops=n:m', '-Og', '-falign-loops=n', '-ftree-loop-optimize', '-fschedule-insns2', '-ftree-sra', '-falign-functions=24', '-Wa', '--', '-fsplit-stack', '-ffloat-store', '-fselective-scheduling', '-fsched2-use-superblocks', '-flto[=n]', '-fcompare-elim', '-fcprop-registers', '-fsimd-cost-model=model', '-fthread-jumps', '-ffinite-math-only', '-frerun-cse-after-loop', '-O3', '-fprofile-correction', '--with-isl', '-fno-guess-branch-probability', '-ftrapping-math', '-gdwarf-5', '-fipa-icf-functions', '-fno-signaling-nans', '-fsched-last-insn-heuristic', '-ftree-loop-ivcanon', '-finline-small-functions', '-faggressive-loop-optimizations', '-fsel-sched-pipelining', '-fvect-cost-model=dynamic', '-floop-interchange', '-fkeep-inline-functions', '-fversion-loops-for-strides', '-fipa-pure-const', '-fschedule-fusion', '-fprofile-values', '-ffp-contract=style', '-falign-loops=n:m:n2:m2', '-fprofile-use=path', '-fgcse-sm', '->', '-ftree-vectorize', '-fno-math-errno', '-fsched-spec', '-falign-jumps', '-fstrict-aliasing', '-fsched-pressure', '-fsched-spec-load', '-fhoist-adjacent-loads', '-fmodulo-sched', '-falign-functions=1', '-fipa-cp-clone', '-flive-patching=level', '-fvpt'})

#include <bits/stdc++.h>

struct InputOutputStream {
    enum {
        SIZE = 1 << 18 | 1
    };

    char ibuf[SIZE], *s, *t, obuf[SIZE], *oh;

    InputOutputStream() : s(), t(), oh(obuf) {}

    ~InputOutputStream() { fwrite(obuf, 1, oh - obuf, stdout); }

    inline char read() {
        return (s == t) && (t = (s = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                s == t ? -1 : *s++;
    }

    template<typename T>
    inline InputOutputStream &operator>>(T &x) {
        static char c;
        static bool iosig;
        for (c = read(), iosig = false; !isdigit(c); c = read()) {
            if (c == -1) return *this;
            iosig |= c == '-';
        }
        for (x = 0; isdigit(c); c = read()) x = x * 10 + (c ^ '0');
        iosig && (x = -x);
        return *this;
    }

    inline void print(char c) {
        (oh == obuf + SIZE) && (fwrite(obuf, 1, SIZE, stdout), oh = obuf);
        *oh++ = c;
    }

    template<typename T>
    inline void print(T x) {
        static int buf[21], cnt;
        if (x != 0) {
            (x < 0) && (print('-'), x = -x);
            for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 | 48;
            while (cnt) print((char) buf[cnt--]);
        } else {
            print('0');
        }
    }

    template<typename T>
    inline InputOutputStream &operator<<(const T &x) {
        print(x);
        return *this;
    }
} io;

const int MAXN = 200000 + 1;
const int MAXG = MAXN * 2 + 1;
const int MAX_LOG = 19;

int n, q;

struct Edge {
    int v, w;

    Edge(int v, int w) : v(v), w(w) {}
};

std::vector<Edge> edge[MAXN], g[MAXG];
int a[MAXN];
int tot;

inline void addEdge(int u, int v, int w) {
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
}

inline void binarize(int u, int pre) {
    static std::vector<Edge *> now;
    now.clear();
    for (auto &p : edge[u])
        if (p.v != pre) now.push_back(&p);
    int o = u;
    for (int i = 0; i < (int) now.size(); i++) {
        addEdge(o, now[i]->v, now[i]->w);
        if (now.size() - i > 2) {
            addEdge(o, ++tot, 0);
            o = tot;
        }
    }
    for (auto &p : edge[u])
        if (p.v != pre) binarize(p.v, u);
}

bool vis[MAXG];
int sz[MAXG], idx[MAXG][MAX_LOG], dep[MAXG];
long long dis[MAXG][MAX_LOG];

void dfsSize(int u, int pre) {
    sz[u] = 1;
    for (auto &p : g[u]) {
        if (!vis[p.v] && p.v != pre) {
            dfsSize(p.v, u);
            sz[u] += sz[p.v];
        }
    }
}

int get(int u, int pre, int n) {
    for (auto &p : g[u])
        if (!vis[p.v] && p.v != pre && sz[p.v] > n) return get(p.v, u, n);
    return u;
}

void dfs(int u, int pre, int d) {
    for (auto &p : g[u]) {
        if (!vis[p.v] && p.v != pre) {
            idx[p.v][d] = idx[u][d];
            dis[p.v][d] = dis[u][d] + p.w;
            dfs(p.v, u, d);
        }
    }
}

void build(int u, int d) {
    dfsSize(u, 0);
    vis[u = get(u, 0, sz[u] / 2)] = true;
    dep[u] = d;
    int c = 0;
    for (auto &p : g[u]) {
        if (!vis[p.v]) {
            dis[p.v][d] = p.w;
            idx[p.v][d] = c++;
            dfs(p.v, u, d);
            build(p.v, d + 1);
        }
    }
}

char *cur;

struct Node *null;

struct Node {
    static const int NODE_SIZE;
    Node *c[3];
    int sz;
    long long sum;

    inline void *operator new(size_t) { return cur += NODE_SIZE; }
};

const int Node::NODE_SIZE = sizeof(Node);

const int MAXM = MAXG * MAX_LOG * 2;

char pool[MAXM * Node::NODE_SIZE];

void insert(Node *&p, Node *pre, int u, int d) {
    p = new Node(*pre);
    p->sz++;
    p->sum += dis[u][d] - dis[u][d - 1];
    if (d != dep[u]) insert(p->c[idx[u][d]], pre->c[idx[u][d]], u, d + 1);
}

void erase(Node *&p, Node *pre, int u, int d) {
    p = new Node(*pre);
    p->sz--;
    p->sum -= dis[u][d] - dis[u][d - 1];
    if (d != dep[u]) erase(p->c[idx[u][d]], pre->c[idx[u][d]], u, d + 1);
}

long long query(Node *p, int u, int d) {
    return ((d == dep[u] || p == null) ? 0 : query(p->c[idx[u][d]], u, d + 1)) +
           p->sum + p->sz * (dis[u][d] - dis[u][d - 1]);
}

Node *root[MAXG];

int main() {
    

    cur = pool;
    null = (Node *) pool;
    null->c[0] = null->c[1] = null->c[2] = null;
    io >> n >> q;
    for (int i = 1; i <= n; i++) io >> a[i];
    for (int i = 1, u, v, w; i < n; i++) {
        io >> u >> v >> w;
        edge[u].emplace_back(v, w);
        edge[v].emplace_back(u, w);
    }
    tot = n;
    binarize(1, 0);
    build(1, 1);
    for (int i = 0; i <= n; i++) root[i] = null;
    for (int i = 1; i <= n; i++) insert(root[i], root[i - 1], a[i], 1);
    long long lastans = 0;
    for (int cmd, l, r, u; q--;) {
        io >> cmd;
        switch (cmd) {
            case 1: {
                io >> l >> r >> u;
                l ^= lastans;
                r ^= lastans;
                u ^= lastans;
                lastans = query(root[r], u, 1) - query(root[l - 1], u, 1);
                io << lastans << '\n';
                lastans &= ((1 << 30) - 1);
                break;
            }
            case 2: {
                io >> u;
                u ^= lastans;
                erase(root[u], root[u], a[u], 1);
                std::swap(a[u], a[u + 1]);
                insert(root[u], root[u], a[u], 1);
                break;
            }
        }
    }
    return 0;
}