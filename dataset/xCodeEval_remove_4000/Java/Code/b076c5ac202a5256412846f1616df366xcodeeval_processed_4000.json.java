import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.InputMismatchException;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            Thread lolka = new Thread(null, new Runnable() {

                final int cntLetters = 'v' - 'a' + 1;
                int n;
                id7 graph;

                int[] sizeTree;
                int[] height;

                int[] id0;
                int[] id3;
                int[] answer;

                id15[] allVertices;

                private void dfs(int v, int p, id15 hardVertices) {
                    int id10 = -1;
                    {
                        {
                            for (int i = graph.firstOutbound(v); i != -1; i = graph.nextOutbound(i)) {
                                if (graph.destination(i) == p) {
                                    continue;
                                }
                                if (id10 == -1 ||
                                        sizeTree[graph.destination(id10)] < sizeTree[graph.destination(i)]) {
                                    id10 = i;
                                }
                            }
                            if (id10 == -1) {
                                hardVertices.add(v);
                                id3[id0[v]] = Math.max(id3[id0[v]], height[v]);
                                return;
                            }
                        }
                        for (int i = graph.firstOutbound(v); i != -1; i = graph.nextOutbound(i)) {
                            {
                                if (graph.destination(i) == p || i == id10) {
                                    continue;
                                }
                                id0[graph.destination(i)] = id0[v] ^ (1 << graph.weight(i));
                            }
                            id15 dfs = new id15(sizeTree[graph.destination(i)]);
                            dfs(graph.destination(i), v, dfs);
                            for (int j = 0; j < dfs.size(); j++) {
                                id3[this.id0[dfs.get(j)]] = -1;
                            }
                            allVertices[i] = dfs;
                        }

                        id0[graph.destination(id10)] = id0[v] ^ (1 << graph.weight(id10));
                    }
                    dfs(graph.destination(id10), v, hardVertices);
                    {
                        answer[v] = Math.max(answer[v], answer[graph.destination(id10)]);
                    }

                    for (int i = graph.firstOutbound(v); i != -1; i = graph.nextOutbound(i)) {
                        if (graph.destination(i) == p || i == id10) {
                            continue;
                        }
                        answer[v] = Math.max(answer[v], answer[graph.destination(i)]);
                        id15 dfs = allVertices[i];
                        allVertices[i] = null;
                        for (int j = 0; j < dfs.size(); j++) {
                            int to = dfs.get(j);
                            int msk = this.id0[to];
                            answer[v] = Math.max(answer[v], getAns(msk, height[to], height[v]));
                        }
                        for (int j = 0; j < dfs.size(); j++) {
                            int to = dfs.get(j);
                            int msk = this.id0[to];
                            id3[msk] = Math.max(id3[msk], height[to]);
                            hardVertices.add(to);
                        }
                    }

                    answer[v] = Math.max(answer[v], getAns(id0[v], height[v], height[v]));
                    id3[id0[v]] = Math.max(id3[id0[v]], height[v]);
                    hardVertices.add(v);

                }

                private int getAns(int msk, int id6, int id17) {
                    int res = 0;
                    for (int bitPos = -1; bitPos < cntLetters; bitPos++) {
                        int id13 = msk ^ (bitPos == -1 ? 0 : 1 << bitPos);
                        int tagHeight = id3[id13];
                        if (tagHeight != -1) {
                            res = Math.max(res, tagHeight + id6 - 2 * id17);
                        }
                    }
                    return res;
                }

                private void init(int v, int p) {
                    sizeTree[v] = 1;
                    for (int i = graph.firstOutbound(v); i != -1; i = graph.nextOutbound(i)) {
                        int to = graph.destination(i);
                        if (to == p) {
                            continue;
                        }
                        height[to] = height[v] + 1;
                        init(to, v);
                        sizeTree[v] += sizeTree[to];
                    }
                }


                public void run() {
                    

                    n = in.readInt();
                    graph = new id7(n, n - 1);
                    for (int v = 1; v < n; v++) {
                        int to = in.readInt() - 1;
                        int w = in.readCharacter() - 'a';
                        graph.id1(v, to, w);
                    }
                


                


                    sizeTree = new int[n];
                    height = new int[n];
                    init(0, -1);

                    answer = new int[n];
                    id3 = new int[1 << cntLetters];
                    Arrays.fill(id3, -1);
                    id0 = new int[n];
                    allVertices = new id15[2 * n];
                    id15 res = new id15(n);
                    dfs(0, -1, res);
                    out.printLine(answer);
                
                }
            }, "LOLKA", 256 * 1024 * 1024);
            lolka.start();
            try {
                lolka.join();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
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
            id12(edgeCount + 1);
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
                int id9 = edgeCount;
                addEdge(to, from, -weight, 0, id9 + id11());
                return addEdge(from, to, weight, capacity, id9);
            }
        }

        protected int id11() {
            return 1;
        }

        public final int id1(int from, int to, long weight) {
            return id8(from, to, weight, 0);
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

        public final long weight(int id) {
            if (weight == null) {
                return 0;
            }
            return weight[id];
        }

        public final boolean flag(int id, int bit) {
            return ((flags[id] >> bit) & 1) != 0;
        }

        public final boolean isRemoved(int id) {
            return flag(id, id18);
        }

        protected void id12(int size) {
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

    static interface IntList extends id14 {
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

    static class id7 extends Graph {
        public int[] id2;

        public id7(int vertexCount) {
            this(vertexCount, vertexCount);
        }

        public id7(int vertexCount, int edgeCapacity) {
            super(vertexCount, 2 * edgeCapacity);
            id2 = new int[2 * edgeCapacity];
        }


        public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
            int id9 = edgeCount;
            super.addEdge(fromID, toID, weight, capacity, reverseEdge);
            super.addEdge(toID, fromID, weight, capacity, (reverseEdge == -1) ? -1 : (reverseEdge + 1));
            this.id2[id9] = id9 + 1;
            this.id2[id9 + 1] = id9;
            return id9;
        }


        protected int id11() {
            return 2;
        }


        protected void id12(int size) {
            if (size > edgeCapacity()) {
                super.id12(size);
                id2 = resize(id2, edgeCapacity());
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

    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static interface id14 extends IntCollection {
    }

    static class id15 extends id4 implements IntList {
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
                if ((c < '0') || (c > '9')) {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id5(c));
            return res * sgn;
        }

        public boolean id5(int c) {
            if (filter != null) {
                return filter.id5(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return (c == ' ') || (c == '\n') || (c == '\r') || (c == '\t') || (c == -1);
        }

        public char readCharacter() {
            int c = read();
            while (id5(c)) {
                c = read();
            }
            return (char) c;
        }

        public interface id16 {
            public boolean id5(int ch);

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

    }

    static interface Edge {
    }
}

