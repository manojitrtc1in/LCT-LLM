import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;
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
        int[] dp;
        int[] q;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n, m;
            Graph gr;

            n = in.readInt();
            m = in.readInt();




            gr = new Graph(n, m);
            for (int i = 0; i < m; i++) {


                gr.id13(in.readInt() - 1, in.readInt() - 1);


            }

            Pair<int[], Graph> id16 = id10.id16(gr);
            int[] condensed = id16.first;
            Graph cgr = id16.second;

















            id18[] vertex = new id18[cgr.vertexCount()];
            for (int cv = 0; cv < cgr.vertexCount(); cv++) {
                vertex[cv] = new id18();
            }
            for (int v = 0; v < n; v++) {
                vertex[condensed[v]].add(v);
            }

            long id14 = 0;
            long id15 = 0;
            dp = new int[n];
            q = new int[n];
            for (int cv = 0; cv < cgr.vertexCount(); cv++) {
                if (cgr.firstOutbound(cv) == -1 && vertex[cv].size() != 1) {
                    ++id14;
                    id15 += f(gr, vertex[cv].toArray(), condensed, cv);
                }
            }
            out.printLine(1000 * id14 + (id15 - id14) * 999 + (n - id15));
        }

        private long f(Graph gr, int[] starts, int[] condensed, int color) {

            int length = Integer.MAX_VALUE;

            id2 q = new id2(starts.length);


            for (int start : starts) {
                for (int v : starts) {
                    dp[v] = Integer.MAX_VALUE;
                }


                q.clear();

                q.add(start);
                dp[start] = 0;
                cyc:
                while (!q.isEmpty()) {
                    int v = q.poll();
                    for (int id = gr.firstOutbound(v); id != -1; id = gr.nextOutbound(id)) {
                        int to = gr.destination(id);
                        if (condensed[to] != color) {
                            continue;
                        }
                        if (dp[to] == Integer.MAX_VALUE) {
                            dp[to] = dp[v] + 1;
                            q.add(to);
                        }
                        if (to == start) {
                            length = Math.min(length, dp[v] + 1);
                            break cyc;
                        }
                    }
                }
            }
            return length;
        }

    }

    static abstract class id4 implements IntStream {

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

    static interface IntList extends id17 {
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

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id20 filter;

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
            while (id3(c)) {
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
            } while (!id3(c));
            return res * sgn;
        }

        public boolean id3(int c) {
            if (filter != null) {
                return filter.id3(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface id20 {
            public boolean id3(int ch);

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
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            Pair pair = (Pair) o;

            return !(first != null ? !first.equals(pair.first) : pair.first != null) &&
                    !(second != null ? !second.equals(pair.second) : pair.second != null);
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
            if (value != 0) {
                return value;
            }
            return ((Comparable<V>) second).compareTo(o.second);
        }

    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static class id10 {
        private final Graph graph;
        private int[] order;
        private boolean[] visited;
        private int index = 0;
        private int vertexCount;
        private int[] condensed;
        private IntSet next;

        private id10(Graph graph) {
            this.graph = graph;
            vertexCount = graph.vertexCount();
            order = new int[vertexCount];
            visited = new boolean[vertexCount];
            condensed = new int[vertexCount];
        }

        public static Pair<int[], Graph> id16(Graph graph) {
            return new id10(graph).id16();
        }

        private Pair<int[], Graph> id16() {
            for (int i = 0; i < vertexCount; i++) {
                if (!visited[i]) {
                    firstDFS(i);
                }
            }
            Arrays.fill(visited, false);
            Graph result = new Graph(0);
            index = 0;
            for (int i = vertexCount - 1; i >= 0; i--) {
                if (!visited[order[i]]) {
                    next = new id19();
                    secondDFS(order[i]);
                    result.addVertices(1);
                    for (int set : next.toArray()) {
                        result.id13(set, index);
                    }
                    index++;
                }
            }
            return Pair.makePair(condensed, result);
        }

        private void secondDFS(int vertexID) {
            if (visited[vertexID]) {
                if (condensed[vertexID] != index) {
                    next.add(condensed[vertexID]);
                }
                return;
            }
            condensed[vertexID] = index;
            visited[vertexID] = true;
            int edgeID = graph.firstInbound(vertexID);
            while (edgeID != -1) {
                secondDFS(graph.source(edgeID));
                edgeID = graph.nextInbound(edgeID);
            }
        }

        private void firstDFS(int vertexID) {
            if (visited[vertexID]) {
                return;
            }
            visited[vertexID] = true;
            int edgeID = graph.firstOutbound(vertexID);
            while (edgeID != -1) {
                firstDFS(graph.destination(edgeID));
                edgeID = graph.nextOutbound(edgeID);
            }
            order[index++] = vertexID;
        }

    }

    static interface Edge {
    }

    static class IntHash {
        private IntHash() {
        }

        public static int hash(int c) {
            return c;
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

        public void printLine(long i) {
            writer.println(i);
        }

    }

    static class IntegerUtils {
        public static int gcd(int a, int b) {
            a = Math.abs(a);
            b = Math.abs(b);
            while (b != 0) {
                int temp = a % b;
                a = b;
                b = temp;
            }
            return a;
        }

    }

    static interface IntQueue extends IntCollection {
    }

    static interface IntSet extends IntCollection {
    }

    static class IntArray extends id4 implements IntList {
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

    static interface id17 extends IntCollection {
    }

    static class id2 implements IntQueue {
        private int[] data;
        private int from;
        private int to;

        public id2(int capacity) {
            data = new int[Integer.highestOneBit(capacity) << 1];
        }

        public id2() {
            this(3);
        }

        public id2(int[] array) {
            this(array.length);
            to = array.length;
            System.arraycopy(array, 0, data, 0, to);
        }

        public id2(IntStream s) {
            addAll(s);
        }

        public id2(IntCollection c) {
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

        public void clear() {
            from = to = 0;
        }

    }

    static class id18 extends id4 implements IntList {
        private int size;
        private int[] data;

        public id18() {
            this(3);
        }

        public id18(int capacity) {
            data = new int[capacity];
        }

        public id18(IntCollection c) {
            this(c.size());
            addAll(c);
        }

        public id18(IntStream c) {
            this();
            if (c instanceof IntCollection) {
                ensureCapacity(((IntCollection) c).size());
            }
            addAll(c);
        }

        public id18(id18 c) {
            size = c.size();
            data = c.data.clone();
        }

        public id18(int[] arr) {
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

    static class id19 extends id4 implements IntSet {
        private static final Random RND = new Random();
        private static final int[] id9 = new int[4];
        private static final byte id1 = 1;
        private static final byte id5 = 2;
        private int size;
        private int realSize;
        private int[] values;
        private byte[] present;
        private int step;
        private int ratio;

        static {
            for (int i = 0; i < 4; i++) {
                id9[i] = RND.nextInt(31) + 1;
            }
        }

        public id19() {
            this(3);
        }

        public id19(int capacity) {
            capacity = Math.max(capacity, 3);
            values = new int[capacity];
            present = new byte[capacity];
            ratio = 2;
            initStep(capacity);
        }

        public id19(IntCollection c) {
            this(c.size());
            addAll(c);
        }

        public id19(int[] arr) {
            this(new IntArray(arr));
        }

        private void initStep(int capacity) {
            step = RND.nextInt(capacity - 2) + 1;
            while (IntegerUtils.gcd(step, capacity) != 1) {
                step++;
            }
        }


        public IntIterator intIterator() {
            return new IntIterator() {
                private int position = size == 0 ? values.length : -1;

                public int value() throws NoSuchElementException {
                    if (position == -1) {
                        advance();
                    }
                    if (position >= values.length) {
                        throw new NoSuchElementException();
                    }
                    if ((present[position] & id1) == 0) {
                        throw new IllegalStateException();
                    }
                    return values[position];
                }

                public boolean advance() throws NoSuchElementException {
                    if (position >= values.length) {
                        throw new NoSuchElementException();
                    }
                    position++;
                    while (position < values.length && (present[position] & id1) == 0) {
                        position++;
                    }
                    return isValid();
                }

                public boolean isValid() {
                    return position < values.length;
                }

                public void remove() {
                    if ((present[position] & id1) == 0) {
                        throw new IllegalStateException();
                    }
                    present[position] = id5;
                }
            };
        }


        public int size() {
            return size;
        }


        public void add(int value) {
            ensureCapacity((realSize + 1) * ratio + 2);
            int current = getHash(value);
            while (present[current] != 0) {
                if ((present[current] & id1) != 0 && values[current] == value) {
                    return;
                }
                current += step;
                if (current >= values.length) {
                    current -= values.length;
                }
            }
            while ((present[current] & id1) != 0) {
                current += step;
                if (current >= values.length) {
                    current -= values.length;
                }
            }
            if (present[current] == 0) {
                realSize++;
            }
            present[current] = id1;
            values[current] = value;
            size++;
        }

        private int getHash(int value) {
            int hash = IntHash.hash(value);
            int result = hash;
            for (int i : id9) {
                result ^= hash >> i;
            }
            result %= values.length;
            if (result < 0) {
                result += values.length;
            }
            return result;
        }

        private void ensureCapacity(int capacity) {
            if (values.length < capacity) {
                capacity = Math.max(capacity * 2, values.length);
                rebuild(capacity);
            }
        }

        private void rebuild(int capacity) {
            initStep(capacity);
            int[] oldValues = values;
            byte[] oldPresent = present;
            values = new int[capacity];
            present = new byte[capacity];
            size = 0;
            realSize = 0;
            for (int i = 0; i < oldValues.length; i++) {
                if ((oldPresent[i] & id1) == id1) {
                    add(oldValues[i]);
                }
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
            id11(edgeCount + 1);
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
                int id8 = edgeCount;
                addEdge(to, from, -weight, 0, id8 + id12());
                return addEdge(from, to, weight, capacity, id8);
            }
        }

        protected int id12() {
            return 1;
        }

        public final int id0(int from, int to, long weight) {
            return id6(from, to, weight, 0);
        }

        public final int id13(int from, int to) {
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

        public final int firstInbound(int vertex) {
            initInbound();
            int id = firstInbound[vertex];
            while (id != -1 && isRemoved(id)) {
                id = nextInbound[id];
            }
            return id;
        }

        public final int nextInbound(int id) {
            initInbound();
            id = nextInbound[id];
            while (id != -1 && isRemoved(id)) {
                id = nextInbound[id];
            }
            return id;
        }

        public final int source(int id) {
            return from[id];
        }

        public final int destination(int id) {
            return to[id];
        }

        public final void addVertices(int count) {
            id7(vertexCount + count);
            Arrays.fill(firstOutbound, vertexCount, vertexCount + count, -1);
            if (firstInbound != null) {
                Arrays.fill(firstInbound, vertexCount, vertexCount + count, -1);
            }
            vertexCount += count;
        }

        private void initInbound() {
            if (firstInbound == null) {
                firstInbound = new int[firstOutbound.length];
                Arrays.fill(firstInbound, 0, vertexCount, -1);
                nextInbound = new int[from.length];
                for (int i = 0; i < edgeCount; i++) {
                    nextInbound[i] = firstInbound[to[i]];
                    firstInbound[to[i]] = i;
                }
            }
        }

        public final boolean flag(int id, int bit) {
            return (flags[id] >> bit & 1) != 0;
        }

        public final boolean isRemoved(int id) {
            return flag(id, id21);
        }

        protected void id11(int size) {
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

        private void id7(int size) {
            if (firstOutbound.length < size) {
                int newSize = Math.max(size, 2 * from.length);
                firstOutbound = resize(firstOutbound, newSize);
                if (firstInbound != null) {
                    firstInbound = resize(firstInbound, newSize);
                }
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

    static interface IntCollection extends IntStream {
        public int size();

        default public boolean isEmpty() {
            return size() == 0;
        }

        default public void add(int value) {
            throw new UnsupportedOperationException();
        }

        default public int[] toArray() {
            int size = size();
            int[] array = new int[size];
            int i = 0;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                array[i++] = it.value();
            }
            return array;
        }

        default public IntCollection addAll(IntStream values) {
            for (IntIterator it = values.intIterator(); it.isValid(); it.advance()) {
                add(it.value());
            }
            return this;
        }

    }
}

