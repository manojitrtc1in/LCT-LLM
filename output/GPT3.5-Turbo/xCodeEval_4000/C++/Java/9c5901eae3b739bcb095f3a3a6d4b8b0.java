import java.util.*;
import java.io.*;

public class 9c5901eae3b739bcb095f3a3a6d4b8b0_nc {
    static final int MOD = 998244353;
    static final int N = 300 * 1000 + 13;
    static int n;
    static ArrayList<Integer>[] g = new ArrayList[N];
    static int[][] dp = new int[N][3];

    static int add(int a, int b) {
        a += b;
        if (a >= MOD)
            a -= MOD;
        if (a < 0)
            a += MOD;
        return a;
    }

    static int mul(int a, int b) {
        return (int) ((long) a * b % MOD);
    }

    static void dfs(int v, int p) {
        dp[v][0] = 1;
        dp[v][1] = 1;
        ArrayList<Integer> vals = new ArrayList<>();
        ArrayList<Integer> init = new ArrayList<>();
        for (int u : g[v]) {
            if (u != p) {
                dfs(u, v);
                vals.add(add(dp[u][1], add(dp[u][2], dp[u][2])));
                init.add(add(dp[u][0], dp[u][1]));
                dp[v][0] = mul(dp[v][0], add(dp[u][1], add(dp[u][2], dp[u][2])));
                dp[v][1] = mul(dp[v][1], add(dp[u][1], dp[u][2]));
            }
        }
        dp[v][0] = add(dp[v][0], -dp[v][1]);

        ArrayList<Integer> pr = new ArrayList<>();
        ArrayList<Integer> su = new ArrayList<>();
        pr.add(1);
        su.add(1);
        for (int i = 0; i < vals.size(); i++) {
            pr.add(mul(pr.get(i), vals.get(i)));
        }
        Collections.reverse(vals);
        for (int i = 0; i < vals.size(); i++) {
            su.add(mul(su.get(i), vals.get(i)));
        }
        Collections.reverse(vals);
        Collections.reverse(su);

        dp[v][2] = 0;
        for (int i = 0; i < vals.size(); i++) {
            dp[v][2] = add(dp[v][2], mul(init.get(i), mul(pr.get(i), su.get(i + 1))));
        }
    }

    static void solve() {
        dfs(0, -1);
        System.out.println(add(dp[0][1], dp[0][2]));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = br.readLine()) != null) {
            n = Integer.parseInt(line);
            for (int i = 0; i < N; i++) {
                g[i] = new ArrayList<>();
            }
            for (int i = 0; i < n - 1; i++) {
                String[] input = br.readLine().split(" ");
                int v = Integer.parseInt(input[0]) - 1;
                int u = Integer.parseInt(input[1]) - 1;
                g[v].add(u);
                g[u].add(v);
            }
            solve();
        }
    }
}
