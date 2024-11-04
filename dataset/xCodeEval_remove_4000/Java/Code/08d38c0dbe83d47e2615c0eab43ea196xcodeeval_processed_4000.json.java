import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.Collection;
import java.io.IOException;
import java.io.Writer;
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

    static class TaskB {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            try {
                int n = in.readInt();
                int[] a = in.id0(n);
                int max = ArrayUtils.maxElement(a);
                int[] counter = new int[max + 1];
                int minIdx = 0;
                ArrayUtils.sort(a);
                int res = 0;
                id7[] toUpdate = new id7[max + 1];
                Arrays.setAll(toUpdate, i -> new id14());
                int idx = 0;
                for (int i = 1; i <= max; i++) {
                    for (int x : toUpdate[i].toArray()) {
                        int x_ = i - x;
                        counter[x_]--;
                        x_ = i + x;
                        if (x_ <= max) {
                            toUpdate[x_].add(x);
                        }
                        counter[i]++;
                    }
                    toUpdate[i].clear();
                    if (idx < n && a[idx] == i) {
                        if (2 * i <= max) {
                            toUpdate[2 * i].add(i);
                        }
                        counter[i]++;
                        while (counter[minIdx] == 0) {
                            minIdx++;
                        }
                        res = Math.max(res, i - minIdx);
                        while (idx < n && a[idx] == i) {
                            idx++;
                        }
                    }
                }
                out.printLine(res);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static class ArrayUtils {
        public static int[] sort(int[] array) {
            return sort(array, IntComparator.DEFAULT);
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

        public static int maxElement(int[] array) {
            return new IntArray(array).max();
        }

    }

    static interface id8 extends id2 {
        int size();

        id13 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id19 filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int[] id0(int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = readInt();
            }
            return array;
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
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id3(c));
            return res * sgn;
        }

        public boolean id3(int c) {
            if (filter != null) {
                return filter.id3(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface id19 {
            boolean id3(int ch);

        }

    }

    static interface id7 extends id2 {
        int size();

        id13 iterator();

        int[] toArray();

        boolean add(int element);

        void clear();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface id13 {
        boolean hasNext();

        int next();

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

    static class Sorter {
        private static final int id12 = 16;

        private Sorter() {
        }

        public static void sort(IntList list, IntComparator comparator) {
            quickSort(list, 0, list.size() - 1, (Integer.bitCount(Integer.highestOneBit(list.size()) - 1) * 5) >> 1,
                    comparator);
        }

        private static void quickSort(IntList list, int from, int to, int remaining, IntComparator comparator) {
            if (to - from < id12) {
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

    static class id14 implements id7, id8 {
        private static final int id17 = 10;
        private static final double id6 = 2.0;
        private static final int id11 = 0x811c9dc5;
        private static final int id18 = 0x01000193;
        private int[] array;
        private int size;

        public id14() {
            this(id17);
        }

        public id14(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            array = new int[capacity];
            size = 0;
        }

        public id14(id2 collection) {
            size = collection.size();
            array = new int[size];
            int i = 0;
            for (id13 iterator = collection.iterator(); iterator.hasNext(); ) {
                array[i++] = iterator.next();
            }
        }

        public id14(int[] srcArray) {
            size = srcArray.length;
            array = new int[size];
            System.arraycopy(srcArray, 0, array, 0, size);
        }

        public id14(Collection<Integer> javaCollection) {
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

        public id13 iterator() {
            return new id10();
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

        public void clear() {
            size = 0;
        }

        private void enlarge() {
            int newSize = Math.max(size + 1, (int) (size * id6));
            int[] newArray = new int[newSize];
            System.arraycopy(array, 0, newArray, 0, size);
            array = newArray;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id14 that = (id14) o;

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
            int hash = id11;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ id9.getHash(array[i])) * id18;
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

        private class id10 implements id13 {
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

    static final class id9 {
        private id9() {
        }

        public static int getHash(int x) {
            return x;
        }

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

    static interface IntComparator {
        IntComparator DEFAULT = Integer::compare;

        int compare(int first, int second);

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

        public void printLine(int i) {
            writer.println(i);
        }

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

        default int max() {
            int result = Integer.MIN_VALUE;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                int current = it.value();
                if (current > result) {
                    result = current;
                }
            }
            return result;
        }

    }

    static interface id15 extends IntCollection {
    }

    static class id16 extends id4 implements IntList {
        private int size;
        private int[] data;

        public id16() {
            this(3);
        }

        public id16(int capacity) {
            data = new int[capacity];
        }

        public id16(IntCollection c) {
            this(c.size());
            addAll(c);
        }

        public id16(IntStream c) {
            this();
            if (c instanceof IntCollection) {
                ensureCapacity(((IntCollection) c).size());
            }
            addAll(c);
        }

        public id16(id16 c) {
            size = c.size();
            data = c.data.clone();
        }

        public id16(int[] arr) {
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

    }

    static interface IntList extends id15 {
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
                    return new id16(this);
                }
            };
        }

    }

    static interface id2 {
        int size();

        id13 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface IntCollection extends IntStream {
        public int size();

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
}

