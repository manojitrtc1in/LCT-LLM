import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.Random;
import java.io.IOException;
import java.util.AbstractCollection;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.NoSuchElementException;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int m = in.readInt();
            int[] u = new int[m];
            int[] v = new int[m];
            IOUtils.id7(in, u, v);

            MiscUtils.id5(u, v);
            Graph graph = id4.createGraph(n, u, v);
            Pair<id15, id15> partitions = GraphAlgorithms.id10(graph);

            if (partitions == null) {
                out.printLine(-1);
            } else {
                int[] first = partitions.first.toArray();
                int[] second = partitions.second.toArray();
                MiscUtils.id14(first, second);

                out.printLine(first.length);
                out.printLine(first);
                out.printLine(second.length);
                out.printLine(second);
            }
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

    static abstract class IntCollection {
        public abstract IntIterator iterator();

        public abstract int size();

        public int[] toArray() {
            int size = size();
            int[] array = new int[size];
            int i = 0;
            for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance())
                array[i++] = iterator.value();
            return array;
        }

    }

    static interface Edge {
    }

    static class IOUtils {
        public static void id7(InputReader in, int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++)
                    arrays[j][i] = in.readInt();
            }
        }

    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public void advance() throws NoSuchElementException;

        public boolean isValid();

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
                if (i != 0)
                    writer.print(' ');
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

    static class id15 extends IntSet {
        private static final Random RND = new Random();
        private static final int[] id9 = new int[4];
        private static final byte id1 = 1;
        private int size;
        private int realSize;
        private int[] values;
        private byte[] present;
        private int step;
        private int ratio;

        static {
            for (int i = 0; i < 4; i++)
                id9[i] = RND.nextInt(31) + 1;
        }

        public id15() {
            this(3);
        }

        public id15(int capacity) {
            capacity = Math.max(capacity, 1);
            values = new int[capacity];
            present = new byte[capacity];
            ratio = 2;
            initStep(capacity);
        }

        private void initStep(int capacity) {
            step = RND.nextInt(capacity - 2) + 1;
            while (IntegerUtils.gcd(step, capacity) != 1)
                step++;
        }


        public IntIterator iterator() {
            return new IntIterator() {
                private int position = size == 0 ? values.length : -1;

                public int value() throws NoSuchElementException {
                    if (position == -1)
                        advance();
                    if (position >= values.length)
                        throw new NoSuchElementException();
                    return values[position];
                }

                public void advance() throws NoSuchElementException {
                    if (position >= values.length)
                        throw new NoSuchElementException();
                    position++;
                    while (position < values.length && (present[position] & id1) == 0)
                        position++;
                }

                public boolean isValid() {
                    return position < values.length;
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
                if (current >= values.length)
                    current -= values.length;
            }
            while ((present[current] & id1) != 0) {
                current += step;
                if (current >= values.length)
                    current -= values.length;
            }
            if (present[current] == 0) {
                realSize++;
            }
            present[current] = id1;
            values[current] = value;
            size++;
        }

        private int getHash(int value) {
            int result = value;
            for (int i : id9)
                result ^= value >> i;
            result %= values.length;
            if (result < 0)
                result += values.length;
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
                if ((oldPresent[i] & id1) == id1)
                    add(oldValues[i]);
            }
        }


        public boolean contains(int value) {
            int current = getHash(value);
            while (present[current] != 0) {
                if (values[current] == value && (present[current] & id1) != 0)
                    return true;
                current += step;
                if (current >= values.length)
                    current -= values.length;
            }
            return false;
        }

    }

    static class MiscUtils {
        public static void id5(int[]... arrays) {
            for (int[] array : arrays) {
                for (int i = 0; i < array.length; i++)
                    array[i]--;
            }
        }

        public static void id14(int[]... arrays) {
            for (int[] array : arrays) {
                for (int i = 0; i < array.length; i++)
                    array[i]++;
            }
        }

    }

    static class id4 extends Graph {
        public int[] id2;

        public id4(int vertexCount) {
            this(vertexCount, vertexCount);
        }

        public id4(int vertexCount, int edgeCapacity) {
            super(vertexCount, 2 * edgeCapacity);
            id2 = new int[2 * edgeCapacity];
        }

        public static id4 createGraph(int vertexCount, int[] from, int[] to) {
            id4 graph = new id4(vertexCount, from.length);
            for (int i = 0; i < from.length; i++)
                graph.id13(from[i], to[i]);
            return graph;
        }


        public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
            int id8 = edgeCount;
            super.addEdge(fromID, toID, weight, capacity, reverseEdge);
            super.addEdge(toID, fromID, weight, capacity, reverseEdge == -1 ? -1 : reverseEdge + 1);
            this.id2[id8] = id8 + 1;
            this.id2[id8 + 1] = id8;
            return id8;
        }


        protected int id12() {
            return 2;
        }


        protected void id11(int size) {
            if (size > edgeCapacity()) {
                super.id11(size);
                id2 = resize(id2, edgeCapacity());
            }
        }

    }

    static abstract class IntSet extends IntCollection {
    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id16 filter;

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
            while (id3(c))
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
            } while (!id3(c));
            return res * sgn;
        }

        public boolean id3(int c) {
            if (filter != null)
                return filter.id3(c);
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface id16 {
            public boolean id3(int ch);

        }

    }

    static class GraphAlgorithms {
        public static Pair<id15, id15> id10(Graph graph) {
            LinkedList<Integer> queue = new LinkedList<Integer>();
            id15 setA = new id15();
            id15 setB = new id15();

            for (int i = 0; i < graph.vertexCount(); i++) {
                if (setA.contains(i) || setB.contains(i)) {
                    continue;
                }
                queue.push(i);
                setA.add(i);
                while (!queue.isEmpty()) {
                    int current = queue.poll();
                    id15 currentSet, otherSet;
                    if (setA.contains(current)) {
                        currentSet = setA;
                        otherSet = setB;
                    } else {
                        currentSet = setB;
                        otherSet = setA;
                    }

                    for (int j = graph.firstOutbound(current); j != -1; j = graph.nextOutbound(j)) {
                        int next = graph.destination(j);
                        if (currentSet.contains(next)) {
                            return null;
                        } else if (!otherSet.contains(next)) {
                            otherSet.add(next);
                            queue.push(next);
                        }
                    }
                }
            }

            return Pair.makePair(setA, setB);
        }

    }

    static class Graph {
        public static final int id17 = 0;
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

        public final boolean flag(int id, int bit) {
            return (flags[id] >> bit & 1) != 0;
        }

        public final boolean isRemoved(int id) {
            return flag(id, id17);
        }

        protected void id11(int size) {
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

        protected class GraphEdge implements Edge {
            protected int id;

            protected GraphEdge(int id) {
                this.id = id;
            }

        }

    }
}

