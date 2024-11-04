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
    TaskD solver = new TaskD();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskD {
    int n;
    int m;
    long r;
    long b;
    boolean rbSwap;
    int[] x;
    int[] y;
    int disXCnt;
    int disYCnt;
    int[] disX;
    int[] disY;
    int[] xCnt;
    int[] yCnt;
    int[] xLimit;
    int[] yLimit;
    IntBoundedMaxFlow bmf;
    int[] edges;

    public void solve(int testNumber, QuickScanner in, QuickWriter out) {
      n = in.nextInt();
      m = in.nextInt();
      r = in.nextLong();
      b = in.nextLong();
      rbSwap = r > b;
      if (rbSwap) {
        r ^= b;
        b ^= r;
        r ^= b;
      }
      x = new int[n];
      y = new int[n];
      disX = new int[n];
      disY = new int[n];
      for (int i = 0; i < n; ++i) {
        x[i] = in.nextInt();
        y[i] = in.nextInt();
        disX[i] = x[i];
        disY[i] = y[i];
      }
      Arrays.sort(disX);
      Arrays.sort(disY);
      disXCnt = IntArrayUtils.unique(disX);
      disYCnt = IntArrayUtils.unique(disY);
      xCnt = new int[disXCnt];
      yCnt = new int[disYCnt];
      for (int i = 0; i < n; ++i) {
        x[i] = Arrays.binarySearch(disX, 0, disXCnt, x[i]);
        y[i] = Arrays.binarySearch(disY, 0, disYCnt, y[i]);
        ++xCnt[x[i]];
        ++yCnt[y[i]];
      }
      xLimit = new int[disXCnt];
      yLimit = new int[disYCnt];
      for (int i = 0; i < disXCnt; ++i) xLimit[i] = xCnt[i];
      for (int i = 0; i < disYCnt; ++i) yLimit[i] = yCnt[i];
      for (int i = 0; i < m; ++i) {
        int t = in.nextInt();
        int l = in.nextInt();
        int d = in.nextInt();
        if (t == 1) {
          int idx = Arrays.binarySearch(disX, 0, disXCnt, l);
          if (idx < 0) continue;
          xLimit[idx] = Math.min(xLimit[idx], d);
        } else {
          int idx = Arrays.binarySearch(disY, 0, disYCnt, l);
          if (idx < 0) continue;
          yLimit[idx] = Math.min(yLimit[idx], d);
        }
      }
      bmf = new IntBoundedMaxFlow(disXCnt + disYCnt + 2, disXCnt + disYCnt + n);
      bmf.init(disXCnt + disYCnt + 2);
      int source = disXCnt + disYCnt, sink = source + 1;
      edges = new int[n];
      for (int i = 0; i < n; ++i) {
        edges[i] = bmf.add(x[i], disXCnt + y[i], 0, 1);
      }
      for (int i = 0; i < disXCnt; ++i) {
        bmf.add(source, i, (xCnt[i] - xLimit[i] + 1) >> 1, (xCnt[i] + xLimit[i]) >> 1);
      }
      for (int i = 0; i < disYCnt; ++i) {
        bmf.add(disXCnt + i, sink, (yCnt[i] - yLimit[i] + 1) >> 1, (yCnt[i] + yLimit[i]) >> 1);
      }
      int cnt = bmf.calc(source, sink);
      if (cnt == -1) {
        out.println("-1");
        return;
      }
      long res = r * cnt + b * (n - cnt);
      out.println(res);
      for (int i = 0; i < n; ++i) {
        boolean red = (bmf.flow[edges[i]] > 0) ^ rbSwap;
        out.print(red ? 'r' : 'b');
      }
      out.println();
    }

  }

  static class IntMaxFlow extends AbstractBidirectionalGraph {
    protected static final int INF = Integer.MAX_VALUE;
    public int[] flow;
    public int[] capacity;
    private int source;
    private int sink;
    private IntArrayQueue q;
    private int[] level;
    private int[] edgePnt;

    public IntMaxFlow(int vertexCapacity, int edgeCapacity) {
      super(vertexCapacity, edgeCapacity);
    }

    public IntMaxFlow(int vertexCapacity, int edgeCapacity, boolean initialize) {
      super(vertexCapacity, edgeCapacity, initialize);
    }


    public void createSubclass(int vertexCapacity, int edgeCapacity) {
      this.flow = new int[edgeCapacity];
      this.capacity = new int[edgeCapacity];
      this.q = new IntArrayQueue(vertexCapacity);
      this.level = new int[vertexCapacity];
      this.edgePnt = new int[vertexCapacity];
    }


    public void initSubclass(int vertexCnt) {
    }


    public void add(int fromIdx, int toIdx) {
      throw new UnsupportedOperationException();
    }

    public int add(int fromIdx, int toIdx, int capacity) {
      flow[currentEdgeCnt] = flow[currentEdgeCnt + 1] = 0;
      this.capacity[currentEdgeCnt] = capacity;
      this.capacity[currentEdgeCnt + 1] = 0;
      super.add(fromIdx, toIdx);
      return currentEdgeCnt - 2;
    }

    public int addInf(int fromIdx, int toIdx) {
      return add(fromIdx, toIdx, INF);
    }

    public int calc(int source, int sink) {
      this.source = source;
      this.sink = sink;
      int res = 0;
      while (bfs()) {
        for (int i = 0; i < vertexCnt; ++i) edgePnt[i] = lastOut[i];
        while (true) {
          int flow = dfs(source, INF);
          if (flow == INF) return INF;
          if (flow == 0) break;
          res += flow;
        }
      }
      return res;
    }

    private boolean bfs() {
      q.clear();
      q.add(source);
      Arrays.fill(level, 0, vertexCnt, -1);
      level[source] = 0;
      while (!q.isEmpty() && level[sink] < 0) {
        int u = q.poll();
        for (int edgeIdx = lastOut[u]; edgeIdx >= 0; edgeIdx = nextOut[edgeIdx]) {
          int v = toIdx[edgeIdx];
          if (level[v] < 0 && flow[edgeIdx] < capacity[edgeIdx]) {
            q.add(v);
            level[v] = level[u] + 1;
          }
        }
      }
      return level[sink] >= 0;
    }

    private int dfs(int u, int flow) {
      if (flow == 0) return 0;
      if (u == sink) return flow;
      for (; edgePnt[u] >= 0; edgePnt[u] = nextOut[edgePnt[u]]) {
        int edgeIdx = edgePnt[u];
        int v = toIdx[edgeIdx];
        if (level[v] != level[u] + 1) continue;
        int res = dfs(v, Math.min(flow, capacity[edgeIdx] - this.flow[edgeIdx]));
        if (res > 0) {
          this.flow[edgeIdx] += res;
          this.flow[edgeIdx ^ 1] -= res;
          return res;
        }
      }
      return 0;
    }

  }

  static class IntArrayQueue implements IntCollection {
    protected int[] values;
    protected int open;
    protected int close;

    public IntArrayQueue(int capacity) {
      values = new int[Integer.highestOneBit(capacity) << 1];
    }


    public void clear() {
      open = close = 0;
    }


    public int size() {
      return (close - open) & (values.length - 1);
    }


    public void add(int value) {
      ensureCapacity(size() + 1);
      values[close++] = value;
      close &= values.length - 1;
    }

    public int poll() {
      if (open == close) throw new ArrayIndexOutOfBoundsException();
      int res = values[open];
      open = (open + 1) & (values.length - 1);
      return res;
    }


    public String toString() {
      StringBuilder sb = new StringBuilder("[");
      for (int i = open; i != close; i = (i + 1) & (values.length - 1)) {
        if (i != open) sb.append(',').append(' ');
        sb.append(values[i]);
      }
      return sb.append(']').toString();
    }

    protected void ensureCapacity(int capacity) {
      if (capacity < values.length) return;
      int[] newValues = new int[Integer.highestOneBit(capacity) << 1];
      for (int i = 0, j = open; j != close; ++i, j = (j + 1) & (values.length - 1)) {
        newValues[i] = values[j];
      }
      close = size();
      open = 0;
      values = newValues;
    }

  }

  static interface IntCollection {
    int size();

    default boolean isEmpty() {
      return size() == 0;
    }

  }

  static abstract class AbstractBidirectionalGraph extends AbstractDirectedGraph implements BidirectionalGraphInterface {
    public AbstractBidirectionalGraph(int vertexCapacity, int edgeCapacity) {
      super(vertexCapacity, edgeCapacity << 1);
    }

    public AbstractBidirectionalGraph(int vertexCapacity, int edgeCapacity, boolean initialize) {
      super(vertexCapacity, edgeCapacity << 1, initialize);
    }


    public void add(int u, int v) {
      super.add(u, v);
      super.add(v, u);
    }

  }

  static interface DirectedGraphInterface {
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

  static class IntBoundedMaxFlow extends IntMaxFlow {
    public int[] lowerBound;
    public int[] upperBound;
    private int fakeSource;
    private int fakeSink;
    private int[] inFlow;
    private int[] outFlow;
    private boolean noSolution;

    public IntBoundedMaxFlow(int vertexCapacity, int edgeCapacity) {
      super(vertexCapacity + 2, edgeCapacity + vertexCapacity + 1, false);
      init(vertexCapacity);
    }


    public void createSubclass(int vertexCapacity, int edgeCapacity) {
      super.createSubclass(vertexCapacity, edgeCapacity);
      this.lowerBound = new int[edgeCapacity];
      this.upperBound = new int[edgeCapacity];
      this.inFlow = new int[vertexCapacity];
      this.outFlow = new int[vertexCapacity];
    }


    public void initSubclass(int vertexCnt) {
      super.initSubclass(vertexCnt);
      fakeSource = vertexCnt - 2;
      fakeSink = vertexCnt - 1;
      Arrays.fill(inFlow, 0, vertexCnt, 0);
      Arrays.fill(outFlow, 0, vertexCnt, 0);
      noSolution = false;
    }


    public void init(int vertexCnt) {
      super.init(vertexCnt + 2);
    }


    public int add(int fromIdx, int toIdx, int upperBound) {
      return add(fromIdx, toIdx, 0, upperBound);
    }


    public int addInf(int fromIdx, int toIdx) {
      return add(fromIdx, toIdx, 0, IntMaxFlow.INF);
    }

    public int add(int fromIdx, int toIdx, int lowerBound, int upperBound) {
      noSolution |= lowerBound > upperBound;
      this.lowerBound[currentEdgeCnt] = lowerBound;
      this.upperBound[currentEdgeCnt] = upperBound;
      if (lowerBound > 0) {
        outFlow[fromIdx] += lowerBound;
        inFlow[toIdx] += lowerBound;
      }
      return super.add(fromIdx, toIdx, upperBound - lowerBound);
    }


    public int calc(int source, int sink) {
      if (noSolution) return -1;
      int infEdgeIdx = super.addInf(sink, source);
      int sum = 0;
      for (int i = 0; i + 2 < vertexCnt; ++i)
        if (inFlow[i] != outFlow[i]) {
          if (inFlow[i] > outFlow[i]) {
            sum += inFlow[i] - outFlow[i];
            super.add(fakeSource, i, inFlow[i] - outFlow[i]);
          } else {
            super.add(i, fakeSink, outFlow[i] - inFlow[i]);
          }
        }
      int res = super.calc(fakeSource, fakeSink);
      if (res != sum) return -1;
      block(infEdgeIdx);
      for (int edgeIdx = lastOut[fakeSource]; edgeIdx >= 0; edgeIdx = nextOut[edgeIdx]) {
        block(edgeIdx);
      }
      for (int edgeIdx = lastIn[fakeSink]; edgeIdx >= 0; edgeIdx = nextIn[edgeIdx]) {
        block(edgeIdx);
      }
      res = super.calc(source, sink);
      if (res == IntMaxFlow.INF) return IntMaxFlow.INF;
      res = outFlow[source];
      for (int edgeIdx = lastOut[source]; edgeIdx >= 0; edgeIdx = nextOut[edgeIdx]) {
        res += flow[edgeIdx];
      }
      return res;
    }

    private void block(int edgeIdx) {
      flow[edgeIdx] = capacity[edgeIdx] = 0;
      flow[edgeIdx ^ 1] = capacity[edgeIdx ^ 1] = 0;
    }

  }

  static interface BidirectionalGraphInterface extends DirectedGraphInterface {
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

    public long nextLong() {
      int c = nextNonSpaceChar();
      boolean positive = true;
      if (c == '-') {
        positive = false;
        c = nextChar();
      }
      long res = 0;
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
      return c == ' '
          || c == '\n'
          || c == '\r'
          || c == '\t'
          || c < 0;
    }

  }

  static class IntArrayUtils {
    public static int unique(int[] values) {
      return unique(values, 0, values.length);
    }

    public static int unique(int[] values, int fromIdx, int toIdx) {
      if (fromIdx == toIdx) return 0;
      int res = 1;
      for (int i = fromIdx + 1; i < toIdx; ++i) {
        if (values[i - 1] != values[i]) {
          values[fromIdx + res++] = values[i];
        }
      }
      return res;
    }

  }
}

