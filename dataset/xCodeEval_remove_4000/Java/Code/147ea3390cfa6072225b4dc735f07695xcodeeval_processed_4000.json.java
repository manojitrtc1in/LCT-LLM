import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.Collection;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Random;
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
        id17 solver = new id17();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class id17 {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt(), m = in.readInt(), k = in.readInt();
            int[] u = new int[m], v = new int[m];
            in.id13(u, v);
            MiscUtils.id8(u, v);
            id10[] graph = createGraph(n, m, u, v);
            solve(n, graph, k, out);
        }

        void solve(int n, id10[] graph, int k, OutputWriter out) {
            id20 queue = new id0();
            boolean[] used = new boolean[n];
            for (int i = 0; i < n; i++) {
                if (graph[i].size() < k) {
                    queue.add(i);
                    used[i] = true;
                }
            }
            while (!queue.isEmpty()) {
                int u = queue.removeFirst();
                if (graph[u].size() == k - 1 && checkClique(u, graph)) {
                    int[] res = new int[k];
                    res[0] = u;
                    System.arraycopy(graph[u].toArray(), 0, res, 1, k - 1);
                    MiscUtils.id24(res);
                    out.printLine(2);
                    out.printLine(res);
                    return;
                }
                for (id25 it = graph[u].iterator(); it.hasNext(); ) {
                    int v = it.next();
                    if (graph[v].size() == k) {
                        queue.add(v);
                        used[v] = true;
                    }
                    graph[v].remove(u);
                }
                graph[u].clear();
            }
            if (ArrayUtils.count(used, false) == 0) {
                out.printLine(-1);
            } else {
                id6 list = new id26();
                for (int i = 0; i < n; i++) {
                    if (!used[i]) {
                        list.add(i);
                    }
                }
                int[] res = list.toArray();
                MiscUtils.id24(res);
                out.printLine(1, res.length);
                out.printLine(res);
            }
        }

        boolean checkClique(int u, id10[] graph) {
            for (id25 it = graph[u].iterator(); it.hasNext(); ) {
                int v = it.next();
                for (id25 it2 = graph[u].iterator(); it2.hasNext(); ) {
                    int w = it2.next();
                    if (v != w && !graph[v].contains(w)) {
                        return false;
                    }
                }
            }
            return true;
        }

        id10[] createGraph(int n, int m, int[] u, int[] v) {
            id10[] res = new id10[n];
            Arrays.setAll(res, i -> new id12(0));
            for (int i = 0; i < m; i++) {
                res[u[i]].add(v[i]);
                res[v[i]].add(u[i]);
            }
            return res;
        }

    }

    static class ArrayUtils {
        public static int count(boolean[] array, boolean value) {
            int result = 0;
            for (boolean i : array) {
                if (i == value) {
                    result++;
                }
            }
            return result;
        }

    }

    static interface id10 extends id2 {
        int size();

        boolean contains(int element);

        id25 iterator();

        int[] toArray();

        boolean add(int element);

        boolean remove(int element);

        void clear();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface id27 extends id20, id7 {
        int size();

        boolean isEmpty();

        id25 iterator();

        boolean add(int element);

        boolean equals(Object object);

        int hashCode();

        String toString();

        int removeFirst();

    }

    static final class id22 {
        private static final double id1 = 2.0;
        private static final Random rnd = new Random();

        private id22() {
        }

        private static int id19(int length) {
            if (length <= 1) {
                return 0;
            }
            int log = Integer.numberOfTrailingZeros(Integer.highestOneBit(length - 1)) + 1;
            return (int) (id1 * log);
        }

        public static void sort(int[] a) {
            quickSort(a, 0, a.length, 0, id19(a.length));
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

    static interface id7 extends id2 {
        int size();

        id25 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static class id12 implements id10 {
        private static final int id29 = 8;
        private static final int id15 = 32;
        private static final int id18 = 0x811c9dc5;
        private static final int id30 = 0x01000193;
        private static final byte FREE = 0;
        private static final byte REMOVED = 1;
        private static final byte FILLED = 2;
        private static final Random rnd = new Random();
        private static final int id23;
        private static final int id33;
        private static final int id11;
        private static final int id9;
        private int[] table;
        private byte[] status;
        private int size;
        private int removedCount;
        private int mask;
        private final int hashSeed;

        static {
            id23 = rnd.nextInt(10) + 11;
            id33 = rnd.nextInt(10) + 21;
            id11 = rnd.nextInt(10) + 11;
            id9 = rnd.nextInt(10) + 21;
        }

        public id12() {
            this(id29);
        }

        public id12(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            

            int length = 4 * Math.max(1, capacity);
            if ((length & (length - 1)) != 0) {
                length = Integer.highestOneBit(length) << 1;
            }
            

            id32(length);
            hashSeed = rnd.nextInt();
        }

        public id12(id2 collection) {
            this(collection.size());
            for (id25 iterator = collection.iterator(); iterator.hasNext(); ) {
                add(iterator.next());
            }
        }

        public id12(int[] srcArray) {
            this(srcArray.length);
            for (int element : srcArray) {
                add(element);
            }
        }

        public id12(Collection<Integer> javaCollection) {
            this(javaCollection.size());
            for (int element : javaCollection) {
                add(element);
            }
        }

        private int id3(int h) {
            h ^= hashSeed;
            h ^= (h >>> id23) ^ (h >>> id33);
            return h & mask;
        }

        private int getStep(int h) {
            h ^= hashSeed;
            h ^= (h >>> id11) ^ (h >>> id9);
            return ((h << 1) | 1) & mask;
        }

        public int size() {
            return size;
        }

        public boolean contains(int element) {
            final int elementHash = id14.getHash(element);
            int pos = id3(elementHash);
            final int step = getStep(elementHash);
            for (; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && table[pos] == element) {
                    return true;
                }
            }
            return false;
        }

        public id25 iterator() {
            return new id28();
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
            final int elementHash = id14.getHash(element);
            int pos = id3(elementHash);
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
            final int elementHash = id14.getHash(element);
            int pos = id3(elementHash);
            final int step = getStep(elementHash);
            for (; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && table[pos] == element) {
                    status[pos] = REMOVED;
                    size--;
                    removedCount++;
                    if (table.length > id15) {
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

        public void clear() {
            if (table.length > id15) {
                id32(id15);
            } else {
                Arrays.fill(status, FREE);
                size = 0;
                removedCount = 0;
            }
        }

        private void rebuild(int newLength) {
            int[] oldTable = table;
            byte[] oldStatus = status;
            id32(newLength);
            for (int i = 0; i < oldTable.length; i++) {
                if (oldStatus[i] == FILLED) {
                    add(oldTable[i]);
                }
            }
        }

        private void id32(int length) {
            table = new int[length];
            status = new byte[length];
            size = 0;
            removedCount = 0;
            mask = length - 1;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id12 that = (id12) o;

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
            id22.sort(array);
            int hash = id18;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ id14.getHash(array[i])) * id30;
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

        private class id28 implements id25 {
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

    static class MiscUtils {
        public static void id8(int[] array) {
            for (int i = 0; i < array.length; i++) {
                array[i]--;
            }
        }

        public static void id8(int[]... arrays) {
            for (int[] array : arrays) {
                id8(array);
            }
        }

        public static void id24(int[] array) {
            for (int i = 0; i < array.length; i++) {
                array[i]++;
            }
        }

    }

    static interface id20 extends id2 {
        int size();

        boolean isEmpty();

        id25 iterator();

        boolean add(int element);

        boolean equals(Object object);

        int hashCode();

        String toString();

        int removeFirst();

    }

    static interface id6 extends id2 {
        int size();

        id25 iterator();

        int[] toArray();

        boolean add(int element);

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface id25 {
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

    static final class id14 {
        private id14() {
        }

        public static int getHash(int x) {
            return x;
        }

    }

    static class id26 implements id6, id7 {
        private static final int id29 = 10;
        private static final double id5 = 2.0;
        private static final int id18 = 0x811c9dc5;
        private static final int id30 = 0x01000193;
        private int[] array;
        private int size;

        public id26() {
            this(id29);
        }

        public id26(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            array = new int[capacity];
            size = 0;
        }

        public id26(id2 collection) {
            size = collection.size();
            array = new int[size];
            int i = 0;
            for (id25 iterator = collection.iterator(); iterator.hasNext(); ) {
                array[i++] = iterator.next();
            }
        }

        public id26(int[] srcArray) {
            size = srcArray.length;
            array = new int[size];
            System.arraycopy(srcArray, 0, array, 0, size);
        }

        public id26(Collection<Integer> javaCollection) {
            size = javaCollection.size();
            array = new int[size];
            int i = 0;
            for (int element : javaCollection) {
                array[i++] = element;
            }
        }

        public int size() {
            return size;
        }

        public id25 iterator() {
            return new id16();
        }

        public int[] toArray() {
            int[] result = new int[size];
            System.arraycopy(array, 0, result, 0, size);
            return result;
        }

        public boolean add(int element) {
            if (size == array.length) {
                enlarge();
            }
            array[size++] = element;
            return true;
        }

        private void enlarge() {
            int newSize = Math.max(size + 1, (int) (size * id5));
            int[] newArray = new int[newSize];
            System.arraycopy(array, 0, newArray, 0, size);
            array = newArray;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id26 that = (id26) o;

            if (size != that.size) {
                return false;
            }
            for (int i = 0; i < size; i++) {
                if (array[i] != that.array[i]) {
                    return false;
                }
            }
            return true;
        }

        public int hashCode() {
            int hash = id18;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ id14.getHash(array[i])) * id30;
            }
            return hash;
        }

        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append('[');
            for (int i = 0; i < size; i++) {
                sb.append(array[i]);
                if (i < size - 1) {
                    sb.append(", ");
                }
            }
            sb.append(']');
            return sb.toString();
        }

        private class id16 implements id25 {
            private int curIndex = 0;

            public boolean hasNext() {
                return curIndex < size;
            }

            public int next() {
                if (curIndex == size) {
                    throw new NoSuchElementException("Iterator doesn't have more elements");
                }
                return array[curIndex++];
            }

        }

    }

    static interface id2 {
        int size();

        id25 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static class id0 implements id27, id6 {
        private static final int id29 = 8;
        private static final int id18 = 0x811c9dc5;
        private static final int id30 = 0x01000193;
        private int[] deque;
        private int size;
        private int head;
        private int tail;
        private int mask;

        public id0() {
            this(id29);
        }

        public id0(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            if (capacity < 1) {
                capacity = 1;
            }
            if ((capacity & (capacity - 1)) != 0) {
                capacity = Integer.highestOneBit(capacity) << 1;
            }
            

            deque = new int[capacity];
            size = 0;
            head = 0;
            tail = 0;
            mask = deque.length - 1;
        }

        public id0(id2 collection) {
            this(collection.size() + 1);
            for (id25 iterator = collection.iterator(); iterator.hasNext(); ) {
                deque[tail++] = iterator.next();
            }
            size = collection.size();
        }

        public id0(int[] srcArray) {
            this(srcArray.length + 1);
            System.arraycopy(srcArray, 0, deque, 0, srcArray.length);
            tail = srcArray.length;
            size = srcArray.length;
        }

        public id0(Collection<Integer> javaCollection) {
            this(javaCollection.size() + 1);
            for (int element : javaCollection) {
                deque[tail++] = element;
            }
            size = javaCollection.size();
        }

        public int size() {
            return size;
        }

        public boolean isEmpty() {
            return size == 0;
        }

        public id25 iterator() {
            return new id21();
        }

        public int[] toArray() {
            int[] result = new int[size];
            for (int i = head, j = 0; i != tail; i = (i + 1) & mask) {
                result[j++] = deque[i];
            }
            return result;
        }

        public boolean add(int element) {
            deque[tail] = element;
            tail = (tail + 1) & mask;
            size++;
            if (size == deque.length) {
                enlarge();
            }
            return true;
        }

        public int removeFirst() {
            if (size == 0) {
                throw new NoSuchElementException("Trying to call removeFirst() on empty ArrayDeque");
            }
            final int removedElement = deque[head];
            size--;
            head = (head + 1) & mask;
            return removedElement;
        }

        private void enlarge() {
            int newSize = (size << 1);
            int[] newArray = new int[newSize];
            System.arraycopy(deque, head, newArray, 0, deque.length - head);
            System.arraycopy(deque, 0, newArray, deque.length - tail, tail);
            deque = newArray;
            head = 0;
            tail = size;
            mask = deque.length - 1;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id0 that = (id0) o;

            if (size != that.size) {
                return false;
            }
            for (int i = head, j = that.head; i != tail; i = (i + 1) & mask, j = (j + 1) & that.mask) {
                if (deque[i] != that.deque[j]) {
                    return false;
                }
            }
            return true;
        }

        public int hashCode() {
            int hash = id18;
            for (int i = head; i != tail; i = (i + 1) & mask) {
                hash = (hash ^ id14.getHash(deque[i])) * id30;
            }
            return hash;
        }

        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append('[');
            for (int i = head; i != tail; i = (i + 1) & mask) {
                if (i != head) {
                    sb.append(", ");
                }
                sb.append(deque[i]);
            }
            sb.append(']');
            return sb.toString();
        }

        private class id21 implements id25 {
            private int curIndex = head;

            public boolean hasNext() {
                return curIndex != tail;
            }

            public int next() {
                if (curIndex == tail) {
                    throw new NoSuchElementException("Iterator doesn't have more elements");
                }
                final int result = deque[curIndex];
                curIndex = (curIndex + 1) & mask;
                return result;
            }

        }

    }

    static class InputReader {
        private final InputStream stream;
        private final byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id31 filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public void id13(int[]... arrays) {
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

        public interface id31 {
            boolean id4(int ch);

        }

    }
}

