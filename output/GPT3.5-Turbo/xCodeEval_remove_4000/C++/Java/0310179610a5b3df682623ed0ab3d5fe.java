import java.util.*;

class Main {
    static final long INF = (long) 1e18;

    static long id0(List<List<Edge>> G, int v, int t, long f, boolean[] used) {
        if (v == t)
            return f;
        used[v] = true;
        for (int i = 0; i < G.get(v).size(); ++i) {
            Edge e = G.get(v).get(i);
            if (!used[e.to] && e.cap > 0) {
                long d = id0(G, e.to, t, Math.min(f, e.cap), used);
                if (d > 0) {
                    e.cap -= d;
                    G.get(e.to).get(e.rev).cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    static long max_flow(List<List<Edge>> G, int s, int t) {
        long flow = 0;
        for (;;) {
            boolean[] used = new boolean[G.size()];
            for (int i = 0; i < used.length; i++)
                used[i] = false;
            long f = id0(G, s, t, INF, used);
            if (f == 0) {
                return flow;
            }
            flow += f;
        }
    }

    static void id2(List<List<Edge>> G, int s, List<Long> d, List<Boolean> negative) {
        d = new ArrayList<>(Collections.nCopies(G.size(), INF));
        negative = new ArrayList<>(Collections.nCopies(G.size(), false));
        for (int i = 0; i < d.size(); i++)
            d.set(i, INF);
        for (int i = 0; i < negative.size(); i++)
            negative.set(i, false);
        d.set(s, 0L);
        for (int k = 0; k < G.size() - 1; k++) {
            for (int i = 0; i < G.size(); i++) {
                for (int j = 0; j < G.get(i).size(); j++) {
                    if (d.get(i) != INF && d.get(G.get(i).get(j).to) > d.get(i) + G.get(i).get(j).cap) {
                        d.set(G.get(i).get(j).to, d.get(i) + G.get(i).get(j).cap);
                    }
                }
            }
        }
        for (int k = 0; k < G.size() - 1; k++) {
            for (int i = 0; i < G.size(); i++) {
                for (int j = 0; j < G.get(i).size(); j++) {
                    if (d.get(i) != INF && d.get(G.get(i).get(j).to) > d.get(i) + G.get(i).get(j).cap) {
                        d.set(G.get(i).get(j).to, d.get(i) + G.get(i).get(j).cap);
                        negative.set(G.get(i).get(j).to, true);
                    }
                    if (negative.get(i) == true)
                        negative.set(G.get(i).get(j).to, true);
                }
            }
        }
    }

    static void Dijkstra(List<List<Edge>> G, int s, List<Long> d) {
        d = new ArrayList<>(Collections.nCopies(G.size(), INF));
        for (int i = 0; i < d.size(); i++)
            d.set(i, INF);
        d.set(s, 0L);
        PriorityQueue<Pair<Long, Integer>> q = new PriorityQueue<>(Comparator.comparingLong(Pair::getKey));
        q.add(new Pair<>(0L, s));
        while (!q.isEmpty()) {
            Pair<Long, Integer> a = q.poll();
            if (d.get(a.getValue()) < a.getKey())
                continue;
            for (int i = 0; i < G.get(a.getValue()).size(); i++) {
                Edge e = G.get(a.getValue()).get(i);
                if (d.get(e.to) > d.get(a.getValue()) + e.cap) {
                    d.set(e.to, d.get(a.getValue()) + e.cap);
                    q.add(new Pair<>(d.get(e.to), e.to));
                }
            }
        }
    }

    static void id4(List<List<Edge>> G, List<List<Long>> d) {
        d = new ArrayList<>(Collections.nCopies(G.size(), new ArrayList<>(Collections.nCopies(G.size(), INF))));
        for (int i = 0; i < d.size(); i++) {
            for (int j = 0; j < d.get(i).size(); j++) {
                d.get(i).set(j, (i != j) ? INF : 0);
            }
        }
        for (int i = 0; i < G.size(); i++) {
            for (int j = 0; j < G.get(i).size(); j++) {
                chmin(d.get(i).get(G.get(i).get(j).to), G.get(i).get(j).cap);
            }
        }
        for (int i = 0; i < G.size(); i++) {
            for (int j = 0; j < G.size(); j++) {
                for (int k = 0; k < G.size(); k++) {
                    if (d.get(j).get(i) != INF && d.get(i).get(k) != INF)
                        chmin(d.get(j).get(k), d.get(j).get(i) + d.get(i).get(k));
                }
            }
        }
    }

    static boolean tsort(List<List<Edge>> graph, List<Integer> order) {
        int n = graph.size(), k = 0;
        int[] in = new int[n];
        for (List<Edge> es : graph)
            for (Edge e : es)
                in[e.to]++;
        PriorityQueue<Integer> que = new PriorityQueue<>();
        for (int i = 0; i < n; i++)
            if (in[i] == 0)
                que.add(i);
        while (!que.isEmpty()) {
            int v = que.poll();
            order.add(v);
            for (Edge e : graph.get(v))
                if (--in[e.to] == 0)
                    que.add(e.to);
        }
        return order.size() == n;
    }

    static class Lca {
        final int n = 0;
        final int log2_n = 0;
        int[][] parent;
        int[] depth;

        Lca() {
        }

        Lca(List<List<Edge>> g, int root) {
            int n = g.size();
            int log2_n = (int) (Math.log(n) / Math.log(2)) + 1;
            parent = new int[log2_n][n];
            depth = new int[n];
            dfs(g, root, -1, 0);
            for (int k = 0; k + 1 < log2_n; k++) {
                for (int v = 0; v < g.size(); v++) {
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
                    dfs(g, e.to, v, d + 1);
            }
        }

        int get(int u, int v) {
            if (depth[u] > depth[v])
                swap(u, v);
            for (int k = 0; k < log2_n; k++) {
                if ((depth[v] - depth[u]) >> k & 1) {
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

    static class UnionFind {
        int[] data;
        int n;

        UnionFind(int size) {
            data = new int[size];
            n = size;
            for (int i = 0; i < size; i++)
                data[i] = -1;
        }

        boolean merge(int x, int y) {
            x = root(x);
            y = root(y);
            if (x != y) {
                if (data[y] < data[x])
                    swap(x, y);
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
            return data[x] < 0 ? x : data[x] = root(data[x]);
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

        MergeFunction<T> merge;
        T identity;
        long n;
        List<T> dat;

        SegmentTree(MergeFunction<T> f, T id, List<T> v) {
            merge = f;
            identity = id;
            int _n = v.size();
            n = 1;
            while (n < _n)
                n *= 2;
            dat = new ArrayList<>(Collections.nCopies((int) (2 * n - 1), identity));
            for (int i = 0; i < _n; i++)
                dat.set((int) (n + i - 1), v.get(i));
            for (int i = (int) (n - 2); i >= 0; i--)
                dat.set(i, merge.merge(dat.get(i * 2 + 1), dat.get(i * 2 + 2)));
        }

        void set_val(int i, T x) {
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
                if ((l & 1) == 0)
                    left = merge.merge(left, dat.get(l));
                if ((r & 1) == 0)
                    right = merge.merge(dat.get(r - 1), right);
                l = l / 2;
                r = (r - 1) / 2;
            }
            return merge.merge(left, right);
        }
    }

    static class id3<T> {
        List<T> data;
        int n;
        int p;

        id3(int n) {
            this.n = n;
            data = new ArrayList<>(Collections.nCopies(n + 1, null));
            p = 1;
            while (p < data.size())
                p *= 2;
        }

        T sum(int k) {
            T ret = null;
            for (; k > 0; k -= k & -k)
                ret += data.get(k);
            return ret;
        }

        T sum(int a, int b) {
            return sum(b) - sum(a);
        }

        void add(int k, T x) {
            for (++k; k <= n; k += k & -k)
                data.set(k, data.get(k) + x);
        }

        int lower_bound(long w) {
            if (w <= 0)
                return -1;
            int x = 0;
            for (int k = p / 2; k > 0; k /= 2) {
                if (x + k <= n && data.get(x + k) < w)
                    w -= data.get(x + k);
                x += k;
            }
            return x;
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

    static void id5(long n, List<Pair<Long, Long>> ret) {
        for (long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                ret.add(new Pair<>(i, 0L));
                while (n % i == 0) {
                    n /= i;
                    ret.get(ret.size() - 1).setValue(ret.get(ret.size() - 1).getValue() + 1);
                }
            }
        }
        if (n != 1)
            ret.add(new Pair<>(n, 1L));
    }

    static long mod_pow(long x, long n, long mod) {
        long res = 1;
        while (n > 0) {
            if ((n & 1) == 1)
                res = res * x % mod;
            x = x * x % mod;
            n >>= 1;
        }
        return res;
    }

    static long mod_inv(long x, long mod) {
        return mod_pow(x, mod - 2, mod);
    }

    static class Combination {
        List<Long> fact;
        List<Long> fact_inv;
        long mod;

        Combination(long _n, long _mod) {
            mod = _mod;
            long n = Math.min(_n + 1, mod);
            fact = new ArrayList<>(Collections.nCopies((int) n, 0L));
            fact.set(0, 1L);
            for (int i = 0; i < n - 1; i++) {
                fact.set(i + 1, fact.get(i) * (i + 1L) % mod);
            }
            fact_inv = new ArrayList<>(Collections.nCopies((int) n, 0L));
            fact_inv.set((int) (n - 1), mod_inv(fact.get((int) (n - 1)), mod));
            for (int i = (int) (n - 1); i > 0; i--) {
                fact_inv.set(i - 1, fact_inv.get(i) * i % mod);
            }
        }

        long nCr(long n, long r) {
            if (n < r)
                return 0;
            if (n < mod)
                return ((fact.get((int) n) * fact_inv.get((int) r) % mod) * fact_inv.get((int) (n - r))) % mod;
            long ret = 1;
            while (n != 0 || r != 0) {
                long _n = n % mod, _r = r % mod;
                n /= mod;
                r /= mod;
                (ret *= nCr(_n, _r)) %= mod;
            }
            return ret;
        }

        long nPr(long n, long r) {
            return (fact.get((int) n) * fact_inv.get((int) (n - r))) % mod;
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

    static long id1(long a, long b, long[] x, long[] y) {
        if (a < b)
            return id1(b, a, y, x);

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

    static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long m = sc.nextLong();
        long h1 = sc.nextLong();
        long a1 = sc.nextLong();
        long x1 = sc.nextLong();
        long y1 = sc.nextLong();
        List<Long> t = new ArrayList<>();
        boolean[] used = new boolean[(int) m];
        used[(int) h1] = true;
        t.add(h1);
        while (true) {
            long tmp = (t.get(t.size() - 1) * x1 + y1) % m;
            t.add(tmp);
            if (used[(int) tmp])
                break;
            used[(int) tmp] = true;
        }
        used = new boolean[(int) m];
        long h2 = sc.nextLong();
        long a2 = sc.nextLong();
        long x2 = sc.nextLong();
        long y2 = sc.nextLong();
        used[(int) h2] = true;
        List<Long> s = new ArrayList<>();
        s.add(h2);
        while (true) {
            long tmp = (s.get(s.size() - 1) * x2 + y2) % m;
            s.add(tmp);
            if (used[(int) tmp])
                break;
            used[(int) tmp] = true;
        }

        long l1 = -1, l2 = -1;
        long mn1 = INF, mn2 = INF;
        long now = 0;
        while (true) {
            if (t.get(t.size() - 1).equals(t.get((int) now))) {
                l1 = t.size() - (int) now - 1;
            }
            if (t.get((int) now).equals(a1)) {
                mn1 = now;
                break;
            }
            now++;
            if (now == t.size())
                break;
        }
        now = 0;
        while (true) {
            if (s.get(s.size() - 1).equals(s.get((int) now))) {
                l2 = s.size() - (int) now - 1;
            }
            if (s.get((int) now).equals(a2)) {
                mn2 = now;
                break;
            }
            now++;
            if (now == s.size())
                break;
        }
        long calc = 0;
        if (mn1 != INF && mn2 != INF) {
            if (mn1 == mn2)
                calc = mn1;
            else if (mn1 > mn2 && l2 == -1)
                calc = -1;
            else if (mn1 < mn2 && l1 == -1)
                calc = -1;
            else if (l1 == -1) {
                if ((mn1 - mn2) % l2 == 0)
                    calc = mn1;
                else
                    calc = -1;
            } else if (l2 == -1) {
                if ((mn2 - mn1) % l1 == 0)
                    calc = mn2;
                else
                    calc = -1;
            } else if (l1 == l2) {
                if (Math.abs(mn1 - mn2) % l1 == 0)
                    calc = Math.max(mn1, mn2);
                else
                    calc = -1;
            } else if (mn2 > mn1 && (mn2 - mn1) % l1 == 0)
                calc = mn2;
            else if (mn1 > mn2 && (mn1 - mn2) % l2 == 0)
                calc = mn1;
            else if (Math.abs(mn2 - mn1) % gcd(l1, l2) != 0)
                calc = -1;
            else {
                long[] x = new long[1];
                long[] y = new long[1];
                long g = id1(l1, l2, x, y);
                x[0] *= (mn2 - mn1) / g;
                y[0] *= (mn2 - mn1) / g;
                if (x[0] * l1 + mn1 < Math.max(mn1, mn2))
                    x[0] += ((Math.max(mn1, mn2) - x[0] * l1 + mn1 + l1 - 1) / l1 + l2 / g - 1) / (l2 / g) * (l2 / g);
                if (x[0] * l1 + mn1 >= Math.max(mn1, mn2))
                    x[0] -= (x[0] * l1 + mn1 - Math.max(mn1, mn2)) / l1 / (l2 / g) * (l2 / g);
                calc = x[0] * l1 + mn1;
            }
        } else
            calc = -1;
        System.out.println(calc);
    }

    static class Pair<K, V> {
        private K key;
        private V value;

        Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }

        K getKey() {
            return key;
        }

        V getValue() {
            return value;
        }

        void setKey(K key) {
            this.key = key;
        }

        void setValue(V value) {
            this.value = value;
        }
    }

    static class Edge {
        int to;
        int rev;
        long cap;

        Edge(int _to, long _cap, int _rev) {
            to = _to;
            cap = _cap;
            rev = _rev;
        }
    }

    static void add_edge(List<List<Edge>> G, int from, int to, long cap, boolean revFlag, long revCap) {
        G.get(from).add(new Edge(to, cap, G.get(to).size() + (from == to ? 1 : 0)));
        if (revFlag)
            G.get(to).add(new Edge(from, revCap, G.get(from).size() - 1));
    }

    static <T> boolean chmin(T a, T b) {
        if (a > b) {
            a = b;
            return true;
        }
        return false;
    }

    static <T> boolean chmax(T a, T b) {
        if (a < b) {
            a = b;
            return true;
        }
        return false;
    }

    static void swap(long a, long b) {
        long tmp = a;
        a = b;
        b = tmp;
    }

    static void swap(int a, int b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    static void chmin(long a, long b) {
        if (a > b)
            a = b;
    }

    static void chmin(int a, int b) {
        if (a > b)
            a = b;
    }

    static void chmax(long a, long b) {
        if (a < b)
            a = b;
    }

    static void chmax(int a, int b) {
        if (a < b)
            a = b;
    }
}
