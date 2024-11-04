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
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n;
            int m;
            int k;
            int[][] x;
            int[][] y;
            int[][] cost;
            int[][] garland;
            int[][] lamp;
            long[][] partSumCost;

            n = in.readInt();
            m = in.readInt();
            k = in.readInt();
            x = new int[k][];
            y = new int[k][];
            cost = new int[k][];
            garland = new int[n][m];
            lamp = new int[n][m];
            ArrayUtils.fill(garland, -1);
            ArrayUtils.fill(lamp, -1);
            partSumCost = new long[k][];
            for (int g = 0; g < k; g++) {
                int len = in.readInt();
                x[g] = new int[len];
                y[g] = new int[len];
                cost[g] = new int[len];
                IOUtils.readIntArrays(in, x[g], y[g], cost[g]);
                MiscUtils.decreaseByOne(x[g], y[g]);
                for (int l = 0; l < len; l++) {
                    garland[x[g][l]][y[g][l]] = g;
                    lamp[x[g][l]][y[g][l]] = l;
                }
                partSumCost[g] = ArrayUtils.partialSums(cost[g]);
            }

            int q = in.readInt();
            boolean[] isOn = new boolean[k];
            Arrays.fill(isOn, true);
            IntArrayList[] poss = new IntArrayList[k];
            for (int i = 0; i < k; i++) {
                poss[i] = new IntArrayList(2000);
            }
            for (int iter = 0; iter < q; iter++) {
                String s = in.readString();
                if (s.charAt(0) == 'S') {
                    isOn[in.readInt() - 1] ^= true;
                } else {
                    int x0 = in.readInt() - 1;
                    int y0 = in.readInt() - 1;
                    int x1 = in.readInt() - 1;
                    int y1 = in.readInt() - 1;

                    for (int xx = x0; xx <= x1; xx++) {
                        if (garland[xx][y0] != -1) {
                            poss[garland[xx][y0]].add(lamp[xx][y0]);
                        }
                        if (garland[xx][y1] != -1 && y0 != y1) {
                            poss[garland[xx][y1]].add(lamp[xx][y1]);
                        }
                    }
                    for (int yy = y0 + 1; yy < y1; yy++) {
                        if (garland[x0][yy] != -1) {
                            poss[garland[x0][yy]].add(lamp[x0][yy]);
                        }
                        if (garland[x1][yy] != -1 && x0 != x1) {
                            poss[garland[x1][yy]].add(lamp[x1][yy]);
                        }
                    }

                    long answer = 0;
                    for (int g = 0; g < k; g++) {
                        if (!isOn[g]) {
                            continue;
                        }
                        poss[g] = new IntArrayList(poss[g].sort());

                        int len = x[g].length;
                        if ((poss[g].isEmpty() || poss[g].last() != len - 1) &&
                                isIn(x0, x[g][len - 1], x1, y0, y[g][len - 1], y1)) {
                            poss[g].add(len - 1);
                        }
                        if ((poss[g].isEmpty() || poss[g].first() != 0) &&
                                isIn(x0, x[g][0], x1, y0, y[g][0], y1)) {
                            poss[g].addAt(0, 0);
                        }




                        for (int j = 0; j < poss[g].size(); j++) {
                            int l = poss[g].get(j);
                            answer += cost[g][l];
                            if (j != 0) {
                                int prL = poss[g].get(j - 1);
                                if (prL + 1 != l && isIn(x0, x[g][prL + 1], x1, y0, y[g][prL + 1], y1)) {
                                    answer += partSumCost[g][l] - partSumCost[g][prL + 1];
                                    

                                }
                            }
                        }
                    }
                    out.printLine(answer);
                    for (int i = 0; i < k; i++) {
                        poss[i].clear();


                    }
                }
            }
        }

        private boolean isIn(int x0, int x, int x1, int y0, int y, int y1) {
            return x0 <= x && x <= x1 && y0 <= y && y <= y1;
        }

    }

    static class IntArrayList extends IntAbstractStream implements IntList {
        private int size;
        private int[] data;

        public IntArrayList() {
            this(3);
        }

        public IntArrayList(int capacity) {
            data = new int[capacity];
        }

        public IntArrayList(IntCollection c) {
            this(c.size());
            addAll(c);
        }

        public IntArrayList(IntStream c) {
            this();
            if (c instanceof IntCollection) {
                ensureCapacity(((IntCollection) c).size());
            }
            addAll(c);
        }

        public IntArrayList(IntArrayList c) {
            size = c.size();
            data = c.data.clone();
        }

        public IntArrayList(int[] arr) {
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

        public void clear() {
            size = 0;
        }

        public void set(int index, int value) {
            if (index >= size) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            data[index] = value;
        }

    }

    static class ArrayUtils {
        public static void fill(int[][] array, int value) {
            for (int[] row : array) {
                Arrays.fill(row, value);
            }
        }

        public static long[] partialSums(int[] array) {
            long[] result = new long[array.length + 1];
            for (int i = 0; i < array.length; i++) {
                result[i + 1] = result[i] + array[i];
            }
            return result;
        }

    }

    static class IOUtils {
        public static void readIntArrays(InputReader in, int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = in.readInt();
                }
            }
        }

    }

    static interface IntCollection extends IntStream {
        public int size();

        default public boolean isEmpty() {
            return size() == 0;
        }

        default public void add(int value) {
            throw new UnsupportedOperationException();
        }

        default public IntCollection addAll(IntStream values) {
            for (IntIterator it = values.intIterator(); it.isValid(); it.advance()) {
                add(it.value());
            }
            return this;
        }

    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

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

    static class MiscUtils {
        public static void decreaseByOne(int[]... arrays) {
            for (int[] array : arrays) {
                for (int i = 0; i < array.length; i++) {
                    array[i]--;
                }
            }
        }

    }

    static interface IntReversableCollection extends IntCollection {
    }

    static class Sorter {
        private static final int INSERTION_THRESHOLD = 16;

        private Sorter() {
        }

        public static void sort(IntList list, IntComparator comparator) {
            quickSort(list, 0, list.size() - 1, (Integer.bitCount(Integer.highestOneBit(list.size()) - 1) * 5) >> 1,
                    comparator);
        }

        private static void quickSort(IntList list, int from, int to, int remaining, IntComparator comparator) {
            if ((to - from) < INSERTION_THRESHOLD) {
                insertionSort(list, from, to, comparator);
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
                siftDown(list, i, to, comparator, from);
            }
            for (int i = to; i > from; i--) {
                list.swap(from, i);
                siftDown(list, from, i - 1, comparator, from);
            }
        }

        private static void siftDown(IntList list, int start, int end, IntComparator comparator, int delta) {
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

        private static void insertionSort(IntList list, int from, int to, IntComparator comparator) {
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

    static interface IntList extends IntReversableCollection {
        public abstract int get(int index);

        public abstract void set(int index, int value);

        public abstract void addAt(int index, int value);

        public abstract void removeAt(int index);

        default public int first() {
            return get(0);
        }

        default public int last() {
            return get(size() - 1);
        }

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

        default public IntList sort() {
            sort(IntComparator.DEFAULT);
            return this;
        }

        default public IntList sort(IntComparator comparator) {
            Sorter.sort(this, comparator);
            return this;
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

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
            while (isSpaceChar(c)) {
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
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return (c == ' ') || (c == '\n') || (c == '\r') || (c == '\t') || (c == -1);
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static abstract class IntAbstractStream implements IntStream {

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

    static interface IntComparator {
        public static final IntComparator DEFAULT = (first, second) -> {
            if (first < second) {
                return -1;
            }
            if (first > second) {
                return 1;
            }
            return 0;
        };

        public int compare(int first, int second);

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
}

