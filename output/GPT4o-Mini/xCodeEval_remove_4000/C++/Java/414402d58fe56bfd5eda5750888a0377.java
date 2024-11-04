import java.io.*;
import java.util.*;
import java.util.function.Function;

public class 414402d58fe56bfd5eda5750888a0377xcodeeval_processed_4000.json {
    static final int md = (int) 1e9 + 7;
    static int[] d = new int[123];
    static Mint[] dp = new Mint[7];
    static Mint[] new_dp = new Mint[7];

    static class Mint {
        private final int value;

        public Mint(int value) {
            this.value = normalize(value);
        }

        public static int normalize(int x) {
            if (x < 0) x += md;
            if (x >= md) x -= md;
            return x;
        }

        public int getValue() {
            return value;
        }

        public Mint add(Mint other) {
            return new Mint(this.value + other.value);
        }

        public Mint multiply(Mint other) {
            return new Mint((int) ((long) this.value * other.value % md));
        }

        public static Mint power(Mint a, long b) {
            Mint res = new Mint(1);
            while (b > 0) {
                if ((b & 1) == 1) res = res.multiply(a);
                a = a.multiply(a);
                b >>= 1;
            }
            return res;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int tt = scanner.nextInt();
        while (tt-- > 0) {
            long m = scanner.nextLong();
            int len = 0;
            while (m > 0) {
                d[len++] = (int) (m & 1);
                m >>= 1;
            }
            Arrays.fill(dp, new Mint(0));
            Arrays.fill(new_dp, new Mint(0));
            dp[0] = new Mint(1);
            for (int it = len - 1; it >= 0; it--) {
                if (d[it] == 0) {
                    new_dp[0] = dp[0].add(dp[1]).add(dp[2]).add(dp[3]);
                    new_dp[1] = new_dp[2] = dp[1].add(dp[2]).add(dp[3]).add(dp[4]);
                    new_dp[3] = new_dp[4] = dp[2].add(dp[3]).add(dp[4]).add(dp[5]);
                    new_dp[5] = new_dp[6] = dp[3].add(dp[4]).add(dp[5]).add(dp[6]);
                } else {
                    new_dp[0] = new_dp[1] = dp[0].add(dp[1]).add(dp[2]).add(dp[3]);
                    new_dp[2] = new_dp[3] = dp[1].add(dp[2]).add(dp[3]).add(dp[4]);
                    new_dp[4] = new_dp[5] = dp[2].add(dp[3]).add(dp[4]).add(dp[5]);
                    new_dp[6] = dp[3].add(dp[4]).add(dp[5]).add(dp[6]);
                }
                System.arraycopy(new_dp, 0, dp, 0, 7);
            }
            System.out.println(dp[0].getValue());
        }
    }
}
