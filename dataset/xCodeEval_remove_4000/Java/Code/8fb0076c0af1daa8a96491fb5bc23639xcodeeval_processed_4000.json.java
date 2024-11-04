


import java.io.File;
import java.lang.invoke.MethodHandles;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;
import java.util.concurrent.atomic.AtomicInteger;
























































public class id3 {
  static final int MOD = 998244353;
  static final Random RAND = new Random();

  final static List<Integer> id4 = Arrays.asList(
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
      2221,2237,2239,2243,2251,2267,2269,2273,2281,2287,2293,2297,2309,2311,2333,2339,2341,2347,
      2351,2357,2371,2377,2381,2383,2389,2393,2399,2411,2417,2423,2437,2441,2447,2459,2467,2473,
      2477,2503,2521,2531,2539,2543,2549,2551,2557,2579,2591,2593,2609,2617,2621,2633,2647,2657,
      2659,2663,2671,2677,2683,2687,2689,2693,2699,2707,2711,2713,2719,2729,2731,2741,2749,2753,
      2767,2777,2789,2791,2797,2801,2803,2819,2833,2837,2843,2851,2857,2861,2879,2887,2897,2903,
      2909,2917,2927,2939,2953,2957,2963,2969,2971,2999,3001,3011,3019,3023,3037,3041,3049,3061,
      3067,3079,3083,3089,3109,3119,3121,3137,3163,3167,3169,3181,3187,3191,3203,3209,3217,3221);

  

  static int N = 4000;

  static boolean[] isPrime;

  static TreeMap<Integer, List<int[]>> SM = null;

  public static int[] solve(int[] arr) {
    int n = arr.length;
    int max = 0;
    for (int v : arr) {
      max = Math.max(max, v);
    }
    Map<Integer, Integer> memo = new HashMap<>();

    N = max;
    isPrime = id0(N);
    SM = id2();

    int[] ans = new int[n];
    for (int i = 0; i < n; i++) {
      int c = arr[i];
      if (memo.containsKey(c)) {
        ans[i] = memo.get(c);
      } else {
        int v = solve(c);
        memo.put(c, v);
        ans[i] = v;
      }
    }
    return ans;
  }


  

  static int solve(int c) {
    

    

    

    

    

    final int[] small = {1, -1, 2, 3, -1, 5, 4, 7, -1, -1};
    if (c <= small.length) {
      return small[c-1];
    }
    

    return split(c);
  }

  static int split(int c) {
    AtomicInteger ans = new AtomicInteger(-1);
    List<int[]> curr = new ArrayList<>();
    split(c, curr, ans);
    return ans.get();
  }

  static int getValue(List<int[]> v) {
    int value = 1;
    for (int[] e : v) {
      for (int i = 0; i < e[1]; i++) {
        value *= e[0];
      }
    }
    return value;
  }

  

  

  static void split(int c, List<int[]> curr, AtomicInteger ans) {
    

    if (c == 1) {
      int value = getValue(curr);
      if (ans.get() < 0 || ans.get() > value) {
        ans.set(value);
      }
      return;
    }

    

    int minp = curr.isEmpty() ? 2 : curr.get(curr.size() - 1)[0] + 1;
    for (int v : SM.keySet()) {
      if (v > c) {
        break;
      }
      if (c % v == 0) {
        

        int idx = curr.size();
        for (int[] e : SM.get(v)) {
          if (e[0] < minp) {
            continue;
          }
          curr.add(idx, e);
          split(c / v, curr, ans);
          curr.remove(idx);
        }
      }
    }
    if (c > 4000 & isPrime[c-1]) {
      int p = c - 1;
      

      for (int[] e : curr) {
        if (e[0] == p) {
          return;
        }
      }
      curr.add(new int[] {p, 1});
      int value = getValue(curr);
      if (ans.get() < 0 || ans.get() > value) {
        ans.set(value);
      }
      curr.remove(curr.size() - 1);
    }
  }

  

  

  

  

  

  static TreeMap<Integer, List<int[]>> id2() {
    TreeMap<Integer, List<int[]>> map = new TreeMap<>();
    for (int p : id4) {
      long w = p * p;
      long x = 1 + p + w;
      int e = 2;
      while (x <= N) {
        map.computeIfAbsent((int) x, v -> new ArrayList<>()).add(new int[] {p, e});
        w *= p;
        x += w;
        e++;
      }
    }
    

    

    for (int i = 2; i <= Math.min(N, 4000); i++) {
      if (isPrime[i]) {
        map.computeIfAbsent(i+1, v -> new ArrayList<>()).add(new int[] {i, 1});
      }
    }
    
    return map;
  }

  

  public static boolean[] id0(int n) {
    boolean[] arr = new boolean[n+1];
    Arrays.fill(arr, true);
    arr[1] = false;
    int p = 2;
    int r = (int) (1 + Math.sqrt(n));
    while (p <= r) {
      int v = p + p;
      while (v <= n) {
        arr[v] = false;
        v += p;
      }
      p++;
      while (p <= r && !arr[p]) {
        p++;
      }
    }
    

    return arr;
  }

  

  static List<Integer> getFactors(int v) {
    Set<Integer> factors = new HashSet<>();
    factors.add(1);
    factors.add(v);
    int r = (int) (1 + Math.sqrt(v));
    for (int p : id4) {
      if (p > r || p > v) {
        break;
      }
      while (v % p == 0) {
        factors.add(p);
        factors.add(v / p);
        v /= p;
      }
    }
    List<Integer> ans = new ArrayList<>(factors);
    Collections.sort(ans);
    return ans;
  }

  static boolean isPrime(int k) {
    List<int[]> entries = id1(k);
    return entries.size() == 1 && entries.get(0)[1] == 1;
  }

  public static List<int[]> id1(int k) {
    if (k <= 0) {
      new RuntimeException("Input must be positive!");
    }
    List<int[]> ans = new ArrayList<>();
    int r = (int) Math.sqrt(k) + 1;
    for (int p : id4) {
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

  static String traceEntries(List<List<int[]>> entries) {
    StringBuilder sb = new StringBuilder();
    for (List<int[]> e : entries) {
      sb.append(traceEntry(e));
      sb.append(',');
    }
    return sb.toString();
  }

  static String traceEntry(List<int[]> e) {
    StringBuilder sb = new StringBuilder();
    for (int[] v : e) {
      sb.append("[");
      sb.append(v[0]);
      sb.append(',');
      sb.append(v[1]);
      sb.append("]");
    }
    return sb.toString();
  }

  static void doTest() {
    long t0 = System.currentTimeMillis();
    N = 10000000;
    isPrime = id0(N);
    SM = id2();
    for (Map.Entry<Integer, List<int[]>> e : SM.entrySet()) {
      System.out.format("%9d %s\n", e.getKey(), traceEntry(e.getValue()));
    }
    System.out.println(solve(12));
    System.out.format("%d msec\n", System.currentTimeMillis() - t0);
    System.exit(0);
  }

  public static void main(String[] args) {
    

    Scanner in = id5();
    int T = in.nextInt();
    int[] nums = new int[T];
    for (int t = 1; t <= T; t++) {
      nums[t-1] = in.nextInt();
    }
    int[] ans = solve(nums);
    output(ans);
    in.close();
  }

  static Scanner id5() {
    try {
      final String USERDIR = System.getProperty("user.dir");
      final String CNAME = MethodHandles.lookup().lookupClass().getSimpleName();
      final File fin = new File(USERDIR + "/io/c" + CNAME.substring(1,5) + "/" + CNAME + ".in");
      return fin.exists() ? new Scanner(fin) : new Scanner(System.in);
    } catch (Exception e) {
      return new Scanner(System.in);
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
}
