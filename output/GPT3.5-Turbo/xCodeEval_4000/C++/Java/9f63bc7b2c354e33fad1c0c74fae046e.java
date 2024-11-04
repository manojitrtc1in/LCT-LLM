import java.util.*;

class Main {
    static final int MOD = 998244353;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        ModInt.setMod(m);

        ModInt[] dp = new ModInt[n + 1];
        ModInt[] p = new ModInt[n + 1];

        dp[n] = ModInt.valueOf(1);
        p[n] = ModInt.valueOf(1);
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

    static int l1, r1;

    static int get(int i, int z) {
        l1 = 1 * i * z;
        r1 = 1 * (i + i) * z;

        int ans = l1;

        while (l1 <= r1) {
            int m = (l1 + r1) / 2;
            if (m / z > i) {
                r1 = m - 1;
            } else {
                ans = Math.max(ans, m);
                l1 = m + 1;
            }
        }

        return ans;
    }

    static class ModInt {
        static int mod;

        int value;

        ModInt(int value) {
            this.value = value;
        }

        static void setMod(int m) {
            mod = m;
        }

        static ModInt valueOf(int value) {
            return new ModInt(value % mod);
        }

        int val() {
            return value;
        }

        ModInt add(ModInt other) {
            return new ModInt((value + other.value) % mod);
        }

        ModInt subtract(ModInt other) {
            return new ModInt((value - other.value + mod) % mod);
        }

        ModInt multiply(ModInt other) {
            return new ModInt((int) ((long) value * other.value % mod));
        }

        ModInt divide(ModInt other) {
            return multiply(other.inverse());
        }

        ModInt inverse() {
            int a = value, b = mod, u = 1, v = 0;
            while (b != 0) {
                int t = a / b;
                a -= t * b;
                int temp1 = a;
                a = b;
                b = temp1;
                u -= t * v;
                int temp2 = u;
                u = v;
                v = temp2;
            }
            if (u < 0) u += mod;
            return new ModInt(u);
        }
    }
}
