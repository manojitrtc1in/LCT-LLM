import java.io.*;
import java.util.*;
import java.util.function.Function;

public class 7fa2ade1b040d6e63dd80ba9efe7cbb7xcodeeval_processed_4000.json {
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
                    throw new RuntimeException(e);
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
        }

        void println(Object... objects) {
            print(objects);
            out.println();
        }

        void flush() {
            out.flush();
        }
    }

    static class ModInt {
        static int mod;
        int val;

        public ModInt(long val) {
            this.val = (int) ((val % mod + mod) % mod);
        }

        public static void setMod(int m) {
            mod = m;
        }

        public ModInt add(ModInt other) {
            return new ModInt(val + other.val);
        }

        public ModInt subtract(ModInt other) {
            return new ModInt(val - other.val);
        }

        public ModInt multiply(ModInt other) {
            return new ModInt((long) val * other.val);
        }

        public ModInt inverse() {
            return new ModInt(modInverse(val, mod));
        }

        private static int modInverse(int a, int m) {
            int m0 = m, y = 0, x = 1;
            if (m == 1) return 0;
            while (a > 1) {
                int q = a / m;
                int t = m;
                m = a % m;
                a = t;
                t = y;
                y = x - q * y;
                x = t;
            }
            if (x < 0) x += m0;
            return x;
        }

        public ModInt pow(long n) {
            ModInt res = new ModInt(1);
            ModInt base = new ModInt(val);
            while (n > 0) {
                if ((n & 1) == 1) res = res.multiply(base);
                base = base.multiply(base);
                n >>= 1;
            }
            return res;
        }

        @Override
        public String toString() {
            return String.valueOf(val);
        }
    }

    static class SegmentTree {
        ModInt[] tree;
        int size;

        public SegmentTree(int n) {
            size = n;
            tree = new ModInt[n * 4];
            Arrays.fill(tree, new ModInt(0));
        }

        public void apply(int l, int r, ModInt value) {
            apply(1, 0, size, l, r, value);
        }

        private void apply(int node, int start, int end, int l, int r, ModInt value) {
            if (start >= r || end <= l) return;
            if (start >= l && end <= r) {
                tree[node] = tree[node].add(value);
                return;
            }
            int mid = (start + end) / 2;
            apply(node * 2, start, mid, l, r, value);
            apply(node * 2 + 1, mid, end, l, r, value);
        }

        public ModInt get(int index) {
            return get(1, 0, size, index);
        }

        private ModInt get(int node, int start, int end, int index) {
            if (start == end - 1) return tree[node];
            int mid = (start + end) / 2;
            if (index < mid) {
                return tree[node].add(get(node * 2, start, mid, index));
            } else {
                return tree[node].add(get(node * 2 + 1, mid, end, index));
            }
        }
    }

    public static void solve() {
        Scanner scanner = new Scanner(System.in);
        Printer printer = new Printer(System.out);

        long N = scanner.nextLong();
        int mod = scanner.nextInt();
        ModInt.setMod(mod);

        SegmentTree seg = new SegmentTree((int) N + 1);
        ModInt[] dp = new ModInt[(int) N + 1];
        dp[1] = new ModInt(1);

        for (int n = 1; n <= N; n++) {
            dp[n] = dp[n].add(seg.get(n));
            seg.apply(n + 1, (int) N + 1, dp[n]);

            long z = 2;
            while (true) {
                long l = n * z;
                long r = (n + 1) * z;
                if (l > N) break;
                z++;
                r = Math.min(r, N + 1);
                seg.apply((int) l, (int) r, dp[n]);
            }
        }

        printer.println(dp[(int) N]);
        printer.flush();
    }

    public static void main(String[] args) {
        solve();
    }
}
