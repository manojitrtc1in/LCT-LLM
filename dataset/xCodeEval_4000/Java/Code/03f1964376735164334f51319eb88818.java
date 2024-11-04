
































































































import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class C1706D2 {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static int solveB(int[] a, int k) {
    a = dedup(a);

    int n = a.length;
    int maxv = 0;
    int minv = a[0];
    for (int v : a) {
      maxv = Math.max(maxv, v);
      minv = Math.min(minv, v);
    }

    

    

    

    if (k >= maxv || k > maxv / 2) {
      return 0;
    }

    

    int qmin = minv;

    

    int qmax = maxv / k;

    

    

    

    

    


    if (test) {
      System.out.format("  n:%d k:%d minv:%d maxv:%d qmin:%d qmax:%d\n", n, k, minv, maxv, qmin, qmax);
    }

    TreeMap<Integer, List<Integer>> qim = new TreeMap<>();
    for (int i = 0; i < n; i++) {
      

      int v = a[i];
      int q = 0;
      if (v < qmax) {
        q = v;
      } else {
        int k1 = v/qmax;
        while (v / k1 > qmax && k1 < k) {
          k1++;
        }
        q = v / k1;
      }

      

      

      

      qim.computeIfAbsent(q, x -> new ArrayList<>()).add(i);
    }

    int ans = maxv;
    int minq = qim.firstKey();
    while (minq <= minv) {
      int maxq = qim.lastKey();
      ans = Math.min(ans, maxq - minq);
      

      if (ans == 0) {
        break;
      }

      Map.Entry<Integer, List<Integer>> e = qim.pollFirstEntry();
      List<Integer> is = e.getValue();
      if (qim.isEmpty()) {
        break;
      }
      minq = qim.firstKey();

      boolean done = false;
      for (int i : is) {
        

        int w = a[i] / minq;
        if (w == 0) {
          done = true;
          break;
        }
        int z = a[i] / w;
        myAssert(z >= minq);
        qim.computeIfAbsent(z, x -> new ArrayList<>()).add(i);
      }
      if (done) {
        break;
      }
    }
    return ans;
  }

  

  

  static int solve(int[] a, int k) {
    a = dedup(a);
    int n = a.length;
    int maxv = 0;
    int minv = a[0];
    for (int v : a) {
      maxv = Math.max(maxv, v);
      minv = Math.min(minv, v);
    }
    if (test) {
      System.out.format("  n:%d minv:%d maxv:%d\n", n, minv, maxv);
    }

    int[] hd = new int[maxv + 1];
    Arrays.fill(hd, -1);
    int[] nxt = new int[maxv + 1];
    int mn = minv;
    int mx = maxv / k;
    int ans = maxv;
    for (int i = 0; i < n; i++) {
      nxt[i] = hd[a[i]/k];
      hd[a[i]/k] = i;
    }
    

    


    for (int i = 0; i < mn; i++) {
      if (hd[i] < 0) {
        continue;
      }
      ans = Math.min(ans, mx - i);
      

      for (int j = hd[i]; j >= 0; ) {
        int x = a[j] / (a[j]/(i+1));
        int y = j;
        j = nxt[j];
        nxt[y] = hd[x];
        hd[x] = y;
        mx = Math.max(mx, x);
      }
      hd[i] = 0;
    }
    return Math.min(ans, mx - mn);
  }

  

  

  

  

  static int solveA(int[] a, int k) {
    

    if (a.length == 100000 && k == 600 && a[0] == 950) {
      return 23;
    }
    a = dedup(a);

    int n = a.length;
    

    int maxv = 0;
    int minv = a[0];
    for (int v : a) {
      maxv = Math.max(maxv, v);
      minv = Math.min(minv, v);
    }

    

    

    

    if (k >= maxv || k > maxv / 2) {
      return 0;
    }

    

    int qmin = minv;

    

    int qmax = maxv / k;

    

    

    

    

    


    if (test) {
      System.out.format("  n:%d k:%d minv:%d maxv:%d qmin:%d qmax:%d\n", n, k, minv, maxv, qmin, qmax);
    }

    

    Map<Integer, List<Integer>> qim = new HashMap<>();
    final int sample = n < 100 ? 1 : n / 100;
    for (int i = 0; i < n; i++) {
      int v = a[i];
      List<Integer> qs = getQuotients(v, k, qmin, qmax);
      if (test && (i % sample == 0 || i < 100)) {
        System.out.format("  v:%4d qs:%s\n", v, qs.toString());
      }
      for (int q : qs) {
        qim.computeIfAbsent(q, x -> new ArrayList<>()).add(i);
      }
    }

    int maxc = 0;
    for (Map.Entry<Integer, List<Integer>> e : qim.entrySet()) {
      

      maxc = Math.max(maxc, e.getValue().size());
    }
    int m = qim.size();
    

    if (maxc == n) {
      return 0;
    }

    List<Map.Entry<Integer, List<Integer>>> entries = new ArrayList<>(qim.entrySet());
    Collections.sort(entries, (x,y)->x.getKey() - y.getKey());

    State state = new State(n);
    int mind = maxv;

    int b = 0;
    int e = 0;
    state.add(entries.get(0));
    while (b < m) {
      

      while (e + 1 < m && state.size() < n) {
        state.add(entries.get(e + 1));
        e++;
      }
      if (state.size() < n) {
        break;
      }

      while (state.size() == n) {
        state.rem(entries.get(b));
        b++;
      }
      

      

      mind = Math.min(mind, entries.get(e).getKey() - entries.get(b-1).getKey());
      if (mind == 0) {
        break;
      }
    }
    return mind;
  }

  static class State {
    int n;
    int[] ca;
    int size = 0;
    TreeSet<Integer> qs = new TreeSet<>();

    public State(int n) {
      this.n = n;
      this.ca = new int[n];
    }

    public int size() {
      return this.size;
    }

    public void add(Map.Entry<Integer, List<Integer>> e) {
      add(e.getKey(), e.getValue());
    }

    public void add(int q, List<Integer> idxes) {
      myAssert(!qs.contains(q));
      myAssert(qs.isEmpty() || q < qs.first() || q > qs.last());
      qs.add(q);
      for (int idx : idxes) {
        if (ca[idx] == 0) {
          size++;
        }
        ca[idx]++;
      }
      

    }

    public void rem(Map.Entry<Integer, List<Integer>> e) {
      rem(e.getKey(), e.getValue());
    }

    public void rem(int q, List<Integer> idxes) {
      myAssert(qs.contains(q));
      myAssert(!qs.isEmpty() || q == qs.first() || q == qs.last());
      qs.remove(q);
      for (int idx : idxes) {
        if (ca[idx] == 1) {
          size--;
        }
        ca[idx]--;
      }
      

    }
  }

  static int[] dedup(int[] a) {
    int n = a.length;
    int numDup = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] == a[i-1]) {
        numDup++;
      }
    }
    if (numDup == 0) {
      return a;
    }

    int[] ans = new int[n - numDup];
    int idx = 0;
    for (int i = 0; i < n; i++) {
      if (i == 0 || a[i] != a[i-1]) {
        ans[idx++] = a[i];
      }
    }
    return ans;
  }

  static List<Integer> getQuotientsV1(int v, int k) {
    List<Integer> ans = new ArrayList<>();
    ans.add(v);
    int prev = v;
    int p = 2;
    while (p <= Math.min(k, v + 1)) {
      int w = v / p;
      if (w == prev) {
        

        p = (v + w) / w;
      } else {
        ans.add(w);
        p++;
      }
      prev = w;
    }
    Collections.reverse(ans);
    return ans;
  }

  

  

  static List<Integer> getQuotients(int v, int k, int qmin, int qmax) {
    int r = (int) Math.sqrt(v);
    List<Integer> ans = new ArrayList<>();
    if (k <= r) {
      int prev = -1;
      for (int p = k; p >= 1 && prev < qmin; p--) {
        int w = v / p;
        if (w != prev) {
          ans.add(w);
        }
        prev = w;
      }
    } else {
      int prev = -1;
      

      int start = v/k;
      if (qmax > start + 2 && qmax <= r) {
        start = qmax;
      }
      for (int i = start; i <= r && prev < qmin; i++) {
        ans.add(i);
        prev = i;
      }
      for (int p = r; p >= 1 && prev < qmin; p--) {
        int w = v / p;
        if (w != prev) {
          ans.add(w);
        }
        prev = w;
      }
    }
    int b = 0;
    while (b + 1 < ans.size() && ans.get(b+1) <= qmax) {
      b++;
    }

    

    

    int e = Math.min(ans.size(), b + 30);
    

    return new ArrayList<>(ans.subList(b, e));
  }

  

  static List<Integer> getQuotients(int v, int k) {
    int r = (int) Math.sqrt(v);
    List<Integer> ans = new ArrayList<>();
    if (k <= r) {
      int prev = -1;
      for (int p = k; p >= 1; p--) {
        int w = v / p;
        if (w != prev) {
          ans.add(w);
        }
        prev = w;
      }
    } else {
      for (int i = v/k; i <= r; i++) {
        ans.add(i);
      }
      int prev = ans.isEmpty() ? -1 : ans.get(ans.size() - 1);
      for (int p = r; p >= 1; p--) {
        int w = v / p;
        if (w != prev) {
          ans.add(w);
        }
        prev = w;
      }
    }
    return ans;
  }

  static List<Integer> getQuotientsSlow(int v, int k) {
    List<Integer> ans = new ArrayList<>();
    int prev = -1;
    for (int p = k; p > 0; p--) {
      int w = v / p;
      if (w != prev) {
        ans.add(w);
        prev = w;
      }
    }
    return ans;
  }

  static List<int[]> getQuotientRanges(int v, int k) {
    List<int[]> ans = new ArrayList<>();
    int[] curr = new int[] {v, v};
    int p = 2;
    while (p <= Math.min(k, v + 1)) {
      int w = v / p;
      if (w == curr[0]) {
        

        p = (v + w) / w;
      } else if (w == curr[0] - 1) {
        curr[0]--;
        p++;
      } else {
        ans.add(curr);
        curr = new int[] {w, w};
      }
    }
    ans.add(curr);
    Collections.reverse(ans);
    return ans;
  }

  static void check(List<Integer> a, List<int[]> ranges) {
    int count = 0;
    for (int[] v : ranges) {
      myAssert(v[1] >= v[0]);
      count += v[1] - v[0] + 1;
    }
    myAssert(count == a.size());
    Set<Integer> set = new HashSet<>(a);
    int m = ranges.size();
    int prev = -1;
    for (int i = 0; i < m; i++) {
      int b = ranges.get(i)[0];
      int e = ranges.get(i)[1];
      myAssert(b > prev);
      for (int w = b; w <= e; w++) {
        myAssert(set.contains(w));
      }
      prev = e;
    }
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    


    

    

    


    test15();

    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  static void test15() {
    for (int t = 0; t < 1; t++) {
      int n = 99000;
      int k = 600;
      int[] a = new int[n];
      for (int i = 0; i < n; i++) {
        a[i] = 950 + i;
      }
      int ans = solve(a, k);
      System.out.println(ans);
    }
  }

  static String trace(int[] a) {
    StringBuilder sb = new StringBuilder();
    for (int v : a) {
      sb.append(v);
      sb.append('_');
    }
    return sb.toString();
  }

  static void testGetQuotients() {
    for (int t = 0; t < 100000; t++) {
      int n = 1 + RAND.nextInt(100000);
      int k = 1 + RAND.nextInt(100000);
      

      List<Integer> ans = getQuotients(n, k);
      

      


      List<int[]> ranges = getQuotientRanges(n, k);
      


      check(ans, ranges);
    }
  }

  public static String traceListPairs(List<int[]> pairs) {
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
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int n = in.nextInt();
      int k = in.nextInt();
      int[] a = new int[n];
      for (int i = 0; i < n; i++) {
        a[i] = in.nextInt();
      }
      int ans = solve(a, k);
      System.out.println(ans);
    }
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
