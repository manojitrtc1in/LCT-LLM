import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Collection;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Random;
import java.util.Map;
import java.io.Writer;
import java.util.Map.Entry;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        id0 solver = new id0();
        solver.solve(1, in, out);
        out.close();
    }

    static class id0 {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            var tc = in.nextInt();
            for (int i = 0; i < tc; i++) {
                solution(i, in, out);
            }
        }

        void solution(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] arr = in.id12(n);

            

            id2 id8 = new id2();
            for (int i = 0; i < n; i++) {
                id8.put(arr[i], i);
            }

            id13 zeroed = new id13();
            int broken = -1;
            for (int i = n - 1; i > 0; i--) {
                if (arr[i - 1] > arr[i]) {
                    broken = i;
                    break;
                }
            }

            if (broken == -1) {
                out.println(0);
                return;
            }


            purge(arr, broken - 1, 0, zeroed, id8);
            out.println(zeroed.size());
        }

        void purge(int[] arr, int end, int start, id13 zeroed, id2 id8) {
            for (int i = end; i >= start; i--) {
                if (!zeroed.contains(arr[i])) {
                    int lastPosition = id8.get(arr[i]);
                    if (lastPosition > end) {
                        purge(arr, lastPosition, end, zeroed, id8);
                    }
                }
                zeroed.add(arr[i]);
            }
        }

    }

    static class id2 implements id1 {
        private static final int id23 = 8;
        private static final int id17 = 0x811c9dc5;
        private static final int id24 = 0x01000193;
        private static final byte FREE = 0;
        private static final byte FILLED = 2;
        public static final int id15 = 0;
        private static final Random rnd = new Random(System.nanoTime());
        private static final int id20;
        private static final int id27;
        private static final int id10;
        private static final int id9;
        private int[] keys;
        private int[] values;
        private byte[] status;
        private int size;
        private int removedCount;
        private int mask;
        private boolean returnedNull;
        private final int hashSeed;

        static {
            id20 = rnd.nextInt(10) + 11;
            id27 = rnd.nextInt(10) + 21;
            id10 = rnd.nextInt(10) + 11;
            id9 = rnd.nextInt(10) + 21;
        }

        public id2() {
            this(id23);
        }

        public id2(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            

            int length = 4 * Math.max(1, capacity);
            if ((length & (length - 1)) != 0) {
                length = Integer.highestOneBit(length) << 1;
            }
            

            id26(length);
            returnedNull = false;
            hashSeed = rnd.nextInt();
        }

        public id2(id1 map) {
            this(map.size());
            for (id16 it = map.iterator(); it.hasNext(); it.next()) {
                put(it.getKey(), it.getValue());
            }
        }

        public id2(Map<Integer, Integer> javaMap) {
            this(javaMap.size());
            for (Map.Entry<Integer, Integer> e : javaMap.entrySet()) {
                put(e.getKey(), e.getValue());
            }
        }

        private int id5(int h) {
            h ^= hashSeed;
            h ^= (h >>> id20) ^ (h >>> id27);
            return h & mask;
        }

        private int getStep(int h) {
            h ^= hashSeed;
            h ^= (h >>> id10) ^ (h >>> id9);
            return ((h << 1) | 1) & mask;
        }

        public int size() {
            return size;
        }

        public int get(int key) {
            final int keyHash = id14.getHash(key);
            int pos = id5(keyHash);
            final int step = getStep(keyHash);
            for (; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && keys[pos] == key) {
                    returnedNull = false;
                    return values[pos];
                }
            }
            returnedNull = true;
            return id15;
        }

        public int put(int key, int value) {
            final int keyHash = id14.getHash(key);
            int pos = id5(keyHash);
            final int step = getStep(keyHash);
            for (; status[pos] == FILLED; pos = (pos + step) & mask) {
                if (keys[pos] == key) {
                    final int oldValue = values[pos];
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
                return id15;
            }
            final int removedPos = pos;
            for (pos = (pos + step) & mask; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && keys[pos] == key) {
                    final int oldValue = values[pos];
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
            return id15;
        }

        public id16 iterator() {
            return new id7();
        }

        private void rebuild(int newLength) {
            int[] oldKeys = keys;
            int[] oldValues = values;
            byte[] oldStatus = status;
            id26(newLength);
            for (int i = 0; i < oldKeys.length; i++) {
                if (oldStatus[i] == FILLED) {
                    put(oldKeys[i], oldValues[i]);
                }
            }
        }

        private void id26(int length) {
            keys = new int[length];
            values = new int[length];
            status = new byte[length];
            size = 0;
            removedCount = 0;
            mask = length - 1;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id2 that = (id2) o;

            if (size != that.size) {
                return false;
            }
            for (int i = 0; i < keys.length; i++) {
                if (status[i] == FILLED) {
                    int thatValue = that.get(keys[i]);
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
                    int hash = id17;
                    hash = (hash ^ id14.getHash(keys[i])) * id24;
                    hash = (hash ^ id14.getHash(values[i])) * id24;
                    entryHashes[j++] = hash;
                }
            }
            randomShuffle(entryHashes);
            Arrays.sort(entryHashes);
            int hash = id17;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ entryHashes[i]) * id24;
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

        private class id7 implements id16 {
            private int curIndex;

            private id7() {
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

            public int getValue() {
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

    static class id13 implements id11 {
        private static final int id23 = 8;
        private static final int id17 = 0x811c9dc5;
        private static final int id24 = 0x01000193;
        private static final byte FREE = 0;
        private static final byte FILLED = 2;
        private static final Random rnd = new Random(System.nanoTime());
        private static final int id20;
        private static final int id27;
        private static final int id10;
        private static final int id9;
        private int[] table;
        private byte[] status;
        private int size;
        private int removedCount;
        private int mask;
        private final int hashSeed;

        static {
            id20 = rnd.nextInt(10) + 11;
            id27 = rnd.nextInt(10) + 21;
            id10 = rnd.nextInt(10) + 11;
            id9 = rnd.nextInt(10) + 21;
        }

        public id13() {
            this(id23);
        }

        public id13(int capacity) {
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

        public id13(id4 collection) {
            this(collection.size());
            for (id21 iterator = collection.iterator(); iterator.hasNext(); ) {
                add(iterator.next());
            }
        }

        public id13(int[] srcArray) {
            this(srcArray.length);
            for (int element : srcArray) {
                add(element);
            }
        }

        public id13(Collection<Integer> javaCollection) {
            this(javaCollection.size());
            for (int element : javaCollection) {
                add(element);
            }
        }

        private int id5(int h) {
            h ^= hashSeed;
            h ^= (h >>> id20) ^ (h >>> id27);
            return h & mask;
        }

        private int getStep(int h) {
            h ^= hashSeed;
            h ^= (h >>> id10) ^ (h >>> id9);
            return ((h << 1) | 1) & mask;
        }

        public int size() {
            return size;
        }

        public boolean contains(int element) {
            final int elementHash = id14.getHash(element);
            int pos = id5(elementHash);
            final int step = getStep(elementHash);
            for (; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && table[pos] == element) {
                    return true;
                }
            }
            return false;
        }

        public id21 iterator() {
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
            final int elementHash = id14.getHash(element);
            int pos = id5(elementHash);
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
            id13 that = (id13) o;

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
            id19.sort(array);
            int hash = id17;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ id14.getHash(array[i])) * id24;
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

        private class id22 implements id21 {
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

    static interface id11 extends id4 {
        int size();

        id21 iterator();

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

        public void println(int i) {
            writer.println(i);
        }

    }

    static final class id19 {
        private static final double id3 = 2.0;
        private static final Random rnd = new Random(System.nanoTime());

        private id19() {
        }

        private static int id18(int length) {
            if (length <= 1) {
                return 0;
            }
            int log = Integer.numberOfTrailingZeros(Integer.highestOneBit(length - 1)) + 1;
            return (int) (id3 * log);
        }

        public static void sort(int[] a) {
            quickSort(a, 0, a.length, 0, id18(a.length));
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

    static interface id16 {
        boolean hasNext();

        int getKey();

        int getValue();

        void next();

    }

    static interface id4 {
        int size();

        id21 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface id1 {
        int size();

        id16 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static class Arrays {
        private Arrays() {
        }

        public static void sort(int[] a) {
            id19.sort(a);
        }

    }

    static interface id21 {
        boolean hasNext();

        int next();

    }

    static final class id14 {
        private id14() {
        }

        public static int getHash(int x) {
            return x;
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id25 filter;

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
            while (id6(c)) {
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
            } while (!id6(c));
            return res * sgn;
        }

        public boolean id6(int c) {
            if (filter != null) {
                return filter.id6(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public int[] id12(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; ++i) array[i] = nextInt();
            return array;
        }

        public interface id25 {
            public boolean id6(int ch);

        }

    }
}

