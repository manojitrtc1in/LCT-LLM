import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.HashMap;
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
        final long base = 179;
        final int maxn = (int) (1e5 + 5);
        final long[] pow = IntegerUtils.generatePowers(base, maxn + 1, Long.MAX_VALUE);
        int n;
        BidirectionalGraph graph;
        int[] sizeSubTree;
        long[] hash;
        Counter<Long> allHashs;
        int answer;
        int answerRoot;

        private void dfs(final int v, final int p) {
            if (answer < allHashs.size() || answer == allHashs.size() && answerRoot > v) {
                answer = allHashs.size();
                answerRoot = v;
            }

            IntArrayList orderIdRids = new IntArrayList();
            for (int i = graph.firstOutbound(v); i != -1; i = graph.nextOutbound(i)) {
                orderIdRids.add(i);
            }
            Sorter.sort(orderIdRids, (i, j) -> Long.compare(hash[graph.destination(i)], hash[graph.destination(j)]));
            long[] suf = new long[orderIdRids.size() + 1];
            suf[orderIdRids.size()] = ')';
            for (int i = orderIdRids.size() - 1; i >= 0; i--) {
                int to = graph.destination(orderIdRids.get(i));
                suf[i] = hash[to] + suf[i + 1] * pow[sizeSubTree[to]];
            }

            long pref = '(';
            int sizePref = 1;
            for (int i = 0; i < orderIdRids.size(); i++) {
                int to = graph.destination(orderIdRids.get(i));
                if (to != p) {
                    long oldHashV = hash[v];
                    long newHashV = pref + suf[i + 1] * pow[sizePref];
                    allHashs.add(oldHashV, -1);
                    allHashs.add(newHashV, 1);
                    hash[v] = newHashV;
                    sizeSubTree[v] = n - sizeSubTree[to];

                    long oldHashTo = hash[to];
                    int oldSizeSubTreeTo = sizeSubTree[to];
                    initHashAndSizeForRoot(to, -1);
                    long newHashTo = hash[to];
                    allHashs.add(oldHashTo, -1);
                    allHashs.add(newHashTo, 1);
                    hash[to] = newHashTo;

                    dfs(to, v);

                    allHashs.add(oldHashV, 1);
                    allHashs.add(newHashV, -1);
                    hash[v] = oldHashV;
                    sizeSubTree[v] = n;

                    allHashs.add(oldHashTo, 1);
                    allHashs.add(newHashTo, -1);
                    hash[to] = oldHashTo;
                    sizeSubTree[to] = oldSizeSubTreeTo;
                }
                pref += hash[to] * pow[sizePref];
                sizePref += sizeSubTree[to];
            }
        }

        private void initHashAndSizeForRoot(int v, int p) {
            IntArrayList orderEdge = new IntArrayList();
            sizeSubTree[v] = 1;
            for (int i = graph.firstOutbound(v); i != -1; i = graph.nextOutbound(i)) {
                int to = graph.destination(i);
                if (to == p) {
                    continue;
                }
                orderEdge.add(i);
                sizeSubTree[v] += sizeSubTree[to];
            }
            Sorter.sort(orderEdge, (i, j) -> Long.compare(hash[graph.destination(i)], hash[graph.destination(j)]));
            hash[v] = '(';
            int size = 1;
            for (int i = 0; i < orderEdge.size(); i++) {
                int to = graph.destination(orderEdge.get(i));
                hash[v] += hash[to] * pow[size];
                size += sizeSubTree[to];
            }
            hash[v] += ')' * pow[size];
        }

        private void initHash(int v, int p) {
            for (int i = graph.firstOutbound(v); i != -1; i = graph.nextOutbound(i)) {
                int to = graph.destination(i);
                if (to == p) {
                    continue;
                }
                initHash(to, v);
            }
            initHashAndSizeForRoot(v, p);
            allHashs.add(hash[v], 1);
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {









            n = in.readInt();
            graph = new BidirectionalGraph(n, n - 1);
            for (int i = 0; i < n - 1; i++) {
                int a = in.readInt() - 1;
                int b = in.readInt() - 1;
                graph.addSimpleEdge(a, b);
            }

            answer = -1;
            answerRoot = -1;
            hash = new long[n];
            sizeSubTree = new int[n];
            allHashs = new Counter<>(n + 5);
            int root = (11392) % n;
            initHash(root, -1);
            dfs(root, -1);
            out.printLine(answerRoot + 1);
        }

    }

    static interface IntReversableCollection extends IntCollection {
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

    static abstract class IntAbstractStream implements IntStream {

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

    static interface Edge {
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

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

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

    static class IntegerUtils {
        public static long[] generatePowers(long base, int count, long mod) {
            long[] result = new long[count];
            if (count != 0) {
                result[0] = 1 % mod;
            }
            for (int i = 1; i < count; i++) {
                result[i] = (result[i - 1] * base) % mod;
            }
            return result;
        }

    }

    static class IntArrayList extends IntAbstractStream implements IntList {
        private int size;
        private int[] data;

        public IntArrayList() {
            this(3);
        }

        public IntArrayList(int capacity) {
            data = new int[capacity];
        }

        public IntArrayList(IntCollection c) {
            this(c.size());
            addAll(c);
        }

        public IntArrayList(IntStream c) {
            this();
            if (c instanceof IntCollection) {
                ensureCapacity(((IntCollection) c).size());
            }
            addAll(c);
        }

        public IntArrayList(IntArrayList c) {
            size = c.size();
            data = c.data.clone();
        }

        public IntArrayList(int[] arr) {
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

        public void set(int index, int value) {
            if (index >= size) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            data[index] = value;
        }

    }

    static interface IntComparator {
        public int compare(int first, int second);

    }

    static class Sorter {
        private static final int INSERTION_THRESHOLD = 16;

        private Sorter() {
        }

        public static void sort(IntList list, IntComparator comparator) {
            quickSort(list, 0, list.size() - 1, (Integer.bitCount(Integer.highestOneBit(list.size()) - 1) * 5) >> 1,
                    comparator);
        }

        private static void quickSort(IntList list, int from, int to, int remaining, IntComparator comparator) {
            if ((to - from) < INSERTION_THRESHOLD) {
                insertionSort(list, from, to, comparator);
                return;
            }
            if (remaining == 0) {
                heapSort(list, from, to, comparator);
                return;
            }
            remaining--;
            int pivotIndex = (from + to) >> 1;
            int pivot = list.get(pivotIndex);
            list.swap(pivotIndex, to);
            int storeIndex = from;
            int equalIndex = to;
            for (int i = from; i < equalIndex; i++) {
                int value = comparator.compare(list.get(i), pivot);
                if (value < 0) {
                    list.swap(storeIndex++, i);
                } else if (value == 0) {
                    list.swap(--equalIndex, i--);
                }
            }
            quickSort(list, from, storeIndex - 1, remaining, comparator);
            for (int i = equalIndex; i <= to; i++) {
                list.swap(storeIndex++, i);
            }
            quickSort(list, storeIndex, to, remaining, comparator);
        }

        private static void heapSort(IntList list, int from, int to, IntComparator comparator) {
            for (int i = ((to + from) - 1) >> 1; i >= from; i--) {
                siftDown(list, i, to, comparator, from);
            }
            for (int i = to; i > from; i--) {
                list.swap(from, i);
                siftDown(list, from, i - 1, comparator, from);
            }
        }

        private static void siftDown(IntList list, int start, int end, IntComparator comparator, int delta) {
            int value = list.get(start);
            while (true) {
                int child = ((start - delta) << 1) + 1 + delta;
                if (child > end) {
                    return;
                }
                int childValue = list.get(child);
                if ((child + 1) <= end) {
                    int otherValue = list.get(child + 1);
                    if (comparator.compare(otherValue, childValue) > 0) {
                        child++;
                        childValue = otherValue;
                    }
                }
                if (comparator.compare(value, childValue) >= 0) {
                    return;
                }
                list.swap(start, child);
                start = child;
            }
        }

        private static void insertionSort(IntList list, int from, int to, IntComparator comparator) {
            for (int i = from + 1; i <= to; i++) {
                int value = list.get(i);
                for (int j = i - 1; j >= from; j--) {
                    if (comparator.compare(list.get(j), value) <= 0) {
                        break;
                    }
                    list.swap(j, j + 1);
                }
            }
        }

    }

    static class Counter<K> extends HashMap<K, Long> {
        public Counter() {
            super();
        }

        public Counter(int capacity) {
            super(capacity);
        }

        public void add(K key, long delta) {
            put(key, get(key) + delta);
            if (get(key) == 0) {
                remove(key);
            }
        }


        public Long get(Object key) {
            if (containsKey(key)) {
                return super.get(key);
            }
            return 0L;
        }

    }

    static interface IntList extends IntReversableCollection {
        public abstract int get(int index);

        public abstract void set(int index, int value);

        public abstract void addAt(int index, int value);

        public abstract void removeAt(int index);

        default public void swap(int first, int second) {
            if (first == second) {
                return;
            }
            int temp = get(first);
            set(first, get(second));
            set(second, temp);
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

        public final int addSimpleEdge(int from, int to) {
            return addWeightedEdge(from, to, 0);
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
}

