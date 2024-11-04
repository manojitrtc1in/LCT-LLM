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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n;
            int m;
            int k;
            Graph graph;
            final long inf = (int) 1e18;

            n = in.readInt();
            m = in.readInt();
            k = in.readInt();
            graph = new BidirectionalGraph(n, m);
            for (int iter = 0; iter < m; iter++) {
                int v = in.readInt() - 1;
                int to = in.readInt() - 1;
                int w = in.readInt();
                graph.addWeightedEdge(v, to, w);
            }

            long[] dist = new long[n];
            Arrays.fill(dist, inf);
            IntSplaySet set = new IntSplaySet(new IntComparator() {

                public int compare(int first, int second) {
                    int res = Long.compare(dist[first], dist[second]);
                    if (res != 0) {
                        return res;
                    }
                    return first - second;
                }
            });
            boolean[] isStore = new boolean[n];
            for (int i = 0; i < k; i++) {
                int v = in.readInt() - 1;
                isStore[v] = true;
                dist[v] = 0;
                set.add(v);
            }

            while (!set.isEmpty()) {
                int v = set.first();
                set.remove(v);
                for (int id = graph.firstOutbound(v); id != -1; id = graph.nextOutbound(id)) {
                    int to = graph.destination(id);
                    long w = graph.weight(id);
                    if (dist[to] > dist[v] + w) {
                        set.remove(to);
                        dist[to] = dist[v] + w;
                        set.add(to);
                    }
                }
            }

            long d = inf;
            for (int v = 0; v < n; v++) {
                if (dist[v] != 0) {
                    if (isStore[v]) {
                        throw new RuntimeException();
                    }
                    d = Math.min(d, dist[v]);
                }
            }
            if (d == inf) {
                out.printLine("-1");
            } else {
                out.printLine(d);
            }
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

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
            while (isSpaceChar(c)) {
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
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return (c == ' ') || (c == '\n') || (c == '\r') || (c == '\t') || (c == -1);
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static class Graph {
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
            ensureEdgeCapacity(edgeCount + 1);
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

        public final int addWeightedEdge(int from, int to, long weight) {
            return addFlowWeightedEdge(from, to, weight, 0);
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
            return flag(id, REMOVED_BIT);
        }

        protected void ensureEdgeCapacity(int size) {
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

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static interface IntSet extends IntCollection {
    }

    static class IntSplaySet implements IntSet {
        protected int[] value;
        protected int[] left;
        protected int[] right;
        protected int[] parent;
        private int[] size;
        private final IntComparator comparator;
        private int nextFree;
        protected int root = -1;

        public IntSplaySet() {
            this(null);
        }

        public IntSplaySet(IntComparator comparator) {
            this(comparator, 5);
        }

        public IntSplaySet(int capacity) {
            this(null, capacity);
        }

        public IntSplaySet(IntComparator comparator, int capacity) {
            this.comparator = comparator;
            value = new int[capacity];
            left = new int[capacity];
            right = new int[capacity];
            parent = new int[capacity];
            size = new int[capacity];
        }

        protected final int compare(int first, int second) {
            if (comparator == null) {
                return (first < second) ? -1 : ((first == second) ? 0 : 1);
            } else {
                return comparator.compare(first, second);
            }
        }


        public IntIterator intIterator() {
            return new IntIterator() {
                private boolean first = true;
                private boolean exhausted = root == -1;


                public int value() throws NoSuchElementException {
                    if (first) {
                        if (root == -1) {
                            throw new NoSuchElementException();
                        }
                        int leftmost = leftmost(root);
                        splay(leftmost);
                        first = false;
                    }
                    return value[root];
                }


                public boolean advance() throws NoSuchElementException {
                    if ((root == -1) || exhausted) {
                        throw new NoSuchElementException();
                    }
                    int next = leftmost(right[root]);
                    if (next == -1) {
                        exhausted = true;
                        return false;
                    }
                    splay(next);
                    return true;
                }


                public boolean isValid() {
                    return !exhausted;
                }


                public void remove() throws NoSuchElementException {
                    throw new UnsupportedOperationException();
                }
            };
        }

        private void splay(int node) {
            if (node == -1) {
                return;
            }
            while (parent[node] != -1) {
                if (parent[parent[node]] == -1) {
                    rotate(node);
                } else if ((left[parent[node]] == node) == (left[parent[parent[node]]] == parent[node])) {
                    rotate(parent[node]);
                    rotate(node);
                } else {
                    rotate(node);
                    rotate(node);
                }
            }
            this.root = node;
        }

        private void rotate(int node) {
            int cParent = parent[node];
            if (node == left[cParent]) {
                setLeft(cParent, right[node]);
                if (parent[cParent] != -1) {
                    if (cParent == left[parent[cParent]]) {
                        setLeft(parent[cParent], node);
                    } else {
                        setRight(parent[cParent], node);
                    }
                } else {
                    parent[node] = -1;
                }
                setRight(node, cParent);
            } else {
                setRight(cParent, left[node]);
                if (parent[cParent] != -1) {
                    if (cParent == left[parent[cParent]]) {
                        setLeft(parent[cParent], node);
                    } else {
                        setRight(parent[cParent], node);
                    }
                } else {
                    parent[node] = -1;
                }
                setLeft(node, cParent);
            }
            update(cParent);
            update(node);
        }

        protected void update(int node) {
            size[node] = size(left[node]) + size(right[node]) + 1;
        }

        protected int size(int node) {
            if (node != -1) {
                return size[node];
            }
            return 0;
        }

        protected int leftmost(int root) {
            if (root == -1) {
                return -1;
            }
            while (left[root] != -1) {
                root = left[root];
            }
            return root;
        }

        protected int rightmost(int root) {
            if (root == -1) {
                return -1;
            }
            while (right[root] != -1) {
                root = right[root];
            }
            return root;
        }


        public int size() {
            return size(root);
        }


        public void add(int value) {
            if (contains(value)) {
                return;
            }
            ensureCapacity(nextFree + 1);
            IntSplaySet.Split roots = split(root, value);
            setLeft(nextFree, roots.left);
            setRight(nextFree, roots.right);
            parent[nextFree] = -1;
            this.value[nextFree] = value;
            update(nextFree);
            root = nextFree++;
        }

        private void merge(int left, int right) {
            if (left == -1) {
                root = right;
            } else if (right == -1) {
                root = left;
            } else {
                splay(rightmost(left));
                setRight(root, right);
                update(root);
            }
        }

        private void setLeft(int node, int child) {
            left[node] = child;
            if (child != -1) {
                parent[child] = node;
            }
        }

        private void setRight(int node, int child) {
            right[node] = child;
            if (child != -1) {
                parent[child] = node;
            }
        }

        protected IntSplaySet.Split split(int root, int value) {
            if (root == -1) {
                return new IntSplaySet.Split();
            }
            int compare = compare(this.value[root], value);
            if (compare < 0) {
                IntSplaySet.Split result = split(right[root], value);
                setRight(root, result.left);
                result.left = root;
                update(root);
                behead(root);
                return result;
            } else if (compare > 0) {
                IntSplaySet.Split result = split(left[root], value);
                setLeft(root, result.right);
                result.right = root;
                update(root);
                behead(root);
                return result;
            } else {
                IntSplaySet.Split result = new IntSplaySet.Split();
                result.left = left[root];
                result.right = right[root];
                behead(left[root]);
                behead(right[root]);
                return result;
            }
        }

        protected int ensureCapacity(int capacity) {
            if (parent.length < capacity) {
                capacity = Math.max(2 * parent.length, capacity);
                left = Arrays.copyOf(left, capacity);
                right = Arrays.copyOf(right, capacity);
                parent = Arrays.copyOf(parent, capacity);
                size = Arrays.copyOf(size, capacity);
                value = Arrays.copyOf(value, capacity);
                return capacity;
            }
            return parent.length;
        }


        public boolean remove(int value) {
            if (contains(value)) {
                behead(left[root]);
                behead(right[root]);
                merge(left[root], right[root]);
                return true;
            }
            return false;
        }


        public boolean contains(int value) {
            int node = root;
            int lastNode = -1;
            while (node != -1) {
                lastNode = node;
                int compare = compare(value, this.value[node]);
                if (compare == 0) {
                    splay(node);
                    return true;
                }
                if (compare < 0) {
                    node = left[node];
                } else {
                    node = right[node];
                }
            }
            if (lastNode != -1) {
                splay(lastNode);
            }
            return false;
        }

        protected void behead(int node) {
            if (node != -1) {
                parent[node] = -1;
            }
        }

        protected static class Split {
            protected int left = -1;
            protected int right = -1;

        }

    }

    static interface IntComparator {
        public int compare(int first, int second);

    }

    static interface Edge {
    }

    static class BidirectionalGraph extends Graph {
        public int[] transposedEdge;

        public BidirectionalGraph(int vertexCount) {
            this(vertexCount, vertexCount);
        }

        public BidirectionalGraph(int vertexCount, int edgeCapacity) {
            super(vertexCount, 2 * edgeCapacity);
            transposedEdge = new int[2 * edgeCapacity];
        }


        public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
            int lastEdgeCount = edgeCount;
            super.addEdge(fromID, toID, weight, capacity, reverseEdge);
            super.addEdge(toID, fromID, weight, capacity, (reverseEdge == -1) ? -1 : (reverseEdge + 1));
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

    static interface IntCollection extends IntStream {
        public int size();

        default public boolean isEmpty() {
            return size() == 0;
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

        default public int first() {
            return intIterator().value();
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
}

