import java.io.*;
import java.util.*;

public class 0f977c8c881b25da36f54313d882090axcodeeval_processed_4000.json {
    static final int INF = (int) 1e9;
    static final long INF64 = (long) 1e18;
    static final int MOD = (int) 1e9 + 7;
    static final double EPS = 1e-9;
    static final double PI = Math.acos(-1.0);
    static final int N = 4 * 1000 * 1000 + 13;

    static int n, mod;
    static int[] dp = new int[N];
    static int[] pr = new int[N];

    static boolean read(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        if (st.countTokens() < 2) return false;
        n = Integer.parseInt(st.nextToken());
        mod = Integer.parseInt(st.nextToken());
        return true;
    }

    static int add(int a, int b) {
        a += b;
        if (a >= mod) a -= mod;
        if (a < 0) a += mod;
        return a;
    }

    static long mul(int a, int b) {
        return (long) a * b % mod;
    }

    static void solve() {
        Arrays.fill(dp, 0);
        Arrays.fill(pr, 0);
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

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        PrintWriter out = new PrintWriter(System.out);

        int tc = Integer.parseInt(br.readLine());
        while (tc-- > 0) {
            if (!read(br)) break;
            solve();
        }

        out.close();
    }
}
