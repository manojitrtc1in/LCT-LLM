import java.io.BufferedWriter;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.*;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }
}

class Task {

    int[] A, delta;
    Integer[] order;
    final int SIZE = 1700, INF=1_000_000_001;
    int j;
    long target;
    boolean canEqual;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.readInt(), q = in.readInt();
        A = IOUtils.id1(in, n);
        delta = new int[n];
        order = new Integer[n];
        for (int i = 0; i < n; i += SIZE)
            build(i, Math.min(i + SIZE, n));
        while (q-- > 0) {
            int t = in.readInt();
            if (t == 1) {
                int l = in.readInt() - 1, r = in.readInt() - 1, x = in
                        .readInt();
                f1(l, r, x);
            } else {
                int y = in.readInt(), f2 = f2(y, out);
                out.printLine(f2);
            }
        }
    }

    void build(int from, int to) {
        for (int i = from; i < to; i++) {
            A[i] += delta[from];
            if (A[i]>INF) A[i]=INF;
            order[i] = i;
        }
        delta[from] = 0;
        Arrays.sort(order, from, to, new Comparator<Integer>() {
            @Override
            public int compare(Integer first, Integer second) {
                if (A[first] != A[second])
                    return A[first] < A[second] ? -1 : 1;
                return first - second;
            }
        });
    }

    void f1(int l, int r, int x) {
        int sl = l / SIZE, sr = r / SIZE, n = A.length;
        if (sl == sr) {
            for (int i = l; i <= r; i++) {
                A[i] += x;
                if (A[i]>INF) A[i]=INF;
            }
            build(sl * SIZE, Math.min((sl + 1) * SIZE, n));
            return;
        }
        for (int i = l; i < (sl + 1) * SIZE; i++) {
            A[i] += x;
            if (A[i]>INF) A[i]=INF;
        }
        build(sl * SIZE, Math.min((sl + 1) * SIZE, n));
        for (int i = sr * SIZE; i <= r; i++) {
            A[i] += x;
            if (A[i]>INF) A[i]=INF;
        }
        build(sr * SIZE, Math.min((sr + 1) * SIZE, n));
        for (int i = sl + 1; i < sr; i++) {
            delta[i * SIZE] += x;
            if (delta[i*SIZE]>INF) delta[i*SIZE]=INF;
        }
    }

    int f2(int y, OutputWriter out) {
        if (y>INF) return -1;
        int n = A.length, max = -1, min = -1;
        canEqual=true;
        for (int i = 0; i < n && min==-1; i += SIZE) {
            j = Math.min(i + SIZE, n);
            target = y - delta[i];
            int from = binarySearch(i, j);
            if (from<j && A[order[from]] == target)
                min = from;
        }
        canEqual=false;
        for (int i=(n-1)/SIZE*SIZE; i>=0 && max==-1; i-=SIZE) {
            j = Math.min(i + SIZE, n);
            target = y - delta[i];
            int to = binarySearch(i, j) - 1;
            if (to>=i && A[order[to]] == target)
                max = to;
        }
        return max == -1 ? -1 : order[max] - order[min];
    }

    int binarySearch(int from, int to) {
        while (from < to) {
            int argument = from + (to - from) / 2;
            long a=A[order[argument]];
            if (argument==j || (canEqual ? a >= target : a > target))
                to = argument;
            else
                from = argument + 1;
        }
        return from;
    }
}

class Graph {
    public static final int id28 = 0;

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

    public static Graph createGraph(int vertexCount, int[] from, int[] to) {
        Graph graph = new Graph(vertexCount, from.length);
        for (int i = 0; i < from.length; i++)
            graph.id18(from[i], to[i]);
        return graph;
    }

    public static Graph id2(int vertexCount, int[] from,
            int[] to, long[] weight) {
        Graph graph = new Graph(vertexCount, from.length);
        for (int i = 0; i < from.length; i++)
            graph.id0(from[i], to[i], weight[i]);
        return graph;
    }

    public static Graph id21(int vertexCount, int[] from, int[] to,
            long[] capacity) {
        Graph graph = new Graph(vertexCount, from.length * 2);
        for (int i = 0; i < from.length; i++)
            graph.id10(from[i], to[i], capacity[i]);
        return graph;
    }

    public static Graph id12(int vertexCount, int[] from,
            int[] to, long[] weight, long[] capacity) {
        Graph graph = new Graph(vertexCount, from.length * 2);
        for (int i = 0; i < from.length; i++)
            graph.id13(from[i], to[i], weight[i], capacity[i]);
        return graph;
    }

    public static Graph createTree(int[] parent) {
        Graph graph = new Graph(parent.length + 1, parent.length);
        for (int i = 0; i < parent.length; i++)
            graph.id18(parent[i], i + 1);
        return graph;
    }

    public int addEdge(int fromID, int toID, long weight, long capacity,
            int reverseEdge) {
        id19(edgeCount + 1);
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

    public final int id13(int from, int to, long weight,
            long capacity) {
        if (capacity == 0) {
            return addEdge(from, to, weight, 0, -1);
        } else {
            int id16 = edgeCount;
            addEdge(to, from, -weight, 0, id16 + id17());
            return addEdge(from, to, weight, capacity, id16);
        }
    }

    protected int id17() {
        return 1;
    }

    public final int id10(int from, int to, long capacity) {
        return id13(from, to, 0, capacity);
    }

    public final int id0(int from, int to, long weight) {
        return id13(from, to, weight, 0);
    }

    public final int id18(int from, int to) {
        return id0(from, to, 0);
    }

    public final int vertexCount() {
        return vertexCount;
    }

    public final int edgeCount() {
        return edgeCount;
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

    public final int firstInbound(int vertex) {
        initInbound();
        int id = firstInbound[vertex];
        while (id != -1 && isRemoved(id))
            id = nextInbound[id];
        return id;
    }

    public final int nextInbound(int id) {
        initInbound();
        id = nextInbound[id];
        while (id != -1 && isRemoved(id))
            id = nextInbound[id];
        return id;
    }

    public final int source(int id) {
        return from[id];
    }

    public final int destination(int id) {
        return to[id];
    }

    public final long weight(int id) {
        if (weight == null)
            return 0;
        return weight[id];
    }

    public final long capacity(int id) {
        if (capacity == null)
            return 0;
        return capacity[id];
    }

    public final long flow(int id) {
        if (reverseEdge == null)
            return 0;
        return capacity[reverseEdge[id]];
    }

    public final void pushFlow(int id, long flow) {
        if (flow == 0)
            return;
        if (flow > 0) {
            if (capacity(id) < flow)
                throw new IllegalArgumentException("Not enough capacity");
        } else {
            if (flow(id) < -flow)
                throw new IllegalArgumentException("Not enough capacity");
        }
        capacity[id] -= flow;
        capacity[reverseEdge[id]] += flow;
    }

    public int transposed(int id) {
        return -1;
    }

    public final int reverse(int id) {
        if (reverseEdge == null)
            return -1;
        return reverseEdge[id];
    }

    public final void addVertices(int count) {
        id15(vertexCount + count);
        Arrays.fill(firstOutbound, vertexCount, vertexCount + count, -1);
        if (firstInbound != null)
            Arrays.fill(firstInbound, vertexCount, vertexCount + count, -1);
        vertexCount += count;
    }

    protected final void initEdges() {
        if (edges == null) {
            edges = new Edge[from.length];
            for (int i = 0; i < edgeCount; i++)
                edges[i] = createEdge(i);
        }
    }

    public final void removeVertex(int vertex) {
        int id = firstOutbound[vertex];
        while (id != -1) {
            removeEdge(id);
            id = nextOutbound[id];
        }
        initInbound();
        id = firstInbound[vertex];
        while (id != -1) {
            removeEdge(id);
            id = nextInbound[id];
        }
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

    public final void setFlag(int id, int bit) {
        flags[id] |= 1 << bit;
    }

    public final void removeFlag(int id, int bit) {
        flags[id] &= -1 - (1 << bit);
    }

    public final void removeEdge(int id) {
        setFlag(id, id28);
    }

    public final void restoreEdge(int id) {
        removeFlag(id, id28);
    }

    public final boolean isRemoved(int id) {
        return flag(id, id28);
    }

    public final Iterable<Edge> outbound(final int id) {
        initEdges();
        return new Iterable<Edge>() {
            public Iterator<Edge> iterator() {
                return new EdgeIterator(id, firstOutbound, nextOutbound);
            }
        };
    }

    public final Iterable<Edge> inbound(final int id) {
        initEdges();
        initInbound();
        return new Iterable<Edge>() {
            public Iterator<Edge> iterator() {
                return new EdgeIterator(id, firstInbound, nextInbound);
            }
        };
    }

    protected void id19(int size) {
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

    private void id15(int size) {
        if (firstOutbound.length < size) {
            int newSize = Math.max(size, 2 * from.length);
            firstOutbound = resize(firstOutbound, newSize);
            if (firstInbound != null)
                firstInbound = resize(firstInbound, newSize);
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

        public int getSource() {
            return source(id);
        }

        public int getDestination() {
            return destination(id);
        }

        public long getWeight() {
            return weight(id);
        }

        public long getCapacity() {
            return capacity(id);
        }

        public long getFlow() {
            return flow(id);
        }

        public void pushFlow(long flow) {
            Graph.this.pushFlow(id, flow);
        }

        public boolean getFlag(int bit) {
            return flag(id, bit);
        }

        public void setFlag(int bit) {
            Graph.this.setFlag(id, bit);
        }

        public void removeFlag(int bit) {
            Graph.this.removeFlag(id, bit);
        }

        public int id6() {
            return transposed(id);
        }

        public Edge id4() {
            int reverseID = id6();
            if (reverseID == -1)
                return null;
            initEdges();
            return edge(reverseID);
        }

        public int id22() {
            return reverse(id);
        }

        public Edge id23() {
            int reverseID = id22();
            if (reverseID == -1)
                return null;
            initEdges();
            return edge(reverseID);
        }

        public int getID() {
            return id;
        }

        public void remove() {
            removeEdge(id);
        }

        public void restore() {
            restoreEdge(id);
        }
    }

    public class EdgeIterator implements Iterator<Edge> {
        private int edgeID;
        private final int[] next;
        private int lastID = -1;

        public EdgeIterator(int id, int[] first, int[] next) {
            this.next = next;
            edgeID = nextEdge(first[id]);
        }

        private int nextEdge(int id) {
            while (id != -1 && isRemoved(id))
                id = next[id];
            return id;
        }

        public boolean hasNext() {
            return edgeID != -1;
        }

        public Edge next() {
            if (edgeID == -1)
                throw new NoSuchElementException();
            lastID = edgeID;
            edgeID = nextEdge(next[lastID]);
            return edges[lastID];
        }

        public void remove() {
            if (lastID == -1)
                throw new IllegalStateException();
            removeEdge(lastID);
            lastID = -1;
        }
    }

}

interface Edge {
    public int getSource();

    public int getDestination();

    public long getWeight();

    public long getCapacity();

    public long getFlow();

    public void pushFlow(long flow);

    public boolean getFlag(int bit);

    public void setFlag(int bit);

    public void removeFlag(int bit);

    public int id6();

    public Edge id4();

    public int id22();

    public Edge id23();

    public int getID();

    public void remove();

    public void restore();
}

class id9 extends Graph {
    public int[] id3;

    public id9(int vertexCount) {
        this(vertexCount, vertexCount);
    }

    public id9(int vertexCount, int edgeCapacity) {
        super(vertexCount, 2 * edgeCapacity);
        id3 = new int[2 * edgeCapacity];
    }

    public static id9 createGraph(int vertexCount, int[] from,
            int[] to) {
        id9 graph = new id9(vertexCount,
                from.length);
        for (int i = 0; i < from.length; i++)
            graph.id18(from[i], to[i]);
        return graph;
    }

    public static id9 id2(int vertexCount,
            int[] from, int[] to, long[] weight) {
        id9 graph = new id9(vertexCount,
                from.length);
        for (int i = 0; i < from.length; i++)
            graph.id0(from[i], to[i], weight[i]);
        return graph;
    }

    public static id9 id21(int vertexCount,
            int[] from, int[] to, long[] capacity) {
        id9 graph = new id9(vertexCount,
                from.length * 2);
        for (int i = 0; i < from.length; i++)
            graph.id10(from[i], to[i], capacity[i]);
        return graph;
    }

    public static id9 id12(int vertexCount,
            int[] from, int[] to, long[] weight, long[] capacity) {
        id9 graph = new id9(vertexCount,
                from.length * 2);
        for (int i = 0; i < from.length; i++)
            graph.id13(from[i], to[i], weight[i], capacity[i]);
        return graph;
    }

    @Override
    public int addEdge(int fromID, int toID, long weight, long capacity,
            int reverseEdge) {
        int id16 = edgeCount;
        super.addEdge(fromID, toID, weight, capacity, reverseEdge);
        super.addEdge(toID, fromID, weight, capacity, reverseEdge == -1 ? -1
                : reverseEdge + 1);
        this.id3[id16] = id16 + 1;
        this.id3[id16 + 1] = id16;
        return id16;
    }

    @Override
    protected int id17() {
        return 2;
    }

    @Override
    public final int transposed(int id) {
        return id3[id];
    }

    @Override
    protected void id19(int size) {
        if (size > edgeCapacity()) {
            super.id19(size);
            id3 = resize(id3, edgeCapacity());
        }
    }
}

class IOUtils {
    public static long[] id14(InputReader in, int size) {
        long[] array = new long[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readLong();
        return array;
    }

    public static int[] id1(InputReader in, int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readInt();
        return array;
    }
}

interface Function<A, V> {
    public abstract V value(A argument);
}

class IntegerUtils {

    public static List<Pair<Long, Integer>> factorize(long number) {
        List<Pair<Long, Integer>> result = new ArrayList<Pair<Long, Integer>>();
        for (long i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                int power = 0;
                do {
                    power++;
                    number /= i;
                } while (number % i == 0);
                result.add(Pair.makePair(i, power));
            }
        }
        if (number != 1)
            result.add(Pair.makePair(number, 1));
        return result;
    }

    public static List<Long> id26(long number) {
        List<Pair<Long, Integer>> id25 = factorize(number);
        return id11(id25, 0, 1, new ArrayList<Long>());
    }

    private static List<Long> id11(
            List<Pair<Long, Integer>> id25, int index, long current,
            List<Long> result) {
        if (index == id25.size()) {
            result.add(current);
            return result;
        }
        long p = id25.get(index).first;
        int power = id25.get(index).second;
        for (int i = 0; i <= power; i++) {
            id11(id25, index + 1, current, result);
            current *= p;
        }
        return result;
    }
}

class Pair<U, V> implements Comparable<Pair<U, V>> {
    public final U first;
    public final V second;

    public static <U, V> Pair<U, V> makePair(U first, V second) {
        return new Pair<U, V>(first, second);
    }

    private Pair(U first, V second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || getClass() != o.getClass())
            return false;

        Pair pair = (Pair) o;

        return !(first != null ? !first.equals(pair.first) : pair.first != null)
                && !(second != null ? !second.equals(pair.second)
                        : pair.second != null);

    }

    @Override
    public int hashCode() {
        int result = first != null ? first.hashCode() : 0;
        result = 31 * result + (second != null ? second.hashCode() : 0);
        return result;
    }

    public Pair<V, U> swap() {
        return makePair(second, first);
    }

    @Override
    public String toString() {
        return "(" + first + "," + second + ")";
    }

    @SuppressWarnings({ "unchecked" })
    public int compareTo(Pair<U, V> o) {
        int value = ((Comparable<U>) first).compareTo(o.first);
        if (value != 0)
            return value;
        return ((Comparable<V>) second).compareTo(o.second);
    }
}

class InputReader {
    private boolean finished = false;

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private id27 filter;

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

    public int peek() {
        if (numChars == -1)
            return -1;
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                return -1;
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar];
    }

    public int readInt() {
        int c = read();
        while (id8(c))
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
        } while (!id8(c));
        return res * sgn;
    }

    public long readLong() {
        int c = read();
        while (id8(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!id8(c));
        return res * sgn;
    }

    public String readString() {
        int c = read();
        while (id8(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            if (Character.isValidCodePoint(c))
                res.appendCodePoint(c);
            c = read();
        } while (!id8(c));
        return res.toString();
    }

    public boolean id8(int c) {
        if (filter != null)
            return filter.id8(c);
        return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    private String id5() {
        StringBuilder buf = new StringBuilder();
        int c = read();
        while (c != '\n' && c != -1) {
            if (c != '\r')
                buf.appendCodePoint(c);
            c = read();
        }
        return buf.toString();
    }

    public String readLine() {
        String s = id5();
        while (s.trim().length() == 0)
            s = id5();
        return s;
    }

    public String readLine(boolean id24) {
        if (id24)
            return readLine();
        else
            return id5();
    }

    public BigInteger id20() {
        try {
            return new BigInteger(readString());
        } catch (NumberFormatException e) {
            throw new InputMismatchException();
        }
    }

    public char readCharacter() {
        int c = read();
        while (id8(c))
            c = read();
        return (char) c;
    }

    public double readDouble() {
        int c = read();
        while (id8(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        double res = 0;
        while (!id8(c) && c != '.') {
            if (c == 'e' || c == 'E')
                return res * Math.pow(10, readInt());
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        }
        if (c == '.') {
            c = read();
            double m = 1;
            while (!id8(c)) {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, readInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                m /= 10;
                res += (c - '0') * m;
                c = read();
            }
        }
        return res * sgn;
    }

    public boolean id7() {
        int value;
        while (id8(value = peek()) && value != -1)
            read();
        return value == -1;
    }

    public String next() {
        return readString();
    }

    public id27 getFilter() {
        return filter;
    }

    public void setFilter(id27 filter) {
        this.filter = filter;
    }

    public interface id27 {
        public boolean id8(int ch);
    }
}

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
                outputStream)));
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void print(char[] array) {
        writer.print(array);
    }

    public void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(objects[i]);
        }
    }

    public void print(int[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(array[i]);
        }
    }

    public void print(long[] array) {
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

    public void printLine(long[] array) {
        print(array);
        writer.println();
    }

    public void printLine() {
        writer.println();
    }

    public void printLine(Object... objects) {
        print(objects);
        writer.println();
    }

    public void print(char i) {
        writer.print(i);
    }

    public void printLine(char i) {
        writer.println(i);
    }

    public void printLine(char[] array) {
        writer.println(array);
    }

    public void printFormat(String format, Object... objects) {
        writer.printf(format, objects);
    }

    public void close() {
        writer.close();
    }

    public void flush() {
        writer.flush();
    }

    public void print(long i) {
        writer.print(i);
    }

    public void printLine(long i) {
        writer.println(i);
    }

    public void print(int i) {
        writer.print(i);
    }

    public void printLine(int i) {
        writer.println(i);
    }
}

class ArrayUtils {

    public static int[] createOrder(int size) {
        int[] order = new int[size];
        for (int i = 0; i < size; i++)
            order[i] = i;
        return order;
    }

    public static int maxPosition(int[] array) {
        return maxPosition(array, 0, array.length);
    }

    public static int maxPosition(int[] array, int from, int to) {
        if (from >= to)
            return -1;
        int max = array[from];
        int result = from;
        for (int i = from + 1; i < to; i++) {
            if (array[i] > max) {
                max = array[i];
                result = i;
            }
        }
        return result;
    }

}