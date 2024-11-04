import java.util.*;
import java.io.*;

class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
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

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static class Mint {
        static int mod;
        int v;

        public Mint(int v) {
            this.v = v;
        }

        public static void setMod(int m) {
            mod = m;
        }

        public static Mint raw(int v) {
            return new Mint(v);
        }

        public int val() {
            return v;
        }

        public Mint add(Mint other) {
            v += other.v;
            if (v >= mod) v -= mod;
            return this;
        }

        public Mint subtract(Mint other) {
            v += mod - other.v;
            if (v >= mod) v -= mod;
            return this;
        }

        public Mint multiply(Mint other) {
            long z = (long) v * other.v;
            v = (int) (z % mod);
            return this;
        }

        public Mint divide(Mint other) {
            return this.multiply(other.inverse());
        }

        public Mint increment() {
            v++;
            if (v == mod) v = 0;
            return this;
        }

        public Mint decrement() {
            if (v == 0) v = mod;
            v--;
            return this;
        }

        public Mint inverse() {
            int a = v, b = mod, u = 0, v = 1;
            while (a != 0) {
                int t = b / a;
                b -= t * a;
                u -= t * v;
                int temp = a;
                a = b;
                b = temp;
                temp = u;
                u = v;
                v = temp;
            }
            if (u < 0) u += mod / b;
            return new Mint(u);
        }

        public Mint pow(long n) {
            Mint x = new Mint(v), r = new Mint(1);
            while (n > 0) {
                if ((n & 1) == 1) r.multiply(x);
                x.multiply(x);
                n >>= 1;
            }
            return r;
        }

        public static Mint operatorPlus(Mint a, Mint b) {
            return new Mint(a.v).add(b);
        }

        public static Mint operatorMinus(Mint a, Mint b) {
            return new Mint(a.v).subtract(b);
        }

        public static Mint operatorMultiply(Mint a, Mint b) {
            return new Mint(a.v).multiply(b);
        }

        public static Mint operatorDivide(Mint a, Mint b) {
            return new Mint(a.v).divide(b);
        }

        public static boolean operatorEquals(Mint a, Mint b) {
            return a.v == b.v;
        }

        public static boolean operatorNotEquals(Mint a, Mint b) {
            return a.v != b.v;
        }
    }

    public static void solve() {
        FastReader sc = new FastReader();
        int n = sc.nextInt();
        int m = sc.nextInt();

        Mint.setMod(m);

        Mint[] dp = new Mint[n + 1];
        Mint[] p = new Mint[n + 1];

        dp[n] = Mint.raw(1);
        p[n] = Mint.raw(1);

        for (int i = n - 1; i >= 1; i--) {
            dp[i] = dp[i].add(p[i + 1]);

            for (int z = 2; z * i <= n; z++) {
                int r = i * z + z;
                int l = z * i;
                dp[i] = dp[i].add(p[l]);
                if (r <= n) dp[i] = dp[i].subtract(p[r]);
            }

            p[i] = p[i + 1].add(dp[i]);
        }

        System.out.println(dp[1].val());
    }

    public static void main(String[] args) {
        int t = 1;

        while (t-- > 0) {
            solve();
        }
    }
}
