




































































































































































































































































































































import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.StringTokenizer;

public class id1 {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static void solve(int[] d, MyScanner in, Judge judge) {
    int n = d.length;

    

    List<int[]> arr = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      arr.add(new int[] {d[i], i, 0});
    }
    Collections.sort(arr, (x,y)->y[0]-x[0]);

    int[] nids = new int[n];
    int[] degs = new int[n];
    for (int i = 0; i < n; i++) {
      int[] v = arr.get(i);
      v[2] = i;
      degs[i] = v[0];
      nids[v[1]] = i;
    }

    UnionFind uf = new UnionFind(n);
    for (int[] e : arr) {
      int deg = e[0];
      int o = e[1];
      int v = e[2];
      if (deg == 0) {
        continue;
      }
      if (uf.find(v) != v) {
        

        continue;
      } else {
        for (int j = 0; j < deg; j++) {
          int w = ask(o, in, judge);
          w = nids[w];
          uf.union(v, w);
          if (uf.find(v) != v) {
            break;
          }
        }
      }
    }

    int cid = 0;
    int[] crr = new int[n];
    for (Map.Entry<Integer, List<Integer>> e : uf.getGroups().entrySet()) {
      List<Integer> ids = e.getValue();
      cid++;
      for (int w : ids) {
        crr[w] = cid;
      }
    }

    int[] colors = new int[n];
    for (int i = 0; i < n; i++) {
      int[] v = arr.get(i);
      colors[v[1]] = crr[v[2]];
    }

    StringBuilder sb = new StringBuilder();
    sb.append("!");
    for (int v : colors) {
      sb.append(" ");
      sb.append(v);
    }
    System.out.println(sb.toString());
    System.out.flush();
  }

  static void answer(int[] colors, MyScanner in, Judge judge) {
    if (in != null) {
      StringBuilder sb = new StringBuilder();
      sb.append("!");
      for (int v : colors) {
        sb.append(" ");
        sb.append(v);
      }
      System.out.println(sb.toString());
      System.out.flush();
    } else {
      judge.answer(colors);
    }
  }

  static int ask(int v, MyScanner in, Judge judge) {
    if (in != null) {
      System.out.format("? %d\n", v + 1);
      System.out.flush();
      return in.nextInt() - 1;
    } else {
      return judge.ask(v);
    }
  }

  static class UnionFind {
    int n;
    int m;  

    int[] gids;
    Map<Integer, Integer> gsm = new HashMap<>();

    public UnionFind(int n) {
      this.n = n;
      this.m = n;
      this.gids = new int[n];
      for (int i = 0; i < n; i++) {
        gids[i] = i;
        gsm.put(i, 1);
      }
    }

    public boolean union(int i, int j) {
      int ri = find(i);
      int rj = find(j);
      if (ri != rj) {
        int id = Math.min(ri, rj);
        

        gids[ri] = id;
        gids[rj] = id;
        m--;
        int s = gsm.remove(ri) + gsm.remove(rj);
        gsm.put(id, s);
        return true;
      }
      return false;
    }

    public int find(int i) {
      while (i != gids[i]) {
        gids[i] = gids[gids[i]];
        i = gids[i];
      }
      return i;
    }

    public int gsize(int i) {
      return gsm.get(find(i));
    }

    public boolean id2() {
      return m == 1;
    }

    public int id0() {
      return m;
    }

    public Map<Integer, List<Integer>> getGroups() {
      Map<Integer, List<Integer>> map = new HashMap<>();
      for (int i = 0; i < n; i++) {
        int id = find(i);
        map.computeIfAbsent(id, v -> new ArrayList<>()).add(i);
      }
      return map;
    }
  }

  static class Judge {
    int n;
    List<Integer>[] adjs;
    int[] degs;

    int[] idxes;

    public Judge(int n, int[][] edges) {
      this.n = n;
      adjs = new ArrayList[n];
      for (int i = 0; i < n; i++) {
        adjs[i] = new ArrayList<>();
      }
      for (int[] edge : edges) {
        int u = edge[0] - 1;
        int v = edge[1] - 1;
        adjs[u].add(v);
        adjs[v].add(u);
      }
      idxes = new int[n];
      degs = new int[n];
      for (int i = 0; i < n; i++) {
        degs[i] = adjs[i].size();
        System.out.format("  %d %s\n", i, adjs[i].toString());
      }
    }

    public int ask(int v) {
      System.out.format("  ask %d idx:%d\n", v, idxes[v]);
      myAssert(idxes[v] < adjs[v].size());
      int w = adjs[v].get(idxes[v]);
      idxes[v]++;
      return w;
    }

    public void answer(int[] colors) {
      myAssert(colors.length == n);
      Map<Integer, List<Integer>> cids = new HashMap<>();
      for (int i = 0; i < n; i++) {
        cids.computeIfAbsent(colors[i], x -> new ArrayList<>()).add(i);
      }
      for (List<Integer> ids : cids.values()) {
        int nc = ids.size();
        int sc = 0;
        for (int id : ids) {
          sc += adjs[id].size();
        }
        myAssert(sc <= nc * nc);
      }
    }
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    Judge judge = new Judge(3, new int[][] {{1,2},{2,3}});
    solve(judge.degs, null, judge);
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    doTest();
    MyScanner in = new MyScanner();
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int n = in.nextInt();
      int[] d = new int[n];
      for (int i = 0; i < n; i++) {
        d[i] = in.nextInt();
      }
      solve(d, in, null);
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
