import java.io.*;
import java.util.*;
import java.util.function.*;

class Main {
    static class Mint {
        static int mod;
        int val;

        Mint(long val) {
            this.val = (int) ((val % mod + mod) % mod);
        }

        static void setMod(int m) {
            mod = m;
        }

        Mint add(Mint other) {
            return new Mint(val + other.val);
        }

        Mint subtract(Mint other) {
            return new Mint(val - other.val);
        }

        Mint multiply(Mint other) {
            return new Mint((long) val * other.val);
        }

        Mint inverse() {
            int a = val, b = mod, u = 1, v = 0, t;
            while (b > 0) {
                t = a / b;
                a -= t * b;
                int temp = u; u -= t * v; v = temp;
                int temp2 = a; a = b; b = temp2;
            }
            return new Mint(u);
        }

        Mint pow(long n) {
            Mint ret = new Mint(1);
            Mint mul = new Mint(val);
            while (n > 0) {
                if ((n & 1) != 0) ret = ret.multiply(mul);
                mul = mul.multiply(mul);
                n >>= 1;
            }
            return ret;
        }
    }

    static class DualSegTree {
        private final int n;
        private final int size;
        private final Mint[] laz;

        DualSegTree(int n) {
            this.n = n;
            int log = 1;
            while ((1 << log) < n) log++;
            this.size = 1 << log;
            laz = new Mint[size << 1];
            Arrays.fill(laz, new Mint(0));
        }

        void allApply(int k, Mint a) {
            laz[k] = laz[k].add(a);
        }

        Mint get(int p) {
            p += size;
            for (int i = (int) (Math.log(size) / Math.log(2)); i >= 1; i--) push(p >> i);
            return laz[p];
        }

        void apply(int l, int r, Mint a) {
            l += size;
            r += size;
            while (l < r) {
                if ((l & 1) != 0) allApply(l++, a);
                if ((r & 1) != 0) allApply(--r, a);
                l >>= 1;
                r >>= 1;
            }
        }

        private void push(int k) {
            allApply(2 * k, laz[k]);
            allApply(2 * k + 1, laz[k]);
            laz[k] = new Mint(0);
        }
    }

    static void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long N = Long.parseLong(st.nextToken());
        int mod = Integer.parseInt(st.nextToken());
        Mint.setMod(mod);

        DualSegTree seg = new DualSegTree((int) N + 1);
        Mint[] dp = new Mint[(int) N + 1];
        dp[1] = new Mint(1);

        for (int n = 1; n <= N; n++) {
            dp[n] = dp[n].add(seg.get(n));
            seg.apply(n + 1, (int) N + 1, dp[n]);
            long z = 2;
            while (true) {
                long l = n * z, r = (n + 1) * z;
                if (l > N) break;
                z++;
                r = Math.min(r, N + 1);
                seg.apply((int) l, (int) r, dp[n]);
            }
        }

        System.out.println(dp[(int) N]);
    }

    public static void main(String[] args) throws IOException {
        solve();
    }
}
