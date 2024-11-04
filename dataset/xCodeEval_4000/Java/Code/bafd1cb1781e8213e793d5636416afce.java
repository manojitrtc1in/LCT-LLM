import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.ArrayList;
import java.util.List;
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
    IntBoundedMaxFlowEdge[] edges;

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
      edges = new IntBoundedMaxFlowEdge[n];
      for (int i = 0; i < n; ++i) {
        

        edges[i] = bmf.add(x[i], disXCnt + y[i], 1);
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
        boolean red = (edges[i].flow > 0) ^ rbSwap;
        out.print(red ? 'r' : 'b');
      }
      out.println();
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

  static class IntArrayUtils {
    public static int unique(int[] values) {
      if (values.length == 0) return 0;
      int res = 1;
      for (int i = 1; i < values.length; ++i) {
        if (values[i - 1] != values[i]) {
          values[res++] = values[i];
        }
      }
      return res;
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


    public void add(int v) {
      ensureCapacity(size() + 1);
      values[close++] = v;
      close &= values.length - 1;
    }

    public int poll() {
      if (open == close) throw new ArrayIndexOutOfBoundsException();
      int res = values[open];
      open = (open + 1) & (values.length - 1);
      return res;
    }

    protected void ensureCapacity(int capacity) {
      if (capacity < values.length) return;
      int[] newValues = new int[Integer.highestOneBit(capacity) << 1];
      for (int i = 0, j = open; j != close; i++, j = (j + 1) & (values.length - 1)) {
        newValues[i] = values[j];
      }
      close = size();
      open = 0;
      values = newValues;
    }

  }

  static class DirectedGraphEdge {
    public int fromIdx;
    public int toIdx;
    public DirectedGraphEdge nextOutgoing;
    public DirectedGraphEdge nextIncoming;

    public DirectedGraphEdge(int fromIdx, int toIdx) {
      this.fromIdx = fromIdx;
      this.toIdx = toIdx;
    }

  }

  static class IntBoundedMaxFlow extends IntMaxFlow {
    private int fakeSource;
    private int fakeSink;
    private int[] inFlow;
    private int[] outFlow;
    private boolean noSolution;

    public IntBoundedMaxFlow(int vertexCapacity, int edgeCapacity) {
      super(vertexCapacity + 2, edgeCapacity + vertexCapacity);
      this.inFlow = new int[vertexCapacity];
      this.outFlow = new int[vertexCapacity];
    }


    public void init(int vertexCnt) {
      super.init(vertexCnt + 2);
      fakeSource = vertexCnt;
      fakeSink = vertexCnt + 1;
      Arrays.fill(inFlow, 0, vertexCnt, 0);
      Arrays.fill(outFlow, 0, vertexCnt, 0);
      noSolution = false;
    }


    public IntBoundedMaxFlowEdge add(int fromIdx, int toIdx, int upperBound) {
      return add(fromIdx, toIdx, 0, upperBound);
    }


    public IntBoundedMaxFlowEdge addInf(int fromIdx, int toIdx) {
      return add(fromIdx, toIdx, 0, IntMaxFlow.INF);
    }

    public IntBoundedMaxFlowEdge add(int fromIdx, int toIdx, int lowerBound, int upperBound) {
      noSolution |= lowerBound > upperBound;
      IntBoundedMaxFlowEdge forward = new IntBoundedMaxFlowEdge(fromIdx, toIdx, lowerBound, upperBound);
      IntMaxFlowEdge backward = new IntMaxFlowEdge(toIdx, fromIdx, 0);
      super.add(forward, backward);
      if (lowerBound > 0) {
        outFlow[fromIdx] += lowerBound;
        inFlow[toIdx] += lowerBound;
      }
      return forward;
    }


    public int calc(int source, int sink) {
      

      if (noSolution) return -1;
      IntMaxFlowEdge infEdge = super.addInf(sink, source);
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
      

    
      block(infEdge);
      for (IntMaxFlowEdge edge = lastOutgoingEdge(fakeSource); edge != null; edge = (IntMaxFlowEdge) edge.nextOutgoing) {
        block(edge);
      }
      for (IntMaxFlowEdge edge = lastIncomingEdge(fakeSink); edge != null; edge = (IntMaxFlowEdge) edge.nextIncoming) {
        block(edge);
      }
      

      

      

      res = super.calc(source, sink);
      if (res == IntMaxFlow.INF) return IntMaxFlow.INF;
      res = outFlow[source];
      for (IntMaxFlowEdge edge = lastOutgoingEdge(source); edge != null; edge = (IntMaxFlowEdge) edge.nextOutgoing) {
        res += edge.flow;
      }
      return res;
    }

    private void block(IntMaxFlowEdge edge) {
      edge.flow = edge.capacity = 0;
      IntMaxFlowEdge reverseEdge = (IntMaxFlowEdge) edge.reverse;
      reverseEdge.flow = reverseEdge.capacity = 0;
    }

  }

  static class DirectedGraph<EDGE extends DirectedGraphEdge> {
    public int vertexCnt;
    public List<EDGE> edges;
    public int[] inDegree;
    public int[] outDegree;
    private List<EDGE> lastOutgoingEdge;
    private List<EDGE> lastIncomingEdge;

    public DirectedGraph(int vertexCapacity, int edgeCapacity) {
      edges = new ArrayList<>(edgeCapacity);
      lastOutgoingEdge = new ArrayList<>(vertexCapacity);
      lastIncomingEdge = new ArrayList<>(vertexCapacity);
      inDegree = new int[vertexCapacity];
      outDegree = new int[vertexCapacity];
    }

    public void init(int vertexCnt) {
      this.vertexCnt = vertexCnt;
      edges.clear();
      lastOutgoingEdge.clear();
      lastIncomingEdge.clear();
      Arrays.fill(inDegree, 0, vertexCnt, 0);
      Arrays.fill(outDegree, 0, vertexCnt, 0);
      for (int i = 0; i < vertexCnt; ++i) {
        lastOutgoingEdge.add(null);
        lastIncomingEdge.add(null);
      }
    }

    public void add(EDGE edge) {
      edges.add(edge);
      int fromIdx = edge.fromIdx;
      int toIdx = edge.toIdx;
      edge.nextOutgoing = lastOutgoingEdge.get(fromIdx);
      lastOutgoingEdge.set(fromIdx, edge);
      edge.nextIncoming = lastIncomingEdge.get(toIdx);
      lastIncomingEdge.set(toIdx, edge);
      ++inDegree[toIdx];
      ++outDegree[fromIdx];
    }

    public EDGE lastOutgoingEdge(int vertexIdx) {
      return lastOutgoingEdge.get(vertexIdx);
    }

    public EDGE lastIncomingEdge(int vertexIdx) {
      return lastIncomingEdge.get(vertexIdx);
    }

  }

  static class IntMaxFlow extends BidirectionalGraph<IntMaxFlowEdge> {
    protected static final int INF = Integer.MAX_VALUE;
    private int source;
    private int sink;
    private IntArrayQueue q;
    private int[] level;
    private IntMaxFlowEdge[] edgePnt;

    public IntMaxFlow(int vertexCapacity, int edgeCapacity) {
      super(vertexCapacity, edgeCapacity);
      this.q = new IntArrayQueue(vertexCapacity);
      this.level = new int[vertexCapacity];
      this.edgePnt = new IntMaxFlowEdge[vertexCapacity];
    }

    public IntMaxFlowEdge add(int fromIdx, int toIdx, int capacity) {
      IntMaxFlowEdge forward = new IntMaxFlowEdge(fromIdx, toIdx, capacity);
      IntMaxFlowEdge backward = new IntMaxFlowEdge(toIdx, fromIdx, 0);
      super.add(forward, backward);
      return forward;
    }

    public IntMaxFlowEdge addInf(int fromIdx, int toIdx) {
      return add(fromIdx, toIdx, INF);
    }

    public int calc(int source, int sink) {
      this.source = source;
      this.sink = sink;
      int res = 0;
      while (bfs()) {
        for (int i = 0; i < vertexCnt; ++i) edgePnt[i] = lastOutgoingEdge(i);
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
        for (IntMaxFlowEdge edge = lastOutgoingEdge(u); edge != null; edge = (IntMaxFlowEdge) edge.nextOutgoing) {
          int v = edge.toIdx;
          if (level[v] < 0 && edge.flow < edge.capacity) {
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
      for (; edgePnt[u] != null; edgePnt[u] = (IntMaxFlowEdge) edgePnt[u].nextOutgoing) {
        IntMaxFlowEdge edge = edgePnt[u];
        int v = edge.toIdx;
        if (level[v] != level[u] + 1) continue;
        int res = dfs(v, Math.min(flow, edge.capacity - edge.flow));
        if (res > 0) {
          

          edge.flow += res;
          ((IntMaxFlowEdge) edge.reverse).flow -= res;
          return res;
        }
      }
      return 0;
    }

  }

  static interface IntCollection {
    int size();

    default boolean isEmpty() {
      return size() == 0;
    }

  }

  static class IntMaxFlowEdge extends BidirectionalGraphEdge {
    public int capacity;
    public int flow;

    public IntMaxFlowEdge(int fromIdx, int toIdx, int capacity) {
      super(fromIdx, toIdx);
      this.capacity = capacity;
      this.flow = 0;
    }

  }

  static class QuickScanner {
    private static final int BUFFER_SIZE = 1024;
    private InputStream stream;
    private byte[] buffer;
    private int currentPostion;
    private int numberOfChars;

    public QuickScanner(InputStream stream) {
      this.stream = stream;
      this.buffer = new byte[BUFFER_SIZE];
      this.currentPostion = 0;
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
      if (currentPostion >= numberOfChars) {
        currentPostion = 0;
        try {
          numberOfChars = stream.read(buffer);
        } catch (Exception e) {
          throw new RuntimeException(e);
        }
        if (numberOfChars <= 0) {
          return -1;
        }
      }
      return buffer[currentPostion++];
    }

    public boolean isSpaceChar(int c) {
      return c == ' '
          || c == '\n'
          || c == '\r'
          || c == '\t'
          || c < 0;
    }

  }

  static class BidirectionalGraph<EDGE extends BidirectionalGraphEdge> extends DirectedGraph<EDGE> {
    public BidirectionalGraph(int vertexCapacity, int edgeCapacity) {
      super(vertexCapacity, edgeCapacity << 1);
    }

    public void add(EDGE edge, EDGE reverseEdge) {
      add(edge);
      add(reverseEdge);
      edge.reverse = reverseEdge;
      reverseEdge.reverse = edge;
    }

  }

  static class BidirectionalGraphEdge extends DirectedGraphEdge {
    public BidirectionalGraphEdge reverse;

    public BidirectionalGraphEdge(int fromIdx, int toIdx) {
      super(fromIdx, toIdx);
    }

  }

  static class IntBoundedMaxFlowEdge extends IntMaxFlowEdge {
    public int lowerBound;
    public int upperBound;

    public IntBoundedMaxFlowEdge(int fromIdx, int toIdx, int lowerBound, int upperBound) {
      super(fromIdx, toIdx, upperBound - lowerBound);
      this.lowerBound = lowerBound;
      this.upperBound = upperBound;
    }

  }
}

