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
        EKompaniya solver = new EKompaniya();
        solver.solve(1, in, out);
        out.close();
    }

    static class EKompaniya {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.readInt();
            int q = in.readInt();

            TreeGraph tree = new TreeGraph(n);
            for (int i = 1; i < n; i++) {
                tree.addEdgeBi(i, in.readInt() - 1);
            }

            GraphDfs dfs = new GraphDfs(tree, 0, new GraphDfs.DepthMetric(), new GraphDfs.OrderMetric());
            int[] firstInOrder = new int[n];
            Arrays.fill(firstInOrder, -1);

            ArrayList<Integer> order = dfs.order();
            for (int i = 0; i < order.size(); i++) {
                if (firstInOrder[order.get(i)] == -1) {
                    firstInOrder[order.get(i)] = i;
                }
            }

            TreeLcmFast lcm = new TreeLcmFast(tree, 0);

            KthStatisticFactory<IntPair> statFac = KthStatisticFactory.newInstance(2);
            KthStatisticFactory<IntPair> statFacRev = KthStatisticFactory.newInstance(2, Comparator.<IntPair>reverseOrder());

            SegmentTree<KthStatisticArray<IntPair>> segForFirst = new SegmentTree<>(n, KthStatisticArray::merge);
            SegmentTree<KthStatisticArray<IntPair>> segForLast = new SegmentTree<>(n, KthStatisticArray::merge);

            


            int[] depth = dfs.depth();


            for (int i = 0; i < n; i++) {
                segForFirst.set(i, statFac.getStat(new IntPair(firstInOrder[i], i)));
                segForLast.set(i, statFacRev.getStat(new IntPair(firstInOrder[i], i)));
                

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

                KthStatisticArray<IntPair> first = segForFirst.get(from, to);
                KthStatisticArray<IntPair> last = segForLast.get(from, to);

                int lcm1 = lcm.getLcm(first.get(1).y(), last.get(0).y());
                int lcm2 = lcm.getLcm(first.get(0).y(), last.get(1).y());

                if (depth[lcm1] >= depth[lcm2]) {
                    out.println((first.get(0).y() + 1) + " " + depth[lcm1]);
                } else {
                    out.println((last.get(0).y() + 1) + " " + depth[lcm2]);
                }
            }



























































        }

    }

    static final class Utils {
        private Utils() {
        }

        public static <T extends Comparable<T>> T minObj(T a, T b) {
            return a.compareTo(b) <= 0 ? a : b;
        }

        public static <T> T[] makeArrayInd(int n, IntFunction<T> creator) {
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
            return makeArrayInd(n, value -> creator.get());
        }

        public static int log2ceil(long x) {
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

    static class GraphDfs {
        private TreeGraph graph;
        private Map<Class, GraphDfs.DfsMetric> metrics;

        public GraphDfs(TreeGraph graph, int startNode, GraphDfs.DfsMetric... requiredMetrics) {

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

        public <T extends GraphDfs.DfsMetric> T metric(Class<T> c) {
            return (T) metrics.get(c);
        }

        public ArrayList<Integer> order() {
            return metric(GraphDfs.OrderMetric.class).order;
        }

        public int[] depth() {
            return metric(GraphDfs.DepthMetric.class).depth;
        }

        public interface DfsMetric {
            void init(int size);

            void onEnter(int node, int from, boolean firstTime);

            void onLeave(int node, int to);

        }

        public static class DepthMetric implements GraphDfs.DfsMetric {
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

        public static class OrderMetric implements GraphDfs.DfsMetric {
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

    static interface IKthStatistic<T> {
    }

    static interface IRmq<T> {
        void set(int index, T value);

        T get(int from, int to);

    }

    static class KthStatisticArray<T> implements IKthStatistic<T> {
        private Object[] stats;
        private KthStatisticFactory<T> factory;

        protected KthStatisticArray(KthStatisticFactory<T> factory, Object[] vals) {
            this.factory = factory;
            stats = new Object[2];

            stats[0] = vals[0];
            if (vals.length > 1) {
                stats[1] = vals[1];
            }
        }

        public void addValue(T a) {
            if (a == null) return;

            if (stats[0] == null || factory.comparator.compare(a, (T) stats[0]) <= 0) {
                stats[1] = stats[0];
                stats[0] = a;
            } else if (stats[1] == null || factory.comparator.compare(a, (T) stats[1]) <= 0) {
                stats[1] = a;
            }
        }

        public T get(int index) {
            return (T) stats[index];
        }

        static public <U> KthStatisticArray<U> merge(KthStatisticArray<U> a, KthStatisticArray<U> b) {
            if (a.factory != b.factory) {
                throw new RuntimeException();
            }

            KthStatisticArray<U> res = new KthStatisticArray<U>(a.factory, a.stats);
            for (Object stat : b.stats) {
                res.addValue((U) stat);
            }

            return res;
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

        private T get(int subTreeRoot, int subTreeFrom, int subTreeTo, int from, int to) {
            if (from == subTreeFrom && to == subTreeTo)
                return (T) arr[subTreeRoot];

            int middle = (subTreeFrom + subTreeTo) / 2;

            if (to <= middle) {
                return get(subTreeRoot * 2, subTreeFrom, middle, from, to);
            }

            if (from > middle) {
                return get(subTreeRoot * 2 + 1, middle + 1, subTreeTo, from, to);
            }

            T leftSum = get(subTreeRoot * 2, subTreeFrom, middle, from, middle);
            T rightSum = get(subTreeRoot * 2 + 1, middle + 1, subTreeTo, middle + 1, to);

            return ops.apply(leftSum, rightSum);
        }

    }

    static class KthStatisticFactory<T> {
        protected Comparator<T> comparator;
        protected int size;

        protected KthStatisticFactory(int size, Comparator<T> comparator) {
            this.comparator = Comparator.nullsLast(comparator);
            this.size = size;
        }

        public KthStatisticArray<T> getStat(T... vals) {
            return new KthStatisticArray<>(this, vals);
        }

        public static <T> KthStatisticFactory<T> newInstance(int size, Comparator<T> comparator) {
            return new KthStatisticFactory<>(size, comparator);
        }

        public static <T extends Comparable<T>> KthStatisticFactory<T> newInstance(int size) {
            return new KthStatisticFactory<>(size, Comparator.<T>naturalOrder());
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

        public void addEdgeBi(int a, int b) {
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
            this.log = Utils.log2ceil(this.n);

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

    static class TreeLcmFast {
        private TreeGraph graph;
        private int root;
        private int[] first;
        private IRmq<IntPair> sparseTable;
        private int blockSize;
        private int blocksCount;
        private int[] blockId2mask;
        private int[][][] mask2minIndex;
        private int[] depth;
        private ArrayList<Integer> order;

        public TreeLcmFast(TreeGraph graph, int root) {
            this.graph = graph;
            this.root = root;

            this.buildLcm();
        }

        private void buildLcm() {
            GraphDfs dfs = new GraphDfs(graph, root, new GraphDfs.OrderMetric(), new GraphDfs.DepthMetric());

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

            buildSparseTable(order, depth);
            buildMasks();
        }

        private void buildSparseTable(ArrayList<Integer> order, int[] depth) {
            int n = order.size();
            blockSize = (Utils.log2ceil(n) + 1) / 2;
            blocksCount = (n + blockSize - 1) / blockSize;

            blockId2mask = new int[blocksCount];
            sparseTable = new SparseTable<>(blocksCount, Utils::minObj);

            for (int partI = 0; partI < blocksCount; partI++) {
                int index = partI * blockSize;
                int minDepthIndex = order.get(index++);
                int mask = 0;

                for (; index < (partI + 1) * blockSize; index++) {
                    if (index >= order.size()) {
                        mask = mask << 1;
                        continue;
                    }
                    int curIndex = order.get(index);
                    int prevIndex = order.get(index - 1);

                    mask = (mask << 1) | (depth[curIndex] < depth[prevIndex] ? 1 : 0);

                    if (depth[curIndex] < depth[minDepthIndex]) {
                        minDepthIndex = curIndex;
                    }
                }

                blockId2mask[partI] = mask;
                sparseTable.set(partI, new IntPair(depth[minDepthIndex], minDepthIndex));
            }
        }

        private void buildMasks() {
            mask2minIndex = new int[1 << blockSize][blockSize][blockSize];

            for (int mask = 0; mask < (1 << blockSize); mask++) {
                for (int i = 0; i < blockSize; i++) {
                    boolean bitAtI = (mask & (1 << i)) > 0;
                    int minHeightAt = i;
                    int minHeightVal = 0;
                    int heightCur = 0;

                    mask2minIndex[mask][i][i] = i;

                    for (int j = i + 1; j < blockSize; j++) {
                        boolean bitAtJ = (mask & (1 << (blockSize - 1 - j))) > 0;

                        heightCur = heightCur + (bitAtJ ? -1 : 1);

                        if (heightCur < minHeightVal) {
                            minHeightAt = j;
                            minHeightVal = heightCur;
                        }

                        mask2minIndex[mask][i][j] = minHeightAt;
                    }
                }
            }
        }

        public int getLcm(int a, int b) {
            int from = Math.min(first[a], first[b]);
            int to = Math.max(first[a], first[b]);

            int blockFirst = from / blockSize;
            int blockLast = to / blockSize;

            int blockFirstFrom = from - blockFirst * blockSize;
            int blockLastTo = to - blockLast * blockSize;

            List<IntPair> min = new ArrayList<>();

            if (blockFirst == blockLast) {
                min.add(getInBlock(blockFirst, blockFirstFrom, blockLastTo));
            } else {
                min.add(getInBlock(blockFirst, blockFirstFrom, blockSize - 1));
                min.add(getInBlock(blockLast, 0, blockLastTo));

                int blockFirstNext = blockFirst + 1;
                int blockLastBefore = blockLast - 1;

                if (blockFirstNext <= blockLastBefore) {
                    min.add(sparseTable.get(blockFirstNext, blockLastBefore));
                }
            }

            return min.stream().reduce(Utils::minObj).get().y();
        }

        private IntPair getInBlock(int blockId, int blockFrom, int blockTo) {
            int indexInBlock = mask2minIndex[blockId2mask[blockId]][blockFrom][blockTo];
            int indexGlobal = blockId * blockSize + indexInBlock;

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

