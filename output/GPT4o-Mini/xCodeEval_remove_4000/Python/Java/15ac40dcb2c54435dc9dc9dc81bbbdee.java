import java.util.*;

public class 15ac40dcb2c54435dc9dc9dc81bbbdeexcodeeval_processed_4000.json {
    static final int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int M = (int) Math.sqrt(n) + 10;

        long[] dp = new long[n + 1];
        long[] imos = new long[n + 1];
        dp[1] = 1;

        for (int i = 1; i < n; i++) {
            imos[i] = (imos[i] + imos[i - 1]) % MOD;
            dp[i] = (dp[i] + imos[i]) % MOD;

            imos[i + 1] = (imos[i + 1] + dp[i]) % MOD;

            for (int j = 2; i * j <= n; j++) {
                imos[i * j] = (imos[i * j] + dp[i]) % MOD;
                if ((i + 1) * j <= n) {
                    imos[(i + 1) * j] = (imos[(i + 1) * j] - dp[i] + MOD) % MOD;
                }
            }
        }

        long res = (dp[n] + imos[n] + imos[n - 1]) % MOD;
        System.out.println(res);
    }
}
