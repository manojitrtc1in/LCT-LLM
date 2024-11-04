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
    id19 dset;
    id23 tree;

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
      dset = new id19(n);
      int minC = Integer.MAX_VALUE;
      int id20 = -1;
      long sumW = 0;
      tree = new id23(n);
      for (int i = 0; i < m; ++i) {
        int fromIdx = edges[i].fromIdx;
        int toIdx = edges[i].toIdx;
        if (dset.isFriend(fromIdx, toIdx)) continue;


        dset.setFriend(fromIdx, toIdx);
        tree.add(fromIdx, toIdx, i);
        edges[i].id10 = true;
        sumW += edges[i].w;
        if (minC > edges[i].c) {
          minC = edges[i].c;
          id20 = i;
        }
      }
      int findIdx = id20, replaceIdx = id20;
      long res = sumW - s / minC;
      id30 id12 = new id30(n);
      id12.init(tree, 0);
      for (int i = 0; i < m; ++i)
        if (!edges[i].id10 && edges[i].c < minC) {
          id12.calc(edges[i].fromIdx, edges[i].toIdx);
          int currentIdx = id12.resIdx;
          long currentRes = sumW - edges[currentIdx].w + edges[i].w - s / edges[i].c;
          if (res <= currentRes) continue;
          res = currentRes;
          findIdx = currentIdx;
          replaceIdx = i;
        }
      out.println(res);
      for (int i = 0; i < m; ++i)
        if (edges[i].id10) {
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
      boolean id10;

      Edge(int idx) {
        this.idx = idx;
        id10 = false;
      }


      public int compareTo(Edge o) {
        return w - o.w;
      }

    }

    class id30 extends id25 {
      int[][] id0;
      int resIdx;

      public id30(int capacity) {
        super(capacity);
      }


      public void createSubclass(int id14, int capacity) {
        id0 = new int[id14][capacity];
      }


      public void initSubclass(int u, int id17) {
        id0[0][u] = tree.edgeWeight(id17);
      }


      public void initMerge(int targetBit, int targetIdx, int sourceBit, int id1, int id18) {
        int idx1 = id0[sourceBit][id1];
        int idx2 = id0[sourceBit][id18];
        id0[targetBit][targetIdx] = edges[idx1].w > edges[idx2].w ? idx1 : idx2;
      }


      public void calcAppend(int bit, int idx) {
        if (resIdx == -1 || edges[resIdx].w < edges[id0[bit][idx]].w) {
          resIdx = id0[bit][idx];
        }
      }

      public void calc(int fromIdx, int toIdx) {
        resIdx = -1;
        super.calc(fromIdx, toIdx);
      }

    }

  }

  static interface TreeInterface extends id16 {
  }

  static class id22 extends id33 {
    private int[][] rmq;
    private int[][] id32;
    private int[] initValues;
    private int resIdx;

    public id22(int capacity) {
      super(capacity);
    }


    public void createArrays(int id14) {
      rmq = new int[id14][];
      id32 = new int[id14][];
    }


    public void createArray(int bit, int capacity) {
      rmq[bit] = new int[capacity];
      id32[bit] = new int[capacity];
    }


    public void initSubclass(int n) {
      for (int i = 0; i < n; ++i) {
        rmq[0][i] = initValues[i];
        id32[0][i] = i;
      }
    }


    public void initMerge(int targetBit, int targetIdx, int sourceBit, int id1, int id18) {
      if (rmq[sourceBit][id1] <= rmq[sourceBit][id18]) {
        rmq[targetBit][targetIdx] = rmq[sourceBit][id1];
        id32[targetBit][targetIdx] = id32[sourceBit][id1];
      } else {
        rmq[targetBit][targetIdx] = rmq[sourceBit][id18];
        id32[targetBit][targetIdx] = id32[sourceBit][id18];
      }
    }


    public void calcMerge(int bit, int x, int y) {
      resIdx = rmq[bit][x] <= rmq[bit][y] ? id32[bit][x] : id32[bit][y];
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

  static interface id7 extends id5, id16 {
  }

  static abstract class id11 extends id24 implements id2 {
    public int[] edgeWeights;

    public id11(int vertexCapacity, int edgeCapacity) {
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
      edgeWeights[id3] = weight;
      super.add(fromIdx, toIdx);
    }


    public int edgeWeight(int edgeIdx) {
      return edgeWeights[edgeIdx];
    }

  }

  static interface id16 extends id28 {
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
        res = res * 10 + c - '0';
        c = nextChar();
      } while (!id4(c));
      return positive ? res : -res;
    }

    public int id9() {
      int res = nextChar();
      for (; id4(res) || res < 0; res = nextChar()) ;
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

    public boolean id4(int c) {
      return c == ' ' || c == '\t' || id27(c);
    }

    public boolean id27(int c) {
      return c == '\n' || c == '\r' || c < 0;
    }

  }

  static interface id2 extends id5, id28 {
  }

  static abstract class id24 implements id28 {
    public int vertexCnt;
    public int id3;
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

    public id24(int vertexCapacity, int edgeCapacity) {
      this(vertexCapacity, edgeCapacity, true);
    }

    public id24(int vertexCapacity, int edgeCapacity, boolean initialize) {
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
      id3 = 0;
      Arrays.fill(inDegree, 0, vertexCnt, 0);
      Arrays.fill(outDegree, 0, vertexCnt, 0);
      Arrays.fill(lastIn, 0, vertexCnt, -1);
      Arrays.fill(lastOut, 0, vertexCnt, -1);
      initSubclass(vertexCnt);
    }


    public void add(int fromIdx, int toIdx) {
      this.fromIdx[id3] = fromIdx;
      this.toIdx[id3] = toIdx;
      ++outDegree[fromIdx];
      ++inDegree[toIdx];
      nextOut[id3] = lastOut[fromIdx];
      lastOut[fromIdx] = id3;
      nextIn[id3] = lastIn[toIdx];
      lastIn[toIdx] = id3;
      ++id3;
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

  static interface id31 extends id5, TreeInterface {
  }

  static interface id5 {
  }

  static abstract class id25 {
    private id21 lca;
    private TreeInterface tree;
    private int[] id17;
    private int[][] ancestor;
    private int calcCnt;
    private int[] calcBit;
    private int[] calcIdx;

    public abstract void createSubclass(int id14, int capacity);

    public abstract void initSubclass(int u, int id17);

    public abstract void initMerge(int targetBit, int targetIdx, int sourceBit, int id1, int id18);

    public abstract void calcAppend(int bit, int idx);

    public id25(int capacity) {
      lca = new id21(capacity);
      id17 = new int[capacity];
      int highBit = 32 - Integer.numberOfLeadingZeros(capacity);
      ancestor = new int[highBit][capacity];
      calcBit = new int[highBit];
      calcIdx = new int[highBit];
      createSubclass(highBit, capacity);
    }

    public void init(TreeInterface tree, int id26) {
      this.tree = tree;
      lca.init(tree, id26);
      dfsInternal(id26, -1);
      int n = tree.vertexCnt();
      for (int i = 0; i < n; ++i) {
        int edgeIdx = id17[i];
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
          if (j >= 0) {
            initMerge(bit, i, bit - 1, i, j);
          }
        }
      }
    }

    public void calc(int fromIdx, int toIdx) {
      int lca = this.lca.calc(fromIdx, toIdx);
      int id15 = this.lca.depth[lca];
      int n = calcInternal(fromIdx, this.lca.depth[fromIdx] - id15);
      for (int i = 0; i < n; ++i) {
        calcAppend(calcBit[i], calcIdx[i]);
      }
      n = calcInternal(toIdx, this.lca.depth[toIdx] - id15);
      for (int i = n - 1; i >= 0; --i) {
        calcAppend(calcBit[i], calcIdx[i]);
      }
    }

    private void dfsInternal(int u, int id17) {
      this.id17[u] = id17;
      for (int edgeIdx = tree.lastOut(u); edgeIdx >= 0; edgeIdx = tree.nextOut(edgeIdx)) {
        if (edgeIdx != id17) {
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

  static class id29 extends id11 implements id7 {
    public id29(int vertexCapacity, int edgeCapacity) {
      super(vertexCapacity, edgeCapacity << 1);
    }


    public void add(int fromIdx, int toIdx, int weight) {
      super.add(fromIdx, toIdx, weight);
      super.add(toIdx, fromIdx, weight);
    }

  }

  static class id23 extends id29 implements id31 {
    public id23(int vertexCapacity) {
      super(vertexCapacity, vertexCapacity - 1);
    }

  }

  static class id19 {
    int[] parent;

    public id19(int vertexCapacity) {
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

  static abstract class id33 {
    public abstract void createArrays(int id14);

    public abstract void createArray(int bit, int capacity);

    public abstract void initSubclass(int n);

    public abstract void initMerge(int targetBit, int targetIdx, int sourceBit, int id1, int id18);

    public abstract void calcMerge(int bit, int x, int y);

    public id33(int capacity) {
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

  static interface id28 {
    int vertexCnt();

    int toIdx(int edgeIdx);

    int lastOut(int nodeIdx);

    int nextOut(int edgeIdx);

  }

  static class id21 {
    public int[] depth;
    private TreeInterface tree;
    private int dfsCnt;
    private int[] dfsIn;
    private int[] dfsOut;
    private int[] dfsDepth;
    private int[] id13;
    private id22 rmq;

    public id21(int vertexCapacity) {
      depth = new int[vertexCapacity];
      int id6 = vertexCapacity * 3;
      rmq = new id22(id6);
      dfsIn = new int[vertexCapacity];
      dfsOut = new int[vertexCapacity];
      dfsDepth = new int[id6];
      id13 = new int[id6];
    }

    public void init(TreeInterface tree, int id26) {
      this.tree = tree;
      dfsCnt = 0;
      dfsInternal(id26, -1, 0);
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

  }
}

