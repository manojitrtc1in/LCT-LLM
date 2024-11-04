










































































































































import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.Arrays;
import java.util.Map;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class id0 {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  

  static int[] solve(int[] a, int[][] updates) {
    int n = a.length;
    int q = updates.length;

    int maxv = a[0];
    for (int v : a) {
      maxv = Math.max(maxv, v);
    }
    for (int[] v : updates) {
      maxv = Math.max(maxv, v[1]);
    }

    int m = maxv + 20;
    int[] cts = new int[m];
    for (int v : a) {
      cts[v]++;
    }

    for (int i = 1; i < m - 1; i++) {
      cts[i+1] += cts[i] / 2;
      cts[i] = cts[i] % 2;
    }
    


    

    TreeMap<Integer, Integer> bm = new TreeMap<>();
    {
      int b = 0;
      while (b < m) {
        while (b < m && cts[b] == 0) {
          b++;
        }
        if (b >= m) {
          break;
        }
        int e = b + 1;
        while (cts[e] > 0) {
          e++;
        }
        bm.put(b, e - 1);
        b = e;
      }
      

    }
    


    int[] ans = new int[q];
    for (int i = 0; i < q; i++) {
      int k = updates[i][0];
      int l = updates[i][1];
      int v = a[k];
      

      a[k] = l;
      


      remove(bm, v);
      add(bm, l);
      ans[i] = bm.lastEntry().getValue();

      if (test) {
        int prev = -2;
        for (Map.Entry<Integer,Integer> e : bm.entrySet()) {
          myAssert(e.getKey() > prev + 1);
          myAssert(e.getKey() <= e.getValue());
          prev = e.getValue();
        }
        int exp = id1(a);
        if (exp != ans[i]) {
          System.out.format("  exp:%d ans:%d %s\n", exp, ans[i], Arrays.toString(a));
        }
        myAssert(exp == ans[i]);
      }
    }
    return ans;
  }

  private static void remove(TreeMap<Integer, Integer> bm, int v) {
    Map.Entry<Integer, Integer> fe = bm.floorEntry(v);
    if (fe != null && v <= fe.getValue()) {
      int b = fe.getKey();
      int e = fe.getValue();
      myAssert(b <= v && v <= e);
      

      

      bm.remove(b);
      if (v > b) {
        bm.put(b, v-1);
      }
      if (v < e) {
        bm.put(v + 1, e);
      }
    } else {
      Map.Entry<Integer, Integer> ce = bm.ceilingEntry(v);
      myAssert(ce != null);
      int b = ce.getKey();
      int e = ce.getValue();
      

      

      bm.remove(b);
      if (e > b) {
        bm.put(b + 1, e);
      }
      

      while (true) {
        fe = bm.floorEntry(v - 1);
        if (fe == null || fe.getValue() < v - 1) {
          break;
        }
        v = fe.getKey();
      }
      bm.put(v, b-1);
    }
    

  }

  private static void add(TreeMap<Integer, Integer> bm, int l) {
    Map.Entry<Integer, Integer> fe = bm.floorEntry(l);
    Map.Entry<Integer, Integer> ce = bm.ceilingEntry(l);
    if (fe == null || fe.getValue() < l - 1) {
      

      if (ce == null) {
        bm.put(l, l);
      } else if (ce.getKey() == l + 1) {
        

        int e = ce.getValue();
        bm.remove(l + 1);
        bm.put(l, e);
      } else {
        myAssert(ce.getKey() > l + 1);
        bm.put(l, l);
      }
    } else if (fe.getValue() == l - 1) {
      int b = fe.getKey();
      int e = l;
      bm.remove(b);
      if (bm.containsKey(l + 1)) {
        e = bm.get(l + 1);
        bm.remove(l + 1);
      }
      bm.put(b, e);
    } else {
      int b = fe.getKey();
      int e = fe.getValue();
      bm.remove(b);
      

      

      

      if (b <= l - 1) {
        bm.put(b, l - 1);
      }
      

      b = e + 1;
      e = e + 1;
      if (bm.containsKey(b + 1)) {
        e = bm.get(b + 1);
        bm.remove(b + 1);
      }
      bm.put(b, e);
    }
    

  }

  static int id1(int[] a) {
    int n = a.length;
    int maxv = a[0];
    for (int v : a) {
      maxv = Math.max(maxv, v);
    }
    int m = maxv + 20;
    int[] cts = new int[m];
    for (int v : a) {
      cts[v]++;
    }
    System.out.format("    cts: %s\n", Arrays.toString(cts));
    int ans = 0;
    for (int i = 1; i < m - 1; i++) {
      cts[i+1] += cts[i] / 2;
      cts[i] = cts[i] % 2;
      if (cts[i] > 0) {
        ans = i;
      }
    }
    System.out.format("    cts: %s\n", Arrays.toString(cts));
    return ans;
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    int[] a = {4, 8, 11, 10, 3, 5, 10, 3, 10, 10, 11, 1};
    
    int n = a.length;
    int q = 16;
    int[][] updates = new int[q][2];
    for (int i = 0; i < q; i++) {
      updates[i][0] = RAND.nextInt(n);
      updates[i][1] = 1 + RAND.nextInt(12);
    }
    System.out.format("              %s\n", Arrays.toString(a));
    updates = new int[][] {{8,5},{0,7},{1,9},{11,12},{8,8},{10,6},{5,1},{4,7},{9,9},{6,12},{0,3},{5,3},{2,8},{5,5},{7,8},{0,2}};
    System.out.format("  %s\n", tracePairs(updates));
    int[] ans = solve(a, updates);
    output(ans);
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static String tracePairs(int[][] pairs) {
    StringBuilder sb = new StringBuilder();
    sb.append('{');
    for (int[] e : pairs) {
      if (sb.length() > 1) {
        sb.append(',');
      }
      sb.append('{');
      sb.append(e[0]);
      sb.append(',');
      sb.append(e[1]);
      sb.append('}');
    }
    sb.append('}');
    return sb.toString();
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int n = in.nextInt();
    int q = in.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = in.nextInt();
    }
    int[][] updates = new int[q][2];
    for (int i = 0; i < q; i++) {
      updates[i][0] = in.nextInt() - 1;
      updates[i][1] = in.nextInt();
    }
    int[] ans = solve(a, updates);
    output(ans);
  }

  static void output(int[] a) {
    StringBuilder sb = new StringBuilder();
    for (int v : a) {
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
