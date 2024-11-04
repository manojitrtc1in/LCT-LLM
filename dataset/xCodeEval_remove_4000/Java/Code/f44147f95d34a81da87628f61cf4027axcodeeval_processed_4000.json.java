import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.InputMismatchException;
import java.util.AbstractCollection;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.io.IOException;
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
            try {
                int n = in.readInt(), m = in.readInt();
                int[] u = new int[m], v = new int[m], w = new int[m];
                in.id9(u, v, w);
                MiscUtils.id7(u, v);
                Graph graph = id6.id1(n, u, v, ArrayUtils.asLong(w));
                int source = in.readInt() - 1;
                IntCollection edges = dijkstra(graph, source);
                long sum = edges.reduce(0, (id18) (s, i) -> s + graph.edge(i).getWeight());
                out.printLine(sum);
                IntCollection res = edges.map((id3) x -> x / 2 + 1).compute();
                out.printLine(res);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        IntCollection dijkstra(Graph graph, int source) {
            int n = graph.vertexCount();
            long[] dist = ArrayUtils.createArray(n, Long.MAX_VALUE), prevWeight = ArrayUtils.createArray(n, Long.MAX_VALUE);
            int[] prevEdge = ArrayUtils.createArray(n, -1);
            dist[source] = prevWeight[source] = 0;
            PriorityQueue<id11> pq = new PriorityQueue<>();
            pq.add(new id11(0, 0, source));
            while (!pq.isEmpty()) {
                id11 triple = pq.poll();
                long d = triple.first, pw = triple.second;
                int u = triple.third;
                if (u != source && (d > dist[u] || pw > prevWeight[u])) {
                    continue;
                }
                for (int ed = graph.firstOutbound(u); ed != -1; ed = graph.nextOutbound(ed)) {
                    int v = graph.destination(ed);
                    long w = graph.weight(ed);
                    if (dist[v] > d + w || (dist[v] == d + w && prevWeight[v] > w)) {
                        dist[v] = d + w;
                        prevWeight[v] = w;
                        prevEdge[v] = ed;
                        pq.add(new id11(dist[v], prevWeight[v], v));
                    }
                }
            }
            return new IntArray(prevEdge).filter(x -> x != -1).compute();
        }

    }

    static class id17 extends id5 implements IntList {
        private int size;
        private int[] data;

        public id17() {
            this(3);
        }

        public id17(int capacity) {
            data = new int[capacity];
        }

        public id17(IntCollection c) {
            this(c.size());
            addAll(c);
        }

        public id17(IntStream c) {
            this();
            if (c instanceof IntCollection) {
                ensureCapacity(((IntCollection) c).size());
            }
            addAll(c);
        }

        public id17(id17 c) {
            size = c.size();
            data = c.data.clone();
        }

        public id17(int[] arr) {
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
            if (index > size || index < 0) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            if (index != size) {
                System.arraycopy(data, index, data, index + 1, size - index);
            }
            data[index] = value;
            size++;
        }

        public void removeAt(int index) {
            if (index >= size || index < 0) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            if (index != size - 1) {
                System.arraycopy(data, index + 1, data, index, size - index - 1);
            }
            size--;
        }

    }

    static class Graph {
        public static final int id21 = 0;
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
            id13(edgeCount + 1);
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

        public final int id8(int from, int to, long weight, long capacity) {
            if (capacity == 0) {
                return addEdge(from, to, weight, 0, -1);
            } else {
                int id12 = edgeCount;
                addEdge(to, from, -weight, 0, id12 + id14());
                return addEdge(from, to, weight, capacity, id12);
            }
        }

        protected int id14() {
            return 1;
        }

        public final int id0(int from, int to, long weight) {
            return id8(from, to, weight, 0);
        }

        public final int vertexCount() {
            return vertexCount;
        }

        protected final int edgeCapacity() {
            return from.length;
        }

        public final Edge edge(int id) {
            initEdges();
            return edges[id];
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

        public final long weight(int id) {
            if (weight == null) {
                return 0;
            }
            return weight[id];
        }

        protected final void initEdges() {
            if (edges == null) {
                edges = new Edge[from.length];
                for (int i = 0; i < edgeCount; i++) {
                    edges[i] = createEdge(i);
                }
            }
        }

        public final boolean flag(int id, int bit) {
            return (flags[id] >> bit & 1) != 0;
        }

        public final boolean isRemoved(int id) {
            return flag(id, id21);
        }

        protected void id13(int size) {
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

            public long getWeight() {
                return weight(id);
            }

        }

    }

    static final class id10 {
        private id10() {
        }

        public static int getHash(int x) {
            return x;
        }

        public static int getHash(long x) {
            return (int) x ^ (int) (x >>> 32);
        }

    }

    static class IntArray extends id5 implements IntList {
        private int[] data;

        public IntArray(int[] arr) {
            data = arr;
        }

        public int size() {
            return data.length;
        }

        public int get(int at) {
            return data[at];
        }

        public void addAt(int index, int value) {
            throw new UnsupportedOperationException();
        }

        public void removeAt(int index) {
            throw new UnsupportedOperationException();
        }

    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

        public void remove();

    }

    static interface IntList extends id16 {
        public abstract int get(int index);

        public abstract void addAt(int index, int value);

        public abstract void removeAt(int index);

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
                    return !removed && at < size();
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

    static abstract class id5 implements IntStream {
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

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void printLine(long i) {
            writer.println(i);
        }

    }

    static class id11 implements Comparable<id11> {
        private static final int id15 = 0x811c9dc5;
        private static final int id19 = 0x01000193;
        public long first;
        public long second;
        public int third;

        public id11(long first, long second, int third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id11 that = (id11) o;

            return first == that.first && second == that.second && third == that.third;
        }

        public int hashCode() {
            int hash = id15;
            hash = (hash ^ id10.getHash(first)) * id19;
            hash = (hash ^ id10.getHash(second)) * id19;
            hash = (hash ^ id10.getHash(third)) * id19;
            return hash;
        }

        public int compareTo(id11 o) {
            int res = Long.compare(first, o.first);
            if (res == 0) {
                res = Long.compare(second, o.second);
                if (res == 0) {
                    res = Integer.compare(third, o.third);
                }
            }
            return res;
        }

        public String toString() {
            return "(" + first + ", " + second + ", " + third + ")";
        }

    }

    static interface IntFilter {
        public boolean accept(int value);

    }

    static class ArrayUtils {
        public static long[] asLong(int[] array) {
            long[] result = new long[array.length];
            for (int i = 0; i < array.length; i++) {
                result[i] = array[i];
            }
            return result;
        }

        public static int[] createArray(int count, int value) {
            int[] array = new int[count];
            Arrays.fill(array, value);
            return array;
        }

        public static long[] createArray(int count, long value) {
            long[] array = new long[count];
            Arrays.fill(array, value);
            return array;
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id20 filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public void id9(int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readInt();
                }
            }
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

        public interface id20 {
            boolean id4(int ch);

        }

    }

    static interface id16 extends IntCollection {
    }

    static class MiscUtils {
        public static void id7(int[]... arrays) {
            for (int[] array : arrays) {
                for (int i = 0; i < array.length; i++) {
                    array[i]--;
                }
            }
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

        default public IntCollection compute() {
            return this;
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

        public static id6 id1(int vertexCount, int[] from, int[] to, long[] weight) {
            id6 graph = new id6(vertexCount, from.length);
            for (int i = 0; i < from.length; i++) {
                graph.id0(from[i], to[i], weight[i]);
            }
            return graph;
        }

        public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
            int id12 = edgeCount;
            super.addEdge(fromID, toID, weight, capacity, reverseEdge);
            super.addEdge(toID, fromID, weight, capacity, reverseEdge == -1 ? -1 : reverseEdge + 1);
            this.id2[id12] = id12 + 1;
            this.id2[id12 + 1] = id12;
            return id12;
        }

        protected int id14() {
            return 2;
        }

        protected void id13(int size) {
            if (size > edgeCapacity()) {
                super.id13(size);
                id2 = resize(id2, edgeCapacity());
            }
        }

    }

    static interface Edge {
        long getWeight();

    }

    static interface id3 {
        public int value(int key);

    }

    static interface id18 {
        public long value(long first, int second);

    }

    static interface IntStream extends Iterable<Integer>, Comparable<IntStream> {
        IntIterator intIterator();

        default Iterator<Integer> iterator() {
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

        default IntCollection compute() {
            return new id17(this);
        }

        default int compareTo(IntStream c) {
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

        default long reduce(long initial, id18 f) {
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                initial = f.value(initial, it.value());
            }
            return initial;
        }

        default IntStream filter(IntFilter f) {
            return () -> new IntIterator() {
                private IntIterator it = IntStream.this.intIterator();

                {
                    next();
                }

                private void next() {
                    while (it.isValid() && !f.accept(it.value())) {
                        it.advance();
                    }
                }

                public int value() {
                    return it.value();
                }

                public boolean advance() {
                    it.advance();
                    next();
                    return isValid();
                }

                public boolean isValid() {
                    return it.isValid();
                }

                public void remove() {
                    it.remove();
                }
            };
        }

        default IntStream map(id3 function) {
            return () -> new IntIterator() {
                private IntIterator it = IntStream.this.intIterator();

                public int value() {
                    return function.value(it.value());
                }

                public boolean advance() {
                    return it.advance();
                }

                public boolean isValid() {
                    return it.isValid();
                }

                public void remove() {
                    it.remove();
                }
            };
        }

    }
}
