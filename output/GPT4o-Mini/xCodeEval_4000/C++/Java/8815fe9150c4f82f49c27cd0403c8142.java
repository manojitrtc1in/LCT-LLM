import java.util.*;
import java.io.*;

class Main {
    static final int MOD = 998244353;

    static class Mint {
        long value;

        Mint() {
            this.value = 0;
        }

        Mint(long val) {
            this.value = norm(val);
        }

        static long norm(long x) {
            return (x % MOD + MOD) % MOD;
        }

        Mint add(Mint other) {
            return new Mint(norm(this.value + other.value));
        }

        Mint subtract(Mint other) {
            return new Mint(norm(this.value - other.value));
        }

        Mint multiply(Mint other) {
            return new Mint(this.value * other.value % MOD);
        }

        Mint divide(Mint other) {
            return this.multiply(inverse(other));
        }

        static Mint inverse(Mint a) {
            return new Mint(power(a, MOD - 2));
        }

        static long power(Mint x, long n) {
            Mint ans = new Mint(1);
            while (n > 0) {
                if ((n & 1) == 1) {
                    ans = ans.multiply(x);
                }
                x = x.multiply(x);
                n >>= 1;
            }
            return ans.value;
        }

        @Override
        public String toString() {
            return Long.toString(value);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        boolean[] a = new boolean[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt() == 1;
        }
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = scanner.nextInt();
        }

        int zw = 0, ow = 0;
        for (int i = 0; i < n; i++) {
            if (a[i]) {
                ow += w[i];
            } else {
                zw += w[i];
            }
        }
        int s = zw + ow;
        Mint[] inv = new Mint[2 * m + 1];
        for (int d = -m; d <= m; d++) {
            if (s + d > 0) {
                inv[d + m] = new Mint(1).divide(new Mint(s + d));
            }
        }

        Mint[][] dp = new Mint[m + 1][2];
        for (int i = 0; i <= m; i++) {
            dp[i][0] = new Mint(0);
            dp[i][1] = new Mint(0);
        }
        dp[0][0] = new Mint(1);

        for (int i = 0; i < m; i++) {
            Mint[][] ndp = new Mint[m + 1][2];
            for (int z = 0; z <= i; z++) {
                int o = i - z;
                int wz = zw - z;
                int wo = ow + o;
                if (wz < 0) continue;

                for (int dz = -1; dz <= 0; dz++) {
                    int nwz = wz + dz;
                    int nz = z + (-dz);
                    if (nwz < 0) continue;

                    Mint eps = inv[wz + wo - s + m];
                    Mint p = (dz == -1 ? new Mint(wz) : new Mint(wo)).multiply(eps);
                    ndp[nz][-dz] = ndp[nz][-dz].add(dp[z][-dz].multiply(p));
                    ndp[nz][1 + dz] = ndp[nz][1 + dz].add((p.add(new Mint(2 * dz + 1).multiply(eps))).multiply(dp[z][1 + dz]));
                }
            }
            dp = ndp;
        }

        Mint cz = new Mint(0), co = new Mint(0);
        for (int i = 0; i <= m; i++) {
            cz = cz.add(dp[i][0]);
            co = co.add(dp[i][1]);
        }

        for (int i = 0; i < n; i++) {
            System.out.println(w[i] * (a[i] ? co : cz));
        }
    }
}
