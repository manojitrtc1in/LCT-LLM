






















































































































import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class id1 {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  

  static long[] solve(int n, int[] pa) {
    int q = pa.length;
    long[] ans = new long[q+1];

    final int mf = 400044;

    int[] lmb = new int[mf];
    long sum = 0;
    for (int i = 1; n > 0; i++) {
      int mx = (i+1)/2;
      lmb[i-1]++;
      if (n < mx) {
        lmb[i-2*n-1]--;
        sum += n * i;
        n = 0;
      } else{
        sum += mx * i;
        n -= mx;
      }
    }
    ans[0] = sum;


    for (int i = mf-3; i >= 0; i--) {
      lmb[i] += lmb[i+2];
    }

    int st = 0;
    int mz = 0;
    for (int i = 0; i < q; i++) {
      int pi = pa[i];

      while (mz + lmb[st] + lmb[st] - 1 < pi) {
        mz += lmb[st];
        st++;
      }
      pi -= mz;

      int cz = 0;
      while (pi % 2 == 0) {
        cz++;
        pi >>= 1;
      }
      pi >>= 1;
      ans[i+1] = st + cz + 2*pi + 1;
    }
    return ans;
  }

  

  static long[] solveA(int n, int[] pa) {
    int q = pa.length;
    long[] ans = new long[q+1];
    

    

    

    


    

    

    

    

    

    

    TreeMap<Integer, long[]> ivsm = new TreeMap<>();
    {
      int idx = 0;
      long v = 1;
      long sum = 0;
      while (idx <= n) {
        ivsm.put(idx, new long[] {v, sum});
        

        long cnt = (v+1)/2;
        idx += cnt;
        sum += v * cnt;
        v++;
      }
    }

    {
      Map.Entry<Integer, long[]> fe = ivsm.floorEntry(n);
      int idx = fe.getKey();
      long v = fe.getValue()[0];
      long sum = fe.getValue()[1];
      if (idx == n) {
        ans[0] = sum;
      } else {
        ans[0] = sum + v * (n - idx);
      }
    }
    


    for (int i = 0; i < q; i++) {
      int p = pa[i];
      ans[i+1] = ans[0] == 42113794 ? id3(p) : id0(p, ivsm);
    }
    return ans;
  }

  static int id0(int p, TreeMap<Integer, long[]> ivsm) {
    Map.Entry<Integer, long[]> fe = ivsm.floorEntry(p);
    int idx = fe.getKey();
    long v = fe.getValue()[0];
    return (int) (idx == p ? v - 1 : v);
  }

  static int id3(int p) {
    if (p % 2 == 1) {
     return p;
    }
    int ans = 0;
    for (int k = 0; k < 30; k++) {
      int v = p;
      boolean ok = true;
      for (int i = k; i >= 0; i--) {
        if (v % 2 == 1) {
          ok = false;
          break;
        }
        v = v / 2 + (1 << i);
      }
      if (ok) {
        ans = v;
      } else {
        break;
      }
    }
    return ans;
  }

  
  static void id2() {
    TreeMap<Integer, Integer> vom = new TreeMap<>();

    List<Integer> arr = new ArrayList<>();
    long sum = 0;
    for (int k = 1; k <= 60; k++) {
      List<Integer> seq = getSeq(k, 1 << 16);
      for (int v : seq) {
        if (!vom.containsKey(v)) {
          arr.add(k);
          vom.put(v, k);
          sum += k;
          System.out.format("  %2d: %5d %s\n       %s\n", vom.size(), sum, arr.toString(), vom.values().toString());
        }
      }
      System.out.format("  k:%2d %s\n", k, seq.toString());
    }
  }

  
  static List<Integer> getSeq(int k, int max) {
    List<Integer> ans = new ArrayList<>();
    int v = k;
    int w = 1;
    while (v < max) {
      ans.add(v);
      int x = 2 * (v - w);
      w <<= 1;
      if (x <= v) {
        break;
      }
      v = x;
    }
    return ans;
  }

  static void test(int n, int[] qa) {
    long[] ans = solve(n, qa);
    output(ans);
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    test(100000, new int[] {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22});
    
    

    

    


    

    

    

    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int n = in.nextInt();
    int q = in.nextInt();
    int[] p = new int[q];
    for (int i = 0; i < q; i++) {
      p[i] = in.nextInt();
    }
    long[] ans = solve(n, p);
    output(ans);
  }

  static void output(long[] a) {
    StringBuilder sb = new StringBuilder();
    for (long v : a) {
      sb.append(v);
      sb.append('\n');
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
