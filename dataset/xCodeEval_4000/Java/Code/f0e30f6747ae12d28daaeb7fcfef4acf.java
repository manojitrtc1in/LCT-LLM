import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Collection;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        char[][] tab;
        boolean[] can;
        EzIntArrayList[][] preX;
        EzIntArrayList[][] preY;
        int[][] dist;
        boolean[][] vis;
        EzIntArrayList usedX;
        EzIntArrayList usedY;
        EzIntArrayDeque queueX;
        EzIntArrayDeque queueY;
        EzIntArrayList[] listX;
        EzIntArrayList[] listY;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
            CombinatorialEnumerations.Combinations comb = new CombinatorialEnumerations.Combinations(26, k);
            String ans = null;
            tab = in.nextCharArray2(n, m);
            int sx = -1, sy = -1, tx = -1, ty = -1;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    if (tab[i][j] == 'S') {
                        sx = i;
                        sy = j;
                    } else if (tab[i][j] == 'T') {
                        tx = i;
                        ty = j;
                    }
                }
            can = new boolean[26];
            preX = new EzIntArrayList[n][m];
            preY = new EzIntArrayList[n][m];
            dist = new int[n][m];
            vis = new boolean[n][m];
            usedX = new EzIntArrayList();
            usedY = new EzIntArrayList();
            queueX = new EzIntArrayDeque();
            queueY = new EzIntArrayDeque();
            listX = new EzIntArrayList[2];
            listY = new EzIntArrayList[2];
            for (int i = 0; i < 2; i++) {
                listX[i] = new EzIntArrayList();
                listY[i] = new EzIntArrayList();
            }
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    preX[i][j] = new EzIntArrayList();
                    preY[i][j] = new EzIntArrayList();
                    dist[i][j] = Integer.MAX_VALUE;
                }
            for (int i = 0; i < comb.totalCount(); i++) {
                int[] arr = comb.fromNumber(i);
                Arrays.fill(can, false);
                for (int x : arr) can[x] = true;
                String aux = solve(sx, sy, tx, ty);
                if (ans == null || (aux != null && (aux.length() < ans.length() || (aux.length() == ans.length() && aux.compareTo(ans) < 0))))
                    ans = aux;
            }
            if (ans == null) out.println(-1);
            else out.println(ans);
        }

        String solve(int sx, int sy, int tx, int ty) {
            if (can['c' - 'a'] && can['b' - 'a'] && can['q' - 'a']) {
                System.err.println();
            }
            int n = tab.length, m = tab[0].length;
            dist[tx][ty] = 0;
            queueX.add(tx);
            queueY.add(ty);
            final int[] dx = new int[]{-1, 0, 0, 1}, dy = new int[]{0, -1, 1, 0};
            while (!queueX.isEmpty()) {
                int x = queueX.removeFirst(), y = queueY.removeFirst();
                usedX.add(x);
                usedY.add(y);
                for (int i = 0; i < 4; i++) {
                    int x2 = x + dx[i], y2 = y + dy[i];
                    if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && (tab[x2][y2] == 'S' || tab[x2][y2] == 'T' || can[tab[x2][y2] - 'a'])) {
                        if (dist[x2][y2] >= dist[x][y] + 1) {
                            if (dist[x2][y2] > dist[x][y] + 1) {
                                dist[x2][y2] = dist[x][y] + 1;
                                queueX.addLast(x2);
                                queueY.addLast(y2);
                            }
                            preX[x2][y2].add(x);
                            preY[x2][y2].add(y);
                        }
                    }
                }
            }
            String ans = null;
            if (dist[sx][sy] != Integer.MAX_VALUE) {
                StringBuilder str = new StringBuilder();
                for (int i = 0; i < 2; i++) {
                    listX[i].clear();
                    listY[i].clear();
                }
                listX[0].add(sx);
                listY[0].add(sy);
                vis[sx][sy] = true;
                for (int now = 0, next = 1; ; now ^= 1, next ^= 1) {
                    char min = Character.MAX_VALUE;
                    for (int i = 0; i < listX[now].size(); i++) {
                        char aux = tab[listX[now].get(i)][listY[now].get(i)];
                        if (aux < min) min = aux;
                    }
                    if (min != 'S') {
                        if (min == 'T') break;
                        else str.append(min);
                    }
                    listX[next].clear();
                    listY[next].clear();
                    for (int i = 0; i < listX[now].size(); i++) {
                        int x = listX[now].get(i), y = listY[now].get(i);
                        char aux = tab[x][y];
                        if (aux == min) for (int j = 0; j < preX[x][y].size(); j++) {
                            int x2 = preX[x][y].get(j), y2 = preY[x][y].get(j);
                            if (!vis[x2][y2]) {
                                vis[x2][y2] = true;
                                listX[next].add(x2);
                                listY[next].add(y2);
                            }
                        }
                    }
                }
                ans = str.toString();
            }
            while (!usedX.isEmpty()) {
                int x = usedX.removeLast(), y = usedY.removeLast();
                dist[x][y] = Integer.MAX_VALUE;
                preX[x][y].clear();
                preY[x][y].clear();
                vis[x][y] = false;
            }
            return ans;
        }

    }

    static interface EzIntDeque extends EzIntQueue, EzIntStack {
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

        public String nextString() {
            return next();
        }

        public char[] nextCharArray(int n) {
            char[] a = nextString().toCharArray();
            assert (a.length == n);
            return a;
        }

        public char[][] nextCharArray2(int n, int m) {
            char[][] a = new char[n][];
            for (int i = 0; i < n; i++) a[i] = nextCharArray(m);
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

    static interface EzIntStack extends EzIntCollection {
        int size();

        EzIntIterator iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface EzIntQueue extends EzIntCollection {
        int size();

        EzIntIterator iterator();

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


        public boolean isEmpty() {
            return size == 0;
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


        public void clear() {
            size = 0;
        }


        public int get(int index) {
            if (index < 0 || index >= size) {
                throw new IndexOutOfBoundsException("Index " + index + " is out of range, size = " + size);
            }
            return array[index];
        }


        public int removeLast() {
            if (size == 0) {
                throw new NoSuchElementException("Trying to call removeLast() on empty ArrayList");
            }
            return array[--size];
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


        public void addLast(int element) {
            deque[tail] = element;
            tail = (tail + 1) & mask;
            size++;
            if (size == deque.length) {
                enlarge();
            }
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

    static interface EzIntList extends EzIntCollection {
        int size();

        EzIntIterator iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface EzIntIterator {
        boolean hasNext();

        int next();

    }

    static interface EzIntCollection {
        int size();

        EzIntIterator iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static class CombinatorialEnumerations {
        public static abstract class AbstractEnumeration {
            protected final int range;
            protected final int length;

            protected AbstractEnumeration(int range, int length) {
                this.range = range;
                this.length = length;
            }

            protected abstract long count(int[] prefix);

            public long totalCount() {
                return count(new int[0]);
            }

            public int[] fromNumber(long number) {
                int[] sequence = new int[length];
                for (int i = 0; i < sequence.length; i++) {
                    int[] prefix = Arrays.copyOf(sequence, i + 1);
                    for (prefix[i] = 0; prefix[i] < range; ++prefix[i]) {
                        long cur = count(prefix);
                        if (number < cur) {
                            break;
                        }
                        number -= cur;
                    }
                    sequence[i] = prefix[i];
                }
                return sequence;
            }

        }

        public static class Combinations extends CombinatorialEnumerations.AbstractEnumeration {
            final long[][] binomial;

            public Combinations(int n, int k) {
                super(n, k);
                binomial = new long[n + 1][n + 1];
                

                for (int i = 0; i <= n; i++)
                    for (int j = 0; j <= i; j++)
                        binomial[i][j] = (j == 0) ? 1 : binomial[i - 1][j - 1] + binomial[i - 1][j];
            }


            protected long count(int[] prefix) {
                int size = prefix.length;

                

                

                if (size >= 2 && prefix[size - 1] <= prefix[size - 2])
                    return 0;

                

                int last = size > 0 ? prefix[size - 1] : -1;
                return binomial[range - 1 - last][length - size];
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
}

