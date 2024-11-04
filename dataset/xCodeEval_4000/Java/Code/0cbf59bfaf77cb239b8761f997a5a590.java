import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.lang.reflect.Array;
import java.util.function.BiFunction;
import java.util.InputMismatchException;
import java.util.function.Supplier;
import java.util.ArrayList;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.util.function.IntFunction;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.stream.Collectors;
import java.util.stream.Stream;
import java.io.Writer;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int q = in.readInt();

            TreeGraph tree = new TreeGraph(n);
            for (int i = 1; i < n; i++) {
                tree.addEdgeBi(i, in.readInt() - 1);
            }

            TreeLcmFast lcm = new TreeLcmFast(tree, 0);

            int[] depth = lcm.depth;
            int[] firstInOrder = lcm.first;


            

            


            IRmq<Integer> segForFirst2 = new SegmentTree<>(n, (a, b) -> {
                if (firstInOrder[a] == firstInOrder[b]) {
                    return a.compareTo(b) <= 0 ? a : b;
                }
                return firstInOrder[a] <= firstInOrder[b] ? a : b;
            });


            IRmq<Integer> segForLast2 = new SegmentTree<>(n, (a, b) -> {
                if (firstInOrder[a] == firstInOrder[b]) {
                    return a.compareTo(b) <= 0 ? b : a;
                }
                return firstInOrder[a] <= firstInOrder[b] ? b : a;
            });


            for (int i = 0; i < n; i++) {
                segForFirst2.set(i, i);
                segForLast2.set(i, i);
                

                

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

                

                

                int firstId = segForFirst2.get(from, to);
                int firstPos = firstInOrder[firstId];

                int lastId = segForLast2.get(from, to);
                int lastPos = firstInOrder[lastId];


                

                

                


                

                firstInOrder[firstId] = Integer.MAX_VALUE;
                segForFirst2.set(firstId, firstId);

                int firstWithoutFirstId = segForFirst2.get(from, to);
                int lcm1 = lcm.getLcm(firstWithoutFirstId, lastId);

                

                firstInOrder[firstId] = firstPos;
                segForFirst2.set(firstId, firstId);


                

                firstInOrder[lastId] = 0;
                segForLast2.set(lastId, lastId);

                int lastWithoutLastId = segForLast2.get(from, to);
                int lcm2 = lcm.getLcm(firstId, lastWithoutLastId);

                

                firstInOrder[lastId] = lastPos;
                segForLast2.set(lastId, lastId);


                if (depth[lcm1] >= depth[lcm2]) {
                    out.println((firstId + 1) + " " + depth[lcm1]);
                } else {
                    out.println((lastId + 1) + " " + depth[lcm2]);
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

    static class TreeLcmFast {
        private TreeGraph graph;
        private int root;
        private IRmq<IntPair> sparseTable;
        private int blockSize;
        private int[] blockId2mask;
        private int[][][] mask2minIndex;
        public int[] first;
        public int[] depth;
        public ArrayList<Integer> order;

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
            int blocksCount = (n + blockSize - 1) / blockSize;

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

            IntPair res = null;

            if (blockFirst == blockLast) {
                res = getInBlock(blockFirst, blockFirstFrom, blockLastTo);
            } else {
                res = Utils.minObj(getInBlock(blockFirst, blockFirstFrom, blockSize - 1), getInBlock(blockLast, 0, blockLastTo));

                int blockFirstNext = blockFirst + 1;
                int blockLastBefore = blockLast - 1;

                if (blockFirstNext <= blockLastBefore) {
                    res = Utils.minObj(res, sparseTable.get(blockFirstNext, blockLastBefore));
                }
            }

            return res.y();
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

    static class GraphDfs {
        private TreeGraph graph;
        private Map<Class, GraphDfs.DfsMetric> metrics;
        private GraphDfs.DfsMetric[] metricList;

        public GraphDfs(TreeGraph graph, int startNode, GraphDfs.DfsMetric... requiredMetrics) {

            this.metrics = Stream.of(requiredMetrics).collect(Collectors.toMap(Object::getClass, o -> o));
            this.metricList = requiredMetrics;

            this.graph = graph;

            metrics.values().forEach(dfsMetric -> dfsMetric.init(graph.n));



            this.dfs2(startNode);
        }

        private void dfs2(int start) {
            FastStack<GraphDfs.Visitor> stack = new FastStack<>(graph.n);
            stack.addFirst(new GraphDfs.Visitor(start, -1, true));

            while (!stack.isEmpty()) {
                GraphDfs.Visitor head = stack.pollFirst();
                int node = head.to;
                int from = head.from;

                if (head.leave) {
                    for (GraphDfs.DfsMetric metric : metricList) {
                        metric.onLeave(node, from);
                    }
                    continue;
                }

                for (GraphDfs.DfsMetric metric : metricList) {
                    metric.onEnter(node, from, head.firstTime);
                }

                if (head.firstTime) {
                    stack.addFirst(new GraphDfs.Visitor(node, from, false, true));
                    for (int i = 0; i < graph.edges[node].size(); i++) {
                        int target = graph.edges[node].get(graph.edges[node].size() - 1 - i);
                        if (target != from) {
                            stack.addFirst(new GraphDfs.Visitor(node, target, false));
                            stack.addFirst(new GraphDfs.Visitor(target, node, true));
                        }
                    }
                }
            }
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

        private static class Visitor {
            int from;
            int to;
            boolean firstTime;
            boolean leave;

            Visitor(int to, int from, boolean firstTime) {
                this.from = from;
                this.to = to;
                this.firstTime = firstTime;
            }

            Visitor(int to, int from, boolean firstTime, boolean leave) {
                this.from = from;
                this.to = to;
                this.firstTime = firstTime;
                this.leave = leave;
            }

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

        private void refreshTree2() {
            for (int i = n - 1; i >= 1; i--) {
                arr[i] = doSum((T) arr[2 * i], (T) arr[2 * i + 1]);
            }
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
                refreshTree2();
            }

            return get2(from, to + 1);
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

        private T get2(int from, int to) {
            T value = null;
            from += n;
            to += n;
            while (from < to) {
                if (from % 2 == 1) {
                    value = doSum(value, (T) arr[from++]);
                }
                if (to % 2 == 1) {
                    value = doSum(value, (T) arr[--to]);
                }
                from /= 2;
                to /= 2;
            }
            return value;
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int readInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static interface IRmq<T> {
        void set(int index, T value);

        T get(int from, int to);

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

    static class FastStack<T> {
        private ArrayList<T> stack;

        public FastStack(int n) {
            stack = new ArrayList<>(n);
        }

        public void addFirst(T val) {
            push(val);
        }

        public T pollFirst() {
            return pool();
        }

        public void push(T val) {
            stack.add(val);
        }

        public T peek() {
            return stack.size() > 0 ? stack.get(stack.size() - 1) : null;
        }

        public T pool() {
            T var = peek();
            stack.remove(stack.size() - 1);
            return var;
        }

        public boolean isEmpty() {
            return stack.isEmpty();
        }

    }
}

