import java.util.*;
import java.io.*;

public class 5598d7ef668fdcf1a6156c7a024869df_nc {
    static final int MAXI = 2 << 29;
    static final int M = 1000000007;
    static long[][] dp = new long[5005][5005];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String t = br.readLine();
        reset(dp);
        
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < t.length(); j++) {
                if (s.charAt(i) == t.charAt(j)) {
                    dp[i + 1][j + 1] = (dp[i + 1][j] % M + (dp[i][j] + 1) % M) % M;
                } else {
                    dp[i + 1][j + 1] = dp[i + 1][j];
                }
            }
        }
        
        long re = 0;
        int sz = t.length();
        for (int i = 0; i < s.length(); i++) {
            re = (re + dp[i + 1][sz] % M) % M;
        }
        System.out.println(re);
    }

    static void reset(long[][] array) {
        for (int i = 0; i < array.length; i++) {
            Arrays.fill(array[i], 0);
        }
    }
}
