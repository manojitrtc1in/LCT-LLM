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

    static FastScanner scanner = new FastScanner();
    static FastPrinter printer = new FastPrinter();

    static void flush() {
        printer.flush();
    }

    static void print() {
        printer.println();
    }

    static <T> void print(T head) {
        printer.print(head + " ");
    }

    static <T> void println(T head) {
        printer.println(head);
    }

    static <T> void print(T... args) {
        for (T x : args) {
            print(x);
        }
    }

    static <T> void println(T... args) {
        for (T x : args) {
            print(x);
        }
        println();
    }

    static void read() {
    }

    static <T> void read(T head) {
    }

    static <T> void read(T... args) {
    }

    static void YES(boolean t) {
        println(t ? "YES" : "NO");
    }

    static void NO(boolean t) {
        YES(!t);
    }

    static void Yes(boolean t) {
        println(t ? "Yes" : "No");
    }

    static void No(boolean t) {
        Yes(!t);
    }

    static void yes(boolean t) {
        println(t ? "yes" : "no");
    }

    static void no(boolean t) {
        yes(!t);
    }

    static class modint {
        static final int mod = 1000000007;
        int val;

        modint(long val) {
            this.val = (int) (val >= 0 ? val % mod : (mod - (-val) % mod) % mod);
        }

        modint add(modint p) {
            val += p.val;
            if (val >= mod) {
                val -= mod;
            }
            return this;
        }

        modint subtract(modint p) {
            val += mod - p.val;
            if (val >= mod) {
                val -= mod;
            }
            return this;
        }

        modint multiply(modint p) {
            val = (int) (1L * val * p.val % mod);
            return this;
        }

        modint divide(modint p) {
            return multiply(p.inverse());
        }

        modint negate() {
            return new modint(mod - val);
        }

        modint add(modint p) {
            return new modint(val + p.val);
        }

        modint subtract(modint p) {
            return new modint(val + mod - p.val);
        }

        modint multiply(modint p) {
            return new modint(1L * val * p.val % mod);
        }

        modint divide(modint p) {
            return multiply(p.inverse());
        }

        boolean equals(modint p) {
            return val == p.val;
        }

        boolean notEquals(modint p) {
            return val != p.val;
        }

        modint inverse() {
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
            return new modint(u);
        }

        modint pow(long n) {
            modint ret = new modint(1);
            modint mul = new modint(val);
            while (n > 0) {
                if ((n & 1) == 1) {
                    ret.multiply(mul);
                }
                mul.multiply(mul);
                n >>= 1;
            }
            return ret;
        }
    }

    static class Group_Add {
        static class X {
            int val;

            X(int val) {
                this.val = val;
            }
        }

        static X op(X x, X y) {
            return new X(x.val + y.val);
        }

        static X inverse(X x) {
            return new X(-x.val);
        }

        static X power(X x, long n) {
            return new X(n * x.val);
        }

        static X unit() {
            return new X(0);
        }

        static boolean commute = true;
    }

    static class id2<Monoid> {
        int n, log, size;
        ArrayList<Monoid.X> laz;

        id2(int n) {
            this.n = n;
            log = 1;
            while ((1 << log) < n) {
                ++log;
            }
            size = 1 << log;
            laz = new ArrayList<>(size << 1);
            for (int i = 0; i < size << 1; i++) {
                laz.add(Group_Add.unit());
            }
        }

        void reset() {
            for (int i = 0; i < size << 1; i++) {
                laz.set(i, Group_Add.unit());
            }
        }

        void all_apply(int k, Monoid.X a) {
            laz.set(k, Group_Add.op(laz.get(k), a));
        }

        Monoid.X get(int p) {
            assert 0 <= p && p < n;
            p += size;
            for (int i = log; i >= 1; i--) {
                push(p >> i);
            }
            return laz.get(p);
        }

        ArrayList<Monoid.X> get_all() {
            for (int i = 0; i < size; i++) {
                push(i);
            }
            return new ArrayList<>(laz.subList(size, size + n));
        }

        void apply(int l, int r, Monoid.X a) {
            assert 0 <= l && l <= r && r <= n;
            if (l == r) {
                return;
            }

            l += size;
            r += size;

            if (!Group_Add.commute) {
                for (int i = log; i >= 1; i--) {
                    if (((l >> i) << i) != l) {
                        push(l >> i);
                    }
                    if (((r >> i) << i) != r) {
                        push((r - 1) >> i);
                    }
                }
            }

            int l2 = l, r2 = r;
            while (l < r) {
                if ((l & 1) == 1) {
                    all_apply(l++, a);
                }
                if ((r & 1) == 1) {
                    all_apply(--r, a);
                }
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        void debug() {
            println("dualsegtree getall:" + get_all());
        }

        private void push(int k) {
            all_apply(2 * k, laz.get(k));
            all_apply(2 * k + 1, laz.get(k));
            laz.set(k, Group_Add.unit());
        }
    }

    static void solve() {
        long N = scanner.nextLong();
        int mod = scanner.nextInt();
        modint.set_mod(mod);

        id2<Group_Add> seg = new id2<>(N + 1);

        ArrayList<mint> dp = new ArrayList<>(Collections.nCopies((int) (N + 1), new mint(0)));
        dp.set(1, new mint(1));
        for (int n = 1; n <= N; n++) {
            dp.set(n, dp.get(n).add(seg.get(n)));
            seg.apply(n + 1, (int) (N + 1), dp.get(n));
            long z = 2;
            while (true) {
                long l = n * z, r = (n + 1) * z;
                if (l > N) {
                    break;
                }
                ++z;
                r = Math.min(r, N + 1);
                seg.apply((int) l, (int) r, dp.get(n));
            }
        }

        println(dp.get(dp.size() - 1));
    }

    public static void main(String[] args) {
        int T = 1;

        for (int t = 0; t < T; t++) {
            solve();
        }

        flush();
    }
}
