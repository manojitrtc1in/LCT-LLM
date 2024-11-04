


































































































































import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Random;
import java.util.Set;
import java.util.StringTokenizer;

public class C1741G {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  

  

  

  

  static int solve(int n, int[][] edges, int[] h, int[] p) {
    List<Integer>[] adjs = new ArrayList[n];
    for (int i = 0; i < n; i++) {
      adjs[i] = new ArrayList<>();
    }
    for (int[] edge : edges) {
      int u = edge[0];
      int v = edge[1];
      adjs[u].add(v);
      adjs[v].add(u);
    }
    int[] dists = new int[n];
    {
      Arrays.fill(dists, n);
      dists[0] = 0;
      Queue<Integer> q = new LinkedList<>();
      q.add(0);
      while (!q.isEmpty()) {
        int v = q.poll();
        for (int w : adjs[v]) {
          if (dists[w] > dists[v] + 1) {
            dists[w] = dists[v] + 1;
            q.add(w);
          }
        }
      }
      

    }

    int[] degs = new int[n];
    List<Integer>[] pas = new ArrayList[n];
    Queue<Integer> q = new LinkedList<>();
    for (int i = 0; i < n; i++) {
      pas[i] = new ArrayList<>();
    }
    for (int i = 0; i < n; i++) {
      for (int v : adjs[i]) {
        if (dists[v] == dists[i] + 1) {
          degs[i]++;
        } else if (dists[v] == dists[i] - 1) {
          pas[i].add(v);
        }
      }
      if (!pas[i].isEmpty()) {
        

      }
      if (degs[i] == 0) {
        q.add(i);
      }
    }

    

    Set<Integer> ps = new HashSet<>();
    int k = p.length;

    

    int[] ncfidx = new int[h.length];
    Arrays.fill(ncfidx, -1);
    for (int i = 0; i < k; i++) {
      int fid = p[i];
      ps.add(fid);
      ncfidx[fid] = i;
    }

    


    List<Integer>[] fcars = new ArrayList[n];
    List<Integer>[] fnocs = new ArrayList[n];
    for (int i = 0; i < n; i++) {
      fcars[i] = new ArrayList<>();
      fnocs[i] = new ArrayList<>();
    }
    for (int i = 0; i < h.length; i++) {
      int v = h[i];
      if (ps.contains(i)) {
        

        fnocs[v].add(i);
      } else {
        fcars[v].add(i);
      }
    }

    

    

    Map<Integer, Long>[] masks = new HashMap[n];
    for (int i = 0; i < n; i++) {
      masks[i] = new HashMap<>();
    }

    while (!q.isEmpty()) {
      int v = q.poll();
      int mask = 0;
      if (!fnocs[v].isEmpty()) {
        for (int x : fnocs[v]) {
          mask |= (1 << ncfidx[x]);
        }
        Iterator<Map.Entry<Integer, Long>> it = masks[v].entrySet().iterator();
        while (it.hasNext()) {
          Map.Entry<Integer, Long> e = it.next();
          long x = mergeMask(e.getValue(), mask);
          e.setValue(x);
          

        }
      }
      for (int w : fcars[v]) {
        masks[v].put(w, mergeMask(0, mask));
      }
      

      

      

      for (int i = 0; i < pas[v].size(); i++) {
        int w = pas[v].get(i);
        if (i == pas[v].size() - 1) {
          masks[w] = mergeMasksFast(masks[v], masks[w]);
        } else {
          mergeMasks(masks[v], masks[w]);
        }
        

        

        degs[w]--;
        if (degs[w] == 0) {
          q.add(w);
        }
      }
    }

    


    {
      List<Long> values = new ArrayList<>(masks[0].values());
      int m = masks[0].size();
      if (n == 10000) {
        new RuntimeException("m_" + m + "_" + k);
      }
      boolean[][] dp = new boolean[m+1][1 << k];
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < (1 << k); j++) {
          dp[i+1][j] = dp[i][j];
        }
        

        long mask = values.get(i);
        for (int j = 0; j < (1 << k); j++) {
          if ((mask & (1L << j)) != 0) {
            

            dp[i+1][j] = true;
            for (int l = 0; l < (1 << k); l++) {
              if (dp[i][l]) {
                dp[i+1][j | l] = true;
              }
            }
          }
        }

        {
          int maxbit = 0;
          for (int j = 0; j < (1 <<k); j++) {
            if (dp[i+1][j]) {
              maxbit = Math.max(maxbit, Integer.bitCount(j));
            }
          }
          if (maxbit == k) {
            return 0;
          }
        }
      }

      int maxbit = 0;
      for (int i = 0; i < (1 <<k); i++) {
        if (dp[m][i]) {
          maxbit = Math.max(maxbit, Integer.bitCount(i));
        }
      }
      return k - maxbit;
    }
  }

  static void show(Map<Integer, Long> mp) {
    for (Map.Entry<Integer, Long> e : mp.entrySet()) {
      System.out.format("  %4d %s\n", e.getKey(), traceMask(e.getValue()));
    }
  }

  static String traceMask(long v) {
    char[] ca = new char[64];
    Arrays.fill(ca, '0');
    int idx = 63;
    while (v != 0) {
      if (v % 2 == 1) {
        ca[idx] = '1';
      }
      v /= 2;
      idx--;
    }
    return new String(ca);
  }

  static void mergeMasks(Map<Integer, Long> src, Map<Integer, Long> dst) {
    if (src.isEmpty()) {
      return;
    }
    

    for (Map.Entry<Integer, Long> e : src.entrySet()) {
      int k = e.getKey();
      long v = e.getValue();
      if (!dst.containsKey(k)) {
        dst.put(k, v);
      } else {
        dst.put(k, v | dst.get(k));
      }
    }
  }

  static Map<Integer, Long> mergeMasksFast(Map<Integer, Long> src, Map<Integer, Long> dst) {
    if (src.size() <= dst.size()) {
      merge(src, dst);
      return dst;
    } else {
      merge(dst, src);
      return src;
    }
  }

  static void merge(Map<Integer, Long> src, Map<Integer, Long> dst) {
    if (src.isEmpty()) {
      return;
    }
    for (Map.Entry<Integer, Long> e : src.entrySet()) {
      int k = e.getKey();
      long v = e.getValue();
      if (!dst.containsKey(k)) {
        dst.put(k, v);
      } else {
        dst.put(k, v | dst.get(k));
      }
    }
  }

  static long mergeMask(long v, int mask) {
    myAssert(mask <= 63);
    if (mask == 0) {
      return v;
    }
    long ans = 0;
    if (v == 0) {
      ans = (1L << mask);
    } else {
      long s = 1;
      for (int i = 0; i < 64; i++) {
        if ((v & s) != 0) {
          int j = i | mask;
          ans |= (1L << j);
        }
        s <<= 1;
      }
    }
    

    return ans;
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int n = in.nextInt();
      int m = in.nextInt();
      int[][] edges = new int[m][2];
      for (int i = 0; i < m; i++) {
        edges[i][0] = in.nextInt() - 1;
        edges[i][1] = in.nextInt() - 1;
      }
      int f = in.nextInt();
      int[] h = new int[f];
      for (int i = 0; i < f; i++) {
        h[i] = in.nextInt()-1;
      }
      int k = in.nextInt();
      int[] p = new int[k];
      for (int i = 0; i < k; i++) {
        p[i] = in.nextInt() - 1;
      }

      int ans = solve(n, edges, h, p);
      System.out.println(ans);
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
