import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
    boolean ok = true;
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int count = in.readInt();
        int[][] table = IOUtils.readIntTable(in, count, count);

        for (int i = 0; i < count; i++) {
            if (table[i][i] != 0) {
                out.printLine("NO");
                return;
            }
        }

        IntList from = new IntArrayList();
        IntList to = new IntArrayList();
        IntList weight = new IntArrayList();

        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                if (table[i][j] != table[j][i] || table[i][j] == 0) {
                    out.printLine("NO");
                    return;
                }
                from.add(i);
                to.add(j);
                weight.add(table[i][j]);
            }
        }

        int[] order = ArrayUtils.order(weight.toArray());

        Graph graph = new BidirectionalGraph(count);
        IndependentSetSystem setSystem = new RecursiveIndependentSetSystem(count);

        for (int i = 0; i < from.size(); i++) {
            int idx = order[i];
            if (setSystem.join(from.get(idx), to.get(idx)))
                graph.add(new WeightedEdge(from.get(idx), to.get(idx), weight.get(idx)));
        }

        for (int i = 0; i < count; i++) {
            ok = true;
            dfs(-1, i, i, graph, table, 0);
            if (!ok) {
                out.printLine("NO");
                return;
            }
        }

        out.printLine("YES");
    }

    private void dfs(int from, int cur, int begin, Graph graph, int[][] table, long len) {
        for (Edge e : graph.getIncident(cur)) {
            if (e.getDestination() == from)
                continue;
            long val = len + e.getWeight();
            if (val != table[begin][e.getDestination()])
                ok = false;
            dfs(cur, e.getDestination(), begin, graph, table, val);
        }
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

    public void printLine(Object...objects) {
        print(objects);
        writer.println();
    }

    public void close() {
        writer.close();
    }

}

class IOUtils {

    public static int[][] readIntTable(InputReader in, int rowCount, int columnCount) {
        int[][] table = new int[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = readIntArray(in, columnCount);
        return table;
    }

    public static int[] readIntArray(InputReader in, int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readInt();
        return array;
    }

}

abstract class IntList extends IntCollection implements Comparable<IntList> {
    private static final int INSERTION_THRESHOLD = 8;

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

    public IntList subList(final int from, final int to) {
        return new SubList(from, to);
    }

    private void swap(int first, int second) {
        if (first == second)
            return;
        int temp = get(first);
        set(first, get(second));
        set(second, temp);
    }

    public IntSortedList inPlaceSort(IntComparator comparator) {
        quickSort(0, size() - 1, size(), comparator);
        return new IntSortedArray(this, comparator);
    }

    private void quickSort(int from, int to, int remaining, IntComparator comparator) {
        if (to - from < INSERTION_THRESHOLD) {
            insertionSort(from, to, comparator);
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
            siftDown(i, to, comparator, from);
        for (int i = to; i > from; i--) {
            swap(from, i);
            siftDown(from, i - 1, comparator, from);
        }
    }

    private void siftDown(int start, int end, IntComparator comparator, int delta) {
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

    private void insertionSort(int from, int to, IntComparator comparator) {
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

    public IntSortedList sort(IntComparator comparator) {
        return new IntArray(this).inPlaceSort(comparator);
    }

    private class SubList extends IntList {
        private final int to;
        private final int from;
        private int size;

        public SubList(int from, int to) {
            this.to = to;
            this.from = from;
            size = to - from;
        }

        public int get(int index) {
            if (index < 0 || index >= size)
                throw new IndexOutOfBoundsException();
            return IntList.this.get(index + from);
        }

        public void set(int index, int value) {
            if (index < 0 || index >= size)
                throw new IndexOutOfBoundsException();
            IntList.this.set(index + from, value);
        }

        public int size() {
            return size;
        }

        public void add(int value) {
            throw new UnsupportedOperationException();
            

        }

    }


}

class IntArrayList extends IntList {
    private int[] array;
    private int size;

    public IntArrayList() {
        this(10);
    }

    public IntArrayList(int capacity) {
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

    public int[] toArray() {
        int[] array = new int[size];
        System.arraycopy(this.array, 0, array, 0, size);
        return array;
    }
}

abstract class IntCollection {
    public abstract IntIterator iterator();
    public abstract int size();
    public abstract void add(int value);

    public int[] toArray() {
        int size = size();
        int[] array = new int[size];
        int i = 0;
        for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance())
            array[i++] = iterator.value();
        return array;
    }

}

class ArrayUtils {

    public static int[] createOrder(int size) {
        int[] order = new int[size];
        for (int i = 0; i < size; i++)
            order[i] = i;
        return order;
    }

    public static int[] sort(int[] array, IntComparator comparator) {
        return sort(array, 0, array.length, comparator);
    }

    public static int[] sort(int[] array, int from, int to, IntComparator comparator) {
        if (from == 0 && to == array.length)
            new IntArray(array).inPlaceSort(comparator);
        else
            new IntArray(array).subList(from, to).inPlaceSort(comparator);
        return array;
    }

    public static int[] order(final int[] array) {
        return sort(createOrder(array.length), new IntComparator() {
            public int compare(int first, int second) {
                if (array[first] < array[second])
                    return -1;
                if (array[first] > array[second])
                    return 1;
                return 0;
            }
        });
    }

    


    



}

class Graph {
    private final int size;
    private final List<Edge>[] edges;

    public Graph(int size) {
        this.size = size;
        

        edges = new List[size];
        for (int i = 0; i < size; i++)
            edges[i] = new ArrayList<Edge>();
    }

    public List<Edge> getIncident(int vertex) {
        return edges[vertex];
    }

    public void add(Edge edge) {
        edges[edge.getSource()].add(edge);
        edge = edge.getReverseEdge();
        if (edge != null)
            edges[edge.getSource()].add(edge);
    }

    

}

class BidirectionalGraph extends Graph {
    public BidirectionalGraph(int size) {
        super(size);
    }

    public void add(Edge edge) {
        super.add(edge);
        super.add(edge.getTransposedEdge());
    }
}

interface IndependentSetSystem {
    public boolean join(int first, int second);

    public static interface Listener {
        public void joined(int joinedRoot, int root);
    }
}

class RecursiveIndependentSetSystem implements IndependentSetSystem {
    private final int[] color;
    private int setCount;
    private Listener listener;

    public RecursiveIndependentSetSystem(int size) {
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

interface Edge {
    public int getSource();
    public int getDestination();
    public long getWeight();

    public Edge getTransposedEdge();
    public Edge getReverseEdge();
}

class WeightedEdge extends SimpleEdge {
    private final long weight;

    public WeightedEdge(int source, int destination, long weight) {
        super(source, destination);
        this.weight = weight;
    }

    public long getWeight() {
        return weight;
    }

    public Edge getTransposedEdge() {
        if (transposed == null)
            transposed = new WeightedTransposedEdge();
        return transposed;
    }

    protected class WeightedTransposedEdge extends SimpleTransposedEdge {
        public long getWeight() {
            return weight;
        }
    }
}

interface IntIterator {
    public int value() throws NoSuchElementException;
    
    public void advance() throws NoSuchElementException;
    public boolean isValid();
}

abstract class IntSortedList extends IntList {
    protected final IntComparator comparator;

    protected IntSortedList(IntComparator comparator) {
        this.comparator = comparator;
    }

    public void set(int index, int value) {
        throw new UnsupportedOperationException();
    }

    public void add(int value) {
        throw new UnsupportedOperationException();
    }

    public IntSortedList inPlaceSort(IntComparator comparator) {
        if (comparator == this.comparator)
            return this;
        throw new UnsupportedOperationException();
    }

    public IntSortedList sort(IntComparator comparator) {
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

    public IntSortedList subList(final int from, final int to) {
        return new IntSortedList(comparator) {
            private int size = to - from;

            public int get(int index) {
                if (index < 0 || index >= size)
                    throw new IndexOutOfBoundsException();
                return IntSortedList.this.get(index + from);
            }

            public int size() {
                return size;
            }

            public void add(int value) {
                

            }
        };
    }
}

interface IntComparator {

    public int compare(int first, int second);
}

class IntSortedArray extends IntSortedList {
    private final int[] array;

    public IntSortedArray(IntCollection collection, IntComparator comparator) {
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

    public IntArray(int[] array) {
        this.array = array;
    }

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

    public int[] toArray() {
        return array;
    }
}

class SimpleEdge implements Edge {
    protected final int source;
    protected final int destination;
    protected Edge transposed = null;

    public SimpleEdge(int source, int destination) {
        this.source = source;
        this.destination = destination;
    }

    public int getSource() {
        return source;
    }

    public int getDestination() {
        return destination;
    }

    public long getWeight() {
        return 1;
    }

    public Edge getTransposedEdge() {
        if (transposed == null)
            transposed = new SimpleTransposedEdge();
        return transposed;
    }

    public Edge getReverseEdge() {
        return null;
    }

    protected class SimpleTransposedEdge implements Edge {
        public int getSource() {
            return destination;
        }

        public int getDestination() {
            return source;
        }

        public long getWeight() {
            return 1;
        }

        public Edge getTransposedEdge() {
            return SimpleEdge.this;
        }

        public Edge getReverseEdge() {
            return null;
        }

    }
}

