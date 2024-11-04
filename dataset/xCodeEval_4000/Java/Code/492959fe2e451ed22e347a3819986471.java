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
    BXeniaIRaznotsvetnieKamushki solver = new BXeniaIRaznotsvetnieKamushki();
    solver.solve(1, in, out);
    out.close();
  }

  static class BXeniaIRaznotsvetnieKamushki {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int t = in.readInt();
      while (t-- > 0) {
        int[] n = in.readIntArray(3);
        int[][] a = new int[3][];
        for (int i = 0; i < 3; i++) a[i] = in.readIntArray(n[i]);
        long ans = fullSolve(a[0], a[1], a[2]);


        out.printLine(ans);
      }
    }

    long s(long v) {
      return v * v;
    }

    long f(long x, long y, long z) {
      return s(x - y) + s(x - z) + s(y - z);
    }

    long solve(int[] a, int[] b, int[] c) {
      long ans = Long.MAX_VALUE;
      int atB = 0;
      int atC = 0;
      for (int x : a) {
        while (atB < b.length && x > b[atB]) atB++;
        if (atB == b.length) break;
        while (atC < c.length && b[atB] > c[atC]) atC++;
        if (atC == c.length) break;
        int y = b[atB];
        int z = c[atC];
        int mid = x + z >> 1;
        int at = find(b, mid);
        if (0 <= at && at < b.length) ans = Math.min(ans, f(x, b[at], z));
        at++;
        if (0 <= at && at < b.length) ans = Math.min(ans, f(x, b[at], z));
      }
      return ans;
    }

    long fullSolve(int[] a, int[] b, int[] c) {
      a = unique(a);
      b = unique(b);
      c = unique(c);
      long[] ans = {
          solve(a, b, c),
          solve(a, c, b),
          solve(b, a, c),
          solve(b, c, a),
          solve(c, a, b),
          solve(c, b, a)
      };
      return ArrayUtils.minElement(ans);
    }

    int find(int[] a, int x) {
      int l = -1;
      int r = a.length;
      while (r - l > 1) {
        int m = l + r >> 1;
        if (a[m] <= x) l = m;
        else r = m;
      }
      return l;
    }

    int[] unique(int[] a) {
      ArrayUtils.sort(a = a.clone());
      int sz = 1;
      for (int i = 1; i < a.length; i++) if (a[i] != a[i - 1]) a[sz++] = a[i];
      return Arrays.copyOfRange(a, 0, sz);
    }

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

    public static long minElement(long[] array) {
      return new LongArray(array).min();
    }

  }

  static interface IntList extends IntReversableCollection {
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
          return new IntArrayList(this);
        }
      };
    }

  }

  static class IntArray extends IntAbstractStream implements IntList {
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

  static interface IntReversableCollection extends IntCollection {
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

  static interface LongCollection extends LongStream {
    public int size();

  }

  static interface LongStream extends Iterable<Long>, Comparable<LongStream> {
    public LongIterator longIterator();

    default public Iterator<Long> iterator() {
      return new Iterator<Long>() {
        private LongIterator it = longIterator();

        public boolean hasNext() {
          return it.isValid();
        }

        public Long next() {
          long result = it.value();
          it.advance();
          return result;
        }
      };
    }

    default public int compareTo(LongStream c) {
      LongIterator it = longIterator();
      LongIterator jt = c.longIterator();
      while (it.isValid() && jt.isValid()) {
        long i = it.value();
        long j = jt.value();
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

    default public long min() {
      long result = Long.MAX_VALUE;
      for (LongIterator it = longIterator(); it.isValid(); it.advance()) {
        long current = it.value();
        if (current < result) {
          result = current;
        }
      }
      return result;
    }

  }

  static interface IntIterator {
    public int value() throws NoSuchElementException;

    public boolean advance();

    public boolean isValid();

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
      if (to - from < INSERTION_THRESHOLD) {
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
      for (int i = (to + from - 1) >> 1; i >= from; i--) {
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

  static class LongArray extends LongAbstractStream implements LongList {
    private long[] data;

    public LongArray(long[] arr) {
      data = arr;
    }

    public int size() {
      return data.length;
    }

    public long get(int at) {
      return data[at];
    }

    public void removeAt(int index) {
      throw new UnsupportedOperationException();
    }

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

  static class InputReader {
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private InputReader.SpaceCharFilter filter;

    public InputReader(InputStream stream) {
      this.stream = stream;
    }

    public int[] readIntArray(int size) {
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
        if (c < '0' || c > '9') {
          throw new InputMismatchException();
        }
        res *= 10;
        res += c - '0';
        c = read();
      } while (!isSpaceChar(c));
      return res * sgn;
    }

    public boolean isSpaceChar(int c) {
      if (filter != null) {
        return filter.isSpaceChar(c);
      }
      return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
      return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public interface SpaceCharFilter {
      public boolean isSpaceChar(int ch);

    }

  }

  static interface LongList extends LongReversableCollection {
    public abstract long get(int index);

    public abstract void removeAt(int index);

    default public LongIterator longIterator() {
      return new LongIterator() {
        private int at;
        private boolean removed;

        public long value() {
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

  }

  static interface LongIterator {
    public long value() throws NoSuchElementException;

    public boolean advance();

    public boolean isValid();

  }

  static abstract class LongAbstractStream implements LongStream {
    public String toString() {
      StringBuilder builder = new StringBuilder();
      boolean first = true;
      for (LongIterator it = longIterator(); it.isValid(); it.advance()) {
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
      if (!(o instanceof LongStream)) {
        return false;
      }
      LongStream c = (LongStream) o;
      LongIterator it = longIterator();
      LongIterator jt = c.longIterator();
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
      for (LongIterator it = longIterator(); it.isValid(); it.advance()) {
        result *= 31;
        result += it.value();
      }
      return result;
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

  static interface LongReversableCollection extends LongCollection {
  }
}

