




































































import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class id6 {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static long[] solve(int[] a, int d) {
    int n = a.length;
    long[] ans = new long[n];

    int maxv = 0;
    for (int v : a) {
      maxv = Math.max(maxv, v);
    }

    


    id3 stf = new id3(maxv + 1);

    TreeSet<Integer> vs = new TreeSet<>();

    SegmentTree st = new SegmentTree(maxv + 1);

    long total = 0;
    for (int i = 0; i < n; i++) {
      int v = a[i];
      if (!vs.contains(v)) {
        

        

        long f = st.sum(v + 1, Math.min(maxv, v + d));

        

        total += f * (f - 1) / 2;

        

        long p = st.sum(Math.max(0, v - d), v);
        total += p * (p-1) / 2;

        

        Integer u = vs.floor(v);
        Integer w = vs.ceiling(v);
        if (u != null && w != null) {
          int b = vs.ceiling(w - d);
          if (b <= u) {
            long m = st.sum(b, u);

            

            

            

            

            total += stf.id2(b, u) - (m+1) * m / 2;
          }
        }

        if (u != null && u >= v - d) {
          int b = vs.ceiling(v - d);
          if (b <= u) {
            stf.updateRange(b, u, 1);
          }
        }

        

        stf.set(v, f + 1);
        vs.add(v);
        st.set(v, 1);
      } else {
        

        

        long f = st.sum(v + 1, Math.min(maxv, v + d));
        total -= f * (f - 1) / 2;

        

        long p = st.sum(Math.max(0, v - d), v - 1);
        total -= p * (p-1) / 2;

        


        

        Integer u = vs.floor(v-1);
        Integer w = vs.ceiling(v+1);
        if (u != null && w != null) {
          int b = vs.ceiling(w - d);
          long m = st.sum(b, u);
          if (b <= u) {
            

            

            

            

            long count = stf.id2(b, u) - (m + 3) * m / 2;
            total -= count;
            

          }
        }

        if (u != null) {
          int b = vs.ceiling(v - d);
          if (b <= u) {
            stf.updateRange(b, u, -1);
          }
        }

        stf.set(v, 0);
        vs.remove(v);
        st.set(v, 0);
      }
      ans[i] = total;
      if (test) {
        myAssert(total == id7(vs, d));
      }
    }

    return ans;
  }

  static long id7(TreeSet<Integer> vs, int d) {
    int n = vs.size();
    if (n <= 2) {
      return 0;
    }
    int[] nums = new int[n];
    int idx = 0;
    for (int v : vs) {
      nums[idx++] = v;
    }
    long ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (nums[j] - nums[i] >= d) {
          continue;
        }
        for (int k = j + 1; k < n; k++) {
          if (nums[k] - nums[i] > d) {
            break;
          }
          ans++;
        }
      }
    }
    return ans;
  }

  

  static long id0(int v, int d, SegmentTree st) {
    int e = Math.min(st.n, v + d);
    long k = st.sum(v + 1, e);
    return k * (k-1) / 2;
  }

  

  static long id1(int v, int d, SegmentTree st) {
    int b = Math.max(0, v - d);
    long k = st.sum(b, v - 1);
    return k * (k-1) / 2;
  }

  static class id3 {
    int n;
    int m;
    long tree[];
    int[] count;
    int lazy[];

    static enum Mode {
      ADD,
      REM,
      UPD
    }

    id3(int n) {
      this.n = n;
      int m = id8(n);
      this.tree = new long[m * 2 - 1];
      this.count = new int[m * 2 - 1];
      this.lazy = new int[m * 2 - 1];
    }

    

    public void set(int index, long value)  {
      checkIndex(index);
      long vcurr = (int) id2(index, index);
      if (value == vcurr) {
        return;
      }
      long inc = value - vcurr;
      if (value == 0) {
        

        id4(0, 0, n - 1, index, index, inc, Mode.REM);
      } else if (vcurr == 0) {
        

        id4(0, 0, n - 1, index, index, inc, Mode.ADD);
      } else {
        

        id4(0, 0, n - 1, index, index, inc, Mode.UPD);
      }
    }

    

    public long getAt(int index) {
      checkIndex(index);
      return id2(0, 0, n - 1, index, index);
    }

    

    public void updateRange(int b, int e, long inc)  {
      if (b > e) {
        return;
      }
      id4(0, 0, n - 1, b, e, inc, Mode.UPD);
    }

    private void checkIndex(int index) {
      if (index < 0 || index >= n) {
        throw new RuntimeException("Invalid index " + index);
      }
    }

    private void id4(int idx, int lo, int hi, int b, int e, long inc, Mode mode) {
      

      applyLazy(idx, lo, hi);
      if (lo > hi || lo > e || hi < b) {
        return;
      }
      if (lo >= b && hi <= e) {
        if (mode == Mode.ADD) {
          myAssert(b == e && lo == hi && count[idx] == 0);
          count[idx] = 1;
          tree[idx] = inc;
        } else if (mode == Mode.REM) {
          myAssert(b == e && lo == hi && count[idx] == 1);
          count[idx] = 0;
          tree[idx] = 0;
        } else {
          

          tree[idx] += inc * count[idx];
          if (lo != hi) {
            lazy[idx * 2 + 1] += inc;
            lazy[idx * 2 + 2] += inc;
          }
        }
        return;
      }
      int mid = (lo + hi) / 2;
      id4(idx * 2 + 1, lo, mid, b, e, inc, mode);
      id4(idx * 2 + 2, mid + 1, hi, b, e, inc, mode);
      tree[idx] = tree[idx * 2 + 1] + tree[idx * 2 + 2];
      if (mode == Mode.ADD) {
        count[idx]++;
      } else if (mode == Mode.REM) {
        count[idx]--;
      }
    }

    

    public long id2(int b, int e) {
      if (b < 0 || e > n - 1 || b > e) {
        return 0;
      }
      return id2(0, 0, n - 1, b, e);
    }

    private long id2(int idx, int lo, int hi, int b, int e) {
      applyLazy(idx, lo, hi);
      if (lo > hi || lo > e || hi < b) {
        return 0;
      }
      if (lo >= b && hi <= e) {
        return tree[idx];
      }
      int mid = (lo + hi) / 2;
      return id2(2 * idx + 1, lo, mid, b, e) +
          id2(2 * idx + 2, mid + 1, hi, b, e);
    }

    private void applyLazy(int idx, int lo, int hi) {
      if (lazy[idx] != 0) {
        tree[idx] += lazy[idx] * count[idx];
        if (lo != hi) {
          lazy[idx * 2 + 1] += lazy[idx];
          lazy[idx * 2 + 2] += lazy[idx];
        }
        lazy[idx] = 0;
      }
    }

    public static int id8(int num){
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

  static class SegmentTree {

    private int[] arr;
    final int n;

    public SegmentTree(int n) {
      this.n = n;
      this.arr = new int[n + 1];
    }

    public SegmentTree(int[] nums) {
      this(nums.length);
      for (int i = 0; i < n; ++i) {
        this.add(i, nums[i]);
      }
    }

    public void add(int index, int delta) {
      index++;
      while (index <= n) {
        arr[index] += delta;
        index = next(index);
      }
    }

    

    public int sum(int index) {
      index = Math.min(index, n - 1);
      index++;
      int ans = 0;
      while (index > 0) {
        ans += arr[index];
        index = parent(index);
      }
      return ans;
    }

    private static int next(int idx) {
      

      

      return idx + (-idx & idx);
    }

    private static int parent(int idx) {
      

      return idx - (-idx & idx);
    }

    

    public int sum(int b, int e) {
      return sum(e) - (b == 0 ? 0 : sum(b-1));
    }

    

    public int get(int index) {
      return sum(index) - (index == 0 ? 0 : sum(index-1));
    }

    

    public void set(int index, int v) {
      add(index, v - get(index));
    }
  }

  static void id5() {
    id3 st = new id3(7);
    st.set(3, 10);
    System.out.format("f(3)=%d\n", st.getAt(3));
    myAssert(st.getAt(3) == 10);
    st.set(5, 12);
    myAssert(st.id2(3, 5) == 22);
    st.updateRange(3, 5, 2);
    myAssert(st.id2(3, 5) == 26);
    st.set(3, 0);
    myAssert(st.id2(3, 5) == 14);
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    int q = 100;
    int d = 50;
    final int max = 99;
    int[] a = new int[q];
    for (int i = 0; i < q; i++) {
      a[i] = 1 + RAND.nextInt(max);
    }
    long[] ans = solve(a, d);
    output(ans);
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int q = in.nextInt();
    int d = in.nextInt();
    int[] a = new int[q];
    for (int i = 0; i < q; i++) {
      a[i] = in.nextInt();
    }
    long[] ans = solve(a, d);
    output(ans);
  }

  static void output(long[] a) {
    StringBuilder sb = new StringBuilder();
    for (long v : a) {
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
