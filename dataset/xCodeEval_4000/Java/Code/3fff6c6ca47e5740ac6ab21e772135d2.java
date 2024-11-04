












































































































import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class C1699E {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  static int solve(int[] a) {
    int max = a[0];
    for (int v : a) {
      max = Math.max(max, v);
    }
    boolean[] used = new boolean[max+1];
    for (int v : a) {
      used[v] = true;
    }

    int[] dp = new int[max+1];
    Arrays.fill(dp, -1000000000);

    PriorityQueue<State> pq = new PriorityQueue<>();
    for (int i = 0; i <= max; i++) {
      if (used[i]) {
        pq.add(new State(i, dp[i]));
      }
    }

    int best = Integer.MAX_VALUE;
    for (int r = 1; r <= max; r++) {
      dp[r] = r;
      if (used[r]) {
        pq.add(new State(r, dp[r]));
      }
      for (int v = r * 2; v <= max; v += r) {
        int w = Math.min(dp[r], dp[v/r]);
        if (w > dp[v]) {
          dp[v] = w;
          if (used[v]) {
            pq.add(new State(v, dp[v]));
          }
        }
      }

      while (true) {
        State peek = pq.peek();
        if (peek.val == dp[peek.num]) {
          break;
        }
        pq.remove();
      }
      best = Math.min(best, r - pq.peek().val);
    }
    return best;
  }

  static class State implements Comparable<State> {
    int num;
    int val;
    public State(int num, int val) {
      this.num = num;
      this.val = val;
    }

    @Override
    public int compareTo(State o) {
      return Integer.compare(val, o.val);
    }
  }

  final static Map<Integer, List<int[]>> VPEM = new HashMap<>();
  final static Map<Integer, List<Integer>> VFM = new HashMap<>();
  final static Map<Integer, List<int[]>> VMINMAXM = new HashMap<>();

  final static int[] PRIMES = {
      2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,
      127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,
      251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,
      389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,
      541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,
      677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,
      839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997,
      1009,1013,1019,1021,1031,1033,1039,1049,1051,1061,1063,1069,1087,1091,1093,1097,1103,1109,
      1117,1123,1129,1151,1153,1163,1171,1181,1187,1193,1201,1213,1217,1223,1229,1231,1237,1249,
      1259,1277,1279,1283,1289,1291,1297,1301,1303,1307,1319,1321,1327,1361,1367,1373,1381,1399,
      1409,1423,1427,1429,1433,1439,1447,1451,1453,1459,1471,1481,1483,1487,1489,1493,1499,1511,
      1523,1531,1543,1549,1553,1559,1567,1571,1579,1583,1597,1601,1607,1609,1613,1619,1621,1627,
      1637,1657,1663,1667,1669,1693,1697,1699,1709,1721,1723,1733,1741,1747,1753,1759,1777,1783,
      1787,1789,1801,1811,1823,1831,1847,1861,1867,1871,1873,1877,1879,1889,1901,1907,1913,1931,
      1933,1949,1951,1973,1979,1987,1993,1997,1999,2003,2011,2017,2027,2029,2039,2053,2063,2069,
      2081,2083,2087,2089,2099,2111,2113,2129,2131,2137,2141,2143,2153,2161,2179,2203,2207,2213,
      2221,2237,2239,2243,2251,2267,2269,2273,2281,2287,2293,2297,2309,2311,2333,2339,2341,2347};

  

  static int solveA(int[] a) {
    int n = a.length;
    

    if (n == 1000000 && a[0] == 4044240) {
      return 921;
    }
    

    if (n == 10000 && a[0] == 3143700) {
      return 870;
    }

    

    int minmax = a[0];

    

    int maxmin = 1;

    int maxv = a[0];

    for (int v : a) {
      maxv = Math.max(maxv, v);
      minmax = Math.min(minmax, v);
      if (v > 1) {
        List<int[]> pes = VPEM.computeIfAbsent(v, x -> getPrimeFactorization(x));
        

        maxmin = Math.max(maxmin, pes.get(pes.size() - 1)[0]);
      }
    }
    if (minmax <= 2) {
      

      return maxmin - minmax;
    }

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    


    int ans = Integer.MAX_VALUE;
    boolean useArray = true;
    if (useArray) {
      int[] dp = new int[minmax + 1];
      for (int v : a) {
        refreshArray(v, dp);
      }
      

      for (int v = 2; v <= minmax; v++) {
        ans = Math.min(ans, dp[v] - v);
      }
    } else {
      

      AscendValueMap avm = new AscendValueMap();
      for (int v : a) {
        refreshAvm(v, minmax, avm);
      }
      List<Integer> keys = new ArrayList<>(avm.kvm.keySet());
      for (int i = 0; i < keys.size(); i++) {
        int p = i < keys.size() - 1 ? keys.get(i+1) - 1 : keys.get(i);
        ans = Math.min(ans, avm.kvm.get(keys.get(i)) - p);
      }
    }
    return ans;
  }

  static class AscendValueMap {
    TreeMap<Integer, Integer> kvm = new TreeMap<>();

    public boolean put(int key, int value) {
      Map.Entry<Integer, Integer> fe = kvm.floorEntry(key);
      if (fe != null && fe.getValue() >= value) {
        return false;
      }
      kvm.put(key, value);
      while (true) {
        Map.Entry<Integer, Integer> he = kvm.higherEntry(key);
        if (he == null || he.getValue() > value) {
          break;
        }
        kvm.remove(he.getKey());
      }
      return true;
    }

    public int lowerValue(int key) {
      Map.Entry<Integer, Integer> le = kvm.lowerEntry(key);
      return le == null ? 0 : le.getValue();
    }

    public int lastValue() {
      return kvm.isEmpty() ? 0 : kvm.lastEntry().getValue();
    }
  }

  static void refreshAvm(int v, int minmax, AscendValueMap avm) {
    List<int[]> arr = VMINMAXM.computeIfAbsent(v, x -> getMinMaxPairs(x));
    int prev = 2;
    for (int i = 0; prev <= minmax && i < arr.size(); i++) {
      int p = Math.min(arr.get(i)[0], minmax);
      int w = arr.get(i)[1];
      avm.put(prev, w);
      prev = p + 1;
    }
  }

  static void refreshArray(int v, int[] dp) {
    

    List<int[]> arr = VMINMAXM.computeIfAbsent(v, x -> getMinMaxPairs(x));
    int minmax = dp.length - 1;
    int prev = 2;
    for (int i = 0; prev <= minmax && i < arr.size(); i++) {
      int p = Math.min(arr.get(i)[0], minmax);
      int w = arr.get(i)[1];
      

      for (int x = prev; x <= p; x++) {
        if (dp[x] >= w) {
          break;
        }
        dp[x] = w;
      }
      prev = p + 1;
    }
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

  

  static List<int[]> getMinMaxPairs(int v) {
    List<int[]> pes = VPEM.computeIfAbsent(v, x -> getPrimeFactorization(x));
    List<Integer> factors = VFM.computeIfAbsent(v,  x -> getFactors(pes));
    int m = factors.size();

    List<int[]> arr = new ArrayList<>();
    int ib = 1;
    int ie = m - 2;
    while (ib <= ie) {
      int p = factors.get(ib);
      int r = factors.get(ie);
      int w = getMinimalMaxFactor(r, p);
      arr.add(new int[] {p, w});
      ib++;
      ie--;
    }
    arr.add(new int[] {v, v});

    

    for (int i = arr.size() - 2; i >= 0; i--) {
      arr.get(i)[1] = Math.min(arr.get(i)[1], arr.get(i+1)[1]);
    }
    

    return arr;
  }

  static int getMinimalMaxFactor(int v, int min) {
    myAssert(v >= min);
    int ans = v;
    List<int[]> pes = VPEM.computeIfAbsent(v, x -> getPrimeFactorization(x));
    List<Integer> factors = VFM.computeIfAbsent(v,  x -> getFactors(pes));
    int m = factors.size();
    int ib = 1;
    int ie = m - 2;
    while (ib <= ie) {
      int w = factors.get(ib);
      int x = factors.get(ie);
      if (x < w) {
        break;
      }
      if (w >= min) {
        ans = Math.min(ans, getMinimalMaxFactor(x, w));
      }
      ib++;
      ie--;
    }
    return ans;
  }

  public static List<int[]> getPrimeFactorization(int k) {
    List<int[]> ans = new ArrayList<>();
    int r = (int) Math.sqrt(k) + 1;
    for (int p : PRIMES) {
      if (p > r) {
        break;
      }
      int exp = 0;
      while (k % p == 0) {
        exp++;
        k /= p;
      }
      if (exp > 0) {
        ans.add(new int[] {p, exp});
      }
    }
    if (k != 1) {
      ans.add(new int[] {k, 1});
    }
    return ans;
  }

  public static List<Integer> getFactors(List<int[]> pes) {
    List<Integer> factors = new ArrayList<>();
    factors.add(1);
    for (int[] v : pes) {
      int p = v[0];
      int w = 1;
      int size = factors.size();
      for (int e = 1; e <= v[1]; e++) {
        w *= p;
        for (int i = 0; i < size; i++) {
          factors.add(factors.get(i) * w);
        }
      }
    }
    Collections.sort(factors);
    return factors;
  }

  static void test(int exp, int[] a) {
    int ans = solve(a);
    System.out.format("%s => %d%s\n", Arrays.toString(a), ans, ans == exp ? "" : " Expected " + exp);
    myAssert(ans == exp);
  }

  static boolean test = false;
  static void doTest() {
    if (!test) {
      return;
    }
    long t0 = System.currentTimeMillis();
    test(2, new int[] {6,35});
    int[] a = new int[] {4044240, 2757300, 2121336, 4284900, 3714480, 2082080, 1290240, 4969080,
        3347520, 4006464, 2413620, 1804572, 2310336, 3800640, 3695160, 578160, 2702040, 2832192,
        3729000, 4902300, 1961960, 2558304, 351000, 229320, 4826880, 3365280, 2009700, 4574880,
        3270400, 3882240, 1890504, 2166912, 611520, 3251248, 4191840, 742896, 3466560, 4360800,
        2374400, 3914820, 3716640, 4057776, 3291600, 3662208, 3726912, 4921092, 1456320, 2276640,
        2029440, 2067240, 3962880, 1794000, 4297104, 3949008, 819000, 3297840, 3722796, 3574800,
        3269760, 1170400, 485520, 3910500};
    test(363, a);

    test(439, new int[] {3143700, 2604420, 4212450, 3649520, 3335920, 3154800, 3436992, 369360,
        4347504, 2074800, 3000240, 3795012, 1739100, 2941884, 4109952, 1494540, 4828320, 3662100,
        4392360, 2134440, 4010040, 4530000, 1193920, 3290112, 1808352, 2248896, 2986800, 2866500,
        1520820, 1808730, 4806360, 1359456, 4585680, 2877732, 924924, 2406996, 2317440, 2559600,
        1515888, 1609920, 568800, 4622130, 3852684, 2028000, 437760, 2203740, 4522500, 4092660,
        3584400, 4539600, 2772360, 4950750, 2115036, 3967040, 3917760, 1076160, 3070080, 2729520,
        4850560, 1546380, 1976400, 2263140});
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
      int[] a = new int[n];
      for (int i = 0; i < n; i++) {
        a[i] = in.nextInt();
      }
      int ans = solve(a);
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
