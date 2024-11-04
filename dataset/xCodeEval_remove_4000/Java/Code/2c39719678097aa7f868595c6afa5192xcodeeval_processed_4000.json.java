


import java.io.File;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Scanner;
import java.util.TreeMap;
































































public class id0 {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  

  static int solveA(int[] a) {
    int n = a.length;
    

    

    

    

    

    

    

    

    

    


    

    TreeMap<Integer, int[]> prev = new TreeMap<>();
    prev.put(1, new int[] {1, a[0] % MOD});
    prev.put(a[0] + 1, new int[] {0, 0});
    

    int psum = a[0] % MOD;

    for (int i = 1; i < n; i++) {
      TreeMap<Integer, int[]> curr = new TreeMap<>();
      long csum = 0;
      for (Map.Entry<Integer, int[]> e : prev.entrySet()) {
        int b = e.getKey();
        int w = e.getValue()[0];
        int c = e.getValue()[1];

        System.out.format("  i:%d b:%d w:%d c:%d\n", i, b, w, c);
        if (b > a[i]) {
          continue;
        }
        int nw = (int) (((long)psum + MOD - w) % MOD);
        int nc = Math.min(c, a[i] + 1 - b);
        if (b == a[i-1] + 1 && a[i] > a[i-1]) {
          nc = a[i] - a[i-1];
        }
        csum += ((long)nw * nc) % MOD;
        System.out.format("          w:%d c:%d csum:%d\n", nw, nc, csum);
        curr.put(b, new int[] {nw, nc});
      }
      curr.put(a[i] + 1, new int[] {0, 0});
      prev = curr;
      psum = (int) (csum % MOD);
    }
    return psum;
  }

  

  static int solveB(int[] a) {
    int n = a.length;
    int z = id4(a);
    if (z >= 0) {
      return z;
    }

    

    

    

    

    

    

    

    

    

    


    

    int[][] ia = new int[200001][3];
    ia[0][0] = 1;
    ia[0][1] = 1;
    ia[0][2] = a[0] % MOD;
    ia[1][0] = a[0] + 1;
    int m = 2;
    

    int psum = a[0] % MOD;

    for (int i = 1; i < n; i++) {
      long csum = 0;
      int idx = 0;
      for (int j = 0; j < m; j++) {
        int b = ia[j][0];
        int w = ia[j][1];
        int c = ia[j][2];
        System.out.format("  i:%d b:%d w:%d c:%d\n", i, b, w, c);
        if (b > a[i]) {
          continue;
        }
        int nw = (int) (((long)psum + MOD - w) % MOD);
        int nc = Math.min(c, a[i] + 1 - b);
        if (b == a[i-1] + 1 && a[i] > a[i-1]) {
          nc = a[i] - a[i-1];
        }
        csum += ((long)nw * nc) % MOD;
        ia[idx][1] = nw;
        ia[idx][2] = nc;
        idx++;
        System.out.format("          w:%d c:%d csum:%d\n", nw, nc, csum);
      }
      ia[idx][0] = a[i] + 1;
      ia[idx][1] = 0;
      ia[idx][2] = 0;
      idx++;
      m = idx;
      psum = (int) (csum % MOD);
    }
    return psum;
  }

  

  static int solveC(int[] ain) {
    int n = ain.length;
    final int N = n + 3;
    int[] a = new int[N];
    int[] q = new int[N];
    int[] l = new int[N];
    int[] r = new int[N];
    int[] f = new int[N];
    int[] g = new int[N];
    int[] s = new int[N];

    for (int i = 2; i <= n+1; i++) {
      a[i] = ain[i-2];
    }
    a[1] = a[n+2] = -(1<<30);
    int t = 1;
    q[1] = 1;
    for (int i = 2; i <= n+2; i++){
      for (; t != 0 && a[q[t]] >= a[i]; --t) {
        r[q[t]] = i;
      }
      l[i]=q[t];
      q[++t]=i;
    }
    f[1]=1;
    s[1]=1;
    int ans = 0;
    for (int i = 2; i <= n + 1; i++) {
      f[i] = (s[i-1] + MOD - s[l[i]-1]) % MOD;
      int val = (int) ((1L * a[i] * f[i]) % MOD);
      g[i]= (int) ((g[i] + g[i-1] + (long)val) % MOD);
      g[r[i]]= (g[r[i]] + MOD - val) % MOD;
      int vg = ((i & 1) > 0) ? MOD-g[i] : g[i];
      s[i]= (s[i-1] + MOD -g[i]) % MOD;
      

      if (i == n+1) {
        ans = (vg + MOD) % MOD;
      }
    }
    
    return ans;
  }

  static int id4(int[] a) {
    int n = a.length;
    if (id5(a)) {
      

      long ans = a[0] % MOD;
      for (int i = 1; i < n; i++) {
        ans = (ans * (a[i] - 1)) % MOD;
      }
      return (int) ans;
    } else if (id2(a)) {
      

      long ans = a[n-1] % MOD;
      for (int i = n-2; i >= 0; i--) {
        ans = (ans * (a[i] - 1)) % MOD;
      }
      return (int) ans;
    } else {
      return -1;
    }
  }

  

  static boolean id5(int[] a) {
    int n = a.length;
    for (int i = 1; i < n; i++) {
      if (a[i] < a[i-1]) {
        return false;
      }
    }
    return true;
  }

  

  static boolean id2(int[] a) {
    int n = a.length;
    for (int i = 1; i < n; i++) {
      if (a[i] > a[i-1]) {
        return false;
      }
    }
    return true;
  }

  static class Affine {
    long a;
    long b;

    Affine(){
      a = 1;
      b = 0;
    }

    Affine(long A, long B){
      this.a = A;
      this.b = B;
    }
  }

  static Affine composite(Affine f, Affine g) {
    return new Affine(f.a * g.a % MOD, (f.b * g.a + g.b) % MOD);
  }

  static long[] composite(long[] f, long[] g) {
    return new long[] {f[0] * g[0] % MOD, (f[1] * g[0] + g[1]) % MOD};
  }

  static class id1 {
    int N;
    long[] sum;
    long[] wsum;
    long[][] lazy;

    id1(int[] A, int[] B) {
      int n = A.length;
      N = id6(n);
      int m = N * 2 - 1;
      sum = new long[m];
      wsum = new long[m];
      lazy = new long[m][2];

      for (int i = 0; i < m; i++) {
        lazy[i][0] = 1;
      }

      for (int i = 0; i < n; i++) {
        sum[N - 1 + i] = (long)A[i] * B[i] % MOD;
        wsum[N - 1 + i] = B[i];
      }
      for (int i = N - 2; i >= 0; i--){
        sum[i] = (sum[i * 2 + 1] + sum[i * 2 + 2]) % MOD;
        wsum[i] = (wsum[i * 2 + 1] + wsum[i * 2 + 2]) % MOD;
      }
    }

    void eval(int i) {
      if (i < N - 1) {
        {
          long[] f = lazy[i * 2 + 1];
          long[] g = lazy[i];
          long x = f[0] * g[0] % MOD;
          long y = (f[1] * g[0] + g[1]) % MOD;
          f[0] = x;
          f[1] = y;
        }
        {
          long[] f = lazy[i * 2 + 2];
          long[] g = lazy[i];
          long x = f[0] * g[0] % MOD;
          long y = (f[1] * g[0] + g[1]) % MOD;
          f[0] = x;
          f[1] = y;
        }
        

        

        

      }
      sum[i] = (sum[i] * lazy[i][0] + wsum[i] * lazy[i][1]) % MOD;
      

      lazy[i][0] = 1;
      lazy[i][1] = 0;
    }

    void rangeAffine(int L, int R, long[] f, int i, int l, int r) {
      eval(i);
      if (R <= l || r <= L) {
        return;
      } else if (L <= l && r <= R) {
        lazy[i][0] = f[0];
        lazy[i][1] = f[1];
        eval(i);
      } else {
        int m = (l + r) / 2;
        rangeAffine(L, R, f, i * 2 + 1, l, m);
        rangeAffine(L, R, f, i * 2 + 2, m, r);
        sum[i] = (sum[i * 2 + 1] + sum[i * 2 + 2]) % MOD;
      }
    }

    void rangeAffine(int L, int R, long[] f) {
      rangeAffine(L, R, f, 0, 0, N);
    }

    long rangeSum(int L, int R, int i, int l, int r) {
      eval(i);
      if (R <= l || r <= L) {
        return 0;
      } else if (L <= l && r <= R) {
        return sum[i];
      } else {
        int m = (l + r) / 2;
        return (rangeSum(L, R, i * 2 + 1, l, m) + rangeSum(L, R, i * 2 + 2, m, r)) % MOD;
      }
    }
    long range_sum(int L, int R) {
      return rangeSum(L, R, 0, 0, N);
    }

    public static int id6(int num) {
      if (num == 0) {
        return 1;
      }
      if (num > 0 && (num & (num-1)) == 0) {
        return num;
      }
      while ((num & (num-1)) > 0) {
          num = num & (num - 1);
      }
      return num << 1;
    }
  }

  static void show(int[] a) {
    int n = a.length;
    int[] prefix = new int[n];
    List<int[]> output = new ArrayList<>();
    dfs(a, 0, prefix, output);
    for (int i = 0; i < output.size(); i++) {
      System.out.format("  %4d: %s\n", i+1, Arrays.toString(output.get(i)));
    }
    

    for (int i = 0; i < n; i++) {
      int[] count = new int[a[i]];
      for (int[] v : output) {
        count[v[i]-1]++;
      }
      System.out.format("   idx: %d count: %s\n", i, Arrays.toString(count));
    }
  }

  static void dfs(int[] a, int k, int[] prefix, List<int[]> output) {
    int n = a.length;
    if (k == n) {
      int[] arr = new int[n];
      System.arraycopy(prefix, 0, arr, 0, n);
      output.add(arr);
      return;
    }
    for (int v = 1; v <= a[k]; v++) {
      if (k > 0 && v == prefix[k-1]) {
        continue;
      }
      prefix[k] = v;
      dfs(a, k+1, prefix, output);
    }
  }

  static void doTest() {
    long t0 = System.currentTimeMillis();
    

    

    

    int n = 200000;
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = 1 + RAND.nextInt(1000000000);
    }
    

    System.out.println(solve(a));
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    t0 = System.currentTimeMillis();
    System.out.println(solveC(a));
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  static int solve(int[] a) {
    int n = a.length;
    int[][] p = new int[n][2];
    for (int i = 0; i < n; i++) {
      p[i][0] = a[i];
      p[i][1] = i;
    }
    Arrays.sort(p, (x,y)->x[0] - y[0]);
    int[] pos = new int[n];
    for (int i = 0; i < n; i++){
      pos[p[i][1]] = i;
    }
    int[] b = new int[n];
    b[0] = p[0][0];
    for (int i = 0; i < n - 1; i++){
      b[i + 1] = p[i+1][0] - p[i][0];
    }
    int[] s = new int[n];
    for (int i = 0; i <= pos[0]; i++){
      s[i] = 1;
    }
    id1 lst = new id1(s, b);
    for (int i = 0; i < n - 1; i++) {
      long sum = lst.range_sum(0, n);
      lst.rangeAffine(0, pos[i + 1] + 1, new long[] {MOD - 1, sum});
      lst.rangeAffine(pos[i + 1] + 1, n, new long[] {0, 0});
    }
    int ans = (int) lst.range_sum(0, n);
    return ans;
  }

  public static void main(String[] args) {
    

    Scanner in = id3();
    

    int n = in.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = in.nextInt();
    }
    int ans = solve(a);
    System.out.println(ans);
    in.close();
  }

  static Scanner id3() {
    try {
      final String USERDIR = System.getProperty("user.dir");
      final String CNAME = MethodHandles.lookup().lookupClass().getSimpleName();
      final File fin = new File(USERDIR + "/io/c" + CNAME.substring(1,5) + "/" + CNAME + ".in");
      return fin.exists() ? new Scanner(fin) : new Scanner(System.in);
    } catch (Exception e) {
      return new Scanner(System.in);
    }
  }
}
