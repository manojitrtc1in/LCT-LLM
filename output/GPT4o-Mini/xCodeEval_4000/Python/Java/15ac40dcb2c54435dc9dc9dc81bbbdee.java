import java.util.*;

public class 15ac40dcb2c54435dc9dc9dc81bbbdee_nc {
    static int mod;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        mod = scanner.nextInt();

        int M = (int) Math.sqrt(n) + 10;

        int[] dp = new int[n + 1];
        int[] imos = new int[n + 1];
        dp[1] = 1;

        for (int i = 1; i < n; i++) {
            imos[i] = (imos[i] + imos[i - 1]) % mod;
            dp[i] = (dp[i] + imos[i]) % mod;

            imos[i + 1] = (imos[i + 1] + dp[i]) % mod;

            for (int j = 2; i * j <= n; j++) {
                imos[i * j] = (imos[i * j] + dp[i]) % mod;
                if ((i + 1) * j <= n) {
                    imos[(i + 1) * j] = (imos[(i + 1) * j] - dp[i] + mod) % mod;
                }
            }
        }

        int res = (dp[n] + imos[n] + imos[n - 1]) % mod;
        System.out.println(res);
    }
}
