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
    id26 upperValue;
    id26 lowerValue;
    id15 id17;
    id15 id19;
    id18 upperTree;
    id18 lowerTree;

    public void solve(int testNumber, QuickScanner in, QuickWriter out) {
      upperCovered = new boolean[n];
      upperValue = new id26(n);
      id17 = new id15(n);
      upperTree = new id18(n);

      lowerCovered = new boolean[n];
      lowerValue = new id26(n);
      id19 = new id15(n);
      lowerTree = new id18(n);

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
        cover(lower, upper, upperCovered, id17, upperValue, value);
        upperTree.update(lower, upper, value, false);
      } else {
        cover(lower, upper, lowerCovered, id19, lowerValue, -value);
        lowerTree.update(lower, upper, -value, false);
      }
    }

    void cover(
        int lower, int upper, boolean[] covered, id15 dset, id26 valueTree, int value) {

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

    public class id26 extends id12 {
      int[] minValue;
      int[] setValue;
      int updateValue;

      public id26(int leafCapacity) {
        super(leafCapacity);
      }


      public void createStorage(int nodeCapacity) {
        minValue = new int[nodeCapacity];
        setValue = new int[nodeCapacity];
      }


      public void initLeaf(int id2, int idx) {
        minValue[id2] = Integer.MAX_VALUE;
      }


      public void id14() {
        setValue[0] = updateValue;
      }


      public void id11(int id22, int id28) {
        setValue[id28] = Math.min(setValue[id28], setValue[id22]);
        minValue[id28] = Math.min(minValue[id28], setValue[id28]);
      }


      public void id3(int id2) {
        setValue[id2] = Integer.MAX_VALUE;
      }


      public void merge(int id4, int id20, int id2) {
        minValue[id2] = Math.min(minValue[id4], minValue[id20]);
      }


      public void id29(int id22, int id28) {
        minValue[id28] = minValue[id22];
      }


      public void id10(int id2) {
        minValue[id2] = Integer.MAX_VALUE;
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

    public class id18 extends id12 {
      private int[] maxValue;
      private int[] id13;
      private int[] id16;
      private long[] sum;
      private boolean cover;
      private int updateValue;

      public id18(int leafCapacity) {
        super(leafCapacity);
      }


      public void createStorage(int nodeCapacity) {
        maxValue = new int[nodeCapacity];
        id13 = new int[nodeCapacity];
        id16 = new int[nodeCapacity];
        sum = new long[nodeCapacity];
      }


      public void initLeaf(int id2, int idx) {
        maxValue[id2] = Integer.MIN_VALUE;
        id13[id2] = 0;
        id16[id2] = Integer.MIN_VALUE;
        sum[id2] = 0;
      }


      public void id14() {
        maxValue[0] = updateValue;
      }


      public void id11(int id22, int id28) {
        if (cover && id22 == 0 && rangeLength(id28) == 1) {
          maxValue[id28] = maxValue[0];
          id13[id28] = 1;
          id16[id28] = Integer.MIN_VALUE;
          sum[id28] = maxValue[0];
          return;
        }
        if (maxValue[id28] <= maxValue[id22]) return;
        if (id16[id28] < maxValue[id22]) {
          sum[id28] -= (long) (maxValue[id28] - maxValue[id22]) * id13[id28];
          maxValue[id28] = maxValue[id22];
          return;
        }
        int id4 = id28 << 1, id20 = id4 | 1;
        id11(id22, id4);
        id11(id22, id20);
        merge(id4, id20, id28);
      }


      public void id3(int id2) {
      }


      public void merge(int id4, int id20, int id2) {
        maxValue[id2] = Math.max(maxValue[id4], maxValue[id20]);
        id13[id2] = (maxValue[id2] == maxValue[id4] ? id13[id4] : 0)
            + (maxValue[id2] == maxValue[id20] ? id13[id20] : 0);
        if (maxValue[id4] == maxValue[id20]) {
          id16[id2] = Math.max(id16[id4], id16[id20]);
        } else if (maxValue[id4] > maxValue[id20]) {
          id16[id2] = Math.max(id16[id4], maxValue[id20]);
        } else {
          id16[id2] = Math.max(maxValue[id4], id16[id20]);
        }
        sum[id2] = sum[id4] + sum[id20];
      }


      public void id29(int id22, int id28) {
        maxValue[id28] = maxValue[id22];
        id13[id28] = id13[id22];
        id16[id28] = id16[id22];
        sum[id28] = sum[id22];
      }


      public void id10(int id2) {
        maxValue[id2] = id16[id2] = Integer.MIN_VALUE;
        id13[id2] = 0;
        sum[id2] = 0;
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

  static class id15 {
    public int[] parent;
    public int setCnt;

    public id15(int vertexCapacity) {
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

    public void reverse() {
      id5.reverse(values, 0, size);
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

  static class id5 {
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
    public static boolean id7(int n) {
      return n > 0 && (n & (n - 1)) == 0;
    }

    public static int id25(int n) {
      if (n < 1) return 1;
      return id7(n) ? n : Integer.highestOneBit(n) << 1;
    }

  }

  static class QuickScanner {
    private static final int BUFFER_SIZE = 1024;
    private InputStream stream;
    private byte[] buffer;
    private int currentPosition;
    private int id8;

    public QuickScanner(InputStream stream) {
      this.stream = stream;
      this.buffer = new byte[BUFFER_SIZE];
      this.currentPosition = 0;
      this.id8 = 0;
    }

    public int nextInt() {
      int c = id9();
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
      } while (!id6(c));
      return positive ? res : -res;
    }

    public int id9() {
      int res = nextChar();
      for (; id6(res) || res < 0; res = nextChar()) ;
      return res;
    }

    public int nextChar() {
      if (id8 == -1) {
        throw new RuntimeException();
      }
      if (currentPosition >= id8) {
        currentPosition = 0;
        try {
          id8 = stream.read(buffer);
        } catch (Exception e) {
          throw new RuntimeException(e);
        }
        if (id8 <= 0) {
          return -1;
        }
      }
      return buffer[currentPosition++];
    }

    public boolean id6(int c) {
      return c == ' ' || c == '\t' || id24(c);
    }

    public boolean id24(int c) {
      return c == '\n' || c == '\r' || c < 0;
    }

  }

  static abstract class id12 implements Displayable {
    private int nodeCapacity;
    private int leafCnt;
    private int height;
    private int[] rangeLower;
    private int[] rangeUpper;
    private id27 id23;
    private id27 id0;

    public abstract void createStorage(int nodeCapacity);

    public abstract void initLeaf(int id2, int idx);

    public abstract void id14();

    public abstract void id11(int id22, int id28);

    public abstract void id3(int id2);

    public abstract void merge(int id4, int id20, int id2);

    public abstract void id29(int id22, int id28);

    public abstract void id10(int id2);

    public id12(int leafCapacity) {
      this(leafCapacity, true);
    }

    public id12(int leafCapacity, boolean initialize) {
      int height = 32 - Integer.numberOfLeadingZeros(leafCapacity);
      id23 = new id27(height << 1);
      id0 = new id27(height);
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
        id3(i);
        id3(i + leafCnt);
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
      id14();
      id21(lower, upper);
      boolean calcLeft = false, calcRight = false;
      for (lower += leafCnt, upper += leafCnt; lower < upper; lower >>= 1, upper >>= 1) {
        if (calcLeft) merge(lower - 1);
        if (calcRight) merge(upper);
        if ((lower & 1) > 0) {
          id11(0, lower++);
          calcLeft = true;
        }
        if ((upper & 1) > 0) {
          id11(0, --upper);
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
        id10(0);
        return;
      }
      id21(lower, upper);
      id23.clear();
      id0.clear();
      for (lower += leafCnt, upper += leafCnt; lower < upper; lower >>= 1, upper >>= 1) {
        if ((lower & 1) > 0) {
          if (isValid(lower)) id23.add(lower);
          ++lower;
        }
        if ((upper & 1) > 0) {
          if (isValid(--upper)) id0.add(upper);
        }
      }
      id0.reverse();
      id23.addAll(id0);
      int id2 = id23.get(0);
      int id1 = nodeCapacity;
      id29(id2, id1);
      rangeLower[id1] = rangeLower[id2];
      rangeUpper[id1] = rangeUpper[id2];
      for (int i = 1; i < id23.size; ++i, id1 ^= 1) {
        id2 = id23.get(i);
        merge(id1, id2, id1 ^ 1);
        rangeLower[id1 ^ 1] = rangeLower[id1];
        rangeUpper[id1 ^ 1] = rangeUpper[id2];
      }
      id29(id1, 0);
    }

    public int rangeLength(int id2) {
      return rangeUpper[id2] - rangeLower[id2];
    }

    public boolean isValid(int id2) {
      return rangeLower[id2] < rangeUpper[id2];
    }

    private void merge(int id2) {
      merge(id2 << 1, (id2 << 1) | 1, id2);
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
        id11(id23.values[i]);
      }
    }

    private void id11(int id2) {
      id11(id2, id2 << 1);
      id11(id2, (id2 << 1) | 1);
      id3(id2);
    }

  }
}

