




































































import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.lang.invoke.MethodHandles;
import java.util.Random;
import java.util.StringTokenizer;

public class id1 {
    static final int MOD = 998244353;
    static final Random RAND = new Random();

    final static int[][] CO = computeCoeff();

    static final int LOW = 2000;
    static final Combination COMB = new Combination(LOW);

    static final long[] F = new long[2001];

    static int solveA(int n, int m, int k) {
        

        

        

        if (m == 1) {
            return power(n, k);
        }
        

        

        


        int a = (m + 1) / 2;
        int b = m / 2;

        long ans = 0;

        if (n <= LOW) {
            long v0 = (long)a * inverse(b) % MOD;
            long v1 = power(b, n);
            long v2 = v1;
            for (int e = 0; e <= n; e++) {
                long v = COMB.choose(n, e) * v2 % MOD;
                v2 = v2 * v0 % MOD;
                ans = (ans + v * power(e, k)) % MOD;
            }
            return (int) ans;
        }

        

        

        

        


        

        

        

        

        

        


        F[0] = power(m, n);
        long mul = 1;
        for (int j = 1; j <= k; j++) {
            mul = (mul * (n - j + 1) % MOD) * a % MOD;
            F[j] = mul * power(m, n-j) % MOD;
        }

        

        

        

        

        


        

        

        

        

        

        

        

        

        

        

        

        

        


        int[] co = CO[k];
        for (int i = 0; i < co.length; i++) {
            ans = (ans + co[i] * F[i]) % MOD;
        }
        return (int) ans;
    }

    

    static int[][] computeCoeff() {
        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        int[][] arr = new int[2001][];
        for (int i = 0; i < 2001; i++) {
            arr[i] = new int[i+1];
        }
        arr[0][0] = 1;
        for (int i = 1; i < 2001; i++) {
            for(int j = 1; j < i; j++) {
                arr[i][j] = (int) ((1L * arr[i-1][j] * j % MOD + arr[i-1][j-1]) % MOD);
            }
            arr[i][i] = 1;
            if (i < 20) {
                

            }
        }
        return arr;
    }

    

    public static int inverse(long a) {
        return power(a, MOD - 2);
    }

    

    public static int power(long x, int y) {
        if (y == 0) {
            return 1;
        }
        long w = power(x, y / 2);
        w = (w * w) % MOD;
        return (int) (y % 2 == 0 ? w : (w * x) % MOD);
    }

    static int solve(int n, int m, int k) {
        long a = (m + 1)/2;

        long q = a * inverse(m) % MOD;

        long ans = 0;
        long mul = 1;
        for (int i = 1; i <= k; i++) {
            mul = mul * q % MOD * (n-i+1) % MOD;
            ans = (ans + CO[k][i] * mul % MOD) % MOD;
        }
        return (int) (ans * power(m,n) % MOD);
    }

    static class Combination {
        final int n;
        int[] fact;
        int[] finv;

        public Combination(int n) {
            this.n = n;
            this.fact = new int[n+1];
            this.finv = new int[n+1];
            fact[0] = 1;
            finv[0] = 1;
            for (int i = 1; i <= n; i++) {
                fact[i] = (int) (((long) fact[i-1] * i) % MOD);
                finv[i] = (int) (((long) finv[i-1] * inverse(i)) % MOD);
            }
        }

        

        public int choose(int m, int k) {
            return (int) ((((long)fact[m] * finv[k] % MOD) * finv[m-k]) % MOD);
        }
    }

    private static long[][] id0(int N) {
        

        

        

        

        

        

        long[][] ta = new long[N][];
        for (int i = 0; i < N; i++) {
            ta[i] = new long[i+1];
            if (i == 0) {
                ta[i][0] = 1;
            } else {
                

                System.arraycopy(ta[i-1], 0, ta[i], 1, ta[i-1].length);
                for (int h = 0; h < i; h++) {
                    ta[i][h] = (ta[i][h] + MOD - (i-1) * ta[i-1][h] % MOD) % MOD;
                }
            }
            if (i < 10) {
                

            }
        }
        return ta;
    }

    static void test(int exp, int n, int m, int k) {
        int ans = solve(n, m, k);
        System.out.format("%9d %9d %9d => %d %s\n", n, m, k, ans, ans == exp ? "" : "Expected " + exp);
        myAssert(ans == exp);
    }

    static boolean test = false;
    static void doTest() {
        if (!test) {
            return;
        }
        long t0 = System.currentTimeMillis();
        


        test(485812953, 3825, 476, 2000);
        test(75131880, 1317, 8974, 2000);
        test(515879741, 9550, 4026, 2000);
        test(34049613, 8133, 129, 2000);
        test(631767740, 6429, 5211, 2000);
        test(330122212, 2715, 5907, 2000);
        test(31026911, 6815, 2681, 2000);
        test(772513405, 3674, 4043, 2000);
        test(546776189, 1614, 1664, 2000);
        test(273860898, 4845, 4622, 2000);
        test(987134517, 4568, 508, 2000);
        test(585535066, 6740, 4691, 2000);
        test(303481469, 8401, 2520, 2000);
        test(942774678, 5518, 1225, 2000);
        test(611130133, 5818, 6963, 2000);
        test(884718389, 409, 1798, 2000);
        test(61887968, 5932, 597, 2000);
        test(391461706, 2489, 8196, 2000);
        test(655612215, 9961, 4627, 2000);
        test(413770298, 2245, 6151, 2000);
        test(960818414, 2549, 2543, 2000);
        test(359085754, 743, 3202, 2000);
        test(298890537, 6032, 67, 2000);
        test(313703051, 5605, 7867, 2000);
        test(82535400, 8935, 7951, 2000);
        test(379388626, 2411, 123, 2000);
        test(351929892, 7627, 4689, 2000);
        test(636574771, 5579, 2554, 2000);
        test(812449761, 7330, 340, 2000);
        test(742447387, 5176, 4410, 2000);
        test(762551061, 6781, 7020, 2000);
        test(591374949, 2447, 7826, 2000);
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
            int k = in.nextInt();
            int ans = solve(n, m, k);
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
