import java.io.*;
import java.util.*;
import java.util.function.Function;

public class 414402d58fe56bfd5eda5750888a0377_nc {
    static final int MOD = (int) 1e9 + 7;
    static int[] d = new int[123];
    static Mint[] dp = new Mint[7];
    static Mint[] new_dp = new Mint[7];

    static class Mint {
        private int value;

        public Mint() {
            this.value = 0;
        }

        public Mint(int x) {
            this.value = normalize(x);
        }

        private int normalize(int x) {
            if (x < 0) x += MOD;
            if (x >= MOD) x -= MOD;
            return x;
        }

        public Mint add(Mint other) {
            return new Mint(this.value + other.value);
        }

        public Mint add(int other) {
            return new Mint(this.value + other);
        }

        public Mint multiply(Mint other) {
            return new Mint((int) ((1L * this.value * other.value) % MOD));
        }

        public int getValue() {
            return value;
        }

        @Override
        public String toString() {
            return String.valueOf(value);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tt = Integer.parseInt(br.readLine());
        while (tt-- > 0) {
            long m = Long.parseLong(br.readLine());
            int len = 0;
            while (m > 0) {
                d[len++] = (int) (m & 1);
                m >>= 1;
            }
            Arrays.fill(dp, new Mint());
            Arrays.fill(new_dp, new Mint());
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
            System.out.println(dp[0]);
        }
    }
}