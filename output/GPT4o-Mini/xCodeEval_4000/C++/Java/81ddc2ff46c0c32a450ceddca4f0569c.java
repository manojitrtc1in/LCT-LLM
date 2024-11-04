import java.util.*;

class Atcoder {
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

    static class StaticModint {
        private final int m;
        private int v;

        StaticModint(int m) {
            this.m = m;
            this.v = 0;
        }

        StaticModint(int v, int m) {
            this.m = m;
            this.v = (v % m + m) % m;
        }

        int val() {
            return v;
        }

        StaticModint add(StaticModint rhs) {
            return new StaticModint((v + rhs.v) % m, m);
        }

        StaticModint subtract(StaticModint rhs) {
            return new StaticModint((v - rhs.v + m) % m, m);
        }

        StaticModint multiply(StaticModint rhs) {
            return new StaticModint((int) ((long) v * rhs.v % m), m);
        }

        StaticModint pow(long n) {
            StaticModint x = this;
            StaticModint r = new StaticModint(1, m);
            while (n > 0) {
                if ((n & 1) == 1) r = r.multiply(x);
                x = x.multiply(x);
                n >>= 1;
            }
            return r;
        }

        StaticModint inv() {
            return pow(m - 2);
        }
    }

    public static void solve() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        StaticModint modint = new StaticModint(m);
        StaticModint[] dp = new StaticModint[n + 1];
        StaticModint[] p = new StaticModint[n + 1];

        dp[n] = new StaticModint(1, m);
        p[n] = new StaticModint(1, m);
        for (int i = n - 1; i >= 1; i--) {
            dp[i] = dp[i].add(p[i + 1]);

            for (int z = 2; (long) z * i <= n; z++) {
                int r = i * z + z;
                int l = z * i;
                dp[i] = dp[i].add(p[l]);
                if (r <= n) dp[i] = dp[i].subtract(p[r]);
            }

            p[i] = p[i + 1].add(dp[i]);
        }

        System.out.println(dp[1].val());
    }

    public static void main(String[] args) {
        solve();
    }
}
