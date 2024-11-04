import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.Set;
import java.io.IOException;
import java.util.List;
import java.util.TreeMap;
import java.io.Writer;
import java.io.InputStream;


public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    OutputWriter out = new OutputWriter(outputStream);
    DRecoverIt solver = new DRecoverIt();
    solver.solve(1, in, out);
    out.close();
  }

  static class DRecoverIt {
    public void solve(int testNumber, InputReader in, OutputWriter out) {

      int n = in.readInt();
      int[] seq = ArrayUtils.sort(in.readIntArray(n * 2));

      boolean[] table = new boolean[5000000];

      Arrays.fill(table, true);

      TreeCounter<Integer> counter = new TreeCounter<>();

      for (int e : seq) counter.add(e);

      for (int i = 2; i * i < table.length; ++i)
        if (table[i]) for (int j = i * i; j < table.length; j += i) table[j] = false;

      List<Integer> primes = new ArrayList<>();

      for (int i = 2; i < table.length; ++i) if (table[i]) primes.add(i);

      Object[] keys = counter.keySet().toArray();

      for (int i = keys.length - 1; i >= 0; --i) {
        int key = (int) keys[i];
        long cnt = counter.getOrDefault(key, 0L);
        if (cnt > 0 && !table[key]) {
          LongList divs = IntegerUtils.getDivisors(key).sort();
          int maxDiv = (int) divs.get(divs.size() - 2);

          for (int j = 0; j < cnt; ++j) {
            if (!counter.containsKey(maxDiv))
              throw new RuntimeException(maxDiv + " does not exist");
            counter.remove(maxDiv, 1L);
          }
        }
      }

      for (Object i : keys) {
        int key = (int) i;
        long cnt = counter.getOrDefault(key, 0L);
        if (cnt > 0 && table[key]) {
          int prime = primes.get(key - 1);

          for (int j = 0; j < cnt; ++j) {
            if (!counter.containsKey(prime)) throw new RuntimeException(prime + " does not exist");
            counter.remove(prime, 1L);
          }
        }
      }

      List<Integer> ans = new ArrayList<>();

      for (int e : counter.keySet()) {

        int cnt = counter.get(e).intValue();
        for (int i = 0; i < cnt; ++i) ans.add(e);
      }

      out.printLine(ans.toArray());
    }
  }

  static interface LongReversableCollection extends LongCollection {}

  static interface IntReversableCollection extends IntCollection {}

  abstract static class LongAbstractStream implements LongStream {
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

  static interface LongStream extends Iterable<Long>, Comparable<LongStream> {
    public LongIterator longIterator();

    public default Iterator<Long> iterator() {
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

    public default int compareTo(LongStream c) {
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

  static interface IntCollection extends IntStream {
    public int size();

    public default void add(int value) {
      throw new UnsupportedOperationException();
    }

    public default IntCollection addAll(IntStream values) {
      for (IntIterator it = values.intIterator(); it.isValid(); it.advance()) {
        add(it.value());
      }
      return this;
    }
  }

  static interface LongComparator {
    public static final LongComparator DEFAULT =
        (first, second) -> {
          if (first < second) {
            return -1;
          }
          if (first > second) {
            return 1;
          }
          return 0;
        };

    public int compare(long first, long second);
  }

  static class TreeCounter<K> extends TreeMap<K, Long> {
    public TreeCounter() {
      super();
    }

    public void add(K key) {
      put(key, get(key) + 1);
    }

    public Long remove(K key, Long delta) {
      if (!containsKey(key)) {
        return -1L;
      }
      Long curVal = get(key) - delta;
      if (curVal <= 0L) {
        remove(key);
      } else {
        put(key, curVal);
      }
      return curVal;
    }

    public Long get(Object key) {
      if (containsKey(key)) {
        return super.get(key);
      }
      return 0L;
    }
  }

  static class Sorter {
    private static final int INSERTION_THRESHOLD = 16;

    private Sorter() {}

    public static void sort(IntList list, IntComparator comparator) {
      quickSort(
          list,
          0,
          list.size() - 1,
          (Integer.bitCount(Integer.highestOneBit(list.size()) - 1) * 5) >> 1,
          comparator);
    }

    private static void quickSort(
        IntList list, int from, int to, int remaining, IntComparator comparator) {
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

    private static void siftDown(
        IntList list, int start, int end, IntComparator comparator, int delta) {
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

    public static void sort(LongList list, LongComparator comparator) {
      quickSort(
          list,
          0,
          list.size() - 1,
          (Integer.bitCount(Integer.highestOneBit(list.size()) - 1) * 5) >> 1,
          comparator);
    }

    private static void quickSort(
        LongList list, int from, int to, int remaining, LongComparator comparator) {
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
      long pivot = list.get(pivotIndex);
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

    private static void heapSort(LongList list, int from, int to, LongComparator comparator) {
      for (int i = (to + from - 1) >> 1; i >= from; i--) {
        siftDown(list, i, to, comparator, from);
      }
      for (int i = to; i > from; i--) {
        list.swap(from, i);
        siftDown(list, from, i - 1, comparator, from);
      }
    }

    private static void siftDown(
        LongList list, int start, int end, LongComparator comparator, int delta) {
      long value = list.get(start);
      while (true) {
        int child = ((start - delta) << 1) + 1 + delta;
        if (child > end) {
          return;
        }
        long childValue = list.get(child);
        if (child + 1 <= end) {
          long otherValue = list.get(child + 1);
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

    private static void insertionSort(LongList list, int from, int to, LongComparator comparator) {
      for (int i = from + 1; i <= to; i++) {
        long value = list.get(i);
        for (int j = i - 1; j >= from; j--) {
          if (comparator.compare(list.get(j), value) <= 0) {
            break;
          }
          list.swap(j, j + 1);
        }
      }
    }
  }

  static interface LongCollection extends LongStream {
    public int size();

    public default void add(long value) {
      throw new UnsupportedOperationException();
    }

    public default LongCollection addAll(LongStream values) {
      for (LongIterator it = values.longIterator(); it.isValid(); it.advance()) {
        add(it.value());
      }
      return this;
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
  }

  static class LongIntPair implements Comparable<LongIntPair> {
    public final long first;
    public final int second;

    public static LongIntPair makePair(long first, int second) {
      return new LongIntPair(first, second);
    }

    public LongIntPair(long first, int second) {
      this.first = first;
      this.second = second;
    }

    public boolean equals(Object o) {
      if (this == o) {
        return true;
      }
      if (o == null || getClass() != o.getClass()) {
        return false;
      }

      LongIntPair pair = (LongIntPair) o;

      return first == pair.first && second == pair.second;
    }

    public int hashCode() {
      int result = Long.hashCode(first);
      result = 31 * result + Integer.hashCode(second);
      return result;
    }

    public String toString() {
      return "(" + first + "," + second + ")";
    }

    public int compareTo(LongIntPair o) {
      int value = Long.compare(first, o.first);
      if (value != 0) {
        return value;
      }
      return Integer.compare(second, o.second);
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

  static interface IntList extends IntReversableCollection {
    public abstract int get(int index);

    public abstract void set(int index, int value);

    public abstract void addAt(int index, int value);

    public abstract void removeAt(int index);

    public default void swap(int first, int second) {
      if (first == second) {
        return;
      }
      int temp = get(first);
      set(first, get(second));
      set(second, temp);
    }

    public default IntIterator intIterator() {
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

    public default void add(int value) {
      addAt(size(), value);
    }

    public default IntList sort(IntComparator comparator) {
      Sorter.sort(this, comparator);
      return this;
    }

    public default IntList subList(final int from, final int to) {
      return new IntList() {
        private final int shift;
        private final int size;

        {
          if (from < 0 || from > to || to > IntList.this.size()) {
            throw new IndexOutOfBoundsException(
                "from = " + from + ", to = " + to + ", size = " + size());
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

  abstract static class IntAbstractStream implements IntStream {
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
  }

  static class IntegerUtils {
    public static List<LongIntPair> factorize(long number) {
      List<LongIntPair> result = new ArrayList<>();
      for (long i = 2; i * i <= number; i++) {
        if (number % i == 0) {
          int power = 0;
          do {
            power++;
            number /= i;
          } while (number % i == 0);
          result.add(LongIntPair.makePair(i, power));
        }
      }
      if (number != 1) {
        result.add(LongIntPair.makePair(number, 1));
      }
      return result;
    }

    public static LongList getDivisors(long number) {
      List<LongIntPair> primeDivisors = factorize(number);
      return getDivisorsImpl(primeDivisors, 0, 1, new LongArrayList());
    }

    private static LongList getDivisorsImpl(
        List<LongIntPair> primeDivisors, int index, long current, LongList result) {
      if (index == primeDivisors.size()) {
        result.add(current);
        return result;
      }
      long p = primeDivisors.get(index).first;
      int power = primeDivisors.get(index).second;
      for (int i = 0; i <= power; i++) {
        getDivisorsImpl(primeDivisors, index + 1, current, result);
        current *= p;
      }
      return result;
    }
  }

  static interface IntStream extends Iterable<Integer>, Comparable<IntStream> {
    public IntIterator intIterator();

    public default Iterator<Integer> iterator() {
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

    public default int compareTo(IntStream c) {
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

  static interface LongList extends LongReversableCollection {
    public abstract long get(int index);

    public abstract void set(int index, long value);

    public abstract void addAt(int index, long value);

    public abstract void removeAt(int index);

    public default void swap(int first, int second) {
      if (first == second) {
        return;
      }
      long temp = get(first);
      set(first, get(second));
      set(second, temp);
    }

    public default LongIterator longIterator() {
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

    public default void add(long value) {
      addAt(size(), value);
    }

    public default LongList sort() {
      sort(LongComparator.DEFAULT);
      return this;
    }

    public default LongList sort(LongComparator comparator) {
      Sorter.sort(this, comparator);
      return this;
    }
  }

  static interface LongIterator {
    public long value() throws NoSuchElementException;

    public boolean advance();

    public boolean isValid();
  }

  static interface IntComparator {
    public static final IntComparator DEFAULT =
        (first, second) -> {
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

  static class LongArrayList extends LongAbstractStream implements LongList {
    private int size;
    private long[] data;

    public LongArrayList() {
      this(3);
    }

    public LongArrayList(int capacity) {
      data = new long[capacity];
    }

    public LongArrayList(LongCollection c) {
      this(c.size());
      addAll(c);
    }

    public LongArrayList(LongStream c) {
      this();
      if (c instanceof LongCollection) {
        ensureCapacity(((LongCollection) c).size());
      }
      addAll(c);
    }

    public LongArrayList(LongArrayList c) {
      size = c.size();
      data = c.data.clone();
    }

    public LongArrayList(long[] arr) {
      size = arr.length;
      data = arr.clone();
    }

    public int size() {
      return size;
    }

    public long get(int at) {
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

    public void addAt(int index, long value) {
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

    public void set(int index, long value) {
      if (index >= size) {
        throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
      }
      data[index] = value;
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

  static interface IntIterator {
    public int value() throws NoSuchElementException;

    public boolean advance();

    public boolean isValid();
  }
}
