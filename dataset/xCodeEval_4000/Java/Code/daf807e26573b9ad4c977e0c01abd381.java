




















































































































import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class C1759G {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static int[] solve(int[] b) {
    int m = b.length;
    int n = m * 2;
    {
      int[] c = new int[m];
      System.arraycopy(b, 0, c, 0, m);
      sort(c);
      for (int i = 0; i < m; i++) {
        if (c[i] < 2 * (i+1)) {
          return null;
        }
        if (i > 0 && c[i] == c[i-1]) {
          return null;
        }
      }
    }

    boolean[] used = new boolean[n+1];
    for (int i = 0; i < m; i++) {
      used[b[i]] = true;
    }

    int[] ans = new int[n];
    for (int i = 0; i < m; i++) {
      ans[2 * i + 1] = b[i];
    }

    

    int[] da = new int[n+1];
    for (int i = 1; i <= n; i++) {
      da[i] = da[i-1] + (used[i] ? -1 : 1);
    }
    if (test) {
      System.out.format("  da:%s\n", Arrays.toString(da));
    }

    TreeSet<Integer> aval = new TreeSet<>();
    for (int i = 1; i <= n; i++) {
      if (!used[i]) {
        aval.add(i);
      }
    }
    if (test) {
      System.out.format("  aval:%s\n", aval.toString());
    }

    LazyRangeMinIndexSegmentTree st = new LazyRangeMinIndexSegmentTree(da);
    for (int i = 0; i < m; i++) {
      int v = b[i];
      

      int[] ret = st.getRangeMin(1, v-1);
      if (test) System.out.format("    i:%d v:%d ret:%s\n", i, v, Arrays.toString(ret));
      int idx = ret[0] == 0 ? ret[2] : ret[1];
      if (!aval.contains(idx)) {
        idx = aval.ceiling(idx);
      }
      if (test) {
        System.out.format("  i:%d v:%2d minv:%d idx:%d\n", i, v, ret[0], idx);
      }
      ans[2 * i] = idx;
      if (idx + 1 <= v - 1) {
        st.updateRange(idx + 1, v - 1, -1);
      }
      st.set(idx, n);
      st.set(v, n);
      used[idx] = true;
      aval.remove(idx);
    }
    return ans;
  }

  public static void sort(int[] arr) {
    for (int i = 0; i < arr.length; i++) {
      int r = RAND.nextInt(arr.length);
      int temp = arr[i];
      arr[i] = arr[r];
      arr[r] = temp;
    }
    Arrays.sort(arr);
  }

  static class LazyRangeMinIndexSegmentTree {
    int n;
    int[][] tree;
    int[] lazy;

    LazyRangeMinIndexSegmentTree(int[] arr) {
      this.n = arr.length;
      int m = nextPowerOf2(n);
      

      this.tree = new int[m * 2 - 1][3];
      this.lazy = new int[m * 2 - 1];
      constructSegTree(arr, 0, n - 1, 0);
    }

    void constructSegTree(int arr[], int lo, int hi, int idx) {
      if (lo > hi) {
        return;
      }
      if (lo == hi) {
        tree[idx][0] = arr[lo];
        tree[idx][1] = lo;
        tree[idx][2] = lo;
        return;
      }
      int mid = (lo + hi) / 2;
      constructSegTree(arr, lo, mid, idx * 2 + 1);
      constructSegTree(arr, mid + 1, hi, idx * 2 + 2);
      aggregateChildren(idx);
    }

    

    public void updateRange(int b, int e, int inc)  {
      if (b > e) {
        return;
      }
      updateRangeInner(0, 0, n - 1, b, e, inc);
    }

    

    public void set(int index, int value)  {
      checkIndex(index);
      int[] vcurr = getRangeMin(index, index);
      int inc = value - vcurr[0];
      updateRange(index, index, inc);
    }

    

    public int getAt(int index) {
      checkIndex(index);
      int[] ret = getRangeMin(0, 0, n - 1, index, index);
      return ret[0];
    }

    private void checkIndex(int index) {
      if (index < 0 || index >= n) {
        throw new RuntimeException("Invalid index " + index);
      }
    }

    

    public int[] getRangeMin(int b, int e) {
      if (b < 0 || e > n - 1 || b > e) {
        return new int[] {Integer.MAX_VALUE, -1};
      }
      return getRangeMin(0, 0, n - 1, b, e);
    }

    private void updateRangeInner(int idx, int lo, int hi, int b, int e, int inc) {
      if (lazy[idx] != 0) {
        tree[idx][0] += lazy[idx];
        if (lo != hi) {
          lazy[idx * 2 + 1] += lazy[idx];
          lazy[idx * 2 + 2] += lazy[idx];
        }
        lazy[idx] = 0;
      }
      if (lo > hi || lo > e || hi < b) {
        return;
      }
      if (lo >= b && hi <= e) {
        tree[idx][0] += inc;
        if (lo != hi) {
          lazy[idx * 2 + 1] += inc;
          lazy[idx * 2 + 2] += inc;
        }
        return;
      }
      int mid = (lo + hi) / 2;
      updateRangeInner(idx * 2 + 1, lo, mid, b, e, inc);
      updateRangeInner(idx * 2 + 2, mid + 1, hi, b, e, inc);
      aggregateChildren(idx);
    }

    

    private void aggregateChildren(int idx) {
      if (tree[idx * 2 + 1][0] < tree[idx * 2 + 2][0]) {
        tree[idx][0] = tree[idx * 2 + 1][0];
        tree[idx][1] = tree[idx * 2 + 1][1];
        tree[idx][2] = tree[idx * 2 + 1][2];
      } else if (tree[idx * 2 + 1][0] == tree[idx * 2 + 2][0]) {
        tree[idx][0] = tree[idx * 2 + 1][0];
        tree[idx][1] = tree[idx * 2 + 1][1];
        tree[idx][2] = tree[idx * 2 + 2][2];
      } else {
        tree[idx][0] = tree[idx * 2 + 2][0];
        tree[idx][1] = tree[idx * 2 + 2][1];
        tree[idx][2] = tree[idx * 2 + 2][2];
      }
    }

    private int[] getRangeMin(int idx, int lo, int hi, int b, int e) {
      if (lazy[idx] != 0) {
        tree[idx][0] += lazy[idx];
        if (lo != hi) {
          lazy[idx * 2 + 1] += lazy[idx];
          lazy[idx * 2 + 2] += lazy[idx];
        }
        lazy[idx] = 0;
      }
      if (lo > hi || lo > e || hi < b) {
        return new int[] {Integer.MAX_VALUE, -1};
      }
      if (lo >= b && hi <= e) {
        return tree[idx];
      }
      int mid = (lo + hi) / 2;
      int[] l = getRangeMin(2 * idx + 1, lo, mid, b, e);
      int[] r = getRangeMin(2 * idx + 2, mid + 1, hi, b, e);
      if (l[0] < r[0]) {
        return l;
      } else if (l[0] == r[0]) {
        return new int[] {l[0], l[1], r[2]};
      } else {
        return r;
      }
    }

    public static int nextPowerOf2(int num){
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

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    for (int t = 0; t < 1; t++) {
      int m = 5;
      int n = 2 * m;
      int[] a = getRandomPerm(n);
      a = new int[] {1, 4, 2, 6, 3, 5};
      n = a.length;
      m = n / 2;
      System.out.format("  arr:%s\n", Arrays.toString(a));

      int[] b = new int[m];
      for (int i = 0; i < m; i++) {
        b[i] = Math.max(a[2*i], a[2*i+1]);
      }
      System.out.format("  brr:%s\n", Arrays.toString(b));
      int[] ans = solve(b);
      System.out.format("  ans:%s\n", Arrays.toString(ans));
      myAssert(ans != null);
      myAssert(compare(ans, a) <= 0);
    }
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  static int[] getRandomPerm(int n) {
    List<Integer> nums = new ArrayList<>();
    for (int i = 1; i <= n; i++) {
      nums.add(i);
    }
    Collections.shuffle(nums);
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) {
      arr[i] = nums.get(i);
    }
    return arr;
  }

  static int compare(int[] a, int[] b) {
    int m = a.length;
    myAssert(a.length == b.length);
    for (int i = 0; i < m; i++) {
      if (a[i] < b[i]) {
        return -1;
      } else if (a[i] > b[i]) {
        return 1;
      }
    }
    return 0;
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int n = in.nextInt();
      int m = n / 2;
      int[] b = new int[m];
      for (int i = 0; i < m; i++) {
        b[i] = in.nextInt();
      }
      int[] ans = solve(b);
      output(ans);
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
