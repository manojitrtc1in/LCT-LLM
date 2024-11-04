import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.util.Random;
import java.util.OptionalInt;
import java.util.ArrayList;
import java.io.BufferedOutputStream;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.NoSuchElementException;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Writer;
import java.util.Map.Entry;
import java.io.BufferedReader;
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
        ArrayList<EzIntIntPair>[] graph;
        int[] cap;
        int[] par;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] A = in.nextIntArray(n);
            EzIntIntHashMap map = new EzIntIntHashMap();
            for (int i = 0; i < n; i++) map.put(A[i], i);
            graph = new ArrayList[n];
            for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();
            for (int i = 1; i < n; i++) {
                int u = in.nextInt() - 1, v = in.nextInt() - 1, w = in.nextInt();
                graph[u].add(new EzIntIntPair(v, w));
                graph[v].add(new EzIntIntPair(u, w));
            }
            cap = new int[n];
            par = new int[n];
            dfs(0, -1, Integer.MAX_VALUE);
            int[] ans = solve(A, map);
            for (int x : ans) out.print(x + " ");
            out.println();
        }

        int[] solve(int[] A, EzIntIntHashMap map) {
            int n = A.length;
            EzIntArrayDeque[] deque = new EzIntArrayDeque[n];
            for (int i = 0; i < n; i++) deque[i] = new EzIntArrayDeque(new int[]{A[i]});
            int finished = 0;
            int[] ans = new int[n], up = new int[n];
            for (int time = 0; finished < n; time++) {
                for (int x : deque[0].toArray()) ans[map.get(x)] = time;
                finished += deque[0].size();
                for (int i = 0; i < n; i++) {
                    if (deque[i].size() > cap[i]) {
                        up[i] = cap[i];
                        NthElement.nth_element(deque[i], 0, deque[i].size(), cap[i] - 1);
                    } else up[i] = deque[i].size();
                }
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < up[i]; j++) {
                        int x = deque[i].removeFirst();
                        if (par[i] != -1) deque[par[i]].addLast(x);
                    }
            }
            return ans;
        }

        void dfs(int u, int p, int c) {
            par[u] = p;
            cap[u] = c;
            for (EzIntIntPair edge : graph[u]) {
                int v = edge.first, w = edge.second;
                if (v != p) dfs(v, u, w);
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


        public EzIntIterator iterator() {
            return new EzIntArrayDequeIterator();
        }


        public int[] toArray() {
            int[] result = new int[size];
            for (int i = head, j = 0; i != tail; i = (i + 1) & mask) {
                result[j++] = deque[i];
            }
            return result;
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


        public int get(int index) {
            if (index < 0 || index >= size) {
                throw new IndexOutOfBoundsException("Index " + index + " is out of range, size = " + size);
            }
            return deque[(head + index) & mask];
        }


        public int set(int index, int element) {
            if (index < 0 || index >= size) {
                throw new IndexOutOfBoundsException("Index " + index + " is out of range, size = " + size);
            }
            final int realIndex = (head + index) & mask;
            final int oldElement = deque[realIndex];
            deque[realIndex] = element;
            return oldElement;
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

    static class EzIntIntPair {
        private static final int HASHCODE_INITIAL_VALUE = 0x811c9dc5;
        private static final int HASHCODE_MULTIPLIER = 0x01000193;
        public int first;
        public int second;

        public EzIntIntPair(int first, int second) {
            this.first = first;
            this.second = second;
        }


        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            EzIntIntPair that = (EzIntIntPair) o;

            return first == that.first && second == that.second;
        }


        public int hashCode() {
            int hash = HASHCODE_INITIAL_VALUE;
            hash = (hash ^ PrimitiveHashCalculator.getHash(first)) * HASHCODE_MULTIPLIER;
            hash = (hash ^ PrimitiveHashCalculator.getHash(second)) * HASHCODE_MULTIPLIER;
            return hash;
        }


        public String toString() {
            return "(" + first + ", " + second + ")";
        }

    }

    static interface EzIntIterator {
        boolean hasNext();

        int next();

    }

    static interface EzIntIntMap {
        int size();

        EzIntIntMapIterator iterator();

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

    }

    static class EzIntIntHashMap implements EzIntIntMap {
        private static final int DEFAULT_CAPACITY = 8;
        private static final int HASHCODE_INITIAL_VALUE = 0x811c9dc5;
        private static final int HASHCODE_MULTIPLIER = 0x01000193;
        private static final byte FREE = 0;
        private static final byte FILLED = 2;
        private static final int DEFAULT_NULL_VALUE = (new int[1])[0];
        private static final Random rnd = new Random();
        private static final int POS_RANDOM_SHIFT_1;
        private static final int POS_RANDOM_SHIFT_2;
        private static final int STEP_RANDOM_SHIFT_1;
        private static final int STEP_RANDOM_SHIFT_2;
        private int[] keys;
        private int[] values;
        private byte[] status;
        private int size;
        private int removedCount;
        private int mask;
        private boolean returnedNull;
        private final int hashSeed;

        static {
            POS_RANDOM_SHIFT_1 = rnd.nextInt(10) + 11;
            POS_RANDOM_SHIFT_2 = rnd.nextInt(10) + 21;
            STEP_RANDOM_SHIFT_1 = rnd.nextInt(10) + 11;
            STEP_RANDOM_SHIFT_2 = rnd.nextInt(10) + 21;
        }

        public EzIntIntHashMap() {
            this(DEFAULT_CAPACITY);
        }

        public EzIntIntHashMap(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            

            int length = 4 * Math.max(1, capacity);
            if ((length & (length - 1)) != 0) {
                length = Integer.highestOneBit(length) << 1;
            }
            

            initEmptyTable(length);
            returnedNull = false;
            hashSeed = rnd.nextInt();
        }

        public EzIntIntHashMap(EzIntIntMap map) {
            this(map.size());
            for (EzIntIntMapIterator it = map.iterator(); it.hasNext(); it.next()) {
                put(it.getKey(), it.getValue());
            }
        }

        public EzIntIntHashMap(Map<Integer, Integer> javaMap) {
            this(javaMap.size());
            for (Map.Entry<Integer, Integer> e : javaMap.entrySet()) {
                put(e.getKey(), e.getValue());
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


        public int get(int key) {
            final int keyHash = PrimitiveHashCalculator.getHash(key);
            int pos = getStartPos(keyHash);
            final int step = getStep(keyHash);
            for (; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && keys[pos] == key) {
                    returnedNull = false;
                    return values[pos];
                }
            }
            returnedNull = true;
            return DEFAULT_NULL_VALUE;
        }


        public int put(int key, int value) {
            final int keyHash = PrimitiveHashCalculator.getHash(key);
            int pos = getStartPos(keyHash);
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
                return DEFAULT_NULL_VALUE;
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
            return DEFAULT_NULL_VALUE;
        }


        public EzIntIntMapIterator iterator() {
            return new EzIntIntHashMapIterator();
        }

        private void rebuild(int newLength) {
            int[] oldKeys = keys;
            int[] oldValues = values;
            byte[] oldStatus = status;
            initEmptyTable(newLength);
            for (int i = 0; i < oldKeys.length; i++) {
                if (oldStatus[i] == FILLED) {
                    put(oldKeys[i], oldValues[i]);
                }
            }
        }

        private void initEmptyTable(int length) {
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
            EzIntIntHashMap that = (EzIntIntHashMap) o;

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
                    int hash = HASHCODE_INITIAL_VALUE;
                    hash = (hash ^ PrimitiveHashCalculator.getHash(keys[i])) * HASHCODE_MULTIPLIER;
                    hash = (hash ^ PrimitiveHashCalculator.getHash(values[i])) * HASHCODE_MULTIPLIER;
                    entryHashes[j++] = hash;
                }
            }
            randomShuffle(entryHashes);
            Arrays.sort(entryHashes);
            int hash = HASHCODE_INITIAL_VALUE;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ entryHashes[i]) * HASHCODE_MULTIPLIER;
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

        private class EzIntIntHashMapIterator implements EzIntIntMapIterator {
            private int curIndex;

            private EzIntIntHashMapIterator() {
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

    static interface EzIntIntMapIterator {
        boolean hasNext();

        int getKey();

        int getValue();

        void next();

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

    static interface EzIntStack extends EzIntCollection {
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

    static interface EzIntDeque extends EzIntQueue, EzIntStack {
        int size();

        EzIntIterator iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface EzIntList extends EzIntCollection {
        int size();

        EzIntIterator iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

        int get(int index);

        int set(int index, int element);

    }

    static class NthElement {
        static int partition(int[] a, int fromInclusive, int toExclusive, int separatorIndex) {
            int i = fromInclusive;
            int j = toExclusive - 1;
            if (i >= j) return j;
            int separator = a[separatorIndex];
            swap(a, i++, separatorIndex);
            while (i <= j) {
                while (i <= j && a[i] < separator)
                    ++i;
                while (i <= j && a[j] > separator)
                    --j;
                if (i >= j)
                    break;
                swap(a, i++, j--);
            }
            swap(a, j, fromInclusive);
            return j;
        }

        static int partition(EzIntList a, int fromInclusive, int toExclusive, int separatorIndex) {
            int i = fromInclusive;
            int j = toExclusive - 1;
            if (i >= j) return j;
            int separator = a.get(separatorIndex);
            swap(a, i++, separatorIndex);
            while (i <= j) {
                while (i <= j && a.get(i) < separator)
                    ++i;
                while (i <= j && a.get(j) > separator)
                    --j;
                if (i >= j)
                    break;
                swap(a, i++, j--);
            }
            swap(a, j, fromInclusive);
            return j;
        }

        static void swap(int[] a, int i, int j) {
            int t = a[j];
            a[j] = a[i];
            a[i] = t;
        }

        static void swap(EzIntList a, int i, int j) {
            int t = a.get(j);
            a.set(j, a.get(i));
            a.set(i, t);
        }

        public static void nth_element(int[] a, int low, int high, int n) {
            if (high - low <= 1)
                return;
            while (true) {
                int[] a5 = new int[(high - low + 4) / 5];
                for (int i = low, cnt = 0; i < high; i += 5) {
                    int j = Math.min(i + 5, high);
                    for (int iteration = 0; iteration < 3; iteration++) {
                        for (int k = i; k + 1 < j; k++) {
                            if (a[k] > a[k + 1]) {
                                int t = a[k];
                                a[k] = a[k + 1];
                                a[k + 1] = t;
                            }
                        }
                    }
                    a5[cnt++] = a[(i + j) >>> 1];
                }
                nth_element(a5, 0, a5.length, a5.length / 2);
                int separatorIndex = IntStream.range(low, high).filter(i -> a[i] == a5[a5.length / 2]).findFirst().getAsInt();
                int k = partition(a, low, high, separatorIndex);
                if (n < k)
                    high = k;
                else if (n > k)
                    low = k + 1;
                else
                    return;
            }
        }

        public static void nth_element(EzIntList a, int low, int high, int n) {
            if (high - low <= 1)
                return;
            while (true) {
                int[] a5 = new int[(high - low + 4) / 5];
                for (int i = low, cnt = 0; i < high; i += 5) {
                    int j = Math.min(i + 5, high);
                    for (int iteration = 0; iteration < 3; iteration++) {
                        for (int k = i; k + 1 < j; k++) {
                            if (a.get(k) > a.get(k + 1)) {
                                int t = a.get(k);
                                a.set(k, a.get(k + 1));
                                a.set(k + 1, t);
                            }
                        }
                    }
                    a5[cnt++] = a.get((i + j) >>> 1);
                }
                nth_element(a5, 0, a5.length, a5.length / 2);
                int separatorIndex = IntStream.range(low, high).filter(i -> a.get(i) == a5[a5.length / 2]).findFirst().getAsInt();
                int k = partition(a, low, high, separatorIndex);
                if (n < k)
                    high = k;
                else if (n > k)
                    low = k + 1;
                else
                    return;
            }
        }

    }

    static interface EzIntQueue extends EzIntCollection {
        int size();

        EzIntIterator iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }
}

