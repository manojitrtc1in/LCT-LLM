


import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.TreeMap;










































































































public class C1633E {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static int II = 0;
  static UnionFind UF = null;

  

  static long solve(int n, int[][] edges, int[] queries) {
    int m = edges.length;
    int k = queries.length;

    UF = new UnionFind(n);

    

    Arrays.sort(queries);
    


    Arrays.sort(edges, (x,y)->x[2] - y[2]);
    


    

    TreeMap<Integer, long[]> cm = new TreeMap<>();
    for (int[] edge : edges) {
      int x = edge[2];
      long[] arr = getCost(n, edges, x);
      cm.put(x, arr);
      

    }
    {
      II = 0;
      int extraGetCosts = 0;
      int v = cm.firstKey();
      while (v != cm.lastKey()) {
        long[] curr = cm.get(v);
        long[] next = cm.ceilingEntry(v + 1).getValue();
        if (curr[2] + curr[3] == next[2] || curr[1] + 1 == next[1]) {
          v = (int)next[1];
        } else {
          int x = (int) ((curr[1] + next[1]) / 2);
          long[] arr = getCost(n, edges, x);
          

          extraGetCosts++;
          cm.put(x, arr);
        }
      }
      

    }

    long[] costb = cm.firstEntry().getValue();
    long[] coste = cm.lastEntry().getValue();

    int numGetCosts = 0;
    II = 0;
    long ans = 0;
    int ib = 0;
    long[] fe = null;
    long[] ce = null;
    while (ib < k) {
      int x = queries[ib];
      int ie = ib + 1;
      while (ie < k && queries[ie] == queries[ib]) {
        ie++;
      }
      if ((ie - ib) % 2 == 0) {
        ib = ie;
        continue;
      }
      ib = ie;
      long cost = 0;
      if (x <= costb[1]) {
        cost = costb[0] + (costb[1] - x) * (n-1);
      } else if (x >= coste[1]) {
        cost = coste[0] + (x - coste[1]) * (n-1);
      } else {
        if (fe == null || (ce != null && x >= ce[1])) {
          fe = cm.floorEntry(x).getValue();
          ce = cm.ceilingEntry(x).getValue();
        }
        

        

        

        

        

        

        if (x == fe[1]) {
          cost = fe[0];
        } else if (ce[2] == fe[2] + fe[3]) {
          int nl = (int) (fe[2] + fe[3]);
          int nr = (int) fe[4];
          cost = fe[0] + (x - fe[1]) * (nl - nr);
          
        } else {
          long[] arr = getCost(n, edges, x);
          numGetCosts++;
          while (!cm.isEmpty() && cm.firstKey() < x) {
            cm.remove(cm.firstKey());
          }
          cm.put(x, arr);
          fe = arr;
          cost = arr[0];
        }
      }
      ans ^= cost;
    }
    

    return ans;
  }

  

  

  private static long[] getCost(int n, int[][] edges, int x) {
    int m = edges.length;
    long[] ans = new long[5];
    ans[1] = x;

    while (II < m && edges[II][2] <= x) {
      II++;
    }
    

    int b = II - 1;
    

    int e = II;
    

    UF.clear();
    while (!UF.isSingleGroup()) {
      

      int j = (b >= 0 && (e >= m || x - edges[b][2] <= edges[e][2] - x)) ? b : e;
      

      int u = edges[j][0];
      int v = edges[j][1];
      int w = edges[j][2];
      if (UF.union(u, v)) {
        ans[0] += Math.abs(w - x);
        if (x == w) {
          ans[3]++;
        } else if (j == b) {
          ans[2]++;
        } else {
          ans[4]++;
        }
      }
      if (j == b) {
        b--;
      } else {
        e++;
      }
    }
    return ans;
  }

  static class UnionFind {
    int n;
    int m;  

    int[] gids;

    public UnionFind(int n) {
      this.n = n;
      this.m = n;
      this.gids = new int[n];
      for (int i = 0; i < n; i++) {
        gids[i] = i;
      }
    }

    public boolean union(int i, int j) {
      int ri = find(i);
      int rj = find(j);
      if (ri != rj) {
        int id = Math.min(ri, rj);
        

        gids[ri] = id;
        gids[rj] = id;
        m--;
        return true;
      }
      return false;
    }

    public int find(int i) {
      while (i != gids[i]) {
        gids[i] = gids[gids[i]];
        i = gids[i];
      }
      return i;
    }

    public boolean isSingleGroup() {
      return m == 1;
    }

    public void clear() {
      for (int i = 0; i < n; i++) {
        gids[i] = i;
      }
      this.m = n;
    }
  }

  public static void sort(int[] arr) {
    for (int i = 0; i < arr.length; i++) {
      int r = RAND.nextInt(arr.length);
      int temp = arr[i];
      arr[i] = arr[r];
      arr[r] = temp;
    }
    Arrays.sort(arr);
  }

  static void doTest() {
    long t0 = System.currentTimeMillis();
    int n = 50;
    int m = 300;
    int k = 5000000;
    int c = 100000000;
    int[][] edges = generateEdges(n, m, c);
    

    int[] queries = new int[k];
    for (int i = 0; i < k; i++) {
      queries[i] = RAND.nextInt(c - 1);
    }
    long ans = solve(n, edges, queries);
    

    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  

  public static int[][] generateEdges(int n, int m, int c) {
    myAssert(n >= 2 && m >= n-1);
    int[][] edges = new int[m][3];

    

    List<Integer> used = new ArrayList<>();
    List<Integer> avai = new ArrayList<>();
    Random rand = new Random();
    int i0 = rand.nextInt(n);
    used.add(i0);
    for (int i = 0; i < n; i++) {
      if (i != i0) {
        avai.add(i);
      }
    }
    int idx = 0;
    while (!avai.isEmpty()) {
      edges[idx][0] = avai.remove(rand.nextInt(avai.size()));
      edges[idx][1] = used.get(rand.nextInt(used.size()));
      edges[idx][2] = rand.nextInt(c);
      used.add(edges[idx][0]);
      idx++;
    }
    

    while (idx < m) {
      edges[idx][0] = rand.nextInt(n);
      edges[idx][1] = rand.nextInt(n);
      edges[idx][2] = rand.nextInt(c);
      idx++;
    }
    return edges;
  }

  public static void main(String[] args) {
    

    MyScanner in = new MyScanner();
    int n = in.nextInt();
    int m = in.nextInt();
    int[][] edges = new int[m][3];
    for (int i = 0; i < m; i++) {
      edges[i][0] = in.nextInt() - 1;
      edges[i][1] = in.nextInt() - 1;
      edges[i][2] = in.nextInt();
    }
    int p = in.nextInt();
    int k = in.nextInt();
    int a = in.nextInt();
    int b = in.nextInt();
    int c = in.nextInt();
    int[] queries = new int[k];
    for (int i = 0; i < p; i++) {
      queries[i] = in.nextInt();
    }
    for (int i = p; i < k; i++) {
      queries[i] = (int) (((long)queries[i-1] * a + b) % c);
    }

    long ans = solve(n, edges, queries);
    System.out.println(ans);
  }

  static Scanner getInputScanner() {
    try {
      final String USERDIR = System.getProperty("user.dir");
      final String CNAME = MethodHandles.lookup().lookupClass().getSimpleName();
      final File fin = new File(USERDIR + "/io/c" + CNAME.substring(1,5) + "/" + CNAME + ".in");
      return fin.exists() ? new Scanner(fin) : new Scanner(System.in);
    } catch (Exception e) {
      return new Scanner(System.in);
    }
  }

  static void output(int[] a) {
    if (a == null) {
      System.out.println("-1");
      return;
    }
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
}
