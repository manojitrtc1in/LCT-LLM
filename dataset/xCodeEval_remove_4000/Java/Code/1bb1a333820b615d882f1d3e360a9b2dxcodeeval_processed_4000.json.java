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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        static OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {



            TaskE.out = out;
            int n;
            int m;
            int id8;
            int[][] x;
            int[][] y;
            int[][] cost;
            n = in.readInt();
            m = in.readInt();
            id8 = in.readInt();
            x = new int[id8][];
            y = new int[id8][];
            cost = new int[id8][];

            for (int i = 0; i < id8; i++) {
                int len = in.readInt();
                x[i] = new int[len];
                y[i] = new int[len];
                cost[i] = new int[len];
                IOUtils.id7(in, x[i], y[i], cost[i]);
                

            }

            int q = in.readInt();
            boolean[] isAsk = new boolean[q];
            long[] answers = new long[q];
            id12[] qwer = new id12[id8];
            for (int i = 0; i < id8; i++) {
                qwer[i] = new id12();
            }
            boolean[] isOn = new boolean[id8];
            Arrays.fill(isOn, true);
            int[] x0 = new int[q];
            int[] x1 = new int[q];
            int[] y0 = new int[q];
            int[] y1 = new int[q];
            for (int iter = 0; iter < q; iter++) {
                String s = in.readString();
                if (s.charAt(0) == 'S') {
                    int index = in.readInt() - 1;
                    isOn[index] ^= true;
                } else {
                    isAsk[iter] = true;
                    x0[iter] = in.readInt();
                    y0[iter] = in.readInt();
                    x1[iter] = in.readInt();
                    y1[iter] = in.readInt();
                    for (int i = 0; i < id8; i++) {
                        if (isOn[i]) {
                            qwer[i].add(iter);
                        }
                    }
                }
            }

            for (int g = 0; g < id8; g++) {
                TaskE.SegTree seg = new TaskE.SegTree(ArrayUtils.order(x[g]), x[g], y[g], cost[g]);
                for (int i = 0; i < qwer[g].size(); i++) {
                    int idQ = qwer[g].get(i);
                    answers[idQ] += seg.sum(x0[idQ], x1[idQ], y0[idQ], y1[idQ]);
                }
            }
            for (int i = 0; i < q; i++) {
                if (isAsk[i]) {
                    out.printLine(answers[i]);
                }
            }
        }

        static class SegTree {
            int n;
            int[] id6;
            int[] x;
            int[] y;
            int[] cost;
            int[][] id9;
            long[][] id2;

            public SegTree(int[] id6, int[] x, int[] y, int[] cost) {
                this.id6 = id6;
                this.x = x;
                this.y = y;
                this.cost = cost;
                n = id6.length;
                int max = Math.max(1, Integer.highestOneBit(n) << 2);
                id9 = new int[max][];
                id2 = new long[max][];
                init(0, 0, n - 1);
            }

            private void init(int v, int tl, int tr) {
                id9[v] = new int[tr - tl + 1];
                id2[v] = new long[tr - tl + 1];
                if (tl == tr) {
                    id9[v][0] = id6[tl];
                    id2[v][0] = cost[id6[tl]];
                } else {
                    int tm = (tl + tr) >> 1;
                    init(v + v + 1, tl, tm);
                    init(v + v + 2, tm + 1, tr);
                    merge(id9[v], id2[v], id9[v + v + 1], id9[v + v + 2]);
                }
            }

            private void merge(int[] order, long[] sum, int[] orderL, int[] orderR) {
                int l = 0;
                int r = 0;
                for (int pos = 0; pos < order.length; pos++) {
                    if (l < orderL.length && r < orderR.length) {
                        if (y[orderL[l]] < y[orderR[r]]) {
                            order[pos] = orderL[l++];
                        } else {
                            order[pos] = orderR[r++];
                        }
                    } else if (l < orderL.length) {
                        order[pos] = orderL[l++];
                    } else {
                        order[pos] = orderR[r++];
                    }
                }
                for (int pos = 0; pos < order.length; pos++) {
                    sum[pos] = cost[order[pos]];
                    if (pos != 0) {
                        sum[pos] += sum[pos - 1];
                    }
                }
            }

            long sum(int x0, int x1, int y0, int y1) {
                return sum(x0, x1, y0, y1, 0, 0, n - 1);
            }

            private long sum(int x0, int x1, int y0, int y1, int v, int tl, int tr) {
                int xtl = x[id6[tl]];
                int xtr = x[id6[tr]];
                if (x1 < xtl || xtr < x0) {
                    return 0;
                }

                if (x0 <= xtl && xtr <= x1) {
                    int posL = id0(y0 - 1, id9[v]);
                    int posR = lastLess(y1 + 1, id9[v]);
                    long res = posL <= posR ? id2[v][posR] - (posL == 0 ? 0 : id2[v][posL - 1]) : 0;
                    return res;
                } else {
                    int tm = (tl + tr) >>> 1;
                    return sum(x0, x1, y0, y1, v + v + 1, tl, tm) +
                            sum(x0, x1, y0, y1, v + v + 2, tm + 1, tr);
                }
            }

            private int lastLess(int y, int[] id13) {
                int l = -1, r = id13.length - 1;
                while (l < r) {
                    int m = (l + r + 1) >>> 1;
                    if (this.y[id13[m]] < y) {
                        l = m;
                    } else {
                        r = m - 1;
                    }
                }
                return l;
            }

            private int id0(int y, int[] id13) {
                int l = 0, r = id13.length;
                while (l < r) {
                    int m = (l + r) >>> 1;
                    if (y < this.y[id13[m]]) {
                        r = m;
                    } else {
                        l = m + 1;
                    }
                }
                return l;
            }

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
            if ((from == 0) && (to == array.length)) {
                new IntArray(array).sort(comparator);
            } else {
                new IntArray(array).subList(from, to).sort(comparator);
            }
            return array;
        }

        public static int[] order(final int[] array) {
            return sort(createOrder(array.length), new IntComparator() {
                public int compare(int first, int second) {
                    if (array[first] < array[second]) {
                        return -1;
                    }
                    if (array[first] > array[second]) {
                        return 1;
                    }
                    return 0;
                }
            });
        }

    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static interface id11 extends IntCollection {
    }

    static class IntArray extends id4 implements IntList {
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

    static interface IntList extends id11 {
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
                    return !removed && (at < size());
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

        default public IntList subList(final int from, final int to) {
            return new IntList() {
                private final int shift;
                private final int size;

                {
                    if ((from < 0) || (from > to) || (to > IntList.this.size())) {
                        throw new IndexOutOfBoundsException("from = " + from + ", to = " + to + ", size = " + size());
                    }
                    shift = from;
                    size = to - from;
                }

                public int size() {
                    return size;
                }

                public int get(int at) {
                    if ((at < 0) || (at >= size)) {
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
                    if ((at < 0) || (at >= size)) {
                        throw new IndexOutOfBoundsException("at = " + at + ", size = " + size());
                    }
                    IntList.this.set(at + shift, value);
                }

                public IntList compute() {
                    return new id12(this);
                }
            };
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id14 filter;

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

        public int readInt() {
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
                if ((c < '0') || (c > '9')) {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id3(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (id3(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id3(c));
            return res.toString();
        }

        public boolean id3(int c) {
            if (filter != null) {
                return filter.id3(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return (c == ' ') || (c == '\n') || (c == '\r') || (c == '\t') || (c == -1);
        }

        public interface id14 {
            public boolean id3(int ch);

        }

    }

    static abstract class id4 implements IntStream {

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

        public void printLine(long i) {
            writer.println(i);
        }

    }

    static class id12 extends id4 implements IntList {
        private int size;
        private int[] data;

        public id12() {
            this(3);
        }

        public id12(int capacity) {
            data = new int[capacity];
        }

        public id12(IntCollection c) {
            this(c.size());
            addAll(c);
        }

        public id12(IntStream c) {
            this();
            if (c instanceof IntCollection) {
                ensureCapacity(((IntCollection) c).size());
            }
            addAll(c);
        }

        public id12(id12 c) {
            size = c.size();
            data = c.data.clone();
        }

        public id12(int[] arr) {
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
            if ((index > size) || (index < 0)) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            if (index != size) {
                System.arraycopy(data, index, data, index + 1, size - index);
            }
            data[index] = value;
            size++;
        }

        public void removeAt(int index) {
            if ((index >= size) || (index < 0)) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            if (index != (size - 1)) {
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

    }

    static class IOUtils {
        public static void id7(InputReader in, int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = in.readInt();
                }
            }
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

    static interface IntStream extends Iterable<Integer>, Comparable<IntStream> {
        public IntIterator intIterator();

        default public Iterator<Integer> iterator() {
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

        default public int compareTo(IntStream c) {
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

    static class Sorter {
        private static final int id10 = 16;

        private Sorter() {
        }

        public static void sort(IntList list, IntComparator comparator) {
            quickSort(list, 0, list.size() - 1, (Integer.bitCount(Integer.highestOneBit(list.size()) - 1) * 5) >> 1,
                    comparator);
        }

        private static void quickSort(IntList list, int from, int to, int remaining, IntComparator comparator) {
            if ((to - from) < id10) {
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
            for (int i = ((to + from) - 1) >> 1; i >= from; i--) {
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
                if ((child + 1) <= end) {
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

    static interface IntComparator {
        public int compare(int first, int second);

    }
}
