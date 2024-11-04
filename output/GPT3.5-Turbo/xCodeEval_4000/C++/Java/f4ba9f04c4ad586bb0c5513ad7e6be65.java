import java.util.*;
import java.io.*;

class Main {
    static final int CR = 7;
    static final int BITS = 15;
    static final int MOD = (int) 1e9 + 7;

    static long n;

    static boolean read() {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            n = Long.parseLong(br.readLine());
            return true;
        } catch (IOException e) {
            return false;
        }
    }

    static class Mint {
        int val;

        Mint(long v) {
            if (v < 0) v = v % MOD + MOD;
            if (v >= MOD) v %= MOD;
            val = (int) v;
        }

        Mint(int v) {
            this((long) v);
        }

        Mint inv() {
            return invMod(val);
        }

        static Mint invMod(int a, int m) {
            int g = m, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r;
                int temp = g;
                g = r;
                r = temp;
                x -= q * y;
                int temp2 = x;
                x = y;
                y = temp2;
            }

            return x < 0 ? new Mint(x + m) : new Mint(x);
        }

        static Mint invMod(int a) {
            return invMod(a, MOD);
        }

        Mint add(Mint other) {
            val -= MOD - other.val;
            if (val < 0) val += MOD;
            return this;
        }

        Mint subtract(Mint other) {
            val -= other.val;
            if (val < 0) val += MOD;
            return this;
        }

        static int fastMod(long x, int m) {
            if (x < 0) x = x % m + m;
            if (x >= m) x %= m;
            return (int) x;
        }

        Mint multiply(Mint other) {
            val = fastMod((long) val * other.val, MOD);
            return this;
        }

        Mint divide(Mint other) {
            return multiply(other.inv());
        }

        Mint pow(long p) {
            if (p < 0) return inv().pow(-p);

            Mint a = this, result = new Mint(1);

            while (p > 0) {
                if ((p & 1) == 1) result.multiply(a);
                a.multiply(a);
                p >>= 1;
            }

            return result;
        }

        @Override
        public String toString() {
            return Integer.toString(val);
        }
    }

    static Mint[][][] dp = new Mint[CR][BITS + 1][CR];
    static Mint[][][] cnt = new Mint[CR][CR][1 << BITS];

    static void precalc() {
        for (Mint[][] row1 : dp) {
            for (Mint[] row2 : row1) {
                Arrays.fill(row2, new Mint(0));
            }
        }
        for (int i = 0; i < CR; i++) {
            dp[i][0][i] = new Mint(1);
        }
        for (int cs = 0; cs < CR; cs++) {
            for (int i = 0; i < BITS; i++) {
                for (int ct = 0; ct < CR; ct++) {
                    for (int x = 0; x < (1 << BITS); x++) {
                        if (!dp[cs][i][ct].equals(new Mint(0))) {
                            for (int cc = 0; cc <= CR; cc++) {
                                dp[cs][i + 1][(ct + cc) / 2][(((ct + cc) % 2) << i) | x].add(dp[cs][i][ct]);
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < CR; i++) {
            for (int j = 0; j < CR; j++) {
                for (int x = 0; x < (1 << BITS); x++) {
                    cnt[i][j][x] = dp[i][BITS][j][x];
                }
            }
        }
    }

    static Mint[][] dp2 = new Mint[5][CR];

    static void solve() {
        for (Mint[] row : dp2) {
            Arrays.fill(row, new Mint(0));
        }
        dp2[0][0] = new Mint(1);
        for (int i = 0; i < 4; i++) {
            int x = (int) (n & ((1 << BITS) - 1));
            n >>= BITS;
            for (int j = 0; j < CR; j++) {
                for (int k = 0; k < CR; k++) {
                    dp2[i + 1][k].add(dp2[i][j].multiply(cnt[j][k][x]));
                }
            }
        }
        System.out.println(dp2[4][0]);
    }

    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int tc = Integer.parseInt(br.readLine());
            precalc();
            while (tc-- > 0 && read()) {
                solve();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
