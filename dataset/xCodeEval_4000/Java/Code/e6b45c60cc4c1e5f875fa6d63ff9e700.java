


























































































import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class C1715E {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static long[] solve(int n, int[][] roads, int k) {
    List<List<int[]>> adjs = extractAdjs(n, roads);
    long[] d = new long[n];
    final long maxv = 1L << 50;
    Arrays.fill(d, maxv);
    d[0] = 0;
    dijkstra(d, adjs);
    int[] s = new int[n];
    long[] dn = new long[n];

    for (int h = 1; h <= k; h++) {
      int top = -1;
      for (int i = 0; i < n; i++) {
        while (top > 0 && slope(s[top-1], i, d) < slope(s[top-1], s[top], d)) {
          top--;
        }
        s[++top] = i;
      }
      for (int i = 0, j = 0; i < n; i++) {
        while (j < top && slope(s[j], s[j+1], d) < 2.0 * i) {
          j++;
        }
        dn[i] = d[s[j]] + 1L * (i-s[j]) * (i-s[j]);
      }
      for (int i = 0; i < n; i++) {
        d[i] = Math.min(d[i], dn[i]);
      }
      dijkstra(d, adjs);
    }
    return d;
  }

  static List<List<int[]>> extractAdjs(int n, int[][] roads) {
    List<List<int[]>> adjs = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      adjs.add(new ArrayList<>());
    }
    for (int[] road : roads) {
      int u = road[0];
      int v = road[1];
      int w = road[2];
      adjs.get(u).add(new int[] {v, w});
      adjs.get(v).add(new int[] {u, w});
    }
    return adjs;
  }

  static void dijkstra(long[] curr, List<List<int[]>> adjs) {
    int n = curr.length;
    

    boolean[] visited = new boolean[n];
    

    

    PriorityQueue<long[]> pq = new PriorityQueue<>((x,y)->Long.compare(x[0], y[0]));
    for (int i = 0; i < n; i++) {
      pq.add(new long[] {curr[i], i});
    }
    while (!pq.isEmpty()) {
      long[] entry = pq.poll();
      int v = (int) entry[1];
      if (visited[v]) {
        continue;
      }
      visited[v] = true;
      for (int[] e : adjs.get(v)) {
        int u = e[0];
        int w = e[1];
        

        

        

        if (curr[v] + w < curr[u]) {
          

          curr[u] = Math.min(curr[u], curr[v] + w);
          pq.add(new long[] {curr[u], u});
        }
      }
    }
  }

  static double slope(int x, int y, long[] d) {
    return (1.0*x*x+d[x]-1.0*y*y-d[y])/(x-y);
  }

  

  

  

  

  

  static long[] solveA(int n, int[][] roads, int k) {
    

    List<List<int[]>> adjs = extractAdjs(n, roads);

    long[][] dp = new long[k+1][n];
    {
      long[] curr = dp[0];
      final long max = 1L << 50;
      Arrays.fill(curr, max);
      curr[0] = 0;
      dijkstra(curr, adjs);
      if (test) {
        System.out.format("  h:%2d curr: %s\n", 0, trace(curr, 30));
      }
    }
    


    for (int h = 1; h <= k; h++) {
      long[] prev = dp[h-1];

      

      

      

      


      List<Integer> idxes = new ArrayList<>();
      for (int i = 0; i < n; i++) {
        if (prev[i] != Long.MAX_VALUE) {
          idxes.add(i);
        }
      }
      Collections.sort(idxes, (x,y)->Long.compare(prev[x], prev[y]));

      

      TreeMap<Integer, Integer> ibm = new TreeMap<>();

      long t0 = System.currentTimeMillis();
      for (int i : idxes) {
        handle(i, prev, ibm);
      }
      

      


      List<int[]> ibea = new ArrayList<>();
      int p = -1;
      for (Map.Entry<Integer, Integer> e : ibm.entrySet()) {
        int i = e.getKey();
        int b = e.getValue();
        ibea.add(new int[] {i, b, 0});
        if (b <= p) {
          System.out.format("test(%d,new int[][]%s,%d);\n", n, trace(roads), k);
        }
        myAssert(b > p);
        p = b;
      }
      for (int i = 0; i < ibea.size(); i++) {
        ibea.get(i)[2] = i == ibea.size() - 1 ? n - 1 : ibea.get(i+1)[1] - 1;
      }
      


      long[] curr = dp[h];
      System.arraycopy(prev, 0, curr, 0, n);
      int idx = 0;
      for (int[] v : ibea) {
        int i = v[0];
        int e = v[2];
        while (idx <= e) {
          long d = Math.abs(idx - i);
          curr[idx] = Math.min(curr[idx], prev[i] + d * d);
          idx++;
        }
      }
      if (test) {
        System.out.format("  h:%2d curr: %s\n", h, trace(curr, 30));
      }

      

      dijkstra(curr, adjs);

      if (test) {
        System.out.format("  h:%2d curr: %s\n", h, trace(curr, 30));
      }
    }
    return dp[k];
  }

  static void handle(int i, long[] curr, TreeMap<Integer, Integer> ibm) {
    int n = curr.length;
    if (ibm.isEmpty()) {
      ibm.put(i, 0);
      return;
    }
    long vi = curr[i];
    long b = 0;
    

    while (true) {
      Map.Entry<Integer, Integer> fe = ibm.floorEntry(i - 1);
      if (fe == null) {
        break;
      }
      int j = fe.getKey();
      long vj = curr[j];
      b = fl(i, vi, j, vj);
      

      if (b <= fe.getValue()) {
        

        ibm.remove(j);
        continue;
      } else if (b >= n) {
        

        return;
      } else {
        break;
      }
    }
    

    long e = n - 1;
    while (true) {
      Map.Entry<Integer, Integer> ce = ibm.ceilingEntry(i + 1);
      if (ce == null) {
        break;
      }
      

      

      

      int j = ce.getKey();
      int xb = ce.getValue();

      long vj = curr[j];
      e = fr(i, vi, j, vj);
      

      myAssert(e < j);

      if (e < 0) {
        

        return;
      } else if (e < xb) {
        break;
      } else {
        Map.Entry<Integer, Integer> xce = ibm.ceilingEntry(j + 1);
        int xe = xce == null ? n - 1 : xce.getValue() - 1;
        if (e >= xe) {
          

          ibm.remove(j);
          continue;
        } else {
          ibm.put(j, (int)(e + 1));
          break;
        }
      }
    }
    if (e >= b) {
      

      ibm.put(i, (int)b);
    }
    

  }

  

  

  

  

  

  static long fl(int i, long vi, int j, long vj) {
    myAssert(vi >= vj);
    myAssert(j < i);
    long d = i - j;
    long num = (vi - vj) + (i+j) * d;
    long den = 2 * d;
    return (num + den - 1)/den;
  }

  

  

  

  

  

  static long fr(int i, long vi, int j, long vj) {
    myAssert(vi >= vj);
    myAssert(i < j);
    long d = j - i;
    long num = (i+j) * d - (vi - vj);
    long den = 2 * d;
    if (num <= 0) {
      return -1;
    } else {
      return num % den == 0 ? num / den - 1 : num /den;
    }
  }

  static long[] solveNaive(int n, int[][] roads, int k) {
    List<List<int[]>> adjs = extractAdjs(n, roads);

    long[][] dp = new long[k+1][n];
    {
      long[] dists = new long[n];
      Arrays.fill(dists, Long.MAX_VALUE);
      dists[0] = 0;
      PriorityQueue<Integer> pq = new PriorityQueue<>((x,y)->Long.compare(dists[x], dists[y]));
      pq.add(0);
      while (!pq.isEmpty()) {
        int v = pq.poll();
        for (int[] e : adjs.get(v)) {
          int u = e[0];
          int w = e[1];
          if (dists[v] + w < dists[u]) {
            pq.remove(u);
            dists[u] = dists[v] + w;
            pq.add(u);
          }
        }
      }
      System.out.format("  h:%2d dists: %s\n", 0, trace(dists, 30));
      System.arraycopy(dists, 0, dp[0], 0, n);
    }

    for (int h = 1; h <= k; h++) {
      long[] dists = dp[h];
      System.arraycopy(dp[h-1], 0, dists, 0, n);
      

      

      

      

      for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          long x = 1L * (j-i) * (j-i);
          if (x >= dists[i]) {
            break;
          }
          if (dp[h-1][j] != Long.MAX_VALUE) {
            dists[i] = Math.min(dists[i], dp[h-1][j] + x);
          }
        }
        for (int j = i - 1; j >= 0; j--) {
          long x = 1L * (i-j) * (i-j);
          if (x >= dists[i]) {
            break;
          }
          if (dp[h-1][j] != Long.MAX_VALUE) {
            dists[i] = Math.min(dists[i], dp[h-1][j] + x);
          }
        }
      }

      

      dijkstra(dists, adjs);

      

    }

    return dp[k];
  }

  static String trace(long[] dists, int m) {
    StringBuilder sb = new StringBuilder();
    int n = dists.length;
    int h = m / 2;
    for (int i = 0; i < n; i++) {
      if (n <= m || i < h || i >= n - h) {
        long v = dists[i] == Long.MAX_VALUE ? -1 : dists[i];
        if (sb.length() > 0) {
          sb.append(',');
        }
        sb.append(v);
      }
      if (n > m && i == h) {
        sb.append(",...");
      }
    }
    return sb.toString();
  }

  static String trace(int[][] roads) {
    return Arrays.deepToString(roads).replace('[', '{').replace(']', '}').replace(" ", "");
  }

  static void test(int n, int[][] roads, int k) {
    long[] ans = solve(n, roads, k);
    long[] exp = n > 100 ? ans : solveNaive(n, roads, k);
    System.out.format("%d %s %d =>\n", n, trace(roads), k);
    System.out.format("%s\n", trace(ans, 30));
    System.out.format("%s\n", trace(exp, 30));
    for (int i = 0; i < n; i++) {
      myAssert(exp[i] == ans[i]);
    }
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    

    

    for (int t = 0; t < 1; t++) {
      int n = 100000;
      int m = 100000;
      int k = 20;
      final int max = 9;
      int[][] roads = new int[m][3];
      for (int i = 0; i < m; i++) {
        int x = RAND.nextInt(n);
        int y = RAND.nextInt(n);
        while (y == x) {
          y = RAND.nextInt(n);
        }
        roads[i][0] = Math.min(x, y);
        roads[i][1] = Math.max(x, y);
        roads[i][2] = 1 + RAND.nextInt(max);
      }
      

      test(n, roads, k);
    }

    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int n = in.nextInt();
    int m = in.nextInt();
    int k = in.nextInt();

    int[][] roads = new int[m][3];
    for (int i = 0; i < m; i++) {
      roads[i][0] = in.nextInt() - 1;
      roads[i][1] = in.nextInt() - 1;
      roads[i][2] = in.nextInt();
    }
    long[] ans = solve(n, roads, k);
    output(ans);
  }

  static void output(long[] a) {
    if (a == null) {
      System.out.println("-1");
      return;
    }
    StringBuilder sb = new StringBuilder();
    for (long v : a) {
      sb.append(v);
      sb.append(' ');
      if (sb.length() > 4000) {
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

  static class MyScanner {
    BufferedReader br;
    StringTokenizer st;

    public MyScanner() {
      try {
        final String USERDIR = System.getProperty("user.dir");
        String cname = MethodHandles.lookup().lookupClass().getCanonicalName().replace(".MyScanner", "");
        cname = cname.lastIndexOf('.') > 0 ? cname.substring(cname.lastIndexOf('.') + 1) : cname;
        final File fin = new File(USERDIR + "/io/c" + cname.substring(1,5) + "/" + cname + ".in");
        br = new BufferedReader(new InputStreamReader(fin.exists()
            ? new FileInputStream(fin) : System.in));
      } catch (Exception e) {
        br = new BufferedReader(new InputStreamReader(System.in));
      }
    }

    public String next() {
      try {
        while (st == null || !st.hasMoreElements()) {
          st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
      } catch (Exception e) {
        throw new RuntimeException(e);
      }
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }

    public long nextLong() {
      return Long.parseLong(next());
    }
  }
}
