import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.Arrays;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.Comparator;


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
}

class TaskE {
    static final int id7 = 200;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int count = in.readInt();
        long[] base = new long[count];
        long[] max = new long[count];
        long[] rate = new long[count];
        IOUtils.id5(in, base, max, rate);
        int parts = (count + id7 - 1) / id7;
        long[] id6 = new long[parts];
        Arrays.fill(id6, -1);
        long[][] k = new long[parts][id7 + 1];
        long[][] b = new long[parts][id7 + 1];
        long[][] at = new long[parts][id7 + 1];
        int[] qty = new int[parts];
        int[] order = ArrayUtils.createOrder(id7);
        long[] endsIn = new long[count];
        for (int i = 0; i < count; i++) {
            if (rate[i] == 0) {
                endsIn[i] = Integer.MAX_VALUE;
            } else {
                endsIn[i] = (max[i] + rate[i] - 1) / rate[i];
            }
        }
        for (int i = 0; i < parts; i++) {
            final int shift = i * id7;
            if (shift + id7 > count) {
                order = ArrayUtils.createOrder(count - i * id7);
            }
            ArrayUtils.sort(order, new IntComparator() {
                @Override
                public int compare(int first, int second) {
                    return Long.compare(endsIn[first + shift], endsIn[second + shift]);
                }
            });
            long sumRate = 0;
            for (int j = shift; j < count && j < shift + id7; j++) {
                sumRate += rate[j];
            }
            long sumBase = 0;
            k[i][0] = sumRate;
            for (int j : order) {
                sumRate -= rate[j + shift];
                sumBase += max[j + shift];
                if (endsIn[j + shift] != at[i][qty[i]]) {
                    qty[i]++;
                }
                k[i][qty[i]] = sumRate;
                b[i][qty[i]] = sumBase;
                at[i][qty[i]] = endsIn[j + shift];
            }
            qty[i]++;
        }
        int queryCount = in.readInt();
        for (int i = 0; i < queryCount; i++) {
            long time = in.readLong();
            int from = in.readInt() - 1;
            int to = in.readInt() - 1;
            int fromPart = from / id7;
            int toPart = to / id7;
            long result = 0;
            if (id6[fromPart] != -1) {
                fixPart(base, rate, id6, fromPart);
            }
            if (fromPart == toPart) {
                for (int j = from; j <= to; j++) {
                    result += Math.min(base[j] + rate[j] * time, max[j]);
                    base[j] = -rate[j] * time;
                }
            } else {
                for (int j = from; j < (fromPart + 1) * id7; j++) {
                    result += Math.min(base[j] + rate[j] * time, max[j]);
                    base[j] = -rate[j] * time;
                }
                if (id6[toPart] != -1) {
                    fixPart(base, rate, id6, toPart);
                }
                for (int j = toPart * id7; j <= to; j++) {
                    result += Math.min(base[j] + rate[j] * time, max[j]);
                    base[j] = -rate[j] * time;
                }
                for (int j = fromPart + 1; j < toPart; j++) {
                    if (id6[j] == -1) {
                        for (int l = j * id7; l < (j + 1) * id7; l++) {
                            result += Math.min(base[l] + rate[l] * time, max[l]);
                        }
                    } else {
                        int position = Arrays.binarySearch(at[j], 0, qty[j], time - id6[j]);
                        if (position < 0) {
                            position = -position - 2;
                        }
                        result += k[j][position] * (time - id6[j]) + b[j][position];
                    }
                    id6[j] = time;
                }
            }
            out.printLine(result);
        }
    }

    protected void fixPart(long[] base, long[] rate, long[] id6, int part) {
        for (int j = part * id7; j < (part + 1) * id7; j++) {
            base[j] = -rate[j] * id6[part];
        }
        id6[part] = -1;
    }
}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private id10 filter;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    public int readInt() {
        int c = read();
        while (id1(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!id1(c));
        return res * sgn;
    }

    public long readLong() {
        int c = read();
        while (id1(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!id1(c));
        return res * sgn;
    }

    public boolean id1(int c) {
        if (filter != null)
            return filter.id1(c);
        return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public interface id10 {
        public boolean id1(int ch);
    }
}

class OutputWriter {
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

class IOUtils {

    public static void id5(InputReader in, long[]... arrays) {
        for (int i = 0; i < arrays[0].length; i++) {
            for (int j = 0; j < arrays.length; j++)
                arrays[j][i] = in.readLong();
        }
    }

}

class ArrayUtils {

    public static int[] createOrder(int size) {
        int[] order = new int[size];
        for (int i = 0; i < size; i++)
            order[i] = i;
        return order;
    }

    public static int[] sort(int[] array, IntComparator comparator) {
        return sort(array, 0, array.length, comparator);
    }

    public static int[] sort(int[] array, int from, int to, IntComparator comparator) {
        if (from == 0 && to == array.length)
            new IntArray(array).id4(comparator);
        else
            new IntArray(array).subList(from, to).id4(comparator);
        return array;
    }

}

interface IntComparator {
    public static final IntComparator DEFAULT = new IntComparator() {
        public int compare(int first, int second) {
            if (first < second)
                return -1;
            if (first > second)
                return 1;
            return 0;
        }
    };

    public int compare(int first, int second);
}

abstract class IntCollection {
    public abstract IntIterator iterator();
    public abstract int size();

}

interface IntIterator {
    public int value() throws NoSuchElementException;
    
    public void advance() throws NoSuchElementException;
    public boolean isValid();
}

abstract class IntList extends IntCollection implements Comparable<IntList> {
    private static final int id8 = 16;

    public abstract int get(int index);
    public abstract void set(int index, int value);

    public IntIterator iterator() {
        return new IntIterator() {
            private int size = size();
            private int index = 0;

            public int value() throws NoSuchElementException {
                if (!isValid())
                    throw new NoSuchElementException();
                return get(index);
            }

            public void advance() throws NoSuchElementException {
                if (!isValid())
                    throw new NoSuchElementException();
                index++;
            }

            public boolean isValid() {
                return index < size;
            }
        };
    }

    public IntList subList(final int from, final int to) {
        return new SubList(from, to);
    }

    private void swap(int first, int second) {
        if (first == second)
            return;
        int temp = get(first);
        set(first, get(second));
        set(second, temp);
    }

    public id9 id4(IntComparator comparator) {
        quickSort(0, size() - 1, (Integer.bitCount(Integer.highestOneBit(size()) - 1) * 5) >> 1, comparator);
        return new id3(this, comparator);
    }

    private void quickSort(int from, int to, int remaining, IntComparator comparator) {
        if (to - from < id8) {
            id2(from, to, comparator);
            return;
        }
        if (remaining == 0) {
            heapSort(from, to, comparator);
            return;
        }
        remaining--;
        int pivotIndex = (from + to) >> 1;
        int pivot = get(pivotIndex);
        swap(pivotIndex, to);
        int storeIndex = from;
        int equalIndex = to;
        for (int i = from; i < equalIndex; i++) {
            int value = comparator.compare(get(i), pivot);
            if (value < 0)
                swap(storeIndex++, i);
            else if (value == 0)
                swap(--equalIndex, i--);
        }
        quickSort(from, storeIndex - 1, remaining, comparator);
        for (int i = equalIndex; i <= to; i++)
            swap(storeIndex++, i);
        quickSort(storeIndex, to, remaining, comparator);
    }

    private void heapSort(int from, int to, IntComparator comparator) {
        for (int i = (to + from - 1) >> 1; i >= from; i--)
            id0(i, to, comparator, from);
        for (int i = to; i > from; i--) {
            swap(from, i);
            id0(from, i - 1, comparator, from);
        }
    }

    private void id0(int start, int end, IntComparator comparator, int delta) {
        int value = get(start);
        while (true) {
            int child = ((start - delta) << 1) + 1 + delta;
            if (child > end)
                return;
            int childValue = get(child);
            if (child + 1 <= end) {
                int otherValue = get(child + 1);
                if (comparator.compare(otherValue, childValue) > 0) {
                    child++;
                    childValue = otherValue;
                }
            }
            if (comparator.compare(value, childValue) >= 0)
                return;
            swap(start, child);
            start = child;
        }
    }

    private void id2(int from, int to, IntComparator comparator) {
        for (int i = from + 1; i <= to; i++) {
            int value = get(i);
            for (int j = i - 1; j >= from; j--) {
                if (comparator.compare(get(j), value) <= 0)
                    break;
                swap(j, j + 1);
            }
        }
    }

    public int hashCode() {
        int hashCode = 1;
        for (IntIterator i = iterator(); i.isValid(); i.advance())
            hashCode = 31 * hashCode + i.value();
        return hashCode;
    }

    public boolean equals(Object obj) {
        if (!(obj instanceof IntList))
            return false;
        IntList list = (IntList)obj;
        if (list.size() != size())
            return false;
        IntIterator i = iterator();
        IntIterator j = list.iterator();
        while (i.isValid()) {
            if (i.value() != j.value())
                return false;
            i.advance();
            j.advance();
        }
        return true;
    }

    public int compareTo(IntList o) {
        IntIterator i = iterator();
        IntIterator j = o.iterator();
        while (true) {
            if (i.isValid()) {
                if (j.isValid()) {
                    if (i.value() != j.value()) {
                        if (i.value() < j.value())
                            return -1;
                        else
                            return 1;
                    }
                } else
                    return 1;
            } else {
                if (j.isValid())
                    return -1;
                else
                    return 0;
            }
            i.advance();
            j.advance();
        }
    }

    private class SubList extends IntList {
        private final int to;
        private final int from;
        private int size;

        public SubList(int from, int to) {
            this.to = to;
            this.from = from;
            size = to - from;
        }

        public int get(int index) {
            if (index < 0 || index >= size)
                throw new IndexOutOfBoundsException();
            return IntList.this.get(index + from);
        }

        public void set(int index, int value) {
            if (index < 0 || index >= size)
                throw new IndexOutOfBoundsException();
            IntList.this.set(index + from, value);
        }

        public int size() {
            return size;
        }

    }
}

abstract class id9 extends IntList {
    protected final IntComparator comparator;

    protected id9(IntComparator comparator) {
        this.comparator = comparator;
    }

    public void set(int index, int value) {
        throw new UnsupportedOperationException();
    }

    public id9 id4(IntComparator comparator) {
        if (comparator == this.comparator)
            return this;
        throw new UnsupportedOperationException();
    }

    protected void ensureSorted() {
        int size = size();
        if (size == 0)
            return;
        int last = get(0);
        for (int i = 1; i < size; i++) {
            int current = get(i);
            if (comparator.compare(last, current) > 0)
                throw new IllegalArgumentException();
            last = current;
        }
    }

    public id9 subList(final int from, final int to) {
        return new id9(comparator) {
            private int size = to - from;

            @Override
            public int get(int index) {
                if (index < 0 || index >= size)
                    throw new IndexOutOfBoundsException();
                return id9.this.get(index + from);
            }

            @Override
            public int size() {
                return size;
            }
        };
    }
}

class IntArray extends IntList {
    private final int[] array;

    public IntArray(int[] array) {
        this.array = array;
    }

    public IntArray(IntCollection collection) {
        array = new int[collection.size()];
        int i = 0;
        for (IntIterator iterator = collection.iterator(); iterator.isValid(); iterator.advance())
            array[i++] = iterator.value();
    }

    public int get(int index) {
        return array[index];
    }

    public void set(int index, int value) {
        array[index] = value;
    }

    public int size() {
        return array.length;
    }

}

class id3 extends id9 {
    private final int[] array;

    public id3(int[] array) {
        this(array, IntComparator.DEFAULT);
    }

    public id3(IntCollection collection) {
        this(collection, IntComparator.DEFAULT);
    }

    public id3(int[] array, IntComparator comparator) {
        super(comparator);
        this.array = array;
        ensureSorted();
    }

    public id3(IntCollection collection, IntComparator comparator) {
        super(comparator);
        array = new int[collection.size()];
        int i = 0;
        for (IntIterator iterator = collection.iterator(); iterator.isValid(); iterator.advance())
            array[i++] = iterator.value();
        ensureSorted();
    }

    public int get(int index) {
        return array[index];
    }

    public int size() {
        return array.length;
    }
}