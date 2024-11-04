import java.util.*;
import java.io.*;

class Main {
    static final int MOD = 998244353;

    static class Mint {
        long v;

        Mint() {
            this.v = 0;
        }

        Mint(long val) {
            this.v = norm(val);
        }

        static long norm(long x) {
            return x < MOD ? x : x - MOD;
        }

        Mint add(Mint m) {
            return new Mint(norm(this.v + m.v));
        }

        Mint subtract(Mint m) {
            return new Mint(norm(this.v + MOD - m.v));
        }

        Mint multiply(Mint m) {
            return new Mint((this.v * m.v) % MOD);
        }

        Mint divide(Mint m) {
            return this.multiply(inverse(m.v));
        }

        static Mint inverse(long a) {
            return new Mint(pow(a, MOD - 2));
        }

        static long pow(long x, long n) {
            long ans = 1;
            while (n > 0) {
                if ((n & 1) == 1) {
                    ans = (ans * x) % MOD;
                }
                x = (x * x) % MOD;
                n >>= 1;
            }
            return ans;
        }

        @Override
        public String toString() {
            return Long.toString(v);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        boolean[] a = new boolean[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken()) == 1;
        }

        int[] w = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            w[i] = Integer.parseInt(st.nextToken());
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
                    ndp[nz][-dz] = ndp[nz][-dz] == null ? new Mint(0) : ndp[nz][-dz].add(dp[z][-dz].multiply(p));
                    ndp[nz][1 + dz] = ndp[nz][1 + dz] == null ? new Mint(0) : ndp[nz][1 + dz].add((p.add(new Mint((2 * dz + 1)).multiply(eps))).multiply(dp[z][1 + dz]));
                }
            }
            dp = ndp;
        }

        Mint cz = new Mint(0), co = new Mint(0);
        for (int i = 0; i <= m; i++) {
            cz = cz.add(dp[i][0]);
            co = co.add(dp[i][1]);
        }

        StringBuilder result = new StringBuilder();
        for (int i = 0; i < n; i++) {
            result.append(w[i] * (a[i] ? co : cz)).append("\n");
        }
        System.out.print(result);
    }
}
