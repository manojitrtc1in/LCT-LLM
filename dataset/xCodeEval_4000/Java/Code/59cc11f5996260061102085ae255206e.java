import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.HashSet;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Set;
import java.util.NoSuchElementException;
import java.math.BigInteger;
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
}

class TaskC {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.readInt();
        int[] a = new int[n];
        boolean[][] match = new boolean[n][];
        Graph graph = new Graph(n + 2, n * n + 2 * n);
        for (int i = 0; i < n; ++i) {
            match[i] = new boolean[n];
            a[i] = in.readInt();
        }
        int oddCount = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 1) oddCount++;
            for (int j = 0; j < n; ++j) {
                match[i][j] = IntegerUtils.isPrime(a[i] + a[j]);
            }
        }
        if (oddCount * 2 != n) {
            out.printLine("Impossible");
            return;
        }
        int source = 0;
        int target = n + 1;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 1) {
                graph.addFlowEdge(source, i + 1, 2);
            } else {
                graph.addFlowEdge(i + 1, target, 2);
            }
            if (a[i] % 2 == 0) continue;
            for (int j = 0; j < n; ++j) {
                if (a[j] % 2 == 1) continue;
                if (match[i][j]) {
                    graph.addFlowEdge(i + 1, j + 1, 1);
                }
            }
        }
        long flow = MaxFlow.dinic(graph, source, target);
        if (flow != n) {
            out.printLine("Impossible");
            return;
        }
        Graph conGraph = new BidirectionalGraph(n, n);
        RecursiveIndependentSetSystem dsu = new RecursiveIndependentSetSystem(n);
        int numEdgesAdded = 0;
        for (int edgeId = 0; edgeId < graph.edgeCount(); ++edgeId) {
            Edge edge = graph.edge(edgeId);
            if (edge.getSource() == source || edge.getSource() == target) continue;
            if (edge.getDestination() == source || edge.getDestination() == target) continue;
            if (!match[edge.getSource() - 1][edge.getDestination() - 1]) continue;
            if (a[edge.getSource() - 1] % 2 == 0) continue;
            if (graph.flow(edgeId) == 1) {
                int u = edge.getSource() - 1;
                int v = edge.getDestination() - 1;
                conGraph.addSimpleEdge(u, v);
                ++numEdgesAdded;
                dsu.join(u, v);
            }
        }
        int numGroups = getNumGroups(dsu, n);
        boolean[] used = ArrayUtils.createArray(n, false);
        out.printLine(numGroups);
        for (int v = 0; v < n; ++v) {
            if (used[v]) continue;
            List<Integer> ids = new ArrayList<>();
            GraphAlgorithms.dfs(conGraph, v, used, ids);
            out.print(ids.size());
            for (Integer u : ids) {
                out.print(" ");
                out.print(u + 1);
            }
            for (int i = 0; i < ids.size(); ++i) {
                int aa = ids.get(i);
                int b = ids.get((i + 1) % ids.size());
                if (!match[aa][b]) {
                    throw new RuntimeException();
                }
            }
            out.printLine();
        }
    }

    private int getNumGroups(RecursiveIndependentSetSystem dsu, int n) {
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < n; ++i) {
            set.add(dsu.get(i));
        }
        return set.size();
    }

}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private SpaceCharFilter filter;

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
        while (isSpaceChar(c))
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
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public boolean isSpaceChar(int c) {
        if (filter != null)
            return filter.isSpaceChar(c);
        return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public interface SpaceCharFilter {
        public boolean isSpaceChar(int ch);
    }
}

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public void print(Object...objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(objects[i]);
        }
    }

    public void printLine() {
        writer.println();
    }

    public void printLine(Object...objects) {
        print(objects);
        writer.println();
    }

    public void close() {
        writer.close();
    }

    public void print(int i) {
        writer.print(i);
    }

    public void printLine(int i) {
        writer.println(i);
    }
}

class Graph {
    public static final int REMOVED_BIT = 0;

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
        ensureEdgeCapacity(edgeCount + 1);
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

    public final int addFlowWeightedEdge(int from, int to, long weight, long capacity) {
        if (capacity == 0) {
            return addEdge(from, to, weight, 0, -1);
        } else {
            int lastEdgeCount = edgeCount;
            addEdge(to, from, -weight, 0, lastEdgeCount + entriesPerEdge());
            return addEdge(from, to, weight, capacity, lastEdgeCount);
        }
    }

    protected int entriesPerEdge() {
        return 1;
    }

    public final int addFlowEdge(int from, int to, long capacity) {
        return addFlowWeightedEdge(from, to, 0, capacity);
    }

    public final int addWeightedEdge(int from, int to, long weight) {
        return addFlowWeightedEdge(from, to, weight, 0);
    }

    public final int addSimpleEdge(int from, int to) {
        return addWeightedEdge(from, to, 0);
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

    public final int source(int id) {
        return from[id];
    }

    public final int destination(int id) {
        return to[id];
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

    protected final void initEdges() {
        if (edges == null) {
            edges = new Edge[from.length];
            for (int i = 0; i < edgeCount; i++)
                edges[i] = createEdge(i);
        }
    }

    public final boolean flag(int id, int bit) {
        return (flags[id] >> bit & 1) != 0;
    }

    public final void setFlag(int id, int bit) {
        flags[id] |= 1 << bit;
    }

    public final void removeEdge(int id) {
        setFlag(id, REMOVED_BIT);
    }

    public final boolean isRemoved(int id) {
        return flag(id, REMOVED_BIT);
    }

    public final Iterable<Edge> outbound(final int id) {
        initEdges();
        return new Iterable<Edge>() {
            public Iterator<Edge> iterator() {
                return new EdgeIterator(id, firstOutbound, nextOutbound);
            }
        };
    }

    protected void ensureEdgeCapacity(int size) {
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

        public int getSource() {
            return source(id);
        }

        public int getDestination() {
            return destination(id);
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

class IntegerUtils {

    public static boolean isPrime(long number) {
        if (number < 2)
            return false;
        for (long i = 2; i * i <= number; i++) {
            if (number % i == 0)
                return false;
        }
        return true;
    }

}

class MaxFlow {
    private final Graph graph;
    private int source;
    private int destination;
    private int[] queue;
    private int[] distance;
    private int[] nextEdge;

    private MaxFlow(Graph graph, int source, int destination) {
        this.graph = graph;
        this.source = source;
        this.destination = destination;
        int vertexCount = graph.vertexCount();
        queue = new int[vertexCount];
        distance = new int[vertexCount];
        nextEdge = new int[vertexCount];
    }

    public static long dinic(Graph graph, int source, int destination) {
        return new MaxFlow(graph, source, destination).dinic();
    }

    private long dinic() {
        long totalFlow = 0;
        while (true) {
            edgeDistances();
            if (distance[destination] == -1)
                break;
            Arrays.fill(nextEdge, -2);
            totalFlow += dinicImpl(source, Long.MAX_VALUE);
        }
        return totalFlow;
    }

    private void edgeDistances() {
        Arrays.fill(distance, -1);
        distance[source] = 0;
        int size = 1;
        queue[0] = source;
        for (int i = 0; i < size; i++) {
            int current = queue[i];
            int id = graph.firstOutbound(current);
            while (id != -1) {
                if (graph.capacity(id) != 0) {
                    int next = graph.destination(id);
                    if (distance[next] == -1) {
                        distance[next] = distance[current] + 1;
                        queue[size++] = next;
                    }
                }
                id = graph.nextOutbound(id);
            }
        }
    }

    private long dinicImpl(int source, long flow) {
        if (source == destination)
            return flow;
        if (flow == 0 || distance[source] == distance[destination])
            return 0;
        int id = nextEdge[source];
        if (id == -2)
            nextEdge[source] = id = graph.firstOutbound(source);
        long totalPushed = 0;
        while (id != -1) {
            int nextDestinationID = graph.destination(id);
            if (graph.capacity(id) != 0 && distance[nextDestinationID] == distance[source] + 1) {
                long pushed = dinicImpl(nextDestinationID, Math.min(flow, graph.capacity(id)));
                if (pushed != 0) {
                    graph.pushFlow(id, pushed);
                    flow -= pushed;
                    totalPushed += pushed;
                    if (flow == 0)
                        return totalPushed;
                }
            }
            nextEdge[source] = id = graph.nextOutbound(id);
        }
        return totalPushed;
    }
}

class BidirectionalGraph extends Graph {
    public int[] transposedEdge;

    public BidirectionalGraph(int vertexCount, int edgeCapacity) {
        super(vertexCount, 2 * edgeCapacity);
        transposedEdge = new int[2 * edgeCapacity];
    }

    public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
        int lastEdgeCount = edgeCount;
        super.addEdge(fromID, toID, weight, capacity, reverseEdge);
        super.addEdge(toID, fromID, weight, capacity, reverseEdge == -1 ? -1 : reverseEdge + 1);
        this.transposedEdge[lastEdgeCount] = lastEdgeCount + 1;
        this.transposedEdge[lastEdgeCount + 1] = lastEdgeCount;
        return lastEdgeCount;
    }

    protected int entriesPerEdge() {
        return 2;
    }

    protected void ensureEdgeCapacity(int size) {
        if (size > edgeCapacity()) {
            super.ensureEdgeCapacity(size);
            transposedEdge = resize(transposedEdge, edgeCapacity());
        }
    }
}

class RecursiveIndependentSetSystem implements IndependentSetSystem {
    private final int[] color;
    private final int[] rank;
    private int setCount;
    private Listener listener;

    public RecursiveIndependentSetSystem(int size) {
        color = new int[size];
        rank = new int[size];
        for (int i = 0; i < size; i++)
            color[i] = i;
        setCount = size;
    }

    public boolean join(int first, int second) {
        first = get(first);
        second = get(second);
        if (first == second)
            return false;
        if (rank[first] < rank[second]) {
            int temp = first;
            first = second;
            second = temp;
        } else if (rank[first] == rank[second])
            rank[first]++;
        setCount--;
        color[second] = first;
        if (listener != null)
            listener.joined(second, first);
        return true;
    }

    public int get(int index) {
        if (color[index] == index)
            return index;
        return color[index] = get(color[index]);
    }

}

interface Edge {
    public int getSource();
    public int getDestination();
}

class ArrayUtils {

    public static boolean[] createArray(int count, boolean value) {
        boolean[] array = new boolean[count];
        Arrays.fill(array, value);
        return array;
    }

}

class GraphAlgorithms {

    public static void dfs(Graph graph, int v, boolean[] used, List<Integer> visited) {
        used[v] = true;
        for (Edge edge : graph.outbound(v)) {
            if (!used[edge.getDestination()]) {
                dfs(graph, edge.getDestination(), used, visited);
            }
        }
        visited.add(v);
    }
}

interface IndependentSetSystem {

    public static interface Listener {
        public void joined(int joinedRoot, int root);
    }
}

