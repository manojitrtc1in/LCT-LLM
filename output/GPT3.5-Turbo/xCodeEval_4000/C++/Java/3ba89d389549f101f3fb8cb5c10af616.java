import java.util.*;
import java.io.*;

class Main {
    static final long INF = (long) 1e18;
    static final int MOD = (int) 1e9 + 7;

    static class Edge {
        long to, cap, rev;

        Edge(long _to, long _cap, long _rev) {
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

    static class Combination {
        long[] fact;
        long[] inv;
        int mod;

        Combination(int n, int _mod) {
            mod = _mod;
            fact = new long[n + 1];
            fact[0] = 1;
            for (int i = 1; i <= n; i++) {
                fact[i] = (fact[i - 1] * i) % mod;
            }
            inv = new long[n + 1];
            inv[n] = mod_inv(fact[n]);
            for (int i = n; i > 0; i--) {
                inv[i - 1] = (inv[i] * i) % mod;
            }
        }

        long mod_pow(long x, long n, long mod) {
            long res = 1;
            while (n > 0) {
                if (n % 2 == 1) {
                    res = (res * x) % mod;
                }
                x = (x * x) % mod;
                n /= 2;
            }
            return res;
        }

        long mod_inv(long x) {
            return mod_pow(x, mod - 2, mod);
        }

        long nCr(long n, long r) {
            return ((fact[(int) n] * inv[(int) r] % mod) * inv[(int) (n - r)]) % mod;
        }

        long nPr(long n, long r) {
            return (fact[(int) n] * inv[(int) (n - r)]) % mod;
        }

        long nHr(long n, long r) {
            return nCr(r + n - 1, r);
        }
    }

    static long gcd(long m, long n) {
        if (n == 0)
            return m;
        return gcd(n, m % n);
    }

    static long lcm(long m, long n) {
        return m / gcd(m, n) * n;
    }

    static List<List<Edge>> createGraph(int n) {
        List<List<Edge>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        return graph;
    }

    static void addEdge(List<List<Edge>> graph, int from, int to, long cap, boolean revFlag, long revCap) {
        graph.get(from).add(new Edge(to, cap, graph.get(to).size()));
        if (revFlag)
            graph.get(to).add(new Edge(from, revCap, graph.get(from).size() - 1));
    }

    static long maxFlowDfs(List<List<Edge>> graph, int v, int t, long f, boolean[] used) {
        if (v == t)
            return f;
        used[v] = true;
        for (int i = 0; i < graph.get(v).size(); i++) {
            Edge e = graph.get(v).get(i);
            if (!used[(int) e.to] && e.cap > 0) {
                long d = maxFlowDfs(graph, (int) e.to, t, Math.min(f, e.cap), used);
                if (d > 0) {
                    e.cap -= d;
                    graph.get((int) e.to).get((int) e.rev).cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    static long maxFlow(List<List<Edge>> graph, int s, int t) {
        long flow = 0;
        for (;;) {
            boolean[] used = new boolean[graph.size()];
            for (int i = 0; i < used.length; i++)
                used[i] = false;
            long f = maxFlowDfs(graph, s, t, INF, used);
            if (f == 0) {
                return flow;
            }
            flow += f;
        }
    }

    static void bellmanFord(List<List<Edge>> graph, int s, long[] d, boolean[] negative) {
        Arrays.fill(d, INF);
        Arrays.fill(negative, false);
        d[s] = 0;
        for (int k = 0; k < graph.size() - 1; k++) {
            for (int i = 0; i < graph.size(); i++) {
                for (int j = 0; j < graph.get(i).size(); j++) {
                    if (d[i] != INF && d[graph.get(i).get(j).to] > d[i] + graph.get(i).get(j).cap) {
                        d[graph.get(i).get(j).to] = d[i] + graph.get(i).get(j).cap;
                    }
                }
            }
        }
        for (int k = 0; k < graph.size() - 1; k++) {
            for (int i = 0; i < graph.size(); i++) {
                for (int j = 0; j < graph.get(i).size(); j++) {
                    if (d[i] != INF && d[graph.get(i).get(j).to] > d[i] + graph.get(i).get(j).cap) {
                        d[graph.get(i).get(j).to] = d[i] + graph.get(i).get(j).cap;
                        negative[graph.get(i).get(j).to] = true;
                    }
                    if (negative[i] == true)
                        negative[graph.get(i).get(j).to] = true;
                }
            }
        }
    }

    static void dijkstra(List<List<Edge>> graph, int s, long[] d) {
        Arrays.fill(d, INF);
        d[s] = 0;
        PriorityQueue<Pair> q = new PriorityQueue<>((a, b) -> Long.compare(a.first, b.first));
        q.add(new Pair(0, s));
        while (!q.isEmpty()) {
            Pair a = q.poll();
            if (d[(int) a.second] < a.first)
                continue;
            for (int i = 0; i < graph.get((int) a.second).size(); i++) {
                Edge e = graph.get((int) a.second).get(i);
                if (d[(int) e.to] > d[(int) a.second] + e.cap) {
                    d[(int) e.to] = d[(int) a.second] + e.cap;
                    q.add(new Pair(d[(int) e.to], e.to));
                }
            }
        }
    }

    static void warshallFloyd(List<List<Edge>> graph, long[][] d) {
        for (int i = 0; i < d.length; i++) {
            Arrays.fill(d[i], INF);
        }
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph.get(i).size(); j++) {
                d[i][(int) graph.get(i).get(j).to] = graph.get(i).get(j).cap;
            }
        }
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph.size(); j++) {
                for (int k = 0; k < graph.size(); k++) {
                    d[j][k] = Math.min(d[j][k], d[j][i] + d[i][k]);
                }
            }
        }
    }

    static boolean tsort(List<List<Edge>> graph, List<Integer> order) {
        int n = graph.size(), k = 0;
        int[] in = new int[n];
        for (List<Edge> es : graph)
            for (Edge e : es)
                in[(int) e.to]++;
        PriorityQueue<Long> que = new PriorityQueue<>();
        for (int i = 0; i < n; i++)
            if (in[i] == 0)
                que.add((long) i);
        while (!que.isEmpty()) {
            long v = que.poll();
            order.add((int) v);
            for (Edge e : graph.get((int) v))
                if (--in[(int) e.to] == 0)
                    que.add(e.to);
        }
        return order.size() == n;
    }

    static class LCA {
        int n, log2_n;
        int[][] parent;
        int[] depth;

        LCA(List<List<Edge>> g, int root) {
            n = g.size();
            log2_n = (int) (Math.log(n) / Math.log(2)) + 1;
            parent = new int[log2_n][n];
            depth = new int[n];
            dfs(g, root, -1, 0);
            for (int k = 0; k + 1 < log2_n; k++) {
                for (int v = 0; v < n; v++) {
                    if (parent[k][v] < 0)
                        parent[k + 1][v] = -1;
                    else
                        parent[k + 1][v] = parent[k][parent[k][v]];
                }
            }
        }

        void dfs(List<List<Edge>> g, int v, int p, int d) {
            parent[0][v] = p;
            depth[v] = d;
            for (Edge e : g.get(v)) {
                if (e.to != p)
                    dfs(g, (int) e.to, v, d + 1);
            }
        }

        int get(int u, int v) {
            if (depth[u] > depth[v])
                u = u ^ v ^ (v = u);
            for (int k = 0; k < log2_n; k++) {
                if (((depth[v] - depth[u]) >> k & 1) == 1) {
                    v = parent[k][v];
                }
            }
            if (u == v)
                return u;
            for (int k = log2_n - 1; k >= 0; k--) {
                if (parent[k][u] != parent[k][v]) {
                    u = parent[k][u];
                    v = parent[k][v];
                }
            }
            return parent[0][u];
        }
    }

    static void visit(List<List<Edge>> g, int v, List<List<Long>> scc, Stack<Long> S, long[] inS, long[] low, long[] num,
            long[] time) {
        low[(int) v] = num[(int) v] = ++time[0];
        S.push(v);
        inS[(int) v] = 1;
        for (Edge e : g.get((int) v)) {
            int w = (int) e.to;
            if (num[w] == 0) {
                visit(g, w, scc, S, inS, low, num, time);
                low[(int) v] = Math.min(low[(int) v], low[w]);
            } else if (inS[w] == 1)
                low[(int) v] = Math.min(low[(int) v], num[w]);
        }
        if (low[(int) v] == num[(int) v]) {
            scc.add(new ArrayList<>());
            while (true) {
                int w = (int) S.pop();
                inS[w] = 0;
                scc.get(scc.size() - 1).add((long) w);
                if (v == w)
                    break;
            }
        }
    }

    static void stronglyConnectedComponents(List<List<Edge>> g, List<List<Long>> scc) {
        int n = g.size();
        long[] num = new long[n];
        long[] low = new long[n];
        long[] inS = new long[n];
        Stack<Long> S = new Stack<>();
        long[] time = new long[1];
        for (int u = 0; u < n; u++)
            if (num[u] == 0)
                visit(g, u, scc, S, inS, low, num, time);
    }

    static class UnionFind {
        int[] data;
        int num;

        UnionFind(int size) {
            data = new int[size];
            num = size;
            Arrays.fill(data, -1);
        }

        boolean unite(int x, int y) {
            x = root(x);
            y = root(y);
            if (x != y) {
                if (data[y] < data[x])
                    swap(x, y);
                data[x] += data[y];
                data[y] = x;
            }
            num -= (x != y);
            return x != y;
        }

        boolean findSet(int x, int y) {
            return root(x) == root(y);
        }

        int root(int x) {
            return data[x] < 0 ? x : data[x] = root(data[x]);
        }

        int size(int x) {
            return -data[root(x)];
        }

        int numSet() {
            return num;
        }
    }

    static class SumSegTree {
        long n, height;
        long[] dat;

        SumSegTree(long _n) {
            n = 1;
            height = 1;
            while (n < _n) {
                n *= 2;
                height++;
            }
            dat = new long[(int) (2 * n - 1)];
        }

        void add(long i, long x) {
            i += n - 1;
            dat[(int) i] += x;
            while (i > 0) {
                i = (i - 1) / 2;
                dat[(int) i] += x;
            }
        }

        long sum(long a, long b) {
            return _sum(a, b, 0, 0, n);
        }

        long _sum(long a, long b, long k, long l, long r) {
            if (r <= a || b <= l)
                return 0;
            if (a <= l && r <= b)
                return dat[(int) k];
            else {
                long s1 = _sum(a, b, 2 * k + 1, l, (l + r) / 2);
                long s2 = _sum(a, b, 2 * k + 2, (l + r) / 2, r);
                return s1 + s2;
            }
        }
    }

    static class RmqTree {
        long n, height;
        long[] dat;

        RmqTree(long _n) {
            n = 1;
            height = 1;
            while (n < _n) {
                n *= 2;
                height++;
            }
            dat = new long[(int) (2 * n - 1)];
            Arrays.fill(dat, INF);
        }

        void update(long i, long x) {
            i += n - 1;
            dat[(int) i] = x;
            while (i > 0) {
                i = (i - 1) / 2;
                dat[(int) i] = Math.min(dat[(int) (i * 2 + 1)], dat[(int) (i * 2 + 2)]);
            }
        }

        long find(long a, long b) {
            return _find(a, b, 0, 0, n);
        }

        long _find(long a, long b, long k, long l, long r) {
            if (r <= a || b <= l)
                return INF;
            if (a <= l && r <= b)
                return dat[(int) k];
            else {
                long s1 = _find(a, b, 2 * k + 1, l, (l + r) / 2);
                long s2 = _find(a, b, 2 * k + 2, (l + r) / 2, r);
                return Math.min(s1, s2);
            }
        }
    }

    static void divisor(long n, List<Long> ret) {
        for (long i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                ret.add(i);
                if (i * i != n)
                    ret.add(n / i);
            }
        }
        Collections.sort(ret);
    }

    static List<Long> lisFast(List<Long> a) {
        int n = a.size();
        List<Long> A = new ArrayList<>();
        List<Long> id = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            id.add((long) i);
            A.add((long) Integer.MAX_VALUE);
        }
        for (int i = 0; i < n; i++) {
            int idx = Collections.binarySearch(A, a.get(i));
            if (idx < 0)
                idx = -(idx + 1);
            A.set(idx, a.get(i));
            id.set(idx, (long) i);
        }
        int m = Collections.max(id).intValue();
        List<Long> b = new ArrayList<>();
        for (int i = n - 1; i >= 0; i--) {
            if (id.get(i) == m) {
                b.add(a.get(i));
                m--;
            }
        }
        return b;
    }

    static boolean zAlgorithm(String str, List<Integer> z) {
        int L = str.length();
        z = new ArrayList<>(str.length());
        for (int i = 0; i < L; i++) {
            z.add(0);
        }
        for (int i = 1, left = 0, right = 0; i < L; i++) {
            if (i > right) {
                left = right = i;
                while (right < L && str.charAt(right - left) == str.charAt(right))
                    right++;
                z.set(i, right - left);
                right--;
            } else {
                int k = i - left;
                if (z.get(k) < right - i + 1) {
                    z.set(i, z.get(k));
                } else {
                    left = i;
                    while (right < L && str.charAt(right - left) == str.charAt(right))
                        right++;
                    z.set(i, right - left);
                    right--;
                }
            }
            if (z.get(i) == L)
                return true;
        }
        return false;
    }

    static class RollingHash {
        static final int base1 = 1007, base2 = 2009;
        static final int mod1 = 1000000007, mod2 = 1000000009;
        List<Long> hash1, hash2, power1, power2;

        RollingHash(String S) {
            int n = S.length();
            hash1 = new ArrayList<>();
            hash2 = new ArrayList<>();
            power1 = new ArrayList<>();
            power2 = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                hash1.add((long) 0);
                hash2.add((long) 0);
                power1.add((long) 1);
                power2.add((long) 1);
            }
            for (int i = 0; i < n; i++) {
                hash1.set(i, (hash1.get(i - 1) * base1 + S.charAt(i)) % mod1);
                hash2.set(i, (hash2.get(i - 1) * base2 + S.charAt(i)) % mod2);
                power1.set(i, (power1.get(i - 1) * base1) % mod1);
                power2.set(i, (power2.get(i - 1) * base2) % mod2);
            }
        }

        Pair get(int l, int r) {
            long res1 = hash1.get(r) - hash1.get(l - 1) * power1.get(r - l + 1) % mod1;
            if (res1 < 0)
                res1 += mod1;
            long res2 = hash2.get(r) - hash2.get(l - 1) * power2.get(r - l + 1) % mod2;
            if (res2 < 0)
                res2 += mod2;
            return new Pair(res1, res2);
        }

        int getLCP(int a, int b) {
            int len = Math.min(hash1.size() - a, hash1.size() - b);
            int low = 0, high = len;
            while (high - low > 1) {
                int mid = (low + high) >> 1;
                if (get(a, a + mid) != get(b, b + mid))
                    high = mid;
                else
                    low = mid;
            }
            return low;
        }
    }

    static long mod_pow(long x, long n, long mod) {
        long res = 1;
        while (n > 0) {
            if (n % 2 == 1)
                res = (res * x) % mod;
            x = (x * x) % mod;
            n /= 2;
        }
        return res;
    }

    static long mod_inv(long x, long mod) {
        return mod_pow(x, mod - 2, mod);
    }

    static class RectangleSum<T> {
        List<List<T>> sum;

        T getSum(int left, int right, int top, int bottom) {
            T res = sum.get(bottom).get(right);
            if (left > 0)
                res -= sum.get(bottom).get(left - 1);
            if (top > 0)
                res -= sum.get(top - 1).get(right);
            if (left > 0 && top > 0)
                res += sum.get(top - 1).get(left - 1);
            return res;
        }

        RectangleSum(List<List<T>> s, int h, int w) {
            sum = new ArrayList<>();
            for (int i = 0; i < h; i++) {
                sum.add(new ArrayList<>());
                for (int j = 0; j < w; j++) {
                    sum.get(i).add(s.get(i).get(j));
                    if (i > 0)
                        sum.get(i).set(j, sum.get(i).get(j) + sum.get(i - 1).get(j));
                    if (j > 0)
                        sum.get(i).set(j, sum.get(i).get(j) + sum.get(i).get(j - 1));
                    if (i > 0 && j > 0)
                        sum.get(i).set(j, sum.get(i).get(j) - sum.get(i - 1).get(j - 1));
                }
            }
        }
    }

    static long _garner(List<Long> xs, List<Long> mods) {
        int M = xs.size();

        List<Long> coeffs = new ArrayList<>();
        List<Long> constants = new ArrayList<>();

        for (int i = 0; i < M - 1; ++i) {
            long mod_i = mods.get(i);

            long v = (xs.get(i) - constants.get(i) + mod_i) % mod_i;
            v = (v * mod_inv(coeffs.get(i), mod_i)) % mod_i;

            for (int j = i + 1; j < M; j++) {
                long mod_j = mods.get(j);
                constants.set(j, (constants.get(j) + coeffs.get(j) * v) % mod_j);
                coeffs.set(j, (coeffs.get(j) * mod_i) % mod_j);
            }
        }

        return constants.get(constants.size() - 1);
    }

    static List<Long> convolutionNtt(List<Long> a, List<Long> b, long mod) {
        for (int i = 0; i < a.size(); i++) {
            a.set(i, a.get(i) % mod);
        }
        for (int i = 0; i < b.size(); i++) {
            b.set(i, b.get(i) % mod);
        }

        long maxval = Math.max(a.size(), b.size()) * Collections.max(a) * Collections.max(b);
        if (maxval < 1224736769) {
            NTT ntt3 = new NTT(1224736769, 3);
            return ntt3.convolution(a, b);
        }

        NTT ntt1 = new NTT(167772161, 3);
        NTT ntt2 = new NTT(469762049, 3);
        NTT ntt3 = new NTT(1224736769, 3);

        List<Long> x1 = ntt1.convolution(a, b);
        List<Long> x2 = ntt2.convolution(a, b);
        List<Long> x3 = ntt3.convolution(a, b);

        List<Long> ret = new ArrayList<>();
        List<Long> mods = new ArrayList<>();
        mods.add(167772161L);
        mods.add(469762049L);
        mods.add(1224736769L);
        mods.add(mod);
        for (int i = 0; i < x1.size(); i++) {
            List<Long> xs = new ArrayList<>();
            xs.add(x1.get(i));
            xs.add(x2.get(i));
            xs.add(x3.get(i));
            xs.add((long) 0);
            ret.add(_garner(xs, mods));
        }

        return ret;
    }

    static int popcount3(int x) {
        x = (x & 0x55555555) + (x >> 1 & 0x55555555);
        x = (x & 0x33333333) + (x >> 2 & 0x33333333);
        x = (x & 0x0F0F0F0F) + (x >> 4 & 0x0F0F0F0F);
        x = (x & 0x00FF00FF) + (x >> 8 & 0x00FF00FF);
        x = (x & 0x0000FFFF) + (x >> 16 & 0x0000FFFF);

        return x;
    }

    static class NTT {
        long mod, primitiveRoot;

        NTT(long _mod, long _primitiveRoot) {
            mod = _mod;
            primitiveRoot = _primitiveRoot;
        }

        long getMod() {
            return mod;
        }

        void ntt(List<Long> input, int sign) {
            int n = input.size();
            assert ((n ^ (n & -n)) == 0);

            long g = primitiveRoot;

            long tmp = (mod - 1) * mod_pow(n, mod - 2, mod) % mod;

            long h = mod_pow(g, tmp, mod);

            if (sign == -1)
                h = mod_pow(h, mod - 2, mod);

            bitReverse(input);

            for (int m = 1; m < n; m <<= 1) {
                int m2 = 2 * m;
                long base = mod_pow(h, n / m2, mod);
                long w = 1;
                for (int x = 0; x < m; ++x) {
                    for (int s = x; s < n; s += m2) {
                        long u = input.get(s);
                        long d = (input.get(s + m) * w) % mod;
                        input.set(s, (u + d) % mod);
                        input.set(s + m, (u - d + mod) % mod);
                    }
                    w = (w * base) % mod;
                }
            }
        }

        void bitReverse(List<Long> a) {
            int n = a.size();
            int i = 0;
            for (int j = 1; j < n - 1; ++j) {
                for (int k = n >> 1; k > (i ^= k); k >>= 1)
                    ;
                if (j < i)
                    Collections.swap(a, i, j);
            }
        }

        List<Long> convolution(List<Long> a, List<Long> b) {
            int resultSize = a.size() + b.size() - 1;
            int n = 1;
            while (n < resultSize)
                n <<= 1;

            List<Long> _a = new ArrayList<>(a);
            List<Long> _b = new ArrayList<>(b);
            for (int i = 0; i < n; i++) {
                _a.add((long) 0);
                _b.add((long) 0);
            }

            ntt(_a, 1);
            ntt(_b, 1);
            for (int i = 0; i < n; i++) {
                _a.set(i, (_a.get(i) * _b.get(i)) % mod);
            }
            ntt(_a, -1);

            _a = new ArrayList<>(_a.subList(0, resultSize));
            return _a;
        }
    }

    static void dfs(List<List<Edge>> g, int v, int t, Set<Integer> st, int[] used, int s) {
        used[v] = 1;
        if (v != s)
            st.add(v);
        if (v == t)
            return;
        if (v != s) {
            for (int i = 0; i < g.get(v).size(); i++) {
                Edge e = g.get(v).get(i);
                if (used[(int) e.to] == 0)
                    dfs(g, (int) e.to, t, st, used, s);
                else if (used[(int) e.to] == 2)
                    st.add(t);
            }
        } else {
            for (int i = 0; i < g.get(v).size(); i++) {
                Edge e = g.get(v).get(i);
                if (used[(int) e.to] != 0)
                    continue;
                dfs(g, (int) e.to, t, st, used, s);
                if (st.contains(t)) {
                    for (int itr : st)
                        used[itr] = 2;
                }
                st.clear();
            }
        }
    }

    static void solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        a--;
        b--;
        List<List<Edge>> g = createGraph(n);
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            u--;
            v--;
            addEdge(g, u, v, 1, true, 1);
        }
        int[] used = new int[n];
        Set<Integer> st = new HashSet<>();
        dfs(g, a, b, st, used, a);
        int s = 0, t = 0;
        for (int i = 0; i < n; i++) {
            if (used[i] == 1)
                s++;
            else if (used[i] == 0)
                t++;
        }
        s--;
        System.out.println(s * t);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++)
            solve();
    }
}
