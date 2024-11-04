import java.io.*;
import java.util.*;

public class Solution {

    

    static final int MOD = (int) (1e9 + 7);
    static final int IMAX = 0x7fffffff;
    static final int IMIN = 0x80000000;
    static final long LMAX = 0x7fffffffffffffffL;
    static final long LMIN = -0x8000000000000000L;
    

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;
    public static PrintWriter out;
    public static FastReader in;

    public static void main(String[] args) throws IOException {
        long s = System.currentTimeMillis();
        in = new FastReader();
        out = new PrintWriter(System.out);


        pre();
        int t = 1;
        t = ni();
        for (int i = 1; i <= t; i++) {


            solve();
        }
        out.flush();
        tr(System.currentTimeMillis() - s + "ms");
    }

    private static void pre() {
    }

    private static void solve() {
        long[] a = nal(7);
        Arrays.sort(a);
        long a1 = a[0];
        long a23 = a[6] - a1;
        HashSet<Long> set = new HashSet<>();
        for (int i = 1; i < 6; i++) {
            set.add(a[i]);
        }

        for (int i = 1; i < 6; i++) {
            if (set.contains(a23 - a[i])) {
                out.println(a1 + " " + a[i] + " " + (a23 - a[i]));
                return;
            }
        }
    }

    

    private static int ni() {
        return in.nextInt();
    }

    private static String ns() {
        return in.next();
    }

    private static int[] na(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = ni();
        return a;
    }

    private static long[] nal(int n) {
        long[] a = new long[n];
        for (int i = 0; i < n; i++) a[i] = nl();
        return a;
    }

    private static long nl() {
        return in.nextLong();
    }

    private static double nd() {
        return in.nextDouble();
    }

    private static void print(char[] a) {
        for (char x : a) out.print(x + " ");
        out.println();
    }

    private static void print(int[] a) {
        for (int x : a) System.out.print(x + " ");
        System.out.println();
    }

    private static void print(long[] a) {
        for (long x : a) out.print(x + " ");
        out.println();
    }

    


    private int[][] preFixSum(int[][] a) {
        int R = a.length;
        int C = a[0].length;
        int[][] psa = new int[R][C];
        psa[0][0] = a[0][0];
        for (int i = 1; i < C; i++)
            psa[0][i] = psa[0][i - 1] + a[0][i];
        for (int i = 1; i < R; i++)
            psa[i][0] = psa[i - 1][0] + a[i][0];
        for (int i = 1; i < R; i++)
            for (int j = 1; j < C; j++)
                psa[i][j] = psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1] + a[i][j];
        return psa;
    }

    public static int getSum(int r1, int c1, int r2, int c2, int[][] sum) {
        r1++;
        c1++;
        r2++;
        c2++;
        return sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1];
    }

    static void reverse(int[] a) {
        for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {
            int swap = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = swap;
        }
    }

    static void reverse(long[] a) {
        for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {
            long swap = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = swap;
        }
    }

    static void reverse(char[] a) {
        for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {
            char swap = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = swap;
        }
    }

    static int[] copy(int[] a) {
        int[] ans = new int[a.length];
        for (int i = 0; i < a.length; ++i) ans[i] = a[i];
        return ans;
    }

    static long[] copy(long[] a) {
        long[] ans = new long[a.length];
        for (int i = 0; i < a.length; ++i) ans[i] = a[i];
        return ans;
    }

    static char[] copy(char[] a) {
        char[] ans = new char[a.length];
        for (int i = 0; i < a.length; ++i) ans[i] = a[i];
        return ans;
    }

    static int min(int... x) {
        if (x.length == 1) return x[0];
        if (x.length == 2) return Math.min(x[0], x[1]);
        if (x.length == 3) return Math.min(x[0], Math.min(x[1], x[2]));
        int min = x[0];
        for (int i = 1; i < x.length; ++i) if (x[i] < min) min = x[i];
        return min;
    }

    static long min(long... x) {
        if (x.length == 1) return x[0];
        if (x.length == 2) return Math.min(x[0], x[1]);
        if (x.length == 3) return Math.min(x[0], Math.min(x[1], x[2]));
        long min = x[0];
        for (int i = 1; i < x.length; ++i) if (x[i] < min) min = x[i];
        return min;
    }

    

    static int max(int... x) {
        if (x.length == 1) return x[0];
        if (x.length == 2) return Math.max(x[0], x[1]);
        if (x.length == 3) return Math.max(x[0], Math.max(x[1], x[2]));
        return Arrays.stream(x).max().getAsInt();
    }

    static long max(long... x) {
        if (x.length == 1) return x[0];
        if (x.length == 2) return Math.max(x[0], x[1]);
        if (x.length == 3) return Math.max(x[0], Math.max(x[1], x[2]));
        long max = x[0];
        for (int i = 1; i < x.length; ++i) if (x[i] > max) max = x[i];
        return max;
    }

    static int pow(int a, int b) {
        if (a == 0) return 0;
        int ans = 1;
        while (b > 0) {
            if ((b & 1) > 0) ans *= a;
            a *= a;
            b >>= 1;
        }
        return ans;
    }

    static long pow(long a, int b) {
        if (a == 0) return 0;
        long ans = 1;
        while (b > 0) {
            if ((b & 1) > 0) ans *= a;
            a *= a;
            b >>= 1;
        }
        return ans;
    }

    static long power(long x, int y, int p) {
        long res = 1;
        x = x % p;
        if (x == 0) return 0;
        while (y > 0) {
            if ((y & 1) != 0)
                res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }

    static long modInverse(long n, int p) {
        return power(n, p - 2, p);
    }

    static long modInverse(int n, int p) {
        return power(n, p - 2, p);
    }

    static long nCrModPFermat(int n, int r, int p) {
        if (n < r)
            return 0;
        if (r == 0)
            return 1;
        int[] fac = new int[n + 1];
        fac[0] = 1;
        for (int i = 1; i <= n; i++)
            fac[i] = fac[i - 1] * i % p;
        return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
    }

    static boolean isPrime(long n) {
        for (long i = 2; i * i <= n; i++) if (n % i == 0) return false;
        return true;
    }

    public static long gcd(long a, long b) {
        while (b != 0) {
            a %= b;
            long t = a;
            a = b;
            b = t;
        }
        return a;
    }

    private static boolean sorted(int[] a) {
        for (int i = 0; i < a.length - 1; i++) {
            if (a[i] > a[i + 1]) return false;
        }
        return true;
    }

    private static boolean sorted(long[] a) {
        for (int i = 0; i < a.length - 1; i++) {
            if (a[i] > a[i + 1]) return false;
        }
        return true;
    }

    private static boolean sorted(char[] a) {
        for (int i = 0; i < a.length - 1; i++) {
            if (a[i] > a[i + 1]) return false;
        }
        return true;
    }

    public static int lowerBound(int[] a, int element) {
        int low = -1, high = a.length;
        while (low < high) {
            int middle = low + (high - low) / 2;
            if (element > a[middle]) {
                low = middle + 1;
            } else {
                high = middle;
            }
        }
        return low;
    }

    static int upperBound(int[] a, int element) {
        int low = -1, high = a.length;
        while (low < high) {
            int middle = low + (high - low) / 2;
            if (a[middle] > element) {
                high = middle;
            } else {
                low = middle + 1;
            }
        }
        return low;
    }

    public static int[] facs(int n, int[] primes) {
        int[] ret = new int[9];
        int rp = 0;
        for (int p : primes) {
            if (p * p > n) break;
            int i;
            i = 0;
            while (n % p == 0) {
                n /= p;
                i++;
            }
            if (i > 0) ret[rp++] = p;
        }
        if (n != 1) ret[rp++] = n;
        return Arrays.copyOf(ret, rp);
    }

    public static int[] sieveEratosthenes(int n) {
        if (n <= 32) {
            int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
            for (int i = 0; i < primes.length; i++) {
                if (n < primes[i]) {
                    return Arrays.copyOf(primes, i);
                }
            }
            return primes;
        }

        int u = n + 32;
        double lu = Math.log(u);
        int[] ret = new int[(int) (u / lu + u / lu / lu * 1.5)];
        ret[0] = 2;
        int pos = 1;

        int[] isnp = new int[(n + 1) / 32 / 2 + 1];
        int sup = (n + 1) / 32 / 2 + 1;

        int[] tprimes = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        for (int tp : tprimes) {
            ret[pos++] = tp;
            int[] ptn = new int[tp];
            for (int i = (tp - 3) / 2; i < tp << 5; i += tp) ptn[i >> 5] |= 1 << (i & 31);
            for (int j = 0; j < sup; j += tp) {
                for (int i = 0; i < tp && i + j < sup; i++) {
                    isnp[j + i] |= ptn[i];
                }
            }
        }

        

        

        int[] magic = {
                0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13, 31, 22, 28, 18, 26, 10, 7, 12, 21,
                17, 9, 6, 16, 5, 15, 14
        };
        int h = n / 2;
        for (int i = 0; i < sup; i++) {
            for (int j = ~isnp[i]; j != 0; j &= j - 1) {
                int pp = i << 5 | magic[(j & -j) * 0x076be629 >>> 27];
                int p = 2 * pp + 3;
                if (p > n) break;
                ret[pos++] = p;
                if ((long) p * p > n) continue;
                for (int q = (p * p - 3) / 2; q <= h; q += p) isnp[q >> 5] |= 1 << q;
            }
        }

        return Arrays.copyOf(ret, pos);
    }

    private static int[][] uniqCount(int[] a) {
        int n = a.length;
        int p = 0;
        int[][] b = new int[n][];
        for (int i = 0; i < n; i++) {
            if (i == 0 || a[i] != a[i - 1]) b[p++] = new int[]{a[i], 0};
            b[p - 1][1]++;
        }
        return Arrays.copyOf(b, p);
    }

    private static long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }

    public static int[][] enumPrimesAndLPF(int n) {
        int[] lpf = new int[n + 1];
        double lu = Math.log(n + 32);

        int tot = 0;
        int[] primes = new int[(int) ((n + 32) / lu + (n + 32) / lu / lu * 1.5)];

        for (int i = 2; i <= n; i++) {
            lpf[i] = i;
        }

        for (int p = 2, tmp; p <= n; p++) {
            if (lpf[p] == p) {
                primes[tot++] = p;
            }
            for (int i = 0; i < tot && primes[i] <= lpf[p] && (tmp = primes[i] * p) <= n; i++) {
                lpf[tmp] = primes[i];
            }
        }

        return new int[][]{Arrays.copyOf(primes, tot), lpf};
    }

    public static int[] enumPrimes(int n) {
        int[] lpf = new int[n + 1];
        double lu = Math.log(n + 32);

        int tot = 0;
        int[] primes = new int[(int) ((n + 32) / lu + (n + 32) / lu / lu * 1.5)];

        for (int i = 2; i <= n; i++) {
            lpf[i] = i;
        }

        for (int p = 2, tmp; p <= n; p++) {
            if (lpf[p] == p) {
                primes[tot++] = p;
            }
            for (int i = 0; i < tot && primes[i] <= lpf[p] && (tmp = primes[i] * p) <= n; i++) {
                lpf[tmp] = primes[i];
            }
        }

        return Arrays.copyOf(primes, tot);
    }

    static boolean isPrime(int n) {
        for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
        return true;
    }

    private static void tr(Object... o) {
        if (!oj) System.out.println(Arrays.deepToString(o));
    }

    public String isSubset(long[] a1, long[] a2, long n, long m) {
        HashMap<Long, Integer> a1Map = new HashMap<>();
        HashMap<Long, Integer> a2Map = new HashMap<>();
        for (long x : a1) {
            a1Map.putIfAbsent(x, 0);
            a1Map.put(x, 1 + a1Map.get(x));
        }
        for (long x : a2) {
            a2Map.putIfAbsent(x, 0);
            a2Map.put(x, 1 + a2Map.get(x));
        }
        for (Map.Entry<Long, Integer> entry : a2Map.entrySet()) {
            if (!a1Map.containsKey(entry.getKey()) || entry.getValue() > a1Map.get(entry.getKey())) {
                return "No";
            }
        }
        return "Yes";
    }

    public int countOccurence(int[] arr, int n, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int x : arr) {
            map.putIfAbsent(x, 0);
            map.put(x, 1 + map.get(x));
        }
        int cnt = 0;
        for (int x : map.values()) {
            if (x >= n / k) cnt++;
        }
        return cnt;
    }

    private float nf() {
        return (float) in.nextDouble();
    }

    

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() throws FileNotFoundException {
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
    }
}