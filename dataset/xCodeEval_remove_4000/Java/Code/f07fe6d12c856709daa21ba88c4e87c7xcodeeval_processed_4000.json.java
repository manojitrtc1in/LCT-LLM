


import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;
import java.util.Set;
import java.util.StringTokenizer;
























































































public class id5 {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  

  

  static int[] solve(int[][] a, int[][] queries) {
    trace(a);
    int n = a[0].length;
    int q = queries.length;
    int[] ans = new int[q];

    int id = detectGroups(a, n);

    int[] la = id1(a, n);

    int[] ra = id0(a, n);

    int[] precnt = id3(a, n, id);

    for (int i = 0; i < q; i++) {
      int l = queries[i][0];
      int r = queries[i][1];
      

      ans[i] = precnt[r] - (l == 0 ? 0 : precnt[l-1]);
      if (test) System.out.format("  ans[i]:%d\n", ans[i]);

      

      Set<Integer> ids = new HashSet<>();
      if (l > 0) {
        for (int h = 0; h < 3; h++) {
          if (a[h][l] == a[h][l-1] && a[h][l] != 0) {
            if (test) System.out.format("  group %d across left\n", a[h][l]);
            ids.add(a[h][l]);
          }
        }
        ans[i] += ids.size();
      }

      boolean isl = isSplit(a, l);
      boolean isr = isSplit(a, r);

      if (!isl && !isr) {
        

        

        

        

        

      } else if (!isl && isr) {
        

        

        

        if (la[r] < l) {
          ans[i]++;
        }
      } else if (isl && !isr) {
        

        

        

        if (ra[l] > r) {
          ans[i]++;
        }
      } else {
        myAssert(isl && isr);
        

        

        

        

        

        if (a[0][l] == a[0][r]) {
          if (l == r) {
            

            

            

            ans[i] += 1;
          }
          

          

          

          

          else if (ra[l] == n) {
            if (la[r] == -1) {
              

              

              

              

              

              ans[i] += 2;
            } else if (la[r] < l) {
              

              

              

              

              

              ans[i] += 1;
            } else {
              

              

              

              

              

              ans[i] += 1;
            }
          } else if (ra[l] > r) {
            if (la[r] == -1) {
              

              

              

              

              

              ans[i] += 1;
            } else if (la[r] < l) {
              

              

              

              

              

              ans[i] += 1;
            } else {
              myAssert(false);
            }
          } else {
            if (la[r] == -1) {
              

              

              

              

              

              ans[i] += 1;
            } else if (la[r] < l) {
              myAssert(false);
            } else {
              

              

              

              

              

            }
          }
        } else {
          if (ra[l] > r) {
            ans[i]++;
          }
          if (la[r] < l) {
            ans[i]++;
          }
        }
      }
      if (test) {
        System.out.format("  i:%2d [%2d,%2d] isl:%d isr:%d ra:%2d la:%2d %d -> %d\n",
            i, l, r, isl ? 1 : 0, isr ? 1 : 0, ra[l], la[r], ids.size(), ans[i]);
      }

    }
    return ans;
  }

  private static int[] id3(int[][] a, int n, int id) {
    int[] precnt = new int[n];
    boolean[] seen = new boolean[id];
    seen[0] = true;
    for (int j = 0; j < n; j++) {
      precnt[j] = j == 0 ? 0 : precnt[j-1];
      for (int i = 0; i < 3; i++) {
        if (!seen[a[i][j]]) {
          precnt[j]++;
          seen[a[i][j]] = true;
        }
      }
    }
    if (test) {
      System.out.format("  pcnt:%s\n", trace(precnt));
    }
    return precnt;
  }

  private static int[] id0(int[][] a, int n) {
    int[] ra = new int[n];
    Arrays.fill(ra, n);
    for (int j = n-1; j >= 0; j--) {
      if (a[0][j] != a[2][j] || a[0][j] == 0) {
        continue;
      }
      

      int gid = a[0][j];
      if (a[1][j] == gid) {
        

        ra[j] = j;
      } else if (j < n - 1) {
        if (a[0][j+1] == gid && a[2][j+1] == gid) {
          ra[j] = ra[j+1];
        } else {
          

          

          

          

        }
      }
    }
    if (test) {
      System.out.format("    ra:%s\n", trace(ra));
    }
    return ra;
  }

  private static int[] id1(int[][] a, int n) {
    

    int[] la = new int[n];
    Arrays.fill(la, -1);
    for (int j = 0; j < n; j++) {
      if (a[0][j] != a[2][j] || a[0][j] == 0) {
        continue;
      }
      

      int gid = a[0][j];
      if (a[1][j] == gid) {
        

        la[j] = j;
      } else if (j > 0) {
        if (a[0][j-1] == gid && a[2][j-1] == gid) {
          la[j] = la[j-1];
        } else {
          

          

          

          

        }
      }
    }
    if (test) {
      System.out.format("    la:%s\n", trace(la));
    }
    return la;
  }

  private static int detectGroups(int[][] a, int n) {
    int id = 2;
    Queue<int[]> queue = new LinkedList<>();
    final int[][] dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < 3; i++) {
        

        if (a[i][j] != 1) {
          continue;
        }
        a[i][j] = id;
        queue.add(new int[] {i,j});
        while (!queue.isEmpty()) {
          int[] v = queue.poll();
          for (int[] dir : dirs) {
            int r = v[0] + dir[0];
            int c = v[1] + dir[1];
            if (r >= 0 && r < 3 && c >= 0 && c < n && a[r][c] == 1) {
              a[r][c] = id;
              queue.add(new int[] {r,c});
            }
          }
        }
        id++;
      }
    }

    trace(a);
    return id;
  }

  static boolean isSplit(int[][] a, int j) {
    return a[0][j] == a[2][j] && a[0][j] != 0 && a[1][j] == 0;
  }

  static void trace(int[][] a) {
    if (test) {
      for (int i = 0; i < 3; i++) {
        System.out.format("  %s\n", trace(a[i]));
      }
    }
  }

  static int[] id2(int[][] a, int[][] queries) {
    int n = a[0].length;
    int q = queries.length;
    int[][] incr = {
      

        {  0,  1,  1,  1,  1,  2,  1,  1},
        {  0,  0,  1,  0,  1,  1,  1,  0},
        {  1,  1,  0,  0,  1,  2,  0,  0},
        {  0,  0,  0,  0,  1,  1,  0,  0},
        {  0,  1,  1,  1,  0,  1,  0,  0},
        {  0,  0,  1,  0,  0,  0,  0,  0},
        {  0,  1,  0,  0,  0,  1,  0,  0},
        {  0,  0,  0,  0,  0,  0,  0,  0}
    };

    

    int[][] dp = new int[n][n];
    for (int i = 0; i < n; i++) {
      dp[i][i] = a[1][i] == 1 ? 1 : a[0][i] + a[2][i];
      for (int j = i + 1; j < n; j++) {
        int k1 = a[0][j-1] + a[1][j-1] * 2 + a[2][j-1] * 4;
        int k2 = a[0][j] + a[1][j] * 2 + a[2][j] * 4;
        dp[i][j] = dp[i][j-1] + incr[k1][k2];
      }
    }

    int[] ans = new int[q];
    for (int i = 0; i < q; i++) {
      ans[i] = dp[queries[i][0]][queries[i][1]];
    }
    return ans;
  }

  static int[] id4(int[][] a, int[][] queries) {
    int n = a[0].length;
    int q = queries.length;

    int[] ans = new int[q];
    for (int i = 0; i < q; i++) {
      int l = queries[i][0];
      int r = queries[i][1];
      ans[i] = detectGroups(a, l, r);
    }
    return ans;
  }

  private static int detectGroups(int[][] a, int l, int r) {
    int id = 2;
    Queue<int[]> queue = new LinkedList<>();
    final int[][] dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    for (int j = l; j <= r; j++) {
      for (int i = 0; i < 3; i++) {
        

        if (a[i][j] != 1) {
          continue;
        }
        a[i][j] = id;
        queue.add(new int[] {i,j});
        while (!queue.isEmpty()) {
          int[] v = queue.poll();
          for (int[] dir : dirs) {
            int x = v[0] + dir[0];
            int y = v[1] + dir[1];
            if (x >= 0 && x < 3 && y >= l && y <= r && a[x][y] == 1) {
              a[x][y] = id;
              queue.add(new int[] {x,y});
            }
          }
        }
        id++;
      }
    }

    for (int j = l; j <= r; j++) {
      for (int i = 0; i < 3; i++) {
        if (a[i][j] > 1) {
          a[i][j] = 1;
        }
      }
    }
    return id - 2;
  }

  static void test(int[][] a, int[][] queries) {
    int n = a[0].length;
    int q = queries.length;
    int[] exp = id4(a, queries);

    int[][] b = new int[3][n];
    for (int i = 0; i < 3; i++) {
      System.arraycopy(a[i], 0, b[i], 0, n);
    }

    int[] ans = solve(b, queries);
    for (int i = 0; i < q; i++) {
      if (ans[i] != exp[i]) {
        System.out.format("  i:%4d [%d,%d] ans:%d exp:%d\n", i, queries[i][0], queries[i][1], ans[i], exp[i]);
        id6(a);
        id6(a, queries[i][0], queries[i][1]);
      }
      myAssert(ans[i] == exp[i]);
    }
  }

  static int[][] id7(String[] s) {
    myAssert(s.length == 3);
    int n = s[0].length();
    int[][] a = new int[3][n];
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = s[i].charAt(j) - '0';
      }
    }
    return a;
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    {
      String[] s = {
          "011101110101101111100011",
          "010010011000000101110101",
          "011100010001100110110111"};
      int[][] a = id7(s);
      int[][] queries = {{2,2}};
      test(a, queries);
    }
    {
      String[] s = {
          "000111011011111011101011111010",
          "011111000111111011010000101100",
          "010101001011010010011101011110"};
      int[][] a = id7(s);
      int[][] queries = {{25,25}};
      test(a, queries);
    }
    {
      int[][] a = {
          {0,1,1,0,1,0,1,0,1,1},
          {0,0,1,1,0,0,1,1,0,1},
          {1,1,1,1,1,1,1,1,1,1}};
      int[][] queries = {{1,8}};
      test(a, queries);
    }

    for (int t = 0; t < 20; t++) {
      int n = 1 + RAND.nextInt(99);
      int[][] a = new int[3][n];
      for (int i = 0; i < n; i++) {
        a[0][i] = RAND.nextInt(2);
        a[1][i] = RAND.nextInt(2);
        a[2][i] = RAND.nextInt(2);
      }
      int q = Math.min(400, n * n / 2);
      int[][] queries = new int[q][2];
      for (int i = 0; i < q; i++) {
        int v1 = RAND.nextInt(n);
        int v2 = RAND.nextInt(n);
        queries[i][0] = Math.min(v1, v2);
        queries[i][1] = Math.max(v1, v2);
      }
      test(a, queries);
    }

    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  static void id6(int[][] a) {
    int n = a[0].length;
    id6(a, 0, n-1);
  }

  static void id6(int[][] a, int l, int r) {
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < 3; i++) {
      sb.setLength(0);
      for (int j = l; j <= r; j++) {
        sb.append((char)('0' + a[i][j]));
      }
      System.out.format("  %s\n", sb.toString());
    }
    char[] ca = new char[r-l+1];
    for (int j = l; j <= r; j++) {
      ca[j-l] = j % 10 == 0 ? '*' : ' ';
    }
    System.out.format("  %s\n", new String(ca));
  }

  static String trace(int[] a) {
    StringBuilder sb = new StringBuilder();
    sb.append('{');
    int n = a.length;
    final int h = 16;
    for (int i = 0; i < a.length; i++) {
      if (i > h && i < n-h) {
        continue;
      }
      if (sb.length() > 1) {
        sb.append(',');
      }
      if (i == h && n >= h * 2) {
        sb.append("...");
      } else {
        sb.append(a[i]);
      }
    }
    sb.append('}');
    return sb.toString();
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int n = in.nextInt();
    int[][] a = new int[3][n];
    for (int i = 0; i < 3; i++) {
      String s = in.next();
      for (int j = 0; j < n; j++) {
        a[i][j] = s.charAt(j) - '0';
      }
    }
    int q = in.nextInt();
    int[][] queries = new int[q][2];
    for (int i = 0; i < q; i++) {
      queries[i][0] = in.nextInt() - 1;
      queries[i][1] = in.nextInt() - 1;
    }
    int[] ans = solve(a, queries);
    output(ans);
  }

  static void output(int[] a) {
    StringBuilder sb = new StringBuilder();
    for (int v : a) {
      sb.append(v);
      sb.append('\n');
      if (sb.length() > 500) {
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
