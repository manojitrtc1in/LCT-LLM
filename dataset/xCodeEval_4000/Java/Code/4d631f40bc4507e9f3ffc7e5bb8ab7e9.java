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
    LongArrayList disHashs;
    IntArrayList open;
    IntArrayList close;
    boolean[] answer;
    DisjointSetSupportPoll dset;

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
      dset = new DisjointSetSupportPoll(n);
      calc(open.size, 0, q - 1);
      for (int i = 0; i < q; ++i) {
        out.println(answer[i] ? "YES" : "NO");
      }
    }

    void initEvents() {
      disHashs = new LongArrayList(q);
      disHashs.addAll(hash);
      disHashs.sortAndUnique();
      open = new IntArrayList(q);
      close = new IntArrayList(q);
      int m = disHashs.size;
      int[] pos = new int[m];
      Arrays.fill(pos, -1);
      for (int i = 0; i < q; ++i) {
        int hashIdx = disHashs.lowerBound(hash[i]);
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

  static class LongArrayList implements LongCollection, Iterable<Long> {
    private static final long[] EMPTY = {};
    public long[] values;
    public int size;

    public LongArrayList() {
      values = EMPTY;
      clear();
    }

    public LongArrayList(int capacity) {
      values = new long[IntUtils.nextPow2(capacity)];
      clear();
    }

    public LongArrayList(Collection<Long> collection) {
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
      LongArrayUtils.sort(values, 0, size);
    }

    public void unique() {
      size = LongArrayUtils.unique(values, 0, size);
    }

    public void sortAndUnique() {
      sort();
      unique();
    }

    public int lowerBound(long value) {
      return LongArrayUtils.lowerBound(values, 0, size, value);
    }

    public void ensureCapacity(int capacity) {
      if (capacity <= values.length) return;
      long[] newValues = new long[IntUtils.nextPow2(capacity)];
      for (int i = 0; i < size; ++i) {
        newValues[i] = values[i];
      }
      values = newValues;
    }


    public String toString() {
      return LongArrayUtils.toString(values, 0, size);
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

  static interface IntCollection {
    int size();

    default boolean isNotEmpty() {
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

  static class IntArrayUtils {
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

  static class DisjointSetSupportPoll extends DisjointSetNoCompress {
    private IntArrayList records;
    private IntArrayList recordSizes;

    public DisjointSetSupportPoll() {
      super();
    }

    public DisjointSetSupportPoll(int n) {
      super(n);
    }


    public void init(int n) {
      super.init(n);
      if (records == null) {
        records = new IntArrayList(n);
        recordSizes = new IntArrayList(n);
      }
      records.clear();
      recordSizes.clear();
    }


    protected void setFriendAtRoot(int rootX, int rootY, int distance) {
      if (height[rootX] <= height[rootY]) {
        recordSizes.add(parent[rootX]);
        records.add((rootX << 1) | (height[rootX] == height[rootY] ? 1 : 0));
      } else {
        recordSizes.add(parent[rootY]);
        records.add(rootY << 1);
      }
      super.setFriendAtRoot(rootX, rootY, distance);
    }

    public void poll() {
      Truth.assertThat(records.isNotEmpty());
      int record = records.pollLast();
      int child = record >> 1;
      int parent = this.parent[child];
      this.parent[child] = recordSizes.pollLast();
      this.parent[parent] -= this.parent[child];
      height[parent] -= record & 1;
      distance[child] = 0;
    }

  }

  static class LongArrayUtils {
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
      IntArrayUtils.swap(values, x, y);
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

  static class DisjointSetNoCompress implements Displayable {
    private int n;
    protected int[] height;
    protected int[] parent;
    protected int[] distance;

    public DisjointSetNoCompress() {
    }

    public DisjointSetNoCompress(int n) {
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
      setFriendAtRoot(rootX, rootY, calcDistance(x) + calcDistance(y) + 1);
      return true;
    }

    protected void setFriendAtRoot(int rootX, int rootY, int distance) {
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
      int size = IntUtils.nextPow2(capacity);
      parent = new int[size];
      height = new int[size];
      distance = new int[size];
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

