import java.util.*;
import java.io.*;

class Main {
    static final int mod = 998244353;

    static class ModInt {
        int value;

        public ModInt(int value) {
            this.value = value;
        }

        public ModInt add(ModInt other) {
            return new ModInt((value + other.value) % mod);
        }

        public ModInt subtract(ModInt other) {
            return new ModInt((value - other.value + mod) % mod);
        }

        public ModInt multiply(ModInt other) {
            return new ModInt((int) ((long) value * other.value % mod));
        }

        public ModInt divide(ModInt other) {
            return multiply(other.inverse());
        }

        public ModInt inverse() {
            return pow(mod - 2);
        }

        public ModInt pow(int exponent) {
            ModInt result = new ModInt(1);
            ModInt base = new ModInt(value);
            while (exponent > 0) {
                if ((exponent & 1) == 1) {
                    result = result.multiply(base);
                }
                base = base.multiply(base);
                exponent >>= 1;
            }
            return result;
        }
    }

    static ModInt[] inv;
    static ModInt[][] dp;

    static ModInt solve(int n, int m, boolean[] a, int[] w) {
        int zw = 0, ow = 0;
        for (int i = 0; i < n; i++) {
            if (a[i]) {
                ow += w[i];
            } else {
                zw += w[i];
            }
        }
        int s = zw + ow;
        inv = new ModInt[2 * m + 1];
        for (int d = -m; d <= m; d++) {
            if (s + d > 0) {
                inv[d + m] = new ModInt(1).divide(new ModInt(s + d));
            }
        }
        dp = new ModInt[m + 1][2];
        for (int i = 0; i <= m; i++) {
            dp[i][0] = new ModInt(0);
            dp[i][1] = new ModInt(0);
        }
        dp[0][0] = new ModInt(1);
        dp[0][1] = new ModInt(1);
        for (int i = 0; i < m; i++) {
            ModInt[][] ndp = new ModInt[m + 1][2];
            for (int z = 0; z <= i; z++) {
                int o = i - z;
                int wz = zw - z;
                int wo = ow + o;
                if (wz < 0) {
                    continue;
                }
                for (int dz = -1; dz <= 0; dz++) {
                    int nwz = wz + dz;
                    int nz = z + (-dz);
                    if (nwz < 0) {
                        continue;
                    }
                    ModInt eps = inv[wz + wo - s + m];
                    ModInt p = new ModInt(dz == -1 ? wz : wo).multiply(eps);
                    ndp[nz][-dz] = ndp[nz][-dz].add(dp[z][-dz].multiply(p));
                    ndp[nz][1 + dz] = ndp[nz][1 + dz].add(dp[z][1 + dz].multiply(p.add(new ModInt(2 * dz + 1).multiply(eps))));
                }
            }
            dp = ndp;
        }
        ModInt cz = new ModInt(0), co = new ModInt(0);
        for (int i = 0; i <= m; i++) {
            cz = cz.add(dp[i][0]);
            co = co.add(dp[i][1]);
        }
        ModInt[] ans = new ModInt[n];
        for (int i = 0; i < n; i++) {
            ans[i] = new ModInt(w[i]).multiply(a[i] ? co : cz);
        }
        return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        boolean[] a = new boolean[n];
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            a[i] = Integer.parseInt(st.nextToken()) == 1;
            w[i] = Integer.parseInt(st.nextToken());
        }
        ModInt[] ans = solve(n, m, a, w);
        for (int i = 0; i < n; i++) {
            pw.println(ans[i].value);
        }
        pw.close();
    }
}
