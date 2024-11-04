


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
























































































































































public class id0 {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  

  static int[] solve(int[] p, int[] a) {
    int n = a.length;
    

    

    

    

    

    

    

    int[] indegs = new int[n];
    int maxv = 0;
    for (int i = 0; i < n; i++) {
      indegs[p[i]]++;
      maxv = Math.max(maxv, a[i]);
    }
    if (maxv == n - 1) {
      return a;
    }
    int id1 = 0;
    for (int i = 0; i < n; i++) {
      if (indegs[i] == 0) {
        id1++;
      }
    }
    

    myAssert(id1 > 0);
    int steps = (maxv - n + 1) / id1;
    myAssert(steps > 0);

    int[][] pp = new int[n][31];
    for (int i = 0; i < n; i++) {
      pp[i][0] = p[i];
    }
    for (int j = 1; j < 30; j++) {
      for (int i = 0; i < n; i++) {
        pp[i][j] = pp[pp[i][j-1]][j-1];
      }
    }
    

    List<List<Integer>> sas = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      sas.add(new ArrayList<>());
    }
    for (int i = 0; i < n; i++) {
      int d = getDst(i, steps, pp);
      sas.get(d).add(i);
    }

    int[] minv = new int[n];
    Arrays.fill(minv, -1);
    int[] ans = new int[n];
    Arrays.fill(ans, -1);
    boolean[] used = new boolean[n];
    for (int i = 0; i < n; i++) {
      List<Integer> sa = sas.get(i);
      if (!sa.isEmpty()) {
        

        ans[sa.get(0)] = a[i];
        used[a[i]] = true;
        for (int j : sa) {
          minv[j] = a[i] + 1;
        }
      }
    }
    

    int iu = 0;
    TreeSet<Integer> candidates = new TreeSet<>();
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        candidates.add(i);
      }
    }
    for (int i = 0; i < n; i++) {
      if (ans[i] >= 0) {
        continue;
      }
      int w = candidates.ceiling(minv[i]);
      ans[i] = w;
      used[w] = true;
      candidates.remove(w);
      
    }
    return ans;
  }

  static int getDst(int v, int k, int[][] pp) {
    int w = v;
    for (int i = 0; i < 31; i++) {
      if ((k & (1 << i)) != 0) {
        w = pp[w][i];
        k -= (1 << i);
        if (k == 0) {
          break;
        }
      }
    }
    return w;
  }

  

  

  

  static int[] detectLoops(int[] p, List<Integer> srcs) {
    int n = p.length;
    int [] loops = new int[n];
    boolean[] visited = new boolean[n];
    

    for (int v : srcs) {
      myAssert(!visited[v]);
      int u = v;
      visited[u] = true;
      while (true) {
        int w = p[u];
        

        if (visited[w]) {
          if (loops[w] == 0) {
            

            if (u == w) {
              

              loops[w] = 1;
              

            } else {
              int b = v;
              while (b != u && b != w) {
                b = p[b];
              }
              if (b == w) {
                

                

                

                

                int len = 1;
                b = w;
                while (b != u) {
                  b = p[b];
                  len++;
                }

                b = w;
                List<Integer> ids = new ArrayList<>();
                while (true) {
                  ids.add(b);
                  loops[b] = len;
                  b = p[b];
                  if (b == w) {
                    break;
                  }
                }
                

              }
            }
          }
          break;
        }
        visited[w] = true;
        u = w;
      }
    }

    

    for (int i = 0; i < n; i++) {
      if (visited[i]) {
        continue;
      }
      int b = i;
      int len = 1;
      while (p[b] != i) {
        b = p[b];
        len++;
        myAssert(len < n);
      }
      b = i;
      while (true) {
        loops[b] = len;
        b = p[b];
        if (b == i) {
          break;
        }
      }
    }
    return loops;
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    int n = 100000;
    int[] p = id2(n);
    int[] a0 = id3(n);
    

    

    

    

    int steps = RAND.nextInt(40);
    int[] a = moveSeats(a0, steps, p);
    

    int[] b = solve(p, a);
    

    int[] dst = moveSeats(b, steps, p);
    

    for (int i = 0; i < n; i++) {
      myAssert(a[i] == dst[i]);
    }
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  static String trace(int[] a) {
    return Arrays.toString(a).replace('[', '{').replace(']', '}').replace(" ", "");
  }

  

  

  static int[] id2(int n) {
    myAssert(n >= 2);
    int[] p = new int[n];
    boolean ok = false;
    do {
      int[] ct = new int[n];
      for (int i = 0; i < n; i++) {
        int v = RAND.nextInt(n);
        p[i] = v;
        ct[v]++;
        if (ct[v] >= 2) {
          ok = true;
        }
      }
    } while (!ok);
    return p;
  }

  static int[] id3(int n) {
    List<Integer> perm = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      perm.add(i);
    }
    Collections.shuffle(perm);
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = perm.get(i);
    }
    return a;
  }

  static int[] moveSeats(int[] a, int k, int[] p) {
    int n = a.length;
    int[] curr = new int[n];
    System.arraycopy(a, 0, curr, 0, n);
    int[] next = new int[n];
    int head = n;
    for (int j = 0; j < k; j++) {
      Arrays.fill(next, -1);
      for (int i = 0; i < n; i++) {
        if (next[p[i]] < 0 || next[p[i]] > curr[i]) {
          next[p[i]] = curr[i];
        }
      }
      for (int i = 0; i < n; i++) {
        if (next[i] == -1) {
          next[i] = head++;
        }
      }
      System.arraycopy(next, 0, curr, 0, n);
      

    }
    return curr;
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int n = in.nextInt();
    int[] p = new int[n];
    for (int i = 0; i < n; i++) {
      p[i] = in.nextInt() - 1;
    }
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = in.nextInt() - 1;
    }
    int[] ans = solve(p, a);
    output(ans);
  }

  static void output(int[] a) {
    StringBuilder sb = new StringBuilder();
    for (int v : a) {
      sb.append(v + 1);
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
