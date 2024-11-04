import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.Random;
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
    TaskD solver = new TaskD();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskD {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
      int n = in.readInt();
      long[] a = IOUtils.id10(in, n);
      int m = in.readInt();
      int[] from = new int[m];
      int[] to = new int[m];
      IOUtils.id12(in, from, to);
      MiscUtils.id9(from, to);

      int[] index = ArrayUtils.createOrder(m);
      ArrayUtils.orderBy(to, from, index);
      long[] answer = new long[m];

      id11 id4 = new id11(a);
      id2 id7 = new id2(n);
      id18 lastIndex = new id18(n);

      int j = 0;
      for (int i = 0; i < n; i++) {
        int ai = (int) a[i];
        if (lastIndex.contains(ai)) {
          int li = lastIndex.get(ai);
          id7.add(li, ai);
        }
        lastIndex.put(ai, i);
        id7.add(i, ai);

        while (j < m && to[j] == i) {
          answer[index[j]] = id7.query(from[j], to[j]) ^ id4.query(from[j], to[j]);
          j++;
        }
      }

      for (j = 0; j < m; j++) {
        out.printLine(answer[j]);
      }
    }

    private class id11 {
      private final long[] array;

      public id11(long[] a) {
        this.array = a.clone();
        for (int i = 1; i < array.length; i++) {
          this.array[i] ^= this.array[i - 1];
        }
      }

      public long query(int from, int to) {
        if (to >= this.array.length) {
          to = this.array.length - 1;
        }
        if (from <= 0) {
          return this.array[to];
        }
        return this.array[to] ^ this.array[from - 1];
      }

    }

    private class id2 {
      private final long[] value;

      public id2(int size) {
        value = new long[size];
      }

      public long query(int from, int to) {
        return get(to) ^ get(from - 1);
      }

      private long get(int to) {
        to = Math.min(to, value.length - 1);
        long result = 0;
        while (to >= 0) {
          result ^= value[to];
          to = (to & (to + 1)) - 1;
        }
        return result;
      }

      public void add(int at, long value) {
        while (at < this.value.length) {
          this.value[at] ^= value;
          at = at | (at + 1);
        }
      }

    }

  }

  static class IntegerUtils {
    public static int gcd(int a, int b) {
      a = Math.abs(a);
      b = Math.abs(b);
      while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
      }
      return a;
    }

  }

  static interface IntComparator {
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

  static class id8 extends id16 {
    private final int[] array;

    public id8(int[] array) {
      this(array, IntComparator.DEFAULT);
    }

    public id8(IntCollection collection) {
      this(collection, IntComparator.DEFAULT);
    }

    public id8(int[] array, IntComparator comparator) {
      super(comparator);
      this.array = array;
      ensureSorted();
    }

    public id8(IntCollection collection, IntComparator comparator) {
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

  static class ArrayUtils {
    private static int[] tempInt = new int[0];

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
        new IntArray(array).id14(comparator);
      else
        new IntArray(array).subList(from, to).id14(comparator);
      return array;
    }

    private static void id0(int size) {
      if (tempInt.length >= size)
        return;
      size = Math.max(size, tempInt.length << 1);
      tempInt = new int[size];
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

    public static void orderBy(int[] base, int[]... arrays) {
      int[] order = ArrayUtils.order(base);
      order(order, base);
      for (int[] array : arrays)
        order(order, array);
    }

    public static void order(int[] order, int[] array) {
      id0(order.length);
      for (int i = 0; i < order.length; i++)
        tempInt[i] = array[order[i]];
      System.arraycopy(tempInt, 0, array, 0, array.length);
    }

  }

  static abstract class id16 extends IntList {
    protected final IntComparator comparator;

    protected id16(IntComparator comparator) {
      this.comparator = comparator;
    }


    public void set(int index, int value) {
      throw new UnsupportedOperationException();
    }


    public id16 id14(IntComparator comparator) {
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


    public id16 subList(final int from, final int to) {
      return new id16(comparator) {
        private int size = to - from;


        public int get(int index) {
          if (index < 0 || index >= size)
            throw new IndexOutOfBoundsException();
          return id16.this.get(index + from);
        }


        public int size() {
          return size;
        }
      };
    }

  }

  static interface IntIterator {
    public int value() throws NoSuchElementException;

    public void advance() throws NoSuchElementException;

    public boolean isValid();

  }

  static class id18 extends IntSet {
    private static final Random RND = new Random();
    private static final int[] id13 = new int[4];
    private static final byte id1 = 1;
    private int size;
    private int realSize;
    private int[] keys;
    private int[] values;
    private byte[] present;
    private int step;
    private int ratio;

    static {
      for (int i = 0; i < 4; i++)
        id13[i] = RND.nextInt(31) + 1;
    }

    public id18() {
      this(3);
    }

    public id18(int capacity) {
      capacity = Math.max(capacity, 1);
      keys = new int[capacity];
      present = new byte[capacity];
      values = new int[capacity];
      ratio = 2;
      initStep(capacity);
    }

    private void initStep(int capacity) {
      step = RND.nextInt(capacity - 2) + 1;
      while (IntegerUtils.gcd(step, capacity) != 1)
        step++;
    }


    public IntIterator iterator() {
      return new IntIterator() {
        private int position = size == 0 ? keys.length : -1;

        public int value() throws NoSuchElementException {
          if (position == -1)
            advance();
          if (position >= keys.length)
            throw new NoSuchElementException();
          return keys[position];
        }

        public void advance() throws NoSuchElementException {
          if (position >= keys.length)
            throw new NoSuchElementException();
          position++;
          while (position < keys.length && (present[position] & id1) == 0)
            position++;
        }

        public boolean isValid() {
          return position < keys.length;
        }
      };
    }


    public int size() {
      return size;
    }

    public void put(int key, int value) {
      ensureCapacity((realSize + 1) * ratio + 2);
      int current = getHash(key);
      while (present[current] != 0) {
        if ((present[current] & id1) != 0 && keys[current] == key) {
          values[current] = value;
          return;
        }
        current += step;
        if (current >= values.length)
          current -= values.length;
      }
      while ((present[current] & id1) != 0) {
        current += step;
        if (current >= keys.length)
          current -= keys.length;
      }
      if (present[current] == 0) {
        realSize++;
      }
      present[current] = id1;
      keys[current] = key;
      values[current] = value;
      size++;
    }

    private int getHash(int key) {
      int result = key;
      for (int i : id13)
        result ^= key >> i;
      result %= keys.length;
      if (result < 0)
        result += keys.length;
      return result;
    }

    private void ensureCapacity(int capacity) {
      if (keys.length < capacity) {
        capacity = Math.max(capacity * 2, keys.length);
        rebuild(capacity);
      }
    }

    private void rebuild(int capacity) {
      initStep(capacity);
      int[] oldKeys = keys;
      byte[] oldPresent = present;
      int[] oldValues = values;
      keys = new int[capacity];
      present = new byte[capacity];
      values = new int[capacity];
      size = 0;
      realSize = 0;
      for (int i = 0; i < oldKeys.length; i++) {
        if ((oldPresent[i] & id1) == id1)
          put(oldKeys[i], oldValues[i]);
      }
    }


    public boolean contains(int key) {
      int current = getHash(key);
      while (present[current] != 0) {
        if (keys[current] == key && (present[current] & id1) != 0)
          return true;
        current += step;
        if (current >= keys.length)
          current -= keys.length;
      }
      return false;
    }

    public int get(int key) {
      int current = getHash(key);
      while (present[current] != 0) {
        if (keys[current] == key && (present[current] & id1) != 0)
          return values[current];
        current += step;
        if (current >= keys.length)
          current -= keys.length;
      }
      throw new NoSuchElementException();
    }

  }

  static class IOUtils {
    public static long[] id10(InputReader in, int size) {
      long[] array = new long[size];
      for (int i = 0; i < size; i++)
        array[i] = in.readLong();
      return array;
    }

    public static void id12(InputReader in, int[]... arrays) {
      for (int i = 0; i < arrays[0].length; i++) {
        for (int j = 0; j < arrays.length; j++)
          arrays[j][i] = in.readInt();
      }
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

  static abstract class IntSet extends IntCollection {
  }

  static abstract class IntCollection {
    public abstract IntIterator iterator();

    public abstract int size();

  }

  static class MiscUtils {
    public static void id9(int[]... arrays) {
      for (int[] array : arrays) {
        for (int i = 0; i < array.length; i++)
          array[i]--;
      }
    }

  }

  static abstract class IntList extends IntCollection implements Comparable<IntList> {
    private static final int id15 = 16;

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

    public id16 id14(IntComparator comparator) {
      quickSort(0, size() - 1, (Integer.bitCount(Integer.highestOneBit(size()) - 1) * 5) >> 1, comparator);
      return new id8(this, comparator);
    }

    private void quickSort(int from, int to, int remaining, IntComparator comparator) {
      if (to - from < id15) {
        id6(from, to, comparator);
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
        id3(i, to, comparator, from);
      for (int i = to; i > from; i--) {
        swap(from, i);
        id3(from, i - 1, comparator, from);
      }
    }

    private void id3(int start, int end, IntComparator comparator, int delta) {
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

    private void id6(int from, int to, IntComparator comparator) {
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
      IntList list = (IntList) obj;
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

  static class InputReader {
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private InputReader.id17 filter;

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
      while (id5(c))
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
      } while (!id5(c));
      return res * sgn;
    }

    public long readLong() {
      int c = read();
      while (id5(c))
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
      } while (!id5(c));
      return res * sgn;
    }

    public boolean id5(int c) {
      if (filter != null)
        return filter.id5(c);
      return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
      return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public interface id17 {
      public boolean id5(int ch);

    }

  }

  static class IntArray extends IntList {
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
}

