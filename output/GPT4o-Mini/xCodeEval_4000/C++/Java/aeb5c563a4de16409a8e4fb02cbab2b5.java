import java.util.*;

public class aeb5c563a4de16409a8e4fb02cbab2b5_nc {
    static final long MOD = 998244353;

    static class Edge {
        int to, rev;
        long cap;

        Edge(int _to, long _cap, int _rev) {
            to = _to;
            cap = _cap;
            rev = _rev;
        }
    }

    static class Graph extends ArrayList<List<Edge>> {}

    static void addEdge(Graph G, int from, int to, long cap, boolean revFlag, long revCap) {
        G.get(from).add(new Edge(to, cap, G.get(to).size() + (from == to ? 1 : 0)));
        if (revFlag) G.get(to).add(new Edge(from, revCap, G.get(from).size() - 1));
    }

    static long maxFlowDfs(Graph G, long v, long t, long f, boolean[] used) {
        if (v == t) return f;
        used[(int) v] = true;
        for (Edge e : G.get((int) v)) {
            if (!used[e.to] && e.cap > 0) {
                long d = maxFlowDfs(G, e.to, t, Math.min(f, e.cap), used);
                if (d > 0) {
                    e.cap -= d;
                    G.get(e.to).get(e.rev).cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    static long maxFlow(Graph G, long s, long t) {
        long flow = 0;
        while (true) {
            boolean[] used = new boolean[G.size()];
            long f = maxFlowDfs(G, s, t, Long.MAX_VALUE, used);
            if (f == 0) return flow;
            flow += f;
        }
    }

    static void bellmanFord(Graph G, long s, long[] d, boolean[] negative) {
        Arrays.fill(d, Long.MAX_VALUE);
        Arrays.fill(negative, false);
        d[(int) s] = 0;
        for (int k = 0; k < G.size() - 1; k++) {
            for (int i = 0; i < G.size(); i++) {
                for (Edge e : G.get(i)) {
                    if (d[i] != Long.MAX_VALUE && d[e.to] > d[i] + e.cap) {
                        d[e.to] = d[i] + e.cap;
                    }
                }
            }
        }
        for (int k = 0; k < G.size() - 1; k++) {
            for (int i = 0; i < G.size(); i++) {
                for (Edge e : G.get(i)) {
                    if (d[i] != Long.MAX_VALUE && d[e.to] > d[i] + e.cap) {
                        d[e.to] = d[i] + e.cap;
                        negative[e.to] = true;
                    }
                    if (negative[i]) negative[e.to] = true;
                }
            }
        }
    }

    static void dijkstra(Graph G, long s, long[] d) {
        Arrays.fill(d, Long.MAX_VALUE);
        d[(int) s] = 0;
        PriorityQueue<long[]> q = new PriorityQueue<>(Comparator.comparingLong(a -> a[0]));
        q.add(new long[]{0, s});
        while (!q.isEmpty()) {
            long[] a = q.poll();
            if (d[(int) a[1]] < a[0]) continue;
            for (Edge e : G.get((int) a[1])) {
                if (d[e.to] > d[(int) a[1]] + e.cap) {
                    d[e.to] = d[(int) a[1]] + e.cap;
                    q.add(new long[]{d[e.to], e.to});
                }
            }
        }
    }

    static void warshallFloyd(Graph G, long[][] d) {
        for (int i = 0; i < G.size(); i++) {
            for (int j = 0; j < G.size(); j++) {
                d[i][j] = (i != j) ? Long.MAX_VALUE : 0;
            }
        }
        for (int i = 0; i < G.size(); i++) {
            for (Edge e : G.get(i)) {
                d[i][e.to] = Math.min(d[i][e.to], e.cap);
            }
        }
        for (int i = 0; i < G.size(); i++) {
            for (int j = 0; j < G.size(); j++) {
                for (int k = 0; k < G.size(); k++) {
                    d[j][k] = Math.min(d[j][k], d[j][i] + d[i][k]);
                }
            }
        }
    }

    static boolean tsort(Graph graph, List<Long> order) {
        int n = graph.size();
        long[] in = new long[n];
        for (List<Edge> es : graph) {
            for (Edge e : es) in[e.to]++;
        }
        PriorityQueue<Long> que = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) que.add((long) i);
        }
        while (!que.isEmpty()) {
            long v = que.poll();
            order.add(v);
            for (Edge e : graph.get((int) v)) {
                if (--in[e.to] == 0) que.add((long) e.to);
            }
        }
        return order.size() == n;
    }

    static class Lca {
        int n, log2_n;
        int[][] parent;
        int[] depth;

        Lca(Graph g, int root) {
            n = g.size();
            log2_n = Integer.highestOneBit(n) * 2;
            parent = new int[log2_n][n];
            depth = new int[n];
            dfs(g, root, -1, 0);
            for (int k = 0; k + 1 < log2_n; k++) {
                for (int v = 0; v < g.size(); v++) {
                    if (parent[k][v] < 0) parent[k + 1][v] = -1;
                    else parent[k + 1][v] = parent[k][parent[k][v]];
                }
            }
        }

        void dfs(Graph g, int v, int p, int d) {
            parent[0][v] = p;
            depth[v] = d;
            for (Edge e : g.get(v)) {
                if (e.to != p) dfs(g, e.to, v, d + 1);
            }
        }

        int get(int u, int v) {
            if (depth[u] > depth[v]) {
                int temp = u;
                u = v;
                v = temp;
            }
            for (int k = 0; k < log2_n; k++) {
                if ((depth[v] - depth[u] & (1 << k)) != 0) {
                    v = parent[k][v];
                }
            }
            if (u == v) return u;
            for (int k = log2_n - 1; k >= 0; k--) {
                if (parent[k][u] != parent[k][v]) {
                    u = parent[k][u];
                    v = parent[k][v];
                }
            }
            return parent[0][u];
        }
    }

    static class UnionFind {
        int[] data;
        long num;

        UnionFind(int size) {
            data = new int[size];
            Arrays.fill(data, -1);
            num = size;
        }

        boolean merge(int x, int y) {
            x = root(x);
            y = root(y);
            if (x != y) {
                if (data[y] < data[x]) {
                    int temp = x;
                    x = y;
                    y = temp;
                }
                data[x] += data[y];
                data[y] = x;
            }
            num -= (x != y) ? 1 : 0;
            return x != y;
        }

        boolean same(int x, int y) {
            return root(x) == root(y);
        }

        int root(int x) {
            return data[x] < 0 ? x : (data[x] = root(data[x]));
        }

        long size(int x) {
            return -data[root(x)];
        }

        long num() {
            return num;
        }
    }

    static class SegmentTree<T> {
        T identity;
        BiFunction<T, T, T> merge;
        int n;
        List<T> dat;

        SegmentTree(BiFunction<T, T, T> f, T id, List<T> v) {
            merge = f;
            identity = id;
            int _n = v.size();
            n = 1;
            while (n < _n) n *= 2;
            dat = new ArrayList<>(Collections.nCopies(2 * n - 1, identity));
            for (int i = 0; i < _n; i++) dat.set(n + i - 1, v.get(i));
            for (int i = n - 2; i >= 0; i--) dat.set(i, merge.apply(dat.get(i * 2 + 1), dat.get(i * 2 + 2)));
        }

        void setVal(int i, T x) {
            i += n - 1;
            dat.set(i, x);
            while (i > 0) {
                i = (i - 1) / 2;
                dat.set(i, merge.apply(dat.get(i * 2 + 1), dat.get(i * 2 + 2)));
            }
        }

        T query(int l, int r) {
            T left = identity, right = identity;
            l += n - 1;
            r += n - 1;
            while (l < r) {
                if ((l & 1) == 0) left = merge.apply(left, dat.get(l));
                if ((r & 1) == 0) right = merge.apply(dat.get(r - 1), right);
                l = l / 2;
                r = (r - 1) / 2;
            }
            return merge.apply(left, right);
        }
    }

    static class FenwickTree<T> {
        List<T> data;
        int n;
        int p;

        FenwickTree(int n) {
            this.n = n;
            data = new ArrayList<>(Collections.nCopies(n + 1, (T) Long.valueOf(0)));
            p = 1;
            while (p < data.size()) p *= 2;
        }

        T sum(int k) {
            long ret = 0;
            for (; k > 0; k -= k & -k) ret += (Long) data.get(k);
            return (T) Long.valueOf(ret);
        }

        T sum(int a, int b) {
            return sum(b) - sum(a);
        }

        void add(int k, T x) {
            for (++k; k <= n; k += k & -k) data.set(k, (T) Long.valueOf((Long) data.get(k) + (Long) x));
        }

        int lowerBound(long w) {
            if (w <= 0) return -1;
            int x = 0;
            for (int k = p / 2; k > 0; k /= 2) {
                if (x + k <= n && (Long) data.get(x + k) < w) {
                    w -= (Long) data.get(x + k);
                    x += k;
                }
            }
            return x;
        }
    }

    static void divisor(long n, List<Long> ret) {
        for (long i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                ret.add(i);
                if (i * i != n) ret.add(n / i);
            }
        }
        Collections.sort(ret);
    }

    static void primeFactorization(long n, List<Pair<Long, Integer>> ret) {
        for (long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                ret.add(new Pair<>(i, 0));
                while (n % i == 0) {
                    n /= i;
                    ret.get(ret.size() - 1).second++;
                }
            }
        }
        if (n != 1) ret.add(new Pair<>(n, 1));
    }

    static long modPow(long x, long n, long mod) {
        long res = 1;
        while (n > 0) {
            if ((n & 1) != 0) res = res * x % mod;
            x = x * x % mod;
            n >>= 1;
        }
        return res;
    }

    static long modInv(long x, long mod) {
        return modPow(x, mod - 2, mod);
    }

    static class Combination {
        long[] fact;
        long[] factInv;
        long mod;

        Combination(long _n, long _mod) {
            mod = _mod;
            long n = Math.min(_n + 1, mod);
            fact = new long[(int) n];
            fact[0] = 1;
            for (int i = 1; i < n; i++) {
                fact[i] = (fact[i - 1] * i) % mod;
            }
            factInv = new long[(int) n];
            factInv[(int) (n - 1)] = modInv(fact[(int) (n - 1)], mod);
            for (int i = (int) (n - 1); i > 0; i--) {
                factInv[i - 1] = factInv[i] * i % mod;
            }
        }

        long nCr(long n, long r) {
            if (n < r) return 0;
            if (n < mod) return ((fact[(int) n] * factInv[(int) r] % mod) * factInv[(int) (n - r)]) % mod;

            long ret = 1;
            while (n > 0 || r > 0) {
                long _n = n % mod, _r = r % mod;
                n /= mod;
                r /= mod;
                (ret *= nCr(_n, _r)) %= mod;
            }
            return ret;
        }

        long nPr(long n, long r) {
            return (fact[(int) n] * factInv[(int) (n - r)]) % mod;
        }

        long nHr(long n, long r) {
            return nCr(r + n - 1, r);
        }
    }

    static long popcount(long x) {
        x = (x & 0x5555555555555555L) + (x >> 1 & 0x5555555555555555L);
        x = (x & 0x3333333333333333L) + (x >> 2 & 0x3333333333333333L);
        x = (x & 0x0F0F0F0F0F0F0F0FL) + (x >> 4 & 0x0F0F0F0F0F0F0F0FL);
        x = (x & 0x00FF00FF00FF00FFL) + (x >> 8 & 0x00FF00FF00FF00FFL);
        x = (x & 0x0000FFFF0000FFFFL) + (x >> 16 & 0x0000FFFF0000FFFFL);
        x = (x & 0x00000000FFFFFFFFL) + (x >> 32 & 0x00000000FFFFFFFFL);
        return x;
    }

    static class LazySegmentTree<T, E> {
        T identityT;
        E identityE;
        BiFunction<T, T, T> fTT;
        BiFunction<T, E, T> fTE;
        BiFunction<E, E, E> fEE;
        BiFunction<E, Integer, E> fEP;
        List<T> dat;
        List<E> lazy;
        int n;

        LazySegmentTree(List<T> v, T idT, E idE, BiFunction<T, T, T> f, BiFunction<T, E, T> g, BiFunction<E, E, E> h, BiFunction<E, Integer, E> p) {
            identityT = idT;
            identityE = idE;
            fTT = f;
            fTE = g;
            fEE = h;
            fEP = p;
            n = 1;
            while (n < v.size()) n *= 2;
            dat = new ArrayList<>(Collections.nCopies(2 * n - 1, identityT));
            lazy = new ArrayList<>(Collections.nCopies(2 * n - 1, identityE));
            for (int i = 0; i < v.size(); i++) dat.set(n + i - 1, v.get(i));
            for (int i = n - 2; i >= 0; i--) dat.set(i, fTT.apply(dat.get(i * 2 + 1), dat.get(i * 2 + 2)));
        }

        void eval(int k, int len) {
            if (lazy.get(k).equals(identityE)) return;
            if (k < n - 1) {
                lazy.set(2 * k + 1, fEE.apply(lazy.get(2 * k + 1), lazy.get(k)));
                lazy.set(2 * k + 2, fEE.apply(lazy.get(2 * k + 2), lazy.get(k)));
            }
            dat.set(k, fTE.apply(dat.get(k), fEP.apply(lazy.get(k), len)));
            lazy.set(k, identityE);
        }

        void update(int a, int b, E x, int k, int l, int r) {
            eval(k, r - l);
            if (a <= l && r <= b) {
                lazy.set(k, fEE.apply(lazy.get(k), x));
                eval(k, r - l);
            } else if (a < r && l < b) {
                update(a, b, x, 2 * k + 1, l, (l + r) / 2);
                update(a, b, x, 2 * k + 2, (l + r) / 2, r);
                dat.set(k, fTT.apply(dat.get(2 * k + 1), dat.get(2 * k + 2)));
            }
        }

        T query(int a, int b, int k, int l, int r) {
            eval(k, r - l);
            if (r <= a || b <= l) return identityT;
            else if (a <= l && r <= b) return dat.get(k);
            else {
                T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
                T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
                return fTT.apply(vl, vr);
            }
        }

        void update(int a, int b, E x) {
            update(a, b, x, 0, 0, n);
        }

        T query(int a, int b) {
            return query(a, b, 0, 0, n);
        }
    }

    static long[][] mIdentity(long n) {
        long[][] A = new long[(int) n][(int) n];
        for (int i = 0; i < n; i++) A[i][i] = 1;
        return A;
    }

    static long[][] mMul(long[][] A, long[][] B, long M) {
        long[][] C = new long[A.length][B[0].length];
        for (int i = 0; i < C.length; i++) {
            for (int k = 0; k < A[i].length; k++) {
                for (int j = 0; j < C[i].length; j++) {
                    C[i][j] = (C[i][j] + (A[i][k] % M) * (B[k][j] % M)) % M) % M;
                }
            }
        }
        return C;
    }

    static long[][] mPow(long[][] A, long e, long M) {
        return e == 0 ? mIdentity(A.length) : e % 2 == 0 ? mPow(mMul(A, A, M), e / 2, M) : mMul(A, mPow(A, e - 1, M), M);
    }

    static class NTT {
        static void bitReverse(long[] a) {
            int n = a.length;
            int i = 0;
            for (int j = 1; j < n - 1; j++) {
                for (int k = n >> 1; k > (i ^= k); k >>= 1);
                if (j < i) {
                    long temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }

        static void ntt(long[] input, long mod, long root) {
            int n = input.length;
            assert (n ^ (n & -n)) == 0;

            long tmp = (mod - 1) * modPow(n, mod - 2, mod) % mod;
            long h = modPow(root, tmp, mod);

            bitReverse(input);

            for (long m = 1; m < n; m <<= 1) {
                long m2 = 2 * m;
                long _base = modPow(h, n / m2, mod);
                long _w = 1;
                for (int x = 0; x < m; x++) {
                    for (long s = x; s < n; s += m2) {
                        long u = input[(int) s];
                        long d = (input[(int) (s + m)] * _w) % mod;
                        input[(int) s] = (u + d) % mod;
                        input[(int) (s + m)] = (u - d + mod) % mod;
                    }
                    _w = (_w * _base) % mod;
                }
            }
        }

        static long[] convolution(long[] a, long[] b, long mod, long root) {
            int resultSize = a.length + b.length - 1;
            int n = 1;
            while (n < resultSize) n <<= 1;

            long[] _a = Arrays.copyOf(a, n);
            long[] _b = Arrays.copyOf(b, n);

            ntt(_a, mod, root);
            ntt(_b, mod, root);
            for (int i = 0; i < n; i++) _a[i] = (_a[i] * _b[i]) % mod;

            ntt(_a, mod, root);
            long nInv = modPow(n, mod - 2, mod);
            for (int i = 0; i < _a.length; i++) _a[i] = (_a[i] * nInv) % mod;

            return Arrays.copyOf(_a, resultSize);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long k = scanner.nextLong();
        Graph a = new Graph();
        for (int i = 0; i < n; i++) {
            a.add(new ArrayList<>());
            long t = scanner.nextLong();
            for (int j = 0; j < t; j++) {
                long tmp = scanner.nextLong();
                if (a.get(i).size() < k) a.get(i).add(new Edge((int) tmp, 0, 0));
            }
        }
        long[] w = new long[(int) n];
        for (int i = 0; i < n; i++) {
            w[i] = Arrays.stream(a.get(i).toArray()).mapToLong(e -> e.to).sum();
        }
        long ans = 0;
