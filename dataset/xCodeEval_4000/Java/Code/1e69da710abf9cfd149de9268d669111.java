
















































































































import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.StringTokenizer;

public class C1735D {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static long solve(int[][] a) {
    int n = a.length;
    int k = a[0].length;

    Map<Long, Integer> masks = new HashMap<>();
    for (int i = 0; i < n; i++) {
      masks.put(getMask(a[i]), i);
    }
    


    

    

    int[][] dp = new int[n][n];
    for (int i = 0; i < n; i++) {
      Arrays.fill(dp[i], -1);
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        long mask = 0;
        for (int h = 0; h < k; h++) {
          long v = a[i][h] == a[j][h] ? a[i][h] : 3 - a[i][h] - a[j][h];
          mask |= v << (2 *h);
        }
        

        if (masks.containsKey(mask)) {
          int v = masks.get(mask);
          if (v > j) {
            dp[i][j] = v;
          }
        }
      }
    }

    


    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    List<int[]>[] sets = new ArrayList[n];
    for (int i = 0; i < n; i++) {
      sets[i] = new ArrayList<>();
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dp[i][j] < 0) {
          continue;
        }
        int v = dp[i][j];
        sets[i].add(new int[] {j,v});
        sets[j].add(new int[] {i,v});
        sets[v].add(new int[] {i,j});
      }
    }
    long ans = 0;
    for (int i = 0; i < n; i++) {
      int m = sets[i].size();
      ans += m * (m-1) / 2;
      if (m > 1) {
        

      }
    }

    return ans;
  }

  static long getMask(int[] b) {
    int k = b.length;
    long ans = 0;
    for (int h = 0; h < k; h++) {
      ans |= (long)b[h] << (2 * h);
    }
    return ans;
  }

  static long solveNaive(int[][] a) {
    int n = a.length;
    int k = a[0].length;
    

    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
      if (Integer.bitCount(i) != 5) {
        continue;
      }
      List<Integer> ids = new ArrayList<>();
      for (int j = 0; j < n; j++) {
        if ((i & (1 << j)) != 0) {
          ids.add(j);
        }
      }
      if (isMetaSet(ids, a)) {
        ans++;
        System.out.format(" %3d %s\n", ans, ids.toString());
      }
    }
     return ans;
  }

  static boolean isMetaSet(List<Integer> ids, int[][] a) {
    int n = a.length;
    int k = a[0].length;
    if (ids.size() != 5) {
      return false;
    }
    int set = 0;
    int m = 5;
    for (int i = 0; i < (1 << m); i++) {
      if (Integer.bitCount(i) != 3) {
        continue;
      }
      List<Integer> chosen = new ArrayList<>();
      for (int j = 0; j < m; j++) {
        if ((i & (1 << j)) != 0) {
          chosen.add(ids.get(j));
        }
      }
      boolean good = true;
      for (int j = 0; j < k; j++) {
        int[] ct = new int[3];
        for (int v : chosen) {
          ct[a[v][j]]++;
        }
        if (ct[0] == 3 || ct[1] == 3 || ct[2] == 3 || (ct[0] == 1 && ct[1] == 1 && ct[2] == 1)) {
        } else {
          good = false;
          break;
        }
      }
      if (good) {
        set++;
      }
    }
    return set > 1;
  }

  static void test(long exp, int[][] a) {
    long ans = solve(a);
    long exp2 = solveNaive(a);
    

    myAssert(ans == exp);
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    test(9, new int[][] {
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 0, 1, 0},
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 0, 1, 1},
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 0, 1, 2},
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 0, 2, 0},
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 0, 2, 1},
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 0, 2, 2},
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 1, 0, 0},
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 1, 0, 1},
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 1, 0, 2},
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 1, 1, 0},
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 1, 1, 1},
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 1, 1, 2},
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 1, 2, 0}
    });

    test(1, new int[][] {{0,0,0,0},{0,0,0,1},{0,0,0,2},{0,0,1,0},{0,0,2,0},{0,1,0,0},{1,0,0,0},{2,2,0,0}});
    test(3, new int[][] {{0,0,0,0},{0,0,0,1},{0,0,0,2},{0,0,1,0},{0,0,2,0},{0,1,0,0},{0,2,0,0}});
    test(54, new int[][] {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}});
    test(9, new int[][] {
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 0, 1, 0},
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 0, 1, 1},
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 0, 1, 2},
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 0, 2, 0},
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 0, 2, 1},
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 0, 2, 2},
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 1, 0, 0},
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 1, 0, 1},
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 1, 0, 2},
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 1, 1, 0},
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 1, 1, 1},
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 1, 1, 2},
      {1, 2, 2, 1, 0, 0, 2, 1, 2, 2, 2, 1, 0, 1, 1, 2, 1, 1, 2, 0}
    });
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int n = in.nextInt();
    int k = in.nextInt();
    int[][] a = new int[n][k];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < k; j++) {
        a[i][j] = in.nextInt();
      }
    }
    long ans = solve(a);
    System.out.println(ans);
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
