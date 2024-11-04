






























































































































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

public class id3 {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static int[] FACT = id1(1000000);

  static int solve(int[] v, int k) {
    int n = v.length;
    myAssert(v[0] <= 0);

    

    

    

    for (int i = 1; i <= k; i++) {
      if (v[n-i] > 0) {
        return 0;
      }
    }

    

    int e = n - k - 1;
    

    

    


    long ans = FACT[k+1];
    for (int i = 1; i <= e; i++) {
      long mul = 1;
      if (v[i] > 0) {
        

      } else if (v[i] == 0) {
        

        mul = mul * (k+1) % MOD;
      } else {
        myAssert(v[i] == -1);
        

        

        mul = i + k + 1;
      }
      ans = ans * mul % MOD;
      if (test) {
        System.out.format("  i:%d mul:%2d ans:%d\n", i, mul, ans);
      }
    }
    return (int) ans;
  }

  static int[] id1(int n) {
    int[] fact = new int[n+1];
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
      fact[i] = (int) (((long) fact[i-1] * i) % MOD);
    }
    return fact;
  }

  static class Permutation {
    int[] perm;
    boolean checkedNext = true;
    boolean hasNext = true;
    

    int m = 1;

    

    public Permutation(int n) {
      this.perm = firstPerm(n);
    }

    

    public Permutation(int n, int k) {
      myAssert(n >= 1 && k > 0 && k <= n);

      

      this.m = 1;
      for (int i = 1; i <= n - k; i++) {
        m *= i;
      }
      this.perm = firstPerm(n);
    }

    

    

    

    

    public Permutation(int[] state) {
      this.perm = state;
    }

    boolean hasNext() {
      if (!checkedNext) {
        checkNext();
      }
      return hasNext;
    }

    private void checkNext() {
      if (!checkedNext) {
        for (int i = 0; i < m; i++) {
          hasNext = nextPerm(perm);
        }
        checkedNext = true;
      }
    }

    public int[] next() {
      checkNext();
      checkedNext = false;
      return hasNext ? perm : null;
    }

    

    public List<int[]> getAll() {
      List<int[]> all = new ArrayList<>();
      while (hasNext()) {
        next();
        int[] one = new int[perm.length];
        System.arraycopy(perm, 0, one, 0, perm.length);
        all.add(one);
      }
      return all;
    }

    public static int[] firstPerm(int n) {
      int[] perm = new int[n];
      for (int i = 0; i < n; i++) {
        perm[i] = i;
      }
      return perm;
    }

    

    

    

    

    

    

    public static boolean nextPerm(int[] nums) {
      int n = nums.length;
      int i = n - 1;
      while (i > 0 && nums[i-1] >= nums[i]) {
        i--;
      }
      if (i == 0) {
        return false;
      }
      i--;
      int j = n - 1;
      while (nums[j] <= nums[i]) {
        j--;
      }
      swap(nums, i ,j);
      i++;
      j = n - 1;
      while (i < j) {
        swap(nums, i ,j);
        i++;
        j--;
      }
      return true;
    }

    static void swap(int[] idxes, int i, int j) {
      int t = idxes[i];
      idxes[i] = idxes[j];
      idxes[j] = t;
    }

    public static List<int[]> id0(int n, int k) {
      return new Permutation(n,k).getAll();
    }
  }

  static void reduce(int[] p) {
    int n = p.length;
    for (int i = 0; i < n - 1; i++) {
      if (p[i] > p[i+1]) {
        int t = p[i];
        p[i] = p[i+1];
        p[i+1] = t;
      }
    }
  }

  static void reduce(int[] p, int k) {
    for (int i = 0; i < k; i++) {
      reduce(p);
    }
  }

  static void getCount(int[] p, int[] ct) {
    int n = p.length;
    Arrays.fill(ct, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (p[j] > p[i]) {
          ct[i]++;
        }
      }
    }
  }

  static String trace(int[] a) {
    StringBuilder sb = new StringBuilder();
    sb.append('{');
    for (int v : a) {
      if (sb.length() > 1) {
        sb.append(',');
      }
      sb.append(v);
    }
    sb.append('}');
    return sb.toString();
  }

  static void increment(int[] ct, List<int[]> cts, List<Integer> ctv) {
    int n = ct.length;
    for (int i = 0; i < cts.size(); i++) {
      boolean equal = true;
      int[] v = cts.get(i);
      for (int j = 0; j < n; j++) {
        if (v[j] != ct[j]) {
          equal = false;
          break;
        }
      }
      if (equal) {
        ctv.set(i, ctv.get(i) + 1);
        return;
      }
    }
    int[] arr = new int[n];
    System.arraycopy(ct, 0, arr, 0, n);
    cts.add(arr);
    ctv.add(1);
  }

  static void test(int exp, int[] v, int k) {
    int ans = solve(v, k);
    System.out.format("%s %d => %d%s\n", trace(v), k, ans, ans == exp ? "" : " Expected " + exp);
    myAssert(ans == exp);
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();

    


    test(120, new int[] {0,-1,0,0,0}, 4);
    test(161280, new int[] {-1,-1,-1,-1,-1,0,0,0,0}, 3);
    test(181440, new int[] {-1,-1,-1,-1,0,-1,0,0,0}, 3);

    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  private static void id2() {
    int n = 9;
    int k = 3;
    List<int[]> all = Permutation.id0(n, n);
    StringBuilder sb = new StringBuilder();
    int index = 0;
    int[] ct = new int[n];
    List<int[]> cts = new ArrayList<>();
    List<Integer> ctv = new ArrayList<>();
    for (int[] p : all) {
      index++;
      sb.append(String.format("%6d ", index));
      sb.append(trace(p));
      reduce(p, k);
      sb.append(" -> ");
      sb.append(trace(p));
      getCount(p, ct);
      sb.append(" -> ");
      sb.append(trace(ct));
      sb.append('\n');
      increment(ct, cts, ctv);
    }
    System.out.print(sb.toString());
    for (int i = 0; i < cts.size(); i++) {
      System.out.format("  %4d %s %d\n", i+1, trace(cts.get(i)), ctv.get(i));
    }
    for (int i = 0; i < n - k; i++) {
      char[] ca = new char[2 * n - 1];
      Arrays.fill(ca, ' ');
      for (int j = 0; j <= i; j++) {
        int v = 0;
        for (int h = 0; h < n; h++) {
          ca[2*h] = h < n - k ? '*' : '0';
        }
        ca[2*i] = (char)('0' + j);
        for (int h = 0; h < cts.size(); h++) {
          if (cts.get(h)[i] == j) {
            v += ctv.get(h);
          }
        }
        System.out.format("    %s -> %d\n", new String(ca), v);
      }
    }
    int[] ct40 = new int[n];
    for (int i = 0; i < cts.size(); i++) {
      if (cts.get(i)[4] == 0) {
        ct40[cts.get(i)[5]] += ctv.get(i);
      }
    }
    System.out.format("  ct40: %s\n", trace(ct40));
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int n = in.nextInt();
      int k = in.nextInt();
      int[] v = new int[n];
      for (int i = 0; i < n; i++) {
        v[i] = in.nextInt();
      }
      int ans = solve(v, k);
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
