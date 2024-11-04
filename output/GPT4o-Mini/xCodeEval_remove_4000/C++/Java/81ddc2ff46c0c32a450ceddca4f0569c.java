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
        private final int mod;
        private int value;

        ModInt(int mod) {
            this.mod = mod;
            this.value = 0;
        }

        ModInt(int value, int mod) {
            this.mod = mod;
            this.value = (value % mod + mod) % mod;
        }

        ModInt add(ModInt other) {
            return new ModInt((value + other.value) % mod, mod);
        }

        ModInt subtract(ModInt other) {
            return new ModInt((value - other.value + mod) % mod, mod);
        }

        ModInt multiply(ModInt other) {
            return new ModInt((int) ((long) value * other.value % mod), mod);
        }

        ModInt pow(long n) {
            ModInt result = new ModInt(1, mod);
            ModInt base = new ModInt(value, mod);
            while (n > 0) {
                if ((n & 1) == 1) result = result.multiply(base);
                base = base.multiply(base);
                n >>= 1;
            }
            return result;
        }

        int val() {
            return value;
        }
    }

    static void solve() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        Barrett barrett = new Barrett(m);
        ModInt[] dp = new ModInt[n + 1];
        ModInt[] p = new ModInt[n + 1];

        for (int i = 0; i <= n; i++) {
            dp[i] = new ModInt(0, m);
            p[i] = new ModInt(0, m);
        }

        dp[n] = new ModInt(1, m);
        p[n] = new ModInt(1, m);
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
