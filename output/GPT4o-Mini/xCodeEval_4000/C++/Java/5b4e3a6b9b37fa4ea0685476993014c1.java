import java.io.*;
import java.util.*;
import java.util.function.Function;

class Modular<T> {
    private long value;
    private static final int MOD = (int) 1e9 + 7;

    public Modular() {
        this.value = 0;
    }

    public Modular(long x) {
        this.value = normalize(x);
    }

    private long normalize(long x) {
        if (x < 0) x += MOD;
        if (x >= MOD) x -= MOD;
        return x;
    }

    public long getValue() {
        return value;
    }

    public Modular<T> add(Modular<T> other) {
        return new Modular<>(normalize(this.value + other.value));
    }

    public Modular<T> subtract(Modular<T> other) {
        return new Modular<>(normalize(this.value - other.value));
    }

    public Modular<T> multiply(Modular<T> other) {
        return new Modular<>(normalize(this.value * other.value));
    }

    public Modular<T> divide(Modular<T> other) {
        return multiply(new Modular<>(inverse(other.value)));
    }

    private long inverse(long a) {
        long m0 = MOD, x0 = 0, x1 = 1;
        if (MOD == 1) return 0;
        while (a > 1) {
            long q = a / MOD;
            long t = MOD;
            MOD = a % MOD;
            a = t;
            t = x0;
            x0 = x1 - q * x0;
            x1 = t;
        }
        if (x1 < 0) x1 += m0;
        return x1;
    }

    @Override
    public String toString() {
        return Long.toString(value);
    }
}

public class 5b4e3a6b9b37fa4ea0685476993014c1_nc {
    static int[] d = new int[123];
    static Modular<Long>[] dp = new Modular[7];
    static Modular<Long>[] new_dp = new Modular[7];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int tt = Integer.parseInt(br.readLine());

        for (int i = 0; i < 7; i++) {
            dp[i] = new Modular<>();
            new_dp[i] = new Modular<>();
        }

        while (tt-- > 0) {
            long m = Long.parseLong(br.readLine());
            int len = 0;
            while (m > 0) {
                d[len++] = (int) (m & 1);
                m >>= 1;
            }
            Arrays.fill(dp, new Modular<>());
            dp[0] = new Modular<>(1);

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
            out.println(dp[0]);
        }
        out.flush();
    }
}
