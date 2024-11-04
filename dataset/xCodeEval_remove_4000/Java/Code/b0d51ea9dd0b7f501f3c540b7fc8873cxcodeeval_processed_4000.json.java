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
        id5 solver = new id5();
        solver.solve(1, in, out);
        out.close();
    }

    static class id5 {
        static InputReader in = null;
        static OutputWriter out = null;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            var tc = in.nextInt();
            for (int i = 0; i < tc; i++) {
                solution(i);
            }
        }

        void solution(int testNumber) {
            int l = in.nextInt();
            int[] a = in.id9(l);

            id15 pq = new id10();
            for (int i = 0; i < l; i++) {
                pq.add(a[i]);
            }

            if (pq.size() == 1) {
                out.println(-1);
                return;
            }
            id18 result = new id18();
            while (!pq.isEmpty()) {
                int x = pq.getFirst();
                int currIdx = result.size();
                if (a[currIdx] != x) {
                    result.add(x);
                    pq.removeFirst();
                } else {
                    if (pq.size() > 1) {
                        pq.removeFirst();
                        result.add(pq.removeFirst());
                        pq.add(x);
                    } else {
                        result.add(pq.removeFirst());
                    }
                }
            }

            int[] resultArray = result.toArray();
            if (resultArray[l - 1] == a[l - 1]) {
                

                int temp = resultArray[l - 1];
                resultArray[l - 1] = resultArray[l - 2];
                resultArray[l - 2] = temp;
            }

            out.println(resultArray);

            

            

        }

    }

    static class id18 implements id7, id8 {
        private static final int id19 = 10;
        private static final double id6 = 2.0;
        private static final int id13 = 0x811c9dc5;
        private static final int id20 = 0x01000193;
        private int[] array;
        private int size;

        public id18() {
            this(id19);
        }

        public id18(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            array = new int[capacity];
            size = 0;
        }

        public id18(id2 collection) {
            size = collection.size();
            array = new int[size];
            int i = 0;
            for (id17 iterator = collection.iterator(); iterator.hasNext(); ) {
                array[i++] = iterator.next();
            }
        }

        public id18(int[] srcArray) {
            size = srcArray.length;
            array = new int[size];
            System.arraycopy(srcArray, 0, array, 0, size);
        }

        public id18(Collection<Integer> javaCollection) {
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

        public id17 iterator() {
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
            int newSize = Math.max(size + 1, (int) (size * id6));
            int[] newArray = new int[newSize];
            System.arraycopy(array, 0, newArray, 0, size);
            array = newArray;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id18 that = (id18) o;

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
            int hash = id13;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ id11.getHash(array[i])) * id20;
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

        private class id12 implements id17 {
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

    static interface id17 {
        boolean hasNext();

        int next();

    }

    static class id10 implements id15 {
        private static final int id19 = 10;
        private static final double id6 = 2.0;
        private static final int id13 = 0x811c9dc5;
        private static final int id20 = 0x01000193;
        private int[] heap;
        private int size;

        public id10() {
            this(id19);
        }

        public id10(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            heap = new int[capacity];
            size = 0;
        }

        public id10(id2 collection) {
            size = collection.size();
            heap = new int[size];
            int i = 0;
            for (id17 iterator = collection.iterator(); iterator.hasNext(); ) {
                heap[i++] = iterator.next();
            }
            makeHeap();
        }

        public id10(int[] srcArray) {
            size = srcArray.length;
            heap = new int[size];
            System.arraycopy(srcArray, 0, heap, 0, size);
            makeHeap();
        }

        public id10(Collection<Integer> javaCollection) {
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
            while (index > 0 && element < heap[parent]) {
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
                int id0 = (index << 1) + 1;
                if (id0 + 1 < size && heap[id0 + 1] < heap[id0]) {
                    id0++;
                }
                if (heap[id0] >= element) {
                    break;
                }
                heap[index] = heap[id0];
                index = id0;
            }
            heap[index] = element;
        }

        public int size() {
            return size;
        }

        public boolean isEmpty() {
            return size == 0;
        }

        public id17 iterator() {
            return new id3();
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

        public int getFirst() {
            if (size == 0) {
                throw new NoSuchElementException("Trying to call getFirst() on empty Heap");
            }
            return heap[0];
        }

        public int removeFirst() {
            if (size == 0) {
                throw new NoSuchElementException("Trying to call removeFirst() on empty Heap");
            }
            final int minimalElement = heap[0];
            heap[0] = heap[--size];
            down(0);
            return minimalElement;
        }

        private void enlarge() {
            int newSize = Math.max(size + 1, (int) (size * id6));
            int[] newArray = new int[newSize];
            System.arraycopy(heap, 0, newArray, 0, size);
            heap = newArray;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id10 that = (id10) o;

            if (size != that.size) {
                return false;
            }
            int[] thisArray = toArray();
            int[] thatArray = that.toArray();
            id16.sort(thisArray);
            id16.sort(thatArray);
            for (int i = 0; i < size; i++) {
                if (thisArray[i] != thatArray[i]) {
                    return false;
                }
            }
            return true;
        }

        public int hashCode() {
            int[] array = toArray();
            id16.sort(array);
            int hash = id13;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ id11.getHash(array[i])) * id20;
            }
            return hash;
        }

        public String toString() {
            int[] array = toArray();
            id16.sort(array);
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

        private class id3 implements id17 {
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

    static interface id2 {
        int size();

        id17 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id21 filter;

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

        public boolean id4(int c) {
            if (filter != null) {
                return filter.id4(c);
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

        public interface id21 {
            public boolean id4(int ch);

        }

    }

    static interface id7 extends id2 {
        int size();

        id17 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static final class id16 {
        private static final double id1 = 2.0;
        private static final Random rnd = new Random(System.nanoTime());

        private id16() {
        }

        private static int id14(int length) {
            if (length <= 1) {
                return 0;
            }
            int log = Integer.numberOfTrailingZeros(Integer.highestOneBit(length - 1)) + 1;
            return (int) (id1 * log);
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

    static interface id8 extends id2 {
        int size();

        id17 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static final class id11 {
        private id11() {
        }

        public static int getHash(int x) {
            return x;
        }

    }

    static interface id15 extends id2 {
        int size();

        boolean isEmpty();

        id17 iterator();

        boolean add(int element);

        boolean equals(Object object);

        int hashCode();

        String toString();

        int getFirst();

        int removeFirst();

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

        public void println(int i) {
            writer.println(i);
        }

    }
}

