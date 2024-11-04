import java.io.*;
import java.util.*;

public class 97e862a6bcabaf8b203916591239d370_nc {
    static final int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        long[] DP = new long[n + 5];
        long[] CUM = new long[n + 5];
        CUM[1] = 0;
        DP[1] = 1;

        long S = 1;

        for (int i = 2; i <= n; i++) {
            CUM[i] = (CUM[i - 1] + CUM[i]) % m;
            DP[i] = (S + CUM[i]) % m;
            S = (S + DP[i]) % m;

            for (int j = i + i; j <= n; j += i) {
                CUM[j] = (CUM[j] + DP[i] - DP[i - 1]) % m;
            }
        }

        System.out.println(DP[n]);
    }
}
