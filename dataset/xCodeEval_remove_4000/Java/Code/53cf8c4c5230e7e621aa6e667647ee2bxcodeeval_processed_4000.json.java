import java.io.OutputStreamWriter;
import java.util.PriorityQueue;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.util.Comparator;
import java.io.OutputStream;
import java.util.RandomAccess;
import java.io.PrintWriter;
import java.util.AbstractList;
import java.io.Writer;
import java.util.Collection;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Set;
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Queue;
import java.math.BigInteger;
import java.util.Collections;
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
        int count = in.readInt();
        int edgeCount = in.readInt();
        Graph<Integer> graph = new id4<Integer>();
        for (int i = 0; i < edgeCount; i++) {
            int from = in.readInt();
            int to = in.readInt();
            graph.add(new SimpleEdge<Integer>(from, to));
        }
        final Pair<Map<Integer,Long>,Map<Integer,Edge<Integer>>> firstDistance = GraphAlgorithms.id11(graph, 1);
        final Pair<Map<Integer,Long>,Map<Integer,Edge<Integer>>> secondDistance = GraphAlgorithms.id11(graph, count);
        double[] firstCount = getCount(count, graph, firstDistance, 1);
        double[] secondCount = getCount(count, graph, secondDistance, count);
        double answer = 1;
        for (int i = 2; i < count; i++) {
            if (firstDistance.first.get(i) + secondDistance.first.get(i) == firstDistance.first.get(count))
                answer = Math.max(answer, 2 * firstCount[i] * secondCount[i] / firstCount[count]);
        }
        out.printLine(answer);
    }

    private double[] getCount(int count, Graph<Integer> graph, final Pair<Map<Integer, Long>, Map<Integer, Edge<Integer>>> distance, int start) {
        double[] firstCount = new double[count + 1];
        firstCount[start] = 1;
        int[] order = new int[count];
        for (int i = 0; i < count; i++)
            order[i] = i + 1;
        ArrayUtils.sort(order, new IntComparator() {
            public int compare(int first, int second) {
                return IntegerUtils.longCompare(distance.first.get(first), distance.first.get(second));
            }
        });
        for (int i : order) {
            for (Edge<Integer> edge : graph.getIncident(i)) {
                if (distance.first.get(edge.getDestination()) + 1 == distance.first.get(i))
                    firstCount[i] += firstCount[edge.getDestination()];
            }
        }
        return firstCount;
    }
}

class InputReader {
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private id10 filter;

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
        while (id2(c))
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
        } while (!id2(c));
        return res * sgn;
    }

    public boolean id2(int c) {
        if (filter != null)
            return filter.id2(c);
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public interface id10 {
        public boolean id2(int ch);
    }

    }

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
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

class Graph<V> {
    private Map<V, Edge<V>> firstEdge = new HashMap<V, Edge<V>>();
    private Map<Edge<V>, Edge<V>> nextEdge = new HashMap<Edge<V>, Edge<V>>();
    private Map<Edge<V>, Edge<V>> lastEdge = new HashMap<Edge<V>, Edge<V>>();

    public Iterable<Edge<V>> getIncident(final V vertex) {
        return new Iterable<Edge<V>>() {
            public Iterator<Edge<V>> iterator() {
                return new EdgeIterator(vertex);
            }
        };
    }

    public void add(Edge<V> edge) {
        addImpl(edge);
        edge = edge.id8();
        if (edge != null)
            addImpl(edge);
    }

    private void addImpl(Edge<V> edge) {
        V source = edge.getSource();
        if (firstEdge.containsKey(source)) {
            Edge<V> last = firstEdge.get(source);
            lastEdge.put(last, edge);
            nextEdge.put(edge, last);
        }
        firstEdge.put(source, edge);
    }

    public void remove(Edge<V> edge) {
        removeImpl(edge);
        edge = edge.id8();
        if (edge != null)
            removeImpl(edge);
    }

    private void removeImpl(Edge<V> edge) {
        V source = edge.getSource();
        if (firstEdge.containsKey(source)) {
            Edge<V> next = nextEdge.get(edge);
            Edge<V> last = lastEdge.get(edge);
            if (last == null) {
                if (next == null)
                    firstEdge.remove(source);
                else {
                    firstEdge.put(source, next);
                    lastEdge.remove(next);
                }
            } else if (next == null)
                nextEdge.remove(last);
            else {
                nextEdge.put(last, next);
                lastEdge.put(next, last);
            }
            nextEdge.remove(edge);
            lastEdge.remove(edge);
        }
    }

    private class EdgeIterator implements Iterator<Edge<V>> {
        private Edge<V> current, last;

        public EdgeIterator(V vertex) {
            current = firstEdge.get(vertex);
        }

        public boolean hasNext() {
            return current != null;
        }

        public Edge<V> next() {
            if (!hasNext())
                throw new NoSuchElementException();
            last = current;
            current = nextEdge.get(current);
            return last;
        }

        public void remove() {
            if (last == null)
                throw new IllegalStateException();
            Graph.this.remove(last);
            last = null;
        }
    }
}

class id4<V> extends Graph<V> {
    public void add(Edge<V> edge) {
        super.add(edge);
        super.add(edge.id1());
    }

    public void remove(Edge<V> edge) {
        super.remove(edge);
        super.remove(edge.id1());
    }
}

interface Edge<V> {
    public V getSource();
    public V getDestination();
    public long getWeight();
    public Edge<V> id1();
    public Edge<V> id8();
}

class SimpleEdge<V> implements Edge<V> {
    protected final V source;
    protected final V destination;
    protected Edge<V> transposed = null;

    public SimpleEdge(V source, V destination) {
        this.source = source;
        this.destination = destination;
    }

    public V getSource() {
        return source;
    }

    public V getDestination() {
        return destination;
    }

    public long getWeight() {
        return 1;
    }

    public Edge<V> id1() {
        if (transposed == null)
            transposed = new id12();
        return transposed;
    }

    public Edge<V> id8() {
        return null;
    }

    protected class id12 implements Edge<V> {
        public V getSource() {
            return destination;
        }

        public V getDestination() {
            return source;
        }

        public long getWeight() {
            return 1;
        }

        public Edge<V> id1() {
            return SimpleEdge.this;
        }

        public Edge<V> id8() {
            return null;
        }

    }
}

class Pair<U, V> implements Comparable<Pair<U, V>> {

    public final U first;
    public final V second;

    public static<U, V> Pair<U, V> makePair(U first, V second) {
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

    public int compareTo(Pair<U, V> o) {
        int value = ((Comparable<U>)first).compareTo(o.first);
        if (value != 0)
            return value;
        return ((Comparable<V>)second).compareTo(o.second);
    }
}

class GraphAlgorithms {
    public static<V> Pair<Map<V, Long>, Map<V, Edge<V>>> id11(Graph<V> graph, V source) {
        Map<V, Long> distance = new HashMap<V, Long>();
        Queue<Pair<Long, V>> queue = new PriorityQueue<Pair<Long, V>>();
        Map<V, Edge<V>> last = new HashMap<V, Edge<V>>();
        distance.put(source, 0L);
        queue.add(Pair.makePair(0L, source));
        Set<V> processed = new HashSet<V>();
        while (!queue.isEmpty()) {
            V current = queue.poll().second;
            if (processed.contains(current))
                continue;
            processed.add(current);
            for (Edge<V> edge : graph.getIncident(current)) {
                V next = edge.getDestination();
                long total = edge.getWeight() + distance.get(current);
                if (!distance.containsKey(next) || distance.get(next) > total) {
                    distance.put(next, total);
                    last.put(next, edge);
                    queue.add(Pair.makePair(total, next));
                }
            }
        }
        return Pair.makePair(distance, last);
    }
}

class ArrayUtils {

    public static int[] sort(int[] array, IntComparator comparator) {
        return sort(array, 0, array.length, comparator);
    }

    public static int[] sort(int[] array, int from, int to, IntComparator comparator) {
        new IntArray(array).subList(from, to).id6(comparator);






        return array;
    }

    


    }

interface IntComparator {
    public static final IntComparator DEFAULT = new IntComparator() {
        public int compare(int first, int second) {
            if (first < second)
                return -1;
            if (first > second)
                return 1;
            return 0;
        }
    };

    public int compare(int first, int second);
}

class IntegerUtils {

    public static int longCompare(long a, long b) {
        if (a < b)
            return -1;
        if (a > b)
            return 1;
        return 0;
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

abstract class IntList extends IntCollection implements Comparable<IntList> {
    private static final int id7 = 8;

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

    public id9 id6(IntComparator comparator) {
        quickSort(0, size() - 1, size(), comparator);
        return new id5(this, comparator);
    }

    private void quickSort(int from, int to, int remaining, IntComparator comparator) {
        if (to - from < id7) {
            id3(from, to, comparator);
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
            id0(i, to, comparator, from);
        for (int i = to; i > from; i--) {
            swap(from, i);
            id0(from, i - 1, comparator, from);
        }
    }

    private void id0(int start, int end, IntComparator comparator, int delta) {
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

    private void id3(int from, int to, IntComparator comparator) {
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

    public id9 sort(IntComparator comparator) {
        return new IntArray(this).id6(comparator);
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

        }
}

abstract class id9 extends IntList {
    protected final IntComparator comparator;

    protected id9(IntComparator comparator) {
        this.comparator = comparator;
    }

    public void set(int index, int value) {
        throw new UnsupportedOperationException();
    }

    public id9 id6(IntComparator comparator) {
        if (comparator == this.comparator)
            return this;
        throw new UnsupportedOperationException();
    }

    public id9 sort(IntComparator comparator) {
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

    public id9 subList(final int from, final int to) {
        return new id9(comparator) {
            private int size = to - from;

            @Override
            public int get(int index) {
                if (index < 0 || index >= size)
                    throw new IndexOutOfBoundsException();
                return id9.this.get(index + from);
            }

            @Override
            public int size() {
                return size;
            }

            public void add(int value) {
                

            }
        };
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

    }

class id5 extends id9 {
    private final int[] array;

    public id5(int[] array) {
        this(array, IntComparator.DEFAULT);
    }

    public id5(IntCollection collection) {
        this(collection, IntComparator.DEFAULT);
    }

    public id5(int[] array, IntComparator comparator) {
        super(comparator);
        this.array = array;
        ensureSorted();
    }

    public id5(IntCollection collection, IntComparator comparator) {
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
