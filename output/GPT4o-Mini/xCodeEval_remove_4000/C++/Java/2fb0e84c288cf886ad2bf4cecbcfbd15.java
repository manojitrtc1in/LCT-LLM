import java.util.*;

class AtCoder {
    static class Barrett {
        private final int m;
        private final long im;

        Barrett(int m) {
            this.m = m;
            this.im = (long) (-1) / m + 1;
        }

        int umod() {
            return m;
        }

        int mul(int a, int b) {
            long z = (long) a * b;
            long x = (z * im) >> 64;
            int v = (int) (z - x * m);
            if (m <= v) v += m;
            return v;
        }
    }

    static long safeMod(long x, long m) {
        x %= m;
        if (x < 0) x += m;
        return x;
    }

    static long id4(long x, long n, int m) {
        if (m == 1) return 0;
        int _m = m;
        long r = 1;
        long y = safeMod(x, m);
        while (n > 0) {
            if ((n & 1) == 1) r = (r * y) % _m;
            y = (y * y) % _m;
            n >>= 1;
        }
        return r;
    }

    static boolean id1(int n) {
        if (n <= 1) return false;
        if (n == 2 || n == 7 || n == 61) return true;
        if (n % 2 == 0) return false;
        long d = n - 1;
        while (d % 2 == 0) d /= 2;
        long[] bases = {2, 7, 61};
        for (long a : bases) {
            long t = d;
            long y = id4(a, t, n);
            while (t != n - 1 && y != 1 && y != n - 1) {
                y = y * y % n;
                t <<= 1;
            }
            if (y != n - 1 && t % 2 == 0) {
                return false;
            }
        }
        return true;
    }

    static class ModInt {
        private final int m;
        private int v;

        ModInt(int m) {
            this.m = m;
            this.v = 0;
        }

        ModInt(int v, int m) {
            this.m = m;
            this.v = (v % m + m) % m;
        }

        int val() {
            return v;
        }

        ModInt add(ModInt other) {
            v += other.v;
            if (v >= m) v -= m;
            return this;
        }

        ModInt subtract(ModInt other) {
            v -= other.v;
            if (v < 0) v += m;
            return this;
        }

        ModInt multiply(ModInt other) {
            v = (int) ((long) v * other.v % m);
            return this;
        }

        ModInt pow(long n) {
            ModInt x = new ModInt(v, m);
            ModInt r = new ModInt(1, m);
            while (n > 0) {
                if ((n & 1) == 1) r = r.multiply(x);
                x = x.multiply(x);
                n >>= 1;
            }
            return r;
        }

        ModInt inv() {
            return pow(m - 2);
        }

        static void setMod(int m) {
            // Set the modulus if needed
        }
    }

    static int get(int i, int z) {
        int l = i * z;
        int r = (i + i) * z;
        int ans = l;

        while (l <= r) {
            int m = (l + r) / 2;
            if (m / z > i) {
                r = m - 1;
            } else {
                ans = Math.max(ans, m);
                l = m + 1;
            }
        }

        return ans;
    }

    static void solve() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        ModInt.setMod(m);

        ModInt[] dp = new ModInt[n + 1];
        ModInt[] p1 = new ModInt[n + 1];
        for (int i = 0; i <= n; i++) {
            dp[i] = new ModInt(0, m);
            p1[i] = new ModInt(0, m);
        }

        dp[n] = new ModInt(1, m);
        p1[n] = new ModInt(1, m);
        for (int i = n - 1; i >= 1; i--) {
            dp[i] = dp[i].add(p1[i + 1]);

            for (int z = 2; z * i <= n; z++) {
                int r = get(i, z) + 1;
                int l = z * i;
                dp[i] = dp[i].add(p1[l]);
                if (r <= n) dp[i] = dp[i].subtract(p1[r]);
            }

            p1[i] = p1[i + 1].add(dp[i]);
        }

        System.out.println(dp[1].val());
    }

    public static void main(String[] args) {
        solve();
    }
}
