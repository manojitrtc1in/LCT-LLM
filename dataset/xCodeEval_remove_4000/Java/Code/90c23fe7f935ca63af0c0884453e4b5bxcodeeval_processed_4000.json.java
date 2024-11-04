import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.List;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Collections;
import java.util.Iterator;
import java.io.IOException;
import java.util.Arrays;
import java.util.AbstractList;
import java.io.InputStream;
import java.util.Random;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.util.AbstractMap;
import java.util.Comparator;
import java.util.AbstractSet;
import java.util.Set;
import java.util.RandomAccess;


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
}

class TaskD {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int count = in.readInt();
        int[][] table = IOUtils.id6(in, count, count);

        for (int i = 0; i < count; i++) {
            if (table[i][i] != 0) {
                out.printLine("NO");
                return;
            }
        }

        int total = count * (count - 1) / 2;
        long[] edge = new long[total];

        int id = 0;

        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                if (table[i][j] != table[j][i] || table[i][j] == 0) {
                    out.printLine("NO");
                    return;
                }
                edge[id++] = (long)table[i][j] << 32 | i << 16 | j;
            }
        }

        edge = ArrayUtils.id25(edge);

        Graph graph = new id9(count);
        id15 setSystem = new id11(count);

        for (int i = 0; i < total; i++) {
            int from = (int)(edge[i]>>>16&65535);
            int to = (int)(edge[i] & 65535);
            if (setSystem.join(from, to))
                graph.id2(from, to, table[from][to]);
        }

        LCA lca = new LCA(graph);

        long[] fromRoot = new long[count];
        dfs(-1, 0, 0, graph, fromRoot);

        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                if (table[i][j] != fromRoot[i] + fromRoot[j] - 2L * fromRoot[lca.id23(i, j)]) {
                    out.printLine("NO");
                    return;
                }
            }
        }

        out.printLine("YES");
    }

    private void dfs(int from, int cur, long len, Graph graph, long[] fromRoot) {
        fromRoot[cur] = len;
        for (int i = graph.firstOutbound(cur); i != -1; i = graph.nextOutbound(i)) {
            if (graph.destination(i) == from)
                continue;
            dfs(cur, graph.destination(i), len + graph.weight(i), graph, fromRoot);
        }
    }
}

class InputReader {
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private id24 filter;

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
        while (id5(c))
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
        } while (!id5(c));
        return res * sgn;
    }

    public boolean id5(int c) {
        if (filter != null)
            return filter.id5(c);
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public interface id24 {
        public boolean id5(int ch);
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

    public void printLine(Object...objects) {
        print(objects);
        writer.println();
    }

    public void close() {
        writer.close();
    }

}

class IOUtils {

    public static int[][] id6(InputReader in, int rowCount, int columnCount) {
        int[][] table = new int[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id1(in, columnCount);
        return table;
    }

    public static int[] id1(InputReader in, int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readInt();
        return array;
    }

}

class ArrayUtils {

    


    public static long[] id25(long[] f)
    {
        long[] to = new long[f.length];
        {
            int[] b = new int[65537];
            for(int i = 0;i < f.length;i++)b[1+(int)(f[i]&0xffff)]++;
            for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
            for(int i = 0;i < f.length;i++)to[b[(int)(f[i]&0xffff)]++] = f[i];
            long[] d = f; f = to;to = d;
        }
        {
            int[] b = new int[65537];
            for(int i = 0;i < f.length;i++)b[1+(int)(f[i]>>>16&0xffff)]++;
            for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
            for(int i = 0;i < f.length;i++)to[b[(int)(f[i]>>>16&0xffff)]++] = f[i];
            long[] d = f; f = to;to = d;
        }
        {
            int[] b = new int[65537];
            for(int i = 0;i < f.length;i++)b[1+(int)(f[i]>>>32&0xffff)]++;
            for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
            for(int i = 0;i < f.length;i++)to[b[(int)(f[i]>>>32&0xffff)]++] = f[i];
            long[] d = f; f = to;to = d;
        }
        {
            int[] b = new int[65537];
            for(int i = 0;i < f.length;i++)b[1+(int)(f[i]>>>48&0xffff)]++;
            for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
            for(int i = 0;i < f.length;i++)to[b[(int)(f[i]>>>48&0xffff)]++] = f[i];
            long[] d = f; f = to;to = d;
        }
        return f;
    }

    



}

class Graph {
    public static final int id26 = 0;

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

    public final int id13(int from, int to, long weight, long capacity) {
        if (capacity == 0) {
            return addEdge(from, to, weight, 0, -1);
        } else {
            int id16 = edgeCount;
            addEdge(to, from, -weight, 0, id16 + id18());
            return addEdge(from, to, weight, capacity, id16);
        }
    }

    protected int id18() {
        return 1;
    }

    public final int id2(int from, int to, long weight) {
        return id13(from, to, weight, 0);
    }

    protected final int edgeCapacity() {
        return from.length;
    }

    public final int destination(int id) {
        return to[id];
    }

    public final boolean flag(int id, int bit) {
        return (flags[id] >> bit & 1) != 0;
    }

    public final boolean isRemoved(int id) {
        return flag(id, id26);
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

    public final long weight(int id) {
        if (weight == null)
            return 0;
        return weight[id];
    }

    public final int nextOutbound(int id) {
        id = nextOutbound[id];
        while (id != -1 && isRemoved(id))
            id = nextOutbound[id];
        return id;
    }

}

class id9 extends Graph {
    public int[] id4;

    public id9(int vertexCount) {
        this(vertexCount, vertexCount);
    }

    public id9(int vertexCount, int edgeCapacity) {
        super(vertexCount, 2 * edgeCapacity);
        id4 = new int[2 * edgeCapacity];
    }

    public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
        int id16 = edgeCount;
        super.addEdge(fromID, toID, weight, capacity, reverseEdge);
        super.addEdge(toID, fromID, weight, capacity, reverseEdge);
        this.id4[id16] = id16 + 1;
        this.id4[id16 + 1] = id16;
        return id16;
    }

    protected int id18() {
        return 2;
    }

    protected void id19(int size) {
        if (size > edgeCapacity()) {
            super.id19(size);
            id4 = resize(id4, edgeCapacity());
        }
    }
}

interface id15 {
    public boolean join(int first, int second);

    public static interface Listener {
        public void joined(int joinedRoot, int root);
    }
}

class id11 implements id15 {
    private final int[] color;
    private int setCount;
    private Listener listener;

    public id11(int size) {
        color = new int[size];
        for (int i = 0; i < size; i++)
            color[i] = i;
        setCount = size;
    }

    public boolean join(int first, int second) {
        first = get(first);
        second = get(second);
        if (first == second)
            return false;
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

class LCA {
    private final long[] order;
    private final int[] position;
    private final Graph graph;
    private final IntervalTree id20;
    private final int[] level;

    public LCA(Graph graph) {
        this(graph, 0);
    }

    public LCA(Graph graph, int root) {
        this.graph = graph;
        order = new long[2 * graph.vertexCount() - 1];
        position = new int[graph.vertexCount()];
        level = new int[graph.vertexCount()];
        int[] index = new int[graph.vertexCount()];
        for (int i = 0; i < index.length; i++)
            index[i] = graph.firstOutbound(i);
        int[] last = new int[graph.vertexCount()];
        int[] stack = new int[graph.vertexCount()];
        stack[0] = root;
        int size = 1;
        int j = 0;
        last[root] = -1;
        Arrays.fill(position, -1);
        while (size > 0) {
            int vertex = stack[--size];
            if (position[vertex] == -1)
                position[vertex] = j;
            order[j++] = vertex;
            if (last[vertex] != -1)
                level[vertex] = level[last[vertex]] + 1;
            while (index[vertex] != -1 && last[vertex] == graph.destination(index[vertex]))
                index[vertex] = graph.nextOutbound(index[vertex]);
            if (index[vertex] != -1) {
                stack[size++] = vertex;
                stack[size++] = graph.destination(index[vertex]);
                last[graph.destination(index[vertex])] = vertex;
                index[vertex] = graph.nextOutbound(index[vertex]);
            }
        }
        id20 = new id14(order) {

            protected long joinValue(long left, long right) {
                if (left == -1)
                    return right;
                if (right == -1)
                    return left;
                if (level[((int) left)] < level[((int) right)])
                    return left;
                return right;
            }

            protected long neutralValue() {
                return -1;
            }
        };
        id20.init();
    }

    public int id23(int first, int second) {
        return (int) id20.query(Math.min(position[first], position[second]), Math.max(position[first], position[second]));
    }
}

abstract class IntCollection {
    public abstract IntIterator iterator();
    public abstract int size();

}

interface IntIterator {
    public int value() throws NoSuchElementException;
    
    public void advance() throws NoSuchElementException;
    public boolean isValid();
}

interface IntComparator {

    public int compare(int first, int second);
}

abstract class IntList extends IntCollection implements Comparable<IntList> {
    private static final int id21 = 8;

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

    public id22 id17(IntComparator comparator) {
        quickSort(0, size() - 1, size(), comparator);
        return new id12(this, comparator);
    }

    private void quickSort(int from, int to, int remaining, IntComparator comparator) {
        if (to - from < id21) {
            id7(from, to, comparator);
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
            id3(i, to, comparator, from);
        for (int i = to; i > from; i--) {
            swap(from, i);
            id3(from, i - 1, comparator, from);
        }
    }

    private void id3(int start, int end, IntComparator comparator, int delta) {
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

    private void id7(int from, int to, IntComparator comparator) {
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

    public id22 sort(IntComparator comparator) {
        return new IntArray(this).id17(comparator);
    }


}

abstract class id22 extends IntList {
    protected final IntComparator comparator;

    protected id22(IntComparator comparator) {
        this.comparator = comparator;
    }

    public void set(int index, int value) {
        throw new UnsupportedOperationException();
    }

    public id22 id17(IntComparator comparator) {
        if (comparator == this.comparator)
            return this;
        throw new UnsupportedOperationException();
    }

    public id22 sort(IntComparator comparator) {
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

}

interface Edge {
}

abstract class IntervalTree {
    protected int size;

    public IntervalTree(int size, boolean shouldInit) {
        this.size = size;
        int nodeCount = Math.max(1, Integer.highestOneBit(size) << 2);
        initData(size, nodeCount);
        if (shouldInit)
            init();
    }

    protected abstract void initData(int size, int nodeCount);
    protected abstract void initAfter(int root, int left, int right, int middle);
    protected abstract void initBefore(int root, int left, int right, int middle);
    protected abstract void initLeaf(int root, int index);

    protected abstract long id8(int root, int left, int right, int from, int to, int middle, long leftResult, long rightResult);
    protected abstract void id10(int root, int left, int right, int from, int to, int middle);
    protected abstract long queryFull(int root, int left, int right, int from, int to);
    protected abstract long id0();

    public void init() {
        if (size == 0)
            return;
        init(0, 0, size - 1);
    }

    private void init(int root, int left, int right) {
        if (left == right) {
            initLeaf(root, left);
        } else {
            int middle = (left + right) >> 1;
            initBefore(root, left, right, middle);
            init(2 * root + 1, left, middle);
            init(2 * root + 2, middle + 1, right);
            initAfter(root, left, right, middle);
        }
    }

    public long query(int from, int to) {
        return query(0, 0, size - 1, from, to);
    }

    protected long query(int root, int left, int right, int from, int to) {
        if (left > to || right < from)
            return id0();
        if (left >= from && right <= to)
            return queryFull(root, left, right, from, to);
        int middle = (left + right) >> 1;
        id10(root, left, right, from, to, middle);
        long leftResult = query(2 * root + 1, left, middle, from, to);
        long rightResult = query(2 * root + 2, middle + 1, right, from, to);
        return id8(root, left, right, from, to, middle, leftResult, rightResult);
    }
}

abstract class id14 extends IntervalTree {
    protected long[] value;
    protected long[] array;

    protected id14(long[] array) {
        super(array.length, false);
        this.array = array;
        init();
    }

    protected void initData(int size, int nodeCount) {
        value = new long[nodeCount];
    }

    protected void initAfter(int root, int left, int right, int middle) {
        value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
    }

    protected void initBefore(int root, int left, int right, int middle) {
    }

    protected void initLeaf(int root, int index) {
        value[root] = array[index];
    }

    protected long id8(int root, int left, int right, int from, int to, int middle, long leftResult, long rightResult) {
        return joinValue(leftResult, rightResult);
    }

    protected void id10(int root, int left, int right, int from, int to, int middle) {
    }

    protected long queryFull(int root, int left, int right, int from, int to) {
        return value[root];
    }

    protected long id0() {
        return neutralValue();
    }

    protected abstract long neutralValue();
    protected abstract long joinValue(long left, long right);
}

class id12 extends id22 {
    private final int[] array;

    public id12(IntCollection collection, IntComparator comparator) {
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

