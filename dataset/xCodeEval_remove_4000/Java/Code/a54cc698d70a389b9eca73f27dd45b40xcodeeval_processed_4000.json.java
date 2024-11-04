import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
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
        int n;
        id5 graph;
        int[] depth;
        boolean[] id16;
        int answer;

        private void dfs(int v, int p) {
            int h0 = -1;
            int h1 = -1;
            boolean id9 = true;
            boolean id12 = true;
            id15 orderEdges = new id15();
            for (int i = graph.firstOutbound(v); i != -1; i = graph.nextOutbound(i)) {
                orderEdges.add(i);
                int to = graph.destination(i);
                if (h0 == -1 || h0 == depth[to]) {
                    h0 = depth[to];
                } else if (h1 == -1 || h1 == depth[to]) {
                    h1 = depth[to];
                } else {
                    id9 = false;
                }
                id12 &= id16[to];
            }

            if (id9 && id12) {
                int curAns;
                if (h1 == -1) {
                    curAns = h0 + 1 + h0 + 1;
                } else {
                    curAns = h0 + 1 + h1 + 1;
                }
                while (curAns % 2 == 0) {
                    curAns /= 2;
                }
                answer = Math.min(answer, curAns);
            }

            boolean[] id2 = new boolean[orderEdges.size()];
            for (int i = orderEdges.size() - 1; i >= 0; i--) {
                int to = graph.destination(orderEdges.get(i));
                id2[i] = id16[to];
                if (i + 1 < orderEdges.size()) {
                    id2[i] &= id2[i + 1] &&
                            depth[graph.destination(orderEdges.get(i))] ==
                                    depth[graph.destination(orderEdges.get(i + 1))];
                }
            }

            boolean prefOk = true;
            for (int i = 0; i < orderEdges.size(); i++) {
                int to = graph.destination(orderEdges.get(i));

                boolean canGo = prefOk;
                if (i + 1 != orderEdges.size()) {
                    canGo &= id2[i + 1];
                }
                if (i != 0 && i + 1 != orderEdges.size()) {
                    canGo &=
                            depth[graph.destination(orderEdges.first())] == depth[graph.destination(orderEdges.last())];
                }
                canGo &= to != p;


                if (canGo) {
                    int oldDV = depth[v];
                    depth[v] = 0;
                    for (int index = graph.firstOutbound(v); index != -1; index = graph.nextOutbound(index)) {
                        if (graph.destination(index) != to) {
                            depth[v] = Math.max(depth[v], depth[graph.destination(index)] + 1);
                            break;
                        }
                    }
                    boolean id13 = id16[v];
                    id16[v] = true;

                    dfs(to, v);

                    depth[v] = oldDV;
                    id16[v] = id13;
                }

                

                prefOk &= id16[to];
                if (i != 0) {
                    prefOk &= depth[to] == depth[graph.destination(orderEdges.get(i - 1))];
                }
            }
        }

        private void init(int v, int p) {
            depth[v] = 0;
            id16[v] = true;
            for (int i = graph.firstOutbound(v); i != -1; i = graph.nextOutbound(i)) {
                int to = graph.destination(i);
                if (to == p) {
                    continue;
                }
                init(to, v);

                if (depth[v] == 0) {
                    depth[v] = depth[to] + 1;
                } else if (depth[v] != depth[to] + 1) {
                    id16[v] = false;
                    depth[v] = Math.max(depth[v], depth[to] + 1);
                }
                id16[v] &= id16[to];
            }
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.readInt();
            graph = new id5(n, n - 1);
            for (int i = 0; i < n - 1; i++) {
                int a = in.readInt() - 1;
                int b = in.readInt() - 1;
                graph.id11(a, b);
            }

            int root = (int) (111235424214125L % n);
            depth = new int[n];
            id16 = new boolean[n];
            init(root, -1);
            answer = Integer.MAX_VALUE;
            dfs(root, -1);
            out.printLine(answer == Integer.MAX_VALUE ? -1 : answer);

        }

    }

    static interface IntCollection extends IntStream {
        public int size();

        default public void add(int value) {
            throw new UnsupportedOperationException();
        }

        default public IntCollection addAll(IntStream values) {
            for (IntIterator it = values.intIterator(); it.isValid(); it.advance()) {
                add(it.value());
            }
            return this;
        }

    }

    static interface Edge {
    }

    static interface id14 extends IntCollection {
    }

    static class id5 extends Graph {
        public int[] id1;

        public id5(int vertexCount) {
            this(vertexCount, vertexCount);
        }

        public id5(int vertexCount, int edgeCapacity) {
            super(vertexCount, 2 * edgeCapacity);
            id1 = new int[2 * edgeCapacity];
        }


        public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
            int id7 = edgeCount;
            super.addEdge(fromID, toID, weight, capacity, reverseEdge);
            super.addEdge(toID, fromID, weight, capacity, (reverseEdge == -1) ? -1 : (reverseEdge + 1));
            this.id1[id7] = id7 + 1;
            this.id1[id7 + 1] = id7;
            return id7;
        }


        protected int id10() {
            return 2;
        }


        protected void id8(int size) {
            if (size > edgeCapacity()) {
                super.id8(size);
                id1 = resize(id1, edgeCapacity());
            }
        }

    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static interface IntList extends id14 {
        public abstract int get(int index);

        public abstract void addAt(int index, int value);

        public abstract void removeAt(int index);

        default public int first() {
            return get(0);
        }

        default public int last() {
            return get(size() - 1);
        }

        default public IntIterator intIterator() {
            return new IntIterator() {
                private int at;
                private boolean removed;

                public int value() {
                    if (removed) {
                        throw new IllegalStateException();
                    }
                    return get(at);
                }

                public boolean advance() {
                    at++;
                    removed = false;
                    return isValid();
                }

                public boolean isValid() {
                    return !removed && (at < size());
                }

                public void remove() {
                    removeAt(at);
                    at--;
                    removed = true;
                }
            };
        }


        default public void add(int value) {
            addAt(size(), value);
        }

    }

    static class id15 extends id3 implements IntList {
        private int size;
        private int[] data;

        public id15() {
            this(3);
        }

        public id15(int capacity) {
            data = new int[capacity];
        }

        public id15(IntCollection c) {
            this(c.size());
            addAll(c);
        }

        public id15(IntStream c) {
            this();
            if (c instanceof IntCollection) {
                ensureCapacity(((IntCollection) c).size());
            }
            addAll(c);
        }

        public id15(id15 c) {
            size = c.size();
            data = c.data.clone();
        }

        public id15(int[] arr) {
            size = arr.length;
            data = arr.clone();
        }

        public int size() {
            return size;
        }

        public int get(int at) {
            if (at >= size) {
                throw new IndexOutOfBoundsException("at = " + at + ", size = " + size);
            }
            return data[at];
        }

        private void ensureCapacity(int capacity) {
            if (data.length >= capacity) {
                return;
            }
            capacity = Math.max(2 * data.length, capacity);
            data = Arrays.copyOf(data, capacity);
        }

        public void addAt(int index, int value) {
            ensureCapacity(size + 1);
            if ((index > size) || (index < 0)) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            if (index != size) {
                System.arraycopy(data, index, data, index + 1, size - index);
            }
            data[index] = value;
            size++;
        }

        public void removeAt(int index) {
            if ((index >= size) || (index < 0)) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            if (index != (size - 1)) {
                System.arraycopy(data, index + 1, data, index, size - index - 1);
            }
            size--;
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
        public long[] weight;
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
            id8(edgeCount + 1);
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

        public final int id6(int from, int to, long weight, long capacity) {
            if (capacity == 0) {
                return addEdge(from, to, weight, 0, -1);
            } else {
                int id7 = edgeCount;
                addEdge(to, from, -weight, 0, id7 + id10());
                return addEdge(from, to, weight, capacity, id7);
            }
        }

        protected int id10() {
            return 1;
        }

        public final int id0(int from, int to, long weight) {
            return id6(from, to, weight, 0);
        }

        public final int id11(int from, int to) {
            return id0(from, to, 0);
        }

        protected final int edgeCapacity() {
            return from.length;
        }

        public final int firstOutbound(int vertex) {
            int id = firstOutbound[vertex];
            while ((id != -1) && isRemoved(id)) {
                id = nextOutbound[id];
            }
            return id;
        }

        public final int nextOutbound(int id) {
            id = nextOutbound[id];
            while ((id != -1) && isRemoved(id)) {
                id = nextOutbound[id];
            }
            return id;
        }

        public final int destination(int id) {
            return to[id];
        }

        public final boolean flag(int id, int bit) {
            return ((flags[id] >> bit) & 1) != 0;
        }

        public final boolean isRemoved(int id) {
            return flag(id, id18);
        }

        protected void id8(int size) {
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

    static interface IntStream extends Iterable<Integer>, Comparable<IntStream> {
        public IntIterator intIterator();

        default public Iterator<Integer> iterator() {
            return new Iterator<Integer>() {
                private IntIterator it = intIterator();

                public boolean hasNext() {
                    return it.isValid();
                }

                public Integer next() {
                    int result = it.value();
                    it.advance();
                    return result;
                }
            };
        }

        default public int compareTo(IntStream c) {
            IntIterator it = intIterator();
            IntIterator jt = c.intIterator();
            while (it.isValid() && jt.isValid()) {
                int i = it.value();
                int j = jt.value();
                if (i < j) {
                    return -1;
                } else if (i > j) {
                    return 1;
                }
                it.advance();
                jt.advance();
            }
            if (it.isValid()) {
                return 1;
            }
            if (jt.isValid()) {
                return -1;
            }
            return 0;
        }

    }

    static abstract class id3 implements IntStream {

        public String toString() {
            StringBuilder builder = new StringBuilder();
            boolean first = true;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                if (first) {
                    first = false;
                } else {
                    builder.append(' ');
                }
                builder.append(it.value());
            }
            return builder.toString();
        }


        public boolean equals(Object o) {
            if (!(o instanceof IntStream)) {
                return false;
            }
            IntStream c = (IntStream) o;
            IntIterator it = intIterator();
            IntIterator jt = c.intIterator();
            while (it.isValid() && jt.isValid()) {
                if (it.value() != jt.value()) {
                    return false;
                }
                it.advance();
                jt.advance();
            }
            return !it.isValid() && !jt.isValid();
        }


        public int hashCode() {
            int result = 0;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                result *= 31;
                result += it.value();
            }
            return result;
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
                if ((c < '0') || (c > '9')) {
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
            return (c == ' ') || (c == '\n') || (c == '\r') || (c == '\t') || (c == -1);
        }

        public interface id17 {
            public boolean id4(int ch);

        }

    }
}
