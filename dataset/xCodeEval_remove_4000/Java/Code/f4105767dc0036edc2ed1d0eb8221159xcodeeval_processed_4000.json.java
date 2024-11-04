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
        id23 solver = new id23();
        solver.solve(1, in, out);
        out.close();
    }

    static class id23 {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int tc = in.nextInt();
            for (; tc > 0; tc--) {
                int n = in.nextInt();
                int m = in.nextInt();
                int[] sight = in.id6(n * m);


                id9[] ta = new id9[n];
                for (int i = 0; i < n; i++) {
                    id9 t = new id9(m);
                    for (int j = 0; j < m; j++) {
                        t.add(j);
                    }
                    ta[i] = t;
                }

                int[] sortedSight = ArrayUtils.clone(sight);
                Arrays.sort(sortedSight);

                long id21 = 0;
                for (int s : sight) {
                    

                    

                    int minLocation = id17(sortedSight, s);
                    int maxLocation = id26(sortedSight, s);
                    

                    int id10 = minLocation / m;
                    int id28 = minLocation % m;
                    int id7 = maxLocation / m;
                    int id15 = maxLocation % m;
                    

                    int loc = -1;
                    int row = -1;
                    for (int i = id10; i <= id7; i++) {
                        if (i == id7) {
                            loc = ta[i].floor(id15);
                            if (!ta[i].returnedNull()) {
                                row = i;
                                break;
                            }
                        } else if (i == id10) {
                            loc = ta[i].floor(m);
                            if (!ta[i].returnedNull() && loc >= id28) {
                                row = i;
                                break;
                            }
                        } else {
                            loc = ta[i].floor(m);
                            if (!ta[i].returnedNull()) {
                                row = i;
                                break;
                            }
                        }
                    }

                    ta[row].remove(loc);
                    for (int i = 0; i < loc; i++) {
                        if (!ta[row].contains(i)) {
                            id21++;
                        }
                    }
                }

                out.println(id21);
            }
        }

        public static int id17(int[] A, int x) {
            

            int left = 0;
            int right = A.length - 1;

            

            int result = -1;

            

            while (left <= right) {
                

                int mid = (left + right) / 2;

                

                

                if (x == A[mid]) {
                    result = mid;
                    right = mid - 1;
                }

                

                else if (x < A[mid]) {
                    right = mid - 1;
                }

                

                else {
                    left = mid + 1;
                }
            }

            

            return result;
        }

        public static int id26(int[] A, int x) {
            

            int left = 0;
            int right = A.length - 1;

            

            int result = -1;

            

            while (left <= right) {
                

                int mid = (left + right) / 2;

                

                

                if (x == A[mid]) {
                    result = mid;
                    left = mid + 1;
                }

                

                else if (x < A[mid]) {
                    right = mid - 1;
                }

                

                else {
                    left = mid + 1;
                }
            }

            

            return result;
        }

    }

    static interface id19 {
        boolean hasNext();

        int next();

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
            while (id2(c)) {
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
            } while (!id2(c));
            return res * sgn;
        }

        public boolean id2(int c) {
            if (filter != null) {
                return filter.id2(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public int[] id6(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; ++i) array[i] = nextInt();
            return array;
        }

        public interface id25 {
            public boolean id2(int ch);

        }

    }

    static class id9 implements id27 {
        private static final int id22 = 10;
        private static final double id3 = 2.0;
        private static final int id12 = 0x811c9dc5;
        private static final int id24 = 0x01000193;
        private static final boolean BLACK = false;
        private static final boolean RED = true;
        private static final int NULL = 0;
        private static final int id11 = -1;
        private int[] key;
        private int[] left;
        private int[] right;
        private int[] p;
        private boolean[] color;
        private int size;
        private int root;
        private boolean returnedNull;

        public id9() {
            this(id22);
        }

        public id9(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
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

        public id9(id1 collection) {
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

        public int size() {
            return size;
        }

        public boolean contains(int element) {
            int x = root;
            while (x != NULL) {
                if (element < key[x]) {
                    x = left[x];
                } else if (element > key[x]) {
                    x = right[x];
                } else {
                    return true;
                }
            }
            return false;
        }

        public id19 iterator() {
            return new id18();
        }

        public boolean add(int element) {
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
            id13(z);
            return true;
        }

        public boolean remove(int element) {
            int z = root;
            while (z != NULL) {
                if (element < key[z]) {
                    z = left[z];
                } else if (element > key[z]) {
                    z = right[z];
                } else {
                    removeNode(z);
                    return true;
                }
            }
            return false;
        }

        private void removeNode(int z) {
            int y = (left[z] == NULL || right[z] == NULL) ? z : id20(z);
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
                id4(x);
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

        private int id20(int x) {
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

        private void id13(int z) {
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

        private void id4(int x) {
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

        private void enlarge() {
            int newLength = Math.max(color.length + 1, (int) (color.length * id3));
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

        public int floor(int element) {
            int x = root;
            while (x != NULL) {
                if (element > key[x]) {
                    if (right[x] != NULL) {
                        x = right[x];
                    } else {
                        returnedNull = false;
                        return key[x];
                    }
                } else if (element < key[x]) {
                    if (left[x] != NULL) {
                        x = left[x];
                    } else {
                        int y = p[x];
                        while (y != NULL && x == left[y]) {
                            

                            x = y;
                            y = p[y];
                        }
                        if (y == NULL) {
                            returnedNull = true;
                            return id11;
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
            return id11;
        }

        public boolean returnedNull() {
            return returnedNull;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id9 that = (id9) o;

            if (size != that.size) {
                return false;
            }
            for (int x = firstNode(), y = that.firstNode();
                 x != NULL;
                

                 x = id20(x), y = that.id20(y)
            ) {
                if (key[x] != that.key[y]) {
                    return false;
                }
            }
            return true;
        }

        public int hashCode() {
            int hash = id12;
            for (int x = firstNode(); x != NULL; x = id20(x)) {
                hash = (hash ^ id8.getHash(key[x])) * id24;
            }
            return hash;
        }

        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append('[');
            for (int x = firstNode(); x != NULL; x = id20(x)) {
                if (sb.length() > 1) {
                    sb.append(", ");
                }
                sb.append(key[x]);
            }
            sb.append(']');
            return sb.toString();
        }

        private class id18 implements id19 {
            private int x;

            private id18() {
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
                x = id20(x);
                return result;
            }

        }

    }

    static final class id8 {
        private id8() {
        }

        public static int getHash(int x) {
            return x;
        }

    }

    static interface id27 extends id5 {
        int size();

        id19 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static final class id16 {
        private static final double id0 = 2.0;
        private static final Random rnd = new Random(System.nanoTime());

        private id16() {
        }

        private static int id14(int length) {
            if (length <= 1) {
                return 0;
            }
            int log = Integer.numberOfTrailingZeros(Integer.highestOneBit(length - 1)) + 1;
            return (int) (id0 * log);
        }

        public static void sort(int[] a) {
            quickSort(a, 0, a.length, 0, id14(a.length));
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

    static interface id1 {
        int size();

        id19 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static class ArrayUtils {
        public static int[] clone(final int[] array) {
            if (array == null) {
                return null;
            }
            return array.clone();
        }

        public ArrayUtils() {
        }

    }

    static class Arrays {
        private Arrays() {
        }

        public static void sort(int[] a) {
            id16.sort(a);
        }

        public static int[] copyOf(int[] original, int newLength) {
            return java.util.Arrays.copyOf(original, newLength);
        }

        public static boolean[] copyOf(boolean[] original, int newLength) {
            return java.util.Arrays.copyOf(original, newLength);

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

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

    }

    static interface id5 extends id1 {
        int size();

        id19 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }
}

