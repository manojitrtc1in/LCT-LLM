import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.OptionalInt;
import java.util.ArrayList;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.Collection;
import java.io.IOException;
import java.util.Objects;
import java.util.List;
import java.io.Writer;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        id1 solver = new id1();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class id1 {
        int[][][] path = null;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            if (path == null) {
                path = init();
            }
            int n = in.readInt(), m = in.readInt();
            char[][] table = in.readTable(n, m);
            List<int[]> res = new ArrayList<>();
            for (int r = 0; r < n; ) {
                int n2 = r + 3 == n ? 3 : 2;
                for (int c = 0; c < m; ) {
                    int m2 = c + 3 == m ? 3 : 2;
                    int start = 0;
                    for (int i = 0; i < n2; i++) {
                        for (int j = 0; j < m2; j++) {
                            if (table[r + i][c + j] == '1') {
                                start ^= 1 << (i * m2 + j);
                            }
                        }
                    }
                    List<int[]> p = getPath(start, n2, m2);
                    for (int[] arr : p) {
                        for (int i = 0; i < 6; i++) {
                            arr[i] += i % 2 == 0 ? r + 1 : c + 1;
                        }
                    }
                    res.addAll(p);
                    c += m2;
                }
                r += n2;
            }
            out.printLine(res.size());
            for (int[] arr : res) {
                out.printLine(arr);
            }
        }

        List<int[]> getPath(int u, int n, int m) {
            int[] previous = path[n - 2][m - 2];
            List<int[]> res = new ArrayList<>();
            id7 list = new id19(6);
            while (u != 0) {
                int v = previous[u];
                int[] arr = new int[6];
                for (int i = 0; i < n * m; i++) {
                    if (((u ^ v) & (1 << i)) > 0) {
                        list.add(i / m);
                        list.add(i % m);
                    }
                }
                res.add(list.toArray());
                list.clear();
                u = v;
            }
            return res;
        }

        int[][][] init() {
            int[][][] res = new int[2][2][];
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    res[i][j] = getPath(i + 2, j + 2);
                }
            }
            return res;
        }

        int[] getPath(int n, int m) {
            Graph graph = new Graph(1 << (n * m));
            for (int u = 0; u < (1 << (n * m)); u++) {
                for (int r0 = 0; r0 < n - 1; r0++) {
                    for (int c0 = 0; c0 < m - 1; c0++) {
                        int aux = u;
                        for (int r = r0; r < r0 + 2; r++) {
                            for (int c = c0; c < c0 + 2; c++) {
                                aux ^= 1 << (r * m + c);
                            }
                        }
                        for (int r = r0; r < r0 + 2; r++) {
                            for (int c = c0; c < c0 + 2; c++) {
                                int v = aux ^ (1 << (r * m + c));
                                graph.id15(u, v);
                            }
                        }
                    }
                }
            }
            Pair<int[], int[]> dijkstra = ShortestDistance.bfs(graph, 0);
            if (ArrayUtils.maxElement(dijkstra.first) > n * m) {
                throw new UnknownError();
            }
            return Arrays.stream(dijkstra.second).map(i -> i == -1 ? -1 : graph.source(i)).toArray();
        }

    }

    static class Pair<U, V> implements Comparable<Pair<U, V>> {
        public final U first;
        public final V second;

        public static <U, V> Pair<U, V> makePair(U first, V second) {
            return new Pair<>(first, second);
        }

        private Pair(U first, V second) {
            this.first = first;
            this.second = second;
        }

        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            Pair pair = (Pair) o;

            return Objects.equals(first, pair.first) &&
                    Objects.equals(second, pair.second);
        }

        public int hashCode() {
            int result = first != null ? first.hashCode() : 0;
            result = 31 * result + (second != null ? second.hashCode() : 0);
            return result;
        }

        public String toString() {
            return "(" + first + "," + second + ")";
        }

        public int compareTo(Pair<U, V> o) {
            int value = ((Comparable<U>) first).compareTo(o.first);
            if (value != 0) {
                return value;
            }
            return ((Comparable<V>) second).compareTo(o.second);
        }

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

        public final int id9(int from, int to, long weight, long capacity) {
            if (capacity == 0) {
                return addEdge(from, to, weight, 0, -1);
            } else {
                int id11 = edgeCount;
                addEdge(to, from, -weight, 0, id11 + id14());
                return addEdge(from, to, weight, capacity, id11);
            }
        }

        protected int id14() {
            return 1;
        }

        public final int id0(int from, int to, long weight) {
            return id9(from, to, weight, 0);
        }

        public final int id15(int from, int to) {
            return id0(from, to, 0);
        }

        public final int vertexCount() {
            return vertexCount;
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

        public final int source(int id) {
            return from[id];
        }

        public final int destination(int id) {
            return to[id];
        }

        public final boolean flag(int id, int bit) {
            return (flags[id] >> bit & 1) != 0;
        }

        public final boolean isRemoved(int id) {
            return flag(id, id23);
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

        }

    }

    static interface id7 extends id2 {
        int size();

        id18 iterator();

        int[] toArray();

        boolean add(int element);

        void clear();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(int[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void printLine(int[] array) {
            print(array);
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void printLine(int i) {
            writer.println(i);
        }

    }

    static interface IntCollection extends id17 {
        public int size();

        default public boolean isEmpty() {
            return size() == 0;
        }

        default public void add(int value) {
            throw new UnsupportedOperationException();
        }

        default public IntCollection addAll(id17 values) {
            for (IntIterator it = values.intIterator(); it.isValid(); it.advance()) {
                add(it.value());
            }
            return this;
        }

    }

    static class id19 implements id7, id8 {
        private static final int id20 = 10;
        private static final double id6 = 2.0;
        private static final int id16 = 0x811c9dc5;
        private static final int id21 = 0x01000193;
        private int[] array;
        private int size;

        public id19() {
            this(id20);
        }

        public id19(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            array = new int[capacity];
            size = 0;
        }

        public id19(id2 collection) {
            size = collection.size();
            array = new int[size];
            int i = 0;
            for (id18 iterator = collection.iterator(); iterator.hasNext(); ) {
                array[i++] = iterator.next();
            }
        }

        public id19(int[] srcArray) {
            size = srcArray.length;
            array = new int[size];
            System.arraycopy(srcArray, 0, array, 0, size);
        }

        public id19(Collection<Integer> javaCollection) {
            size = javaCollection.size();
            array = new int[size];
            int i = 0;
            for (int element : javaCollection) {
                array[i++] = element;
            }
        }

        public int size() {
            return size;
        }

        public id18 iterator() {
            return new id12();
        }

        public int[] toArray() {
            int[] result = new int[size];
            System.arraycopy(array, 0, result, 0, size);
            return result;
        }

        public boolean add(int element) {
            if (size == array.length) {
                enlarge();
            }
            array[size++] = element;
            return true;
        }

        public void clear() {
            size = 0;
        }

        private void enlarge() {
            int newSize = Math.max(size + 1, (int) (size * id6));
            int[] newArray = new int[newSize];
            System.arraycopy(array, 0, newArray, 0, size);
            array = newArray;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id19 that = (id19) o;

            if (size != that.size) {
                return false;
            }
            for (int i = 0; i < size; i++) {
                if (array[i] != that.array[i]) {
                    return false;
                }
            }
            return true;
        }

        public int hashCode() {
            int hash = id16;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ id10.getHash(array[i])) * id21;
            }
            return hash;
        }

        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append('[');
            for (int i = 0; i < size; i++) {
                sb.append(array[i]);
                if (i < size - 1) {
                    sb.append(", ");
                }
            }
            sb.append(']');
            return sb.toString();
        }

        private class id12 implements id18 {
            private int curIndex = 0;

            public boolean hasNext() {
                return curIndex < size;
            }

            public int next() {
                if (curIndex == size) {
                    throw new NoSuchElementException("Iterator doesn't have more elements");
                }
                return array[curIndex++];
            }

        }

    }

    static interface id18 {
        boolean hasNext();

        int next();

    }

    static class ShortestDistance {
        public static Pair<int[], int[]> bfs(Graph graph, int source) {
            int vertexCount = graph.vertexCount();
            final int[] distance = new int[vertexCount];
            int[] last = new int[vertexCount];
            Arrays.fill(distance, Integer.MAX_VALUE);
            Arrays.fill(last, -1);
            distance[source] = 0;
            IntQueue queue = new id4();
            queue.add(source);
            while (!queue.isEmpty()) {
                int current = queue.poll();
                int id = graph.firstOutbound(current);
                while (id != -1) {
                    int next = graph.destination(id);
                    int total = 1 + distance[current];
                    if (distance[next] > total) {
                        distance[next] = total;
                        queue.add(next);
                        last[next] = id;
                    }
                    id = graph.nextOutbound(id);
                }
            }
            return Pair.makePair(distance, last);
        }

    }

    static class InputReader {
        private final InputStream stream;
        private final byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id22 filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public char[] id3(int size) {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = readCharacter();
            }
            return array;
        }

        public char[][] readTable(int rowCount, int columnCount) {
            char[][] table = new char[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id3(columnCount);
            }
            return table;
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
            while (id5(c)) {
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
            } while (!id5(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (id5(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id5(c));
            return res.toString();
        }

        public boolean id5(int c) {
            if (filter != null) {
                return filter.id5(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public char readCharacter() {
            int c = read();
            while (id5(c)) {
                c = read();
            }
            return (char) c;
        }

        public String next() {
            return readString();
        }

        public interface id22 {
            boolean id5(int ch);

        }

    }

    static interface Edge {
    }

    static final class id10 {
        private id10() {
        }

        public static int getHash(int x) {
            return x;
        }

    }

    static class ArrayUtils {
        public static int maxElement(int[] array) {
            return Arrays.stream(array).max().getAsInt();
        }

    }

    static interface IntQueue extends IntCollection {
        public int poll();

    }

    static class id4 implements IntQueue {
        private int[] data;
        private int from;
        private int to;

        public id4(int capacity) {
            data = new int[Integer.highestOneBit(capacity) << 1];
        }

        public id4() {
            this(3);
        }

        public id4(int[] array) {
            this(array.length);
            to = array.length;
            System.arraycopy(array, 0, data, 0, to);
        }

        public id4(id17 s) {
            addAll(s);
        }

        public id4(IntCollection c) {
            this(c.size());
            addAll(c);
        }

        public int size() {
            return (to - from) & (data.length - 1);
        }

        public void add(int v) {
            ensureCapacity(size() + 1);
            data[to++] = v;
            to &= data.length - 1;
        }

        public int poll() {
            if (from == to) {
                throw new NoSuchElementException();
            }
            int result = data[from++];
            from &= data.length - 1;
            return result;
        }

        public IntIterator intIterator() {
            return new IntIterator() {
                private int at = from;

                public int value() {
                    if (at == to) {
                        throw new NoSuchElementException();
                    }
                    return data[at];
                }

                public boolean advance() {
                    if (!isValid()) {
                        throw new NoSuchElementException();
                    }
                    at++;
                    at &= data.length - 1;
                    return isValid();
                }

                public boolean isValid() {
                    return at != to;
                }

                public void remove() {
                    throw new UnsupportedOperationException();
                }
            };
        }

        private void ensureCapacity(int capacity) {
            if (data.length <= capacity) {
                int[] newData = new int[Integer.highestOneBit(capacity) << 1];
                if (from <= to) {
                    System.arraycopy(data, from, newData, 0, size());
                } else {
                    System.arraycopy(data, from, newData, 0, data.length - from);
                    System.arraycopy(data, 0, newData, data.length - from, to);
                }
                to = size();
                from = 0;
                data = newData;
            }
        }

    }

    static interface id8 extends id2 {
        int size();

        id18 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface id17 extends Iterable<Integer>, Comparable<id17> {
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

        default int compareTo(id17 c) {
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

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static interface id2 {
        int size();

        id18 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }
}

