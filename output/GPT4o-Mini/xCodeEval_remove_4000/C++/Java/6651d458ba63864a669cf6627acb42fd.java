import java.io.*;
import java.util.*;
import java.util.function.Function;

public class 6651d458ba63864a669cf6627acb42fdxcodeeval_processed_4000.json {
    static final int md = (int) 1e9 + 7;
    static final int MAX_D = 123;
    static final int MAX_DP = 7;
    static int[] d = new int[MAX_D];
    static Mint[] dp = new Mint[MAX_DP];
    static Mint[] new_dp = new Mint[MAX_DP];

    static class Mint {
        private final int value;

        public Mint(int value) {
            this.value = normalize(value);
        }

        public static int normalize(int x) {
            if (x < 0) x += md;
            return x % md;
        }

        public int getValue() {
            return value;
        }

        public Mint add(Mint other) {
            return new Mint(this.value + other.value);
        }

        public Mint add(int other) {
            return add(new Mint(other));
        }

        public Mint multiply(Mint other) {
            return new Mint((int) ((1L * this.value * other.value) % md));
        }

        public Mint multiply(int other) {
            return multiply(new Mint(other));
        }

        @Override
        public String toString() {
            return String.valueOf(value);
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
                System.arraycopy(new_dp, 0, dp, 0, MAX_DP);
            }
            System.out.println(dp[0]);
        }
        scanner.close();
    }
}
