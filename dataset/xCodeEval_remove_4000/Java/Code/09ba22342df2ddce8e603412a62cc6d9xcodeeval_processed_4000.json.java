import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
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
        id3 solver = new id3();
        solver.solve(1, in, out);
        out.close();
    }

    static class id3 {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            var tc = in.nextInt();
            for (int i = 0; i < tc; i++) {
                solution(i, in, out);
            }
        }

        void solution(int testNumber, InputReader in, OutputWriter out) {
            char[] k = in.nextString().toCharArray();
            int limit = in.nextInt();
            var currentDigits = new id25(k).size();
            if (limit >= currentDigits) {
                out.println(k);
                return;
            }
            char[] stt = id13(k, limit);
            out.println(stt);
        }

        int findCount(char N) {
            int count = 0;
            while (N > 0) {
                count++;
                N = (char) (N & (N - 1));
            }
            return count;
        }

        int getBit(char n, int k) {
            return (n >> k) & 1;
        }

        private char[] id13(char[] k, int limit) {
            char[] minc = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};

            for (char zz = 0; findCount(zz) <= 10; zz++) {
                if (findCount(zz) == limit) {
                    var ezc = new id8();
                    for (int i = 0; i <= 10; i++) {
                        if (getBit(zz, i) == 1) {
                            ezc.add(Integer.toString(i).charAt(0));
                        }
                    }

                    char[] res = id19(k, ezc);
                    if (compareArrays(res, minc) < 0) {
                        minc = res;
                    }

                }
            }


            return minc;
        }

        private char[] id19(char[] ooo, id8 t) {
            

            

            char[] z = ArrayUtils.clone(ooo);
            for (int i = 0; i < z.length; i++) {
                char best = t.ceiling(z[i]);
                if (best == id8.id2) {
                    

                    


                    

                    char nnh = best;
                    for (; i >= 0 && nnh == id8.id2; i--) {
                        nnh = t.higher(z[i]);
                    }

                    

                    if (nnh == id8.id2) {
                        

                        var retArr = new char[z.length + 1];
                        

                        Arrays.fill(retArr, t.getFirst());
                        var firstChar = t.higher((char) '0');
                        if (firstChar != id8.id2) {
                            retArr[0] = firstChar;
                        } else {
                            Arrays.fill(retArr, (char) 'z');
                        }
                        return retArr;
                        

                    }

                    

                    

                    i++;
                    z[i] = nnh;
                    for (int zv = i + 1; zv < z.length; zv++) {
                        z[zv] = t.getFirst();
                    }
                    return z;
                }

                

                if (best == z[i]) {
                    continue;
                }

                if (best > z[i]) {
                    

                    z[i] = best;
                    for (int zv = i + 1; zv < z.length; zv++) {
                        z[zv] = t.getFirst();
                    }
                    return z;
                }
            }
            return z;
        }

        private int compareArrays(char[] a, char[] b) {
            if (a.length != b.length) {
                return Integer.compare(a.length, b.length);
            }
            return Arrays.compare(a, b);
        }

    }

    static class id8 implements id22 {
        private static final int id24 = 10;
        private static final double id7 = 2.0;
        private static final int id14 = 0x811c9dc5;
        private static final int id26 = 0x01000193;
        private static final boolean BLACK = false;
        private static final boolean RED = true;
        private static final int NULL = 0;
        public static final char id2 = (new char[1])[0];
        private char[] key;
        private int[] left;
        private int[] right;
        private int[] p;
        private boolean[] color;
        private int size;
        private int root;
        private boolean returnedNull;

        public id8() {
            this(id24);
        }

        public id8(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            capacity++;
            key = new char[capacity];
            left = new int[capacity];
            right = new int[capacity];
            p = new int[capacity];
            color = new boolean[capacity];
            color[NULL] = BLACK;
            size = 0;
            root = NULL;
            returnedNull = false;
        }

        public id8(id20 collection) {
            this(collection.size());
            for (id6 iterator = collection.iterator(); iterator.hasNext(); ) {
                add(iterator.next());
            }
        }

        public id8(char[] srcArray) {
            this(srcArray.length);
            for (char element : srcArray) {
                add(element);
            }
        }

        public id8(Collection<Character> javaCollection) {
            this(javaCollection.size());
            for (char element : javaCollection) {
                add(element);
            }
        }

        public int size() {
            return size;
        }

        public id6 iterator() {
            return new id16();
        }

        public boolean add(char element) {
            int y = NULL;
            int x = root;
            while (x != NULL) {
                

                y = x;
                if (element < key[x]) {
                    x = left[x];
                } else if (element > key[x]) {
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
                if (element < key[y]) {
                    left[y] = z;
                } else {
                    right[y] = z;
                }
            }
            left[z] = NULL;
            right[z] = NULL;
            color[z] = RED;
            id15(z);
            return true;
        }

        private int id21(int x) {
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

        private void id15(int z) {
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

        private void enlarge() {
            int newLength = Math.max(color.length + 1, (int) (color.length * id7));
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

        public char getFirst() {
            if (root == NULL) {
                returnedNull = true;
                return id2;
            }
            final int x = firstNode();
            returnedNull = false;
            return key[x];
        }

        public char ceiling(char element) {
            int x = root;
            while (x != NULL) {
                if (element < key[x]) {
                    if (left[x] != NULL) {
                        x = left[x];
                    } else {
                        returnedNull = false;
                        return key[x];
                    }
                } else if (element > key[x]) {
                    if (right[x] != NULL) {
                        x = right[x];
                    } else {
                        int y = p[x];
                        while (y != NULL && x == right[y]) {
                            

                            x = y;
                            y = p[y];
                        }
                        if (y == NULL) {
                            returnedNull = true;
                            return id2;
                        } else {
                            returnedNull = false;
                            return key[y];
                        }
                    }
                } else {
                    returnedNull = false;
                    return key[x];
                }
            }
            returnedNull = true;
            return id2;
        }

        public char higher(char element) {
            int x = root;
            while (x != NULL) {
                if (element < key[x]) {
                    if (left[x] != NULL) {
                        x = left[x];
                    } else {
                        returnedNull = false;
                        return key[x];
                    }
                } else {
                    if (right[x] != NULL) {
                        x = right[x];
                    } else {
                        int y = p[x];
                        while (y != NULL && x == right[y]) {
                            

                            x = y;
                            y = p[y];
                        }
                        if (y == NULL) {
                            returnedNull = true;
                            return id2;
                        } else {
                            returnedNull = false;
                            return key[y];
                        }
                    }
                }
            }
            returnedNull = true;
            return id2;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id8 that = (id8) o;

            if (size != that.size) {
                return false;
            }
            for (int x = firstNode(), y = that.firstNode();
                 x != NULL;
                

                 x = id21(x), y = that.id21(y)
            ) {
                if (key[x] != that.key[y]) {
                    return false;
                }
            }
            return true;
        }

        public int hashCode() {
            int hash = id14;
            for (int x = firstNode(); x != NULL; x = id21(x)) {
                hash = (hash ^ id11.getHash(key[x])) * id26;
            }
            return hash;
        }

        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append('[');
            for (int x = firstNode(); x != NULL; x = id21(x)) {
                if (sb.length() > 1) {
                    sb.append(", ");
                }
                sb.append(key[x]);
            }
            sb.append(']');
            return sb.toString();
        }

        private class id16 implements id6 {
            private int x;

            private id16() {
                x = firstNode();
            }

            public boolean hasNext() {
                return x != NULL;
            }

            public char next() {
                if (x == NULL) {
                    throw new NoSuchElementException("Iterator doesn't have more elements");
                }
                final char result = key[x];
                x = id21(x);
                return result;
            }

        }

    }

    static interface id1 extends id20 {
        int size();

        id6 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static final class id11 {
        private id11() {
        }

        public static int getHash(char x) {
            return x;
        }

    }

    static interface id22 extends id1 {
        int size();

        id6 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static class ArrayUtils {
        public static char[] clone(final char[] array) {
            if (array == null) {
                return null;
            }
            return array.clone();
        }

        public ArrayUtils() {
        }

    }

    static final class id23 {
        private static final double id0 = 2.0;
        private static final Random rnd = new Random();

        private id23() {
        }

        private static int id17(int length) {
            if (length <= 1) {
                return 0;
            }
            int log = Integer.numberOfTrailingZeros(Integer.highestOneBit(length - 1)) + 1;
            return (int) (id0 * log);
        }

        public static void sort(char[] a) {
            quickSort(a, 0, a.length, 0, id17(a.length));
        }

        private static void quickSort(char[] a, int left, int right, int depth, int maxDepth) {
            if (right - left <= 1) {
                return;
            }
            if (depth > maxDepth) {
                heapSort(a, left, right - left);
                return;
            }
            final char pivot = a[left + rnd.nextInt(right - left)];
            int i = left;
            int j = right - 1;
            do {
                while (a[i] < pivot) i++;
                while (pivot < a[j]) j--;
                if (i <= j) {
                    char tmp = a[i];
                    a[i++] = a[j];
                    a[j--] = tmp;
                }
            } while (i <= j);
            quickSort(a, left, j + 1, depth + 1, maxDepth);
            quickSort(a, i, right, depth + 1, maxDepth);
        }

        private static void heapSort(char[] a, int offset, int size) {
            

            for (int i = (size >>> 1) - 1; i >= 0; i--) {
                down(a, i, offset, size);
            }
            for (int i = size - 1; i > 0; i--) {
                char tmp = a[offset];
                a[offset] = a[offset + i];
                a[offset + i] = tmp;
                down(a, 0, offset, i);
            }
        }

        private static void down(char[] a, int index, int offset, int size) {
            final char element = a[offset + index];
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

    static interface id6 {
        boolean hasNext();

        char next();

    }

    static interface id20 {
        int size();

        id6 iterator();

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

        public void println(char[] array) {
            writer.println(array);
        }

        public void close() {
            writer.close();
        }

    }

    static class id25 implements id1 {
        private static final int id24 = 8;
        private static final int id14 = 0x811c9dc5;
        private static final int id26 = 0x01000193;
        private static final byte FREE = 0;
        private static final byte FILLED = 2;
        private static final Random rnd = new Random();
        private static final int id18;
        private static final int id29;
        private static final int id10;
        private static final int id9;
        private char[] table;
        private byte[] status;
        private int size;
        private int removedCount;
        private int mask;
        private final int hashSeed;

        static {
            id18 = rnd.nextInt(10) + 11;
            id29 = rnd.nextInt(10) + 21;
            id10 = rnd.nextInt(10) + 11;
            id9 = rnd.nextInt(10) + 21;
        }

        public id25() {
            this(id24);
        }

        public id25(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            

            int length = 4 * Math.max(1, capacity);
            if ((length & (length - 1)) != 0) {
                length = Integer.highestOneBit(length) << 1;
            }
            

            id28(length);
            hashSeed = rnd.nextInt();
        }

        public id25(id20 collection) {
            this(collection.size());
            for (id6 iterator = collection.iterator(); iterator.hasNext(); ) {
                add(iterator.next());
            }
        }

        public id25(char[] srcArray) {
            this(srcArray.length);
            for (char element : srcArray) {
                add(element);
            }
        }

        public id25(Collection<Character> javaCollection) {
            this(javaCollection.size());
            for (char element : javaCollection) {
                add(element);
            }
        }

        private int id4(int h) {
            h ^= hashSeed;
            h ^= (h >>> id18) ^ (h >>> id29);
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

        public boolean contains(char element) {
            final int elementHash = id11.getHash(element);
            int pos = id4(elementHash);
            final int step = getStep(elementHash);
            for (; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && table[pos] == element) {
                    return true;
                }
            }
            return false;
        }

        public id6 iterator() {
            return new id12();
        }

        public char[] toArray() {
            char[] result = new char[size];
            for (int i = 0, j = 0; i < table.length; i++) {
                if (status[i] == FILLED) {
                    result[j++] = table[i];
                }
            }
            return result;
        }

        public boolean add(char element) {
            final int elementHash = id11.getHash(element);
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
            char[] oldTable = table;
            byte[] oldStatus = status;
            id28(newLength);
            for (int i = 0; i < oldTable.length; i++) {
                if (oldStatus[i] == FILLED) {
                    add(oldTable[i]);
                }
            }
        }

        private void id28(int length) {
            table = new char[length];
            status = new byte[length];
            size = 0;
            removedCount = 0;
            mask = length - 1;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id25 that = (id25) o;

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
            char[] array = toArray();
            id23.sort(array);
            int hash = id14;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ id11.getHash(array[i])) * id26;
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

        private class id12 implements id6 {
            private int curIndex = 0;

            public boolean hasNext() {
                while (curIndex < table.length && status[curIndex] != FILLED) {
                    curIndex++;
                }
                return curIndex < table.length;
            }

            public char next() {
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
}

