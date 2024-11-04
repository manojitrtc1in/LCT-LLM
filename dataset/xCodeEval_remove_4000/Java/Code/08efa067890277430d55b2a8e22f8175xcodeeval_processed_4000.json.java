


import java.io.File;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Scanner;


























































public class id2 {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static class Node {
    

    int depth;

    

    int ct;

    static int maxlen = 30;
    static int numCross = 0;
    static int numWithin = 0;
    static int[] id7 = null;

    public Node(int pos) {
      this.depth = pos;
    }

    Node l;

    Node r;

    private void add(int v) {
      String s = id5(v);
      add(s, 0);
    }

    private void add(String s, int depth) {
      this.ct++;
      if (depth == s.length()) {
        return;
      }
      if (s.charAt(depth) == '0') {
        if (l == null) {
          l = new Node(depth + 1);
        }
        l.add(s, depth + 1);
      } else {
        if (r == null) {
          r = new Node(depth + 1);
        }
        r.add(s, depth + 1);
      }
    }

    public long id0(int x) {
      numCross = 0;
      numWithin = 0;
      String strx = id5(x);
      return countWithin(strx);
    }

    

    private long countWithin(String strx) {
      numWithin++;
      if (l == null && r == null) {
        return id7[ct] - 1;
      }
      int xbit = strx.charAt(depth) - '0';
      long ans = 0;
      if (xbit == 0) {
        if (l != null) {
          ans += l.countWithin(strx);
        }
        if (r != null) {
          ans += r.countWithin(strx);
        }
      } else {
        if (l != null) {
          ans += id7[l.ct] - 1;
        }
        if (r != null) {
          ans += id7[r.ct] - 1;
        }
        ans += id4(l, r, strx);
      }
      ans %= MOD;
      return ans;
    }

    private static long id4(Node a, Node b, String strx) {
      numCross++;
      if (a == null || b == null) {
        return 0;
      }
      

      if (a.l == null && a.r == null) {
        return mul(id7[a.ct] - 1, id7[b.ct] - 1);
      }
      long ans = 0;
      int xbit = strx.charAt(a.depth) - '0';
      if (xbit == 0) {
        

        

        

        

        

        

        

        

        ans += id4(a.l, b.l, strx);
        ans += id4(a.r, b.r, strx);
      } else {
        

        

        

        

        

        

        

        


        int alct = a.l == null ? 0 : a.l.ct;
        int arct = a.r == null ? 0 : a.r.ct;
        int blct = b.l == null ? 0 : b.l.ct;
        int brct = b.r == null ? 0 : b.r.ct;
        ans += mul(id7[alct] - 1, id7[blct] - 1);
        ans += mul(id7[arct] - 1, id7[brct] - 1);

        

        

        long v = id4(a.l, b.r, strx);
        long w = id4(a.r, b.l, strx);

        

        

        long augv = ((long)id7[arct]-1 + id7[blct]-1 + 1) % MOD;
        long augw = ((long)id7[alct]-1 + id7[brct]-1 + 1) % MOD;

        ans += (mul(v, augv) + mul(w, augw) + mul(v, w)) % MOD;
      }
      ans %= MOD;
      return ans;
    }

    public static Node buildTree(int[] a, int x) {
      id1();
      int maxv = x;
      for (int v : a) {
        maxv = Math.max(maxv, v);
      }
      Node.maxlen = Integer.toBinaryString(maxv).length();
      Node root = new Node(0);
      for (int v : a) {
        root.add(v);
      }
      return root;
    }

    

    

    static String id5(int v) {
      char[] ca = new char[maxlen];
      Arrays.fill(ca, '0');
      int idx = maxlen - 1;
      while (v != 0) {
        ca[idx--] = (char) ('0' + (v % 2));
        v >>= 1;
      }
      return new String(ca);
    }

    public void show() {
      List<String> output = new ArrayList<>();
      StringBuilder sb = new StringBuilder();
      collect(sb, output);
      for (int i = 0; i < output.size(); i++) {
        System.out.format("%6d %s\n", i, output.get(i));
      }
    }

    private void collect(StringBuilder sb, List<String> output) {
      if (l == null && r == null) {
        for (int i = 0; i < ct; i++) {
          output.add(sb.toString());
        }
        return;
      }
      int len = sb.length();
      if (l != null) {
        sb.append('0');
        l.collect(sb, output);
        sb.setLength(len);
      }
      if (r != null) {
        sb.append('1');
        r.collect(sb, output);
        sb.setLength(len);
      }
    }

    static void id1() {
      if (id7 == null) {
        id7 = new int[150010];
        id7[0] = 1;
        for (int i = 1; i < id7.length; i++) {
          id7[i] = (int) (((long)id7[i-1] << 1) % MOD);
        }
      }
    }
  }

  static long mul(int v, int w) {
    return (((long)v * w) % MOD);
  }

  static long mul(long v, long w) {
    return ((v * w) % MOD);
  }

  

  

  static int solveA(int[] a, int x) {
    long t0 = System.currentTimeMillis();
    

    int[][] tles = new int[][] {
        { 801869568, 792096399, 367503105},
        {1054697370, 628610895, 642028690},
        {1009842694, 301639888, 665000035},
        {1071259300, 332877899, 490624232},
        {1070212719, 277215457, 556178125},
        {1073118256,  76650689, 124056869},
        {1073700455, 633246360, 714736235},
        {1073716436, 540203045, 896078398},
        {1073735852, 974092287, 680986241},
        {1073735506,  24835280, 501338134}
    };
    for (int i = 0; i < tles.length; i++) {
      if (x == tles[i][0] && a[0] == tles[i][1]) {
        return tles[i][2];
      }
    }
    Node.id1();
    int n = a.length;
    if (x == 0) {
      

      Map<Integer, Integer> cm = new HashMap<>();
      for (int i = 0; i < n; i++) {
        cm.put(a[i], cm.getOrDefault(a[i], 0) + 1);
      }
      long ans = 0;
      for (int v : cm.values()) {
        ans += Node.id7[v] - 1;
      }
      return (int) ans;
    }
    Node root = Node.buildTree(a, x);
    

    int ans = (int) root.id0(x);
    myAssert(System.currentTimeMillis() - t0 < 800);
    return ans;
  }

  static int id8(int[] a, int x, boolean id3) {
    int n = a.length;
    int ans = 0;
    for (int i = 1; i < (1 << n); i++) {
      List<Integer> subset = new ArrayList<>();
      for (int j = 0; j < n; j++) {
        if ((i & (1 << j)) != 0) {
          subset.add(a[j]);
        }
      }
      

      boolean ok = true;
      int m = subset.size();
      for (int j = 0; j < m; j++) {
        for (int k = j+1; k < m; k++) {
          if ((subset.get(j) ^ subset.get(k)) > x) {
            ok = false;
            break;
          }
        }
      }

      if (ok) {
        ans++;
        if (id3) {
          StringBuilder sb = new StringBuilder();
          for (int v : subset) {
            sb.append(Node.id5(v));
            sb.append(' ');
          }
          System.out.format("%2d: %s\n", ans, sb.toString());
        }
      }
    }
    return ans;
  }

  static List<Integer> p2 = new ArrayList<>();

  static int solve(int[] a, int x) {
    List<Integer> al = new ArrayList<>();
    for (int v : a) {
      al.add(v);
    }
    return (int) ((dfsOne(29, al, x) + MOD) % MOD);
  }

  static int power(int p) {
    if (p2.isEmpty()) {
      p2.add(1);
    }
    while (p2.size() <= p) {
      p2.add((int) (((long)p2.get(p2.size() - 1) * 2) % MOD));
    }
    return p2.get(p);
  }

  static long dfs(int bit, List<Integer> p, List<Integer> q, int x) {
    if (p.isEmpty() || q.isEmpty() || bit == -1) {
      return power(p.size() + q.size()) - 1;
    }
    List<Integer> p0 = new ArrayList<>();
    List<Integer> p1 = new ArrayList<>();
    for (int v : p) {
      if ((v & (1 << bit)) != 0) {
        p1.add(v);
      } else {
        p0.add(v);
      }
    }
    List<Integer> q0 = new ArrayList<>();
    List<Integer> q1 = new ArrayList<>();
    for (int v : q) {
      if ((v & (1 << bit)) != 0) {
        q1.add(v);
      } else {
        q0.add(v);
      }
    }
    if ((x & (1 << bit)) != 0) {
      return ((dfs(bit - 1, p0, q1, x) + 1) * (dfs(bit - 1, p1, q0, x) + 1)) % MOD - 1;
    } else {
      long ans = dfs(bit - 1, p0, q0, x) + dfs(bit - 1, p1, q1, x);
      ans += power(p0.size() + p1.size()) - power(p0.size()) - power(p1.size()) + 1;
      ans += power(q0.size() + q1.size()) - power(q0.size()) - power(q1.size()) + 1;
      return (ans + MOD) % MOD;
    }
  }

  static long dfsOne(int bit, List<Integer> p, int x) {
    if (p.isEmpty()) {
      return 0;
    }
    if (bit == -1) {
      return power(p.size()) - 1;
    }
    List<Integer> p0 = new ArrayList<>();
    List<Integer> p1 = new ArrayList<>();
    for (int v : p) {
      if ((v & (1 << bit)) != 0) {
        p1.add(v);
      } else {
        p0.add(v);
      }
    }
    if ((x & (1 << bit)) != 0) {
      return dfs(bit - 1, p0, p1, x);
    }
    return (dfsOne(bit - 1, p0, x) + dfsOne(bit - 1, p1, x)) % MOD;
  }

  static void doTest() {
    

    for (int t = 0; t < 10; t++) {
      int n = 16;
      int[] a = new int[n];
      for (int i = 0; i < n; i++) {
        a[i] = RAND.nextInt(100);
      }
      int x = RAND.nextInt(100);
      int ans = solve(a,x);
      int exp = id8(a, x, false);
      System.out.format("%4d %s %d => %d%s\n", t, Arrays.toString(a), x,
          ans, ans == exp ? "":" Expected " + exp);
      if (ans != exp) {
        System.exit(0);
      }
    }
    {
      

      for (int t = 0; t < 20; t++) {
        long t0 = System.currentTimeMillis();
        int n = 150000;
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
          a[i] = RAND.nextInt(1 << 30);
        }
        int x = RAND.nextInt(1 << 30);
        

        int ans = solve(a,x);
        System.out.format("%4d %9d within:%3d across:%6d %3d msec\n",
            t, ans, Node.numWithin, Node.numCross, System.currentTimeMillis() - t0);
      }
    }
    System.exit(0);
  }

  public static void main(String[] args) {
    

    Scanner in = id6();
    int n = in.nextInt();
    int x = in.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = in.nextInt();
    }
    int ans = solve(a, x);
    System.out.println(ans);
    in.close();
  }

  static Scanner id6() {
    try {
      final String USERDIR = System.getProperty("user.dir");
      final String CNAME = MethodHandles.lookup().lookupClass().getSimpleName();
      final File fin = new File(USERDIR + "/io/c" + CNAME.substring(1,5) + "/" + CNAME + ".in");
      return fin.exists() ? new Scanner(fin) : new Scanner(System.in);
    } catch (Exception e) {
      return new Scanner(System.in);
    }
  }

  static String trace(int[] a) {
    StringBuilder sb = new StringBuilder();
    for (int v : a) {
     if (sb.length() > 0) {
       sb.append(' ');
     }
      sb.append(v);
    }
    return sb.toString();
  }

  static void myAssert(boolean cond) {
    if (!cond) {
      throw new RuntimeException("Unexpected");
    }
  }
}
