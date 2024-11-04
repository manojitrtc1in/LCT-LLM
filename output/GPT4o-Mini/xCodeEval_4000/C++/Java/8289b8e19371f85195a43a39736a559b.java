import java.io.*;
import java.util.*;
import java.util.function.*;

public class 8289b8e19371f85195a43a39736a559b_nc {
    static class Mint {
        static int mod;
        int val;

        public Mint(long val) {
            this.val = (int) ((val % mod + mod) % mod);
        }

        public static void setMod(int m) {
            mod = m;
        }

        public Mint add(Mint other) {
            return new Mint(this.val + other.val);
        }

        public Mint sub(Mint other) {
            return new Mint(this.val - other.val);
        }

        public Mint mul(Mint other) {
            return new Mint((long) this.val * other.val);
        }

        public Mint inv() {
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
            return new Mint(u);
        }

        public Mint pow(long n) {
            Mint ret = new Mint(1);
            Mint mul = new Mint(val);
            while (n > 0) {
                if ((n & 1) == 1) ret = ret.mul(mul);
                mul = mul.mul(mul);
                n >>= 1;
            }
            return ret;
        }

        @Override
        public String toString() {
            return String.valueOf(val);
        }
    }

    static class DualSegTree {
        private final int n;
        private final int size;
        private final Mint[] laz;

        public DualSegTree(int n) {
            this.n = n;
            int log = 1;
            while ((1 << log) < n) log++;
            this.size = 1 << log;
            laz = new Mint[size << 1];
            Arrays.fill(laz, new Mint(0));
        }

        public void apply(int l, int r, Mint a) {
            if (l == r) return;

            l += size;
            r += size;

            while (l < r) {
                if ((l & 1) == 1) laz[l++] = laz[l].add(a);
                if ((r & 1) == 1) laz[--r] = laz[r].add(a);
                l >>= 1;
                r >>= 1;
            }
        }

        public Mint get(int p) {
            p += size;
            for (int i = 1; i < laz.length; i++) {
                push(p >> i);
            }
            return laz[p];
        }

        private void push(int k) {
            laz[2 * k] = laz[2 * k].add(laz[k]);
            laz[2 * k + 1] = laz[2 * k + 1].add(laz[k]);
            laz[k] = new Mint(0);
        }
    }

    public static void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long N = Long.parseLong(st.nextToken());
        int mod = Integer.parseInt(st.nextToken());
        Mint.setMod(mod);

        DualSegTree seg = new DualSegTree((int) N + 1);
        seg.apply(1, 2, new Mint(1));

        for (int n = 1; n <= N; n++) {
            Mint dp = seg.get(n);
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
        System.out.println(seg.get((int) N));
    }

    public static void main(String[] args) throws IOException {
        solve();
    }
}
