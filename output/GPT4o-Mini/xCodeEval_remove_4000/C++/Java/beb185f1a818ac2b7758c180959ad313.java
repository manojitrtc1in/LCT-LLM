import java.util.*;

public class beb185f1a818ac2b7758c180959ad313xcodeeval_processed_4000.json {
    static final long MOD = 1000000007;
    static final long INF = 1L << 61;
    static final double EPS = 1e-10;

    static class Edge {
        int to, rev;
        long cap;

        Edge(int _to, long _cap, int _rev) {
            to = _to;
            cap = _cap;
            rev = _rev;
        }
    }

    static class Graph {
        List<List<Edge>> edges;

        Graph(int n) {
            edges = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                edges.add(new ArrayList<>());
            }
        }

        void addEdge(int from, int to, long cap, boolean revFlag, long revCap) {
            edges.get(from).add(new Edge(to, cap, edges.get(to).size() + (from == to ? 1 : 0)));
            if (revFlag) edges.get(to).add(new Edge(from, revCap, edges.get(from).size() - 1));
        }
    }

    static long id0(Graph G, long v, long t, long f, boolean[] used) {
        if (v == t) return f;
        used[(int) v] = true;
        for (Edge e : G.edges.get((int) v)) {
            if (!used[e.to] && e.cap > 0) {
                long d = id0(G, e.to, t, Math.min(f, e.cap), used);
                if (d > 0) {
                    e.cap -= d;
                    G.edges.get(e.to).get(e.rev).cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    static long maxFlow(Graph G, long s, long t) {
        long flow = 0;
        while (true) {
            boolean[] used = new boolean[G.edges.size()];
            long f = id0(G, s, t, INF, used);
            if (f == 0) return flow;
            flow += f;
        }
    }

    static void id2(Graph G, long s, long[] d, boolean[] negative) {
        Arrays.fill(d, INF);
        Arrays.fill(negative, false);
        d[(int) s] = 0;
        for (int k = 0; k < G.edges.size() - 1; k++) {
            for (int i = 0; i < G.edges.size(); i++) {
                for (Edge e : G.edges.get(i)) {
                    if (d[i] != INF && d[e.to] > d[i] + e.cap) {
                        d[e.to] = d[i] + e.cap;
                    }
                }
            }
        }
        for (int k = 0; k < G.edges.size() - 1; k++) {
            for (int i = 0; i < G.edges.size(); i++) {
                for (Edge e : G.edges.get(i)) {
                    if (d[i] != INF && d[e.to] > d[i] + e.cap) {
                        d[e.to] = d[i] + e.cap;
                        negative[e.to] = true;
                    }
                    if (negative[i]) negative[e.to] = true;
                }
            }
        }
    }

    static void dijkstra(Graph G, long s, long[] d) {
        Arrays.fill(d, INF);
        d[(int) s] = 0;
        PriorityQueue<Pair> q = new PriorityQueue<>(Comparator.comparingLong(a -> a.first));
        q.add(new Pair(0, s));
        while (!q.isEmpty()) {
            Pair a = q.poll();
            if (d[(int) a.second] < a.first) continue;
            for (Edge e : G.edges.get((int) a.second)) {
                if (d[e.to] > d[(int) a.second] + e.cap) {
                    d[e.to] = d[(int) a.second] + e.cap;
                    q.add(new Pair(d[e.to], e.to));
                }
            }
        }
    }

    static void id4(Graph G, long[][] d) {
        for (int i = 0; i < G.edges.size(); i++) {
            Arrays.fill(d[i], INF);
            d[i][i] = 0;
        }
        for (int i = 0; i < G.edges.size(); i++) {
            for (Edge e : G.edges.get(i)) {
                d[i][e.to] = Math.min(d[i][e.to], e.cap);
            }
        }
        for (int i = 0; i < G.edges.size(); i++) {
            for (int j = 0; j < G.edges.size(); j++) {
                for (int k = 0; k < G.edges.size(); k++) {
                    if (d[j][i] != INF && d[i][k] != INF) {
                        d[j][k] = Math.min(d[j][k], d[j][i] + d[i][k]);
                    }
                }
            }
        }
    }

    static boolean tsort(Graph graph, List<Integer> order) {
        int n = graph.edges.size();
        int[] in = new int[n];
        for (List<Edge> es : graph.edges) {
            for (Edge e : es) in[e.to]++;
        }
        PriorityQueue<Integer> que = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) que.add(i);
        }
        while (!que.isEmpty()) {
            int v = que.poll();
            order.add(v);
            for (Edge e : graph.edges.get(v)) {
                if (--in[e.to] == 0) que.add(e.to);
            }
        }
        return order.size() == n;
    }

    static class Lca {
        int n, log2_n;
        int[][] parent;
        int[] depth;

        Lca(Graph g, int root) {
            n = g.edges.size();
            log2_n = Integer.SIZE - Integer.numberOfLeadingZeros(n);
            parent = new int[log2_n][n];
            depth = new int[n];
            dfs(g, root, -1, 0);
            for (int k = 0; k + 1 < log2_n; k++) {
                for (int v = 0; v < n; v++) {
                    if (parent[k][v] < 0) parent[k + 1][v] = -1;
                    else parent[k + 1][v] = parent[k][parent[k][v]];
                }
            }
        }

        void dfs(Graph g, int v, int p, int d) {
            parent[0][v] = p;
            depth[v] = d;
            for (Edge e : g.edges.get(v)) {
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
                if ((depth[v] - depth[u] >> k & 1) != 0) {
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
        int n;

        UnionFind(int size) {
            data = new int[size];
            Arrays.fill(data, -1);
            n = size;
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
            n -= (x != y) ? 1 : 0;
            return x != y;
        }

        boolean same(int x, int y) {
            return root(x) == root(y);
        }

        int root(int x) {
            return data[x] < 0 ? x : (data[x] = root(data[x]));
        }

        int size(int x) {
            return -data[root(x)];
        }

        int num() {
            return n;
        }
    }

    static class SegmentTree<T> {
        T identity;
        BiFunction<T, T, T> merge;
        long n;
        List<T> dat;

        SegmentTree(BiFunction<T, T, T> f, T id, List<T> v) {
            merge = f;
            identity = id;
            int _n = v.size();
            n = 1;
            while (n < _n) n *= 2;
            dat = new ArrayList<>(Collections.nCopies(2 * (int) n - 1, identity));
            for (int i = 0; i < _n; i++) dat.set((int) n + i - 1, v.get(i));
            for (int i = (int) n - 2; i >= 0; i--) {
                dat.set(i, merge.apply(dat.get(i * 2 + 1), dat.get(i * 2 + 2)));
            }
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
                if ((l & 1) == 0) left = merge.apply(left, dat.get((int) l));
                if ((r & 1) == 0) right = merge.apply(dat.get((int) r - 1), right);
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
            data = new ArrayList<>(Collections.nCopies(n + 1, 0));
            p = 1;
            while (p < data.size()) p *= 2;
        }

        T sum(int k) {
            T ret = (T) Long.valueOf(0);
            for (; k > 0; k -= k & -k) ret += data.get(k);
            return ret;
        }

        T sum(int a, int b) {
            return sum(b) - sum(a);
        }

        void add(int k, T x) {
            for (++k; k <= n; k += k & -k) data.set(k, data.get(k) + x);
        }

        int lowerBound(long w) {
            if (w <= 0) return -1;
            int x = 0;
            for (int k = p / 2; k > 0; k /= 2) {
                if (x + k <= n && data.get(x + k) < w) {
                    w -= data.get(x + k);
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

    static void id5(long n, List<Pair> ret) {
        for (long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                ret.add(new Pair(i, 0));
                while (n % i == 0) {
                    n /= i;
                    ret.get(ret.size() - 1).second++;
                }
            }
        }
        if (n != 1) ret.add(new Pair(n, 1));
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
                fact[i] = (fact[i - 1] * (i + 1)) % mod;
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

    static long id1(long a, long b, long[] x, long[] y) {
        if (a < b) return id1(b, a, y, x);
        if (b > 0) {
            long g = id1(b, a % b, y, x);
            y[0] -= (a / b) * x[0];
            return g;
        } else {
            x[0] = 1;
            y[0] = 0;
            return a;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long m = scanner.nextLong();
        long h1 = scanner.nextLong(), a1 = scanner.nextLong(), x1 = scanner.nextLong(), y1 = scanner.nextLong();
        List<Long> t = new ArrayList<>();
        t.add(h1);
        boolean[] used = new boolean[(int) m];
        used[(int) h1] = true;
        while (true) {
            long tmp = (t.get(t.size() - 1) * x1 + y1) % m;
            t.add(tmp);
            if (used[(int) tmp]) break;
            used[(int) tmp] = true;
        }
        used = new boolean[(int) m];
        long h2 = scanner.nextLong(), a2 = scanner.nextLong(), x2 = scanner.nextLong(), y2 = scanner.nextLong();
        used[(int) h2] = true;
        List<Long> s = new ArrayList<>();
        s.add(h2);
        while (true) {
            long tmp = (s.get(s.size() - 1) * x2 + y2) % m;
            s.add(tmp);
            if (used[(int) tmp]) break;
            used[(int) tmp] = true;
        }

        long l1 = -1, l2 = -1;
        long mn1 = INF, mn2 = INF;
        long now = 0;
        while (true) {
            if (t.get(t.size() - 1).equals(t.get((int) now))) {
                l1 = t.size() - now - 1;
            }
            if (t.get((int) now).equals(a1)) {
                mn1 = now;
                break;
            }
            now++;
            if (now == t.size()) break;
        }
        now = 0;
        while (true) {
            if (s.get(s.size() - 1).equals(s.get((int) now))) {
                l2 = s.size() - now - 1;
            }
            if (s.get((int) now).equals(a2)) {
                mn2 = now;
                break;
            }
            now++;
            if (now == s.size()) break;
        }
        long result = calc(mn1, mn2, l1, l2);
        System.out.println(result);
    }

    static long calc(long mn1, long mn2, long l1, long l2) {
        if (mn1 != INF && mn2 != INF) {
            if (mn1 == mn2) return mn1;
            if (mn1 > mn2 && l2 == -1) return -1;
            if (mn1 < mn2 && l1 == -1) return -1;
            if (l1 == -1) {
                if ((mn1 - mn2) % l2 == 0) return mn1;
                else return -1;
            }
            if (l2 == -1) {
                if ((mn2 - mn1) % l1 == 0) return mn2;
                else return -1;
            }
            if (l1 == l2) {
                if (Math.abs(mn1 - mn2) % l1 == 0) return Math.max(mn1, mn2);
                else return -1;
            }
            if (mn2 > mn1 && (mn2 - mn1) % l1 == 0) return mn2;
            if (mn1 > mn2 && (mn1 - mn2) % l2 == 0) return mn1;

            if (Math.abs(mn2 - mn1) % Math.abs(gcd(l1, l2)) != 0) return -1;
            long[] x = new long[1], y = new long[1];
            long g = id1(l1, l2, x, y);
            x[0] *= (mn2 - mn1) / g;
            y[0] *= (mn2 - mn1) / g;
            long mn = INF;
            while (x[0] * l1 + mn1 < Math.max(mn1, mn2)) {
                x[0] += l2 / g;
            }
            mn = x[0] * l1 + mn1;
            while (true) {
                x[0] -= l2 / g;
                if (x[0] * l1 + mn1 >= Math.max(mn1, mn2)) mn = Math.min(mn, x[0] * l1 + mn1);
                else break;
            }
            return mn;
        } else return -1;
    }

    static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    static class Pair {
        long first, second;

        Pair(long first, long second) {
            this.first = first;
            this.second = second;
        }
    }
}
