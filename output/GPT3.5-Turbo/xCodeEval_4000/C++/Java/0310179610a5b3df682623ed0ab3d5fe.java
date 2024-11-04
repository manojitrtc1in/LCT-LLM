import java.util.*;
import java.io.*;

public class 0310179610a5b3df682623ed0ab3d5fe_nc {
    static final long INF = (long)1e18;
    static final long MOD = (long)1e9 + 7;
    static final double EPS = 1e-10;
    static final double PI = 3.1415926535897932;

    static class Edge {
        int to, rev;
        long cap;

        Edge(int _to, long _cap, int _rev) {
            to = _to;
            cap = _cap;
            rev = _rev;
        }
    }

    static class Pair {
        long first, second;

        Pair(long _first, long _second) {
            first = _first;
            second = _second;
        }
    }

    static class Graph {
        int V;
        ArrayList<ArrayList<Edge>> adj;

        Graph(int _V) {
            V = _V;
            adj = new ArrayList<>();
            for (int i = 0; i < V; i++) {
                adj.add(new ArrayList<>());
            }
        }

        void addEdge(int from, int to, long cap, boolean revFlag, long revCap) {
            adj.get(from).add(new Edge(to, cap, adj.get(to).size() + (from == to ? 0 : 1)));
            if (revFlag) {
                adj.get(to).add(new Edge(from, revCap, adj.get(from).size() - 1));
            }
        }
    }

    static long maxFlowDFS(Graph G, int v, int t, long f, boolean[] used) {
        if (v == t) {
            return f;
        }
        used[v] = true;
        for (int i = 0; i < G.adj.get(v).size(); i++) {
            Edge e = G.adj.get(v).get(i);
            if (!used[e.to] && e.cap > 0) {
                long d = maxFlowDFS(G, e.to, t, Math.min(f, e.cap), used);
                if (d > 0) {
                    e.cap -= d;
                    G.adj.get(e.to).get(e.rev).cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    static long maxFlow(Graph G, int s, int t) {
        long flow = 0;
        while (true) {
            boolean[] used = new boolean[G.V];
            Arrays.fill(used, false);
            long f = maxFlowDFS(G, s, t, INF, used);
            if (f == 0) {
                return flow;
            }
            flow += f;
        }
    }

    static void BellmanFord(Graph G, int s, long[] d, boolean[] negative) {
        Arrays.fill(d, INF);
        Arrays.fill(negative, false);
        d[s] = 0;
        for (int k = 0; k < G.V - 1; k++) {
            for (int i = 0; i < G.V; i++) {
                for (int j = 0; j < G.adj.get(i).size(); j++) {
                    Edge e = G.adj.get(i).get(j);
                    if (d[i] != INF && d[e.to] > d[i] + e.cap) {
                        d[e.to] = d[i] + e.cap;
                    }
                }
            }
        }
        for (int k = 0; k < G.V - 1; k++) {
            for (int i = 0; i < G.V; i++) {
                for (int j = 0; j < G.adj.get(i).size(); j++) {
                    Edge e = G.adj.get(i).get(j);
                    if (d[i] != INF && d[e.to] > d[i] + e.cap) {
                        d[e.to] = d[i] + e.cap;
                        negative[e.to] = true;
                    }
                    if (negative[i]) {
                        negative[e.to] = true;
                    }
                }
            }
        }
    }

    static void Dijkstra(Graph G, int s, long[] d) {
        Arrays.fill(d, INF);
        d[s] = 0;
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> Long.compare(a.first, b.first));
        pq.add(new Pair(0, s));
        while (!pq.isEmpty()) {
            Pair p = pq.poll();
            int a = p.second;
            if (d[a] < p.first) {
                continue;
            }
            for (int i = 0; i < G.adj.get(a).size(); i++) {
                Edge e = G.adj.get(a).get(i);
                if (d[e.to] > d[a] + e.cap) {
                    d[e.to] = d[a] + e.cap;
                    pq.add(new Pair(d[e.to], e.to));
                }
            }
        }
    }

    static void WarshallFloyd(Graph G, long[][] d) {
        for (int i = 0; i < G.V; i++) {
            Arrays.fill(d[i], INF);
            d[i][i] = 0;
        }
        for (int i = 0; i < G.V; i++) {
            for (int j = 0; j < G.adj.get(i).size(); j++) {
                Edge e = G.adj.get(i).get(j);
                d[i][e.to] = Math.min(d[i][e.to], e.cap);
            }
        }
        for (int i = 0; i < G.V; i++) {
            for (int j = 0; j < G.V; j++) {
                for (int k = 0; k < G.V; k++) {
                    if (d[j][i] != INF && d[i][k] != INF) {
                        d[j][k] = Math.min(d[j][k], d[j][i] + d[i][k]);
                    }
                }
            }
        }
    }

    static boolean tsort(Graph graph, ArrayList<Integer> order) {
        int n = graph.V, k = 0;
        int[] in = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph.adj.get(i).size(); j++) {
                Edge e = graph.adj.get(i).get(j);
                in[e.to]++;
            }
        }
        PriorityQueue<Integer> que = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                que.add(i);
            }
        }
        while (!que.isEmpty()) {
            int v = que.poll();
            order.add(v);
            for (int i = 0; i < graph.adj.get(v).size(); i++) {
                Edge e = graph.adj.get(v).get(i);
                if (--in[e.to] == 0) {
                    que.add(e.to);
                }
            }
        }
        return order.size() == n;
    }

    static class Lca {
        int n, log2_n;
        int[][] parent;
        int[] depth;

        Lca() {}

        Lca(Graph g, int root) {
            n = g.V;
            log2_n = (int)(Math.log(n) / Math.log(2)) + 1;
            parent = new int[log2_n][n];
            depth = new int[n];
            dfs(g, root, -1, 0);
            for (int k = 0; k + 1 < log2_n; k++) {
                for (int v = 0; v < g.V; v++) {
                    if (parent[k][v] < 0) {
                        parent[k + 1][v] = -1;
                    } else {
                        parent[k + 1][v] = parent[k][parent[k][v]];
                    }
                }
            }
        }

        void dfs(Graph g, int v, int p, int d) {
            parent[0][v] = p;
            depth[v] = d;
            for (int i = 0; i < g.adj.get(v).size(); i++) {
                Edge e = g.adj.get(v).get(i);
                if (e.to != p) {
                    dfs(g, e.to, v, d + 1);
                }
            }
        }

        int get(int u, int v) {
            if (depth[u] > depth[v]) {
                int tmp = u;
                u = v;
                v = tmp;
            }
            for (int k = 0; k < log2_n; k++) {
                if (((depth[v] - depth[u]) >> k & 1) == 1) {
                    v = parent[k][v];
                }
            }
            if (u == v) {
                return u;
            }
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
            n = size;
            Arrays.fill(data, -1);
        }

        boolean merge(int x, int y) {
            x = root(x);
            y = root(y);
            if (x != y) {
                if (data[y] < data[x]) {
                    int tmp = x;
                    x = y;
                    y = tmp;
                }
                data[x] += data[y];
                data[y] = x;
            }
            n -= (x != y);
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
        interface MergeFunction<T> {
            T merge(T a, T b);
        }

        T identity;
        MergeFunction<T> merge;
        int n;
        ArrayList<T> dat;

        SegmentTree(MergeFunction<T> f, T id, ArrayList<T> v) {
            merge = f;
            identity = id;
            int _n = v.size();
            n = 1;
            while (n < _n) {
                n *= 2;
            }
            dat = new ArrayList<>(2 * n - 1);
            for (int i = 0; i < 2 * n - 1; i++) {
                dat.add(identity);
            }
            for (int i = 0; i < _n; i++) {
                dat.set(n + i - 1, v.get(i));
            }
            for (int i = n - 2; i >= 0; i--) {
                dat.set(i, merge.merge(dat.get(i * 2 + 1), dat.get(i * 2 + 2)));
            }
        }

        void setVal(int i, T x) {
            i += n - 1;
            dat.set(i, x);
            while (i > 0) {
                i = (i - 1) / 2;
                dat.set(i, merge.merge(dat.get(i * 2 + 1), dat.get(i * 2 + 2)));
            }
        }

        T query(int l, int r) {
            T left = identity, right = identity;
            l += n - 1;
            r += n - 1;
            while (l < r) {
                if ((l & 1) == 0) {
                    left = merge.merge(left, dat.get(l));
                }
                if ((r & 1) == 0) {
                    right = merge.merge(dat.get(r - 1), right);
                }
                l = l / 2;
                r = (r - 1) / 2;
            }
            return merge.merge(left, right);
        }
    }

    static class FenwickTree<T> {
        ArrayList<T> data;
        int n;
        int p;

        FenwickTree(int _n) {
            n = _n;
            data = new ArrayList<>(n + 1);
            for (int i = 0; i <= n; i++) {
                data.add(null);
            }
            p = 1;
            while (p < data.size()) {
                p *= 2;
            }
        }

        T sum(int k) {
            T ret = data.get(0);
            for (; k > 0; k -= k & -k) {
                ret = merge.merge(ret, data.get(k));
            }
            return ret;
        }

        T sum(int a, int b) {
            return merge.merge(sum(b), merge.merge(inverse.merge(data.get(a)), inverse.merge(data.get(b))));
        }

        void add(int k, T x) {
            for (++k; k <= n; k += k & -k) {
                data.set(k, merge.merge(data.get(k), x));
            }
        }

        int lowerBound(long w) {
            if (w <= 0) {
                return -1;
            }
            int x = 0;
            for (int k = p / 2; k > 0; k /= 2) {
                if (x + k <= n && inverse.merge(data.get(x + k)) < w) {
                    w -= inverse.merge(data.get(x + k));
                    x += k;
                }
            }
            return x;
        }
    }

    static void divisor(long n, ArrayList<Long> ret) {
        for (long i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                ret.add(i);
                if (i * i != n) {
                    ret.add(n / i);
                }
            }
        }
        Collections.sort(ret);
    }

    static void primeFactorization(long n, ArrayList<Pair> ret) {
        for (long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                ret.add(new Pair(i, 0));
                while (n % i == 0) {
                    n /= i;
                    ret.get(ret.size() - 1).second++;
                }
            }
        }
        if (n != 1) {
            ret.add(new Pair(n, 1));
        }
    }

    static long modPow(long x, long n, long mod) {
        long res = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                res = res * x % mod;
            }
            x = x * x % mod;
            n >>= 1;
        }
        return res;
    }

    static long modInv(long x, long mod) {
        return modPow(x, mod - 2, mod);
    }

    static class Combination {
        ArrayList<Long> fact;
        ArrayList<Long> factInv;
        long mod;

        Combination(long _n, long _mod) {
            mod = _mod;
            long n = Math.min(_n + 1, mod);
            fact = new ArrayList<>();
            fact.add(1L);
            for (long i = 1; i < n; i++) {
                fact.add(fact.get((int)(i - 1)) * i % mod);
            }
            factInv = new ArrayList<>();
            factInv.add(modInv(fact.get((int)(n - 1)), mod));
            for (int i = (int)(n - 1); i > 0; i--) {
                factInv.add(factInv.get((int)(n - i - 1)) * i % mod);
            }
            Collections.reverse(factInv);
        }

        long nCr(long n, long r) {
            if (n < r) {
                return 0;
            }
            if (n < mod) {
                return fact.get((int)n) * factInv.get((int)r) % mod * factInv.get((int)(n - r)) % mod;
            }
            long ret = 1;
            while (n > 0 || r > 0) {
                long _n = n % mod, _r = r % mod;
                n /= mod;
                r /= mod;
                ret = ret * nCr(_n, _r) % mod;
            }
            return ret;
        }

        long nPr(long n, long r) {
            return fact.get((int)n) * factInv.get((int)(n - r)) % mod;
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

    static final long mod = 998244353;

    static long extgcd(long a, long b, long[] x, long[] y) {
        if (a < b) {
            return extgcd(b, a, y, x);
        }
        if (b > 0) {
            long g = extgcd(b, a % b, y, x);
            y[0] -= (a / b) * x[0];
            return g;
        } else {
            x[0] = 1;
            y[0] = 0;
            return a;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        long m = Long.parseLong(br.readLine());
        String[] h1a1x1y1 = br.readLine().split(" ");
        long h1 = Long.parseLong(h1a1x1y1[0]);
        long a1 = Long.parseLong(h1a1x1y1[1]);
        long x1 = Long.parseLong(h1a1x1y1[2]);
        long y1 = Long.parseLong(h1a1x1y1[3]);
        ArrayList<Long> t = new ArrayList<>();
        boolean[] used = new boolean[(int)m];
        used[(int)h1] = true;
        t.add(h1);
        while (true) {
            long tmp = (t.get(t.size() - 1) * x1 + y1) % m;
            t.add(tmp);
            if (used[(int)tmp]) {
                break;
            }
            used[(int)tmp] = true;
        }
        used = new boolean[(int)m];
        String[] h2a2x2y2 = br.readLine().split(" ");
        long h2 = Long.parseLong(h2a2x2y2[0]);
        long a2 = Long.parseLong(h2a2x2y2[1]);
        long x2 = Long.parseLong(h2a2x2y2[2]);
        long y2 = Long.parseLong(h2a2x2y2[3]);
        used[(int)h2] = true;
        ArrayList<Long> s = new ArrayList<>();
        s.add(h2);
        while (true) {
            long tmp = (s.get(s.size() - 1) * x2 + y2) % m;
            s.add(tmp);
            if (used[(int)tmp]) {
                break;
            }
            used[(int)tmp] = true;
        }

        long l1 = -1, l2 = -1;
        long mn1 = INF, mn2 = INF;
        int now = 0;
        while (true) {
            if (t.get(t.size() - 1).equals(t.get(now))) {
                l1 = t.size() - now - 1;
            }
            if (t.get(now).equals(a1)) {
                mn1 = now;
                break;
            }
            now++;
            if (now == t.size()) {
                break;
            }
        }
        now = 0;
        while (true) {
            if (s.get(s.size() - 1).equals(s.get(now))) {
                l2 = s.size() - now - 1;
            }
            if (s.get(now).equals(a2)) {
                mn2 = now;
                break;
            }
            now++;
            if (now == s.size()) {
                break;
            }
        }

        long calc = -1;
        if (mn1 != INF && mn2 != INF) {
            if (mn1 == mn2) {
                calc = mn1;
            } else if (mn1 > mn2 && l2 == -1) {
                calc = -1;
            } else if (mn1 < mn2 && l1 == -1) {
                calc = -1;
            } else if (l1 == -1) {
                if ((mn1 - mn2) % l2 == 0) {
                    calc = mn1;
                } else {
                    calc = -1;
                }
            } else if (l2 == -1) {
                if ((mn2 - mn1) % l1 == 0) {
                    calc = mn2;
                } else {
                    calc = -1;
                }
            } else if (l1 == l2) {
                if (Math.abs(mn1 - mn2) % l1 == 0) {
                    calc = Math.max(mn1, mn2);
                } else {
                    calc = -1;
                }
            } else if (mn2 > mn1 && (mn2 - mn1) % l1 == 0) {
                calc = mn2;
            } else if (mn1 > mn2 && (mn1 - mn2) % l2 == 0) {
                calc = mn1;
            } else if (Math.abs(mn2 - mn1) % gcd(l1, l2) != 0) {
                calc = -1;
            } else {
                long[] x = new long[1];
                long[] y = new long[1];
                long g = extgcd(l1, l2, x, y);
                x[0] *= (mn2 - mn1) / g;
                y[0] *= (mn2 - mn1) / g;
                if (x[0] * l1 + mn1 < Math.max(mn1, mn2)) {
                    x[0] += ((Math.max(mn1, mn2) - x[0] * l1 + mn1 + l1 - 1) / l1 + l2 / g - 1) / (l2 / g) * (l2 / g);
                }
                if (x[0] * l1 + mn1 >= Math.max(mn1, mn2)) {
                    x[0] -= (x[0] * l1 + mn1 - Math.max(mn1, mn2)) / l1 / (l2 / g) * (l2 / g);
                }
                calc = x[0] * l1 + mn1;
            }
        }

        pw.println(calc);

        pw.flush();
        pw.close();
        br.close();
    }
}
