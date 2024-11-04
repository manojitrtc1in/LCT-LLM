import java.util.*;
import java.io.*;

public class 5598d7ef668fdcf1a6156c7a024869dfxcodeeval_processed_4000.json {
    static final int MAXI = 2 << 29;
    static final int M = 1000000007;
    static long[][] dp = new long[5005][5005];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String t = br.readLine();
        
        for (int i = 0; i <= s.length(); i++) {
            for (int j = 0; j <= t.length(); j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else {
                    if (s.charAt(i - 1) == t.charAt(j - 1)) {
                        dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] + 1) % M;
                    } else {
                        dp[i][j] = dp[i][j - 1];
                    }
                }
            }
        }

        long re = 0;
        int sz = t.length();
        for (int i = 0; i < s.length(); i++) {
            re = (re + dp[i + 1][sz]) % M;
        }
        System.out.println(re);
    }
}
