














































































































import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class id2 {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  

  static String solve(int[][] rains, int m) {
    int n = rains.length;
    int[] xx = new int[n];
    int[] pp = new int[n];
    int[] xa = new int[n * 3];
    for (int i = 0; i < n; i++) {
      int x = xx[i] = rains[i][0];
      int p = pp[i] = rains[i][1];
      

      xa[i * 3 + 0] = x - p;
      xa[i * 3 + 1] = x;
      xa[i * 3 + 2] = x + p;
    }

    

    xa = Arrays.stream(xa).boxed().sorted().mapToInt($->$).toArray();
    int k = 1;
    for (int i = 1; i < n * 3; i++) {
      if (xa[i] != xa[i - 1]) {
        xa[k++] = xa[i];
      }
    }
    


    

    int[] ll = new int[n];
    int[] rr = new int[n];
    for (int i = 0; i < n; i++) {
      int b = xx[i] - pp[i];
      int e = xx[i] + pp[i];
      ll[i] = search(xa, k, b);
      rr[i] = search(xa, k, e);
      xx[i] = search(xa, k, xx[i]);
    }

    

    int[] ss = new int[k];
    for (int i = 0; i < n; i++) {
      ss[ll[i]]++;
      ss[xx[i]] -= 2;
      ss[rr[i]]++;
    }

    

    long[] yy = new long[k];
    long[] yp = new long[k];
    long[] ym = new long[k];
    for (int s = ss[0], i = 1; i < k; s += ss[i++]) {
      

      long x = xa[i] - xa[i - 1];
      yy[i] = yy[i - 1] + x * s;
      yp[i] = yp[i - 1] + x * (s + 1);
      ym[i] = ym[i - 1] + x * (s - 1);
    }
    

    

    


    

    int[] styy = build(yy, k);
    int[] styp = build(yp, k);
    int[] stym = build(ym, k);

    char[] ans = new char[n];
    for (int h = 0; h < n; h++) {
      int l = ll[h];
      int r = rr[h];
      int x = xx[h];
      

      

      

      

      

      

      int i = query(yy, styy, 0, l);
      int j = query(yy, styy, r, k - 1);
      long y = Math.max(yy[i], yy[j]);
      

      i = query(ym, stym, l, x);
      y = Math.max(y, yy[i] - (xa[i] - xa[l]));
      

      i = query(yp, styp, x, r);
      y = Math.max(y, yy[i] + (xa[i] - xa[r]));
      ans[h] = y <= m ? '1' : '0';
    }
    return new String(ans);
  }

  static int search(int[] aa, int n, int a) {
    int lower = 0, upper = n;
    while (upper - lower > 1) {
      int i = (lower + upper) / 2;
      if (aa[i] <= a) {
        lower = i;
      } else {
        upper = i;
      }
    }
    return lower;
  }

  static int[] build(long[] aa, int k) {
    int[] st = new int[k * 2];
    for (int i = 0; i < k; i++) {
      st[k + i] = i;
    }
    for (int i = k - 1; i > 0; i--) {
      int u = st[i << 1];
      int v = st[i << 1 | 1];
      st[i] = aa[u] > aa[v] ? u : v;
    }
    return st;
  }

  static int query(long[] aa, int[] st, int l, int r) {
    int k = aa.length;
    int i = -1;
    for (l += k, r += k; l <= r; l >>= 1, r >>= 1) {
      if ((l & 1) == 1) {
        int j = st[l++];
        if (i == -1 || aa[i] < aa[j]) {
          i = j;
        }
      }
      if ((r & 1) == 0) {
        int j = st[r--];
        if (i == -1 || aa[i] < aa[j]) {
          i = j;
        }
      }
    }
    return i;
  }

  

  

  

  

  

  

  static String solveA(int[][] rains, int m) {
    int n = rains.length;
    char[] ans = new char[n];
    Arrays.fill(ans, '0');

    TreeSet<Integer> positions = new TreeSet<>();
    for (int[] v : rains) {
      positions.add(v[0]);
    }
    int k = positions.size();
    int[] pos = new int[k];
    TreeMap<Integer, Integer> pim = new TreeMap<>();
    {
      int idx = 0;
      for (int v : positions) {
        pos[idx++] = v;
      }
      for (int i = 0; i < k; i++) {
        pim.put(pos[i], i);
      }
    }

    

    List<int[]> ra = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      int x = rains[i][0];
      int p = rains[i][1];
      ra.add(new int[] {x, p, x - p, x + p, i});
    }
    Collections.sort(ra, (x,y)->x[0] - y[0]);
    


    

    long[] presum = new long[n];
    {
      

      PriorityQueue<int[]> pq = new PriorityQueue<>((x,y)->x[3] - y[3]);
      long sum = 0;
      for (int i = 0; i < n; i++) {
        if (i > 0) {
          long curr = ra.get(i)[0];
          long prev = ra.get(i-1)[0];
          while (!pq.isEmpty() && pq.peek()[3] <= curr) {
            int[] v = pq.poll();
            sum -= v[3] - prev;
          }
          sum -= pq.size() * (curr - prev);
          myAssert(sum >= 0);
        }
        pq.add(ra.get(i));
        sum += ra.get(i)[1];
        presum[i] = sum;
      }
      

    }
    long[] id0 = new long[n];
    {
      

      PriorityQueue<int[]> pq = new PriorityQueue<>((x,y)->y[2] - x[2]);
      long sum = 0;
      for (int i = n-1; i >= 0; i--) {
        if (i < n-1) {
          long curr = ra.get(i)[0];
          long prev = ra.get(i+1)[0];
          while (!pq.isEmpty() && pq.peek()[2] >= curr) {
            int[] v = pq.poll();
            sum -= prev - v[2];
          }
          sum -= pq.size() * (prev - curr);
          myAssert(sum >= 0);
        }
        pq.add(ra.get(i));
        sum += ra.get(i)[1];
        id0[i] = sum;
      }
      

    }

    

    long[] ha = new long[k];
    for (int i = 0; i < n; i++) {
      int x = ra.get(i)[0];
      int idx = pim.get(x);
      ha[idx] = Math.max(ha[idx], presum[i] + id0[i] - ra.get(i)[1]);
    }

    id1 st = new id1(ha);

    List<long[]> peaks = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      long h = presum[i] + id0[i] - ra.get(i)[1];
      peaks.add(new long[] {h, ra.get(i)[0]});
    }
    Collections.sort(peaks, (x,y)->Long.compare(y[0], x[0]));
    


    for (int i = 0; i < n; i++) {
      int x = rains[i][0];
      int p = rains[i][1];
      int ii = pim.get(x);
      if (st.id3(0, k-1) > m + p) {
        continue;
      }

      

      

      int ib = pim.get(x);
      int ie = pim.get(x);
      int b = x - p + 1;
      int e = x + p - 1;
      {
        Map.Entry<Integer, Integer> ce = pim.ceilingEntry(b);
        myAssert(ce != null);
        ib = ce.getValue();
      }
      {
        Map.Entry<Integer, Integer> fe = pim.floorEntry(e);
        myAssert(fe != null);
        ie = fe.getValue();
      }
      


      if (ib > 0 && st.id3(0, ib - 1) > m) {
        continue;
      }
      if (ie + 1 < k && st.id3(ie + 1, k-1) > m) {
        continue;
      }

      boolean ok = true;
      if (ie - ib >= 5000) {
        for (int l = 0; l < 200; l++) {
          int j = ib + RAND.nextInt(ie - ib + 1);
          int xj = pos[j];
          long h = ha[j] - p + Math.abs(xj - x);
          if (h > m) {
            ok = false;
            break;
          }
        }
      } else {
        for (int j = ib; ok && j <= ie; j++) {
          int xj = pos[j];
          long h = ha[j] - p + Math.abs(xj - x);
          if (h > m) {
            ok = false;
            break;
          }
        }
      }
      if (ok) {
        ans[i] = '1';
      }
    }
    return new String(ans);
  }

  static class id1 {
    int m;

    long[] arr;

    public id1(int n) {
      

      this.m = 1;
      while (m < n) {
        m <<= 1;
      }
      arr = new long[m * 2];
    }

    public id1(long[] nums) {
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
        arr[i] = Math.max(arr[2 * i], arr[2 * i + 1]);
        i /= 2;
      }
    }

    public void add(int index, long increment) {
      set(index, get(index) + increment);
    }

    

    

    

    

    

    

    

    

    public long id3(int b, int e) {
      if (b == e) {
        return arr[m + b];
      }
      int ib = m + b;
      int ie = m + e;
      long v = Math.max(arr[ib], arr[ie]);
      while (ib / 2 != ie / 2) {
        if (ib % 2 == 0) {
          

          v = Math.max(v, arr[ib + 1]);
        }
        if (ie % 2 == 1) {
          

          v = Math.max(v, arr[ie - 1]);
        }
        ib /= 2;
        ie /= 2;
      }
      return v;
    }
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int n = in.nextInt();
      int m = in.nextInt();
      int[][] rains = new int[n][2];
      for (int i = 0; i < n; i++) {
        

        rains[i][0] = in.nextInt();
        rains[i][1] = in.nextInt();
      }
      String ans = solve(rains, m);
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
