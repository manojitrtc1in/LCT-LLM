import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.util.RandomAccess;
import java.io.PrintWriter;
import java.util.AbstractList;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.util.Collections;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int id9 = in.readInt();
        int id6 = in.readInt();
        IntList attack = new id10();
        IntList defence = new id10();
        for (int i = 0; i < id9; i++) {
            if ("DEF".equals(in.readString()))
                defence.add(in.readInt());
            else
                attack.add(in.readInt());
        }
        int[] id12 = IOUtils.id0(in, id6);
        attack.id5(IntComparator.REVERSE);
        defence.id5();
        ArrayUtils.sort(id12, IntComparator.REVERSE);
        int answer = 0;
        for (int i = 1; i <= Math.min(attack.size(), id6); i++) {
            int current = 0;
            for (int j = 0; j < i; j++)
                current += id12[j];
            for (int j = attack.size() - i; j < attack.size(); j++)
                current -= attack.get(j);
            answer = Math.max(answer, current);
        }
        boolean[] killed = new boolean[id6];
        ArrayUtils.reverse(id12);
        int j = 0;
        for (int i : defence.toArray()) {
            while (j < id6 && i >= id12[j])
                j++;
            if (j == id6) {
                out.printLine(answer);
                return;
            }
            killed[j++] = true;
        }
        j = 0;
        int all = 0;
        for (int i = id6 - 1; i >= 0; i--) {
            if (killed[i])
                continue;
            if (j == attack.size())
                all += id12[i];
            else if (id12[i] < attack.get(j)) {
                out.printLine(answer);
                return;
            } else
                all += id12[i] - attack.get(j++);
        }
        answer = Math.max(answer, all);
        out.printLine(answer);
    }
}

class InputReader {
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private id11 filter;

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
        while (id2(c))
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
        } while (!id2(c));
        return res * sgn;
    }

    public boolean id2(int c) {
        if (filter != null)
            return filter.id2(c);
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public String readString() {
        int c = read();
        while (id2(c))
            c = read();
        StringBuffer res = new StringBuffer();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!id2(c));
        return res.toString();
    }

    public interface id11 {
        public boolean id2(int ch);
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

    public void print(Object...objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(objects[i]);
        }
    }

    public void printLine(Object...objects) {
        print(objects);
        writer.println();
    }

    public void close() {
        writer.close();
    }

}

abstract class IntList extends IntCollection implements Comparable<IntList> {
    private static final int id7 = 8;

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

    public id8 id5() {
        return id5(IntComparator.DEFAULT);
    }

    public id8 id5(IntComparator comparator) {
        quickSort(0, size() - 1, size(), comparator);
        return new id4(this, comparator);
    }

    private void quickSort(int from, int to, int remaining, IntComparator comparator) {
        if (to - from < id7) {
            id3(from, to, comparator);
            return;
        }
        if (remaining == 0) {
            heapSort(from, to, comparator);
            return;
        }
        remaining >>= 1;
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
            id1(i, to, comparator, from);
        for (int i = to; i > from; i--) {
            swap(from, i);
            id1(from, i - 1, comparator, from);
        }
    }

    private void id1(int start, int end, IntComparator comparator, int delta) {
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

    private void id3(int from, int to, IntComparator comparator) {
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

    public id8 sort(IntComparator comparator) {
        return new IntArray(this).id5(comparator);
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

        public void add(int value) {
            throw new UnsupportedOperationException();
            

        }

    }
}

class id10 extends IntList {
    private int[] array;
    private int size;

    public id10() {
        this(10);
    }

    public id10(int capacity) {
        array = new int[capacity];
    }

    public id10(IntList list) {
        this(list.size());
        addAll(list);
    }

    public int get(int index) {
        if (index >= size)
            throw new IndexOutOfBoundsException();
        return array[index];
    }

    public void set(int index, int value) {
        if (index >= size)
            throw new IndexOutOfBoundsException();
        array[index] = value;
    }

    public int size() {
        return size;
    }

    public void add(int value) {
        ensureCapacity(size + 1);
        array[size++] = value;
    }

    private void ensureCapacity(int newCapacity) {
        if (newCapacity > array.length) {
            int[] newArray = new int[Math.max(newCapacity, array.length << 1)];
            System.arraycopy(array, 0, newArray, 0, size);
            array = newArray;
        }
    }

    public int[] toArray() {
        int[] array = new int[size];
        System.arraycopy(this.array, 0, array, 0, size);
        return array;
    }
}

abstract class IntCollection {
    public abstract IntIterator iterator();
    public abstract int size();
    public abstract void add(int value);

    public int[] toArray() {
        int size = size();
        int[] array = new int[size];
        int i = 0;
        for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance())
            array[i++] = iterator.value();
        return array;
    }

    public void addAll(IntCollection values) {
        for (IntIterator it = values.iterator(); it.isValid(); it.advance()) {
            add(it.value());
        }
    }
}

class IOUtils {

    public static int[] id0(InputReader in, int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readInt();
        return array;
    }

    }

abstract class id8 extends IntList {
    protected final IntComparator comparator;

    protected id8(IntComparator comparator) {
        this.comparator = comparator;
    }

    public void set(int index, int value) {
        throw new UnsupportedOperationException();
    }

    public void add(int value) {
        throw new UnsupportedOperationException();
    }

    public id8 id5(IntComparator comparator) {
        if (comparator == this.comparator)
            return this;
        throw new UnsupportedOperationException();
    }

    public id8 sort(IntComparator comparator) {
        if (comparator == this.comparator)
            return this;
        return super.sort(comparator);
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

    public id8 subList(final int from, final int to) {
        return new id8(comparator) {
            private int size = to - from;

            @Override
            public int get(int index) {
                if (index < 0 || index >= size)
                    throw new IndexOutOfBoundsException();
                return id8.this.get(index + from);
            }

            @Override
            public int size() {
                return size;
            }

            @Override
            public void add(int value) {
                

            }
        };
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

    public static final IntComparator REVERSE = new IntComparator() {
        public int compare(int first, int second) {
            if (first < second)
                return 1;
            if (first > second)
                return -1;
            return 0;
        }
    };

    public int compare(int first, int second);
}

class ArrayUtils {

    public static int[] sort(int[] array, IntComparator comparator) {
        return sort(array, 0, array.length, comparator);
    }

    public static int[] sort(int[] array, int from, int to, IntComparator comparator) {
        new IntArray(array).subList(from, to).id5(comparator);






        return array;
    }

    public static void reverse(int[] array) {
        for (int i = 0, j = array.length - 1; i < j; i++, j--) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    


    }

interface IntIterator {
    public int value() throws NoSuchElementException;
    
    public void advance() throws NoSuchElementException;
    public boolean isValid();
}

class id4 extends id8 {
    private final int[] array;

    public id4(int[] array) {
        this(array, IntComparator.DEFAULT);
    }

    public id4(IntCollection collection) {
        this(collection, IntComparator.DEFAULT);
    }

    public id4(int[] array, IntComparator comparator) {
        super(comparator);
        this.array = array;
        ensureSorted();
    }

    public id4(IntCollection collection, IntComparator comparator) {
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

    public void add(int value) {
        throw new UnsupportedOperationException();
    }

    public int[] toArray() {
        return array;
    }
}
