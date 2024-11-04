import java.util.*;
import java.io.*;

public class fbaf14b2671023e8789fa8f221fc4878xcodeeval_processed_4000.json {
    static final int MAXI = 1 << 29;
    static final int M = 1000000007;
    static long[][] dp = new long[5005][5005];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String t = br.readLine();
        int sz1 = s.length(), sz2 = t.length();
        for (int i = 0; i <= sz1; i++) {
            for (int j = 0; j <= sz2; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else {
                    if (s.charAt(i - 1) == t.charAt(j - 1)) {
                        dp[i][j] = (dp[i][j - 1] + (dp[i - 1][j - 1] + 1) % M) % M;
                    } else {
                        dp[i][j] = dp[i][j - 1];
                    }
                }
            }
        }
        long re = 0;
        for (int i = 0; i < sz1; i++) {
            re = (re + dp[i + 1][sz2]) % M;
        }
        System.out.println(re);
    }
}
