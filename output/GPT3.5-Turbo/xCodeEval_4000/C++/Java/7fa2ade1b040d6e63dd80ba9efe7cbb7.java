import java.io.*;
import java.util.*;

class Main {
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
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

    static class FastPrinter {
        PrintWriter pw;

        public FastPrinter() {
            pw = new PrintWriter(System.out);
        }

        void print(String str) {
            pw.print(str);
        }

        void println(String str) {
            pw.println(str);
        }

        void println() {
            pw.println();
        }

        void flush() {
            pw.flush();
        }
    }

    static class ModInt {
        static int mod;
        int val;

        public ModInt(int val) {
            this.val = val >= 0 ? val % mod : (mod - (-val) % mod) % mod;
        }

        public ModInt add(ModInt p) {
            int res = val + p.val;
            if (res >= mod) {
                res -= mod;
            }
            return new ModInt(res);
        }

        public ModInt subtract(ModInt p) {
            int res = val - p.val;
            if (res < 0) {
                res += mod;
            }
            return new ModInt(res);
        }

        public ModInt multiply(ModInt p) {
            long res = (long) val * p.val % mod;
            return new ModInt((int) res);
        }

        public ModInt divide(ModInt p) {
            return multiply(p.inverse());
        }

        public ModInt inverse() {
            int a = val, b = mod, u = 1, v = 0, t;
            while (b > 0) {
                t = a / b;
                a -= t * b;
                u -= t * v;
                t = a;
                a = b;
                b = t;
                t = u;
                u = v;
                v = t;
            }
            u %= mod;
            if (u < 0) {
                u += mod;
            }
            return new ModInt(u);
        }

        public ModInt pow(long n) {
            ModInt ret = new ModInt(1);
            ModInt mul = new ModInt(val);
            while (n > 0) {
                if ((n & 1) == 1) {
                    ret = ret.multiply(mul);
                }
                mul = mul.multiply(mul);
                n >>= 1;
            }
            return ret;
        }

        public static void setMod(int mod) {
            ModInt.mod = mod;
        }

        public static int getMod() {
            return mod;
        }
    }

    static class DualSegTree {
        int n, log, size;
        ModInt[] laz;

        public DualSegTree(int n) {
            this.n = n;
            log = 1;
            while ((1 << log) < n) {
                ++log;
            }
            size = 1 << log;
            laz = new ModInt[size << 1];
            for (int i = 0; i < laz.length; i++) {
                laz[i] = new ModInt(0);
            }
        }

        public void reset() {
            for (int i = 0; i < laz.length; i++) {
                laz[i] = new ModInt(0);
            }
        }

        public void allApply(int k, ModInt a) {
            laz[k] = laz[k].add(a);
        }

        public ModInt get(int p) {
            assert (0 <= p && p < n);
            p += size;
            for (int i = log; i >= 1; i--) {
                push(p >> i);
            }
            return laz[p];
        }

        public ModInt[] getAll() {
            for (int i = 0; i < size; i++) {
                push(i);
            }
            ModInt[] res = new ModInt[n];
            System.arraycopy(laz, size, res, 0, n);
            return res;
        }

        public void apply(int l, int r, ModInt a) {
            assert (0 <= l && l <= r && r <= n);
            if (l == r) {
                return;
            }

            l += size;
            r += size;

            if (true) {
                for (int i = log; i >= 1; i--) {
                    if (((l >> i) << i) != l) {
                        push(l >> i);
                    }
                    if (((r >> i) << i) != r) {
                        push((r - 1) >> i);
                    }
                }
            }

            {
                int l2 = l, r2 = r;
                while (l < r) {
                    if ((l & 1) == 1) {
                        allApply(l++, a);
                    }
                    if ((r & 1) == 1) {
                        allApply(--r, a);
                    }
                    l >>= 1;
                    r >>= 1;
                }
                l = l2;
                r = r2;
            }
        }

        private void push(int k) {
            allApply(2 * k, laz[k]);
            allApply(2 * k + 1, laz[k]);
            laz[k] = new ModInt(0);
        }
    }

    static void solve() {
        int N = fs.nextInt();
        int mod = fs.nextInt();
        ModInt.setMod(mod);

        DualSegTree seg = new DualSegTree(N + 1);

        ModInt[] dp = new ModInt[N + 1];
        dp[1] = new ModInt(1);
        for (int n = 1; n <= N; n++) {
            dp[n] = dp[n].add(seg.get(n));
            seg.apply(n + 1, N + 1, dp[n]);
            long z = 2;
            while (true) {
                long l = n * z, r = (n + 1) * z;
                if (l > N) {
                    break;
                }
                ++z;
                r = Math.min(r, N + 1);
                seg.apply((int) l, (int) r, dp[n]);
            }
        }

        out.println(dp[N]);
    }

    static FastScanner fs = new FastScanner();
    static FastPrinter out = new FastPrinter();

    public static void main(String[] args) {
        int T = 1;

        for (int t = 0; t < T; t++) {
            solve();
        }

        out.flush();
    }
}
