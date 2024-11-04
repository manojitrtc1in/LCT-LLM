import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collection;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.NoSuchElementException;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        ShortestCycle solver = new ShortestCycle();
        solver.solve(1, in, out);
        out.close();
    }

    static class ShortestCycle {
        int n;
        EzLongList a;
        int ans;
        EzIntList[] adj;

        void bfs(int s) {
            boolean[] vis = new boolean[a.size()];
            int[] d = new int[a.size()];
            int[] p = new int[a.size()];
            Arrays.fill(p, -1);
            d[s] = 0;
            EzIntQueue q = new EzIntArrayDeque();

            q.add(s);
            vis[s] = true;
            while (!q.isEmpty()) {
                int u = q.removeFirst();
                for (int i = 0; i < adj[u].size(); i++) {
                    int v = adj[u].get(i);
                    if (!vis[v]) {
                        d[v] = d[u] + 1;
                        vis[v] = true;
                        p[v] = u;
                        q.add(v);
                    } else if (v != p[u]) {
                        ans = Math.min(ans, d[u] + d[v] + 1);
                    }
                }
            }
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.ni();
            a = new EzLongArrayList();
            for (int i = 0; i < n; i++) {
                long x = in.nl();
                if (x != 0) {
                    a.add(x);
                }
            }

            if (a.size() >= 121) {
                out.println(3);
                return;
            }

            adj = new EzIntList[a.size()];
            Arrays.setAll(adj, i -> new EzIntArrayList());
            for (int i = 0; i < a.size(); i++) {
                for (int j = i + 1; j < a.size(); j++) {
                    if ((a.get(i) & a.get(j)) != 0) {
                        adj[i].add(j);
                        adj[j].add(i);
                    }
                }
            }

            ans = Integer.MAX_VALUE;
            for (int i = 0; i < a.size(); i++) {
                bfs(i);
            }

            if (ans == Integer.MAX_VALUE) {
                out.println(-1);
            } else {
                out.println(ans);
            }
        }

    }

    static interface EzLongIterator {
        boolean hasNext();

        long next();

    }

    static interface EzIntList extends EzIntCollection {
        int size();

        EzIntIterator iterator();

        boolean add(int element);

        boolean equals(Object object);

        int hashCode();

        String toString();

        int get(int index);

    }

    static interface EzLongList extends EzLongCollection {
        int size();

        EzLongIterator iterator();

        boolean add(long element);

        boolean equals(Object object);

        int hashCode();

        String toString();

        long get(int index);

    }

    static class EzLongArrayList implements EzLongList, EzLongStack {
        private static final int DEFAULT_CAPACITY = 10;
        private static final double ENLARGE_SCALE = 2.0;
        private static final int HASHCODE_INITIAL_VALUE = 0x811c9dc5;
        private static final int HASHCODE_MULTIPLIER = 0x01000193;
        private long[] array;
        private int size;

        public EzLongArrayList() {
            this(DEFAULT_CAPACITY);
        }

        public EzLongArrayList(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            array = new long[capacity];
            size = 0;
        }

        public EzLongArrayList(EzLongCollection collection) {
            size = collection.size();
            array = new long[size];
            int i = 0;
            for (EzLongIterator iterator = collection.iterator(); iterator.hasNext(); ) {
                array[i++] = iterator.next();
            }
        }

        public EzLongArrayList(long[] srcArray) {
            size = srcArray.length;
            array = new long[size];
            System.arraycopy(srcArray, 0, array, 0, size);
        }

        public EzLongArrayList(Collection<Long> javaCollection) {
            size = javaCollection.size();
            array = new long[size];
            int i = 0;
            for (long element : javaCollection) {
                array[i++] = element;
            }
        }

        public int size() {
            return size;
        }

        public EzLongIterator iterator() {
            return new EzLongArrayListIterator();
        }

        public boolean add(long element) {
            if (size == array.length) {
                enlarge();
            }
            array[size++] = element;
            return true;
        }

        public long get(int index) {
            if (index < 0 || index >= size) {
                throw new IndexOutOfBoundsException("Index " + index + " is out of range, size = " + size);
            }
            return array[index];
        }

        private void enlarge() {
            int newSize = Math.max(size + 1, (int) (size * ENLARGE_SCALE));
            long[] newArray = new long[newSize];
            System.arraycopy(array, 0, newArray, 0, size);
            array = newArray;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            EzLongArrayList that = (EzLongArrayList) o;

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
            int hash = HASHCODE_INITIAL_VALUE;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ PrimitiveHashCalculator.getHash(array[i])) * HASHCODE_MULTIPLIER;
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

        private class EzLongArrayListIterator implements EzLongIterator {
            private int curIndex = 0;

            public boolean hasNext() {
                return curIndex < size;
            }

            public long next() {
                if (curIndex == size) {
                    throw new NoSuchElementException("Iterator doesn't have more elements");
                }
                return array[curIndex++];
            }

        }

    }

    static interface EzIntIterator {
        boolean hasNext();

        int next();

    }

    static interface EzLongCollection {
        int size();

        EzLongIterator iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static final class PrimitiveHashCalculator {
        private PrimitiveHashCalculator() {
        }

        public static int getHash(int x) {
            return x;
        }

        public static int getHash(long x) {
            return (int) x ^ (int) (x >>> 32);
        }

    }

    static interface EzLongStack extends EzLongCollection {
        int size();

        EzLongIterator iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static class EzIntArrayList implements EzIntList, EzIntStack {
        private static final int DEFAULT_CAPACITY = 10;
        private static final double ENLARGE_SCALE = 2.0;
        private static final int HASHCODE_INITIAL_VALUE = 0x811c9dc5;
        private static final int HASHCODE_MULTIPLIER = 0x01000193;
        private int[] array;
        private int size;

        public EzIntArrayList() {
            this(DEFAULT_CAPACITY);
        }

        public EzIntArrayList(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            array = new int[capacity];
            size = 0;
        }

        public EzIntArrayList(EzIntCollection collection) {
            size = collection.size();
            array = new int[size];
            int i = 0;
            for (EzIntIterator iterator = collection.iterator(); iterator.hasNext(); ) {
                array[i++] = iterator.next();
            }
        }

        public EzIntArrayList(int[] srcArray) {
            size = srcArray.length;
            array = new int[size];
            System.arraycopy(srcArray, 0, array, 0, size);
        }

        public EzIntArrayList(Collection<Integer> javaCollection) {
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

        public EzIntIterator iterator() {
            return new EzIntArrayListIterator();
        }

        public boolean add(int element) {
            if (size == array.length) {
                enlarge();
            }
            array[size++] = element;
            return true;
        }

        public int get(int index) {
            if (index < 0 || index >= size) {
                throw new IndexOutOfBoundsException("Index " + index + " is out of range, size = " + size);
            }
            return array[index];
        }

        private void enlarge() {
            int newSize = Math.max(size + 1, (int) (size * ENLARGE_SCALE));
            int[] newArray = new int[newSize];
            System.arraycopy(array, 0, newArray, 0, size);
            array = newArray;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            EzIntArrayList that = (EzIntArrayList) o;

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
            int hash = HASHCODE_INITIAL_VALUE;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ PrimitiveHashCalculator.getHash(array[i])) * HASHCODE_MULTIPLIER;
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

        private class EzIntArrayListIterator implements EzIntIterator {
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

    static class InputReader {
        private final InputStream is;
        private final byte[] inbuf = new byte[1024];
        private int lenbuf = 0;
        private int ptrbuf = 0;

        public InputReader(InputStream stream) {
            is = stream;
        }

        private int readByte() {
            if (lenbuf == -1) throw new InputMismatchException();
            if (ptrbuf >= lenbuf) {
                ptrbuf = 0;
                try {
                    lenbuf = is.read(inbuf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (lenbuf <= 0) return -1;
            }
            return inbuf[ptrbuf++];
        }

        public int ni() {
            int num = 0, b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
            if (b == '-') {
                minus = true;
                b = readByte();
            }

            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10 + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

        public long nl() {
            long num = 0;
            int b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
            if (b == '-') {
                minus = true;
                b = readByte();
            }

            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10 + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

    }

    static interface EzIntQueue extends EzIntCollection {
        int size();

        boolean isEmpty();

        EzIntIterator iterator();

        boolean add(int element);

        boolean equals(Object object);

        int hashCode();

        String toString();

        int removeFirst();

    }

    static interface EzIntDeque extends EzIntQueue, EzIntStack {
        int size();

        boolean isEmpty();

        EzIntIterator iterator();

        boolean add(int element);

        boolean equals(Object object);

        int hashCode();

        String toString();

        int removeFirst();

    }

    static class EzIntArrayDeque implements EzIntDeque, EzIntList {
        private static final int DEFAULT_CAPACITY = 8;
        private static final int HASHCODE_INITIAL_VALUE = 0x811c9dc5;
        private static final int HASHCODE_MULTIPLIER = 0x01000193;
        private int[] deque;
        private int size;
        private int head;
        private int tail;
        private int mask;

        public EzIntArrayDeque() {
            this(DEFAULT_CAPACITY);
        }

        public EzIntArrayDeque(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            if (capacity < 1) {
                capacity = 1;
            }
            if ((capacity & (capacity - 1)) != 0) {
                capacity = Integer.highestOneBit(capacity) << 1;
            }
            

            deque = new int[capacity];
            size = 0;
            head = 0;
            tail = 0;
            mask = deque.length - 1;
        }

        public EzIntArrayDeque(EzIntCollection collection) {
            this(collection.size() + 1);
            for (EzIntIterator iterator = collection.iterator(); iterator.hasNext(); ) {
                deque[tail++] = iterator.next();
            }
            size = collection.size();
        }

        public EzIntArrayDeque(int[] srcArray) {
            this(srcArray.length + 1);
            System.arraycopy(srcArray, 0, deque, 0, srcArray.length);
            tail = srcArray.length;
            size = srcArray.length;
        }

        public EzIntArrayDeque(Collection<Integer> javaCollection) {
            this(javaCollection.size() + 1);
            for (int element : javaCollection) {
                deque[tail++] = element;
            }
            size = javaCollection.size();
        }

        public int size() {
            return size;
        }

        public boolean isEmpty() {
            return size == 0;
        }

        public EzIntIterator iterator() {
            return new EzIntArrayDequeIterator();
        }

        public boolean add(int element) {
            deque[tail] = element;
            tail = (tail + 1) & mask;
            size++;
            if (size == deque.length) {
                enlarge();
            }
            return true;
        }

        public int removeFirst() {
            if (size == 0) {
                throw new NoSuchElementException("Trying to call removeFirst() on empty ArrayDeque");
            }
            final int removedElement = deque[head];
            size--;
            head = (head + 1) & mask;
            return removedElement;
        }

        public int get(int index) {
            if (index < 0 || index >= size) {
                throw new IndexOutOfBoundsException("Index " + index + " is out of range, size = " + size);
            }
            return deque[(head + index) & mask];
        }

        private void enlarge() {
            int newSize = (size << 1);
            int[] newArray = new int[newSize];
            System.arraycopy(deque, head, newArray, 0, deque.length - head);
            System.arraycopy(deque, 0, newArray, deque.length - tail, tail);
            deque = newArray;
            head = 0;
            tail = size;
            mask = deque.length - 1;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            EzIntArrayDeque that = (EzIntArrayDeque) o;

            if (size != that.size) {
                return false;
            }
            for (int i = head, j = that.head; i != tail; i = (i + 1) & mask, j = (j + 1) & that.mask) {
                if (deque[i] != that.deque[j]) {
                    return false;
                }
            }
            return true;
        }

        public int hashCode() {
            int hash = HASHCODE_INITIAL_VALUE;
            for (int i = head; i != tail; i = (i + 1) & mask) {
                hash = (hash ^ PrimitiveHashCalculator.getHash(deque[i])) * HASHCODE_MULTIPLIER;
            }
            return hash;
        }

        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append('[');
            for (int i = head; i != tail; i = (i + 1) & mask) {
                if (i != head) {
                    sb.append(", ");
                }
                sb.append(deque[i]);
            }
            sb.append(']');
            return sb.toString();
        }

        private class EzIntArrayDequeIterator implements EzIntIterator {
            private int curIndex = head;

            public boolean hasNext() {
                return curIndex != tail;
            }

            public int next() {
                if (curIndex == tail) {
                    throw new NoSuchElementException("Iterator doesn't have more elements");
                }
                final int result = deque[curIndex];
                curIndex = (curIndex + 1) & mask;
                return result;
            }

        }

    }

    static interface EzIntCollection {
        int size();

        EzIntIterator iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface EzIntStack extends EzIntCollection {
        int size();

        EzIntIterator iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }
}

