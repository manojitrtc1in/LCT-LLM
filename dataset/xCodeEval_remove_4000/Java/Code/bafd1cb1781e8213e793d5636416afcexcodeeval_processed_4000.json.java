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
    int id7;
    int id10;
    int[] disX;
    int[] disY;
    int[] xCnt;
    int[] yCnt;
    int[] xLimit;
    int[] yLimit;
    id0 bmf;
    id17[] edges;

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
      id7 = id3.unique(disX);
      id10 = id3.unique(disY);
      xCnt = new int[id7];
      yCnt = new int[id10];
      for (int i = 0; i < n; ++i) {
        x[i] = Arrays.binarySearch(disX, 0, id7, x[i]);
        y[i] = Arrays.binarySearch(disY, 0, id10, y[i]);
        ++xCnt[x[i]];
        ++yCnt[y[i]];
      }
      xLimit = new int[id7];
      yLimit = new int[id10];
      for (int i = 0; i < id7; ++i) xLimit[i] = xCnt[i];
      for (int i = 0; i < id10; ++i) yLimit[i] = yCnt[i];
      for (int i = 0; i < m; ++i) {
        int t = in.nextInt();
        int l = in.nextInt();
        int d = in.nextInt();
        if (t == 1) {
          int idx = Arrays.binarySearch(disX, 0, id7, l);
          if (idx < 0) continue;
          xLimit[idx] = Math.min(xLimit[idx], d);
        } else {
          int idx = Arrays.binarySearch(disY, 0, id10, l);
          if (idx < 0) continue;
          yLimit[idx] = Math.min(yLimit[idx], d);
        }
      }
      bmf = new id0(id7 + id10 + 2, id7 + id10 + n);
      bmf.init(id7 + id10 + 2);
      int source = id7 + id10, sink = source + 1;
      edges = new id17[n];
      for (int i = 0; i < n; ++i) {
        

        edges[i] = bmf.add(x[i], id7 + y[i], 1);
      }
      for (int i = 0; i < id7; ++i) {
        

        bmf.add(source, i, (xCnt[i] - xLimit[i] + 1) >> 1, (xCnt[i] + xLimit[i]) >> 1);
      }
      for (int i = 0; i < id10; ++i) {
        

        bmf.add(id7 + i, sink, (yCnt[i] - yLimit[i] + 1) >> 1, (yCnt[i] + yLimit[i]) >> 1);
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

  static class id5 {
    public int fromIdx;
    public int toIdx;
    public id5 nextOutgoing;
    public id5 nextIncoming;

    public id5(int fromIdx, int toIdx) {
      this.fromIdx = fromIdx;
      this.toIdx = toIdx;
    }

  }

  static class id0 extends id13 {
    private int fakeSource;
    private int fakeSink;
    private int[] inFlow;
    private int[] outFlow;
    private boolean noSolution;

    public id0(int vertexCapacity, int edgeCapacity) {
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


    public id17 add(int fromIdx, int toIdx, int upperBound) {
      return add(fromIdx, toIdx, 0, upperBound);
    }


    public id17 addInf(int fromIdx, int toIdx) {
      return add(fromIdx, toIdx, 0, id13.INF);
    }

    public id17 add(int fromIdx, int toIdx, int lowerBound, int upperBound) {
      noSolution |= lowerBound > upperBound;
      id17 forward = new id17(fromIdx, toIdx, lowerBound, upperBound);
      id15 backward = new id15(toIdx, fromIdx, 0);
      super.add(forward, backward);
      if (lowerBound > 0) {
        outFlow[fromIdx] += lowerBound;
        inFlow[toIdx] += lowerBound;
      }
      return forward;
    }


    public int calc(int source, int sink) {
      

      if (noSolution) return -1;
      id15 infEdge = super.addInf(sink, source);
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
      for (id15 edge = id16(fakeSource); edge != null; edge = (id15) edge.nextOutgoing) {
        block(edge);
      }
      for (id15 edge = id8(fakeSink); edge != null; edge = (id15) edge.nextIncoming) {
        block(edge);
      }
      

      

      

      res = super.calc(source, sink);
      if (res == id13.INF) return id13.INF;
      res = outFlow[source];
      for (id15 edge = id16(source); edge != null; edge = (id15) edge.nextOutgoing) {
        res += edge.flow;
      }
      return res;
    }

    private void block(id15 edge) {
      edge.flow = edge.capacity = 0;
      id15 reverseEdge = (id15) edge.reverse;
      reverseEdge.flow = reverseEdge.capacity = 0;
    }

  }

  static class DirectedGraph<EDGE extends id5> {
    public int vertexCnt;
    public List<EDGE> edges;
    public int[] inDegree;
    public int[] outDegree;
    private List<EDGE> id16;
    private List<EDGE> id8;

    public DirectedGraph(int vertexCapacity, int edgeCapacity) {
      edges = new ArrayList<>(edgeCapacity);
      id16 = new ArrayList<>(vertexCapacity);
      id8 = new ArrayList<>(vertexCapacity);
      inDegree = new int[vertexCapacity];
      outDegree = new int[vertexCapacity];
    }

    public void init(int vertexCnt) {
      this.vertexCnt = vertexCnt;
      edges.clear();
      id16.clear();
      id8.clear();
      Arrays.fill(inDegree, 0, vertexCnt, 0);
      Arrays.fill(outDegree, 0, vertexCnt, 0);
      for (int i = 0; i < vertexCnt; ++i) {
        id16.add(null);
        id8.add(null);
      }
    }

    public void add(EDGE edge) {
      edges.add(edge);
      int fromIdx = edge.fromIdx;
      int toIdx = edge.toIdx;
      edge.nextOutgoing = id16.get(fromIdx);
      id16.set(fromIdx, edge);
      edge.nextIncoming = id8.get(toIdx);
      id8.set(toIdx, edge);
      ++inDegree[toIdx];
      ++outDegree[fromIdx];
    }

    public EDGE id16(int vertexIdx) {
      return id16.get(vertexIdx);
    }

    public EDGE id8(int vertexIdx) {
      return id8.get(vertexIdx);
    }

  }

  static class id13 extends id9<id15> {
    protected static final int INF = Integer.MAX_VALUE;
    private int source;
    private int sink;
    private id2 q;
    private int[] level;
    private id15[] id14;

    public id13(int vertexCapacity, int edgeCapacity) {
      super(vertexCapacity, edgeCapacity);
      this.q = new id2(vertexCapacity);
      this.level = new int[vertexCapacity];
      this.id14 = new id15[vertexCapacity];
    }

    public id15 add(int fromIdx, int toIdx, int capacity) {
      id15 forward = new id15(fromIdx, toIdx, capacity);
      id15 backward = new id15(toIdx, fromIdx, 0);
      super.add(forward, backward);
      return forward;
    }

    public id15 addInf(int fromIdx, int toIdx) {
      return add(fromIdx, toIdx, INF);
    }

    public int calc(int source, int sink) {
      this.source = source;
      this.sink = sink;
      int res = 0;
      while (bfs()) {
        for (int i = 0; i < vertexCnt; ++i) id14[i] = id16(i);
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
        for (id15 edge = id16(u); edge != null; edge = (id15) edge.nextOutgoing) {
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
      for (; id14[u] != null; id14[u] = (id15) id14[u].nextOutgoing) {
        id15 edge = id14[u];
        int v = edge.toIdx;
        if (level[v] != level[u] + 1) continue;
        int res = dfs(v, Math.min(flow, edge.capacity - edge.flow));
        if (res > 0) {
          

          edge.flow += res;
          ((id15) edge.reverse).flow -= res;
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

  static class id15 extends id6 {
    public int capacity;
    public int flow;

    public id15(int fromIdx, int toIdx, int capacity) {
      super(fromIdx, toIdx);
      this.capacity = capacity;
      this.flow = 0;
    }

  }

  static class QuickScanner {
    private static final int BUFFER_SIZE = 1024;
    private InputStream stream;
    private byte[] buffer;
    private int id1;
    private int id11;

    public QuickScanner(InputStream stream) {
      this.stream = stream;
      this.buffer = new byte[BUFFER_SIZE];
      this.id1 = 0;
      this.id11 = 0;
    }

    public int nextInt() {
      int c = id12();
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
      int c = id12();
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

    public int id12() {
      int res = nextChar();
      for (; id4(res) || res < 0; res = nextChar()) ;
      return res;
    }

    public int nextChar() {
      if (id11 == -1) {
        throw new RuntimeException();
      }
      if (id1 >= id11) {
        id1 = 0;
        try {
          id11 = stream.read(buffer);
        } catch (Exception e) {
          throw new RuntimeException(e);
        }
        if (id11 <= 0) {
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

  static class id9<EDGE extends id6> extends DirectedGraph<EDGE> {
    public id9(int vertexCapacity, int edgeCapacity) {
      super(vertexCapacity, edgeCapacity << 1);
    }

    public void add(EDGE edge, EDGE reverseEdge) {
      add(edge);
      add(reverseEdge);
      edge.reverse = reverseEdge;
      reverseEdge.reverse = edge;
    }

  }

  static class id6 extends id5 {
    public id6 reverse;

    public id6(int fromIdx, int toIdx) {
      super(fromIdx, toIdx);
    }

  }

  static class id17 extends id15 {
    public int lowerBound;
    public int upperBound;

    public id17(int fromIdx, int toIdx, int lowerBound, int upperBound) {
      super(fromIdx, toIdx, upperBound - lowerBound);
      this.lowerBound = lowerBound;
      this.upperBound = upperBound;
    }

  }
}

