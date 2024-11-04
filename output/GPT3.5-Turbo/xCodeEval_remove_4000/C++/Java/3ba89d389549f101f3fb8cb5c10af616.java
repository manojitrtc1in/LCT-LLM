import java.util.*;

class Main {
    static class Edge {
        long to, cap, rev;

        Edge(long _to, long _cap, long _rev) {
            to = _to;
            cap = _cap;
            rev = _rev;
        }
    }

    static class Graph {
        List<List<Edge>> adj;

        Graph(int n) {
            adj = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                adj.add(new ArrayList<>());
            }
        }

        void addEdge(int from, int to, int cap, boolean revFlag, int revCap) {
            adj.get(from).add(new Edge(to, cap, adj.get(to).size()));
            if (revFlag) {
                adj.get(to).add(new Edge(from, revCap, adj.get(from).size() - 1));
            }
        }
    }

    static long INF = (long) Math.pow(2, 60);

    static long id1(Graph G, int v, int t, long f, boolean[] used) {
        if (v == t) {
            return f;
        }
        used[v] = true;
        for (int i = 0; i < G.adj.get(v).size(); i++) {
            Edge e = G.adj.get(v).get(i);
            if (!used[(int) e.to] && e.cap > 0) {
                long d = id1(G, (int) e.to, t, Math.min(f, e.cap), used);
                if (d > 0) {
                    e.cap -= d;
                    G.adj.get((int) e.to).get((int) e.rev).cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    static long maxFlow(Graph G, int s, int t) {
        long flow = 0;
        for (; ; ) {
            boolean[] used = new boolean[G.adj.size()];
            for (int i = 0; i < used.length; i++) {
                used[i] = false;
            }
            long f = id1(G, s, t, INF, used);
            if (f == 0) {
                return flow;
            }
            flow += f;
        }
    }

    static void id6(Graph G, int s, List<Long> d, List<Boolean> negative) {
        d = new ArrayList<>(Collections.nCopies(G.adj.size(), INF));
        negative = new ArrayList<>(Collections.nCopies(G.adj.size(), false));
        d.set(s, 0L);
        for (int k = 0; k < G.adj.size() - 1; k++) {
            for (int i = 0; i < G.adj.size(); i++) {
                for (int j = 0; j < G.adj.get(i).size(); j++) {
                    if (d.get(i) != INF && d.get(G.adj.get(i).get(j).to) > d.get(i) + G.adj.get(i).get(j).cap) {
                        d.set(G.adj.get(i).get(j).to, d.get(i) + G.adj.get(i).get(j).cap);
                    }
                }
            }
        }
        for (int k = 0; k < G.adj.size() - 1; k++) {
            for (int i = 0; i < G.adj.size(); i++) {
                for (int j = 0; j < G.adj.get(i).size(); j++) {
                    if (d.get(i) != INF && d.get(G.adj.get(i).get(j).to) > d.get(i) + G.adj.get(i).get(j).cap) {
                        d.set(G.adj.get(i).get(j).to, d.get(i) + G.adj.get(i).get(j).cap);
                        negative.set(G.adj.get(i).get(j).to, true);
                    }
                    if (negative.get(i)) {
                        negative.set(G.adj.get(i).get(j).to, true);
                    }
                }
            }
        }
    }

    static void Dijkstra(Graph G, int s, List<Long> d) {
        d = new ArrayList<>(Collections.nCopies(G.adj.size(), INF));
        d.set(s, 0L);
        PriorityQueue<Pair<Long, Integer>> q = new PriorityQueue<>(Comparator.comparingLong(Pair::getKey));
        q.add(new Pair<>(0L, s));
        while (!q.isEmpty()) {
            Pair<Long, Integer> a = q.poll();
            if (d.get(a.getValue()) < a.getKey()) {
                continue;
            }
            for (int i = 0; i < G.adj.get(a.getValue()).size(); i++) {
                Edge e = G.adj.get(a.getValue()).get(i);
                if (d.get(e.to) > d.get(a.getValue()) + e.cap) {
                    d.set(e.to, d.get(a.getValue()) + e.cap);
                    q.add(new Pair<>(d.get(e.to), e.to));
                }
            }
        }
    }

    static void id9(Graph G, List<List<Long>> d) {
        d = new ArrayList<>(Collections.nCopies(G.adj.size(), new ArrayList<>(Collections.nCopies(G.adj.size(), INF))));
        for (int i = 0; i < d.size(); i++) {
            for (int j = 0; j < d.get(i).size(); j++) {
                d.get(i).set(j, INF);
            }
        }
        for (int i = 0; i < G.adj.size(); i++) {
            for (int j = 0; j < G.adj.get(i).size(); j++) {
                d.get(i).set(G.adj.get(i).get(j).to, G.adj.get(i).get(j).cap);
            }
        }
        for (int i = 0; i < G.adj.size(); i++) {
            for (int j = 0; j < G.adj.size(); j++) {
                for (int k = 0; k < G.adj.size(); k++) {
                    d.get(j).set(k, Math.min(d.get(j).get(k), d.get(j).get(i) + d.get(i).get(k)));
                }
            }
        }
    }

    static boolean tsort(Graph graph, List<Integer> order) {
        int n = graph.adj.size(), k = 0;
        List<Integer> in = new ArrayList<>(Collections.nCopies(n, 0));
        for (List<Edge> es : graph.adj) {
            for (Edge e : es) {
                in.set((int) e.to, in.get((int) e.to) + 1);
            }
        }
        PriorityQueue<Long> que = new PriorityQueue<>(Comparator.comparingLong(Long::longValue));
        for (int i = 0; i < n; i++) {
            if (in.get(i) == 0) {
                que.add((long) i);
            }
        }
        while (!que.isEmpty()) {
            int v = (int) (long) que.poll();
            order.add(v);
            for (Edge e : graph.adj.get(v)) {
                if (--in.get((int) e.to) == 0) {
                    que.add(e.to);
                }
            }
        }
        return order.size() == n;
    }

    static class LCA {
        int n, log2_n;
        List<List<Integer>> parent;
        List<Integer> depth;

        LCA(Graph g, int root) {
            n = g.adj.size();
            log2_n = (int) (Math.log(n) / Math.log(2)) + 1;
            parent = new ArrayList<>(log2_n);
            for (int i = 0; i < log2_n; i++) {
                parent.add(new ArrayList<>(Collections.nCopies(n, -1)));
            }
            depth = new ArrayList<>(Collections.nCopies(n, 0));
            dfs(g, root, -1, 0);
            for (int k = 0; k + 1 < log2_n; k++) {
                for (int v = 0; v < g.adj.size(); v++) {
                    if (parent.get(k).get(v) < 0) {
                        parent.get(k + 1).set(v, -1);
                    } else {
                        parent.get(k + 1).set(v, parent.get(k).get(parent.get(k).get(v)));
                    }
                }
            }
        }

        void dfs(Graph g, int v, int p, int d) {
            parent.get(0).set(v, p);
            depth.set(v, d);
            for (Edge e : g.adj.get(v)) {
                if (e.to != p) {
                    dfs(g, (int) e.to, v, d + 1);
                }
            }
        }

        int get(int u, int v) {
            if (depth.get(u) > depth.get(v)) {
                int tmp = u;
                u = v;
                v = tmp;
            }
            for (int k = 0; k < log2_n; k++) {
                if (((depth.get(v) - depth.get(u)) >> k & 1) == 1) {
                    v = parent.get(k).get(v);
                }
            }
            if (u == v) {
                return u;
            }
            for (int k = log2_n - 1; k >= 0; k--) {
                if (parent.get(k).get(u) != parent.get(k).get(v)) {
                    u = parent.get(k).get(u);
                    v = parent.get(k).get(v);
                }
            }
            return parent.get(0).get(u);
        }
    }

    static void visit(Graph g, int v, List<List<Integer>> scc, Stack<Long> S, List<Boolean> inS, List<Long> low, List<Long> num, int time) {
        low.set((int) v, (long) num.get((int) v));
        num.set((int) v, (long) ++time);
        S.push((long) v);
        inS.set((int) v, true);
        for (Edge e : g.adj.get((int) v)) {
            int w = (int) e.to;
            if (num.get(w) == 0) {
                visit(g, w, scc, S, inS, low, num, time);
                low.set((int) v, Math.min(low.get((int) v), low.get(w)));
            } else if (inS.get(w)) {
                low.set((int) v, Math.min(low.get((int) v), num.get(w)));
            }
        }
        if (low.get((int) v).equals(num.get((int) v))) {
            scc.add(new ArrayList<>());
            while (true) {
                int w = (int) (long) S.pop();
                inS.set(w, false);
                scc.get(scc.size() - 1).add(w);
                if (v == w) {
                    break;
                }
            }
        }
    }

    static void id7(Graph g, List<List<Integer>> scc) {
        int n = g.adj.size();
        List<Long> num = new ArrayList<>(Collections.nCopies(n, 0L));
        List<Long> low = new ArrayList<>(Collections.nCopies(n, 0L));
        List<Boolean> inS = new ArrayList<>(Collections.nCopies(n, false));
        Stack<Long> S = new Stack<>();
        int time = 0;
        for (int u = 0; u < n; u++) {
            if (num.get(u) == 0) {
                visit(g, u, scc, S, inS, low, num, time);
            }
        }
    }

    static class UnionFind {
        List<Integer> data;
        int num;

        UnionFind(int size) {
            data = new ArrayList<>(Collections.nCopies(size, -1));
            num = size;
        }

        boolean unite(int x, int y) {
            x = root(x);
            y = root(y);
            if (x != y) {
                if (data.get(y) < data.get(x)) {
                    int tmp = x;
                    x = y;
                    y = tmp;
                }
                data.set(x, data.get(x) + data.get(y));
                data.set(y, x);
            }
            num -= (x != y);
            return x != y;
        }

        boolean findSet(int x, int y) {
            return root(x) == root(y);
        }

        int root(int x) {
            return data.get(x) < 0 ? x : data.set(x, root(data.get(x)));
        }

        int size(int x) {
            return -data.get(root(x));
        }

        int numSet() {
            return num;
        }
    }

    static class id8 {
        long n, height;
        List<Long> dat;

        id8(long _n) {
            n = 1;
            height = 1;
            while (n < _n) {
                n <<= 1;
                height++;
            }
            dat = new ArrayList<>(Collections.nCopies((int) (2 * n - 1), 0L));
        }

        void add(long i, long x) {
            i += n - 1;
            dat.set((int) i, dat.get((int) i) + x);
            while (i > 0) {
                i = (i - 1) / 2;
                dat.set((int) i, dat.get((int) i * 2 + 1) + dat.get((int) i * 2 + 2));
            }
        }

        long sum(long a, long b, int k, int l, int r) {
            if (r <= a || b <= l) {
                return 0;
            }
            if (a <= l && r <= b) {
                return dat.get(k);
            } else {
                long s1 = sum(a, b, k * 2 + 1, l, (l + r) / 2);
                long s2 = sum(a, b, k * 2 + 2, (l + r) / 2, r);
                return s1 + s2;
            }
        }

        long sum(long a, long b) {
            return sum(a, b, 0, 0, (int) n);
        }
    }

    static class id10 {
        long n, height;
        List<Long> dat;

        id10(long _n) {
            n = 1;
            height = 1;
            while (n < _n) {
                n <<= 1;
                height++;
            }
            dat = new ArrayList<>(Collections.nCopies((int) (2 * n - 1), INF));
        }

        void update(long i, long x) {
            i += n - 1;
            dat.set((int) i, x);
            while (i > 0) {
                i = (i - 1) / 2;
                dat.set((int) i, Math.min(dat.get((int) i * 2 + 1), dat.get((int) i * 2 + 2)));
            }
        }

        long find(long a, long b, int k, int l, int r) {
            if (r <= a || b <= l) {
                return INF;
            }
            if (a <= l && r <= b) {
                return dat.get(k);
            } else {
                long s1 = find(a, b, k * 2 + 1, l, (l + r) / 2);
                long s2 = find(a, b, k * 2 + 2, (l + r) / 2, r);
                return Math.min(s1, s2);
            }
        }

        long find(long a, long b) {
            return find(a, b, 0, 0, (int) n);
        }
    }

    static void divisor(long n, List<Long> ret) {
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

    static List<Long> lis_fast(List<Long> a) {
        int n = a.size();
        List<Long> A = new ArrayList<>(a);
        List<Integer> id = new ArrayList<>(Collections.nCopies(n, 0));
        for (int i = 0; i < n; i++) {
            id.set(i, Collections.binarySearch(A, a.get(i)));
        }
        int m = Collections.max(id) + 1;
        List<Long> b = new ArrayList<>(Collections.nCopies(m, 0L));
        for (int i = n - 1; i >= 0; i--) {
            if (id.get(i) == m - 1) {
                b.set(--m, a.get(i));
            }
        }
        return b;
    }

    static boolean z_algorithm(String str, List<Integer> z, int s) {
        int L = str.length();
        z = new ArrayList<>(Collections.nCopies(str.length(), 0));
        for (int i = 1, left = 0, right = 0; i < L; i++) {
            if (i > right) {
                left = right = i;
                while (right < L && str.charAt(right - left) == str.charAt(right)) {
                    right++;
                }
                z.set(i, right - left);
                right--;
            } else {
                int k = i - left;
                if (z.get(k) < right - i + 1) {
                    z.set(i, z.get(k));
                } else {
                    left = i;
                    while (right < L && str.charAt(right - left) == str.charAt(right)) {
                        right++;
                    }
                    z.set(i, right - left);
                    right--;
                }
            }
            if (z.get(i) == s) {
                return true;
            }
        }
        return false;
    }

    static boolean z_algorithm(String str, List<Integer> z) {
        int L = str.length();
        z = new ArrayList<>(Collections.nCopies(str.length(), 0));
        for (int i = 1, left = 0, right = 0; i < L; i++) {
            if (i > right) {
                left = right = i;
                while (right < L && str.charAt(right - left) == str.charAt(right)) {
                    right++;
                }
                z.set(i, right - left);
                right--;
            } else {
                int k = i - left;
                if (z.get(k) < right - i + 1) {
                    z.set(i, z.get(k));
                } else {
                    left = i;
                    while (right < L && str.charAt(right - left) == str.charAt(right)) {
                        right++;
                    }
                    z.set(i, right - left);
                    right--;
                }
            }
        }
        return true;
    }

    static class RollingHash {
        static final long base1 = 1007, base2 = 2009;
        static final long mod1 = 1000000007, mod2 = 1000000009;
        List<Long> hash1, hash2, power1, power2;

        RollingHash(String S) {
            int n = S.length();
            hash1 = new ArrayList<>(Collections.nCopies(n + 1, 0L));
            hash2 = new ArrayList<>(Collections.nCopies(n + 1, 0L));
            power1 = new ArrayList<>(Collections.nCopies(n + 1, 1L));
            power2 = new ArrayList<>(Collections.nCopies(n + 1, 1L));
            for (int i = 0; i < n; i++) {
                hash1.set(i + 1, (hash1.get(i) * base1 + S.charAt(i)) % mod1);
                hash2.set(i + 1, (hash2.get(i) * base2 + S.charAt(i)) % mod2);
                power1.set(i + 1, (power1.get(i) * base1) % mod1);
                power2.set(i + 1, (power2.get(i) * base2) % mod2);
            }
        }

        Pair<Long, Long> get(int l, int r) {
            long res1 = (hash1.get(r) - hash1.get(l) * power1.get(r - l) % mod1 + mod1) % mod1;
            long res2 = (hash2.get(r) - hash2.get(l) * power2.get(r - l) % mod2 + mod2) % mod2;
            return new Pair<>(res1, res2);
        }

        int getLCP(int a, int b) {
            int len = Math.min(hash1.size() - a, hash1.size() - b);
            int low = 0, high = len;
            while (high - low > 1) {
                int mid = (low + high) >> 1;
                if (!get(a, a + mid).equals(get(b, b + mid))) {
                    high = mid;
                } else {
                    low = mid;
                }
            }
            return low;
        }
    }

    static long mod_pow(long x, long n, long mod) {
        long res = 1L;
        while (n > 0) {
            if ((n & 1) == 1) {
                res = res * x % mod;
            }
            x = x * x % mod;
            n >>= 1;
        }
        return res;
    }

    static long mod_inv(long x, long mod) {
        return mod_pow(x, mod - 2, mod);
    }

    static class Combination {
        List<Long> fact, inv;
        long mod;

        Combination(long n, long _mod) {
            mod = _mod;
            fact = new ArrayList<>(Collections.nCopies((int) (n + 1), 0L));
            fact.set(0, 1L);
            for (int i = 0; i < n; i++) {
                fact.set(i + 1, (fact.get(i) * (i + 1L)) % mod);
            }
            inv = new ArrayList<>(Collections.nCopies((int) (n + 1), 0L));
            inv.set((int) n, mod_inv(fact.get((int) n), mod));
            for (int i = (int) n; i > 0; i--) {
                inv.set(i - 1, inv.get(i) * i % mod);
            }
        }

        long nCr(long n, long r) {
            return ((fact.get((int) n) * inv.get((int) r) % mod) * inv.get((int) (n - r))) % mod;
        }

        long nPr(long n, long r) {
            return (fact.get((int) n) * inv.get((int) (n - r))) % mod;
        }

        long nHr(long n, long r) {
            return nCr(r + n - 1, r);
        }
    }

    static long gcd(long m, long n) {
        if (n == 0) {
            return m;
        }
        return gcd(n, m % n);
    }

    static long lcm(long m, long n) {
        return m / gcd(m, n) * n;
    }

    static List<List<Long>> mIdentity(long n) {
        List<List<Long>> A = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            List<Long> row = new ArrayList<>(Collections.nCopies((int) n, 0L));
            row.set(i, 1L);
            A.add(row);
        }
        return A;
    }

    static List<List<Long>> mMul(List<List<Long>> A, List<List<Long>> B) {
        int n = A.size();
        List<List<Long>> C = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            List<Long> row = new ArrayList<>(Collections.nCopies((int) B.get(0).size(), 0L));
            C.add(row);
        }
        for (int i = 0; i < C.size(); i++) {
            for (int j = 0; j < C.get(i).size(); j++) {
                for (int k = 0; k < A.get(i).size(); k++) {
                    C.get(i).set(j, (C.get(i).get(j) % MOD + (A.get(i).get(k) % MOD * B.get(k).get(j) % MOD) % MOD) % MOD);
                }
            }
        }
        return C;
    }

    static List<List<Long>> mPow(List<List<Long>> A, long e) {
        return e == 0 ? mIdentity(A.size()) :
                e % 2 == 0 ? mPow(mMul(A, A), e / 2) : mMul(A, mPow(A, e - 1));
    }

    static class RectangleSum<T> {
        List<List<T>> sum;

        RectangleSum(List<List<T>> s, int h, int w) {
            sum = new ArrayList<>();
            for (int i = 0; i < h; i++) {
                sum.add(new ArrayList<>(Collections.nCopies(w, null)));
            }
            for (int y = 0; y < h; y++) {
                for (int x = 0; x < w; x++) {
                    sum.get(y).set(x, s.get(y).get(x));
                    if (y > 0) {
                        sum.get(y).set(x, (T) ((long) sum.get(y).get(x) + (long) sum.get(y - 1).get(x)));
                    }
                    if (x > 0) {
                        sum.get(y).set(x, (T) ((long) sum.get(y).get(x) + (long) sum.get(y).get(x - 1)));
                    }
                    if (y > 0 && x > 0) {
                        sum.get(y).set(x, (T) ((long) sum.get(y).get(x) - (long) sum.get(y - 1).get(x - 1)));
                    }
                }
            }
        }

        T getSum(int left, int right, int top, int bottom) {
            T res = sum.get(bottom).get(right);
            if (left > 0) {
                res = (T) ((long) res - (long) sum.get(bottom).get(left - 1));
            }
            if (top > 0) {
                res = (T) ((long) res - (long) sum.get(top - 1).get(right));
            }
            if (left > 0 && top > 0) {
                res = (T) ((long) res + (long) sum.get(top - 1).get(left - 1));
            }
            return res;
        }
    }

    static long _garner(List<Long> xs, List<Long> mods) {
        int M = xs.size();

        List<Long> coeffs = new ArrayList<>(Collections.nCopies(M, 1L));
        List<Long> constants = new ArrayList<>(Collections.nCopies(M, 0L));

        for (int i = 0; i < M - 1; ++i) {
            long mod_i = mods.get(i);

            long v = (xs.get(i) - constants.get(i) + mod_i) % mod_i;
            v = (v * mod_pow(coeffs.get(i), mod_i - 2, mod_i)) % mod_i;

            for (int j = i + 1; j < M; j++) {
                long mod_j = mods.get(j);
                constants.set(j, (constants.get(j) + coeffs.get(j) * v) % mod_j);
                coeffs.set(j, (coeffs.get(j) * mod_i) % mod_j);
            }
        }

        return constants.get(constants.size() - 1);
    }

    static List<Long> id4(List<Long> a, List<Long> b, long mod) {
        for (int i = 0; i < a.size(); i++) {
            a.set(i, a.get(i) % mod);
        }
        for (int i = 0; i < b.size(); i++) {
            b.set(i, b.get(i) % mod);
        }

        long maxval = Math.max(a.size(), b.size()) * Collections.max(a) * Collections.max(b);
        if (maxval < 1224736769) {
            NTT<1224736769, 3> id5 = new NTT<>();
            return id5.convolution(a, b);
        }

        NTT<167772161, 3> id2 = new NTT<>();
        NTT<469762049, 3> id0 = new NTT<>();
        NTT<1224736769, 3> id5 = new NTT<>();

        List<Long> x1 = id2.convolution(a, b);
        List<Long> x2 = id0.convolution(a, b);
        List<Long> x3 = id5.convolution(a, b);

        List<Long> ret = new ArrayList<>(x1.size());
        List<Long> mods = Arrays.asList(167772161L, 469762049L, 1224736769L, mod);
        for (int i = 0; i < x1.size(); i++) {
            List<Long> xs = Arrays.asList(x1.get(i), x2.get(i), x3.get(i), 0L);
            ret.set(i, _garner(xs, mods));
        }

        return ret;
    }

    static int id3(int x) {
        x = (x & 0x55555555) + (x >> 1 & 0x55555555);
        x = (x & 0x33333333) + (x >> 2 & 0x33333333);
        x = (x & 0x0F0F0F0F) + (x >> 4 & 0x0F0F0F0F);
        x = (x & 0x00FF00FF) + (x >> 8 & 0x00FF00FF);
        x = (x & 0x0000FFFF) + (x >> 16 & 0x0000FFFF);

        return x;
    }

    static void rowReduction(List<Long> mat, List<Long> basis) {
        for (long e : mat) {
            for (long b : basis) {
                e = Math.min(e, e ^ b);
            }
            if (e != 0) {
                basis.add(e);
            }
        }
        basis.sort(Collections.reverseOrder());
    }

    static class SegT {
        int n;
        List<Long> node, lazy;
        long init_c = 0;

        SegT(int sz) {
            n = 1;
            while (n < sz) {
                n <<= 1;
            }
            node = new ArrayList<>(Collections.nCopies(2 * n - 1, 0L));
            lazy = new ArrayList<>(Collections.nCopies(2 * n - 1, 0L));
        }

        long f(long a, long b) {
            return Math.max(a, b);
        }

        void eval(int k, int l, int r) {
            node.set(k, node.get(k) + lazy.get(k));
            if (r - l > 1) {
                lazy.set(2 * k + 1, lazy.get(2 * k + 1) + lazy.get(k));
                lazy.set(2 * k + 2, lazy.get(2 * k + 2) + lazy.get(k));
            }
            lazy.set(k, 0L);
        }

        void add(long x, int a, int b, int k, int l, int r) {
            if (r <= a || b <= l) {
                return;
            }
            eval(k, l, r);
            if (a <= l && r <= b) {
                lazy.set(k, lazy.get(k) + x);
                eval(k, l, r);
            } else {
                add(x, a, b, 2 * k + 1, l, (l + r) / 2);
                add(x, a, b, 2 * k + 2, (l + r) / 2, r);
                node.set(k, f(node.get(2 * k + 1), node.get(2 * k + 2)));
            }
        }

        long query(int a, int b, int k, int l, int r) {
            if (r <= a || b <= l) {
                return init_c;
            }
            eval(k, l, r);
            if (a <= l && r <= b) {
                return node.get(k);
            } else {
                long vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
                long vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
                return f(vl, vr);
            }
        }

        long query(int a, int b) {
            return query(a, b, 0, 0, n);
        }
    }

    static void dfs(Graph g, int v, int t, Set<Integer> st, boolean[] used, int s) {
        used[v] = true;
        if (v != s) {
            st.add(v);
        }
        if (v == t) {
            return;
        }
        if (v != s) {
            for (int i = 0; i < g.adj.get(v).size(); i++) {
                Edge e = g.adj.get(v).get(i);
                if (!used[(int) e.to] && e.cap > 0) {
                    dfs(g, (int) e.to, t, st, used, s);
                } else if (used[(int) e.to] && e.cap == 0) {
                    st.add(t);
                }
            }
        } else {
            for (int i = 0; i < g.adj.get(v).size(); i++) {
                Edge e = g.adj.get(v).get(i);
                if (used[(int) e.to]) {
                    continue;
                }
                dfs(g, (int) e.to, t, st, used, s);
                if (st.contains(t)) {
                    for (int itr : st) {
                        used[itr] = true;
                    }
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
        Graph g = new Graph(n);
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            u--;
            v--;
            g.addEdge(u, v, 1, true, 1);
        }
        boolean[] used = new boolean[n];
        Set<Integer> st = new HashSet<>();
        dfs(g, a, b, st, used, a);
        int s = 0, t = 0;
        for (int i = 0; i < n; i++) {
            if (used[i]) {
                s++;
            } else {
                t++;
            }
        }
        s--;
        System.out.println(s * t);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            solve();
        }
    }
}
