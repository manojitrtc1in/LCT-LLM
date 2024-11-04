import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.function.IntConsumer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;


public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    QuickScanner in = new QuickScanner(inputStream);
    QuickWriter out = new QuickWriter(outputStream);
    TaskD solver = new TaskD();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskD {
    int vertexCnt;
    id9 tree;
    id19 lca;
    int[] specialCnt;
    int[] partCnt;

    public void solve(int testNumber, QuickScanner in, QuickWriter out) {
      vertexCnt = in.nextInt();
      tree = new id9(vertexCnt + 1);
      for (int i = 0; i < vertexCnt; ++i) {
        int parent = in.nextInt();
        int type = in.nextInt();
        tree.add(
            i,
            parent < 0 ? vertexCnt : parent - 1,
            type > 0);
      }
      lca = new id19();
      lca.init(tree, vertexCnt);
      preCalc();
      for (int remQ = in.nextInt(); remQ > 0; --remQ) {
        out.println(calc(in.nextInt(), in.nextInt() - 1, in.nextInt() - 1) ? "YES" : "NO");
      }
    }

    void preCalc() {
      specialCnt = new int[vertexCnt];
      partCnt = new int[vertexCnt];
      tree.id4(vertexCnt, u -> dfs(u, vertexCnt, 0, 0));
    }

    void dfs(int u, int parent, int specialCnt, int partCnt) {
      this.specialCnt[u] = specialCnt;
      this.partCnt[u] = partCnt;
      tree.id31(u, edgeIdx -> {
        int v = tree.toIdx(edgeIdx);
        if (v == parent) return;
        boolean isPart = tree.edgeWeight(edgeIdx);
        dfs(v, u, specialCnt + (isPart ? 0 : 1), partCnt + (isPart ? 1 : 0));
      });
    }

    boolean calc(int type, int u, int v) {
      if (u == v) return false;
      int lca = this.lca.calc(u, v);
      if (lca == vertexCnt) return false;
      if (type == 1) {
        return lca == u && id32(v, u);
      } else {
        return lca != v && id36(v, lca) && id32(u, lca);
      }
    }

    boolean id32(int u, int ancestor) {
      return specialCnt[u] - specialCnt[ancestor] == lca.depth[u] - lca.depth[ancestor];
    }

    boolean id36(int u, int ancestor) {
      return partCnt[u] - partCnt[ancestor] == lca.depth[u] - lca.depth[ancestor];
    }

  }

  static abstract class id35 {
    public abstract void createArrays(int id14);

    public abstract void createArray(int bit, int capacity);

    public abstract void initSubclass(int n);

    public abstract void initMerge(int targetBit, int targetIdx, int sourceBit, int id1, int id16);

    public abstract void calcMerge(int bit, int x, int y);

    public id35(int capacity) {
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
    private int id10;

    public QuickScanner(InputStream stream) {
      this.stream = stream;
      this.buffer = new byte[BUFFER_SIZE];
      this.currentPosition = 0;
      this.id10 = 0;
    }

    public int nextInt() {
      int c = id11();
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

    public int id11() {
      int res = nextChar();
      for (; id5(res) || res < 0; res = nextChar()) ;
      return res;
    }

    public int nextChar() {
      if (id10 == -1) {
        throw new RuntimeException();
      }
      if (currentPosition >= id10) {
        currentPosition = 0;
        try {
          id10 = stream.read(buffer);
        } catch (Exception e) {
          throw new RuntimeException(e);
        }
        if (id10 <= 0) {
          return -1;
        }
      }
      return buffer[currentPosition++];
    }

    public boolean id5(int c) {
      return c == ' ' || c == '\t' || id26(c);
    }

    public boolean id26(int c) {
      return c == '\n' || c == '\r' || c < 0;
    }

  }

  static class id19 {
    public int[] depth;
    private TreeInterface tree;
    private int dfsCnt;
    private int[] dfsIn;
    private int[] dfsOut;
    private int[] dfsDepth;
    private int[] id13;
    private id20 rmq;

    public id19() {
    }

    public id19(int vertexCapacity) {
      ensureCapacity(vertexCapacity);
    }

    public void init(TreeInterface tree, int id25) {
      ensureCapacity(tree.vertexCnt());
      this.tree = tree;
      dfsCnt = 0;
      dfsInternal(id25, -1, 0);
      rmq.init(dfsCnt, dfsDepth);
    }

    public int calc(int x, int y) {
      return id13[rmq.calcIdx(Math.min(dfsIn[x], dfsIn[y]), Math.max(dfsOut[x], dfsOut[y]) + 1)];
    }

    private void dfsInternal(int u, int parent, int depth) {
      this.depth[u] = depth;
      dfsDepth[dfsCnt] = depth;
      id13[dfsCnt] = u;
      dfsIn[u] = dfsCnt++;
      for (int edgeIdx = tree.lastOut(u); edgeIdx >= 0; edgeIdx = tree.nextOut(edgeIdx)) {
        int v = tree.toIdx(edgeIdx);
        if (v == parent) continue;
        dfsInternal(v, u, depth + 1);
        dfsDepth[dfsCnt] = depth;
        id13[dfsCnt++] = u;
      }
      dfsDepth[dfsCnt] = depth;
      id13[dfsCnt] = u;
      dfsOut[u] = dfsCnt++;
    }

    private void ensureCapacity(int capacity) {
      if (depth != null && depth.length >= capacity) return;
      int size = IntUtils.id29(capacity);
      int size3 = IntUtils.id29(capacity * 3);
      depth = new int[size];
      dfsIn = new int[size];
      dfsOut = new int[size];
      rmq = new id20(size3);
      dfsDepth = new int[size3];
      id13 = new int[size3];
    }

  }

  static class id20 extends id35 {
    private int[][] rmq;
    private int[][] id33;
    private int[] initValues;
    private int resIdx;

    public id20(int capacity) {
      super(capacity);
    }


    public void createArrays(int id14) {
      rmq = new int[id14][];
      id33 = new int[id14][];
    }


    public void createArray(int bit, int capacity) {
      rmq[bit] = new int[capacity];
      id33[bit] = new int[capacity];
    }


    public void initSubclass(int n) {
      for (int i = 0; i < n; ++i) {
        rmq[0][i] = initValues[i];
        id33[0][i] = i;
      }
    }


    public void initMerge(int targetBit, int targetIdx, int sourceBit, int id1, int id16) {
      if (rmq[sourceBit][id1] <= rmq[sourceBit][id16]) {
        rmq[targetBit][targetIdx] = rmq[sourceBit][id1];
        id33[targetBit][targetIdx] = id33[sourceBit][id1];
      } else {
        rmq[targetBit][targetIdx] = rmq[sourceBit][id16];
        id33[targetBit][targetIdx] = id33[sourceBit][id16];
      }
    }


    public void calcMerge(int bit, int x, int y) {
      resIdx = rmq[bit][x] <= rmq[bit][y] ? id33[bit][x] : id33[bit][y];
    }

    public void init(int n, int[] initValues) {
      this.initValues = initValues;
      initInternal(n);
    }

    public int calcIdx(int fromIdx, int toIdx) {
      calcInternal(fromIdx, toIdx);
      return resIdx;
    }

  }

  static interface id15 extends id28 {
  }

  static interface id27 extends id21, TreeInterface {
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

  static interface id24 extends id21, id15 {
  }

  static class id3 {
    public static boolean[] expand(boolean[] values, int newLength) {
      if (values != null && values.length >= newLength) return values;
      boolean[] res = new boolean[newLength];
      if (values == null) return res;
      for (int i = 0; i < values.length; ++i) res[i] = values[i];
      return res;
    }

  }

  static interface id0 extends id21, id28 {
  }

  static abstract class id12 extends id23 implements id0 {
    public boolean[] edgeWeights;

    public id12(int vertexCapacity, int edgeCapacity) {
      super(vertexCapacity, edgeCapacity);
    }


    public void id8(int vertexCapacity) {
    }


    public void id17(int edgeCapacity) {
      edgeWeights = id3.expand(edgeWeights, edgeCapacity);
    }


    public void id34(int vertexCnt) {
    }


    public void add(int fromIdx, int toIdx) {
      throw new UnsupportedOperationException();
    }


    public void add(int fromIdx, int toIdx, boolean weight) {
      edgeWeights[id2] = weight;
      super.add(fromIdx, toIdx);
    }


    public boolean edgeWeight(int edgeIdx) {
      return edgeWeights[edgeIdx];
    }

  }

  static interface TreeInterface extends id15 {
  }

  static abstract class id23 implements id28 {
    protected int vertexCnt;
    protected int id2;
    protected int[] fromIdx;
    protected int[] toIdx;
    protected int[] nextIn;
    protected int[] nextOut;
    protected int[] lastIn;
    protected int[] lastOut;
    protected int[] inDegree;
    protected int[] outDegree;

    public abstract void id8(int vertexCapacity);

    public abstract void id17(int edgeCapacity);

    public abstract void id34(int vertexCnt);

    public id23() {
    }

    public id23(int vertexCapacity, int edgeCapacity) {
      this(vertexCapacity, edgeCapacity, true);
    }

    public id23(int vertexCapacity, int edgeCapacity, boolean initialize) {
      id18(vertexCapacity);
      id22(edgeCapacity);
      if (initialize) init(vertexCapacity);
    }


    public void init(int vertexCnt) {
      id18(vertexCnt);
      this.vertexCnt = vertexCnt;
      id2 = 0;
      Arrays.fill(inDegree, 0, vertexCnt, 0);
      Arrays.fill(outDegree, 0, vertexCnt, 0);
      Arrays.fill(lastIn, 0, vertexCnt, -1);
      Arrays.fill(lastOut, 0, vertexCnt, -1);
      id34(vertexCnt);
    }


    public void add(int fromIdx, int toIdx) {
      id22(id2 + 1);
      this.fromIdx[id2] = fromIdx;
      this.toIdx[id2] = toIdx;
      ++outDegree[fromIdx];
      ++inDegree[toIdx];
      nextOut[id2] = lastOut[fromIdx];
      lastOut[fromIdx] = id2;
      nextIn[id2] = lastIn[toIdx];
      lastIn[toIdx] = id2;
      ++id2;
    }


    public int vertexCnt() {
      return vertexCnt;
    }


    public int toIdx(int edgeIdx) {
      return toIdx[edgeIdx];
    }


    public int lastOut(int nodeIdx) {
      return lastOut[nodeIdx];
    }


    public int nextOut(int edgeIdx) {
      return nextOut[edgeIdx];
    }


    public void id4(int nodeIdx, IntConsumer consumer) {
      for (int edgeIdx = lastOut[nodeIdx]; edgeIdx >= 0; edgeIdx = nextOut[edgeIdx]) {
        consumer.accept(toIdx[edgeIdx]);
      }
    }


    public void id31(int nodeIdx, IntConsumer consumer) {
      for (int edgeIdx = lastOut[nodeIdx]; edgeIdx >= 0; edgeIdx = nextOut[edgeIdx]) {
        consumer.accept(edgeIdx);
      }
    }

    private void id18(int vertexCapacity) {
      if (lastIn != null && lastIn.length >= vertexCapacity) return;
      int capacity = IntUtils.id29(vertexCapacity);
      lastIn = new int[capacity];
      lastOut = new int[capacity];
      inDegree = new int[capacity];
      outDegree = new int[capacity];
      id8(capacity);
    }

    private void id22(int edgeCapacity) {
      if (fromIdx != null && fromIdx.length >= edgeCapacity) return;
      int capacity = IntUtils.id29(edgeCapacity);
      fromIdx = id6.expand(fromIdx, capacity);
      toIdx = id6.expand(toIdx, capacity);
      nextIn = id6.expand(nextIn, capacity);
      nextOut = id6.expand(nextOut, capacity);
      id17(capacity);
    }

  }

  static class id9 extends id30 implements id27 {
    public id9(int vertexCapacity) {
      super(vertexCapacity, vertexCapacity - 1);
    }

  }

  static interface id21 {
  }

  static class IntUtils {
    public static boolean id7(int n) {
      return n > 0 && (n & (n - 1)) == 0;
    }

    public static int id29(int n) {
      if (n < 1) return 1;
      return id7(n) ? n : Integer.highestOneBit(n) << 1;
    }

  }

  static class id30 extends id12 implements id24 {
    public id30(int vertexCapacity, int edgeCapacity) {
      super(vertexCapacity, edgeCapacity << 1);
    }


    public void add(int fromIdx, int toIdx, boolean weight) {
      super.add(fromIdx, toIdx, weight);
      super.add(toIdx, fromIdx, weight);
    }

  }

  static interface id28 {
    int vertexCnt();

    int toIdx(int edgeIdx);

    int lastOut(int nodeIdx);

    int nextOut(int edgeIdx);

  }

  static class id6 {
    public static int[] expand(int[] values, int newLength) {
      if (values != null && values.length >= newLength) return values;
      int[] res = new int[newLength];
      if (values == null) return res;
      for (int i = 0; i < values.length; ++i) res[i] = values[i];
      return res;
    }

  }
}

