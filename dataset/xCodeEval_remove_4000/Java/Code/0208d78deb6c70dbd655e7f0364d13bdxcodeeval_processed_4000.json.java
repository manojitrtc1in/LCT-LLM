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
    IT itree;
    int globalMin;
    int[] id10;
    id14 rmq;
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
    id20 disIdx;

    public void solve(int testNumber, QuickScanner in, QuickWriter out) {
      this.out = out;
      input(in);
      discrete();
      rmq();
      id10();
      calc();
    }

    void calc() {
      itree = new IT(id10.length);
      itree.init(id10.length);
      for (int queryIdx = 0; queryIdx < queryCnt; ++queryIdx) {
        if (op[queryIdx] == 1) {
          itree.update(left[queryIdx], right[queryIdx], setValue[queryIdx]);
        } else {
          out.println(itree.calc(left[queryIdx], right[queryIdx]));
        }
      }
    }

    void id10() {
      globalMin = id4.min(value, 0, valueCnt);
      id10 = new int[disIdx.size - 1];
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
        id10[i - 1] = res;


      }
    }

    void rmq() {
      rmq = new id14(valueCnt << 1);


      rmq.init(valueCnt << 1, value);
    }

    void discrete() {
      disIdx.id15();
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
      disIdx = new id20(queryCnt << 1);
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

    class IT extends id1 {
      boolean[] overwritten;
      int[] overwriteValue;
      int[] minValue;
      int updateValue;
      int res;

      public IT(int leafCapacity) {
        super(leafCapacity);
      }


      public void createSubclass(int nodeCapacity) {
        overwritten = new boolean[nodeCapacity];
        overwriteValue = new int[nodeCapacity];
        minValue = new int[nodeCapacity];
      }


      public void initLeaf(int nodeIdx, int idx) {
        overwritten[nodeIdx] = false;
        minValue[nodeIdx] = id10[idx];
      }


      public void merge(int nodeIdx, int id9, int id19) {
        minValue[nodeIdx] = Math.min(minValue[id9], minValue[id19]);
      }


      public void updateNode(int nodeIdx, int lower, int upper) {
        updateNode(nodeIdx, updateValue);
      }


      public void calcAppend(int nodeIdx, int lower, int upper) {
        res = Math.min(res, minValue[nodeIdx]);
      }


      public void id12(int id2, int id17) {
        if (overwritten[id2]) {
          updateNode(id17, overwriteValue[id2]);
        }
      }


      public void id3(int nodeIdx) {
        overwritten[nodeIdx] = false;
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

      private void updateNode(int nodeIdx, int updateValue) {
        overwritten[nodeIdx] = true;
        overwriteValue[nodeIdx] = updateValue;
        minValue[nodeIdx] = updateValue;
      }

    }

  }

  static class id4 {
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

  static class id14 extends id22 {
    private int[][] rmq;
    private int[][] id21;
    private int[] initValues;
    private int resIdx;

    public id14(int capacity) {
      super(capacity);
    }


    public void createArrays(int id11) {
      rmq = new int[id11][];
      id21 = new int[id11][];
    }


    public void createArray(int bit, int capacity) {
      rmq[bit] = new int[capacity];
      id21[bit] = new int[capacity];
    }


    public void initSubclass(int n) {
      for (int i = 0; i < n; ++i) {
        rmq[0][i] = initValues[i];
        id21[0][i] = i;
      }
    }


    public void initMerge(int targetBit, int targetIdx, int sourceBit, int id0, int id13) {
      if (rmq[sourceBit][id0] <= rmq[sourceBit][id13]) {
        rmq[targetBit][targetIdx] = rmq[sourceBit][id0];
        id21[targetBit][targetIdx] = id21[sourceBit][id0];
      } else {
        rmq[targetBit][targetIdx] = rmq[sourceBit][id13];
        id21[targetBit][targetIdx] = id21[sourceBit][id13];
      }
    }


    public void calcMerge(int bit, int x, int y) {
      resIdx = rmq[bit][x] <= rmq[bit][y] ? id21[bit][x] : id21[bit][y];
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

  static class id20 implements IntCollection, Iterable<Integer> {
    private static final int[] EMPTY = {};
    public int[] values;
    public int size;

    public id20() {
      values = EMPTY;
      clear();
    }

    public id20(int capacity) {
      values = new int[IntUtils.id18(capacity)];
      clear();
    }

    public id20(Collection<Integer> collection) {
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
      id4.sort(values, 0, size);
    }

    public void unique() {
      size = id4.unique(values, 0, size);
    }

    public void id15() {
      sort();
      unique();
    }

    public int lowerBound(int value) {
      return id4.lowerBound(values, 0, size, value);
    }

    public void ensureCapacity(int capacity) {
      if (capacity <= values.length) return;
      int[] newValues = new int[IntUtils.id18(capacity)];
      for (int i = 0; i < size; ++i) {
        newValues[i] = values[i];
      }
      values = newValues;
    }


    public String toString() {
      return id4.toString(values, 0, size);
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

  static abstract class id1 {
    private int n;
    private int left;
    private int right;

    public abstract void createSubclass(int nodeCapacity);

    public abstract void initLeaf(int nodeIdx, int idx);

    public abstract void merge(int nodeIdx, int id9, int id19);

    public abstract void updateNode(int nodeIdx, int lower, int upper);

    public abstract void calcAppend(int nodeIdx, int lower, int upper);

    public abstract void id12(int id2, int id17);

    public abstract void id3(int nodeIdx);

    public id1(int leafCapacity) {
      createSubclass(leafCapacity << 2);
      init(leafCapacity);
    }

    public void init(int n) {
      this.n = n;
      init(0, 0, n);
    }

    public void updateRange(int lower, int upper) {
      left = lower;
      right = upper;
      updateRange(0, 0, n);
    }

    public void calcRange(int lower, int upper) {
      left = lower;
      right = upper;
      calc(0, 0, n);
    }

    private void init(int nodeIdx, int lower, int upper) {
      if (lower + 1 == upper) {
        initLeaf(nodeIdx, lower);
        return;
      }
      int medium = (lower + upper) >> 1;
      init(toLeft(nodeIdx), lower, medium);
      init(toRight(nodeIdx), medium, upper);
      merge(nodeIdx, toLeft(nodeIdx), toRight(nodeIdx));
    }

    private void updateRange(int nodeIdx, int lower, int upper) {
      if (left <= lower && upper <= right) {
        updateNode(nodeIdx, lower, upper);
        return;
      }
      id12(nodeIdx);
      int medium = (lower + upper) >> 1;
      if (left < medium) {
        updateRange(toLeft(nodeIdx), lower, medium);
      }
      if (medium < right) {
        updateRange(toRight(nodeIdx), medium, upper);
      }
      merge(nodeIdx, toLeft(nodeIdx), toRight(nodeIdx));
    }

    private void calc(int nodeIdx, int lower, int upper) {
      if (left <= lower && upper <= right) {
        calcAppend(nodeIdx, lower, upper);
        return;
      }
      id12(nodeIdx);
      int medium = (lower + upper) >> 1;
      if (left < medium) {
        calc(toLeft(nodeIdx), lower, medium);
      }
      if (medium < right) {
        calc(toRight(nodeIdx), medium, upper);
      }
      merge(nodeIdx, toLeft(nodeIdx), toRight(nodeIdx));
    }

    private void id12(int nodeIdx) {
      id12(nodeIdx, toLeft(nodeIdx));
      id12(nodeIdx, toRight(nodeIdx));
      id3(nodeIdx);
    }

    private int toLeft(int nodeIdx) {
      return (nodeIdx << 1) | 1;
    }

    private int toRight(int nodeIdx) {
      return (nodeIdx + 1) << 1;
    }

  }

  static abstract class id22 {
    public abstract void createArrays(int id11);

    public abstract void createArray(int bit, int capacity);

    public abstract void initSubclass(int n);

    public abstract void initMerge(int targetBit, int targetIdx, int sourceBit, int id0, int id13);

    public abstract void calcMerge(int bit, int x, int y);

    public id22(int capacity) {
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

  static class IntUtils {
    public static boolean id6(int n) {
      return n > 0 && (n & (n - 1)) == 0;
    }

    public static int id18(int n) {
      if (n < 1) return 1;
      return id6(n) ? n : Integer.highestOneBit(n) << 1;
    }

  }

  static interface IntCollection {
  }

  static class QuickScanner {
    private static final int BUFFER_SIZE = 1024;
    private InputStream stream;
    private byte[] buffer;
    private int currentPosition;
    private int id7;

    public QuickScanner(InputStream stream) {
      this.stream = stream;
      this.buffer = new byte[BUFFER_SIZE];
      this.currentPosition = 0;
      this.id7 = 0;
    }

    public int nextInt() {
      int c = id8();
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
      } while (!id5(c));
      return positive ? res : -res;
    }

    public int id8() {
      int res = nextChar();
      for (; id5(res) || res < 0; res = nextChar()) ;
      return res;
    }

    public int nextChar() {
      if (id7 == -1) {
        throw new RuntimeException();
      }
      if (currentPosition >= id7) {
        currentPosition = 0;
        try {
          id7 = stream.read(buffer);
        } catch (Exception e) {
          throw new RuntimeException(e);
        }
        if (id7 <= 0) {
          return -1;
        }
      }
      return buffer[currentPosition++];
    }

    public boolean id5(int c) {
      return c == ' ' || c == '\t' || id16(c);
    }

    public boolean id16(int c) {
      return c == '\n' || c == '\r' || c < 0;
    }

  }
}

