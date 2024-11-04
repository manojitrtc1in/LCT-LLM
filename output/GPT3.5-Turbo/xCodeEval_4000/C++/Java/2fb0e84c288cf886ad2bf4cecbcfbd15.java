import java.util.*;

class Main {
    static final int MOD = 998244353;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        ModInt.setMod(m);

        ModInt[] dp = new ModInt[n + 1];
        ModInt[] p1 = new ModInt[n + 1];

        dp[n] = new ModInt(1);
        p1[n] = new ModInt(1);
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

    static class ModInt {
        static int mod;

        int x;

        ModInt(int x) {
            this.x = (x % mod + mod) % mod;
        }

        static void setMod(int m) {
            mod = m;
        }

        int val() {
            return x;
        }

        ModInt add(ModInt other) {
            return new ModInt(x + other.x >= mod ? x + other.x - mod : x + other.x);
        }

        ModInt subtract(ModInt other) {
            return new ModInt(x - other.x < 0 ? x - other.x + mod : x - other.x);
        }

        ModInt multiply(ModInt other) {
            return new ModInt((int) ((long) x * other.x % mod));
        }

        ModInt divide(ModInt other) {
            return multiply(other.inverse());
        }

        ModInt inverse() {
            int a = x, b = mod, u = 1, v = 0;
            while (b > 0) {
                int t = a / b;
                a -= t * b;
                int tmp1 = a;
                a = b;
                b = tmp1;
                u -= t * v;
                int tmp2 = u;
                u = v;
                v = tmp2;
            }
            return new ModInt(u);
        }
    }
}
