import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int mod = sc.nextInt();

        int M = (int) Math.sqrt(n) + 10;

        long[] dp = new long[n+1];
        long[] imos = new long[n+1];
        dp[1] = 1;
        for (int i = 1; i < n; i++) {
            imos[i] = (imos[i] + imos[i-1]) % mod;
            dp[i] += imos[i];
            dp[i] %= mod;

            imos[i+1] += dp[i];
            imos[i+1] %= mod;

            for (int j = 2; j <= n; j++) {
                if (i*j > n) {
                    break;
                }

                imos[i*j] += dp[i];
                imos[i*j] %= mod;
                if ((i+1)*j <= n) {
                    imos[(i+1)*j] -= dp[i];
                    imos[(i+1)*j] %= mod;
                }
            }
        }

        long res = dp[n] + imos[n] + imos[n-1];
        res %= mod;
        System.out.println(res);
    }
}
