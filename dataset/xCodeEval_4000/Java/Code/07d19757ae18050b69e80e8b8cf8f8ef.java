




























































































import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.StringTokenizer;

public class C1720E {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static int solve(int[][] a, int k) {
    int n = a.length;
    int m = n * n;
    int[] cnt = new int[m + 5];
    int[][] r = new int[n+5][n+5];

    int[] c = new int[1];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ins(a[i][j], cnt, c);
      }
    }

    if (c[0] == k) {
      return 0;
    }
    if (c[0] < k) {
      return k - c[0];
    }

    for (int i = 0; i < n; i++) {
      r[i][0] = 0;
      del(a[i][0], cnt, c);
      for (int j = 0; j < n; j++) {
        if (c[0] == k || c[0] + 1 == k) {
          return 1;
        }
        while (c[0] > k && r[i][j] < n - 1 && i + r[i][j] - j < n - 1) {
          ++r[i][j];
          int len = r[i][j] - j + 1;
          for (int x = 1; x <= len; x++) {
            del(a[i + x - 1][j + len - 1], cnt, c);
            if (x != len) {
              del(a[i+len-1][j+x-1], cnt, c);
            }
          }
          if (c[0] == k || c[0] + 1 == k) {
            return 1;
          }
        }
        int len = r[i][j] - j + 1;
        for (int x = 1; x <= len; x++) {
          ins(a[i+x-1][r[i][j]-len+1], cnt, c);
          if (x != len) {
            ins(a[i+len-1][r[i][j]-x+1], cnt, c);
          }
        }
        r[i][j+1] = r[i][j];
      }
      ins(a[i][n-1], cnt, c);
     }
    return 2;
  }

  static void ins(int x, int[] cnt, int[] c) {
    if (cnt[x] == 0) {
      c[0]++;
    }
    cnt[x]++;
  }

  static void del(int x, int[] cnt, int[] c) {
    --cnt[x];
    if (cnt[x] == 0) {
      c[0]--;
    }
  }

  

  

  static int solveA(int[][] a, int k) {
    int n = a.length;
    int m = n * n;
    int[] ct = new int[m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ct[a[i][j]]++;
      }
    }

    int unique = 0;
    for (int i = 0; i < m; i++) {
      if (ct[i] > 0) {
        unique++;
      }
    }

    if (k >= unique) {
      

      return k - unique;
    } else if (k == 1) {
      

      return unique == m ? 0 : 1;
    } else {
      int ans = k;

      int r = unique - k;
      

      int h = (int) (n * Math.sqrt(1.0 * r / unique));

      if (test) {
        System.out.format("  unique:%d r:%d h:%d\n", unique, r, h);
      }
      

      int s = checkSquares(a, h, ct, r);
      if (s == 0) {
        ans = 1;
      } else if (s > 0) {
        ans = Math.min(ans, 1 + s);
      } else {
        ans = Math.min(ans, 1 - s);
      }
      return ans;
    }
  }

  static int checkSquares(int[][] a, int h, int[] ct, int r) {
    int n = a.length;
    

    

    Map<Integer, Integer> cm = new HashMap<>();
    List<Integer> ea = new ArrayList<>();

    int i = 0;
    int j = 0;
    int eliminated = 0;
    for (int x = 0; x < h; x++) {
      for (int y = 0; y < h; y++) {
        int v = a[x][y];
        int count = cm.getOrDefault(v, 0) + 1;
        if (count == ct[v]) {
          eliminated++;
          if (count > 1) {
            cm.remove(v);
          }
        } else {
          cm.put(v, count);
        }
      }
    }

    while (i <= n - h) {
      if (test) {
        

      }
      if (eliminated == r) {
        return 0;
      }
      ea.add(eliminated);
      if (i % 2 == 0) {
        if (j < n - h) {
          

          

          

          

          

          

          for (int x = i; x < i+h; x++) {
            int v = a[x][j];
            int count = cm.getOrDefault(v, ct[v]) - 1;
            

            if (count > 0) {
              cm.put(v, count);
            } else {
              cm.remove(v);
            }
            if (count == ct[v] - 1) {
              eliminated--;
            }
          }
          

          for (int x = i; x < i+h; x++) {
            int v = a[x][j+h];
            int count = cm.getOrDefault(v, 0) + 1;
            if (count == ct[v]) {
              eliminated++;
              if (count > 1) {
                cm.remove(v);
              }
            } else {
              cm.put(v, count);
            }
          }
          j++;
        } else if (i < n - h) {
          

          

          

          

          

          

          

          for (int y = j; y < j+h; y++) {
            int v = a[i][y];
            int count = cm.getOrDefault(v, ct[v]) - 1;
            if (count > 0) {
              cm.put(v, count);
            } else {
              cm.remove(v);
            }
            if (count == ct[v] - 1) {
              eliminated--;
            }
          }
          

          for (int y = j; y < j+h; y++) {
            int v = a[i+h][y];
            int count = cm.getOrDefault(v, 0) + 1;
            if (count == ct[v]) {
              eliminated++;
              if (count > 1) {
                cm.remove(v);
              }
            } else {
              cm.put(v, count);
            }
          }
          i++;
        } else {
          break;
        }
      } else {
        if (j > 0) {
          

          

          

          

          

          

          for (int x = i; x < i+h; x++) {
            int v = a[x][j+h-1];
            int count = cm.getOrDefault(v, ct[v]) - 1;
            if (count > 0) {
              cm.put(v, count);
            } else {
              cm.remove(v);
            }
            if (count == ct[v] - 1) {
              eliminated--;
            }
          }
          

          for (int x = i; x < i+h; x++) {
            int v = a[x][j-1];
            int count = cm.getOrDefault(v, 0) + 1;
            if (count == ct[v]) {
              eliminated++;
              if (count > 1) {
                cm.remove(v);
              }
            } else {
              cm.put(v, count);
            }
          }
          j--;
        } else if (i < n - h) {
          

          

          

          

          

          

          

          for (int y = j; y < j+h; y++) {
            int v = a[i][y];
            int count = cm.getOrDefault(v, ct[v]) - 1;
            if (count > 0) {
              cm.put(v, count);
            } else {
              cm.remove(v);
            }
            if (count == ct[v] - 1) {
              eliminated--;
            }
          }
          

          for (int y = j; y < j+h; y++) {
            int v = a[i+h][y];
            int count = cm.getOrDefault(v, 0) + 1;
            if (count == ct[v]) {
              eliminated++;
              if (count > 1) {
                cm.remove(v);
              }
            } else {
              cm.put(v, count);
            }
          }
          i++;
        } else {
          break;
        }
      }
    }
    Collections.sort(ea);
    if (test) {
      System.out.format("  ea %s\n", ea.toString());
    }
    for (int v : ea) {
      if (v > r) {
        return v - r;
      }
    }
    

    return ea.get(ea.size() - 1) - r;
  }

  public static String trace(int[][] points) {
    StringBuilder sb = new StringBuilder();
    int h = 8;
    int m = points.length;
    for (int i = 0; i < m; i++) {
      if (m > (h << 1)) {
        if (i == h) {
          sb.append("     ...\n");
        }
        if (i >= h && i < m - h) {
          continue;
        }
      }
      sb.append(String.format("%3d: ", i));
      sb.append('[');

      int n = points[i].length;
      for (int j = 0; j < n; j++) {
        

        if (n > (h << 1)) {
          if (j == h) {
            sb.append(" ...");
          }
          if (j >= h && j < n - h) {
            continue;
          }
        }
        if (j > 0) {
          sb.append(' ');
        }
        sb.append(String.format("%2d", points[i][j]));
      }
      sb.append(']');
      if (i < points.length-1) {
        sb.append("\n");
      }
    }
    return sb.toString();
  }

  static void test(int[][] a, int k) {
    System.out.format("%s k:%d\n", trace(a), k);
    int ans = solve(a, k);
    System.out.format(" => %d\n", ans);
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    int n = 495;
    int m = n * n;
    int[][] a = new int[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = RAND.nextInt(m);
      }
    }
    int k = 1 + RAND.nextInt(m);
    k = 143;
    test(a, k);

    

    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int n = in.nextInt();
    int k = in.nextInt();
    int[][] a = new int[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = in.nextInt();
      }
    }
    int ans = solve(a, k);
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
