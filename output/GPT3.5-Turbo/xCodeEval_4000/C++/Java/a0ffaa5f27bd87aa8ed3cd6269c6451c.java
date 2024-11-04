import java.io.*;
import java.util.*;

class Main {
    static class Scanner {
        private final BufferedReader br;
        private StringTokenizer st;

        public Scanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }

        public String nextLine() {
            try {
                return br.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(nextLine());
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    static class Printer {
        private final BufferedWriter bw;

        public Printer(OutputStream os) {
            bw = new BufferedWriter(new OutputStreamWriter(os));
        }

        public void print(Object obj) {
            try {
                bw.write(obj.toString());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        public void println(Object obj) {
            print(obj);
            print("\n");
        }

        public void flush() {
            try {
                bw.flush();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        public void close() {
            try {
                bw.close();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }

    static class ModInt {
        private static int mod;
        private int value;

        public ModInt(int value) {
            this.value = value;
        }

        public static void setMod(int m) {
            mod = m;
        }

        public int getValue() {
            return value;
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

        public ModInt pow(long n) {
            ModInt result = new ModInt(1);
            ModInt x = new ModInt(value);
            while (n > 0) {
                if ((n & 1) == 1) {
                    result = result.multiply(x);
                }
                x = x.multiply(x);
                n >>= 1;
            }
            return result;
        }

        public ModInt inverse() {
            return pow(mod - 2);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Printer pr = new Printer(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int mod = sc.nextInt();
        ModInt.setMod(mod);

        ModInt[][] C = new ModInt[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            C[i][0] = new ModInt(1);
            for (int j = 1; j <= n; j++) {
                C[i][j] = C[i - 1][j - 1].add(C[i - 1][j]);
            }
        }

        ModInt[] g = new ModInt[n + 1];
        for (int i = 0; i <= n; i++) {
            g[i] = new ModInt(i * (i + 1) / 2);
        }

        class Pair {
            ModInt first;
            ModInt second;

            public Pair(ModInt first, ModInt second) {
                this.first = first;
                this.second = second;
            }
        }

        Pair[] f = new Pair[n + 1];
        f[0] = new Pair(new ModInt(1), new ModInt(0));

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                ModInt z = f[j].first.multiply(f[i - 1 - j].first).multiply(C[i - 1][j]);
                f[i] = new Pair(f[i].first.add(z.multiply(new ModInt(i + 1))),
                        f[i].second.add(z.multiply(g[j].add(g[i - 1 - j]))));
                f[i].second = f[i].second.add(f[i - 1 - j].first.multiply(f[j].second)
                        .add(f[j].first.multiply(f[i - 1 - j].second)).multiply(C[i - 1][j]).multiply(new ModInt(i + 1)));
            }
        }

        ModInt[][] dp = new ModInt[n + 2][m + 1];
        dp[0][0] = new Pair(new ModInt(1), new ModInt(0));
        for (int l = 0; l <= n; l++) {
            for (int r = l + 1; r <= n + 1; r++) {
                int di = r - l - 1;
                for (int i = 0; i + di <= m; i++) {
                    ModInt z = dp[l][i].first.multiply(f[di].first).multiply(C[i + di][di]);
                    dp[r][i + di].first = dp[r][i + di].first.add(z);
                    dp[r][i + di].second = dp[r][i + di].second.add(
                            dp[l][i].second.multiply(f[di].first).add(dp[l][i].first.multiply(f[di].second))
                                    .multiply(C[i + di][di]));
                }
            }
        }

        pr.println(dp[n + 1][m].second.getValue());
        pr.flush();
    }
}
