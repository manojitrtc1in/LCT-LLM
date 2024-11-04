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

    static final class ModInt {
        private static Barrett barrett;
        private final int v;

        ModInt(int v) {
            long x = safeMod(v, mod());
            this.v = (int) (x < 0 ? x + mod() : x);
        }

        static void setMod(int m) {
            barrett = new Barrett(m);
        }

        static int mod() {
            return barrett.umod();
        }

        int val() {
            return v;
        }

        ModInt add(ModInt other) {
            int result = v + other.v;
            if (result >= mod()) result -= mod();
            return new ModInt(result);
        }

        ModInt subtract(ModInt other) {
            int result = v - other.v;
            if (result < 0) result += mod();
            return new ModInt(result);
        }

        ModInt multiply(ModInt other) {
            long z = (long) v * other.v;
            return new ModInt((int) (z % mod()));
        }

        ModInt pow(long n) {
            assert n >= 0;
            ModInt x = this;
            ModInt r = new ModInt(1);
            while (n > 0) {
                if ((n & 1) == 1) r = r.multiply(x);
                x = x.multiply(x);
                n >>= 1;
            }
            return r;
        }

        ModInt inv() {
            long eg = id2(v, mod());
            assert eg == 1;
            return new ModInt(eg);
        }
    }

    static long id2(long a, long b) {
        a = safeMod(a, b);
        if (a == 0) return b;

        long s = b, t = a;
        long m0 = 0, m1 = 1;

        while (t > 0) {
            long u = s / t;
            s -= t * u;
            m0 -= m1 * u;

            long tmp = s;
            s = t;
            t = tmp;
            tmp = m0;
            m0 = m1;
            m1 = tmp;
        }

        if (m0 < 0) m0 += b / s;
        return s == 1 ? m0 : -1;
    }

    static int get(int i, int z) {
        long l1 = (long) i * z;
        long r1 = (long) (i + i) * z;

        long ans = l1;

        while (l1 <= r1) {
            long m = (l1 + r1) / 2;
            if (m / z > i) {
                r1 = m - 1;
            } else {
                ans = Math.max(ans, m);
                l1 = m + 1;
            }
        }

        return (int) ans;
    }

    static void solve() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        ModInt.setMod(m);

        ModInt[] dp = new ModInt[n + 1];
        ModInt[] p = new ModInt[n + 1];

        dp[n] = new ModInt(1);
        p[n] = new ModInt(1);
        for (int i = n - 1; i >= 1; i--) {
            dp[i] = dp[i].add(p[i + 1]);

            for (int z = 2; z * i <= n; z++) {
                int r = get(i, z) + 1;
                int l = z * i;
                dp[i] = dp[i].add(p[l]);
                if (r <= n) dp[i] = dp[i].subtract(p[r]);
            }

            p[i] = p[i + 1].add(dp[i]);
        }

        System.out.println(dp[1].val());
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int _t = 1;

        while (_t-- > 0) solve();
    }
}
