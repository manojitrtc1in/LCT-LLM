import java.util.*;
import java.io.*;

class Main {
    static final int N = 4 * 1000 * 1000 + 13;
    static int n, mod;
    static int[] dp = new int[N];
    static int[] pr = new int[N];

    static boolean read() {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            n = sc.nextInt();
            mod = sc.nextInt();
            return true;
        }
        return false;
    }

    static int add(int a, int b) {
        a += b;
        if (a >= mod)
            a -= mod;
        if (a < 0)
            a += mod;
        return a;
    }

    static int mul(int a, int b) {
        return (int) ((long) a * b % mod);
    }

    static void solve() {
        Arrays.fill(dp, 0);
        Arrays.fill(pr, 0);
        pr[1] = 1;
        pr[2] = mod - 1;
        for (int i = 1; i <= n; ++i) {
            dp[i] = pr[i];
            pr[i + 1] = add(pr[i + 1], dp[i]);
            for (int j = 2; j * i <= n; ++j) {
                pr[j * i] = add(pr[j * i], dp[i]);
                if (j * (i + 1) < N)
                    pr[j * (i + 1)] = add(pr[j * (i + 1)], -dp[i]);
            }
            pr[i + 1] = add(pr[i + 1], pr[i]);
        }
        System.out.println(dp[n]);
    }

    public static void main(String[] args) throws IOException {
        // FileReader fr = new FileReader("input.txt");
        // BufferedReader br = new BufferedReader(fr);
        // int tc = Integer.parseInt(br.readLine());
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        while (tc-- > 0) {
            read();
            solve();
        }
    }
}
