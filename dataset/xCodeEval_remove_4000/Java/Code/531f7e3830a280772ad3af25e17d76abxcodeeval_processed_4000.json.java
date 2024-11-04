


























































































import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Random;
import java.util.StringTokenizer;

public class id3 {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static int[] solve(int[] pa, int[] xa) {
    int n = pa.length;
    int q = xa.length;

    

    int[] depth = new int[n];
    for (int i = 1; i < n; i++) {
      

      depth[i] = depth[pa[i]] + 1;
    }

    

    int[] f = new int[n];
    Arrays.fill(f, -1);
    List<Integer>[] adjs = id1(pa);
    List<Integer> que = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      if (adjs[i].size() == 1) {
        que.add(i);
        f[i] = 0;
      }
    }
    for (int i = 0; i < que.size(); i++) {
      int v = que.get(i);
      for (int w : adjs[v]) {
        if (f[w] == -1) {
          f[w] = f[v] + 1;
          que.add(w);
        }
      }
    }
    if (test) {
      System.out.format("  d:%s\n", Arrays.toString(depth));
      System.out.format("  f:%s\n", Arrays.toString(f));
    }

    int[] ans = new int[q];
    List<Integer>[] dp = new ArrayList[n];
    for (int i = 0; i < n; i++) {
      dp[i] = new ArrayList<>();
    }

    for (int v = n-1; v >= 0; v--) {
      for (int u : adjs[v]) {
        if (u < v) {
          continue;
        }
        if (dp[u].size() > dp[v].size()) {
          List<Integer> t = dp[u];
          dp[u] = dp[v];
          dp[v] = t;
        }

        for (int i = 0; i < dp[u].size(); i++) {
          for (int h = 0; h < q; h++) {
            do {
              int j = Math.max(0, ans[h] + 1 - xa[h] - i);
              if (j < dp[v].size() && dp[v].get(j) + dp[u].get(i) - 2 * depth[v] >= ans[h] + 1) {
                ans[h]++;
              } else {
                break;
              }
            } while (true);
          }
        }
        for (int i = 0; i < dp[u].size(); i++) {
          dp[v].set(i, Math.max(dp[v].get(i), dp[u].get(i)));
        }
      }

      for (int h = 0; h < q; h++) {
        do {
          int j = Math.max(0, ans[h] + 1 - xa[h] - f[v]);
          if (j < dp[v].size() && dp[v].get(j) - depth[v] >= ans[h] + 1) {
            ans[h]++;
          } else {
            break;
          }
        } while (true);
      }
      if (f[v] < dp[v].size()) {
        dp[v].set(f[v], Math.max(dp[v].get(f[v]), depth[v]));
      } else {
        myAssert(f[v] == dp[v].size());
        dp[v].add(depth[v]);
      }
    }
    return ans;
  }

  

  

  

  

  

  static int[] solveA(int[] pa, int[] xa) {
    int n = pa.length;
    int q = xa.length;

    List<Integer>[] adjs = id1(pa);

    boolean[] visited = new boolean[n];
    

    int[][] arr = new int[n][5];
    for (int i = 0; i < n; i++) {
      arr[i][0] = i;
      arr[i][2] = n;
    }

    List<Integer> nodes = new ArrayList<>();
    Queue<Integer> queue = new LinkedList<>();

    int[] degs = new int[n];
    for (int i = 0; i < n; i++) {
      degs[i] = adjs[i].size();
      if (degs[i] == 1) {
        queue.add(i);
      }
    }
    while (!queue.isEmpty()) {
      int v = queue.poll();
      

      nodes.add(v);
      visited[v] = true;
      int[] curr = arr[v];
      List<Integer> nbs = adjs[v];
      if (nbs.size() == 1) {
        

        curr[1] = nbs.get(0);
        curr[2] = 1;
        curr[3] = 0;
        curr[4] = 0;
      } else {
        curr[3] = 0;  

        curr[4] = 0;  

        for (int w : nbs) {
          if (visited[w]) {
            arr[w][1] = v;
            int d = arr[w][2];
            curr[2] = Math.min(curr[2], d + 1);
            if (d >= arr[v][3]) {
              curr[4] = curr[3];
              curr[3] = d;
            } else if (d > arr[v][4]) {
              curr[4] = d;
            }
          } else {
            curr[1] = w;
          }
        }
        

      }

      int p = arr[v][1];
      if (p >= 0) {
        degs[p]--;
        if (degs[p] == 1) {
          queue.add(p);
        }
      }
      if (queue.isEmpty()) {
        arr[v][1] = -1;
      }
    }
    

    System.out.format("  nodes: %s\n", nodes.toString());

    int[] ans = new int[q];
    for (int h = 0; h < q; h++) {
      int x = xa[h];
      for (int v : nodes) {
        int[] e = arr[v];
        int d0 = e[3];
        int d1 = e[4];
        int diameter = 0;
        if (d0 > 0 && d1 > 0) {
          if (x >= d0 + d1) {
            diameter = Math.max(diameter, d0 + d1);
          } else {
            

            diameter = Math.max(diameter, (d0 + d1 + x)/2);
          }
        }
        if (h == 8 && diameter == 4) {
          System.out.format("  v:%d diameter:%d\n", v, diameter);
        }
        ans[h] = Math.max(ans[h], diameter);
      }
      

    }
    return ans;
  }

  private static List<Integer>[] id1(int[] pa) {
    int n = pa.length;
    List<Integer>[] adjs = new ArrayList[n];
    for (int i = 0; i < n; i++) {
      adjs[i] = new ArrayList<>();
    }
    for (int i = 1; i < n; i++) {
      adjs[i].add(pa[i]);
      adjs[pa[i]].add(i);
    }
    return adjs;
  }

  

  

  public static int[] generateParents(int n) {
    int[] pa = new int[n];
    if (n == 1) {
      return pa;
    }
    Random rand = new Random();
    for (int i = 1; i < n; i++) {
      int p = rand.nextInt(i);
      pa[i] = p;
    }
    return pa;
  }

  static int[] id2(int[] pa, int[] xa) {
    int n = pa.length;
    int q = xa.length;
    int[] ans = new int[q];
    List<Integer>[] adjs = id1(pa);
    List<Integer> leafs = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      if (adjs[i].size() == 1) {
        leafs.add(i);
      }
    }
    for (int h = 0; h < q; h++) {
      int x = xa[h];
      int[][] graph = new int[n][n];
      for (int i = 0; i < n; i++) {
        Arrays.fill(graph[i], -1);
        graph[i][i] = 0;
      }
      for (int i = 0; i < n; i++) {
        List<Integer> nbs = adjs[i];
        for (int j : nbs) {
          graph[i][j] = 1;
          graph[j][i] = 1;
        }
      }
      for (int i = 0; i < leafs.size(); i++) {
        for (int j = i+1; j < leafs.size(); j++) {
          graph[leafs.get(i)][leafs.get(j)] = x;
          graph[leafs.get(j)][leafs.get(i)] = x;
        }
      }
      

      int[][] dists = id0(graph);
      

      for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
          ans[h] = Math.max(ans[h], dists[i][j]);
        }
      }
    }
    return ans;
  }

  static int[][] id0(int[][] graph) {
    int n = graph.length;
    int dist[][] = new int[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dist[i][j] = graph[i][j];
      }
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          

          if (dist[i][k] == -1 || dist[k][j] == -1) {
            continue;
          }
          if (dist[i][j] == -1 || dist[i][k] + dist[k][j] < dist[i][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
          }
        }
      }
    }
    return dist;
  }

  static String trace(int[] dists, int m) {
    StringBuilder sb = new StringBuilder();
    sb.append('{');
    int n = dists.length;
    int h = m / 2;
    for (int i = 0; i < n; i++) {
      if (n <= m || i < h || i >= n - h) {
        long v = dists[i] == Long.MAX_VALUE ? -1 : dists[i];
        if (sb.length() > 1) {
          sb.append(',');
        }
        sb.append(v);
      }
      if (n > m && i == h) {
        sb.append(",...");
      }
    }
    sb.append('}');
    return sb.toString();
  }

  public static void traceChildren(int[] pa, List<Integer>[] adjs) {
    int n = pa.length;
    for (int i = 0; i < n; i++) {
      List<Integer> nbs = adjs[i];
      if (nbs.size() == 1) {
        continue;
      }
      List<Integer> children = new ArrayList<>();
      for (int w : nbs) {
        if (w != pa[i]) {
          children.add(w);
        }
      }
      Collections.sort(children);
      System.out.format("  %4d: %s\n", i, children.toString());
    }
  }

  public static int[] generateXa(int q, int n) {
    int[] xa = new int[q];
    for (int i = 0; i < q; i++) {
      xa[i] = 1 + RAND.nextInt(n);
    }
    return xa;
  }

  static void test(int[] pa, int[] xa) {
    System.out.format("%s %s\n", trace(pa, 16), trace(xa, 16));
    int[] ans = solve(pa, xa);
    System.out.format("  => ");
    output(ans);
    if (pa.length <= 100) {
      int[] exp = id2(pa, xa);
      for (int i = 0; i < exp.length; i++) {
        if (exp[i] != ans[i]) {
          System.out.format(" exp ");
          output(exp);
          traceChildren(pa, id1(pa));
        }
        myAssert(exp[i] == ans[i]);
      }
    }
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    test(new int[] {0,0,1,1}, new int[] {1,2,3,4});
    test(new int[] {0,0,1,2,3,1,0}, new int[] {2,1,3,7,5,6,4});
    test(new int[] {0,0,1}, new int[] {1});

    for (int t = 0; t < 100; t++) {
      int n = 3 + RAND.nextInt(97);
      test(generateParents(n), generateXa(10, n));
    }

    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int n = in.nextInt();
    int[] p = new int[n];
    for (int i = 1; i < n; i++) {
      p[i] = in.nextInt() - 1;
    }
    int q = in.nextInt();
    int[] x = new int[q];
    for (int i = 0; i < q; i++) {
      x[i] = in.nextInt();
    }
    int[] ans = solve(p, x);
    output(ans);
  }

  static void output(int[] a) {
    StringBuilder sb = new StringBuilder();
    for (int v : a) {
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
