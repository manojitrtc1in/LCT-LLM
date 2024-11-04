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
    id11 itree;
    int globalMin;
    int[] id12;
    id19 rmq;
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
    id25 disIdx;

    public void solve(int testNumber, QuickScanner in, QuickWriter out) {
      this.out = out;
      input(in);
      discrete();
      rmq();
      id12();
      calc();
    }

    void calc() {
      itree = new id11(id12.length);
      itree.init(id12.length, id12);
      for (int queryIdx = 0; queryIdx < queryCnt; ++queryIdx) {
        if (op[queryIdx] == 1) {
          itree.update(left[queryIdx], right[queryIdx], setValue[queryIdx]);
        } else {
          out.println(itree.calc(left[queryIdx], right[queryIdx]));
        }
      }
    }

    void id12() {
      globalMin = id5.min(value, 0, valueCnt);
      id12 = new int[disIdx.size - 1];
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
        id12[i - 1] = res;
      }
    }

    void rmq() {
      rmq = new id19(valueCnt << 1);
      rmq.init(valueCnt << 1, value);
    }

    void discrete() {
      disIdx.id20();
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
      disIdx = new id25(queryCnt << 1);
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

  static class id5 {
    private static final Random RANDOM = new Random(1000000007);

    public static int min(int[] values, int fromIdx, int toIdx) {
      int res = Integer.MAX_VALUE;
      for (int i = fromIdx; i < toIdx; ++i) {
        if (res > values[i]) res = values[i];
      }
      return res;
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

    public static String toString(int[] values, int fromIdx, int toIdx) {
      StringBuilder sb = new StringBuilder("[");
      for (int i = fromIdx; i < toIdx; ++i) {
        if (i != fromIdx) sb.append(", ");
        sb.append(values[i]);
      }
      return sb.append("]").toString();
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

  static class id19 extends id30 {
    private int[][] rmq;
    private int[][] id29;
    private int[] initValues;
    private int resIdx;

    public id19(int capacity) {
      super(capacity);
    }


    public void createArrays(int id13) {
      rmq = new int[id13][];
      id29 = new int[id13][];
    }


    public void createArray(int bit, int capacity) {
      rmq[bit] = new int[capacity];
      id29[bit] = new int[capacity];
    }


    public void initSubclass(int n) {
      for (int i = 0; i < n; ++i) {
        rmq[0][i] = initValues[i];
        id29[0][i] = i;
      }
    }


    public void initMerge(int targetBit, int targetIdx, int sourceBit, int id0, int id16) {
      if (rmq[sourceBit][id0] <= rmq[sourceBit][id16]) {
        rmq[targetBit][targetIdx] = rmq[sourceBit][id0];
        id29[targetBit][targetIdx] = id29[sourceBit][id0];
      } else {
        rmq[targetBit][targetIdx] = rmq[sourceBit][id16];
        id29[targetBit][targetIdx] = id29[sourceBit][id16];
      }
    }


    public void calcMerge(int bit, int x, int y) {
      resIdx = rmq[bit][x] <= rmq[bit][y] ? id29[bit][x] : id29[bit][y];
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

  static abstract class id18 {
    public int[] lower;
    public int[] upper;
    private int n;
    private int height;
    private id25 id26;
    private id25 id21;

    public abstract void createSubclass(int nodeCapacity);

    public abstract void id3(int nodeCapacity);

    public abstract void initLeaf(int nodeIdx, int idx);

    public abstract void id17(int nodeIdx);

    public abstract void calcAppend(int nodeIdx);

    public abstract void id15();

    public abstract void id14(int id1, int id23);

    public abstract void id2(int nodeIdx);

    public abstract String id31(int nodeIdx);

    public abstract String id27(int nodeIdx);

    public id18(int leafCapacity, boolean initialize) {
      id26 = new id25();
      id21 = new id25();
      int id28 = leafCapacity << 1;
      lower = new int[id28];
      upper = new int[id28];
      createSubclass(id28);
      if (initialize) init(leafCapacity);
    }

    public void init(int n) {
      this.n = n;
      this.height = 32 - Integer.numberOfLeadingZeros(n);
      id3(n << 1);
      for (int i = 0; i < n; ++i) {
        lower[n + i] = i;
        upper[n + i] = i + 1;
        initLeaf(n + i, i);
      }
      for (int i = n - 1; i > 0; --i) {
        int left = i << 1, right = left | 1;
        if (upper[left] == lower[right]) {
          lower[i] = lower[left];
          upper[i] = upper[right];
          id17(i);
        } else {
          lower[i] = n;
          upper[i] = -1;
        }
      }
    }

    public void updateRange(int lower, int upper) {
      id15();
      pushInternal(lower);
      pushInternal(upper - 1);
      boolean id7 = false, id4 = false;
      for (lower += n, upper += n; lower < upper; lower >>= 1, upper >>= 1) {
        if (id7) id17(lower - 1);
        if (id4) id17(upper);
        if ((lower & 1) > 0) {
          id14(0, lower++);
          id7 = true;
        }
        if ((upper & 1) > 0) {
          id14(0, --upper);
          id4 = true;
        }
      }
      for (--lower; upper > 0; lower >>= 1, upper >>= 1) {
        if (id7) id17(lower);
        if (id4 && (!id7 || lower != upper)) id17(upper);
      }
    }

    public void calcRange(int lower, int upper) {
      pushInternal(lower);
      pushInternal(upper - 1);
      id26.clear();
      id21.clear();
      for (lower += n, upper += n; lower < upper; lower >>= 1, upper >>= 1) {
        if ((lower & 1) > 0) id26.add(lower++);
        if ((upper & 1) > 0) id21.add(--upper);
      }
      for (int i = 0; i < id26.size; ++i) {
        int idx = id26.get(i);
        calcAppend(idx);
      }
      for (int i = id21.size - 1; i >= 0; --i) {
        int idx = id21.get(i);
        calcAppend(idx);
      }
    }


    public String toString() {
      StringBuilder sb = new StringBuilder();
      for (int i = 0; i < n << 1; ++i)
        if (lower[i] < upper[i]) {
          sb.append(String.format("@%d[%d,%d):%s", i, lower[i], upper[i], id31(i)));
          if (lower[i] + 1 < upper[i]) sb.append(String.format(" | %s", id27(i)));
          if (i + 1 < n << 1) sb.append('\n');
        }
      return sb.toString();
    }

    private void pushInternal(int nodeIdx) {
      for (int s = height, l = nodeIdx + n, r = l; s > 0; --s) {
        for (int i = l >> s; i <= r >> s; ++i)
          if (lower[i] < upper[i]) {


            id14(i, i << 1);
            id14(i, (i << 1) | 1);
            id2(i);
          }
      }
    }

  }

  static class id25 implements IntCollection, Iterable<Integer> {
    private static final int[] EMPTY = {};
    public int[] values;
    public int size;

    public id25() {
      values = EMPTY;
      clear();
    }

    public id25(int capacity) {
      values = new int[IntUtils.id24(capacity)];
      clear();
    }

    public id25(Collection<Integer> collection) {
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

    public int get(int idx) {
      if (idx >= size) throw new ArrayIndexOutOfBoundsException();
      return values[idx];
    }

    public void sort() {
      id5.sort(values, 0, size);
    }

    public void unique() {
      size = id5.unique(values, 0, size);
    }

    public void id20() {
      sort();
      unique();
    }

    public int lowerBound(int value) {
      return id5.lowerBound(values, 0, size, value);
    }

    public void ensureCapacity(int capacity) {
      if (capacity <= values.length) return;
      int[] newValues = new int[IntUtils.id24(capacity)];
      for (int i = 0; i < size; ++i) {
        newValues[i] = values[i];
      }
      values = newValues;
    }


    public String toString() {
      return id5.toString(values, 0, size);
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

  static abstract class id30 {
    public abstract void createArrays(int id13);

    public abstract void createArray(int bit, int capacity);

    public abstract void initSubclass(int n);

    public abstract void initMerge(int targetBit, int targetIdx, int sourceBit, int id0, int id16);

    public abstract void calcMerge(int bit, int x, int y);

    public id30(int capacity) {
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
      } while (!id6(c));
      return positive ? res : -res;
    }

    public int id10() {
      int res = nextChar();
      for (; id6(res) || res < 0; res = nextChar()) ;
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

    public boolean id6(int c) {
      return c == ' ' || c == '\t' || id22(c);
    }

    public boolean id22(int c) {
      return c == '\n' || c == '\r' || c < 0;
    }

  }

  static class IntUtils {
    public static boolean id8(int n) {
      return n > 0 && (n & (n - 1)) == 0;
    }

    public static int id24(int n) {
      if (n < 1) return 1;
      return id8(n) ? n : Integer.highestOneBit(n) << 1;
    }

  }

  static interface IntCollection {
  }

  static class id11 extends id18 {
    int[] minValue;
    boolean[] toSet;
    int[] setValue;
    int res;
    int[] initValues;
    int updateValue;

    public id11(int leafCapacity) {
      super(leafCapacity, false);
    }


    public void createSubclass(int nodeCapacity) {
      minValue = new int[nodeCapacity];
      toSet = new boolean[nodeCapacity];
      setValue = new int[nodeCapacity];
    }


    public void id3(int nodeCapacity) {
      Arrays.fill(toSet, 0, nodeCapacity, false);
    }


    public void initLeaf(int nodeIdx, int idx) {
      minValue[nodeIdx] = initValues[idx];
    }


    public void id17(int nodeIdx) {
      if (toSet[nodeIdx]) {
        minValue[nodeIdx] = setValue[nodeIdx];
      } else {
        minValue[nodeIdx] = Math.min(minValue[nodeIdx << 1], minValue[(nodeIdx << 1) | 1]);
      }
    }


    public void calcAppend(int nodeIdx) {
      res = Math.min(res, minValue[nodeIdx]);
    }


    public void id15() {
      toSet[0] = true;
      setValue[0] = updateValue;
    }


    public void id14(int id1, int id23) {
      if (toSet[id1]) {
        toSet[id23] = true;
        setValue[id23] = setValue[id1];
        minValue[id23] = setValue[id23];
      }
    }


    public void id2(int nodeIdx) {
      toSet[nodeIdx] = false;
    }


    public String id31(int nodeIdx) {
      return String.format("min:%d", minValue[nodeIdx]);
    }


    public String id27(int nodeIdx) {
      return "set:" + (toSet[nodeIdx] ? setValue[nodeIdx] : "X");
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
      res = Integer.MAX_VALUE;
      calcRange(lower, upper);
      return res;
    }

  }
}

