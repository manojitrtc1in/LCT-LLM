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
        id17 solver = new id17();
        solver.solve(1, in, out);
        out.close();
    }

    static class id17 {
        long id7 = 0;
        long id6 = 0;
        id20 ezib = new id20();
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

            

            

            id9 t = new id9(n);

            HashMap<id8, Boolean> p = new HashMap<>();
            

            

            for (int i = 0; i < m; i++) {
                int a = in.nextInt();
                int b = in.nextInt();
                int start = Math.min(a, b);
                int end = Math.max(a, b);
                boolean equals = (in.nextString().equals("crewmate"));
                t.addEdge(start, end);
                var edge = new id8(start, end);
                if (p.containsKey(edge)) {
                    if (p.get(edge) != equals) {
                        broken = true;
                    }
                }
                p.put(new id8(start, end), equals);
            }

            if (broken) {
                out.println("-1");
                return;
            }

            


            long id28 = 0;
            

            id13 visited = new id13();
            for (Integer nn : t.nodes.keySet()) {
                if (visited.contains(nn)) {
                    continue;
                }
                id7 = 0;
                id6 = 0;
                ezib = new id20();
                id19(true, nn, p, visited, t);
                if (broken == true) {
                    out.println("-1");
                    return;
                }

                id28 += Math.max(id6, id7 - id6);
            }

            if (broken == true) {
                out.println("-1");
            } else {
                out.println(id28 + n - (t.nodes.size()));
            }


        }

        private void id19(boolean believe, Integer nn, HashMap<id8, Boolean> p, id13 visited, id9 t) {
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
                id7++;
            } else {
                id7++;
                id6++;
            }
            visited.add(nn);

            for (var n : t.getNode(nn).edges.toArray()) {
                int start = Math.min(nn, n);
                int end = Math.max(nn, n);
                var edge = new id8(start, end);
                var realEdge = p.get(edge);
                id19(realEdge == believe, n, p, visited, t);
            }
        }

    }

    static class id20 implements id3 {
        private static final int id25 = 8;
        private static final int id16 = 0x811c9dc5;
        private static final int id26 = 0x01000193;
        private static final byte FREE = 0;
        private static final byte FILLED = 2;
        private static final boolean id15 = (new boolean[1])[0];
        private static final Random rnd = new Random(System.nanoTime());
        private static final int id22;
        private static final int id31;
        private static final int id11;
        private static final int id10;
        private int[] keys;
        private boolean[] values;
        private byte[] status;
        private int size;
        private int removedCount;
        private int mask;
        private boolean returnedNull;
        private final int hashSeed;

        static {
            id22 = rnd.nextInt(10) + 11;
            id31 = rnd.nextInt(10) + 21;
            id11 = rnd.nextInt(10) + 11;
            id10 = rnd.nextInt(10) + 21;
        }

        public id20() {
            this(id25);
        }

        public id20(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            

            int length = 4 * Math.max(1, capacity);
            if ((length & (length - 1)) != 0) {
                length = Integer.highestOneBit(length) << 1;
            }
            

            id29(length);
            returnedNull = false;
            hashSeed = rnd.nextInt();
        }

        public id20(id3 map) {
            this(map.size());
            for (id0 it = map.iterator(); it.hasNext(); it.next()) {
                put(it.getKey(), it.getValue());
            }
        }

        public id20(Map<Integer, Boolean> javaMap) {
            this(javaMap.size());
            for (Map.Entry<Integer, Boolean> e : javaMap.entrySet()) {
                put(e.getKey(), e.getValue());
            }
        }

        private int id4(int h) {
            h ^= hashSeed;
            h ^= (h >>> id22) ^ (h >>> id31);
            return h & mask;
        }

        private int getStep(int h) {
            h ^= hashSeed;
            h ^= (h >>> id11) ^ (h >>> id10);
            return ((h << 1) | 1) & mask;
        }

        public int size() {
            return size;
        }

        public boolean containsKey(int key) {
            final int keyHash = id14.getHash(key);
            int pos = id4(keyHash);
            final int step = getStep(keyHash);
            for (; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && keys[pos] == key) {
                    return true;
                }
            }
            return false;
        }

        public boolean get(int key) {
            final int keyHash = id14.getHash(key);
            int pos = id4(keyHash);
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

        public boolean put(int key, boolean value) {
            final int keyHash = id14.getHash(key);
            int pos = id4(keyHash);
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
                return id15;
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
            return id15;
        }

        public id0 iterator() {
            return new id30();
        }

        private void rebuild(int newLength) {
            int[] oldKeys = keys;
            boolean[] oldValues = values;
            byte[] oldStatus = status;
            id29(newLength);
            for (int i = 0; i < oldKeys.length; i++) {
                if (oldStatus[i] == FILLED) {
                    put(oldKeys[i], oldValues[i]);
                }
            }
        }

        private void id29(int length) {
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
            id20 that = (id20) o;

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
                    int hash = id16;
                    hash = (hash ^ id14.getHash(keys[i])) * id26;
                    hash = (hash ^ id14.getHash(values[i])) * id26;
                    entryHashes[j++] = hash;
                }
            }
            randomShuffle(entryHashes);
            Arrays.sort(entryHashes);
            int hash = id16;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ entryHashes[i]) * id26;
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

        private class id30 implements id0 {
            private int curIndex;

            private id30() {
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

    static class id9 {
        public int size;
        public HashMap<Integer, Node> nodes;

        public id9(int size) {
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

    static final class id14 {
        private id14() {
        }

        public static int getHash(boolean x) {
            return x ? 1231 : 1237; 

        }

        public static int getHash(int x) {
            return x;
        }

    }

    static interface id0 {
        boolean hasNext();

        int getKey();

        boolean getValue();

        void next();

    }

    static class Node {
        int id;
        public id13 edges;

        public Node(int id) {
            this.id = id;
            edges = new id13();
        }

    }

    static class id8 implements Comparable<id8> {
        private static final int id16 = 0x811c9dc5;
        private static final int id26 = 0x01000193;
        public int first;
        public int second;

        public id8(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id8 that = (id8) o;

            return first == that.first && second == that.second;
        }

        public int hashCode() {
            int hash = id16;
            hash = (hash ^ id14.getHash(first)) * id26;
            hash = (hash ^ id14.getHash(second)) * id26;
            return hash;
        }

        public int compareTo(id8 o) {
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
            id21.sort(a);
        }

    }

    static class id13 implements id12 {
        private static final int id25 = 8;
        private static final int id16 = 0x811c9dc5;
        private static final int id26 = 0x01000193;
        private static final byte FREE = 0;
        private static final byte FILLED = 2;
        private static final Random rnd = new Random(System.nanoTime());
        private static final int id22;
        private static final int id31;
        private static final int id11;
        private static final int id10;
        private int[] table;
        private byte[] status;
        private int size;
        private int removedCount;
        private int mask;
        private final int hashSeed;

        static {
            id22 = rnd.nextInt(10) + 11;
            id31 = rnd.nextInt(10) + 21;
            id11 = rnd.nextInt(10) + 11;
            id10 = rnd.nextInt(10) + 21;
        }

        public id13() {
            this(id25);
        }

        public id13(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            

            int length = 4 * Math.max(1, capacity);
            if ((length & (length - 1)) != 0) {
                length = Integer.highestOneBit(length) << 1;
            }
            

            id29(length);
            hashSeed = rnd.nextInt();
        }

        public id13(id2 collection) {
            this(collection.size());
            for (id23 iterator = collection.iterator(); iterator.hasNext(); ) {
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

        private int id4(int h) {
            h ^= hashSeed;
            h ^= (h >>> id22) ^ (h >>> id31);
            return h & mask;
        }

        private int getStep(int h) {
            h ^= hashSeed;
            h ^= (h >>> id11) ^ (h >>> id10);
            return ((h << 1) | 1) & mask;
        }

        public int size() {
            return size;
        }

        public boolean contains(int element) {
            final int elementHash = id14.getHash(element);
            int pos = id4(elementHash);
            final int step = getStep(elementHash);
            for (; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && table[pos] == element) {
                    return true;
                }
            }
            return false;
        }

        public id23 iterator() {
            return new id24();
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
            int pos = id4(elementHash);
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
            id29(newLength);
            for (int i = 0; i < oldTable.length; i++) {
                if (oldStatus[i] == FILLED) {
                    add(oldTable[i]);
                }
            }
        }

        private void id29(int length) {
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
            id21.sort(array);
            int hash = id16;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ id14.getHash(array[i])) * id26;
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

        private class id24 implements id23 {
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

    static interface id23 {
        boolean hasNext();

        int next();

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id27 filter;

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

        public String nextString() {
            int c = read();
            while (id5(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id5(c));
            return res.toString();
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

        public interface id27 {
            public boolean id5(int ch);

        }

    }

    static interface id12 extends id2 {
        int size();

        id23 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static final class id21 {
        private static final double id1 = 2.0;
        private static final Random rnd = new Random(System.nanoTime());

        private id21() {
        }

        private static int id18(int length) {
            if (length <= 1) {
                return 0;
            }
            int log = Integer.numberOfTrailingZeros(Integer.highestOneBit(length - 1)) + 1;
            return (int) (id1 * log);
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

    static interface id2 {
        int size();

        id23 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface id3 {
        int size();

        id0 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }
}

