import java.util.*;
import java.io.*;

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
            this.val = (val >= 0 ? val % mod : (mod - (-val) % mod) % mod);
        }

        ModInt add(ModInt p) {
            if ((val += p.val) >= mod) val -= mod;
            return this;
        }

        ModInt subtract(ModInt p) {
            if ((val += mod - p.val) >= mod) val -= mod;
            return this;
        }

        ModInt multiply(ModInt p) {
            val = (int) (1L * val * p.val % mod);
            return this;
        }

        ModInt divide(ModInt p) {
            return multiply(p.inverse());
        }

        ModInt negate() {
            return new ModInt(mod - val);
        }

        ModInt add(ModInt a, ModInt b) {
            return new ModInt(a.val).add(b);
        }

        ModInt subtract(ModInt a, ModInt b) {
            return new ModInt(a.val).subtract(b);
        }

        ModInt multiply(ModInt a, ModInt b) {
            return new ModInt(a.val).multiply(b);
        }

        ModInt divide(ModInt a, ModInt b) {
            return new ModInt(a.val).divide(b);
        }

        ModInt inverse() {
            int a = val, b = mod, u = 1, v = 0, t;
            while (b > 0) {
                t = a / b;
                int temp = a - t * b;
                a = b;
                b = temp;
                u -= t * v;
                int temp2 = u;
                u = v;
                v = temp2;
            }
            return new ModInt(u);
        }

        ModInt pow(long n) {
            ModInt ret = new ModInt(1);
            ModInt mul = new ModInt(val);
            while (n > 0) {
                if ((n & 1) == 1) {
                    ret.multiply(mul);
                }
                mul.multiply(mul);
                n >>= 1;
            }
            return ret;
        }

        static void setMod(int mod) {
            ModInt.mod = mod;
        }

        static int getMod() {
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
            Arrays.fill(laz, new ModInt(0));
        }

        void reset() {
            Arrays.fill(laz, new ModInt(0));
        }

        void allApply(int k, ModInt a) {
            laz[k] = laz[k].add(a);
        }

        ModInt get(int p) {
            assert (0 <= p && p < n);
            p += size;
            for (int i = log; i >= 1; i--) {
                push(p >> i);
            }
            return laz[p];
        }

        ModInt[] getAll() {
            for (int i = 0; i < size; i++) {
                push(i);
            }
            return Arrays.copyOfRange(laz, size, size + n);
        }

        void apply(int l, int r, ModInt a) {
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

        void debug() {
            System.out.println("dualsegtree getall:" + Arrays.toString(getAll()));
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
        seg.apply(1, 2, new ModInt(1));

        for (int n = 1; n <= N; n++) {
            ModInt dp = seg.get(n);
            seg.apply(n + 1, N + 1, dp);
            int z = 2;
            while (true) {
                int l = n * z, r = (n + 1) * z;
                if (l > N) {
                    break;
                }
                ++z;
                r = Math.min(r, N + 1);
                seg.apply(l, r, dp);
            }
        }
        System.out.println(seg.get(N).val);
    }

    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        FastPrinter fp = new FastPrinter();

        int T = 1;

        for (int t = 0; t < T; t++) {
            solve();
        }

        fp.flush();
    }
}
