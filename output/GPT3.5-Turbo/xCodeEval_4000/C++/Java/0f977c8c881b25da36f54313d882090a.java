import java.util.*;
import java.io.*;

public class 0f977c8c881b25da36f54313d882090a_nc {
    static final int N = 4 * 1000 * 1000 + 13;
    static int n, mod;
    static int[] dp = new int[N];
    static int[] pr = new int[N];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        mod = Integer.parseInt(st.nextToken());

        pr[1] = 1;
        pr[2] = mod - 1;
        for (int i = 1; i <= n; i++) {
            dp[i] = pr[i];
            pr[i + 1] = add(pr[i + 1], dp[i]);
            for (int j = 2; j * i <= n; j++) {
                pr[j * i] = add(pr[j * i], dp[i]);
                if (j * (i + 1) < N)
                    pr[j * (i + 1)] = add(pr[j * (i + 1)], -dp[i]);
            }
            pr[i + 1] = add(pr[i + 1], pr[i]);
        }
        System.out.println(dp[n]);
    }

    static int add(int a, int b) {
        a += b;
        if (a >= mod)
            a -= mod;
        if (a < 0)
            a += mod;
        return a;
    }
}
