import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Random;
import java.io.BufferedOutputStream;
import java.util.StringTokenizer;
import java.util.NoSuchElementException;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.stream.Stream;
import java.io.Writer;
import java.io.BufferedReader;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        LittleElephantAndStrings solver = new LittleElephantAndStrings();
        solver.solve(1, in, out);
        out.close();
    }

    static class LittleElephantAndStrings {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            int[] begin = new int[n], lengths = new int[n];
            EzIntArrayList list = new EzIntArrayList();
            for (int i = 0; i < n; i++) {
                list.add(i);
                begin[i] = list.size() - 1;
                char[] str = in.nextString().toCharArray();
                lengths[i] = str.length;
                for (char c : str) list.add(n + c);
            }
            int N = list.size();
            int[] str = list.toArray(), SA = SuffixArray.suffixArray(str), LCP = SuffixArray.lcp(SA, str), idx = new int[N];
            for (int i = 0; i < N; i++) {
                int pos = Arrays.binarySearch(begin, SA[i]);
                idx[i] = -pos - 2;
            }
            RmqSparseTable rmq = new RmqSparseTable(LCP);
            HashMap<Integer, EzIntHashSet> map = new HashMap<>();
            SegmentTree seg = new SegmentTree(N) {

                protected int modifyOperation(int x, int y) {
                    return Math.max(x, y);
                }


                protected int queryOperation(int leftValue, int rightValue) {
                    return Math.max(leftValue, rightValue);
                }


                protected int deltaEffectOnSegment(int delta, int segmentLength) {
                    return delta;
                }


                protected int getNeutralDelta() {
                    return 0;
                }


                protected int getInitValue() {
                    return 0;
                }
            };
            for (int i = n, j = n; i < N; i++) {
                int id = idx[i];
                map.putIfAbsent(id, new EzIntHashSet());
                map.get(id).add(i);
                while (map.size() - (map.get(idx[j]).size() == 1 ? 1 : 0) == k) {
                    map.get(idx[j]).remove(j);
                    if (map.get(idx[j]).isEmpty()) map.remove(idx[j]);
                    j++;
                }
                if (map.size() == k) {
                    int x = i == j ? begin[id] + lengths[id] + 1 - SA[i] : LCP[rmq.minPos(j, i - 1)];
                    seg.modify(j, i, x);
                }
            }
            map.clear();
            for (int i = N - 1, j = N - 1; i >= n; i--) {
                int id = idx[i];
                map.putIfAbsent(id, new EzIntHashSet());
                map.get(id).add(i);
                while (map.size() - (map.get(idx[j]).size() == 1 ? 1 : 0) == k) {
                    map.get(idx[j]).remove(j);
                    if (map.get(idx[j]).isEmpty()) map.remove(idx[j]);
                    j--;
                }
                if (map.size() == k) {
                    int x = i == j ? begin[id] + lengths[id] + 1 - SA[i] : LCP[rmq.minPos(i, j - 1)];
                    seg.modify(i, j, x);
                }
            }
            long[] ans = new long[n];
            for (int i = n; i < N; i++) ans[idx[i]] += seg.query(i, i);
            for (long x : ans) out.print(x + " ");
            out.println();
        }

    }

    static class RmqSparseTable {
        int[] logTable;
        int[][] rmq;
        int[] a;

        public RmqSparseTable(int[] a) {
            this.a = a;
            int n = a.length;

            logTable = new int[n + 1];
            for (int i = 2; i <= n; i++)
                logTable[i] = logTable[i >> 1] + 1;

            rmq = new int[logTable[n] + 1][n];

            for (int i = 0; i < n; ++i)
                rmq[0][i] = i;

            for (int k = 1; (1 << k) < n; ++k) {
                for (int i = 0; i + (1 << k) <= n; i++) {
                    int x = rmq[k - 1][i];
                    int y = rmq[k - 1][i + (1 << k - 1)];
                    rmq[k][i] = a[x] <= a[y] ? x : y;
                }
            }
        }

        public int minPos(int i, int j) {
            int k = logTable[j - i];
            int x = rmq[k][i];
            int y = rmq[k][j - (1 << k) + 1];
            return a[x] <= a[y] ? x : y;
        }

    }

    static class EzIntHashSet implements EzIntSet {
        private static final int DEFAULT_CAPACITY = 8;
        private static final int REBUILD_LENGTH_THRESHOLD = 32;
        private static final int HASHCODE_INITIAL_VALUE = 0x811c9dc5;
        private static final int HASHCODE_MULTIPLIER = 0x01000193;
        private static final byte FREE = 0;
        private static final byte REMOVED = 1;
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


        public boolean isEmpty() {
            return size == 0;
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


        public boolean remove(int element) {
            final int elementHash = PrimitiveHashCalculator.getHash(element);
            int pos = getStartPos(elementHash);
            final int step = getStep(elementHash);
            for (; status[pos] != FREE; pos = (pos + step) & mask) {
                if (status[pos] == FILLED && table[pos] == element) {
                    status[pos] = REMOVED;
                    size--;
                    removedCount++;
                    if (table.length > REBUILD_LENGTH_THRESHOLD) {
                        if (8 * size <= table.length) {
                            rebuild(table.length / 2); 

                        } else if (size < removedCount) {
                            rebuild(table.length); 

                        }
                    }
                    return true;
                }
            }
            return false;
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

    static interface EzIntList extends EzIntCollection {
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

    static class SuffixArray {
        public static int[] suffixArray(int[] S) {
            int n = S.length;
            int[] sa = IntStream.range(0, n).mapToObj(i -> n - 1 - i).sorted((a, b) -> Integer.compare(S[a], S[b])).mapToInt(Integer::intValue).toArray(), classes = S.clone();
            for (int len = 1; len < n; len *= 2) {
                int[] c = classes.clone();
                for (int i = 0; i < n; i++)
                    classes[sa[i]] = i > 0 && c[sa[i - 1]] == c[sa[i]] && sa[i - 1] + len < n && c[sa[i - 1] + len / 2] == c[sa[i] + len / 2] ? classes[sa[i - 1]] : i;
                int[] cnt = IntStream.range(0, n).toArray(), s = sa.clone();
                for (int i = 0; i < n; i++) {
                    int s1 = s[i] - len;
                    if (s1 >= 0) sa[cnt[classes[s1]]++] = s1;
                }
            }
            return sa;
        }

        public static int[] lcp(int[] sa, int[] s) {
            int n = sa.length;
            int[] rank = new int[n];
            for (int i = 0; i < n; i++) rank[sa[i]] = i;
            int[] lcp = new int[n - 1];
            for (int i = 0, h = 0; i < n; i++)
                if (rank[i] < n - 1) {
                    for (int j = sa[rank[i] + 1]; Math.max(i, j) + h < s.length && s[i + h] == s[j + h]; h++) ;
                    lcp[rank[i]] = h;
                    if (h > 0) h--;
                }
            return lcp;
        }

    }

    static abstract class SegmentTree {
        private int n;
        private int[] value;
        private int[] delta;

        protected abstract int modifyOperation(int x, int y);

        protected abstract int queryOperation(int leftValue, int rightValue);

        protected abstract int deltaEffectOnSegment(int delta, int segmentLength);

        protected abstract int getNeutralDelta();

        protected abstract int getInitValue();

        private int joinValueWithDelta(int value, int delta) {
            if (delta == getNeutralDelta()) return value;
            return modifyOperation(value, delta);
        }

        private int joinDeltas(int delta1, int delta2) {
            if (delta1 == getNeutralDelta()) return delta2;
            if (delta2 == getNeutralDelta()) return delta1;
            return modifyOperation(delta1, delta2);
        }

        private void pushDelta(int root, int left, int right) {
            value[root] = joinValueWithDelta(value[root], deltaEffectOnSegment(delta[root], right - left + 1));
            delta[2 * root + 1] = joinDeltas(delta[2 * root + 1], delta[root]);
            delta[2 * root + 2] = joinDeltas(delta[2 * root + 2], delta[root]);
            delta[root] = getNeutralDelta();
        }

        public SegmentTree(int n) {
            this.n = n;
            value = new int[4 * n];
            delta = new int[4 * n];
            init(0, 0, n - 1);
        }

        private void init(int root, int left, int right) {
            if (left == right) {
                value[root] = getInitValue();
                delta[root] = getNeutralDelta();
            } else {
                int mid = (left + right) >> 1;
                init(2 * root + 1, left, mid);
                init(2 * root + 2, mid + 1, right);
                value[root] = queryOperation(value[2 * root + 1], value[2 * root + 2]);
                delta[root] = getNeutralDelta();
            }
        }

        public int query(int from, int to) {
            return query(from, to, 0, 0, n - 1);
        }

        private int query(int from, int to, int root, int left, int right) {
            if (from == left && to == right)
                return joinValueWithDelta(value[root], deltaEffectOnSegment(delta[root], right - left + 1));
            pushDelta(root, left, right);
            int mid = (left + right) >> 1;
            if (from <= mid && to > mid)
                return queryOperation(
                        query(from, Math.min(to, mid), root * 2 + 1, left, mid),
                        query(Math.max(from, mid + 1), to, root * 2 + 2, mid + 1, right));
            else if (from <= mid)
                return query(from, Math.min(to, mid), root * 2 + 1, left, mid);
            else if (to > mid)
                return query(Math.max(from, mid + 1), to, root * 2 + 2, mid + 1, right);
            else
                throw new RuntimeException("Incorrect query from " + from + " to " + to);
        }

        public void modify(int from, int to, int delta) {
            modify(from, to, delta, 0, 0, n - 1);
        }

        private void modify(int from, int to, int delta, int root, int left, int right) {
            if (from == left && to == right) {
                this.delta[root] = joinDeltas(this.delta[root], delta);
                return;
            }
            pushDelta(root, left, right);
            int mid = (left + right) >> 1;
            if (from <= mid)
                modify(from, Math.min(to, mid), delta, 2 * root + 1, left, mid);
            if (to > mid)
                modify(Math.max(from, mid + 1), to, delta, 2 * root + 2, mid + 1, right);
            value[root] = queryOperation(
                    joinValueWithDelta(value[2 * root + 1], deltaEffectOnSegment(this.delta[2 * root + 1], mid - left + 1)),
                    joinValueWithDelta(value[2 * root + 2], deltaEffectOnSegment(this.delta[2 * root + 2], right - mid)));
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

        public String nextLine() {
            try {
                return br.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
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

    static interface EzIntIterator {
        boolean hasNext();

        int next();

    }
}

