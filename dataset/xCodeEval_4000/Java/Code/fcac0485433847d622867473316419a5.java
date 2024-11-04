


import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Random;
import java.util.StringTokenizer;
































































































public class C1632E1 {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static int[] solve(int[][] edges) {
    int n = edges.length + 1;
    List<List<Integer>> eas = getEdgesList(edges);
    


    

    

    

    int[][] nodes = bfs(eas);
    


    int m = 0;
    int end = 0;
    for (int i = 1; i <= n; i++) {
      if (nodes[i][1] > m) {
        m = nodes[i][1];
        end = i;
      }
    }
    m++;

    List<List<Integer>> children = getChildrenList(eas, nodes);

    

    int[] ha = new int[m];
    int v = end;
    int idx = m - 2;
    while (v != 1) {
      int p = nodes[v][0];
      List<Integer> childs = children.get(p);
      int w = childs.size() == 1 ? 0 : (childs.get(0) == v ? childs.get(1) : childs.get(0));
      ha[idx] = nodes[w][3];
      v = p;
      idx--;
    }
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    int[] a0 = new int[m];
    a0[0] = ha[0];
    for (int j = 1; j < m; j++) {
      a0[j] = Math.max(a0[j-1], j + ha[j]);
    }
    


    int[] ba = new int[m];
    for (int j = 0; j < m; j++) {
      ba[j] = ha[j] - j;
    }
    

    RangeMaxSegmentTree rmst = new RangeMaxSegmentTree(ba);
    int[] ans = new int[n];
    int i = 2;
    for (int x = 1; x <= n; x++) {
      if (x >= m - 1) {
        ans[x-1] = m - 1;
      } else {
        

        i = Math.max(i, x + 1);
        ans[x-1] = f(x, i, a0, rmst);
        

        int ii = i + 1;
        while (ii <= m - 1) {
          int value = f(x, ii, a0, rmst);
          if (value < ans[x-1]) {
            i = ii;
            ans[x-1] = value;
          } else if (value > ans[x-1]) {
            break;
          }
          ii++;
        }
      }
    }
    return ans;
  }

  

  

  

  static int[][] bfs(List<List<Integer>> eas) {
    int n = eas.size() - 1;
    int[][] nodes = new int[n+1][4];
    Queue<Integer> q = new LinkedList<>();
    q.add(1);
    int depth = 0;
    while (!q.isEmpty()) {
      depth++;
      int size = q.size();
      for (int i = 0; i < size; i++) {
        int v = q.poll();
        for (int w : eas.get(v)) {
          if (w == v || w == 1 || nodes[w][1] != 0) {
            

            continue;
          }
          nodes[v][2]++;  

          nodes[w][0] = v;
          nodes[w][1] = depth;
          q.add(w);
        }
      }
    }
    


    

    List<Integer> leafs = new ArrayList<>();
    for (int i = 1; i <= n; i++) {
      if (nodes[i][2] == 0) {
        nodes[i][3] = 1;  

        q.add(i);
        leafs.add(i);
      }
    }
    int[] repoted = new int[n+1];
    

    while (!q.isEmpty()) {
      int v = q.poll();
      int p = nodes[v][0];
      

      if (p == 0) {
        continue;
      }
      nodes[p][3] = Math.max(nodes[p][3], 1 + nodes[v][3]);
      repoted[p]++;
      if (repoted[p] == nodes[p][2]) {
        q.add(p);
      }
    }
    return nodes;
  }

  

  static int f(int x, int i, int[] a0, RangeMaxSegmentTree rmst) {
    int m = a0.length;
    

    int k = (i + x + 1) / 2;
    

    int rm = rmst.getRangeMax(k, i);
    int v0 = a0[k-1];
    int v1 = rm + x + i;
    int v2 = x + m - i - 1;
    int dv = Math.max(Math.max(v0, v1), v2);
    

    

    return dv;
  }

  static class RangeMaxSegmentTree {
    int n;
    int tree[];

    RangeMaxSegmentTree(int[] arr) {
      this.n = arr.length;
      int m = nextPowerOf2(n);
      this.tree = new int[m * 2];
      constructSegTree(arr, 0, n - 1, 1);
    }

    void constructSegTree(int arr[], int low, int high, int idx) {
      if (low > high) {
        return;
      }

      if (low == high) {
        tree[idx] = arr[low];
        return;
      }

      int mid = (low + high) / 2;
      constructSegTree(arr, low, mid, idx * 2);
      constructSegTree(arr, mid + 1, high, idx * 2 + 1);
      tree[idx] = Math.max(tree[idx * 2], tree[idx * 2 + 1]);
    }

    

    public void set(int index, int value)  {
      myAssert (index >= 0 && index < n);
      int vcurr = getRangeMax(index, index);
      int delta = value - vcurr;
      updateInner(1, 0, n - 1, index, delta);
    }

    public int getRangeMax(int start, int end) {
      myAssert (start >= 0 && end < n && start <= end);
      return getRangeMax(1, 0, n - 1, start, end);
    }

    private void updateInner(int idx, int low, int high, int index, int delta) {
      if (low > high || low > index || high < index) {
        return;
      }

      if (low >= index && high <= index) {
        tree[idx] += delta;
        return;
      }

      int mid = (low + high) / 2;
      updateInner(idx * 2 + 1, low, mid, index, delta);
      updateInner(idx * 2 + 2, mid + 1, high, index, delta);
      tree[idx] = Math.max(tree[idx * 2], tree[idx * 2 + 1]);
    }

    private int getRangeMax(int idx, int low, int high, int start, int end) {
      if (low > high || low > end || high < start) {
        return Integer.MIN_VALUE;
      }
      if (low >= start && high <= end) {
        return tree[idx];
      }
      int mid = (low + high) / 2;
      return Math.max(getRangeMax(2 * idx, low, mid, start, end),
          getRangeMax(2 * idx + 1, mid + 1, high, start, end));
    }

    public static int nextPowerOf2(int num){
      if (num == 0) {
        return 1;
      }
      if (num > 0 && (num & (num-1)) == 0) {
        return num;
      }
      while ((num & (num-1)) > 0) {
          num = num & (num - 1);
      }
      return num << 1;
    }
  }

  private static List<List<Integer>> getChildrenList(List<List<Integer>> eas, int[][] nodes) {
    int n = eas.size() - 1;
    List<List<Integer>> children = new ArrayList<>();
    for (int i = 0; i <= n; i++) {
      children.add(new ArrayList<>());
    }
    for (int i = 1; i <= n; i++) {
      for (int v : eas.get(i)) {
        if (v != nodes[i][0]) {
          children.get(i).add(v);
        }
      }
      Collections.sort(children.get(i), (x,y) -> nodes[y][3] - nodes[x][3]);
    }
    return children;
  }

  static List<List<Integer>> getEdgesList(int[][] edges) {
    int n = edges.length + 1;
    List<List<Integer>> eas = new ArrayList<>();
    for (int i = 0; i <= n; i++) {
      eas.add(new ArrayList<>());
    }
    for (int[] edge : edges) {
      int u = edge[0];
      int v = edge[1];
      eas.get(u).add(v);
      eas.get(v).add(u);
    }
    return eas;
  }

  


  static int[][] generateTree(int n) {
    int[][] edges = new int[n-1][2];
    if (n == 1) {
      return edges;
    }
    List<Integer> used = new ArrayList<>();
    List<Integer> avai = new ArrayList<>();
    int i0 = 1 + RAND.nextInt(n);
    used.add(i0);
    for (int i = 1; i <= n; i++) {
      if (i != i0) {
        avai.add(i);
      }
    }
    int idx = 0;
    while (!avai.isEmpty()) {
      int v = avai.remove(RAND.nextInt(avai.size()));
      int w = used.get(RAND.nextInt(used.size()));
      edges[idx][0] = v;
      edges[idx][1] = w;
      idx++;
      used.add(v);
    }
    return edges;
  }

  static int[] solveNaive(int[][] edges) {
    int n = edges.length + 1;
    List<List<Integer>> eas = new ArrayList<>();
    for (int i = 0; i <= n; i++) {
      eas.add(new ArrayList<>());
    }
    for (int[] edge : edges) {
      int u = edge[0];
      int v = edge[1];
      eas.get(u).add(v);
      eas.get(v).add(u);
    }
    int[] ans = new int[n];
    int dv = bfs(eas, 0, 0, 0);
    for (int x = 1; x <= n; x++) {
      ans[x-1] = dv;
      for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
          ans[x-1] = Math.min(ans[x-1], bfs(eas, i, j, x));
        }
      }
    }
    return ans;
  }

  

  static int bfs(List<List<Integer>> eas, int a, int b, int x) {
    int n = eas.size() + 1;
    int[] dists = new int[n + 1];
    Arrays.fill(dists, n);
    dists[1] = 0;
    PriorityQueue<Integer> pq = new PriorityQueue<>((v, w)->dists[v] - dists[w]);
    pq.add(1);
    int ans = 0;
    while (!pq.isEmpty()) {
      int v = pq.poll();
      

      ans = Math.max(ans, dists[v]);
      for (int w : eas.get(v)) {
        if (dists[w] > dists[v] + 1) {
          pq.remove(w);
          dists[w] = dists[v] + 1;
          pq.add(w);
        }
      }
      if (v == a) {
        if (dists[b] > dists[v] + x) {
          pq.remove(b);
          dists[b] = dists[v] + x;
          pq.add(b);
        }
      } else if (v == b) {
        if (dists[a] > dists[v] + x) {
          pq.remove(a);
          dists[a] = dists[v] + x;
          pq.add(a);
        }
      }
    }
    return ans;
  }

  static void test(int[][] edges) {
    int[] ans = solve(edges);
    System.out.format("%s\n", trace(edges).replace('[', '{').replace(']', '}'));
    output(ans);
    if (edges.length < 50) {
      int[] exp = solveNaive(edges);
      for (int i = 0; i <= edges.length; i++) {
        if (ans[i] != exp[i]) {
          output(exp);
          List<List<Integer>> eas = getEdgesList(edges);
          int[][] nodes = bfs(eas);
          List<List<Integer>> children = getChildrenList(eas, nodes);
          System.out.println(traceListListInt(children));
          myAssert(false);
        }
      }
    }
  }

  static void doTest() {
    long t0 = System.currentTimeMillis();
    test(new int[][] {{5,3},{4,3},{8,3},{2,4},{6,5},{1,2},{7,6}});
    for (int t = 0; t < 50; t++) {
      int n = 8;
      int[][] edges = generateTree(n);
      test(edges);
    }
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static String traceListListInt(List<List<Integer>> values) {
    StringBuilder sb = new StringBuilder();
    int n = values.size();
    for (int i = 0; i < n; i++) {
      if (i < 16 || i >= n - 16) {
        if (i > 0) {
          sb.append("\n");
        }
        sb.append(String.format("%3d: %s", i, join(values.get(i), ",")));
      }
      if (n >= 32 && i == 16) {
        sb.append("\n...");
      }
    }
    return sb.toString();
  }

  public static String join(Collection<?> objs, String delimiter) {
    StringBuilder sb = new StringBuilder();
    Iterator<?> it = objs.iterator();
    boolean first = true;
    while (it.hasNext()) {
      if (!first) {
        sb.append(delimiter);
      }
      sb.append(it.next().toString());
      first = false;
    }
    return sb.toString();
  }

  public static String trace(int[][] points) {
    StringBuilder sb = new StringBuilder();
    sb.append('[');
    

    int h = 10;
    int m = points.length;
    for (int i = 0; i < m; i++) {
      if (m > (h << 1)) {
        if (i == h) {
          sb.append(",...");
        }
        if (i >= h && i < m - h) {
          continue;
        }
      }
      if (i > 0) {
        sb.append(',');
      }
      sb.append('[');

      int n = points[i].length;
      for (int j = 0; j < n; j++) {
        

        if (n > (h << 1)) {
          if (j == h) {
            sb.append(",...");
          }
          if (j >= h && j < n - h) {
            continue;
          }
        }

        if (j > 0) {
          sb.append(',');
        }
        sb.append(points[i][j]);
      }
      sb.append(']');
    }
    sb.append(']');
    return sb.toString();
  }

  public static void main(String[] args) {
    

    MyScanner in = new MyScanner();
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int n = in.nextInt();
      int[][] edges = new int[n-1][2];
      for (int i = 0; i < n-1; i++) {
        edges[i][0] = in.nextInt();
        edges[i][1] = in.nextInt();
      }
      int[] ans = solve(edges);
      output(ans);
    }
  }

  static class MyScanner {
    BufferedReader br;
    StringTokenizer st;

    public MyScanner() {
      try {
        final String USERDIR = System.getProperty("user.dir");
        String cname = MethodHandles.lookup().lookupClass().getCanonicalName();
        

        int i = cname.lastIndexOf('.');
        if (i > 0) {
          cname = cname.substring(0, i);
        }
        final File fin = new File(USERDIR + "/io/c" + cname.substring(1,5) + "/" + cname + ".in");
        br = new BufferedReader(new InputStreamReader(fin.exists() ? new FileInputStream(fin) : System.in));
      } catch (Exception e) {
        br = new BufferedReader(new InputStreamReader(System.in));
      }
    }

    public String next() {
      while (st == null || !st.hasMoreElements()) {
        try {
          st = new StringTokenizer(br.readLine());
        } catch (IOException e) {
          e.printStackTrace();
        }
      }
      return st.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }

    public long nextLong() {
      return Long.parseLong(next());
    }

    public double nextDouble() {
      return Double.parseDouble(next());
    }

    public String nextLine() {
      String str = "";
      try {
        str = br.readLine();
      } catch (IOException e) {
        e.printStackTrace();
      }
      return str;
    }
  }

  static void output(int[] a) {
    StringBuilder sb = new StringBuilder();
    for (int v : a) {
      sb.append(v);
      sb.append(' ');
      if (sb.length() > 500) {
        System.out.print(sb.toString());
        sb.setLength(0);
      }
    }
    System.out.println(sb.toString());
  }

  static void myAssert(boolean cond) {
    if (!cond) {
      throw new RuntimeException("Unexpected");
    }
  }
}
