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

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    pw.print(' ');
                }
                pw.print(objects[i]);
            }
        }

        public void println(Object... objects) {
            print(objects);
            pw.println();
        }

        public void flush() {
            pw.flush();
        }
    }

    static FastScanner scanner = new FastScanner();
    static FastPrinter printer = new FastPrinter();

    public static void main(String[] args) {
        int T = 1;

        for (int t = 0; t < T; t++) {
            solve();
        }

        printer.flush();
    }

    static void solve() {
        int N = scanner.nextInt();
        int mod = scanner.nextInt();
        id4.set_mod(mod);

        id2<Group_Add<id4>> seg = new id2<>(N + 1);
        seg.apply(1, 2, new id4(1));

        for (int n = 1; n <= N; n++) {
            id4 dp = seg.get(n);
            seg.apply(n + 1, N + 1, dp);
            int z = 2;
            while (true) {
                int l = n * z, r = (n + 1) * z;
                if (l > N) break;
                z++;
                r = Math.min(r, N + 1);
                seg.apply(l, r, dp);
            }
        }
        printer.println(seg.get(N));
    }

    static class id2<Monoid extends Group_Add> {
        int n, log, size;
        id4[] laz;

        public id2(int n) {
            this.n = n;
            log = 1;
            while ((1 << log) < n) {
                log++;
            }
            size = 1 << log;
            laz = new id4[size << 1];
            for (int i = 0; i < laz.length; i++) {
                laz[i] = Monoid.unit();
            }
        }

        void reset() {
            Arrays.fill(laz, Monoid.unit());
        }

        void all_apply(int k, id4 a) {
            laz[k] = Monoid.op(laz[k], a);
        }

        id4 get(int p) {
            assert (0 <= p && p < n);
            p += size;
            for (int i = log; i >= 1; i--) {
                push(p >> i);
            }
            return laz[p];
        }

        id4[] get_all() {
            for (int i = 0; i < size; i++) {
                push(i);
            }
            return Arrays.copyOfRange(laz, size, size + n);
        }

        void apply(int l, int r, id4 a) {
            assert (0 <= l && l <= r && r <= n);
            if (l == r) return;

            l += size;
            r += size;

            if (!Monoid.commute) {
                for (int i = log; i >= 1; i--) {
                    if (((l >> i) << i) != l) push(l >> i);
                    if (((r >> i) << i) != r) push((r - 1) >> i);
                }
            }

            int l2 = l, r2 = r;
            while (l < r) {
                if ((l & 1) == 1) all_apply(l++, a);
                if ((r & 1) == 1) all_apply(--r, a);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        private void push(int k) {
            all_apply(2 * k, laz[k]);
            all_apply(2 * k + 1, laz[k]);
            laz[k] = Monoid.unit();
        }
    }

    static class Group_Add<id4> {
        static id4 op(id4 x, id4 y) {
            return (id4) x + y;
        }

        static id4 inverse(id4 x) {
            return (id4) -x;
        }

        static id4 power(id4 x, long n) {
            return (id4) (n * (long) x);
        }

        static id4 unit() {
            return (id4) 0;
        }

        static final boolean commute = true;
    }

    static class id4 {
        int val;

        public id4(int val) {
            this.val = val >= 0 ? val % get_mod() : (get_mod() - (-val) % get_mod()) % get_mod();
        }

        public static int get_mod() {
            return mod;
        }

        public static void set_mod(int md) {
            mod = md;
        }

        public id4 add(id4 p) {
            if ((val += p.val) >= get_mod()) val -= get_mod();
            return this;
        }

        public id4 subtract(id4 p) {
            if ((val += get_mod() - p.val) >= get_mod()) val -= get_mod();
            return this;
        }

        public id4 multiply(id4 p) {
            long a = (long) val * p.val;
            int xh = (int) (a >> 32), xl = (int) a, d, m;
            d = xh / get_mod();
            m = xh - d * get_mod();
            a = (long) m << 32 | xl;
            val = (int) (a % get_mod());
            return this;
        }

        public id4 divide(id4 p) {
            multiply(p.inverse());
            return this;
        }

        public id4 inverse() {
            int a = val, b = get_mod(), u = 1, v = 0, t;
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
            if (u < 0) u += get_mod();
            return new id4(u);
        }

        public id4 pow(long n) {
            id4 ret = new id4(1), mul = new id4(val);
            while (n > 0) {
                if ((n & 1) == 1) ret.multiply(mul);
                mul.multiply(mul);
                n >>= 1;
            }
            return ret;
        }
    }
}
