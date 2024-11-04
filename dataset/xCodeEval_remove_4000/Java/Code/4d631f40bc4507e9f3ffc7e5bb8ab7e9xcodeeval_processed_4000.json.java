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
    TaskF solver = new TaskF();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskF {
    int n;
    int q;
    int[] x;
    int[] y;
    long[] hash;
    id6 id14;
    id13 open;
    id13 close;
    boolean[] answer;
    id15 dset;

    public void solve(int testNumber, QuickScanner in, QuickWriter out) {
      n = in.nextInt();
      q = in.nextInt();
      x = new int[q];
      y = new int[q];
      hash = new long[q];
      for (int i = 0; i < q; ++i) {
        int l = in.nextInt() - 1;
        int r = in.nextInt() - 1;
        x[i] = Math.min(l, r);
        y[i] = Math.max(l, r);
        hash[i] = (long) x[i] * n + y[i];
      }
      initEvents();
      answer = new boolean[q];
      dset = new id15(n);
      calc(open.size, 0, q - 1);
      for (int i = 0; i < q; ++i) {
        out.println(answer[i] ? "YES" : "NO");
      }
    }

    void initEvents() {
      id14 = new id6(q);
      id14.addAll(hash);
      id14.id7();
      open = new id13(q);
      close = new id13(q);
      int m = id14.size;
      int[] pos = new int[m];
      Arrays.fill(pos, -1);
      for (int i = 0; i < q; ++i) {
        int hashIdx = id14.lowerBound(hash[i]);
        if (pos[hashIdx] >= 0) {
          open.add(pos[hashIdx]);
          close.add(i - 1);
          pos[hashIdx] = -1;
        } else {
          pos[hashIdx] = i;
        }
      }
      for (int i = 0; i < m; ++i)
        if (pos[i] >= 0) {
          open.add(pos[i]);
          close.add(q - 1);
        }
    }

    void calc(int size, int lower, int upper) {
      int pnt = 0;
      int cnt = 0;
      boolean valid = true;
      for (int i = 0; i < size; ++i) {
        int left = open.get(i);
        int right = close.get(i);
        if (right < lower || upper < left) continue;
        if (left <= lower && upper <= right) {
          if (dset.isFriend(x[left], y[left])) {




            if ((Math.abs(dset.calcDistance(x[left]) - dset.calcDistance(y[left])) & 1) == 0) {
              valid = false;
            }
          } else {


            dset.setFriend(x[left], y[left]);


            ++cnt;
          }
          continue;
        }
        open.swap(pnt, i);
        close.swap(pnt, i);
        ++pnt;
      }
      if (size == 0 || lower == upper || !valid) {
        for (int i = lower; i <= upper; ++i) {


          answer[i] = valid;
        }
      } else {
        int medium = (lower + upper) >> 1;
        calc(pnt, lower, medium);
        calc(pnt, medium + 1, upper);
      }


      for (int i = 0; i < cnt; ++i) {
        dset.poll();
      }


    }

  }

  static class Truth {
    public static void assertThat(boolean o) {
      if (!o) throw new IllegalArgumentException();
    }

  }

  static class id6 implements LongCollection, Iterable<Long> {
    private static final long[] EMPTY = {};
    public long[] values;
    public int size;

    public id6() {
      values = EMPTY;
      clear();
    }

    public id6(int capacity) {
      values = new long[IntUtils.id11(capacity)];
      clear();
    }

    public id6(Collection<Long> collection) {
      this(collection.size());
      addAll(collection);
    }


    public void clear() {
      size = 0;
    }


    public void addAll(long[] values) {
      ensureCapacity(size + values.length);
      for (long value : values) {
        addInternal(value);
      }
    }


    public void addAll(Collection<Long> values) {
      ensureCapacity(size + values.size());
      for (long value : values) {
        addInternal(value);
      }
    }

    public void sort() {
      id12.sort(values, 0, size);
    }

    public void unique() {
      size = id12.unique(values, 0, size);
    }

    public void id7() {
      sort();
      unique();
    }

    public int lowerBound(long value) {
      return id12.lowerBound(values, 0, size, value);
    }

    public void ensureCapacity(int capacity) {
      if (capacity <= values.length) return;
      long[] newValues = new long[IntUtils.id11(capacity)];
      for (int i = 0; i < size; ++i) {
        newValues[i] = values[i];
      }
      values = newValues;
    }


    public String toString() {
      return id12.toString(values, 0, size);
    }


    public Iterator<Long> iterator() {
      return new Iterator<Long>() {
        private int i = 0;


        public boolean hasNext() {
          return i < size;
        }


        public Long next() {
          return values[i++];
        }
      };
    }

    private void addInternal(long value) {
      values[size++] = value;
    }

  }

  static class QuickScanner {
    private static final int BUFFER_SIZE = 1024;
    private InputStream stream;
    private byte[] buffer;
    private int currentPosition;
    private int id4;

    public QuickScanner(InputStream stream) {
      this.stream = stream;
      this.buffer = new byte[BUFFER_SIZE];
      this.currentPosition = 0;
      this.id4 = 0;
    }

    public int nextInt() {
      int c = id5();
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
      } while (!id1(c));
      return positive ? res : -res;
    }

    public int id5() {
      int res = nextChar();
      for (; id1(res) || res < 0; res = nextChar()) ;
      return res;
    }

    public int nextChar() {
      if (id4 == -1) {
        throw new RuntimeException();
      }
      if (currentPosition >= id4) {
        currentPosition = 0;
        try {
          id4 = stream.read(buffer);
        } catch (Exception e) {
          throw new RuntimeException(e);
        }
        if (id4 <= 0) {
          return -1;
        }
      }
      return buffer[currentPosition++];
    }

    public boolean id1(int c) {
      return c == ' ' || c == '\t' || id9(c);
    }

    public boolean id9(int c) {
      return c == '\n' || c == '\r' || c < 0;
    }

  }

  static interface IntCollection {
    int size();

    default boolean id8() {
      return size() > 0;
    }

  }

  static interface LongCollection {
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

  static class id2 {
    public static void swap(int[] values, int uIdx, int vIdx) {
      if (uIdx == vIdx) return;
      values[uIdx] ^= values[vIdx];
      values[vIdx] ^= values[uIdx];
      values[uIdx] ^= values[vIdx];
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

  static interface Displayable {
  }

  static class id15 extends id0 {
    private id13 records;
    private id13 recordSizes;

    public id15() {
      super();
    }

    public id15(int n) {
      super(n);
    }


    public void init(int n) {
      super.init(n);
      if (records == null) {
        records = new id13(n);
        recordSizes = new id13(n);
      }
      records.clear();
      recordSizes.clear();
    }


    protected void id10(int rootX, int rootY, int distance) {
      if (height[rootX] <= height[rootY]) {
        recordSizes.add(parent[rootX]);
        records.add((rootX << 1) | (height[rootX] == height[rootY] ? 1 : 0));
      } else {
        recordSizes.add(parent[rootY]);
        records.add(rootY << 1);
      }
      super.id10(rootX, rootY, distance);
    }

    public void poll() {
      Truth.assertThat(records.id8());
      int record = records.pollLast();
      int child = record >> 1;
      int parent = this.parent[child];
      this.parent[child] = recordSizes.pollLast();
      this.parent[parent] -= this.parent[child];
      height[parent] -= record & 1;
      distance[child] = 0;
    }

  }

  static class id12 {
    private static final Random RANDOM = new Random(1000000007);

    public static int unique(long[] values, int fromIdx, int toIdx) {
      if (fromIdx == toIdx) return 0;
      int res = 1;
      for (int i = fromIdx + 1; i < toIdx; ++i) {
        if (values[i - 1] != values[i]) {
          values[fromIdx + res++] = values[i];
        }
      }
      return res;
    }

    public static void sort(long[] values, int fromIdx, int toIdx) {
      shuffle(values, fromIdx, toIdx);
      Arrays.sort(values, fromIdx, toIdx);
    }

    public static int lowerBound(long[] values, int fromIdx, int toIdx, long value) {
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

    public static void swap(long[] values, int uIdx, int vIdx) {
      if (uIdx == vIdx) return;
      values[uIdx] ^= values[vIdx];
      values[vIdx] ^= values[uIdx];
      values[uIdx] ^= values[vIdx];
    }

    public static void shuffle(long[] values, int fromIdx, int toIdx) {
      for (int i = toIdx - fromIdx - 1; i > 0; --i) {
        swap(values, i + fromIdx, RANDOM.nextInt(i + 1) + fromIdx);
      }
    }

    public static String toString(long[] values, int fromIdx, int toIdx) {
      StringBuilder sb = new StringBuilder("[");
      for (int i = fromIdx; i < toIdx; ++i) {
        if (i != fromIdx) sb.append(", ");
        sb.append(values[i]);
      }
      return sb.append("]").toString();
    }

  }

  static class id13 implements IntCollection, Iterable<Integer> {
    private static final int[] EMPTY = {};
    public int[] values;
    public int size;

    public id13() {
      values = EMPTY;
      clear();
    }

    public id13(int capacity) {
      values = new int[IntUtils.id11(capacity)];
      clear();
    }

    public id13(Collection<Integer> collection) {
      this(collection.size());
      addAll(collection);
    }


    public void clear() {
      size = 0;
    }


    public int size() {
      return size;
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

    public int pollLast() {
      return values[--size];
    }

    public int get(int idx) {
      if (idx >= size) throw new ArrayIndexOutOfBoundsException();
      return values[idx];
    }

    public void swap(int x, int y) {
      if (x >= size || y >= size) throw new ArrayIndexOutOfBoundsException();
      id2.swap(values, x, y);
    }

    public void ensureCapacity(int capacity) {
      if (capacity <= values.length) return;
      int[] newValues = new int[IntUtils.id11(capacity)];
      for (int i = 0; i < size; ++i) {
        newValues[i] = values[i];
      }
      values = newValues;
    }


    public String toString() {
      return id2.toString(values, 0, size);
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

  static class id0 implements Displayable {
    private int n;
    protected int[] height;
    protected int[] parent;
    protected int[] distance;

    public id0() {
    }

    public id0(int n) {
      init(n);
    }

    public void init(int n) {
      this.n = n;
      ensureCapacity(n);
      Arrays.fill(parent, 0, n, -1);
      Arrays.fill(height, 0, n, 0);
      Arrays.fill(distance, 0, n, 0);
    }

    public boolean isFriend(int x, int y) {
      return calcRoot(x) == calcRoot(y);
    }

    public boolean setFriend(int x, int y) {
      int rootX = calcRoot(x);
      int rootY = calcRoot(y);
      if (rootX == rootY) return false;
      id10(rootX, rootY, calcDistance(x) + calcDistance(y) + 1);
      return true;
    }

    protected void id10(int rootX, int rootY, int distance) {
      if (height[rootX] <= height[rootY]) {
        parent[rootY] += parent[rootX];
        attachRoot(rootX, rootY, distance, height[rootX] == height[rootY]);
      } else {
        parent[rootX] += parent[rootY];
        attachRoot(rootY, rootX, distance, false);
      }
    }

    public int calcDistance(int x) {
      int res = 0;
      for (; parent[x] >= 0; x = parent[x]) res += distance[x];
      return res;
    }

    private int calcRoot(int x) {
      for (; parent[x] >= 0; x = parent[x]) {
      }
      return x;
    }

    private void attachRoot(int rootX, int rootY, int distance, boolean heightIncrease) {
      parent[rootX] = rootY;
      this.distance[rootX] = distance;
      if (heightIncrease) ++height[rootY];
    }

    private void ensureCapacity(int capacity) {
      if (parent != null && parent.length >= capacity) return;
      int size = IntUtils.id11(capacity);
      parent = new int[size];
      height = new int[size];
      distance = new int[size];
    }

  }

  static class IntUtils {
    public static boolean id3(int n) {
      return n > 0 && (n & (n - 1)) == 0;
    }

    public static int id11(int n) {
      if (n < 1) return 1;
      return id3(n) ? n : Integer.highestOneBit(n) << 1;
    }

  }
}

