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
    int id5;
    int id7;
    int[] disX;
    int[] disY;
    int[] xCnt;
    int[] yCnt;
    int[] xLimit;
    int[] yLimit;
    id0 bmf;
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
      id5 = id3.unique(disX);
      id7 = id3.unique(disY);
      xCnt = new int[id5];
      yCnt = new int[id7];
      for (int i = 0; i < n; ++i) {
        x[i] = Arrays.binarySearch(disX, 0, id5, x[i]);
        y[i] = Arrays.binarySearch(disY, 0, id7, y[i]);
        ++xCnt[x[i]];
        ++yCnt[y[i]];
      }
      xLimit = new int[id5];
      yLimit = new int[id7];
      for (int i = 0; i < id5; ++i) xLimit[i] = xCnt[i];
      for (int i = 0; i < id7; ++i) yLimit[i] = yCnt[i];
      for (int i = 0; i < m; ++i) {
        int t = in.nextInt();
        int l = in.nextInt();
        int d = in.nextInt();
        if (t == 1) {
          int idx = Arrays.binarySearch(disX, 0, id5, l);
          if (idx < 0) continue;
          xLimit[idx] = Math.min(xLimit[idx], d);
        } else {
          int idx = Arrays.binarySearch(disY, 0, id7, l);
          if (idx < 0) continue;
          yLimit[idx] = Math.min(yLimit[idx], d);
        }
      }
      bmf = new id0(id5 + id7 + 2, id5 + id7 + n);
      bmf.init(id5 + id7 + 2);
      int source = id5 + id7, sink = source + 1;
      edges = new int[n];
      for (int i = 0; i < n; ++i) {
        edges[i] = bmf.add(x[i], id5 + y[i], 0, 1);
      }
      for (int i = 0; i < id5; ++i) {
        bmf.add(source, i, (xCnt[i] - xLimit[i] + 1) >> 1, (xCnt[i] + xLimit[i]) >> 1);
      }
      for (int i = 0; i < id7; ++i) {
        bmf.add(id5 + i, sink, (yCnt[i] - yLimit[i] + 1) >> 1, (yCnt[i] + yLimit[i]) >> 1);
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

  static class id3 {
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

  static class id0 extends id11 {
    public int[] lowerBound;
    public int[] upperBound;
    private int fakeSource;
    private int fakeSink;
    private int[] inFlow;
    private int[] outFlow;
    private boolean noSolution;

    public id0(int vertexCapacity, int edgeCapacity) {
      super(vertexCapacity + 2, edgeCapacity + vertexCapacity + 1);
      this.lowerBound = new int[(edgeCapacity + vertexCapacity + 1) << 1];
      this.upperBound = new int[(edgeCapacity + vertexCapacity + 1) << 1];
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


    public int add(int fromIdx, int toIdx, int upperBound) {
      return add(fromIdx, toIdx, 0, upperBound);
    }


    public int addInf(int fromIdx, int toIdx) {
      return add(fromIdx, toIdx, 0, id11.INF);
    }

    public int add(int fromIdx, int toIdx, int lowerBound, int upperBound) {
      noSolution |= lowerBound > upperBound;
      this.lowerBound[edgeCnt] = lowerBound;
      this.upperBound[edgeCnt] = upperBound;
      if (lowerBound > 0) {
        outFlow[fromIdx] += lowerBound;
        inFlow[toIdx] += lowerBound;
      }
      return super.add(fromIdx, toIdx, upperBound - lowerBound);
    }


    public int calc(int source, int sink) {
      if (noSolution) return -1;
      int id10 = super.addInf(sink, source);
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
      block(id10);
      for (int edgeIdx = lastOut[fakeSource]; edgeIdx >= 0; edgeIdx = nextOut[edgeIdx]) {
        block(edgeIdx);
      }
      for (int edgeIdx = lastIn[fakeSink]; edgeIdx >= 0; edgeIdx = nextIn[edgeIdx]) {
        block(edgeIdx);
      }
      res = super.calc(source, sink);
      if (res == id11.INF) return id11.INF;
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

  static class id11 extends id6 {
    protected static final int INF = Integer.MAX_VALUE;
    public int[] flow;
    public int[] capacity;
    private int source;
    private int sink;
    private id2 q;
    private int[] level;
    private int[] id12;

    public id11(int vertexCapacity, int edgeCapacity) {
      super(vertexCapacity, edgeCapacity);
      this.flow = new int[edgeCapacity << 1];
      this.capacity = new int[edgeCapacity << 1];
      this.q = new id2(vertexCapacity);
      this.level = new int[vertexCapacity];
      this.id12 = new int[vertexCapacity];
    }


    public void add(int fromIdx, int toIdx) {
      throw new UnsupportedOperationException();
    }

    public int add(int fromIdx, int toIdx, int capacity) {
      flow[edgeCnt] = flow[edgeCnt + 1] = 0;
      this.capacity[edgeCnt] = capacity;
      this.capacity[edgeCnt + 1] = 0;
      super.add(fromIdx, toIdx);
      return edgeCnt - 2;
    }

    public int addInf(int fromIdx, int toIdx) {
      return add(fromIdx, toIdx, INF);
    }

    public int calc(int source, int sink) {
      this.source = source;
      this.sink = sink;
      int res = 0;
      while (bfs()) {
        for (int i = 0; i < vertexCnt; ++i) id12[i] = lastOut[i];
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
      for (; id12[u] >= 0; id12[u] = nextOut[id12[u]]) {
        int edgeIdx = id12[u];
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

  static interface IntCollection {
    int size();

    default boolean isEmpty() {
      return size() == 0;
    }

  }

  static class id2 implements IntCollection {
    protected int[] values;
    protected int open;
    protected int close;

    public id2(int capacity) {
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

  static class DirectedGraph {
    public int vertexCnt;
    public int edgeCnt;
    public int[] fromIdx;
    public int[] toIdx;
    public int[] nextIn;
    public int[] nextOut;
    public int[] lastIn;
    public int[] lastOut;
    public int[] inDegree;
    public int[] outDegree;

    public DirectedGraph(int vertexCapacity, int edgeCapacity) {
      this.fromIdx = new int[edgeCapacity];
      this.toIdx = new int[edgeCapacity];
      this.lastIn = new int[vertexCapacity];
      this.lastOut = new int[vertexCapacity];
      this.nextIn = new int[edgeCapacity];
      this.nextOut = new int[edgeCapacity];
      this.inDegree = new int[vertexCapacity];
      this.outDegree = new int[vertexCapacity];
    }

    public void init(int vertexCnt) {
      this.vertexCnt = vertexCnt;
      this.edgeCnt = 0;
      Arrays.fill(inDegree, 0, vertexCnt, 0);
      Arrays.fill(outDegree, 0, vertexCnt, 0);
      Arrays.fill(lastIn, 0, vertexCnt, -1);
      Arrays.fill(lastOut, 0, vertexCnt, -1);
    }

    public void add(int fromIdx, int toIdx) {
      this.fromIdx[edgeCnt] = fromIdx;
      this.toIdx[edgeCnt] = toIdx;
      ++outDegree[fromIdx];
      ++inDegree[toIdx];
      nextOut[edgeCnt] = lastOut[fromIdx];
      lastOut[fromIdx] = edgeCnt;
      nextIn[edgeCnt] = lastIn[toIdx];
      lastIn[toIdx] = edgeCnt;
      ++edgeCnt;
    }

  }

  static class id6 extends DirectedGraph {
    public id6(int vertexCapacity, int edgeCapacity) {
      super(vertexCapacity, edgeCapacity << 1);
    }


    public void add(int u, int v) {
      super.add(u, v);
      super.add(v, u);
    }

  }

  static class QuickScanner {
    private static final int BUFFER_SIZE = 1024;
    private InputStream stream;
    private byte[] buffer;
    private int id1;
    private int id8;

    public QuickScanner(InputStream stream) {
      this.stream = stream;
      this.buffer = new byte[BUFFER_SIZE];
      this.id1 = 0;
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

    public long nextLong() {
      int c = id9();
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
      if (id1 >= id8) {
        id1 = 0;
        try {
          id8 = stream.read(buffer);
        } catch (Exception e) {
          throw new RuntimeException(e);
        }
        if (id8 <= 0) {
          return -1;
        }
      }
      return buffer[id1++];
    }

    public boolean id4(int c) {
      return c == ' '
          || c == '\n'
          || c == '\r'
          || c == '\t'
          || c < 0;
    }

  }
}

