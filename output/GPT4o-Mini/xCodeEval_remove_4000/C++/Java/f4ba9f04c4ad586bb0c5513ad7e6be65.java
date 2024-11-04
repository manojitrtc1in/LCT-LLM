import java.util.*;
import java.io.*;

public class f4ba9f04c4ad586bb0c5513ad7e6be65xcodeeval_processed_4000.json {
    static final int INF = (int) 1e9;
    static final long INF64 = (long) 1e18;
    static final int MOD = (int) 1e9 + 7;
    static final double EPS = 1e-9;
    static final double PI = Math.acos(-1.0);
    static final int CR = 7;
    static final int BITS = 15;

    static long n;

    static boolean read(Scanner scanner) {
        if (!scanner.hasNextLong()) return false;
        n = scanner.nextLong();
        return true;
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

        static int inv_mod(int a) {
            int g = MOD, r = a, x = 0, y = 1;

            while (r != 0) {
                int q = g / r;
                g %= r; 
                int temp = g; g = r; r = temp;
                x -= q * y; 
                temp = x; x = y; y = temp;
            }

            return x < 0 ? x + MOD : x;
        }

        Mint inv() {
            return new Mint(inv_mod(val));
        }

        Mint pow(long p) {
            if (p < 0) return inv().pow(-p);
            Mint a = this, result = new Mint(1);

            while (p > 0) {
                if ((p & 1) != 0) result = result.mul(a);
                a = a.mul(a);
                p >>= 1;
            }

            return result;
        }

        Mint add(Mint other) {
            val += other.val;
            if (val >= MOD) val -= MOD;
            return this;
        }

        Mint sub(Mint other) {
            val -= other.val;
            if (val < 0) val += MOD;
            return this;
        }

        Mint mul(Mint other) {
            val = (int) fast_mod((long) val * other.val);
            return this;
        }

        static long fast_mod(long x) {
            return x % MOD;
        }

        @Override
        public String toString() {
            return String.valueOf(val);
        }
    }

    static Mint[][][][] dp = new Mint[CR][BITS + 1][CR][1 << BITS];
    static Mint[][][] cnt = new Mint[CR][CR][1 << BITS];

    static void precalc() {
        for (int i = 0; i < CR; i++) {
            for (int j = 0; j <= BITS; j++) {
                for (int k = 0; k < CR; k++) {
                    Arrays.fill(dp[i][j][k], new Mint(0));
                }
            }
        }
        for (int i = 0; i < CR; i++) dp[i][0][i][0] = new Mint(1);
        for (int cs = 0; cs < CR; cs++) {
            for (int i = 0; i < BITS; i++) {
                for (int ct = 0; ct < CR; ct++) {
                    for (int x = 0; x < (1 << BITS); x++) {
                        if (!dp[cs][i][ct][x].val.equals(0)) {
                            for (int cc = 0; cc < CR + 1; cc++) {
                                dp[cs][i + 1][(ct + cc) / 2][(((ct + cc) % 2) << i) | x].add(dp[cs][i][ct][x]);
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
        for (int i = 0; i < 5; i++) {
            Arrays.fill(dp2[i], new Mint(0));
        }
        dp2[0][0] = new Mint(1);
        for (int i = 0; i < 4; i++) {
            int x = (int) (n & ((1 << BITS) - 1));
            n >>= BITS;
            for (int j = 0; j < CR; j++) {
                for (int k = 0; k < CR; k++) {
                    dp2[i + 1][k].add(dp2[i][j].mul(cnt[j][k][x]));
                }
            }
        }
        System.out.println(dp2[4][0]);
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("input.txt"));
        precalc();

        int tc = scanner.nextInt();
        while (tc-- > 0) {
            if (read(scanner)) {
                solve();
            }
        }
        scanner.close();
    }
}
