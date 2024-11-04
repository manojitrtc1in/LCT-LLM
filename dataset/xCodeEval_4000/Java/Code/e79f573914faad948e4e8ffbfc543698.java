






















































































































































import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class C1735E {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static Result solve(int[] d0, int[] d1) {
    int n = d0.length;
    Result r = new Result(n);
    Arrays.sort(d0);
    Arrays.sort(d1);
    List<int[]> dc0 = getValueCounts(d0);
    List<int[]> dc1 = getValueCounts(d1);
    

    

    if (n == 1) {
      r.h[0] = 0;
      r.p0 = d0[0];
      r.p1 = d1[0];
      return r;
    } else {
      

      if (solveBothOutside(d0, d1, r)) {
        return r;
      }

      

      if (solveOneOutside(d0, d1, r)) {
        return r;
      }

      


      

      Map<Integer, int[]> dcm = new HashMap<>();
      for (int[] v : dc1) {
        dcm.computeIfAbsent(v[0], x -> new int[2])[0] += v[1];
      }
      


      

      

      

      


      r.h[0] = 0;
      int p0 = d0[n-1];

      

      


      

      Set<String>[] memos = new HashSet[dc0.size()];
      for (int i = 0; i < dc0.size(); i++) {
        memos[i] = new HashSet<>();
      }

      int m = dc1.size();
      for (int i = 0; i < m; i++) {
        

        

        int p1 = dc1.get(i)[0];
        if (p1 == p0) {
          

          continue;
        }

        {
          

          

          

          long sd2 = 0;
          int p = Math.abs(p1 - p0);
          for (int j = 0; j < dc0.size(); j++) {
            long v = dc0.get(j)[0];
            int k = dc0.get(j)[1];
            sd2 = (sd2 + (v * v % p) * k) % p;
          }
          for (int j = 0; j < dc1.size(); j++) {
            long v = dc1.get(j)[0];
            int k = dc1.get(j)[1];
            sd2 = (sd2 + p - ((v * v % p) * k) % p) % p;
          }
          if (sd2 != 0) {
            

            continue;
          }
        }

        Houses h = new Houses(n);
        boolean ok = isOk(dc0.size() - 1, p0, p1, dcm, dc0, h, memos);
        if (ok) {
          myAssert(h.idx == n);
          r.p0 = p0;
          r.p1 = p1;
          r.h = h.h;
          return r;
        }
      }
      return null;
    }
  }

  private static boolean solveOneOutside(int[] d0, int[] d1, Result r) {
    int n = d0.length;
    if (d1[n-1] <= d0[n-1]) {
      

      

      

      r.p0 = 0;
      for (int i = 0; i < n; i++) {
        r.h[i] = d0[i];
      }
      int x = r.h[0] + d1[n-1];
      if (isOk(r.h, x, d1)) {
        

        

        

        

        r.p1 = x;
        return true;
      }

      int y = r.h[n-1] - d1[n-1];
      if (isOk(r.h, y, d1)) {
        

        

        

        

        r.p1 = y;
        return true;
      }
    } else {
      

      

      

      r.p1 = 0;
      for (int i = 0; i < n; i++) {
        r.h[i] = d1[i];
      }
      int x = r.h[0] + d0[n-1];
      if (isOk(r.h, x, d0)) {
        

        

        

        

        r.p0 = x;
        return true;
      }

      int y = r.h[n-1] - d0[n-1];
      if (isOk(r.h, y, d0)) {
        

        

        

        

        r.p0 = y;
        return true;
      }
    }
    return false;
  }

  private static boolean solveBothOutside(int[] d0, int[] d1, Result r) {
    int n = d0.length;
    if (d1[n-1] <= d0[n-1]) {
      r.p0 = 0;
      for (int i = 0; i < n; i++) {
        r.h[i] = d0[i];
      }
      int x = d0[n-1] - d1[n-1];
      if (isOk(r.h, x, d1)) {
        

        

        

        

        r.p1 = x;
        return true;
      }

      int y = r.h[0] + d1[n-1];
      if (isOk(r.h, y, d1)) {
        

        

        

        r.p1 = y;
        return true;
      }
    } else {
      r.p1 = 0;
      for (int i = 0; i < n; i++) {
        r.h[i] = d1[i];
      }
      int x = d1[n-1] - d0[n-1];
      if (isOk(r.h, x, d0)) {
        

        

        

        

        r.p0 = x;
        return true;
      }

      int y = r.h[0] + d0[n-1];
      if (isOk(r.h, y, d0)) {
        

        

        

        r.p0 = y;
        return true;
      }
    }
    return false;
  }

  

  static List<int[]> getValueCounts(int[] a) {
    TreeMap<Integer, Integer> vcm = new TreeMap<>();
    for (int v : a) {
      vcm.put(v, vcm.getOrDefault(v, 0) + 1);
    }
    List<int[]> ans = new ArrayList<>();
    for (Map.Entry<Integer, Integer> e : vcm.entrySet()) {
      ans.add(new int[] {e.getKey(), e.getValue()});
    }
    return ans;
  }

  static boolean isOk(int[] h, int p, int[] d) {
    int n = h.length;
    boolean ok = true;
    int[] dists = new int[n];
    for (int i = 0; i < n; i++) {
      dists[i] = Math.abs(p - h[i]);
    }
    Arrays.sort(dists);
    for (int i = 0; i < n; i++) {
      if (d[i] != dists[i]) {
        ok = false;
        break;
      }
    }
    

    

    return ok;
  }

  static class Houses {
    int n;
    int idx;
    int[] h;

    public Houses(int n) {
      this.n = n;
      this.idx = 0;
      this.h = new int[n];
    }

    public void add(int x, int cnt) {
      myAssert(idx + cnt <= n);
      for (int i = 0; i < cnt; i++) {
        h[idx++] = x;
      }
    }

    public void pop(int cnt) {
      myAssert(idx - cnt >= 0);
      idx -= cnt;
    }
  }

  

  static boolean isOk(int k, int p0, int p1, Map<Integer, int[]> dcm,
      List<int[]> dc0, Houses h, Set<String>[] memos) {
    int m = dc0.size();
    myAssert(p0 != p1);
    boolean ok = false;
    if (k == -1) {
      return true;
    }
    StringBuilder sb = new StringBuilder();
    sb.append(p1);
    for (int[] e : dcm.values()) {
      if (sb.length() > 0) {
        sb.append('_');
      }
      sb.append(e[1]);
    }
    String key = sb.toString();
    if (memos[k].contains(key)) {
      return false;
    }
    int v = dc0.get(k)[0];
    int cnt = dc0.get(k)[1];
    

    if (v == 0) {
      int x = p0;
      int d = Math.abs(x - p1);
      int[] e = dcm.get(d);
      if (e != null && e[1] + cnt <= e[0]) {
        e[1] += cnt;
        ok = isOk(k-1, p0, p1, dcm, dc0, h, memos);
        

        e[1] -= cnt;
        if (ok) {
          h.add(x, cnt);
        }
      }
    } else {
      for (int l = 0; l <= cnt; l++) {
        int r = cnt - l;
        int xl = p0 - v;
        int xr = p0 + v;
        int dl = Math.abs(xl - p1);
        int dr = Math.abs(xr - p1);
        myAssert(dl != dr);
        int[] el = dcm.get(dl);
        int[] er = dcm.get(dr);
        boolean lok = l == 0 || (el != null && el[1] + l <= el[0]);
        boolean rok = r == 0 || (er != null && er[1] + r <= er[0]);
        if (lok && rok) {
          if (l > 0) {
            el[1] += l;
          }
          if (r > 0) {
            er[1] += r;
          }
          ok = isOk(k-1, p0, p1, dcm, dc0, h, memos);
          if (l > 0) {
            el[1] -= l;
          }
          if (r > 0) {
            er[1] -= r;
          }
          if (ok) {
            h.add(xl, l);
            h.add(xr, r);
            break;
          }
        }
      }
    }
    if (!ok) {
      memos[k].add(key);
    }
    

    return ok;
  }

  static class Result {
    int[] h;
    int p0;
    int p1;

    public Result(int n) {
      h = new int[n];
    }
  }

  static void test(boolean exp, int[] d0, int[] d1) {
    Result ans = test(d0, d1);
    if (exp) {
      myAssert(ans != null);
    } else {
      myAssert(ans == null);
    }
  }

  static Result test(int[] d0, int[] d1) {
    Result ans = solve(d0, d1);
    System.out.format("  d0: %s\n", Arrays.toString(d0));
    System.out.format("  d1: %s\n", Arrays.toString(d1));
    output(ans);
    return ans;
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();

    test(true, new int[] {1,1,1,2,2,2,3,4,4,5}, new int[] {0,1,1,2,2,3,3,4,5,6});
    test(true, new int[] {864,460,161,514,165,768,457,679,528,1},
               new int[] {16,664,150,499,513,849,753,146,445,442});
    test(true, new int[] {0,0,1,2,2,2,3,5,5,6}, new int[] {7,1,4,8,6,1,6,4,3,0});
    test(true, new int[] {1,1,1,2,3,4,4,4,4,5}, new int[] {3,4,2,5,4,4,4,1,1,1});
    test(true, new int[] {14,17,19,16,18,11,12,10,11,16}, new int[] {0,1,4,8,2,1,7,2,6,7});
    test(true, new int[] {6891,10200,13111,18479,19414,28399,31437,75297,77366,115995},
               new int[] {113556,100598,95230,92319,75228,62705,53720,33876,6822,4753});
    test(true, new int[] {0,1,1,1,2,2,3,3,3,5}, new int[] {4,5,7,5,1,1,6,5,7,2});

    test(new int[] {6891,10200,13111,18479,19414,28399,31437,75297,77366,115995},
        new int[] {113556,100598,95230,92319,75228,62705,53720,33876,6822,4753});
    test(new int[] {1}, new int[] {0});
    test(new int[] {0,0,1,1,2,2,3,4,4,4}, new int[] {0,1,1,2,3,3,3,3,4,5});
    test(new int[] {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,3,3,4,4,4,4,4,5,5,5,5,5,5,5,5,5,
             6,6,6,6,6,7,7,8,8,8,8,8,8,8},
         new int[] {6,6,6,6,6,6,6,5,5,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,2,2,2,2,
             2,2,2,2,1,1,1,1,1,0,0,0,0,0});

    test(new int[] {0, 1, 1, 1, 2,2,3, 3, 3, 5}, new int[] {4, 5, 7, 5, 1, 1, 6, 5, 7, 2});
    test(new int[] {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
         new int[] {2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});

    test(new int[] {826,938,1069,5322,5328,7583,7606,8882,12873,18755,19023,20914,22447,23845,
        24418,26021,27968,36930,39866,43070,45236,55318,56051,60971,71356,73979,78166,87190,
        87566,88456,88643,94326,96991,97154,101588,102617,103252,106868,109394,112134,113167,
        116214,119709,123381,134827,140602,147995,151176,151420,151634},
         new int[] {111255,111041,110797,107616,100223,94448,83002,79330,75835,72788,71755,
             69015,66489,62873,62238,61209,56775,56612,53947,48264,48077,47985,47187,46811,
             39553,39441,39310,37787,35057,35051,33600,32796,31497,30977,27506,21624,21356,
             20592,19465,17932,16534,15961,15672,14939,14358,12411,4857,3449,2691,513});
    test(new int[] {3040,3735,6703,9550,9928,14013,14077,14878,17810,18376,21044,21248,23242,
        24993,26036,29038,29780,29945,31874,33521,33529,34351,35808,36549,37153,45858,46707,
        50629,52074,52733,55997,57106,57910,58302,58826,60834,62621,63823,65155,75531,76858,
        78310,78809,82686,83584,83950,86496,97530,102308,103066},
        new int[] {181,197,4330,6012,8063,11297,11501,12787,16289,16450,20033,23760,24604,24625,
            26061,26802,28123,32989,34740,38785,39692,40882,41621,42327,42986,43268,43276,46900,
            48555,49079,51087,52874,55408,55605,56454,65744,65784,66853,67111,67657,68563,69062,
            72939,73570,73837,74203,76749,87783,92561,93319});
    test(new int[] {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,3,3,4,4,4,4,4,5,5,5,5,5,5,5,5,5,6,6,6,6,6,7,7,8,8,8,8,8,8,8},
         new int[] {6,6,6,6,6,6,6,5,5,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,0,0,0,0,0});

    {
      int n = 1000;
      int[] d0 = new int[n];
      int[] d1 = new int[n];
      for (int i = 0; i < n; i++) {
        d0[i] = RAND.nextInt(20);
        d1[i] = RAND.nextInt(20);
      }
      test(d0, d1);
    }
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int n = in.nextInt();
      int[] d0 = new int[n];
      for (int i = 0; i < n; i++) {
        d0[i] = in.nextInt();
      }
      int[] d1 = new int[n];
      for (int i = 0; i < n; i++) {
        d1[i] = in.nextInt();
      }
      Result ans = solve(d0,d1);
      output(ans);
    }
  }

  static String traceData(int[] a) {
    StringBuilder sb = new StringBuilder();
    for (int v : a) {
      if (sb.length() > 0) {
        sb.append('_');
      }
      sb.append(v);
    }
    return sb.toString();
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

  static void output(Result a) {
    if (a == null) {
      System.out.println("NO");
      return;
    }
    StringBuilder sb = new StringBuilder();
    sb.append("YES\n");

    for (int v : a.h) {
      sb.append(v);
      sb.append(' ');
    }
    sb.append('\n');
    sb.append(a.p0);
    sb.append(' ');
    sb.append(a.p1);
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
