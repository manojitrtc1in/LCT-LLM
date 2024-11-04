import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.lang.reflect.Array;
import java.util.function.BiFunction;
import java.util.function.Supplier;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.function.IntFunction;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.stream.Collectors;
import java.util.stream.Stream;
import java.io.BufferedReader;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        id19 solver = new id19();
        solver.solve(1, in, out);
        out.close();
    }

    static class id19 {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.readInt();
            int q = in.readInt();

            TreeGraph tree = new TreeGraph(n);
            for (int i = 1; i < n; i++) {
                tree.id3(i, in.readInt() - 1);
            }

            id8 lcm = new id8(tree, 0);

            IRmq<IntPair> id1 = new SegmentTree<>(n, Utils::minObj);
            IRmq<IntPair> id4 = new SegmentTree<>(n, Utils::maxObj);

            int[] depth = lcm.depth;
            int[] id24 = lcm.first;


            for (int i = 0; i < n; i++) {
                id1.set(i, new IntPair(id24[i], i));
                id4.set(i, new IntPair(id24[i], i));
            }

            for (int i = 0; i < q; i++) {
                int from = in.readInt() - 1;
                int to = in.readInt() - 1;

                if (to - from == 1) {
                    if (depth[from] >= depth[to]) {
                        out.println((to + 1) + " " + depth[from]);
                    } else {
                        out.println((from + 1) + " " + depth[to]);
                    }

                    continue;
                }

                IntPair first = id1.get(from, to);
                IntPair last = id4.get(from, to);

                

                id1.set(first.y(), new IntPair(Integer.MAX_VALUE, first.y()));
                id4.set(last.y(), new IntPair(0, last.y()));

                IntPair id27 = id1.get(from, to);
                IntPair id25 = id4.get(from, to);

                id1.set(first.y(), first);
                id4.set(last.y(), last);


                int id12 = lcm.id29(id27.y(), last.y());
                int id18 = lcm.id29(first.y(), id25.y());

                if (depth[id12] >= depth[id18]) {
                    out.println((first.y() + 1) + " " + depth[id12]);
                } else {
                    out.println((last.y() + 1) + " " + depth[id18]);
                }
            }
        }

    }

    static final class Utils {
        private Utils() {
        }

        public static <T extends Comparable<T>> T maxObj(T a, T b) {
            return a.compareTo(b) < 0 ? b : a;
        }

        public static <T extends Comparable<T>> T minObj(T a, T b) {
            return a.compareTo(b) <= 0 ? a : b;
        }

        public static <T> T[] id7(int n, IntFunction<T> creator) {
            if (n > 0) {
                T first = creator.apply(0);
                T[] res = (T[]) Array.newInstance(first.getClass(), n);
                res[0] = first;

                for (int i = 1; i < n; i++) {
                    res[i] = creator.apply(i);
                }

                return res;
            } else {
                return null;
            }
        }

        public static <T> T[] makeArray(int n, Supplier<T> creator) {
            return id7(n, value -> creator.get());
        }

        public static int id33(long x) {
            int res = 1;
            long p = 1;
            while (p < x) {
                p *= 2;
                res++;
            }
            return res;
        }

    }

    static class Pair<K, V> {
        private final K key;
        private final V value;

        public Pair(K k, V v) {
            key = k;
            value = v;
        }

        public Pair(Pair<? extends K, ? extends V> entry) {
            this(entry.getKey(), entry.getValue());
        }

        public K getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }

        public K getFirst() {
            return key;
        }

        public V getSecond() {
            return value;
        }

        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (!(o instanceof Pair)) {
                return false;
            } else {
                Pair<?, ?> oP = (Pair<?, ?>) o;
                return (key == null ?
                        oP.key == null :
                        key.equals(oP.key)) &&
                        (value == null ?
                                oP.value == null :
                                value.equals(oP.value));
            }
        }

        public int hashCode() {
            int result = key == null ? 0 : key.hashCode();

            final int h = value == null ? 0 : value.hashCode();
            result = 37 * result + h ^ (h >>> 16);

            return result;
        }

        public String toString() {
            return "[" + getKey() + ", " + getValue() + "]";
        }

    }

    static class TreeGraph {
        protected int n;
        protected ArrayList<Integer>[] edges;

        public TreeGraph(int n) {
            this.n = n;
            this.edges = Utils.makeArray(n, ArrayList::new);
        }

        public void addEdge(int from, int to) {
            edges[from].add(to);
        }

        public void id3(int a, int b) {
            addEdge(a, b);
            addEdge(b, a);
        }

    }

    static interface IRmq<T> {
        void set(int index, T value);

        T get(int from, int to);

    }

    static class id20 {
        private TreeGraph graph;
        private Map<Class, id20.id14> metrics;

        public id20(TreeGraph graph, int startNode, id20.id14... requiredMetrics) {

            this.metrics = Stream.of(requiredMetrics).collect(Collectors.toMap(Object::getClass, o -> o));

            this.graph = graph;

            metrics.values().forEach(dfsMetric -> dfsMetric.init(graph.n));

            this.dfs(startNode, -1);
        }

        private void dfs(int node, int from) {
            metrics.values().forEach(dfsMetric -> dfsMetric.onEnter(node, from, true));


            for (int target : graph.edges[node]) {
                if (target != from) {
                    dfs(target, node);
                    metrics.values().forEach(dfsMetric -> dfsMetric.onEnter(node, target, false));
                }
            }

            metrics.values().forEach(dfsMetric -> dfsMetric.onLeave(node, from));
        }

        public <T extends id20.id14> T metric(Class<T> c) {
            return (T) metrics.get(c);
        }

        public ArrayList<Integer> order() {
            return metric(id20.OrderMetric.class).order;
        }

        public int[] depth() {
            return metric(id20.DepthMetric.class).depth;
        }

        public interface id14 {
            void init(int size);

            void onEnter(int node, int from, boolean firstTime);

            void onLeave(int node, int to);

        }

        public static class DepthMetric implements id20.id14 {
            public int[] depth;

            public void init(int size) {
                depth = new int[size];
                Arrays.fill(depth, -1);
            }

            public void onEnter(int node, int from, boolean firstTime) {
                if (firstTime) {
                    depth[node] = from == -1 ? 0 : depth[from] + 1;
                }
            }

            public void onLeave(int node, int to) {
            }

        }

        public static class OrderMetric implements id20.id14 {
            public ArrayList<Integer> order;

            public void init(int size) {
                order = new ArrayList<>(size * 2);
            }

            public void onEnter(int node, int from, boolean firstTime) {
                order.add(node);
            }

            public void onLeave(int node, int to) {
            }

        }

    }

    static class SegmentTree<T> implements IRmq<T> {
        private Object[] arr;
        private int n;
        private BiFunction<T, T, T> ops;
        private boolean hadQueries = false;

        public SegmentTree(int size, BiFunction<T, T, T> ops) {
            this.ops = ops;
            int len = 1;
            while (len < size) {
                len *= 2;
            }
            this.n = len;

            arr = new Object[2 * n + 1];
        }

        private T refreshTree(int pos) {
            if (pos >= n) {
                return (T) arr[pos];
            }

            T sum = doSum(refreshTree(pos * 2), refreshTree(pos * 2 + 1));
            arr[pos] = sum;
            return sum;
        }

        public void set(int pos, T value) {
            pos += n;
            arr[pos] = value;

            

            if (!hadQueries) {
                return;
            }

            pos /= 2;

            while (pos >= 1) {
                arr[pos] = doSum((T) arr[2 * pos], (T) arr[2 * pos + 1]);
                pos /= 2;
            }
        }

        public T get(int from, int to) {
            if (!hadQueries) {
                hadQueries = true;
                refreshTree(1);
            }
            return get(1, 0, n - 1, from, to);
        }

        private T doSum(T a, T b) {
            if (a == null) {
                return b;
            }
            if (b == null) {
                return a;
            }
            return ops.apply(a, b);
        }

        private T get(int id5, int id15, int id28, int from, int to) {
            if (from == id15 && to == id28)
                return (T) arr[id5];

            int middle = (id15 + id28) / 2;

            if (to <= middle) {
                return get(id5 * 2, id15, middle, from, to);
            }

            if (from > middle) {
                return get(id5 * 2 + 1, middle + 1, id28, from, to);
            }

            T leftSum = get(id5 * 2, id15, middle, from, middle);
            T rightSum = get(id5 * 2 + 1, middle + 1, id28, middle + 1, to);

            return ops.apply(leftSum, rightSum);
        }

    }

    static class SparseTable<T> implements IRmq<T> {
        private final BiFunction<T, T, T> ops;
        private final int n;
        private final Object[][] table;
        private final int log;

        public SparseTable(int n, BiFunction<T, T, T> ops) {
            this.n = n;
            this.ops = ops;
            this.log = Utils.id33(this.n);

            this.table = new Object[n][log];
        }

        public void set(int index, T value) {
            if (this.table[index][0] != null) {
                throw new RuntimeException("Run time modification");
            }
            this.table[index][0] = value;
        }

        public T get(int from, int to) {
            if (from == to) {
                return (T) table[from][0];
            }
            

            int sz = 1;

            int pw = 0;
            while (sz < to - from + 1) {
                pw++;
                sz = sz << 1;
            }
            pw--;

            return ops.apply(build(from, pw), build(to - (1 << pw) + 1, pw));
        }

        private T build(int l, int i) {
            if (table[l][i] != null) {
                return (T) table[l][i];
            }
            return (T) (table[l][i] = ops.apply(build(l, i - 1), build(l + (1 << (i - 1)), i - 1)));
        }

    }

    static class id8 {
        private TreeGraph graph;
        private int root;
        private IRmq<IntPair> id26;
        private int blockSize;
        private int[] id21;
        private int[][][] id22;
        public int[] first;
        public int[] depth;
        public ArrayList<Integer> order;

        public id8(TreeGraph graph, int root) {
            this.graph = graph;
            this.root = root;

            this.id0();
        }

        private void id0() {
            id20 dfs = new id20(graph, root, new id20.OrderMetric(), new id20.DepthMetric());

            depth = dfs.depth();
            order = dfs.order();

            first = new int[graph.n];
            Arrays.fill(first, -1);

            for (int i = 0; i < order.size(); i++) {
                int node = order.get(i);

                if (first[node] == -1) {
                    first[node] = i;
                }
            }

            id6(order, depth);
            buildMasks();
        }

        private void id6(ArrayList<Integer> order, int[] depth) {
            int n = order.size();
            blockSize = (Utils.id33(n) + 1) / 2;
            int blocksCount = (n + blockSize - 1) / blockSize;

            id21 = new int[blocksCount];
            id26 = new SparseTable<>(blocksCount, Utils::minObj);

            for (int partI = 0; partI < blocksCount; partI++) {
                int index = partI * blockSize;
                int id16 = order.get(index++);
                int mask = 0;

                for (; index < (partI + 1) * blockSize; index++) {
                    if (index >= order.size()) {
                        mask = mask << 1;
                        continue;
                    }
                    int curIndex = order.get(index);
                    int prevIndex = order.get(index - 1);

                    mask = (mask << 1) | (depth[curIndex] < depth[prevIndex] ? 1 : 0);

                    if (depth[curIndex] < depth[id16]) {
                        id16 = curIndex;
                    }
                }

                id21[partI] = mask;
                id26.set(partI, new IntPair(depth[id16], id16));
            }
        }

        private void buildMasks() {
            id22 = new int[1 << blockSize][blockSize][blockSize];

            for (int mask = 0; mask < (1 << blockSize); mask++) {
                for (int i = 0; i < blockSize; i++) {
                    boolean id10 = (mask & (1 << i)) > 0;
                    int id23 = i;
                    int id30 = 0;
                    int heightCur = 0;

                    id22[mask][i][i] = i;

                    for (int j = i + 1; j < blockSize; j++) {
                        boolean id32 = (mask & (1 << (blockSize - 1 - j))) > 0;

                        heightCur = heightCur + (id32 ? -1 : 1);

                        if (heightCur < id30) {
                            id23 = j;
                            id30 = heightCur;
                        }

                        id22[mask][i][j] = id23;
                    }
                }
            }
        }

        public int id29(int a, int b) {
            int from = Math.min(first[a], first[b]);
            int to = Math.max(first[a], first[b]);

            int blockFirst = from / blockSize;
            int blockLast = to / blockSize;

            int id9 = from - blockFirst * blockSize;
            int id17 = to - blockLast * blockSize;

            IntPair res = null;

            if (blockFirst == blockLast) {
                res = id2(blockFirst, id9, id17);
            } else {
                res = Utils.minObj(id2(blockFirst, id9, blockSize - 1), id2(blockLast, 0, id17));

                int id11 = blockFirst + 1;
                int id13 = blockLast - 1;

                if (id11 <= id13) {
                    res = Utils.minObj(res, id26.get(id11, id13));
                }
            }

            return res.y();
        }

        private IntPair id2(int blockId, int blockFrom, int blockTo) {
            int id31 = id22[id21[blockId]][blockFrom][blockTo];
            int indexGlobal = blockId * blockSize + id31;

            return new IntPair(depth[order.get(indexGlobal)], order.get(indexGlobal));
        }

    }

    static class IntPair extends Pair<Integer, Integer> implements Comparable<IntPair> {
        public IntPair(Integer integer, Integer integer2) {
            super(integer, integer2);
        }

        public IntPair(Pair<? extends Integer, ? extends Integer> entry) {
            super(entry);
        }

        public Integer x() {
            return getFirst();
        }

        public Integer y() {
            return getSecond();
        }

        public int compareTo(IntPair o) {
            if (x().equals(o.x())) {
                return y().compareTo(o.y());
            }
            return x().compareTo(o.x());
        }

    }

    static class FastScanner {
        private StringTokenizer st;
        private BufferedReader in;

        public FastScanner(final InputStream in) {
            this.in = new BufferedReader(new InputStreamReader(in));
        }

        public String readToken() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(in.readLine());
                } catch (final IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        public int readInt() {
            return Integer.parseInt(readToken());
        }

    }
}

