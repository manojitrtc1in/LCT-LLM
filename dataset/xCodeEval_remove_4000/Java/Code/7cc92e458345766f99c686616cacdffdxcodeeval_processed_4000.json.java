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
    id16 maxIT;
    TaskF.AreaIT areaIT;

    public void solve(int testNumber, QuickScanner in, QuickWriter out) {
      n = in.nextInt();
      query = in.nextInt();
      s = in.next(n);




      initH();
      id8();
      id0();
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
      for (int i = 1; i < n; ++i) H[i - 1] = id11(s[i - 1], s[i]);
    }

    int id11(String a, String b) {
      int length = Math.min(a.length(), b.length());
      for (int i = 0; i < length; ++i)
        if (a.charAt(i) != b.charAt(i)) {
          return i;
        }
      return length;
    }

    void id8() {
      int[] initLength = new int[n];
      for (int i = 0; i < n; ++i) initLength[i] = s[i].length();
      maxIT = new id16(n);
      maxIT.init(n, initLength);
    }

    void id0() {
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
        H[idx] = id11(s[idx], s[idx + 1]);
        lower = idx;
        upper = idx + 1;
      } else if (idx == n - 1) {
        H[idx - 1] = id11(s[idx - 1], s[idx]);
        lower = idx - 1;
        upper = idx;
      } else {
        H[idx - 1] = id11(s[idx - 1], s[idx]);
        H[idx] = id11(s[idx], s[idx + 1]);
        lower = idx - 1;
        upper = idx + 1;
      }
      areaIT.update(lower, upper);
    }

    static class AreaIT extends id1 {
      int[] H;
      id17[] leftH;
      id17[] leftD;
      id17[] rightH;
      id17[] rightD;
      int[] best;

      public AreaIT(int leafCapacity) {
        super(leafCapacity);
      }


      public void createStorage(int nodeCapacity) {
        leftH = new id17[nodeCapacity];
        leftD = new id17[nodeCapacity];
        rightH = new id17[nodeCapacity];
        rightD = new id17[nodeCapacity];
        best = new int[nodeCapacity];
        for (int i = 0; i < nodeCapacity; ++i) {
          leftH[i] = new id17();
          leftD[i] = new id17();
          rightH[i] = new id17();
          rightD[i] = new id17();
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


      public void merge(int idx, int leftIdx, int rightIdx) {
        id2(
            leftH[idx], leftD[idx],
            leftH[leftIdx], leftD[leftIdx],
            leftH[rightIdx], leftD[rightIdx]);
        id2(
            rightH[idx], rightD[idx],
            rightH[rightIdx], rightD[rightIdx],
            rightH[leftIdx], rightD[leftIdx]);
        best[idx] = Math.max(Math.max(Math.max(Math.max(
            best[leftIdx],
            best[rightIdx]),
            id18(
                rightH[leftIdx], rightD[leftIdx],
                leftH[rightIdx], leftD[rightIdx])),
            id12(leftH[idx], leftD[idx])),
            id12(rightH[idx], rightD[idx]));
      }


      public void copy(int destIdx, int sourceIdx) {
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
        id10(lower, upper);
      }

      public int calc(int lower, int upper) {
        calcRange(lower, upper);
        return best[0];
      }

      private void id2(
          id17 resH, id17 resD,
          id17 leftH, id17 leftD,
          id17 rightH, id17 rightD) {

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

      private int id12(id17 H, id17 D) {
        int sumD = 0;
        int res = 0;
        for (int i = 0; i < H.size; ++i) {
          sumD += D.get(i);
          res = Math.max(res, H.get(i) * (sumD + 1));
        }
        return res;
      }

      private int id18(
          id17 rightH, id17 rightD,
          id17 leftH, id17 leftD) {

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

  static class IntUtils {
    public static boolean id5(int n) {
      return n > 0 && (n & (n - 1)) == 0;
    }

    public static int id15(int n) {
      if (n < 1) return 1;
      return id5(n) ? n : Integer.highestOneBit(n) << 1;
    }

  }

  static class id16 extends id1 {
    private int[] values;
    private int[] maxValues;

    public id16(int leafCapacity) {
      super(leafCapacity);
    }


    public void init(int n) {
      throw new UnsupportedOperationException();
    }


    public void createStorage(int nodeCapacity) {
      maxValues = new int[nodeCapacity];
    }


    public void initLeaf(int nodeIdx, int idx) {
      maxValues[nodeIdx] = values[idx];
    }


    public void merge(int idx, int leftIdx, int rightIdx) {
      maxValues[idx] = Math.max(maxValues[leftIdx], maxValues[rightIdx]);
    }


    public void copy(int destIdx, int sourceIdx) {
      maxValues[destIdx] = maxValues[sourceIdx];
    }


    public void clearNode(int idx) {
      maxValues[idx] = Integer.MIN_VALUE;
    }

    public void init(int n, int[] values) {
      this.values = values;
      super.init(n);
    }

    public void update(int idx, int value) {
      maxValues[idx + leafCnt()] = value;
      id10(idx, idx + 1);
    }

    public int calc(int lower, int upper) {
      calcRange(lower, upper);
      return maxValues[0];
    }

  }

  static class id3 {
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

  static interface IntCollection {
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

  static abstract class id1 implements Displayable {
    private int nodeCapacity;
    private int leafCnt;
    private int[] rangeLower;
    private int[] rangeUpper;
    private id17 calcIdx;
    private id17 id14;

    public abstract void createStorage(int nodeCapacity);

    public abstract void initLeaf(int nodeIdx, int idx);

    public abstract void merge(int idx, int leftIdx, int rightIdx);

    public abstract void copy(int destIdx, int sourceIdx);

    public abstract void clearNode(int idx);

    public id1(int leafCapacity) {
      calcIdx = new id17();
      id14 = new id17();
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
        initLeaf(n + i, i);
      }
      for (int i = n - 1; i > 0; --i) {
        int left = i << 1, right = left | 1;
        if (rangeUpper[left] == rangeLower[right]) {
          rangeLower[i] = rangeLower[left];
          rangeUpper[i] = rangeUpper[right];
          merge(i, left, right);
        } else {
          rangeLower[i] = n;
          rangeUpper[i] = -1;
        }
      }
    }

    public void id10(int lower, int upper) {
      lower = (lower + leafCnt) >> 1;
      upper = (upper - 1 + leafCnt) >> 1;
      for (; lower > 0 && lower <= upper; lower >>= 1, upper >>= 1) {
        for (int nodeIdx = lower; nodeIdx <= upper; ++nodeIdx)
          if (id9(nodeIdx)) {
            merge(nodeIdx);
          }
      }
      for (; upper > 0 && id9(upper); upper >>= 1) {
        merge(upper);
      }
    }

    public void calcRange(int lower, int upper) {
      if (lower >= upper) {
        clearNode(0);
        return;
      }
      calcIdx.clear();
      id14.clear();
      for (lower += leafCnt, upper += leafCnt; lower < upper; lower >>= 1, upper >>= 1) {
        if ((lower & 1) > 0) {
          if (id9(lower)) calcIdx.add(lower);
          ++lower;
        }
        if ((upper & 1) > 0) {
          if (id9(--upper)) id14.add(upper);
        }
      }
      id14.reverse();
      calcIdx.addAll(id14);
      int idx = calcIdx.get(0);
      int resIdx = nodeCapacity;
      copy(resIdx, idx);
      rangeLower[resIdx] = rangeLower[idx];
      rangeUpper[resIdx] = rangeUpper[idx];
      for (int i = 1; i < calcIdx.size; ++i, resIdx ^= 1) {
        idx = calcIdx.get(i);
        merge(resIdx ^ 1, resIdx, idx);
        rangeLower[resIdx ^ 1] = rangeLower[resIdx];
        rangeUpper[resIdx ^ 1] = rangeUpper[idx];
      }
      copy(0, resIdx);
    }

    public int leafCnt() {
      return leafCnt;
    }

    public boolean id9(int idx) {
      return rangeLower[idx] < rangeUpper[idx];
    }

    private void merge(int idx) {
      merge(idx, idx << 1, (idx << 1) | 1);
    }

  }

  static class id17 implements Displayable, IntCollection, Iterable<Integer> {
    private static final int[] EMPTY = {};
    public int[] values;
    public int size;

    public id17() {
      values = EMPTY;
      clear();
    }

    public id17(int capacity) {
      values = new int[IntUtils.id15(capacity)];
      clear();
    }

    public id17(Collection<Integer> collection) {
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

    public void addAll(id17 values) {
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
      id3.reverse(values, 0, size);
    }

    public void ensureCapacity(int capacity) {
      if (capacity <= values.length) return;
      int[] newValues = new int[IntUtils.id15(capacity)];
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

  static interface Displayable {
  }

  static class QuickScanner {
    private static final int BUFFER_SIZE = 1024;
    private InputStream stream;
    private byte[] buffer;
    private int currentPosition;
    private int id6;

    public QuickScanner(InputStream stream) {
      this.stream = stream;
      this.buffer = new byte[BUFFER_SIZE];
      this.currentPosition = 0;
      this.id6 = 0;
    }

    public String next() {
      int b = id7();
      StringBuilder res = new StringBuilder();
      do {
        res.appendCodePoint(b);
        b = nextChar();
      } while (!id4(b));
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
      int c = id7();
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
      } while (!id4(c));
      return positive ? res : -res;
    }

    public int id7() {
      int res = nextChar();
      for (; id4(res) || res < 0; res = nextChar()) ;
      return res;
    }

    public int nextChar() {
      if (id6 == -1) {
        throw new RuntimeException();
      }
      if (currentPosition >= id6) {
        currentPosition = 0;
        try {
          id6 = stream.read(buffer);
        } catch (Exception e) {
          throw new RuntimeException(e);
        }
        if (id6 <= 0) {
          return -1;
        }
      }
      return buffer[currentPosition++];
    }

    public boolean id4(int c) {
      return c == ' ' || c == '\t' || id13(c);
    }

    public boolean id13(int c) {
      return c == '\n' || c == '\r' || c < 0;
    }

  }
}

