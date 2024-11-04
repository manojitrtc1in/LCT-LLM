import java.util.*;
import java.io.*;
import java.math.*;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
public class Main {
  static class PR
  {
    public int x;
    public int y;
    public PR(int x_, int y_) {
      x = x_;
      y = y_;
    }
  };
  static MaxFlow mf;
  static int source;

  static int sink;

  public static long INF = 1l << 50;
  static ArrayList<Integer> a[] = new ArrayList[22000];
  

  

  static int [][]fa = new int[50001][21];
  static int []dep = new int[50001];
  static Map<PR, Integer> mp;
  static void dfs(int x, int f) {
    fa[x][0] = f;
    for (int i = 1;i <= 20;++i) {
      fa[x][i] = fa[fa[x][i - 1]][i - 1];
    }
    dep[x] = dep[f] + 1;
    for (int v:a[x]) {
      if (v != f) dfs(v, x);
    }
  }
  static void dfs_edge(int x, int f) {
    fa[x][0] = f;
    if (f != 0) {
      int nid0 = mp.get(new PR(x, 0));
      mf.add_edge(nid0, sink, 1);
    }
    for (int i = 1;i <= 20;++i) {
      fa[x][i] = fa[fa[x][i - 1]][i - 1];
      if (fa[x][i] > 0) {
        int nid1 = mp.get(new PR(x, i));
        int nid2 = mp.get(new PR(x, i - 1));
        int nid3 = mp.get(new PR(fa[x][i - 1], i - 1));
        mf.add_edge(nid1, nid2, INF);
        mf.add_edge(nid1, nid3, INF);
      }
    }
    for (int v:a[x]) {
      if (v != f) dfs_edge(v, x);
    }
  }
  

  

  

  

  static void  LCA_eid(int u,int v, int eid)
  {
    if (dep[u] < dep[v]) {
      int tmp = u;
      u = v;
      v = tmp;
    }
    int delta = dep[u] - dep[v];
    for(int x = 0;x <= 20;x++) {
      int flag = (1<<x)&delta;
      if(flag > 0) {
        int nid = mp.get(new PR(u, x));
        mf.add_edge(eid, nid, INF);
        u = fa[u][x];
      }
    }
    if (u == v) return ;
    for(int x = 20;x >= 0;x--) {
      if(fa[u][x] != fa[v][x]) {
        int nid1 = mp.get(new PR(u, x));
        int nid2 = mp.get(new PR(v, x));
        mf.add_edge(eid, nid1, INF);
        mf.add_edge(eid, nid2, INF);
        u=fa[u][x];
        v=fa[v][x];
      }
    }
    mf.add_edge(eid, mp.get(new PR(u, 0)), INF);
    mf.add_edge(eid, mp.get(new PR(v, 0)), INF);
    

  }
  static int LCA(int u,int v)
  {
    if (dep[u] < dep[v]) {
      int tmp = u;
      u = v;
      v = tmp;
    }
    int delta = dep[u] - dep[v];

    for(int x = 0;x <= 20;x++) {
      int flag = (1<<x)&delta;
      if(flag > 0) {
        u = fa[u][x];
      }
    }
    if (u == v) return u;
    for(int x = 20;x >= 0;x--) {
      if(fa[u][x] != fa[v][x]) {
        u=fa[u][x];
        v=fa[v][x];
      }
    }
    return fa[u][0];
  }

  public static void main(String[] args) {
    try {
      MScanner in = new MScanner(System.in);
      BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out, "UTF-8"));
      int n = in.nextInt();
      int m = in.nextInt();
      for (int i = 0;i <= n;++i) {
        a[i] = new ArrayList<Integer>();
      }
      int [][]tree = new int [n][2];
      for (int i = 1;i < n;++i) {
        int s = in.nextInt();
        int t = in.nextInt();
        a[t].add(s);
        a[s].add(t);
        tree[i][0] = s;
        tree[i][1] = t;
      }
      int [][]e = new int [m][2];
      for (int i = 0;i < m;++i){
        e[i][0] = in.nextInt();
        e[i][1] = in.nextInt();
      }
      dfs(1, 0);
      mp = new TreeMap<>( new Comparator<PR>() {
        public int compare(PR obj1, PR obj2) {
          if (obj1.x != obj2.x) {
            return obj1.x - obj2.x;
          }
          return obj1.y - obj2.y;
        }
      });
      int nc = 0;
      for (int i = 1;i <= n;++i) {
        for (int k = 0;k <= 20;++k) {
          if (fa[i][k] == 0) break;
          mp.put(new PR(i, k), ++nc);
          

        }
      }

      int gn = mp.size() + m + 2;
      


      mf = new MaxFlow(gn, 3000000);
      source = 0;
      sink = gn - 1;
      dfs_edge(1, 0);
      

      

      

      

      

      

      

      


      

      

      

      

      

      

      
      
      for (int i = 0;i < m;++i){
        int eid = mp.size() + i + 1;
        mf.add_edge(source, eid, 1);
      }
      
      for (int i = 0;i < m;++i){
        int eid = mp.size() + i + 1;
        LCA_eid(e[i][0], e[i][1], eid);
      }
      
      
      long ans = mf.dinic(source, sink);


      
      

      

      

      

      

      
      

      

      

      

      

      

      

      

      

      

      

      mf.bfs(source, sink);

      

      System.out.println(ans);
      int ec = 0;
      for (int i = 0;i < m;++i){
        int eid = mp.size() + i + 1;
        

        if (mf.level[eid] == -1) ec += 1;
      }
      

      System.out.print(ec + " ");
      for (int i = 0;i < m;++i){
        int eid = mp.size() + i + 1;
        

        

        if (mf.level[eid] == -1) System.out.print((i + 1) + " ");
      }
      

      System.out.println();
      ec = 0;
      for (int i = 1;i < n;++i) {
        int i1 = tree[i][0];
        int i2 = tree[i][1];
        int i0 = i1;
        if (dep[i1] < dep[i2]) i0 = i2;
        int nid = mp.get(new PR(i0, 0));
        

        if (mf.level[nid] >= 0) ec += 1;
      }
      

      System.out.print(ec + " ");
      for (int i = 1;i < n;++i) {
        int i1 = tree[i][0];
        int i2 = tree[i][1];
        int i0 = i1;
        if (dep[i1] < dep[i2]) i0 = i2;
        int nid = mp.get(new PR(i0, 0));
        

        

        if (mf.level[nid] >= 0) System.out.print(i + " ");
      }
      

      System.out.println();
      
      

      

    } catch (Exception e) {
      e.printStackTrace();
    }
  }
  static class MScanner {
    StringTokenizer st;
    BufferedReader br;
    public MScanner(InputStream system) {
      br = new BufferedReader(new InputStreamReader(system));
    }

    public MScanner(String file) throws Exception {
      br = new BufferedReader(new FileReader(file));
    }

    public String next() throws IOException {
      while (st == null || !st.hasMoreTokens())
        st = new StringTokenizer(br.readLine());
      return st.nextToken();
    }
    public int[] takearr(int n) throws IOException {
      int[]in=new int[n];for(int i=0;i<n;i++)in[i]=nextInt();
      return in;
    }
    public long[] takearrl(int n) throws IOException {
      long[]in=new long[n];for(int i=0;i<n;i++)in[i]=nextLong();
      return in;
    }
    public Integer[] takearrobj(int n) throws IOException {
      Integer[]in=new Integer[n];for(int i=0;i<n;i++)in[i]=nextInt();
      return in;
    }
    public Long[] takearrlobj(int n) throws IOException {
      Long[]in=new Long[n];for(int i=0;i<n;i++)in[i]=nextLong();
      return in;
    }
    public String nextLine() throws IOException {
      return br.readLine();
    }

    public int nextInt() throws IOException {
      return Integer.parseInt(next());
    }

    public double nextDouble() throws IOException {
      return Double.parseDouble(next());
    }

    public char nextChar() throws IOException {
      return next().charAt(0);
    }

    public Long nextLong() throws IOException {
      return Long.parseLong(next());
    }

    public boolean ready() throws IOException {
      return br.ready();
    }

    public void waitForInput() throws InterruptedException {
      Thread.sleep(3000);
    }
  }
}

class MaxFlow {
  public long[] flow, capa;
  public int[] from, now, level, eadj, eprev, elast;
  public int eidx, N, M;
  public static long INF = 1l << 50;

  public MaxFlow(int nodes, int edges) {
    this.N = nodes;
    this.M = edges;

    flow = new long[2*M];
    capa = new long[2*M];
    eadj = new int[2*M];
    from = new int[2*M];
    eprev = new int[2*M];
    elast = new int[N];
    level = new int[N];
    now = new int[N];
    Arrays.fill(elast, -1);
    eidx = 0;
  }

  public void add_edge(int a, int b, long c) {
    from[eidx] = a;eadj[eidx] = b; flow[eidx] = 0; capa[eidx] = c; eprev[eidx] = elast[a]; elast[a] = eidx++;
    from[eidx] = b;eadj[eidx] = a; flow[eidx] = c; capa[eidx] = c; eprev[eidx] = elast[b]; elast[b] = eidx++;
  }

  public long dinic(int source, int sink) {
    long res, flow = 0;
    while (bfs(source, sink)) {
      System.arraycopy(elast, 0, now, 0, N);
      while ((res = dfs(source, INF, sink)) > 0)
        flow += res;
    }
    return flow;
  }

  public boolean bfs(int source, int sink) {
    Arrays.fill(level, -1);
    int front = 0, back = 0;
    int[] queue = new int[N];

    level[source] = 0;
    queue[back++] = source;

    while (front < back && level[sink] == -1) {
      int node = queue[front++];
      for (int e = elast[node]; e != -1; e = eprev[e]) {
        int to = eadj[e];
        if (level[to] == -1 && flow[e] < capa[e]) {
          level[to] = level[node] + 1;
          queue[back++] = to;
        }
      }
    }

    return level[sink] != -1;
  }

  private long dfs(int cur, long curflow, int goal) {
    if (cur == goal) return curflow;

    for (int e = now[cur]; e != -1; now[cur] = e = eprev[e]) {
      if (level[eadj[e]] > level[cur] && flow[e] < capa[e]) {
        long res = dfs(eadj[e], Math.min(curflow, capa[e] - flow[e]), goal);
        if (res > 0) {
          flow[e] += res;
          flow[e ^ 1] -= res;
          return res;
        }
      }
    }
    return 0;
  }
}

class FastReader {
  private boolean finished = false;

  private InputStream stream;
  private byte[] buf = new byte[1024];
  private int curChar;
  private int numChars;
  private SpaceCharFilter filter;

  public FastReader(InputStream stream) {
    this.stream = stream;
  }

  public int read() {
    if (numChars == -1) {
      throw new InputMismatchException();
    }
    if (curChar >= numChars) {
      curChar = 0;
      try {
        numChars = stream.read(buf);
      } catch (IOException e) {
        throw new InputMismatchException();
      }
      if (numChars <= 0) {
        return -1;
      }
    }

    return buf[curChar++];
  }

  public int peek() {
    if (numChars == -1) {
      return -1;
    }
    if (curChar >= numChars) {
      curChar = 0;
      try {
        numChars = stream.read(buf);
      } catch (IOException e) {
        return -1;
      }
      if (numChars <= 0) {
        return -1;
      }
    }
    return buf[curChar];
  }

  public int nextInt() {
    int c = read();
    while (isSpaceChar(c))
      c = read();
    int sgn = 1;
    if (c == '-') {
      sgn = -1;
      c = read();
    }
    int res = 0;
    do {
      if (c == ',') {
        c = read();
      }
      if (c < '0' || c > '9') {
        throw new InputMismatchException();
      }
      res *= 10;
      res += c - '0';
      c = read();
    } while (!isSpaceChar(c));
    return res * sgn;
  }

  public long nextLong() {
    int c = read();
    while (isSpaceChar(c))
      c = read();
    int sgn = 1;
    if (c == '-') {
      sgn = -1;
      c = read();
    }
    long res = 0;
    do {
      if (c < '0' || c > '9') {
        throw new InputMismatchException();
      }
      res *= 10;
      res += c - '0';
      c = read();
    } while (!isSpaceChar(c));
    return res * sgn;
  }

  public String nextString() {
    int c = read();
    while (isSpaceChar(c))
      c = read();
    StringBuilder res = new StringBuilder();
    do {
      res.appendCodePoint(c);
      c = read();
    } while (!isSpaceChar(c));
    return res.toString();
  }

  public boolean isSpaceChar(int c) {
    if (filter != null) {
      return filter.isSpaceChar(c);
    }
    return isWhitespace(c);
  }

  public static boolean isWhitespace(int c) {
    return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
  }

  private String readLine0() {
    StringBuilder buf = new StringBuilder();
    int c = read();
    while (c != '\n' && c != -1) {
      if (c != '\r') {
        buf.appendCodePoint(c);
      }
      c = read();
    }
    return buf.toString();
  }

  public String nextLine() {
    String s = readLine0();
    while (s.trim().length() == 0)
      s = readLine0();
    return s;
  }

  public String nextLine(boolean ignoreEmptyLines) {
    if (ignoreEmptyLines) {
      return nextLine();
    } else {
      return readLine0();
    }
  }

  public BigInteger nextBigInteger() {
    try {
      return new BigInteger(nextString());
    } catch (NumberFormatException e) {
      throw new InputMismatchException();
    }
  }

  public char nextCharacter() {
    int c = read();
    while (isSpaceChar(c))
      c = read();
    return (char) c;
  }

  public double nextDouble() {
    int c = read();
    while (isSpaceChar(c))
      c = read();
    int sgn = 1;
    if (c == '-') {
      sgn = -1;
      c = read();
    }
    double res = 0;
    while (!isSpaceChar(c) && c != '.') {
      if (c == 'e' || c == 'E') {
        return res * Math.pow(10, nextInt());
      }
      if (c < '0' || c > '9') {
        throw new InputMismatchException();
      }
      res *= 10;
      res += c - '0';
      c = read();
    }
    if (c == '.') {
      c = read();
      double m = 1;
      while (!isSpaceChar(c)) {
        if (c == 'e' || c == 'E') {
          return res * Math.pow(10, nextInt());
        }
        if (c < '0' || c > '9') {
          throw new InputMismatchException();
        }
        m /= 10;
        res += (c - '0') * m;
        c = read();
      }
    }
    return res * sgn;
  }

  public boolean isExhausted() {
    int value;
    while (isSpaceChar(value = peek()) && value != -1)
      read();
    return value == -1;
  }

  public String next() {
    return nextString();
  }

  public SpaceCharFilter getFilter() {
    return filter;
  }

  public void setFilter(SpaceCharFilter filter) {
    this.filter = filter;
  }

  public interface SpaceCharFilter {
    public boolean isSpaceChar(int ch);
  }
}
