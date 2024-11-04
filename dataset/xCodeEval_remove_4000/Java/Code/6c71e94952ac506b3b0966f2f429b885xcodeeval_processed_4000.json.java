


import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Objects;
import java.util.Random;
import java.util.Set;
import java.util.StringTokenizer;

public class D {

  static MyScanner scanner = new MyScanner();
  static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
  static final int MOD = 1000000007;
  static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;
  static final int[][] d4 = new int[][]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
  static final int[][] d8 = new int[][]{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
  static final int N = 0;

  static int primes[]=new int[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
      73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
      173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269,
      271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379,
      383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487,
      491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607,
      613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727,
      733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853,
      857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977,
      983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087,
      1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201,
      1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303,
      1307, 1319, 1321, 1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447,
      1451, 1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, 1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597, 1601, 1607,
      1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721,
      1723, 1733, 1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 1823, 1831, 1847,
      1861, 1867, 1871, 1873, 1877, 1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973,
      1979, 1987, 1993, 1997, 1999, 2003, 2011, 2017, 2027, 2029, 2039, 2053, 2063, 2069, 2081,
      2083, 2087, 2089, 2099, 2111, 2113, 2129, 2131, 2137, 2141, 2143, 2153, 2161, 2179, 2203,
      2207, 2213, 2221, 2237, 2239, 2243, 2251, 2267, 2269, 2273, 2281, 2287, 2293, 2297, 2309,
      2311, 2333, 2339, 2341, 2347, 2351, 2357, 2371, 2377, 2381, 2383, 2389, 2393, 2399, 2411,
      2417, 2423, 2437, 2441, 2447, 2459, 2467, 2473, 2477, 2503, 2521, 2531, 2539, 2543, 2549,
      2551, 2557, 2579, 2591, 2593, 2609, 2617, 2621, 2633, 2647, 2657, 2659, 2663, 2671, 2677,
      2683, 2687, 2689, 2693, 2699, 2707, 2711, 2713, 2719, 2729, 2731, 2741, 2749, 2753, 2767,
      2777, 2789, 2791, 2797, 2801, 2803, 2819, 2833, 2837, 2843, 2851, 2857, 2861, 2879, 2887,
      2897, 2903, 2909, 2917, 2927, 2939, 2953, 2957, 2963, 2969, 2971, 2999, 3001, 3011, 3019,
      3023, 3037, 3041, 3049, 3061, 3067, 3079, 3083, 3089, 3109, 3119, 3121, 3137, 3163, 3167,
      3169, 3181, 3187, 3191, 3203, 3209, 3217, 3221, 3229, 3251, 3253, 3257, 3259, 3271, 3299,
      3301, 3307, 3313, 3319, 3323, 3329, 3331, 3343, 3347, 3359, 3361, 3371, 3373,
      3389, 3391, 3407, 3413, 3433, 3449, 3457, 3461, 3463, 3467, 3469, 3491, 3499, 3511, 3517,
      3527, 3529, 3533, 3539, 3541, 3547, 3557, 3559, 3571, 3581, 3583, 3593, 3607, 3613, 3617,
      3623, 3631, 3637, 3643, 3659, 3671, 3673, 3677, 3691, 3697, 3701, 3709, 3719, 3727, 3733, 3739,
      3761, 3767, 3769, 3779, 3793, 3797, 3803, 3821, 3823, 3833, 3847, 3851, 3853, 3863, 3877, 3881, 3889,
      3907, 3911, 3917, 3919, 3923, 3929, 3931, 3943, 3947, 3967, 3989, 4001, 4003, 4007, 4013, 4019, 4021,
      4027, 4049, 4051, 4057, 4073, 4079, 4091, 4093, 4099, 4111, 4127, 4129, 4133, 4139, 4153, 4157, 4159,
      4177, 4201, 4211, 4217, 4219, 4229, 4231, 4241, 4243, 4253, 4259, 4261, 4271, 4273, 4283, 4289, 4297,
      4327, 4337, 4339, 4349, 4357, 4363, 4373, 4391, 4397, 4409, 4421, 4423, 4441, 4447, 4451, 4457, 4463,
      4481, 4483, 4493, 4507, 4513, 4517, 4519, 4523, 4547, 4549, 4561, 4567, 4583, 4591, 4597, 4603, 4621,
      4637, 4639, 4643, 4649, 4651, 4657, 4663, 4673, 4679, 4691, 4703, 4721, 4723, 4729, 4733, 4751, 4759,
      4783, 4787, 4789, 4793, 4799, 4801, 4813, 4817, 4831, 4861, 4871, 4877, 4889, 4903, 4909, 4919, 4931,
      4933, 4937, 4943, 4951, 4957, 4967, 4969, 4973, 4987, 4993, 4999};

  private static List<Integer> get(int a) {
    List<Integer> ps = new ArrayList<>();
    for(int prime : primes) {
      if(a%prime == 0) {
        while(a%prime == 0) a /= prime;
        ps.add(prime);
      }
    }
    if(a != 1) ps.add(a);
    return ps;
  }

  public static void main(String[] args) {
    int tc = 1;
    for(int t=0; t<tc; t++) {
      int n = scanner.nextInt();
      int q = scanner.nextInt();
      int[] a = id1(n);
      List<Integer>[] pss = new List[n];
      for(int i=0; i<n; i++) {
        pss[i] = get(a[i]);
      }

      int j = 0;
      int[][] f = new int[n+1][20];
      Set<Integer> ks = new HashSet<>();
      for(int i=0; i<n; i++) {
        for(int v : pss[i]) {
          while(ks.contains(v)) {
            f[j][0] = i;
            for(int v1 : pss[j]) ks.remove(v1);
            j++;
          }
          ks.add(v);
        }
      }
      for(; j<n+1; j++) f[j][0] = n;




      for(int i=1; i<20; i++) {
        for(j=0; j<=n; j++) {
          f[j][i] = f[f[j][i-1]][i-1];
        }
      }

      for(j=0; j<q; j++) {
        int l = scanner.nextInt()-1, r = scanner.nextInt()-1, res = 0;
        for(int i=19; i>=0; i--) {
          if(f[l][i] > r) continue;
          res += (1<<i);
          l = f[l][i];
        }
        out.println(res+1);
      }
    }
    out.close();
  }

  private static int[] id1(int n) {
    int[] a = new int[n];
    for(int i=0; i<n; i++) {
      a[i] = scanner.nextInt();
    }
    return a;
  }

  private static long[] id2(int n) {
    long[] a = new long[n];
    for(int i=0; i<n; i++) {
      a[i] = scanner.nextLong();
    }
    return a;
  }

  public static void print(Object o) {
    if(!oj) {
      out.println(o);
    }
  }

  

  public static long gcd(long a, long b) {
    if (a < b) return gcd(b,a);
    if (b == 0)
      return a;
    else
      return gcd(b,a%b);
  }

  private static long[] fac = new long[N+1];
  private static long[] invfac = new long[N+1];

  private static long fac(int n){
    if(n == 0) return fac[0] = 1;
    else if(fac[n] > 0) return fac[n];
    else return fac[n] = n * fac(n-1) % MOD;
  }

  private static long invfac(int n){
    if(invfac[n] > 0) return invfac[n];
    else return invfac[n] = inv(fac[n]);
  }

  private static long choose(int n, int k){
    return fac(n) * invfac(k) % MOD * invfac(n-k) % MOD;
  }

  private static long inv(long a){
    return (id0(a, MOD).key + MOD) % MOD;
  }

  private static Pair<Long, Long> id0(long a, long b){
    if(b > a) return id0(b, a).invert();
    else if(b == 0) return new Pair<>(1L, 0L);
    else{
      Pair<Long, Long> p = id0(b, a % b);
      return new Pair<>(p.key, p.key - p.value*(a/b));
    }
  }

  

  public static long power(long x, long y, long m) {
    if (y < 0) return 0L;
    long ans = 1;
    x %= m;
    while (y > 0) {
      if(y % 2 == 1)
        ans = (ans * x) % m;
      y /= 2;
      x = (x * x) % m;
    }
    return ans;
  }

  public static int[] shuffle(int[] array) {
    Random rgen = new Random();
    for (int i = 0; i < array.length; i++) {
      int randomPosition = rgen.nextInt(array.length);
      int temp = array[i];
      array[i] = array[randomPosition];
      array[randomPosition] = temp;
    }
    return array;
  }

  public static long[] shuffle(long[] array) {
    Random rgen = new Random();
    for (int i = 0; i < array.length; i++) {
      int randomPosition = rgen.nextInt(array.length);
      long temp = array[i];
      array[i] = array[randomPosition];
      array[randomPosition] = temp;
    }
    return array;
  }

  public static int[][] shuffle(int[][] array) {
    Random rgen = new Random();
    for (int i = 0; i < array.length; i++) {
      int randomPosition = rgen.nextInt(array.length);
      int[] temp = array[i];
      array[i] = array[randomPosition];
      array[randomPosition] = temp;
    }
    return array;
  }

  public static int[][] sort(int[][] array) {
    


    Arrays.sort(array, new Comparator<int[]>() {
      @Override
      public int compare(int[] a, int[] b) {
        return a[1]-b[1]; 

      }
    });
    return array;
  }

  public static long[][] sort(long[][] array) {
    

    Random rgen = new Random();
    for (int i = 0; i < array.length; i++) {
      int randomPosition = rgen.nextInt(array.length);
      long[] temp = array[i];
      array[i] = array[randomPosition];
      array[randomPosition] = temp;
    }
    Arrays.sort(array, new Comparator<long[]>() {
      @Override
      public int compare(long[] a, long[] b) {
        if (a[0] < b[0])
          return -1;
        else if (a[0] > b[0])
          return 1;
        else
          return 0;
      }
    });
    return array;
  }

  static class MyScanner {
    private BufferedReader br;
    private StringTokenizer st;

    MyScanner() {
      br = new BufferedReader(new InputStreamReader(System.in));
    }

    String next() {
      while (st == null || !st.hasMoreElements()) {
        try {
          st = new StringTokenizer(br.readLine());
        } catch (IOException e) {
          e.printStackTrace();
        }
      }
      return st.nextToken();
    }

    int nextInt() {
      return Integer.parseInt(next());
    }

    long nextLong() {
      return Long.parseLong(next());
    }

    double nextDouble() {
      return Double.parseDouble(next());
    }

    String nextLine(){
      String str = "";
      try {
        str = br.readLine();
      } catch (IOException e) {
        e.printStackTrace();
      }
      return str;
    }
  }

  static class Pair<K,V> {

    public K key;
    public V value;

    public Pair(K key, V value) {
      this.key = key;
      this.value = value;
    }

    @Override
    public String toString() {
      return key + ":" + value;
    }

    @Override
    public int hashCode() {
      return key.hashCode() * 13 + (value == null ? 0 : value.hashCode());
    }

    @Override
    public boolean equals(Object o) {
      if (this == o) return true;
      if (o instanceof Pair) {
        Pair pair = (Pair) o;
        return Objects.equals(key, pair.key) && Objects.equals(value, pair.value);
      }
      return false;
    }

    public Pair<V, K> invert() {
      return new Pair<>(value, key);
    }
  }

  static class Triple<A, B, C> {
    public A a;
    public B b;
    public C c;

    public Triple(A a, B b, C c) {
      this.a = a;
      this.b = b;
      this.c = c;
    }

    @Override
    public String toString() {
      return a + ":" + b + ":" + c;
    }

    @Override
    public int hashCode() {
      return (a == null ? 0 : a.hashCode()) * 13 + (b == null ? 0 : b.hashCode()) * 41 + (c == null ? 0 : c.hashCode());
    }

    @Override
    public boolean equals(Object o) {
      if (this == o) return true;
      if (o instanceof Triple) {
        Triple triple = (Triple) o;
        return Objects.equals(a, triple.a) && Objects.equals(b, triple.b) && Objects.equals(c, triple.c);
      }
      return false;
    }
  }
}