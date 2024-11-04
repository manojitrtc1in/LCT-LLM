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
    id22 maxIT;
    TaskF.AreaIT areaIT;

    public void solve(int testNumber, QuickScanner in, QuickWriter out) {
      n = in.nextInt();
      query = in.nextInt();
      s = in.next(n);
      initH();
      id11();
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
      for (int i = 1; i < n; ++i) H[i - 1] = id14(s[i - 1], s[i]);
    }

    int id14(String a, String b) {
      int length = Math.min(a.length(), b.length());
      for (int i = 0; i < length; ++i)
        if (a.charAt(i) != b.charAt(i)) {
          return i;
        }
      return length;
    }

    void id11() {
      int[] initLength = new int[n];
      for (int i = 0; i < n; ++i) initLength[i] = s[i].length();
      maxIT = new id22(n);
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
        H[idx] = id14(s[idx], s[idx + 1]);
        lower = idx;
        upper = idx + 1;
      } else if (idx == n - 1) {
        H[idx - 1] = id14(s[idx - 1], s[idx]);
        lower = idx - 1;
        upper = idx;
      } else {
        H[idx - 1] = id14(s[idx - 1], s[idx]);
        H[idx] = id14(s[idx], s[idx + 1]);
        lower = idx - 1;
        upper = idx + 1;
      }
      areaIT.update(lower, upper);
    }

    static class AreaIT extends id1 {
      int[] H;
      id23[] leftH;
      id23[] leftD;
      id23[] rightH;
      id23[] rightD;
      int[] best;

      public AreaIT(int leafCapacity) {
        super(leafCapacity);
      }


      public void createStorage(int nodeCapacity) {
        leftH = new id23[nodeCapacity];
        leftD = new id23[nodeCapacity];
        rightH = new id23[nodeCapacity];
        rightD = new id23[nodeCapacity];
        best = new int[nodeCapacity];
        for (int i = 0; i < nodeCapacity; ++i) {
          leftH[i] = new id23();
          leftD[i] = new id23();
          rightH[i] = new id23();
          rightD[i] = new id23();
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
        id4(
            leftH[idx], leftD[idx],
            leftH[leftIdx], leftD[leftIdx],
            leftH[rightIdx], leftD[rightIdx]);
        id4(
            rightH[idx], rightD[idx],
            rightH[rightIdx], rightD[rightIdx],
            rightH[leftIdx], rightD[leftIdx]);
        best[idx] = Math.max(Math.max(Math.max(Math.max(
            best[leftIdx],
            best[rightIdx]),
            id24(
                rightH[leftIdx], rightD[leftIdx],
                leftH[rightIdx], leftD[rightIdx])),
            id17(leftH[idx], leftD[idx])),
            id17(rightH[idx], rightD[idx]));
      }


      public void id26(int sourceIdx, int destIdx) {
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
        id13(lower, upper);
      }

      public int calc(int lower, int upper) {
        calcRange(lower, upper);
        return best[0];
      }

      private void id4(
          id23 resH, id23 resD,
          id23 leftH, id23 leftD,
          id23 rightH, id23 rightD) {

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

      private int id17(id23 H, id23 D) {
        int sumD = 0;
        int res = 0;
        for (int i = 0; i < H.size; ++i) {
          sumD += D.get(i);
          res = Math.max(res, H.get(i) * (sumD + 1));
        }
        return res;
      }

      private int id24(
          id23 rightH, id23 rightD,
          id23 leftH, id23 leftD) {

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

  static abstract class id1 implements Displayable {
    private int nodeCapacity;
    private int leafCnt;
    private int[] rangeLower;
    private int[] rangeUpper;
    private id23 id20;
    private id23 id19;

    public abstract void createStorage(int nodeCapacity);

    public abstract void initLeaf(int id3, int idx);

    public abstract void merge(int id5, int id15, int id3);

    public abstract void id26(int id16, int id25);

    public abstract void clearNode(int idx);

    public id1(int leafCapacity) {
      id20 = new id23();
      id19 = new id23();
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

    public void id13(int lower, int upper) {
      lower = (lower + leafCnt) >> 1;
      upper = (upper - 1 + leafCnt) >> 1;
      for (; lower > 0 && lower <= upper; lower >>= 1, upper >>= 1) {
        for (int id3 = lower; id3 <= upper; ++id3)
          if (id12(id3)) {
            merge(id3);
          }
      }
      for (; upper > 0 && id12(upper); upper >>= 1) {
        merge(upper);
      }
    }

    public void calcRange(int lower, int upper) {
      if (lower >= upper) {
        clearNode(0);
        return;
      }
      id20.clear();
      id19.clear();
      for (lower += leafCnt, upper += leafCnt; lower < upper; lower >>= 1, upper >>= 1) {
        if ((lower & 1) > 0) {
          if (id12(lower)) id20.add(lower);
          ++lower;
        }
        if ((upper & 1) > 0) {
          if (id12(--upper)) id19.add(upper);
        }
      }
      id19.reverse();
      id20.addAll(id19);
      int id3 = id20.get(0);
      int id2 = nodeCapacity;
      id26(id3, id2);
      rangeLower[id2] = rangeLower[id3];
      rangeUpper[id2] = rangeUpper[id3];
      for (int i = 1; i < id20.size; ++i, id2 ^= 1) {
        id3 = id20.get(i);
        merge(id2, id3, id2 ^ 1);
        rangeLower[id2 ^ 1] = rangeLower[id2];
        rangeUpper[id2 ^ 1] = rangeUpper[id3];
      }
      id26(id2, 0);
    }

    public int leafCnt() {
      return leafCnt;
    }

    public int id3(int idx) {
      return idx + leafCnt;
    }

    public boolean id12(int id3) {
      return rangeLower[id3] < rangeUpper[id3];
    }

    private void merge(int id3) {
      merge(id3 << 1, (id3 << 1) | 1, id3);
    }

  }

  static interface IntCollection {
  }

  static class id22 extends id1 {
    private int[] values;
    private int[] maxValues;

    public id22(int leafCapacity) {
      super(leafCapacity);
    }


    public void init(int n) {
      throw new UnsupportedOperationException();
    }


    public void createStorage(int nodeCapacity) {
      maxValues = new int[nodeCapacity];
    }


    public void initLeaf(int id3, int idx) {
      maxValues[id3] = values[idx];
    }


    public void merge(int id5, int id15, int id3) {
      maxValues[id3] = Math.max(
          maxValues[id5], maxValues[id15]);
    }


    public void id26(int id16, int id25) {
      maxValues[id25] = maxValues[id16];
    }


    public void clearNode(int id3) {
      maxValues[id3] = Integer.MIN_VALUE;
    }

    public void init(int n, int[] values) {
      this.values = values;
      super.init(n);
    }

    public void update(int idx, int value) {
      maxValues[id3(idx)] = value;
      id13(idx, idx + 1);
    }

    public int calc(int lower, int upper) {
      calcRange(lower, upper);
      return maxValues[0];
    }

  }

  static interface Displayable {
  }

  static class id23 implements Displayable, IntCollection, Iterable<Integer> {
    private static final int[] EMPTY = {};
    public int[] values;
    public int size;

    public id23() {
      values = EMPTY;
      clear();
    }

    public id23(int capacity) {
      values = new int[IntUtils.id21(capacity)];
      clear();
    }

    public id23(Collection<Integer> collection) {
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

    public void addAll(id23 values) {
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
      id6.reverse(values, 0, size);
    }

    public void ensureCapacity(int capacity) {
      if (capacity <= values.length) return;
      int[] newValues = new int[IntUtils.id21(capacity)];
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

  static class id6 {
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
    private int id9;

    public QuickScanner(InputStream stream) {
      this.stream = stream;
      this.buffer = new byte[BUFFER_SIZE];
      this.currentPosition = 0;
      this.id9 = 0;
    }

    public String next() {
      int b = id10();
      StringBuilder res = new StringBuilder();
      do {
        res.appendCodePoint(b);
        b = nextChar();
      } while (!id7(b));
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
      return c == ' ' || c == '\t' || id18(c);
    }

    public boolean id18(int c) {
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
    public static boolean id8(int n) {
      return n > 0 && (n & (n - 1)) == 0;
    }

    public static int id21(int n) {
      if (n < 1) return 1;
      return id8(n) ? n : Integer.highestOneBit(n) << 1;
    }

  }
}

