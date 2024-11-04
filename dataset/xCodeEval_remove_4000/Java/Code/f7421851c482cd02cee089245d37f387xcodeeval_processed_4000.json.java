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
        id25 solver = new id25();
        solver.solve(1, in, out);
        out.close();
    }

    static class id25 {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            var tc = in.nextInt();
            for (int i = 0; i < tc; i++) {
                solution(i, in, out);
            }
        }

        void solution(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] a = in.id9(n);
            int[] b = in.id9(n);

            

            

            


            

            

            


            Arrays.sort(a);
            Arrays.sort(b);

            id13 heap = new id13();
            int idx = 0;
            id22 minans = new id22();
            id22 maxans = new id22();
            while (idx < n) {
                int i = idx;
                for (; i < n; i++) {
                    if (heap.size() > 0) {
                        if (heap.getFirst() < a[i]) {
                            heap.clear();
                            break;
                        }
                    }
                    heap.add(b[i]);
                }

                id11 set = new id11();
                for (int j = idx; j < i; j++) {
                    set.add(b[j]);
                }

                for (int j = idx; j < i; j++) {
                    int aa = a[j];
                    int maxd = set.getLast() - aa;
                    int mind = set.ceiling(aa) - aa;
                    minans.add(mind);
                    maxans.add(maxd);
                }

                idx = i;
                

            }

            out.println(minans.toArray());
            out.println(maxans.toArray());
        }

    }

    static final class id10 {
        private id10() {
        }

        public static int getHash(int x) {
            return x;
        }

    }

    static interface id21 {
        boolean hasNext();

        int next();

    }

    static final class id26 {
        private static final double id1 = 2.0;
        private static final Random rnd = new Random(System.nanoTime());

        private id26() {
        }

        private static int id17(int length) {
            if (length <= 1) {
                return 0;
            }
            int log = Integer.numberOfTrailingZeros(Integer.highestOneBit(length - 1)) + 1;
            return (int) (id1 * log);
        }

        public static void sort(int[] a) {
            quickSort(a, 0, a.length, 0, id17(a.length));
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
                while (a[i] > pivot) i++;
                while (pivot > a[j]) j--;
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
                int id0 = (index << 1) + 1;
                if (id0 + 1 < size && a[offset + id0 + 1] < a[offset + id0]) {
                    id0++;
                }
                if (a[offset + id0] >= element) {
                    break;
                }
                a[offset + index] = a[offset + id0];
                index = id0;
            }
            a[offset + index] = element;
        }

    }

    static class Arrays {
        private Arrays() {
        }

        public static void sort(int[] a) {
            id19.sort(a);
        }

        public static int[] copyOf(int[] original, int newLength) {
            return java.util.Arrays.copyOf(original, newLength);
        }

        public static boolean[] copyOf(boolean[] original, int newLength) {
            return java.util.Arrays.copyOf(original, newLength);

        }

    }

    static interface id2 {
        int size();

        id21 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static class id22 implements id6, id7 {
        private static final int id24 = 10;
        private static final double id5 = 2.0;
        private static final int id15 = 0x811c9dc5;
        private static final int id27 = 0x01000193;
        private int[] array;
        private int size;

        public id22() {
            this(id24);
        }

        public id22(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            array = new int[capacity];
            size = 0;
        }

        public id22(id2 collection) {
            size = collection.size();
            array = new int[size];
            int i = 0;
            for (id21 iterator = collection.iterator(); iterator.hasNext(); ) {
                array[i++] = iterator.next();
            }
        }

        public id22(int[] srcArray) {
            size = srcArray.length;
            array = new int[size];
            System.arraycopy(srcArray, 0, array, 0, size);
        }

        public id22(Collection<Integer> javaCollection) {
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

        public id21 iterator() {
            return new id12();
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
            id22 that = (id22) o;

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
            int hash = id15;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ id10.getHash(array[i])) * id27;
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

        private class id12 implements id21 {
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

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(int[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void println(int[] array) {
            print(array);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static interface id18 extends id2 {
        int size();

        id21 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface id29 extends id8 {
        int size();

        id21 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id28 filter;

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

        public boolean id3(int c) {
            if (filter != null) {
                return filter.id3(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public int[] id9(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; ++i) array[i] = nextInt();
            return array;
        }

        public interface id28 {
            public boolean id3(int ch);

        }

    }

    static interface id8 extends id2 {
        int size();

        id21 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface id6 extends id2 {
        int size();

        id21 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface id7 extends id2 {
        int size();

        id21 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static class id11 implements id29 {
        private static final int id24 = 10;
        private static final double id5 = 2.0;
        private static final int id15 = 0x811c9dc5;
        private static final int id27 = 0x01000193;
        private static final boolean BLACK = false;
        private static final boolean RED = true;
        private static final int NULL = 0;
        private static final int id14 = -1;
        private int[] key;
        private int[] left;
        private int[] right;
        private int[] p;
        private boolean[] color;
        private int size;
        private int root;
        private boolean returnedNull;

        public id11() {
            this(id24);
        }

        public id11(int capacity) {
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

        public id11(id2 collection) {
            this(collection.size());
            for (id21 iterator = collection.iterator(); iterator.hasNext(); ) {
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

        public int size() {
            return size;
        }

        public id21 iterator() {
            return new id20();
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
            id16(z);
            return true;
        }

        private int id23(int x) {
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

        private void id16(int z) {
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

        private int lastNode() {
            int x = root;
            while (right[x] != NULL) {
                x = right[x];
            }
            return x;
        }

        public int getLast() {
            if (root == NULL) {
                returnedNull = true;
                return id14;
            }
            final int x = lastNode();
            returnedNull = false;
            return key[x];
        }

        public int ceiling(int element) {
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
                            return id14;
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
            return id14;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id11 that = (id11) o;

            if (size != that.size) {
                return false;
            }
            for (int x = firstNode(), y = that.firstNode();
                 x != NULL;
                

                 x = id23(x), y = that.id23(y)
            ) {
                if (key[x] != that.key[y]) {
                    return false;
                }
            }
            return true;
        }

        public int hashCode() {
            int hash = id15;
            for (int x = firstNode(); x != NULL; x = id23(x)) {
                hash = (hash ^ id10.getHash(key[x])) * id27;
            }
            return hash;
        }

        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append('[');
            for (int x = firstNode(); x != NULL; x = id23(x)) {
                if (sb.length() > 1) {
                    sb.append(", ");
                }
                sb.append(key[x]);
            }
            sb.append(']');
            return sb.toString();
        }

        private class id20 implements id21 {
            private int x;

            private id20() {
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
                x = id23(x);
                return result;
            }

        }

    }

    static final class id19 {
        private static final double id1 = 2.0;
        private static final Random rnd = new Random(System.nanoTime());

        private id19() {
        }

        private static int id17(int length) {
            if (length <= 1) {
                return 0;
            }
            int log = Integer.numberOfTrailingZeros(Integer.highestOneBit(length - 1)) + 1;
            return (int) (id1 * log);
        }

        public static void sort(int[] a) {
            quickSort(a, 0, a.length, 0, id17(a.length));
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

    static class id13 implements id18 {
        private static final int id24 = 10;
        private static final double id5 = 2.0;
        private static final int id15 = 0x811c9dc5;
        private static final int id27 = 0x01000193;
        private int[] heap;
        private int size;

        public id13() {
            this(id24);
        }

        public id13(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            heap = new int[capacity];
            size = 0;
        }

        public id13(id2 collection) {
            size = collection.size();
            heap = new int[size];
            int i = 0;
            for (id21 iterator = collection.iterator(); iterator.hasNext(); ) {
                heap[i++] = iterator.next();
            }
            makeHeap();
        }

        public id13(int[] srcArray) {
            size = srcArray.length;
            heap = new int[size];
            System.arraycopy(srcArray, 0, heap, 0, size);
            makeHeap();
        }

        public id13(Collection<Integer> javaCollection) {
            size = javaCollection.size();
            heap = new int[size];
            int i = 0;
            for (int element : javaCollection) {
                heap[i++] = element;
            }
            makeHeap();
        }

        private void makeHeap() {
            for (int i = (size >>> 1) - 1; i >= 0; i--) {
                down(i);
            }
        }

        private void up(int index) {
            final int element = heap[index];
            int parent = (index - 1) >>> 1;
            while (index > 0 && element > heap[parent]) {
                heap[index] = heap[parent];
                index = parent;
                parent = (index - 1) >>> 1;
            }
            heap[index] = element;
        }

        private void down(int index) {
            final int element = heap[index];
            final int firstLeaf = size >>> 1;
            while (index < firstLeaf) {
                int largestChild = (index << 1) + 1;
                if (largestChild + 1 < size && heap[largestChild + 1] > heap[largestChild]) {
                    largestChild++;
                }
                if (heap[largestChild] <= element) {
                    break;
                }
                heap[index] = heap[largestChild];
                index = largestChild;
            }
            heap[index] = element;
        }

        public int size() {
            return size;
        }

        public id21 iterator() {
            return new id4();
        }

        public int[] toArray() {
            int[] result = new int[size];
            System.arraycopy(heap, 0, result, 0, size);
            return result;
        }

        public boolean add(int element) {
            if (size == heap.length) {
                enlarge();
            }
            heap[size] = element;
            up(size++);
            return true;
        }

        public void clear() {
            size = 0;
        }

        public int getFirst() {
            if (size == 0) {
                throw new NoSuchElementException("Trying to call getFirst() on empty Heap");
            }
            return heap[0];
        }

        private void enlarge() {
            int newSize = Math.max(size + 1, (int) (size * id5));
            int[] newArray = new int[newSize];
            System.arraycopy(heap, 0, newArray, 0, size);
            heap = newArray;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id13 that = (id13) o;

            if (size != that.size) {
                return false;
            }
            int[] thisArray = toArray();
            int[] thatArray = that.toArray();
            id26.sort(thisArray);
            id26.sort(thatArray);
            for (int i = 0; i < size; i++) {
                if (thisArray[i] != thatArray[i]) {
                    return false;
                }
            }
            return true;
        }

        public int hashCode() {
            int[] array = toArray();
            id26.sort(array);
            int hash = id15;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ id10.getHash(array[i])) * id27;
            }
            return hash;
        }

        public String toString() {
            int[] array = toArray();
            id26.sort(array);
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

        private class id4 implements id21 {
            private int curIndex = 0;

            public boolean hasNext() {
                return curIndex < size;
            }

            public int next() {
                if (curIndex == size) {
                    throw new NoSuchElementException("Iterator doesn't have more elements");
                }
                return heap[curIndex++];
            }

        }

    }
}

