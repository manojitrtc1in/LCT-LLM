import java.util.*;

public class J {

    public static final int MOD998 = 998244353;
    public static final int MOD100 = 1000000007;

    public static void main(String[] args) throws Exception {
        ContestScanner sc = new ContestScanner();
        ContestPrinter cp = new ContestPrinter();
        String S = sc.next();
        int N = S.length();
        ArrayList<Integer> start = new ArrayList<>();
        ArrayList<Integer> end = new ArrayList<>();
        for (int n = 0; n <= N; n++) {
            if (n == 0) {
                if (S.charAt(0) == '
                    start.add(0);
                }
            } else if (n == N) {
                if (S.charAt(N - 1) == '
                    end.add(N - 1);
                }
            } else {
                if (S.charAt(n - 1) == '_' && S.charAt(n) == '
                    start.add(n);
                } else if (S.charAt(n - 1) == '
                    end.add(n - 1);
                }
            }
        }
        

        boolean ok1 = true;
        if (!start.isEmpty()) {
            if (start.get(0) > 0 || end.get(end.size() - 1) < N - 1) {
                ok1 = false;
            } else {
                for (int n = 0; n < start.size() - 1; n++) {
                    if (end.get(n) + 2 != start.get(n + 1)) {
                        ok1 = false;
                        break;
                    }
                }
            }
        }
        if (ok1) {
            ArrayList<Integer> ans = new ArrayList<>();
            for (int n = 0; n < start.size(); n++) {
                ans.add(end.get(n) - start.get(n) + 1);
            }
            cp.println(ans.size());
            for (int i : ans) {
                cp.print(i + " ");
            }
            cp.println();
            cp.close();
            return;
        }
        

        boolean ok2 = true;
        if (start.get(0) % 2 == 0 || (N - end.get(end.size() - 1)) % 2 == 1) {
            ok2 = false;
        } else {
            for (int n = 0; n < start.size() - 1; n++) {
                if (start.get(n + 1) - end.get(n) < 3 || (start.get(n + 1) - end.get(n) - 3) % 2 == 1) {
                    ok2 = false;
                    break;
                }
            }
        }
        if (ok2) {
            ArrayList<Integer> ans = new ArrayList<>();
            for (int n = 0; n < start.size(); n++) {
                if (n == 0) {
                    for (int m = 0; m < (start.get(0) - 1) / 2; m++) {
                        ans.add(1);
                    }
                }
                ans.add(end.get(n) - start.get(n) + 2);
                for (int m = 0; m < ((n == start.size() - 1 ? N + 1 : start.get(n + 1)) - end.get(n) - 3) / 2; m++) {
                    ans.add(1);
                }
            }
            cp.println(ans.size());
            for (int i : ans) {
                cp.print(i + " ");
            }
            cp.println();
            cp.close();
            return;
        }
        

        boolean ok3 = true;
        if (start.get(0) < 4 && start.get(0) != 2
                || (N - end.get(end.size() - 1) - 1) < 4 && (N - end.get(end.size() - 1) - 1) != 2) {
            ok3 = false;
        } else {
            for (int n = 0; n < start.size() - 1; n++) {
                if (start.get(n + 1) - end.get(n) < 4 || start.get(n + 1) - end.get(n) == 5) {
                    ok3 = false;
                    break;
                }
            }
        }
        if (ok3) {
            ArrayList<Integer> ans = new ArrayList<>();
            for (int n = 0; n < start.size(); n++) {
                if (n == 0) {
                    if (start.get(0) % 2 == 0) {
                        for (int m = 0; m < (start.get(0) - 2) / 2; m++) {
                            ans.add(1);
                        }
                    } else {
                        ans.add(2);
                        for (int m = 0; m < (start.get(0) - 5) / 2; m++) {
                            ans.add(1);
                        }
                    }
                }
                ans.add(end.get(n) - start.get(n) + 3);
                if (((n == start.size() - 1 ? N + 1 : start.get(n + 1)) - end.get(n)) % 2 == 0) {
                    for (int m = 0; m < ((n == start.size() - 1 ? N + 1 : start.get(n + 1)) - end.get(n) - 4)
                            / 2; m++) {
                        ans.add(1);
                    }
                } else {
                    ans.add(2);
                    for (int m = 0; m < ((n == start.size() - 1 ? N + 1 : start.get(n + 1)) - end.get(n) - 7)
                            / 2; m++) {
                        ans.add(1);
                    }
                }
            }
            cp.println(ans.size());
            for (int i : ans) {
                cp.print(i + " ");
            }
            cp.println();
            cp.close();
            return;
        }
        

        boolean ok4 = true;
        if (start.get(0) < 5 && start.get(0) != 3
                || (N - end.get(end.size() - 1) - 1) < 5 && (N - end.get(end.size() - 1) - 1) != 3) {
            ok4 = false;
        } else {
            for (int n = 0; n < start.size() - 1; n++) {
                if (start.get(n + 1) - end.get(n) < 5 || start.get(n + 1) - end.get(n) == 6) {
                    ok4 = false;
                    break;
                }
            }
        }
        if (ok4) {
            ArrayList<Integer> ans = new ArrayList<>();
            for (int n = 0; n < start.size(); n++) {
                if (n == 0) {
                    if (start.get(0) % 2 == 1) {
                        for (int m = 0; m < (start.get(0) - 3) / 2; m++) {
                            ans.add(1);
                        }
                    } else {
                        ans.add(2);
                        for (int m = 0; m < (start.get(0) - 8) / 2; m++) {
                            ans.add(1);
                        }
                    }
                }
                ans.add(end.get(n) - start.get(n) + 4);
                if (((n == start.size() - 1 ? N + 1 : start.get(n + 1)) - end.get(n)) % 2 == 1) {
                    for (int m = 0; m < ((n == start.size() - 1 ? N + 1 : start.get(n + 1)) - end.get(n) - 5)
                            / 2; m++) {
                        ans.add(1);
                    }
                } else {
                    ans.add(2);
                    for (int m = 0; m < ((n == start.size() - 1 ? N + 1 : start.get(n + 1)) - end.get(n) - 8)
                            / 2; m++) {
                        ans.add(1);
                    }
                }
            }
            cp.println(ans.size());
            for (int i : ans) {
                cp.print(i + " ");
            }
            cp.println();
            cp.close();
            return;
        }
        cp.println(-1);
        cp.close();
    }

    

    

    


    public static int id43(int[][][] weighted_graph, int start, int goal) {
        int[] dist = new int[weighted_graph.length];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;
        LinkedList<Integer> queue = new LinkedList<>();
        queue.add(start);
        while (!queue.isEmpty()) {
            int now = queue.poll();
            if (now == goal) {
                return dist[goal];
            }
            for (int[] info : weighted_graph[now]) {
                if (dist[info[0]] > dist[now] + info[1]) {
                    dist[info[0]] = dist[now] + info[1];
                    if (info[1] == 0) {
                        queue.addFirst(info[0]);
                    } else {
                        queue.addLast(info[0]);
                    }
                }
            }
        }
        return -1;
    }

    public static int[] id15(int[][][] weighted_graph, int start) {
        int[] dist = new int[weighted_graph.length];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;
        LinkedList<Integer> queue = new LinkedList<>();
        queue.add(start);
        while (!queue.isEmpty()) {
            int now = queue.poll();
            for (int[] info : weighted_graph[now]) {
                if (dist[info[0]] > dist[now] + info[1]) {
                    dist[info[0]] = dist[now] + info[1];
                    if (info[1] == 0) {
                        queue.addFirst(info[0]);
                    } else {
                        queue.addLast(info[0]);
                    }
                }
            }
        }
        return dist;
    }

    public static long dijkstra(int[][][] weighted_graph, int start, int goal) {
        long[] dist = new long[weighted_graph.length];
        Arrays.fill(dist, 0, dist.length, Long.MAX_VALUE);
        dist[start] = 0;
        PriorityQueue<Pair<Integer, Long>> id18 = new PriorityQueue<>((u, v) -> (int) (u.cdr - v.cdr));
        id18.offer(new Pair<Integer, Long>(start, 0L));
        while (!id18.isEmpty()) {
            Pair<Integer, Long> pair = id18.poll();
            int now = pair.car;
            if (now == goal) {
                return dist[goal];
            }
            if (dist[now] < pair.cdr) {
                continue;
            }
            for (int[] info : weighted_graph[now]) {
                if (dist[info[0]] > dist[now] + info[1]) {
                    dist[info[0]] = dist[now] + info[1];
                    id18.offer(new Pair<Integer, Long>(info[0], dist[info[0]]));
                }
            }
        }
        return -1;
    }

    public static long[] id39(int[][][] weighted_graph, int start) {
        long[] dist = new long[weighted_graph.length];
        Arrays.fill(dist, 0, dist.length, Long.MAX_VALUE);
        dist[start] = 0;
        PriorityQueue<Pair<Integer, Long>> id18 = new PriorityQueue<>((u, v) -> (int) (u.cdr - v.cdr));
        id18.offer(new Pair<Integer, Long>(start, 0L));
        while (!id18.isEmpty()) {
            Pair<Integer, Long> pair = id18.poll();
            int now = pair.car;
            if (dist[now] < pair.cdr) {
                continue;
            }
            for (int[] info : weighted_graph[now]) {
                if (dist[info[0]] > dist[now] + info[1]) {
                    dist[info[0]] = dist[now] + info[1];
                    id18.offer(new Pair<Integer, Long>(info[0], dist[info[0]]));
                }
            }
        }
        return dist;
    }

    public static class Pair<A, B> {
        public final A car;
        public final B cdr;

        public Pair(A car_, B cdr_) {
            car = car_;
            cdr = cdr_;
        }

        private static boolean eq(Object o1, Object o2) {
            return o1 == null ? o2 == null : o1.equals(o2);
        }

        private static int hc(Object o) {
            return o == null ? 0 : o.hashCode();
        }

        @Override
        public boolean equals(Object o) {
            if (!(o instanceof Pair))
                return false;
            Pair<?, ?> rhs = (Pair<?, ?>) o;
            return eq(car, rhs.car) && eq(cdr, rhs.cdr);
        }

        @Override
        public int hashCode() {
            return hc(car) ^ hc(cdr);
        }
    }

    static class EdgeData {
        private int capacity;
        private int[] from, to, weight;
        private int p = 0;
        private boolean weighted;

        public EdgeData(boolean weighted) {
            this(weighted, 500000);
        }

        public EdgeData(boolean weighted, int initial_capacity) {
            capacity = initial_capacity;
            from = new int[capacity];
            to = new int[capacity];
            weight = new int[capacity];
            this.weighted = weighted;
        }

        public void addEdge(int u, int v) {
            if (weighted) {
                System.err.println("The graph is weighted!");
                return;
            }
            if (p == capacity) {
                int[] newfrom = new int[capacity * 2];
                int[] newto = new int[capacity * 2];
                System.arraycopy(from, 0, newfrom, 0, capacity);
                System.arraycopy(to, 0, newto, 0, capacity);
                from = newfrom;
                to = newto;
                capacity *= 2;
            }
            from[p] = u;
            to[p] = v;
            p++;
        }

        public void addEdge(int u, int v, int w) {
            if (!weighted) {
                System.err.println("The graph is NOT weighted!");
                return;
            }
            if (p == capacity) {
                int[] newfrom = new int[capacity * 2];
                int[] newto = new int[capacity * 2];
                int[] newweight = new int[capacity * 2];
                System.arraycopy(from, 0, newfrom, 0, capacity);
                System.arraycopy(to, 0, newto, 0, capacity);
                System.arraycopy(weight, 0, newweight, 0, capacity);
                from = newfrom;
                to = newto;
                weight = newweight;
                capacity *= 2;
            }
            from[p] = u;
            to[p] = v;
            weight[p] = w;
            p++;
        }

        public int[] getFrom() {
            int[] result = new int[p];
            System.arraycopy(from, 0, result, 0, p);
            return result;
        }

        public int[] getTo() {
            int[] result = new int[p];
            System.arraycopy(to, 0, result, 0, p);
            return result;
        }

        public int[] getWeight() {
            int[] result = new int[p];
            System.arraycopy(weight, 0, result, 0, p);
            return result;
        }

        public int size() {
            return p;
        }
    }

    

    

    


    static class MathLib {
        private static long safe_mod(long x, long m) {
            x %= m;
            if (x < 0)
                x += m;
            return x;
        }

        private static long[] id5(long a, long b) {
            a = safe_mod(a, b);
            if (a == 0)
                return new long[] { b, 0 };
            long s = b, t = a;
            long m0 = 0, m1 = 1;
            while (t > 0) {
                long u = s / t;
                s -= t * u;
                m0 -= m1 * u;
                long tmp = s;
                s = t;
                t = tmp;
                tmp = m0;
                m0 = m1;
                m1 = tmp;
            }
            if (m0 < 0)
                m0 += b / s;
            return new long[] { s, m0 };
        }

        public static long gcd(long a, long b) {
            a = java.lang.Math.abs(a);
            b = java.lang.Math.abs(b);
            return id5(a, b)[0];
        }

        public static long lcm(long a, long b) {
            a = java.lang.Math.abs(a);
            b = java.lang.Math.abs(b);
            return a / gcd(a, b) * b;
        }

        public static long pow_mod(long x, long n, int m) {
            assert n >= 0;
            assert m >= 1;
            if (m == 1)
                return 0L;
            x = safe_mod(x, m);
            long ans = 1L;
            while (n > 0) {
                if ((n & 1) == 1)
                    ans = (ans * x) % m;
                x = (x * x) % m;
                n >>>= 1;
            }
            return ans;
        }

        public static long[] crt(long[] r, long[] m) {
            assert (r.length == m.length);
            int n = r.length;

            long r0 = 0, m0 = 1;
            for (int i = 0; i < n; i++) {
                assert (1 <= m[i]);
                long r1 = safe_mod(r[i], m[i]), m1 = m[i];
                if (m0 < m1) {
                    long tmp = r0;
                    r0 = r1;
                    r1 = tmp;
                    tmp = m0;
                    m0 = m1;
                    m1 = tmp;
                }
                if (m0 % m1 == 0) {
                    if (r0 % m1 != r1)
                        return new long[] { 0, 0 };
                    continue;
                }

                long[] ig = id5(m0, m1);
                long g = ig[0], im = ig[1];

                long u1 = m1 / g;
                if ((r1 - r0) % g != 0)
                    return new long[] { 0, 0 };

                long x = (r1 - r0) / g % u1 * im % u1;

                r0 += x * m0;
                m0 *= u1;
                if (r0 < 0)
                    r0 += m0;
                

            }
            return new long[] { r0, m0 };
        }

        public static long floor_sum(long n, long m, long a, long b) {
            long ans = 0;
            if (a >= m) {
                ans += (n - 1) * n * (a / m) / 2;
                a %= m;
            }
            if (b >= m) {
                ans += n * (b / m);
                b %= m;
            }

            long y_max = (a * n + b) / m;
            long x_max = y_max * m - b;
            if (y_max == 0)
                return ans;
            ans += (n - (x_max + a - 1) / a) * y_max;
            ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
            return ans;
        }

        public static java.util.ArrayList<Long> id1(long n) {
            java.util.ArrayList<Long> id1 = new ArrayList<>();
            java.util.ArrayList<Long> large = new ArrayList<>();

            for (long i = 1; i * i <= n; i++)
                if (n % i == 0) {
                    id1.add(i);
                    if (i * i < n)
                        large.add(n / i);
                }
            for (int p = large.size() - 1; p >= 0; p--) {
                id1.add(large.get(p));
            }
            return id1;
        }
    }

    static class Multiset<T> extends java.util.TreeMap<T, Long> {
        public Multiset() {
            super();
        }

        public Multiset(java.util.List<T> list) {
            super();
            for (T e : list)
                this.addOne(e);
        }

        public long count(Object elm) {
            return getOrDefault(elm, 0L);
        }

        public void add(T elm, long amount) {
            if (!this.containsKey(elm))
                put(elm, amount);
            else
                replace(elm, get(elm) + amount);
            if (this.count(elm) == 0)
                this.remove(elm);
        }

        public void addOne(T elm) {
            this.add(elm, 1);
        }

        public void removeOne(T elm) {
            this.add(elm, -1);
        }

        public void removeAll(T elm) {
            this.add(elm, -this.count(elm));
        }

        public static <T> Multiset<T> merge(Multiset<T> a, Multiset<T> b) {
            Multiset<T> c = new Multiset<>();
            for (T x : a.keySet())
                c.add(x, a.count(x));
            for (T y : b.keySet())
                c.add(y, b.count(y));
            return c;
        }
    }

    static class GraphBuilder {
        public static int[][] makeGraph(int id30, int id12, int[] from, int[] to,
                boolean undirected) {
            int[][] graph = new int[id30][];
            int[] outdegree = new int[id30];
            for (int i = 0; i < id12; i++) {
                outdegree[from[i]]++;
                if (undirected)
                    outdegree[to[i]]++;
            }
            for (int i = 0; i < id30; i++)
                graph[i] = new int[outdegree[i]];
            for (int i = 0; i < id12; i++) {
                graph[from[i]][--outdegree[from[i]]] = to[i];
                if (undirected)
                    graph[to[i]][--outdegree[to[i]]] = from[i];
            }
            return graph;
        }

        public static int[][][] id4(int id30, int id12, int[] from, int[] to,
                int[] weight, boolean undirected) {
            int[][][] graph = new int[id30][][];
            int[] outdegree = new int[id30];
            for (int i = 0; i < id12; i++) {
                outdegree[from[i]]++;
                if (undirected)
                    outdegree[to[i]]++;
            }
            for (int i = 0; i < id30; i++)
                graph[i] = new int[outdegree[i]][];
            for (int i = 0; i < id12; i++) {
                graph[from[i]][--outdegree[from[i]]] = new int[] { to[i], weight[i] };
                if (undirected)
                    graph[to[i]][--outdegree[to[i]]] = new int[] { from[i], weight[i] };
            }
            return graph;
        }

        public static int[][][] id6(int id30, int id12, int[] from, int[] to,
                boolean undirected) {
            int[][][] graph = new int[id30][][];
            int[] outdegree = new int[id30];
            for (int i = 0; i < id12; i++) {
                outdegree[from[i]]++;
                if (undirected)
                    outdegree[to[i]]++;
            }
            for (int i = 0; i < id30; i++)
                graph[i] = new int[outdegree[i]][];
            for (int i = 0; i < id12; i++) {
                graph[from[i]][--outdegree[from[i]]] = new int[] { to[i], i, 0 };
                if (undirected)
                    graph[to[i]][--outdegree[to[i]]] = new int[] { from[i], i, 1 };
            }
            return graph;
        }

        public static int[][][] id23(int id30, int id12, int[] from,
                int[] to, int[] weight, boolean undirected) {
            int[][][] graph = new int[id30][][];
            int[] outdegree = new int[id30];
            for (int i = 0; i < id12; i++) {
                outdegree[from[i]]++;
                if (undirected)
                    outdegree[to[i]]++;
            }
            for (int i = 0; i < id30; i++)
                graph[i] = new int[outdegree[i]][];
            for (int i = 0; i < id12; i++) {
                graph[from[i]][--outdegree[from[i]]] = new int[] { to[i], weight[i], i, 0 };
                if (undirected)
                    graph[to[i]][--outdegree[to[i]]] = new int[] { from[i], weight[i], i, 1 };
            }
            return graph;
        }
    }

    static class DSU {
        private int n;
        private int[] id9;

        public DSU(int n) {
            this.n = n;
            this.id9 = new int[n];
            java.util.Arrays.fill(id9, -1);
        }

        int merge(int a, int b) {
            if (!(0 <= a && a < n))
                throw new IndexOutOfBoundsException("a=" + a);
            if (!(0 <= b && b < n))
                throw new IndexOutOfBoundsException("b=" + b);

            int x = leader(a);
            int y = leader(b);
            if (x == y)
                return x;
            if (-id9[x] < -id9[y]) {
                int tmp = x;
                x = y;
                y = tmp;
            }
            id9[x] += id9[y];
            id9[y] = x;
            return x;
        }

        boolean same(int a, int b) {
            if (!(0 <= a && a < n))
                throw new IndexOutOfBoundsException("a=" + a);
            if (!(0 <= b && b < n))
                throw new IndexOutOfBoundsException("b=" + b);
            return leader(a) == leader(b);
        }

        int leader(int a) {
            if (id9[a] < 0) {
                return a;
            } else {
                id9[a] = leader(id9[a]);
                return id9[a];
            }
        }

        int size(int a) {
            if (!(0 <= a && a < n))
                throw new IndexOutOfBoundsException("" + a);
            return -id9[leader(a)];
        }

        java.util.ArrayList<java.util.ArrayList<Integer>> groups() {
            int[] leaderBuf = new int[n];
            int[] groupSize = new int[n];
            for (int i = 0; i < n; i++) {
                leaderBuf[i] = leader(i);
                groupSize[leaderBuf[i]]++;
            }
            java.util.ArrayList<java.util.ArrayList<Integer>> result = new java.util.ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                result.add(new java.util.ArrayList<>(groupSize[i]));
            }
            for (int i = 0; i < n; i++) {
                result.get(leaderBuf[i]).add(i);
            }
            result.removeIf(java.util.ArrayList::isEmpty);
            return result;
        }
    }

    static class id42 {
        private final ModArithmetic ma;
        private final int mod;

        private final boolean id33;
        private final ModArithmetic.id19 id7;

        private ArrayList<Integer> factorial;
        private ArrayList<Integer> id27;

        public id42(int mod) {
            this.ma = ModArithmetic.of(mod);
            this.id33 = ma instanceof ModArithmetic.id19;
            this.id7 = id33 ? (ModArithmetic.id19) ma : null;
            this.mod = mod;

            this.factorial = new ArrayList<>();
            this.id27 = new ArrayList<>();
        }

        public ModInt create(long value) {
            if ((value %= mod) < 0)
                value += mod;
            if (id33) {
                return new ModInt(id7.generate(value));
            } else {
                return new ModInt((int) value);
            }
        }

        private void id22(int max) {
            factorial.ensureCapacity(max + 1);
            if (factorial.size() == 0)
                factorial.add(1);
            for (int i = factorial.size(); i <= max; i++) {
                factorial.add(ma.mul(factorial.get(i - 1), i));
            }
        }

        public ModInt factorial(int i) {
            id22(i);
            return create(factorial.get(i));
        }

        public ModInt permutation(int n, int r) {
            if (n < 0 || r < 0 || n < r)
                return create(0);
            id22(n);
            if (id27.size() > n) {
                return create(ma.mul(factorial.get(n), id27.get(n - r)));
            }
            return create(ma.div(factorial.get(n), factorial.get(n - r)));
        }

        public ModInt combination(int n, int r) {
            if (n < 0 || r < 0 || n < r)
                return create(0);
            id22(n);
            if (id27.size() > n) {
                return create(
                        ma.mul(factorial.get(n), ma.mul(id27.get(n - r), id27.get(r))));
            }
            return create(ma.div(factorial.get(n), ma.mul(factorial.get(r), factorial.get(n - r))));
        }

        public void id34(int max) {
            id22(max);
            id27.ensureCapacity(max + 1);
            for (int i = id27.size(); i <= max; i++) {
                id27.add(ma.inv(factorial.get(i)));
            }
        }

        public int getMod() {
            return mod;
        }

        public class ModInt {
            private int value;

            private ModInt(int value) {
                this.value = value;
            }

            public int mod() {
                return mod;
            }

            public int value() {
                if (ma instanceof ModArithmetic.id19) {
                    return ((ModArithmetic.id19) ma).reduce(value);
                }
                return value;
            }

            public ModInt add(ModInt mi) {
                return new ModInt(ma.add(value, mi.value));
            }

            public ModInt add(ModInt mi1, ModInt mi2) {
                return new ModInt(ma.add(value, mi1.value)).id36(mi2);
            }

            public ModInt add(ModInt mi1, ModInt mi2, ModInt mi3) {
                return new ModInt(ma.add(value, mi1.value)).id36(mi2).id36(mi3);
            }

            public ModInt add(ModInt mi1, ModInt mi2, ModInt mi3, ModInt mi4) {
                return new ModInt(ma.add(value, mi1.value)).id36(mi2).id36(mi3).id36(mi4);
            }

            public ModInt add(ModInt mi1, ModInt... mis) {
                ModInt mi = add(mi1);
                for (ModInt m : mis)
                    mi.id36(m);
                return mi;
            }

            public ModInt add(long mi) {
                return new ModInt(ma.add(value, ma.remainder(mi)));
            }

            public ModInt sub(ModInt mi) {
                return new ModInt(ma.sub(value, mi.value));
            }

            public ModInt sub(long mi) {
                return new ModInt(ma.sub(value, ma.remainder(mi)));
            }

            public ModInt mul(ModInt mi) {
                return new ModInt(ma.mul(value, mi.value));
            }

            public ModInt mul(ModInt mi1, ModInt mi2) {
                return new ModInt(ma.mul(value, mi1.value)).id21(mi2);
            }

            public ModInt mul(ModInt mi1, ModInt mi2, ModInt mi3) {
                return new ModInt(ma.mul(value, mi1.value)).id21(mi2).id21(mi3);
            }

            public ModInt mul(ModInt mi1, ModInt mi2, ModInt mi3, ModInt mi4) {
                return new ModInt(ma.mul(value, mi1.value)).id21(mi2).id21(mi3).id21(mi4);
            }

            public ModInt mul(ModInt mi1, ModInt... mis) {
                ModInt mi = mul(mi1);
                for (ModInt m : mis)
                    mi.id21(m);
                return mi;
            }

            public ModInt mul(long mi) {
                return new ModInt(ma.mul(value, ma.remainder(mi)));
            }

            public ModInt div(ModInt mi) {
                return new ModInt(ma.div(value, mi.value));
            }

            public ModInt div(long mi) {
                return new ModInt(ma.div(value, ma.remainder(mi)));
            }

            public ModInt inv() {
                return new ModInt(ma.inv(value));
            }

            public ModInt pow(long b) {
                return new ModInt(ma.pow(value, b));
            }

            public ModInt id36(ModInt mi) {
                this.value = ma.add(value, mi.value);
                return this;
            }

            public ModInt id36(ModInt mi1, ModInt mi2) {
                return id36(mi1).id36(mi2);
            }

            public ModInt id36(ModInt mi1, ModInt mi2, ModInt mi3) {
                return id36(mi1).id36(mi2).id36(mi3);
            }

            public ModInt id36(ModInt mi1, ModInt mi2, ModInt mi3, ModInt mi4) {
                return id36(mi1).id36(mi2).id36(mi3).id36(mi4);
            }

            public ModInt id36(ModInt... mis) {
                for (ModInt m : mis)
                    id36(m);
                return this;
            }

            public ModInt id36(long mi) {
                this.value = ma.add(value, ma.remainder(mi));
                return this;
            }

            public ModInt id37(ModInt mi) {
                this.value = ma.sub(value, mi.value);
                return this;
            }

            public ModInt id37(long mi) {
                this.value = ma.sub(value, ma.remainder(mi));
                return this;
            }

            public ModInt id21(ModInt mi) {
                this.value = ma.mul(value, mi.value);
                return this;
            }

            public ModInt id21(ModInt mi1, ModInt mi2) {
                return id21(mi1).id21(mi2);
            }

            public ModInt id21(ModInt mi1, ModInt mi2, ModInt mi3) {
                return id21(mi1).id21(mi2).id21(mi3);
            }

            public ModInt id21(ModInt mi1, ModInt mi2, ModInt mi3, ModInt mi4) {
                return id21(mi1).id21(mi2).id21(mi3).id21(mi4);
            }

            public ModInt id21(ModInt... mis) {
                for (ModInt m : mis)
                    id21(m);
                return this;
            }

            public ModInt id21(long mi) {
                this.value = ma.mul(value, ma.remainder(mi));
                return this;
            }

            public ModInt id3(ModInt mi) {
                this.value = ma.div(value, mi.value);
                return this;
            }

            public ModInt id3(long mi) {
                this.value = ma.div(value, ma.remainder(mi));
                return this;
            }

            @Override
            public String toString() {
                return String.valueOf(value());
            }

            @Override
            public boolean equals(Object o) {
                if (o instanceof ModInt) {
                    ModInt mi = (ModInt) o;
                    return mod() == mi.mod() && value() == mi.value();
                }
                return false;
            }

            @Override
            public int hashCode() {
                return (1 * 37 + mod()) * 37 + value();
            }
        }

        private static abstract class ModArithmetic {
            abstract int mod();

            abstract int remainder(long value);

            abstract int add(int a, int b);

            abstract int sub(int a, int b);

            abstract int mul(int a, int b);

            int div(int a, int b) {
                return mul(a, inv(b));
            }

            int inv(int a) {
                int b = mod();
                if (b == 1)
                    return 0;
                long u = 1, v = 0;
                while (b >= 1) {
                    int t = a / b;
                    a -= t * b;
                    int tmp1 = a;
                    a = b;
                    b = tmp1;
                    u -= t * v;
                    long tmp2 = u;
                    u = v;
                    v = tmp2;
                }
                if (a != 1) {
                    throw new ArithmeticException("divide by zero");
                }
                return remainder(u);
            }

            int pow(int a, long b) {
                if (b < 0)
                    throw new ArithmeticException("negative power");
                int r = 1;
                int x = a;
                while (b > 0) {
                    if ((b & 1) == 1)
                        r = mul(r, x);
                    x = mul(x, x);
                    b >>= 1;
                }
                return r;
            }

            static ModArithmetic of(int mod) {
                if (mod <= 0) {
                    throw new IllegalArgumentException();
                } else if (mod == 1) {
                    return new id17();
                } else if (mod == 2) {
                    return new id35();
                } else if (mod == 998244353) {
                    return new id0();
                } else if (mod == 1000000007) {
                    return new id8();
                } else if ((mod & 1) == 1) {
                    return new id19(mod);
                } else {
                    return new id13(mod);
                }
            }

            private static final class id17 extends ModArithmetic {
                int mod() {
                    return 1;
                }

                int remainder(long value) {
                    return 0;
                }

                int add(int a, int b) {
                    return 0;
                }

                int sub(int a, int b) {
                    return 0;
                }

                int mul(int a, int b) {
                    return 0;
                }

                int pow(int a, long b) {
                    return 0;
                }
            }

            private static final class id35 extends ModArithmetic {
                int mod() {
                    return 2;
                }

                int remainder(long value) {
                    return (int) (value & 1);
                }

                int add(int a, int b) {
                    return a ^ b;
                }

                int sub(int a, int b) {
                    return a ^ b;
                }

                int mul(int a, int b) {
                    return a & b;
                }
            }

            private static final class id0 extends ModArithmetic {
                private final int mod = 998244353;

                int mod() {
                    return mod;
                }

                int remainder(long value) {
                    return (int) ((value %= mod) < 0 ? value + mod : value);
                }

                int add(int a, int b) {
                    int res = a + b;
                    return res >= mod ? res - mod : res;
                }

                int sub(int a, int b) {
                    int res = a - b;
                    return res < 0 ? res + mod : res;
                }

                int mul(int a, int b) {
                    return (int) (((long) a * b) % mod);
                }
            }

            private static final class id8 extends ModArithmetic {
                private final int mod = 1000000007;

                int mod() {
                    return mod;
                }

                int remainder(long value) {
                    return (int) ((value %= mod) < 0 ? value + mod : value);
                }

                int add(int a, int b) {
                    int res = a + b;
                    return res >= mod ? res - mod : res;
                }

                int sub(int a, int b) {
                    int res = a - b;
                    return res < 0 ? res + mod : res;
                }

                int mul(int a, int b) {
                    return (int) (((long) a * b) % mod);
                }
            }

            private static final class id19 extends id24 {
                private final long negInv;
                private final long r2;

                private id19(int mod) {
                    super(mod);
                    long inv = 0;
                    long s = 1, t = 0;
                    for (int i = 0; i < 32; i++) {
                        if ((t & 1) == 0) {
                            t += mod;
                            inv += s;
                        }
                        t >>= 1;
                        s <<= 1;
                    }
                    long r = (1l << 32) % mod;
                    this.negInv = inv;
                    this.r2 = (r * r) % mod;
                }

                private int generate(long x) {
                    return reduce(x * r2);
                }

                private int reduce(long x) {
                    x = (x + ((x * negInv) & 0xffff_ffffl) * mod) >>> 32;
                    return (int) (x < mod ? x : x - mod);
                }

                @Override
                int remainder(long value) {
                    return generate((value %= mod) < 0 ? value + mod : value);
                }

                @Override
                int mul(int a, int b) {
                    return reduce((long) a * b);
                }

                @Override
                int inv(int a) {
                    return super.inv(reduce(a));
                }

                @Override
                int pow(int a, long b) {
                    return generate(super.pow(a, b));
                }
            }

            private static final class id13 extends id24 {
                private static final long mask = 0xffff_ffffl;
                private final long mh;
                private final long ml;

                private id13(int mod) {
                    super(mod);
                    
                    long a = (1l << 32) / mod;
                    long b = (1l << 32) % mod;
                    long m = a * a * mod + 2 * a * b + (b * b) / mod;
                    mh = m >>> 32;
                    ml = m & mask;
                }

                private int reduce(long x) {
                    long z = (x & mask) * ml;
                    z = (x & mask) * mh + (x >>> 32) * ml + (z >>> 32);
                    z = (x >>> 32) * mh + (z >>> 32);
                    x -= z * mod;
                    return (int) (x < mod ? x : x - mod);
                }

                @Override
                int remainder(long value) {
                    return (int) ((value %= mod) < 0 ? value + mod : value);
                }

                @Override
                int mul(int a, int b) {
                    return reduce((long) a * b);
                }
            }

            private static class id24 extends ModArithmetic {
                final int mod;

                id24(int mod) {
                    this.mod = mod;
                }

                int mod() {
                    return mod;
                }

                int remainder(long value) {
                    return (int) ((value %= mod) < 0 ? value + mod : value);
                }

                int add(int a, int b) {
                    int sum = a + b;
                    return sum >= mod ? sum - mod : sum;
                }

                int sub(int a, int b) {
                    int sum = a - b;
                    return sum < 0 ? sum + mod : sum;
                }

                int mul(int a, int b) {
                    return (int) (((long) a * b) % mod);
                }
            }
        }
    }

    static class Convolution {
        
        private static int primitiveRoot(int m) {
            if (m == 2)
                return 1;
            if (m == 167772161)
                return 3;
            if (m == 469762049)
                return 3;
            if (m == 754974721)
                return 11;
            if (m == 998244353)
                return 3;

            int[] divs = new int[20];
            divs[0] = 2;
            int cnt = 1;
            int x = (m - 1) / 2;
            while (x % 2 == 0)
                x /= 2;
            for (int i = 3; (long) (i) * i <= x; i += 2) {
                if (x % i == 0) {
                    divs[cnt++] = i;
                    while (x % i == 0) {
                        x /= i;
                    }
                }
            }
            if (x > 1) {
                divs[cnt++] = x;
            }
            for (int g = 2;; g++) {
                boolean ok = true;
                for (int i = 0; i < cnt; i++) {
                    if (pow(g, (m - 1) / divs[i], m) == 1) {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                    return g;
            }
        }

        
        private static long pow(long x, long n, int m) {
            if (m == 1)
                return 0;
            long r = 1;
            long y = x % m;
            while (n > 0) {
                if ((n & 1) != 0)
                    r = (r * y) % m;
                y = (y * y) % m;
                n >>= 1;
            }
            return r;
        }

        
        private static int id31(int n) {
            int x = 0;
            while ((1L << x) < n)
                x++;
            return x;
        }

        
        private static long garner(long[] c, int[] mods) {
            int n = c.length + 1;
            long[] cnst = new long[n];
            long[] coef = new long[n];
            java.util.Arrays.fill(coef, 1);
            for (int i = 0; i < n - 1; i++) {
                int m1 = mods[i];
                long v = (c[i] - cnst[i] + m1) % m1;
                v = v * pow(coef[i], m1 - 2, m1) % m1;

                for (int j = i + 1; j < n; j++) {
                    long m2 = mods[j];
                    cnst[j] = (cnst[j] + coef[j] * v) % m2;
                    coef[j] = (coef[j] * m1) % m2;
                }
            }
            return cnst[n - 1];
        }

        
        private static long[] sumE(int mod, int g) {
            long[] sum_e = new long[30];
            long[] es = new long[30];
            long[] ies = new long[30];
            int cnt2 = Integer.numberOfTrailingZeros(mod - 1);
            long e = pow(g, (mod - 1) >> cnt2, mod);
            long ie = pow(e, mod - 2, mod);
            for (int i = cnt2; i >= 2; i--) {
                es[i - 2] = e;
                ies[i - 2] = ie;
                e = e * e % mod;
                ie = ie * ie % mod;
            }
            long now = 1;
            for (int i = 0; i < cnt2 - 2; i++) {
                sum_e[i] = es[i] * now % mod;
                now = now * ies[i] % mod;
            }
            return sum_e;
        }

        
        private static long[] sumIE(int mod, int g) {
            long[] sum_ie = new long[30];
            long[] es = new long[30];
            long[] ies = new long[30];

            int cnt2 = Integer.numberOfTrailingZeros(mod - 1);
            long e = pow(g, (mod - 1) >> cnt2, mod);
            long ie = pow(e, mod - 2, mod);
            for (int i = cnt2; i >= 2; i--) {
                es[i - 2] = e;
                ies[i - 2] = ie;
                e = e * e % mod;
                ie = ie * ie % mod;
            }
            long now = 1;
            for (int i = 0; i < cnt2 - 2; i++) {
                sum_ie[i] = ies[i] * now % mod;
                now = now * es[i] % mod;
            }
            return sum_ie;
        }

        
        private static void id28(long[] a, long[] sumIE, int mod) {
            int n = a.length;
            int h = id31(n);

            for (int ph = h; ph >= 1; ph--) {
                int w = 1 << (ph - 1), p = 1 << (h - ph);
                long inow = 1;
                for (int s = 0; s < w; s++) {
                    int offset = s << (h - ph + 1);
                    for (int i = 0; i < p; i++) {
                        long l = a[i + offset];
                        long r = a[i + offset + p];
                        a[i + offset] = (l + r) % mod;
                        a[i + offset + p] = (mod + l - r) * inow % mod;
                    }
                    int x = Integer.numberOfTrailingZeros(~s);
                    inow = inow * sumIE[x] % mod;
                }
            }
        }

        
        private static void id10(long[] a, long[] sumE, int mod) {
            int n = a.length;
            int h = id31(n);

            for (int ph = 1; ph <= h; ph++) {
                int w = 1 << (ph - 1), p = 1 << (h - ph);
                long now = 1;
                for (int s = 0; s < w; s++) {
                    int offset = s << (h - ph + 1);
                    for (int i = 0; i < p; i++) {
                        long l = a[i + offset];
                        long r = a[i + offset + p] * now % mod;
                        a[i + offset] = (l + r) % mod;
                        a[i + offset + p] = (l - r + mod) % mod;
                    }
                    int x = Integer.numberOfTrailingZeros(~s);
                    now = now * sumE[x] % mod;
                }
            }
        }

        
        public static long[] convolution(long[] a, long[] b, int mod) {
            int n = a.length;
            int m = b.length;
            if (n == 0 || m == 0)
                return new long[0];

            int z = 1 << id31(n + m - 1);
            {
                long[] na = new long[z];
                long[] nb = new long[z];
                System.arraycopy(a, 0, na, 0, n);
                System.arraycopy(b, 0, nb, 0, m);
                a = na;
                b = nb;
            }

            int g = primitiveRoot(mod);
            long[] sume = sumE(mod, g);
            long[] sumie = sumIE(mod, g);

            id10(a, sume, mod);
            id10(b, sume, mod);
            for (int i = 0; i < z; i++) {
                a[i] = a[i] * b[i] % mod;
            }
            id28(a, sumie, mod);
            a = java.util.Arrays.copyOf(a, n + m - 1);

            long iz = pow(z, mod - 2, mod);
            for (int i = 0; i < n + m - 1; i++)
                a[i] = a[i] * iz % mod;
            return a;
        }

        
        public static long[] id14(long[] a, long[] b, int mod) {
            int n = a.length;
            int m = b.length;
            if (n == 0 || m == 0)
                return new long[0];

            int mod1 = 754974721;
            int mod2 = 167772161;
            int mod3 = 469762049;

            long[] c1 = convolution(a, b, mod1);
            long[] c2 = convolution(a, b, mod2);
            long[] c3 = convolution(a, b, mod3);

            int retSize = c1.length;
            long[] ret = new long[retSize];
            int[] mods = { mod1, mod2, mod3, mod };
            for (int i = 0; i < retSize; ++i) {
                ret[i] = garner(new long[] { c1[i], c2[i], c3[i] }, mods);
            }
            return ret;
        }

        
        public static java.util.List<id42.ModInt> convolution(java.util.List<id42.ModInt> a,
                java.util.List<id42.ModInt> b) {
            int mod = a.get(0).mod();
            long[] va = a.stream().mapToLong(id42.ModInt::value).toArray();
            long[] vb = b.stream().mapToLong(id42.ModInt::value).toArray();
            long[] c = id14(va, vb, mod);

            id42 factory = new id42(mod);
            return java.util.Arrays.stream(c).mapToObj(factory::create).collect(java.util.stream.Collectors.toList());
        }

        
        public static long[] id11(long[] a, long[] b, int mod) {
            int n = a.length;
            int m = b.length;
            int k = n + m - 1;
            long[] ret = new long[k];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ret[i + j] += a[i] * b[j] % mod;
                    ret[i + j] %= mod;
                }
            }
            return ret;
        }
    }

    static class ContestScanner {
        private final java.io.InputStream in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;

        private static final long id38 = 922337203685477580L;
        private static final int id20 = 7;
        private static final int id16 = 8;

        public ContestScanner(java.io.InputStream in) {
            this.in = in;
        }

        public ContestScanner() {
            this(System.in);
        }

        private boolean id44() {
            if (ptr < buflen) {
                return true;
            } else {
                ptr = 0;
                try {
                    buflen = in.read(buffer);
                } catch (java.io.IOException e) {
                    e.printStackTrace();
                }
                if (buflen <= 0) {
                    return false;
                }
            }
            return true;
        }

        private int readByte() {
            if (id44())
                return buffer[ptr++];
            else
                return -1;
        }

        private static boolean id46(int c) {
            return 33 <= c && c <= 126;
        }

        public boolean hasNext() {
            while (id44() && !id46(buffer[ptr]))
                ptr++;
            return id44();
        }

        public String next() {
            if (!hasNext())
                throw new java.util.NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while (id46(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        public long nextLong() {
            if (!hasNext())
                throw new java.util.NoSuchElementException();
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            if (b < '0' || '9' < b) {
                throw new NumberFormatException();
            }
            while (true) {
                if ('0' <= b && b <= '9') {
                    int digit = b - '0';
                    if (n >= id38) {
                        if (n == id38) {
                            if (minus) {
                                if (digit <= id16) {
                                    n = -n * 10 - digit;
                                    b = readByte();
                                    if (!id46(b)) {
                                        return n;
                                    } else if (b < '0' || '9' < b) {
                                        throw new NumberFormatException(
                                                String.format("%d%s... is not number", n, Character.toString(b)));
                                    }
                                }
                            } else {
                                if (digit <= id20) {
                                    n = n * 10 + digit;
                                    b = readByte();
                                    if (!id46(b)) {
                                        return n;
                                    } else if (b < '0' || '9' < b) {
                                        throw new NumberFormatException(
                                                String.format("%d%s... is not number", n, Character.toString(b)));
                                    }
                                }
                            }
                        }
                        throw new ArithmeticException(
                                String.format("%s%d%d... overflows long.", minus ? "-" : "", n, digit));
                    }
                    n = n * 10 + digit;
                } else if (b == -1 || !id46(b)) {
                    return minus ? -n : n;
                } else {
                    throw new NumberFormatException();
                }
                b = readByte();
            }
        }

        public int nextInt() {
            long nl = nextLong();
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
                throw new NumberFormatException();
            return (int) nl;
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public long[] id45(int length) {
            long[] array = new long[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextLong();
            return array;
        }

        public long[] id45(int length, java.util.function.LongUnaryOperator map) {
            long[] array = new long[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsLong(this.nextLong());
            return array;
        }

        public int[] id29(int length) {
            int[] array = new int[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextInt();
            return array;
        }

        public int[][] id26(int length, int width) {
            int[][] arrays = new int[width][length];
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < width; j++)
                    arrays[j][i] = this.nextInt();
            }
            return arrays;
        }

        public int[] id29(int length, java.util.function.IntUnaryOperator map) {
            int[] array = new int[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsInt(this.nextInt());
            return array;
        }

        public double[] id41(int length) {
            double[] array = new double[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextDouble();
            return array;
        }

        public double[] id41(int length, java.util.function.DoubleUnaryOperator map) {
            double[] array = new double[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsDouble(this.nextDouble());
            return array;
        }

        public long[][] id25(int height, int width) {
            long[][] mat = new long[height][width];
            for (int h = 0; h < height; h++)
                for (int w = 0; w < width; w++) {
                    mat[h][w] = this.nextLong();
                }
            return mat;
        }

        public int[][] id2(int height, int width) {
            int[][] mat = new int[height][width];
            for (int h = 0; h < height; h++)
                for (int w = 0; w < width; w++) {
                    mat[h][w] = this.nextInt();
                }
            return mat;
        }

        public double[][] id40(int height, int width) {
            double[][] mat = new double[height][width];
            for (int h = 0; h < height; h++)
                for (int w = 0; w < width; w++) {
                    mat[h][w] = this.nextDouble();
                }
            return mat;
        }

        public char[][] id32(int height, int width) {
            char[][] mat = new char[height][width];
            for (int h = 0; h < height; h++) {
                String s = this.next();
                for (int w = 0; w < width; w++) {
                    mat[h][w] = s.charAt(w);
                }
            }
            return mat;
        }
    }

    static class ContestPrinter extends java.io.PrintWriter {
        public ContestPrinter(java.io.PrintStream stream) {
            super(stream);
        }

        public ContestPrinter() {
            super(System.out);
        }

        private static String dtos(double x, int n) {
            StringBuilder sb = new StringBuilder();
            if (x < 0) {
                sb.append('-');
                x = -x;
            }
            x += Math.pow(10, -n) / 2;
            sb.append((long) x);
            sb.append(".");
            x -= (long) x;
            for (int i = 0; i < n; i++) {
                x *= 10;
                sb.append((int) x);
                x -= (int) x;
            }
            return sb.toString();
        }

        @Override
        public void print(float f) {
            super.print(dtos(f, 20));
        }

        @Override
        public void println(float f) {
            super.println(dtos(f, 20));
        }

        @Override
        public void print(double d) {
            super.print(dtos(d, 20));
        }

        @Override
        public void println(double d) {
            super.println(dtos(d, 20));
        }

        public void printArray(int[] array, String separator) {
            int n = array.length;
            for (int i = 0; i < n - 1; i++) {
                super.print(array[i]);
                super.print(separator);
            }
            super.println(array[n - 1]);
        }

        public void printArray(int[] array) {
            this.printArray(array, " ");
        }

        public void printArray(int[] array, String separator, java.util.function.IntUnaryOperator map) {
            int n = array.length;
            for (int i = 0; i < n - 1; i++) {
                super.print(map.applyAsInt(array[i]));
                super.print(separator);
            }
            super.println(map.applyAsInt(array[n - 1]));
        }

        public void printArray(int[] array, java.util.function.IntUnaryOperator map) {
            this.printArray(array, " ", map);
        }

        public void printArray(long[] array, String separator) {
            int n = array.length;
            for (int i = 0; i < n - 1; i++) {
                super.print(array[i]);
                super.print(separator);
            }
            super.println(array[n - 1]);
        }

        public void printArray(long[] array) {
            this.printArray(array, " ");
        }

        public void printArray(long[] array, String separator, java.util.function.LongUnaryOperator map) {
            int n = array.length;
            for (int i = 0; i < n - 1; i++) {
                super.print(map.applyAsLong(array[i]));
                super.print(separator);
            }
            super.println(map.applyAsLong(array[n - 1]));
        }

        public void printArray(long[] array, java.util.function.LongUnaryOperator map) {
            this.printArray(array, " ", map);
        }

    }

    public static void safeSort(int[] array) {
        Integer[] temp = new Integer[array.length];
        for (int n = 0; n < array.length; n++) {
            temp[n] = array[n];
        }
        Arrays.sort(temp);
        for (int n = 0; n < array.length; n++) {
            array[n] = temp[n];
        }
    }

    public static void safeSort(long[] array) {
        Long[] temp = new Long[array.length];
        for (int n = 0; n < array.length; n++) {
            temp[n] = array[n];
        }
        Arrays.sort(temp);
        for (int n = 0; n < array.length; n++) {
            array[n] = temp[n];
        }
    }

    public static void safeSort(double[] array) {
        Double[] temp = new Double[array.length];
        for (int n = 0; n < array.length; n++) {
            temp[n] = array[n];
        }
        Arrays.sort(temp);
        for (int n = 0; n < array.length; n++) {
            array[n] = temp[n];
        }
    }

}
