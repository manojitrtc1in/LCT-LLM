import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Iterator;
import java.io.IOException;
import java.util.Arrays;
import java.io.InputStream;
import java.util.Collection;
import java.io.OutputStreamWriter;
import java.util.Comparator;


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
    int[] primes = IntegerUtils.id18(20000);
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int count = in.readInt();
        int[] age = IOUtils.id1(in, count);
        Graph graph = new Graph(count + 2);
        for (int i = 0; i < count; i++) {
            if ((age[i] & 1) == 0) {
                graph.id6(count, i, 2);
                for (int j = 0; j < count; j++) {
                    if (Arrays.binarySearch(primes, age[i] + age[j]) >= 0) {
                        graph.id6(i, j, 1);
                    }
                }
            } else {
                graph.id6(i, count + 1, 2);
            }
        }
        if (MaxFlow.dinic(graph, count, count + 1) != count) {
            out.printLine("Impossible");
        } else {
            List<IntList> answer = new ArrayList<IntList>();
            boolean[] taken = new boolean[count];
            for (int i = 0; i < count; i++) {
                if (taken[i]) {
                    continue;
                }
                IntList table = new id17();
                table.add(i + 1);
                taken[i] = true;
                int current = i;
                boolean completed = false;
                while (!completed) {
                    if ((age[current] & 1) == 0) {
                        for (int j = graph.firstOutbound(current); j != -1; j = graph.nextOutbound(j)) {
                            int to = graph.destination(j);
                            if (graph.flow(j) > 0 && (!taken[to] || to == i && table.size() > 2)) {
                                if (!taken[to]) {
                                    taken[to] = true;
                                    table.add(to + 1);
                                    current = to;
                                } else {
                                    completed = true;
                                }
                                break;
                            }
                        }
                    } else {
                        for (int j = graph.firstInbound(current); j != -1; j = graph.nextInbound(j)) {
                            int to = graph.source(j);
                            if (graph.flow(j) > 0 && (!taken[to] || to == i && table.size() > 2)) {
                                if (!taken[to]) {
                                    taken[to] = true;
                                    table.add(to + 1);
                                    current = to;
                                } else {
                                    completed = true;
                                }
                                break;
                            }
                        }
                    }
                }
                answer.add(table);
            }
            out.printLine(answer.size());
            for (IntList table : answer) {
                out.print(table.size() + " ");
                out.printLine(table);
            }
        }
    }
}

class IntegerUtils {

    public static int[] id18(int upTo) {
        boolean[] isPrime = id3(upTo);
        List<Integer> primes = new ArrayList<Integer>();
        for (int i = 0; i < upTo; i++) {
            if (isPrime[i])
                primes.add(i);
        }
        return CollectionUtils.toArray(primes);
    }

    public static boolean[] id3(int upTo) {
        boolean[] isPrime = new boolean[upTo];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i < upTo; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < upTo; j += i)
                    isPrime[j] = false;
            }
        }
        return isPrime;
    }

}

class InputReader {
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private id19 filter;

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
        while (id4(c))
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
        } while (!id4(c));
        return res * sgn;
    }

    public boolean id4(int c) {
        if (filter != null)
            return filter.id4(c);
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public interface id19 {
        public boolean id4(int ch);
    }

}

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public void print(IntCollection collection) {
        boolean first = true;
        for (IntIterator iterator = collection.iterator(); iterator.isValid(); iterator.advance()) {
            if (first)
                first = false;
            else
                writer.print(' ');
            writer.print(iterator.value());
        }
    }

    public void printLine(IntCollection collection) {
        print(collection);
        writer.println();
    }

    public void print(Object...objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(objects[i]);
        }
    }

    public void printLine(Object...objects) {
        print(objects);
        writer.println();
    }

    public void close() {
        writer.close();
    }

}

class IOUtils {

    public static int[] id1(InputReader in, int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readInt();
        return array;
    }

}

class Graph {
    public static final int id20 = 0;

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
    private long[] capacity;
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

    public final int id8(int from, int to, long weight, long capacity) {
        if (capacity == 0) {
            return addEdge(from, to, weight, 0, -1);
        } else {
            int id10 = edgeCount;
            addEdge(to, from, -weight, 0, id10 + id13());
            return addEdge(from, to, weight, capacity, id10);
        }
    }

    protected int id13() {
        return 1;
    }

    public final int destination(int id) {
        return to[id];
    }

    public final boolean flag(int id, int bit) {
        return (flags[id] >> bit & 1) != 0;
    }

    public final boolean isRemoved(int id) {
        return flag(id, id20);
    }

    protected void id12(int size) {
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

    public final int vertexCount() {
        return vertexCount;
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

    public final long capacity(int id) {
        if (capacity == null)
            return 0;
        return capacity[id];
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

    public final long flow(int id) {
        if (reverseEdge == null)
            return 0;
        return capacity[reverseEdge[id]];
    }

    public final int source(int id) {
        return from[id];
    }

    public final int id6(int from, int to, long capacity) {
        return id8(from, to, 0, capacity);
    }

}

class MaxFlow {
    private final Graph graph;
    private int source;
    private int destination;
    private int[] queue;
    private int[] distance;
    private int[] nextEdge;

    public MaxFlow(Graph graph, int source, int destination) {
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

    public long dinic() {
        long totalFlow = 0;
        while (true) {
            edgeDistances();
            if (distance[destination] == -1)
                break;
            Arrays.fill(nextEdge, -2);
            totalFlow += id0(source, Long.MAX_VALUE);
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

    private long id0(int source, long flow) {
        if (source == destination)
            return flow;
        if (flow == 0 || distance[source] == distance[destination])
            return 0;
        int id = nextEdge[source];
        if (id == -2)
            nextEdge[source] = id = graph.firstOutbound(source);
        long id14 = 0;
        while (id != -1) {
            int id9 = graph.destination(id);
            if (graph.capacity(id) != 0 && distance[id9] == distance[source] + 1) {
                long pushed = id0(id9, Math.min(flow, graph.capacity(id)));
                if (pushed != 0) {
                    graph.pushFlow(id, pushed);
                    flow -= pushed;
                    id14 += pushed;
                    if (flow == 0)
                        return id14;
                }
            }
            nextEdge[source] = id = graph.nextOutbound(id);
        }
        return id14;
    }
}

abstract class IntList extends IntCollection implements Comparable<IntList> {
    private static final int id15 = 8;

    public abstract int get(int index);
    public abstract void set(int index, int value);

    public IntIterator iterator() {
        return new IntIterator() {
            private int size = size();
            private int index = 0;

            public int value() throws NoSuchElementException {
                if (!isValid())
                    throw new NoSuchElementException();
                return get(index);
            }

            public void advance() throws NoSuchElementException {
                if (!isValid())
                    throw new NoSuchElementException();
                index++;
            }

            public boolean isValid() {
                return index < size;
            }
        };
    }

    private void swap(int first, int second) {
        if (first == second)
            return;
        int temp = get(first);
        set(first, get(second));
        set(second, temp);
    }

    public id16 id11(IntComparator comparator) {
        quickSort(0, size() - 1, size(), comparator);
        return new id7(this, comparator);
    }

    private void quickSort(int from, int to, int remaining, IntComparator comparator) {
        if (to - from < id15) {
            id5(from, to, comparator);
            return;
        }
        if (remaining == 0) {
            heapSort(from, to, comparator);
            return;
        }
        remaining >>= 1;
        int pivotIndex = (from + to) >> 1;
        int pivot = get(pivotIndex);
        swap(pivotIndex, to);
        int storeIndex = from;
        int equalIndex = to;
        for (int i = from; i < equalIndex; i++) {
            int value = comparator.compare(get(i), pivot);
            if (value < 0)
                swap(storeIndex++, i);
            else if (value == 0)
                swap(--equalIndex, i--);
        }
        quickSort(from, storeIndex - 1, remaining, comparator);
        for (int i = equalIndex; i <= to; i++)
            swap(storeIndex++, i);
        quickSort(storeIndex, to, remaining, comparator);
    }

    private void heapSort(int from, int to, IntComparator comparator) {
        for (int i = (to + from - 1) >> 1; i >= from; i--)
            id2(i, to, comparator, from);
        for (int i = to; i > from; i--) {
            swap(from, i);
            id2(from, i - 1, comparator, from);
        }
    }

    private void id2(int start, int end, IntComparator comparator, int delta) {
        int value = get(start);
        while (true) {
            int child = ((start - delta) << 1) + 1 + delta;
            if (child > end)
                return;
            int childValue = get(child);
            if (child + 1 <= end) {
                int otherValue = get(child + 1);
                if (comparator.compare(otherValue, childValue) > 0) {
                    child++;
                    childValue = otherValue;
                }
            }
            if (comparator.compare(value, childValue) >= 0)
                return;
            swap(start, child);
            start = child;
        }
    }

    private void id5(int from, int to, IntComparator comparator) {
        for (int i = from + 1; i <= to; i++) {
            int value = get(i);
            for (int j = i - 1; j >= from; j--) {
                if (comparator.compare(get(j), value) <= 0)
                    break;
                swap(j, j + 1);
            }
        }
    }

    public int hashCode() {
        int hashCode = 1;
        for (IntIterator i = iterator(); i.isValid(); i.advance())
            hashCode = 31 * hashCode + i.value();
        return hashCode;
    }

    public boolean equals(Object obj) {
        if (!(obj instanceof IntList))
            return false;
        IntList list = (IntList)obj;
        if (list.size() != size())
            return false;
        IntIterator i = iterator();
        IntIterator j = list.iterator();
        while (i.isValid()) {
            if (i.value() != j.value())
                return false;
            i.advance();
            j.advance();
        }
        return true;
    }

    public int compareTo(IntList o) {
        IntIterator i = iterator();
        IntIterator j = o.iterator();
        while (true) {
            if (i.isValid()) {
                if (j.isValid()) {
                    if (i.value() != j.value()) {
                        if (i.value() < j.value())
                            return -1;
                        else
                            return 1;
                    }
                } else
                    return 1;
            } else {
                if (j.isValid())
                    return -1;
                else
                    return 0;
            }
            i.advance();
            j.advance();
        }
    }

    public id16 sort(IntComparator comparator) {
        return new IntArray(this).id11(comparator);
    }


}

class id17 extends IntList {
    private int[] array;
    private int size;

    public id17() {
        this(10);
    }

    public id17(int capacity) {
        array = new int[capacity];
    }

    public int get(int index) {
        if (index >= size)
            throw new IndexOutOfBoundsException();
        return array[index];
    }

    public void set(int index, int value) {
        if (index >= size)
            throw new IndexOutOfBoundsException();
        array[index] = value;
    }

    public int size() {
        return size;
    }

    public void add(int value) {
        ensureCapacity(size + 1);
        array[size++] = value;
    }

    public void ensureCapacity(int newCapacity) {
        if (newCapacity > array.length) {
            int[] newArray = new int[Math.max(newCapacity, array.length << 1)];
            System.arraycopy(array, 0, newArray, 0, size);
            array = newArray;
        }
    }

}

abstract class IntCollection {
    public abstract IntIterator iterator();
    public abstract int size();
    public abstract void add(int value);

}

class CollectionUtils {

    public static int[] toArray(Collection<Integer> collection) {
        int[] array = new int[collection.size()];
        int index = 0;
        for (int element : collection)
            array[index++] = element;
        return array;
    }

}

interface IntIterator {
    public int value() throws NoSuchElementException;
    
    public void advance() throws NoSuchElementException;
    public boolean isValid();
}

interface Edge {
}

abstract class id16 extends IntList {
    protected final IntComparator comparator;

    protected id16(IntComparator comparator) {
        this.comparator = comparator;
    }

    public void set(int index, int value) {
        throw new UnsupportedOperationException();
    }

    public void add(int value) {
        throw new UnsupportedOperationException();
    }

    public id16 id11(IntComparator comparator) {
        if (comparator == this.comparator)
            return this;
        throw new UnsupportedOperationException();
    }

    public id16 sort(IntComparator comparator) {
        if (comparator == this.comparator)
            return this;
        return super.sort(comparator);
    }

    protected void ensureSorted() {
        int size = size();
        if (size == 0)
            return;
        int last = get(0);
        for (int i = 1; i < size; i++) {
            int current = get(i);
            if (comparator.compare(last, current) > 0)
                throw new IllegalArgumentException();
            last = current;
        }
    }

}

interface IntComparator {

    public int compare(int first, int second);
}

class id7 extends id16 {
    private final int[] array;

    public id7(IntCollection collection, IntComparator comparator) {
        super(comparator);
        array = new int[collection.size()];
        int i = 0;
        for (IntIterator iterator = collection.iterator(); iterator.isValid(); iterator.advance())
            array[i++] = iterator.value();
        ensureSorted();
    }

    public int get(int index) {
        return array[index];
    }

    public int size() {
        return array.length;
    }
}

class IntArray extends IntList {
    private final int[] array;

    public IntArray(IntCollection collection) {
        array = new int[collection.size()];
        int i = 0;
        for (IntIterator iterator = collection.iterator(); iterator.isValid(); iterator.advance())
            array[i++] = iterator.value();
    }

    public int get(int index) {
        return array[index];
    }

    public void set(int index, int value) {
        array[index] = value;
    }

    public int size() {
        return array.length;
    }

    public void add(int value) {
        throw new UnsupportedOperationException();
    }

}
