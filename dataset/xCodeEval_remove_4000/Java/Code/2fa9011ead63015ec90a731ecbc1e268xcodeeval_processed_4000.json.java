import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
        id10 solver = new id10();
        solver.solve(1, in, out);
        out.close();
    }

    static class id10 {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int[] X = new int[n], Y = new int[n], C = new int[n];
            in.id11(X, Y, C);
            for (int i = 0; i < n; i++) {
                if (X[i] > Y[i]) {
                    int tmp = X[i];
                    X[i] = Y[i];
                    Y[i] = tmp;
                }
            }
            int[] orig = ArrayUtils.compress(X, Y);
            int m = orig.length;
            long[] neg = new long[m];
            Arrays.setAll(neg, i -> -(long) orig[i] * m + i);
            int[] order = ArrayUtils.order(X);
            int idx = 0;
            IntervalTree it = new id8(neg) {

                protected long joinValue(long left, long right) {
                    return Math.max(left, right);
                }


                protected long joinDelta(long was, long delta) {
                    return was + delta;
                }


                protected long accumulate(long value, long delta, int length) {
                    return value + delta;
                }


                protected long neutralValue() {
                    return Long.MIN_VALUE;
                }


                protected long neutralDelta() {
                    return 0;
                }
            };
            for (int i = 0; i < n; i++) {
                it.update(Y[i], m - 1, (long) C[i] * m);
            }
            long res = 0;
            int from = orig[m - 1] + 1, to = orig[m - 1] + 1;
            for (int i = 0; i < m; i++) {
                it.update(i, m - 1, (long) (orig[i] - (i == 0 ? 0 : orig[i - 1])) * m);
                while (idx < n && X[order[idx]] < i) {
                    int id = order[idx], pos = Y[id], val = C[id];
                    idx++;
                    it.update(pos, m - 1, -(long) val * m);
                }
                long q = it.query(i, m - 1);
                if (q > res) {
                    res = q;
                    from = orig[i];
                    int pos = (int) (q % m);
                    to = orig[pos];
                }
            }
            res /= m;
            out.printLine(res);
            out.printLine(from, from, to, to);
        }

    }

    static class id15 extends id3 implements IntList {
        private int size;
        private int[] data;

        public id15() {
            this(3);
        }

        public id15(int capacity) {
            data = new int[capacity];
        }

        public id15(IntCollection c) {
            this(c.size());
            addAll(c);
        }

        public id15(IntStream c) {
            this();
            if (c instanceof IntCollection) {
                ensureCapacity(((IntCollection) c).size());
            }
            addAll(c);
        }

        public id15(id15 c) {
            size = c.size();
            data = c.data.clone();
        }

        public id15(int[] arr) {
            size = arr.length;
            data = arr.clone();
        }

        public int size() {
            return size;
        }

        public int get(int at) {
            if (at >= size) {
                throw new IndexOutOfBoundsException("at = " + at + ", size = " + size);
            }
            return data[at];
        }

        private void ensureCapacity(int capacity) {
            if (data.length >= capacity) {
                return;
            }
            capacity = Math.max(2 * data.length, capacity);
            data = Arrays.copyOf(data, capacity);
        }

        public void addAt(int index, int value) {
            ensureCapacity(size + 1);
            if (index > size || index < 0) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            if (index != size) {
                System.arraycopy(data, index, data, index + 1, size - index);
            }
            data[index] = value;
            size++;
        }

        public void removeAt(int index) {
            if (index >= size || index < 0) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            if (index != size - 1) {
                System.arraycopy(data, index + 1, data, index, size - index - 1);
            }
            size--;
        }

        public void set(int index, int value) {
            if (index >= size) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            data[index] = value;
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

    }

    static interface id14 extends IntCollection {
    }

    static class Sorter {
        private static final int id13 = 16;

        private Sorter() {
        }

        public static void sort(IntList list, IntComparator comparator) {
            quickSort(list, 0, list.size() - 1, (Integer.bitCount(Integer.highestOneBit(list.size()) - 1) * 5) >> 1,
                    comparator);
        }

        private static void quickSort(IntList list, int from, int to, int remaining, IntComparator comparator) {
            if (to - from < id13) {
                id5(list, from, to, comparator);
                return;
            }
            if (remaining == 0) {
                heapSort(list, from, to, comparator);
                return;
            }
            remaining--;
            int pivotIndex = (from + to) >> 1;
            int pivot = list.get(pivotIndex);
            list.swap(pivotIndex, to);
            int storeIndex = from;
            int equalIndex = to;
            for (int i = from; i < equalIndex; i++) {
                int value = comparator.compare(list.get(i), pivot);
                if (value < 0) {
                    list.swap(storeIndex++, i);
                } else if (value == 0) {
                    list.swap(--equalIndex, i--);
                }
            }
            quickSort(list, from, storeIndex - 1, remaining, comparator);
            for (int i = equalIndex; i <= to; i++) {
                list.swap(storeIndex++, i);
            }
            quickSort(list, storeIndex, to, remaining, comparator);
        }

        private static void heapSort(IntList list, int from, int to, IntComparator comparator) {
            for (int i = (to + from - 1) >> 1; i >= from; i--) {
                id1(list, i, to, comparator, from);
            }
            for (int i = to; i > from; i--) {
                list.swap(from, i);
                id1(list, from, i - 1, comparator, from);
            }
        }

        private static void id1(IntList list, int start, int end, IntComparator comparator, int delta) {
            int value = list.get(start);
            while (true) {
                int child = ((start - delta) << 1) + 1 + delta;
                if (child > end) {
                    return;
                }
                int childValue = list.get(child);
                if (child + 1 <= end) {
                    int otherValue = list.get(child + 1);
                    if (comparator.compare(otherValue, childValue) > 0) {
                        child++;
                        childValue = otherValue;
                    }
                }
                if (comparator.compare(value, childValue) >= 0) {
                    return;
                }
                list.swap(start, child);
                start = child;
            }
        }

        private static void id5(IntList list, int from, int to, IntComparator comparator) {
            for (int i = from + 1; i <= to; i++) {
                int value = list.get(i);
                for (int j = i - 1; j >= from; j--) {
                    if (comparator.compare(list.get(j), value) <= 0) {
                        break;
                    }
                    list.swap(j, j + 1);
                }
            }
        }

    }

    static class IntArray extends id3 implements IntList {
        private int[] data;

        public IntArray(int[] arr) {
            data = arr;
        }

        public int size() {
            return data.length;
        }

        public int get(int at) {
            return data[at];
        }

        public void addAt(int index, int value) {
            throw new UnsupportedOperationException();
        }

        public void removeAt(int index) {
            throw new UnsupportedOperationException();
        }

        public void set(int index, int value) {
            data[index] = value;
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

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void printLine(long i) {
            writer.println(i);
        }

    }

    static class Range {
        public static IntList range(int from, int to) {
            int[] result = new int[Math.abs(from - to)];
            int current = from;
            if (from <= to) {
                for (int i = 0; i < result.length; i++) {
                    result[i] = current++;
                }
            } else {
                for (int i = 0; i < result.length; i++) {
                    result[i] = current--;
                }
            }
            return new IntArray(result);
        }

    }

    static interface IntCollection extends IntStream {
        public int size();

        default public void add(int value) {
            throw new UnsupportedOperationException();
        }

        default public int[] toArray() {
            int size = size();
            int[] array = new int[size];
            int i = 0;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                array[i++] = it.value();
            }
            return array;
        }

        default public IntCollection addAll(IntStream values) {
            for (IntIterator it = values.intIterator(); it.isValid(); it.advance()) {
                add(it.value());
            }
            return this;
        }

    }

    static abstract class id8 extends id12 {
        private long[] array;

        protected id8(long[] array) {
            super(array.length, false);
            this.array = array;
            init();
        }

        protected long initValue(int index) {
            return array[index];
        }

    }

    static abstract class id12 extends IntervalTree {
        protected long[] value;
        protected long[] delta;

        protected id12(int size) {
            this(size, true);
        }

        public id12(int size, boolean shouldInit) {
            super(size, shouldInit);
        }

        protected void initData(int size, int nodeCount) {
            value = new long[nodeCount];
            delta = new long[nodeCount];
        }

        protected abstract long joinValue(long left, long right);

        protected abstract long joinDelta(long was, long delta);

        protected abstract long accumulate(long value, long delta, int length);

        protected abstract long neutralValue();

        protected abstract long neutralDelta();

        protected long initValue(int index) {
            return neutralValue();
        }

        protected void initAfter(int root, int left, int right, int middle) {
            value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
            delta[root] = neutralDelta();
        }

        protected void initBefore(int root, int left, int right, int middle) {
        }

        protected void initLeaf(int root, int index) {
            value[root] = initValue(index);
            delta[root] = neutralDelta();
        }

        protected void id2(int root, int left, int right, int from, int to, long delta, int middle) {
            value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
        }

        protected void id9(int root, int left, int right, int from, int to, long delta, int middle) {
            pushDown(root, left, middle, right);
        }

        protected void pushDown(int root, int left, int middle, int right) {
            value[2 * root + 1] = accumulate(value[2 * root + 1], delta[root], middle - left + 1);
            value[2 * root + 2] = accumulate(value[2 * root + 2], delta[root], right - middle);
            delta[2 * root + 1] = joinDelta(delta[2 * root + 1], delta[root]);
            delta[2 * root + 2] = joinDelta(delta[2 * root + 2], delta[root]);
            delta[root] = neutralDelta();
        }

        protected void updateFull(int root, int left, int right, int from, int to, long delta) {
            value[root] = accumulate(value[root], delta, right - left + 1);
            this.delta[root] = joinDelta(this.delta[root], delta);
        }

        protected long id6(int root, int left, int right, int from, int to, int middle, long leftResult,
                                        long rightResult) {
            return joinValue(leftResult, rightResult);
        }

        protected void id7(int root, int left, int right, int from, int to, int middle) {
            pushDown(root, left, middle, right);
        }

        protected long queryFull(int root, int left, int right, int from, int to) {
            return value[root];
        }

        protected long id0() {
            return neutralValue();
        }

    }

    static abstract class id3 implements IntStream {
        public String toString() {
            StringBuilder builder = new StringBuilder();
            boolean first = true;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                if (first) {
                    first = false;
                } else {
                    builder.append(' ');
                }
                builder.append(it.value());
            }
            return builder.toString();
        }

        public boolean equals(Object o) {
            if (!(o instanceof IntStream)) {
                return false;
            }
            IntStream c = (IntStream) o;
            IntIterator it = intIterator();
            IntIterator jt = c.intIterator();
            while (it.isValid() && jt.isValid()) {
                if (it.value() != jt.value()) {
                    return false;
                }
                it.advance();
                jt.advance();
            }
            return !it.isValid() && !jt.isValid();
        }

        public int hashCode() {
            int result = 0;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                result *= 31;
                result += it.value();
            }
            return result;
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id16 filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public void id11(int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readInt();
                }
            }
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

        public int readInt() {
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

        public interface id16 {
            boolean id4(int ch);

        }

    }

    static interface IntList extends id14 {
        public abstract int get(int index);

        public abstract void set(int index, int value);

        public abstract void addAt(int index, int value);

        public abstract void removeAt(int index);

        default public void swap(int first, int second) {
            if (first == second) {
                return;
            }
            int temp = get(first);
            set(first, get(second));
            set(second, temp);
        }

        default public IntIterator intIterator() {
            return new IntIterator() {
                private int at;
                private boolean removed;

                public int value() {
                    if (removed) {
                        throw new IllegalStateException();
                    }
                    return get(at);
                }

                public boolean advance() {
                    at++;
                    removed = false;
                    return isValid();
                }

                public boolean isValid() {
                    return !removed && at < size();
                }

                public void remove() {
                    removeAt(at);
                    at--;
                    removed = true;
                }
            };
        }

        default public void add(int value) {
            addAt(size(), value);
        }

        default public IntList sort(IntComparator comparator) {
            Sorter.sort(this, comparator);
            return this;
        }

        default IntList unique() {
            int last = Integer.MIN_VALUE;
            IntList result = new id15();
            int size = size();
            for (int i = 0; i < size; i++) {
                int current = get(i);
                if (current != last) {
                    result.add(current);
                    last = current;
                }
            }
            return result;
        }

        default public IntList subList(final int from, final int to) {
            return new IntList() {
                private final int shift;
                private final int size;

                {
                    if (from < 0 || from > to || to > IntList.this.size()) {
                        throw new IndexOutOfBoundsException("from = " + from + ", to = " + to + ", size = " + size());
                    }
                    shift = from;
                    size = to - from;
                }

                public int size() {
                    return size;
                }

                public int get(int at) {
                    if (at < 0 || at >= size) {
                        throw new IndexOutOfBoundsException("at = " + at + ", size = " + size());
                    }
                    return IntList.this.get(at + shift);
                }

                public void addAt(int index, int value) {
                    throw new UnsupportedOperationException();
                }

                public void removeAt(int index) {
                    throw new UnsupportedOperationException();
                }

                public void set(int at, int value) {
                    if (at < 0 || at >= size) {
                        throw new IndexOutOfBoundsException("at = " + at + ", size = " + size());
                    }
                    IntList.this.set(at + shift, value);
                }

                public IntList compute() {
                    return new id15(this);
                }
            };
        }

    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static abstract class IntervalTree {
        protected int size;

        protected IntervalTree(int size) {
            this(size, true);
        }

        public IntervalTree(int size, boolean shouldInit) {
            this.size = size;
            int nodeCount = Math.max(1, Integer.highestOneBit(size) << 2);
            initData(size, nodeCount);
            if (shouldInit) {
                init();
            }
        }

        protected abstract void initData(int size, int nodeCount);

        protected abstract void initAfter(int root, int left, int right, int middle);

        protected abstract void initBefore(int root, int left, int right, int middle);

        protected abstract void initLeaf(int root, int index);

        protected abstract void id2(int root, int left, int right, int from, int to, long delta, int middle);

        protected abstract void id9(int root, int left, int right, int from, int to, long delta, int middle);

        protected abstract void updateFull(int root, int left, int right, int from, int to, long delta);

        protected abstract long id6(int root, int left, int right, int from, int to, int middle,
                                                 long leftResult, long rightResult);

        protected abstract void id7(int root, int left, int right, int from, int to, int middle);

        protected abstract long queryFull(int root, int left, int right, int from, int to);

        protected abstract long id0();

        public void init() {
            if (size == 0) {
                return;
            }
            init(0, 0, size - 1);
        }

        private void init(int root, int left, int right) {
            if (left == right) {
                initLeaf(root, left);
            } else {
                int middle = (left + right) >> 1;
                initBefore(root, left, right, middle);
                init(2 * root + 1, left, middle);
                init(2 * root + 2, middle + 1, right);
                initAfter(root, left, right, middle);
            }
        }

        public void update(int from, int to, long delta) {
            update(0, 0, size - 1, from, to, delta);
        }

        protected void update(int root, int left, int right, int from, int to, long delta) {
            if (left > to || right < from) {
                return;
            }
            if (left >= from && right <= to) {
                updateFull(root, left, right, from, to, delta);
                return;
            }
            int middle = (left + right) >> 1;
            id9(root, left, right, from, to, delta, middle);
            update(2 * root + 1, left, middle, from, to, delta);
            update(2 * root + 2, middle + 1, right, from, to, delta);
            id2(root, left, right, from, to, delta, middle);
        }

        public long query(int from, int to) {
            return query(0, 0, size - 1, from, to);
        }

        protected long query(int root, int left, int right, int from, int to) {
            if (left > to || right < from) {
                return id0();
            }
            if (left >= from && right <= to) {
                return queryFull(root, left, right, from, to);
            }
            int middle = (left + right) >> 1;
            id7(root, left, right, from, to, middle);
            long leftResult = query(2 * root + 1, left, middle, from, to);
            long rightResult = query(2 * root + 2, middle + 1, right, from, to);
            return id6(root, left, right, from, to, middle, leftResult, rightResult);
        }

    }

    static class ArrayUtils {
        public static int[] range(int from, int to) {
            return Range.range(from, to).toArray();
        }

        public static int[] createOrder(int size) {
            return range(0, size);
        }

        public static int[] sort(int[] array, IntComparator comparator) {
            return sort(array, 0, array.length, comparator);
        }

        public static int[] sort(int[] array, int from, int to, IntComparator comparator) {
            if (from == 0 && to == array.length) {
                new IntArray(array).sort(comparator);
            } else {
                new IntArray(array).subList(from, to).sort(comparator);
            }
            return array;
        }

        public static int[] order(final int[] array) {
            return sort(createOrder(array.length), (first, second) -> Integer.compare(array[first], array[second]));
        }

        public static int[] unique(int[] array) {
            return new IntArray(array).unique().toArray();
        }

        public static int[] compress(int[]... arrays) {
            int totalLength = 0;
            for (int[] array : arrays) {
                totalLength += array.length;
            }
            int[] all = new int[totalLength];
            int delta = 0;
            for (int[] array : arrays) {
                System.arraycopy(array, 0, all, delta, array.length);
                delta += array.length;
            }
            sort(all, IntComparator.DEFAULT);
            all = unique(all);
            for (int[] array : arrays) {
                for (int i = 0; i < array.length; i++) {
                    array[i] = Arrays.binarySearch(all, array[i]);
                }
            }
            return all;
        }

    }

    static interface IntComparator {
        IntComparator DEFAULT = Integer::compare;

        int compare(int first, int second);

    }

    static interface IntStream extends Iterable<Integer>, Comparable<IntStream> {
        IntIterator intIterator();

        default Iterator<Integer> iterator() {
            return new Iterator<Integer>() {
                private IntIterator it = intIterator();

                public boolean hasNext() {
                    return it.isValid();
                }

                public Integer next() {
                    int result = it.value();
                    it.advance();
                    return result;
                }
            };
        }

        default int compareTo(IntStream c) {
            IntIterator it = intIterator();
            IntIterator jt = c.intIterator();
            while (it.isValid() && jt.isValid()) {
                int i = it.value();
                int j = jt.value();
                if (i < j) {
                    return -1;
                } else if (i > j) {
                    return 1;
                }
                it.advance();
                jt.advance();
            }
            if (it.isValid()) {
                return 1;
            }
            if (jt.isValid()) {
                return -1;
            }
            return 0;
        }

    }
}

