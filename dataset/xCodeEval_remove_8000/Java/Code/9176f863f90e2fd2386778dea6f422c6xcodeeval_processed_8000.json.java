import java.util.*;

public class E {

    public static final int MOD998 = 998244353;
    public static final int MOD100 = 1000000007;

    public static void main(String[] args) throws Exception {
        ContestScanner sc = new ContestScanner();
        ContestPrinter cp = new ContestPrinter();
        int Q = sc.nextInt();
        for (int q = 0; q < Q; q++) {
            int N = sc.nextInt();
            String S = sc.next();
            String T = sc.next();
            long min = Long.MAX_VALUE;
            Long[] init = new Long[N];
            for (int n = 0; n < N; n++) {
                init[n] = (1L << 32) + (1L << (S.charAt(n) - 'a'));
            }
            SegTree<Long> seg = new SegTree<Long>(init,
                    (u, v) -> ((((u >> 32) + (v >> 32)) << 32) | ((u << 32 | v << 32) >> 32)),
                    0L);
            long solid = 0;
            int sp = 0;
            for (int n = 0; n < N; n++) {
                while (seg.get(sp) == 0) {
                    sp++;
                }
                int s = 0;
                long ssp = (seg.get(sp) << 32) >> 33;
                while (ssp != 0) {
                    ssp = ssp >> 1;
                    s++;
                }
                int t = T.charAt(n) - 'a';
                if (s < t) {
                    min = Math.min(solid, min);
                    break;
                } else if (s == t) {
                    int small = seg.maxRight(sp + 1, x -> (x & ((1 << t) - 1)) == 0);
                    if (small < N) {
                        long count = seg.prod(0, small) >> 32;
                        

                        min = Math.min(solid + count, min);
                    }
                    seg.set(sp, 0L);
                } else {
                    int small = seg.maxRight(sp + 1, x -> (x & ((1 << t) - 1)) == 0);
                    if (small < N) {
                        long count = seg.prod(0, small) >> 32;
                        

                        min = Math.min(solid + count, min);
                    }
                    int same = seg.maxRight(sp + 1, x -> (x & (1 << t)) == 0);
                    if (same < N) {
                        long count = seg.prod(0, same) >> 32;
                        

                        solid += count;
                        seg.set(same, 0L);
                    } else {
                        break;
                    }
                }
            }
            cp.println(min == Long.MAX_VALUE ? -1 : min);
        }
        cp.close();
    }

    static class SegTree<S> {
        final int MAX;

        final int N;
        final java.util.function.BinaryOperator<S> op;
        final S E;

        final S[] data;

        @SuppressWarnings("unchecked")
        public SegTree(int n, java.util.function.BinaryOperator<S> op, S e) {
            this.MAX = n;
            int k = 1;
            while (k < n)
                k <<= 1;
            this.N = k;
            this.E = e;
            this.op = op;
            this.data = (S[]) new Object[N << 1];
            java.util.Arrays.fill(data, E);
        }

        public SegTree(S[] dat, java.util.function.BinaryOperator<S> op, S e) {
            this(dat.length, op, e);
            build(dat);
        }

        private void build(S[] dat) {
            int l = dat.length;
            System.arraycopy(dat, 0, data, N, l);
            for (int i = N - 1; i > 0; i--) {
                data[i] = op.apply(data[i << 1 | 0], data[i << 1 | 1]);
            }
        }

        public void set(int p, S x) {
            id23(p);
            data[p += N] = x;
            p >>= 1;
            while (p > 0) {
                data[p] = op.apply(data[p << 1 | 0], data[p << 1 | 1]);
                p >>= 1;
            }
        }

        public S get(int p) {
            id23(p);
            return data[p + N];
        }

        public S prod(int l, int r) {
            if (l > r) {
                throw new IllegalArgumentException(String.format("Invalid range: [%d, %d)", l, r));
            }
            id1(l);
            id1(r);
            S sumLeft = E;
            S sumRight = E;
            l += N;
            r += N;
            while (l < r) {
                if ((l & 1) == 1)
                    sumLeft = op.apply(sumLeft, data[l++]);
                if ((r & 1) == 1)
                    sumRight = op.apply(data[--r], sumRight);
                l >>= 1;
                r >>= 1;
            }
            return op.apply(sumLeft, sumRight);
        }

        public S allProd() {
            return data[1];
        }

        public int maxRight(int l, java.util.function.Predicate<S> f) {
            id1(l);
            if (!f.test(E)) {
                throw new IllegalArgumentException("Identity element must satisfy the condition.");
            }
            if (l == MAX)
                return MAX;
            l += N;
            S sum = E;
            do {
                l >>= Integer.numberOfTrailingZeros(l);
                if (!f.test(op.apply(sum, data[l]))) {
                    while (l < N) {
                        l = l << 1;
                        if (f.test(op.apply(sum, data[l]))) {
                            sum = op.apply(sum, data[l]);
                            l++;
                        }
                    }
                    return l - N;
                }
                sum = op.apply(sum, data[l]);
                l++;
            } while ((l & -l) != l);
            return MAX;
        }

        public int minLeft(int r, java.util.function.Predicate<S> f) {
            id1(r);
            if (!f.test(E)) {
                throw new IllegalArgumentException("Identity element must satisfy the condition.");
            }
            if (r == 0)
                return 0;
            r += N;
            S sum = E;
            do {
                r--;
                while (r > 1 && (r & 1) == 1)
                    r >>= 1;
                if (!f.test(op.apply(data[r], sum))) {
                    while (r < N) {
                        r = r << 1 | 1;
                        if (f.test(op.apply(data[r], sum))) {
                            sum = op.apply(data[r], sum);
                            r--;
                        }
                    }
                    return r + 1 - N;
                }
                sum = op.apply(data[r], sum);
            } while ((r & -r) != r);
            return 0;
        }

        private void id23(int p) {
            if (p < 0 || p >= MAX) {
                throw new IndexOutOfBoundsException(
                        String.format("Index %d out of bounds for the range [%d, %d).", p, 0, MAX));
            }
        }

        private void id1(int p) {
            if (p < 0 || p > MAX) {
                throw new IndexOutOfBoundsException(
                        String.format("Index %d out of bounds for the range [%d, %d].", p, 0, MAX));
            }
        }

        


        private int indent = 6;

        public void setIndent(int newIndent) {
            this.indent = newIndent;
        }

        @Override
        public String toString() {
            return id8();
        }

        public String id19() {
            return id19(1, 0);
        }

        private String id19(int k, int sp) {
            if (k >= N)
                return indent(sp) + data[k];
            String s = "";
            s += id19(k << 1 | 1, sp + indent);
            s += "\n";
            s += indent(sp) + data[k];
            s += "\n";
            s += id19(k << 1 | 0, sp + indent);
            return s;
        }

        private static String indent(int n) {
            StringBuilder sb = new StringBuilder();
            while (n-- > 0)
                sb.append(' ');
            return sb.toString();
        }

        public String id8() {
            StringBuilder sb = new StringBuilder();
            sb.append('[');
            for (int i = 0; i < N; i++) {
                sb.append(data[i + N]);
                if (i < N - 1)
                    sb.append(',').append(' ');
            }
            sb.append(']');
            return sb.toString();
        }
    }

    

    

    


    public static int id28(int[][][] weighted_graph, int start, int goal) {
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

    public static int[] id10(int[][][] weighted_graph, int start) {
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
        PriorityQueue<Pair<Integer, Long>> id13 = new PriorityQueue<>((u, v) -> (int) (u.cdr - v.cdr));
        id13.offer(new Pair<Integer, Long>(start, 0L));
        while (!id13.isEmpty()) {
            Pair<Integer, Long> pair = id13.poll();
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
                    id13.offer(new Pair<Integer, Long>(info[0], dist[info[0]]));
                }
            }
        }
        return -1;
    }

    public static long[] id24(int[][][] weighted_graph, int start) {
        long[] dist = new long[weighted_graph.length];
        Arrays.fill(dist, 0, dist.length, Long.MAX_VALUE);
        dist[start] = 0;
        PriorityQueue<Pair<Integer, Long>> id13 = new PriorityQueue<>((u, v) -> (int) (u.cdr - v.cdr));
        id13.offer(new Pair<Integer, Long>(start, 0L));
        while (!id13.isEmpty()) {
            Pair<Integer, Long> pair = id13.poll();
            int now = pair.car;
            if (dist[now] < pair.cdr) {
                continue;
            }
            for (int[] info : weighted_graph[now]) {
                if (dist[info[0]] > dist[now] + info[1]) {
                    dist[info[0]] = dist[now] + info[1];
                    id13.offer(new Pair<Integer, Long>(info[0], dist[info[0]]));
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

    public static class id22<T> {
        private PriorityQueue<T> queue;
        private Multiset<T> total;
        private int size = 0;

        public id22() {
            queue = new PriorityQueue<>();
            total = new Multiset<>();
        }

        public id22(Comparator<T> c) {
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

    static int[][] id26(ContestScanner sc, int node, int edge, boolean undirected) {
        int[][] arr = sc.id16(edge, 2);
        for (int n = 0; n < edge; n++) {
            arr[0][n]--;
            arr[1][n]--;
        }
        return GraphBuilder.makeGraph(node, edge, arr[0], arr[1], undirected);
    }

    static int[][][] id7(ContestScanner sc, int node, int edge, boolean undirected) {
        int[][] arr = sc.id16(edge, 3);
        for (int n = 0; n < edge; n++) {
            arr[0][n]--;
            arr[1][n]--;
        }
        return GraphBuilder.id3(node, edge, arr[0], arr[1], arr[2], undirected);
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

        private static long[] id4(long a, long b) {
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
            return id4(a, b)[0];
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

                long[] ig = id4(m0, m1);
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

        public static java.util.ArrayList<Long> id0(long n) {
            java.util.ArrayList<Long> id0 = new ArrayList<>();
            java.util.ArrayList<Long> large = new ArrayList<>();

            for (long i = 1; i * i <= n; i++)
                if (n % i == 0) {
                    id0.add(i);
                    if (i * i < n)
                        large.add(n / i);
                }
            for (int p = large.size() - 1; p >= 0; p--) {
                id0.add(large.get(p));
            }
            return id0;
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
        public static int[][] makeGraph(int id18, int id9, int[] from, int[] to,
                boolean undirected) {
            int[][] graph = new int[id18][];
            int[] outdegree = new int[id18];
            for (int i = 0; i < id9; i++) {
                outdegree[from[i]]++;
                if (undirected)
                    outdegree[to[i]]++;
            }
            for (int i = 0; i < id18; i++)
                graph[i] = new int[outdegree[i]];
            for (int i = 0; i < id9; i++) {
                graph[from[i]][--outdegree[from[i]]] = to[i];
                if (undirected)
                    graph[to[i]][--outdegree[to[i]]] = from[i];
            }
            return graph;
        }

        public static int[][][] id3(int id18, int id9, int[] from, int[] to,
                int[] weight, boolean undirected) {
            int[][][] graph = new int[id18][][];
            int[] outdegree = new int[id18];
            for (int i = 0; i < id9; i++) {
                outdegree[from[i]]++;
                if (undirected)
                    outdegree[to[i]]++;
            }
            for (int i = 0; i < id18; i++)
                graph[i] = new int[outdegree[i]][];
            for (int i = 0; i < id9; i++) {
                graph[from[i]][--outdegree[from[i]]] = new int[] { to[i], weight[i] };
                if (undirected)
                    graph[to[i]][--outdegree[to[i]]] = new int[] { from[i], weight[i] };
            }
            return graph;
        }

        public static int[][][] id5(int id18, int id9, int[] from, int[] to,
                boolean undirected) {
            int[][][] graph = new int[id18][][];
            int[] outdegree = new int[id18];
            for (int i = 0; i < id9; i++) {
                outdegree[from[i]]++;
                if (undirected)
                    outdegree[to[i]]++;
            }
            for (int i = 0; i < id18; i++)
                graph[i] = new int[outdegree[i]][];
            for (int i = 0; i < id9; i++) {
                graph[from[i]][--outdegree[from[i]]] = new int[] { to[i], i, 0 };
                if (undirected)
                    graph[to[i]][--outdegree[to[i]]] = new int[] { from[i], i, 1 };
            }
            return graph;
        }

        public static int[][][] id14(int id18, int id9, int[] from,
                int[] to, int[] weight, boolean undirected) {
            int[][][] graph = new int[id18][][];
            int[] outdegree = new int[id18];
            for (int i = 0; i < id9; i++) {
                outdegree[from[i]]++;
                if (undirected)
                    outdegree[to[i]]++;
            }
            for (int i = 0; i < id18; i++)
                graph[i] = new int[outdegree[i]][];
            for (int i = 0; i < id9; i++) {
                graph[from[i]][--outdegree[from[i]]] = new int[] { to[i], weight[i], i, 0 };
                if (undirected)
                    graph[to[i]][--outdegree[to[i]]] = new int[] { from[i], weight[i], i, 1 };
            }
            return graph;
        }
    }

    static class DSU {
        private int n;
        private int[] id6;

        public DSU(int n) {
            this.n = n;
            this.id6 = new int[n];
            java.util.Arrays.fill(id6, -1);
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
            if (-id6[x] < -id6[y]) {
                int tmp = x;
                x = y;
                y = tmp;
            }
            id6[x] += id6[y];
            id6[y] = x;
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
            if (id6[a] < 0) {
                return a;
            } else {
                id6[a] = leader(id6[a]);
                return id6[a];
            }
        }

        int size(int a) {
            if (!(0 <= a && a < n))
                throw new IndexOutOfBoundsException("" + a);
            return -id6[leader(a)];
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

    static class ContestScanner {
        private final java.io.InputStream in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;

        private static final long id21 = 922337203685477580L;
        private static final int id12 = 7;
        private static final int id11 = 8;

        public ContestScanner(java.io.InputStream in) {
            this.in = in;
        }

        public ContestScanner() {
            this(System.in);
        }

        private boolean id29() {
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
            if (id29())
                return buffer[ptr++];
            else
                return -1;
        }

        private static boolean id31(int c) {
            return 33 <= c && c <= 126;
        }

        public boolean hasNext() {
            while (id29() && !id31(buffer[ptr]))
                ptr++;
            return id29();
        }

        public String next() {
            if (!hasNext())
                throw new java.util.NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while (id31(b)) {
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
                    if (n >= id21) {
                        if (n == id21) {
                            if (minus) {
                                if (digit <= id11) {
                                    n = -n * 10 - digit;
                                    b = readByte();
                                    if (!id31(b)) {
                                        return n;
                                    } else if (b < '0' || '9' < b) {
                                        throw new NumberFormatException(
                                                String.format("%d%s... is not number", n, Character.toString(b)));
                                    }
                                }
                            } else {
                                if (digit <= id12) {
                                    n = n * 10 + digit;
                                    b = readByte();
                                    if (!id31(b)) {
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
                } else if (b == -1 || !id31(b)) {
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

        public long[] id30(int length) {
            long[] array = new long[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextLong();
            return array;
        }

        public long[] id30(int length, java.util.function.LongUnaryOperator map) {
            long[] array = new long[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsLong(this.nextLong());
            return array;
        }

        public int[] id17(int length) {
            int[] array = new int[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextInt();
            return array;
        }

        public int[][] id16(int length, int width) {
            int[][] arrays = new int[width][length];
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < width; j++)
                    arrays[j][i] = this.nextInt();
            }
            return arrays;
        }

        public int[] id17(int length, java.util.function.IntUnaryOperator map) {
            int[] array = new int[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsInt(this.nextInt());
            return array;
        }

        public double[] id27(int length) {
            double[] array = new double[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextDouble();
            return array;
        }

        public double[] id27(int length, java.util.function.DoubleUnaryOperator map) {
            double[] array = new double[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsDouble(this.nextDouble());
            return array;
        }

        public long[][] id15(int height, int width) {
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

        public double[][] id25(int height, int width) {
            double[][] mat = new double[height][width];
            for (int h = 0; h < height; h++)
                for (int w = 0; w < width; w++) {
                    mat[h][w] = this.nextDouble();
                }
            return mat;
        }

        public char[][] id20(int height, int width) {
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
