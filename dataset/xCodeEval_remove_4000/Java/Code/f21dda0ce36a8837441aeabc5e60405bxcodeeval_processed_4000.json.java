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
        id1 a;
        int ans;
        id6[] adj;

        void bfs(int s) {
            boolean[] vis = new boolean[a.size()];
            int[] d = new int[a.size()];
            int[] p = new int[a.size()];
            Arrays.fill(p, -1);
            d[s] = 0;
            id11 q = new id0();

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
            a = new id5();
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

            adj = new id6[a.size()];
            Arrays.setAll(adj, i -> new id15());
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

    static interface id16 {
        boolean hasNext();

        long next();

    }

    static interface id6 extends id2 {
        int size();

        id14 iterator();

        boolean add(int element);

        boolean equals(Object object);

        int hashCode();

        String toString();

        int get(int index);

    }

    static interface id1 extends id3 {
        int size();

        id16 iterator();

        boolean add(long element);

        boolean equals(Object object);

        int hashCode();

        String toString();

        long get(int index);

    }

    static class id5 implements id1, id18 {
        private static final int id19 = 10;
        private static final double id4 = 2.0;
        private static final int id10 = 0x811c9dc5;
        private static final int id20 = 0x01000193;
        private long[] array;
        private int size;

        public id5() {
            this(id19);
        }

        public id5(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            array = new long[capacity];
            size = 0;
        }

        public id5(id3 collection) {
            size = collection.size();
            array = new long[size];
            int i = 0;
            for (id16 iterator = collection.iterator(); iterator.hasNext(); ) {
                array[i++] = iterator.next();
            }
        }

        public id5(long[] srcArray) {
            size = srcArray.length;
            array = new long[size];
            System.arraycopy(srcArray, 0, array, 0, size);
        }

        public id5(Collection<Long> javaCollection) {
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

        public id16 iterator() {
            return new id12();
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
            int newSize = Math.max(size + 1, (int) (size * id4));
            long[] newArray = new long[newSize];
            System.arraycopy(array, 0, newArray, 0, size);
            array = newArray;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id5 that = (id5) o;

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
            int hash = id10;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ id8.getHash(array[i])) * id20;
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

        private class id12 implements id16 {
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

    static interface id14 {
        boolean hasNext();

        int next();

    }

    static interface id3 {
        int size();

        id16 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static final class id8 {
        private id8() {
        }

        public static int getHash(int x) {
            return x;
        }

        public static int getHash(long x) {
            return (int) x ^ (int) (x >>> 32);
        }

    }

    static interface id18 extends id3 {
        int size();

        id16 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static class id15 implements id6, id7 {
        private static final int id19 = 10;
        private static final double id4 = 2.0;
        private static final int id10 = 0x811c9dc5;
        private static final int id20 = 0x01000193;
        private int[] array;
        private int size;

        public id15() {
            this(id19);
        }

        public id15(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            array = new int[capacity];
            size = 0;
        }

        public id15(id2 collection) {
            size = collection.size();
            array = new int[size];
            int i = 0;
            for (id14 iterator = collection.iterator(); iterator.hasNext(); ) {
                array[i++] = iterator.next();
            }
        }

        public id15(int[] srcArray) {
            size = srcArray.length;
            array = new int[size];
            System.arraycopy(srcArray, 0, array, 0, size);
        }

        public id15(Collection<Integer> javaCollection) {
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

        public id14 iterator() {
            return new id9();
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
            int newSize = Math.max(size + 1, (int) (size * id4));
            int[] newArray = new int[newSize];
            System.arraycopy(array, 0, newArray, 0, size);
            array = newArray;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id15 that = (id15) o;

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
            int hash = id10;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ id8.getHash(array[i])) * id20;
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

        private class id9 implements id14 {
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

    static interface id11 extends id2 {
        int size();

        boolean isEmpty();

        id14 iterator();

        boolean add(int element);

        boolean equals(Object object);

        int hashCode();

        String toString();

        int removeFirst();

    }

    static interface id17 extends id11, id7 {
        int size();

        boolean isEmpty();

        id14 iterator();

        boolean add(int element);

        boolean equals(Object object);

        int hashCode();

        String toString();

        int removeFirst();

    }

    static class id0 implements id17, id6 {
        private static final int id19 = 8;
        private static final int id10 = 0x811c9dc5;
        private static final int id20 = 0x01000193;
        private int[] deque;
        private int size;
        private int head;
        private int tail;
        private int mask;

        public id0() {
            this(id19);
        }

        public id0(int capacity) {
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

        public id0(id2 collection) {
            this(collection.size() + 1);
            for (id14 iterator = collection.iterator(); iterator.hasNext(); ) {
                deque[tail++] = iterator.next();
            }
            size = collection.size();
        }

        public id0(int[] srcArray) {
            this(srcArray.length + 1);
            System.arraycopy(srcArray, 0, deque, 0, srcArray.length);
            tail = srcArray.length;
            size = srcArray.length;
        }

        public id0(Collection<Integer> javaCollection) {
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

        public id14 iterator() {
            return new id13();
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
            id0 that = (id0) o;

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
            int hash = id10;
            for (int i = head; i != tail; i = (i + 1) & mask) {
                hash = (hash ^ id8.getHash(deque[i])) * id20;
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

        private class id13 implements id14 {
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

    static interface id2 {
        int size();

        id14 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface id7 extends id2 {
        int size();

        id14 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }
}

