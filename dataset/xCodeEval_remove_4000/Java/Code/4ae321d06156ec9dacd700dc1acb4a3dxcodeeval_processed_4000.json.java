import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.Collection;
import java.util.Random;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;


public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    QuickScanner in = new QuickScanner(inputStream);
    QuickWriter out = new QuickWriter(outputStream);
    TaskG solver = new TaskG();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskG {
    QuickWriter out;
    id26 itree;
    int globalMin;
    int[] id11;
    id18 rmq;
    int[] left;
    int[] right;
    int valueCnt;
    int repeatCnt;
    int[] value;
    int queryCnt;
    int[] oldLeft;
    int[] oldRight;
    int[] op;
    int[] setValue;
    id27 disIdx;

    public void solve(int testNumber, QuickScanner in, QuickWriter out) {
      this.out = out;
      input(in);
      discrete();
      rmq();
      id11();
      calc();
    }

    void calc() {
      itree = new id26(id11.length, false);
      itree.init(id11.length, id11);
      for (int queryIdx = 0; queryIdx < queryCnt; ++queryIdx) {
        if (op[queryIdx] == 1) {
          itree.update(left[queryIdx], right[queryIdx], setValue[queryIdx]);
        } else {
          out.println(itree.calc(left[queryIdx], right[queryIdx]));
        }
      }
    }

    void id11() {
      globalMin = id6.min(value, 0, valueCnt);
      id11 = new int[disIdx.size - 1];
      for (int i = 1; i < disIdx.size; ++i) {
        int left = disIdx.get(i - 1);
        int right = disIdx.get(i);
        int res;
        if (right - left >= valueCnt) {
          res = globalMin;
        } else {
          left %= valueCnt;
          right %= valueCnt;
          res = left < right ? rmq.calc(left, right) : rmq.calc(left, right + valueCnt);
        }
        id11[i - 1] = res;
      }
    }

    void rmq() {
      rmq = new id18(valueCnt << 1);
      rmq.init(valueCnt << 1, value);
    }

    void discrete() {
      disIdx.id19();
      left = new int[queryCnt];
      right = new int[queryCnt];
      for (int i = 0; i < queryCnt; ++i) {
        left[i] = disIdx.lowerBound(oldLeft[i]);
        right[i] = disIdx.lowerBound(oldRight[i]);
      }
    }

    void input(QuickScanner in) {
      valueCnt = in.nextInt();
      repeatCnt = in.nextInt();
      value = new int[valueCnt << 1];
      for (int i = 0, j = valueCnt; i < valueCnt; ++i, ++j) {
        value[i] = in.nextInt();
        value[j] = value[i];
      }
      queryCnt = in.nextInt();
      op = new int[queryCnt];
      oldLeft = new int[queryCnt];
      oldRight = new int[queryCnt];
      setValue = new int[queryCnt];
      disIdx = new id27(queryCnt << 1);
      for (int i = 0; i < queryCnt; ++i) {
        op[i] = in.nextInt();
        oldLeft[i] = in.nextInt() - 1;
        oldRight[i] = in.nextInt();
        disIdx.add(oldLeft[i]);
        disIdx.add(oldRight[i]);
        if (op[i] == 1) {
          setValue[i] = in.nextInt();
        }
      }
    }

  }

  static interface IntCollection {
  }

  static abstract class id15 implements Displayable {
    private int nodeCapacity;
    private int leafCnt;
    private int height;
    private int[] rangeLower;
    private int[] rangeUpper;
    private id27 id23;
    private id27 id1;

    public abstract void createStorage(int nodeCapacity);

    public abstract void initLeaf(int id3, int idx);

    public abstract void id16();

    public abstract void id14(int id22, int id30);

    public abstract void id4(int id3);

    public abstract void merge(int id5, int id20, int id3);

    public abstract void id31(int id22, int id30);

    public abstract void id12(int id3);

    public id15(int leafCapacity) {
      this(leafCapacity, true);
    }

    public id15(int leafCapacity, boolean initialize) {
      int height = 32 - Integer.numberOfLeadingZeros(leafCapacity);
      id23 = new id27(height << 1);
      id1 = new id27(height);
      nodeCapacity = leafCapacity << 1;
      rangeLower = new int[nodeCapacity + 2];
      rangeUpper = new int[nodeCapacity + 2];
      createStorage(nodeCapacity + 2);
      if (initialize) init(leafCapacity);
    }

    public void init(int leafCnt) {
      this.leafCnt = leafCnt;
      this.height = 32 - Integer.numberOfLeadingZeros(leafCnt);
      for (int i = 0; i < leafCnt; ++i) {
        rangeLower[i + leafCnt] = i;
        rangeUpper[i + leafCnt] = i + 1;
        initLeaf(i + leafCnt, i);
        id4(i);
        id4(i + leafCnt);
      }
      for (int i = leafCnt - 1; i >= 0; --i) {
        int left = i << 1, right = left | 1;
        if (rangeUpper[left] == rangeLower[right]) {
          rangeLower[i] = rangeLower[left];
          rangeUpper[i] = rangeUpper[right];
          merge(left, right, i);
        } else {
          rangeLower[i] = leafCnt;
          rangeUpper[i] = -1;
        }
      }
    }

    public void updateRange(int lower, int upper) {
      id16();
      id21(lower, upper);
      boolean calcLeft = false, calcRight = false;
      for (lower += leafCnt, upper += leafCnt; lower < upper; lower >>= 1, upper >>= 1) {
        if (calcLeft) merge(lower - 1);
        if (calcRight) merge(upper);
        if ((lower & 1) > 0) {
          id14(0, lower++);
          calcLeft = true;
        }
        if ((upper & 1) > 0) {
          id14(0, --upper);
          calcRight = true;
        }
      }
      for (--lower; upper > 0; lower >>= 1, upper >>= 1) {
        if (calcLeft) merge(lower);
        if (calcRight && (!calcLeft || lower != upper)) merge(upper);
      }
    }

    public void calcRange(int lower, int upper) {
      if (lower >= upper) {
        id12(0);
        return;
      }
      id21(lower, upper);
      id23.clear();
      id1.clear();
      for (lower += leafCnt, upper += leafCnt; lower < upper; lower >>= 1, upper >>= 1) {
        if ((lower & 1) > 0) {
          if (isValid(lower)) id23.add(lower);
          ++lower;
        }
        if ((upper & 1) > 0) {
          if (isValid(--upper)) id1.add(upper);
        }
      }
      id1.reverse();
      id23.addAll(id1);
      int id3 = id23.get(0);
      int id2 = nodeCapacity;
      id31(id3, id2);
      rangeLower[id2] = rangeLower[id3];
      rangeUpper[id2] = rangeUpper[id3];
      for (int i = 1; i < id23.size; ++i, id2 ^= 1) {
        id3 = id23.get(i);
        merge(id2, id3, id2 ^ 1);
        rangeLower[id2 ^ 1] = rangeLower[id2];
        rangeUpper[id2 ^ 1] = rangeUpper[id3];
      }
      id31(id2, 0);
    }

    public boolean isValid(int id3) {
      return rangeLower[id3] < rangeUpper[id3];
    }

    private void merge(int id3) {
      merge(id3 << 1, (id3 << 1) | 1, id3);
    }

    private void id21(int lower, int upper) {
      lower = (lower + leafCnt) >> 1;
      upper = (upper - 1 + leafCnt) >> 1;
      for (id23.clear(); lower < upper; lower >>= 1, upper >>= 1) {
        if (isValid(lower)) id23.add(lower);
        if (isValid(upper)) id23.add(upper);
      }
      for (; lower > 0 && isValid(lower); lower >>= 1) {
        id23.add(lower);
      }
      for (int i = id23.size - 1; i >= 0; --i) {
        id14(id23.values[i]);
      }
    }

    private void id14(int id3) {
      id14(id3, id3 << 1);
      id14(id3, (id3 << 1) | 1);
      id4(id3);
    }

  }

  static class id18 extends id29 {
    private int[][] rmq;
    private int[][] id28;
    private int[] initValues;
    private int resIdx;

    public id18(int capacity) {
      super(capacity);
    }


    public void createArrays(int id13) {
      rmq = new int[id13][];
      id28 = new int[id13][];
    }


    public void createArray(int bit, int capacity) {
      rmq[bit] = new int[capacity];
      id28[bit] = new int[capacity];
    }


    public void initSubclass(int n) {
      for (int i = 0; i < n; ++i) {
        rmq[0][i] = initValues[i];
        id28[0][i] = i;
      }
    }


    public void initMerge(int targetBit, int targetIdx, int sourceBit, int id0, int id17) {
      if (rmq[sourceBit][id0] <= rmq[sourceBit][id17]) {
        rmq[targetBit][targetIdx] = rmq[sourceBit][id0];
        id28[targetBit][targetIdx] = id28[sourceBit][id0];
      } else {
        rmq[targetBit][targetIdx] = rmq[sourceBit][id17];
        id28[targetBit][targetIdx] = id28[sourceBit][id17];
      }
    }


    public void calcMerge(int bit, int x, int y) {
      resIdx = rmq[bit][x] <= rmq[bit][y] ? id28[bit][x] : id28[bit][y];
    }

    public void init(int n, int[] initValues) {
      this.initValues = initValues;
      initInternal(n);
    }

    public int calc(int fromIdx, int toIdx) {
      return rmq[0][calcIdx(fromIdx, toIdx)];
    }

    public int calcIdx(int fromIdx, int toIdx) {
      calcInternal(fromIdx, toIdx);
      return resIdx;
    }

  }

  static abstract class id29 {
    public abstract void createArrays(int id13);

    public abstract void createArray(int bit, int capacity);

    public abstract void initSubclass(int n);

    public abstract void initMerge(int targetBit, int targetIdx, int sourceBit, int id0, int id17);

    public abstract void calcMerge(int bit, int x, int y);

    public id29(int capacity) {
      int highBit = 32 - Integer.numberOfLeadingZeros(capacity);
      createArrays(highBit);
      for (int bit = 0; bit < highBit; ++bit) {
        createArray(bit, capacity - (1 << bit) + 1);
      }
    }

    protected void initInternal(int n) {
      initSubclass(n);
      for (int bitI = 1; 1 << bitI <= n; ++bitI) {
        for (int i = n - (1 << bitI), j = i + (1 << (bitI - 1)); i >= 0; --i, --j) {
          initMerge(bitI, i, bitI - 1, i, j);
        }
      }
    }

    protected void calcInternal(int fromIdx, int toIdx) {
      int bit = 31 - Integer.numberOfLeadingZeros(toIdx - fromIdx);
      calcMerge(bit, fromIdx, toIdx - (1 << bit));
    }

  }

  static class id6 {
    private static final Random RANDOM = new Random(1000000007);

    public static int min(int[] values, int fromIdx, int toIdx) {
      int res = Integer.MAX_VALUE;
      for (int i = fromIdx; i < toIdx; ++i) {
        if (res > values[i]) res = values[i];
      }
      return res;
    }

    public static void reverse(int[] values, int fromIdx, int toIdx) {
      for (int i = fromIdx, j = toIdx - 1; i < j; ++i, --j) {
        swap(values, i, j);
      }
    }

    public static int unique(int[] values, int fromIdx, int toIdx) {
      if (fromIdx == toIdx) return 0;
      int res = 1;
      for (int i = fromIdx + 1; i < toIdx; ++i) {
        if (values[i - 1] != values[i]) {
          values[fromIdx + res++] = values[i];
        }
      }
      return res;
    }

    public static void sort(int[] values, int fromIdx, int toIdx) {
      shuffle(values, fromIdx, toIdx);
      Arrays.sort(values, fromIdx, toIdx);
    }

    public static int lowerBound(int[] values, int fromIdx, int toIdx, int value) {
      int res = toIdx;
      for (int lower = fromIdx, upper = toIdx - 1; lower <= upper; ) {
        int medium = (lower + upper) >> 1;
        if (value <= values[medium]) {
          res = medium;
          upper = medium - 1;
        } else {
          lower = medium + 1;
        }
      }
      return res;
    }

    public static void swap(int[] values, int uIdx, int vIdx) {
      if (uIdx == vIdx) return;
      values[uIdx] ^= values[vIdx];
      values[vIdx] ^= values[uIdx];
      values[uIdx] ^= values[vIdx];
    }

    public static void shuffle(int[] values, int fromIdx, int toIdx) {
      for (int i = toIdx - fromIdx - 1; i > 0; --i) {
        swap(values, i + fromIdx, RANDOM.nextInt(i + 1) + fromIdx);
      }
    }

  }

  static interface Displayable {
  }

  static class id27 implements Displayable, IntCollection, Iterable<Integer> {
    private static final int[] EMPTY = {};
    public int[] values;
    public int size;

    public id27() {
      values = EMPTY;
      clear();
    }

    public id27(int capacity) {
      values = new int[IntUtils.id25(capacity)];
      clear();
    }

    public id27(Collection<Integer> collection) {
      this(collection.size());
      addAll(collection);
    }


    public void clear() {
      size = 0;
    }


    public void add(int value) {
      ensureCapacity(size + 1);
      addInternal(value);
    }


    public void addAll(Collection<Integer> values) {
      ensureCapacity(size + values.size());
      for (int value : values) {
        addInternal(value);
      }
    }

    public void addAll(id27 values) {
      ensureCapacity(size + values.size);
      for (int i = 0; i < values.size; ++i) {
        addInternal(values.get(i));
      }
    }

    public int get(int idx) {
      if (idx >= size) throw new ArrayIndexOutOfBoundsException();
      return values[idx];
    }

    public void sort() {
      id6.sort(values, 0, size);
    }

    public void unique() {
      size = id6.unique(values, 0, size);
    }

    public void id19() {
      sort();
      unique();
    }

    public int lowerBound(int value) {
      return id6.lowerBound(values, 0, size, value);
    }

    public void reverse() {
      id6.reverse(values, 0, size);
    }

    public void ensureCapacity(int capacity) {
      if (capacity <= values.length) return;
      int[] newValues = new int[IntUtils.id25(capacity)];
      for (int i = 0; i < size; ++i) {
        newValues[i] = values[i];
      }
      values = newValues;
    }


    public Iterator<Integer> iterator() {
      return new Iterator<Integer>() {
        private int i = 0;


        public boolean hasNext() {
          return i < size;
        }


        public Integer next() {
          return values[i++];
        }
      };
    }

    private void addInternal(int value) {
      values[size++] = value;
    }

  }

  static class IntUtils {
    public static boolean id8(int n) {
      return n > 0 && (n & (n - 1)) == 0;
    }

    public static int id25(int n) {
      if (n < 1) return 1;
      return id8(n) ? n : Integer.highestOneBit(n) << 1;
    }

  }

  static class id26 extends id15 {
    int[] minValue;
    boolean[] toSet;
    int[] setValue;
    int[] initValues;
    int updateValue;

    public id26(int leafCapacity) {
      super(leafCapacity);
    }

    public id26(int leafCapacity, boolean initialize) {
      super(leafCapacity, initialize);
    }


    public void createStorage(int nodeCapacity) {
      minValue = new int[nodeCapacity];
      toSet = new boolean[nodeCapacity];
      setValue = new int[nodeCapacity];
    }


    public void initLeaf(int id3, int idx) {
      minValue[id3] = initValues[idx];
    }


    public void id16() {
      toSet[0] = true;
      setValue[0] = updateValue;
    }


    public void id14(int id22, int id30) {
      if (toSet[id22]) {
        toSet[id30] = true;
        setValue[id30] = setValue[id22];
        minValue[id30] = setValue[id30];
      }
    }


    public void id4(int id3) {
      toSet[id3] = false;
    }


    public void merge(int id5, int id20, int id3) {
      minValue[id3] = Math.min(minValue[id5], minValue[id20]);
    }


    public void id31(int id22, int id30) {
      minValue[id30] = minValue[id22];
    }


    public void id12(int id3) {
      minValue[id3] = Integer.MAX_VALUE;
    }

    public void init(int n, int[] initValues) {
      this.initValues = initValues;
      super.init(n);
    }

    public void update(int lower, int upper, int updateValue) {
      this.updateValue = updateValue;
      updateRange(lower, upper);
    }

    public int calc(int lower, int upper) {
      calcRange(lower, upper);
      return minValue[0];
    }

  }

  static class QuickWriter {
    private final PrintWriter writer;

    public QuickWriter(OutputStream outputStream) {
      this.writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public QuickWriter(Writer writer) {
      this.writer = new PrintWriter(writer);
    }

    public void print(Object... objects) {
      for (int i = 0; i < objects.length; ++i) {
        if (i > 0) {
          writer.print(' ');
        }
        writer.print(objects[i]);
      }
    }

    public void println(Object... objects) {
      print(objects);
      writer.print('\n');
    }

    public void close() {
      writer.close();
    }

  }

  static class QuickScanner {
    private static final int BUFFER_SIZE = 1024;
    private InputStream stream;
    private byte[] buffer;
    private int currentPosition;
    private int id9;

    public QuickScanner(InputStream stream) {
      this.stream = stream;
      this.buffer = new byte[BUFFER_SIZE];
      this.currentPosition = 0;
      this.id9 = 0;
    }

    public int nextInt() {
      int c = id10();
      boolean positive = true;
      if (c == '-') {
        positive = false;
        c = nextChar();
      }
      int res = 0;
      do {
        if (c < '0' || '9' < c) throw new RuntimeException();
        res = res * 10 + c - '0';
        c = nextChar();
      } while (!id7(c));
      return positive ? res : -res;
    }

    public int id10() {
      int res = nextChar();
      for (; id7(res) || res < 0; res = nextChar()) ;
      return res;
    }

    public int nextChar() {
      if (id9 == -1) {
        throw new RuntimeException();
      }
      if (currentPosition >= id9) {
        currentPosition = 0;
        try {
          id9 = stream.read(buffer);
        } catch (Exception e) {
          throw new RuntimeException(e);
        }
        if (id9 <= 0) {
          return -1;
        }
      }
      return buffer[currentPosition++];
    }

    public boolean id7(int c) {
      return c == ' ' || c == '\t' || id24(c);
    }

    public boolean id24(int c) {
      return c == '\n' || c == '\r' || c < 0;
    }

  }
}

