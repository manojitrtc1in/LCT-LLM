


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
































































































public class id1 {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  
  static long[] solve(int[][] points, int[][] queries) {
    int n = points.length;
    int q = queries.length;
    long[] f = new long[n];
    Arrays.fill(f, (long)5e18);

    List<List<int[]>> qa = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      qa.add(new ArrayList<>());
    }
    for (int i = 0; i < q; i++) {
      int l = queries[i][0];
      int r = queries[i][1];
      qa.get(l).add(new int[] {r, i});
    }

    int[] s = new int[n];
    int it = 0;
    List<List<Integer>> ra = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      ra.add(new ArrayList<>());
    }

    for (int i = 0; i < n; i++) {
      while (it >= 1 && points[s[it]][1] >= points[i][1]) {
        ra.get(s[it]).add(i);
        it--;
      }
      ra.get(s[it]).add(i);
      s[++it] = i;
    }

    long[] ans = new long[q];
    for (int i = n - 2; i >= 0; i--) {
      Add(i, i + 1, points, f);
      for (int j : ra.get(i)) {
        Add(i, j, points, f);
      }
      for (int[] e : qa.get(i)) {
        int x = e[0];
        int y = e[1];
        ans[y] = get(x, (long)5e18, f);
        

      }
    }
    return ans;
  }

  static void add(int x, long y, long[] f) {
    int n = f.length;
    for(; x < n; x += (-x&x)) {
      f[x] = Math.min(f[x], y);
      if (x == 0) break;
    }
  }

  static long get(int x, long y, long[] f) {
    while (true) {
      y = Math.min(y,f[x]);
      x -= (-x & x);
      if (x == 0) {
        break;
      }
    }
    return y;
  }

  static void Add(int x, int y, int[][] points, long[] f) {
    add(y, ((long)(points[x][1] + points[y][1])) * (points[y][0] - points[x][0]), f);
  }

  

  static long[] solveA(int[][] points, int[][] queries) {
    int n = points.length;
    int q = queries.length;

    int m = getRank(n);
    if (test) System.out.format("  n:%d r:%d\n", n, m);
    List<id0> sts = new ArrayList<>();
    sts.add(null);
    for (int i = 1; i <= m; i++) {
      sts.add(new id0(n));
    }

    id3 st0 = new id3(n);
    

    for (int i = 0; i < n; i++) {
      st0.set(i, points[i][1]);
    }

    

    id0 st1 = sts.get(1);
    for (int i = 0; i < n - 1; i++) {
      st1.set(i, getwd(points, i, i + 1));
    }

    long idx = 0;
    for (int r = 2; r <= m; r++) {
      int len = 1 << r;
      id0 stc = sts.get(r);
      int end = n - (1 << r);
      for (int i = 0; i <= end; i++) {
        idx++;
        stc.set(i, id2(i, i + len - 1, true, points, sts, st0));
        if (idx % 100000 == 0) {
          if (test) System.out.format("  r:%2d idx:%d\n", r, idx);
        }
      }
    }
    if (test) System.out.format("  *************************\n");
    long[] ans = new long[q];
    for (int i = 0; i < q; i++) {
      int l = queries[i][0];
      int r = queries[i][1];
      ans[i] = id2(l, r, false, points, sts, st0);
    }
    if (test) {
      System.out.format("total loop %d\n", loop);
    }
    return ans;
  }

  static int loop = 0;
  static int[] mine = new int[3];

  static long id2(int l, int r, boolean prepare, int[][] points,
      List<id0> sts, id3 st0) {
    int rank = getRank(r - l + 1);
    int h = 1 << rank;
    int e = r - l + 1 - h;
    if (prepare) {
      myAssert(e == 0);
      rank--;
      h = 1 << rank;
      e = h;
    }
    id0 stc = sts.get(rank);
    

    

    

    

    

    

    

    

    

    

    

    


    

    long value = stc.id2(l, l + e);

    st0.id4(l, r, mine);
    int i0 = -1;
    if (mine[1] > l && mine[1] < r) {
      i0 = mine[1];
    } else if (mine[2] > l && mine[2] < r) {
      i0 = mine[2];
    }

    if (i0 >= l + e && i0 <= l + h) {
      

    } else {
      for (int j = l; j < l + e; j++) {
        int minw = st0.id2(j + h, r);
        long minv = getwd(points[j][0], points[j][1], points[j+h][0], minw);
        if (minv >= value) {
          continue;
        }
        loop++;
        boolean reduced = false;
        for (int k = j + h; k <= r; k++) {
          long z = getwd(points, j, k);
          if (z < value) {
            value = z;
            reduced = true;
          }
        }
        if (test) {
          System.out.format("  loop %4d r:%2d i:%5d j:%5d minw:%9d minv:%17d   ans:%17d %s\n",
              loop, rank, l, j, minw, minv, value, reduced ? "reduced" : "");
        }
      }
    }
    return value;
  }

  static long getwd(int[][] points, int i, int j) {
    myAssert(i < j);
    return (long)(points[j][0] - points[i][0]) * (points[i][1] + points[j][1]);
  }

  static long getwd(int xi, int wi, int xj, int wj) {
    myAssert(xi < xj);
    return (long)(xj - xi) * (wi + wj);
  }

  

  static int getRank(int v) {
    int m = 0;
    int w = 1;
    while (w * 2 <= v) {
      w *= 2;
      m++;
    }
    return m;
  }

  static class id0 {
    int m;

    long[] arr;

    public id0(int n) {
      

      this.m = 1;
      while (m < n) {
        m <<= 1;
      }
      arr = new long[m * 2];
    }

    public id0(long[] nums) {
      this(nums.length);
      for (int i = 0; i < nums.length; i++) {
        set(i, nums[i]);
      }
    }

    public long get(int index) {
      return arr[m + index];
    }

    public void set(int index, long value) {
      int i = m + index;
      arr[i] = value;
      i /= 2;
      while (i > 0) {
        arr[i] = Math.min(arr[2 * i], arr[2 * i + 1]);
        i /= 2;
      }
    }

    public void add(int index, long increment) {
      set(index, get(index) + increment);
    }

    public long id2(int b, int e) {
      if (b == e) {
        return arr[m + b];
      }
      int ib = m + b;
      int ie = m + e;
      long v = Math.min(arr[ib], arr[ie]);
      while (ib / 2 != ie / 2) {
        if (ib % 2 == 0) {
          

          v = Math.min(v, arr[ib + 1]);
        }
        if (ie % 2 == 1) {
          

          v = Math.min(v, arr[ie - 1]);
        }
        ib /= 2;
        ie /= 2;
      }
      return v;
    }
  }

  static class id3 {
    int m;

    int[] arr;
    int[] ila;
    int[] ira;

    public id3(int n) {
      

      this.m = 1;
      while (m < n) {
        m <<= 1;
      }
      arr = new int[m * 2];
      ila = new int[m * 2];
      ira = new int[m * 2];
      Arrays.fill(arr, Integer.MAX_VALUE);
    }

    public id3(int[] nums) {
      this(nums.length);
      for (int i = 0; i < nums.length; i++) {
        set(i, nums[i]);
      }
    }

    public int get(int index) {
      return arr[m + index];
    }

    public void set(int index, int value) {
      int i = m + index;
      arr[i] = value;
      ila[i] = index;
      ira[i] = index;
      i /= 2;
      while (i > 0) {
        int v = Math.min(arr[2 * i], arr[2 * i + 1]);
        if (v == arr[2 * i] && v == arr[2 * i + 1]) {
          ila[i] = ila[2 * i];
          ira[i] = ira[2 * i + 1];
        } else if (v == arr[2 * i]) {
          ila[i] = ila[2 * i];
          ira[i] = ira[2 * i];
        } else {
          ila[i] = ila[2 * i + 1];
          ira[i] = ira[2 * i + 1];
        }
        arr[i] = v;
        i /= 2;
      }
    }

    public void add(int index, int increment) {
      set(index, get(index) + increment);
    }

    

    

    

    

    

    

    

    

    

    public int id4(int b, int e, int[] output) {
      myAssert(b <= e);
      output[0] = arr[m + b];
      output[0] = b;
      output[1] = e;
      if (b == e) {
        return output[0];
      }
      int ib = m + b;
      int ie = m + e;
      int il = b;
      int ir = e;
      int v = Math.min(arr[ib], arr[ie]);
      if (v == arr[ib] && v != arr[ie]) {
        ir = b;
      } else if (v != arr[ib] && v == arr[ie]) {
        il = e;
      }
      int enter = 0;
      while (ib / 2 != ie / 2) {
        myAssert(++enter < 30);
        if (ib % 2 == 0) {
          

          if (arr[ib + 1] < v) {
            v = arr[ib + 1];
            il = ila[ib + 1];
            ir = ira[ib + 1];
          } else if (arr[ib + 1] == v) {
            ir = Math.max(ir, ira[ib + 1]);
            il = Math.min(il, ila[ib + 1]);
          }
        }
        if (ie % 2 == 1) {
          

          if (arr[ie - 1] < v) {
            v = arr[ie - 1];
            il = ila[ie - 1];
            ir = ira[ie - 1];
          } else if (arr[ie - 1] == v) {
            il = Math.min(il, ila[ie - 1]);
            ir = Math.max(ir, ira[ie - 1]);
          }
        }
        ib /= 2;
        ie /= 2;
      }
      output[0] = v;
      output[1] = il;
      output[2] = ir;
      return v;
    }

    public int id2(int b, int e) {
      myAssert(b <= e);
      if (b == e) {
        return arr[m + b];
      }
      int ib = m + b;
      int ie = m + e;
      int v = Math.min(arr[ib], arr[ie]);
      int enter = 0;
      while (ib / 2 != ie / 2) {
        myAssert(++enter < 30);
        if (ib % 2 == 0) {
          

          v = Math.min(v, arr[ib + 1]);
        }
        if (ie % 2 == 1) {
          

          v = Math.min(v, arr[ie - 1]);
        }
        ib /= 2;
        ie /= 2;
      }
      return v;
    }
  }

  static long[] id5(int[][] points, int[][] queries) {
    int q = queries.length;
    long[] ans = new long[q];
    Arrays.fill(ans, Long.MAX_VALUE);
    for (int i = 0; i < q; i++) {
      int l = queries[i][0];
      int r = queries[i][1];
      for (int j = l; j < r; j++) {
        for (int k = j + 1; k <= r; k++) {
          ans[i] = Math.min(ans[i],
              (long)(points[k][0] - points[j][0]) * (points[k][1] + points[j][1]));
        }
      }
    }
    return ans;
  }

  public static String trace(int[][] points) {
    StringBuilder sb = new StringBuilder();
    sb.append('{');

    int h = 6;
    int m = points.length;
    for (int i = 0; i < m; i++) {
      if (m > (h << 1)) {
        if (i == h) {
          sb.append(",...");
        }
        if (i >= h && i < m - h) {
          continue;
        }
      }
      if (i > 0) {
        sb.append(',');
      }
      sb.append('{');

      int n = points[i].length;
      for (int j = 0; j < n; j++) {
        

        if (n > (h << 1)) {
          if (j == h) {
            sb.append(",...");
          }
          if (j >= h && j < n - h) {
            continue;
          }
        }

        if (j > 0) {
          sb.append(',');
        }
        sb.append(points[i][j]);
      }
      sb.append('}');
    }
    sb.append('}');
    return sb.toString();
  }

  public static String trace(long[] values) {
    StringBuilder sb = new StringBuilder();
    sb.append('{');

    int h = 20;
    int m = values.length;
    for (int i = 0; i < m; i++) {
      if (m > (h << 1)) {
        if (i == h) {
          sb.append(",...");
        }
        if (i >= h && i < m - h) {
          continue;
        }
      }
      if (i > 0) {
        sb.append(',');
      }
      sb.append(values[i]);
    }
    sb.append('}');
    return sb.toString();
  }

  static void test(int[][] points, int[][] queries) {
    int n = points.length;
    int q = queries.length;
    System.out.format(" points: %s\n", trace(points));
    System.out.format("queries: %s\n", trace(queries));
    long[] ans = solve(points, queries);
    long[] exp = n <= 1000 ? id5(points, queries) : ans;
    System.out.format("    ans: %s\n", trace(ans));
    for (int i = 0; i < q; i++) {
      if (ans[i] != exp[i]) {
        System.out.format("    exp: %s\n", trace(exp));
        System.out.format("  i:%d [%d,%d] ans:%d exp:%d\n",
            i, queries[i][0], queries[i][1], ans[i], exp[i]);
      }
      myAssert(ans[i] == exp[i]);
    }
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();

    for (int t = 0; t < 1; t++) {
      int n = 300000;
      int q = 300000;
      int xmax = 1000000000;
      int wmax = 1000000000;
      int[][] points = new int[n][2];
      TreeSet<Integer> coordinates = new TreeSet<>();
      while (coordinates.size() < n) {
        coordinates.add(RAND.nextInt(xmax * 2) - xmax);
      }
      List<Integer> xs = new ArrayList<>(coordinates);
      for (int i = 0; i < n; i++) {
        points[i][0] = xs.get(i);
        points[i][1] = 1 + RAND.nextInt(wmax);
      }
      int[][] queries = new int[q][2];
      for (int i = 0; i < q; i++) {
        int u = RAND.nextInt(n);
        int v = u;
        while (v == u) {
          v = RAND.nextInt(n);
        }
        queries[i][0] = Math.min(u, v);
        queries[i][1] = Math.max(u, v);
      }
      

      

      test(points, queries);
    }
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int n = in.nextInt();
    int q = in.nextInt();
    int[][] points = new int[n][2];
    for (int i = 0; i < n; i++) {
      points[i][0] = in.nextInt();
      points[i][1] = in.nextInt();
    }
    int[][] queries = new int[q][2];
    for (int i = 0; i < q; i++) {
      queries[i][0] = in.nextInt() - 1;
      queries[i][1] = in.nextInt() - 1;
    }
    long[] ans = solve(points, queries);
    output(ans);
  }

  static void output(long[] ans) {
    StringBuilder sb = new StringBuilder();
    for (long v : ans) {
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
