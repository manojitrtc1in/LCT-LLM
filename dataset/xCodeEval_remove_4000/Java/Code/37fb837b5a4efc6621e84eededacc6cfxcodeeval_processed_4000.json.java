import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        final long mod = (long) (1e9 + 7);
        int n;
        int[] from;
        int[] to;
        int[] w;
        id7 gr;
        LCA lca;
        long[] cnt;
        long[] sumL;
        long[] id14;
        long[] cntUp;
        long[] id0;
        long[] id17;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.readInt();
            from = new int[n - 1];
            to = new int[n - 1];
            w = new int[n - 1];
            IOUtils.id12(in, from, to, w);
            MiscUtils.id9(from, to);
            gr = id7.id3(n, from, to, ArrayUtils.asLong(w));
            lca = new LCA(gr);

            cnt = new long[n];
            sumL = new long[n];
            id14 = new long[n];
            dfs(0, -1);

            cntUp = new long[n];
            id0 = new long[n];
            id17 = new long[n];
            dfsUp(0, -1);

            long[] dist = ShortestDistance.id22(gr, 0).first;
            int Q = in.readInt();
            for (int iter = 0; iter < Q; iter++) {
                int u = in.readInt() - 1;
                int v = in.readInt() - 1;
                int id19 = lca.id20(u, v);
                long d = dist[v] + dist[u] - 2 * dist[id19];
                d %= mod;

                long s0, s1;
                if (id19 == v) {
                    s1 = f(id0[v], id17[v], d, cntUp[v]);
                    s0 = id14[u] + id17[u] - s1;
                    s0 %= mod;


                } else {
                    s0 = id14[v] + 2 * d * sumL[v] % mod + d * d % mod * cnt[v] % mod;
                    s0 %= mod;
                    s1 = id14[u] + id17[u] - s0;


                }
                out.printLine(IntegerUtils.trueMod(s0 - s1, mod));
            }
        }

        long f(long sumL, long id14, long d, long cnt) {
            return (id14 + 2 * d % mod * sumL + d * d % mod * cnt % mod) % mod;
        }

        private void dfsUp(int v, int p) {
            for (int id = gr.firstOutbound(v); id != -1; id = gr.nextOutbound(id)) {
                int to = gr.destination(id);
                if (to == p) continue;

                cntUp[to] = cntUp[v] + cnt[v] - cnt[to];
                id0[to] = sumL[v] - (cnt[to] * gr.weight(id) % mod + sumL[to]) +
                        id0[v] +
                        cntUp[to] * gr.weight(id) % mod;
                id17[to] = f(id0[v], id17[v], gr.weight(id), cntUp[v]) +
                        f((sumL[v] - cnt[to] * gr.weight(id) % mod - sumL[to]) % mod,
                                (id14[v] - f(sumL[to], id14[to], gr.weight(id), cnt[to])) % mod,
                                gr.weight(id),
                                cnt[v] - cnt[to]);

                cntUp[to] %= mod;
                id0[to] %= mod;
                id17[to] %= mod;

                dfsUp(to, v);
            }

        }

        private void dfs(int v, int p) {
            cnt[v] = 1;
            for (int id = gr.firstOutbound(v); id != -1; id = gr.nextOutbound(id)) {
                int to = gr.destination(id);
                if (to == p) continue;
                dfs(to, v);
                cnt[v] += cnt[to];
                sumL[v] += cnt[to] * gr.weight(id) % mod + sumL[to];
                id14[v] += f(sumL[to], id14[to], gr.weight(id), cnt[to]);
            }
            cnt[v] %= mod;
            sumL[v] %= mod;
            id14[v] %= mod;
        }

    }

    static class Heap {
        private IntComparator comparator;
        private int size = 0;
        private int[] elements;
        private int[] at;

        public Heap(int maxElement) {
            this(10, maxElement);
        }

        public Heap(IntComparator comparator, int maxElement) {
            this(10, comparator, maxElement);
        }

        public Heap(int capacity, int maxElement) {
            this(capacity, IntComparator.DEFAULT, maxElement);
        }

        public Heap(int capacity, IntComparator comparator, int maxElement) {
            this.comparator = comparator;
            elements = new int[capacity];
            at = new int[maxElement];
            Arrays.fill(at, -1);
        }

        public boolean isEmpty() {
            return size == 0;
        }

        public int add(int element) {
            ensureCapacity(size + 1);
            elements[size] = element;
            at[element] = size;
            shiftUp(size++);
            return at[element];
        }

        public void shiftUp(int index) {




            int value = elements[index];
            while (index != 0) {
                int parent = (index - 1) >>> 1;
                int parentValue = elements[parent];
                if (comparator.compare(parentValue, value) <= 0) {
                    elements[index] = value;
                    at[value] = index;
                    return;
                }
                elements[index] = parentValue;
                at[parentValue] = index;
                index = parent;
            }
            elements[0] = value;
            at[value] = 0;
        }

        public void shiftDown(int index) {
            if (index < 0 || index >= size)
                throw new IllegalArgumentException();
            while (true) {
                int child = (index << 1) + 1;
                if (child >= size)
                    return;
                if (child + 1 < size && comparator.compare(elements[child], elements[child + 1]) > 0)
                    child++;
                if (comparator.compare(elements[index], elements[child]) <= 0)
                    return;
                swap(index, child);
                index = child;
            }
        }

        public int getIndex(int element) {
            return at[element];
        }

        private void swap(int first, int second) {
            int temp = elements[first];
            elements[first] = elements[second];
            elements[second] = temp;
            at[elements[first]] = first;
            at[elements[second]] = second;
        }

        private void ensureCapacity(int size) {
            if (elements.length < size) {
                int[] oldElements = elements;
                elements = new int[Math.max(2 * elements.length, size)];
                System.arraycopy(oldElements, 0, elements, 0, this.size);
            }
        }

        public int poll() {
            if (isEmpty())
                throw new IndexOutOfBoundsException();
            int result = elements[0];
            at[result] = -1;
            if (size == 1) {
                size = 0;
                return result;
            }
            elements[0] = elements[--size];
            at[elements[0]] = 0;
            shiftDown(0);
            return result;
        }

    }

    static class IntegerUtils {
        public static int longCompare(long a, long b) {
            if (a < b)
                return -1;
            if (a > b)
                return 1;
            return 0;
        }

        public static long trueMod(long a, long b) {
            a %= b;
            a += b;
            a %= b;
            return a;
        }

    }

    static class Pair<U, V> implements Comparable<Pair<U, V>> {
        public final U first;
        public final V second;

        public static <U, V> Pair<U, V> makePair(U first, V second) {
            return new Pair<U, V>(first, second);
        }

        private Pair(U first, V second) {
            this.first = first;
            this.second = second;
        }


        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Pair pair = (Pair) o;

            return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);

        }


        public int hashCode() {
            int result = first != null ? first.hashCode() : 0;
            result = 31 * result + (second != null ? second.hashCode() : 0);
            return result;
        }


        public String toString() {
            return "(" + first + "," + second + ")";
        }

        @SuppressWarnings({"unchecked"})
        public int compareTo(Pair<U, V> o) {
            int value = ((Comparable<U>) first).compareTo(o.first);
            if (value != 0)
                return value;
            return ((Comparable<V>) second).compareTo(o.second);
        }

    }

    static class IOUtils {
        public static void id12(InputReader in, int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++)
                    arrays[j][i] = in.readInt();
            }
        }

    }

    static class LCA {
        private final long[] order;
        private final int[] position;
        private final Graph graph;
        private final IntervalTree id18;
        private final int[] level;

        public LCA(Graph graph) {
            this(graph, 0);
        }

        public LCA(Graph graph, int root) {
            this.graph = graph;
            order = new long[2 * graph.vertexCount() - 1];
            position = new int[graph.vertexCount()];
            level = new int[graph.vertexCount()];
            int[] index = new int[graph.vertexCount()];
            for (int i = 0; i < index.length; i++)
                index[i] = graph.firstOutbound(i);
            int[] last = new int[graph.vertexCount()];
            int[] stack = new int[graph.vertexCount()];
            stack[0] = root;
            int size = 1;
            int j = 0;
            last[root] = -1;
            Arrays.fill(position, -1);
            while (size > 0) {
                int vertex = stack[--size];
                if (position[vertex] == -1)
                    position[vertex] = j;
                order[j++] = vertex;
                if (last[vertex] != -1)
                    level[vertex] = level[last[vertex]] + 1;
                while (index[vertex] != -1 && last[vertex] == graph.destination(index[vertex]))
                    index[vertex] = graph.nextOutbound(index[vertex]);
                if (index[vertex] != -1) {
                    stack[size++] = vertex;
                    stack[size++] = graph.destination(index[vertex]);
                    last[graph.destination(index[vertex])] = vertex;
                    index[vertex] = graph.nextOutbound(index[vertex]);
                }
            }
            id18 = new id11(order) {

                protected long joinValue(long left, long right) {
                    if (left == -1)
                        return right;
                    if (right == -1)
                        return left;
                    if (level[((int) left)] < level[((int) right)])
                        return left;
                    return right;
                }


                protected long neutralValue() {
                    return -1;
                }
            };
            id18.init();
        }

        public int id20(int first, int second) {
            return (int) id18.query(Math.min(position[first], position[second]), Math.max(position[first], position[second]));
        }

    }

    static class ShortestDistance {
        public static Pair<long[], int[]> id22(Graph graph, int source) {
            int vertexCount = graph.vertexCount();
            final long[] distance = new long[vertexCount];
            int[] last = new int[vertexCount];
            Arrays.fill(distance, Long.MAX_VALUE);
            Arrays.fill(last, -1);
            distance[source] = 0;
            if (graph.isSparse()) {
                Heap heap = new Heap(vertexCount, new IntComparator() {
                    public int compare(int first, int second) {
                        return IntegerUtils.longCompare(distance[first], distance[second]);
                    }
                }, vertexCount);
                heap.add(source);
                while (!heap.isEmpty()) {
                    int current = heap.poll();
                    int id = graph.firstOutbound(current);
                    while (id != -1) {
                        int next = graph.destination(id);
                        long total = graph.weight(id) + distance[current];
                        if (distance[next] > total) {
                            distance[next] = total;
                            if (heap.getIndex(next) == -1)
                                heap.add(next);
                            else
                                heap.shiftUp(heap.getIndex(next));
                            last[next] = id;
                        }
                        id = graph.nextOutbound(id);
                    }
                }
            } else {
                boolean[] visited = new boolean[vertexCount];
                for (int i = 0; i < vertexCount; i++) {
                    int index = -1;
                    long length = Long.MAX_VALUE;
                    for (int j = 0; j < vertexCount; j++) {
                        if (!visited[j] && distance[j] < length) {
                            length = distance[j];
                            index = j;
                        }
                    }
                    if (index == -1)
                        break;
                    visited[index] = true;
                    int id = graph.firstOutbound(index);
                    while (id != -1) {
                        int next = graph.destination(id);
                        if (!visited[next]) {
                            long total = graph.weight(id) + length;
                            if (distance[next] > total) {
                                distance[next] = total;
                                last[next] = id;
                            }
                        }
                        id = graph.nextOutbound(id);
                    }
                }
            }
            return Pair.makePair(distance, last);
        }

    }

    static abstract class id11 extends IntervalTree {
        protected long[] value;
        protected long[] array;

        protected id11(long[] array) {
            super(array.length, false);
            this.array = array;
            init();
        }


        protected void initData(int size, int nodeCount) {
            value = new long[nodeCount];
        }


        protected void initAfter(int root, int left, int right, int middle) {
            value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
        }


        protected void initBefore(int root, int left, int right, int middle) {
        }


        protected void initLeaf(int root, int index) {
            value[root] = array[index];
        }


        protected long id6(int root, int left, int right, int from, int to, int middle, long leftResult, long rightResult) {
            return joinValue(leftResult, rightResult);
        }


        protected void id8(int root, int left, int right, int from, int to, int middle) {
        }


        protected long queryFull(int root, int left, int right, int from, int to) {
            return value[root];
        }


        protected long id1() {
            return neutralValue();
        }

        protected abstract long neutralValue();

        protected abstract long joinValue(long left, long right);

    }

    static class id7 extends Graph {
        public int[] id4;

        public id7(int vertexCount) {
            this(vertexCount, vertexCount);
        }

        public id7(int vertexCount, int edgeCapacity) {
            super(vertexCount, 2 * edgeCapacity);
            id4 = new int[2 * edgeCapacity];
        }

        public static id7 id3(int vertexCount, int[] from, int[] to, long[] weight) {
            id7 graph = new id7(vertexCount, from.length);
            for (int i = 0; i < from.length; i++)
                graph.id2(from[i], to[i], weight[i]);
            return graph;
        }


        public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
            int id13 = edgeCount;
            super.addEdge(fromID, toID, weight, capacity, reverseEdge);
            super.addEdge(toID, fromID, weight, capacity, reverseEdge == -1 ? -1 : reverseEdge + 1);
            this.id4[id13] = id13 + 1;
            this.id4[id13 + 1] = id13;
            return id13;
        }


        protected int id15() {
            return 2;
        }


        protected void id16(int size) {
            if (size > edgeCapacity()) {
                super.id16(size);
                id4 = resize(id4, edgeCapacity());
            }
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id21 filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int readInt() {
            int c = read();
            while (id5(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id5(c));
            return res * sgn;
        }

        public boolean id5(int c) {
            if (filter != null)
                return filter.id5(c);
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface id21 {
            public boolean id5(int ch);

        }

    }

    static class MiscUtils {
        public static void id9(int[]... arrays) {
            for (int[] array : arrays) {
                for (int i = 0; i < array.length; i++)
                    array[i]--;
            }
        }

    }

    static abstract class IntervalTree {
        protected int size;

        protected IntervalTree(int size) {
            this(size, true);
        }

        public IntervalTree(int size, boolean shouldInit) {
            this.size = size;
            int nodeCount = Math.max(1, Integer.highestOneBit(size) << 2);
            initData(size, nodeCount);
            if (shouldInit)
                init();
        }

        protected abstract void initData(int size, int nodeCount);

        protected abstract void initAfter(int root, int left, int right, int middle);

        protected abstract void initBefore(int root, int left, int right, int middle);

        protected abstract void initLeaf(int root, int index);

        protected abstract long id6(int root, int left, int right, int from, int to, int middle, long leftResult, long rightResult);

        protected abstract void id8(int root, int left, int right, int from, int to, int middle);

        protected abstract long queryFull(int root, int left, int right, int from, int to);

        protected abstract long id1();

        public void init() {
            if (size == 0)
                return;
            init(0, 0, size - 1);
        }

        private void init(int root, int left, int right) {
            if (left == right) {
                initLeaf(root, left);
            } else {
                int middle = (left + right) >> 1;
                initBefore(root, left, right, middle);
                init(2 * root + 1, left, middle);
                init(2 * root + 2, middle + 1, right);
                initAfter(root, left, right, middle);
            }
        }

        public long query(int from, int to) {
            return query(0, 0, size - 1, from, to);
        }

        protected long query(int root, int left, int right, int from, int to) {
            if (left > to || right < from)
                return id1();
            if (left >= from && right <= to)
                return queryFull(root, left, right, from, to);
            int middle = (left + right) >> 1;
            id8(root, left, right, from, to, middle);
            long leftResult = query(2 * root + 1, left, middle, from, to);
            long rightResult = query(2 * root + 2, middle + 1, right, from, to);
            return id6(root, left, right, from, to, middle, leftResult, rightResult);
        }

    }

    static interface Edge {
    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void printLine(long i) {
            writer.println(i);
        }

    }

    static interface IntComparator {
        public static final IntComparator DEFAULT = new IntComparator() {
            public int compare(int first, int second) {
                if (first < second)
                    return -1;
                if (first > second)
                    return 1;
                return 0;
            }
        };

        public int compare(int first, int second);

    }

    static class Graph {
        public static final int id23 = 0;
        protected int vertexCount;
        protected int edgeCount;
        private int[] firstOutbound;
        private int[] firstInbound;
        private Edge[] edges;
        private int[] nextInbound;
        private int[] nextOutbound;
        private int[] from;
        private int[] to;
        private long[] weight;
        public long[] capacity;
        private int[] reverseEdge;
        private int[] flags;

        public Graph(int vertexCount) {
            this(vertexCount, vertexCount);
        }

        public Graph(int vertexCount, int edgeCapacity) {
            this.vertexCount = vertexCount;
            firstOutbound = new int[vertexCount];
            Arrays.fill(firstOutbound, -1);

            from = new int[edgeCapacity];
            to = new int[edgeCapacity];
            nextOutbound = new int[edgeCapacity];
            flags = new int[edgeCapacity];
        }

        public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
            id16(edgeCount + 1);
            if (firstOutbound[fromID] != -1)
                nextOutbound[edgeCount] = firstOutbound[fromID];
            else
                nextOutbound[edgeCount] = -1;
            firstOutbound[fromID] = edgeCount;
            if (firstInbound != null) {
                if (firstInbound[toID] != -1)
                    nextInbound[edgeCount] = firstInbound[toID];
                else
                    nextInbound[edgeCount] = -1;
                firstInbound[toID] = edgeCount;
            }
            this.from[edgeCount] = fromID;
            this.to[edgeCount] = toID;
            if (capacity != 0) {
                if (this.capacity == null)
                    this.capacity = new long[from.length];
                this.capacity[edgeCount] = capacity;
            }
            if (weight != 0) {
                if (this.weight == null)
                    this.weight = new long[from.length];
                this.weight[edgeCount] = weight;
            }
            if (reverseEdge != -1) {
                if (this.reverseEdge == null) {
                    this.reverseEdge = new int[from.length];
                    Arrays.fill(this.reverseEdge, 0, edgeCount, -1);
                }
                this.reverseEdge[edgeCount] = reverseEdge;
            }
            if (edges != null)
                edges[edgeCount] = createEdge(edgeCount);
            return edgeCount++;
        }

        protected final Graph.GraphEdge createEdge(int id) {
            return new Graph.GraphEdge(id);
        }

        public final int id10(int from, int to, long weight, long capacity) {
            if (capacity == 0) {
                return addEdge(from, to, weight, 0, -1);
            } else {
                int id13 = edgeCount;
                addEdge(to, from, -weight, 0, id13 + id15());
                return addEdge(from, to, weight, capacity, id13);
            }
        }

        protected int id15() {
            return 1;
        }

        public final int id2(int from, int to, long weight) {
            return id10(from, to, weight, 0);
        }

        public final int vertexCount() {
            return vertexCount;
        }

        protected final int edgeCapacity() {
            return from.length;
        }

        public final int firstOutbound(int vertex) {
            int id = firstOutbound[vertex];
            while (id != -1 && isRemoved(id))
                id = nextOutbound[id];
            return id;
        }

        public final int nextOutbound(int id) {
            id = nextOutbound[id];
            while (id != -1 && isRemoved(id))
                id = nextOutbound[id];
            return id;
        }

        public final int destination(int id) {
            return to[id];
        }

        public final long weight(int id) {
            if (weight == null)
                return 0;
            return weight[id];
        }

        public final boolean flag(int id, int bit) {
            return (flags[id] >> bit & 1) != 0;
        }

        public final boolean isRemoved(int id) {
            return flag(id, id23);
        }

        protected void id16(int size) {
            if (from.length < size) {
                int newSize = Math.max(size, 2 * from.length);
                if (edges != null)
                    edges = resize(edges, newSize);
                from = resize(from, newSize);
                to = resize(to, newSize);
                nextOutbound = resize(nextOutbound, newSize);
                if (nextInbound != null)
                    nextInbound = resize(nextInbound, newSize);
                if (weight != null)
                    weight = resize(weight, newSize);
                if (capacity != null)
                    capacity = resize(capacity, newSize);
                if (reverseEdge != null)
                    reverseEdge = resize(reverseEdge, newSize);
                flags = resize(flags, newSize);
            }
        }

        protected final int[] resize(int[] array, int size) {
            int[] newArray = new int[size];
            System.arraycopy(array, 0, newArray, 0, array.length);
            return newArray;
        }

        private long[] resize(long[] array, int size) {
            long[] newArray = new long[size];
            System.arraycopy(array, 0, newArray, 0, array.length);
            return newArray;
        }

        private Edge[] resize(Edge[] array, int size) {
            Edge[] newArray = new Edge[size];
            System.arraycopy(array, 0, newArray, 0, array.length);
            return newArray;
        }

        public final boolean isSparse() {
            return vertexCount == 0 || edgeCount * 20 / vertexCount <= vertexCount;
        }

        protected class GraphEdge implements Edge {
            protected int id;

            protected GraphEdge(int id) {
                this.id = id;
            }

        }

    }

    static class ArrayUtils {
        public static long[] asLong(int[] array) {
            long[] result = new long[array.length];
            for (int i = 0; i < array.length; i++)
                result[i] = array[i];
            return result;
        }

    }
}
