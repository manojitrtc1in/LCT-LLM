import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.List;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Collections;
import java.util.Iterator;
import java.io.IOException;
import java.util.Arrays;
import java.util.AbstractList;
import java.io.InputStream;
import java.util.Random;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.util.AbstractMap;
import java.util.Comparator;
import java.util.AbstractSet;
import java.util.Set;
import java.util.RandomAccess;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskTam solver = new TaskTam();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskTam {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int count = in.readInt();
        int bugCount = in.readInt();
        int maxCredits = in.readInt();
        int[] bugs = IOUtils.readIntArray(in, bugCount);
        int[] skill = IOUtils.readIntArray(in, count);
        int[] price = IOUtils.readIntArray(in, count);
        int[] bugOrder = ArrayUtils.order(bugs);
        int[] skillOrder = ArrayUtils.order(skill);
        int minDays = 1;
        int maxDays = bugCount + 1;
        while (minDays < maxDays) {
            int days = (minDays + maxDays) >> 1;
            if (solve(bugs, bugOrder, skill, price, skillOrder, maxCredits, days) == null)
                minDays = days + 1;
            else
                maxDays = days;
        }
        if (minDays == bugCount + 1)
            out.printLine("NO");
        else {
            out.printLine("YES");
            out.printLine(solve(bugs, bugOrder, skill, price, skillOrder, maxCredits, minDays));
        }
    }

    private int[] solve(int[] bugs, int[] bugOrder, int[] skill, final int[] price, int[] skillOrder, int maxCredits, int days) {
        int current = bugs.length - 1;
        int student = skillOrder.length - 1;
        Heap heap = new Heap(new IntComparator() {
            public int compare(int first, int second) {
                return price[first] - price[second];
            }
        }, skill.length);
        int[] result = new int[bugs.length];
        while (current >= 0 && maxCredits >= 0) {
            while (student >= 0 && skill[skillOrder[student]] >= bugs[bugOrder[current]]) {
                heap.add(skillOrder[student--]);
            }
            if (heap.isEmpty())
                return null;
            int cheapest = heap.poll();
            maxCredits -= price[cheapest];
            current -= days;
            for (int i = Math.max(current + 1, 0); i <= current + days; i++)
                result[bugOrder[i]] = cheapest + 1;
        }
        if (maxCredits < 0)
            return null;
        return result;
    }
}

class InputReader {
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private SpaceCharFilter filter;

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
        while (isSpaceChar(c))
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
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public boolean isSpaceChar(int c) {
        if (filter != null)
            return filter.isSpaceChar(c);
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public interface SpaceCharFilter {
        public boolean isSpaceChar(int ch);
    }

}

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public void print(int[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(array[i]);
        }
    }

    public void printLine(int[] array) {
        print(array);
        writer.println();
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

class IOUtils {

    public static int[] readIntArray(InputReader in, int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readInt();
        return array;
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
            new IntArray(array).inPlaceSort(comparator);
        else
            new IntArray(array).subList(from, to).inPlaceSort(comparator);
        return array;
    }

    public static int[] order(final int[] array) {
        return sort(createOrder(array.length), new IntComparator() {
            public int compare(int first, int second) {
                if (array[first] < array[second])
                    return -1;
                if (array[first] > array[second])
                    return 1;
                return 0;
            }
        });
    }

    


    



}

class Heap {
    private IntComparator comparator;
    private int size = 0;
    private int[] elements;
    private int[] at;

    public Heap(IntComparator comparator, int maxElement) {
        this(10, comparator, maxElement);
    }

    public Heap(int capacity, IntComparator comparator, int maxElement) {
        this.comparator = comparator;
        elements = new int[capacity];
        at = new int[maxElement];
        Arrays.fill(at, -1);
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int add(int element) {
        ensureCapacity(size + 1);
        elements[size] = element;
        at[element] = size;
        shiftUp(size++);
        return at[element];
    }

    public void shiftUp(int index) {




        int value = elements[index];
        while (index != 0) {
            int parent = (index - 1) >>> 1;
            int parentValue = elements[parent];
            if (comparator.compare(parentValue, value) <= 0) {
                elements[index] = value;
                at[value] = index;
                return;
            }
            elements[index] = parentValue;
            at[parentValue] = index;
            index = parent;
        }
        elements[0] = value;
        at[value] = 0;
    }

    public void shiftDown(int index) {
        if (index < 0 || index >= size)
            throw new IllegalArgumentException();
        while (true) {
            int child = (index << 1) + 1;
            if (child >= size)
                return;
            if (child + 1 < size && comparator.compare(elements[child], elements[child + 1]) > 0)
                child++;
            if (comparator.compare(elements[index], elements[child]) <= 0)
                return;
            swap(index, child);
            index = child;
        }
    }

    private void swap(int first, int second) {
        int temp = elements[first];
        elements[first] = elements[second];
        elements[second] = temp;
        at[elements[first]] = first;
        at[elements[second]] = second;
    }

    private void ensureCapacity(int size) {
        if (elements.length < size) {
            int[] oldElements = elements;
            elements = new int[Math.max(2 * elements.length, size)];
            System.arraycopy(oldElements, 0, elements, 0, this.size);
        }
    }

    public int poll() {
        if (isEmpty())
            throw new IndexOutOfBoundsException();
        int result = elements[0];
        at[result] = -1;
        if (size == 1) {
            size = 0;
            return result;
        }
        elements[0] = elements[--size];
        at[elements[0]] = 0;
        shiftDown(0);
        return result;
    }

}

interface IntComparator {

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
    private static final int INSERTION_THRESHOLD = 8;

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

    public IntSortedList inPlaceSort(IntComparator comparator) {
        quickSort(0, size() - 1, size(), comparator);
        return new IntSortedArray(this, comparator);
    }

    private void quickSort(int from, int to, int remaining, IntComparator comparator) {
        if (to - from < INSERTION_THRESHOLD) {
            insertionSort(from, to, comparator);
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
            siftDown(i, to, comparator, from);
        for (int i = to; i > from; i--) {
            swap(from, i);
            siftDown(from, i - 1, comparator, from);
        }
    }

    private void siftDown(int start, int end, IntComparator comparator, int delta) {
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

    private void insertionSort(int from, int to, IntComparator comparator) {
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

    public IntSortedList sort(IntComparator comparator) {
        return new IntArray(this).inPlaceSort(comparator);
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

abstract class IntSortedList extends IntList {
    protected final IntComparator comparator;

    protected IntSortedList(IntComparator comparator) {
        this.comparator = comparator;
    }

    public void set(int index, int value) {
        throw new UnsupportedOperationException();
    }

    public IntSortedList inPlaceSort(IntComparator comparator) {
        if (comparator == this.comparator)
            return this;
        throw new UnsupportedOperationException();
    }

    public IntSortedList sort(IntComparator comparator) {
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

    public IntSortedList subList(final int from, final int to) {
        return new IntSortedList(comparator) {
            private int size = to - from;

            public int get(int index) {
                if (index < 0 || index >= size)
                    throw new IndexOutOfBoundsException();
                return IntSortedList.this.get(index + from);
            }

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

class IntSortedArray extends IntSortedList {
    private final int[] array;

    public IntSortedArray(IntCollection collection, IntComparator comparator) {
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