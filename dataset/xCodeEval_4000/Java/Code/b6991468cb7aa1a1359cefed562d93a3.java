




























































































































import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.Random;
import java.util.StringTokenizer;

public class C1681E {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static long[] solve(int[][] doors, int[][] queries) {
    

    long[][][][] dp = computeMovesBinaryLift(doors);

    return processQueries(queries, doors, dp);
  }

  private static long[] processQueries(int[][] queries, int[][] doors, long[][][][] dp) {
    long t0 = System.currentTimeMillis();

    

    preProcessQueries(queries);

    int m = queries.length;
    long[] ans = new long[m];
    for (int k = 0; k < m; k++) {
      int x1 = queries[k][0];
      int y1 = queries[k][1];
      int x2 = queries[k][2];
      int y2 = queries[k][3];
      int l = Math.max(x1, y1);
      int h = Math.max(x2, y2) - l;
      

      myAssert(h >= 0);
      if (h == 0) {
        ans[k] = dist(x1, y1, x2, y2);
      } else {
        

        long d0 = distToDoor(x1, y1, 0, doors);
        long d1 = distToDoor(x1, y1, 1, doors);
        int mask = h - 1;
        int layer = l;
        for (int b = 0; b < dp.length; b++) {
          if ((mask & (1 << b)) > 0) {
            long next0 = Math.min(d0 + dp[b][layer][0][0], d1 + dp[b][layer][1][0]);
            long next1 = Math.min(d0 + dp[b][layer][0][1], d1 + dp[b][layer][1][1]);
            d0 = next0;
            d1 = next1;
            layer += 1 << b;
          }
        }
        d0 += distToPrevDoor(x2, y2, 0, doors);
        d1 += distToPrevDoor(x2, y2, 1, doors);
        ans[k] = Math.min(d0, d1);
      }
    }
    if (test) {
      System.out.format("queryProcess %d msec\n", System.currentTimeMillis() - t0);
    }
    return ans;
  }

  

  static void preProcessQueries(int[][] queries) {
    int m = queries.length;
    for (int i = 0; i < m; i++) {
      if (Math.max(queries[i][0], queries[i][1]) > Math.max(queries[i][2], queries[i][3])) {
        int t1 = queries[i][2];
        queries[i][2] = queries[i][0];
        queries[i][0] = t1;
        int t2 = queries[i][3];
        queries[i][3] = queries[i][1];
        queries[i][1] = t2;
      }
    }
  }

  static long[][][][] computeMovesBinaryLift(int[][] doors) {
    long t0 = System.currentTimeMillis();
    int n = doors.length + 1;
    int L = 0;
    while (1 << L <= n) {
      L++;
    }
    

    

    long[][][][] dp = new long[L][n][2][2];
    for (int i = 0; i < n-2; i++) {
      

      

      

      

      

      

      

      

      

      

      

      

      dp[0][i][0][0] = 1 + Math.abs(doors[i][1] - doors[i+1][1]);

      

      dp[0][i][0][1] = Math.min(
          1 + dist(doors[i][0]+1, doors[i][1], doors[i+1][2], doors[i+1][3]),
          d2d(doors, i) + 1 + dist(doors[i][2], doors[i][3]+1, doors[i+1][2], doors[i+1][3]));

      

      dp[0][i][1][0] = Math.min(
          1 + dist(doors[i][2], doors[i][3]+1, doors[i+1][0], doors[i+1][1]),
          d2d(doors, i) + 1 + dist(doors[i][0] + 1, doors[i][1], doors[i+1][0], doors[i+1][1]));

      

      dp[0][i][1][1] = 1 + Math.abs(doors[i][2] - doors[i+1][2]);
    }
    


    for (int k = 1; k < L; k++) {
      for (int i = 0; i < n; i++) {
        if (i + (1 << k) >= n-1) {
          continue;
        }
        for (int s = 0; s < 2; s++) {
          for (int d = 0; d < 2; d++) {
            

            

            

            

            int m = i + (1 << (k-1));
            long d1 = dp[k-1][i][s][0] + dp[k-1][m][0][d];
            long d2 = dp[k-1][i][s][1] + dp[k-1][m][1][d];
            dp[k][i][s][d] = Math.min(d1, d2);
          }
        }
      }
      

    }
    if (test) {
      System.out.format("computeMovesBinaryLift %d msec\n", System.currentTimeMillis() - t0);
    }
    return dp;
  }

  

  static int distToPrevDoor(int x, int y, int s, int[][] doors) {
    int i = Math.max(x, y) - 1;
    if (s == 0) {
      return 1 + dist(doors[i][0] + 1, doors[i][1], x, y);
    } else {
      return 1 + dist(doors[i][2], doors[i][3] + 1, x, y);
    }
  }

  

  static int distToDoor(int x, int y, int s, int[][] doors) {
    int i = Math.max(x, y);
    return s == 0 ? dist(doors[i][0], doors[i][1], x, y) : dist(doors[i][2], doors[i][3], x, y);
  }

  

  static int dist(int[] p, int[] q) {
    myAssert(Math.max(p[0], p[1]) == Math.max(q[0], q[1]));
    return Math.abs(p[0] - p[1] - q[0] + q[1]);
  }

  static int dist(int x0, int y0, int x1, int y1) {
    return Math.abs(x0 - y0 - x1 + y1);
  }

  

  static int d2d(int[][] doors, int i) {
    return Math.abs(doors[i][0] - doors[i][1] - doors[i][2] + doors[i][3]);
  }

  

  static int[][][][] buildCache(int[][] doors, int[][][][] dp) {
    long t0 = System.currentTimeMillis();
    int n = dp[0].length;
    final int C = 32;
    int[][][][] cache = new int[C][n][2][2];
    for (int j = 0; j < C; j++) {
      for (int i = 0; i < n - j - 1; i++) {
        for (int s = 0; s < 2; s++) {
          for (int d = 0; d < 2; d++) {
            if (j == 0) {
              

              cache[0][i][s][d] = s == d ? 0 : d2d(doors, i);
            } else if (j <= 2) {
              cache[j][i][s][d] = dp[j-1][i][s][d];
            } else {
              cache[j][i][s][d] = Math.min(
                  cache[j-1][i][s][0] + cache[1][i+j-1][0][d],
                  cache[j-1][i][s][1] + cache[1][i+j-1][1][d]);
            }
          }
        }
      }
    }
    if (test) {
      System.out.format("buildCache %d msec\n", System.currentTimeMillis() - t0);
    }
    return cache;
  }

  

  

  static int func(int h, int i, int s, int d, int[][] doors, int[][][][] dp, int[][][][] cache) {
    int C = cache.length;
    if (h < C) {
      return cache[h][i][s][d];
    } else {
      

      int p = Integer.highestOneBit(h);
      int k = 0;
      while (1 << k != p) {
        k++;
      }
      return Math.min(dp[k][i][s][0] + func(h - p, i + p, 0, d, doors, dp, cache),
          dp[k][i][s][1] + func(h - p, i + p, 1, d, doors, dp, cache));
    }
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    int n = 100000;
    int[][] doors = new int[n-1][4];
    for (int i = 0; i < n-1; i++) {
      doors[i][0] = i;
      doors[i][1] = RAND.nextInt(i+1);
      doors[i][2] = RAND.nextInt(i+1);
      doors[i][3] = i;
    }
    int m = 100000;
    int[][] queries = new int[m][4];
    for (int i = 0; i < m; i++) {
      queries[i][0] = RAND.nextInt(n);
      queries[i][1] = RAND.nextInt(n);
      queries[i][2] = RAND.nextInt(n);
      queries[i][3] = RAND.nextInt(n);
    }
    long[] ans = solve(doors, queries);
    output(ans);
    long max = ans[0];
    for (long v : ans) {
      max = Math.max(max, v);
    }
    System.out.format("max: %d\n", max);
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int n = in.nextInt();
    int[][] doors = new int[n-1][4];
    for (int i = 0; i < n-1; i++) {
      doors[i][0] = in.nextInt() - 1;
      doors[i][1] = in.nextInt() - 1;
      doors[i][2] = in.nextInt() - 1;
      doors[i][3] = in.nextInt() - 1;
      myAssert(doors[i][0] == i);
      myAssert(doors[i][3] == i);
    }
    int m = in.nextInt();
    int[][] queries = new int[m][4];
    for (int i = 0; i < m; i++) {
      queries[i][0] = in.nextInt() - 1;
      queries[i][1] = in.nextInt() - 1;
      queries[i][2] = in.nextInt() - 1;
      queries[i][3] = in.nextInt() - 1;
    }
    long[] ans = solve(doors, queries);
    output(ans);
  }

  static void output(long[] a) {
    StringBuilder sb = new StringBuilder();
    for (long v : a) {
      sb.append(v);
      sb.append('\n');
      if (sb.length() > 1000) {
        System.out.print(sb.toString());
        sb.setLength(0);
      }
    }
    System.out.print(sb.toString());
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
