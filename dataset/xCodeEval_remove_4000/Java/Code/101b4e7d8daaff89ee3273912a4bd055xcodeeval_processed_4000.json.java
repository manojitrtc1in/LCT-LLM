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
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int[] aa = new int[n - 1], bb = new int[n - 1];
            IOUtils.id12(in, aa, bb);
            MiscUtils.id8(aa, bb);
            id6 graph = id6.createGraph(n, aa, bb);
            DFSOrder dfsOrder = new DFSOrder(graph);
            MaxHard fill = new MaxHard(n);
            MaxHard empty = new MaxHard(n);
            int numQueries = in.readInt();
            for (int query = 0; query < numQueries; query++) {
                int type = in.readInt();
                int v = in.readInt() - 1;
                if (type == 1) {
                    fill.update(dfsOrder.position[v], dfsOrder.end[v], query);
                } else if (type == 2) {
                    empty.update(dfsOrder.position[v], dfsOrder.position[v], query);
                } else if (type == 3) {
                    int fillTime = fill.query(dfsOrder.position[v], dfsOrder.position[v]);
                    int emptyTime = empty.query(dfsOrder.position[v], dfsOrder.end[v]);
                    out.printLine(emptyTime >= fillTime ? 0 : 1);
                } else throw new RuntimeException();
            }
        }

        public abstract class IntervalTree {
            protected int size;

            protected IntervalTree(int size) {
                this(size, true);
            }

            public IntervalTree(int size, boolean shouldInit) {
                this.size = size;
                int nodeCount = Math.max(1, Integer.highestOneBit(size) << 2);
                initData(size, nodeCount);
                if (shouldInit) {
                    init();
                }
            }

            protected abstract void initData(int size, int nodeCount);
            protected abstract void initAfter(int root, int left, int right, int middle);
            protected abstract void initBefore(int root, int left, int right, int middle);
            protected abstract void initLeaf(int root, int index);
            protected abstract void id3(int root, int left, int right, int from, int to, int delta, int middle);
            protected abstract void id10(int root, int left, int right, int from, int to, int delta, int middle);
            protected abstract void updateFull(int root, int left, int right, int from, int to, int delta);
            protected abstract int id5(int root, int left, int right, int from, int to, int middle,
                                                    int leftResult, int rightResult);
            protected abstract void id7(int root, int left, int right, int from, int to, int middle);
            protected abstract int queryFull(int root, int left, int right, int from, int to);
            protected abstract int id0();

            public void init() {
                if (size == 0) {
                    return;
                }
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

            public void update(int from, int to, int delta) {
                update(0, 0, size - 1, from, to, delta);
            }

            protected void update(int root, int left, int right, int from, int to, int delta) {
                if (left > to || right < from) {
                    return;
                }
                if (left >= from && right <= to) {
                    updateFull(root, left, right, from, to, delta);
                    return;
                }
                int middle = (left + right) >> 1;
                id10(root, left, right, from, to, delta, middle);
                update(2 * root + 1, left, middle, from, to, delta);
                update(2 * root + 2, middle + 1, right, from, to, delta);
                id3(root, left, right, from, to, delta, middle);
            }

            public int query(int from, int to) {
                return query(0, 0, size - 1, from, to);
            }

            protected int query(int root, int left, int right, int from, int to) {
                if (left > to || right < from) {
                    return id0();
                }
                if (left >= from && right <= to) {
                    return queryFull(root, left, right, from, to);
                }
                int middle = (left + right) >> 1;
                id7(root, left, right, from, to, middle);
                int leftResult = query(2 * root + 1, left, middle, from, to);
                int rightResult = query(2 * root + 2, middle + 1, right, from, to);
                return id5(root, left, right, from, to, middle, leftResult, rightResult);
            }
        }
        public abstract class id11 extends IntervalTree {
            protected int[] value;
            protected int[] delta;

            protected id11(int size) {
                this(size, true);
            }

            public id11(int size, boolean shouldInit) {
                super(size, shouldInit);
            }

            protected void initData(int size, int nodeCount) {
                value = new int[nodeCount];
                delta = new int[nodeCount];
            }

            protected abstract int joinValue(int left, int right);
            protected abstract int joinDelta(int was, int delta);
            protected abstract int accumulate(int value, int delta, int length);
            protected abstract int neutralValue();
            protected abstract int neutralDelta();

            protected int initValue(int index) {
                return neutralValue();
            }

            protected void initAfter(int root, int left, int right, int middle) {
                value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
                delta[root] = neutralDelta();
            }

            protected void initBefore(int root, int left, int right, int middle) {
            }

            protected void initLeaf(int root, int index) {
                value[root] = initValue(index);
                delta[root] = neutralDelta();
            }

            protected void id3(int root, int left, int right, int from, int to, int delta, int middle) {
                value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
            }

            protected void id10(int root, int left, int right, int from, int to, int delta, int middle) {
                pushDown(root, left, middle, right);
            }

            protected void pushDown(int root, int left, int middle, int right) {
                value[2 * root + 1] = accumulate(value[2 * root + 1], delta[root], middle - left + 1);
                value[2 * root + 2] = accumulate(value[2 * root + 2], delta[root], right - middle);
                delta[2 * root + 1] = joinDelta(delta[2 * root + 1], delta[root]);
                delta[2 * root + 2] = joinDelta(delta[2 * root + 2], delta[root]);
                delta[root] = neutralDelta();
            }

            protected void updateFull(int root, int left, int right, int from, int to, int delta) {
                value[root] = accumulate(value[root], delta, right - left + 1);
                this.delta[root] = joinDelta(this.delta[root], delta);
            }

            protected int id5(int root, int left, int right, int from, int to, int middle, int leftResult,
                                           int rightResult) {
                return joinValue(leftResult, rightResult);
            }

            protected void id7(int root, int left, int right, int from, int to, int middle) {
                pushDown(root, left, middle, right);
            }

            protected int queryFull(int root, int left, int right, int from, int to) {
                return value[root];
            }

            protected int id0() {
                return neutralValue();
            }
        }
        public class MaxHard extends id11 {
            int[] array;

            public MaxHard(int size) {
                super(size);
                array = null;
            }

            public MaxHard(int[] array) {
                super(array.length, false);
                this.array = array;
                init();
            }

            protected int joinValue(int left, int right) {
                return Math.max(left, right);
            }

            protected int joinDelta(int was, int delta) {
                return delta == neutralDelta() ? was : delta;
            }

            protected int accumulate(int value, int delta, int length) {
                return delta == neutralDelta() ? value : delta;
            }

            protected int neutralValue() {
                return Integer.MIN_VALUE;
            }

            protected int neutralDelta() {
                return Integer.MIN_VALUE;
            }

            protected int initValue(int index) {
                if (array == null) return Integer.MIN_VALUE;
                return array[index];
            }
        }
    }
    static class DFSOrder {
        public final int[] position;
        public final int[] end;

        public DFSOrder(Graph graph) {
            this(graph, 0);
        }

        public DFSOrder(Graph graph, int root) {
            int count = graph.vertexCount();
            position = new int[count];
            end = new int[count];
            int[] edge = new int[count];
            int[] stack = new int[count];
            for (int i = 0; i < count; i++) {
                edge[i] = graph.firstOutbound(i);
            }
            stack[0] = root;
            int size = 1;
            position[root] = 0;
            int index = 0;
            while (size > 0) {
                int current = stack[size - 1];
                if (edge[current] == -1) {
                    end[current] = index;
                    size--;
                } else {
                    int next = graph.destination(edge[current]);
                    edge[current] = graph.nextOutbound(edge[current]);
                    position[next] = ++index;
                    stack[size++] = next;
                }
            }
        }

        public DFSOrder(id6 graph) {
            this(graph, 0);
        }

        public DFSOrder(id6 graph, int root) {
            int count = graph.vertexCount();
            position = new int[count];
            end = new int[count];
            int[] edge = new int[count];
            int[] stack = new int[count];
            int[] last = new int[count];
            for (int i = 0; i < count; i++) {
                edge[i] = graph.firstOutbound(i);
            }
            stack[0] = root;
            last[root] = -1;
            int size = 1;
            position[root] = 0;
            int index = 0;
            while (size > 0) {
                int current = stack[size - 1];
                if (edge[current] == -1) {
                    end[current] = index;
                    size--;
                } else {
                    int next = graph.destination(edge[current]);
                    if (next == last[current]) {
                        edge[current] = graph.nextOutbound(edge[current]);
                        continue;
                    }
                    edge[current] = graph.nextOutbound(edge[current]);
                    position[next] = ++index;
                    last[next] = current;
                    stack[size++] = next;
                }
            }
        }
    }
    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id17 filter;

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

        public interface id17 {
            public boolean id4(int ch);
        }
    }
    static interface Edge {
    }
    static class IOUtils {
        public static void id12(InputReader in, int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = in.readInt();
                }
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

        public void close() {
            writer.close();
        }

        public void printLine(int i) {
            writer.println(i);
        }
    }
    static class Graph {
        public static final int id18 = 0;
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
            id15(edgeCount + 1);
            if (firstOutbound[fromID] != -1) {
                nextOutbound[edgeCount] = firstOutbound[fromID];
            } else {
                nextOutbound[edgeCount] = -1;
            }
            firstOutbound[fromID] = edgeCount;
            if (firstInbound != null) {
                if (firstInbound[toID] != -1) {
                    nextInbound[edgeCount] = firstInbound[toID];
                } else {
                    nextInbound[edgeCount] = -1;
                }
                firstInbound[toID] = edgeCount;
            }
            this.from[edgeCount] = fromID;
            this.to[edgeCount] = toID;
            if (capacity != 0) {
                if (this.capacity == null) {
                    this.capacity = new long[from.length];
                }
                this.capacity[edgeCount] = capacity;
            }
            if (weight != 0) {
                if (this.weight == null) {
                    this.weight = new long[from.length];
                }
                this.weight[edgeCount] = weight;
            }
            if (reverseEdge != -1) {
                if (this.reverseEdge == null) {
                    this.reverseEdge = new int[from.length];
                    Arrays.fill(this.reverseEdge, 0, edgeCount, -1);
                }
                this.reverseEdge[edgeCount] = reverseEdge;
            }
            if (edges != null) {
                edges[edgeCount] = createEdge(edgeCount);
            }
            return edgeCount++;
        }

        protected final GraphEdge createEdge(int id) {
            return new GraphEdge(id);
        }

        public final int id9(int from, int to, long weight, long capacity) {
            if (capacity == 0) {
                return addEdge(from, to, weight, 0, -1);
            } else {
                int id13 = edgeCount;
                addEdge(to, from, -weight, 0, id13 + id14());
                return addEdge(from, to, weight, capacity, id13);
            }
        }

        protected int id14() {
            return 1;
        }

        public final int id1(int from, int to, long weight) {
            return id9(from, to, weight, 0);
        }

        public final int id16(int from, int to) {
            return id1(from, to, 0);
        }

        public final int vertexCount() {
            return vertexCount;
        }

        protected final int edgeCapacity() {
            return from.length;
        }

        public final int firstOutbound(int vertex) {
            int id = firstOutbound[vertex];
            while (id != -1 && isRemoved(id)) {
                id = nextOutbound[id];
            }
            return id;
        }

        public final int nextOutbound(int id) {
            id = nextOutbound[id];
            while (id != -1 && isRemoved(id)) {
                id = nextOutbound[id];
            }
            return id;
        }

        public final int destination(int id) {
            return to[id];
        }

        public final boolean flag(int id, int bit) {
            return (flags[id] >> bit & 1) != 0;
        }

        public final boolean isRemoved(int id) {
            return flag(id, id18);
        }

        protected void id15(int size) {
            if (from.length < size) {
                int newSize = Math.max(size, 2 * from.length);
                if (edges != null) {
                    edges = resize(edges, newSize);
                }
                from = resize(from, newSize);
                to = resize(to, newSize);
                nextOutbound = resize(nextOutbound, newSize);
                if (nextInbound != null) {
                    nextInbound = resize(nextInbound, newSize);
                }
                if (weight != null) {
                    weight = resize(weight, newSize);
                }
                if (capacity != null) {
                    capacity = resize(capacity, newSize);
                }
                if (reverseEdge != null) {
                    reverseEdge = resize(reverseEdge, newSize);
                }
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

        protected class GraphEdge implements Edge {
            protected int id;

            protected GraphEdge(int id) {
                this.id = id;
            }
        }
    }
    static class id6 extends Graph {
        public int[] id2;

        public id6(int vertexCount) {
            this(vertexCount, vertexCount);
        }

        public id6(int vertexCount, int edgeCapacity) {
            super(vertexCount, 2 * edgeCapacity);
            id2 = new int[2 * edgeCapacity];
        }

        public static id6 createGraph(int vertexCount, int[] from, int[] to) {
            id6 graph = new id6(vertexCount, from.length);
            for (int i = 0; i < from.length; i++) {
                graph.id16(from[i], to[i]);
            }
            return graph;
        }

        public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
            int id13 = edgeCount;
            super.addEdge(fromID, toID, weight, capacity, reverseEdge);
            super.addEdge(toID, fromID, weight, capacity, reverseEdge == -1 ? -1 : reverseEdge + 1);
            this.id2[id13] = id13 + 1;
            this.id2[id13 + 1] = id13;
            return id13;
        }

        protected int id14() {
            return 2;
        }

        protected void id15(int size) {
            if (size > edgeCapacity()) {
                super.id15(size);
                id2 = resize(id2, edgeCapacity());
            }
        }
    }
    static class MiscUtils {
        public static void id8(int[]... arrays) {
            for (int[] array : arrays) {
                for (int i = 0; i < array.length; i++) {
                    array[i]--;
                }
            }
        }
    }
}
