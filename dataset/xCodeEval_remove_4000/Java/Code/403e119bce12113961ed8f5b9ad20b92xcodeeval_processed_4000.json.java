import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.lang.reflect.Array;
import java.util.function.BiFunction;
import java.util.function.Function;
import java.util.function.Supplier;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.function.IntFunction;
import java.io.PrintWriter;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.stream.Collectors;
import java.util.List;
import java.util.stream.Stream;
import java.util.Optional;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        id21 solver = new id21();
        solver.solve(1, in, out);
        out.close();
    }

    static class id21 {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.readInt();
            int q = in.readInt();

            TreeGraph tree = new TreeGraph(n);
            for (int i = 1; i < n; i++) {
                tree.id3(i, in.readInt() - 1);
            }

            id22 dfs = new id22(tree, 0, new id22.DepthMetric(), new id22.OrderMetric());
            int[] id26 = new int[n];
            Arrays.fill(id26, -1);

            ArrayList<Integer> order = dfs.order();
            for (int i = 0; i < order.size(); i++) {
                if (id26[order.get(i)] == -1) {
                    id26[order.get(i)] = i;
                }
            }

            id9 lcm = new id9(tree, 0);

            id28<IntPair> statFac = id28.newInstance(2);
            id28<IntPair> id7 = id28.newInstance(2, Comparator.<IntPair>reverseOrder());






            SegmentTree<IntPair> id1 = new SegmentTree<>(n, Utils::minObj);
            SegmentTree<IntPair> id5 = new SegmentTree<>(n, Utils::maxObj);

            SegmentTree<Integer> id27 = new SegmentTree<>(n, lcm::id31);

            int[] depth = dfs.depth();


            for (int i = 0; i < n; i++) {





                id1.set(i, new IntPair(id26[i], i));
                id5.set(i, new IntPair(id26[i], i));
                id27.set(i, i);
            }






















































            for (int i = 0; i < q; i++) {
                int from = in.readInt() - 1;
                int to = in.readInt() - 1;

                Function<Integer, Integer> calc = (remId) -> {
                    int id13 = remId > from ? id27.get(from, remId - 1) : -1;
                    int id19 = remId < to ? id27.get(remId + 1, to) : -1;
                    int id20;
                    if (id13 >= 0 && id19 >= 0) {
                        id20 = lcm.id31(id13, id19);
                    } else if (id13 >= 0) {
                        id20 = id13;
                    } else {
                        id20 = id19;
                    }
                    return id20;
                };

                int rem1 = id1.get(from, to).y();
                int rem2 = id5.get(from, to).y();
                int id13 = calc.apply(rem1);
                int id19 = calc.apply(rem2);

                int remId = depth[id13] <= depth[id19] ? rem2 : rem1;
                int id20 = depth[id13] <= depth[id19] ? id19 : id13;


                out.println((remId + 1) + " " + depth[id20]);
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

        public static <T> T[] id8(int n, IntFunction<T> creator) {
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
            return id8(n, value -> creator.get());
        }

        public static int id35(long x) {
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

    static class id22 {
        private TreeGraph graph;
        private Map<Class, id22.id15> metrics;

        public id22(TreeGraph graph, int startNode, id22.id15... requiredMetrics) {

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

        public <T extends id22.id15> T metric(Class<T> c) {
            return (T) metrics.get(c);
        }

        public ArrayList<Integer> order() {
            return metric(id22.OrderMetric.class).order;
        }

        public int[] depth() {
            return metric(id22.DepthMetric.class).depth;
        }

        public interface id15 {
            void init(int size);

            void onEnter(int node, int from, boolean firstTime);

            void onLeave(int node, int to);

        }

        public static class DepthMetric implements id22.id15 {
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

        public static class OrderMetric implements id22.id15 {
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

    static interface IRmq<T> {
        void set(int index, T value);

        T get(int from, int to);

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

        private T get(int id6, int id16, int id30, int from, int to) {
            if (from == id16 && to == id30)
                return (T) arr[id6];

            int middle = (id16 + id30) / 2;

            if (to <= middle) {
                return get(id6 * 2, id16, middle, from, to);
            }

            if (from > middle) {
                return get(id6 * 2 + 1, middle + 1, id30, from, to);
            }

            T leftSum = get(id6 * 2, id16, middle, from, middle);
            T rightSum = get(id6 * 2 + 1, middle + 1, id30, middle + 1, to);

            return ops.apply(leftSum, rightSum);
        }

    }

    static class id28<T> {
        protected Comparator<T> comparator;
        protected int size;

        protected id28(int size, Comparator<T> comparator) {
            this.comparator = Comparator.nullsLast(comparator);
            this.size = size;
        }

        public static <T> id28<T> newInstance(int size, Comparator<T> comparator) {
            return new id28<>(size, comparator);
        }

        public static <T extends Comparable<T>> id28<T> newInstance(int size) {
            return new id28<>(size, Comparator.<T>naturalOrder());
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

    static class SparseTable<T> implements IRmq<T> {
        private final BiFunction<T, T, T> ops;
        private final int n;
        private final Object[][] table;
        private final int log;

        public SparseTable(int n, BiFunction<T, T, T> ops) {
            this.n = n;
            this.ops = ops;
            this.log = Utils.id35(this.n);

            this.table = new Object[n][log];
        }

        public void set(int index, T value) {
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

    static class id9 {
        private TreeGraph graph;
        private int root;
        private int[] first;
        private IRmq<IntPair> id29;
        private int blockSize;
        private int blocksCount;
        private int[] id23;
        private int[][][] id24;
        private int[] depth;
        private ArrayList<Integer> order;

        public id9(TreeGraph graph, int root) {
            this.graph = graph;
            this.root = root;

            this.id0();
        }

        private void id0() {
            id22 dfs = new id22(graph, root, new id22.OrderMetric(), new id22.DepthMetric());

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

            id4(order, depth);
            buildMasks();
        }

        private void id4(ArrayList<Integer> order, int[] depth) {
            int n = order.size();
            blockSize = (Utils.id35(n) + 1) / 2;
            blocksCount = (n + blockSize - 1) / blockSize;

            id23 = new int[blocksCount];
            id29 = new SparseTable<>(blocksCount, Utils::minObj);

            for (int partI = 0; partI < blocksCount; partI++) {
                int index = partI * blockSize;
                int id17 = order.get(index++);
                int mask = 0;

                for (; index < (partI + 1) * blockSize; index++) {
                    if (index >= order.size()) {
                        mask = mask << 1;
                        continue;
                    }
                    int curIndex = order.get(index);
                    int prevIndex = order.get(index - 1);

                    mask = (mask << 1) | (depth[curIndex] < depth[prevIndex] ? 1 : 0);

                    if (depth[curIndex] < depth[id17]) {
                        id17 = curIndex;
                    }
                }

                id23[partI] = mask;
                id29.set(partI, new IntPair(depth[id17], id17));
            }
        }

        private void buildMasks() {
            id24 = new int[1 << blockSize][blockSize][blockSize];

            for (int mask = 0; mask < (1 << blockSize); mask++) {
                for (int i = 0; i < blockSize; i++) {
                    boolean id11 = (mask & (1 << i)) > 0;
                    int id25 = i;
                    int id32 = 0;
                    int heightCur = 0;

                    id24[mask][i][i] = i;

                    for (int j = i + 1; j < blockSize; j++) {
                        boolean id34 = (mask & (1 << (blockSize - 1 - j))) > 0;

                        heightCur = heightCur + (id34 ? -1 : 1);

                        if (heightCur < id32) {
                            id25 = j;
                            id32 = heightCur;
                        }

                        id24[mask][i][j] = id25;
                    }
                }
            }
        }

        public int id31(int a, int b) {
            int from = Math.min(first[a], first[b]);
            int to = Math.max(first[a], first[b]);

            int blockFirst = from / blockSize;
            int blockLast = to / blockSize;

            int id10 = from - blockFirst * blockSize;
            int id18 = to - blockLast * blockSize;

            List<IntPair> min = new ArrayList<>();

            if (blockFirst == blockLast) {
                min.add(id2(blockFirst, id10, id18));
            } else {
                min.add(id2(blockFirst, id10, blockSize - 1));
                min.add(id2(blockLast, 0, id18));

                int id12 = blockFirst + 1;
                int id14 = blockLast - 1;

                if (id12 <= id14) {
                    min.add(id29.get(id12, id14));
                }
            }

            return min.stream().reduce(Utils::minObj).get().y();
        }

        private IntPair id2(int blockId, int blockFrom, int blockTo) {
            int id33 = id24[id23[blockId]][blockFrom][blockTo];
            int indexGlobal = blockId * blockSize + id33;

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

