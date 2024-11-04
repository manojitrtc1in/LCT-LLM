import java.io.*;
import java.util.*;
import java.util.function.Function;

public class 5b4e3a6b9b37fa4ea0685476993014c1xcodeeval_processed_4000.json {
    static final int md = (int) 1e9 + 7;
    static final int MAX_LEN = 123;
    static int[] d = new int[MAX_LEN];
    static Mint[] dp = new Mint[7];
    static Mint[] new_dp = new Mint[7];

    static class Mint {
        private final int value;

        public Mint(int value) {
            this.value = normalize(value);
        }

        private static int normalize(int x) {
            if (x < 0) x += md;
            return x % md;
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

        public static Mint zero() {
            return new Mint(0);
        }

        public static Mint one() {
            return new Mint(1);
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
            Arrays.fill(dp, Mint.zero());
            Arrays.fill(new_dp, Mint.zero());
            dp[0] = Mint.one();
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
        scanner.close();
    }
}
