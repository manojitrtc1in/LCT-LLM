import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Collection;
import java.util.Random;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedOutputStream;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.BufferedReader;
import java.util.NoSuchElementException;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            int[] arr = in.nextIntArray(n), type = new int[n];
            EzIntTreeSet odd = new EzIntTreeSet(), even = new EzIntTreeSet();
            for (int i = 1; i <= m && i <= n; i++) {
                if (i % 2 == 1) odd.add(i);
                else even.add(i);
            }
            int nodd = 0, neven = 0;
            EzIntHashSet used = new EzIntHashSet();
            for (int i = 0; i < n; i++) {
                if (used.contains(arr[i])) type[i] = 1;
                else {
                    used.add(arr[i]);
                    if (arr[i] % 2 == 1) nodd++;
                    else neven++;
                }
            }
            for (int i = 0; i < n; i++)
                if (type[i] == 1) {
                    if (nodd < neven) nodd++;
                    else {
                        type[i] = 2;
                        neven++;
                    }
                }
            for (int i = 0; i < n; i++)
                if (type[i] == 0) {
                    if (nodd < neven && arr[i] % 2 == 0) {
                        nodd++;
                        neven--;
                        type[i] = 1;
                    } else if (nodd > neven && arr[i] % 2 == 1) {
                        nodd--;
                        neven++;
                        type[i] = 2;
                    }
                }
            int diff = 0;
            for (int i = 0; i < n; i++) {
                if (type[i] == 0) {
                    if (arr[i] % 2 == 1) odd.remove(arr[i]);
                    else even.remove(arr[i]);
                } else diff++;
            }
            int[] ans = new int[n];
            boolean valid = true;
            for (int i = 0; i < n; i++) {
                if (type[i] == 0) ans[i] = arr[i];
                else if (type[i] == 1) {
                    if (odd.isEmpty()) valid = false;
                    else ans[i] = odd.removeFirst();
                } else {
                    if (even.isEmpty()) valid = false;
                    else ans[i] = even.removeFirst();
                }
            }
            if (!valid) out.println(-1);
            else {
                out.println(diff);
                for (int i : ans) out.print(i + " ");
                out.println();
            }
        }

    }

    static interface EzIntSortedSet extends EzIntSet {
        int size();

        EzIntIterator iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static class OutputWriter extends PrintWriter {
        public OutputWriter(OutputStream outputStream) {
            super(new BufferedOutputStream(outputStream));
        }

        public OutputWriter(Writer writer) {
            super(writer);
        }

        public void close() {
            super.close();
        }

    }

    static interface EzIntIterator {
        boolean hasNext();

        int next();

    }

    static class EzIntTreeSet implements EzIntSortedSet {
        private static final int DEFAULT_CAPACITY = 10;
        private static final double ENLARGE_SCALE = 2.0;
        private static final int HASHCODE_INITIAL_VALUE = 0x811c9dc5;
        private static final int HASHCODE_MULTIPLIER = 0x01000193;
        private static final boolean BLACK = false;
        private static final boolean RED = true;
        private static final int NULL = 0;
        private static final int DEFAULT_NULL_ELEMENT = (new int[1])[0];
        private int[] key;
        private int[] left;
        private int[] right;
        private int[] p;
        private boolean[] color;
        private int size;
        private int root;
        private boolean returnedNull;

        public EzIntTreeSet() {
            this(DEFAULT_CAPACITY);
        }

        public EzIntTreeSet(int capacity) {
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

        public EzIntTreeSet(EzIntCollection collection) {
            this(collection.size());
            for (EzIntIterator iterator = collection.iterator(); iterator.hasNext(); ) {
                add(iterator.next());
            }
        }

        public EzIntTreeSet(int[] srcArray) {
            this(srcArray.length);
            for (int element : srcArray) {
                add(element);
            }
        }

        public EzIntTreeSet(Collection<Integer> javaCollection) {
            this(javaCollection.size());
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


        public EzIntIterator iterator() {
            return new EzIntTreeSetIterator();
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
            fixAfterAdd(z);
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
            int y = (left[z] == NULL || right[z] == NULL) ? z : successorNode(z);
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
                fixAfterRemove(x);
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

        private int successorNode(int x) {
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

        @SuppressWarnings("PointlessBooleanExpression")
        private void fixAfterAdd(int z) {
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

        @SuppressWarnings("PointlessBooleanExpression")
        private void fixAfterRemove(int x) {
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
            int newLength = Math.max(color.length + 1, (int) (color.length * ENLARGE_SCALE));
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


        public int removeFirst() {
            if (root == NULL) {
                returnedNull = true;
                return DEFAULT_NULL_ELEMENT;
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
            EzIntTreeSet that = (EzIntTreeSet) o;

            if (size != that.size) {
                return false;
            }
            for (int x = firstNode(), y = that.firstNode();
                 x != NULL;
                

                 x = successorNode(x), y = that.successorNode(y)
                    ) {
                if (key[x] != that.key[y]) {
                    return false;
                }
            }
            return true;
        }


        public int hashCode() {
            int hash = HASHCODE_INITIAL_VALUE;
            for (int x = firstNode(); x != NULL; x = successorNode(x)) {
                hash = (hash ^ PrimitiveHashCalculator.getHash(key[x])) * HASHCODE_MULTIPLIER;
            }
            return hash;
        }


        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append('[');
            for (int x = firstNode(); x != NULL; x = successorNode(x)) {
                if (sb.length() > 1) {
                    sb.append(", ");
                }
                sb.append(key[x]);
            }
            sb.append(']');
            return sb.toString();
        }

        private class EzIntTreeSetIterator implements EzIntIterator {
            private int x;

            private EzIntTreeSetIterator() {
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
                x = successorNode(x);
                return result;
            }

        }

    }

    static final class PrimitiveHashCalculator {
        private PrimitiveHashCalculator() {
        }

        public static int getHash(int x) {
            return x;
        }

    }

    static interface EzIntSet extends EzIntCollection {
        int size();

        EzIntIterator iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static class EzIntHashSet implements EzIntSet {
        private static final int DEFAULT_CAPACITY = 8;
        private static final int HASHCODE_INITIAL_VALUE = 0x811c9dc5;
        private static final int HASHCODE_MULTIPLIER = 0x01000193;
        private static final byte FREE = 0;
        private static final byte FILLED = 2;
        private static final Random rnd = new Random();
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

    static final class EzIntSort {
        private static final double HEAPSORT_DEPTH_COEFFICIENT = 2.0;
        private static final Random rnd = new Random();

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

    static class InputReader {
        BufferedReader br;
        StringTokenizer st;

        public InputReader(InputStream inputStream) {
            br = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                st = new StringTokenizer(nextLine());
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }

        public String nextLine() {
            try {
                return br.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

    }
}

