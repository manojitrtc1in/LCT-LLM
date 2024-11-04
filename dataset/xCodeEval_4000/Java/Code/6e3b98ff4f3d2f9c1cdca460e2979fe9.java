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
    SimpleIT itree;
    int globalMin;
    int[] oldMinValue;
    IntMinimumRMQ rmq;
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
    IntArrayList disIdx;

    public void solve(int testNumber, QuickScanner in, QuickWriter out) {
      this.out = out;
      input(in);
      discrete();
      rmq();
      oldMinValue();
      calc();
    }

    void calc() {
      itree = new SimpleIT(oldMinValue.length);
      itree.init(oldMinValue.length);
      for (int queryIdx = 0; queryIdx < queryCnt; ++queryIdx) {
        if (op[queryIdx] == 1) {
          itree.update(left[queryIdx], right[queryIdx], setValue[queryIdx]);
        } else {
          out.println(itree.calc(left[queryIdx], right[queryIdx]));
        }
      }
    }

    void oldMinValue() {
      globalMin = IntArrayUtils.min(value, 0, valueCnt);
      oldMinValue = new int[disIdx.size - 1];
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
        oldMinValue[i - 1] = res;
      }
    }

    void rmq() {
      rmq = new IntMinimumRMQ(valueCnt << 1);
      rmq.init(valueCnt << 1, value);
    }

    void discrete() {
      disIdx.sortAndUnique();
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
      disIdx = new IntArrayList(queryCnt << 1);
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

    class SimpleIT extends AbstractSimpleIntervalTree {
      int[] minValue;
      boolean[] overwritten;
      int[] overwriteValue;
      int res;
      int updateValue;

      public SimpleIT(int leafCapacity) {
        super(leafCapacity);
      }


      public void createSubclass(int nodeCapacity) {
        minValue = new int[nodeCapacity];
        overwritten = new boolean[nodeCapacity];
        overwriteValue = new int[nodeCapacity];
      }


      public void initLazyPropagation(int nodeCapacity) {
        Arrays.fill(overwritten, 0, nodeCapacity, false);
      }


      public void initLeaf(int nodeIdx, int idx) {
        minValue[nodeIdx] = oldMinValue[idx];
      }


      public void calcNonLeafNode(int nodeIdx) {
        if (overwritten[nodeIdx]) {
          minValue[nodeIdx] = overwriteValue[nodeIdx];
        } else {
          minValue[nodeIdx] = Math.min(minValue[nodeIdx << 1], minValue[(nodeIdx << 1) | 1]);
        }
      }


      public void calcAppend(int nodeIdx) {
        res = Math.min(res, minValue[nodeIdx]);
      }


      public void assignFakeLazyPropagation() {
        overwritten[0] = true;
        overwriteValue[0] = updateValue;
      }


      public void pushLazyPropagation(int fromNodeIdx, int toNodeIdx) {
        if (overwritten[fromNodeIdx]) {
          overwritten[toNodeIdx] = true;
          overwriteValue[toNodeIdx] = overwriteValue[fromNodeIdx];
          minValue[toNodeIdx] = overwriteValue[toNodeIdx];
        }
      }


      public void clearLazyPropagation(int nodeIdx) {
        overwritten[nodeIdx] = false;
      }


      public String valueToString(int nodeIdx) {
        return String.format("min:%d", minValue[nodeIdx]);
      }


      public String lazyPropagationToString(int nodeIdx) {
        return "set:" + (overwritten[nodeIdx] ? overwriteValue[nodeIdx] : "X");
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

  static class IntArrayUtils {
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

  static class IntMinimumRMQ extends AbstractRMQ {
    private int[][] rmq;
    private int[][] rmqIdx;
    private int[] initValues;
    private int resIdx;

    public IntMinimumRMQ(int capacity) {
      super(capacity);
    }


    public void createArrays(int capacityHighBit) {
      rmq = new int[capacityHighBit][];
      rmqIdx = new int[capacityHighBit][];
    }


    public void createArray(int bit, int capacity) {
      rmq[bit] = new int[capacity];
      rmqIdx[bit] = new int[capacity];
    }


    public void initSubclass(int n) {
      for (int i = 0; i < n; ++i) {
        rmq[0][i] = initValues[i];
        rmqIdx[0][i] = i;
      }
    }


    public void initMerge(int targetBit, int targetIdx, int sourceBit, int sourceIdx1, int sourceIdx2) {
      if (rmq[sourceBit][sourceIdx1] <= rmq[sourceBit][sourceIdx2]) {
        rmq[targetBit][targetIdx] = rmq[sourceBit][sourceIdx1];
        rmqIdx[targetBit][targetIdx] = rmqIdx[sourceBit][sourceIdx1];
      } else {
        rmq[targetBit][targetIdx] = rmq[sourceBit][sourceIdx2];
        rmqIdx[targetBit][targetIdx] = rmqIdx[sourceBit][sourceIdx2];
      }
    }


    public void calcMerge(int bit, int x, int y) {
      resIdx = rmq[bit][x] <= rmq[bit][y] ? rmqIdx[bit][x] : rmqIdx[bit][y];
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

  static abstract class AbstractSimpleIntervalTree {
    public int[] lower;
    public int[] upper;
    private int n;
    private int height;
    private IntArrayList calcLeftIdx;
    private IntArrayList calcRightIdx;

    public abstract void createSubclass(int nodeCapacity);

    public abstract void initLazyPropagation(int nodeCapacity);

    public abstract void initLeaf(int nodeIdx, int idx);

    public abstract void calcNonLeafNode(int nodeIdx);

    public abstract void calcAppend(int nodeIdx);

    public abstract void assignFakeLazyPropagation();

    public abstract void pushLazyPropagation(int fromNodeIdx, int toNodeIdx);

    public abstract void clearLazyPropagation(int nodeIdx);

    public abstract String valueToString(int nodeIdx);

    public abstract String lazyPropagationToString(int nodeIdx);

    public AbstractSimpleIntervalTree(int leafCapacity) {
      calcLeftIdx = new IntArrayList();
      calcRightIdx = new IntArrayList();
      int leafCapacity2 = leafCapacity << 1;
      lower = new int[leafCapacity2];
      upper = new int[leafCapacity2];
      createSubclass(leafCapacity2);
      init(leafCapacity);
    }

    public void init(int n) {
      this.n = n;
      this.height = 32 - Integer.numberOfLeadingZeros(n);
      initLazyPropagation(n << 1);
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
          calcNonLeafNode(i);
        } else {
          lower[i] = n;
          upper[i] = -1;
        }
      }
    }

    public void updateRange(int lower, int upper) {
      assignFakeLazyPropagation();
      pushInternal(lower);
      pushInternal(upper - 1);
      boolean toCalcLeft = false, toCalcRight = false;
      for (lower += n, upper += n; lower < upper; lower >>= 1, upper >>= 1) {
        if (toCalcLeft) calcNonLeafNode(lower - 1);
        if (toCalcRight) calcNonLeafNode(upper);
        if ((lower & 1) > 0) {
          pushLazyPropagation(0, lower++);
          toCalcLeft = true;
        }
        if ((upper & 1) > 0) {
          pushLazyPropagation(0, --upper);
          toCalcRight = true;
        }
      }
      for (--lower; upper > 0; lower >>= 1, upper >>= 1) {
        if (toCalcLeft) calcNonLeafNode(lower);
        if (toCalcRight && (!toCalcLeft || lower != upper)) calcNonLeafNode(upper);
      }
    }

    public void calcRange(int lower, int upper) {
      pushInternal(lower);
      pushInternal(upper - 1);
      calcLeftIdx.clear();
      calcRightIdx.clear();
      for (lower += n, upper += n; lower < upper; lower >>= 1, upper >>= 1) {
        if ((lower & 1) > 0) calcLeftIdx.add(lower++);
        if ((upper & 1) > 0) calcRightIdx.add(--upper);
      }
      for (int i = 0; i < calcLeftIdx.size; ++i) {
        int idx = calcLeftIdx.get(i);
        calcAppend(idx);
      }
      for (int i = calcRightIdx.size - 1; i >= 0; --i) {
        int idx = calcRightIdx.get(i);
        calcAppend(idx);
      }
    }


    public String toString() {
      StringBuilder sb = new StringBuilder();
      for (int i = 0; i < n << 1; ++i)
        if (lower[i] < upper[i]) {
          sb.append(String.format("@%d[%d,%d):%s", i, lower[i], upper[i], valueToString(i)));
          if (lower[i] + 1 < upper[i]) sb.append(String.format(" | %s", lazyPropagationToString(i)));
          if (i + 1 < n << 1) sb.append('\n');
        }
      return sb.toString();
    }

    private void pushInternal(int nodeIdx) {
      for (int s = height, l = nodeIdx + n, r = l; s > 0; --s) {
        for (int i = l >> s; i <= r >> s; ++i)
          if (lower[i] < upper[i]) {


            pushLazyPropagation(i, i << 1);
            pushLazyPropagation(i, (i << 1) | 1);
            clearLazyPropagation(i);
          }
      }
    }

  }

  static class IntArrayList implements IntCollection, Iterable<Integer> {
    private static final int[] EMPTY = {};
    public int[] values;
    public int size;

    public IntArrayList() {
      values = EMPTY;
      clear();
    }

    public IntArrayList(int capacity) {
      values = new int[IntUtils.nextPow2(capacity)];
      clear();
    }

    public IntArrayList(Collection<Integer> collection) {
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
      IntArrayUtils.sort(values, 0, size);
    }

    public void unique() {
      size = IntArrayUtils.unique(values, 0, size);
    }

    public void sortAndUnique() {
      sort();
      unique();
    }

    public int lowerBound(int value) {
      return IntArrayUtils.lowerBound(values, 0, size, value);
    }

    public void ensureCapacity(int capacity) {
      if (capacity <= values.length) return;
      int[] newValues = new int[IntUtils.nextPow2(capacity)];
      for (int i = 0; i < size; ++i) {
        newValues[i] = values[i];
      }
      values = newValues;
    }


    public String toString() {
      return IntArrayUtils.toString(values, 0, size);
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

  static abstract class AbstractRMQ {
    public abstract void createArrays(int capacityHighBit);

    public abstract void createArray(int bit, int capacity);

    public abstract void initSubclass(int n);

    public abstract void initMerge(int targetBit, int targetIdx, int sourceBit, int sourceIdx1, int sourceIdx2);

    public abstract void calcMerge(int bit, int x, int y);

    public AbstractRMQ(int capacity) {
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
    private int numberOfChars;

    public QuickScanner(InputStream stream) {
      this.stream = stream;
      this.buffer = new byte[BUFFER_SIZE];
      this.currentPosition = 0;
      this.numberOfChars = 0;
    }

    public int nextInt() {
      int c = nextNonSpaceChar();
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
      } while (!isSpaceChar(c));
      return positive ? res : -res;
    }

    public int nextNonSpaceChar() {
      int res = nextChar();
      for (; isSpaceChar(res) || res < 0; res = nextChar()) ;
      return res;
    }

    public int nextChar() {
      if (numberOfChars == -1) {
        throw new RuntimeException();
      }
      if (currentPosition >= numberOfChars) {
        currentPosition = 0;
        try {
          numberOfChars = stream.read(buffer);
        } catch (Exception e) {
          throw new RuntimeException(e);
        }
        if (numberOfChars <= 0) {
          return -1;
        }
      }
      return buffer[currentPosition++];
    }

    public boolean isSpaceChar(int c) {
      return c == ' ' || c == '\t' || isEndOfLineChar(c);
    }

    public boolean isEndOfLineChar(int c) {
      return c == '\n' || c == '\r' || c < 0;
    }

  }

  static class IntUtils {
    public static boolean isPow2(int n) {
      return n > 0 && (n & (n - 1)) == 0;
    }

    public static int nextPow2(int n) {
      if (n < 1) return 1;
      return isPow2(n) ? n : Integer.highestOneBit(n) << 1;
    }

  }

  static interface IntCollection {
  }
}

