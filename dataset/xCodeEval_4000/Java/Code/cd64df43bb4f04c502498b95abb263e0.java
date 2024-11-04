import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
    static int n = 100000;
    boolean[] upperCovered;
    boolean[] lowerCovered;
    IntHistoricalMinIntervalTree upperValue;
    IntHistoricalMinIntervalTree lowerValue;
    DisjointSet upperDset;
    DisjointSet lowerDset;
    IntMaxAndSumIntervalTreeSupportMinTrim upperTree;
    IntMaxAndSumIntervalTreeSupportMinTrim lowerTree;

    public void solve(int testNumber, QuickScanner in, QuickWriter out) {
      upperCovered = new boolean[n];
      upperValue = new IntHistoricalMinIntervalTree(n);
      upperDset = new DisjointSet(n);
      upperTree = new IntMaxAndSumIntervalTreeSupportMinTrim(n);

      lowerCovered = new boolean[n];
      lowerValue = new IntHistoricalMinIntervalTree(n);
      lowerDset = new DisjointSet(n);
      lowerTree = new IntMaxAndSumIntervalTreeSupportMinTrim(n);

      for (int remQuery = in.nextInt(); remQuery > 0; --remQuery) {
        int op = in.nextInt();
        int lower = in.nextInt() - 1;
        int upper = in.nextInt() - 1;
        if (op == 1) {
          update(lower, upper, in.nextInt());
        } else {
          out.println(upperTree.calc(lower, upper) + lowerTree.calc(lower, upper));
        }
      }
    }

    void update(int lower, int upper, int value) {
      if (value > 0) {
        cover(lower, upper, upperCovered, upperDset, upperValue, value);
        upperTree.update(lower, upper, value, false);
      } else {
        cover(lower, upper, lowerCovered, lowerDset, lowerValue, -value);
        lowerTree.update(lower, upper, -value, false);
      }
    }

    void cover(
        int lower, int upper, boolean[] covered, DisjointSet dset, IntHistoricalMinIntervalTree valueTree, int value) {

      valueTree.update(lower, upper, value);
      for (int i = lower; i < upper; i = dset.calcRoot(i + 1)) {
        if (i + 1 < upper) dset.setFriend(i + 1, i);
        if (covered[i]) continue;
        covered[i] = true;
        if (upperCovered[i] && lowerCovered[i]) {




          upperTree.update(i, i + 1, upperValue.calc(i), true);
          lowerTree.update(i, i + 1, lowerValue.calc(i), true);
        }
      }
    }

    public class IntHistoricalMinIntervalTree extends AbstractIntervalTreeWithLazyPropagation {
      int[] minValue;
      int[] setValue;
      int updateValue;

      public IntHistoricalMinIntervalTree(int leafCapacity) {
        super(leafCapacity);
      }


      public void createStorage(int nodeCapacity) {
        minValue = new int[nodeCapacity];
        setValue = new int[nodeCapacity];
      }


      public void initLeaf(int idxInTree, int idx) {
        minValue[idxInTree] = Integer.MAX_VALUE;
      }


      public void assignFakeLazyPropagation() {
        setValue[0] = updateValue;
      }


      public void pushLazyPropagation(int fromIdxInTree, int toIdxInTree) {
        setValue[toIdxInTree] = Math.min(setValue[toIdxInTree], setValue[fromIdxInTree]);
        minValue[toIdxInTree] = Math.min(minValue[toIdxInTree], setValue[toIdxInTree]);
      }


      public void clearLazyPropagation(int idxInTree) {
        setValue[idxInTree] = Integer.MAX_VALUE;
      }


      public void merge(int leftIdxInTree, int rightIdxInTree, int idxInTree) {
        minValue[idxInTree] = Math.min(minValue[leftIdxInTree], minValue[rightIdxInTree]);
      }


      public void copyForCalc(int fromIdxInTree, int toIdxInTree) {
        minValue[toIdxInTree] = minValue[fromIdxInTree];
      }


      public void clearNodeForCalc(int idxInTree) {
        minValue[idxInTree] = Integer.MAX_VALUE;
      }

      void update(int lower, int upper, int value) {
        updateValue = value;
        updateRange(lower, upper);
      }

      int calc(int idx) {
        calcRange(idx, idx + 1);
        return minValue[0];
      }

    }

    public class IntMaxAndSumIntervalTreeSupportMinTrim extends AbstractIntervalTreeWithLazyPropagation {
      private int[] maxValue;
      private int[] maxValueCnt;
      private int[] secondMaxValue;
      private long[] sum;
      private boolean cover;
      private int updateValue;

      public IntMaxAndSumIntervalTreeSupportMinTrim(int leafCapacity) {
        super(leafCapacity);
      }


      public void createStorage(int nodeCapacity) {
        maxValue = new int[nodeCapacity];
        maxValueCnt = new int[nodeCapacity];
        secondMaxValue = new int[nodeCapacity];
        sum = new long[nodeCapacity];
      }


      public void initLeaf(int idxInTree, int idx) {
        maxValue[idxInTree] = Integer.MIN_VALUE;
        maxValueCnt[idxInTree] = 0;
        secondMaxValue[idxInTree] = Integer.MIN_VALUE;
        sum[idxInTree] = 0;
      }


      public void assignFakeLazyPropagation() {
        maxValue[0] = updateValue;
      }


      public void pushLazyPropagation(int fromIdxInTree, int toIdxInTree) {
        if (cover && fromIdxInTree == 0 && rangeLength(toIdxInTree) == 1) {
          maxValue[toIdxInTree] = maxValue[0];
          maxValueCnt[toIdxInTree] = 1;
          secondMaxValue[toIdxInTree] = Integer.MIN_VALUE;
          sum[toIdxInTree] = maxValue[0];
          return;
        }
        if (maxValue[toIdxInTree] <= maxValue[fromIdxInTree]) return;
        if (secondMaxValue[toIdxInTree] < maxValue[fromIdxInTree]) {
          sum[toIdxInTree] -= (long) (maxValue[toIdxInTree] - maxValue[fromIdxInTree]) * maxValueCnt[toIdxInTree];
          maxValue[toIdxInTree] = maxValue[fromIdxInTree];
          return;
        }
        int leftIdxInTree = toIdxInTree << 1, rightIdxInTree = leftIdxInTree | 1;
        pushLazyPropagation(fromIdxInTree, leftIdxInTree);
        pushLazyPropagation(fromIdxInTree, rightIdxInTree);
        merge(leftIdxInTree, rightIdxInTree, toIdxInTree);
      }


      public void clearLazyPropagation(int idxInTree) {
      }


      public void merge(int leftIdxInTree, int rightIdxInTree, int idxInTree) {
        maxValue[idxInTree] = Math.max(maxValue[leftIdxInTree], maxValue[rightIdxInTree]);
        maxValueCnt[idxInTree] = (maxValue[idxInTree] == maxValue[leftIdxInTree] ? maxValueCnt[leftIdxInTree] : 0)
            + (maxValue[idxInTree] == maxValue[rightIdxInTree] ? maxValueCnt[rightIdxInTree] : 0);
        if (maxValue[leftIdxInTree] == maxValue[rightIdxInTree]) {
          secondMaxValue[idxInTree] = Math.max(secondMaxValue[leftIdxInTree], secondMaxValue[rightIdxInTree]);
        } else if (maxValue[leftIdxInTree] > maxValue[rightIdxInTree]) {
          secondMaxValue[idxInTree] = Math.max(secondMaxValue[leftIdxInTree], maxValue[rightIdxInTree]);
        } else {
          secondMaxValue[idxInTree] = Math.max(maxValue[leftIdxInTree], secondMaxValue[rightIdxInTree]);
        }
        sum[idxInTree] = sum[leftIdxInTree] + sum[rightIdxInTree];
      }


      public void copyForCalc(int fromIdxInTree, int toIdxInTree) {
        maxValue[toIdxInTree] = maxValue[fromIdxInTree];
        maxValueCnt[toIdxInTree] = maxValueCnt[fromIdxInTree];
        secondMaxValue[toIdxInTree] = secondMaxValue[fromIdxInTree];
        sum[toIdxInTree] = sum[fromIdxInTree];
      }


      public void clearNodeForCalc(int idxInTree) {
        maxValue[idxInTree] = secondMaxValue[idxInTree] = Integer.MIN_VALUE;
        maxValueCnt[idxInTree] = 0;
        sum[idxInTree] = 0;
      }

      public void update(int lower, int upper, int updateValue, boolean cover) {
        this.updateValue = updateValue;
        this.cover = cover;
        updateRange(lower, upper);
      }

      public long calc(int lower, int upper) {
        calcRange(lower, upper);
        return sum[0];
      }

    }

  }

  static interface IntCollection {
  }

  static class DisjointSet {
    public int[] parent;
    public int setCnt;

    public DisjointSet(int vertexCapacity) {
      this.parent = new int[vertexCapacity];
      init(vertexCapacity);
    }

    public void init(int n) {
      Arrays.fill(parent, 0, n, -1);
      setCnt = n;
    }

    public int calcRoot(int x) {
      int res = x;
      for (; parent[res] >= 0; res = parent[res]) {
      }
      shrink(x, res);
      return res;
    }

    public void setFriend(int x, int y) {
      int rootX = calcRoot(x);
      int rootY = calcRoot(y);
      if (rootX != rootY) {
        parent[rootX] += parent[rootY];
        parent[rootY] = rootX;
        --setCnt;
      }
    }

    private void shrink(int x, int root) {
      while (parent[x] >= 0) {
        int y = parent[x];
        parent[x] = root;
        x = y;
      }
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
      writer.println();
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
        res = res * 10 + (c - '0');
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

  static abstract class AbstractIntervalTreeWithLazyPropagation implements Displayable {
    private int nodeCapacity;
    private int leafCnt;
    private int height;
    private int[] rangeLower;
    private int[] rangeUpper;
    private IntArrayList idxInTreeToUpdate;
    private IntArrayList idxInTreeToUpdateAppendix;

    public abstract void createStorage(int nodeCapacity);

    public abstract void initLeaf(int idxInTree, int idx);

    public abstract void assignFakeLazyPropagation();

    public abstract void pushLazyPropagation(int fromIdxInTree, int toIdxInTree);

    public abstract void clearLazyPropagation(int idxInTree);

    public abstract void merge(int leftIdxInTree, int rightIdxInTree, int idxInTree);

    public abstract void copyForCalc(int fromIdxInTree, int toIdxInTree);

    public abstract void clearNodeForCalc(int idxInTree);

    public AbstractIntervalTreeWithLazyPropagation(int leafCapacity) {
      this(leafCapacity, true);
    }

    public AbstractIntervalTreeWithLazyPropagation(int leafCapacity, boolean initialize) {
      int height = 32 - Integer.numberOfLeadingZeros(leafCapacity);
      idxInTreeToUpdate = new IntArrayList(height << 1);
      idxInTreeToUpdateAppendix = new IntArrayList(height);
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
        clearLazyPropagation(i);
        clearLazyPropagation(i + leafCnt);
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
      assignFakeLazyPropagation();
      pushLazyPropagationToRange(lower, upper);
      boolean calcLeft = false, calcRight = false;
      for (lower += leafCnt, upper += leafCnt; lower < upper; lower >>= 1, upper >>= 1) {
        if (calcLeft) merge(lower - 1);
        if (calcRight) merge(upper);
        if ((lower & 1) > 0) {
          pushLazyPropagation(0, lower++);
          calcLeft = true;
        }
        if ((upper & 1) > 0) {
          pushLazyPropagation(0, --upper);
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
        clearNodeForCalc(0);
        return;
      }
      pushLazyPropagationToRange(lower, upper);
      idxInTreeToUpdate.clear();
      idxInTreeToUpdateAppendix.clear();
      for (lower += leafCnt, upper += leafCnt; lower < upper; lower >>= 1, upper >>= 1) {
        if ((lower & 1) > 0) {
          if (isValid(lower)) idxInTreeToUpdate.add(lower);
          ++lower;
        }
        if ((upper & 1) > 0) {
          if (isValid(--upper)) idxInTreeToUpdateAppendix.add(upper);
        }
      }
      idxInTreeToUpdateAppendix.reverse();
      idxInTreeToUpdate.addAll(idxInTreeToUpdateAppendix);
      int idxInTree = idxInTreeToUpdate.get(0);
      int resIdxInTree = nodeCapacity;
      copyForCalc(idxInTree, resIdxInTree);
      rangeLower[resIdxInTree] = rangeLower[idxInTree];
      rangeUpper[resIdxInTree] = rangeUpper[idxInTree];
      for (int i = 1; i < idxInTreeToUpdate.size; ++i, resIdxInTree ^= 1) {
        idxInTree = idxInTreeToUpdate.get(i);
        merge(resIdxInTree, idxInTree, resIdxInTree ^ 1);
        rangeLower[resIdxInTree ^ 1] = rangeLower[resIdxInTree];
        rangeUpper[resIdxInTree ^ 1] = rangeUpper[idxInTree];
      }
      copyForCalc(resIdxInTree, 0);
    }

    public int rangeLength(int idxInTree) {
      return rangeUpper[idxInTree] - rangeLower[idxInTree];
    }

    public boolean isValid(int idxInTree) {
      return rangeLower[idxInTree] < rangeUpper[idxInTree];
    }

    private void merge(int idxInTree) {
      merge(idxInTree << 1, (idxInTree << 1) | 1, idxInTree);
    }

    private void pushLazyPropagationToRange(int lower, int upper) {
      lower = (lower + leafCnt) >> 1;
      upper = (upper - 1 + leafCnt) >> 1;
      for (idxInTreeToUpdate.clear(); lower < upper; lower >>= 1, upper >>= 1) {
        if (isValid(lower)) idxInTreeToUpdate.add(lower);
        if (isValid(upper)) idxInTreeToUpdate.add(upper);
      }
      for (; lower > 0 && isValid(lower); lower >>= 1) {
        idxInTreeToUpdate.add(lower);
      }
      for (int i = idxInTreeToUpdate.size - 1; i >= 0; --i) {
        pushLazyPropagation(idxInTreeToUpdate.values[i]);
      }
    }

    private void pushLazyPropagation(int idxInTree) {
      pushLazyPropagation(idxInTree, idxInTree << 1);
      pushLazyPropagation(idxInTree, (idxInTree << 1) | 1);
      clearLazyPropagation(idxInTree);
    }

  }
}

