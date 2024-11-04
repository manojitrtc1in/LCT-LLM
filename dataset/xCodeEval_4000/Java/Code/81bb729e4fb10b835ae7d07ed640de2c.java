import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
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
    int m;
    int s;
    Edge[] edges;
    DisjointSet dset;
    IntEdgeWeightedTree tree;

    public void solve(int testNumber, QuickScanner in, QuickWriter out) {
      n = in.nextInt();
      m = in.nextInt();
      edges = new Edge[m];
      for (int i = 0; i < m; ++i) {
        edges[i] = new Edge(i);
      }
      for (int i = 0; i < m; ++i) {
        edges[i].w = in.nextInt();
      }
      for (int i = 0; i < m; ++i) {
        edges[i].c = in.nextInt();
      }
      for (int i = 0; i < m; ++i) {
        edges[i].fromIdx = in.nextInt() - 1;
        edges[i].toIdx = in.nextInt() - 1;
      }
      s = in.nextInt();
      Arrays.sort(edges);
      dset = new DisjointSet(n);
      int minC = Integer.MAX_VALUE;
      int minCIdx = -1;
      long sumW = 0;
      tree = new IntEdgeWeightedTree(n);
      for (int i = 0; i < m; ++i) {
        int fromIdx = edges[i].fromIdx;
        int toIdx = edges[i].toIdx;
        if (dset.isFriend(fromIdx, toIdx)) continue;


        dset.setFriend(fromIdx, toIdx);
        tree.add(fromIdx, toIdx, i);
        edges[i].inMst = true;
        sumW += edges[i].w;
        if (minC > edges[i].c) {
          minC = edges[i].c;
          minCIdx = i;
        }
      }
      int findIdx = minCIdx, replaceIdx = minCIdx;
      long res = sumW - s / minC;
      TreePath treePath = new TreePath(n);
      treePath.init(tree, 0);
      for (int i = 0; i < m; ++i)
        if (!edges[i].inMst && edges[i].c < minC) {
          treePath.calc(edges[i].fromIdx, edges[i].toIdx);
          int currentIdx = treePath.resIdx;
          long currentRes = sumW - edges[currentIdx].w + edges[i].w - s / edges[i].c;
          if (res <= currentRes) continue;
          res = currentRes;
          findIdx = currentIdx;
          replaceIdx = i;
        }
      out.println(res);
      for (int i = 0; i < m; ++i)
        if (edges[i].inMst) {
          if (i == findIdx) {
            out.println(edges[replaceIdx].idx + 1, edges[replaceIdx].w - s / edges[replaceIdx].c);
          } else {
            out.println(edges[i].idx + 1, edges[i].w);
          }
        }
    }

    class Edge implements Comparable<Edge> {
      final int idx;
      int w;
      int c;
      int fromIdx;
      int toIdx;
      boolean inMst;

      Edge(int idx) {
        this.idx = idx;
        inMst = false;
      }


      public int compareTo(Edge o) {
        return w - o.w;
      }

    }

    class TreePath extends AbstractEdgeWeightedTreePath {
      int[][] maxWIdx;
      int resIdx;

      public TreePath(int capacity) {
        super(capacity);
      }


      public void createSubclass(int capacityHighBit, int capacity) {
        maxWIdx = new int[capacityHighBit][capacity];
      }


      public void initSubclass(int u, int toParentEdgeIdx) {
        maxWIdx[0][u] = tree.edgeWeight(toParentEdgeIdx);
      }


      public void initMerge(int targetBit, int targetIdx, int sourceBit, int sourceIdx) {
        maxWIdx[targetBit][targetIdx] = maxWIdx[sourceBit][sourceIdx];
      }


      public void initMerge(int targetBit, int targetIdx, int sourceBit, int sourceIdx1, int sourceIdx2) {
        int idx1 = maxWIdx[sourceBit][sourceIdx1];
        int idx2 = maxWIdx[sourceBit][sourceIdx2];
        maxWIdx[targetBit][targetIdx] = edges[idx1].w > edges[idx2].w ? idx1 : idx2;
      }


      public void calcAppend(int bit, int idx) {
        if (resIdx == -1 || edges[resIdx].w < edges[maxWIdx[bit][idx]].w) {
          resIdx = maxWIdx[bit][idx];
        }
      }

      public void calc(int fromIdx, int toIdx) {
        resIdx = -1;
        super.calc(fromIdx, toIdx);
      }

    }

  }

  static interface TreeInterface extends BidirectionalGraphInterface {
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

  static interface IntEdgeWeightedBidirectionalGraphInterface extends IntEdgeWeighted, BidirectionalGraphInterface {
  }

  static abstract class AbstractIntEdgeWeightedDirectedGraph extends AbstractDirectedGraph implements IntEdgeWeightedDirectedGraphInterface {
    public int[] edgeWeights;

    public AbstractIntEdgeWeightedDirectedGraph(int vertexCapacity, int edgeCapacity) {
      super(vertexCapacity, edgeCapacity);
    }


    public void createSubclass(int vertexCapacity, int edgeCapacity) {
      edgeWeights = new int[edgeCapacity];
    }


    public void initSubclass(int vertexCnt) {
    }


    public void add(int fromIdx, int toIdx) {
      throw new UnsupportedOperationException();
    }


    public void add(int fromIdx, int toIdx, int weight) {
      edgeWeights[currentEdgeCnt] = weight;
      super.add(fromIdx, toIdx);
    }


    public int edgeWeight(int edgeIdx) {
      return edgeWeights[edgeIdx];
    }

  }

  static interface BidirectionalGraphInterface extends DirectedGraphInterface {
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

  static interface IntEdgeWeightedDirectedGraphInterface extends IntEdgeWeighted, DirectedGraphInterface {
  }

  static abstract class AbstractDirectedGraph implements DirectedGraphInterface {
    public int vertexCnt;
    public int currentEdgeCnt;
    public int[] fromIdx;
    public int[] toIdx;
    public int[] nextIn;
    public int[] nextOut;
    public int[] lastIn;
    public int[] lastOut;
    public int[] inDegree;
    public int[] outDegree;

    public abstract void createSubclass(int vertexCapacity, int edgeCapacity);

    public abstract void initSubclass(int vertexCnt);

    public AbstractDirectedGraph(int vertexCapacity, int edgeCapacity) {
      this(vertexCapacity, edgeCapacity, true);
    }

    public AbstractDirectedGraph(int vertexCapacity, int edgeCapacity, boolean initialize) {
      fromIdx = new int[edgeCapacity];
      toIdx = new int[edgeCapacity];
      lastIn = new int[vertexCapacity];
      lastOut = new int[vertexCapacity];
      nextIn = new int[edgeCapacity];
      nextOut = new int[edgeCapacity];
      inDegree = new int[vertexCapacity];
      outDegree = new int[vertexCapacity];
      createSubclass(vertexCapacity, edgeCapacity);
      if (initialize) init(vertexCapacity);
    }


    public void init(int vertexCnt) {
      this.vertexCnt = vertexCnt;
      currentEdgeCnt = 0;
      Arrays.fill(inDegree, 0, vertexCnt, 0);
      Arrays.fill(outDegree, 0, vertexCnt, 0);
      Arrays.fill(lastIn, 0, vertexCnt, -1);
      Arrays.fill(lastOut, 0, vertexCnt, -1);
      initSubclass(vertexCnt);
    }


    public void add(int fromIdx, int toIdx) {
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

  }

  static interface IntEdgeWeightedTreeInterface extends IntEdgeWeighted, TreeInterface {
  }

  static interface IntEdgeWeighted {
  }

  static abstract class AbstractEdgeWeightedTreePath {
    private TreeLCA lca;
    private TreeInterface tree;
    private int[] toParentEdgeIdx;
    private int[][] ancestor;
    private int calcCnt;
    private int[] calcBit;
    private int[] calcIdx;

    public abstract void createSubclass(int capacityHighBit, int capacity);

    public abstract void initSubclass(int u, int toParentEdgeIdx);

    public abstract void initMerge(int targetBit, int targetIdx, int sourceBit, int sourceIdx);

    public abstract void initMerge(int targetBit, int targetIdx, int sourceBit, int sourceIdx1, int sourceIdx2);

    public abstract void calcAppend(int bit, int idx);

    public AbstractEdgeWeightedTreePath(int capacity) {
      lca = new TreeLCA(capacity);
      toParentEdgeIdx = new int[capacity];
      int highBit = 32 - Integer.numberOfLeadingZeros(capacity);
      ancestor = new int[highBit][capacity];
      calcBit = new int[highBit];
      calcIdx = new int[highBit];
      createSubclass(highBit, capacity);
    }

    public void init(TreeInterface tree, int rootNodeIdx) {
      this.tree = tree;
      lca.init(tree, rootNodeIdx);
      dfsInternal(rootNodeIdx, -1);
      int n = tree.vertexCnt();
      for (int i = 0; i < n; ++i) {
        int edgeIdx = toParentEdgeIdx[i];
        ancestor[0][i] = edgeIdx < 0 ? -1 : tree.toIdx(edgeIdx);
        if (edgeIdx >= 0) {
          initSubclass(i, edgeIdx);
        }
      }
      int highBit = 32 - Integer.numberOfLeadingZeros(n);
      for (int bit = 1; bit < highBit; ++bit) {
        for (int i = 0; i < n; ++i) {
          int j = ancestor[bit - 1][i];
          ancestor[bit][i] = j < 0 ? -1 : ancestor[bit - 1][j];
          if (j < 0) {
            initMerge(bit, i, bit - 1, i);
          } else {
            initMerge(bit, i, bit - 1, i, j);
          }
        }
      }
    }

    public void calc(int fromIdx, int toIdx) {
      int lca = this.lca.calc(fromIdx, toIdx);
      int lcaDepth = this.lca.depth[lca];
      int n = calcInternal(fromIdx, this.lca.depth[fromIdx] - lcaDepth);
      for (int i = 0; i < n; ++i) {
        calcAppend(calcBit[i], calcIdx[i]);
      }
      n = calcInternal(toIdx, this.lca.depth[toIdx] - lcaDepth);
      for (int i = n - 1; i >= 0; --i) {
        calcAppend(calcBit[i], calcIdx[i]);
      }
    }

    private void dfsInternal(int u, int toParentEdgeIdx) {
      this.toParentEdgeIdx[u] = toParentEdgeIdx;
      for (int edgeIdx = tree.lastOut(u); edgeIdx >= 0; edgeIdx = tree.nextOut(edgeIdx)) {
        if (edgeIdx != toParentEdgeIdx) {
          dfsInternal(tree.toIdx(edgeIdx), edgeIdx ^ 1);
        }
      }
    }

    private int calcInternal(int fromIdx, int step) {
      calcCnt = 0;
      for (int bit = 0; step > 0; ++bit, step >>= 1)
        if ((step & 1) > 0) {
          calcBit[calcCnt] = bit;
          calcIdx[calcCnt++] = fromIdx;
          fromIdx = ancestor[bit][fromIdx];
        }
      return calcCnt;
    }

  }

  static class AbstractIntEdgeWeightedBidirectionalGraph extends AbstractIntEdgeWeightedDirectedGraph implements IntEdgeWeightedBidirectionalGraphInterface {
    public AbstractIntEdgeWeightedBidirectionalGraph(int vertexCapacity, int edgeCapacity) {
      super(vertexCapacity, edgeCapacity << 1);
    }


    public void add(int fromIdx, int toIdx, int weight) {
      super.add(fromIdx, toIdx, weight);
      super.add(toIdx, fromIdx, weight);
    }

  }

  static class IntEdgeWeightedTree extends AbstractIntEdgeWeightedBidirectionalGraph implements IntEdgeWeightedTreeInterface {
    public IntEdgeWeightedTree(int vertexCapacity) {
      super(vertexCapacity, vertexCapacity - 1);
    }

  }

  static class DisjointSet {
    int[] parent;

    public DisjointSet(int vertexCapacity) {
      this.parent = new int[vertexCapacity];
      init(vertexCapacity);
    }

    public void init(int n) {
      Arrays.fill(parent, 0, n, -1);
    }

    public int calcRoot(int x) {
      int res = x;
      for (; parent[res] >= 0; res = parent[res]) {
      }
      shrink(x, res);
      return res;
    }

    public boolean isFriend(int x, int y) {
      return calcRoot(x) == calcRoot(y);
    }

    public void setFriend(int x, int y) {
      int rootX = calcRoot(x);
      int rootY = calcRoot(y);
      if (rootX != rootY) {
        parent[rootX] += parent[rootY];
        parent[rootY] = rootX;
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

  static interface DirectedGraphInterface {
    int vertexCnt();

    int toIdx(int edgeIdx);

    int lastOut(int nodeIdx);

    int nextOut(int edgeIdx);

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

    public TreeLCA(int vertexCapacity) {
      depth = new int[vertexCapacity];
      int vertexCapacity3 = vertexCapacity * 3;
      rmq = new IntMinimumRMQ(vertexCapacity3);
      dfsIn = new int[vertexCapacity];
      dfsOut = new int[vertexCapacity];
      dfsDepth = new int[vertexCapacity3];
      dfsDepthIdx = new int[vertexCapacity3];
    }

    public void init(TreeInterface tree, int rootNodeIdx) {
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

  }
}

