import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.Collection;
import java.io.IOException;
import java.io.Writer;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        id13 solver = new id13();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class id13 {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt(), m = in.readInt(), k = in.readInt();
            int[] u = new int[m], v = new int[m];
            in.id10(u, v);
            MiscUtils.id5(u, v);
            id8[] graph = createGraph(n, m, u, v);
            solve(n, graph, k, out);
        }

        void solve(int n, id8[] graph, int k, OutputWriter out) {
            Heap heap = new Heap(n, (i, j) -> Integer.compare(graph[i].size(), graph[j].size()), n);
            heap.addAll(Range.range(n));
            while (!heap.isEmpty() && graph[heap.peek()].size() < k) {
                int u = heap.poll();
                if (graph[u].size() == k - 1 && checkClique(u, graph)) {
                    int[] res = new int[k];
                    res[0] = u;
                    System.arraycopy(graph[u].toArray(), 0, res, 1, k - 1);
                    MiscUtils.id18(res);
                    out.printLine(2);
                    out.printLine(res);
                    return;
                }
                for (id20 it = graph[u].iterator(); it.hasNext(); ) {
                    int v = it.next();
                    graph[v].remove(u);
                    heap.shiftUp(heap.getIndex(v));
                }
            }
            if (heap.isEmpty()) {
                out.printLine(-1);
            } else {
                int[] res = heap.toArray();
                MiscUtils.id18(res);
                out.printLine(1, heap.size());
                out.printLine(res);
            }
        }

        boolean checkClique(int u, id8[] graph) {
            for (id20 it = graph[u].iterator(); it.hasNext(); ) {
                int v = it.next();
                for (id20 it2 = graph[u].iterator(); it2.hasNext(); ) {
                    int w = it2.next();
                    if (v != w && !graph[v].contains(w)) {
                        return false;
                    }
                }
            }
            return true;
        }

        id8[] createGraph(int n, int m, int[] u, int[] v) {
            id8[] res = new id8[n];
            Arrays.setAll(res, i -> new id9(0));
            for (int i = 0; i < m; i++) {
                res[u[i]].add(v[i]);
                res[v[i]].add(u[i]);
            }
            return res;
        }

    }

    static interface IntQueue extends IntCollection {
    }

    static class Heap implements IntQueue {
        private IntComparator comparator;
        private int size = 0;
        private int[] elements;
        private int[] at;

        public Heap(int maxElement) {
            this(10, maxElement);
        }

        public Heap(IntComparator comparator, int maxElement) {
            this(10, comparator, maxElement);
        }

        public Heap(int capacity, int maxElement) {
            this(capacity, IntComparator.DEFAULT, maxElement);
        }

        public Heap(int capacity, IntComparator comparator, int maxElement) {
            this.comparator = comparator;
            elements = new int[capacity];
            at = new int[maxElement];
            Arrays.fill(at, -1);
        }

        public int size() {
            return size;
        }

        public boolean isEmpty() {
            return size == 0;
        }

        public void add(int element) {
            ensureCapacity(size + 1);
            elements[size] = element;
            at[element] = size;
            shiftUp(size++);
        }

        public void shiftUp(int index) {
            

            

            int value = elements[index];
            while (index != 0) {
                int parent = (index - 1) >>> 1;
                int parentValue = elements[parent];
                if (comparator.compare(parentValue, value) <= 0) {
                    elements[index] = value;
                    at[value] = index;
                    return;
                }
                elements[index] = parentValue;
                at[parentValue] = index;
                index = parent;
            }
            elements[0] = value;
            at[value] = 0;
        }

        public void shiftDown(int index) {
            if (index < 0 || index >= size) {
                throw new IllegalArgumentException();
            }
            while (true) {
                int child = (index << 1) + 1;
                if (child >= size) {
                    return;
                }
                if (child + 1 < size && comparator.compare(elements[child], elements[child + 1]) > 0) {
                    child++;
                }
                if (comparator.compare(elements[index], elements[child]) <= 0) {
                    return;
                }
                swap(index, child);
                index = child;
            }
        }

        public int getIndex(int element) {
            return at[element];
        }

        private void swap(int first, int second) {
            int temp = elements[first];
            elements[first] = elements[second];
            elements[second] = temp;
            at[elements[first]] = first;
            at[elements[second]] = second;
        }

        private void ensureCapacity(int size) {
            if (elements.length < size) {
                int[] oldElements = elements;
                elements = new int[Math.max(2 * elements.length, size)];
                System.arraycopy(oldElements, 0, elements, 0, this.size);
            }
        }

        public int peek() {
            if (isEmpty()) {
                throw new IndexOutOfBoundsException();
            }
            return elements[0];
        }

        public int poll() {
            if (isEmpty()) {
                throw new IndexOutOfBoundsException();
            }
            int result = elements[0];
            at[result] = -1;
            if (size == 1) {
                size = 0;
                return result;
            }
            elements[0] = elements[--size];
            at[elements[0]] = 0;
            shiftDown(0);
            return result;
        }

        public IntIterator intIterator() {
            return new IntIterator() {
                private int at;


                public int value() throws NoSuchElementException {
                    return elements[at];
                }


                public boolean advance() throws NoSuchElementException {
                    return ++at < size;
                }


                public boolean isValid() {
                    return at < size;
                }


                public void remove() throws NoSuchElementException {
                    throw new UnsupportedOperationException();
                }
            };
        }

    }

    static interface id20 {
        boolean hasNext();

        int next();

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

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void printLine(int i) {
            writer.println(i);
        }

    }

    static interface IntCollection extends id19 {
        public int size();

        default public void add(int value) {
            throw new UnsupportedOperationException();
        }

        default public int[] toArray() {
            int size = size();
            int[] array = new int[size];
            int i = 0;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                array[i++] = it.value();
            }
            return array;
        }

        default public IntCollection addAll(id19 values) {
            for (IntIterator it = values.intIterator(); it.isValid(); it.advance()) {
                add(it.value());
            }
            return this;
        }

    }

    static interface IntList extends id21 {
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
                    return !removed && at < size();
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

    static class MiscUtils {
        public static void id5(int[] array) {
            for (int i = 0; i < array.length; i++) {
                array[i]--;
            }
        }

        public static void id5(int[]... arrays) {
            for (int[] array : arrays) {
                id5(array);
            }
        }

        public static void id18(int[] array) {
            for (int i = 0; i < array.length; i++) {
                array[i]++;
            }
        }

    }

    static interface id1 {
        int size();

        id20 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static final class id16 {
        private static final double id0 = 2.0;
        private static final Random rnd = new Random();

        private id16() {
        }

        private static int id15(int length) {
            if (length <= 1) {
                return 0;
            }
            int log = Integer.numberOfTrailingZeros(Integer.highestOneBit(length - 1)) + 1;
            return (int) (id0 * log);
        }

        public static void sort(int[] a) {
            quickSort(a, 0, a.length, 0, id15(a.length));
        }

        private static void quickSort(int[] a, int left, int right, int depth, int maxDepth) {
            if (right - left <= 1) {
                return;
            }
            if (depth > maxDepth) {
                heapSort(a, left, right - left);
                return;
            }
            final int pivot = a[left + rnd.nextInt(right - left)];
            int i = left;
            int j = right - 1;
            do {
                while (a[i] < pivot) i++;
                while (pivot < a[j]) j--;
                if (i <= j) {
                    int tmp = a[i];
                    a[i++] = a[j];
                    a[j--] = tmp;
                }
            } while (i <= j);
            quickSort(a, left, j + 1, depth + 1, maxDepth);
            quickSort(a, i, right, depth + 1, maxDepth);
        }

        private static void heapSort(int[] a, int offset, int size) {
            

            for (int i = (size >>> 1) - 1; i >= 0; i--) {
                down(a, i, offset, size);
            }
            for (int i = size - 1; i > 0; i--) {
                int tmp = a[offset];
                a[offset] = a[offset + i];
                a[offset + i] = tmp;
                down(a, 0, offset, i);
            }
        }

        private static void down(int[] a, int index, int offset, int size) {
            final int element = a[offset + index];
            final int firstLeaf = (size >>> 1);
            while (index < firstLeaf) {
                int largestChild = (index << 1) + 1;
                if (largestChild + 1 < size && a[offset + largestChild + 1] > a[offset + largestChild]) {
                    largestChild++;
                }
                if (a[offset + largestChild] <= element) {
                    break;
                }
                a[offset + index] = a[offset + largestChild];
                index = largestChild;
            }
            a[offset + index] = element;
        }

    }

    static interface IntComparator {
        IntComparator DEFAULT = Integer::compare;

        int compare(int first, int second);

    }

    static class IntArray extends id3 implements IntList {
        private int[] data;

        public IntArray(int[] arr) {
            data = arr;
        }

        public int size() {
            return data.length;
        }

        public int get(int at) {
            return data[at];
        }

        public void addAt(int index, int value) {
            throw new UnsupportedOperationException();
        }

        public void removeAt(int index) {
            throw new UnsupportedOperationException();
        }

    }

    static interface id21 extends IntCollection {
    }

    static class id9 implements id8 {
        private static final int id23 = 8;
        private static final int id12 = 32;
        private static final int id14 = 0x811c9dc5;
        private static final int id24 = 0x01000193;
        private static final byte FREE = 0;
        private static final byte REMOVED = 1;
        private static final byte FILLED = 2;
        private static final Random rnd = new Random();
        private static final int id17;
        private static final int id27;
        private static final int id7;
        private static final int id6;
        private int[] table;
        private byte[] status;
        private int size;
        private int removedCount;
        private int mask;
        private final int hashSeed;

        static {
            id17 = rnd.nextInt(10) + 11;
            id27 = rnd.nextInt(10) + 21;
            id7 = rnd.nextInt(10) + 11;
            id6 = rnd.nextInt(10) + 21;
        }

        public id9() {
            this(id23);
        }

        public id9(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            

            int length = 4 * Math.max(1, capacity);
            if ((length & (length - 1)) != 0) {
                length = Integer.highestOneBit(length) << 1;
            }
            

            id26(length);
            hashSeed = rnd.nextInt();
        }

        public id9(id1 collection) {
            this(collection.size());
            for (id20 iterator = collection.iterator(); iterator.hasNext(); ) {
                add(iterator.next());
            }
        }

        public id9(int[] srcArray) {
            this(srcArray.length);
            for (int element : srcArray) {
                add(element);
            }
        }

        public id9(Collection<Integer> javaCollection) {
            this(javaCollection.size());
            for (int element : javaCollection) {
                add(element);
            }
        }

        private int id2(int h) {
            h ^= hashSeed;
            h ^= (h >>> id17) ^ (h >>> id27);
            return h & mask;
        }

        private int getStep(int h) {
            h ^= hashSeed;
            h ^= (h >>> id7) ^ (h >>> id6);
            return ((h << 1) | 1) & mask;
        }

        public int size() {
            return size;
        }

        public boolean contains(int element) {
            final int elementHash = id11.getHash(element);
            int pos = id2(elementHash);
            final int step = getStep(elementHash);
            for (; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && table[pos] == element) {
                    return true;
                }
            }
            return false;
        }

        public id20 iterator() {
            return new id22();
        }

        public int[] toArray() {
            int[] result = new int[size];
            for (int i = 0, j = 0; i < table.length; i++) {
                if (status[i] == FILLED) {
                    result[j++] = table[i];
                }
            }
            return result;
        }

        public boolean add(int element) {
            final int elementHash = id11.getHash(element);
            int pos = id2(elementHash);
            final int step = getStep(elementHash);
            for (; status[pos] == FILLED; pos = (pos + step) & mask) {
                if (table[pos] == element) {
                    return false;
                }
            }
            if (status[pos] == FREE) {
                status[pos] = FILLED;
                table[pos] = element;
                size++;
                if ((size + removedCount) * 2 > table.length) {
                    rebuild(table.length * 2); 

                }
                return true;
            }
            final int removedPos = pos;
            for (pos = (pos + step) & mask; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && table[pos] == element) {
                    return false;
                }
            }
            status[removedPos] = FILLED;
            table[removedPos] = element;
            size++;
            removedCount--;
            return true;
        }

        public boolean remove(int element) {
            final int elementHash = id11.getHash(element);
            int pos = id2(elementHash);
            final int step = getStep(elementHash);
            for (; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && table[pos] == element) {
                    status[pos] = REMOVED;
                    size--;
                    removedCount++;
                    if (table.length > id12) {
                        if (8 * size <= table.length) {
                            rebuild(table.length / 2); 

                        } else if (size < removedCount) {
                            rebuild(table.length); 

                        }
                    }
                    return true;
                }
            }
            return false;
        }

        private void rebuild(int newLength) {
            int[] oldTable = table;
            byte[] oldStatus = status;
            id26(newLength);
            for (int i = 0; i < oldTable.length; i++) {
                if (oldStatus[i] == FILLED) {
                    add(oldTable[i]);
                }
            }
        }

        private void id26(int length) {
            table = new int[length];
            status = new byte[length];
            size = 0;
            removedCount = 0;
            mask = length - 1;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id9 that = (id9) o;

            if (size != that.size) {
                return false;
            }
            for (int i = 0; i < table.length; i++) {
                if (status[i] == FILLED) {
                    if (!that.contains(table[i])) {
                        return false;
                    }
                }
            }
            return true;
        }

        public int hashCode() {
            int[] array = toArray();
            id16.sort(array);
            int hash = id14;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ id11.getHash(array[i])) * id24;
            }
            return hash;
        }

        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append('[');
            for (int i = 0; i < table.length; i++) {
                if (status[i] == FILLED) {
                    if (sb.length() > 1) {
                        sb.append(", ");
                    }
                    sb.append(table[i]);
                }
            }
            sb.append(']');
            return sb.toString();
        }

        private class id22 implements id20 {
            private int curIndex = 0;

            public boolean hasNext() {
                while (curIndex < table.length && status[curIndex] != FILLED) {
                    curIndex++;
                }
                return curIndex < table.length;
            }

            public int next() {
                while (curIndex < table.length && status[curIndex] != FILLED) {
                    curIndex++;
                }
                if (curIndex == table.length) {
                    throw new NoSuchElementException("Iterator doesn't have more elements");
                }
                return table[curIndex++];
            }

        }

    }

    static abstract class id3 implements id19 {
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
            if (!(o instanceof id19)) {
                return false;
            }
            id19 c = (id19) o;
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

    static class Range {
        public static IntList range(int from, int to) {
            int[] result = new int[Math.abs(from - to)];
            int current = from;
            if (from <= to) {
                for (int i = 0; i < result.length; i++) {
                    result[i] = current++;
                }
            } else {
                for (int i = 0; i < result.length; i++) {
                    result[i] = current--;
                }
            }
            return new IntArray(result);
        }

        public static IntList range(int n) {
            return range(0, n);
        }

    }

    static class InputReader {
        private final InputStream stream;
        private final byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id25 filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public void id10(int[]... arrays) {
            int length = (int) Arrays.stream(arrays[0]).count();
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readInt();
                }
            }
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
            while (id4(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id4(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (id4(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id4(c));
            return res.toString();
        }

        public boolean id4(int c) {
            if (filter != null) {
                return filter.id4(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            return readString();
        }

        public interface id25 {
            boolean id4(int ch);

        }

    }

    static interface id8 extends id1 {
        int size();

        boolean contains(int element);

        id20 iterator();

        int[] toArray();

        boolean add(int element);

        boolean remove(int element);

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface id19 extends Iterable<Integer>, Comparable<id19> {
        IntIterator intIterator();

        default Iterator<Integer> iterator() {
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

        default int compareTo(id19 c) {
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

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static final class id11 {
        private id11() {
        }

        public static int getHash(int x) {
            return x;
        }

    }
}

