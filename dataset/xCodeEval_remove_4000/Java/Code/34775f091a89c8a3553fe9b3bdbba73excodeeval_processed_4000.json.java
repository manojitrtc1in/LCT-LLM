import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.util.RandomAccess;
import java.io.PrintWriter;
import java.util.Random;
import java.util.AbstractList;
import java.util.AbstractCollection;
import java.io.Writer;
import java.util.Collection;
import java.util.Map;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.AbstractSet;
import java.util.Iterator;
import java.util.Set;
import java.util.AbstractMap;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskA {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int count = in.readInt();
        int k = in.readInt();
        int[] A = IOUtils.id0(in, count);

        ArrayUtils.safeSort(A);

        Set<Integer> answer = new id2<Integer>();

        for (int x : A) {
            if (x % k != 0 || (x % k == 0 && !answer.contains(x / k)))
                answer.add(x);
        }

        out.printLine(answer.size());
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
        while (id3(c))
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
        } while (!id3(c));
        return res * sgn;
    }

    public boolean id3(int c) {
        if (filter != null)
            return filter.id3(c);
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public interface id10 {
        public boolean id3(int ch);
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

class IOUtils {

    public static int[] id0(InputReader in, int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readInt();
        return array;
    }

}

class ArrayUtils {

    


    public static void safeSort(int[] array) {
        Collections.shuffle(asList(array));
        Arrays.sort(array);
    }

    private static List<Integer> asList(int[] array) {
        return new IntList(array);
    }

    private static class IntList extends AbstractList<Integer> implements RandomAccess {

        int[] array;

        private IntList(int[] array) {
            this.array = array;
        }

        public Integer get(int index) {
            return array[index];
        }

        public Integer set(int index, Integer element) {
            int result = array[index];
            array[index] = element;
            return result;
        }

        public int size() {
            return array.length;
        }
    }

    



}

class id2<E> extends AbstractSet<E> {
    private static final Object VALUE = new Object();
    private final Map<E, Object> map;

    public id2() {
        this(4);
    }

    public id2(int maxSize) {
        map = new id6<E, Object>(maxSize);
    }

    public id2(Collection<E> collection) {
        this(collection.size());
        addAll(collection);
    }

    public boolean contains(Object o) {
        return map.containsKey(o);
    }

    public boolean add(E e) {
        if (e == null)
            return false;
        return map.put(e, VALUE) == null;
    }

    public boolean remove(Object o) {
        if (o == null)
            return false;
        return map.remove(o) != null;
    }

    public void clear() {
        map.clear();
    }

    public Iterator<E> iterator() {
        return map.keySet().iterator();
    }

    public int size() {
        return map.size();
    }
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

abstract class IntList extends IntCollection implements Comparable<IntList> {
    private static final int id8 = 8;

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

    private void swap(int first, int second) {
        if (first == second)
            return;
        int temp = get(first);
        set(first, get(second));
        set(second, temp);
    }

    public id9 id7(IntComparator comparator) {
        quickSort(0, size() - 1, size(), comparator);
        return new id5(this, comparator);
    }

    private void quickSort(int from, int to, int remaining, IntComparator comparator) {
        if (to - from < id8) {
            id4(from, to, comparator);
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

    private void id4(int from, int to, IntComparator comparator) {
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

    public id9 sort(IntComparator comparator) {
        return new IntArray(this).id7(comparator);
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

    public id9 id7(IntComparator comparator) {
        if (comparator == this.comparator)
            return this;
        throw new UnsupportedOperationException();
    }

    public id9 sort(IntComparator comparator) {
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

class id6<E, V> extends AbstractMap<E, V> {
    private static final int[] shifts = new int[10];

    private int size;
    private Object[] keys;
    private Object[] values;
    private int capacity;
    private int shift;
    private int[] indices;
    private Set<Entry<E, V>> entrySet;

    static {
        Random random = new Random(System.currentTimeMillis());
        for (int i = 0; i < 10; i++)
            shifts[i] = 1 + 3 * i + random.nextInt(3);
    }

    public id6() {
        this(4);
    }

    private void setCapacity(int size) {
        capacity = Integer.highestOneBit(10 * size);
        keys = new Object[capacity];
        values = new Object[capacity];
        shift = capacity / 3 - 1;
        shift -= 1 - (shift & 1);
        indices = new int[capacity];
    }

    public id6(int maxSize) {
        setCapacity(maxSize);
        entrySet = new AbstractSet<Entry<E, V>>() {
            @Override
            public Iterator<Entry<E, V>> iterator() {
                return new Iterator<Entry<E, V>>() {
                    private HashEntry entry = new HashEntry();
                    int index = 0;

                    public boolean hasNext() {
                        while (index < size && keys[index] == null)
                            index++;
                        return index < size;
                    }

                    public Entry<E, V> next() {
                        if (!hasNext())
                            throw new NoSuchElementException();
                        entry.key = (E) keys[index];
                        entry.value = (V) values[index++];
                        return entry;
                    }

                    public void remove() {
                        if (entry.key == null)
                            throw new IllegalStateException();
                        id6.this.remove(entry.key);
                        entry.key = null;
                        entry.value = null;
                    }
                };
            }

            @Override
            public int size() {
                return size;
            }
        };
    }

    public id6(Map<E, V> map) {
        this(map.size());
        putAll(map);
    }

    public Set<Entry<E, V>> entrySet() {
        return entrySet;
    }

    public void clear() {
        Arrays.fill(keys, null);
        Arrays.fill(values, null);
        size = 0;
    }

    private int index(Object o) {
        return getHash(o.hashCode()) & (capacity - 1);
    }

    private int getHash(int h) {
        int result = h;
        for (int i : shifts)
            result ^= h >>> i;
        return result;
    }

    public V remove(Object o) {
        if (o == null)
            return null;
        int index = index(o);
        int indicesSize = 0;
        while (keys[index] != null && !keys[index].equals(o)) {
            indices[indicesSize++] = index;
            index = (index + shift) & (capacity - 1);
        }
        if (keys[index] == null)
            return null;
        size--;
        int lastIndex = indicesSize;
        indices[indicesSize++] = index;
        keys[index] = null;
        V result = (V) values[index];
        values[index] = null;
        index = (index + shift) & (capacity - 1);
        while (keys[index] != null) {
            int curKey = index(keys[index]);
            for (int i = 0; i <= lastIndex; i++) {
                if (indices[i] == curKey) {
                    keys[indices[lastIndex]] = keys[index];
                    values[indices[lastIndex]] = values[index];
                    keys[index] = null;
                    values[index] = null;
                    lastIndex = indicesSize;
                }
            }
            indices[indicesSize++] = index;
            index = (index + shift) & (capacity - 1);
        }
        return result;
    }

    public V put(E e, V value) {
        if (e == null)
            return null;
        int index = index(e);
        while (keys[index] != null && !keys[index].equals(e))
            index = (index + shift) & (capacity - 1);
        if (keys[index] == null)
            size++;
        keys[index] = e;
        values[index] = value;
        if (size * 2 > capacity) {
            Object[] oldKeys = keys;
            Object[] oldValues = values;
            setCapacity(size);
            size = 0;
            for (int i = 0; i < oldKeys.length; i++) {
                if (oldKeys[i] != null)
                    put((E) oldKeys[i], (V) oldValues[i]);
            }
        }
        return value;
    }

    public V get(Object o) {
        if (o == null)
            return null;
        int index = index(o);
        while (keys[index] != null && !keys[index].equals(o))
            index = (index + shift) & (capacity - 1);
        return (V) values[index];
    }

    public boolean containsKey(Object o) {
        if (o == null)
            return false;
        int index = index(o);
        while (keys[index] != null && !keys[index].equals(o))
            index = (index + shift) & (capacity - 1);
        return keys[index] != null;
    }

    public int size() {
        return size;
    }

    private class HashEntry implements Entry<E, V> {
        private E key;
        private V value;

        public E getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }

        public V setValue(V value) {
            put(key, value);
            return this.value = value;
        }
    }
}

class id5 extends id9 {
    private final int[] array;

    public id5(int[] array) {
        this(array, IntComparator.DEFAULT);
    }

    public id5(IntCollection collection) {
        this(collection, IntComparator.DEFAULT);
    }

    public id5(int[] array, IntComparator comparator) {
        super(comparator);
        this.array = array;
        ensureSorted();
    }

    public id5(IntCollection collection, IntComparator comparator) {
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

