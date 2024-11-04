import java.util.*;

class Main {
    static class ModInt {
        static int mod;
        int value;

        ModInt(int value) {
            this.value = value;
        }

        static void setMod(int m) {
            mod = m;
        }

        static ModInt raw(int v) {
            return new ModInt(v);
        }

        int val() {
            return value;
        }

        ModInt add(ModInt other) {
            value += other.value;
            if (value >= mod) value -= mod;
            return this;
        }

        ModInt subtract(ModInt other) {
            value += mod - other.value;
            if (value >= mod) value -= mod;
            return this;
        }

        ModInt multiply(ModInt other) {
            value = (int) ((long) value * other.value % mod);
            return this;
        }

        ModInt divide(ModInt other) {
            return multiply(other.inverse());
        }

        ModInt inverse() {
            int a = value, b = mod, u = 0, v = 1;
            while (a != 0) {
                int t = b / a;
                b -= t * a;
                u -= t * v;
                int temp = a;
                a = b;
                b = temp;
                temp = u;
                u = v;
                v = temp;
            }
            if (u < 0) u += mod;
            return new ModInt(u);
        }

        ModInt pow(long n) {
            ModInt result = new ModInt(1);
            ModInt x = new ModInt(value);
            while (n > 0) {
                if ((n & 1) == 1) result.multiply(x);
                x.multiply(x);
                n >>= 1;
            }
            return result;
        }

        static ModInt add(ModInt a, ModInt b) {
            return new ModInt(a.value).add(b);
        }

        static ModInt subtract(ModInt a, ModInt b) {
            return new ModInt(a.value).subtract(b);
        }

        static ModInt multiply(ModInt a, ModInt b) {
            return new ModInt(a.value).multiply(b);
        }

        static ModInt divide(ModInt a, ModInt b) {
            return new ModInt(a.value).divide(b);
        }
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
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        ModInt.setMod(m);

        ModInt[] dp = new ModInt[n + 1];
        ModInt[] p = new ModInt[n + 1];

        dp[n] = new ModInt(1);
        p[n] = new ModInt(1);
        for (int i = n - 1; i >= 1; i--) {
            dp[i] = ModInt.add(p[i + 1], new ModInt(0));

            for (int z = 2; z * i <= n; z++) {
                int r = get(i, z) + 1;
                int l = z * i;
                dp[i] = ModInt.add(dp[i], p[l]);
                if (r <= n) dp[i] = ModInt.subtract(dp[i], p[r]);
            }

            p[i] = ModInt.add(p[i + 1], dp[i]);
        }

        System.out.println(dp[1].val());
    }

    public static void main(String[] args) {
        solve();
    }
}
