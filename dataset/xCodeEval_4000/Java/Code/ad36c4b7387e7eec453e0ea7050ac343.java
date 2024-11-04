import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.InputMismatchException;
import java.util.HashMap;
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
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        DTheNumberOfImposters solver = new DTheNumberOfImposters();
        solver.solve(1, in, out);
        out.close();
    }

    static class DTheNumberOfImposters {
        long currentTotalNodes = 0;
        long currentImposters = 0;
        EzIntBooleanHashMap ezib = new EzIntBooleanHashMap();
        boolean broken = false;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            var tc = in.nextInt();
            for (int i = 0; i < tc; i++) {
                solution(i, in, out);
            }
        }

        void solution(int testNumber, InputReader in, OutputWriter out) {
            

            int n = in.nextInt();
            int m = in.nextInt();
            broken = false;

            

            

            UndirectedTree t = new UndirectedTree(n);

            HashMap<EzIntIntPair, Boolean> p = new HashMap<>();
            

            

            for (int i = 0; i < m; i++) {
                int a = in.nextInt();
                int b = in.nextInt();
                int start = Math.min(a, b);
                int end = Math.max(a, b);
                boolean equals = (in.nextString().equals("crewmate"));
                t.addEdge(start, end);
                var edge = new EzIntIntPair(start, end);
                if (p.containsKey(edge)) {
                    if (p.get(edge) != equals) {
                        broken = true;
                    }
                }
                p.put(new EzIntIntPair(start, end), equals);
            }

            if (broken) {
                out.println("-1");
                return;
            }

            


            long imposters = 0;
            

            EzIntHashSet visited = new EzIntHashSet();
            for (Integer nn : t.nodes.keySet()) {
                if (visited.contains(nn)) {
                    continue;
                }
                currentTotalNodes = 0;
                currentImposters = 0;
                ezib = new EzIntBooleanHashMap();
                maxImposters(true, nn, p, visited, t);
                if (broken == true) {
                    out.println("-1");
                    return;
                }

                imposters += Math.max(currentImposters, currentTotalNodes - currentImposters);
            }

            if (broken == true) {
                out.println("-1");
            } else {
                out.println(imposters + n - (t.nodes.size()));
            }


        }

        private void maxImposters(boolean believe, Integer nn, HashMap<EzIntIntPair, Boolean> p, EzIntHashSet visited, UndirectedTree t) {
            if (ezib.containsKey(nn)) {
                if (ezib.get(nn) != believe) {
                    broken = true;
                    return;
                }
            }
            ezib.put(nn, believe);
            if (visited.contains(nn)) {
                return;
            }


            if (believe) {
                currentTotalNodes++;
            } else {
                currentTotalNodes++;
                currentImposters++;
            }
            visited.add(nn);

            for (var n : t.getNode(nn).edges.toArray()) {
                int start = Math.min(nn, n);
                int end = Math.max(nn, n);
                var edge = new EzIntIntPair(start, end);
                var realEdge = p.get(edge);
                maxImposters(realEdge == believe, n, p, visited, t);
            }
        }

    }

    static class EzIntBooleanHashMap implements EzIntBooleanMap {
        private static final int DEFAULT_CAPACITY = 8;
        private static final int HASHCODE_INITIAL_VALUE = 0x811c9dc5;
        private static final int HASHCODE_MULTIPLIER = 0x01000193;
        private static final byte FREE = 0;
        private static final byte FILLED = 2;
        private static final boolean DEFAULT_NULL_VALUE = (new boolean[1])[0];
        private static final Random rnd = new Random(System.nanoTime());
        private static final int POS_RANDOM_SHIFT_1;
        private static final int POS_RANDOM_SHIFT_2;
        private static final int STEP_RANDOM_SHIFT_1;
        private static final int STEP_RANDOM_SHIFT_2;
        private int[] keys;
        private boolean[] values;
        private byte[] status;
        private int size;
        private int removedCount;
        private int mask;
        private boolean returnedNull;
        private final int hashSeed;

        static {
            POS_RANDOM_SHIFT_1 = rnd.nextInt(10) + 11;
            POS_RANDOM_SHIFT_2 = rnd.nextInt(10) + 21;
            STEP_RANDOM_SHIFT_1 = rnd.nextInt(10) + 11;
            STEP_RANDOM_SHIFT_2 = rnd.nextInt(10) + 21;
        }

        public EzIntBooleanHashMap() {
            this(DEFAULT_CAPACITY);
        }

        public EzIntBooleanHashMap(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            

            int length = 4 * Math.max(1, capacity);
            if ((length & (length - 1)) != 0) {
                length = Integer.highestOneBit(length) << 1;
            }
            

            initEmptyTable(length);
            returnedNull = false;
            hashSeed = rnd.nextInt();
        }

        public EzIntBooleanHashMap(EzIntBooleanMap map) {
            this(map.size());
            for (EzIntBooleanMapIterator it = map.iterator(); it.hasNext(); it.next()) {
                put(it.getKey(), it.getValue());
            }
        }

        public EzIntBooleanHashMap(Map<Integer, Boolean> javaMap) {
            this(javaMap.size());
            for (Map.Entry<Integer, Boolean> e : javaMap.entrySet()) {
                put(e.getKey(), e.getValue());
            }
        }

        private int getStartPos(int h) {
            h ^= hashSeed;
            h ^= (h >>> POS_RANDOM_SHIFT_1) ^ (h >>> POS_RANDOM_SHIFT_2);
            return h & mask;
        }

        private int getStep(int h) {
            h ^= hashSeed;
            h ^= (h >>> STEP_RANDOM_SHIFT_1) ^ (h >>> STEP_RANDOM_SHIFT_2);
            return ((h << 1) | 1) & mask;
        }

        public int size() {
            return size;
        }

        public boolean containsKey(int key) {
            final int keyHash = PrimitiveHashCalculator.getHash(key);
            int pos = getStartPos(keyHash);
            final int step = getStep(keyHash);
            for (; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && keys[pos] == key) {
                    return true;
                }
            }
            return false;
        }

        public boolean get(int key) {
            final int keyHash = PrimitiveHashCalculator.getHash(key);
            int pos = getStartPos(keyHash);
            final int step = getStep(keyHash);
            for (; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && keys[pos] == key) {
                    returnedNull = false;
                    return values[pos];
                }
            }
            returnedNull = true;
            return DEFAULT_NULL_VALUE;
        }

        public boolean put(int key, boolean value) {
            final int keyHash = PrimitiveHashCalculator.getHash(key);
            int pos = getStartPos(keyHash);
            final int step = getStep(keyHash);
            for (; status[pos] == FILLED; pos = (pos + step) & mask) {
                if (keys[pos] == key) {
                    final boolean oldValue = values[pos];
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
                return DEFAULT_NULL_VALUE;
            }
            final int removedPos = pos;
            for (pos = (pos + step) & mask; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && keys[pos] == key) {
                    final boolean oldValue = values[pos];
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
            return DEFAULT_NULL_VALUE;
        }

        public EzIntBooleanMapIterator iterator() {
            return new EzIntBooleanHashMapIterator();
        }

        private void rebuild(int newLength) {
            int[] oldKeys = keys;
            boolean[] oldValues = values;
            byte[] oldStatus = status;
            initEmptyTable(newLength);
            for (int i = 0; i < oldKeys.length; i++) {
                if (oldStatus[i] == FILLED) {
                    put(oldKeys[i], oldValues[i]);
                }
            }
        }

        private void initEmptyTable(int length) {
            keys = new int[length];
            values = new boolean[length];
            status = new byte[length];
            size = 0;
            removedCount = 0;
            mask = length - 1;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            EzIntBooleanHashMap that = (EzIntBooleanHashMap) o;

            if (size != that.size) {
                return false;
            }
            for (int i = 0; i < keys.length; i++) {
                if (status[i] == FILLED) {
                    boolean thatValue = that.get(keys[i]);
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
                    int hash = HASHCODE_INITIAL_VALUE;
                    hash = (hash ^ PrimitiveHashCalculator.getHash(keys[i])) * HASHCODE_MULTIPLIER;
                    hash = (hash ^ PrimitiveHashCalculator.getHash(values[i])) * HASHCODE_MULTIPLIER;
                    entryHashes[j++] = hash;
                }
            }
            randomShuffle(entryHashes);
            Arrays.sort(entryHashes);
            int hash = HASHCODE_INITIAL_VALUE;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ entryHashes[i]) * HASHCODE_MULTIPLIER;
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

        private class EzIntBooleanHashMapIterator implements EzIntBooleanMapIterator {
            private int curIndex;

            private EzIntBooleanHashMapIterator() {
                curIndex = 0;
                while (curIndex < status.length && status[curIndex] != FILLED) {
                    curIndex++;
                }
            }

            public boolean hasNext() {
                return curIndex < status.length;
            }

            public int getKey() {
                if (curIndex == keys.length) {
                    throw new NoSuchElementException("Iterator doesn't have more entries");
                }
                return keys[curIndex];
            }

            public boolean getValue() {
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

    static class UndirectedTree {
        public int size;
        public HashMap<Integer, Node> nodes;

        public UndirectedTree(int size) {
            this.size = size;
            nodes = new HashMap<>();
        }

        public void addEdge(int start, int end) {
            nodes.putIfAbsent(start, new Node(start));
            nodes.putIfAbsent(end, new Node(end));

            Node startNode = nodes.get(start);
            Node endNode = nodes.get(end);
            startNode.edges.add(end);
            endNode.edges.add(start);
        }

        public Node getNode(int n) {
            return nodes.get(n);
        }

    }

    static final class PrimitiveHashCalculator {
        private PrimitiveHashCalculator() {
        }

        public static int getHash(boolean x) {
            return x ? 1231 : 1237; 

        }

        public static int getHash(int x) {
            return x;
        }

    }

    static interface EzIntBooleanMapIterator {
        boolean hasNext();

        int getKey();

        boolean getValue();

        void next();

    }

    static class Node {
        int id;
        public EzIntHashSet edges;

        public Node(int id) {
            this.id = id;
            edges = new EzIntHashSet();
        }

    }

    static class EzIntIntPair implements Comparable<EzIntIntPair> {
        private static final int HASHCODE_INITIAL_VALUE = 0x811c9dc5;
        private static final int HASHCODE_MULTIPLIER = 0x01000193;
        public int first;
        public int second;

        public EzIntIntPair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            EzIntIntPair that = (EzIntIntPair) o;

            return first == that.first && second == that.second;
        }

        public int hashCode() {
            int hash = HASHCODE_INITIAL_VALUE;
            hash = (hash ^ PrimitiveHashCalculator.getHash(first)) * HASHCODE_MULTIPLIER;
            hash = (hash ^ PrimitiveHashCalculator.getHash(second)) * HASHCODE_MULTIPLIER;
            return hash;
        }

        public int compareTo(EzIntIntPair o) {
            int res = Integer.compare(first, o.first);
            if (res == 0) {
                res = Integer.compare(second, o.second);
            }
            return res;
        }

        public String toString() {
            return "(" + first + ", " + second + ")";
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

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

    }

    static class Arrays {
        private Arrays() {
        }

        public static void sort(int[] a) {
            EzIntSort.sort(a);
        }

    }

    static class EzIntHashSet implements EzIntSet {
        private static final int DEFAULT_CAPACITY = 8;
        private static final int HASHCODE_INITIAL_VALUE = 0x811c9dc5;
        private static final int HASHCODE_MULTIPLIER = 0x01000193;
        private static final byte FREE = 0;
        private static final byte FILLED = 2;
        private static final Random rnd = new Random(System.nanoTime());
        private static final int POS_RANDOM_SHIFT_1;
        private static final int POS_RANDOM_SHIFT_2;
        private static final int STEP_RANDOM_SHIFT_1;
        private static final int STEP_RANDOM_SHIFT_2;
        private int[] table;
        private byte[] status;
        private int size;
        private int removedCount;
        private int mask;
        private final int hashSeed;

        static {
            POS_RANDOM_SHIFT_1 = rnd.nextInt(10) + 11;
            POS_RANDOM_SHIFT_2 = rnd.nextInt(10) + 21;
            STEP_RANDOM_SHIFT_1 = rnd.nextInt(10) + 11;
            STEP_RANDOM_SHIFT_2 = rnd.nextInt(10) + 21;
        }

        public EzIntHashSet() {
            this(DEFAULT_CAPACITY);
        }

        public EzIntHashSet(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            

            int length = 4 * Math.max(1, capacity);
            if ((length & (length - 1)) != 0) {
                length = Integer.highestOneBit(length) << 1;
            }
            

            initEmptyTable(length);
            hashSeed = rnd.nextInt();
        }

        public EzIntHashSet(EzIntCollection collection) {
            this(collection.size());
            for (EzIntIterator iterator = collection.iterator(); iterator.hasNext(); ) {
                add(iterator.next());
            }
        }

        public EzIntHashSet(int[] srcArray) {
            this(srcArray.length);
            for (int element : srcArray) {
                add(element);
            }
        }

        public EzIntHashSet(Collection<Integer> javaCollection) {
            this(javaCollection.size());
            for (int element : javaCollection) {
                add(element);
            }
        }

        private int getStartPos(int h) {
            h ^= hashSeed;
            h ^= (h >>> POS_RANDOM_SHIFT_1) ^ (h >>> POS_RANDOM_SHIFT_2);
            return h & mask;
        }

        private int getStep(int h) {
            h ^= hashSeed;
            h ^= (h >>> STEP_RANDOM_SHIFT_1) ^ (h >>> STEP_RANDOM_SHIFT_2);
            return ((h << 1) | 1) & mask;
        }

        public int size() {
            return size;
        }

        public boolean contains(int element) {
            final int elementHash = PrimitiveHashCalculator.getHash(element);
            int pos = getStartPos(elementHash);
            final int step = getStep(elementHash);
            for (; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && table[pos] == element) {
                    return true;
                }
            }
            return false;
        }

        public EzIntIterator iterator() {
            return new EzIntHashSetIterator();
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
            final int elementHash = PrimitiveHashCalculator.getHash(element);
            int pos = getStartPos(elementHash);
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
            initEmptyTable(newLength);
            for (int i = 0; i < oldTable.length; i++) {
                if (oldStatus[i] == FILLED) {
                    add(oldTable[i]);
                }
            }
        }

        private void initEmptyTable(int length) {
            table = new int[length];
            status = new byte[length];
            size = 0;
            removedCount = 0;
            mask = length - 1;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            EzIntHashSet that = (EzIntHashSet) o;

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
            EzIntSort.sort(array);
            int hash = HASHCODE_INITIAL_VALUE;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ PrimitiveHashCalculator.getHash(array[i])) * HASHCODE_MULTIPLIER;
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

        private class EzIntHashSetIterator implements EzIntIterator {
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

    static interface EzIntIterator {
        boolean hasNext();

        int next();

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

        public int nextInt() {
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
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public String nextString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static interface EzIntSet extends EzIntCollection {
        int size();

        EzIntIterator iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static final class EzIntSort {
        private static final double HEAPSORT_DEPTH_COEFFICIENT = 2.0;
        private static final Random rnd = new Random(System.nanoTime());

        private EzIntSort() {
        }

        private static int maxQuickSortDepth(int length) {
            if (length <= 1) {
                return 0;
            }
            int log = Integer.numberOfTrailingZeros(Integer.highestOneBit(length - 1)) + 1;
            return (int) (HEAPSORT_DEPTH_COEFFICIENT * log);
        }

        public static void sort(int[] a) {
            quickSort(a, 0, a.length, 0, maxQuickSortDepth(a.length));
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

    static interface EzIntCollection {
        int size();

        EzIntIterator iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface EzIntBooleanMap {
        int size();

        EzIntBooleanMapIterator iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }
}

