import java.io.*;
import java.util.*;
import java.util.function.Function;

public class 8289b8e19371f85195a43a39736a559bxcodeeval_processed_4000.json {
    static class Scanner {
        BufferedReader br;
        StringTokenizer st;

        public Scanner(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
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

        String nextString() {
            return next();
        }
    }

    static class Printer {
        PrintWriter out;

        public Printer(OutputStream stream) {
            out = new PrintWriter(stream);
        }

        void print(Object... objects) {
            for (Object obj : objects) {
                out.print(obj + " ");
            }
            out.flush();
        }

        void println(Object... objects) {
            print(objects);
            out.println();
        }
    }

    static class ModInt {
        static int mod;
        int val;

        ModInt(long val) {
            this.val = (int) ((val % mod + mod) % mod);
        }

        static void setMod(int m) {
            mod = m;
        }

        ModInt add(ModInt other) {
            return new ModInt(val + other.val);
        }

        ModInt subtract(ModInt other) {
            return new ModInt(val - other.val);
        }

        ModInt multiply(ModInt other) {
            return new ModInt((long) val * other.val);
        }

        ModInt inverse() {
            int a = val, b = mod, u = 1, v = 0, t;
            while (b > 0) {
                t = a / b;
                a -= t * b;
                int temp = u;
                u -= t * v;
                v = temp;
                int temp2 = a;
                a = b;
                b = temp2;
            }
            return new ModInt(u);
        }

        ModInt divide(ModInt other) {
            return multiply(other.inverse());
        }

        @Override
        public String toString() {
            return String.valueOf(val);
        }
    }

    static class SegmentTree {
        ModInt[] laz;
        int n, log, size;

        SegmentTree(int n) {
            this.n = n;
            log = 1;
            while ((1 << log) < n) log++;
            size = 1 << log;
            laz = new ModInt[size << 1];
            Arrays.fill(laz, new ModInt(0));
        }

        void apply(int l, int r, ModInt a) {
            l += size;
            r += size;
            while (l < r) {
                if (l % 2 == 1) laz[l++] = laz[l].add(a);
                if (r % 2 == 1) laz[--r] = laz[r].add(a);
                l >>= 1;
                r >>= 1;
            }
        }

        ModInt get(int p) {
            p += size;
            for (int i = log; i >= 1; i--) push(p >> i);
            return laz[p];
        }

        void push(int k) {
            laz[2 * k] = laz[2 * k].add(laz[k]);
            laz[2 * k + 1] = laz[2 * k + 1].add(laz[k]);
            laz[k] = new ModInt(0);
        }
    }

    static void solve(Scanner scanner, Printer printer) {
        long N = scanner.nextLong();
        int mod = scanner.nextInt();
        ModInt.setMod(mod);

        SegmentTree seg = new SegmentTree((int) N + 1);
        seg.apply(1, 2, new ModInt(1));

        for (int n = 1; n <= N; n++) {
            ModInt dp = seg.get(n);
            seg.apply(n + 1, (int) N + 1, dp);
            long z = 2;
            while (true) {
                long l = n * z, r = (n + 1) * z;
                if (l > N) break;
                z++;
                r = Math.min(r, N + 1);
                seg.apply((int) l, (int) r, dp);
            }
        }
        printer.println(seg.get((int) N));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Printer printer = new Printer(System.out);

        int T = 1;
        for (int i = 0; i < T; i++) {
            solve(scanner, printer);
        }
    }
}
