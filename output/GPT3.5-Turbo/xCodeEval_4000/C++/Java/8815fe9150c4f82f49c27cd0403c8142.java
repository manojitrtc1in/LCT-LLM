import java.util.*;
import java.io.*;

class Main {
    static final int mod = 998244353;
    static class modint {
        int v;
        modint(int val) {
            v = val;
        }
        modint add(modint m) {
            return new modint((v + m.v) % mod);
        }
        modint subtract(modint m) {
            return new modint((v - m.v + mod) % mod);
        }
        modint multiply(modint m) {
            return new modint((int)((long)v * m.v % mod));
        }
        modint divide(modint m) {
            return multiply(m.inverse());
        }
        modint inverse() {
            return power(mod - 2);
        }
        modint power(int n) {
            modint ans = new modint(1);
            modint x = new modint(v);
            while (n > 0) {
                if (n % 2 == 1) {
                    ans = ans.multiply(x);
                }
                x = x.multiply(x);
                n /= 2;
            }
            return ans;
        }
        public String toString() {
            return Integer.toString(v);
        }
    }

    static int inInt() throws IOException {
        return Integer.parseInt(in.readLine());
    }

    static int[] inIntArray(int n) throws IOException {
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(in.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        return arr;
    }

    static boolean[] inBoolArray(int n) throws IOException {
        boolean[] arr = new boolean[n];
        StringTokenizer st = new StringTokenizer(in.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken()) == 1;
        }
        return arr;
    }

    static void out(Object obj) {
        System.out.print(obj);
    }

    static void outln(Object obj) {
        System.out.println(obj);
    }

    static BufferedReader in;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        int n = inInt();
        int m = inInt();
        boolean[] a = inBoolArray(n);
        int[] w = inIntArray(n);
        int zw = 0, ow = 0;
        for (int i = 0; i < n; i++) {
            if (a[i]) {
                ow += w[i];
            } else {
                zw += w[i];
            }
        }
        int s = zw + ow;
        modint[] inv = new modint[2 * m + 1];
        for (int d = -m; d <= m; d++) {
            if (s + d > 0) {
                inv[d + m] = new modint(1).divide(new modint(s + d));
            }
        }
        modint[][] dp = new modint[m + 1][2];
        for (int i = 0; i <= m; i++) {
            dp[i][0] = new modint(0);
            dp[i][1] = new modint(0);
        }
        dp[0][0] = new modint(1);
        dp[0][1] = new modint(1);
        for (int i = 0; i < m; i++) {
            modint[][] ndp = new modint[m + 1][2];
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
                    modint eps = inv[wz + wo - s + m];
                    modint p = new modint(dz == -1 ? wz : wo).multiply(eps);
                    ndp[nz][-dz] = ndp[nz][-dz].add(dp[z][-dz].multiply(p));
                    ndp[nz][1 + dz] = ndp[nz][1 + dz].add(dp[z][1 + dz].multiply(p.add(new modint(2 * dz + 1).multiply(eps))));
                }
            }
            dp = ndp;
        }
        modint cz = new modint(0);
        modint co = new modint(0);
        for (int i = 0; i <= m; i++) {
            cz = cz.add(dp[i][0]);
            co = co.add(dp[i][1]);
        }
        for (int i = 0; i < n; i++) {
            outln(new modint(w[i]).multiply(a[i] ? co : cz));
        }
        out.close();
    }
}
