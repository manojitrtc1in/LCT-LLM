import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.DecimalFormat;
import java.lang.reflect.Array;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.security.cert.TrustAnchor;

public class A {
    public static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    static long MOD = (long) (1e9 + 7);
    

    static long MOD2 = MOD * MOD;
    static FastReader sc = new FastReader();
    static int pInf = Integer.MAX_VALUE;
    static int nInf = Integer.MIN_VALUE;
    public static void main(String[] args) {
        int test = 1;
        test = sc.nextInt();
        while (test-- > 0) solve();
        out.flush();
        out.close();
    }
    public static void solve() {
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }
        int[] dec = new int[n];
        int[] inc = new int[n];
        dec[0] = a[0];
        inc[0] = 0;
        for(int i = 1; i < n; i++){
            dec[i] = Math.max(0,Math.min(dec[i-1],a[i]-inc[i-1]));
            inc[i] = a[i]-dec[i];
            if(dec[i]>dec[i-1]||inc[i]<inc[i-1]){
                out.println("NO");
                return;
            }
        }




        out.println("YES");
    }
    static class Node {
        ArrayList<Node> connect = new ArrayList<>();
        int comp = -1;

        public int gsize() {
            return connect.size();
        }
    }

    static long nC2(long n) {
        return add((n * (n + 1)) / 2, 0);
    }

    public static int maxRight(int x, int[] a) {
        int l = -1;      

        int r = a.length;

        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (a[m] <= x) {
                l = m;
            } else {
                r = m;
            }
        }
        return l + 1;
    }

    public static int minLeft(int x, int[] a) {
        int l = -1;      

        int r = a.length;

        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (a[m] < x) {
                l = m;
            } else {
                r = m;
            }
        }
        return r + 1;
    }

    public static int lowerBound(int key, int[] a) {
        int s = 0;
        int e = a.length - 1;
        if (e == -1) {
            return 0;
        }
        int ans = -1;
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (a[m] >= key) {
                ans = m;
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        return ans == -1 ? s : ans;
    }

    public static int upperBound(int key, int[] a) {
        int s = 0;
        int e = a.length - 1;
        if (e == -1) {
            return 0;
        }
        int ans = -1;
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (a[m] > key) {
                ans = m;
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        return ans == -1 ? s : ans;
    }

    public static long c2(long n) {
        if ((n & 1) == 0) {
            return mul(n / 2, n - 1);
        } else {
            return mul(n, (n - 1) / 2);
        }
    }

    public static long mul(long a, long b) {
        return ((a % MOD) * (b % MOD)) % MOD;
    }

    public static long add(long a, long b) {
        return ((a % MOD) + (b % MOD)) % MOD;
    }

    public static long sub(long a, long b) {
        return ((a % MOD) - (b % MOD)) % MOD;
    }

    

























    public static ArrayList<Long> primeFactors(long n) {
        ArrayList<Long> arr = new ArrayList<>();
        if (n % 2 == 0)
            arr.add((long) 2);
        while (n % 2 == 0)
            n /= 2;
        for (long i = 3; i <= Math.sqrt(n); i += 2) {
            int flag = 0;
            while (n % i == 0) {
                n /= i;
                flag = 1;
            }
            if (flag == 1)
                arr.add(i);
        }
        if (n > 2)
            arr.add(n);
        return arr;
    }

    

    static class Pair implements Comparable<Pair> {
        int x;
        int y;
        int len;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
            this.len = y - x + 1;
        }

        @Override
        public int compareTo(Pair o) {
            if (this.x == o.x) {
                return (this.y - o.y);
            }
            return -1 * (this.x - o.x);
        }
    }

    static class TPair implements Comparable<TPair> {
        int l;
        int r;
        long index;

        public TPair(int l, int r, long index) {
            this.l = l;
            this.r = r;
            this.index = index;
        }

        @Override
        public int compareTo(TPair o) {
            if (this.l == o.l) {
                return (this.r - o.r);
            }
            return -1 * (this.l - o.l);
        }
    }

    

    static long[] facts, factInvs;

    static long exp(long base, long e) {
        if (e == 0) return 1;
        long half = exp(base, e / 2);
        if (e % 2 == 0) return mul(half, half);
        return mul(half, mul(half, base));
    }

    static long modInv(long x) {
        return exp(x, MOD - 2);
    }

    static void precomp() {
        facts = new long[1_000_000];
        factInvs = new long[1_000_000];
        factInvs[0] = facts[0] = 1;
        for (int i = 1; i < facts.length; i++)
            facts[i] = mul(facts[i - 1], i);
        factInvs[facts.length - 1] = modInv(facts[facts.length - 1]);
        for (int i = facts.length - 2; i >= 0; i--)
            factInvs[i] = mul(factInvs[i + 1], i + 1);
    }

    static long nCk(int n, int k) {
        return mul(facts[n], mul(factInvs[k], factInvs[n - k]));
    }

    

    static long maxSubArraySum(ArrayList<Long> a) {
        if (a.size() == 0) {
            return 0;
        }
        long max_so_far = a.get(0);
        long curr_max = a.get(0);
        for (int i = 1; i < a.size(); i++) {
            curr_max = Math.max(a.get(i), curr_max + a.get(i));
            max_so_far = Math.max(max_so_far, curr_max);
        }
        return max_so_far;
    }

    

    static final Random random = new Random();

    static void ruffleSort(int[] a) {
        int n = a.length;

        for (int i = 0; i < n; i++) {
            int oi = random.nextInt(n), temp = a[oi];
            a[oi] = a[i];
            a[i] = temp;
        }
        Arrays.sort(a);
    }

    

    static void merge(long arr[], int l, int m, int r) {
        

        int n1 = m - l + 1;
        int n2 = r - m;

        
        long L[] = new long[n1];
        long R[] = new long[n2];

        
        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];


        

        

        int i = 0, j = 0;

        

        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    

    

    static void sort(long arr[], int l, int r) {
        if (l < r) {
            

            int m = (l + r) / 2;

            

            sort(arr, l, m);
            sort(arr, m + 1, r);

            

            merge(arr, l, m, r);
        }
    }

    

    static long countSetBits(long n) {
        if (n == 0) return 0;
        return 1 + countSetBits(n & (n - 1));
    }

    

    static long factorial(long n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 6;
        return n * factorial(n - 1);
    }

    

    static long gcd(long A, long B) {
        if (B == 0) return A;
        return gcd(B, A % B);
    }

    

    static long fastExpo(long x, long n) {
        if (n == 0) return 1;
        if ((n & 1) == 0) return fastExpo((x * x) % MOD, n / 2) % MOD;
        return ((x % MOD) * fastExpo((x * x) % MOD, (n - 1) / 2)) % MOD;
    }

    

    static boolean isPrime(long n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i <= Math.sqrt(n); i += 6)
            if (n % i == 0 || n % (i + 2) == 0) return false;
        return true;
    }

    

    static <T> void reverse(T arr[], int l, int r) {
        Collections.reverse(Arrays.asList(arr).subList(l, r));
    }

    

    static void print1d(long arr[]) {
        out.println(Arrays.toString(arr));
    }

    static void print2d(int arr[][]) {
        for (int a[] : arr) out.println(Arrays.toString(a));
    }

    

    static int[] findPrimes(int n) {
        boolean isPrime[] = new boolean[n + 1];
        ArrayList<Integer> a = new ArrayList<>();
        int result[];
        Arrays.fill(isPrime, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i * i <= n; ++i) {
            if (isPrime[i] == true) {
                for (int j = i * i; j <= n; j += i) isPrime[j] = false;
            }
        }
        for (int i = 0; i <= n; i++) if (isPrime[i] == true) a.add(i);
        result = new int[a.size()];
        for (int i = 0; i < a.size(); i++) result[i] = a.get(i);
        return result;

    }

    

    static ArrayList<Integer>[] indiFactors(int n) {
        ArrayList<Integer>[] A = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) {
            A[i] = new ArrayList<>();
        }
        int[] sieve = new int[n + 1];
        for (int i = 2; i <= n; i++) {
            if (sieve[i] == 0) {
                for (int j = i; j <= n; j += i)
                    if (sieve[j] == 0) {
                        

                        A[j].add(i);
                    }
            }
        }
        return A;
    }

    

    static boolean[] segmentedSieve(long l, long r) {
        boolean[] segSieve = new boolean[(int) (r - l + 1)];
        Arrays.fill(segSieve, true);
        int[] prePrimes = findPrimes((int) Math.sqrt(r));
        for (int p : prePrimes) {
            long low = (l / p) * p;
            if (low < l) {
                low += p;
            }
            if (low == p) {
                low += p;
            }
            for (long j = low; j <= r; j += p) {
                segSieve[(int) (j - l)] = false;
            }
        }
        if (l == 1) {
            segSieve[0] = false;
        }
        return segSieve;
    }

    

    static long countCoprimes(long n) {
        ArrayList<Long> prime_factors = new ArrayList<>();
        long x = n, flag = 0;
        while (x % 2 == 0) {
            if (flag == 0) prime_factors.add(2L);
            flag = 1;
            x /= 2;
        }
        for (long i = 3; i * i <= x; i += 2) {
            flag = 0;
            while (x % i == 0) {
                if (flag == 0) prime_factors.add(i);
                flag = 1;
                x /= i;
            }
        }
        if (x > 2) prime_factors.add(x);
        double ans = (double) n;
        for (Long p : prime_factors) {
            ans *= (1.0 - (Double) 1.0 / p);
        }
        return (long) ans;
    }

    static long modulo = (long) 1e9 + 7;

    public static long modinv(long x) {
        return modpow(x, modulo - 2);
    }

    public static long modpow(long a, long b) {
        if (b == 0) {
            return 1;
        }
        long x = modpow(a, b / 2);
        x = (x * x) % modulo;
        if (b % 2 == 1) {
            return (x * a) % modulo;
        }
        return x;
    }

    public static class FastReader {
        BufferedReader br;
        StringTokenizer st;
        

        


        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (Exception r) {
                    r.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());

        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (Exception r) {
                r.printStackTrace();
            }
            return str;
        }
    }
}