




























































































































import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class id0 {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  

  

  

  

  static long[] solve(int[] a, int[][] queries) {
    int n = a.length;
    int m = queries.length;
    long[] ans = new long[m];

    TreeSet<Integer> bs = new TreeSet<>();
    bs.add(n);
    List<Integer> chunks = new ArrayList<>();
    {
      int b = 0;
      while (b < n) {
        int e = b + 1;
        while (e < n && a[e] == a[b]) {
          e++;
        }
        chunks.add(e - b);
        bs.add(b);
        b = e;
      }
    }
    long sum = id1(chunks);
    


    for (int j = 0; j < m; j++) {
      int i = queries[j][0];
      int x = queries[j][1];
      int b = bs.floor(i);
      int e = bs.ceiling(i + 1) - 1;
      


      

      

      

      if (a[i] == x) {
        ans[j] = sum;
        continue;
      }

      if (b == e) {
        

        

        

        boolean lsame = b > 0 && a[bs.floor(b-1)] == x;
        boolean rsame = e + 1 < n && a[e+1] == x;
        

        if (lsame && rsame) {
          

          

          

          

          

          

          

          

          sum -= i;

          

          sum -= n - 1 - i;

          

          sum -= 2L * i * (n-1-i);
          bs.remove(b);
          bs.remove(b + 1);
        } else if (lsame) {
          

          

          

          

          

          

          

          sum -= i;

          

          sum -= 1L * i * (n-1-i);
          bs.remove(b);
        } else if (rsame) {
          

          

          

          

          

          

          

          

          sum -= n - 1 - i;

          

          sum -= 1L * i * (n-1-i);
          bs.remove(b + 1);
        } else {
          

          

          

          

          

          

          

        }
      } else if (i == b) {
        boolean lsame = b > 0 && a[bs.floor(b-1)] == x;
        if (lsame) {
          

          

          

          

          

          

          

          sum -= i;

          

          sum += n - 1 - i;

          bs.remove(i);
          bs.add(i + 1);
        } else {
          

          

          

          

          

          


          

          sum += n - 1 - i;

          

          sum += 1L * i * (n-1-i);

          bs.add(i + 1);
        }
      } else if (i == e) {
        boolean rsame = e + 1 < n && a[e+1] == x;
        if (rsame) {
          

          

          

          

          

          

          

          sum += i;

          

          sum -= n - 1 - i;

          bs.remove(e + 1);
          bs.add(e);
        } else {
          

          

          

          

          

          

          

          sum += i;

          

          sum += 1L * i * (n-1-i);

          bs.add(i);
        }
      } else {
        

        

        

        

        

        

        sum += i;

        

        sum += n - 1 - i;

        

        sum += 2L * i * (n-1-i);

        bs.add(i);
        bs.add(i + 1);
      }
      ans[j] = sum;
      a[i] = x;
    }

    return ans;
  }

  static long id1(List<Integer> chunks) {
    long ans = 0;
    int m = chunks.size();
    


    

    

    

    long mul = 0;
    long presum = 0;
    for (int i = 0; i < m; i++) {
      int v = chunks.get(i);
      ans += ((long)v) * (v + 1) / 2;
      ans += mul * v;
      

      mul = mul + presum + v * 2;
      presum += v;
    }
    return ans;
  }

  static long id1(int[] a) {
    int n = a.length;
    long ans = 0;
    for (int l = 0; l < n; l++) {
      for (int r = l; r < n; r++) {
        ans += getCount(a, l, r);
      }
    }
    return ans;
  }

  static int getCount(int[] a, int l, int r) {
    int b = l;
    int ans = 0;
    while (b <= r) {
      int e = b + 1;
      while (e <= r && a[e] == a[b]) {
        e++;
      }
      ans++;
      b = e;
    }
    return ans;
  }

  static long[] id3(int[] a, int[][] queries) {
    int n = a.length;
    int m = queries.length;
    long[] ans = new long[m];
    for (int j = 0; j < m; j++) {
      int i = queries[j][0];
      int x = queries[j][1];
      a[i] = x;
      ans[j] = id1(a);
    }
    return ans;
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    int n = 10;
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = 1 + RAND.nextInt(9);
    }
    int m = 10;
    int[][] q = new int[m][2];
    for (int i = 0; i < m; i++) {
      q[i][0] = RAND.nextInt(n);
      q[i][1] = 1 + RAND.nextInt(9);
    }
    a = new int[] {2, 7, 1, 1, 1, 9, 9, 8, 4, 6};
    q = new int[][] {{7, 4}, {3, 6}, {9, 5}, {1, 8}, {5, 1}, {3, 3}, {6, 7}, {0, 3}, {9, 6}, {5, 4}};
    n = a.length;
    m = q.length;

    int[] b = new int[n];
    System.arraycopy(a, 0, b, 0, n);

    System.out.format("  a: %s\n", trace(a));
    System.out.format("  q: %s\n", trace(q));

    long[] ans = solve(a, q);
    System.out.format("ans: %s\n", trace(ans));

    long[] exp = id3(b, q);
    System.out.format("exp: %s\n", trace(exp));
    for (int i = 0; i < m; i++) {
      myAssert(ans[i] == exp[i]);
    }

    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  static String trace(int[] a) {
    return Arrays.toString(a).replace('[', '{').replace(']', '}');
  }

  static String trace(long[] a) {
    return Arrays.toString(a).replace('[', '{').replace(']', '}');
  }

  static String trace(int[][] queries) {
    return Arrays.deepToString(queries).replace('[', '{').replace(']', '}');
  }

  private static void id2() {
    List<Integer> chunks = new ArrayList<>(Arrays.asList(6,5,4,3));
    long sum1 = id1(chunks);
    long sum2 = id1(new int[] {6,6,6,6,6,6,5,5,5,5,5,4,4,4,4,3,3,3});
    System.out.format("  sum1: %d sum2:%d\n", sum1, sum2);
    myAssert(sum1 == sum2);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int n = in.nextInt();
    int m = in.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = in.nextInt();
    }
    int[][] queries = new int[m][2];
    for (int i = 0; i < m; i++) {
      queries[i][0] = in.nextInt() - 1;
      queries[i][1] = in.nextInt();
    }
    long[] ans = solve(a, queries);
    output(ans);
  }

  static void output(long[] a) {
    StringBuilder sb = new StringBuilder();
    for (long v : a) {
      sb.append(v);
      sb.append('\n');
      if (sb.length() > 4000) {
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
