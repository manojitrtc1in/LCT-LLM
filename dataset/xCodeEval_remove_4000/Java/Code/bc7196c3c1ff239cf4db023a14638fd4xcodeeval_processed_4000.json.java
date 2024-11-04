import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Collection;
import java.io.IOException;
import java.io.Writer;
import java.util.Map.Entry;
import java.util.Comparator;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        id20 solver = new id20();
        solver.solve(1, in, out);
        out.close();
    }

    static class id20 {
        public static InputReader in = null;
        public static OutputWriter out = null;
        id4 memo = new id4();
        Node[] nodes;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            var tc = in.nextInt();
            for (int i = 0; i < tc; i++) {
                Thread t = new Thread(null, null, "Task", 1 << 28) {

                    public void run() {
                        solution(0, in, out);
                    }
                };
                t.start();
                try {
                    t.join();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

        }

        void solution(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            nodes = new Node[n + 1];
            for (int i = 1; i <= n; i++) {
                Node node = new Node(i);
                nodes[i] = node;
            }


            for (int i = 2; i <= n; i++) {
                int parent = in.nextInt();
                Node parentN = nodes[parent];
                parentN.edges.add(i);
            }

            for (int i = 1; i <= n; i++) {
                Node node = nodes[i];
                node.score = in.nextInt();
            }

            memo.clear();
            out.println(maxValue(nodes[1], k));
        }

        long maxValue(Node node, int k) {
            if (node.edges.size() == 0) {
                return (long) node.score * (long) k;
            }

            long key = getKey(node.id, k);
            if (memo.containsKey(key)) {
                return memo.get(key);
            }

            int[] edges = node.edges.toArray();

            int r = k / edges.length;
            int rem = k % edges.length;

            Node[] nodes = new Node[edges.length];
            for (int i = 0; i < edges.length; i++) {
                nodes[i] = this.nodes[edges[i]];
            }

            if (rem > 0) {
                Arrays.sort(nodes, (a, b) -> Long.compare(maxValue(a, r) - maxValue(a, r + 1), maxValue(b, r) - maxValue(b, r + 1)));
            }

            long totalScore = 0;
            totalScore += (long) node.score * (long) k;

            for (int i = 0; i < rem; i++) {
                totalScore += maxValue(nodes[i], r + 1);
            }

            for (int i = rem; i < edges.length; i++) {
                totalScore += maxValue(nodes[i], r);
            }

            memo.put(key, totalScore);
            return totalScore;
        }

        long getKey(int node, int k) {
            return ((long) node << 32) | k;
        }

    }

    static interface id0 {
        int size();

        id15 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

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

        public void println(long i) {
            writer.println(i);
        }

    }

    static class id4 implements id0 {
        private static final int id22 = 8;
        private static final int id11 = 32;
        private static final int id14 = 0x811c9dc5;
        private static final int id23 = 0x01000193;
        private static final byte FREE = 0;
        private static final byte FILLED = 2;
        private static final long id12 = (new long[1])[0];
        private static final Random rnd = new Random(System.nanoTime());
        private static final int id18;
        private static final int id26;
        private static final int id7;
        private static final int id6;
        private long[] keys;
        private long[] values;
        private byte[] status;
        private int size;
        private int removedCount;
        private int mask;
        private boolean returnedNull;
        private final int hashSeed;

        static {
            id18 = rnd.nextInt(10) + 11;
            id26 = rnd.nextInt(10) + 21;
            id7 = rnd.nextInt(10) + 11;
            id6 = rnd.nextInt(10) + 21;
        }

        public id4() {
            this(id22);
        }

        public id4(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            

            int length = 4 * Math.max(1, capacity);
            if ((length & (length - 1)) != 0) {
                length = Integer.highestOneBit(length) << 1;
            }
            

            id25(length);
            returnedNull = false;
            hashSeed = rnd.nextInt();
        }

        public id4(id0 map) {
            this(map.size());
            for (id15 it = map.iterator(); it.hasNext(); it.next()) {
                put(it.getKey(), it.getValue());
            }
        }

        public id4(Map<Long, Long> javaMap) {
            this(javaMap.size());
            for (Map.Entry<Long, Long> e : javaMap.entrySet()) {
                put(e.getKey(), e.getValue());
            }
        }

        private int id3(int h) {
            h ^= hashSeed;
            h ^= (h >>> id18) ^ (h >>> id26);
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

        public boolean containsKey(long key) {
            final int keyHash = id10.getHash(key);
            int pos = id3(keyHash);
            final int step = getStep(keyHash);
            for (; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && keys[pos] == key) {
                    return true;
                }
            }
            return false;
        }

        public long get(long key) {
            final int keyHash = id10.getHash(key);
            int pos = id3(keyHash);
            final int step = getStep(keyHash);
            for (; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && keys[pos] == key) {
                    returnedNull = false;
                    return values[pos];
                }
            }
            returnedNull = true;
            return id12;
        }

        public long put(long key, long value) {
            final int keyHash = id10.getHash(key);
            int pos = id3(keyHash);
            final int step = getStep(keyHash);
            for (; status[pos] == FILLED; pos = (pos + step) & mask) {
                if (keys[pos] == key) {
                    final long oldValue = values[pos];
                    values[pos] = value;
                    returnedNull = false;
                    return oldValue;
                }
            }
            if (status[pos] == FREE) {
                status[pos] = FILLED;
                keys[pos] = key;
                values[pos] = value;
                size++;
                if ((size + removedCount) * 2 > keys.length) {
                    rebuild(keys.length * 2); 

                }
                returnedNull = true;
                return id12;
            }
            final int removedPos = pos;
            for (pos = (pos + step) & mask; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && keys[pos] == key) {
                    final long oldValue = values[pos];
                    values[pos] = value;
                    returnedNull = false;
                    return oldValue;
                }
            }
            status[removedPos] = FILLED;
            keys[removedPos] = key;
            values[removedPos] = value;
            size++;
            removedCount--;
            returnedNull = true;
            return id12;
        }

        public void clear() {
            if (keys.length > id11) {
                id25(id11);
            } else {
                Arrays.fill(status, FREE);
                size = 0;
                removedCount = 0;
            }
        }

        public id15 iterator() {
            return new id13();
        }

        private void rebuild(int newLength) {
            long[] oldKeys = keys;
            long[] oldValues = values;
            byte[] oldStatus = status;
            id25(newLength);
            for (int i = 0; i < oldKeys.length; i++) {
                if (oldStatus[i] == FILLED) {
                    put(oldKeys[i], oldValues[i]);
                }
            }
        }

        private void id25(int length) {
            keys = new long[length];
            values = new long[length];
            status = new byte[length];
            size = 0;
            removedCount = 0;
            mask = length - 1;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id4 that = (id4) o;

            if (size != that.size) {
                return false;
            }
            for (int i = 0; i < keys.length; i++) {
                if (status[i] == FILLED) {
                    long thatValue = that.get(keys[i]);
                    if (that.returnedNull || thatValue != values[i]) {
                        return false;
                    }
                }
            }
            return true;
        }

        private void randomShuffle(int[] array) {
            int n = array.length;
            for (int i = 0; i < n; i++) {
                int j = i + rnd.nextInt(n - i);
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }

        public int hashCode() {
            int[] entryHashes = new int[size];
            for (int i = 0, j = 0; i < status.length; i++) {
                if (status[i] == FILLED) {
                    int hash = id14;
                    hash = (hash ^ id10.getHash(keys[i])) * id23;
                    hash = (hash ^ id10.getHash(values[i])) * id23;
                    entryHashes[j++] = hash;
                }
            }
            randomShuffle(entryHashes);
            Arrays.sort(entryHashes);
            int hash = id14;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ entryHashes[i]) * id23;
            }
            return hash;
        }

        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append('{');
            for (int i = 0; i < keys.length; i++) {
                if (status[i] == FILLED) {
                    if (sb.length() > 1) {
                        sb.append(", ");
                    }
                    sb.append(keys[i]);
                    sb.append('=');
                    sb.append(values[i]);
                }
            }
            sb.append('}');
            return sb.toString();
        }

        private class id13 implements id15 {
            private int curIndex;

            private id13() {
                curIndex = 0;
                while (curIndex < status.length && status[curIndex] != FILLED) {
                    curIndex++;
                }
            }

            public boolean hasNext() {
                return curIndex < status.length;
            }

            public long getKey() {
                if (curIndex == keys.length) {
                    throw new NoSuchElementException("Iterator doesn't have more entries");
                }
                return keys[curIndex];
            }

            public long getValue() {
                if (curIndex == values.length) {
                    throw new NoSuchElementException("Iterator doesn't have more entries");
                }
                return values[curIndex];
            }

            public void next() {
                if (curIndex == status.length) {
                    return;
                }
                curIndex++;
                while (curIndex < status.length && status[curIndex] != FILLED) {
                    curIndex++;
                }
            }

        }

    }

    static interface id2 {
        int size();

        id19 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface id15 {
        boolean hasNext();

        long getKey();

        long getValue();

        void next();

    }

    static interface id8 extends id2 {
        int size();

        id19 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static final class id17 {
        private static final double id1 = 2.0;
        private static final Random rnd = new Random(System.nanoTime());

        private id17() {
        }

        private static int id16(int length) {
            if (length <= 1) {
                return 0;
            }
            int log = Integer.numberOfTrailingZeros(Integer.highestOneBit(length - 1)) + 1;
            return (int) (id1 * log);
        }

        public static void sort(int[] a) {
            quickSort(a, 0, a.length, 0, id16(a.length));
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

    static final class id10 {
        private id10() {
        }

        public static int getHash(int x) {
            return x;
        }

        public static int getHash(long x) {
            return (int) x ^ (int) (x >>> 32);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id24 filter;

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

        public int nextInt() {
            int c = read();
            while (id5(c)) {
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
            } while (!id5(c));
            return res * sgn;
        }

        public boolean id5(int c) {
            if (filter != null) {
                return filter.id5(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface id24 {
            public boolean id5(int ch);

        }

    }

    static class id9 implements id8 {
        private static final int id22 = 8;
        private static final int id14 = 0x811c9dc5;
        private static final int id23 = 0x01000193;
        private static final byte FREE = 0;
        private static final byte FILLED = 2;
        private static final Random rnd = new Random(System.nanoTime());
        private static final int id18;
        private static final int id26;
        private static final int id7;
        private static final int id6;
        private int[] table;
        private byte[] status;
        private int size;
        private int removedCount;
        private int mask;
        private final int hashSeed;

        static {
            id18 = rnd.nextInt(10) + 11;
            id26 = rnd.nextInt(10) + 21;
            id7 = rnd.nextInt(10) + 11;
            id6 = rnd.nextInt(10) + 21;
        }

        public id9() {
            this(id22);
        }

        public id9(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            

            int length = 4 * Math.max(1, capacity);
            if ((length & (length - 1)) != 0) {
                length = Integer.highestOneBit(length) << 1;
            }
            

            id25(length);
            hashSeed = rnd.nextInt();
        }

        public id9(id2 collection) {
            this(collection.size());
            for (id19 iterator = collection.iterator(); iterator.hasNext(); ) {
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

        private int id3(int h) {
            h ^= hashSeed;
            h ^= (h >>> id18) ^ (h >>> id26);
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
            final int elementHash = id10.getHash(element);
            int pos = id3(elementHash);
            final int step = getStep(elementHash);
            for (; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && table[pos] == element) {
                    return true;
                }
            }
            return false;
        }

        public id19 iterator() {
            return new id21();
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
            final int elementHash = id10.getHash(element);
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

        private void rebuild(int newLength) {
            int[] oldTable = table;
            byte[] oldStatus = status;
            id25(newLength);
            for (int i = 0; i < oldTable.length; i++) {
                if (oldStatus[i] == FILLED) {
                    add(oldTable[i]);
                }
            }
        }

        private void id25(int length) {
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
            id17.sort(array);
            int hash = id14;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ id10.getHash(array[i])) * id23;
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

        private class id21 implements id19 {
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

    static class Node {
        public int id;
        public int score = 0;
        public id9 edges;

        public Node(int id) {
            this.id = id;
            edges = new id9();
        }

    }

    static class Arrays {
        private Arrays() {
        }

        public static void sort(int[] a) {
            id17.sort(a);
        }

        public static <T> void sort(T[] a, Comparator<? super T> c) {
            java.util.Arrays.sort(a, c);
        }

        public static void fill(byte[] a, byte val) {
            java.util.Arrays.fill(a, val);

        }

    }

    static interface id19 {
        boolean hasNext();

        int next();

    }
}

