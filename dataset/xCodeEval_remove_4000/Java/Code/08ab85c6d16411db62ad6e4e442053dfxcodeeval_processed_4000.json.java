


































































































































































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

public class id0 {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static final Combination COMB = new Combination(100000);

  

  

  

  

  

  

  static int solve(int[] a) {
    int n = a.length;

    int il = 0;
    while (il < n && a[il] == 0) {
      il++;
    }
    if (il == n) {
      return Combination.power(2L, n-1);
    }

    int ir = n-1;
    while (ir >= 0 && a[ir] == 0) {
      ir--;
    }

    long m0 = 1;
    if (il > 0 && ir < n - 1) {
      

      int k = il;
      int m = n - 1 - ir;
      int h = Math.min(k, m);
      

      
      m0 = COMB.choose(k + m, k);
    }
    long sub = func(a, il, ir) % MOD;
    return (int) ((m0 * sub) % MOD);
  }

  static long func(int[] a, int b, int e) {
    long ans = funcInner(a, b, e);
    if (test) {
      int[] arr = new int[e - b + 1];
      for (int i = b; i <= e; i++) {
        arr[i-b] = a[i];
      }
    }
    

    return ans;
  }

  static long funcInner(int[] a, int b, int e) {
    myAssert(b <= e);
    myAssert(a[b] != 0 && a[e] != 0);
    if (b == e) {
      return 1;
    } else if (b + 1 == e) {
      return a[b] == a[e] ? 2 : 1;
    }
    long sb = a[b];
    long se = a[e];
    int b1 = b + 1;
    int e1 = e - 1;
    while (sb != se && b1 <= e1) {
      if (sb > se) {
        se += a[e1];
        e1--;
      } else if (sb < se) {
        sb += a[b1];
        b1++;
      }
    }
    

    b = b1;
    e = e1;
    if (sb != se) {
      return 1;
    }
    if (b > e) {
      

      return 2;
    } else {
      myAssert(b <= e);
      

      int ib1 = b;
      while (ib1 <= e && a[ib1] == 0) {
        ib1++;
      }
      int k = ib1 - b;
      if (ib1 > e) {
        

        

        

        

        

        


        long sum = Combination.power(2L, k+1);
        

        return sum;
      }
      int ie1 = e;
      while (a[ie1] == 0) {
        ie1--;
      }
      long sub = func(a, ib1, ie1);

      int m = e - ie1;
      

      

      if (k == 0 && m == 0) {
        return (2 * sub) % MOD;
      } else {
        int h = Math.min(k, m);
        


        
        long sum = COMB.choose(m+k+2, k+1);
        

        return (sum * sub) % MOD;
      }
    }
  }

  static int pow2(int m) {
    long v = 1;
    for (int i = 0; i < m; i++) {
      v = (v << 1) % MOD;
    }
    return (int) v;
  }

  static class Combination {
    final int n;
    int[] fact;
    int[] finv;

    public Combination(int n) {
      this.n = n;
      this.fact = new int[n+1];
      this.finv = new int[n+1];
      fact[0] = 1;
      finv[0] = 1;
      for (int i = 1; i <= n; i++) {
        fact[i] = (int) (((long) fact[i-1] * i) % MOD);
        finv[i] = (int) (((long) finv[i-1] * inverse(i)) % MOD);
      }
    }

    

    public int choose(int m, int k) {
      return (int) ((((long)fact[m] * finv[k] % MOD) * finv[m-k]) % MOD);
    }

    

    

    public static int inverse(long a) {
      return power(a, MOD - 2);
    }

    

    public static int power(long x, int y) {
      if (y == 0) {
        return 1;
      }
      long w = power(x, y / 2);
      w = (w * w) % MOD;
      return (int) (y % 2 == 0 ? w : (w * x) % MOD);
    }

    

    

    public int permute(int m, int k) {
      return (int) ((long)fact[m] * finv[m-k] % MOD);
    }
  }

  static int id1(int[] a) {
    int n = a.length;
    int m = 1 << (n-1);
    List<Integer> balanced = new ArrayList<>();
    for (int i = 0; i < m; i++) {
      

      int mask = 1 + (i << 1);
      List<Integer> sums = new ArrayList<>();
      int sum = 0;
      for (int j = 0; j < n; j++) {
        if (((1 << j) & mask) != 0) {
          if (j != 0) {
            sums.add(sum);
            sum = 0;
          }
        }
        sum += a[j];
      }
      sums.add(sum);
      if (isBalanced(sums)) {
        

        balanced.add(mask);
      }
    }
    return balanced.size();
  }

  public static String traceBinary(int v, int n) {
    StringBuilder sb = new StringBuilder();
    while (v != 0) {
      sb.append((char)('0' + v % 2));
      v /= 2;
    }
    while (sb.length() < n) {
      sb.append('0');
    }
    return sb.reverse().toString();
  }

  static boolean isBalanced(List<Integer> sums) {
    int b = 0;
    int e = sums.size() - 1;
    while (b < e) {
      if (sums.get(b) != sums.get(e)) {
        return false;
      }
      b++;
      e--;
    }
    return true;
  }

  static void test(int exp, int[] a) {
    int ans = solve(a);
    if (exp < 0) {
      exp = id1(a);
    }
    System.out.format("%s => %d %s\n", Arrays.toString(a), ans, exp == ans ? "":"Expected " + exp);
    myAssert(ans == exp);
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    test(-1, new int[] {0,1,0,1,1,0,2,0,0,1});
    test(-1, new int[] {1, 2, 1, 1, 2, 1, 1, 2, 2, 1});
    for (int t = 0; t < 20; t++) {
      int n = 1 + RAND.nextInt(20);
      int[] a = new int[n];
      for (int i = 0; i < n; i++) {
        a[i] = RAND.nextInt(3);
      }
      test(-1, a);
    }

    test(1, new int[] {1000000000});
    test(2, new int[] {1, 1});
    test(3, new int[] {0,0,1,0});
    test(4, new int[] {1,2,3,2,1});
    test(2, new int[] {1,3,5,7,9});
    test(32, new int[] {0,0,0,0,0,0});
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int n = in.nextInt();
      int[] a = new int[n];
      for (int i = 0; i < n; i++) {
        a[i] = in.nextInt();
      }
      int ans = solve(a);
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
