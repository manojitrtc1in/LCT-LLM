import java.io.*;
import java.util.*;

class Scanner {
    private BufferedReader br;
    private StringTokenizer st;

    public Scanner(InputStream in) {
        br = new BufferedReader(new InputStreamReader(in));
    }

    public String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }
}

class Printer {
    private PrintWriter out;

    public Printer(OutputStream out) {
        this.out = new PrintWriter(out);
    }

    public void println(long x) {
        out.println(x);
    }

    public void flush() {
        out.flush();
    }
}

class ModInt {
    private static int mod;
    private int value;

    public static void setMod(int m) {
        mod = m;
    }

    public ModInt(int v) {
        value = (v % mod + mod) % mod;
    }

    public ModInt add(ModInt other) {
        return new ModInt(value + other.value);
    }

    public ModInt multiply(ModInt other) {
        return new ModInt((int) ((long) value * other.value % mod));
    }

    public ModInt pow(long n) {
        ModInt result = new ModInt(1);
        ModInt base = this;
        while (n > 0) {
            if ((n & 1) == 1) {
                result = result.multiply(base);
            }
            base = base.multiply(base);
            n >>= 1;
        }
        return result;
    }

    public int val() {
        return value;
    }
}

public class a0ffaa5f27bd87aa8ed3cd6269c6451cxcodeeval_processed_4000.json {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Printer pr = new Printer(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int mod = sc.nextInt();
        ModInt.setMod(mod);

        ModInt[][] C = new ModInt[n + 1][n + 1];
        C[0][0] = new ModInt(1);
        for (int i = 1; i <= n; i++) {
            C[i][0] = new ModInt(1);
            for (int j = 1; j <= n; j++) {
                C[i][j] = C[i - 1][j - 1].add(C[i - 1][j]);
            }
        }

        ModInt[] g = new ModInt[n + 1];
        for (int i = 0; i <= n; i++) {
            g[i] = new ModInt(i * (i + 1) / 2);
        }

        Pair<ModInt, ModInt>[] f = new Pair[n + 1];
        f[0] = new Pair<>(new ModInt(1), new ModInt(0));

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                ModInt z = f[j].first.multiply(f[i - 1 - j].first).multiply(C[i - 1][j]);
                f[i].first = f[i].first.add(z.multiply(new ModInt(i + 1)));
                f[i].second = f[i].second.add(z.multiply(g[j].add(g[i - 1 - j])));
                f[i].second = f[i].second.add(f[i - 1 - j].first.multiply(f[j].second).add(f[j].first.multiply(f[i - 1 - j].second)).multiply(C[i - 1][j]).multiply(new ModInt(i + 1)));
            }
        }

        ModInt[][] dp = new ModInt[n + 2][m + 1];
        for (int i = 0; i < dp.length; i++) {
            Arrays.fill(dp[i], new ModInt(0));
        }
        dp[0][0] = new Pair<>(new ModInt(1), new ModInt(0));
        for (int l = 0; l <= n; l++) {
            for (int r = l + 1; r <= n + 1; r++) {
                int di = r - l - 1;
                for (int i = 0; i + di <= m; i++) {
                    ModInt z = dp[l][i].first.multiply(f[di].first);
                    dp[r][i + di].first = dp[r][i + di].first.add(z.multiply(C[i + di][di]));
                    dp[r][i + di].second = dp[r][i + di].second.add(dp[l][i].second.multiply(f[di].first).add(dp[l][i].first.multiply(f[di].second)).multiply(C[i + di][di]));
                }
            }
        }

        pr.println(dp[n + 1][m].second.val());
        pr.flush();
    }
}

class Pair<F, S> {
    public F first;
    public S second;

    public Pair(F first, S second) {
        this.first = first;
        this.second = second;
    }
}
