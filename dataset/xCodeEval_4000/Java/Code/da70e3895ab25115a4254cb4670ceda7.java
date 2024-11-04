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
    BooleanEdgeWeightedTree tree;
    TreeLCA lca;
    int[] specialCnt;
    int[] partCnt;

    public void solve(int testNumber, QuickScanner in, QuickWriter out) {
      vertexCnt = in.nextInt();
      tree = new BooleanEdgeWeightedTree(vertexCnt + 1);
      for (int i = 0; i < vertexCnt; ++i) {
        int parent = in.nextInt();
        int type = in.nextInt();
        tree.add(
            i,
            parent < 0 ? vertexCnt : parent - 1,
            type > 0);
      }
      lca = new TreeLCA();
      lca.init(tree, vertexCnt);
      preCalc();
      for (int remQ = in.nextInt(); remQ > 0; --remQ) {
        out.println(calc(in.nextInt(), in.nextInt() - 1, in.nextInt() - 1) ? "YES" : "NO");
      }
    }

    void preCalc() {
      specialCnt = new int[vertexCnt];
      partCnt = new int[vertexCnt];
      tree.forEachOutNodes(vertexCnt, u -> dfs(u, vertexCnt, 0, 0));
    }

    void dfs(int u, int parent, int specialCnt, int partCnt) {
      this.specialCnt[u] = specialCnt;
      this.partCnt[u] = partCnt;
      tree.forEachOutEdges(u, edgeIdx -> {
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
        return lca == u && isAllSpecial(v, u);
      } else {
        return lca != v && isAllPart(v, lca) && isAllSpecial(u, lca);
      }
    }

    boolean isAllSpecial(int u, int ancestor) {
      return specialCnt[u] - specialCnt[ancestor] == lca.depth[u] - lca.depth[ancestor];
    }

    boolean isAllPart(int u, int ancestor) {
      return partCnt[u] - partCnt[ancestor] == lca.depth[u] - lca.depth[ancestor];
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

  static class TreeLCA {
    public int[] depth;
    private TreeInterface tree;
    private int dfsCnt;
    private int[] dfsIn;
    private int[] dfsOut;
    private int[] dfsDepth;
    private int[] dfsDepthIdx;
    private IntMinimumRMQ rmq;

    public TreeLCA() {
    }

    public TreeLCA(int vertexCapacity) {
      ensureCapacity(vertexCapacity);
    }

    public void init(TreeInterface tree, int rootNodeIdx) {
      ensureCapacity(tree.vertexCnt());
      this.tree = tree;
      dfsCnt = 0;
      dfsInternal(rootNodeIdx, -1, 0);
      rmq.init(dfsCnt, dfsDepth);
    }

    public int calc(int x, int y) {
      return dfsDepthIdx[rmq.calcIdx(Math.min(dfsIn[x], dfsIn[y]), Math.max(dfsOut[x], dfsOut[y]) + 1)];
    }

    private void dfsInternal(int u, int parent, int depth) {
      this.depth[u] = depth;
      dfsDepth[dfsCnt] = depth;
      dfsDepthIdx[dfsCnt] = u;
      dfsIn[u] = dfsCnt++;
      for (int edgeIdx = tree.lastOut(u); edgeIdx >= 0; edgeIdx = tree.nextOut(edgeIdx)) {
        int v = tree.toIdx(edgeIdx);
        if (v == parent) continue;
        dfsInternal(v, u, depth + 1);
        dfsDepth[dfsCnt] = depth;
        dfsDepthIdx[dfsCnt++] = u;
      }
      dfsDepth[dfsCnt] = depth;
      dfsDepthIdx[dfsCnt] = u;
      dfsOut[u] = dfsCnt++;
    }

    private void ensureCapacity(int capacity) {
      if (depth != null && depth.length >= capacity) return;
      int size = IntUtils.nextPow2(capacity);
      int size3 = IntUtils.nextPow2(capacity * 3);
      depth = new int[size];
      dfsIn = new int[size];
      dfsOut = new int[size];
      rmq = new IntMinimumRMQ(size3);
      dfsDepth = new int[size3];
      dfsDepthIdx = new int[size3];
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

    public int calcIdx(int fromIdx, int toIdx) {
      calcInternal(fromIdx, toIdx);
      return resIdx;
    }

  }

  static interface BidirectionalGraphInterface extends DirectedGraphInterface {
  }

  static interface BooleanEdgeWeightedTreeInterface extends BooleanEdgeWeighted, TreeInterface {
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

  static interface BooleanEdgeWeightedBidirectionalGraphInterface extends BooleanEdgeWeighted, BidirectionalGraphInterface {
  }

  static class BooleanArrayUtils {
    public static boolean[] expand(boolean[] values, int newLength) {
      if (values != null && values.length >= newLength) return values;
      boolean[] res = new boolean[newLength];
      if (values == null) return res;
      for (int i = 0; i < values.length; ++i) res[i] = values[i];
      return res;
    }

  }

  static interface BooleanEdgeWeightedDirectedGraphInterface extends BooleanEdgeWeighted, DirectedGraphInterface {
  }

  static abstract class AbstractBooleanEdgeWeightedDirectedGraph extends AbstractDirectedGraph implements BooleanEdgeWeightedDirectedGraphInterface {
    public boolean[] edgeWeights;

    public AbstractBooleanEdgeWeightedDirectedGraph(int vertexCapacity, int edgeCapacity) {
      super(vertexCapacity, edgeCapacity);
    }


    public void createVertexStorage(int vertexCapacity) {
    }


    public void expandEdgeStorage(int edgeCapacity) {
      edgeWeights = BooleanArrayUtils.expand(edgeWeights, edgeCapacity);
    }


    public void initVertexStorage(int vertexCnt) {
    }


    public void add(int fromIdx, int toIdx) {
      throw new UnsupportedOperationException();
    }


    public void add(int fromIdx, int toIdx, boolean weight) {
      edgeWeights[currentEdgeCnt] = weight;
      super.add(fromIdx, toIdx);
    }


    public boolean edgeWeight(int edgeIdx) {
      return edgeWeights[edgeIdx];
    }

  }

  static interface TreeInterface extends BidirectionalGraphInterface {
  }

  static abstract class AbstractDirectedGraph implements DirectedGraphInterface {
    protected int vertexCnt;
    protected int currentEdgeCnt;
    protected int[] fromIdx;
    protected int[] toIdx;
    protected int[] nextIn;
    protected int[] nextOut;
    protected int[] lastIn;
    protected int[] lastOut;
    protected int[] inDegree;
    protected int[] outDegree;

    public abstract void createVertexStorage(int vertexCapacity);

    public abstract void expandEdgeStorage(int edgeCapacity);

    public abstract void initVertexStorage(int vertexCnt);

    public AbstractDirectedGraph() {
    }

    public AbstractDirectedGraph(int vertexCapacity, int edgeCapacity) {
      this(vertexCapacity, edgeCapacity, true);
    }

    public AbstractDirectedGraph(int vertexCapacity, int edgeCapacity, boolean initialize) {
      ensureVertexCapacity(vertexCapacity);
      ensureEdgeCapacity(edgeCapacity);
      if (initialize) init(vertexCapacity);
    }


    public void init(int vertexCnt) {
      ensureVertexCapacity(vertexCnt);
      this.vertexCnt = vertexCnt;
      currentEdgeCnt = 0;
      Arrays.fill(inDegree, 0, vertexCnt, 0);
      Arrays.fill(outDegree, 0, vertexCnt, 0);
      Arrays.fill(lastIn, 0, vertexCnt, -1);
      Arrays.fill(lastOut, 0, vertexCnt, -1);
      initVertexStorage(vertexCnt);
    }


    public void add(int fromIdx, int toIdx) {
      ensureEdgeCapacity(currentEdgeCnt + 1);
      this.fromIdx[currentEdgeCnt] = fromIdx;
      this.toIdx[currentEdgeCnt] = toIdx;
      ++outDegree[fromIdx];
      ++inDegree[toIdx];
      nextOut[currentEdgeCnt] = lastOut[fromIdx];
      lastOut[fromIdx] = currentEdgeCnt;
      nextIn[currentEdgeCnt] = lastIn[toIdx];
      lastIn[toIdx] = currentEdgeCnt;
      ++currentEdgeCnt;
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


    public void forEachOutNodes(int nodeIdx, IntConsumer consumer) {
      for (int edgeIdx = lastOut[nodeIdx]; edgeIdx >= 0; edgeIdx = nextOut[edgeIdx]) {
        consumer.accept(toIdx[edgeIdx]);
      }
    }


    public void forEachOutEdges(int nodeIdx, IntConsumer consumer) {
      for (int edgeIdx = lastOut[nodeIdx]; edgeIdx >= 0; edgeIdx = nextOut[edgeIdx]) {
        consumer.accept(edgeIdx);
      }
    }

    private void ensureVertexCapacity(int vertexCapacity) {
      if (lastIn != null && lastIn.length >= vertexCapacity) return;
      int capacity = IntUtils.nextPow2(vertexCapacity);
      lastIn = new int[capacity];
      lastOut = new int[capacity];
      inDegree = new int[capacity];
      outDegree = new int[capacity];
      createVertexStorage(capacity);
    }

    private void ensureEdgeCapacity(int edgeCapacity) {
      if (fromIdx != null && fromIdx.length >= edgeCapacity) return;
      int capacity = IntUtils.nextPow2(edgeCapacity);
      fromIdx = IntArrayUtils.expand(fromIdx, capacity);
      toIdx = IntArrayUtils.expand(toIdx, capacity);
      nextIn = IntArrayUtils.expand(nextIn, capacity);
      nextOut = IntArrayUtils.expand(nextOut, capacity);
      expandEdgeStorage(capacity);
    }

  }

  static class BooleanEdgeWeightedTree extends AbstractBooleanEdgeWeightedBidirectionalGraph implements BooleanEdgeWeightedTreeInterface {
    public BooleanEdgeWeightedTree(int vertexCapacity) {
      super(vertexCapacity, vertexCapacity - 1);
    }

  }

  static interface BooleanEdgeWeighted {
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

  static class AbstractBooleanEdgeWeightedBidirectionalGraph extends AbstractBooleanEdgeWeightedDirectedGraph implements BooleanEdgeWeightedBidirectionalGraphInterface {
    public AbstractBooleanEdgeWeightedBidirectionalGraph(int vertexCapacity, int edgeCapacity) {
      super(vertexCapacity, edgeCapacity << 1);
    }


    public void add(int fromIdx, int toIdx, boolean weight) {
      super.add(fromIdx, toIdx, weight);
      super.add(toIdx, fromIdx, weight);
    }

  }

  static interface DirectedGraphInterface {
    int vertexCnt();

    int toIdx(int edgeIdx);

    int lastOut(int nodeIdx);

    int nextOut(int edgeIdx);

  }

  static class IntArrayUtils {
    public static int[] expand(int[] values, int newLength) {
      if (values != null && values.length >= newLength) return values;
      int[] res = new int[newLength];
      if (values == null) return res;
      for (int i = 0; i < values.length; ++i) res[i] = values[i];
      return res;
    }

  }
}

