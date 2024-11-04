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
        id16 solver = new id16();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class id16 {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt(), m = in.readInt(), k = in.readInt();
            int[] u = new int[m], v = new int[m];
            in.id12(u, v);
            MiscUtils.id7(u, v);
            id10[] graph = createGraph(n, m, u, v);
            solve(n, graph, k, out);
        }

        void solve(int n, id10[] graph, int k, OutputWriter out) {
            id25 set = new id25(Range.range(n).toArray(),
                    (i, j) -> graph[i].size() != graph[j].size() ? Integer.compare(graph[i].size(), graph[j].size()) : Integer.compare(i, j));
            while (!set.isEmpty() && graph[set.getFirst()].size() < k) {
                int u = set.removeFirst();
                if (graph[u].size() == k - 1 && checkClique(u, graph)) {
                    int[] res = new int[k];
                    res[0] = u;
                    System.arraycopy(graph[u].toArray(), 0, res, 1, k - 1);
                    MiscUtils.id22(res);
                    out.printLine(2);
                    out.printLine(res);
                    return;
                }
                for (id26 it = graph[u].iterator(); it.hasNext(); ) {
                    int v = it.next();
                    set.remove(v);
                    graph[v].remove(u);
                    set.add(v);
                }
                graph[u].clear();
            }
            if (set.isEmpty()) {
                out.printLine(-1);
            } else {
                int[] res = set.toArray();
                MiscUtils.id22(res);
                out.printLine(1, set.size());
                out.printLine(res);
            }
        }

        boolean checkClique(int u, id10[] graph) {
            for (id26 it = graph[u].iterator(); it.hasNext(); ) {
                int v = it.next();
                for (id26 it2 = graph[u].iterator(); it2.hasNext(); ) {
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
            Arrays.setAll(res, i -> new id11(0));
            for (int i = 0; i < m; i++) {
                res[u[i]].add(v[i]);
                res[v[i]].add(u[i]);
            }
            return res;
        }

    }

    static interface id26 {
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

    static class IntArray extends id4 implements IntList {
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

        public void removeAt(int index) {
            throw new UnsupportedOperationException();
        }

    }

    static interface id1 {
        int size();

        id26 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface IntCollection extends id24 {
        public int size();

        default public int[] toArray() {
            int size = size();
            int[] array = new int[size];
            int i = 0;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                array[i++] = it.value();
            }
            return array;
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

    static class id11 implements id10 {
        private static final int id31 = 8;
        private static final int id14 = 32;
        private static final int id17 = 0x811c9dc5;
        private static final int id32 = 0x01000193;
        private static final byte FREE = 0;
        private static final byte REMOVED = 1;
        private static final byte FILLED = 2;
        private static final Random rnd = new Random();
        private static final int id21;
        private static final int id36;
        private static final int id9;
        private static final int id8;
        private int[] table;
        private byte[] status;
        private int size;
        private int removedCount;
        private int mask;
        private final int hashSeed;

        static {
            id21 = rnd.nextInt(10) + 11;
            id36 = rnd.nextInt(10) + 21;
            id9 = rnd.nextInt(10) + 11;
            id8 = rnd.nextInt(10) + 21;
        }

        public id11() {
            this(id31);
        }

        public id11(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            

            int length = 4 * Math.max(1, capacity);
            if ((length & (length - 1)) != 0) {
                length = Integer.highestOneBit(length) << 1;
            }
            

            id35(length);
            hashSeed = rnd.nextInt();
        }

        public id11(id1 collection) {
            this(collection.size());
            for (id26 iterator = collection.iterator(); iterator.hasNext(); ) {
                add(iterator.next());
            }
        }

        public id11(int[] srcArray) {
            this(srcArray.length);
            for (int element : srcArray) {
                add(element);
            }
        }

        public id11(Collection<Integer> javaCollection) {
            this(javaCollection.size());
            for (int element : javaCollection) {
                add(element);
            }
        }

        private int id2(int h) {
            h ^= hashSeed;
            h ^= (h >>> id21) ^ (h >>> id36);
            return h & mask;
        }

        private int getStep(int h) {
            h ^= hashSeed;
            h ^= (h >>> id9) ^ (h >>> id8);
            return ((h << 1) | 1) & mask;
        }

        public int size() {
            return size;
        }

        public boolean contains(int element) {
            final int elementHash = id13.getHash(element);
            int pos = id2(elementHash);
            final int step = getStep(elementHash);
            for (; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && table[pos] == element) {
                    return true;
                }
            }
            return false;
        }

        public id26 iterator() {
            return new id30();
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
            final int elementHash = id13.getHash(element);
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
            final int elementHash = id13.getHash(element);
            int pos = id2(elementHash);
            final int step = getStep(elementHash);
            for (; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && table[pos] == element) {
                    status[pos] = REMOVED;
                    size--;
                    removedCount++;
                    if (table.length > id14) {
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
            if (table.length > id14) {
                id35(id14);
            } else {
                Arrays.fill(status, FREE);
                size = 0;
                removedCount = 0;
            }
        }

        private void rebuild(int newLength) {
            int[] oldTable = table;
            byte[] oldStatus = status;
            id35(newLength);
            for (int i = 0; i < oldTable.length; i++) {
                if (oldStatus[i] == FILLED) {
                    add(oldTable[i]);
                }
            }
        }

        private void id35(int length) {
            table = new int[length];
            status = new byte[length];
            size = 0;
            removedCount = 0;
            mask = length - 1;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id11 that = (id11) o;

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
            id20.sort(array);
            int hash = id17;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ id13.getHash(array[i])) * id32;
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

        private class id30 implements id26 {
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

    static class InputReader {
        private final InputStream stream;
        private final byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id33 filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public void id12(int[]... arrays) {
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
            while (id3(c)) {
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
            } while (!id3(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (id3(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id3(c));
            return res.toString();
        }

        public boolean id3(int c) {
            if (filter != null) {
                return filter.id3(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            return readString();
        }

        public interface id33 {
            boolean id3(int ch);

        }

    }

    static interface id10 extends id1 {
        int size();

        boolean contains(int element);

        id26 iterator();

        int[] toArray();

        boolean add(int element);

        boolean remove(int element);

        void clear();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface id34 extends id10 {
        int size();

        boolean contains(int element);

        id26 iterator();

        int[] toArray();

        boolean add(int element);

        boolean remove(int element);

        void clear();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface id28 extends IntCollection {
    }

    static class MiscUtils {
        public static void id7(int[] array) {
            for (int i = 0; i < array.length; i++) {
                array[i]--;
            }
        }

        public static void id7(int[]... arrays) {
            for (int[] array : arrays) {
                id7(array);
            }
        }

        public static void id22(int[] array) {
            for (int i = 0; i < array.length; i++) {
                array[i]++;
            }
        }

    }

    static interface id24 extends Iterable<Integer>, Comparable<id24> {
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

        default int compareTo(id24 c) {
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

    static abstract class id4 implements id24 {
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
            if (!(o instanceof id24)) {
                return false;
            }
            id24 c = (id24) o;
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

    static interface IntList extends id28 {
        public abstract int get(int index);

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

    }

    static final class id20 {
        private static final double id0 = 2.0;
        private static final Random rnd = new Random();

        private id20() {
        }

        private static int id19(int length) {
            if (length <= 1) {
                return 0;
            }
            int log = Integer.numberOfTrailingZeros(Integer.highestOneBit(length - 1)) + 1;
            return (int) (id0 * log);
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

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static final class id13 {
        private id13() {
        }

        public static int getHash(int x) {
            return x;
        }

    }

    static interface id15 {
        int compare(int a, int b);

    }

    static class id25 implements id34 {
        private static final int id31 = 10;
        private static final double id5 = 2.0;
        private static final int id17 = 0x811c9dc5;
        private static final int id32 = 0x01000193;
        private static final boolean BLACK = false;
        private static final boolean RED = true;
        private static final int NULL = 0;
        private static final int id27 = (new int[1])[0];
        private int[] key;
        private int[] left;
        private int[] right;
        private int[] p;
        private boolean[] color;
        private int size;
        private int root;
        private boolean returnedNull;
        private id15 cmp;

        public id25(id15 cmp) {
            this(id31, cmp);
        }

        public id25(int capacity, id15 cmp) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            this.cmp = cmp;
            capacity++;
            key = new int[capacity];
            left = new int[capacity];
            right = new int[capacity];
            p = new int[capacity];
            color = new boolean[capacity];
            color[NULL] = BLACK;
            size = 0;
            root = NULL;
            returnedNull = false;
        }

        public id25(id1 collection, id15 cmp) {
            this(collection.size(), cmp);
            for (id26 iterator = collection.iterator(); iterator.hasNext(); ) {
                add(iterator.next());
            }
        }

        public id25(int[] srcArray, id15 cmp) {
            this(srcArray.length, cmp);
            for (int element : srcArray) {
                add(element);
            }
        }

        public id25(Collection<Integer> javaCollection, id15 cmp) {
            this(javaCollection.size(), cmp);
            for (int element : javaCollection) {
                add(element);
            }
        }

        public int size() {
            return size;
        }

        public boolean isEmpty() {
            return size == 0;
        }

        public boolean contains(int element) {
            int x = root;
            while (x != NULL) {
                int cmpRes = cmp.compare(element, key[x]);
                if (cmpRes < 0) {
                    x = left[x];
                } else if (cmpRes > 0) {
                    x = right[x];
                } else {
                    return true;
                }
            }
            return false;
        }

        public id26 iterator() {
            return new id23();
        }

        public int[] toArray() {
            int[] result = new int[size];
            for (int i = 0, x = firstNode(); x != NULL; x = id29(x), i++) {
                result[i] = key[x];
            }
            return result;
        }

        public boolean add(int element) {
            int y = NULL;
            int x = root;
            while (x != NULL) {
                

                y = x;
                int cmpRes = cmp.compare(element, key[x]);
                if (cmpRes < 0) {
                    x = left[x];
                } else if (cmpRes > 0) {
                    x = right[x];
                } else {
                    return false;
                }
            }
            if (size == color.length - 1) {
                enlarge();
            }
            int z = ++size;
            key[z] = element;
            p[z] = y;
            if (y == NULL) {
                root = z;
            } else {
                if (cmp.compare(element, key[y]) < 0) {
                    left[y] = z;
                } else {
                    right[y] = z;
                }
            }
            left[z] = NULL;
            right[z] = NULL;
            color[z] = RED;
            id18(z);
            return true;
        }

        public boolean remove(int element) {
            int z = root;
            while (z != NULL) {
                int cmpRes = cmp.compare(element, key[z]);
                if (cmpRes < 0) {
                    z = left[z];
                } else if (cmpRes > 0) {
                    z = right[z];
                } else {
                    removeNode(z);
                    return true;
                }
            }
            return false;
        }

        private void removeNode(int z) {
            int y = (left[z] == NULL || right[z] == NULL) ? z : id29(z);
            int x = (left[y] != NULL) ? left[y] : right[y];
            p[x] = p[y];
            if (p[y] == NULL) {
                root = x;
            } else {
                if (y == left[p[y]]) {
                    left[p[y]] = x;
                } else {
                    right[p[y]] = x;
                }
            }
            if (y != z) {
                key[z] = key[y];
            }
            

            if (color[y] == BLACK) {
                id6(x);
            }
            

            if (y != size) {
                

                key[y] = key[size];
                left[y] = left[size];
                right[y] = right[size];
                p[y] = p[size];
                color[y] = color[size];
                

                p[left[size]] = y;
                p[right[size]] = y;
                

                if (left[p[size]] == size) {
                    left[p[size]] = y;
                } else {
                    right[p[size]] = y;
                }
                

                if (root == size) {
                    root = y;
                }
            }
            size--;
        }

        private int id29(int x) {
            if (right[x] != NULL) {
                x = right[x];
                while (left[x] != NULL) {
                    x = left[x];
                }
                return x;
            } else {
                int y = p[x];
                while (y != NULL && x == right[y]) {
                    

                    x = y;
                    y = p[y];
                }
                return y;
            }
        }

        private void id18(int z) {
            while (color[p[z]] == RED) {
                if (p[z] == left[p[p[z]]]) {
                    int y = right[p[p[z]]];
                    if (color[y] == RED) {
                        color[p[z]] = BLACK;
                        color[y] = BLACK;
                        color[p[p[z]]] = RED;
                        z = p[p[z]];
                    } else {
                        if (z == right[p[z]]) {
                            z = p[z];
                            rotateLeft(z);
                        }
                        color[p[z]] = BLACK;
                        color[p[p[z]]] = RED;
                        rotateRight(p[p[z]]);
                    }
                } else {
                    int y = left[p[p[z]]];
                    if (color[y] == RED) {
                        color[p[z]] = BLACK;
                        color[y] = BLACK;
                        color[p[p[z]]] = RED;
                        z = p[p[z]];
                    } else {
                        if (z == left[p[z]]) {
                            z = p[z];
                            rotateRight(z);
                        }
                        color[p[z]] = BLACK;
                        color[p[p[z]]] = RED;
                        rotateLeft(p[p[z]]);
                    }
                }
            }
            color[root] = BLACK;
        }

        private void id6(int x) {
            while (x != root && color[x] == BLACK) {
                if (x == left[p[x]]) {
                    int w = right[p[x]];
                    if (color[w] == RED) {
                        color[w] = BLACK;
                        color[p[x]] = RED;
                        rotateLeft(p[x]);
                        w = right[p[x]];
                    }
                    if (color[left[w]] == BLACK && color[right[w]] == BLACK) {
                        color[w] = RED;
                        x = p[x];
                    } else {
                        if (color[right[w]] == BLACK) {
                            color[left[w]] = BLACK;
                            color[w] = RED;
                            rotateRight(w);
                            w = right[p[x]];
                        }
                        color[w] = color[p[x]];
                        color[p[x]] = BLACK;
                        color[right[w]] = BLACK;
                        rotateLeft(p[x]);
                        x = root;
                    }
                } else {
                    int w = left[p[x]];
                    if (color[w] == RED) {
                        color[w] = BLACK;
                        color[p[x]] = RED;
                        rotateRight(p[x]);
                        w = left[p[x]];
                    }
                    if (color[left[w]] == BLACK && color[right[w]] == BLACK) {
                        color[w] = RED;
                        x = p[x];
                    } else {
                        if (color[left[w]] == BLACK) {
                            color[right[w]] = BLACK;
                            color[w] = RED;
                            rotateLeft(w);
                            w = left[p[x]];
                        }
                        color[w] = color[p[x]];
                        color[p[x]] = BLACK;
                        color[left[w]] = BLACK;
                        rotateRight(p[x]);
                        x = root;
                    }
                }
            }
            color[x] = BLACK;
        }

        private void rotateLeft(int x) {
            int y = right[x];
            right[x] = left[y];
            if (left[y] != NULL) {
                p[left[y]] = x;
            }
            p[y] = p[x];
            if (p[x] == NULL) {
                root = y;
            } else {
                if (x == left[p[x]]) {
                    left[p[x]] = y;
                } else {
                    right[p[x]] = y;
                }
            }
            left[y] = x;
            p[x] = y;
        }

        private void rotateRight(int x) {
            int y = left[x];
            left[x] = right[y];
            if (right[y] != NULL) {
                p[right[y]] = x;
            }
            p[y] = p[x];
            if (p[x] == NULL) {
                root = y;
            } else {
                if (x == right[p[x]]) {
                    right[p[x]] = y;
                } else {
                    left[p[x]] = y;
                }
            }
            right[y] = x;
            p[x] = y;
        }

        public void clear() {
            color[NULL] = BLACK;
            size = 0;
            root = NULL;
        }

        private void enlarge() {
            int newLength = Math.max(color.length + 1, (int) (color.length * id5));
            key = Arrays.copyOf(key, newLength);
            left = Arrays.copyOf(left, newLength);
            right = Arrays.copyOf(right, newLength);
            p = Arrays.copyOf(p, newLength);
            color = Arrays.copyOf(color, newLength);
        }

        private int firstNode() {
            int x = root;
            while (left[x] != NULL) {
                x = left[x];
            }
            return x;
        }

        public int getFirst() {
            if (root == NULL) {
                returnedNull = true;
                return id27;
            }
            final int x = firstNode();
            returnedNull = false;
            return key[x];
        }

        public int removeFirst() {
            if (root == NULL) {
                returnedNull = true;
                return id27;
            }
            final int x = firstNode();
            returnedNull = false;
            final int removedElement = key[x];
            removeNode(x);
            return removedElement;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id25 that = (id25) o;

            if (size != that.size) {
                return false;
            }
            for (int x = firstNode(), y = that.firstNode();
                 x != NULL;
                

                 x = id29(x), y = that.id29(y)
            ) {
                if (key[x] != that.key[y]) {
                    return false;
                }
            }
            return true;
        }

        public int hashCode() {
            int hash = id17;
            for (int x = firstNode(); x != NULL; x = id29(x)) {
                hash = (hash ^ id13.getHash(key[x])) * id32;
            }
            return hash;
        }

        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append('[');
            for (int x = firstNode(); x != NULL; x = id29(x)) {
                if (sb.length() > 1) {
                    sb.append(", ");
                }
                sb.append(key[x]);
            }
            sb.append(']');
            return sb.toString();
        }

        private class id23 implements id26 {
            private int x;

            private id23() {
                x = firstNode();
            }

            public boolean hasNext() {
                return x != NULL;
            }

            public int next() {
                if (x == NULL) {
                    throw new NoSuchElementException("Iterator doesn't have more elements");
                }
                final int result = key[x];
                x = id29(x);
                return result;
            }

        }

    }
}

