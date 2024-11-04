import java.util.*;

class AtCoder {
    static class Barrett {
        private final int m;
        private final long im;

        Barrett(int m) {
            this.m = m;
            this.im = (-1L / m) + 1;
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

    static long powModConstexpr(long x, long n, int m) {
        if (m == 1) return 0;
        long r = 1;
        long y = safeMod(x, m);
        while (n > 0) {
            if ((n & 1) == 1) r = (r * y) % m;
            y = (y * y) % m;
            n >>= 1;
        }
        return r;
    }

    static boolean isPrimeConstexpr(int n) {
        if (n <= 1) return false;
        if (n == 2 || n == 7 || n == 61) return true;
        if (n % 2 == 0) return false;
        long d = n - 1;
        while (d % 2 == 0) d /= 2;
        long[] bases = {2, 7, 61};
        for (long a : bases) {
            long t = d;
            long y = powModConstexpr(a, t, n);
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

    static class StaticModInt {
        private final int m;
        private int v;

        StaticModInt(int m) {
            this.m = m;
            this.v = 0;
        }

        StaticModInt(int v, int m) {
            this.m = m;
            this.v = (v % m + m) % m;
        }

        int val() {
            return v;
        }

        StaticModInt add(StaticModInt rhs) {
            return new StaticModInt((v + rhs.v) % m, m);
        }

        StaticModInt subtract(StaticModInt rhs) {
            return new StaticModInt((v - rhs.v + m) % m, m);
        }

        StaticModInt multiply(StaticModInt rhs) {
            return new StaticModInt((int) ((long) v * rhs.v % m), m);
        }

        StaticModInt pow(long n) {
            StaticModInt x = this;
            StaticModInt r = new StaticModInt(1, m);
            while (n > 0) {
                if ((n & 1) == 1) r = r.multiply(x);
                x = x.multiply(x);
                n >>= 1;
            }
            return r;
        }

        StaticModInt inv() {
            return pow(m - 2);
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

        StaticModInt modInt = new StaticModInt(m);
        StaticModInt[] dp = new StaticModInt[n + 1];
        StaticModInt[] p1 = new StaticModInt[n + 1];

        dp[n] = new StaticModInt(1, m);
        p1[n] = new StaticModInt(1, m);
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
