import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.Collection;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;


public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    QuickScanner in = new QuickScanner(inputStream);
    QuickWriter out = new QuickWriter(outputStream);
    TaskF solver = new TaskF();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskF {
    int n;
    int query;
    String[] s;
    int[] H;
    IntMaxIntervalTree maxIT;
    TaskF.AreaIT areaIT;

    public void solve(int testNumber, QuickScanner in, QuickWriter out) {
      n = in.nextInt();
      query = in.nextInt();
      s = in.next(n);
      initH();
      initMaxIT();
      initAreaIT();
      for (int remQ = query; remQ > 0; --remQ) {
        int op = in.nextInt();
        if (op == 1) {
          int lower = in.nextInt() - 1;
          int upper = in.nextInt();
          out.println(calc(lower, upper));
        } else {
          int idx = in.nextInt() - 1;
          s[idx] = in.next();
          update(idx);
        }
      }
    }

    void initH() {
      H = new int[n - 1];
      for (int i = 1; i < n; ++i) H[i - 1] = calcLCP(s[i - 1], s[i]);
    }

    int calcLCP(String a, String b) {
      int length = Math.min(a.length(), b.length());
      for (int i = 0; i < length; ++i)
        if (a.charAt(i) != b.charAt(i)) {
          return i;
        }
      return length;
    }

    void initMaxIT() {
      int[] initLength = new int[n];
      for (int i = 0; i < n; ++i) initLength[i] = s[i].length();
      maxIT = new IntMaxIntervalTree(n);
      maxIT.init(n, initLength);
    }

    void initAreaIT() {
      areaIT = new TaskF.AreaIT(n - 1);
      areaIT.init(n - 1, H);
    }

    int calc(int lower, int upper) {
      int res = maxIT.calc(lower, upper);
      if (lower < upper) {
        res = Math.max(res, areaIT.calc(lower, upper - 1));
      }
      return res;
    }

    void update(int idx) {
      maxIT.update(idx, s[idx].length());
      if (n == 1) return;
      int lower, upper;
      if (idx == 0) {
        H[idx] = calcLCP(s[idx], s[idx + 1]);
        lower = idx;
        upper = idx + 1;
      } else if (idx == n - 1) {
        H[idx - 1] = calcLCP(s[idx - 1], s[idx]);
        lower = idx - 1;
        upper = idx;
      } else {
        H[idx - 1] = calcLCP(s[idx - 1], s[idx]);
        H[idx] = calcLCP(s[idx], s[idx + 1]);
        lower = idx - 1;
        upper = idx + 1;
      }
      areaIT.update(lower, upper);
    }

    static class AreaIT extends AbstractIntervalTree {
      int[] H;
      IntArrayList[] leftH;
      IntArrayList[] leftD;
      IntArrayList[] rightH;
      IntArrayList[] rightD;
      int[] best;

      public AreaIT(int leafCapacity) {
        super(leafCapacity);
      }


      public void createStorage(int nodeCapacity) {
        leftH = new IntArrayList[nodeCapacity];
        leftD = new IntArrayList[nodeCapacity];
        rightH = new IntArrayList[nodeCapacity];
        rightD = new IntArrayList[nodeCapacity];
        best = new int[nodeCapacity];
        for (int i = 0; i < nodeCapacity; ++i) {
          leftH[i] = new IntArrayList();
          leftD[i] = new IntArrayList();
          rightH[i] = new IntArrayList();
          rightD[i] = new IntArrayList();
        }
      }


      public void initLeaf(int nodeIdx, int idx) {
        leftH[nodeIdx].clear();
        leftD[nodeIdx].clear();
        leftH[nodeIdx].add(H[idx]);
        leftD[nodeIdx].add(1);
        rightH[nodeIdx].clear();
        rightD[nodeIdx].clear();
        rightH[nodeIdx].add(H[idx]);
        rightD[nodeIdx].add(1);
        best[nodeIdx] = H[idx] << 1;
      }


      public void merge(int leftIdx, int rightIdx, int idx) {
        mergeOneSide(
            leftH[idx], leftD[idx],
            leftH[leftIdx], leftD[leftIdx],
            leftH[rightIdx], leftD[rightIdx]);
        mergeOneSide(
            rightH[idx], rightD[idx],
            rightH[rightIdx], rightD[rightIdx],
            rightH[leftIdx], rightD[leftIdx]);
        best[idx] = Math.max(Math.max(Math.max(Math.max(
            best[leftIdx],
            best[rightIdx]),
            calcTwoSide(
                rightH[leftIdx], rightD[leftIdx],
                leftH[rightIdx], leftD[rightIdx])),
            calcOneSide(leftH[idx], leftD[idx])),
            calcOneSide(rightH[idx], rightD[idx]));
      }


      public void copyForCalc(int sourceIdx, int destIdx) {
        leftD[destIdx].clear();
        leftD[destIdx].addAll(leftD[sourceIdx]);
        leftH[destIdx].clear();
        leftH[destIdx].addAll(leftH[sourceIdx]);
        rightD[destIdx].clear();
        rightD[destIdx].addAll(rightD[sourceIdx]);
        rightH[destIdx].clear();
        rightH[destIdx].addAll(rightH[sourceIdx]);
        best[destIdx] = best[sourceIdx];
      }


      public void clearNode(int idx) {
        leftD[idx].clear();
        leftH[idx].clear();
        rightD[idx].clear();
        rightH[idx].clear();
        best[idx] = 0;
      }

      public void init(int n, int[] H) {
        this.H = H;
        super.init(n);
      }

      public void update(int lower, int upper) {
        for (int i = lower; i < upper; ++i) {
          initLeaf(i + leafCnt(), i);
        }
        populateRangeUpdateToRoot(lower, upper);
      }

      public int calc(int lower, int upper) {
        calcRange(lower, upper);
        return best[0];
      }

      private void mergeOneSide(
          IntArrayList resH, IntArrayList resD,
          IntArrayList leftH, IntArrayList leftD,
          IntArrayList rightH, IntArrayList rightD) {

        resH.clear();
        resD.clear();
        resH.addAll(leftH);
        resD.addAll(leftD);
        for (int i = 0; i < rightH.size; ++i) {
          int h = rightH.get(i);
          int d = rightD.get(i);
          if (h >= resH.peekLast()) {
            resD.add(resD.pollLast() + d);
          } else {
            resH.add(h);
            resD.add(d);
          }
        }
      }

      private int calcOneSide(IntArrayList H, IntArrayList D) {
        int sumD = 0;
        int res = 0;
        for (int i = 0; i < H.size; ++i) {
          sumD += D.get(i);
          res = Math.max(res, H.get(i) * (sumD + 1));
        }
        return res;
      }

      private int calcTwoSide(
          IntArrayList rightH, IntArrayList rightD,
          IntArrayList leftH, IntArrayList leftD) {

        int i = 0, j = 0;
        int sumD = 0;
        int res = 0;
        while (i < rightH.size && j < leftH.size) {
          int rh = rightH.get(i), lh = leftH.get(j);
          if (rh > lh) {
            sumD += rightD.get(i++);
            res = Math.max(res, rh * (sumD + 1));
          } else {
            sumD += leftD.get(j++);
            res = Math.max(res, lh * (sumD + 1));
          }
        }
        for (; i < rightH.size; ++i) {
          sumD += rightD.get(i);
          res = Math.max(res, rightH.get(i) * (sumD + 1));
        }
        for (; j < leftH.size; ++j) {
          sumD += leftD.get(j);
          res = Math.max(res, leftH.get(j) * (sumD + 1));
        }
        return res;
      }

    }

  }

  static abstract class AbstractIntervalTree implements Displayable {
    private int nodeCapacity;
    private int leafCnt;
    private int[] rangeLower;
    private int[] rangeUpper;
    private IntArrayList calcIdxInTree;
    private IntArrayList calcIdxInTreeAppendix;

    public abstract void createStorage(int nodeCapacity);

    public abstract void initLeaf(int idxInTree, int idx);

    public abstract void merge(int leftIdxInTree, int rightIdxInTree, int idxInTree);

    public abstract void copyForCalc(int fromIdxInTree, int toIdxInTree);

    public abstract void clearNode(int idx);

    public AbstractIntervalTree(int leafCapacity) {
      calcIdxInTree = new IntArrayList();
      calcIdxInTreeAppendix = new IntArrayList();
      nodeCapacity = leafCapacity << 1;
      rangeLower = new int[nodeCapacity + 2];
      rangeUpper = new int[nodeCapacity + 2];
      createStorage(nodeCapacity + 2);
    }

    public void init(int n) {
      this.leafCnt = n;
      for (int i = 0; i < n; ++i) {
        rangeLower[n + i] = i;
        rangeUpper[n + i] = i + 1;
        initLeaf(i + leafCnt, i);
      }
      for (int i = n - 1; i > 0; --i) {
        int left = i << 1, right = left | 1;
        if (rangeUpper[left] == rangeLower[right]) {
          rangeLower[i] = rangeLower[left];
          rangeUpper[i] = rangeUpper[right];
          merge(left, right, i);
        } else {
          rangeLower[i] = n;
          rangeUpper[i] = -1;
        }
      }
    }

    public void populateRangeUpdateToRoot(int lower, int upper) {
      lower = (lower + leafCnt) >> 1;
      upper = (upper - 1 + leafCnt) >> 1;
      for (; lower > 0 && lower <= upper; lower >>= 1, upper >>= 1) {
        for (int idxInTree = lower; idxInTree <= upper; ++idxInTree)
          if (isValidNode(idxInTree)) {
            merge(idxInTree);
          }
      }
      for (; upper > 0 && isValidNode(upper); upper >>= 1) {
        merge(upper);
      }
    }

    public void calcRange(int lower, int upper) {
      if (lower >= upper) {
        clearNode(0);
        return;
      }
      calcIdxInTree.clear();
      calcIdxInTreeAppendix.clear();
      for (lower += leafCnt, upper += leafCnt; lower < upper; lower >>= 1, upper >>= 1) {
        if ((lower & 1) > 0) {
          if (isValidNode(lower)) calcIdxInTree.add(lower);
          ++lower;
        }
        if ((upper & 1) > 0) {
          if (isValidNode(--upper)) calcIdxInTreeAppendix.add(upper);
        }
      }
      calcIdxInTreeAppendix.reverse();
      calcIdxInTree.addAll(calcIdxInTreeAppendix);
      int idxInTree = calcIdxInTree.get(0);
      int resIdxInTree = nodeCapacity;
      copyForCalc(idxInTree, resIdxInTree);
      rangeLower[resIdxInTree] = rangeLower[idxInTree];
      rangeUpper[resIdxInTree] = rangeUpper[idxInTree];
      for (int i = 1; i < calcIdxInTree.size; ++i, resIdxInTree ^= 1) {
        idxInTree = calcIdxInTree.get(i);
        merge(resIdxInTree, idxInTree, resIdxInTree ^ 1);
        rangeLower[resIdxInTree ^ 1] = rangeLower[resIdxInTree];
        rangeUpper[resIdxInTree ^ 1] = rangeUpper[idxInTree];
      }
      copyForCalc(resIdxInTree, 0);
    }

    public int leafCnt() {
      return leafCnt;
    }

    public int idxInTree(int idx) {
      return idx + leafCnt;
    }

    public boolean isValidNode(int idxInTree) {
      return rangeLower[idxInTree] < rangeUpper[idxInTree];
    }

    private void merge(int idxInTree) {
      merge(idxInTree << 1, (idxInTree << 1) | 1, idxInTree);
    }

  }

  static interface IntCollection {
  }

  static class IntMaxIntervalTree extends AbstractIntervalTree {
    private int[] values;
    private int[] maxValues;

    public IntMaxIntervalTree(int leafCapacity) {
      super(leafCapacity);
    }


    public void init(int n) {
      throw new UnsupportedOperationException();
    }


    public void createStorage(int nodeCapacity) {
      maxValues = new int[nodeCapacity];
    }


    public void initLeaf(int idxInTree, int idx) {
      maxValues[idxInTree] = values[idx];
    }


    public void merge(int leftIdxInTree, int rightIdxInTree, int idxInTree) {
      maxValues[idxInTree] = Math.max(
          maxValues[leftIdxInTree], maxValues[rightIdxInTree]);
    }


    public void copyForCalc(int fromIdxInTree, int toIdxInTree) {
      maxValues[toIdxInTree] = maxValues[fromIdxInTree];
    }


    public void clearNode(int idxInTree) {
      maxValues[idxInTree] = Integer.MIN_VALUE;
    }

    public void init(int n, int[] values) {
      this.values = values;
      super.init(n);
    }

    public void update(int idx, int value) {
      maxValues[idxInTree(idx)] = value;
      populateRangeUpdateToRoot(idx, idx + 1);
    }

    public int calc(int lower, int upper) {
      calcRange(lower, upper);
      return maxValues[0];
    }

  }

  static interface Displayable {
  }

  static class IntArrayList implements Displayable, IntCollection, Iterable<Integer> {
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

    public void addAll(IntArrayList values) {
      ensureCapacity(size + values.size);
      for (int i = 0; i < values.size; ++i) {
        addInternal(values.get(i));
      }
    }

    public int peekLast() {
      return values[size - 1];
    }

    public int pollLast() {
      return values[--size];
    }

    public int get(int idx) {
      if (idx >= size) throw new ArrayIndexOutOfBoundsException();
      return values[idx];
    }

    public void reverse() {
      IntArrayUtils.reverse(values, 0, size);
    }

    public void ensureCapacity(int capacity) {
      if (capacity <= values.length) return;
      int[] newValues = new int[IntUtils.nextPow2(capacity)];
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

  static class IntArrayUtils {
    public static void reverse(int[] values, int fromIdx, int toIdx) {
      for (int i = fromIdx, j = toIdx - 1; i < j; ++i, --j) {
        swap(values, i, j);
      }
    }

    public static void swap(int[] values, int uIdx, int vIdx) {
      if (uIdx == vIdx) return;
      values[uIdx] ^= values[vIdx];
      values[vIdx] ^= values[uIdx];
      values[uIdx] ^= values[vIdx];
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

    public String next() {
      int b = nextNonSpaceChar();
      StringBuilder res = new StringBuilder();
      do {
        res.appendCodePoint(b);
        b = nextChar();
      } while (!isSpaceChar(b));
      return res.toString();
    }

    public String[] next(int n) {
      String[] res = new String[n];
      next(n, res);
      return res;
    }

    public void next(int n, String[] res) {
      for (int i = 0; i < n; ++i) {
        res[i] = next();
      }
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

  static class IntUtils {
    public static boolean isPow2(int n) {
      return n > 0 && (n & (n - 1)) == 0;
    }

    public static int nextPow2(int n) {
      if (n < 1) return 1;
      return isPow2(n) ? n : Integer.highestOneBit(n) << 1;
    }

  }
}

