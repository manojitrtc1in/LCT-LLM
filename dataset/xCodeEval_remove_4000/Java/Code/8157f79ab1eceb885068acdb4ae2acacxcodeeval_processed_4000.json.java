import java.util.*;

public class D {

    public static final int MOD998 = 998244353;
    public static final int MOD100 = 1000000007;

    public static void main(String[] args) throws Exception {
        ContestScanner sc = new ContestScanner();
        ContestPrinter cp = new ContestPrinter();
        int T = sc.nextInt();
        for (int t = 0; t < T; t++) {
            int N = sc.nextInt();
            int M = sc.nextInt();
            int[][] A = sc.id2(N, M);
            Integer[] order = new Integer[N];
            for (int n = 0; n < N; n++) {
                order[n] = n;
            }
            Arrays.sort(order, Comparator.comparingInt(i -> A[i][0]));
            Arrays.sort(A, Comparator.comparingInt(a -> a[0]));
            

            int[][] lu = new int[N][M];

            int[][] ru = new int[N][M];

            int[][] ld = new int[N][M];

            int[][] rd = new int[N][M];

            for (int n = 0; n < N; n++) {
                for (int m = 0; m < M; m++) {
                    if (n == 0) {
                        if (m == 0) {
                            lu[n][m] = A[n][m];
                        } else {
                            lu[n][m] = Math.max(lu[n][m - 1], A[n][m]);
                        }
                    } else {
                        if (m == 0) {
                            lu[n][m] = Math.max(lu[n - 1][m], A[n][m]);
                        } else {
                            lu[n][m] = Math.max(Math.max(lu[n - 1][m], lu[n][m - 1]), A[n][m]);
                        }
                    }
                }
            }
            for (int n = 0; n < N; n++) {
                for (int m = M - 1; m >= 0; m--) {
                    if (n == 0) {
                        if (m == M - 1) {
                            ru[n][m] = A[n][m];
                        } else {
                            ru[n][m] = Math.min(ru[n][m + 1], A[n][m]);
                        }
                    } else {
                        if (m == M - 1) {
                            ru[n][m] = Math.min(ru[n - 1][m], A[n][m]);
                        } else {
                            ru[n][m] = Math.min(Math.min(ru[n - 1][m], ru[n][m + 1]), A[n][m]);
                        }
                    }
                }
            }
            for (int n = N - 1; n >= 0; n--) {
                for (int m = 0; m < M; m++) {
                    if (n == N - 1) {
                        if (m == 0) {
                            ld[n][m] = A[n][m];
                        } else {
                            ld[n][m] = Math.min(ld[n][m - 1], A[n][m]);
                        }
                    } else {
                        if (m == 0) {
                            ld[n][m] = Math.min(ld[n + 1][m], A[n][m]);
                        } else {
                            ld[n][m] = Math.min(Math.min(ld[n + 1][m], ld[n][m - 1]), A[n][m]);
                        }
                    }
                }
            }
            for (int n = N - 1; n >= 0; n--) {
                for (int m = M - 1; m >= 0; m--) {
                    if (n == N - 1) {
                        if (m == M - 1) {
                            rd[n][m] = A[n][m];
                        } else {
                            rd[n][m] = Math.max(rd[n][m + 1], A[n][m]);
                        }
                    } else {
                        if (m == M - 1) {
                            rd[n][m] = Math.max(rd[n + 1][m], A[n][m]);
                        } else {
                            rd[n][m] = Math.max(Math.max(rd[n + 1][m], rd[n][m + 1]), A[n][m]);
                        }
                    }
                }
            }
            boolean found = false;
            int ansn = -1;
            int ansm = -1;
            for (int n = 0; n < N - 1; n++) {
                for (int m = 0; m < M - 1; m++) {
                    if (lu[n][m] < ld[n + 1][m] && ru[n][m + 1] > rd[n + 1][m + 1]) {
                        found = true;
                        ansn = n;
                        ansm = m;
                    }
                }
            }
            if (found) {
                cp.println("YES");
                boolean[] blue = new boolean[N];
                for (int n = 0; n <= ansn; n++) {
                    blue[order[n]] = true;
                }
                for (boolean b : blue) {
                    cp.print(b ? "B" : "R");
                }
                cp.println(" " + (ansm + 1));
            } else {
                cp.println("NO");

            }
        }
        cp.close();
    }

    

    

    


    public static int id41(int[][][] weighted_graph, int start, int goal) {
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

    public static int[] id13(int[][][] weighted_graph, int start) {
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
        PriorityQueue<Pair<Integer, Long>> id16 = new PriorityQueue<>((u, v) -> (int) (u.cdr - v.cdr));
        id16.offer(new Pair<Integer, Long>(start, 0L));
        while (!id16.isEmpty()) {
            Pair<Integer, Long> pair = id16.poll();
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
                    id16.offer(new Pair<Integer, Long>(info[0], dist[info[0]]));
                }
            }
        }
        return -1;
    }

    public static long[] id36(int[][][] weighted_graph, int start) {
        long[] dist = new long[weighted_graph.length];
        Arrays.fill(dist, 0, dist.length, Long.MAX_VALUE);
        dist[start] = 0;
        PriorityQueue<Pair<Integer, Long>> id16 = new PriorityQueue<>((u, v) -> (int) (u.cdr - v.cdr));
        id16.offer(new Pair<Integer, Long>(start, 0L));
        while (!id16.isEmpty()) {
            Pair<Integer, Long> pair = id16.poll();
            int now = pair.car;
            if (dist[now] < pair.cdr) {
                continue;
            }
            for (int[] info : weighted_graph[now]) {
                if (dist[info[0]] > dist[now] + info[1]) {
                    dist[info[0]] = dist[now] + info[1];
                    id16.offer(new Pair<Integer, Long>(info[0], dist[info[0]]));
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

    public static class Tuple1<A> extends Pair<A, Object> {
        public Tuple1(A a) {
            super(a, null);
        }
    }

    public static class Tuple2<A, B> extends Pair<A, Tuple1<B>> {
        public Tuple2(A a, B b) {
            super(a, new Tuple1<>(b));
        }
    }

    public static class Tuple3<A, B, C> extends Pair<A, Tuple2<B, C>> {
        public Tuple3(A a, B b, C c) {
            super(a, new Tuple2<>(b, c));
        }
    }

    public static class Tuple4<A, B, C, D> extends Pair<A, Tuple3<B, C, D>> {
        public Tuple4(A a, B b, C c, D d) {
            super(a, new Tuple3<>(b, c, d));
        }
    }

    public static class Tuple5<A, B, C, D, E> extends Pair<A, Tuple4<B, C, D, E>> {
        public Tuple5(A a, B b, C c, D d, E e) {
            super(a, new Tuple4<>(b, c, d, e));
        }
    }

    public static class id35<T> {
        private PriorityQueue<T> queue;
        private Multiset<T> total;
        private int size = 0;

        public id35() {
            queue = new PriorityQueue<>();
            total = new Multiset<>();
        }

        public id35(Comparator<T> c) {
            queue = new PriorityQueue<>(c);
            total = new Multiset<>();
        }

        public void clear() {
            queue.clear();
            total.clear();
            size = 0;
        }

        public boolean contains(T e) {
            return total.count(e) > 0;
        }

        public boolean isEmpty() {
            return size == 0;
        }

        public boolean offer(T e) {
            total.addOne(e);
            size++;
            return queue.offer(e);
        }

        public T peek() {
            if (total.isEmpty()) {
                return null;
            }
            simplify();
            return queue.peek();
        }

        public T poll() {
            if (total.isEmpty()) {
                return null;
            }
            simplify();
            size--;
            T res = queue.poll();
            total.removeOne(res);
            return res;
        }

        public void remove(T e) {
            total.removeOne(e);
            size--;
        }

        public int size() {
            return size;
        }

        private void simplify() {
            while (total.count(queue.peek()) == 0) {
                queue.poll();
            }
        }

    }

    static int[][] id39(ContestScanner sc, int node, int edge, boolean undirected) {
        int[][] arr = sc.id24(edge, 2);
        for (int n = 0; n < edge; n++) {
            arr[0][n]--;
            arr[1][n]--;
        }
        return GraphBuilder.makeGraph(node, edge, arr[0], arr[1], undirected);
    }

    static int[][][] id10(ContestScanner sc, int node, int edge, boolean undirected) {
        int[][] arr = sc.id24(edge, 3);
        for (int n = 0; n < edge; n++) {
            arr[0][n]--;
            arr[1][n]--;
        }
        return GraphBuilder.id4(node, edge, arr[0], arr[1], arr[2], undirected);
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
        public static int[][] makeGraph(int id27, int id11, int[] from, int[] to,
                boolean undirected) {
            int[][] graph = new int[id27][];
            int[] outdegree = new int[id27];
            for (int i = 0; i < id11; i++) {
                outdegree[from[i]]++;
                if (undirected)
                    outdegree[to[i]]++;
            }
            for (int i = 0; i < id27; i++)
                graph[i] = new int[outdegree[i]];
            for (int i = 0; i < id11; i++) {
                graph[from[i]][--outdegree[from[i]]] = to[i];
                if (undirected)
                    graph[to[i]][--outdegree[to[i]]] = from[i];
            }
            return graph;
        }

        public static int[][][] id4(int id27, int id11, int[] from, int[] to,
                int[] weight, boolean undirected) {
            int[][][] graph = new int[id27][][];
            int[] outdegree = new int[id27];
            for (int i = 0; i < id11; i++) {
                outdegree[from[i]]++;
                if (undirected)
                    outdegree[to[i]]++;
            }
            for (int i = 0; i < id27; i++)
                graph[i] = new int[outdegree[i]][];
            for (int i = 0; i < id11; i++) {
                graph[from[i]][--outdegree[from[i]]] = new int[] { to[i], weight[i] };
                if (undirected)
                    graph[to[i]][--outdegree[to[i]]] = new int[] { from[i], weight[i] };
            }
            return graph;
        }

        public static int[][][] id6(int id27, int id11, int[] from, int[] to,
                boolean undirected) {
            int[][][] graph = new int[id27][][];
            int[] outdegree = new int[id27];
            for (int i = 0; i < id11; i++) {
                outdegree[from[i]]++;
                if (undirected)
                    outdegree[to[i]]++;
            }
            for (int i = 0; i < id27; i++)
                graph[i] = new int[outdegree[i]][];
            for (int i = 0; i < id11; i++) {
                graph[from[i]][--outdegree[from[i]]] = new int[] { to[i], i, 0 };
                if (undirected)
                    graph[to[i]][--outdegree[to[i]]] = new int[] { from[i], i, 1 };
            }
            return graph;
        }

        public static int[][][] id21(int id27, int id11, int[] from,
                int[] to, int[] weight, boolean undirected) {
            int[][][] graph = new int[id27][][];
            int[] outdegree = new int[id27];
            for (int i = 0; i < id11; i++) {
                outdegree[from[i]]++;
                if (undirected)
                    outdegree[to[i]]++;
            }
            for (int i = 0; i < id27; i++)
                graph[i] = new int[outdegree[i]][];
            for (int i = 0; i < id11; i++) {
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

    static class id40 {
        private final ModArithmetic ma;
        private final int mod;

        private final boolean id29;
        private final ModArithmetic.id17 id7;

        private ArrayList<Integer> factorial;
        private ArrayList<Integer> id25;

        public id40(int mod) {
            this.ma = ModArithmetic.of(mod);
            this.id29 = ma instanceof ModArithmetic.id17;
            this.id7 = id29 ? (ModArithmetic.id17) ma : null;
            this.mod = mod;

            this.factorial = new ArrayList<>();
            this.id25 = new ArrayList<>();
        }

        public ModInt create(long value) {
            if ((value %= mod) < 0)
                value += mod;
            if (id29) {
                return new ModInt(id7.generate(value));
            } else {
                return new ModInt((int) value);
            }
        }

        private void id20(int max) {
            factorial.ensureCapacity(max + 1);
            if (factorial.size() == 0)
                factorial.add(1);
            for (int i = factorial.size(); i <= max; i++) {
                factorial.add(ma.mul(factorial.get(i - 1), i));
            }
        }

        public ModInt factorial(int i) {
            id20(i);
            return create(factorial.get(i));
        }

        public ModInt permutation(int n, int r) {
            if (n < 0 || r < 0 || n < r)
                return create(0);
            id20(n);
            if (id25.size() > n) {
                return create(ma.mul(factorial.get(n), id25.get(n - r)));
            }
            return create(ma.div(factorial.get(n), factorial.get(n - r)));
        }

        public ModInt combination(int n, int r) {
            if (n < 0 || r < 0 || n < r)
                return create(0);
            id20(n);
            if (id25.size() > n) {
                return create(
                        ma.mul(factorial.get(n), ma.mul(id25.get(n - r), id25.get(r))));
            }
            return create(ma.div(factorial.get(n), ma.mul(factorial.get(r), factorial.get(n - r))));
        }

        public void id30(int max) {
            id20(max);
            id25.ensureCapacity(max + 1);
            for (int i = id25.size(); i <= max; i++) {
                id25.add(ma.inv(factorial.get(i)));
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
                if (ma instanceof ModArithmetic.id17) {
                    return ((ModArithmetic.id17) ma).reduce(value);
                }
                return value;
            }

            public ModInt add(ModInt mi) {
                return new ModInt(ma.add(value, mi.value));
            }

            public ModInt add(ModInt mi1, ModInt mi2) {
                return new ModInt(ma.add(value, mi1.value)).id32(mi2);
            }

            public ModInt add(ModInt mi1, ModInt mi2, ModInt mi3) {
                return new ModInt(ma.add(value, mi1.value)).id32(mi2).id32(mi3);
            }

            public ModInt add(ModInt mi1, ModInt mi2, ModInt mi3, ModInt mi4) {
                return new ModInt(ma.add(value, mi1.value)).id32(mi2).id32(mi3).id32(mi4);
            }

            public ModInt add(ModInt mi1, ModInt... mis) {
                ModInt mi = add(mi1);
                for (ModInt m : mis)
                    mi.id32(m);
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
                return new ModInt(ma.mul(value, mi1.value)).id19(mi2);
            }

            public ModInt mul(ModInt mi1, ModInt mi2, ModInt mi3) {
                return new ModInt(ma.mul(value, mi1.value)).id19(mi2).id19(mi3);
            }

            public ModInt mul(ModInt mi1, ModInt mi2, ModInt mi3, ModInt mi4) {
                return new ModInt(ma.mul(value, mi1.value)).id19(mi2).id19(mi3).id19(mi4);
            }

            public ModInt mul(ModInt mi1, ModInt... mis) {
                ModInt mi = mul(mi1);
                for (ModInt m : mis)
                    mi.id19(m);
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

            public ModInt id32(ModInt mi) {
                this.value = ma.add(value, mi.value);
                return this;
            }

            public ModInt id32(ModInt mi1, ModInt mi2) {
                return id32(mi1).id32(mi2);
            }

            public ModInt id32(ModInt mi1, ModInt mi2, ModInt mi3) {
                return id32(mi1).id32(mi2).id32(mi3);
            }

            public ModInt id32(ModInt mi1, ModInt mi2, ModInt mi3, ModInt mi4) {
                return id32(mi1).id32(mi2).id32(mi3).id32(mi4);
            }

            public ModInt id32(ModInt... mis) {
                for (ModInt m : mis)
                    id32(m);
                return this;
            }

            public ModInt id32(long mi) {
                this.value = ma.add(value, ma.remainder(mi));
                return this;
            }

            public ModInt id33(ModInt mi) {
                this.value = ma.sub(value, mi.value);
                return this;
            }

            public ModInt id33(long mi) {
                this.value = ma.sub(value, ma.remainder(mi));
                return this;
            }

            public ModInt id19(ModInt mi) {
                this.value = ma.mul(value, mi.value);
                return this;
            }

            public ModInt id19(ModInt mi1, ModInt mi2) {
                return id19(mi1).id19(mi2);
            }

            public ModInt id19(ModInt mi1, ModInt mi2, ModInt mi3) {
                return id19(mi1).id19(mi2).id19(mi3);
            }

            public ModInt id19(ModInt mi1, ModInt mi2, ModInt mi3, ModInt mi4) {
                return id19(mi1).id19(mi2).id19(mi3).id19(mi4);
            }

            public ModInt id19(ModInt... mis) {
                for (ModInt m : mis)
                    id19(m);
                return this;
            }

            public ModInt id19(long mi) {
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
                    return new id15();
                } else if (mod == 2) {
                    return new id31();
                } else if (mod == 998244353) {
                    return new id0();
                } else if (mod == 1000000007) {
                    return new id8();
                } else if ((mod & 1) == 1) {
                    return new id17(mod);
                } else {
                    return new id12(mod);
                }
            }

            private static final class id15 extends ModArithmetic {
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

            private static final class id31 extends ModArithmetic {
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

            private static final class id17 extends id22 {
                private final long negInv;
                private final long r2;

                private id17(int mod) {
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

            private static final class id12 extends id22 {
                private static final long mask = 0xffff_ffffl;
                private final long mh;
                private final long ml;

                private id12(int mod) {
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

            private static class id22 extends ModArithmetic {
                final int mod;

                id22(int mod) {
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

    static class ContestScanner {
        private final java.io.InputStream in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;

        private static final long id34 = 922337203685477580L;
        private static final int id18 = 7;
        private static final int id14 = 8;

        public ContestScanner(java.io.InputStream in) {
            this.in = in;
        }

        public ContestScanner() {
            this(System.in);
        }

        private boolean id42() {
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
            if (id42())
                return buffer[ptr++];
            else
                return -1;
        }

        private static boolean id44(int c) {
            return 33 <= c && c <= 126;
        }

        public boolean hasNext() {
            while (id42() && !id44(buffer[ptr]))
                ptr++;
            return id42();
        }

        public String next() {
            if (!hasNext())
                throw new java.util.NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while (id44(b)) {
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
                    if (n >= id34) {
                        if (n == id34) {
                            if (minus) {
                                if (digit <= id14) {
                                    n = -n * 10 - digit;
                                    b = readByte();
                                    if (!id44(b)) {
                                        return n;
                                    } else if (b < '0' || '9' < b) {
                                        throw new NumberFormatException(
                                                String.format("%d%s... is not number", n, Character.toString(b)));
                                    }
                                }
                            } else {
                                if (digit <= id18) {
                                    n = n * 10 + digit;
                                    b = readByte();
                                    if (!id44(b)) {
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
                } else if (b == -1 || !id44(b)) {
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

        public long[] id43(int length) {
            long[] array = new long[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextLong();
            return array;
        }

        public long[] id43(int length, java.util.function.LongUnaryOperator map) {
            long[] array = new long[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsLong(this.nextLong());
            return array;
        }

        public int[] id26(int length) {
            int[] array = new int[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextInt();
            return array;
        }

        public int[][] id24(int length, int width) {
            int[][] arrays = new int[width][length];
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < width; j++)
                    arrays[j][i] = this.nextInt();
            }
            return arrays;
        }

        public int[] id26(int length, java.util.function.IntUnaryOperator map) {
            int[] array = new int[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsInt(this.nextInt());
            return array;
        }

        public double[] id38(int length) {
            double[] array = new double[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextDouble();
            return array;
        }

        public double[] id38(int length, java.util.function.DoubleUnaryOperator map) {
            double[] array = new double[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsDouble(this.nextDouble());
            return array;
        }

        public long[][] id23(int height, int width) {
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

        public double[][] id37(int height, int width) {
            double[][] mat = new double[height][width];
            for (int h = 0; h < height; h++)
                for (int w = 0; w < width; w++) {
                    mat[h][w] = this.nextDouble();
                }
            return mat;
        }

        public char[][] id28(int height, int width) {
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