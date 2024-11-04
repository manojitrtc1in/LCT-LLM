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
            if (value >= mod) {
                value -= mod;
            }
            return this;
        }

        ModInt subtract(ModInt other) {
            value += mod - other.value;
            if (value >= mod) {
                value -= mod;
            }
            return this;
        }

        ModInt multiply(ModInt other) {
            long z = (long) value * other.value;
            value = (int) (z % mod);
            return this;
        }

        ModInt divide(ModInt other) {
            return multiply(other.inverse());
        }

        ModInt inverse() {
            long a = value, b = mod, u = 1, v = 0;
            while (b != 0) {
                long t = a / b;
                a -= t * b;
                long x = a;
                a = b;
                b = x;
                u -= t * v;
                long y = u;
                u = v;
                v = y;
            }
            u %= mod;
            if (u < 0) {
                u += mod;
            }
            return new ModInt((int) u);
        }

        ModInt pow(long n) {
            ModInt x = this, r = new ModInt(1);
            while (n != 0) {
                if ((n & 1) != 0) {
                    r.multiply(x);
                }
                x.multiply(x);
                n >>= 1;
            }
            return r;
        }

        static ModInt zero() {
            return new ModInt(0);
        }

        static ModInt one() {
            return new ModInt(1);
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
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        ModInt.setMod(m);
        ModInt[] dp = new ModInt[n + 1];
        ModInt[] p1 = new ModInt[n + 1];
        dp[n] = ModInt.one();
        p1[n] = ModInt.one();
        for (int i = n - 1; i >= 1; i--) {
            dp[i] = dp[i].add(p1[i + 1]);
            for (int z = 2; z * i <= n; z++) {
                int r = get(i, z) + 1;
                int l = z * i;
                dp[i] = dp[i].add(p1[l]);
                if (r <= n) {
                    dp[i] = dp[i].subtract(p1[r]);
                }
            }
            p1[i] = p1[i + 1].add(dp[i]);
        }
        System.out.println(dp[1].val());
    }

    public static void main(String[] args) {
        solve();
    }
}
