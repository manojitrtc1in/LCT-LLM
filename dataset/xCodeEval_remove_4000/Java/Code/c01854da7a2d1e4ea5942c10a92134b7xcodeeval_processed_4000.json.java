import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.lang.reflect.Array;
import java.util.function.BiFunction;
import java.util.InputMismatchException;
import java.util.function.Supplier;
import java.util.ArrayList;
import java.util.AbstractCollection;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
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
                tree.id3(i, in.readInt() - 1);
            }

            id6 lcm = new id6(tree, 0);

            int[] depth = lcm.depth;
            int[] id23 = lcm.first;


            

            


            IRmq<Integer> id28 = new SegmentTree<>(n, (a, b) -> {
                if (id23[a] == id23[b]) {
                    return a.compareTo(b) <= 0 ? a : b;
                }
                return id23[a] <= id23[b] ? a : b;
            });


            IRmq<Integer> id20 = new SegmentTree<>(n, (a, b) -> {
                if (id23[a] == id23[b]) {
                    return a.compareTo(b) <= 0 ? b : a;
                }
                return id23[a] <= id23[b] ? b : a;
            });


            for (int i = 0; i < n; i++) {
                id28.set(i, i);
                id20.set(i, i);
                

                

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

                

                

                int firstId = id28.get(from, to);
                int firstPos = id23[firstId];

                int lastId = id20.get(from, to);
                int lastPos = id23[lastId];


                

                

                


                

                id23[firstId] = Integer.MAX_VALUE;
                id28.set(firstId, firstId);

                int id24 = id28.get(from, to);
                int id12 = lcm.id26(id24, lastId);

                

                id23[firstId] = firstPos;
                id28.set(firstId, firstId);


                

                id23[lastId] = 0;
                id20.set(lastId, lastId);

                int id11 = id20.get(from, to);
                int id17 = lcm.id26(firstId, id11);

                

                id23[lastId] = lastPos;
                id20.set(lastId, lastId);


                if (depth[id12] >= depth[id17]) {
                    out.println((firstId + 1) + " " + depth[id12]);
                } else {
                    out.println((lastId + 1) + " " + depth[id17]);
                }
            }
        }

    }

    static class id6 {
        private TreeGraph graph;
        private int root;
        private IRmq<IntPair> id25;
        private int blockSize;
        private int[] id19;
        private int[][][] id21;
        public int[] first;
        public int[] depth;
        public ArrayList<Integer> order;

        public id6(TreeGraph graph, int root) {
            this.graph = graph;
            this.root = root;

            this.id0();
        }

        private void id0() {
            id18 dfs = new id18(graph, root, new id18.OrderMetric(), new id18.DepthMetric());

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

            id5(order, depth);
            buildMasks();
        }

        private void id5(ArrayList<Integer> order, int[] depth) {
            int n = order.size();
            blockSize = (Utils.id32(n) + 1) / 2;
            int blocksCount = (n + blockSize - 1) / blockSize;

            id19 = new int[blocksCount];
            id25 = new SparseTable<>(blocksCount, Utils::minObj);

            for (int partI = 0; partI < blocksCount; partI++) {
                int index = partI * blockSize;
                int id15 = order.get(index++);
                int mask = 0;

                for (; index < (partI + 1) * blockSize; index++) {
                    if (index >= order.size()) {
                        mask = mask << 1;
                        continue;
                    }
                    int curIndex = order.get(index);
                    int prevIndex = order.get(index - 1);

                    mask = (mask << 1) | (depth[curIndex] < depth[prevIndex] ? 1 : 0);

                    if (depth[curIndex] < depth[id15]) {
                        id15 = curIndex;
                    }
                }

                id19[partI] = mask;
                id25.set(partI, new IntPair(depth[id15], id15));
            }
        }

        private void buildMasks() {
            id21 = new int[1 << blockSize][blockSize][blockSize];

            for (int mask = 0; mask < (1 << blockSize); mask++) {
                for (int i = 0; i < blockSize; i++) {
                    boolean id9 = (mask & (1 << i)) > 0;
                    int id22 = i;
                    int id27 = 0;
                    int heightCur = 0;

                    id21[mask][i][i] = i;

                    for (int j = i + 1; j < blockSize; j++) {
                        boolean id31 = (mask & (1 << (blockSize - 1 - j))) > 0;

                        heightCur = heightCur + (id31 ? -1 : 1);

                        if (heightCur < id27) {
                            id22 = j;
                            id27 = heightCur;
                        }

                        id21[mask][i][j] = id22;
                    }
                }
            }
        }

        public int id26(int a, int b) {
            int from = Math.min(first[a], first[b]);
            int to = Math.max(first[a], first[b]);

            int blockFirst = from / blockSize;
            int blockLast = to / blockSize;

            int id8 = from - blockFirst * blockSize;
            int id16 = to - blockLast * blockSize;

            IntPair res = null;

            if (blockFirst == blockLast) {
                res = id2(blockFirst, id8, id16);
            } else {
                res = Utils.minObj(id2(blockFirst, id8, blockSize - 1), id2(blockLast, 0, id16));

                int id10 = blockFirst + 1;
                int id13 = blockLast - 1;

                if (id10 <= id13) {
                    res = Utils.minObj(res, id25.get(id10, id13));
                }
            }

            return res.y();
        }

        private IntPair id2(int blockId, int blockFrom, int blockTo) {
            int id30 = id21[id19[blockId]][blockFrom][blockTo];
            int indexGlobal = blockId * blockSize + id30;

            return new IntPair(depth[order.get(indexGlobal)], order.get(indexGlobal));
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
            this.log = Utils.id32(this.n);

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

    static class id18 {
        private TreeGraph graph;
        private Map<Class, id18.id14> metrics;

        public id18(TreeGraph graph, int startNode, id18.id14... requiredMetrics) {

            this.metrics = Stream.of(requiredMetrics).collect(Collectors.toMap(Object::getClass, o -> o));

            this.graph = graph;

            metrics.values().forEach(dfsMetric -> dfsMetric.init(graph.n));



            this.dfs2(startNode);
        }

        private void dfs2(int start) {
            LinkedList<id18.Visitor> stack = new LinkedList<>();
            stack.addFirst(new id18.Visitor(start, -1, true));

            while (!stack.isEmpty()) {
                id18.Visitor head = stack.pollFirst();
                int node = head.to;
                int from = head.from;

                if (head.leave) {
                    metrics.values().forEach(dfsMetric -> dfsMetric.onLeave(node, from));
                    continue;
                }

                metrics.values().forEach(dfsMetric -> dfsMetric.onEnter(node, from, head.firstTime));

                if (head.firstTime) {
                    stack.addFirst(new id18.Visitor(node, from, false, true));
                    for (int i = 0; i < graph.edges[node].size(); i++) {
                        int target = graph.edges[node].get(graph.edges[node].size() - 1 - i);
                        if (target != from) {
                            stack.addFirst(new id18.Visitor(node, target, false));
                            stack.addFirst(new id18.Visitor(target, node, true));
                        }
                    }
                }
            }
        }

        public <T extends id18.id14> T metric(Class<T> c) {
            return (T) metrics.get(c);
        }

        public ArrayList<Integer> order() {
            return metric(id18.OrderMetric.class).order;
        }

        public int[] depth() {
            return metric(id18.DepthMetric.class).depth;
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

        public interface id14 {
            void init(int size);

            void onEnter(int node, int from, boolean firstTime);

            void onLeave(int node, int to);

        }

        public static class DepthMetric implements id18.id14 {
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

        public static class OrderMetric implements id18.id14 {
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

        private void id1() {
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
                id1();
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

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id29 filter;

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
            while (id4(c)) {
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
            } while (!id4(c));
            return res * sgn;
        }

        public boolean id4(int c) {
            if (filter != null) {
                return filter.id4(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface id29 {
            public boolean id4(int ch);

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

    static final class Utils {
        private Utils() {
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

        public static int id32(long x) {
            int res = 1;
            long p = 1;
            while (p < x) {
                p *= 2;
                res++;
            }
            return res;
        }

    }
}

