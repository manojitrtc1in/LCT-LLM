


import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Random;
import java.util.StringTokenizer;


























































































public class C1647F {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static int solve(int[] a) {
    int n = a.length;
    int[] va = normalize(a);
    int ans = solveInner(va);
    reverse(va);
    ans += solveInner(va);
    return ans;
  }

  static int solveInner(int[] a) {
    int n = a.length;
    int[][] dp1 = new int[n][2];
    int imax = -1;
    for (int i = 0; i < n; ++i) {
      if (imax == -1 || a[i] > a[imax]) {
        imax = i;
      }
    }
    dp1[0][0] = -1;
    if (imax == 0) {
      dp1[0][1] = n;
    } else {
      dp1[0][1] = -1;
    }
    for (int i = 1; i < n; ++i) {
      if (i == imax) {
        dp1[i][1] = -1;
        dp1[i][0] = dp1[i - 1][0];
        if (dp1[i - 1][1] != n) {
          dp1[i][0] = Math.min(dp1[i][0], a[i - 1]);
        }
      } else if (i < imax) {
        dp1[i][0] = n;
        dp1[i][1] = n;
        if (a[i] > a[i - 1]) {
          dp1[i][0] = dp1[i - 1][0];
        }
        if (dp1[i - 1][1] < a[i]) {
          dp1[i][0] = Math.min(dp1[i][0], a[i - 1]);
        }
        if (a[i] > a[i - 1]) {
          dp1[i][1] = dp1[i - 1][1];
        }
        if (dp1[i - 1][0] < a[i]) {
          dp1[i][1] = Math.min(dp1[i][1], a[i - 1]);
        }
      } else {
        dp1[i][0] = n;
        dp1[i][1] = -1;
        if (a[i] < a[i - 1]) {
          dp1[i][0] = dp1[i - 1][0];
        }
        if (dp1[i - 1][1] > a[i]) {
          dp1[i][0] = Math.min(dp1[i][0], a[i - 1]);
        }
        if (a[i] > a[i - 1]) {
          dp1[i][1] = dp1[i - 1][1];
        }
        if (dp1[i - 1][0] < a[i]) {
          dp1[i][1] = Math.max(dp1[i][1], a[i - 1]);
        }
      }
    }
    int[][] dp2 = new int[n][2];
    dp2[n - 1][0] = -1;
    dp2[n - 1][1] = -1;
    for (int i = n - 2; i >= 0; --i) {
      dp2[i][0] = n;
      dp2[i][1] = n;
      if (a[i] > a[i + 1]) {
        dp2[i][0] = dp2[i + 1][0];
      }
      if (a[i] > dp2[i + 1][1]) {
        dp2[i][0] = Math.min(dp2[i][0], a[i + 1]);
      }
      if (a[i] > a[i + 1]) {
        dp2[i][1] = dp2[i + 1][1];
      }
      if (a[i] > dp2[i + 1][0]) {
        dp2[i][1] = Math.min(dp2[i][1], a[i + 1]);
      }
    }
    int ans = 0;
    for (int i = imax + 1; i < n; ++i) {
      if (dp1[i][1] > dp2[i][1]) {
        

        ans++;
      }
    }
    if (test && ans > 0) {
      show(a, dp1, dp2);
    }
    return ans;
  }

  static void show(int[] va, int[][] dp1, int[][] dp2) {
    StringBuilder sb = new StringBuilder();
    int n = va.length;
    int[] ia = getIdxArray(va);
    

    for (int v = n - 1; v >= 0; v--) {
      

      sb.append(String.format("%11s ", ""));
      for (int j = 0; j < n; j++) {
        if (va[j] > v) {
          sb.append("  *");
        } else {
          sb.append("   ");
        }
      }
      sb.append("\n");
    }
    sb.append(String.format("%11s ", "i"));
    for (int i = 0; i < n; i++) {
      sb.append(String.format("%3d", i));
    }
    sb.append("\n");
    sb.append(String.format("%11s ", "a[i]"));
    for (int i = 0; i < n; i++) {
      sb.append(String.format("%3d", va[i]));
    }
    sb.append("\n");
    sb.append(String.format("%11s ", "dp1[i][0]"));
    for (int i = 0; i < n; i++) {
      sb.append(String.format("%3d", dp1[i][0]));
    }
    sb.append("\n");
    sb.append(String.format("%11s ", "dp1[i][1]"));
    for (int i = 0; i < n; i++) {
      sb.append(String.format("%3d", dp1[i][1]));
    }
    sb.append("\n");
    sb.append(String.format("%11s ", "dp2[i][0]"));
    for (int i = 0; i < n; i++) {
      sb.append(String.format("%3d", dp2[i][0]));
    }
    sb.append("\n");
    sb.append(String.format("%11s ", "dp2[i][0]"));
    for (int i = 0; i < n; i++) {
      sb.append(String.format("%3d", dp2[i][0]));
    }
    sb.append("\n");
    sb.append(String.format("%11s ", "ok"));
    for (int i = 0; i < n; i++) {
      boolean ok = i > ia[n-1] && dp1[i][1] > dp2[i][1];
      sb.append(String.format("%3s", ok ? "Y":""));
    }
    sb.append("\n");
    System.out.format(sb.toString());
  }

  static void reverse(int[] a) {
    int n = a.length;
    int b = 0;
    int e = n-1;
    while (b < e) {
      int t = a[b];
      a[b] = a[e];
      a[e] = t;
      b++;
      e--;
    }
  }

  

  static int[] normalize(int[] a) {
    int n = a.length;
    int[][] arr = new int[n][2];
    for (int i = 0; i < n; i++) {
      arr[i][0] = a[i];
      arr[i][1] = i;
    }
    sort(arr);
    

    int[] va = new int[n];
    for (int i = 0; i < n; i++) {
      va[arr[i][1]] = i;
    }
    return va;
  }

  

  static int[] getIdxArray(int[] a) {
    int n = a.length;
    int[] ia = new int[n];
    for (int i = 0; i < n; i++) {
      ia[a[i]] = i;
    }
    return ia;
  }

  public static void sort(int[][] arr) {
    for (int i = 0; i < arr.length; i++) {
      int r = RAND.nextInt(arr.length);
      int[] temp = arr[i];
      arr[i] = arr[r];
      arr[r] = temp;
    }
    Arrays.sort(arr, new Comparator<int[]>() {
      @Override
      public int compare(int[] a, int[] b) {
        return a[0] - b[0];
      }
    });
  }

  static int solveNaive(int[] a) {
    int n = a.length;
    

    int[] va = normalize(a);

    

    int[] ia = getIdxArray(va);

    int ans = 0;
    for (int vp2 = n - 2; vp2 >= 0; vp2--) {
      for (int i = 1; i < (1 << n); i++) {
        if (isOk(va, ia, vp2, i)) {
          System.out.format("  ok %d at %d with mask %s\n", vp2, ia[vp2], Integer.toBinaryString(i));
          ans++;
          break;
        }
      }
    }
    return ans;
  }

  static boolean isOk(int[] va, int[] ia, int vp2, int i) {
    int n = va.length;
    int i1 = ia[n-1];
    int i2 = ia[vp2];
    if ((i & (1 << i1)) != 0 || ((i & (1 << i2)) == 0)) {
      return false;
    }
    int prev1 = -1;
    int prev2 = -1;
    

    for (int j = 0; j < n; j++) {
      if ((i & (1 << j)) == 0) {
        

        if ((j < i1 && va[j] < prev1) || (j > i1 && va[j] > prev1)) {
          return false;
        }
        prev1 = va[j];
      } else {
        

        if (va[j] > vp2 || (j < i2 && va[j] < prev2) || (j > i2 && va[j] > prev2)) {
          return false;
        }
        prev2 = va[j];
      }
    }
    return true;
  }

  static String trace(int[] a) {
    return Arrays.toString(a).replace('[', '{').replace(']', '}').replace(" ", "");
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    

    

    long t0 = System.currentTimeMillis();
    int n = 12;
    int[] a = getRandomPerm(n);
    test(-1, a);
    

    

    

    

    

    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  static int[] getRandomPerm(int n) {
    List<Integer> arr = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      arr.add(i);
    }
    Collections.shuffle(arr);
    int[] ans = new int[n];
    for (int i = 0; i < n; i++) {
      ans[i] = arr.get(i);
    }
    return ans;
  }

  static void test(int exp, int[] a) {
    int[] va = normalize(a);
    int ans = solve(a);
    if (exp == -1) {
      exp = solveNaive(a);
    }
    System.out.format("%s => %d%s\n", trace(va), ans, ans == exp ? "":" Expected " + exp);
    myAssert(ans == exp);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int n = in.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = in.nextInt();
    }
    int ans = solve(a);
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
        cname = cname.lastIndexOf('.') > 0 ? cname.substring(0, cname.lastIndexOf('.')) : cname;
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
